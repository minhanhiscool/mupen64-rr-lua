/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "menubar.h"

void DrawMenuBar()
{
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open ROM", "CTRL+O"))
            {
            }
            if (ImGui::MenuItem("Close ROM", "CTRL+W"))
            {
            }
            if (ImGui::MenuItem("Reset ROM", "CTRL+R"))
            {
            }
            if (ImGui::MenuItem("Refresh ROM List", "CTRL+F5"))
            {
            }
            ImGui::Separator();
            if (ImGui::BeginMenu("Recent ROMs"))
            {
                if (ImGui::MenuItem("Reset"))
                {
                }
                if (ImGui::MenuItem("Freeze"))
                {
                }
                // TODO: add recent menu functions here
                for (int i = 0; i < 5; i++)
                {
                    if (i == 0)
                    {
                        if (ImGui::MenuItem("(nothing)", "CTRL+SHIFT+O"))
                        {
                        }
                    }
                    if (ImGui::MenuItem("(nothing)"))
                    {
                    }
                }
                ImGui::EndMenu();
            }
            if (ImGui::MenuItem("Exit", "CTRL+Q"))
            {
            }
            ImGui::EndMenu();
        }

        // TODO: add more menus
        ImGui::EndMenuBar();
    }
}
