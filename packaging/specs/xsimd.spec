Name:           xsimd
Version:        10.0.0
Release:        1%{?dist}
Summary:        C++ wrappers for SIMD intrinsics

License:        BSD
URL:            https://github.com/xtensor-stack/xsimd
Source0:        %{name}-%{version}.tar.gz
%global debugsource_package %{nil}
%global debug_package %{nil}

BuildRequires:  cmake, gcc-c++
%description
xsimd - header-only SIMD wrappers.

%prep
%setup -q -n xsimd-10.0.0

%build
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
make -j$(nproc)

%install
cd build
make DESTDIR=%{buildroot} install

%files
/usr/include/xsimd

%changelog
* Thu Oct 30 2025 Packager <you@example.com> - 10.0.0-1
- Initial RPM
