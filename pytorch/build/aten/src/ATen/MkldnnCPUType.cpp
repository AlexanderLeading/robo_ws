// required for old g++ to compile PRId64 macros, see
// https://github.com/pytorch/pytorch/issues/3571
// for context
#define __STDC_FORMAT_MACROS

#include <ATen/MkldnnCPUType.h>

// @generated by aten/src/ATen/gen.py

#include <TH/TH.h>
#include <TH/THTensor.hpp>
#include <THNN/THNN.h>
#undef THNN_
#include <c10/core/TensorImpl.h>
#include <ATen/CPUGenerator.h>
#include <c10/core/Allocator.h>
#include <ATen/DeviceGuard.h>
#include <ATen/NativeFunctions.h>
#include <ATen/Utils.h>
#include <ATen/WrapDimUtils.h>
#include <ATen/Dispatch.h>
#include <c10/util/Half.h>
#include <c10/core/TensorImpl.h>
#include <c10/core/UndefinedTensorImpl.h>
#include <c10/util/Optional.h>

#include <cstddef>
#include <functional>
#include <memory>
#include <utility>

#include <ATen/Config.h>


namespace at {

MkldnnCPUType::MkldnnCPUType()
  : CPUTypeDefault(MkldnnCPUTensorId(), /*is_variable=*/false, /*is_undefined=*/false) {}

Backend MkldnnCPUType::backend() const {
  return Backend::MkldnnCPU;
}

const char * MkldnnCPUType::toString() const {
  return "MkldnnCPUType";
}

TypeID MkldnnCPUType::ID() const {
  return TypeID::MkldnnCPU;
}

/* example
Tensor * MkldnnCPUType::add(Tensor & a, Tensor & b) {
  std::cout << "add Tensor with backend MkldnnCPU\n";
  return &a;
}
*/

Tensor MkldnnCPUType::add(const Tensor & self, const Tensor & other, Scalar alpha) const {
    const OptionalDeviceGuard device_guard(device_of(self));
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_add(/* actuals */ self, other, alpha);
        break;
        default:
            AT_ERROR("add not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor & MkldnnCPUType::add_(Tensor & self, const Tensor & other, Scalar alpha) const {
    const OptionalDeviceGuard device_guard(device_of(self));
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_add_(/* actuals */ self, other, alpha);
        break;
        default:
            AT_ERROR("add_ not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor & MkldnnCPUType::add_out(Tensor & out, const Tensor & self, const Tensor & other, Scalar alpha) const {
    const OptionalDeviceGuard device_guard(device_of(self));
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_add_out(/* actuals */ out, self, other, alpha);
        break;
        default:
            AT_ERROR("add_out not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor MkldnnCPUType::mkldnn_linear(const Tensor & input, const Tensor & weight, const Tensor & bias) const {
    const OptionalDeviceGuard device_guard(device_of(input));
    auto dispatch_scalar_type = infer_scalar_type(input);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_linear(/* actuals */ input, weight, bias);
        break;
        default:
            AT_ERROR("mkldnn_linear not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor MkldnnCPUType::mkldnn_max_pool2d(const Tensor & self, IntArrayRef kernel_size, IntArrayRef stride, IntArrayRef padding, IntArrayRef dilation, bool ceil_mode) const {
    const OptionalDeviceGuard device_guard(device_of(self));
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_max_pool2d(/* actuals */ self, kernel_size, stride, padding, dilation, ceil_mode);
        break;
        default:
            AT_ERROR("mkldnn_max_pool2d not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
std::tuple<Tensor,Tensor,Tensor> MkldnnCPUType::native_batch_norm(const Tensor & input, const Tensor & weight, const Tensor & bias, const Tensor & running_mean, const Tensor & running_var, bool training, double momentum, double eps) const {
    const OptionalDeviceGuard device_guard(device_of(input));
    auto dispatch_scalar_type = infer_scalar_type(input);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_batch_norm(/* actuals */ input, weight, bias, running_mean, running_var, training, momentum, eps);
        break;
        default:
            AT_ERROR("native_batch_norm not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor MkldnnCPUType::mkldnn_reshape(const Tensor & self, IntArrayRef shape) const {
    // DeviceGuard omitted
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_reshape(/* actuals */ self, shape);
        break;
        default:
            AT_ERROR("mkldnn_reshape not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor MkldnnCPUType::relu(const Tensor & self) const {
    const OptionalDeviceGuard device_guard(device_of(self));
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_relu(/* actuals */ self);
        break;
        default:
            AT_ERROR("relu not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor & MkldnnCPUType::relu_(Tensor & self) const {
    const OptionalDeviceGuard device_guard(device_of(self));
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_relu_(/* actuals */ self);
        break;
        default:
            AT_ERROR("relu_ not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor MkldnnCPUType::clone(const Tensor & self) const {
    const OptionalDeviceGuard device_guard(device_of(self));
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_clone(/* actuals */ self);
        break;
        default:
            AT_ERROR("clone not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor MkldnnCPUType::to_dense(const Tensor & self) const {
    const OptionalDeviceGuard device_guard(device_of(self));
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_to_dense(/* actuals */ self);
        break;
        default:
            AT_ERROR("to_dense not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor MkldnnCPUType::mkldnn_reorder_conv2d_weight(const Tensor & self, IntArrayRef padding, IntArrayRef stride, IntArrayRef dilation, int64_t groups) const {
    const OptionalDeviceGuard device_guard(device_of(self));
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_reorder_conv2d_weight(/* actuals */ self, padding, stride, dilation, groups);
        break;
        default:
            AT_ERROR("mkldnn_reorder_conv2d_weight not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor & MkldnnCPUType::avg_pool2d_out(Tensor & out, const Tensor & self, IntArrayRef kernel_size, IntArrayRef stride, IntArrayRef padding, bool ceil_mode, bool count_include_pad) const {
    const OptionalDeviceGuard device_guard(device_of(self));
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_avg_pool2d_out(/* actuals */ out, self, kernel_size, stride, padding, ceil_mode, count_include_pad);
        break;
        default:
            AT_ERROR("avg_pool2d_out not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}
Tensor MkldnnCPUType::avg_pool2d(const Tensor & self, IntArrayRef kernel_size, IntArrayRef stride, IntArrayRef padding, bool ceil_mode, bool count_include_pad) const {
    const OptionalDeviceGuard device_guard(device_of(self));
    auto dispatch_scalar_type = infer_scalar_type(self);
    switch (dispatch_scalar_type) {
        case ScalarType::Bool:
        case ScalarType::Byte:
        case ScalarType::Char:
        case ScalarType::Double:
        case ScalarType::Float:
        case ScalarType::Half:
        case ScalarType::Int:
        case ScalarType::Long:
        case ScalarType::QInt8:
        case ScalarType::Short:
            return at::native::mkldnn_avg_pool2d(/* actuals */ self, kernel_size, stride, padding, ceil_mode, count_include_pad);
        break;
        default:
            AT_ERROR("avg_pool2d not supported on MkldnnCPUType for ", dispatch_scalar_type);
    }
}

}
