//
// Net Use
//
// Copyright (c) 2020-2021 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#ifndef NET_USE_VERSION_HPP
#define NET_USE_VERSION_HPP

#define NET_USE_VERSION_ABCD                1,8,0,20
#define NET_USE_VERSION_STR                 "1.8.0"
#define NET_USE_VERSION_STR_BUILD           "20"
#define NET_USE_VERSION_STR_DATETIME        "2021-11-22 13:35:06"

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

