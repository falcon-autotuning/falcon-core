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

%package boost-filesystem
Summary:        Boost.Filesystem runtime library
Group:          Development/Libraries
Requires:       boost-system >= %{version}-%{release}
Requires:       boost-atomic >= %{version}-%{release}

%description boost-filesystem
This package contains the Boost.Filesystem runtime library (libboost_filesystem).

%package boost-atomic
Summary:        Boost.Atomic runtime library
Group:          Development/Libraries

%description boost-atomic
This package contains the Boost.Atomic runtime library (libboost_atomic).

%package boost-system
Summary:        Boost.System runtime library
Group:          Development/Libraries

%description boost-system
This package contains the Boost.System runtime library (libboost_system).

%package boost-devel
Summary:        Boost C++ header files and development libraries
Group:          Development/Libraries
Requires:       boost-filesystem = %{version}-%{release}
Requires:       boost-system = %{version}-%{release}
Requires:       boost-atomic = %{version}-%{release}

%description boost-devel
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

%files boost-filesystem
%defattr(-,root,root,-)
%{_libdir}/libboost_filesystem.so.*
%{_libdir}/libboost_filesystem.so

%files boost-atomic
%defattr(-,root,root,-)
%{_libdir}/libboost_atomic.so.*
%{_libdir}/libboost_atomic.so

%files boost-system
%defattr(-,root,root,-)
%{_libdir}/libboost_system.so.*
%{_libdir}/libboost_system.so

%files boost-devel
%defattr(-,root,root,-)
%{_includedir}/boost/
%{_libdir}/cmake/Boost*

%changelog
* Thu Oct 30 2025 Packager <daschug1@gmail.com> - 1.88.0 
- Initial RPM
