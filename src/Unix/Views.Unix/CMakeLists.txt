#[===[
Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).

SPDX-License-Identifier: GPL-2.0-or-later
]===]

add_executable(Mupen64RR.Views.Unix
    "menubar.h"

    "main.cpp"
    "menubar.cpp"
)

set_target_properties(Mupen64RR.Views.Unix PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME "mupen64"
    RUNTIME_OUTPUT_DIRECTORY "${MUPEN64RR_OUT_DIR}"
    PDB_OUTPUT_DIRECTORY "${MUPEN64RR_OUT_DIR}"
)

target_precompile_headers(Mupen64RR.Views.Unix PRIVATE "pch.h")
target_link_libraries(Mupen64RR.Views.Unix PRIVATE
    Mupen64RR.Common
    Mupen64RR.Core
    Lua::Lua
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    PkgConfig::speexdsp
    vendor::argh
    vendor::bs-thread-pool
    vendor::microlru
    vendor::mini
    SDL3::SDL3
    imgui
    OpenGL::GL
)

