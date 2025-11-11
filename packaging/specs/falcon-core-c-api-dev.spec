Name:           falcon-core-c-api-dev
Version:        1.0.0
Release:        1%{?dist}
Summary:        Falcon Core C development package with tests and coverage

License:        MIT
URL:            https://github.com/falcon-autotuning/falcon-core
Source0:        %{name}-%{version}.tar.gz

BuildRequires:  cmake, gcc-c++, make, boost-devel, hdf5-devel, yaml-cpp-devel, openssl-devel, sqlite-devel, zlib-devel, gcovr
Requires:       cereal, xtl, xtensor, xsimd, yaml-cpp, hdf5, boost

%description
Development build of Falcon Core C with tests and coverage artifacts.

%prep
%setup -q -n falcon-core-c-api-dev-1.0.0

%build
cd "c-api" || exit
make build-dev USE_VCPKG=0
make run-all-tests
mkdir coverage
make coverage-overview >coverage/falcon-core-c-api.txt

%install
install -Dm755 build/libfalcon_core_c_api.so "%{_sourcedir}/usr/lib/libfalcon_core_c_api.so"
install -d "%{_sourcedir}/usr/include/falcon-core-c-api-dev"
cp -r include/falcon_core/* "%{_sourcedir}/usr/include/falcon-core-c-api-dev/"
# Optionally install coverage reports or test binaries
install -d "%{_sourcedir}/usr/share/falcon-core-c-api-dev/coverage"
cp -r build/coverage/* "%{_sourcedir}/usr/share/falcon-core-c-api-dev/coverage/"

%files
%license LICENSE
/usr/lib/libfalcon_core_c_api.so*
/usr/include/falcon_core_c_api_dev
/usr/share/falcon-core-c-api-dev/coverage

%changelog
* Tue Nov 11 2025 Packager <tylerkovach1@gmail.com> - 1.0.0-2
- Changed the setup to a proper package name
* Thu Oct 30 2025 Packager <daschug1@gmail.com> - 1.0.0-1
- Initial dev RPM
