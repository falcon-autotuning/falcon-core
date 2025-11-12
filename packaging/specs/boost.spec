Name:           boost
Version:        1.88.0
Release:        1%{?dist}
Summary:        Boost C++ Libraries (runtime split: filesystem, system, uuid)
License:        Boost
URL:            https://www.boost.org/
Source0:        %{name}-%{version}.tar.gz

BuildRequires:  gcc-c++
BuildRequires:  gcc
BuildRequires:  make
BuildRequires:  python3
BuildRequires:  bzip2
BuildRequires:  tar
BuildRequires:  cmake
%global debugsource_package %{nil}
%global debug_package %{nil}
%description
Boost provides portable, peer-reviewed, modern C++ libraries. This
package builds Boost and produces runtime subpackages for selected
libraries: boost-filesystem, boost-system and boost-uuid.

%package libs
Summary:        Boost C++ Libraries (runtime)
Group:          Development/Libraries

%description libs
This package contains the runtime libraries for Boost.

%package devel
Summary:        Boost C++ header files and development libraries
Group:          Development/Libraries
Requires:       %{name}-libs = %{version}-%{release}

%description devel
This package contains the C++ header files and CMake configuration
files needed to develop applications using Boost.

%prep
%setup -q -n boost-%{version}

%build
./bootstrap.sh --with-libraries=filesystem,system,uuid,atomic
./b2 %{_smp_mflags} toolset=gcc variant=release link=shared threading=multi

%install
rm -rf %{buildroot}
./b2 install --prefix=%{buildroot}%{_prefix} --libdir=%{buildroot}%{_libdir} --with-filesystem --with-system \
--with-uuid --with-atomic variant=release link=shared threading=multi

find %{buildroot}%{_libdir}/cmake -name "*.cmake" -print0 | xargs -0 sed -i "s|%{buildroot}||g"

%files
%defattr(-,root,root,-)
%license LICENSE_1_0.txt

%files libs
%defattr(-,root,root,-)
%{_libdir}/libboost_*.so
%{_libdir}/libboost_*.so.*

%files devel
%defattr(-,root,root,-)
%{_includedir}/boost/
%{_libdir}/cmake/*

%changelog
* Thu Oct 30 2025 Packager <daschug1@gmail.com> - 1.88.0 
- Initial RPM
