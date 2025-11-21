/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "nfd.h"

std::string OpenFileDialog(nfdfilteritem_t filter, int numFilters);
std::string OpenDirectoryDialog();
void SaveFileDialog(nfdfilteritem_t filter, int numFilters, const char *defaultName);
