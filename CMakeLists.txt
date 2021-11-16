cmake_minimum_required(VERSION 3.0.0)
project(InitCPP VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED False)

include(CTest)
enable_testing()

#add_executable(InitCPP main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


configure_file(D:/TrialProjects/VSCode/InitCPP/header/headerConfig.h.in headerConfig.h)

file(GLOB_RECURSE SOURCES
    D:/TrialProjects/VSCode/InitCPP/header/*.h
    D:/TrialProjects/VSCode/InitCPP/src/*.cpp
)

add_executable(InitCPP ${SOURCES})

target_include_directories(InitCPP PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )


include_directories(include)