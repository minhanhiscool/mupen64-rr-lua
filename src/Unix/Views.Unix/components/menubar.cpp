/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "menubar.h"
#include "file.h"

// TODO: Let users customize shortcuts

void DrawRecent(const char *shortcut)
{
    if (ImGui::MenuItem("Reset"))
    {
    }
    if (ImGui::MenuItem("Freeze"))
    {
    }
    ImGui::Separator();
    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            ImGui::MenuItem("(nothing)", shortcut);
        }
        else
        {
            ImGui::MenuItem("(nothing)");
        }
    }
}

void DrawMenuBar()
{
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open ROM", "Ctrl O"))
            {
                SDL_DialogFileFilter filter = {
                    "N64 Roms",
                    "n64;z64;v64",
                };
                OpenFileDialog(filter, 1);
            }
            if (ImGui::MenuItem("Close ROM", "Ctrl W"))
            {
            }
            if (ImGui::MenuItem("Reset ROM", "Ctrl R"))
            {
            }
            if (ImGui::MenuItem("Refresh ROM List", "Ctrl F5"))
            {
            }
            ImGui::Separator();
            if (ImGui::BeginMenu("Recent ROMs"))
            {
                DrawRecent("Ctrl Shift O");
                ImGui::EndMenu();
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Exit", "Ctrl Q"))
            {
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Emulation"))
        {
            if (ImGui::MenuItem("Pause", "Pause"))
            {
            }
            if (ImGui::MenuItem("Speed Down", "-_"))
            {
            }
            if (ImGui::MenuItem("Speed Up", "=+"))
            {
            }
            if (ImGui::MenuItem("Reset Speed", "CTRL =+"))
            {
            }
            if (ImGui::MenuItem("Fast-Foward", "Tab"))
            {
            }
            if (ImGui::MenuItem("GS Button", "G"))
            {
            }

            ImGui::Separator();

            if (ImGui::MenuItem("Frame Advance", "\\|"))
            {
            }
            if (ImGui::MenuItem("Multi-Frame Advance", "Ctrl \\|"))
            {
            }
            if (ImGui::MenuItem("Multi-Frame Advance -1", "Ctrl E"))
            {
            }
            if (ImGui::MenuItem("Multi-Frame Advance +1", "Ctrl Q"))
            {
            }
            if (ImGui::MenuItem("Multi-Frame Advance Reset", "Ctrl Shift E"))
            {
            }

            ImGui::Separator();

            if (ImGui::BeginMenu("Save State"))
            {
                if (ImGui::MenuItem("Save Current Slot", "I"))
                {
                }
                if (ImGui::MenuItem("Save as File..."))
                {
                }
                ImGui::Separator();
                for (int i = 1; i <= 10; i++)
                {
                    if (ImGui::MenuItem((("Save Slot " + std::to_string(i))).c_str(),
                                        ("Shift " + std::to_string(i % 10)).c_str()))
                    {
                    }
                }
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Load State"))
            {
                if (ImGui::MenuItem("Load Current Slot", "P"))
                {
                }
                if (ImGui::MenuItem("Load from File..."))
                {
                }
                ImGui::Separator();
                for (int i = 1; i <= 10; i++)
                {
                    if (ImGui::MenuItem((("Load Slot " + std::to_string(i))).c_str(),
                                        ("F" + std::to_string(i)).c_str()))
                    {
                    }
                }
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Current State Slot"))
            {
                for (int i = 1; i <= 10; i++)
                {
                    if (ImGui::MenuItem((("Slot " + std::to_string(i))).c_str(), (std::to_string(i % 10)).c_str()))
                    {
                    }
                }
                ImGui::EndMenu();
            }

            if (ImGui::MenuItem("Undo Load State", "Ctrl Z"))
            {
            }

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Options"))
        {
            if (ImGui::MenuItem("Fullscreen", "Alt Enter"))
            {
            }
            ImGui::Separator();
            if (ImGui::BeginMenu("Plugin Settings"))
            {
                if (ImGui::MenuItem("Video Settings"))
                {
                }
                if (ImGui::MenuItem("Audio Settings"))
                {
                }
                if (ImGui::MenuItem("Input Settings"))
                {
                }
                if (ImGui::MenuItem("RSP Settings"))
                {
                }
                ImGui::EndMenu();
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Status Bar", "Alt S"))
            {
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Settings", "Ctrl S"))
            {
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Movie"))
        {
            if (ImGui::MenuItem("Start Movie Recording", "Ctrl Shift R"))
            {
            }
            if (ImGui::MenuItem("Start Movie Playback", "Ctrl Shift P"))
            {
            }
            if (ImGui::MenuItem("Continue Movie Playback"))
            {
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Stop Movie", "Ctrl Shift C"))
            {
            }
            if (ImGui::MenuItem("Create Movie Backup", "Ctrl Shift B"))
            {
            }
            ImGui::Separator();
            if (ImGui::BeginMenu("Recent Movies"))
            {
                DrawRecent("Ctrl Shift T");
                ImGui::EndMenu();
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Loop Movie Playback", "Shift L"))
            {
            }
            if (ImGui::MenuItem("Read-Only", "Shift R"))
            {
            }
            if (ImGui::MenuItem("Wait at Movie End"))
            {
            }

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Utilities"))
        {
            if (ImGui::MenuItem("Command Palette", "Ctrl P"))
            {
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Piano Roll"))
            {
            }
            if (ImGui::MenuItem("Cheats"))
            {
            }
            if (ImGui::MenuItem("Seek...", "Ctrl G"))
            {
            }
            if (ImGui::MenuItem("Usage Statistics"))
            {
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Core Information"))
            {
            }
            if (ImGui::MenuItem("Debugger"))
            {
            }
            if (ImGui::MenuItem("Start Trace Logger"))
            {
            }
            if (ImGui::MenuItem("Stop Trace Logger"))
            {
            }
            ImGui::Separator();
            if (ImGui::BeginMenu("Video Capture"))
            {
                if (ImGui::MenuItem("Start Capture"))
                {
                }
                if (ImGui::MenuItem("Start Capture from Preset"))
                {
                }
                ImGui::Separator();
                if (ImGui::MenuItem("Stop Capture"))
                {
                }
                ImGui::Separator();
                if (ImGui::MenuItem("Take Screenshot", "F12"))
                {
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help"))
        {
            if (ImGui::MenuItem("Check for Updates", "F1"))
            {
            }
            if (ImGui::MenuItem("About", "F2"))
            {
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Lua Script"))
        {
            if (ImGui::MenuItem("Show Instances", "Ctrl N"))
            {
            }
            ImGui::Separator();
            if (ImGui::BeginMenu("Recent Scripts"))
            {
                DrawRecent("Ctrl Shift K");
                ImGui::EndMenu();
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Close All", "Ctrl Shift W")) ImGui::EndMenuBar();
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}
