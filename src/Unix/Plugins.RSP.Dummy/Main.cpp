/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "Main.h"

// PlatformService platform_service;

extern "C" void GetSoInfo(core_plugin_info *info)
{
    info->ver = 0x0101;
    info->type = plugin_rsp;
    strncpy(info->name, PLUGIN_NAME, std::size(info->name));
}

extern "C" void SoAbout(void *hParent)
{
    const auto msg = PLUGIN_NAME "\n"
                                 "Part of the Mupen64 project family."
                                 "\n\n"
                                 "https://github.com/mupen64/mupen64-rr-lua";
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "About", msg, (SDL_Window *)hParent);
}

__attribute__((constructor)) void load()
{
}
__attribute__((destructor)) void unload()
{
}
