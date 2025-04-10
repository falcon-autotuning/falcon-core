from falcon_core.datatypes.axes import Axes
from falcon_core.measurement_interface import Cartesian2DSpace, UnitSpace
from falcon_core.measurement_interface.discretizers import CartesianDiscretizer

# from falcon.datatypes import Domain


def test_3d_unit_space_compilation():
    """Test initialization+compile of UnitSpace class for weird 3D space."""
    d1 = CartesianDiscretizer(
        delta=0.1,
    )
    d2 = CartesianDiscretizer(
        delta=0.1,
    )
    d3 = CartesianDiscretizer(
        delta=0.1,
    )
    ax = Axes([d1, d2, d3])
    # Domain()
    us = UnitSpace(
        axes=ax,
    )
    us.compile()
    assert us.space is not None
    assert us.space.shape == (10**3, 3)


def test_prepackaged_2d_unit_space_compilation():
    """Test initialization+compile of Cartesian2DSpace class."""
    c2ds = Cartesian2DSpace(
        deltas=[0.1, 0.1],
    )
    c2ds.compile()
    assert c2ds.space is not None
    assert c2ds.space.shape == (10**2, 2)
    # import numpy as np
    # print(np.meshgrid(*[c2ds._ranges[i]._data for i in [0,1]]))
    axinds = Axes([0, 1])
    thing = c2ds.create_array(axes=axinds)
    for thingy in thing:
        assert thingy.shape == (10, 10)


def test_bunch_of_2d_unit_space_compilation():
    """Test compilation of UnitSpace class up to 7 dimensions."""
    for num_dims in range(1, 8):
        d1 = CartesianDiscretizer(
            delta=0.1,
        )
        ax = Axes(
            [
                d1,
            ]
            * num_dims
        )
        us = UnitSpace(
            axes=ax,
        )
        us.compile()
        assert us.space is not None
        assert us.space.shape == (10**num_dims, num_dims)
