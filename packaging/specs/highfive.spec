Name:           highfive
Version:        3.1.1
Release:        1%{?dist}
Summary:        Header‑only C++ interface for HDF5
License:        BSD
URL:            https://github.com/highfive-devs/highfive
Source0:        %{name}-%{version}.tar.gz
%global debugsource_package %{nil}
%global debug_package %{nil}
Requires:       hdf5-devel

%description
HighFive provides a modern C++11/14/17 interface to the HDF5 library.
It is header‑only; installing the package copies the headers to
%{_includedir}/highfive.

%prep
%setup -q

%install
mkdir -p %{buildroot}%{_includedir}/highfive
cp -r include/highfive/* %{buildroot}%{_includedir}/highfive/

%files
%{_includedir}/highfive/

%changelog
* Tue Nov 11 2025 Daniel Schug <daschug1@gmail.com> - 3.1.1-1
- Initial package

