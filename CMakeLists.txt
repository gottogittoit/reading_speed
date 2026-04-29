cmake_minimum_required(VERSION 3.27)

project(reading_speed)

set(CMAKE_CXX_STANDARD 23)

add_library(reading_speed_src include/fonts.h src/fonts.cpp "include/guiwidgets.h"  "src/rendercontext.cpp" "include/rendercontext.h" "include/appcontext.h" "include/inputhandler.h" "src/inputhandler.cpp" "include/parser.h" "src/parser.cpp" "include/focusedText.h" "src/focusedText.cpp")

target_include_directories(reading_speed_src PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_ttf CONFIG REQUIRED)
target_link_libraries(reading_speed_src PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf reading_speed_src)

add_custom_target(copy_assets ALL COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/assets $<TARGET_FILE_DIR:reading_speed>/assets)
add_dependencies(${PROJECT_NAME} copy_assets)