cmake_minimum_required (VERSION 3.8)

project ("AndroidPromptKit")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable (AndroidPromptKit   "src/main.cpp" "src/CheckDependencies.cpp" "src/CheckDependencies.h")
