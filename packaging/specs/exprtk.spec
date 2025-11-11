Name:           exprtk
Version:        0.0.2
Release:        1%{?dist}
Summary:        C++ Mathematical Expression Library

License:        CPL
URL:            http://www.partow.net/programming/exprtk/index.html
Source0:        %{name}-%{version}.tar.gz
%global debugsource_package %{nil}
%global debug_package %{nil}

BuildRequires:  cmake, gcc-c++
%description
xsimd - header-only exprtk wrappers.

%prep
%setup -q -n exprtk-0.0.2 

%build
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
make -j$(nproc)

%install
cd build
make DESTDIR=%{buildroot} install

%files
/usr/include/exprtk
/usr/lib*/cmake/exprtk/*
/usr/lib*/pkgconfig/exprtk.pc

%changelog
* Thu Oct 30 2025 Packager <daschug1@gmail.com> - 10.0.0-1
- Initial RPM
