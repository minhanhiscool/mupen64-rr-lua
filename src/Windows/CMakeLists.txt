#[===[
Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).

SPDX-License-Identifier: GPL-2.0-or-later
]===]

if (WIN32)
    # VIEW
    # ============================

    add_subdirectory(Views.Win32)

    # BUNDLED PLUGINS
    # ============================
    
    # common settings
    include("${CMAKE_CURRENT_LIST_DIR}/Plugins.Common.Win32.cmake")

    # dummy plugins
    add_subdirectory(Plugins.Audio.Dummy)
    add_subdirectory(Plugins.Input.Dummy)
    add_subdirectory(Plugins.RSP.Dummy)
    add_subdirectory(Plugins.Video.Dummy)

    # TAS RSP
    add_subdirectory(Plugins.RSP.TAS)
endif()
