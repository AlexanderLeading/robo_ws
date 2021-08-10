// required for old g++ to compile PRId64 macros, see
// https://github.com/pytorch/pytorch/issues/3571
// for context
#define __STDC_FORMAT_MACROS

#include <ATen/SparseCPUType.h>

// @generated by aten/src/ATen/gen.py

#include <ATen/CPUGenerator.h>
#include <c10/core/Allocator.h>
#include <ATen/DeviceGuard.h>
#include <ATen/NativeFunctions.h>
#include <ATen/Utils.h>
#include <ATen/WrapDimUtils.h>
#include <ATen/Dispatch.h>
#include <c10/util/Half.h>
#include <c10/core/UndefinedTensorImpl.h>
#include <c10/util/Optional.h>

#include <cstddef>
#include <functional>
#include <memory>
#include <utility>

#include <ATen/Config.h>


namespace at {

SparseCPUType::SparseCPUType()
  : CPUTypeDefault(SparseCPUTensorId(), /*is_variable=*/false, /*is_undefined=*/false) {}
Backend SparseCPUType::backend() const {
  return Backend::SparseCPU;
}

const char * SparseCPUType::toString() const {
  return "SparseCPUType";
}

TypeID SparseCPUType::ID() const {
  return TypeID::SparseCPU;
}

Tensor SparseCPUType::add(const Tensor & self, const Tensor & other, Scalar alpha) const {
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
            return at::native::add(/* actuals */ self, other, alpha);
        break;
        default:
            AT_ERROR("add not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::add_(Tensor & self, const Tensor & other, Scalar alpha) const {
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
            return at::native::add_(/* actuals */ self, other, alpha);
        break;
        default:
            AT_ERROR("add_ not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::add_out(Tensor & out, const Tensor & self, const Tensor & other, Scalar alpha) const {
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
            return at::native::add_out(/* actuals */ out, self, other, alpha);
        break;
        default:
            AT_ERROR("add_out not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::empty(IntArrayRef size, const TensorOptions & options) const {
    const DeviceGuard device_guard(options.device());
    auto dispatch_scalar_type = typeMetaToScalarType(options.dtype());
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
            return at::native::empty_sparse(/* actuals */ size, options);
        break;
        default:
            AT_ERROR("empty not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::log1p_(Tensor & self) const {
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
            return at::native::log1p_sparse_(/* actuals */ self);
        break;
        default:
            AT_ERROR("log1p_ not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::log1p_out(Tensor & out, const Tensor & self) const {
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
            return at::native::log1p_out_sparse(/* actuals */ out, self);
        break;
        default:
            AT_ERROR("log1p_out not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::narrow_copy(const Tensor & self, int64_t dim, int64_t start, int64_t length) const {
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
            return at::native::narrow_copy_sparse(/* actuals */ self, dim, start, length);
        break;
        default:
            AT_ERROR("narrow_copy not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::_sparse_add_out(Tensor & out, const Tensor & self, const Tensor & other, Scalar alpha) const {
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
            return at::native::add_out_sparse_cpu(/* actuals */ out, self, other, alpha);
        break;
        default:
            AT_ERROR("_sparse_add_out not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::_sparse_div_zerodim_out(Tensor & out, const Tensor & self, const Tensor & other) const {
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
            return at::native::div_out_sparse_zerodim(/* actuals */ out, self, other);
        break;
        default:
            AT_ERROR("_sparse_div_zerodim_out not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::_sparse_div_scalar_out(Tensor & out, const Tensor & self, Scalar other) const {
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
            return at::native::div_out_sparse_scalar(/* actuals */ out, self, other);
        break;
        default:
            AT_ERROR("_sparse_div_scalar_out not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::_sparse_mul_out(Tensor & out, const Tensor & self, const Tensor & other) const {
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
            return at::native::mul_out_sparse_cpu(/* actuals */ out, self, other);
        break;
        default:
            AT_ERROR("_sparse_mul_out not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::_sparse_mul_zerodim_out(Tensor & out, const Tensor & self, const Tensor & other) const {
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
            return at::native::mul_out_sparse_zerodim(/* actuals */ out, self, other);
        break;
        default:
            AT_ERROR("_sparse_mul_zerodim_out not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::_sparse_mul_scalar_out(Tensor & out, const Tensor & self, Scalar other) const {
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
            return at::native::mul_out_sparse_scalar(/* actuals */ out, self, other);
        break;
        default:
            AT_ERROR("_sparse_mul_scalar_out not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::sspaddmm_out(Tensor & out, const Tensor & self, const Tensor & mat1, const Tensor & mat2, Scalar beta, Scalar alpha) const {
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
            return at::native::_sspaddmm_out_cpu(/* actuals */ out, self, mat1, mat2, beta, alpha);
        break;
        default:
            AT_ERROR("sspaddmm_out not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::native_norm(const Tensor & self, Scalar p) const {
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
            return at::native::norm_sparse(/* actuals */ self, p);
        break;
        default:
            AT_ERROR("native_norm not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::_sparse_sum_backward(const Tensor & grad, const Tensor & self, IntArrayRef dim) const {
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
            return at::native::_sparse_sum_backward_cpu(/* actuals */ grad, self, dim);
        break;
        default:
            AT_ERROR("_sparse_sum_backward not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::clone(const Tensor & self) const {
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
            return at::native::clone_sparse(/* actuals */ self);
        break;
        default:
            AT_ERROR("clone not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::resize_as_(Tensor & self, const Tensor & the_template) const {
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
            return at::native::resize_as_sparse_(/* actuals */ self, the_template);
        break;
        default:
            AT_ERROR("resize_as_ not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::pow_out(Tensor & out, const Tensor & self, Scalar exponent) const {
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
            return at::native::pow_out_sparse_scalar(/* actuals */ out, self, exponent);
        break;
        default:
            AT_ERROR("pow_out not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::pow(const Tensor & self, Scalar exponent) const {
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
            return at::native::pow_sparse_scalar(/* actuals */ self, exponent);
        break;
        default:
            AT_ERROR("pow not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::zero_(Tensor & self) const {
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
            return at::native::zero_sparse_(/* actuals */ self);
        break;
        default:
            AT_ERROR("zero_ not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::_sparse_coo_tensor_with_dims(int64_t sparse_dim, int64_t dense_dim, IntArrayRef size, const TensorOptions & options) const {
    const DeviceGuard device_guard(options.device());
    auto dispatch_scalar_type = typeMetaToScalarType(options.dtype());
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
            return at::native::new_with_dims_sparse(/* actuals */ sparse_dim, dense_dim, size, options);
        break;
        default:
            AT_ERROR("_sparse_coo_tensor_with_dims not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::_sparse_coo_tensor_with_dims_and_tensors(int64_t sparse_dim, int64_t dense_dim, IntArrayRef size, const Tensor & indices, const Tensor & values, const TensorOptions & options) const {
    const DeviceGuard device_guard(options.device());
    auto dispatch_scalar_type = typeMetaToScalarType(options.dtype());
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
            return at::native::new_with_dims_and_tensor_sparse(/* actuals */ sparse_dim, dense_dim, size, indices, values, options);
        break;
        default:
            AT_ERROR("_sparse_coo_tensor_with_dims_and_tensors not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::sparse_resize_(Tensor & self, IntArrayRef size, int64_t sparse_dim, int64_t dense_dim) const {
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
            return at::native::sparse_resize_(/* actuals */ self, size, sparse_dim, dense_dim);
        break;
        default:
            AT_ERROR("sparse_resize_ not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::sparse_resize_and_clear_(Tensor & self, IntArrayRef size, int64_t sparse_dim, int64_t dense_dim) const {
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
            return at::native::sparse_resize_and_clear_(/* actuals */ self, size, sparse_dim, dense_dim);
        break;
        default:
            AT_ERROR("sparse_resize_and_clear_ not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::to_dense(const Tensor & self) const {
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
            return at::native::sparse_to_dense(/* actuals */ self);
        break;
        default:
            AT_ERROR("to_dense not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
int64_t SparseCPUType::sparse_dim(const Tensor & self) const {
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
            return at::native::sparse_dim_sparse(/* actuals */ self);
        break;
        default:
            AT_ERROR("sparse_dim not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
int64_t SparseCPUType::dense_dim(const Tensor & self) const {
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
            return at::native::dense_dim_sparse(/* actuals */ self);
        break;
        default:
            AT_ERROR("dense_dim not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
int64_t SparseCPUType::_nnz(const Tensor & self) const {
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
            return at::native::_nnz_sparse(/* actuals */ self);
        break;
        default:
            AT_ERROR("_nnz not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::coalesce(const Tensor & self) const {
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
            return at::native::coalesce_sparse_cpu(/* actuals */ self);
        break;
        default:
            AT_ERROR("coalesce not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
bool SparseCPUType::is_coalesced(const Tensor & self) const {
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
            return at::native::is_coalesced_sparse(/* actuals */ self);
        break;
        default:
            AT_ERROR("is_coalesced not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::_indices(const Tensor & self) const {
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
            return at::native::_indices_sparse(/* actuals */ self);
        break;
        default:
            AT_ERROR("_indices not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::_values(const Tensor & self) const {
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
            return at::native::_values_sparse(/* actuals */ self);
        break;
        default:
            AT_ERROR("_values not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::_coalesced_(Tensor & self, bool coalesced) const {
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
            return at::native::_coalesced_sparse_(/* actuals */ self, coalesced);
        break;
        default:
            AT_ERROR("_coalesced_ not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::indices(const Tensor & self) const {
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
            return at::native::indices_sparse(/* actuals */ self);
        break;
        default:
            AT_ERROR("indices not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::values(const Tensor & self) const {
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
            return at::native::values_sparse(/* actuals */ self);
        break;
        default:
            AT_ERROR("values not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::hspmm_out(Tensor & out, const Tensor & mat1, const Tensor & mat2) const {
    const OptionalDeviceGuard device_guard(device_of(out));
    auto dispatch_scalar_type = infer_scalar_type(out);
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
            return at::native::hspmm_out_sparse_cpu(/* actuals */ out, mat1, mat2);
        break;
        default:
            AT_ERROR("hspmm_out not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor SparseCPUType::hspmm(const Tensor & mat1, const Tensor & mat2) const {
    const OptionalDeviceGuard device_guard(device_of(mat1));
    auto dispatch_scalar_type = infer_scalar_type(mat1);
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
            return at::native::hspmm_sparse_cpu(/* actuals */ mat1, mat2);
        break;
        default:
            AT_ERROR("hspmm not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}
Tensor & SparseCPUType::copy_sparse_to_sparse_(Tensor & self, const Tensor & src, bool non_blocking) const {
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
            return at::native::copy_sparse_(/* actuals */ self, src, non_blocking);
        break;
        default:
            AT_ERROR("copy_sparse_to_sparse_ not supported on SparseCPUType for ", dispatch_scalar_type);
    }
}

}
