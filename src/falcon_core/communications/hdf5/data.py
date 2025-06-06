"""An interface for HDF5 data."""

from typing import TYPE_CHECKING

from .dependancies import (
    Axes,
    Jsonable,
    MeasuredArray,
    MeasurementRequest,
    MeasurementResponse,
    h5py,
    np,
)

if TYPE_CHECKING:
    from .typing import (
        ControlArray,
        CoupledKnobDomain,
        Dimensions,
        Domains,
        LabelledMeasuredArrays,
        Metadata,
        Path,
        Ranges,
        arrayND,
    )


class HDF5Data(Jsonable):
    """An intermediate format that allows for easy conversion to HDF5.

    The file format looks like this:
    dimensions
      dim1
          integer
      ...
    domains
      dim1
          data
              real_data
          labels
              label1
                  label
                      real_label
                  unit
                      real_unit
                  start
                      real_start
                  stop
                      real_stop
              label2
                  label
                      real_label
                  unit
                      real_unit
                  start
                      real_start
                  stop
                      real_stop
              ...
      ...
    ranges
      label1
          label
              real_label
          data
              real_data
          unit
              real_unit
      label2
          label
              real_label
          data
              real_data
          unit
              real_unit
      ...
    metadata
      rest_of_request
          stuff

    """

    _dimensions: "Dimensions"
    _domains: "Domains"
    _ranges: "Ranges"
    _metadata: "Metadata"
    _unique_id: int
    _measurement_title: str
    _timestamp: int

    def __init__(
        self,
        shape: "Axes[int]",
        unit_domain: "Axes[ControlArray[arrayND]]",
        domain_labels: "Axes[CoupledKnobDomain]",
        ranges: "LabelledMeasuredArrays[arrayND]",
        metadata: "Metadata",
        measurement_title: str,
        unique_id: int,
        timestamp: int,
    ) -> None:
        """Initializes the HDF5Data object.

        Args:
            shape: The shape of the data. (Order matters)
        """
        self._unique_id = unique_id
        self._measurement_title = measurement_title
        self._timestamp = timestamp
        self._dimensions = {}
        [self._dimensions.update({"dim" + str(i): shape[i]}) for i in range(len(shape))]
        self._domains = {}
        [
            self._domains.__setitem__(
                "dim" + str(i),
                {
                    "labels": {
                        domain.label._pseudo_name.name
                        if domain.label._pseudo_name is not None
                        else domain.label.instrument_type: {
                            "unit": domain.label.units.symbol,
                            "start": float(domain.domain.bounds[0]),
                            "stop": float(domain.domain.bounds[1]),
                        }
                        for domain in domain_labels[i].domains
                    },
                    "data": ",".join(map(str, unit_domain[i].data.ravel(order="C"))),
                },
            )
            for i in range(len(shape))
        ]
        self._ranges = {}
        [
            self._ranges.__setitem__(
                range.connection.name
                if range.connection is not None
                else range.instrument_type,
                {
                    "unit": range.units.symbol,
                    "data": ",".join(map(str, range.array.data.ravel(order="C"))),
                },
            )
            for range in ranges.arrays
        ]
        self._metadata = metadata

    @classmethod
    def from_communications(
        cls,
        request: "MeasurementRequest",
        response: "MeasurementResponse",
        measurement_title: str,
        unique_id: int,
        timestamp: int,
    ) -> "HDF5Data":
        """Load the HDF5Data object from a MeasurementRequest and MeasurementResponse.

        Args:
            request: The MeasurementRequest object to load.
            response: The MeasurementResponse object to load.
            measurement_title: The measurement title.
            unique_id: The unique ID.
            timestamp: The timestamp.

        Returns:
            the HDF5Data object.
        """
        [wave._space._space.compile() for wave in request.waveforms]
        valid_waveform = next(
            (
                waveform
                for waveform in request.waveforms
                if waveform._space._space.space.shape[1]
                == waveform._space._axes.dimension
            ),
            None,
        )
        assert valid_waveform is not None, "No valid waveform found in request."
        valid_waveform_copy = valid_waveform.deepcopy()
        count = valid_waveform_copy._space._axes.dimension
        axes = Axes([int(value) for value in np.arange(start=0, stop=count, step=1)])
        unit_domain = valid_waveform_copy._space._space.create_array(axes=axes)  # type: ignore[]
        shape = unit_domain[0].shape
        domain_labels = valid_waveform_copy._space._axes
        ranges = response.arrays
        # removing compiled array from the waveform
        # for waveform in request._waveforms:
        #     del waveform._space._space._space
        # removing data from response
        # for array in response._arrays:
        #     array._array._data = np.array([])
        return HDF5Data(
            shape=Axes(shape),
            unit_domain=unit_domain,
            domain_labels=domain_labels,
            ranges=ranges,
            metadata={
                "jsonable_request": request.to_json(),
                "jsonable_response": response.to_json(),
            },
            timestamp=timestamp,
            unique_id=unique_id,
            measurement_title=measurement_title,
        )

    def to_file(self, path: "Path") -> None:
        """Convert the HDF5Data object to a file.

        Args:
            path: The path to the file.
        """
        with h5py.File(path, "w") as f:
            dimensions = f.create_group("dimensions")
            [
                dimensions.create_dataset(
                    dim,
                    data=value,
                    dtype="i8",
                )
                for dim, value in self._dimensions.items()
            ]

            domains = f.create_group("domains")
            sub_domains = [domains.create_group(dim) for dim in self._domains]
            [
                sub_domains[i].create_dataset(
                    "data",
                    data=self._domains[dim]["data"],
                    dtype=h5py.string_dtype(encoding="utf-8"),
                )
                for i, dim in enumerate(self._domains)
            ]
            for i, domain in enumerate(self._domains.values()):
                for j, (label, metadata) in enumerate(domain["labels"].items()):  # type: ignore[assignment]
                    label_group = sub_domains[i].create_group(f"label{j}")
                    label_group.create_dataset(
                        "label",
                        data=label,
                        dtype=h5py.string_dtype(encoding="utf-8"),
                    )
                    label_group.create_dataset(
                        "unit",
                        data=metadata["unit"],
                        dtype=h5py.string_dtype(encoding="utf-8"),
                    )
                    label_group.create_dataset(
                        "start",
                        data=metadata["start"],
                        dtype="f8",
                    )
                    label_group.create_dataset(
                        "stop",
                        data=metadata["stop"],
                        dtype="f8",
                    )

            ranges = f.create_group("ranges")
            sub_range_sets = [
                ranges.create_dataset(
                    f"range{i}",
                    data=self._ranges[range]["data"],
                    dtype=h5py.string_dtype(encoding="utf-8"),
                )
                for i, range in enumerate(self._ranges)
            ]
            for i, (range, range_values) in enumerate(self._ranges.items()):
                sub_range_sets[i].attrs["label"] = range
                sub_range_sets[i].attrs["unit"] = range_values["unit"]

            metadatacontainer = f.create_group("metadata")
            metadatacontainer.attrs["timestamp"] = self._timestamp
            metadatacontainer.attrs["unique_id"] = self._unique_id
            metadatacontainer.attrs["measurement_title"] = self._measurement_title
            for key, value in self._metadata.items():
                metadatacontainer.create_dataset(
                    key,
                    data=value,
                    dtype=h5py.string_dtype(encoding="utf-8"),
                )

    @classmethod
    def from_file(cls, path: "Path") -> "HDF5Data":
        """Convert directly from a file to an HDF5Data object.

        Args:
            path: The path to the file.

        Returns:
            The HDF5Data object.
        """

        def _extract_dataset_value(ds):
            """Extract and decode a value from an h5py.Dataset."""
            value = ds[()]
            if isinstance(value, bytes):
                return value.decode()
            if isinstance(value, np.floating):
                return float(value)
            return value

        def _extract_group_dict(group):
            """Recursively extract all datasets from an h5py.Group into a dict."""
            result = {}
            for key in group:
                item = group[key]
                if hasattr(item, "keys"):  # It's a group
                    result[key] = _extract_group_dict(item)
                else:  # It's a dataset
                    result[key] = _extract_dataset_value(item)
            return result

        with h5py.File(path, "r") as f:
            measurement_title = f["metadata"].attrs["measurement_title"]
            assert isinstance(measurement_title, str), "Invalid measurement title."
            timestamp = int(f["metadata"].attrs["timestamp"])  # type: ignore[assignment]
            assert isinstance(timestamp, int), "Invalid timestamp."
            unique_id = int(f["metadata"].attrs["unique_id"])  # type: ignore[assignment]
            assert isinstance(unique_id, str), "Invalid unique ID."
            dimensions = _extract_group_dict(f["dimensions"])
            assert isinstance(dimensions, dict), "Invalid dimensions."
            metadata = _extract_group_dict(f["metadata"])
            assert isinstance(metadata, dict), "Invalid metadata."
            domains = {}
            for i, sub_domain in enumerate(f["domains"].values()):  # type: ignore[assignment]
                data = ""
                label = ""
                unit = ""
                start = 0.0
                stop = 0.0
                domains[f"dim{i}"] = {}
                domains[f"dim{i}"]["labels"] = {}
                print(sub_domain)
                for sub_domain_name, sub_domain_value in sub_domain.items():
                    if sub_domain_name == "data":
                        data = _extract_dataset_value(sub_domain_value)
                        domains[f"dim{i}"]["data"] = data
                    else:
                        label = _extract_dataset_value(sub_domain_value["label"])
                        unit = _extract_dataset_value(sub_domain_value["unit"])
                        start = _extract_dataset_value(sub_domain_value["start"])
                        stop = _extract_dataset_value(sub_domain_value["stop"])
                        domains[f"dim{i}"]["labels"][label] = {}
                        domains[f"dim{i}"]["labels"][label]["unit"] = unit
                        domains[f"dim{i}"]["labels"][label]["start"] = start
                        domains[f"dim{i}"]["labels"][label]["stop"] = stop

            assert isinstance(domains, dict), "Invalid domains."
            ranges = {}
            for values in f["ranges"].values():  # type: ignore[assignment]
                data = values[()]
                if isinstance(data, bytes):
                    data = data.decode()
                label = values.attrs["label"]
                unit = values.attrs["unit"]
                ranges[label] = {"data": data, "unit": unit}

        obj = cls.__new__(cls)
        obj._dimensions = dimensions
        obj._domains = domains
        obj._ranges = ranges
        obj._metadata = metadata
        obj._unique_id = unique_id
        obj._measurement_title = measurement_title
        obj._timestamp = timestamp
        return obj

    def to_communications(self) -> tuple["MeasurementResponse", MeasurementRequest]:
        """Convert the HDF5Data object to a tuple of MeasurementResponse and Metadata.

        Returns:
            A tuple of MeasurementResponse and Metadata.
        """
        assert self._metadata is not None, "Metadata is not set."
        assert isinstance(self._metadata["jsonable_request"], str), ()
        assert isinstance(self._metadata["jsonable_response"], str), (
            "Response is not a string."
        )
        response = MeasurementResponse.from_json(self._metadata["jsonable_response"])
        request = MeasurementRequest.from_json(self._metadata["jsonable_request"])
        for range in response.arrays:
            if range.connection is not None:
                target_name = range.connection.name
            else:
                target_name = range.instrument_type
            data_str = self._ranges[target_name]["data"]
            shape = tuple(self._dimensions.values())
            range._array = MeasuredArray(
                np.fromstring(data_str, sep=",").reshape(shape, order="C")
            )
        return (response, request)
