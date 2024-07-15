# pacman -S mingw-w64-x86_64-gtk3

# CMakeLists.txt

# rm -rf build/ # reset build
# cmake -S . -B build -G "MinGW Makefiles" && cmake --build build --verbose && build/cairo2d

# [settings.json] of MS Visual Studio Code
# // extension for CMake: ms-vscode.cmake-tools
# "cmake.generator": "MinGW Makefiles", // "Ninja" or "MSYS Makefiles" // cmake -G "MSYS Makefiles" // pacman -S make

cmake_minimum_required(VERSION 3.10)
project(gtk-cairo)

if(WIN32)
    set(PKG_CONFIG_EXECUTABLE "C:\\msys64\\mingw64\\bin\\pkgconf.exe")
endif()

message(STATUS $ENV{PKG_CONFIG_PATH})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

file(GLOB SOURCE_FILES "c_sources/*.c*")
add_executable(cairo2d ${SOURCE_FILES})

target_link_libraries(cairo2d ${GTK3_LIBRARIES})
