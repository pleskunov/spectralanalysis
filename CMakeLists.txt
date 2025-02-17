cmake_minimum_required(VERSION 3.30)

set(CMAKE_BUILD_TYPE Debug)

project(spectralanalysis VERSION 1.0 DESCRIPTION "Spectral data analyzer and optical modelling.")

add_library(moremath)

target_sources(moremath
  PUBLIC
    src/moremath/Constants.hpp
    src/moremath/Chebyshev.hpp
    src/moremath/Faddeeva.hpp
    src/moremath/Dawson.hpp
  PRIVATE
    src/moremath/Chebyshev.cpp
    src/moremath/Faddeeva.cpp
    src/moremath/Dawson.cpp
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
    src/oscillators/lorentz.hpp
    src/oscillators/harmonic.hpp
    src/oscillators/gaussian.hpp

  PRIVATE
    src/oscillators/genosc.cpp
    src/oscillators/drude.cpp
    src/oscillators/lorentz.cpp
    src/oscillators/harmonic.cpp
    src/oscillators/gaussian.cpp
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
