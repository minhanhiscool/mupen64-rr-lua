#[===[
Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).

SPDX-License-Identifier: GPL-2.0-or-later
]===]

# COMMON LIBRARIES
# ============================

# common headers and PCH
add_subdirectory(Common)
# core API and headers
add_subdirectory(Core)

if (MUPEN64RR_BUILD_WIN32)
  add_subdirectory(Windows)
elseif (MUPEN64RR_BUILD_UNIX)
  # Plugins and Views of Unix
  add_subdirectory(Unix)
endif()
