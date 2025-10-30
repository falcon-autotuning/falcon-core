Name:           falcon-core-cpp-dev
Version:        1.0.0
Release:        1%{?dist}
Summary:        Falcon Core C++ development package with tests and coverage

License:        MIT
URL:            https://github.com/falcon-autotuning/falcon-core
Source0:        %{name}-%{version}.tar.gz

BuildRequires:  cmake, gcc-c++, make, boost-devel, hdf5-devel, yaml-cpp-devel, openssl-devel, sqlite-devel, zlib-devel, gcovr
Requires:       falcon-core-cpp

%description
Development build of Falcon Core C++ with tests and coverage artifacts.

%prep
%setup -q -n falcon-core-1.0.0

%build
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DFALCON_BUILD_TESTS=ON -DCMAKE_BUILD_TYPE=RelWithDebInfo
make -j$(nproc)

%install
cd build
make DESTDIR=%{buildroot} install
# Place tests/coverage into a share directory for inspection
install -d %{buildroot}/usr/share/falcon-core-cpp-dev/coverage
if [ -d coverage_html ]; then cp -r coverage_html %{buildroot}/usr/share/falcon-core-cpp-dev/coverage/; fi

%files
%license LICENSE
/usr/lib/libfalcon_core_cpp.so*
/usr/include/falcon_core_cpp
/usr/share/falcon-core-cpp-dev/coverage

%changelog
* Thu Oct 30 2025 Packager <daschug1@gmail.com> - 1.0.0-1
- Initial dev RPM
