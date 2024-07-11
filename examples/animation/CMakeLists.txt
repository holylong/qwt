cmake_minimum_required(VERSION 3.19)


get_filename_component(current_directory_name "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
message("Current directory name: ${current_directory_name}")

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.ui ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

message(STATUS ${SOURCES})

if (${QT_VERSION_MAJOR} EQUAL 6)
  qt_add_executable(${current_directory_name} MANUAL_FINALIZATION ${SOURCES})
else()
  add_executable(${current_directory_name} ${SOURCES})
endif()
target_link_libraries(${current_directory_name} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${current_directory_name} PRIVATE qwt)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})