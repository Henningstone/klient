cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(klient)

#-----------------------------------------------------------------------
# CPM configuration
#-----------------------------------------------------------------------

set(CPM_DIR "${CMAKE_CURRENT_BINARY_DIR}/cpm_packages" CACHE TYPE STRING)
find_package(Git)
if(NOT GIT_FOUND)
message(FATAL_ERROR "CPM requires Git.")
endif()
if (NOT EXISTS ${CPM_DIR}/CPM.cmake)
message(STATUS "Cloning repo (https://github.com/iauns/cpm)")
execute_process(
	COMMAND "${GIT_EXECUTABLE}" clone https://github.com/iauns/cpm ${CPM_DIR}
	RESULT_VARIABLE error_code
	OUTPUT_QUIET ERROR_QUIET)
if(error_code)
	message(FATAL_ERROR "CPM failed to get the hash for HEAD")
endif()
endif()
include(${CPM_DIR}/CPM.cmake)

#------------------------------------------------------------------------------
# CPM Modules
#------------------------------------------------------------------------------

CPM_AddModule("cpm-glfw"
	GIT_REPOSITORY "https://github.com/nsg/cpm-glfw.git"
	GIT_TAG "27d3dd4a8fd34f50f2e4cf1583484e1c4ac4bcec")

CPM_AddModule("cpm-glew"
	GIT_REPOSITORY "https://github.com/iauns/cpm-glew.git"
	GIT_TAG "1.0.1")

CPM_AddModule("cpm-lodepng"
	GIT_REPOSITORY "https://github.com/nsg/cpm-lodepng.git"
	GIT_TAG "9879d938ce3f110ccca020979d282ea2e4713398")

CPM_Finish()

#-----------------------------------------------------------------------
# Misc
#-----------------------------------------------------------------------

set(CMAKE_BUILD_TYPE Debug)

add_executable(klient src/main.cpp)
target_link_libraries(klient ${CPM_LIBRARIES})
