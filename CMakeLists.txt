cmake_minimum_required(VERSION 3.10)

# Project name
project(xenakisAnalogiqueGUI VERSION 1.0 LANGUAGES C)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.c
    )

# Find GTK4 using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

# Include GTK4 directories
include_directories(${GTK4_INCLUDE_DIRS})

# Define the executable
add_executable(xenakisAnalogiqueGUI ${SOURCES})

# Link GTK4 libraries
target_link_libraries(xenakisAnalogiqueGUI ${GTK4_LIBRARIES})

# Add compile options from pkg-config
target_compile_options(xenakisAnalogiqueGUI PRIVATE ${GTK4_CFLAGS_OTHER})

# Set the directories that should be included in the build command for this target
target_include_directories(xenakisAnalogiqueGUI
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)


# SET CSOUND LIB

set (CS_LIB csound64)

find_library(CS_LIB_PATH ${CS_LIB})

find_path(CSOUND_H_PATH csound.h)

if(NOT CS_LIB_PATH)
    message(ERROR "Unable to find library: ${CS_LIB}")
endif()

if(NOT CSOUND_H_PATH)
    message(ERROR "Unable to find csound.h.")
endif()

include_directories(${CSOUND_H_PATH})

target_link_libraries(xenakisAnalogiqueGUI ${CS_LIB_PATH})
