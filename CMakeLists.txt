cmake_minimum_required(VERSION 3.19)
# enable_language(CXX)

project(qwt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# -------------- Support C++17 for using filesystem  ------------------#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif(MSVC)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network OpenGL Gui PrintSupport Svg Concurrent LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network OpenGL PrintSupport Svg Concurrent Gui LinguistTools)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# Create code from a list of Qt designer ui files

# find_package(Qt5 COMPONENTS Widgets REQUIRED)
# find_package(Qt5 COMPONENTS Core REQUIRED)
# find_package(Qt5 COMPONENTS Gui REQUIRED)
# find_package(Qt5 COMPONENTS OpenGL REQUIRED)


file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

if (${QT_VERSION_MAJOR} EQUAL 6)
  list(REMOVE_ITEM HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/qwt_plot_glcanvas.h")
  list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/qwt_plot_glcanvas.cpp")

  message("Version is ${QT_VERSION_MAJOR}")

  # add_library(${PROJECT_NAME} SHARED ${SOURCES})

  add_library(${PROJECT_NAME} OBJECT)
  add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

  set(BACK_SOURCES ${HEADERS})
  list(REMOVE_ITEM HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/qwt_plot_item.h")
  qt6_wrap_cpp(moc_files ${HEADERS}) # no automoc for OBJECT libs:-/

  target_sources(${PROJECT_NAME} PRIVATE
      ${SOURCES} ${BACK_SOURCES}
      ${moc_files}
  )
    # qt6_wrap_cpp(moc_files ${HEADERS})
    # add_library(${PROJECT_NAME} SHARED ${moc_files} ${SOURCES} ${HEADERS})

  message(STATUS ${moc_files})

  target_compile_definitions(${PROJECT_NAME} PUBLIC QWT_MAKEDLL QT_DLL QWT_DLL)

  find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS OpenGLWidgets)
  find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS OpenGLWidgets)
  target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::OpenGLWidgets)
else()
    message("Min Six Version is ${QT_VERSION_MAJOR}")

    # add_library(${PROJECT_NAME} SHARED ${SOURCES})

    add_library(${PROJECT_NAME} OBJECT)
    add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
	
	set(BACK_SOURCES ${HEADERS})
	list(REMOVE_ITEM HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/qwt_plot_item.h")
	
    qt_wrap_cpp(moc_files ${HEADERS}) # no automoc for OBJECT libs:-/
    target_sources(${PROJECT_NAME} PRIVATE
        ${SOURCES} ${BACK_SOURCES}
        ${moc_files}
    )

    target_compile_definitions(${PROJECT_NAME} PUBLIC QWT_MAKEDLL QT_DLL QWT_DLL)
endif()

message(STATUS "${SOURCES}")

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/classincludes)


target_link_libraries(${PROJECT_NAME}  Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(${PROJECT_NAME}  Qt${QT_VERSION_MAJOR}::Core)

target_link_libraries(${PROJECT_NAME}  Qt${QT_VERSION_MAJOR}::Widgets)

target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::OpenGL)
target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Concurrent)
target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::PrintSupport)
target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Svg)
# target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

target_link_libraries(${PROJECT_NAME} opengl32)

target_link_libraries(${PROJECT_NAME} glu32)

add_subdirectory(examples)
add_subdirectory(QwtWaterfall)

add_executable(split_main split_main.cc)
target_link_libraries(split_main Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})