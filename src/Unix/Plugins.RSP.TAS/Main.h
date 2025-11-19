/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include <CommonPCH.h>
#include <core_api.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_opengl3.h"

// #include <Views.Unix/ViewPlugin.h>

#define PLUGIN_VERSION "1.0.1"

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

#define PLUGIN_NAME "TAS RSP " PLUGIN_VERSION PLUGIN_ARCH PLUGIN_TARGET

// HACK: Please remove this struct after View.Unix is implemented

struct core_plugin_extended_funcs
{
    /**
     * \brief Size of the structure in bytes.
     */
    uint32_t size;

    /**
     * \brief Logs the specified message at the trace level.
     */
    void (*log_trace)(const char *);

    /**
     * \brief Logs the specified message at the info level.
     */
    void (*log_info)(const char *);

    /**
     * \brief Logs the specified message at the warning level.
     */
    void (*log_warn)(const char *);

    /**
     * \brief Logs the specified message at the error level.
     */
    void (*log_error)(const char *);
};

extern std::filesystem::path g_app_path;
extern core_plugin_extended_funcs *g_ef;

bool rsp_alive();
void on_rom_closed();
uint32_t do_rsp_cycles(uint32_t Cycles);
