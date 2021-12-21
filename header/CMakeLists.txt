cmake_minimum_required(VERSION 3.0.0)

# file(GLOB_RECURSE SOURCES
#     *.h
# )

add_library(libheader
            cppFileHeaders.h
            )

target_include_directories(libheader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})