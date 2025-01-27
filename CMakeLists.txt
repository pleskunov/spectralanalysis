cmake_minimum_required(VERSION 3.30)

set(CMAKE_BUILD_TYPE Debug)

project(spectralanalysis VERSION 1.0 DESCRIPTION "Spectral data analyzer and optical modelling.")

add_library(oscillators)

target_sources(oscillators
  PUBLIC
    src/oscillators/genosc.hpp
  PRIVATE
    src/oscillators/genosc.cpp
  )

target_include_directories(oscillators
  PUBLIC
    src/oscillators
  )

add_executable(spectralanalysis)

target_sources(spectralanalysis
  PRIVATE
    src/spectralanalysis.cpp
)

target_link_libraries(spectralanalysis PRIVATE oscillators)
