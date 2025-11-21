/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "rombrowser.h"

void DrawROMBrowser()
{
    ImGui::BeginChild("ROMBrowser", ImVec2(0, 0), ImGuiWindowFlags_None);
    // placeholder PLEASE REMOVE
    std::vector<std::string> ROMList;
    ROMList.reserve(100);
    for (int i = 0; i < 100; i++)
    {
        ROMList.push_back("ROM" + std::to_string(i));
    }

    ImGui::BeginTable("ROMList", 4,
                      ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable |
                          ImGuiTableFlags_ScrollY);

    ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, 24.0f);
    ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch);
    ImGui::TableSetupColumn("Filename", ImGuiTableColumnFlags_WidthStretch);
    ImGui::TableSetupColumn("Size", ImGuiTableColumnFlags_WidthFixed, 80.0f);

    ImGui::TableHeadersRow();

    ImGuiListClipper clipper;
    clipper.Begin(100);
    while (clipper.Step())
        for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++)
        {
            ImGui::TableNextColumn();

            ImGui::TableSetColumnIndex(0);
            ImGui::Text("jap");

            ImGui::TableSetColumnIndex(1);
            std::string ROMName = ROMList[i] + "##" + std::to_string(i);
            if (ImGui::Selectable(ROMName.c_str(), false, ImGuiSelectableFlags_SpanAllColumns))
            {
                spdlog::info("ROM selected: {}", ROMList[i]);
            }
            ImGui::TableSetColumnIndex(2);
            ImGui::Text("%s", ROMList[i].c_str());

            ImGui::TableSetColumnIndex(3);
            ImGui::Text("%d MB", 8);
        }

    ImGui::EndTable();

    ImGui::EndChild();
}
