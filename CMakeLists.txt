cmake_minimum_required(VERSION 3.30)

set(CMAKE_BUILD_TYPE Debug)

project(spectralanalysis VERSION 1.0 DESCRIPTION "Spectral data analyzer and optical modelling.")

add_library(moremath)

target_sources(moremath
  PUBLIC
    src/moremath/dawson.hpp
  PRIVATE
    src/moremath/dawson.cpp
)

target_include_directories(moremath
  PUBLIC
    src/moremath
)

add_library(oscillators)

target_sources(oscillators
  PUBLIC
    src/oscillators/constants.hpp
    src/oscillators/types.hpp
    src/oscillators/genosc.hpp
    src/oscillators/drude.hpp
  PRIVATE
    src/oscillators/genosc.cpp
    src/oscillators/drude.cpp
  )

target_include_directories(oscillators
  PUBLIC
    src/oscillators
  )

target_link_libraries(oscillators PRIVATE moremath)

add_executable(spectralanalysis)

target_sources(spectralanalysis
  PRIVATE
    src/spectralanalysis.cpp
)

target_link_libraries(spectralanalysis PRIVATE oscillators)
