cmake_minimum_required(VERSION 3.15)

project(ato_frogger_project)

add_executable(ato_frogger ato_frogger/source/ato_frogger.cpp)

add_subdirectory(box_renderer)

set_property(TARGET ato_frogger PROPERTY CXX_STANDARD 20)

target_include_directories(ato_frogger 
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/box_renderer/source
)

target_link_directories(ato_frogger PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/build/box_renderer/source/Debug)

target_link_libraries(ato_frogger box_renderer)

add_dependencies(ato_frogger box_renderer)