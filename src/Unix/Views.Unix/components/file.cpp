/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "file.h"

std::string OpenFileDialog(nfdfilteritem_t filter, int numFilters)
{
    NFD_Init();

    std::string ret = "";

    nfdnchar_t *outPath = nullptr;
    nfdresult_t result = NFD_OpenDialogN(&outPath, &filter, numFilters, nullptr);

    if (result == NFD_OKAY)
    {
        spdlog::info("File selected: {}", outPath);
        ret = outPath;
        NFD_FreePathN(outPath);
    }
    else if (result == NFD_CANCEL)
    {
        spdlog::info("File selection cancelled");
    }
    else
    {
        spdlog::error("Error selecting file: {}", NFD_GetError());
    }

    NFD_Quit();
    return ret;
}

std::string OpenDirectoryDialog()
{
    NFD_Init();

    std::string ret = "";

    nfdnchar_t *outPath = nullptr;
    nfdresult_t result = NFD_PickFolderN(&outPath, nullptr);

    if (result == NFD_OKAY)
    {
        spdlog::info("Directory selected: {}", outPath);
        ret = outPath;
        NFD_FreePathN(outPath);
    }
    else if (result == NFD_CANCEL)
    {
        spdlog::info("Directory selection cancelled");
    }
    else
    {
        spdlog::error("Error selecting directory: {}", NFD_GetError());
    }

    NFD_Quit();
    return ret;
}

void SaveFileDialog(nfdfilteritem_t filter, int numFilters, const char *defaultName)
{
    NFD_Init();

    nfdnchar_t *outPath = nullptr;

    if (NFD_SaveDialogN(&outPath, &filter, numFilters, nullptr, defaultName) == NFD_OKAY)
    {
        spdlog::info("File saved: {}", outPath);
        NFD_FreePathN(outPath);
    }
    else
    {
        spdlog::error("Error saving file: {}", NFD_GetError());
    }
    NFD_Quit();
    return;
}
