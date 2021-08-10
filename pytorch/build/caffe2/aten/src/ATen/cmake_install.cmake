# Install script for directory: /home/lichangheng/robo_ws/pytorch/aten/src/ATen

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/caffe2/aten/src/ATen/cmake-exports/ATenConfig.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Dispatch.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/div_rtn.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/CPUFixedAllocator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Formatting.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/DeviceGuard.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/TensorUtils.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Version.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/DimVector.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/ATen.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/SmallVector.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/ExpandUtils.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/dlpack.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/CPUApplyUtils.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Context.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/InferSize.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Scalar.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Device.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/WrapDimUtilsMulti.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/ScalarOps.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/TensorOptions.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/DLConvertor.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/OpaqueTensorImpl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/SparseTensorImpl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/NumericUtils.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/AccumulateType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Parallel.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/TensorGeometry.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Storage.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cpp_custom_type_hack.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Generator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/LegacyTHDispatch.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Config.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Utils.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/SparseTensorUtils.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/ScalarType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/ArrayRef.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/WrapDimUtils.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Type.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Layout.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/CPUTypeDefault.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/TensorOperators.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Tensor.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/MemoryOverlap.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/TensorAccessor.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Backend.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/InitialTensorOptions.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/Backtrace.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/MatrixRef.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/UndefinedType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/CheckGenerator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/detail" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/detail/CUDAHooksInterface.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/detail" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/detail/HIPHooksInterface.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/detail" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/detail/CPUGuardImpl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/detail" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/detail/ScalarTypeConversions.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/detail" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/detail/FunctionTraits.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/detail" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/detail/ComplexHooksInterface.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cpu" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cpu/vml.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cpu" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cpu/FlushDenormal.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/SparseTensorRef.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/function_schema.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/Formatting.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/TensorMethods.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/DimVector.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/blob.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/Scalar.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/stack.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/jit_type.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/VariableHooksInterface.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/UndefinedTensorImpl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/Reduction.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/LegacyTypeDispatch.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/Range.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/Generator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/context_base.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/function_schema_inl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/op_registration" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/op_registration/op_registration.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/op_registration" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/op_registration/test_helpers.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/op_registration" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/op_registration/kernel_function.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/op_registration" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/op_registration/kernel_functor.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/op_registration" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/op_registration/infer_schema.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/op_registration" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/op_registration/dispatch_key.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/op_registration" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/op_registration/base.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/op_registration" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/op_registration/kernel_stackbased.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/op_registration" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/op_registration/kernel_lambda.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/LegacyDeviceTypeInit.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/ScalarType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/Macros.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/aten_interned_strings.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/interned_strings_class.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/Type.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/Tensor.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/TensorAccessor.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/interned_strings.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/ivalue.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/DeprecatedTypePropertiesRegistry.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/typeid.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/Backtrace.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/functional.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/ATenGeneral.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/alias_info.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/DeprecatedTypeProperties.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/dispatch" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/dispatch/Dispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/dispatch" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/dispatch/KernelFunction.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/dispatch" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/dispatch/KernelCache.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/dispatch" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/dispatch/DispatchTable.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/../../../../torch/csrc/jit" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/../../../../torch/csrc/jit/source_range.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/../../../../torch/csrc/jit" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/../../../../torch/csrc/jit/source_location.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/../../../../torch/csrc/jit/script" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/../../../../torch/csrc/jit/script/function_schema_parser.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/../../../../torch/csrc/jit/script" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/../../../../torch/csrc/jit/script/lexer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/../../../../torch/csrc/jit/script" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/../../../../torch/csrc/jit/script/strtod.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/../../../../torch/csrc/jit/script" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/../../../../torch/csrc/jit/script/parse_string_literal.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/../../../../torch/csrc/jit/script" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/../../../../torch/csrc/jit/script/schema_type_parser.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/../../../../torch/csrc/jit/script" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/../../../../torch/csrc/jit/script/error_report.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/core/../../../../torch/csrc/jit/script" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/core/../../../../torch/csrc/jit/script/tree.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/CUDAConfig.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/CUDAMultiStreamGuard.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/CUDAUtils.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/Exceptions.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/PinnedMemoryAllocator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/CUDAEvent.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/CUDADevice.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/Array.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/ATenCUDAGeneral.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/CUDAContext.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/CUDATypeDefault.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/_curand_mtgp32_host.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda/detail" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/detail/CUDAHooks.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda/detail" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/detail/KernelUtils.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/CUDATensorMethods.cuh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/CUDAApplyUtils.cuh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/NumericLimits.cuh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda/detail" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/detail/OffsetCalculator.cuh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda/detail" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/detail/IndexUtils.cuh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cuda/detail" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cuda/detail/TensorInfo.cuh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cudnn" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cudnn/Exceptions.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cudnn" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cudnn/Handles.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cudnn" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cudnn/Types.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cudnn" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cudnn/Descriptors.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cudnn" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cudnn/Handle.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cudnn" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cudnn/Utils.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/cudnn" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/cudnn/cudnn-wrapper.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/miopen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/miopen/Exceptions.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/miopen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/miopen/miopen-wrapper.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/miopen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/miopen/Types.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/miopen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/miopen/Descriptors.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/miopen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/miopen/Handle.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen/miopen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/aten/src/ATen/miopen/Utils.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/CPUGenerator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/CPUType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/ExtensionBackendRegistration.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/Functions.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCPUBoolDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCPUByteDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCPUCharDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCPUDoubleDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCPUFloatDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCPUHalfDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCPUIntDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCPULongDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCPUQInt8Dispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCPUShortDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHFunctions.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHQuantizedCPUQInt8Dispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/MSNPUType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/MkldnnCPUType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/NativeFunctions.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/QuantizedCPUType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/RegisterCPU.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/SparseCPUType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/TypeDefault.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/TypeExtendedInterface.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/XLAType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/CUDAGenerator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/CUDAType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCUDABoolDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCUDAByteDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCUDACharDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCUDADoubleDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCUDAFloatDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCUDAHalfDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCUDAIntDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCUDALongDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCUDAQInt8Dispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/LegacyTHCUDAShortDispatcher.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/RegisterCUDA.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/SparseCUDAType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ATen" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/aten/src/ATen/Declarations.yaml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/aten/src/ATen/core/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/aten/src/ATen/quantized/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/sleef/cmake_install.cmake")
  include("/home/lichangheng/robo_ws/pytorch/build/caffe2/aten/src/ATen/test/cmake_install.cmake")

endif()

