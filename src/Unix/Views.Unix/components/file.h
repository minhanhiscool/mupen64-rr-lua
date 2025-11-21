/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

std::string OpenFileDialog(SDL_DialogFileFilter filter, int numFilters);
std::string OpenDirectoryDialog();
void SaveFileDialog(SDL_DialogFileFilter filter, int numFilters);
