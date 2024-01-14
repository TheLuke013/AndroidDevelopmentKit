cmake_minimum_required (VERSION 3.8)

project ("AndroidPromptKit")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

file(GLOB SOURCE_FILES
    "src/*.cpp"
    "thirdparty/imgui/*.cpp"
)

add_executable (AndroidPromptKit   ${SOURCE_FILES})

target_include_directories(AndroidPromptKit PRIVATE
    "thirdparty/glfw/include"
    "thirdparty/imgui"
)

target_link_libraries(AndroidPromptKit PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/lib/glfw3.lib
)
