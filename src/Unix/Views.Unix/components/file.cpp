/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "file.h"

std::string path;

static void SDLCALL callback(void *userdata, const char *const *filelist, int filter)
{
    if (!filelist)
    {
        spdlog::error("Error opening file dialog: {}", SDL_GetError());
        return;
    }
    else if (!*filelist)
    {
        spdlog::info("No file selected");
        return;
    }
    while (*filelist)
    {
        spdlog::info("File {}: {}", userdata, *filelist);
        path = *filelist;
        filelist++;
    }
}

std::string OpenFileDialog(SDL_DialogFileFilter filter, int numFilters)
{
    std::string type = "opened";
    SDL_ShowOpenFileDialog(callback, &type, nullptr, &filter, numFilters, nullptr, 0);

    return path;
}

std::string OpenDirectoryDialog()
{
    std::string type = "opened";
    SDL_ShowOpenFolderDialog(callback, &type, nullptr, nullptr, 0);

    return path;
}

void SaveFileDialog(SDL_DialogFileFilter filter, int numFilters)
{
    std::string type = "saved";
    SDL_ShowSaveFileDialog(callback, &type, nullptr, &filter, numFilters, nullptr);
}
