# Install script for directory: /home/lichangheng/robo_ws/pytorch/aten/src/TH

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/TH" TYPE FILE MESSAGE_NEVER FILES
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/TH.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THAllocator.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THMath.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THBlas.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THDiskFile.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THFile.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THFilePrivate.h"
    "/home/lichangheng/robo_ws/pytorch/build/caffe2/aten/src/TH/THGeneral.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateAllTypes.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateBoolType.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateDoubleType.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateFloatType.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateHalfType.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateLongType.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateIntType.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateShortType.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateCharType.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateByteType.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateFloatTypes.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerateIntTypes.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THLapack.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THLogAdd.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THMemoryFile.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THRandom.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THSize.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THStorage.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THStorageFunctions.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THTensor.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THTensorApply.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THTensorDimApply.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THVector.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THHalf.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THTensor.hpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THStorageFunctions.hpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/THGenerator.hpp"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/TH/vector" TYPE FILE MESSAGE_NEVER FILES
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/vector/AVX.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/vector/AVX2.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/../ATen/native/cpu/avx_mathfun.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/TH/generic" TYPE FILE MESSAGE_NEVER FILES
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THBlas.cpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THBlas.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THLapack.cpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THLapack.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THStorage.cpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THStorage.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THStorageCopy.cpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THStorageCopy.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensor.cpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensor.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensor.hpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensorConv.cpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensorConv.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensorFill.cpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensorFill.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensorLapack.cpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensorLapack.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensorMath.cpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensorMath.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensorRandom.cpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensorRandom.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THVectorDispatch.cpp"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THVector.h"
    "/home/lichangheng/robo_ws/pytorch/aten/src/TH/generic/THTensorFastGetSet.hpp"
    )
endif()

