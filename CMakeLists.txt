cmake_minimum_required(VERSION 3.12)

project(keep-going
    VERSION 1.0.0
    DESCRIPTION "Tiny command-line morale booster"
    LANGUAGES CXX
)

# ---- Build settings ---------------------------------------------------------

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Sensible defaults
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# ---- Target ----------------------------------------------------------------

add_executable(keep-going
    keep-going.cpp
)

# Warnings (kept gentle on purpose)
if (MSVC)
    target_compile_options(keep-going PRIVATE /W4)
else()
    target_compile_options(keep-going PRIVATE -Wall -Wextra -Wpedantic)
endif()

# ---- Install ---------------------------------------------------------------

include(GNUInstallDirs)

install(TARGETS keep-going
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# ---- Summary ---------------------------------------------------------------

message(STATUS "Configured keep-going ${PROJECT_VERSION}")
