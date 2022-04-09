//
// Net Use
//
// Copyright (c) 2020-2022 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#ifndef NET_USE_VERSION_HPP
#define NET_USE_VERSION_HPP

#define NET_USE_VERSION_ABCD 1,11,0,26
#define NET_USE_VERSION_STR "1.11.0"
#define NET_USE_VERSION_STR_BUILD "26"
#define NET_USE_VERSION_STR_DATETIME "2022-04-04 01:45:01"

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
