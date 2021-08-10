# Install script for directory: /home/lichangheng/robo_ws/pytorch/caffe2

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/cmake/../caffe2" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/caffe2/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/caffe2/core/macros.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaffe2.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaffe2.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaffe2.so"
         RPATH "$ORIGIN:/usr/lib/openmpi/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/lib/libcaffe2.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaffe2.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaffe2.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaffe2.so"
         OLD_RPATH "/usr/lib/openmpi/lib:/home/lichangheng/robo_ws/pytorch/build/lib:"
         NEW_RPATH "$ORIGIN:/usr/lib/openmpi/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaffe2.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/aten/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/torch/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/proto/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/contrib/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/core/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/utils/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/predictor/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/predictor/emulator/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/core/nomnigraph/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/serialize/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/db/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/distributed/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/ideep/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/image/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/video/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/mobile/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/mpi/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/observers/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/onnx/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/operators/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/operators/rnn/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/operators/quantized/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/opt/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/python/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/queue/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/sgd/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/share/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/transforms/cmake_install.cmake")

endif()

