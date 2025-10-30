Name:           xtl
Version:        0.7.5
Release:        1%{?dist}
Summary:        C++ implementation of common tools used in the xtensor ecosystem

License:        BSD
URL:            https://github.com/xtensor-stack/xtl
Source0:        %{name}-%{version}.tar.gz
%global debugsource_package %{nil}
%global debug_package %{nil}

BuildRequires:  cmake, gcc-c++
%description
xtl - header-only C++ utilities used by xtensor.

%prep
%setup -q -n xtl-0.7.5

%build
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
make -j$(nproc)

%install
cd build
make DESTDIR=%{buildroot} install

%files
/usr/include/xtl
/usr/share/cmake/xtl/*
/usr/share/pkgconfig/xtl.pc

%changelog
* Thu Oct 30 2025 Packager <you@example.com> - 0.7.5-1
- Initial RPM
