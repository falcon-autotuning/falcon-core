Name:           xtensor-io
Version:        0.13.0
Release:        1%{?dist}
Summary:        IO functionalities for xtensor

License:        BSD
URL:            https://github.com/xtensor-stack/xtensor-io
Source0:        %{name}-%{version}.tar.gz
%global debugsource_package %{nil}
%global debug_package %{nil}

BuildRequires:  cmake, gcc-c++
%description
xtensor-io - IO utilities for xtensor.

%prep
%setup -q -n xtensor-io-0.13.0

%build
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
make -j$(nproc)

%install
cd build
make DESTDIR=%{buildroot} install

%files
/usr/include/xtensor-io

%changelog
* Thu Oct 30 2025 Packager <you@example.com> - 0.13.0-1
- Initial RPM
