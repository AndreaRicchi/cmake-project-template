cmake_minimum_required(VERSION 3.14)

project(
  library_template
  VERSION 1.0.0
  LANGUAGES CXX C)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/StandardProjectSettings.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/PreventInSourceBuilds.cmake)

option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
option(ENABLE_TESTING "Enable Test Builds" OFF)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

file(GLOB_RECURSE PROJECT_HEADERS include/*.hpp)
file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)

add_library(${PROJECT_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES}
                            ${PROJECT_MISC})

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
         $<INSTALL_INTERFACE:include>
  PRIVATE src)

if(NOT BUILD_SHARED_LIBS)
  string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)
  set_target_properties(${PROJECT_NAME}
                        PROPERTIES COMPILE_FLAGS -D${PROJECT_NAME_UPPER}_STATIC)
else()
  set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION
                                                   ${CMAKE_PROJECT_VERSION})
endif()

# Used for symbol visibility
include(GenerateExportHeader)
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)
generate_export_header(
  ${PROJECT_NAME}
  EXPORT_FILE_NAME
  ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/export.hpp
  EXPORT_MACRO_NAME
  ${PROJECT_NAME_UPPER}_EXPORT
  STATIC_DEFINE
  ${PROJECT_NAME_UPPER}_STATIC)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}-config
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
install(EXPORT ${PROJECT_NAME}-config DESTINATION cmake)
export(TARGETS ${PROJECT_NAME} FILE ${PROJECT_NAME}-config.cmake)

if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()
