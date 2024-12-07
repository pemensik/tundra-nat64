Name:           tundra-nat64
Version:        6.0.2
Release:        %autorelease
Summary:        A minimal, user-space, stateless NAT64, CLAT and SIIT implementation for Linux

License:        BSD-3-Clause
URL:            https://github.com/vitlabuda/tundra-nat64
Source0:        %{url}/archive/v%{version}/%{name}-%{version}.tar.gz

BuildRequires:  gcc
BuildRequires:  cmake

%description
Tundra-NAT64 is an open-source IPv6-to-IPv4 & IPv4-to-IPv6 translator for
Linux which operates entirely in user-space, can run in multiple threads
(and thus make use of today's modern multicore CPUs) and uses either the
TUN driver or inherited file descriptors to receive and send packets. It
is written in pure C and translates packets according to the rules of SIIT
(Stateless IP/ICMP Translation Algorithm; RFC 7915)

%prep
%autosetup


%build
%cmake -DCMAKE_INSTALL_SYSCONFDIR="%{_sysconfdir}"
%cmake_build


%install
%cmake_install


%files
%license LICENSE
%doc README.md
%{_sbindir}/%{name}
%dir %{_sysconfdir}/%{name}/
%config(noreplace) %{_sysconfdir}/%{name}/%{name}*.conf
%{_mandir}/man5/%{name}.conf.5*
%{_mandir}/man8/%{name}.8*



%changelog
%autochangelog
