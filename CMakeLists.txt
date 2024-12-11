cmake_minimum_required(VERSION 3.10)

# Project name
project(xenakisAnalogiqueGUI VERSION 1.0 LANGUAGES C)

# Find GTK4 using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

# Include GTK4 directories
include_directories(${GTK4_INCLUDE_DIRS})

# Define the executable
add_executable(xenakisAnalogiqueGUI main.c)

# Link GTK4 libraries
target_link_libraries(xenakisAnalogiqueGUI ${GTK4_LIBRARIES})

# Add compile options from pkg-config
target_compile_options(xenakisAnalogiqueGUI PRIVATE ${GTK4_CFLAGS_OTHER})

