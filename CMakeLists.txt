cmake_minimum_required(VERSION 3.0)

project(dt)

set (FLAGS "-std=c++1z -g")
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${FLAGS})
set (SRC_DIR ./src)
set (EXTLIB_DIR ./extlibs)
include_directories(${SRC_DIR})
include_directories(${EXTLIB_DIR})

set (EXTLIB_H
  ${EXTLIB_DIR}/tinyxml2.h
)

set (EXTLIB_CPP
  ${EXTLIB_DIR}/tinyxml2.cpp
)

set (SRC_H
  ${SRC_DIR}/defines.h
  ${SRC_DIR}/xjx.h
  ${SRC_DIR}/xml_iterator.h
)

set (SRC_CPP
  ${SRC_DIR}/xjx.cpp
  ${SRC_DIR}/xml_iterator.cpp
)

add_executable(xjx ${SRC_DIR}/main.cpp ${SRC_H} ${SRC_CPP} ${EXTLIB_H} ${EXTLIB_CPP})
