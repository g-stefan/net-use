// Net Use
// Copyright (c) 2020-2023 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2020-2023 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#include <XYO/NetUse/License.hpp>
#include <XYO/NetUse/Copyright.hpp>

namespace XYO::NetUse::License {

	std::string license() {
		std::string retV;
		retV += ManagedMemory::License::licenseMITHeader();
		retV += Copyright::copyright();
		retV += "\r\n";
		retV += ManagedMemory::License::licenseMITContent();
		return retV;
	};

	std::string shortLicense() {
		std::string retV;
		retV += Copyright::copyright();
		retV += "\r\n";
		retV += ManagedMemory::License::licenseMITShort();
		return retV;
	};

};
