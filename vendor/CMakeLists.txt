#[===[
Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Hacktarux, ShadowPrince, linker).

SPDX-License-Identifier: GPL-2.0-or-later
]===]

add_subdirectory(aladdin-md5)
add_library(vendor::aladdin-md5 ALIAS aladdin-md5)

add_subdirectory(argh)
add_library(vendor::argh ALIAS argh)

add_subdirectory(bs-thread-pool)
add_library(vendor::bs-thread-pool ALIAS bs-thread-pool)

add_subdirectory(microlru)
add_library(vendor::microlru ALIAS microlru)

add_subdirectory(mini)
add_library(vendor::mini ALIAS mini)

add_subdirectory(xxhash64)
add_library(vendor::xxhash64 ALIAS xxhash64)

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui")
set(IMGUI_SOURCES
  ${IMGUI_DIR}/imgui.cpp
  ${IMGUI_DIR}/imgui_draw.cpp
  ${IMGUI_DIR}/imgui_tables.cpp
  ${IMGUI_DIR}/imgui_widgets.cpp
  ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp
  ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC ${IMGUI_DIR} ${IMGUI_DIR}/backends)
set_target_properties(imgui PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_subdirectory(nativefiledialog-extended)
add_library(vendor::nfd ALIAS nfd)
