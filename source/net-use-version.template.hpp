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

#define NET_USE_VERSION_ABCD                $VERSION_ABCD
#define NET_USE_VERSION_STR                 "$VERSION_VERSION"
#define NET_USE_VERSION_STR_BUILD           "$VERSION_BUILD"
#define NET_USE_VERSION_STR_DATETIME        "$VERSION_DATETIME"

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

