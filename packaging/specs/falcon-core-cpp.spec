Name:           falcon-core-cpp
Version:        1.0.0
Release:        1%{?dist}
Summary:        Falcon Core C++ shared library

License:        MIT
URL:            https://github.com/falcon-autotuning/falcon-core
Source0:        %{name}-%{version}.tar.gz

BuildRequires:  cmake, gcc-c++, make, boost-devel, hdf5-devel, yaml-cpp-devel, openssl-devel, sqlite-devel, zlib-devel
Requires:       boost, hdf5, yaml-cpp, openssl, sqlite, zlib

%description
Falcon Core C++ shared library.

%prep
%setup -q -n falcon-core-1.0.0

%build
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=RelWithDebInfo
make -j$(nproc)

%install
cd build
make DESTDIR=%{buildroot} install

%files
%license LICENSE
/usr/lib/libfalcon_core_cpp.so*
/usr/include/falcon_core_cpp

%changelog
* Thu Oct 30 2025 Packager <you@example.com> - 1.0.0-1
- Initial RPM
