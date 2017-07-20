cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME gImage)
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_DIR src)
set(SOURCE_FILES ${SOURCE_DIR}/main.cc
                 ${SOURCE_DIR}/MainWindow.hh
                 ${SOURCE_DIR}/UtilWidget.hh
                 ${SOURCE_DIR}/MainWindow.cc)
set(VERSION 1.0.0)
set(UI_RESOUCE_FILE resource.xml)

project(${PROJECT_NAME})
execute_process(
        COMMAND
        ${PKG_CONFIG_EXECUTABLE} gio-2.0 --variable glib_compile_resources
        OUTPUT_VARIABLE
        GLIB_COMPILE_RESOURCES_EXECUTABLE
        OUTPUT_STRIP_TRAILING_WHITESPACE)
if (NOT GLIB_COMPILE_RESOURCES_EXECUTABLE)
    #message(SEND_ERROR "Unable to find glib-compile-resources executable")
endif(NOT GLIB_COMPILE_RESOURCES_EXECUTABLE)

add_custom_command(
        OUTPUT
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_resources.c
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_resources.h
        COMMAND
        ${GLIB_COMPILE_RESOURCES_EXECUTABLE}
        --target=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_resources.c
        --sourcedir=${CMAKE_CURRENT_SOURCE_DIR}
        --generate-source
        --c-name ${PROJECT_NAME}
        ${UI_RESOUCE_FILE}
        COMMAND
        ${GLIB_COMPILE_RESOURCES_EXECUTABLE}
        --target=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_resources.h
        --sourcedir=${CMAKE_CURRENT_SOURCE_DIR}
        --generate-header
        --c-name ${PROJECT_NAME}
        ${UI_RESOUCE_FILE}
        WORKING_DIRECTORY
        ${CMAKE_CURRENT_SOURCE_DIR})
set(RESOURCE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_resources.h
             ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_resources.c)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${RESOURCE})

find_package(PkgConfig)
pkg_check_modules(LIBGTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(LIBGLIBMM REQUIRED glibmm-2.4)
include_directories(${LIBGTKMM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${LIBGTKMM_LIBRARIES})
include_directories(${LIBGLIBMM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${LIBGLIBMMLIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${VERSION})
