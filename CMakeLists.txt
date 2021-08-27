cmake_minimum_required(VERSION 3.20)

set(VCPKG_TARGET_TRIPLET "x64-windows")
set(CMAKE_TOOLCHAIN_FILE "D:/buildtools/vcpkg/scripts/buildsystems/vcpkg.cmake") # set in .vscode/settings.json
set(CMAKE_INSTALL_MESSAGE LAZY)  # Don't tell us about up-to-date files.
set(VERBOSE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(audio)

add_library(myaudiosink STATIC MyAudioSink.cpp MyAudioSink.h)
target_include_directories(myaudiosink PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(microsoft_example STATIC microsoft_example.cpp)
target_link_libraries(microsoft_example PUBLIC myaudiosink)

add_executable(main main.cpp)
target_link_libraries(main microsoft_example)
