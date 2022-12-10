// Net Use
// Copyright (c) 2022 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2022 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SECURITY_WIN32
#	define SECURITY_WIN32
#endif

#include <windows.h>
#include <lm.h>
#include <lmuse.h>

#include <XYO/NetUse/Application.hpp>
#include <XYO/NetUse/Copyright.hpp>
#include <XYO/NetUse/License.hpp>
#include <XYO/NetUse/Version.hpp>

namespace XYO::NetUse {

	void Application::showUsage() {
		printf("net-use - mount network drive\n");
		printf("version %s build %s [%s]\n", NetUse::Version::version(), NetUse::Version::build(), NetUse::Version::datetime());
		printf("%s\n\n", NetUse::Copyright::copyright());
		printf("%s\n",
		       "usage:\n"
		       "    net-use --local=... --remote=... --username=... --password=...\n\n"
		       "options:\n"
		       "    --license                                      show license\n"
		       "    --local=[local device name]                    [ K: ]\n"
		       "    --remote=[share name of the remote resource]   [ \\\\192.168.0.1\\ShareName ]\n"
		       "    --username=[username]\n"
		       "    --password=[password]\n"
		       "    @[file name]                                   use filename content as options\n");
	};

	void Application::showLicense() {
		printf("%s", NetUse::License::license());
	};

	void Application::showVersion() {
		printf("version %s build %s [%s]\n", NetUse::Version::version(), NetUse::Version::build(), NetUse::Version::datetime());
	};

	void Application::initMemory() {
		String::initMemory();
		StringUTF16::initMemory();
	};

	int Application::main(int cmdN, char *cmdS[]) {
		int i;
		String opt;
		size_t optIndex;
		String optValue;

		String local;
		String remote;
		String username;
		String password;

		enum {
			OPT_HAS_LOCAL = 0x01,
			OPT_HAS_REMOTE = 0x02,
			OPT_HAS_USERNAME = 0x04,
			OPT_HAS_PASSWORD = 0x08
		};

		int OPT_HAS_ALL = 0x00;
		OPT_HAS_ALL |= OPT_HAS_LOCAL;
		OPT_HAS_ALL |= OPT_HAS_REMOTE;
		OPT_HAS_ALL |= OPT_HAS_USERNAME;
		OPT_HAS_ALL |= OPT_HAS_PASSWORD;

		int optHas = 0x00;

		// get options from file [ @filename ]

		TDynamicArray<String> cmdLine;
		String content;
		int cmdNX;
		char **cmdSX;
		int m;

		for (i = 1; i < cmdN; ++i) {
			if (StringCore::beginWith(cmdS[i], "@")) {
				if (Shell::fileGetContents(&cmdS[i][1], content)) {
					Shell::mainArgsSet(content, cmdNX, cmdSX);
					for (m = 0; m < cmdNX; ++m) {
						cmdLine.push(cmdSX[m]);
					};
					Shell::mainArgsDelete(cmdNX, cmdSX);
					continue;
				};
				printf("Error: file not found - %s\n", &cmdS[i][1]);
				return 1;
			};
			cmdLine.push(cmdS[i]);
		};

		// parse options

		for (i = 0; i < cmdLine.length(); ++i) {
			if (StringCore::beginWith(cmdLine[i], "--")) {
				opt = cmdLine[i].index(2);
				optValue = "";
				if (String::indexOf(opt, "=", 0, optIndex)) {
					optValue = String::substring(opt, optIndex + 1);
					opt = String::substring(opt, 0, optIndex);
				};
				if (opt == "license") {
					showLicense();
					return 0;
				};
				if (opt == "usage") {
					showUsage();
					return 0;
				};
				if (opt == "local") {
					if (optValue.length() > 0) {
						optHas |= OPT_HAS_LOCAL;
						local = optValue;
					};
					continue;
				};
				if (opt == "remote") {
					if (optValue.length() > 0) {
						optHas |= OPT_HAS_REMOTE;
						remote = optValue;
					};
					continue;
				};
				if (opt == "username") {
					if (optValue.length() > 0) {
						optHas |= OPT_HAS_USERNAME;
						username = optValue;
					};
					continue;
				};
				if (opt == "password") {
					if (optValue.length() > 0) {
						optHas |= OPT_HAS_PASSWORD;
						password = optValue;
					};
					continue;
				};
				continue;
			};
		};

		if (optHas != OPT_HAS_ALL) {
			showUsage();
			return 0;
		};

		USE_INFO_2 loginInfo;
		NET_API_STATUS retV;
		DWORD parmErr;

		StringUTF16 ui2_local = TUTFConvert<utf16, utf8>::from(local);
		StringUTF16 ui2_remote = TUTFConvert<utf16, utf8>::from(remote);
		StringUTF16 ui2_username = TUTFConvert<utf16, utf8>::from(username);
		StringUTF16 ui2_password = TUTFConvert<utf16, utf8>::from(password);
		StringUTF16 ui2_domainname = TUTFConvert<utf16, utf8>::from("");

		loginInfo.ui2_local = (LPWSTR)ui2_local.value();
		loginInfo.ui2_remote = (LPWSTR)ui2_remote.value();
		loginInfo.ui2_password = (LPWSTR)ui2_password.value();
		loginInfo.ui2_status = 0;
		loginInfo.ui2_asg_type = USE_DISKDEV;
		loginInfo.ui2_refcount = 0;
		loginInfo.ui2_usecount = 1;
		loginInfo.ui2_username = (LPWSTR)ui2_username.value();
		loginInfo.ui2_domainname = (LPWSTR)ui2_domainname.value();

		retV = NetUseAdd(nullptr, 2, (LPBYTE)&loginInfo, &parmErr);
		if (retV != NERR_Success) {
			printf("Error: %u\n", parmErr);
			return 1;
		};

		return 0;
	};
};

#ifndef XYO_NetUse_LIBRARY
XYO_APPLICATION_MAIN(XYO::NetUse::Application);
#endif
