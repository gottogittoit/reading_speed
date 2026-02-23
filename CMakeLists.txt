cmake_minimum_required(VERSION 3.27)

project(reading_speed)

set(CMAKE_CXX_STANDARD 23)

#add_library(reading_speed_src )

#target_include_directories(reading_speed_src PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} main.cpp)

#find_package(SDL3 CONFIG REQUIRED)
#find_package(SDL3_ttf CONFIG REQUIRED)
#target_link_libraries(reading_speed_src PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf)
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf reading_speed_src)
