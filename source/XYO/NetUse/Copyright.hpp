// Net Use
// Copyright (c) 2022 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2022 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#ifndef XYO_NetUse_COPYRIGHT_HPP
#define XYO_NetUse_COPYRIGHT_HPP

#ifndef XYO_NetUse_DEPENDENCY_HPP
#	include <XYO/NetUse/Dependency.hpp>
#endif

namespace XYO::NetUse::Copyright {
	const char *copyright();
	const char *publisher();
	const char *company();
	const char *contact();
	const char *fullCopyright();
};

#endif
