/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#define PLUGIN_VERSION "1.0.0"

#ifdef _M_X64
#define PLUGIN_ARCH " x64"
#else
#define PLUGIN_ARCH " "
#endif

#ifdef _DEBUG
#define PLUGIN_TARGET " Debug"
#else
#define PLUGIN_TARGET " "
#endif

#define PLUGIN_NAME "No RSP " PLUGIN_VERSION PLUGIN_ARCH PLUGIN_TARGET
