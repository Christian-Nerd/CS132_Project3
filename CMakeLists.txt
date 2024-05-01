# CMakeList.txt : CMake project for CS132_Project3, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CS132_Project3")
# Add source to this project's executable.
add_executable (CS132_Project3 "CS132_Project3.cpp" "CS132_Project3.h" "CS132_Project3_Driver.cpp" "CS132_Project3_Driver.cpp" "Quicksort.h" "Quicksort.cpp")
set_property(TARGET CS132_Project3 PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
add_library(QuickSort.lib UNKNOWN IMPORTED)
# CMake option example (enable header-only version)
# set(UNI_ALGO_HEADER_ONLY ON CACHE INTERNAL "")
# Note that header-only makes the library constexpr

add_subdirectory(uni-algo) # The directory where you extracted this repository

# Config define example (disable normalization)
# target_compile_definitions(uni-algo PUBLIC UNI_ALGO_DISABLE_NORM)
# Note that you can ignore config defines if header-only is enabled
# because Unicode data that is not used won't be compiled anyway.

target_link_libraries(${PROJECT_NAME} PRIVATE uni-algo::uni-algo)
target_link_libraries(QuickSort.lib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CS132_Project3 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
