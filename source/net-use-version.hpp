//
// Net Use
//
// Copyright (c) 2020 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#ifndef NET_USE_VERSION_HPP
#define NET_USE_VERSION_HPP

#define NET_USE_VERSION_ABCD                1,1,0,4
#define NET_USE_VERSION_STR                 "1.1.0"
#define NET_USE_VERSION_STR_BUILD           "4"
#define NET_USE_VERSION_STR_DATETIME        "2020-12-01 21:14:24"

#ifndef XYO_RC

namespace NetUse {
	namespace Version {
		const char *version();
		const char *build();
		const char *versionWithBuild();
		const char *datetime();
	};
};

#endif
#endif

