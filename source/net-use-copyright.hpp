//
// Net Use
//
// Copyright (c) 2020 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#ifndef NET_USE_COPYRIGHT_HPP
#define NET_USE_COPYRIGHT_HPP

#define NET_USE_COPYRIGHT            "Copyright (c) Grigore Stefan"
#define NET_USE_PUBLISHER            "Grigore Stefan"
#define NET_USE_COMPANY              NET_USE_PUBLISHER
#define NET_USE_CONTACT              "g_stefan@yahoo.com"
#define NET_USE_FULL_COPYRIGHT       NET_USE_COPYRIGHT " <" NET_USE_CONTACT ">"

#ifndef XYO_RC

namespace NetUse {
	namespace Copyright {
		const char *copyright();
		const char *publisher();
		const char *company();
		const char *contact();
		const char *fullCopyright();
	};
};

#endif
#endif
