cmake_minimum_required(VERSION 3.16)
enable_testing()

# Project Name and Version
project(NodeEditor LANGUAGES CXX VERSION 1.0.0)

# set search path for CMake files
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# CMake helper functions
include(nodeeditor_helper_functions)

#
include(nodeeditor_deployqt)

# CMake options with default values and description texts
include(nodeeditor_cmake_options)

# compiler settings for this lib
include(nedeeditor_common_compilersettings)

# include Qt with appropriate options to build this lib
include(nodeeditor_common_qtsettings)

# now add subdirectories with the library code ...
add_subdirectory(lib)

# add subdirectories with the tests
if(NODE_EDITOR_BUILD_TESTING)
	add_subdirectory(tests)
endif()

# ... and optionally the examples
if(NODE_EDITOR_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()
