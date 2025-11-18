/* Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "Main.h"
#include "Config.h"

#define FILE "DLL/TAS_RSP.ini"
#define CONFIG_VALUE "Config"

t_config config = {};
t_config default_config = {};
t_config prev_config = {};
t_config working_config = {};

bool show_config = false;

std::string get_config_path()
{
    const char *path = SDL_GetPrefPath("Mupen64", "mupen64-rr-lua");
    if (path == NULL)
    {
        return "";
    }
    std::string path_str = std::string(path) + FILE;
    SDL_free(&path);
    return path_str;
}

void dialog_function()
{
    if (ImGui::BeginPopupModal("RSP Config", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {

        bool verify = config.ucode_cache_verify != 0;
        if (ImGui::Checkbox("Verify Ucode Cache", &verify))
        {
            working_config.ucode_cache_verify = verify ? 1 : 0;
        }

        ImGui::Separator();
        if (ImGui::Button("OK"))
        {
            config = working_config;
            config_save();
            ImGui::CloseCurrentPopup();
            show_config = false;
        }
        if (ImGui::Button("Cancel"))
        {
            working_config = config;
            ImGui::CloseCurrentPopup();
            show_config = false;
        }

        ImGui::EndPopup();
    }
}

void config_save()
{
    g_ef->log_trace("Saving config...");
    std::string path = get_config_path();
    if (path.empty())
    {
        g_ef->log_error("Could not get config path");
        return;
    }
    SDL_IOStream *file = SDL_IOFromFile(path.c_str(), "wb");
    if (!file)
    {
        g_ef->log_error("Could not open config file");
        return;
    }
    if (SDL_WriteIO(file, &config, sizeof(t_config)) < sizeof(t_config))
    {
        g_ef->log_error("Could not write config file");
        return;
    }
    SDL_CloseIO(file);
}

void config_load()
{
    g_ef->log_trace("Loading config...");
    std::string path = get_config_path();
    if (path.empty())
    {
        g_ef->log_error("Could not get config path");
        return;
    }
    SDL_IOStream *file = SDL_IOFromFile(path.c_str(), "rb");
    if (!file)
    {
        g_ef->log_error("Could not open config file");
        return;
    }

    t_config loaded_config{};
    if (SDL_ReadIO(file, &loaded_config, sizeof(t_config)) != sizeof(t_config))
    {
        g_ef->log_error("Could not read config file completely");
        return;
    }
    SDL_CloseIO(file);

    if (loaded_config.version != default_config.version)
    {
        g_ef->log_trace("Config version mismatch. Loading default config.");
        loaded_config = default_config;
    }
    config = loaded_config;
}

void config_show_dialog()
{
    working_config = config;
    show_config = true;
    ImGui::OpenPopup("RSP Config");
}
