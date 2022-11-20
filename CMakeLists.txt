cmake_minimum_required(VERSION 3.14)

project(
  lib_template
  VERSION 1.0.0
  LANGUAGES CXX C)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/StandardProjectSettings.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/PreventInSourceBuilds.cmake)

option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
option(ENABLE_TESTING "Enable Test Builds" OFF)

add_subdirectory(include)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-config)
install(DIRECTORY include/ DESTINATION include)
install(EXPORT ${PROJECT_NAME}-config DESTINATION cmake)
export(TARGETS ${PROJECT_NAME} FILE ${PROJECT_NAME}-config.cmake)

if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()
