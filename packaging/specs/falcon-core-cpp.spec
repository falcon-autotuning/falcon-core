Name:           falcon-core-cpp
Version:        1.0.0
Release:        1%{?dist}
Summary:        Falcon Core C++ development package with tests and coverage

License:        MIT
URL:            https://github.com/falcon-autotuning/falcon-core
Source0:        git+https://github.com/falcon-autotuning/falcon-core.git#new-dev

BuildRequires:  cmake, gcc-c++, make, boost-devel, hdf5-devel, yaml-cpp-devel, openssl-devel, sqlite-devel, zlib-devel, gcovr
Requires:       cereal, xtl, xtensor, xsimd, yaml-cpp, hdf5, boost 

%description
Development build of Falcon Core C++ with tests and coverage artifacts.

%prep
%setup -q -n falcon-core-cpp-1.0.0

%build
cd "cpp" || exit
make build-dev USE_VCPKG=0

%install
install -Dm755 build/libfalcon_core_cpp.so "%{_sourcedir}/usr/lib/libfalcon_core_cpp.so"
install -d "%{_sourcedir}/usr/include/falcon-core-cpp"
cp -r include/falcon_core/* "%{_sourcedir}/usr/include/falcon-core-cpp/"

%files
%license LICENSE
/usr/lib/libfalcon_core_cpp.so*
/usr/include/falcon_core_cpp
/usr/share/falcon-core-cpp/coverage

%changelog
* Tue Nov 11 2025 Packager <tylerkovach1@gmail.com> - 1.0.0-2
- Changed the setup to a proper package name
* Thu Oct 30 2025 Packager <daschug1@gmail.com> - 1.0.0-1
- Initial dev RPM
