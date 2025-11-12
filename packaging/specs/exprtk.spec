Name:           exprtk
Version:        0.0.3
Release:        1%{?dist}
Summary:        C++ Mathematical Expression Library

License:        CPL
URL:            http://www.partow.net/programming/exprtk/index.html
Source0:        %{name}-%{version}.tar.gz
%global debugsource_package %{nil}
%global debug_package %{nil}

BuildRequires:  cmake
%description
xsimd - header-only exprtk wrappers.

%prep
%setup -q -n exprtk-0.0.3

%build

%install
mkdir -p %{buildroot}%{_includedir}/exprtk
cp -a exprtk.hpp %{buildroot}%{_includedir}/exprtk/

%files
%{_includedir}/exprtk.hpp

%changelog
* Thu Oct 30 2025 Packager <daschug1@gmail.com> - 0.0.3-1 
- Initial RPM
