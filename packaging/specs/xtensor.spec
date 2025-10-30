Name:           xtensor
Version:        0.25.0
Release:        1%{?dist}
Summary:        C++ tensors with broadcasting and lazy computing

License:        BSD
URL:            https://github.com/xtensor-stack/xtensor
Source0:        %{name}-%{version}.tar.gz
%global debugsource_package %{nil}
%global debug_package %{nil}

BuildRequires:  cmake, gcc-c++
%description
xtensor - Header-only C++ tensors with broadcasting.

%prep
%setup -q -n xtensor-0.25.0

%build
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
make -j$(nproc)

%install
cd build
make DESTDIR=%{buildroot} install

%files
/usr/include/xtensor

%changelog
* Thu Oct 30 2025 Packager <you@example.com> - 0.25.0-1
- Initial RPM
