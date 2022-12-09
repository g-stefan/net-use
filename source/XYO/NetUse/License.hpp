// Net Use
// Copyright (c) 2022 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2022 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#ifndef XYO_NetUse_LICENSE_HPP
#define XYO_NetUse_LICENSE_HPP

#ifndef XYO_NetUse_DEPENDENCY_HPP
#	include <XYO/NetUse/Dependency.hpp>
#endif

namespace XYO::NetUse::License {

	const char *licenseHeader();
	const char *licenseBody();
	const char *shortLicense();

};

#endif
