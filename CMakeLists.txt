cmake_minimum_required(VERSION 3.9)

include(ExternalProject)

project(g3log_issue)
set (CMAKE_CXX_STANDARD 11)

option( LOG_IN_DLL "Initialize logger on loading dll" ON )

set( G3LOG_SOURCE_DIR "${CMAKE_SOURCE_DIR}/3rd/g3log" )
set( G3LOG_BINARY_DIR "${CMAKE_BINARY_DIR}/3rd/g3log" )

set( G3LOG_INCLUDE_DIR "${G3LOG_SOURCE_DIR}/src;${G3LOG_BINARY_DIR}/include/" )
set( G3LOG_LIBRARY_DIR "${G3LOG_BINARY_DIR}" )
set( G3LOG_LIBRARY     "${G3LOG_LIBRARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}g3logger${CMAKE_STATIC_LIBRARY_SUFFIX}" )

message( "G3LOG_INCLUDE_DIR = ${G3LOG_INCLUDE_DIR}" )

externalproject_add(g3log
  URL              https://github.com/KjellKod/g3log/archive/1.3.2.tar.gz
  URL_HASH         SHA1=88e4fa3f4380be3e11abe692f47c993e8b61c31e
  SOURCE_DIR       "${G3LOG_SOURCE_DIR}"
  BINARY_DIR       "${G3LOG_BINARY_DIR}"
  CMAKE_ARGS       -DG3_SHARED_LIB=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCMAKE_MACOSX_RPATH=1 -DADD_FATAL_EXAMPLE=OFF
  INSTALL_COMMAND  ""
  )

find_package(Threads)
    
add_library(
  foo
  SHARED
  lib/lib.cpp)

add_dependencies(foo g3log)

target_include_directories(
  foo
  PUBLIC
  ${G3LOG_INCLUDE_DIR}
  )


target_link_libraries(
  foo
  PUBLIC
  ${G3LOG_LIBRARY}
  ${CMAKE_THREAD_LIBS_INIT})


if(LOG_IN_DLL)
  target_compile_definitions(
    foo
    PUBLIC
    LOG_IN_DLL=1 )
endif()


add_executable(
  bar
  ${CMAKE_SOURCE_DIR}/app/app.cpp
  )


target_include_directories(
  bar
  PUBLIC ${CMAKE_SOURCE_DIR}
  )


target_link_libraries(
  bar
  PUBLIC foo
  )


if(LOG_IN_DLL)
  target_compile_definitions(
    bar
    PUBLIC
    LOG_IN_DLL=1 )
endif()


