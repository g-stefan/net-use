// Net Use
// Copyright (c) 2020-2025 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2020-2025 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#include <XYO/NetUse/Copyright.hpp>
#include <XYO/NetUse/Copyright.rh>

namespace XYO::NetUse::Copyright {

	static const char *copyright_ = XYO_NetUse_COPYRIGHT;
	static const char *publisher_ = XYO_NetUse_PUBLISHER;
	static const char *company_ = XYO_NetUse_COMPANY;
	static const char *contact_ = XYO_NetUse_CONTACT;

	const char *copyright() {
		return copyright_;
	};

	const char *publisher() {
		return publisher_;
	};

	const char *company() {
		return company_;
	};

	const char *contact() {
		return contact_;
	};

};
