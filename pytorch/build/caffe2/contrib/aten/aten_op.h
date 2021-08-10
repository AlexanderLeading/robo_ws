#pragma once
#include <unordered_map>
#include <string>
#include <ATen/ATen.h>
#include <caffe2/core/context.h>
#include <caffe2/core/operator.h>
#include <caffe2/utils/math.h>
#include <iostream>

// a map from descriptor strings (see [DESCRIPTORS])
// to the key in the switch statement that implements them
static std::unordered_map<std::string, int> op_to_key = {
  { "_th_is_set_to-2", 0 },
  { "_th_masked_select-2", 1 },
  { "_th_nonzero-1", 2 },
  { "_th_clone-1", 3 },
  { "_th_view-size-1", 4 },
  { "_th_index_select-dim-2", 5 },
  { "_th_take-2", 6 },
  { "_th_unfold-dimension-size-step-1", 7 },
  { "_th_gather-dim-2", 8 },
  { "_th_equal-2", 9 },
  { "_th_and-other-1", 10 },
  { "_th_and-2", 11 },
  { "_th_or-other-1", 12 },
  { "_th_or-2", 13 },
  { "_th_xor-other-1", 14 },
  { "_th_xor-2", 15 },
  { "_th_lshift-other-1", 16 },
  { "_th_lshift-2", 17 },
  { "_th_rshift-other-1", 18 },
  { "_th_rshift-2", 19 },
  { "_th_lt-other-1", 20 },
  { "_th_lt-2", 21 },
  { "_th_gt-other-1", 22 },
  { "_th_gt-2", 23 },
  { "_th_le-other-1", 24 },
  { "_th_le-2", 25 },
  { "_th_ge-other-1", 26 },
  { "_th_ge-2", 27 },
  { "_th_eq-other-1", 28 },
  { "_th_eq-2", 29 },
  { "_th_ne-other-1", 30 },
  { "_th_ne-2", 31 },
  { "_th_min-2", 32 },
  { "_th_min-1", 33 },
  { "_th_min-dim-keepdim-1", 34 },
  { "_th_min-dim-1", 35 },
  { "_th_max-2", 36 },
  { "_th_max-1", 37 },
  { "_th_max-dim-keepdim-1", 38 },
  { "_th_max-dim-1", 39 },
  { "_th_mode-dim-keepdim-1", 40 },
  { "_th_mode-dim-1", 41 },
  { "_th_mode-1", 42 },
  { "_th_sort-descending-dim-1", 43 },
  { "_th_sort-dim-1", 44 },
  { "_th_sort-1", 45 },
  { "_th_topk-dim-k-largest-sorted-1", 46 },
  { "_th_topk-dim-k-largest-1", 47 },
  { "_th_topk-dim-k-1", 48 },
  { "_th_topk-k-1", 49 },
  { "_th_abs-1", 50 },
  { "_th_sigmoid-1", 51 },
  { "_th_log-1", 52 },
  { "_th_log10-1", 53 },
  { "_th_log1p-1", 54 },
  { "_th_log2-1", 55 },
  { "_th_lgamma-1", 56 },
  { "_th_digamma-1", 57 },
  { "_th_polygamma-n-1", 58 },
  { "_th_exp-1", 59 },
  { "_th_expm1-1", 60 },
  { "_th_cos-1", 61 },
  { "_th_acos-1", 62 },
  { "_th_cosh-1", 63 },
  { "_th_sin-1", 64 },
  { "_th_asin-1", 65 },
  { "_th_sinh-1", 66 },
  { "_th_tan-1", 67 },
  { "_th_atan-1", 68 },
  { "_th_tanh-1", 69 },
  { "_th_erf-1", 70 },
  { "_th_erfc-1", 71 },
  { "_th_erfinv-1", 72 },
  { "_th_sqrt-1", 73 },
  { "_th_rsqrt-1", 74 },
  { "_th_ceil-1", 75 },
  { "_th_floor-1", 76 },
  { "_th_round-1", 77 },
  { "_th_trunc-1", 78 },
  { "_th_frac-1", 79 },
  { "_th_var-dim-keepdim-unbiased-1", 80 },
  { "_th_var-dim-unbiased-1", 81 },
  { "_th_var-dim-1", 82 },
  { "_th_var-unbiased-1", 83 },
  { "_th_var-1", 84 },
  { "_th_std-dim-keepdim-unbiased-1", 85 },
  { "_th_std-dim-unbiased-1", 86 },
  { "_th_std-dim-1", 87 },
  { "_th_std-unbiased-1", 88 },
  { "_th_std-1", 89 },
  { "_th_renorm-dim-maxnorm-p-1", 90 },
  { "_th_dist-p-2", 91 },
  { "_th_dist-2", 92 },
  { "_th_reciprocal-1", 93 },
  { "_th_neg-1", 94 },
  { "_th_atan2-2", 95 },
  { "_th_pow-exponent-1", 96 },
  { "_th_pow-2", 97 },
  { "_th_pow-self-1", 98 },
  { "_th_histc-bins-max-min-1", 99 },
  { "_th_histc-bins-min-1", 100 },
  { "_th_histc-bins-1", 101 },
  { "_th_histc-1", 102 },
  { "_th_cumsum-dim-1", 103 },
  { "_th_cumprod-dim-1", 104 },
  { "_th_sign-1", 105 },
  { "_th_trace-1", 106 },
  { "_th_fmod-other-1", 107 },
  { "_th_fmod-2", 108 },
  { "_th_remainder-other-1", 109 },
  { "_th_remainder-2", 110 },
  { "_th_clamp-max-min-1", 111 },
  { "_th_clamp_min-min-1", 112 },
  { "_th_clamp_max-max-1", 113 },
  { "_th_dot-2", 114 },
  { "_th_cross_kernel-dim-2", 115 },
  { "_th_diag-diagonal-1", 116 },
  { "_th_diag-1", 117 },
  { "_th_addmm-alpha-beta-3", 118 },
  { "_th_addmm-beta-3", 119 },
  { "_th_addmm-3", 120 },
  { "_th_addmv-alpha-beta-3", 121 },
  { "_th_addmv-beta-3", 122 },
  { "_th_addmv-3", 123 },
  { "_th_addr-alpha-beta-3", 124 },
  { "_th_addr-beta-3", 125 },
  { "_th_addr-3", 126 },
  { "_th_ger-2", 127 },
  { "_th_mv-2", 128 },
  { "_th_mm-2", 129 },
  { "_th_bmm-2", 130 },
  { "_th_addbmm-alpha-beta-3", 131 },
  { "_th_addbmm-beta-3", 132 },
  { "_th_addbmm-3", 133 },
  { "_th_baddbmm-alpha-beta-3", 134 },
  { "_th_baddbmm-beta-3", 135 },
  { "_th_baddbmm-3", 136 },
  { "_th_addcmul-value-3", 137 },
  { "_th_addcmul-3", 138 },
  { "_th_addcdiv-value-3", 139 },
  { "_th_addcdiv-3", 140 },
  { "_th_gels-2", 141 },
  { "_th_symeig-eigenvectors-upper-1", 142 },
  { "_th_symeig-eigenvectors-1", 143 },
  { "_th_symeig-1", 144 },
  { "_th_eig-eigenvectors-1", 145 },
  { "_th_eig-1", 146 },
  { "_th_svd-compute_uv-some-1", 147 },
  { "_th_svd-some-1", 148 },
  { "_th_svd-1", 149 },
  { "_th_getri_single-1", 150 },
  { "_th_potri-upper-1", 151 },
  { "_th_potri-1", 152 },
  { "_th_pstrf-tol-upper-1", 153 },
  { "_th_pstrf-upper-1", 154 },
  { "_th_pstrf-1", 155 },
  { "_th_qr-1", 156 },
  { "_th_geqrf-1", 157 },
  { "_th_orgqr-2", 158 },
  { "_th_ormqr-left-transpose-3", 159 },
  { "_th_ormqr-left-3", 160 },
  { "_th_ormqr-3", 161 },
  { "_th_btrisolve-3", 162 },
  { "_th_multinomial_alias_setup-1", 163 },
  { "_th_multinomial_alias_draw-num_samples-2", 164 },
  { "_th_multinomial-num_samples-replacement-1", 165 },
  { "_th_multinomial-num_samples-1", 166 },
  { "_th_normal-std-1", 167 },
  { "_th_normal-1", 168 },
  { "_th_normal-mean-1", 169 },
  { "_th_normal-2", 170 },
  { "_th_dirichlet_grad-3", 171 },
  { "_th_alias-1", 172 },
  { "_th_cat-dim-*", 173 },
  { "_th_cat-*", 174 },
  { "_thnn_binary_cross_entropy_forward-reduction-3", 175 },
  { "_thnn_binary_cross_entropy_backward-reduction-4", 176 },
  { "_thnn_l1_loss_forward-reduction-2", 177 },
  { "_thnn_l1_loss_backward-reduction-3", 178 },
  { "_thnn_mse_loss_forward-reduction-2", 179 },
  { "_thnn_mse_loss_backward-reduction-3", 180 },
  { "_thnn_multi_margin_loss_forward-margin-p-reduction-3", 181 },
  { "_thnn_multi_margin_loss_backward-margin-p-reduction-4", 182 },
  { "_thnn_multilabel_margin_loss_forward-reduction-2", 183 },
  { "_thnn_multilabel_margin_loss_backward-reduction-4", 184 },
  { "_thnn_nll_loss_forward-ignore_index-reduction-3", 185 },
  { "_thnn_nll_loss_backward-ignore_index-reduction-5", 186 },
  { "_thnn_nll_loss2d_forward-ignore_index-reduction-3", 187 },
  { "_thnn_nll_loss2d_backward-ignore_index-reduction-5", 188 },
  { "_thnn_smooth_l1_loss_forward-reduction-2", 189 },
  { "_thnn_smooth_l1_loss_backward-reduction-3", 190 },
  { "_thnn_soft_margin_loss_forward-reduction-2", 191 },
  { "_thnn_soft_margin_loss_backward-reduction-3", 192 },
  { "_thnn_elu_forward-alpha-input_scale-scale-1", 193 },
  { "_thnn_elu_backward-alpha-input_scale-scale-2", 194 },
  { "_thnn_glu_forward-dim-1", 195 },
  { "_thnn_glu_backward-dim-2", 196 },
  { "_thnn_hardtanh_forward-max_val-min_val-1", 197 },
  { "_thnn_hardtanh_backward-max_val-min_val-2", 198 },
  { "_thnn_leaky_relu_forward-negative_slope-1", 199 },
  { "_thnn_leaky_relu_backward-negative_slope-2", 200 },
  { "_thnn_log_sigmoid_forward-1", 201 },
  { "_thnn_log_sigmoid_backward-3", 202 },
  { "_thnn_rrelu_with_noise_backward-lower-training-upper-3", 203 },
  { "_thnn_softplus_forward-beta-threshold-1", 204 },
  { "_thnn_softplus_backward-beta-threshold-3", 205 },
  { "_thnn_softshrink_forward-lambd-1", 206 },
  { "_thnn_softshrink_backward-lambd-2", 207 },
  { "_thnn_adaptive_avg_pool3d_forward-output_size-1", 208 },
  { "_thnn_adaptive_avg_pool3d_backward-2", 209 },
  { "_thnn_avg_pool2d_forward-ceil_mode-count_include_pad-kernel_size-padding-stride-1", 210 },
  { "_thnn_avg_pool2d_backward-ceil_mode-count_include_pad-kernel_size-padding-stride-2", 211 },
  { "_thnn_avg_pool3d_forward-ceil_mode-count_include_pad-kernel_size-padding-stride-1", 212 },
  { "_thnn_avg_pool3d_backward-ceil_mode-count_include_pad-kernel_size-padding-stride-2", 213 },
  { "_thnn_max_pool2d_with_indices_forward-ceil_mode-dilation-kernel_size-padding-stride-1", 214 },
  { "_thnn_max_pool2d_with_indices_backward-ceil_mode-dilation-kernel_size-padding-stride-3", 215 },
  { "_thnn_max_pool3d_with_indices_forward-ceil_mode-dilation-kernel_size-padding-stride-1", 216 },
  { "_thnn_max_pool3d_with_indices_backward-ceil_mode-dilation-kernel_size-padding-stride-3", 217 },
  { "_thnn_max_unpool2d_forward-output_size-2", 218 },
  { "_thnn_max_unpool2d_backward-output_size-3", 219 },
  { "_thnn_max_unpool3d_forward-output_size-padding-stride-2", 220 },
  { "_thnn_max_unpool3d_backward-output_size-padding-stride-3", 221 },
  { "_thnn_upsample_linear1d_forward-align_corners-output_size-1", 222 },
  { "_thnn_upsample_linear1d_backward-align_corners-input_size-output_size-1", 223 },
  { "_thnn_upsample_bilinear2d_forward-align_corners-output_size-1", 224 },
  { "_thnn_upsample_bilinear2d_backward-align_corners-input_size-output_size-1", 225 },
  { "_thnn_upsample_bicubic2d_forward-align_corners-output_size-1", 226 },
  { "_thnn_upsample_bicubic2d_backward-align_corners-input_size-output_size-1", 227 },
  { "_thnn_upsample_trilinear3d_forward-align_corners-output_size-1", 228 },
  { "_thnn_upsample_trilinear3d_backward-align_corners-input_size-output_size-1", 229 },
  { "_thnn_upsample_nearest1d_forward-output_size-1", 230 },
  { "_thnn_upsample_nearest1d_backward-input_size-output_size-1", 231 },
  { "_thnn_upsample_nearest2d_forward-output_size-1", 232 },
  { "_thnn_upsample_nearest2d_backward-input_size-output_size-1", 233 },
  { "_thnn_upsample_nearest3d_forward-output_size-1", 234 },
  { "_thnn_upsample_nearest3d_backward-input_size-output_size-1", 235 },
  { "_thnn_sigmoid_forward-1", 236 },
  { "_thnn_sigmoid_backward-2", 237 },
  { "_thnn_tanh_forward-1", 238 },
  { "_thnn_tanh_backward-2", 239 },
  { "_thnn_conv_transpose2d_forward-dilation-kernel_size-output_padding-padding-stride-3", 240 },
  { "_thnn_conv_transpose2d_backward-dilation-kernel_size-output_padding-padding-stride-5", 241 },
  { "_thnn_conv_transpose3d_forward-dilation-kernel_size-output_padding-padding-stride-3", 242 },
  { "_thnn_conv_transpose3d_backward-dilation-kernel_size-output_padding-padding-stride-5", 243 },
  { "_thnn_conv2d_forward-kernel_size-padding-stride-3", 244 },
  { "_thnn_conv2d_backward-kernel_size-padding-stride-5", 245 },
  { "_thnn_conv_depthwise2d_forward-dilation-kernel_size-padding-stride-3", 246 },
  { "_thnn_conv_depthwise2d_backward-dilation-kernel_size-padding-stride-3", 247 },
  { "_thnn_conv3d_forward-kernel_size-padding-stride-3", 248 },
  { "_thnn_conv3d_backward-kernel_size-padding-stride-5", 249 },
  { "_thnn_conv_dilated2d_forward-dilation-kernel_size-padding-stride-3", 250 },
  { "_thnn_conv_dilated2d_backward-dilation-kernel_size-padding-stride-5", 251 },
  { "_thnn_conv_dilated3d_forward-dilation-kernel_size-padding-stride-3", 252 },
  { "_thnn_conv_dilated3d_backward-dilation-kernel_size-padding-stride-5", 253 },
  { "_thnn_col2im_forward-dilation-kernel_size-output_size-padding-stride-1", 254 },
  { "_thnn_col2im_backward-dilation-kernel_size-padding-stride-1", 255 },
  { "_thnn_im2col_forward-dilation-kernel_size-padding-stride-1", 256 },
  { "_thnn_im2col_backward-dilation-input_size-kernel_size-padding-stride-1", 257 },
  { "_cast_Byte-non_blocking-1", 258 },
  { "_cast_Byte-1", 259 },
  { "_cast_Char-non_blocking-1", 260 },
  { "_cast_Char-1", 261 },
  { "_cast_Double-non_blocking-1", 262 },
  { "_cast_Double-1", 263 },
  { "_cast_Float-non_blocking-1", 264 },
  { "_cast_Float-1", 265 },
  { "_cast_Int-non_blocking-1", 266 },
  { "_cast_Int-1", 267 },
  { "_cast_Long-non_blocking-1", 268 },
  { "_cast_Long-1", 269 },
  { "_cast_Short-non_blocking-1", 270 },
  { "_cast_Short-1", 271 },
  { "_cast_Half-non_blocking-1", 272 },
  { "_cast_Half-1", 273 },
  { "_cudnn_ctc_loss-blank-deterministic-input_lengths-target_lengths-zero_infinity-2", 274 },
  { "_cudnn_rnn_flatten_weight-batch_first-bidirectional-hidden_size-input_size-mode-num_layers-weight_stride0-*", 275 },
  { "_cudnn_rnn-batch_first-batch_sizes-bidirectional-dropout-hidden_size-mode-num_layers-train-weight_stride0-*", 276 },
  { "_debug_has_internal_overlap-1", 277 },
  { "_fused_dropout-p-1", 278 },
  { "_masked_scale-scale-2", 279 },
  { "_reshape_from_tensor-2", 280 },
  { "_shape_as_tensor-1", 281 },
  { "dropout-p-train-1", 282 },
  { "feature_dropout-p-train-1", 283 },
  { "alpha_dropout-p-train-1", 284 },
  { "feature_alpha_dropout-p-train-1", 285 },
  { "abs-1", 286 },
  { "acos-1", 287 },
  { "avg_pool1d-ceil_mode-count_include_pad-kernel_size-padding-stride-1", 288 },
  { "avg_pool1d-ceil_mode-kernel_size-padding-stride-1", 289 },
  { "avg_pool1d-kernel_size-padding-stride-1", 290 },
  { "avg_pool1d-kernel_size-stride-1", 291 },
  { "avg_pool1d-kernel_size-1", 292 },
  { "adaptive_avg_pool1d-output_size-1", 293 },
  { "adaptive_max_pool1d-output_size-1", 294 },
  { "add-alpha-2", 295 },
  { "add-2", 296 },
  { "add-alpha-other-1", 297 },
  { "add-other-1", 298 },
  { "addmv-alpha-beta-3", 299 },
  { "addmv-beta-3", 300 },
  { "addmv-3", 301 },
  { "addr-alpha-beta-3", 302 },
  { "addr-beta-3", 303 },
  { "addr-3", 304 },
  { "affine_grid_generator-size-1", 305 },
  { "affine_grid_generator_backward-size-1", 306 },
  { "all-dim-keepdim-1", 307 },
  { "all-dim-1", 308 },
  { "allclose-atol-equal_nan-rtol-2", 309 },
  { "allclose-atol-rtol-2", 310 },
  { "allclose-rtol-2", 311 },
  { "allclose-2", 312 },
  { "any-dim-keepdim-1", 313 },
  { "any-dim-1", 314 },
  { "_dim_arange-dim-1", 315 },
  { "argmax-1", 316 },
  { "argmin-1", 317 },
  { "as_strided-size-stride-1", 318 },
  { "asin-1", 319 },
  { "atan-1", 320 },
  { "baddbmm-alpha-beta-3", 321 },
  { "baddbmm-beta-3", 322 },
  { "baddbmm-3", 323 },
  { "batch_norm-cudnn_enabled-eps-momentum-training-5", 324 },
  { "_batch_norm_impl_index-cudnn_enabled-eps-momentum-training-5", 325 },
  { "bernoulli-1", 326 },
  { "bernoulli-p-1", 327 },
  { "bilinear-4", 328 },
  { "binary_cross_entropy_with_logits-reduction-4", 329 },
  { "binary_cross_entropy_with_logits_backward-reduction-5", 330 },
  { "bincount-minlength-2", 331 },
  { "bincount-2", 332 },
  { "bincount-1", 333 },
  { "bmm-2", 334 },
  { "broadcast_tensors-*", 335 },
  { "cat-dim-*", 336 },
  { "cat-*", 337 },
  { "ceil-1", 338 },
  { "chain_matmul-*", 339 },
  { "chunk-chunks-dim-1", 340 },
  { "chunk-chunks-1", 341 },
  { "clamp-1", 342 },
  { "clamp_max-max-1", 343 },
  { "clamp_min-min-1", 344 },
  { "cudnn_is_acceptable-1", 345 },
  { "constant_pad_nd-pad-value-1", 346 },
  { "constant_pad_nd-pad-1", 347 },
  { "contiguous-1", 348 },
  { "convolution-dilation-groups-output_padding-padding-stride-transposed-3", 349 },
  { "_convolution-benchmark-cudnn_enabled-deterministic-dilation-groups-output_padding-padding-stride-transposed-3", 350 },
  { "_convolution_nogroup-dilation-output_padding-padding-stride-transposed-3", 351 },
  { "conv1d-dilation-groups-padding-stride-3", 352 },
  { "conv1d-dilation-padding-stride-3", 353 },
  { "conv1d-padding-stride-3", 354 },
  { "conv1d-stride-3", 355 },
  { "conv1d-3", 356 },
  { "conv1d-2", 357 },
  { "conv2d-dilation-groups-padding-stride-3", 358 },
  { "conv2d-dilation-padding-stride-3", 359 },
  { "conv2d-padding-stride-3", 360 },
  { "conv2d-stride-3", 361 },
  { "conv2d-3", 362 },
  { "conv2d-2", 363 },
  { "conv3d-dilation-groups-padding-stride-3", 364 },
  { "conv3d-dilation-padding-stride-3", 365 },
  { "conv3d-padding-stride-3", 366 },
  { "conv3d-stride-3", 367 },
  { "conv3d-3", 368 },
  { "conv3d-2", 369 },
  { "conv_tbc-pad-3", 370 },
  { "conv_tbc-3", 371 },
  { "conv_tbc_backward-pad-4", 372 },
  { "conv_transpose1d-dilation-groups-output_padding-padding-stride-3", 373 },
  { "conv_transpose1d-groups-output_padding-padding-stride-3", 374 },
  { "conv_transpose1d-output_padding-padding-stride-3", 375 },
  { "conv_transpose1d-padding-stride-3", 376 },
  { "conv_transpose1d-stride-3", 377 },
  { "conv_transpose1d-3", 378 },
  { "conv_transpose1d-2", 379 },
  { "conv_transpose2d-dilation-groups-output_padding-padding-stride-3", 380 },
  { "conv_transpose2d-groups-output_padding-padding-stride-3", 381 },
  { "conv_transpose2d-output_padding-padding-stride-3", 382 },
  { "conv_transpose2d-padding-stride-3", 383 },
  { "conv_transpose2d-stride-3", 384 },
  { "conv_transpose2d-3", 385 },
  { "conv_transpose2d-2", 386 },
  { "conv_transpose3d-dilation-groups-output_padding-padding-stride-3", 387 },
  { "conv_transpose3d-groups-output_padding-padding-stride-3", 388 },
  { "conv_transpose3d-output_padding-padding-stride-3", 389 },
  { "conv_transpose3d-padding-stride-3", 390 },
  { "conv_transpose3d-stride-3", 391 },
  { "conv_transpose3d-3", 392 },
  { "conv_transpose3d-2", 393 },
  { "_s_copy_from-non_blocking-2", 394 },
  { "_s_copy_from-2", 395 },
  { "cos-1", 396 },
  { "cosh-1", 397 },
  { "cosine_embedding_loss-margin-reduction-3", 398 },
  { "cosine_embedding_loss-margin-3", 399 },
  { "cosine_embedding_loss-3", 400 },
  { "cudnn_affine_grid_generator-C-H-N-W-1", 401 },
  { "cudnn_affine_grid_generator_backward-C-H-N-W-1", 402 },
  { "cudnn_batch_norm-epsilon-exponential_average_factor-training-5", 403 },
  { "cudnn_batch_norm_backward-epsilon-7", 404 },
  { "cudnn_convolution-benchmark-deterministic-dilation-groups-padding-stride-3", 405 },
  { "cudnn_convolution_backward_input-benchmark-deterministic-dilation-groups-padding-self_size-stride-2", 406 },
  { "cudnn_convolution_backward_bias-1", 407 },
  { "cudnn_convolution_backward_weight-benchmark-deterministic-dilation-groups-padding-stride-weight_size-2", 408 },
  { "cudnn_convolution_transpose-benchmark-deterministic-dilation-groups-output_padding-padding-stride-3", 409 },
  { "cudnn_convolution_transpose_backward_bias-1", 410 },
  { "cudnn_convolution_transpose_backward_input-benchmark-deterministic-dilation-groups-padding-stride-2", 411 },
  { "cudnn_convolution_transpose_backward_weight-benchmark-deterministic-dilation-groups-padding-stride-weight_size-2", 412 },
  { "cudnn_grid_sampler-2", 413 },
  { "cudnn_grid_sampler_backward-3", 414 },
  { "cumsum-dim-1", 415 },
  { "cumprod-dim-1", 416 },
  { "ctc_loss-blank-input_lengths-reduction-target_lengths-zero_infinity-2", 417 },
  { "ctc_loss-blank-input_lengths-reduction-target_lengths-2", 418 },
  { "ctc_loss-blank-input_lengths-target_lengths-2", 419 },
  { "ctc_loss-input_lengths-target_lengths-2", 420 },
  { "ctc_loss-blank-reduction-zero_infinity-4", 421 },
  { "ctc_loss-blank-reduction-4", 422 },
  { "ctc_loss-blank-4", 423 },
  { "ctc_loss-4", 424 },
  { "_ctc_loss-blank-input_lengths-target_lengths-zero_infinity-2", 425 },
  { "_ctc_loss-blank-input_lengths-target_lengths-2", 426 },
  { "_ctc_loss-input_lengths-target_lengths-2", 427 },
  { "_ctc_loss_backward-blank-input_lengths-target_lengths-zero_infinity-5", 428 },
  { "_ctc_loss_backward-blank-input_lengths-target_lengths-5", 429 },
  { "det-1", 430 },
  { "diag_embed-dim1-dim2-offset-1", 431 },
  { "diag_embed-dim1-offset-1", 432 },
  { "diag_embed-offset-1", 433 },
  { "diag_embed-1", 434 },
  { "diagflat-offset-1", 435 },
  { "diagflat-1", 436 },
  { "diagonal-dim1-dim2-offset-1", 437 },
  { "diagonal-dim1-offset-1", 438 },
  { "diagonal-offset-1", 439 },
  { "diagonal-1", 440 },
  { "div-2", 441 },
  { "div-other-1", 442 },
  { "dot-2", 443 },
  { "embedding-padding_idx-scale_grad_by_freq-sparse-2", 444 },
  { "embedding-padding_idx-scale_grad_by_freq-2", 445 },
  { "embedding-padding_idx-2", 446 },
  { "embedding-2", 447 },
  { "embedding_backward-num_weights-padding_idx-scale_grad_by_freq-sparse-2", 448 },
  { "embedding_dense_backward-num_weights-padding_idx-scale_grad_by_freq-2", 449 },
  { "embedding_sparse_backward-num_weights-padding_idx-scale_grad_by_freq-2", 450 },
  { "embedding_bag-mode-scale_grad_by_freq-sparse-4", 451 },
  { "embedding_bag-mode-scale_grad_by_freq-sparse-3", 452 },
  { "embedding_bag-mode-scale_grad_by_freq-3", 453 },
  { "embedding_bag-scale_grad_by_freq-3", 454 },
  { "embedding_bag-3", 455 },
  { "_embedding_bag-mode-scale_grad_by_freq-sparse-4", 456 },
  { "_embedding_bag-mode-scale_grad_by_freq-sparse-3", 457 },
  { "_embedding_bag-mode-scale_grad_by_freq-3", 458 },
  { "_embedding_bag-scale_grad_by_freq-3", 459 },
  { "_embedding_bag-3", 460 },
  { "_embedding_bag_backward-mode-num_weights-scale_grad_by_freq-sparse-7", 461 },
  { "_embedding_bag_sparse_backward-mode-num_weights-scale_grad_by_freq-6", 462 },
  { "_embedding_bag_dense_backward-mode-num_weights-scale_grad_by_freq-7", 463 },
  { "_embedding_bag_per_sample_weights_backward-mode-5", 464 },
  { "erf-1", 465 },
  { "erfc-1", 466 },
  { "exp-1", 467 },
  { "expm1-1", 468 },
  { "expand-implicit-size-1", 469 },
  { "expand-size-1", 470 },
  { "expand_as-2", 471 },
  { "flatten-end_dim-start_dim-1", 472 },
  { "flatten-start_dim-1", 473 },
  { "flatten-1", 474 },
  { "floor-1", 475 },
  { "frac-1", 476 },
  { "grid_sampler-interpolation_mode-padding_mode-2", 477 },
  { "grid_sampler_2d-interpolation_mode-padding_mode-2", 478 },
  { "grid_sampler_2d_backward-interpolation_mode-padding_mode-3", 479 },
  { "grid_sampler_3d-interpolation_mode-padding_mode-2", 480 },
  { "grid_sampler_3d_backward-interpolation_mode-padding_mode-3", 481 },
  { "hinge_embedding_loss-margin-reduction-2", 482 },
  { "hinge_embedding_loss-margin-2", 483 },
  { "hinge_embedding_loss-2", 484 },
  { "ger-2", 485 },
  { "group_norm-cudnn_enabled-eps-num_groups-3", 486 },
  { "group_norm-eps-num_groups-3", 487 },
  { "group_norm-num_groups-3", 488 },
  { "group_norm-num_groups-2", 489 },
  { "group_norm-num_groups-1", 490 },
  { "fft-normalized-signal_ndim-1", 491 },
  { "fft-signal_ndim-1", 492 },
  { "ifft-normalized-signal_ndim-1", 493 },
  { "ifft-signal_ndim-1", 494 },
  { "rfft-normalized-onesided-signal_ndim-1", 495 },
  { "rfft-normalized-signal_ndim-1", 496 },
  { "rfft-signal_ndim-1", 497 },
  { "irfft-normalized-onesided-signal_ndim-signal_sizes-1", 498 },
  { "irfft-normalized-onesided-signal_ndim-1", 499 },
  { "irfft-normalized-signal_ndim-1", 500 },
  { "irfft-signal_ndim-1", 501 },
  { "_fft_with_size-checked_signal_sizes-complex_input-complex_output-inverse-normalized-onesided-output_sizes-signal_ndim-1", 502 },
  { "_cufft_get_plan_cache_size-device_index-0", 503 },
  { "_cufft_get_plan_cache_max_size-device_index-0", 504 },
  { "index-*", 505 },
  { "index_copy-dim-3", 506 },
  { "index_put-accumulate-*", 507 },
  { "index_put-*", 508 },
  { "instance_norm-cudnn_enabled-eps-momentum-use_input_stats-5", 509 },
  { "inverse-1", 510 },
  { "_inverse_helper-1", 511 },
  { "isclose-atol-equal_nan-rtol-2", 512 },
  { "isclose-atol-rtol-2", 513 },
  { "isclose-rtol-2", 514 },
  { "isclose-2", 515 },
  { "isnan-1", 516 },
  { "is_distributed-1", 517 },
  { "is_floating_point-1", 518 },
  { "is_complex-1", 519 },
  { "is_nonzero-1", 520 },
  { "is_same_size-2", 521 },
  { "is_signed-1", 522 },
  { "kl_div-reduction-2", 523 },
  { "kl_div-2", 524 },
  { "kl_div_backward-reduction-3", 525 },
  { "kl_div_backward-3", 526 },
  { "kthvalue-dim-k-keepdim-1", 527 },
  { "kthvalue-dim-k-1", 528 },
  { "kthvalue-k-1", 529 },
  { "layer_norm-cudnn_enable-eps-normalized_shape-3", 530 },
  { "layer_norm-eps-normalized_shape-3", 531 },
  { "layer_norm-normalized_shape-3", 532 },
  { "layer_norm-normalized_shape-2", 533 },
  { "layer_norm-normalized_shape-1", 534 },
  { "linear-3", 535 },
  { "linear-2", 536 },
  { "mkldnn_linear-3", 537 },
  { "mkldnn_linear-2", 538 },
  { "fbgemm_linear_int8_weight-weight_scale-weight_zero_point-5", 539 },
  { "fbgemm_pack_quantized_matrix-K-N-1", 540 },
  { "fbgemm_is_cpu_supported-0", 541 },
  { "log-1", 542 },
  { "log10-1", 543 },
  { "log1p-1", 544 },
  { "log2-1", 545 },
  { "logdet-1", 546 },
  { "log_softmax-dim-1", 547 },
  { "_log_softmax-dim-half_to_float-1", 548 },
  { "_log_softmax_backward_data-dim-3", 549 },
  { "logsumexp-dim-keepdim-1", 550 },
  { "logsumexp-dim-1", 551 },
  { "margin_ranking_loss-margin-reduction-3", 552 },
  { "margin_ranking_loss-margin-3", 553 },
  { "margin_ranking_loss-3", 554 },
  { "matmul-2", 555 },
  { "matrix_rank-symmetric-tol-1", 556 },
  { "matrix_rank-tol-1", 557 },
  { "matrix_rank-symmetric-1", 558 },
  { "matrix_rank-1", 559 },
  { "matrix_power-n-1", 560 },
  { "max-dim-keepdim-1", 561 },
  { "max-dim-1", 562 },
  { "max_values-dim-keepdim-1", 563 },
  { "max_values-dim-1", 564 },
  { "max_pool1d_with_indices-ceil_mode-dilation-kernel_size-padding-stride-1", 565 },
  { "max_pool1d_with_indices-dilation-kernel_size-padding-stride-1", 566 },
  { "max_pool1d_with_indices-kernel_size-padding-stride-1", 567 },
  { "max_pool1d_with_indices-kernel_size-stride-1", 568 },
  { "max_pool1d_with_indices-kernel_size-1", 569 },
  { "max_pool1d-ceil_mode-dilation-kernel_size-padding-stride-1", 570 },
  { "max_pool1d-dilation-kernel_size-padding-stride-1", 571 },
  { "max_pool1d-kernel_size-padding-stride-1", 572 },
  { "max_pool1d-kernel_size-stride-1", 573 },
  { "max_pool1d-kernel_size-1", 574 },
  { "max_pool2d-ceil_mode-dilation-kernel_size-padding-stride-1", 575 },
  { "max_pool2d-dilation-kernel_size-padding-stride-1", 576 },
  { "max_pool2d-kernel_size-padding-stride-1", 577 },
  { "max_pool2d-kernel_size-stride-1", 578 },
  { "max_pool2d-kernel_size-1", 579 },
  { "mkldnn_max_pool2d-ceil_mode-dilation-kernel_size-padding-stride-1", 580 },
  { "mkldnn_max_pool2d-dilation-kernel_size-padding-stride-1", 581 },
  { "mkldnn_max_pool2d-kernel_size-padding-stride-1", 582 },
  { "mkldnn_max_pool2d-kernel_size-stride-1", 583 },
  { "mkldnn_max_pool2d-kernel_size-1", 584 },
  { "max_pool3d-ceil_mode-dilation-kernel_size-padding-stride-1", 585 },
  { "max_pool3d-dilation-kernel_size-padding-stride-1", 586 },
  { "max_pool3d-kernel_size-padding-stride-1", 587 },
  { "max_pool3d-kernel_size-stride-1", 588 },
  { "max_pool3d-kernel_size-1", 589 },
  { "mean-1", 590 },
  { "mean-dim-keepdim-1", 591 },
  { "mean-dim-1", 592 },
  { "median-dim-keepdim-1", 593 },
  { "median-dim-1", 594 },
  { "min-dim-keepdim-1", 595 },
  { "min-dim-1", 596 },
  { "min_values-dim-keepdim-1", 597 },
  { "min_values-dim-1", 598 },
  { "mkldnn_convolution-dilation-groups-padding-stride-3", 599 },
  { "mkldnn_convolution_backward_input-bias_defined-dilation-groups-padding-self_size-stride-2", 600 },
  { "mkldnn_convolution_backward_weights-bias_defined-dilation-groups-padding-stride-weight_size-2", 601 },
  { "miopen_batch_norm-epsilon-exponential_average_factor-training-5", 602 },
  { "miopen_batch_norm_backward-epsilon-7", 603 },
  { "miopen_convolution-benchmark-deterministic-dilation-groups-padding-stride-3", 604 },
  { "miopen_convolution_backward_input-benchmark-deterministic-dilation-groups-padding-self_size-stride-2", 605 },
  { "miopen_convolution_backward_bias-1", 606 },
  { "miopen_convolution_backward_weight-benchmark-deterministic-dilation-groups-padding-stride-weight_size-2", 607 },
  { "miopen_convolution_transpose-benchmark-deterministic-dilation-groups-output_padding-padding-stride-3", 608 },
  { "miopen_convolution_transpose_backward_input-benchmark-deterministic-dilation-groups-padding-stride-2", 609 },
  { "miopen_convolution_transpose_backward_weight-benchmark-deterministic-dilation-groups-padding-stride-weight_size-2", 610 },
  { "miopen_depthwise_convolution-benchmark-deterministic-dilation-groups-padding-stride-3", 611 },
  { "miopen_depthwise_convolution_backward_input-benchmark-deterministic-dilation-groups-padding-self_size-stride-2", 612 },
  { "miopen_depthwise_convolution_backward_weight-benchmark-deterministic-dilation-groups-padding-stride-weight_size-2", 613 },
  { "mm-2", 614 },
  { "_sparse_mm-2", 615 },
  { "mode-dim-keepdim-1", 616 },
  { "mode-dim-1", 617 },
  { "mode-1", 618 },
  { "mul-2", 619 },
  { "mul-other-1", 620 },
  { "mv-2", 621 },
  { "mvlgamma-p-1", 622 },
  { "narrow_copy-dim-length-start-1", 623 },
  { "narrow-dim-length-start-1", 624 },
  { "native_batch_norm-eps-momentum-training-5", 625 },
  { "batch_norm_stats-eps-1", 626 },
  { "batch_norm_elemt-eps-5", 627 },
  { "batch_norm_gather_stats-count-eps-momentum-5", 628 },
  { "batch_norm_backward_reduce-bias_g-input_g-weight_g-4", 629 },
  { "batch_norm_backward_elemt-7", 630 },
  { "batch_norm_update_stats-momentum-3", 631 },
  { "_nnpack_available-0", 632 },
  { "_nnpack_spatial_convolution-padding-3", 633 },
  { "_nnpack_spatial_convolution_backward_input-padding-3", 634 },
  { "_nnpack_spatial_convolution_backward_weight-padding-weightsize-2", 635 },
  { "pairwise_distance-eps-keepdim-p-2", 636 },
  { "pairwise_distance-eps-p-2", 637 },
  { "pairwise_distance-p-2", 638 },
  { "pairwise_distance-2", 639 },
  { "cdist-p-2", 640 },
  { "cdist-2", 641 },
  { "_cdist_backward-p-4", 642 },
  { "pdist-p-1", 643 },
  { "pdist-1", 644 },
  { "_pdist_forward-p-1", 645 },
  { "_pdist_forward-1", 646 },
  { "_pdist_backward-p-3", 647 },
  { "cosine_similarity-dim-eps-2", 648 },
  { "cosine_similarity-dim-2", 649 },
  { "cosine_similarity-2", 650 },
  { "permute-dims-1", 651 },
  { "pixel_shuffle-upscale_factor-1", 652 },
  { "pin_memory-1", 653 },
  { "pinverse-rcond-1", 654 },
  { "pinverse-1", 655 },
  { "reciprocal-1", 656 },
  { "neg-1", 657 },
  { "repeat-repeats-1", 658 },
  { "repeat_interleave-1", 659 },
  { "repeat_interleave-2", 660 },
  { "repeat_interleave-repeats-1", 661 },
  { "reshape-shape-1", 662 },
  { "mkldnn_reshape-shape-1", 663 },
  { "reshape_as-2", 664 },
  { "round-1", 665 },
  { "rrelu-lower-training-upper-1", 666 },
  { "rrelu-lower-upper-1", 667 },
  { "rrelu-lower-1", 668 },
  { "rrelu-1", 669 },
  { "relu-1", 670 },
  { "prelu-2", 671 },
  { "prelu_backward-3", 672 },
  { "hardshrink-lambd-1", 673 },
  { "hardshrink-1", 674 },
  { "hardshrink_backward-lambd-2", 675 },
  { "rsqrt-1", 676 },
  { "select-dim-index-1", 677 },
  { "selu-1", 678 },
  { "celu-alpha-1", 679 },
  { "celu-1", 680 },
  { "sigmoid-1", 681 },
  { "sin-1", 682 },
  { "sinh-1", 683 },
  { "detach-1", 684 },
  { "size-dim-1", 685 },
  { "slice-dim-end-start-step-1", 686 },
  { "slice-dim-end-start-1", 687 },
  { "slice-dim-start-1", 688 },
  { "slice-dim-1", 689 },
  { "slice-1", 690 },
  { "slogdet-1", 691 },
  { "smm-2", 692 },
  { "softmax-dim-1", 693 },
  { "_softmax-dim-half_to_float-1", 694 },
  { "_softmax_backward_data-dim-3", 695 },
  { "split-dim-split_size-1", 696 },
  { "split-split_size-1", 697 },
  { "split_with_sizes-dim-split_sizes-1", 698 },
  { "split_with_sizes-split_sizes-1", 699 },
  { "squeeze-1", 700 },
  { "squeeze-dim-1", 701 },
  { "sspaddmm-alpha-beta-3", 702 },
  { "sspaddmm-beta-3", 703 },
  { "sspaddmm-3", 704 },
  { "stack-dim-*", 705 },
  { "stack-*", 706 },
  { "stft-n_fft-1", 707 },
  { "stride-dim-1", 708 },
  { "sum-1", 709 },
  { "sum-dim-keepdim-1", 710 },
  { "sum-dim-1", 711 },
  { "sum_to_size-size-1", 712 },
  { "sqrt-1", 713 },
  { "std-unbiased-1", 714 },
  { "std-1", 715 },
  { "std-dim-keepdim-unbiased-1", 716 },
  { "std-dim-unbiased-1", 717 },
  { "std-dim-1", 718 },
  { "prod-1", 719 },
  { "prod-dim-keepdim-1", 720 },
  { "prod-dim-1", 721 },
  { "t-1", 722 },
  { "tan-1", 723 },
  { "tanh-1", 724 },
  { "tensordot-dims_other-dims_self-2", 725 },
  { "threshold-threshold-value-1", 726 },
  { "threshold_backward-threshold-2", 727 },
  { "transpose-dim0-dim1-1", 728 },
  { "one_hot-num_classes-1", 729 },
  { "one_hot-1", 730 },
  { "flip-dims-1", 731 },
  { "roll-dims-shifts-1", 732 },
  { "roll-shifts-1", 733 },
  { "rot90-dims-k-1", 734 },
  { "rot90-k-1", 735 },
  { "rot90-1", 736 },
  { "_trilinear-expand1-expand2-expand3-sumdim-unroll_dim-3", 737 },
  { "_trilinear-expand1-expand2-expand3-sumdim-3", 738 },
  { "triplet_margin_loss-eps-margin-p-reduction-swap-3", 739 },
  { "triplet_margin_loss-eps-margin-p-swap-3", 740 },
  { "triplet_margin_loss-eps-margin-p-3", 741 },
  { "triplet_margin_loss-margin-p-3", 742 },
  { "triplet_margin_loss-margin-3", 743 },
  { "triplet_margin_loss-3", 744 },
  { "trunc-1", 745 },
  { "type_as-2", 746 },
  { "_unique-return_inverse-sorted-1", 747 },
  { "_unique-sorted-1", 748 },
  { "_unique-1", 749 },
  { "unique_dim-dim-return_counts-return_inverse-sorted-1", 750 },
  { "unique_dim-dim-return_inverse-sorted-1", 751 },
  { "unique_dim-dim-sorted-1", 752 },
  { "unique_dim-dim-1", 753 },
  { "unique_consecutive-return_counts-return_inverse-1", 754 },
  { "unique_consecutive-return_inverse-1", 755 },
  { "unique_consecutive-1", 756 },
  { "unique_dim_consecutive-dim-return_counts-return_inverse-1", 757 },
  { "unique_dim_consecutive-dim-return_inverse-1", 758 },
  { "unique_dim_consecutive-dim-1", 759 },
  { "_unique2-return_counts-return_inverse-sorted-1", 760 },
  { "_unique2-return_inverse-sorted-1", 761 },
  { "_unique2-sorted-1", 762 },
  { "_unique2-1", 763 },
  { "_unsafe_view-size-1", 764 },
  { "unsqueeze-dim-1", 765 },
  { "var-unbiased-1", 766 },
  { "var-1", 767 },
  { "var-dim-keepdim-unbiased-1", 768 },
  { "var-dim-unbiased-1", 769 },
  { "var-dim-1", 770 },
  { "view_as-2", 771 },
  { "where-3", 772 },
  { "_s_where-3", 773 },
  { "norm_except_dim-dim-pow-1", 774 },
  { "norm_except_dim-pow-1", 775 },
  { "norm_except_dim-1", 776 },
  { "_weight_norm-dim-2", 777 },
  { "_weight_norm-2", 778 },
  { "_weight_norm_cuda_interface-dim-2", 779 },
  { "_weight_norm_cuda_interface-2", 780 },
  { "_weight_norm_cuda_interface_backward-dim-4", 781 },
  { "_weight_norm_differentiable_backward-dim-4", 782 },
  { "_standard_gamma_grad-2", 783 },
  { "_standard_gamma-1", 784 },
  { "_sample_dirichlet-1", 785 },
  { "poisson-1", 786 },
  { "native_norm-p-1", 787 },
  { "native_norm-1", 788 },
  { "_sparse_sum-1", 789 },
  { "_sparse_sum-dim-1", 790 },
  { "_sparse_sum_backward-dim-2", 791 },
  { "norm-p-1", 792 },
  { "norm-1", 793 },
  { "frobenius_norm-1", 794 },
  { "frobenius_norm-dim-keepdim-1", 795 },
  { "frobenius_norm-dim-1", 796 },
  { "nuclear_norm-keepdim-1", 797 },
  { "nuclear_norm-1", 798 },
  { "clone-1", 799 },
  { "pow-exponent-1", 800 },
  { "sub-alpha-2", 801 },
  { "sub-2", 802 },
  { "sub-alpha-other-1", 803 },
  { "sub-other-1", 804 },
  { "rsub-alpha-2", 805 },
  { "rsub-2", 806 },
  { "rsub-alpha-other-1", 807 },
  { "rsub-other-1", 808 },
  { "s_native_addmm-alpha-beta-3", 809 },
  { "s_native_addmm-beta-3", 810 },
  { "s_native_addmm-3", 811 },
  { "_sparse_addmm-alpha-beta-3", 812 },
  { "_sparse_addmm-beta-3", 813 },
  { "_sparse_addmm-3", 814 },
  { "addmm-alpha-beta-3", 815 },
  { "addmm-beta-3", 816 },
  { "addmm-3", 817 },
  { "to_dense-1", 818 },
  { "to_dense_backward-2", 819 },
  { "sparse_dim-1", 820 },
  { "_dimI-1", 821 },
  { "dense_dim-1", 822 },
  { "_dimV-1", 823 },
  { "_nnz-1", 824 },
  { "coalesce-1", 825 },
  { "is_coalesced-1", 826 },
  { "_indices-1", 827 },
  { "_values-1", 828 },
  { "indices-1", 829 },
  { "values-1", 830 },
  { "hspmm-2", 831 },
  { "numel-1", 832 },
  { "unbind-dim-1", 833 },
  { "unbind-1", 834 },
  { "to_sparse-sparse_dim-1", 835 },
  { "to_sparse-1", 836 },
  { "to_mkldnn-1", 837 },
  { "mkldnn_reorder_conv2d_weight-dilation-groups-padding-stride-1", 838 },
  { "mkldnn_reorder_conv2d_weight-dilation-padding-stride-1", 839 },
  { "mkldnn_reorder_conv2d_weight-padding-stride-1", 840 },
  { "mkldnn_reorder_conv2d_weight-padding-1", 841 },
  { "mkldnn_reorder_conv2d_weight-1", 842 },
  { "to_mkldnn_backward-2", 843 },
  { "quantize_linear-scale-zero_point-1", 844 },
  { "dequantize-1", 845 },
  { "q_scale-1", 846 },
  { "q_zero_point-1", 847 },
  { "int_repr-1", 848 },
  { "meshgrid-*", 849 },
  { "cartesian_prod-*", 850 },
  { "combinations-r-with_replacement-1", 851 },
  { "combinations-r-1", 852 },
  { "combinations-1", 853 },
  { "item-1", 854 },
  { "_local_scalar_dense-1", 855 },
  { "_thnn_fused_lstm_cell-5", 856 },
  { "_thnn_fused_lstm_cell-4", 857 },
  { "_thnn_fused_lstm_cell-3", 858 },
  { "_thnn_fused_lstm_cell_backward-has_bias-5", 859 },
  { "_thnn_fused_gru_cell-5", 860 },
  { "_thnn_fused_gru_cell-4", 861 },
  { "_thnn_fused_gru_cell-3", 862 },
  { "_thnn_fused_gru_cell_backward-has_bias-2", 863 },
  { "lstm-batch_first-bidirectional-dropout-has_biases-num_layers-train-*", 864 },
  { "lstm-bidirectional-dropout-has_biases-num_layers-train-*", 865 },
  { "gru-batch_first-bidirectional-dropout-has_biases-num_layers-train-*", 866 },
  { "gru-bidirectional-dropout-has_biases-num_layers-train-*", 867 },
  { "rnn_tanh-batch_first-bidirectional-dropout-has_biases-num_layers-train-*", 868 },
  { "rnn_tanh-bidirectional-dropout-has_biases-num_layers-train-*", 869 },
  { "rnn_relu-batch_first-bidirectional-dropout-has_biases-num_layers-train-*", 870 },
  { "rnn_relu-bidirectional-dropout-has_biases-num_layers-train-*", 871 },
  { "lstm_cell-*", 872 },
  { "gru_cell-6", 873 },
  { "gru_cell-5", 874 },
  { "gru_cell-4", 875 },
  { "rnn_tanh_cell-6", 876 },
  { "rnn_tanh_cell-5", 877 },
  { "rnn_tanh_cell-4", 878 },
  { "rnn_relu_cell-6", 879 },
  { "rnn_relu_cell-5", 880 },
  { "rnn_relu_cell-4", 881 },
  { "quantized_lstm-batch_first-bidirectional-dropout-has_biases-num_layers-train-*", 882 },
  { "quantized_lstm_cell-scale_hh-scale_ih-zero_point_hh-zero_point_ih-*", 883 },
  { "quantized_gru_cell-scale_hh-scale_ih-zero_point_hh-zero_point_ih-10", 884 },
  { "quantized_rnn_relu_cell-scale_hh-scale_ih-zero_point_hh-zero_point_ih-10", 885 },
  { "quantized_rnn_tanh_cell-scale_hh-scale_ih-zero_point_hh-zero_point_ih-10", 886 },
  { "_pack_padded_sequence-batch_first-2", 887 },
  { "_pack_padded_sequence_backward-batch_first-input_size-2", 888 },
  { "_pad_packed_sequence-batch_first-padding_value-total_length-2", 889 },
  { "is_set_to-2", 890 },
  { "masked_fill-value-2", 891 },
  { "masked_fill-3", 892 },
  { "masked_scatter-3", 893 },
  { "view-size-1", 894 },
  { "index_add-dim-3", 895 },
  { "index_fill-dim-value-2", 896 },
  { "index_fill-dim-3", 897 },
  { "scatter-dim-3", 898 },
  { "scatter-dim-value-2", 899 },
  { "scatter_add-dim-3", 900 },
  { "__and__-other-1", 901 },
  { "__and__-2", 902 },
  { "__or__-other-1", 903 },
  { "__or__-2", 904 },
  { "__xor__-other-1", 905 },
  { "__xor__-2", 906 },
  { "__lshift__-other-1", 907 },
  { "__lshift__-2", 908 },
  { "__rshift__-other-1", 909 },
  { "__rshift__-2", 910 },
  { "addbmm-alpha-beta-3", 911 },
  { "addbmm-beta-3", 912 },
  { "addbmm-3", 913 },
  { "diag-diagonal-1", 914 },
  { "diag-1", 915 },
  { "cross-2", 916 },
  { "triu-diagonal-1", 917 },
  { "triu-1", 918 },
  { "tril-diagonal-1", 919 },
  { "tril-1", 920 },
  { "trace-1", 921 },
  { "ne-other-1", 922 },
  { "ne-2", 923 },
  { "eq-other-1", 924 },
  { "eq-2", 925 },
  { "ge-other-1", 926 },
  { "ge-2", 927 },
  { "le-other-1", 928 },
  { "le-2", 929 },
  { "gt-other-1", 930 },
  { "gt-2", 931 },
  { "lt-other-1", 932 },
  { "lt-2", 933 },
  { "take-2", 934 },
  { "index_select-dim-2", 935 },
  { "masked_select-2", 936 },
  { "nonzero-1", 937 },
  { "gather-dim-sparse_grad-2", 938 },
  { "gather-dim-2", 939 },
  { "_gather_sparse_backward-dim-3", 940 },
  { "addcmul-value-3", 941 },
  { "addcmul-3", 942 },
  { "addcdiv-value-3", 943 },
  { "addcdiv-3", 944 },
  { "gels-2", 945 },
  { "triangular_solve-transpose-unitriangular-upper-2", 946 },
  { "triangular_solve-transpose-upper-2", 947 },
  { "triangular_solve-upper-2", 948 },
  { "triangular_solve-2", 949 },
  { "_triangular_solve_helper-transpose-unitriangular-upper-2", 950 },
  { "symeig-eigenvectors-upper-1", 951 },
  { "symeig-eigenvectors-1", 952 },
  { "symeig-1", 953 },
  { "eig-eigenvectors-1", 954 },
  { "eig-1", 955 },
  { "svd-compute_uv-some-1", 956 },
  { "svd-some-1", 957 },
  { "svd-1", 958 },
  { "cholesky-upper-1", 959 },
  { "cholesky-1", 960 },
  { "_cholesky_helper-upper-1", 961 },
  { "cholesky_solve-upper-2", 962 },
  { "cholesky_solve-2", 963 },
  { "_cholesky_solve_helper-upper-2", 964 },
  { "solve-2", 965 },
  { "_solve_helper-2", 966 },
  { "cholesky_inverse-upper-1", 967 },
  { "cholesky_inverse-1", 968 },
  { "pstrf-tol-upper-1", 969 },
  { "pstrf-upper-1", 970 },
  { "pstrf-1", 971 },
  { "qr-1", 972 },
  { "geqrf-1", 973 },
  { "orgqr-2", 974 },
  { "ormqr-left-transpose-3", 975 },
  { "ormqr-left-3", 976 },
  { "ormqr-3", 977 },
  { "_lu_with_info-check_errors-pivot-1", 978 },
  { "_lu_with_info-pivot-1", 979 },
  { "_lu_with_info-1", 980 },
  { "lu_solve-3", 981 },
  { "multinomial-num_samples-replacement-1", 982 },
  { "multinomial-num_samples-1", 983 },
  { "_multinomial_alias_setup-1", 984 },
  { "_multinomial_alias_draw-num_samples-2", 985 },
  { "lgamma-1", 986 },
  { "digamma-1", 987 },
  { "polygamma-n-1", 988 },
  { "erfinv-1", 989 },
  { "dist-p-2", 990 },
  { "dist-2", 991 },
  { "atan2-2", 992 },
  { "lerp-weight-2", 993 },
  { "lerp-3", 994 },
  { "histc-bins-max-min-1", 995 },
  { "histc-bins-min-1", 996 },
  { "histc-bins-1", 997 },
  { "histc-1", 998 },
  { "sign-1", 999 },
  { "fmod-other-1", 1000 },
  { "fmod-2", 1001 },
  { "remainder-other-1", 1002 },
  { "remainder-2", 1003 },
  { "min-2", 1004 },
  { "min-1", 1005 },
  { "max-2", 1006 },
  { "max-1", 1007 },
  { "median-1", 1008 },
  { "sort-descending-dim-1", 1009 },
  { "sort-dim-1", 1010 },
  { "sort-1", 1011 },
  { "argsort-descending-dim-1", 1012 },
  { "argsort-dim-1", 1013 },
  { "argsort-1", 1014 },
  { "topk-dim-k-largest-sorted-1", 1015 },
  { "topk-dim-k-largest-1", 1016 },
  { "topk-dim-k-1", 1017 },
  { "topk-k-1", 1018 },
  { "all-1", 1019 },
  { "any-1", 1020 },
  { "renorm-dim-maxnorm-p-1", 1021 },
  { "unfold-dimension-size-step-1", 1022 },
  { "equal-2", 1023 },
  { "pow-2", 1024 },
  { "pow-self-1", 1025 },
  { "normal-std-1", 1026 },
  { "normal-1", 1027 },
  { "normal-mean-1", 1028 },
  { "normal-2", 1029 },
  { "alias-1", 1030 },
  { "_dirichlet_grad-3", 1031 },
  { "binary_cross_entropy-reduction-3", 1032 },
  { "binary_cross_entropy-3", 1033 },
  { "binary_cross_entropy-2", 1034 },
  { "binary_cross_entropy_backward-reduction-4", 1035 },
  { "mse_loss-reduction-2", 1036 },
  { "mse_loss-2", 1037 },
  { "mse_loss_backward-reduction-3", 1038 },
  { "l1_loss-reduction-2", 1039 },
  { "l1_loss-2", 1040 },
  { "l1_loss_backward-reduction-3", 1041 },
  { "multi_margin_loss-margin-p-reduction-3", 1042 },
  { "multi_margin_loss-margin-p-3", 1043 },
  { "multi_margin_loss-margin-p-2", 1044 },
  { "multi_margin_loss-p-2", 1045 },
  { "multi_margin_loss-2", 1046 },
  { "multi_margin_loss_backward-margin-p-reduction-4", 1047 },
  { "multilabel_margin_loss-reduction-2", 1048 },
  { "multilabel_margin_loss-2", 1049 },
  { "multilabel_margin_loss_forward-reduction-2", 1050 },
  { "multilabel_margin_loss_backward-reduction-4", 1051 },
  { "nll_loss-ignore_index-reduction-3", 1052 },
  { "nll_loss-reduction-3", 1053 },
  { "nll_loss-3", 1054 },
  { "nll_loss-2", 1055 },
  { "nll_loss_forward-ignore_index-reduction-3", 1056 },
  { "nll_loss_backward-ignore_index-reduction-5", 1057 },
  { "nll_loss2d-ignore_index-reduction-3", 1058 },
  { "nll_loss2d-reduction-3", 1059 },
  { "nll_loss2d-3", 1060 },
  { "nll_loss2d-2", 1061 },
  { "nll_loss2d_forward-ignore_index-reduction-3", 1062 },
  { "nll_loss2d_backward-ignore_index-reduction-5", 1063 },
  { "smooth_l1_loss-reduction-2", 1064 },
  { "smooth_l1_loss-2", 1065 },
  { "smooth_l1_loss_backward-reduction-3", 1066 },
  { "soft_margin_loss-reduction-2", 1067 },
  { "soft_margin_loss-2", 1068 },
  { "soft_margin_loss_backward-reduction-3", 1069 },
  { "elu-alpha-input_scale-scale-1", 1070 },
  { "elu-alpha-scale-1", 1071 },
  { "elu-alpha-1", 1072 },
  { "elu-1", 1073 },
  { "elu_backward-alpha-input_scale-scale-2", 1074 },
  { "glu-dim-1", 1075 },
  { "glu-1", 1076 },
  { "glu_backward-dim-2", 1077 },
  { "hardtanh-max_val-min_val-1", 1078 },
  { "hardtanh-min_val-1", 1079 },
  { "hardtanh-1", 1080 },
  { "hardtanh_backward-max_val-min_val-2", 1081 },
  { "leaky_relu-negative_slope-1", 1082 },
  { "leaky_relu-1", 1083 },
  { "leaky_relu_backward-negative_slope-2", 1084 },
  { "log_sigmoid-1", 1085 },
  { "log_sigmoid_forward-1", 1086 },
  { "log_sigmoid_backward-3", 1087 },
  { "rrelu_with_noise-lower-training-upper-2", 1088 },
  { "rrelu_with_noise-lower-upper-2", 1089 },
  { "rrelu_with_noise-lower-2", 1090 },
  { "rrelu_with_noise-2", 1091 },
  { "rrelu_with_noise_backward-lower-training-upper-3", 1092 },
  { "softplus-beta-threshold-1", 1093 },
  { "softplus-beta-1", 1094 },
  { "softplus-1", 1095 },
  { "softplus_backward-beta-threshold-3", 1096 },
  { "softshrink-lambd-1", 1097 },
  { "softshrink-1", 1098 },
  { "softshrink_backward-lambd-2", 1099 },
  { "adaptive_avg_pool2d-output_size-1", 1100 },
  { "_adaptive_avg_pool2d-output_size-1", 1101 },
  { "_adaptive_avg_pool2d_backward-2", 1102 },
  { "adaptive_avg_pool3d-output_size-1", 1103 },
  { "adaptive_avg_pool3d_backward-2", 1104 },
  { "adaptive_max_pool2d-output_size-1", 1105 },
  { "adaptive_max_pool2d_backward-3", 1106 },
  { "adaptive_max_pool3d-output_size-1", 1107 },
  { "adaptive_max_pool3d_backward-3", 1108 },
  { "avg_pool2d-ceil_mode-count_include_pad-kernel_size-padding-stride-1", 1109 },
  { "avg_pool2d-ceil_mode-kernel_size-padding-stride-1", 1110 },
  { "avg_pool2d-kernel_size-padding-stride-1", 1111 },
  { "avg_pool2d-kernel_size-stride-1", 1112 },
  { "avg_pool2d-kernel_size-1", 1113 },
  { "avg_pool2d_backward-ceil_mode-count_include_pad-kernel_size-padding-stride-2", 1114 },
  { "avg_pool3d-ceil_mode-count_include_pad-kernel_size-padding-stride-1", 1115 },
  { "avg_pool3d-ceil_mode-kernel_size-padding-stride-1", 1116 },
  { "avg_pool3d-kernel_size-padding-stride-1", 1117 },
  { "avg_pool3d-kernel_size-stride-1", 1118 },
  { "avg_pool3d-kernel_size-1", 1119 },
  { "avg_pool3d_backward-ceil_mode-count_include_pad-kernel_size-padding-stride-2", 1120 },
  { "fractional_max_pool2d-kernel_size-output_size-2", 1121 },
  { "fractional_max_pool2d_backward-kernel_size-output_size-3", 1122 },
  { "fractional_max_pool3d-kernel_size-output_size-2", 1123 },
  { "fractional_max_pool3d_backward-kernel_size-output_size-3", 1124 },
  { "max_pool2d_with_indices-ceil_mode-dilation-kernel_size-padding-stride-1", 1125 },
  { "max_pool2d_with_indices-dilation-kernel_size-padding-stride-1", 1126 },
  { "max_pool2d_with_indices-kernel_size-padding-stride-1", 1127 },
  { "max_pool2d_with_indices-kernel_size-stride-1", 1128 },
  { "max_pool2d_with_indices-kernel_size-1", 1129 },
  { "max_pool2d_with_indices_backward-ceil_mode-dilation-kernel_size-padding-stride-3", 1130 },
  { "max_pool3d_with_indices-ceil_mode-dilation-kernel_size-padding-stride-1", 1131 },
  { "max_pool3d_with_indices-dilation-kernel_size-padding-stride-1", 1132 },
  { "max_pool3d_with_indices-kernel_size-padding-stride-1", 1133 },
  { "max_pool3d_with_indices-kernel_size-stride-1", 1134 },
  { "max_pool3d_with_indices-kernel_size-1", 1135 },
  { "max_pool3d_with_indices_backward-ceil_mode-dilation-kernel_size-padding-stride-3", 1136 },
  { "max_unpool2d-output_size-2", 1137 },
  { "max_unpool2d_backward-output_size-3", 1138 },
  { "max_unpool3d-output_size-padding-stride-2", 1139 },
  { "max_unpool3d_backward-output_size-padding-stride-3", 1140 },
  { "reflection_pad1d-padding-1", 1141 },
  { "reflection_pad1d_backward-padding-2", 1142 },
  { "reflection_pad2d-padding-1", 1143 },
  { "reflection_pad2d_backward-padding-2", 1144 },
  { "replication_pad1d-padding-1", 1145 },
  { "replication_pad1d_backward-padding-2", 1146 },
  { "replication_pad2d-padding-1", 1147 },
  { "replication_pad2d_backward-padding-2", 1148 },
  { "replication_pad3d-padding-1", 1149 },
  { "replication_pad3d_backward-padding-2", 1150 },
  { "upsample_linear1d-align_corners-output_size-1", 1151 },
  { "upsample_linear1d_backward-align_corners-input_size-output_size-1", 1152 },
  { "upsample_bilinear2d-align_corners-output_size-1", 1153 },
  { "upsample_bilinear2d_backward-align_corners-input_size-output_size-1", 1154 },
  { "upsample_bicubic2d-align_corners-output_size-1", 1155 },
  { "upsample_bicubic2d_backward-align_corners-input_size-output_size-1", 1156 },
  { "upsample_trilinear3d-align_corners-output_size-1", 1157 },
  { "upsample_trilinear3d_backward-align_corners-input_size-output_size-1", 1158 },
  { "upsample_nearest1d-output_size-1", 1159 },
  { "upsample_nearest1d_backward-input_size-output_size-1", 1160 },
  { "upsample_nearest2d-output_size-1", 1161 },
  { "upsample_nearest2d_backward-input_size-output_size-1", 1162 },
  { "upsample_nearest3d-output_size-1", 1163 },
  { "upsample_nearest3d_backward-input_size-output_size-1", 1164 },
  { "sigmoid_backward-2", 1165 },
  { "tanh_backward-2", 1166 },
  { "thnn_conv_transpose2d-dilation-kernel_size-output_padding-padding-stride-3", 1167 },
  { "thnn_conv_transpose2d-kernel_size-output_padding-padding-stride-3", 1168 },
  { "thnn_conv_transpose2d-kernel_size-padding-stride-3", 1169 },
  { "thnn_conv_transpose2d-kernel_size-stride-3", 1170 },
  { "thnn_conv_transpose2d-kernel_size-3", 1171 },
  { "thnn_conv_transpose2d-kernel_size-2", 1172 },
  { "thnn_conv_transpose2d_forward-dilation-kernel_size-output_padding-padding-stride-3", 1173 },
  { "thnn_conv_transpose3d-dilation-kernel_size-output_padding-padding-stride-3", 1174 },
  { "thnn_conv_transpose3d-kernel_size-output_padding-padding-stride-3", 1175 },
  { "thnn_conv_transpose3d-kernel_size-padding-stride-3", 1176 },
  { "thnn_conv_transpose3d-kernel_size-stride-3", 1177 },
  { "thnn_conv_transpose3d-kernel_size-3", 1178 },
  { "thnn_conv_transpose3d-kernel_size-2", 1179 },
  { "thnn_conv_transpose3d_forward-dilation-kernel_size-output_padding-padding-stride-3", 1180 },
  { "thnn_conv2d-kernel_size-padding-stride-3", 1181 },
  { "thnn_conv2d-kernel_size-stride-3", 1182 },
  { "thnn_conv2d-kernel_size-3", 1183 },
  { "thnn_conv2d-kernel_size-2", 1184 },
  { "thnn_conv2d_forward-kernel_size-padding-stride-3", 1185 },
  { "thnn_conv_depthwise2d-dilation-kernel_size-padding-stride-3", 1186 },
  { "thnn_conv_depthwise2d-kernel_size-padding-stride-3", 1187 },
  { "thnn_conv_depthwise2d-kernel_size-stride-3", 1188 },
  { "thnn_conv_depthwise2d-kernel_size-3", 1189 },
  { "thnn_conv_depthwise2d-kernel_size-2", 1190 },
  { "thnn_conv_depthwise2d_forward-dilation-kernel_size-padding-stride-3", 1191 },
  { "thnn_conv3d-kernel_size-padding-stride-3", 1192 },
  { "thnn_conv3d-kernel_size-stride-3", 1193 },
  { "thnn_conv3d-kernel_size-3", 1194 },
  { "thnn_conv3d-kernel_size-2", 1195 },
  { "thnn_conv3d_forward-kernel_size-padding-stride-3", 1196 },
  { "thnn_conv_dilated2d-dilation-kernel_size-padding-stride-3", 1197 },
  { "thnn_conv_dilated2d-kernel_size-padding-stride-3", 1198 },
  { "thnn_conv_dilated2d-kernel_size-stride-3", 1199 },
  { "thnn_conv_dilated2d-kernel_size-3", 1200 },
  { "thnn_conv_dilated2d-kernel_size-2", 1201 },
  { "thnn_conv_dilated2d_forward-dilation-kernel_size-padding-stride-3", 1202 },
  { "thnn_conv_dilated3d-dilation-kernel_size-padding-stride-3", 1203 },
  { "thnn_conv_dilated3d-kernel_size-padding-stride-3", 1204 },
  { "thnn_conv_dilated3d-kernel_size-stride-3", 1205 },
  { "thnn_conv_dilated3d-kernel_size-3", 1206 },
  { "thnn_conv_dilated3d-kernel_size-2", 1207 },
  { "thnn_conv_dilated3d_forward-dilation-kernel_size-padding-stride-3", 1208 },
  { "thnn_col2im-dilation-kernel_size-output_size-padding-stride-1", 1209 },
  { "thnn_col2im_backward-dilation-kernel_size-padding-stride-1", 1210 },
  { "thnn_im2col-dilation-kernel_size-padding-stride-1", 1211 },
  { "thnn_im2col_backward-dilation-input_size-kernel_size-padding-stride-1", 1212 },
};

namespace caffe2 {

using at::Half; // for AT_FORALL_SCALAR_TYPES_AND_BOOL_EXCEPT_QINT

template <class Context>
class ATenOp : public Operator<Context> {
 public:
  ATenOp(const OperatorDef& operator_def, Workspace* ws)
  : Operator<Context>(operator_def, ws) {
    VLOG(2) << "ATen OpDef: " << ProtoDebugString(operator_def) << "\n";
    switch(findImplementation(operator_def)) {
      case 0: { // _th_is_set_to
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto tensor = peek(1, 2);
              auto the_result = at::_th_is_set_to(self, tensor);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 1: { // _th_masked_select
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mask = peek(1, 2);
              auto the_result = at::_th_masked_select(self, mask);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 2: { // _th_nonzero
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_nonzero(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 3: { // _th_clone
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_clone(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 4: { // _th_view
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_view(self, size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 5: { // _th_index_select
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::_th_index_select(self, dim, index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 6: { // _th_take
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::_th_take(self, index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 7: { // _th_unfold
          int64_t dimension = readAttribute<int64_t>("dimension");
          int64_t size = readAttribute<int64_t>("size");
          int64_t step = readAttribute<int64_t>("step");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_unfold(self, dimension, size, step);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 8: { // _th_gather
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::_th_gather(self, dim, index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 9: { // _th_equal
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_equal(self, other);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 10: { // _th_and
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_and(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 11: { // _th_and
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_and(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 12: { // _th_or
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_or(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 13: { // _th_or
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_or(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 14: { // _th_xor
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_xor(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 15: { // _th_xor
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_xor(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 16: { // _th_lshift
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_lshift(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 17: { // _th_lshift
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_lshift(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 18: { // _th_rshift
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_rshift(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 19: { // _th_rshift
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_rshift(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 20: { // _th_lt
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_lt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 21: { // _th_lt
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_lt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 22: { // _th_gt
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_gt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 23: { // _th_gt
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_gt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 24: { // _th_le
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_le(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 25: { // _th_le
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_le(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 26: { // _th_ge
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_ge(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 27: { // _th_ge
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_ge(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 28: { // _th_eq
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_eq(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 29: { // _th_eq
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_eq(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 30: { // _th_ne
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_ne(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 31: { // _th_ne
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_ne(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 32: { // _th_min
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_min(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 33: { // _th_min
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_min(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 34: { // _th_min
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_min(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 35: { // _th_min
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_min(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 36: { // _th_max
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_max(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 37: { // _th_max
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_max(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 38: { // _th_max
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_max(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 39: { // _th_max
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_max(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 40: { // _th_mode
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_mode(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 41: { // _th_mode
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_mode(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 42: { // _th_mode
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_mode(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 43: { // _th_sort
          int64_t dim = readAttribute<int64_t>("dim");
          bool descending = readAttribute<int64_t>("descending");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_sort(self, dim, descending);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 44: { // _th_sort
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_sort(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 45: { // _th_sort
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_sort(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 46: { // _th_topk
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          bool largest = readAttribute<int64_t>("largest");
          bool sorted = readAttribute<int64_t>("sorted");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_topk(self, k, dim, largest, sorted);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 47: { // _th_topk
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          bool largest = readAttribute<int64_t>("largest");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_topk(self, k, dim, largest);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 48: { // _th_topk
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_topk(self, k, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 49: { // _th_topk
          int64_t k = readAttribute<int64_t>("k");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_topk(self, k);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 50: { // _th_abs
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_abs(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 51: { // _th_sigmoid
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_sigmoid(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 52: { // _th_log
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_log(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 53: { // _th_log10
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_log10(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 54: { // _th_log1p
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_log1p(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 55: { // _th_log2
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_log2(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 56: { // _th_lgamma
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_lgamma(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 57: { // _th_digamma
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_digamma(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 58: { // _th_polygamma
          int64_t n = readAttribute<int64_t>("n");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_polygamma(n, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 59: { // _th_exp
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_exp(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 60: { // _th_expm1
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_expm1(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 61: { // _th_cos
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_cos(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 62: { // _th_acos
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_acos(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 63: { // _th_cosh
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_cosh(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 64: { // _th_sin
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_sin(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 65: { // _th_asin
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_asin(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 66: { // _th_sinh
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_sinh(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 67: { // _th_tan
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_tan(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 68: { // _th_atan
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_atan(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 69: { // _th_tanh
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_tanh(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 70: { // _th_erf
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_erf(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 71: { // _th_erfc
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_erfc(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 72: { // _th_erfinv
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_erfinv(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 73: { // _th_sqrt
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_sqrt(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 74: { // _th_rsqrt
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_rsqrt(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 75: { // _th_ceil
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_ceil(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 76: { // _th_floor
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_floor(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 77: { // _th_round
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_round(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 78: { // _th_trunc
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_trunc(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 79: { // _th_frac
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_frac(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 80: { // _th_var
          int64_t dim = readAttribute<int64_t>("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_var(self, dim, unbiased, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 81: { // _th_var
          int64_t dim = readAttribute<int64_t>("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_var(self, dim, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 82: { // _th_var
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_var(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 83: { // _th_var
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_var(self, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 84: { // _th_var
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_var(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 85: { // _th_std
          int64_t dim = readAttribute<int64_t>("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_std(self, dim, unbiased, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 86: { // _th_std
          int64_t dim = readAttribute<int64_t>("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_std(self, dim, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 87: { // _th_std
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_std(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 88: { // _th_std
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_std(self, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 89: { // _th_std
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_std(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 90: { // _th_renorm
          at::Scalar p = readScalarAttribute("p");
          int64_t dim = readAttribute<int64_t>("dim");
          at::Scalar maxnorm = readScalarAttribute("maxnorm");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_renorm(self, p, dim, maxnorm);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 91: { // _th_dist
          at::Scalar p = readScalarAttribute("p");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_dist(self, other, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 92: { // _th_dist
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_dist(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 93: { // _th_reciprocal
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_reciprocal(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 94: { // _th_neg
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_neg(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 95: { // _th_atan2
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_atan2(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 96: { // _th_pow
          at::Scalar exponent = readScalarAttribute("exponent");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_pow(self, exponent);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 97: { // _th_pow
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto exponent = peek(1, 2);
              auto the_result = at::_th_pow(self, exponent);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 98: { // _th_pow
          at::Scalar self = readScalarAttribute("self");
          run_op = [=] {
              auto exponent = peek(0, 1);
              auto the_result = at::_th_pow(self, exponent);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 99: { // _th_histc
          int64_t bins = readAttribute<int64_t>("bins");
          at::Scalar min = readScalarAttribute("min");
          at::Scalar max = readScalarAttribute("max");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_histc(self, bins, min, max);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 100: { // _th_histc
          int64_t bins = readAttribute<int64_t>("bins");
          at::Scalar min = readScalarAttribute("min");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_histc(self, bins, min);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 101: { // _th_histc
          int64_t bins = readAttribute<int64_t>("bins");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_histc(self, bins);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 102: { // _th_histc
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_histc(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 103: { // _th_cumsum
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_cumsum(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 104: { // _th_cumprod
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_cumprod(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 105: { // _th_sign
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_sign(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 106: { // _th_trace
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_trace(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 107: { // _th_fmod
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_fmod(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 108: { // _th_fmod
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_fmod(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 109: { // _th_remainder
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_remainder(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 110: { // _th_remainder
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_remainder(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 111: { // _th_clamp
          at::Scalar min = readScalarAttribute("min");
          at::Scalar max = readScalarAttribute("max");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_clamp(self, min, max);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 112: { // _th_clamp_min
          at::Scalar min = readScalarAttribute("min");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_clamp_min(self, min);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 113: { // _th_clamp_max
          at::Scalar max = readScalarAttribute("max");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_clamp_max(self, max);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 114: { // _th_dot
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto tensor = peek(1, 2);
              auto the_result = at::_th_dot(self, tensor);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 115: { // _th_cross_kernel
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::_th_cross_kernel(self, other, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 116: { // _th_diag
          int64_t diagonal = readAttribute<int64_t>("diagonal");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_diag(self, diagonal);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 117: { // _th_diag
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_diag(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 118: { // _th_addmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::_th_addmm(self, mat1, mat2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 119: { // _th_addmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::_th_addmm(self, mat1, mat2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 120: { // _th_addmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::_th_addmm(self, mat1, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 121: { // _th_addmv
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat = peek(1, 3);
              auto vec = peek(2, 3);
              auto the_result = at::_th_addmv(self, mat, vec, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 122: { // _th_addmv
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat = peek(1, 3);
              auto vec = peek(2, 3);
              auto the_result = at::_th_addmv(self, mat, vec, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 123: { // _th_addmv
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat = peek(1, 3);
              auto vec = peek(2, 3);
              auto the_result = at::_th_addmv(self, mat, vec);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 124: { // _th_addr
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::_th_addr(self, vec1, vec2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 125: { // _th_addr
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::_th_addr(self, vec1, vec2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 126: { // _th_addr
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::_th_addr(self, vec1, vec2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 127: { // _th_ger
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto vec2 = peek(1, 2);
              auto the_result = at::_th_ger(self, vec2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 128: { // _th_mv
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto vec = peek(1, 2);
              auto the_result = at::_th_mv(self, vec);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 129: { // _th_mm
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mat2 = peek(1, 2);
              auto the_result = at::_th_mm(self, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 130: { // _th_bmm
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mat2 = peek(1, 2);
              auto the_result = at::_th_bmm(self, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 131: { // _th_addbmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::_th_addbmm(self, batch1, batch2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 132: { // _th_addbmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::_th_addbmm(self, batch1, batch2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 133: { // _th_addbmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::_th_addbmm(self, batch1, batch2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 134: { // _th_baddbmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::_th_baddbmm(self, batch1, batch2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 135: { // _th_baddbmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::_th_baddbmm(self, batch1, batch2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 136: { // _th_baddbmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::_th_baddbmm(self, batch1, batch2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 137: { // _th_addcmul
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::_th_addcmul(self, tensor1, tensor2, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 138: { // _th_addcmul
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::_th_addcmul(self, tensor1, tensor2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 139: { // _th_addcdiv
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::_th_addcdiv(self, tensor1, tensor2, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 140: { // _th_addcdiv
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::_th_addcdiv(self, tensor1, tensor2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 141: { // _th_gels
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::_th_gels(self, A);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 142: { // _th_symeig
          bool eigenvectors = readAttribute<int64_t>("eigenvectors");
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_symeig(self, eigenvectors, upper);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 143: { // _th_symeig
          bool eigenvectors = readAttribute<int64_t>("eigenvectors");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_symeig(self, eigenvectors);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 144: { // _th_symeig
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_symeig(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 145: { // _th_eig
          bool eigenvectors = readAttribute<int64_t>("eigenvectors");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_eig(self, eigenvectors);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 146: { // _th_eig
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_eig(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 147: { // _th_svd
          bool some = readAttribute<int64_t>("some");
          bool compute_uv = readAttribute<int64_t>("compute_uv");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_svd(self, some, compute_uv);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 148: { // _th_svd
          bool some = readAttribute<int64_t>("some");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_svd(self, some);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 149: { // _th_svd
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_svd(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 150: { // _th_getri_single
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_getri_single(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 151: { // _th_potri
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_potri(self, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 152: { // _th_potri
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_potri(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 153: { // _th_pstrf
          bool upper = readAttribute<int64_t>("upper");
          at::Scalar tol = readScalarAttribute("tol");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_pstrf(self, upper, tol);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 154: { // _th_pstrf
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_pstrf(self, upper);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 155: { // _th_pstrf
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_pstrf(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 156: { // _th_qr
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_qr(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 157: { // _th_geqrf
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_geqrf(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 158: { // _th_orgqr
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto input2 = peek(1, 2);
              auto the_result = at::_th_orgqr(self, input2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 159: { // _th_ormqr
          bool left = readAttribute<int64_t>("left");
          bool transpose = readAttribute<int64_t>("transpose");
          run_op = [=] {
              auto self = peek(0, 3);
              auto input2 = peek(1, 3);
              auto input3 = peek(2, 3);
              auto the_result = at::_th_ormqr(self, input2, input3, left, transpose);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 160: { // _th_ormqr
          bool left = readAttribute<int64_t>("left");
          run_op = [=] {
              auto self = peek(0, 3);
              auto input2 = peek(1, 3);
              auto input3 = peek(2, 3);
              auto the_result = at::_th_ormqr(self, input2, input3, left);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 161: { // _th_ormqr
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto input2 = peek(1, 3);
              auto input3 = peek(2, 3);
              auto the_result = at::_th_ormqr(self, input2, input3);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 162: { // _th_btrisolve
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto LU_data = peek(1, 3);
              auto LU_pivots = peek(2, 3);
              auto the_result = at::_th_btrisolve(self, LU_data, LU_pivots);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 163: { // _th_multinomial_alias_setup
      
          run_op = [=] {
              auto probs = peek(0, 1);
              auto the_result = at::_th_multinomial_alias_setup(probs);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 164: { // _th_multinomial_alias_draw
          int64_t num_samples = readAttribute<int64_t>("num_samples");
          run_op = [=] {
              auto q = peek(0, 2);
              auto J = peek(1, 2);
              auto the_result = at::_th_multinomial_alias_draw(q, J, num_samples);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 165: { // _th_multinomial
          int64_t num_samples = readAttribute<int64_t>("num_samples");
          bool replacement = readAttribute<int64_t>("replacement");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_multinomial(self, num_samples, replacement);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 166: { // _th_multinomial
          int64_t num_samples = readAttribute<int64_t>("num_samples");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_multinomial(self, num_samples);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 167: { // _th_normal
          double std = readAttribute<float>("std");
          run_op = [=] {
              auto mean = peek(0, 1);
              auto the_result = at::_th_normal(mean, std);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 168: { // _th_normal
      
          run_op = [=] {
              auto mean = peek(0, 1);
              auto the_result = at::_th_normal(mean);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 169: { // _th_normal
          double mean = readAttribute<float>("mean");
          run_op = [=] {
              auto std = peek(0, 1);
              auto the_result = at::_th_normal(mean, std);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 170: { // _th_normal
      
          run_op = [=] {
              auto mean = peek(0, 2);
              auto std = peek(1, 2);
              auto the_result = at::_th_normal(mean, std);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 171: { // _th_dirichlet_grad
      
          run_op = [=] {
              auto x = peek(0, 3);
              auto alpha = peek(1, 3);
              auto total = peek(2, 3);
              auto the_result = at::_th_dirichlet_grad(x, alpha, total);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 172: { // _th_alias
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_th_alias(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 173: { // _th_cat
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::_th_cat(tensors, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 174: { // _th_cat
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::_th_cat(tensors);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 175: { // _thnn_binary_cross_entropy_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::_thnn_binary_cross_entropy_forward(self, target, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 176: { // _thnn_binary_cross_entropy_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto weight = peek(3, 4);
              auto the_result = at::_thnn_binary_cross_entropy_backward(grad_output, self, target, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 177: { // _thnn_l1_loss_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::_thnn_l1_loss_forward(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 178: { // _thnn_l1_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::_thnn_l1_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 179: { // _thnn_mse_loss_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::_thnn_mse_loss_forward(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 180: { // _thnn_mse_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::_thnn_mse_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 181: { // _thnn_multi_margin_loss_forward
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::_thnn_multi_margin_loss_forward(self, target, p, margin, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 182: { // _thnn_multi_margin_loss_backward
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto weight = peek(3, 4);
              auto the_result = at::_thnn_multi_margin_loss_backward(grad_output, self, target, p, margin, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 183: { // _thnn_multilabel_margin_loss_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::_thnn_multilabel_margin_loss_forward(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 184: { // _thnn_multilabel_margin_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto is_target = peek(3, 4);
              auto the_result = at::_thnn_multilabel_margin_loss_backward(grad_output, self, target, reduction, is_target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 185: { // _thnn_nll_loss_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::_thnn_nll_loss_forward(self, target, weight, reduction, ignore_index);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 186: { // _thnn_nll_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto target = peek(2, 5);
              auto weight = peek(3, 5);
              auto total_weight = peek(4, 5);
              auto the_result = at::_thnn_nll_loss_backward(grad_output, self, target, weight, reduction, ignore_index, total_weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 187: { // _thnn_nll_loss2d_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::_thnn_nll_loss2d_forward(self, target, weight, reduction, ignore_index);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 188: { // _thnn_nll_loss2d_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto target = peek(2, 5);
              auto weight = peek(3, 5);
              auto total_weight = peek(4, 5);
              auto the_result = at::_thnn_nll_loss2d_backward(grad_output, self, target, weight, reduction, ignore_index, total_weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 189: { // _thnn_smooth_l1_loss_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::_thnn_smooth_l1_loss_forward(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 190: { // _thnn_smooth_l1_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::_thnn_smooth_l1_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 191: { // _thnn_soft_margin_loss_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::_thnn_soft_margin_loss_forward(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 192: { // _thnn_soft_margin_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::_thnn_soft_margin_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 193: { // _thnn_elu_forward
          at::Scalar alpha = readScalarAttribute("alpha");
          at::Scalar scale = readScalarAttribute("scale");
          at::Scalar input_scale = readScalarAttribute("input_scale");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_elu_forward(self, alpha, scale, input_scale);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 194: { // _thnn_elu_backward
          at::Scalar alpha = readScalarAttribute("alpha");
          at::Scalar scale = readScalarAttribute("scale");
          at::Scalar input_scale = readScalarAttribute("input_scale");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto output = peek(1, 2);
              auto the_result = at::_thnn_elu_backward(grad_output, alpha, scale, input_scale, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 195: { // _thnn_glu_forward
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_glu_forward(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 196: { // _thnn_glu_backward
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::_thnn_glu_backward(grad_output, self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 197: { // _thnn_hardtanh_forward
          at::Scalar min_val = readScalarAttribute("min_val");
          at::Scalar max_val = readScalarAttribute("max_val");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_hardtanh_forward(self, min_val, max_val);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 198: { // _thnn_hardtanh_backward
          at::Scalar min_val = readScalarAttribute("min_val");
          at::Scalar max_val = readScalarAttribute("max_val");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::_thnn_hardtanh_backward(grad_output, self, min_val, max_val);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 199: { // _thnn_leaky_relu_forward
          at::Scalar negative_slope = readScalarAttribute("negative_slope");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_leaky_relu_forward(self, negative_slope);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 200: { // _thnn_leaky_relu_backward
          at::Scalar negative_slope = readScalarAttribute("negative_slope");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::_thnn_leaky_relu_backward(grad_output, self, negative_slope);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 201: { // _thnn_log_sigmoid_forward
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_log_sigmoid_forward(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 202: { // _thnn_log_sigmoid_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto buffer = peek(2, 3);
              auto the_result = at::_thnn_log_sigmoid_backward(grad_output, self, buffer);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 203: { // _thnn_rrelu_with_noise_backward
          at::Scalar lower = readScalarAttribute("lower");
          at::Scalar upper = readScalarAttribute("upper");
          bool training = readAttribute<int64_t>("training");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto noise = peek(2, 3);
              auto the_result = at::_thnn_rrelu_with_noise_backward(grad_output, self, noise, lower, upper, training);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 204: { // _thnn_softplus_forward
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar threshold = readScalarAttribute("threshold");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_softplus_forward(self, beta, threshold);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 205: { // _thnn_softplus_backward
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar threshold = readScalarAttribute("threshold");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto output = peek(2, 3);
              auto the_result = at::_thnn_softplus_backward(grad_output, self, beta, threshold, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 206: { // _thnn_softshrink_forward
          at::Scalar lambd = readScalarAttribute("lambd");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_softshrink_forward(self, lambd);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 207: { // _thnn_softshrink_backward
          at::Scalar lambd = readScalarAttribute("lambd");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::_thnn_softshrink_backward(grad_output, self, lambd);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 208: { // _thnn_adaptive_avg_pool3d_forward
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_adaptive_avg_pool3d_forward(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 209: { // _thnn_adaptive_avg_pool3d_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::_thnn_adaptive_avg_pool3d_backward(grad_output, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 210: { // _thnn_avg_pool2d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_avg_pool2d_forward(self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 211: { // _thnn_avg_pool2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::_thnn_avg_pool2d_backward(grad_output, self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 212: { // _thnn_avg_pool3d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_avg_pool3d_forward(self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 213: { // _thnn_avg_pool3d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::_thnn_avg_pool3d_backward(grad_output, self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 214: { // _thnn_max_pool2d_with_indices_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_max_pool2d_with_indices_forward(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 215: { // _thnn_max_pool2d_with_indices_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::_thnn_max_pool2d_with_indices_backward(grad_output, self, kernel_size, stride, padding, dilation, ceil_mode, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 216: { // _thnn_max_pool3d_with_indices_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_max_pool3d_with_indices_forward(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 217: { // _thnn_max_pool3d_with_indices_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::_thnn_max_pool3d_with_indices_backward(grad_output, self, kernel_size, stride, padding, dilation, ceil_mode, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 218: { // _thnn_max_unpool2d_forward
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::_thnn_max_unpool2d_forward(self, indices, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 219: { // _thnn_max_unpool2d_backward
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::_thnn_max_unpool2d_backward(grad_output, self, indices, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 220: { // _thnn_max_unpool3d_forward
          auto output_size = readIntArrayRef("output_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::_thnn_max_unpool3d_forward(self, indices, output_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 221: { // _thnn_max_unpool3d_backward
          auto output_size = readIntArrayRef("output_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::_thnn_max_unpool3d_backward(grad_output, self, indices, output_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 222: { // _thnn_upsample_linear1d_forward
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_upsample_linear1d_forward(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 223: { // _thnn_upsample_linear1d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::_thnn_upsample_linear1d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 224: { // _thnn_upsample_bilinear2d_forward
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_upsample_bilinear2d_forward(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 225: { // _thnn_upsample_bilinear2d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::_thnn_upsample_bilinear2d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 226: { // _thnn_upsample_bicubic2d_forward
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_upsample_bicubic2d_forward(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 227: { // _thnn_upsample_bicubic2d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::_thnn_upsample_bicubic2d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 228: { // _thnn_upsample_trilinear3d_forward
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_upsample_trilinear3d_forward(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 229: { // _thnn_upsample_trilinear3d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::_thnn_upsample_trilinear3d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 230: { // _thnn_upsample_nearest1d_forward
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_upsample_nearest1d_forward(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 231: { // _thnn_upsample_nearest1d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::_thnn_upsample_nearest1d_backward(grad_output, output_size, input_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 232: { // _thnn_upsample_nearest2d_forward
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_upsample_nearest2d_forward(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 233: { // _thnn_upsample_nearest2d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::_thnn_upsample_nearest2d_backward(grad_output, output_size, input_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 234: { // _thnn_upsample_nearest3d_forward
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_upsample_nearest3d_forward(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 235: { // _thnn_upsample_nearest3d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::_thnn_upsample_nearest3d_backward(grad_output, output_size, input_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 236: { // _thnn_sigmoid_forward
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_sigmoid_forward(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 237: { // _thnn_sigmoid_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto output = peek(1, 2);
              auto the_result = at::_thnn_sigmoid_backward(grad_output, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 238: { // _thnn_tanh_forward
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_tanh_forward(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 239: { // _thnn_tanh_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto output = peek(1, 2);
              auto the_result = at::_thnn_tanh_backward(grad_output, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 240: { // _thnn_conv_transpose2d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_thnn_conv_transpose2d_forward(self, weight, kernel_size, bias, stride, padding, output_padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 241: { // _thnn_conv_transpose2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto weight = peek(2, 5);
              auto columns = peek(3, 5);
              auto ones = peek(4, 5);
              auto the_result = at::_thnn_conv_transpose2d_backward(grad_output, self, weight, kernel_size, stride, padding, output_padding, dilation, columns, ones);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 242: { // _thnn_conv_transpose3d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_thnn_conv_transpose3d_forward(self, weight, kernel_size, bias, stride, padding, output_padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 243: { // _thnn_conv_transpose3d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto weight = peek(2, 5);
              auto finput = peek(3, 5);
              auto fgrad_input = peek(4, 5);
              auto the_result = at::_thnn_conv_transpose3d_backward(grad_output, self, weight, kernel_size, stride, padding, output_padding, dilation, finput, fgrad_input);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 244: { // _thnn_conv2d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_thnn_conv2d_forward(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 245: { // _thnn_conv2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto weight = peek(2, 5);
              auto finput = peek(3, 5);
              auto fgrad_input = peek(4, 5);
              auto the_result = at::_thnn_conv2d_backward(grad_output, self, weight, kernel_size, stride, padding, finput, fgrad_input);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 246: { // _thnn_conv_depthwise2d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_thnn_conv_depthwise2d_forward(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 247: { // _thnn_conv_depthwise2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::_thnn_conv_depthwise2d_backward(grad_output, self, weight, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 248: { // _thnn_conv3d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_thnn_conv3d_forward(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 249: { // _thnn_conv3d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto weight = peek(2, 5);
              auto finput = peek(3, 5);
              auto fgrad_input = peek(4, 5);
              auto the_result = at::_thnn_conv3d_backward(grad_output, self, weight, kernel_size, stride, padding, finput, fgrad_input);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 250: { // _thnn_conv_dilated2d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_thnn_conv_dilated2d_forward(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 251: { // _thnn_conv_dilated2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto weight = peek(2, 5);
              auto columns = peek(3, 5);
              auto ones = peek(4, 5);
              auto the_result = at::_thnn_conv_dilated2d_backward(grad_output, self, weight, kernel_size, stride, padding, dilation, columns, ones);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 252: { // _thnn_conv_dilated3d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_thnn_conv_dilated3d_forward(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 253: { // _thnn_conv_dilated3d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto weight = peek(2, 5);
              auto columns = peek(3, 5);
              auto ones = peek(4, 5);
              auto the_result = at::_thnn_conv_dilated3d_backward(grad_output, self, weight, kernel_size, stride, padding, dilation, columns, ones);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 254: { // _thnn_col2im_forward
          auto output_size = readIntArrayRef("output_size");
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_col2im_forward(self, output_size, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 255: { // _thnn_col2im_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::_thnn_col2im_backward(grad_output, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 256: { // _thnn_im2col_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_thnn_im2col_forward(self, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 257: { // _thnn_im2col_backward
          auto input_size = readIntArrayRef("input_size");
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::_thnn_im2col_backward(grad_output, input_size, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 258: { // _cast_Byte
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Byte(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 259: { // _cast_Byte
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Byte(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 260: { // _cast_Char
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Char(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 261: { // _cast_Char
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Char(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 262: { // _cast_Double
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Double(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 263: { // _cast_Double
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Double(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 264: { // _cast_Float
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Float(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 265: { // _cast_Float
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Float(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 266: { // _cast_Int
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Int(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 267: { // _cast_Int
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Int(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 268: { // _cast_Long
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Long(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 269: { // _cast_Long
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Long(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 270: { // _cast_Short
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Short(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 271: { // _cast_Short
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Short(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 272: { // _cast_Half
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Half(self, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 273: { // _cast_Half
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cast_Half(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 274: { // _cudnn_ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          bool deterministic = readAttribute<int64_t>("deterministic");
          bool zero_infinity = readAttribute<int64_t>("zero_infinity");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::_cudnn_ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, deterministic, zero_infinity);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 275: { // _cudnn_rnn_flatten_weight
          int64_t weight_stride0 = readAttribute<int64_t>("weight_stride0");
          int64_t input_size = readAttribute<int64_t>("input_size");
          int64_t mode = readAttribute<int64_t>("mode");
          int64_t hidden_size = readAttribute<int64_t>("hidden_size");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          bool batch_first = readAttribute<int64_t>("batch_first");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          run_op = [=] {
              auto weight_arr = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::_cudnn_rnn_flatten_weight(weight_arr, weight_stride0, input_size, mode, hidden_size, num_layers, batch_first, bidirectional);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 276: { // _cudnn_rnn
          int64_t weight_stride0 = readAttribute<int64_t>("weight_stride0");
          int64_t mode = readAttribute<int64_t>("mode");
          int64_t hidden_size = readAttribute<int64_t>("hidden_size");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          bool batch_first = readAttribute<int64_t>("batch_first");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          auto batch_sizes = readIntArrayRef("batch_sizes");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto weight = peekSlice(1, InputSize() - 5, InputSize());
              auto weight_buf = peek(1, 5);
              auto hx = peek(2, 5);
              auto cx = peek(3, 5);
              auto dropout_state = peek(4, 5);
              auto the_result = at::_cudnn_rnn(input, weight, weight_stride0, weight_buf, hx, cx, mode, hidden_size, num_layers, batch_first, dropout, train, bidirectional, batch_sizes, dropout_state);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
                if(OutputSize() > 4) {assignTo(Output(4),std::get<4>(the_result));}
              return true;
          };
      } break;
      case 277: { // _debug_has_internal_overlap
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_debug_has_internal_overlap(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 278: { // _fused_dropout
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_fused_dropout(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 279: { // _masked_scale
          double scale = readAttribute<float>("scale");
          run_op = [=] {
              auto self = peek(0, 2);
              auto mask = peek(1, 2);
              auto the_result = at::_masked_scale(self, mask, scale);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 280: { // _reshape_from_tensor
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto shape = peek(1, 2);
              auto the_result = at::_reshape_from_tensor(self, shape);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 281: { // _shape_as_tensor
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_shape_as_tensor(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 282: { // dropout
          double p = readAttribute<float>("p");
          bool train = readAttribute<int64_t>("train");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::dropout(input, p, train);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 283: { // feature_dropout
          double p = readAttribute<float>("p");
          bool train = readAttribute<int64_t>("train");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::feature_dropout(input, p, train);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 284: { // alpha_dropout
          double p = readAttribute<float>("p");
          bool train = readAttribute<int64_t>("train");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::alpha_dropout(input, p, train);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 285: { // feature_alpha_dropout
          double p = readAttribute<float>("p");
          bool train = readAttribute<int64_t>("train");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::feature_alpha_dropout(input, p, train);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 286: { // abs
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::abs(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 287: { // acos
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::acos(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 288: { // avg_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool1d(self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 289: { // avg_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool1d(self, kernel_size, stride, padding, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 290: { // avg_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool1d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 291: { // avg_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool1d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 292: { // avg_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool1d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 293: { // adaptive_avg_pool1d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_avg_pool1d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 294: { // adaptive_max_pool1d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_max_pool1d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 295: { // add
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::add(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 296: { // add
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::add(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 297: { // add
          at::Scalar other = readScalarAttribute("other");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::add(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 298: { // add
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::add(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 299: { // addmv
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat = peek(1, 3);
              auto vec = peek(2, 3);
              auto the_result = at::addmv(self, mat, vec, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 300: { // addmv
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat = peek(1, 3);
              auto vec = peek(2, 3);
              auto the_result = at::addmv(self, mat, vec, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 301: { // addmv
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat = peek(1, 3);
              auto vec = peek(2, 3);
              auto the_result = at::addmv(self, mat, vec);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 302: { // addr
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::addr(self, vec1, vec2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 303: { // addr
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::addr(self, vec1, vec2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 304: { // addr
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto vec1 = peek(1, 3);
              auto vec2 = peek(2, 3);
              auto the_result = at::addr(self, vec1, vec2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 305: { // affine_grid_generator
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto theta = peek(0, 1);
              auto the_result = at::affine_grid_generator(theta, size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 306: { // affine_grid_generator_backward
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto grad = peek(0, 1);
              auto the_result = at::affine_grid_generator_backward(grad, size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 307: { // all
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::all(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 308: { // all
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::all(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 309: { // allclose
          double rtol = readAttribute<float>("rtol");
          double atol = readAttribute<float>("atol");
          bool equal_nan = readAttribute<int64_t>("equal_nan");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::allclose(self, other, rtol, atol, equal_nan);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 310: { // allclose
          double rtol = readAttribute<float>("rtol");
          double atol = readAttribute<float>("atol");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::allclose(self, other, rtol, atol);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 311: { // allclose
          double rtol = readAttribute<float>("rtol");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::allclose(self, other, rtol);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 312: { // allclose
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::allclose(self, other);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 313: { // any
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::any(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 314: { // any
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::any(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 315: { // _dim_arange
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto like = peek(0, 1);
              auto the_result = at::_dim_arange(like, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 316: { // argmax
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::argmax(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 317: { // argmin
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::argmin(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 318: { // as_strided
          auto size = readIntArrayRef("size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::as_strided(self, size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 319: { // asin
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::asin(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 320: { // atan
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::atan(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 321: { // baddbmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::baddbmm(self, batch1, batch2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 322: { // baddbmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::baddbmm(self, batch1, batch2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 323: { // baddbmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::baddbmm(self, batch1, batch2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 324: { // batch_norm
          bool training = readAttribute<int64_t>("training");
          double momentum = readAttribute<float>("momentum");
          double eps = readAttribute<float>("eps");
          bool cudnn_enabled = readAttribute<int64_t>("cudnn_enabled");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::batch_norm(input, weight, bias, running_mean, running_var, training, momentum, eps, cudnn_enabled);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 325: { // _batch_norm_impl_index
          bool training = readAttribute<int64_t>("training");
          double momentum = readAttribute<float>("momentum");
          double eps = readAttribute<float>("eps");
          bool cudnn_enabled = readAttribute<int64_t>("cudnn_enabled");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::_batch_norm_impl_index(input, weight, bias, running_mean, running_var, training, momentum, eps, cudnn_enabled);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignToValue<int64_t>(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 326: { // bernoulli
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::bernoulli(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 327: { // bernoulli
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::bernoulli(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 328: { // bilinear
      
          run_op = [=] {
              auto input1 = peek(0, 4);
              auto input2 = peek(1, 4);
              auto weight = peek(2, 4);
              auto bias = peek(3, 4);
              auto the_result = at::bilinear(input1, input2, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 329: { // binary_cross_entropy_with_logits
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 4);
              auto target = peek(1, 4);
              auto weight = peek(2, 4);
              auto pos_weight = peek(3, 4);
              auto the_result = at::binary_cross_entropy_with_logits(self, target, weight, pos_weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 330: { // binary_cross_entropy_with_logits_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto target = peek(2, 5);
              auto weight = peek(3, 5);
              auto pos_weight = peek(4, 5);
              auto the_result = at::binary_cross_entropy_with_logits_backward(grad_output, self, target, weight, pos_weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 331: { // bincount
          int64_t minlength = readAttribute<int64_t>("minlength");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weights = peek(1, 2);
              auto the_result = at::bincount(self, weights, minlength);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 332: { // bincount
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto weights = peek(1, 2);
              auto the_result = at::bincount(self, weights);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 333: { // bincount
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::bincount(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 334: { // bmm
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mat2 = peek(1, 2);
              auto the_result = at::bmm(self, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 335: { // broadcast_tensors
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::broadcast_tensors(tensors);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 336: { // cat
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::cat(tensors, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 337: { // cat
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::cat(tensors);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 338: { // ceil
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::ceil(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 339: { // chain_matmul
      
          run_op = [=] {
              auto matrices = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::chain_matmul(matrices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 340: { // chunk
          int64_t chunks = readAttribute<int64_t>("chunks");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::chunk(self, chunks, dim);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 341: { // chunk
          int64_t chunks = readAttribute<int64_t>("chunks");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::chunk(self, chunks);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 342: { // clamp
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::clamp(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 343: { // clamp_max
          at::Scalar max = readScalarAttribute("max");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::clamp_max(self, max);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 344: { // clamp_min
          at::Scalar min = readScalarAttribute("min");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::clamp_min(self, min);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 345: { // cudnn_is_acceptable
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cudnn_is_acceptable(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 346: { // constant_pad_nd
          auto pad = readIntArrayRef("pad");
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::constant_pad_nd(self, pad, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 347: { // constant_pad_nd
          auto pad = readIntArrayRef("pad");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::constant_pad_nd(self, pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 348: { // contiguous
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.contiguous();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 349: { // convolution
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool transposed = readAttribute<int64_t>("transposed");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::convolution(input, weight, bias, stride, padding, dilation, transposed, output_padding, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 350: { // _convolution
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool transposed = readAttribute<int64_t>("transposed");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          bool cudnn_enabled = readAttribute<int64_t>("cudnn_enabled");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_convolution(input, weight, bias, stride, padding, dilation, transposed, output_padding, groups, benchmark, deterministic, cudnn_enabled);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 351: { // _convolution_nogroup
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool transposed = readAttribute<int64_t>("transposed");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_convolution_nogroup(input, weight, bias, stride, padding, dilation, transposed, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 352: { // conv1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv1d(input, weight, bias, stride, padding, dilation, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 353: { // conv1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv1d(input, weight, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 354: { // conv1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv1d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 355: { // conv1d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv1d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 356: { // conv1d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv1d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 357: { // conv1d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv1d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 358: { // conv2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv2d(input, weight, bias, stride, padding, dilation, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 359: { // conv2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv2d(input, weight, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 360: { // conv2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv2d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 361: { // conv2d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv2d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 362: { // conv2d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv2d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 363: { // conv2d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv2d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 364: { // conv3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv3d(input, weight, bias, stride, padding, dilation, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 365: { // conv3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv3d(input, weight, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 366: { // conv3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv3d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 367: { // conv3d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv3d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 368: { // conv3d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv3d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 369: { // conv3d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv3d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 370: { // conv_tbc
          int64_t pad = readAttribute<int64_t>("pad");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_tbc(self, weight, bias, pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 371: { // conv_tbc
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_tbc(self, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 372: { // conv_tbc_backward
          int64_t pad = readAttribute<int64_t>("pad");
          run_op = [=] {
              auto self = peek(0, 4);
              auto input = peek(1, 4);
              auto weight = peek(2, 4);
              auto bias = peek(3, 4);
              auto the_result = at::conv_tbc_backward(self, input, weight, bias, pad);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 373: { // conv_transpose1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias, stride, padding, output_padding, groups, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 374: { // conv_transpose1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias, stride, padding, output_padding, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 375: { // conv_transpose1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias, stride, padding, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 376: { // conv_transpose1d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 377: { // conv_transpose1d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 378: { // conv_transpose1d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose1d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 379: { // conv_transpose1d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv_transpose1d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 380: { // conv_transpose2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias, stride, padding, output_padding, groups, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 381: { // conv_transpose2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias, stride, padding, output_padding, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 382: { // conv_transpose2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias, stride, padding, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 383: { // conv_transpose2d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 384: { // conv_transpose2d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 385: { // conv_transpose2d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose2d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 386: { // conv_transpose2d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv_transpose2d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 387: { // conv_transpose3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias, stride, padding, output_padding, groups, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 388: { // conv_transpose3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias, stride, padding, output_padding, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 389: { // conv_transpose3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias, stride, padding, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 390: { // conv_transpose3d
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 391: { // conv_transpose3d
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 392: { // conv_transpose3d
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::conv_transpose3d(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 393: { // conv_transpose3d
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::conv_transpose3d(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 394: { // _s_copy_from
          bool non_blocking = readAttribute<int64_t>("non_blocking");
          run_op = [=] {
              auto self = peek(0, 2);
              auto dst = peek(1, 2);
              auto the_result = at::_s_copy_from(self, dst, non_blocking);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 395: { // _s_copy_from
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto dst = peek(1, 2);
              auto the_result = at::_s_copy_from(self, dst);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 396: { // cos
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cos(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 397: { // cosh
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cosh(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 398: { // cosine_embedding_loss
          double margin = readAttribute<float>("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::cosine_embedding_loss(input1, input2, target, margin, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 399: { // cosine_embedding_loss
          double margin = readAttribute<float>("margin");
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::cosine_embedding_loss(input1, input2, target, margin);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 400: { // cosine_embedding_loss
      
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::cosine_embedding_loss(input1, input2, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 401: { // cudnn_affine_grid_generator
          int64_t N = readAttribute<int64_t>("N");
          int64_t C = readAttribute<int64_t>("C");
          int64_t H = readAttribute<int64_t>("H");
          int64_t W = readAttribute<int64_t>("W");
          run_op = [=] {
              auto theta = peek(0, 1);
              auto the_result = at::cudnn_affine_grid_generator(theta, N, C, H, W);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 402: { // cudnn_affine_grid_generator_backward
          int64_t N = readAttribute<int64_t>("N");
          int64_t C = readAttribute<int64_t>("C");
          int64_t H = readAttribute<int64_t>("H");
          int64_t W = readAttribute<int64_t>("W");
          run_op = [=] {
              auto grad = peek(0, 1);
              auto the_result = at::cudnn_affine_grid_generator_backward(grad, N, C, H, W);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 403: { // cudnn_batch_norm
          bool training = readAttribute<int64_t>("training");
          double exponential_average_factor = readAttribute<float>("exponential_average_factor");
          double epsilon = readAttribute<float>("epsilon");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::cudnn_batch_norm(input, weight, bias, running_mean, running_var, training, exponential_average_factor, epsilon);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 404: { // cudnn_batch_norm_backward
          double epsilon = readAttribute<float>("epsilon");
          run_op = [=] {
              auto input = peek(0, 7);
              auto grad_output = peek(1, 7);
              auto weight = peek(2, 7);
              auto running_mean = peek(3, 7);
              auto running_var = peek(4, 7);
              auto save_mean = peek(5, 7);
              auto save_var = peek(6, 7);
              auto the_result = at::cudnn_batch_norm_backward(input, grad_output, weight, running_mean, running_var, save_mean, save_var, epsilon);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 405: { // cudnn_convolution
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::cudnn_convolution(self, weight, bias, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 406: { // cudnn_convolution_backward_input
          auto self_size = readIntArrayRef("self_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::cudnn_convolution_backward_input(self_size, grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 407: { // cudnn_convolution_backward_bias
      
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::cudnn_convolution_backward_bias(grad_output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 408: { // cudnn_convolution_backward_weight
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::cudnn_convolution_backward_weight(weight_size, grad_output, self, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 409: { // cudnn_convolution_transpose
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::cudnn_convolution_transpose(self, weight, bias, padding, output_padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 410: { // cudnn_convolution_transpose_backward_bias
      
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::cudnn_convolution_transpose_backward_bias(grad_output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 411: { // cudnn_convolution_transpose_backward_input
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::cudnn_convolution_transpose_backward_input(grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 412: { // cudnn_convolution_transpose_backward_weight
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::cudnn_convolution_transpose_backward_weight(weight_size, grad_output, self, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 413: { // cudnn_grid_sampler
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto grid = peek(1, 2);
              auto the_result = at::cudnn_grid_sampler(self, grid);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 414: { // cudnn_grid_sampler_backward
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto grid = peek(1, 3);
              auto grad_output = peek(2, 3);
              auto the_result = at::cudnn_grid_sampler_backward(self, grid, grad_output);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 415: { // cumsum
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cumsum(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 416: { // cumprod
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cumprod(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 417: { // ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          int64_t reduction = readAttribute<int64_t>("reduction");
          bool zero_infinity = readAttribute<int64_t>("zero_infinity");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, reduction, zero_infinity);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 418: { // ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 419: { // ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 420: { // ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 421: { // ctc_loss
          int64_t blank = readAttribute<int64_t>("blank");
          int64_t reduction = readAttribute<int64_t>("reduction");
          bool zero_infinity = readAttribute<int64_t>("zero_infinity");
          run_op = [=] {
              auto log_probs = peek(0, 4);
              auto targets = peek(1, 4);
              auto input_lengths = peek(2, 4);
              auto target_lengths = peek(3, 4);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, reduction, zero_infinity);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 422: { // ctc_loss
          int64_t blank = readAttribute<int64_t>("blank");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto log_probs = peek(0, 4);
              auto targets = peek(1, 4);
              auto input_lengths = peek(2, 4);
              auto target_lengths = peek(3, 4);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 423: { // ctc_loss
          int64_t blank = readAttribute<int64_t>("blank");
          run_op = [=] {
              auto log_probs = peek(0, 4);
              auto targets = peek(1, 4);
              auto input_lengths = peek(2, 4);
              auto target_lengths = peek(3, 4);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths, blank);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 424: { // ctc_loss
      
          run_op = [=] {
              auto log_probs = peek(0, 4);
              auto targets = peek(1, 4);
              auto input_lengths = peek(2, 4);
              auto target_lengths = peek(3, 4);
              auto the_result = at::ctc_loss(log_probs, targets, input_lengths, target_lengths);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 425: { // _ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          bool zero_infinity = readAttribute<int64_t>("zero_infinity");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::_ctc_loss(log_probs, targets, input_lengths, target_lengths, blank, zero_infinity);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 426: { // _ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::_ctc_loss(log_probs, targets, input_lengths, target_lengths, blank);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 427: { // _ctc_loss
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          run_op = [=] {
              auto log_probs = peek(0, 2);
              auto targets = peek(1, 2);
              auto the_result = at::_ctc_loss(log_probs, targets, input_lengths, target_lengths);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 428: { // _ctc_loss_backward
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          bool zero_infinity = readAttribute<int64_t>("zero_infinity");
          run_op = [=] {
              auto grad = peek(0, 5);
              auto log_probs = peek(1, 5);
              auto targets = peek(2, 5);
              auto neg_log_likelihood = peek(3, 5);
              auto log_alpha = peek(4, 5);
              auto the_result = at::_ctc_loss_backward(grad, log_probs, targets, input_lengths, target_lengths, neg_log_likelihood, log_alpha, blank, zero_infinity);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 429: { // _ctc_loss_backward
          auto input_lengths = readIntArrayRef("input_lengths");
          auto target_lengths = readIntArrayRef("target_lengths");
          int64_t blank = readAttribute<int64_t>("blank");
          run_op = [=] {
              auto grad = peek(0, 5);
              auto log_probs = peek(1, 5);
              auto targets = peek(2, 5);
              auto neg_log_likelihood = peek(3, 5);
              auto log_alpha = peek(4, 5);
              auto the_result = at::_ctc_loss_backward(grad, log_probs, targets, input_lengths, target_lengths, neg_log_likelihood, log_alpha, blank);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 430: { // det
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::det(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 431: { // diag_embed
          int64_t offset = readAttribute<int64_t>("offset");
          int64_t dim1 = readAttribute<int64_t>("dim1");
          int64_t dim2 = readAttribute<int64_t>("dim2");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag_embed(self, offset, dim1, dim2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 432: { // diag_embed
          int64_t offset = readAttribute<int64_t>("offset");
          int64_t dim1 = readAttribute<int64_t>("dim1");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag_embed(self, offset, dim1);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 433: { // diag_embed
          int64_t offset = readAttribute<int64_t>("offset");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag_embed(self, offset);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 434: { // diag_embed
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag_embed(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 435: { // diagflat
          int64_t offset = readAttribute<int64_t>("offset");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagflat(self, offset);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 436: { // diagflat
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagflat(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 437: { // diagonal
          int64_t offset = readAttribute<int64_t>("offset");
          int64_t dim1 = readAttribute<int64_t>("dim1");
          int64_t dim2 = readAttribute<int64_t>("dim2");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagonal(self, offset, dim1, dim2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 438: { // diagonal
          int64_t offset = readAttribute<int64_t>("offset");
          int64_t dim1 = readAttribute<int64_t>("dim1");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagonal(self, offset, dim1);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 439: { // diagonal
          int64_t offset = readAttribute<int64_t>("offset");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagonal(self, offset);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 440: { // diagonal
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diagonal(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 441: { // div
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::div(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 442: { // div
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::div(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 443: { // dot
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto tensor = peek(1, 2);
              auto the_result = at::dot(self, tensor);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 444: { // embedding
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto weight = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding(weight, indices, padding_idx, scale_grad_by_freq, sparse);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 445: { // embedding
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          run_op = [=] {
              auto weight = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding(weight, indices, padding_idx, scale_grad_by_freq);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 446: { // embedding
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          run_op = [=] {
              auto weight = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding(weight, indices, padding_idx);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 447: { // embedding
      
          run_op = [=] {
              auto weight = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding(weight, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 448: { // embedding_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto grad = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding_backward(grad, indices, num_weights, padding_idx, scale_grad_by_freq, sparse);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 449: { // embedding_dense_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding_dense_backward(grad_output, indices, num_weights, padding_idx, scale_grad_by_freq);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 450: { // embedding_sparse_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          int64_t padding_idx = readAttribute<int64_t>("padding_idx");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          run_op = [=] {
              auto grad = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::embedding_sparse_backward(grad, indices, num_weights, padding_idx, scale_grad_by_freq);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 451: { // embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto weight = peek(0, 4);
              auto indices = peek(1, 4);
              auto offsets = peek(2, 4);
              auto per_sample_weights = peek(3, 4);
              auto the_result = at::embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode, sparse, per_sample_weights);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 452: { // embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode, sparse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 453: { // embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 454: { // embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::embedding_bag(weight, indices, offsets, scale_grad_by_freq);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 455: { // embedding_bag
      
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::embedding_bag(weight, indices, offsets);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 456: { // _embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto weight = peek(0, 4);
              auto indices = peek(1, 4);
              auto offsets = peek(2, 4);
              auto per_sample_weights = peek(3, 4);
              auto the_result = at::_embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode, sparse, per_sample_weights);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 457: { // _embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::_embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode, sparse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 458: { // _embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::_embedding_bag(weight, indices, offsets, scale_grad_by_freq, mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 459: { // _embedding_bag
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::_embedding_bag(weight, indices, offsets, scale_grad_by_freq);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 460: { // _embedding_bag
      
          run_op = [=] {
              auto weight = peek(0, 3);
              auto indices = peek(1, 3);
              auto offsets = peek(2, 3);
              auto the_result = at::_embedding_bag(weight, indices, offsets);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 461: { // _embedding_bag_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          bool sparse = readAttribute<int64_t>("sparse");
          run_op = [=] {
              auto grad = peek(0, 7);
              auto indices = peek(1, 7);
              auto offsets = peek(2, 7);
              auto offset2bag = peek(3, 7);
              auto bag_size = peek(4, 7);
              auto maximum_indices = peek(5, 7);
              auto per_sample_weights = peek(6, 7);
              auto the_result = at::_embedding_bag_backward(grad, indices, offsets, offset2bag, bag_size, maximum_indices, num_weights, scale_grad_by_freq, mode, sparse, per_sample_weights);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 462: { // _embedding_bag_sparse_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          run_op = [=] {
              auto grad = peek(0, 6);
              auto indices = peek(1, 6);
              auto offsets = peek(2, 6);
              auto offset2bag = peek(3, 6);
              auto bag_size = peek(4, 6);
              auto per_sample_weights = peek(5, 6);
              auto the_result = at::_embedding_bag_sparse_backward(grad, indices, offsets, offset2bag, bag_size, num_weights, scale_grad_by_freq, mode, per_sample_weights);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 463: { // _embedding_bag_dense_backward
          int64_t num_weights = readAttribute<int64_t>("num_weights");
          bool scale_grad_by_freq = readAttribute<int64_t>("scale_grad_by_freq");
          int64_t mode = readAttribute<int64_t>("mode");
          run_op = [=] {
              auto grad = peek(0, 7);
              auto indices = peek(1, 7);
              auto offsets = peek(2, 7);
              auto offset2bag = peek(3, 7);
              auto bag_size = peek(4, 7);
              auto maximum_indices = peek(5, 7);
              auto per_sample_weights = peek(6, 7);
              auto the_result = at::_embedding_bag_dense_backward(grad, indices, offsets, offset2bag, bag_size, maximum_indices, num_weights, scale_grad_by_freq, mode, per_sample_weights);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 464: { // _embedding_bag_per_sample_weights_backward
          int64_t mode = readAttribute<int64_t>("mode");
          run_op = [=] {
              auto grad = peek(0, 5);
              auto weight = peek(1, 5);
              auto indices = peek(2, 5);
              auto offsets = peek(3, 5);
              auto offset2bag = peek(4, 5);
              auto the_result = at::_embedding_bag_per_sample_weights_backward(grad, weight, indices, offsets, offset2bag, mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 465: { // erf
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::erf(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 466: { // erfc
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::erfc(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 467: { // exp
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::exp(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 468: { // expm1
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::expm1(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 469: { // expand
          auto size = readIntArrayRef("size");
          bool implicit = readAttribute<int64_t>("implicit");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.expand(size, implicit);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 470: { // expand
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.expand(size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 471: { // expand_as
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = self.expand_as(other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 472: { // flatten
          int64_t start_dim = readAttribute<int64_t>("start_dim");
          int64_t end_dim = readAttribute<int64_t>("end_dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::flatten(self, start_dim, end_dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 473: { // flatten
          int64_t start_dim = readAttribute<int64_t>("start_dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::flatten(self, start_dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 474: { // flatten
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::flatten(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 475: { // floor
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::floor(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 476: { // frac
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::frac(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 477: { // grid_sampler
          int64_t interpolation_mode = readAttribute<int64_t>("interpolation_mode");
          int64_t padding_mode = readAttribute<int64_t>("padding_mode");
          run_op = [=] {
              auto input = peek(0, 2);
              auto grid = peek(1, 2);
              auto the_result = at::grid_sampler(input, grid, interpolation_mode, padding_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 478: { // grid_sampler_2d
          int64_t interpolation_mode = readAttribute<int64_t>("interpolation_mode");
          int64_t padding_mode = readAttribute<int64_t>("padding_mode");
          run_op = [=] {
              auto input = peek(0, 2);
              auto grid = peek(1, 2);
              auto the_result = at::grid_sampler_2d(input, grid, interpolation_mode, padding_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 479: { // grid_sampler_2d_backward
          int64_t interpolation_mode = readAttribute<int64_t>("interpolation_mode");
          int64_t padding_mode = readAttribute<int64_t>("padding_mode");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto input = peek(1, 3);
              auto grid = peek(2, 3);
              auto the_result = at::grid_sampler_2d_backward(grad_output, input, grid, interpolation_mode, padding_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 480: { // grid_sampler_3d
          int64_t interpolation_mode = readAttribute<int64_t>("interpolation_mode");
          int64_t padding_mode = readAttribute<int64_t>("padding_mode");
          run_op = [=] {
              auto input = peek(0, 2);
              auto grid = peek(1, 2);
              auto the_result = at::grid_sampler_3d(input, grid, interpolation_mode, padding_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 481: { // grid_sampler_3d_backward
          int64_t interpolation_mode = readAttribute<int64_t>("interpolation_mode");
          int64_t padding_mode = readAttribute<int64_t>("padding_mode");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto input = peek(1, 3);
              auto grid = peek(2, 3);
              auto the_result = at::grid_sampler_3d_backward(grad_output, input, grid, interpolation_mode, padding_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 482: { // hinge_embedding_loss
          double margin = readAttribute<float>("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::hinge_embedding_loss(self, target, margin, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 483: { // hinge_embedding_loss
          double margin = readAttribute<float>("margin");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::hinge_embedding_loss(self, target, margin);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 484: { // hinge_embedding_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::hinge_embedding_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 485: { // ger
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto vec2 = peek(1, 2);
              auto the_result = at::ger(self, vec2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 486: { // group_norm
          int64_t num_groups = readAttribute<int64_t>("num_groups");
          double eps = readAttribute<float>("eps");
          bool cudnn_enabled = readAttribute<int64_t>("cudnn_enabled");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::group_norm(input, num_groups, weight, bias, eps, cudnn_enabled);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 487: { // group_norm
          int64_t num_groups = readAttribute<int64_t>("num_groups");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::group_norm(input, num_groups, weight, bias, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 488: { // group_norm
          int64_t num_groups = readAttribute<int64_t>("num_groups");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::group_norm(input, num_groups, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 489: { // group_norm
          int64_t num_groups = readAttribute<int64_t>("num_groups");
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::group_norm(input, num_groups, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 490: { // group_norm
          int64_t num_groups = readAttribute<int64_t>("num_groups");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::group_norm(input, num_groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 491: { // fft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::fft(self, signal_ndim, normalized);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 492: { // fft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::fft(self, signal_ndim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 493: { // ifft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::ifft(self, signal_ndim, normalized);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 494: { // ifft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::ifft(self, signal_ndim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 495: { // rfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          bool onesided = readAttribute<int64_t>("onesided");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rfft(self, signal_ndim, normalized, onesided);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 496: { // rfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rfft(self, signal_ndim, normalized);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 497: { // rfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rfft(self, signal_ndim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 498: { // irfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          bool onesided = readAttribute<int64_t>("onesided");
          auto signal_sizes = readIntArrayRef("signal_sizes");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::irfft(self, signal_ndim, normalized, onesided, signal_sizes);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 499: { // irfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          bool onesided = readAttribute<int64_t>("onesided");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::irfft(self, signal_ndim, normalized, onesided);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 500: { // irfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool normalized = readAttribute<int64_t>("normalized");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::irfft(self, signal_ndim, normalized);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 501: { // irfft
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::irfft(self, signal_ndim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 502: { // _fft_with_size
          int64_t signal_ndim = readAttribute<int64_t>("signal_ndim");
          bool complex_input = readAttribute<int64_t>("complex_input");
          bool complex_output = readAttribute<int64_t>("complex_output");
          bool inverse = readAttribute<int64_t>("inverse");
          auto checked_signal_sizes = readIntArrayRef("checked_signal_sizes");
          bool normalized = readAttribute<int64_t>("normalized");
          bool onesided = readAttribute<int64_t>("onesided");
          auto output_sizes = readIntArrayRef("output_sizes");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_fft_with_size(self, signal_ndim, complex_input, complex_output, inverse, checked_signal_sizes, normalized, onesided, output_sizes);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 503: { // _cufft_get_plan_cache_size
          int64_t device_index = readAttribute<int64_t>("device_index");
          run_op = [=] {
      
              auto the_result = at::_cufft_get_plan_cache_size(device_index);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 504: { // _cufft_get_plan_cache_max_size
          int64_t device_index = readAttribute<int64_t>("device_index");
          run_op = [=] {
      
              auto the_result = at::_cufft_get_plan_cache_max_size(device_index);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 505: { // index
      
          run_op = [=] {
              auto self = peek(0, InputSize());
              auto indices = peekSlice(1, InputSize() - 1, InputSize());
              auto the_result = at::index(self, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 506: { // index_copy
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto source = peek(2, 3);
              auto the_result = at::index_copy(self, dim, index, source);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 507: { // index_put
          bool accumulate = readAttribute<int64_t>("accumulate");
          run_op = [=] {
              auto self = peek(0, InputSize());
              auto indices = peekSlice(1, InputSize() - 2, InputSize());
              auto values = peek(1, 2);
              auto the_result = at::index_put(self, indices, values, accumulate);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 508: { // index_put
      
          run_op = [=] {
              auto self = peek(0, InputSize());
              auto indices = peekSlice(1, InputSize() - 2, InputSize());
              auto values = peek(1, 2);
              auto the_result = at::index_put(self, indices, values);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 509: { // instance_norm
          bool use_input_stats = readAttribute<int64_t>("use_input_stats");
          double momentum = readAttribute<float>("momentum");
          double eps = readAttribute<float>("eps");
          bool cudnn_enabled = readAttribute<int64_t>("cudnn_enabled");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::instance_norm(input, weight, bias, running_mean, running_var, use_input_stats, momentum, eps, cudnn_enabled);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 510: { // inverse
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::inverse(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 511: { // _inverse_helper
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_inverse_helper(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 512: { // isclose
          double rtol = readAttribute<float>("rtol");
          double atol = readAttribute<float>("atol");
          bool equal_nan = readAttribute<int64_t>("equal_nan");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::isclose(self, other, rtol, atol, equal_nan);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 513: { // isclose
          double rtol = readAttribute<float>("rtol");
          double atol = readAttribute<float>("atol");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::isclose(self, other, rtol, atol);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 514: { // isclose
          double rtol = readAttribute<float>("rtol");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::isclose(self, other, rtol);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 515: { // isclose
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::isclose(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 516: { // isnan
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::isnan(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 517: { // is_distributed
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::is_distributed(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 518: { // is_floating_point
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::is_floating_point(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 519: { // is_complex
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::is_complex(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 520: { // is_nonzero
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::is_nonzero(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 521: { // is_same_size
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::is_same_size(self, other);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 522: { // is_signed
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::is_signed(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 523: { // kl_div
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::kl_div(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 524: { // kl_div
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::kl_div(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 525: { // kl_div_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::kl_div_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 526: { // kl_div_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::kl_div_backward(grad_output, self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 527: { // kthvalue
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::kthvalue(self, k, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 528: { // kthvalue
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::kthvalue(self, k, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 529: { // kthvalue
          int64_t k = readAttribute<int64_t>("k");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::kthvalue(self, k);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 530: { // layer_norm
          auto normalized_shape = readIntArrayRef("normalized_shape");
          double eps = readAttribute<float>("eps");
          bool cudnn_enable = readAttribute<int64_t>("cudnn_enable");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::layer_norm(input, normalized_shape, weight, bias, eps, cudnn_enable);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 531: { // layer_norm
          auto normalized_shape = readIntArrayRef("normalized_shape");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::layer_norm(input, normalized_shape, weight, bias, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 532: { // layer_norm
          auto normalized_shape = readIntArrayRef("normalized_shape");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::layer_norm(input, normalized_shape, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 533: { // layer_norm
          auto normalized_shape = readIntArrayRef("normalized_shape");
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::layer_norm(input, normalized_shape, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 534: { // layer_norm
          auto normalized_shape = readIntArrayRef("normalized_shape");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::layer_norm(input, normalized_shape);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 535: { // linear
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::linear(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 536: { // linear
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::linear(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 537: { // mkldnn_linear
      
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::mkldnn_linear(input, weight, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 538: { // mkldnn_linear
      
          run_op = [=] {
              auto input = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::mkldnn_linear(input, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 539: { // fbgemm_linear_int8_weight
          at::Scalar weight_scale = readScalarAttribute("weight_scale");
          at::Scalar weight_zero_point = readScalarAttribute("weight_zero_point");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto packed = peek(2, 5);
              auto col_offsets = peek(3, 5);
              auto bias = peek(4, 5);
              auto the_result = at::fbgemm_linear_int8_weight(input, weight, packed, col_offsets, weight_scale, weight_zero_point, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 540: { // fbgemm_pack_quantized_matrix
          int64_t K = readAttribute<int64_t>("K");
          int64_t N = readAttribute<int64_t>("N");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::fbgemm_pack_quantized_matrix(input, K, N);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 541: { // fbgemm_is_cpu_supported
      
          run_op = [=] {
      
              auto the_result = at::fbgemm_is_cpu_supported();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 542: { // log
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 543: { // log10
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log10(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 544: { // log1p
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log1p(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 545: { // log2
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log2(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 546: { // logdet
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::logdet(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 547: { // log_softmax
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log_softmax(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 548: { // _log_softmax
          int64_t dim = readAttribute<int64_t>("dim");
          bool half_to_float = readAttribute<int64_t>("half_to_float");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_log_softmax(self, dim, half_to_float);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 549: { // _log_softmax_backward_data
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto output = peek(1, 3);
              auto self = peek(2, 3);
              auto the_result = at::_log_softmax_backward_data(grad_output, output, dim, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 550: { // logsumexp
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::logsumexp(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 551: { // logsumexp
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::logsumexp(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 552: { // margin_ranking_loss
          double margin = readAttribute<float>("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::margin_ranking_loss(input1, input2, target, margin, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 553: { // margin_ranking_loss
          double margin = readAttribute<float>("margin");
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::margin_ranking_loss(input1, input2, target, margin);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 554: { // margin_ranking_loss
      
          run_op = [=] {
              auto input1 = peek(0, 3);
              auto input2 = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::margin_ranking_loss(input1, input2, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 555: { // matmul
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::matmul(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 556: { // matrix_rank
          double tol = readAttribute<float>("tol");
          bool symmetric = readAttribute<int64_t>("symmetric");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::matrix_rank(self, tol, symmetric);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 557: { // matrix_rank
          double tol = readAttribute<float>("tol");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::matrix_rank(self, tol);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 558: { // matrix_rank
          bool symmetric = readAttribute<int64_t>("symmetric");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::matrix_rank(self, symmetric);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 559: { // matrix_rank
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::matrix_rank(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 560: { // matrix_power
          int64_t n = readAttribute<int64_t>("n");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::matrix_power(self, n);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 561: { // max
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 562: { // max
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 563: { // max_values
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_values(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 564: { // max_values
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_values(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 565: { // max_pool1d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d_with_indices(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 566: { // max_pool1d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d_with_indices(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 567: { // max_pool1d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d_with_indices(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 568: { // max_pool1d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d_with_indices(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 569: { // max_pool1d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d_with_indices(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 570: { // max_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 571: { // max_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 572: { // max_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 573: { // max_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 574: { // max_pool1d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool1d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 575: { // max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 576: { // max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 577: { // max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 578: { // max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 579: { // max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 580: { // mkldnn_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_max_pool2d(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 581: { // mkldnn_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_max_pool2d(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 582: { // mkldnn_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_max_pool2d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 583: { // mkldnn_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_max_pool2d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 584: { // mkldnn_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_max_pool2d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 585: { // max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 586: { // max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 587: { // max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 588: { // max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 589: { // max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 590: { // mean
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mean(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 591: { // mean
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mean(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 592: { // mean
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mean(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 593: { // median
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::median(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 594: { // median
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::median(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 595: { // min
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::min(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 596: { // min
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::min(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 597: { // min_values
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::min_values(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 598: { // min_values
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::min_values(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 599: { // mkldnn_convolution
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::mkldnn_convolution(self, weight, bias, padding, stride, dilation, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 600: { // mkldnn_convolution_backward_input
          auto self_size = readIntArrayRef("self_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool bias_defined = readAttribute<int64_t>("bias_defined");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::mkldnn_convolution_backward_input(self_size, grad_output, weight, padding, stride, dilation, groups, bias_defined);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 601: { // mkldnn_convolution_backward_weights
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool bias_defined = readAttribute<int64_t>("bias_defined");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::mkldnn_convolution_backward_weights(weight_size, grad_output, self, padding, stride, dilation, groups, bias_defined);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 602: { // miopen_batch_norm
          bool training = readAttribute<int64_t>("training");
          double exponential_average_factor = readAttribute<float>("exponential_average_factor");
          double epsilon = readAttribute<float>("epsilon");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::miopen_batch_norm(input, weight, bias, running_mean, running_var, training, exponential_average_factor, epsilon);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 603: { // miopen_batch_norm_backward
          double epsilon = readAttribute<float>("epsilon");
          run_op = [=] {
              auto input = peek(0, 7);
              auto grad_output = peek(1, 7);
              auto weight = peek(2, 7);
              auto running_mean = peek(3, 7);
              auto running_var = peek(4, 7);
              auto save_mean = peek(5, 7);
              auto save_var = peek(6, 7);
              auto the_result = at::miopen_batch_norm_backward(input, grad_output, weight, running_mean, running_var, save_mean, save_var, epsilon);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 604: { // miopen_convolution
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::miopen_convolution(self, weight, bias, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 605: { // miopen_convolution_backward_input
          auto self_size = readIntArrayRef("self_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::miopen_convolution_backward_input(self_size, grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 606: { // miopen_convolution_backward_bias
      
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::miopen_convolution_backward_bias(grad_output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 607: { // miopen_convolution_backward_weight
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::miopen_convolution_backward_weight(weight_size, grad_output, self, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 608: { // miopen_convolution_transpose
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::miopen_convolution_transpose(self, weight, bias, padding, output_padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 609: { // miopen_convolution_transpose_backward_input
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::miopen_convolution_transpose_backward_input(grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 610: { // miopen_convolution_transpose_backward_weight
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::miopen_convolution_transpose_backward_weight(weight_size, grad_output, self, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 611: { // miopen_depthwise_convolution
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::miopen_depthwise_convolution(self, weight, bias, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 612: { // miopen_depthwise_convolution_backward_input
          auto self_size = readIntArrayRef("self_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::miopen_depthwise_convolution_backward_input(self_size, grad_output, weight, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 613: { // miopen_depthwise_convolution_backward_weight
          auto weight_size = readIntArrayRef("weight_size");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          bool benchmark = readAttribute<int64_t>("benchmark");
          bool deterministic = readAttribute<int64_t>("deterministic");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::miopen_depthwise_convolution_backward_weight(weight_size, grad_output, self, padding, stride, dilation, groups, benchmark, deterministic);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 614: { // mm
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mat2 = peek(1, 2);
              auto the_result = at::mm(self, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 615: { // _sparse_mm
      
          run_op = [=] {
              auto sparse = peek(0, 2);
              auto dense = peek(1, 2);
              auto the_result = at::_sparse_mm(sparse, dense);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 616: { // mode
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mode(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 617: { // mode
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mode(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 618: { // mode
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mode(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 619: { // mul
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::mul(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 620: { // mul
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mul(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 621: { // mv
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto vec = peek(1, 2);
              auto the_result = at::mv(self, vec);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 622: { // mvlgamma
          int64_t p = readAttribute<int64_t>("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mvlgamma(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 623: { // narrow_copy
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t start = readAttribute<int64_t>("start");
          int64_t length = readAttribute<int64_t>("length");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.narrow_copy(dim, start, length);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 624: { // narrow
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t start = readAttribute<int64_t>("start");
          int64_t length = readAttribute<int64_t>("length");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::narrow(self, dim, start, length);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 625: { // native_batch_norm
          bool training = readAttribute<int64_t>("training");
          double momentum = readAttribute<float>("momentum");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::native_batch_norm(input, weight, bias, running_mean, running_var, training, momentum, eps);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 626: { // batch_norm_stats
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto input = peek(0, 1);
              auto the_result = at::batch_norm_stats(input, eps);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 627: { // batch_norm_elemt
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto input = peek(0, 5);
              auto weight = peek(1, 5);
              auto bias = peek(2, 5);
              auto mean = peek(3, 5);
              auto invstd = peek(4, 5);
              auto the_result = at::batch_norm_elemt(input, weight, bias, mean, invstd, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 628: { // batch_norm_gather_stats
          double momentum = readAttribute<float>("momentum");
          double eps = readAttribute<float>("eps");
          int64_t count = readAttribute<int64_t>("count");
          run_op = [=] {
              auto input = peek(0, 5);
              auto mean = peek(1, 5);
              auto invstd = peek(2, 5);
              auto running_mean = peek(3, 5);
              auto running_var = peek(4, 5);
              auto the_result = at::batch_norm_gather_stats(input, mean, invstd, running_mean, running_var, momentum, eps, count);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 629: { // batch_norm_backward_reduce
          bool input_g = readAttribute<int64_t>("input_g");
          bool weight_g = readAttribute<int64_t>("weight_g");
          bool bias_g = readAttribute<int64_t>("bias_g");
          run_op = [=] {
              auto grad_out = peek(0, 4);
              auto input = peek(1, 4);
              auto mean = peek(2, 4);
              auto invstd = peek(3, 4);
              auto the_result = at::batch_norm_backward_reduce(grad_out, input, mean, invstd, input_g, weight_g, bias_g);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
              return true;
          };
      } break;
      case 630: { // batch_norm_backward_elemt
      
          run_op = [=] {
              auto grad_out = peek(0, 7);
              auto input = peek(1, 7);
              auto mean = peek(2, 7);
              auto invstd = peek(3, 7);
              auto weight = peek(4, 7);
              auto mean_dy = peek(5, 7);
              auto mean_dy_xmu = peek(6, 7);
              auto the_result = at::batch_norm_backward_elemt(grad_out, input, mean, invstd, weight, mean_dy, mean_dy_xmu);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 631: { // batch_norm_update_stats
          double momentum = readAttribute<float>("momentum");
          run_op = [=] {
              auto input = peek(0, 3);
              auto running_mean = peek(1, 3);
              auto running_var = peek(2, 3);
              auto the_result = at::batch_norm_update_stats(input, running_mean, running_var, momentum);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 632: { // _nnpack_available
      
          run_op = [=] {
      
              auto the_result = at::_nnpack_available();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 633: { // _nnpack_spatial_convolution
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::_nnpack_spatial_convolution(input, weight, bias, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 634: { // _nnpack_spatial_convolution_backward_input
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 3);
              auto grad_output = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::_nnpack_spatial_convolution_backward_input(input, grad_output, weight, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 635: { // _nnpack_spatial_convolution_backward_weight
          auto weightsize = readIntArrayRef("weightsize");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto input = peek(0, 2);
              auto grad_output = peek(1, 2);
              auto the_result = at::_nnpack_spatial_convolution_backward_weight(input, weightsize, grad_output, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 636: { // pairwise_distance
          double p = readAttribute<float>("p");
          double eps = readAttribute<float>("eps");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::pairwise_distance(x1, x2, p, eps, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 637: { // pairwise_distance
          double p = readAttribute<float>("p");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::pairwise_distance(x1, x2, p, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 638: { // pairwise_distance
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::pairwise_distance(x1, x2, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 639: { // pairwise_distance
      
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::pairwise_distance(x1, x2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 640: { // cdist
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::cdist(x1, x2, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 641: { // cdist
      
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::cdist(x1, x2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 642: { // _cdist_backward
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto grad = peek(0, 4);
              auto x1 = peek(1, 4);
              auto x2 = peek(2, 4);
              auto cdist = peek(3, 4);
              auto the_result = at::_cdist_backward(grad, x1, x2, p, cdist);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 643: { // pdist
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pdist(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 644: { // pdist
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pdist(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 645: { // _pdist_forward
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_pdist_forward(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 646: { // _pdist_forward
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_pdist_forward(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 647: { // _pdist_backward
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto grad = peek(0, 3);
              auto self = peek(1, 3);
              auto pdist = peek(2, 3);
              auto the_result = at::_pdist_backward(grad, self, p, pdist);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 648: { // cosine_similarity
          int64_t dim = readAttribute<int64_t>("dim");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::cosine_similarity(x1, x2, dim, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 649: { // cosine_similarity
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::cosine_similarity(x1, x2, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 650: { // cosine_similarity
      
          run_op = [=] {
              auto x1 = peek(0, 2);
              auto x2 = peek(1, 2);
              auto the_result = at::cosine_similarity(x1, x2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 651: { // permute
          auto dims = readIntArrayRef("dims");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.permute(dims);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 652: { // pixel_shuffle
          int64_t upscale_factor = readAttribute<int64_t>("upscale_factor");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pixel_shuffle(self, upscale_factor);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 653: { // pin_memory
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pin_memory(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 654: { // pinverse
          double rcond = readAttribute<float>("rcond");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pinverse(self, rcond);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 655: { // pinverse
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pinverse(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 656: { // reciprocal
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::reciprocal(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 657: { // neg
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::neg(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 658: { // repeat
          auto repeats = readIntArrayRef("repeats");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.repeat(repeats);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 659: { // repeat_interleave
      
          run_op = [=] {
              auto repeats = peek(0, 1);
              auto the_result = at::repeat_interleave(repeats);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 660: { // repeat_interleave
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto repeats = peek(1, 2);
              auto the_result = at::repeat_interleave(self, repeats);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 661: { // repeat_interleave
          int64_t repeats = readAttribute<int64_t>("repeats");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::repeat_interleave(self, repeats);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 662: { // reshape
          auto shape = readIntArrayRef("shape");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::reshape(self, shape);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 663: { // mkldnn_reshape
          auto shape = readIntArrayRef("shape");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_reshape(self, shape);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 664: { // reshape_as
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = self.reshape_as(other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 665: { // round
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::round(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 666: { // rrelu
          at::Scalar lower = readScalarAttribute("lower");
          at::Scalar upper = readScalarAttribute("upper");
          bool training = readAttribute<int64_t>("training");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rrelu(self, lower, upper, training);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 667: { // rrelu
          at::Scalar lower = readScalarAttribute("lower");
          at::Scalar upper = readScalarAttribute("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rrelu(self, lower, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 668: { // rrelu
          at::Scalar lower = readScalarAttribute("lower");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rrelu(self, lower);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 669: { // rrelu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rrelu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 670: { // relu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::relu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 671: { // prelu
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::prelu(self, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 672: { // prelu_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::prelu_backward(grad_output, self, weight);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 673: { // hardshrink
          at::Scalar lambd = readScalarAttribute("lambd");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::hardshrink(self, lambd);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 674: { // hardshrink
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::hardshrink(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 675: { // hardshrink_backward
          at::Scalar lambd = readScalarAttribute("lambd");
          run_op = [=] {
              auto grad_out = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::hardshrink_backward(grad_out, self, lambd);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 676: { // rsqrt
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rsqrt(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 677: { // select
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t index = readAttribute<int64_t>("index");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::select(self, dim, index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 678: { // selu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::selu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 679: { // celu
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::celu(self, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 680: { // celu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::celu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 681: { // sigmoid
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sigmoid(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 682: { // sin
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sin(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 683: { // sinh
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sinh(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 684: { // detach
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::detach(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 685: { // size
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::size(self, dim);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 686: { // slice
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t start = readAttribute<int64_t>("start");
          int64_t end = readAttribute<int64_t>("end");
          int64_t step = readAttribute<int64_t>("step");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slice(self, dim, start, end, step);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 687: { // slice
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t start = readAttribute<int64_t>("start");
          int64_t end = readAttribute<int64_t>("end");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slice(self, dim, start, end);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 688: { // slice
          int64_t dim = readAttribute<int64_t>("dim");
          int64_t start = readAttribute<int64_t>("start");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slice(self, dim, start);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 689: { // slice
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slice(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 690: { // slice
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slice(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 691: { // slogdet
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::slogdet(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 692: { // smm
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mat2 = peek(1, 2);
              auto the_result = at::smm(self, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 693: { // softmax
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softmax(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 694: { // _softmax
          int64_t dim = readAttribute<int64_t>("dim");
          bool half_to_float = readAttribute<int64_t>("half_to_float");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_softmax(self, dim, half_to_float);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 695: { // _softmax_backward_data
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto output = peek(1, 3);
              auto self = peek(2, 3);
              auto the_result = at::_softmax_backward_data(grad_output, output, dim, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 696: { // split
          int64_t split_size = readAttribute<int64_t>("split_size");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::split(self, split_size, dim);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 697: { // split
          int64_t split_size = readAttribute<int64_t>("split_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::split(self, split_size);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 698: { // split_with_sizes
          auto split_sizes = readIntArrayRef("split_sizes");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::split_with_sizes(self, split_sizes, dim);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 699: { // split_with_sizes
          auto split_sizes = readIntArrayRef("split_sizes");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::split_with_sizes(self, split_sizes);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 700: { // squeeze
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::squeeze(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 701: { // squeeze
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::squeeze(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 702: { // sspaddmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::sspaddmm(self, mat1, mat2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 703: { // sspaddmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::sspaddmm(self, mat1, mat2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 704: { // sspaddmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::sspaddmm(self, mat1, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 705: { // stack
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::stack(tensors, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 706: { // stack
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::stack(tensors);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 707: { // stft
          int64_t n_fft = readAttribute<int64_t>("n_fft");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::stft(self, n_fft);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 708: { // stride
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::stride(self, dim);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 709: { // sum
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sum(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 710: { // sum
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sum(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 711: { // sum
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sum(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 712: { // sum_to_size
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.sum_to_size(size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 713: { // sqrt
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sqrt(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 714: { // std
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std(self, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 715: { // std
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 716: { // std
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std(self, dim, unbiased, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 717: { // std
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std(self, dim, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 718: { // std
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::std(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 719: { // prod
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::prod(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 720: { // prod
          int64_t dim = readAttribute<int64_t>("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::prod(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 721: { // prod
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::prod(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 722: { // t
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::t(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 723: { // tan
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::tan(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 724: { // tanh
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::tanh(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 725: { // tensordot
          auto dims_self = readIntArrayRef("dims_self");
          auto dims_other = readIntArrayRef("dims_other");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::tensordot(self, other, dims_self, dims_other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 726: { // threshold
          at::Scalar threshold = readScalarAttribute("threshold");
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::threshold(self, threshold, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 727: { // threshold_backward
          at::Scalar threshold = readScalarAttribute("threshold");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::threshold_backward(grad_output, self, threshold);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 728: { // transpose
          int64_t dim0 = readAttribute<int64_t>("dim0");
          int64_t dim1 = readAttribute<int64_t>("dim1");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::transpose(self, dim0, dim1);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 729: { // one_hot
          int64_t num_classes = readAttribute<int64_t>("num_classes");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::one_hot(self, num_classes);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 730: { // one_hot
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::one_hot(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 731: { // flip
          auto dims = readIntArrayRef("dims");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::flip(self, dims);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 732: { // roll
          auto shifts = readIntArrayRef("shifts");
          auto dims = readIntArrayRef("dims");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::roll(self, shifts, dims);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 733: { // roll
          auto shifts = readIntArrayRef("shifts");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::roll(self, shifts);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 734: { // rot90
          int64_t k = readAttribute<int64_t>("k");
          auto dims = readIntArrayRef("dims");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rot90(self, k, dims);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 735: { // rot90
          int64_t k = readAttribute<int64_t>("k");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rot90(self, k);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 736: { // rot90
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rot90(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 737: { // _trilinear
          auto expand1 = readIntArrayRef("expand1");
          auto expand2 = readIntArrayRef("expand2");
          auto expand3 = readIntArrayRef("expand3");
          auto sumdim = readIntArrayRef("sumdim");
          int64_t unroll_dim = readAttribute<int64_t>("unroll_dim");
          run_op = [=] {
              auto i1 = peek(0, 3);
              auto i2 = peek(1, 3);
              auto i3 = peek(2, 3);
              auto the_result = at::_trilinear(i1, i2, i3, expand1, expand2, expand3, sumdim, unroll_dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 738: { // _trilinear
          auto expand1 = readIntArrayRef("expand1");
          auto expand2 = readIntArrayRef("expand2");
          auto expand3 = readIntArrayRef("expand3");
          auto sumdim = readIntArrayRef("sumdim");
          run_op = [=] {
              auto i1 = peek(0, 3);
              auto i2 = peek(1, 3);
              auto i3 = peek(2, 3);
              auto the_result = at::_trilinear(i1, i2, i3, expand1, expand2, expand3, sumdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 739: { // triplet_margin_loss
          double margin = readAttribute<float>("margin");
          double p = readAttribute<float>("p");
          double eps = readAttribute<float>("eps");
          bool swap = readAttribute<int64_t>("swap");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative, margin, p, eps, swap, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 740: { // triplet_margin_loss
          double margin = readAttribute<float>("margin");
          double p = readAttribute<float>("p");
          double eps = readAttribute<float>("eps");
          bool swap = readAttribute<int64_t>("swap");
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative, margin, p, eps, swap);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 741: { // triplet_margin_loss
          double margin = readAttribute<float>("margin");
          double p = readAttribute<float>("p");
          double eps = readAttribute<float>("eps");
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative, margin, p, eps);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 742: { // triplet_margin_loss
          double margin = readAttribute<float>("margin");
          double p = readAttribute<float>("p");
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative, margin, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 743: { // triplet_margin_loss
          double margin = readAttribute<float>("margin");
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative, margin);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 744: { // triplet_margin_loss
      
          run_op = [=] {
              auto anchor = peek(0, 3);
              auto positive = peek(1, 3);
              auto negative = peek(2, 3);
              auto the_result = at::triplet_margin_loss(anchor, positive, negative);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 745: { // trunc
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::trunc(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 746: { // type_as
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = self.type_as(other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 747: { // _unique
          bool sorted = readAttribute<int64_t>("sorted");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique(self, sorted, return_inverse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 748: { // _unique
          bool sorted = readAttribute<int64_t>("sorted");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique(self, sorted);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 749: { // _unique
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 750: { // unique_dim
          int64_t dim = readAttribute<int64_t>("dim");
          bool sorted = readAttribute<int64_t>("sorted");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          bool return_counts = readAttribute<int64_t>("return_counts");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim(self, dim, sorted, return_inverse, return_counts);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 751: { // unique_dim
          int64_t dim = readAttribute<int64_t>("dim");
          bool sorted = readAttribute<int64_t>("sorted");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim(self, dim, sorted, return_inverse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 752: { // unique_dim
          int64_t dim = readAttribute<int64_t>("dim");
          bool sorted = readAttribute<int64_t>("sorted");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim(self, dim, sorted);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 753: { // unique_dim
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 754: { // unique_consecutive
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          bool return_counts = readAttribute<int64_t>("return_counts");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_consecutive(self, return_inverse, return_counts);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 755: { // unique_consecutive
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_consecutive(self, return_inverse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 756: { // unique_consecutive
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_consecutive(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 757: { // unique_dim_consecutive
          int64_t dim = readAttribute<int64_t>("dim");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          bool return_counts = readAttribute<int64_t>("return_counts");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim_consecutive(self, dim, return_inverse, return_counts);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 758: { // unique_dim_consecutive
          int64_t dim = readAttribute<int64_t>("dim");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim_consecutive(self, dim, return_inverse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 759: { // unique_dim_consecutive
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unique_dim_consecutive(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 760: { // _unique2
          bool sorted = readAttribute<int64_t>("sorted");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          bool return_counts = readAttribute<int64_t>("return_counts");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique2(self, sorted, return_inverse, return_counts);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 761: { // _unique2
          bool sorted = readAttribute<int64_t>("sorted");
          bool return_inverse = readAttribute<int64_t>("return_inverse");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique2(self, sorted, return_inverse);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 762: { // _unique2
          bool sorted = readAttribute<int64_t>("sorted");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique2(self, sorted);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 763: { // _unique2
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unique2(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 764: { // _unsafe_view
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_unsafe_view(self, size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 765: { // unsqueeze
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unsqueeze(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 766: { // var
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var(self, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 767: { // var
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 768: { // var
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var(self, dim, unbiased, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 769: { // var
          auto dim = readIntArrayRef("dim");
          bool unbiased = readAttribute<int64_t>("unbiased");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var(self, dim, unbiased);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 770: { // var
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::var(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 771: { // view_as
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = self.view_as(other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 772: { // where
      
          run_op = [=] {
              auto condition = peek(0, 3);
              auto self = peek(1, 3);
              auto other = peek(2, 3);
              auto the_result = at::where(condition, self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 773: { // _s_where
      
          run_op = [=] {
              auto condition = peek(0, 3);
              auto self = peek(1, 3);
              auto other = peek(2, 3);
              auto the_result = at::_s_where(condition, self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 774: { // norm_except_dim
          int64_t pow = readAttribute<int64_t>("pow");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto v = peek(0, 1);
              auto the_result = at::norm_except_dim(v, pow, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 775: { // norm_except_dim
          int64_t pow = readAttribute<int64_t>("pow");
          run_op = [=] {
              auto v = peek(0, 1);
              auto the_result = at::norm_except_dim(v, pow);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 776: { // norm_except_dim
      
          run_op = [=] {
              auto v = peek(0, 1);
              auto the_result = at::norm_except_dim(v);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 777: { // _weight_norm
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto v = peek(0, 2);
              auto g = peek(1, 2);
              auto the_result = at::_weight_norm(v, g, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 778: { // _weight_norm
      
          run_op = [=] {
              auto v = peek(0, 2);
              auto g = peek(1, 2);
              auto the_result = at::_weight_norm(v, g);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 779: { // _weight_norm_cuda_interface
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto v = peek(0, 2);
              auto g = peek(1, 2);
              auto the_result = at::_weight_norm_cuda_interface(v, g, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 780: { // _weight_norm_cuda_interface
      
          run_op = [=] {
              auto v = peek(0, 2);
              auto g = peek(1, 2);
              auto the_result = at::_weight_norm_cuda_interface(v, g);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 781: { // _weight_norm_cuda_interface_backward
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto grad_w = peek(0, 4);
              auto saved_v = peek(1, 4);
              auto saved_g = peek(2, 4);
              auto saved_norms = peek(3, 4);
              auto the_result = at::_weight_norm_cuda_interface_backward(grad_w, saved_v, saved_g, saved_norms, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 782: { // _weight_norm_differentiable_backward
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto grad_w = peek(0, 4);
              auto saved_v = peek(1, 4);
              auto saved_g = peek(2, 4);
              auto saved_norms = peek(3, 4);
              auto the_result = at::_weight_norm_differentiable_backward(grad_w, saved_v, saved_g, saved_norms, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 783: { // _standard_gamma_grad
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto output = peek(1, 2);
              auto the_result = at::_standard_gamma_grad(self, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 784: { // _standard_gamma
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_standard_gamma(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 785: { // _sample_dirichlet
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_sample_dirichlet(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 786: { // poisson
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::poisson(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 787: { // native_norm
          at::Scalar p = readScalarAttribute("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::native_norm(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 788: { // native_norm
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::native_norm(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 789: { // _sparse_sum
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_sparse_sum(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 790: { // _sparse_sum
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_sparse_sum(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 791: { // _sparse_sum_backward
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto grad = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::_sparse_sum_backward(grad, self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 792: { // norm
          at::Scalar p = readScalarAttribute("p");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::norm(self, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 793: { // norm
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::norm(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 794: { // frobenius_norm
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::frobenius_norm(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 795: { // frobenius_norm
          auto dim = readIntArrayRef("dim");
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::frobenius_norm(self, dim, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 796: { // frobenius_norm
          auto dim = readIntArrayRef("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::frobenius_norm(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 797: { // nuclear_norm
          bool keepdim = readAttribute<int64_t>("keepdim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::nuclear_norm(self, keepdim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 798: { // nuclear_norm
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::nuclear_norm(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 799: { // clone
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::clone(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 800: { // pow
          at::Scalar exponent = readScalarAttribute("exponent");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pow(self, exponent);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 801: { // sub
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::sub(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 802: { // sub
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::sub(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 803: { // sub
          at::Scalar other = readScalarAttribute("other");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sub(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 804: { // sub
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sub(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 805: { // rsub
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::rsub(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 806: { // rsub
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::rsub(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 807: { // rsub
          at::Scalar other = readScalarAttribute("other");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rsub(self, other, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 808: { // rsub
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::rsub(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 809: { // s_native_addmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::s_native_addmm(self, mat1, mat2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 810: { // s_native_addmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::s_native_addmm(self, mat1, mat2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 811: { // s_native_addmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::s_native_addmm(self, mat1, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 812: { // _sparse_addmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto sparse = peek(1, 3);
              auto dense = peek(2, 3);
              auto the_result = at::_sparse_addmm(self, sparse, dense, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 813: { // _sparse_addmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto sparse = peek(1, 3);
              auto dense = peek(2, 3);
              auto the_result = at::_sparse_addmm(self, sparse, dense, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 814: { // _sparse_addmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto sparse = peek(1, 3);
              auto dense = peek(2, 3);
              auto the_result = at::_sparse_addmm(self, sparse, dense);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 815: { // addmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::addmm(self, mat1, mat2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 816: { // addmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::addmm(self, mat1, mat2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 817: { // addmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mat1 = peek(1, 3);
              auto mat2 = peek(2, 3);
              auto the_result = at::addmm(self, mat1, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 818: { // to_dense
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.to_dense();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 819: { // to_dense_backward
      
          run_op = [=] {
              auto grad = peek(0, 2);
              auto input = peek(1, 2);
              auto the_result = at::to_dense_backward(grad, input);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 820: { // sparse_dim
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.sparse_dim();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 821: { // _dimI
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self._dimI();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 822: { // dense_dim
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.dense_dim();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 823: { // _dimV
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self._dimV();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 824: { // _nnz
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self._nnz();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 825: { // coalesce
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.coalesce();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 826: { // is_coalesced
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.is_coalesced();
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 827: { // _indices
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self._indices();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 828: { // _values
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self._values();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 829: { // indices
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.indices();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 830: { // values
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.values();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 831: { // hspmm
      
          run_op = [=] {
              auto mat1 = peek(0, 2);
              auto mat2 = peek(1, 2);
              auto the_result = at::hspmm(mat1, mat2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 832: { // numel
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::numel(self);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 833: { // unbind
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unbind(self, dim);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 834: { // unbind
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::unbind(self);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 835: { // to_sparse
          int64_t sparse_dim = readAttribute<int64_t>("sparse_dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.to_sparse(sparse_dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 836: { // to_sparse
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.to_sparse();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 837: { // to_mkldnn
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.to_mkldnn();
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 838: { // mkldnn_reorder_conv2d_weight
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          int64_t groups = readAttribute<int64_t>("groups");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_reorder_conv2d_weight(self, padding, stride, dilation, groups);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 839: { // mkldnn_reorder_conv2d_weight
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_reorder_conv2d_weight(self, padding, stride, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 840: { // mkldnn_reorder_conv2d_weight
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_reorder_conv2d_weight(self, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 841: { // mkldnn_reorder_conv2d_weight
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_reorder_conv2d_weight(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 842: { // mkldnn_reorder_conv2d_weight
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::mkldnn_reorder_conv2d_weight(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 843: { // to_mkldnn_backward
      
          run_op = [=] {
              auto grad = peek(0, 2);
              auto input = peek(1, 2);
              auto the_result = at::to_mkldnn_backward(grad, input);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 844: { // quantize_linear
          double scale = readAttribute<float>("scale");
          int64_t zero_point = readAttribute<int64_t>("zero_point");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::quantize_linear(self, scale, zero_point);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 845: { // dequantize
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::dequantize(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 846: { // q_scale
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::q_scale(self);
                if(OutputSize() > 0) {assignTo(Output(0),self.scalar_type(), the_result);}
              return true;
          };
      } break;
      case 847: { // q_zero_point
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::q_zero_point(self);
                if(OutputSize() > 0) {assignTo(Output(0),self.scalar_type(), the_result);}
              return true;
          };
      } break;
      case 848: { // int_repr
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::int_repr(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 849: { // meshgrid
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::meshgrid(tensors);
                if(OutputSize() > 0) {assignListStartingAt(0, the_result);}
              return true;
          };
      } break;
      case 850: { // cartesian_prod
      
          run_op = [=] {
              auto tensors = peekSlice(0, InputSize() - 0, InputSize());
              auto the_result = at::cartesian_prod(tensors);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 851: { // combinations
          int64_t r = readAttribute<int64_t>("r");
          bool with_replacement = readAttribute<int64_t>("with_replacement");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::combinations(self, r, with_replacement);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 852: { // combinations
          int64_t r = readAttribute<int64_t>("r");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::combinations(self, r);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 853: { // combinations
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::combinations(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 854: { // item
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.item();
                if(OutputSize() > 0) {assignTo(Output(0),self.scalar_type(), the_result);}
              return true;
          };
      } break;
      case 855: { // _local_scalar_dense
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_local_scalar_dense(self);
                if(OutputSize() > 0) {assignTo(Output(0),self.scalar_type(), the_result);}
              return true;
          };
      } break;
      case 856: { // _thnn_fused_lstm_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 5);
              auto hidden_gates = peek(1, 5);
              auto cx = peek(2, 5);
              auto input_bias = peek(3, 5);
              auto hidden_bias = peek(4, 5);
              auto the_result = at::_thnn_fused_lstm_cell(input_gates, hidden_gates, cx, input_bias, hidden_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 857: { // _thnn_fused_lstm_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 4);
              auto hidden_gates = peek(1, 4);
              auto cx = peek(2, 4);
              auto input_bias = peek(3, 4);
              auto the_result = at::_thnn_fused_lstm_cell(input_gates, hidden_gates, cx, input_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 858: { // _thnn_fused_lstm_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 3);
              auto hidden_gates = peek(1, 3);
              auto cx = peek(2, 3);
              auto the_result = at::_thnn_fused_lstm_cell(input_gates, hidden_gates, cx);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 859: { // _thnn_fused_lstm_cell_backward
          bool has_bias = readAttribute<int64_t>("has_bias");
          run_op = [=] {
              auto grad_hy = peek(0, 5);
              auto grad_cy = peek(1, 5);
              auto cx = peek(2, 5);
              auto cy = peek(3, 5);
              auto workspace = peek(4, 5);
              auto the_result = at::_thnn_fused_lstm_cell_backward(grad_hy, grad_cy, cx, cy, workspace, has_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
                if(OutputSize() > 4) {assignTo(Output(4),std::get<4>(the_result));}
              return true;
          };
      } break;
      case 860: { // _thnn_fused_gru_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 5);
              auto hidden_gates = peek(1, 5);
              auto hx = peek(2, 5);
              auto input_bias = peek(3, 5);
              auto hidden_bias = peek(4, 5);
              auto the_result = at::_thnn_fused_gru_cell(input_gates, hidden_gates, hx, input_bias, hidden_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 861: { // _thnn_fused_gru_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 4);
              auto hidden_gates = peek(1, 4);
              auto hx = peek(2, 4);
              auto input_bias = peek(3, 4);
              auto the_result = at::_thnn_fused_gru_cell(input_gates, hidden_gates, hx, input_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 862: { // _thnn_fused_gru_cell
      
          run_op = [=] {
              auto input_gates = peek(0, 3);
              auto hidden_gates = peek(1, 3);
              auto hx = peek(2, 3);
              auto the_result = at::_thnn_fused_gru_cell(input_gates, hidden_gates, hx);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 863: { // _thnn_fused_gru_cell_backward
          bool has_bias = readAttribute<int64_t>("has_bias");
          run_op = [=] {
              auto grad_hy = peek(0, 2);
              auto workspace = peek(1, 2);
              auto the_result = at::_thnn_fused_gru_cell_backward(grad_hy, workspace, has_bias);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
                if(OutputSize() > 3) {assignTo(Output(3),std::get<3>(the_result));}
                if(OutputSize() > 4) {assignTo(Output(4),std::get<4>(the_result));}
              return true;
          };
      } break;
      case 864: { // lstm
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peekSlice(1, InputSize() - 1, InputSize());
              auto params = peekSlice(1, InputSize() - 1, InputSize());
              auto the_result = at::lstm(input, hx, params, has_biases, num_layers, dropout, train, bidirectional, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 865: { // lstm
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          run_op = [=] {
              auto data = peek(0, InputSize());
              auto batch_sizes = peek(1, InputSize());
              auto hx = peekSlice(2, InputSize() - 2, InputSize());
              auto params = peekSlice(2, InputSize() - 2, InputSize());
              auto the_result = at::lstm(data, batch_sizes, hx, params, has_biases, num_layers, dropout, train, bidirectional);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 866: { // gru
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peek(1, InputSize());
              auto params = peekSlice(2, InputSize() - 2, InputSize());
              auto the_result = at::gru(input, hx, params, has_biases, num_layers, dropout, train, bidirectional, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 867: { // gru
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          run_op = [=] {
              auto data = peek(0, InputSize());
              auto batch_sizes = peek(1, InputSize());
              auto hx = peek(2, InputSize());
              auto params = peekSlice(3, InputSize() - 3, InputSize());
              auto the_result = at::gru(data, batch_sizes, hx, params, has_biases, num_layers, dropout, train, bidirectional);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 868: { // rnn_tanh
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peek(1, InputSize());
              auto params = peekSlice(2, InputSize() - 2, InputSize());
              auto the_result = at::rnn_tanh(input, hx, params, has_biases, num_layers, dropout, train, bidirectional, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 869: { // rnn_tanh
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          run_op = [=] {
              auto data = peek(0, InputSize());
              auto batch_sizes = peek(1, InputSize());
              auto hx = peek(2, InputSize());
              auto params = peekSlice(3, InputSize() - 3, InputSize());
              auto the_result = at::rnn_tanh(data, batch_sizes, hx, params, has_biases, num_layers, dropout, train, bidirectional);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 870: { // rnn_relu
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peek(1, InputSize());
              auto params = peekSlice(2, InputSize() - 2, InputSize());
              auto the_result = at::rnn_relu(input, hx, params, has_biases, num_layers, dropout, train, bidirectional, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 871: { // rnn_relu
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          run_op = [=] {
              auto data = peek(0, InputSize());
              auto batch_sizes = peek(1, InputSize());
              auto hx = peek(2, InputSize());
              auto params = peekSlice(3, InputSize() - 3, InputSize());
              auto the_result = at::rnn_relu(data, batch_sizes, hx, params, has_biases, num_layers, dropout, train, bidirectional);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 872: { // lstm_cell
      
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peekSlice(1, InputSize() - 5, InputSize());
              auto w_ih = peek(1, 5);
              auto w_hh = peek(2, 5);
              auto b_ih = peek(3, 5);
              auto b_hh = peek(4, 5);
              auto the_result = at::lstm_cell(input, hx, w_ih, w_hh, b_ih, b_hh);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 873: { // gru_cell
      
          run_op = [=] {
              auto input = peek(0, 6);
              auto hx = peek(1, 6);
              auto w_ih = peek(2, 6);
              auto w_hh = peek(3, 6);
              auto b_ih = peek(4, 6);
              auto b_hh = peek(5, 6);
              auto the_result = at::gru_cell(input, hx, w_ih, w_hh, b_ih, b_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 874: { // gru_cell
      
          run_op = [=] {
              auto input = peek(0, 5);
              auto hx = peek(1, 5);
              auto w_ih = peek(2, 5);
              auto w_hh = peek(3, 5);
              auto b_ih = peek(4, 5);
              auto the_result = at::gru_cell(input, hx, w_ih, w_hh, b_ih);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 875: { // gru_cell
      
          run_op = [=] {
              auto input = peek(0, 4);
              auto hx = peek(1, 4);
              auto w_ih = peek(2, 4);
              auto w_hh = peek(3, 4);
              auto the_result = at::gru_cell(input, hx, w_ih, w_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 876: { // rnn_tanh_cell
      
          run_op = [=] {
              auto input = peek(0, 6);
              auto hx = peek(1, 6);
              auto w_ih = peek(2, 6);
              auto w_hh = peek(3, 6);
              auto b_ih = peek(4, 6);
              auto b_hh = peek(5, 6);
              auto the_result = at::rnn_tanh_cell(input, hx, w_ih, w_hh, b_ih, b_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 877: { // rnn_tanh_cell
      
          run_op = [=] {
              auto input = peek(0, 5);
              auto hx = peek(1, 5);
              auto w_ih = peek(2, 5);
              auto w_hh = peek(3, 5);
              auto b_ih = peek(4, 5);
              auto the_result = at::rnn_tanh_cell(input, hx, w_ih, w_hh, b_ih);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 878: { // rnn_tanh_cell
      
          run_op = [=] {
              auto input = peek(0, 4);
              auto hx = peek(1, 4);
              auto w_ih = peek(2, 4);
              auto w_hh = peek(3, 4);
              auto the_result = at::rnn_tanh_cell(input, hx, w_ih, w_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 879: { // rnn_relu_cell
      
          run_op = [=] {
              auto input = peek(0, 6);
              auto hx = peek(1, 6);
              auto w_ih = peek(2, 6);
              auto w_hh = peek(3, 6);
              auto b_ih = peek(4, 6);
              auto b_hh = peek(5, 6);
              auto the_result = at::rnn_relu_cell(input, hx, w_ih, w_hh, b_ih, b_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 880: { // rnn_relu_cell
      
          run_op = [=] {
              auto input = peek(0, 5);
              auto hx = peek(1, 5);
              auto w_ih = peek(2, 5);
              auto w_hh = peek(3, 5);
              auto b_ih = peek(4, 5);
              auto the_result = at::rnn_relu_cell(input, hx, w_ih, w_hh, b_ih);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 881: { // rnn_relu_cell
      
          run_op = [=] {
              auto input = peek(0, 4);
              auto hx = peek(1, 4);
              auto w_ih = peek(2, 4);
              auto w_hh = peek(3, 4);
              auto the_result = at::rnn_relu_cell(input, hx, w_ih, w_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 882: { // quantized_lstm
          bool has_biases = readAttribute<int64_t>("has_biases");
          int64_t num_layers = readAttribute<int64_t>("num_layers");
          double dropout = readAttribute<float>("dropout");
          bool train = readAttribute<int64_t>("train");
          bool bidirectional = readAttribute<int64_t>("bidirectional");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peekSlice(1, InputSize() - 1, InputSize());
              auto params = peekSlice(1, InputSize() - 1, InputSize());
              auto the_result = at::quantized_lstm(input, hx, params, has_biases, num_layers, dropout, train, bidirectional, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 883: { // quantized_lstm_cell
          at::Scalar scale_ih = readScalarAttribute("scale_ih");
          at::Scalar scale_hh = readScalarAttribute("scale_hh");
          at::Scalar zero_point_ih = readScalarAttribute("zero_point_ih");
          at::Scalar zero_point_hh = readScalarAttribute("zero_point_hh");
          run_op = [=] {
              auto input = peek(0, InputSize());
              auto hx = peekSlice(1, InputSize() - 9, InputSize());
              auto w_ih = peek(1, 9);
              auto w_hh = peek(2, 9);
              auto b_ih = peek(3, 9);
              auto b_hh = peek(4, 9);
              auto packed_ih = peek(5, 9);
              auto packed_hh = peek(6, 9);
              auto col_offsets_ih = peek(7, 9);
              auto col_offsets_hh = peek(8, 9);
              auto the_result = at::quantized_lstm_cell(input, hx, w_ih, w_hh, b_ih, b_hh, packed_ih, packed_hh, col_offsets_ih, col_offsets_hh, scale_ih, scale_hh, zero_point_ih, zero_point_hh);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 884: { // quantized_gru_cell
          at::Scalar scale_ih = readScalarAttribute("scale_ih");
          at::Scalar scale_hh = readScalarAttribute("scale_hh");
          at::Scalar zero_point_ih = readScalarAttribute("zero_point_ih");
          at::Scalar zero_point_hh = readScalarAttribute("zero_point_hh");
          run_op = [=] {
              auto input = peek(0, 10);
              auto hx = peek(1, 10);
              auto w_ih = peek(2, 10);
              auto w_hh = peek(3, 10);
              auto b_ih = peek(4, 10);
              auto b_hh = peek(5, 10);
              auto packed_ih = peek(6, 10);
              auto packed_hh = peek(7, 10);
              auto col_offsets_ih = peek(8, 10);
              auto col_offsets_hh = peek(9, 10);
              auto the_result = at::quantized_gru_cell(input, hx, w_ih, w_hh, b_ih, b_hh, packed_ih, packed_hh, col_offsets_ih, col_offsets_hh, scale_ih, scale_hh, zero_point_ih, zero_point_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 885: { // quantized_rnn_relu_cell
          at::Scalar scale_ih = readScalarAttribute("scale_ih");
          at::Scalar scale_hh = readScalarAttribute("scale_hh");
          at::Scalar zero_point_ih = readScalarAttribute("zero_point_ih");
          at::Scalar zero_point_hh = readScalarAttribute("zero_point_hh");
          run_op = [=] {
              auto input = peek(0, 10);
              auto hx = peek(1, 10);
              auto w_ih = peek(2, 10);
              auto w_hh = peek(3, 10);
              auto b_ih = peek(4, 10);
              auto b_hh = peek(5, 10);
              auto packed_ih = peek(6, 10);
              auto packed_hh = peek(7, 10);
              auto col_offsets_ih = peek(8, 10);
              auto col_offsets_hh = peek(9, 10);
              auto the_result = at::quantized_rnn_relu_cell(input, hx, w_ih, w_hh, b_ih, b_hh, packed_ih, packed_hh, col_offsets_ih, col_offsets_hh, scale_ih, scale_hh, zero_point_ih, zero_point_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 886: { // quantized_rnn_tanh_cell
          at::Scalar scale_ih = readScalarAttribute("scale_ih");
          at::Scalar scale_hh = readScalarAttribute("scale_hh");
          at::Scalar zero_point_ih = readScalarAttribute("zero_point_ih");
          at::Scalar zero_point_hh = readScalarAttribute("zero_point_hh");
          run_op = [=] {
              auto input = peek(0, 10);
              auto hx = peek(1, 10);
              auto w_ih = peek(2, 10);
              auto w_hh = peek(3, 10);
              auto b_ih = peek(4, 10);
              auto b_hh = peek(5, 10);
              auto packed_ih = peek(6, 10);
              auto packed_hh = peek(7, 10);
              auto col_offsets_ih = peek(8, 10);
              auto col_offsets_hh = peek(9, 10);
              auto the_result = at::quantized_rnn_tanh_cell(input, hx, w_ih, w_hh, b_ih, b_hh, packed_ih, packed_hh, col_offsets_ih, col_offsets_hh, scale_ih, scale_hh, zero_point_ih, zero_point_hh);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 887: { // _pack_padded_sequence
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto input = peek(0, 2);
              auto lengths = peek(1, 2);
              auto the_result = at::_pack_padded_sequence(input, lengths, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 888: { // _pack_padded_sequence_backward
          auto input_size = readIntArrayRef("input_size");
          bool batch_first = readAttribute<int64_t>("batch_first");
          run_op = [=] {
              auto grad = peek(0, 2);
              auto batch_sizes = peek(1, 2);
              auto the_result = at::_pack_padded_sequence_backward(grad, input_size, batch_sizes, batch_first);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 889: { // _pad_packed_sequence
          bool batch_first = readAttribute<int64_t>("batch_first");
          at::Scalar padding_value = readScalarAttribute("padding_value");
          int64_t total_length = readAttribute<int64_t>("total_length");
          run_op = [=] {
              auto data = peek(0, 2);
              auto batch_sizes = peek(1, 2);
              auto the_result = at::_pad_packed_sequence(data, batch_sizes, batch_first, padding_value, total_length);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 890: { // is_set_to
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto tensor = peek(1, 2);
              auto the_result = self.is_set_to(tensor);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 891: { // masked_fill
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 2);
              auto mask = peek(1, 2);
              auto the_result = at::masked_fill(self, mask, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 892: { // masked_fill
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mask = peek(1, 3);
              auto value = peek(2, 3);
              auto the_result = at::masked_fill(self, mask, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 893: { // masked_scatter
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto mask = peek(1, 3);
              auto source = peek(2, 3);
              auto the_result = at::masked_scatter(self, mask, source);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 894: { // view
          auto size = readIntArrayRef("size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.view(size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 895: { // index_add
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto source = peek(2, 3);
              auto the_result = at::index_add(self, dim, index, source);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 896: { // index_fill
          int64_t dim = readAttribute<int64_t>("dim");
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::index_fill(self, dim, index, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 897: { // index_fill
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto value = peek(2, 3);
              auto the_result = at::index_fill(self, dim, index, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 898: { // scatter
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto src = peek(2, 3);
              auto the_result = at::scatter(self, dim, index, src);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 899: { // scatter
          int64_t dim = readAttribute<int64_t>("dim");
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::scatter(self, dim, index, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 900: { // scatter_add
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto src = peek(2, 3);
              auto the_result = at::scatter_add(self, dim, index, src);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 901: { // __and__
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::__and__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 902: { // __and__
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::__and__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 903: { // __or__
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::__or__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 904: { // __or__
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::__or__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 905: { // __xor__
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::__xor__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 906: { // __xor__
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::__xor__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 907: { // __lshift__
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::__lshift__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 908: { // __lshift__
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::__lshift__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 909: { // __rshift__
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::__rshift__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 910: { // __rshift__
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::__rshift__(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 911: { // addbmm
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::addbmm(self, batch1, batch2, beta, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 912: { // addbmm
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::addbmm(self, batch1, batch2, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 913: { // addbmm
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto batch1 = peek(1, 3);
              auto batch2 = peek(2, 3);
              auto the_result = at::addbmm(self, batch1, batch2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 914: { // diag
          int64_t diagonal = readAttribute<int64_t>("diagonal");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag(self, diagonal);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 915: { // diag
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::diag(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 916: { // cross
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::cross(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 917: { // triu
          int64_t diagonal = readAttribute<int64_t>("diagonal");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::triu(self, diagonal);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 918: { // triu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::triu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 919: { // tril
          int64_t diagonal = readAttribute<int64_t>("diagonal");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::tril(self, diagonal);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 920: { // tril
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::tril(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 921: { // trace
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::trace(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 922: { // ne
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::ne(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 923: { // ne
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::ne(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 924: { // eq
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::eq(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 925: { // eq
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::eq(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 926: { // ge
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::ge(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 927: { // ge
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::ge(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 928: { // le
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::le(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 929: { // le
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::le(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 930: { // gt
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::gt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 931: { // gt
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::gt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 932: { // lt
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::lt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 933: { // lt
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::lt(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 934: { // take
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::take(self, index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 935: { // index_select
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::index_select(self, dim, index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 936: { // masked_select
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto mask = peek(1, 2);
              auto the_result = at::masked_select(self, mask);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 937: { // nonzero
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::nonzero(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 938: { // gather
          int64_t dim = readAttribute<int64_t>("dim");
          bool sparse_grad = readAttribute<int64_t>("sparse_grad");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::gather(self, dim, index, sparse_grad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 939: { // gather
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 2);
              auto index = peek(1, 2);
              auto the_result = at::gather(self, dim, index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 940: { // _gather_sparse_backward
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 3);
              auto index = peek(1, 3);
              auto grad = peek(2, 3);
              auto the_result = at::_gather_sparse_backward(self, dim, index, grad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 941: { // addcmul
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::addcmul(self, tensor1, tensor2, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 942: { // addcmul
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::addcmul(self, tensor1, tensor2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 943: { // addcdiv
          at::Scalar value = readScalarAttribute("value");
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::addcdiv(self, tensor1, tensor2, value);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 944: { // addcdiv
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto tensor1 = peek(1, 3);
              auto tensor2 = peek(2, 3);
              auto the_result = at::addcdiv(self, tensor1, tensor2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 945: { // gels
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::gels(self, A);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 946: { // triangular_solve
          bool upper = readAttribute<int64_t>("upper");
          bool transpose = readAttribute<int64_t>("transpose");
          bool unitriangular = readAttribute<int64_t>("unitriangular");
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::triangular_solve(self, A, upper, transpose, unitriangular);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 947: { // triangular_solve
          bool upper = readAttribute<int64_t>("upper");
          bool transpose = readAttribute<int64_t>("transpose");
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::triangular_solve(self, A, upper, transpose);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 948: { // triangular_solve
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::triangular_solve(self, A, upper);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 949: { // triangular_solve
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::triangular_solve(self, A);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 950: { // _triangular_solve_helper
          bool upper = readAttribute<int64_t>("upper");
          bool transpose = readAttribute<int64_t>("transpose");
          bool unitriangular = readAttribute<int64_t>("unitriangular");
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::_triangular_solve_helper(self, A, upper, transpose, unitriangular);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 951: { // symeig
          bool eigenvectors = readAttribute<int64_t>("eigenvectors");
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::symeig(self, eigenvectors, upper);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 952: { // symeig
          bool eigenvectors = readAttribute<int64_t>("eigenvectors");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::symeig(self, eigenvectors);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 953: { // symeig
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::symeig(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 954: { // eig
          bool eigenvectors = readAttribute<int64_t>("eigenvectors");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::eig(self, eigenvectors);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 955: { // eig
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::eig(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 956: { // svd
          bool some = readAttribute<int64_t>("some");
          bool compute_uv = readAttribute<int64_t>("compute_uv");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::svd(self, some, compute_uv);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 957: { // svd
          bool some = readAttribute<int64_t>("some");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::svd(self, some);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 958: { // svd
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::svd(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 959: { // cholesky
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cholesky(self, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 960: { // cholesky
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cholesky(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 961: { // _cholesky_helper
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_cholesky_helper(self, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 962: { // cholesky_solve
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 2);
              auto input2 = peek(1, 2);
              auto the_result = at::cholesky_solve(self, input2, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 963: { // cholesky_solve
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto input2 = peek(1, 2);
              auto the_result = at::cholesky_solve(self, input2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 964: { // _cholesky_solve_helper
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::_cholesky_solve_helper(self, A, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 965: { // solve
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::solve(self, A);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 966: { // _solve_helper
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto A = peek(1, 2);
              auto the_result = at::_solve_helper(self, A);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 967: { // cholesky_inverse
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cholesky_inverse(self, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 968: { // cholesky_inverse
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::cholesky_inverse(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 969: { // pstrf
          bool upper = readAttribute<int64_t>("upper");
          at::Scalar tol = readScalarAttribute("tol");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pstrf(self, upper, tol);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 970: { // pstrf
          bool upper = readAttribute<int64_t>("upper");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pstrf(self, upper);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 971: { // pstrf
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::pstrf(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 972: { // qr
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::qr(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 973: { // geqrf
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::geqrf(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 974: { // orgqr
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto input2 = peek(1, 2);
              auto the_result = at::orgqr(self, input2);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 975: { // ormqr
          bool left = readAttribute<int64_t>("left");
          bool transpose = readAttribute<int64_t>("transpose");
          run_op = [=] {
              auto self = peek(0, 3);
              auto input2 = peek(1, 3);
              auto input3 = peek(2, 3);
              auto the_result = at::ormqr(self, input2, input3, left, transpose);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 976: { // ormqr
          bool left = readAttribute<int64_t>("left");
          run_op = [=] {
              auto self = peek(0, 3);
              auto input2 = peek(1, 3);
              auto input3 = peek(2, 3);
              auto the_result = at::ormqr(self, input2, input3, left);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 977: { // ormqr
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto input2 = peek(1, 3);
              auto input3 = peek(2, 3);
              auto the_result = at::ormqr(self, input2, input3);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 978: { // _lu_with_info
          bool pivot = readAttribute<int64_t>("pivot");
          bool check_errors = readAttribute<int64_t>("check_errors");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_lu_with_info(self, pivot, check_errors);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 979: { // _lu_with_info
          bool pivot = readAttribute<int64_t>("pivot");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_lu_with_info(self, pivot);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 980: { // _lu_with_info
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_lu_with_info(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 981: { // lu_solve
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto LU_data = peek(1, 3);
              auto LU_pivots = peek(2, 3);
              auto the_result = at::lu_solve(self, LU_data, LU_pivots);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 982: { // multinomial
          int64_t num_samples = readAttribute<int64_t>("num_samples");
          bool replacement = readAttribute<int64_t>("replacement");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::multinomial(self, num_samples, replacement);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 983: { // multinomial
          int64_t num_samples = readAttribute<int64_t>("num_samples");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::multinomial(self, num_samples);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 984: { // _multinomial_alias_setup
      
          run_op = [=] {
              auto probs = peek(0, 1);
              auto the_result = at::_multinomial_alias_setup(probs);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 985: { // _multinomial_alias_draw
          int64_t num_samples = readAttribute<int64_t>("num_samples");
          run_op = [=] {
              auto J = peek(0, 2);
              auto q = peek(1, 2);
              auto the_result = at::_multinomial_alias_draw(J, q, num_samples);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 986: { // lgamma
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::lgamma(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 987: { // digamma
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::digamma(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 988: { // polygamma
          int64_t n = readAttribute<int64_t>("n");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::polygamma(n, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 989: { // erfinv
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::erfinv(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 990: { // dist
          at::Scalar p = readScalarAttribute("p");
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::dist(self, other, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 991: { // dist
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::dist(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 992: { // atan2
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::atan2(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 993: { // lerp
          at::Scalar weight = readScalarAttribute("weight");
          run_op = [=] {
              auto self = peek(0, 2);
              auto end = peek(1, 2);
              auto the_result = at::lerp(self, end, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 994: { // lerp
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto end = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::lerp(self, end, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 995: { // histc
          int64_t bins = readAttribute<int64_t>("bins");
          at::Scalar min = readScalarAttribute("min");
          at::Scalar max = readScalarAttribute("max");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::histc(self, bins, min, max);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 996: { // histc
          int64_t bins = readAttribute<int64_t>("bins");
          at::Scalar min = readScalarAttribute("min");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::histc(self, bins, min);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 997: { // histc
          int64_t bins = readAttribute<int64_t>("bins");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::histc(self, bins);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 998: { // histc
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::histc(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 999: { // sign
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sign(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1000: { // fmod
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::fmod(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1001: { // fmod
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::fmod(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1002: { // remainder
          at::Scalar other = readScalarAttribute("other");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::remainder(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1003: { // remainder
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::remainder(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1004: { // min
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::min(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1005: { // min
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::min(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1006: { // max
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::max(self, other);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1007: { // max
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1008: { // median
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::median(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1009: { // sort
          int64_t dim = readAttribute<int64_t>("dim");
          bool descending = readAttribute<int64_t>("descending");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sort(self, dim, descending);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1010: { // sort
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sort(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1011: { // sort
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::sort(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1012: { // argsort
          int64_t dim = readAttribute<int64_t>("dim");
          bool descending = readAttribute<int64_t>("descending");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::argsort(self, dim, descending);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1013: { // argsort
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::argsort(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1014: { // argsort
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::argsort(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1015: { // topk
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          bool largest = readAttribute<int64_t>("largest");
          bool sorted = readAttribute<int64_t>("sorted");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::topk(self, k, dim, largest, sorted);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1016: { // topk
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          bool largest = readAttribute<int64_t>("largest");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::topk(self, k, dim, largest);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1017: { // topk
          int64_t k = readAttribute<int64_t>("k");
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::topk(self, k, dim);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1018: { // topk
          int64_t k = readAttribute<int64_t>("k");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::topk(self, k);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1019: { // all
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::all(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1020: { // any
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::any(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1021: { // renorm
          at::Scalar p = readScalarAttribute("p");
          int64_t dim = readAttribute<int64_t>("dim");
          at::Scalar maxnorm = readScalarAttribute("maxnorm");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::renorm(self, p, dim, maxnorm);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1022: { // unfold
          int64_t dimension = readAttribute<int64_t>("dimension");
          int64_t size = readAttribute<int64_t>("size");
          int64_t step = readAttribute<int64_t>("step");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = self.unfold(dimension, size, step);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1023: { // equal
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto other = peek(1, 2);
              auto the_result = at::equal(self, other);
                if(OutputSize() > 0) {assignToValue<int64_t>(Output(0),the_result);}
              return true;
          };
      } break;
      case 1024: { // pow
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto exponent = peek(1, 2);
              auto the_result = at::pow(self, exponent);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1025: { // pow
          at::Scalar self = readScalarAttribute("self");
          run_op = [=] {
              auto exponent = peek(0, 1);
              auto the_result = at::pow(self, exponent);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1026: { // normal
          double std = readAttribute<float>("std");
          run_op = [=] {
              auto mean = peek(0, 1);
              auto the_result = at::normal(mean, std);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1027: { // normal
      
          run_op = [=] {
              auto mean = peek(0, 1);
              auto the_result = at::normal(mean);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1028: { // normal
          double mean = readAttribute<float>("mean");
          run_op = [=] {
              auto std = peek(0, 1);
              auto the_result = at::normal(mean, std);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1029: { // normal
      
          run_op = [=] {
              auto mean = peek(0, 2);
              auto std = peek(1, 2);
              auto the_result = at::normal(mean, std);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1030: { // alias
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::alias(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1031: { // _dirichlet_grad
      
          run_op = [=] {
              auto x = peek(0, 3);
              auto alpha = peek(1, 3);
              auto total = peek(2, 3);
              auto the_result = at::_dirichlet_grad(x, alpha, total);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1032: { // binary_cross_entropy
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::binary_cross_entropy(self, target, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1033: { // binary_cross_entropy
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::binary_cross_entropy(self, target, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1034: { // binary_cross_entropy
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::binary_cross_entropy(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1035: { // binary_cross_entropy_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto weight = peek(3, 4);
              auto the_result = at::binary_cross_entropy_backward(grad_output, self, target, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1036: { // mse_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::mse_loss(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1037: { // mse_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::mse_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1038: { // mse_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::mse_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1039: { // l1_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::l1_loss(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1040: { // l1_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::l1_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1041: { // l1_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::l1_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1042: { // multi_margin_loss
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::multi_margin_loss(self, target, p, margin, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1043: { // multi_margin_loss
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::multi_margin_loss(self, target, p, margin, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1044: { // multi_margin_loss
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multi_margin_loss(self, target, p, margin);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1045: { // multi_margin_loss
          at::Scalar p = readScalarAttribute("p");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multi_margin_loss(self, target, p);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1046: { // multi_margin_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multi_margin_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1047: { // multi_margin_loss_backward
          at::Scalar p = readScalarAttribute("p");
          at::Scalar margin = readScalarAttribute("margin");
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto weight = peek(3, 4);
              auto the_result = at::multi_margin_loss_backward(grad_output, self, target, p, margin, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1048: { // multilabel_margin_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multilabel_margin_loss(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1049: { // multilabel_margin_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multilabel_margin_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1050: { // multilabel_margin_loss_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::multilabel_margin_loss_forward(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1051: { // multilabel_margin_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 4);
              auto self = peek(1, 4);
              auto target = peek(2, 4);
              auto is_target = peek(3, 4);
              auto the_result = at::multilabel_margin_loss_backward(grad_output, self, target, reduction, is_target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1052: { // nll_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss(self, target, weight, reduction, ignore_index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1053: { // nll_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss(self, target, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1054: { // nll_loss
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss(self, target, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1055: { // nll_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::nll_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1056: { // nll_loss_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss_forward(self, target, weight, reduction, ignore_index);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1057: { // nll_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto target = peek(2, 5);
              auto weight = peek(3, 5);
              auto total_weight = peek(4, 5);
              auto the_result = at::nll_loss_backward(grad_output, self, target, weight, reduction, ignore_index, total_weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1058: { // nll_loss2d
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss2d(self, target, weight, reduction, ignore_index);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1059: { // nll_loss2d
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss2d(self, target, weight, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1060: { // nll_loss2d
      
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss2d(self, target, weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1061: { // nll_loss2d
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::nll_loss2d(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1062: { // nll_loss2d_forward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto self = peek(0, 3);
              auto target = peek(1, 3);
              auto weight = peek(2, 3);
              auto the_result = at::nll_loss2d_forward(self, target, weight, reduction, ignore_index);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1063: { // nll_loss2d_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          int64_t ignore_index = readAttribute<int64_t>("ignore_index");
          run_op = [=] {
              auto grad_output = peek(0, 5);
              auto self = peek(1, 5);
              auto target = peek(2, 5);
              auto weight = peek(3, 5);
              auto total_weight = peek(4, 5);
              auto the_result = at::nll_loss2d_backward(grad_output, self, target, weight, reduction, ignore_index, total_weight);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1064: { // smooth_l1_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::smooth_l1_loss(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1065: { // smooth_l1_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::smooth_l1_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1066: { // smooth_l1_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::smooth_l1_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1067: { // soft_margin_loss
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::soft_margin_loss(self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1068: { // soft_margin_loss
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto target = peek(1, 2);
              auto the_result = at::soft_margin_loss(self, target);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1069: { // soft_margin_loss_backward
          int64_t reduction = readAttribute<int64_t>("reduction");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto target = peek(2, 3);
              auto the_result = at::soft_margin_loss_backward(grad_output, self, target, reduction);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1070: { // elu
          at::Scalar alpha = readScalarAttribute("alpha");
          at::Scalar scale = readScalarAttribute("scale");
          at::Scalar input_scale = readScalarAttribute("input_scale");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::elu(self, alpha, scale, input_scale);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1071: { // elu
          at::Scalar alpha = readScalarAttribute("alpha");
          at::Scalar scale = readScalarAttribute("scale");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::elu(self, alpha, scale);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1072: { // elu
          at::Scalar alpha = readScalarAttribute("alpha");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::elu(self, alpha);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1073: { // elu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::elu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1074: { // elu_backward
          at::Scalar alpha = readScalarAttribute("alpha");
          at::Scalar scale = readScalarAttribute("scale");
          at::Scalar input_scale = readScalarAttribute("input_scale");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto output = peek(1, 2);
              auto the_result = at::elu_backward(grad_output, alpha, scale, input_scale, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1075: { // glu
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::glu(self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1076: { // glu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::glu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1077: { // glu_backward
          int64_t dim = readAttribute<int64_t>("dim");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::glu_backward(grad_output, self, dim);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1078: { // hardtanh
          at::Scalar min_val = readScalarAttribute("min_val");
          at::Scalar max_val = readScalarAttribute("max_val");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::hardtanh(self, min_val, max_val);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1079: { // hardtanh
          at::Scalar min_val = readScalarAttribute("min_val");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::hardtanh(self, min_val);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1080: { // hardtanh
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::hardtanh(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1081: { // hardtanh_backward
          at::Scalar min_val = readScalarAttribute("min_val");
          at::Scalar max_val = readScalarAttribute("max_val");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::hardtanh_backward(grad_output, self, min_val, max_val);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1082: { // leaky_relu
          at::Scalar negative_slope = readScalarAttribute("negative_slope");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::leaky_relu(self, negative_slope);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1083: { // leaky_relu
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::leaky_relu(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1084: { // leaky_relu_backward
          at::Scalar negative_slope = readScalarAttribute("negative_slope");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::leaky_relu_backward(grad_output, self, negative_slope);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1085: { // log_sigmoid
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log_sigmoid(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1086: { // log_sigmoid_forward
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::log_sigmoid_forward(self);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1087: { // log_sigmoid_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto buffer = peek(2, 3);
              auto the_result = at::log_sigmoid_backward(grad_output, self, buffer);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1088: { // rrelu_with_noise
          at::Scalar lower = readScalarAttribute("lower");
          at::Scalar upper = readScalarAttribute("upper");
          bool training = readAttribute<int64_t>("training");
          run_op = [=] {
              auto self = peek(0, 2);
              auto noise = peek(1, 2);
              auto the_result = at::rrelu_with_noise(self, noise, lower, upper, training);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1089: { // rrelu_with_noise
          at::Scalar lower = readScalarAttribute("lower");
          at::Scalar upper = readScalarAttribute("upper");
          run_op = [=] {
              auto self = peek(0, 2);
              auto noise = peek(1, 2);
              auto the_result = at::rrelu_with_noise(self, noise, lower, upper);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1090: { // rrelu_with_noise
          at::Scalar lower = readScalarAttribute("lower");
          run_op = [=] {
              auto self = peek(0, 2);
              auto noise = peek(1, 2);
              auto the_result = at::rrelu_with_noise(self, noise, lower);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1091: { // rrelu_with_noise
      
          run_op = [=] {
              auto self = peek(0, 2);
              auto noise = peek(1, 2);
              auto the_result = at::rrelu_with_noise(self, noise);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1092: { // rrelu_with_noise_backward
          at::Scalar lower = readScalarAttribute("lower");
          at::Scalar upper = readScalarAttribute("upper");
          bool training = readAttribute<int64_t>("training");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto noise = peek(2, 3);
              auto the_result = at::rrelu_with_noise_backward(grad_output, self, noise, lower, upper, training);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1093: { // softplus
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar threshold = readScalarAttribute("threshold");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softplus(self, beta, threshold);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1094: { // softplus
          at::Scalar beta = readScalarAttribute("beta");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softplus(self, beta);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1095: { // softplus
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softplus(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1096: { // softplus_backward
          at::Scalar beta = readScalarAttribute("beta");
          at::Scalar threshold = readScalarAttribute("threshold");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto output = peek(2, 3);
              auto the_result = at::softplus_backward(grad_output, self, beta, threshold, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1097: { // softshrink
          at::Scalar lambd = readScalarAttribute("lambd");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softshrink(self, lambd);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1098: { // softshrink
      
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::softshrink(self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1099: { // softshrink_backward
          at::Scalar lambd = readScalarAttribute("lambd");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::softshrink_backward(grad_output, self, lambd);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1100: { // adaptive_avg_pool2d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_avg_pool2d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1101: { // _adaptive_avg_pool2d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::_adaptive_avg_pool2d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1102: { // _adaptive_avg_pool2d_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::_adaptive_avg_pool2d_backward(grad_output, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1103: { // adaptive_avg_pool3d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_avg_pool3d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1104: { // adaptive_avg_pool3d_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::adaptive_avg_pool3d_backward(grad_output, self);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1105: { // adaptive_max_pool2d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_max_pool2d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1106: { // adaptive_max_pool2d_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::adaptive_max_pool2d_backward(grad_output, self, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1107: { // adaptive_max_pool3d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::adaptive_max_pool3d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1108: { // adaptive_max_pool3d_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::adaptive_max_pool3d_backward(grad_output, self, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1109: { // avg_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool2d(self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1110: { // avg_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool2d(self, kernel_size, stride, padding, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1111: { // avg_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool2d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1112: { // avg_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool2d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1113: { // avg_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool2d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1114: { // avg_pool2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::avg_pool2d_backward(grad_output, self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1115: { // avg_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool3d(self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1116: { // avg_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool3d(self, kernel_size, stride, padding, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1117: { // avg_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool3d(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1118: { // avg_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool3d(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1119: { // avg_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::avg_pool3d(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1120: { // avg_pool3d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          bool count_include_pad = readAttribute<int64_t>("count_include_pad");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::avg_pool3d_backward(grad_output, self, kernel_size, stride, padding, ceil_mode, count_include_pad);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1121: { // fractional_max_pool2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto random_samples = peek(1, 2);
              auto the_result = at::fractional_max_pool2d(self, kernel_size, output_size, random_samples);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1122: { // fractional_max_pool2d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::fractional_max_pool2d_backward(grad_output, self, kernel_size, output_size, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1123: { // fractional_max_pool3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto random_samples = peek(1, 2);
              auto the_result = at::fractional_max_pool3d(self, kernel_size, output_size, random_samples);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1124: { // fractional_max_pool3d_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::fractional_max_pool3d_backward(grad_output, self, kernel_size, output_size, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1125: { // max_pool2d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d_with_indices(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1126: { // max_pool2d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d_with_indices(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1127: { // max_pool2d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d_with_indices(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1128: { // max_pool2d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d_with_indices(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1129: { // max_pool2d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool2d_with_indices(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1130: { // max_pool2d_with_indices_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::max_pool2d_with_indices_backward(grad_output, self, kernel_size, stride, padding, dilation, ceil_mode, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1131: { // max_pool3d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d_with_indices(self, kernel_size, stride, padding, dilation, ceil_mode);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1132: { // max_pool3d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d_with_indices(self, kernel_size, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1133: { // max_pool3d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d_with_indices(self, kernel_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1134: { // max_pool3d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d_with_indices(self, kernel_size, stride);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1135: { // max_pool3d_with_indices
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::max_pool3d_with_indices(self, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
              return true;
          };
      } break;
      case 1136: { // max_pool3d_with_indices_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          bool ceil_mode = readAttribute<int64_t>("ceil_mode");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::max_pool3d_with_indices_backward(grad_output, self, kernel_size, stride, padding, dilation, ceil_mode, indices);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1137: { // max_unpool2d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::max_unpool2d(self, indices, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1138: { // max_unpool2d_backward
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::max_unpool2d_backward(grad_output, self, indices, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1139: { // max_unpool3d
          auto output_size = readIntArrayRef("output_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 2);
              auto indices = peek(1, 2);
              auto the_result = at::max_unpool3d(self, indices, output_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1140: { // max_unpool3d_backward
          auto output_size = readIntArrayRef("output_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 3);
              auto self = peek(1, 3);
              auto indices = peek(2, 3);
              auto the_result = at::max_unpool3d_backward(grad_output, self, indices, output_size, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1141: { // reflection_pad1d
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::reflection_pad1d(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1142: { // reflection_pad1d_backward
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::reflection_pad1d_backward(grad_output, self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1143: { // reflection_pad2d
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::reflection_pad2d(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1144: { // reflection_pad2d_backward
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::reflection_pad2d_backward(grad_output, self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1145: { // replication_pad1d
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::replication_pad1d(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1146: { // replication_pad1d_backward
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::replication_pad1d_backward(grad_output, self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1147: { // replication_pad2d
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::replication_pad2d(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1148: { // replication_pad2d_backward
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::replication_pad2d_backward(grad_output, self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1149: { // replication_pad3d
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::replication_pad3d(self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1150: { // replication_pad3d_backward
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto self = peek(1, 2);
              auto the_result = at::replication_pad3d_backward(grad_output, self, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1151: { // upsample_linear1d
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_linear1d(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1152: { // upsample_linear1d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_linear1d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1153: { // upsample_bilinear2d
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_bilinear2d(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1154: { // upsample_bilinear2d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_bilinear2d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1155: { // upsample_bicubic2d
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_bicubic2d(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1156: { // upsample_bicubic2d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_bicubic2d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1157: { // upsample_trilinear3d
          auto output_size = readIntArrayRef("output_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_trilinear3d(self, output_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1158: { // upsample_trilinear3d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          bool align_corners = readAttribute<int64_t>("align_corners");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_trilinear3d_backward(grad_output, output_size, input_size, align_corners);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1159: { // upsample_nearest1d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_nearest1d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1160: { // upsample_nearest1d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_nearest1d_backward(grad_output, output_size, input_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1161: { // upsample_nearest2d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_nearest2d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1162: { // upsample_nearest2d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_nearest2d_backward(grad_output, output_size, input_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1163: { // upsample_nearest3d
          auto output_size = readIntArrayRef("output_size");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::upsample_nearest3d(self, output_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1164: { // upsample_nearest3d_backward
          auto output_size = readIntArrayRef("output_size");
          auto input_size = readIntArrayRef("input_size");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::upsample_nearest3d_backward(grad_output, output_size, input_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1165: { // sigmoid_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto output = peek(1, 2);
              auto the_result = at::sigmoid_backward(grad_output, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1166: { // tanh_backward
      
          run_op = [=] {
              auto grad_output = peek(0, 2);
              auto output = peek(1, 2);
              auto the_result = at::tanh_backward(grad_output, output);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1167: { // thnn_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose2d(self, weight, kernel_size, bias, stride, padding, output_padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1168: { // thnn_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose2d(self, weight, kernel_size, bias, stride, padding, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1169: { // thnn_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose2d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1170: { // thnn_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose2d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1171: { // thnn_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose2d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1172: { // thnn_conv_transpose2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::thnn_conv_transpose2d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1173: { // thnn_conv_transpose2d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose2d_forward(self, weight, kernel_size, bias, stride, padding, output_padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1174: { // thnn_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose3d(self, weight, kernel_size, bias, stride, padding, output_padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1175: { // thnn_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose3d(self, weight, kernel_size, bias, stride, padding, output_padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1176: { // thnn_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose3d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1177: { // thnn_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose3d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1178: { // thnn_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose3d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1179: { // thnn_conv_transpose3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::thnn_conv_transpose3d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1180: { // thnn_conv_transpose3d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto output_padding = readIntArrayRef("output_padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_transpose3d_forward(self, weight, kernel_size, bias, stride, padding, output_padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1181: { // thnn_conv2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv2d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1182: { // thnn_conv2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv2d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1183: { // thnn_conv2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv2d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1184: { // thnn_conv2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::thnn_conv2d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1185: { // thnn_conv2d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv2d_forward(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1186: { // thnn_conv_depthwise2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_depthwise2d(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1187: { // thnn_conv_depthwise2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_depthwise2d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1188: { // thnn_conv_depthwise2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_depthwise2d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1189: { // thnn_conv_depthwise2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_depthwise2d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1190: { // thnn_conv_depthwise2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::thnn_conv_depthwise2d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1191: { // thnn_conv_depthwise2d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_depthwise2d_forward(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1192: { // thnn_conv3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv3d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1193: { // thnn_conv3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv3d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1194: { // thnn_conv3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv3d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1195: { // thnn_conv3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::thnn_conv3d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1196: { // thnn_conv3d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv3d_forward(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1197: { // thnn_conv_dilated2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_dilated2d(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1198: { // thnn_conv_dilated2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_dilated2d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1199: { // thnn_conv_dilated2d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_dilated2d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1200: { // thnn_conv_dilated2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_dilated2d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1201: { // thnn_conv_dilated2d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::thnn_conv_dilated2d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1202: { // thnn_conv_dilated2d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_dilated2d_forward(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1203: { // thnn_conv_dilated3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_dilated3d(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1204: { // thnn_conv_dilated3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_dilated3d(self, weight, kernel_size, bias, stride, padding);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1205: { // thnn_conv_dilated3d
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_dilated3d(self, weight, kernel_size, bias, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1206: { // thnn_conv_dilated3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_dilated3d(self, weight, kernel_size, bias);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1207: { // thnn_conv_dilated3d
          auto kernel_size = readIntArrayRef("kernel_size");
          run_op = [=] {
              auto self = peek(0, 2);
              auto weight = peek(1, 2);
              auto the_result = at::thnn_conv_dilated3d(self, weight, kernel_size);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1208: { // thnn_conv_dilated3d_forward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto stride = readIntArrayRef("stride");
          auto padding = readIntArrayRef("padding");
          auto dilation = readIntArrayRef("dilation");
          run_op = [=] {
              auto self = peek(0, 3);
              auto weight = peek(1, 3);
              auto bias = peek(2, 3);
              auto the_result = at::thnn_conv_dilated3d_forward(self, weight, kernel_size, bias, stride, padding, dilation);
                if(OutputSize() > 0) {assignTo(Output(0),std::get<0>(the_result));}
                if(OutputSize() > 1) {assignTo(Output(1),std::get<1>(the_result));}
                if(OutputSize() > 2) {assignTo(Output(2),std::get<2>(the_result));}
              return true;
          };
      } break;
      case 1209: { // thnn_col2im
          auto output_size = readIntArrayRef("output_size");
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::thnn_col2im(self, output_size, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1210: { // thnn_col2im_backward
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::thnn_col2im_backward(grad_output, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1211: { // thnn_im2col
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto self = peek(0, 1);
              auto the_result = at::thnn_im2col(self, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      case 1212: { // thnn_im2col_backward
          auto input_size = readIntArrayRef("input_size");
          auto kernel_size = readIntArrayRef("kernel_size");
          auto dilation = readIntArrayRef("dilation");
          auto padding = readIntArrayRef("padding");
          auto stride = readIntArrayRef("stride");
          run_op = [=] {
              auto grad_output = peek(0, 1);
              auto the_result = at::thnn_im2col_backward(grad_output, input_size, kernel_size, dilation, padding, stride);
                if(OutputSize() > 0) {assignTo(Output(0),the_result);}
              return true;
          };
      } break;
      default:
        CAFFE_THROW("Unexpected key value for aten operator");
    }
  }
  USE_OPERATOR_CONTEXT_FUNCTIONS;

  bool RunOnDevice() override {
    return run_op();
  }
private:
  // actual operator implementation is initialized in ctor.
  std::function<bool()> run_op;
  at::Backend backend() const;

  TypeMeta typeMetaFor(const at::Tensor & t) {
    return typeMetaFor(t.scalar_type());
  }
  TypeMeta typeMetaFor(at::ScalarType st) {
    #define DEFINE_CASE(ctype,aten_name,_) \
      case at::k##aten_name: \
        return TypeMeta::Make<ctype>();
    switch(st) {
      AT_FORALL_SCALAR_TYPES_AND_BOOL_EXCEPT_QINT(DEFINE_CASE)
      default:
        CAFFE_THROW("Unknown ATen Type");
    }
    #undef DEFINE_CASE
  }

  at::TensorOptions optionsFor(const Tensor& ten) {
    at::Device device = ten.GetDevice();
#ifdef __HIP_PLATFORM_HCC__
    if (backend() == at::Backend::HIP) {
      device = at::Device(kCUDA, device.index());
    }
#endif
    return at::TensorOptions(device).dtype(ten.dtype());
  }

  at::Tensor tensorWrapping(const Tensor& ten_) {
    auto& ten = const_cast<Tensor&>(ten_);
    return at::from_blob(
        ten.raw_mutable_data(),
        ten.sizes(),
        optionsFor(ten));
  }

  at::Tensor peek(size_t i, size_t N) {
    auto real_idx = InputSize() - N + i;
    return tensorWrapping(Input(real_idx));
  }

  std::vector<at::Tensor> peekSlice(size_t i, size_t len, size_t N) {
    std::vector<at::Tensor> results;
    for (size_t ii = i; ii < i + len; ++ii) {
      results.push_back(peek(ii, N));
    }
    return results;
  }

  void assignTo(Tensor* dst, const at::Tensor& src_) {
    at::Tensor src = src_.contiguous();
    auto at_sizes = src.sizes();
    caffe2::TypeMeta type_meta = typeMetaFor(src);
    at::Device device = src.device();
#ifdef __HIP_PLATFORM_HCC__
    if (device.type() == at::DeviceType::CUDA) {
      device = at::Device(at::DeviceType::HIP, device.index());
    }
#endif
    at::TensorImpl* src_impl = src.unsafeReleaseTensorImpl();
    std::vector<int64_t> dims(at_sizes.begin(), at_sizes.end());
    dst->Resize(dims);
    dst->ShareExternalPointer(
        at::DataPtr(
            src_impl->data(),
            static_cast<void*>(src_impl),
            [](void* t_ptr) -> void {
              at::TensorImpl* local_impl = static_cast<at::TensorImpl*>(t_ptr);
              c10::raw::intrusive_ptr::decref(local_impl);
            },
            device),
        type_meta,
        0);
  }
  void assignListStartingAt(
      size_t offset,
      const std::vector<at::Tensor>& tensors) {
    for (size_t i = 0; i < tensors.size(); i++) {
      assignTo(Output(offset + i), tensors[i]);
    }
  }

  // the AT_FORALL_SCALAR_TYPES_AND_BOOL_EXCEPT_QINT macro just gives a 'i' or
  // 'd' argument for each type to specify if it is stored as a integer or a
  // double. We need this workaround here to extract the value in the scalar
  // losslessly because in some cases like 'sum' Torch promotes float to double
  // and will complain if we downcast it with toFloat, causing it
  // to lose precision
  double extract_d(const at::Scalar & s) {
    return s.toDouble();
  }
  int64_t extract_i(const at::Scalar & s) {
    return s.toLong();
  }

  void assignTo(Tensor* dst, at::ScalarType scalar_type, at::Scalar scalar) {
    switch(scalar_type) {
      #define DEFINE_CASE(ctype,aten_name,native) \
        case at::k##aten_name: { \
          auto value = extract_##native(scalar); \
          assignToValue<ctype>(dst, at::convert<ctype,decltype(value)>(value)); \
        } break;
      AT_FORALL_SCALAR_TYPES_AND_BOOL_EXCEPT_QINT(DEFINE_CASE)
#undef DEFINE_CASE
      default:
        CAFFE_THROW("Unknown ATen Type");
    }
  }
  template <typename T>
  void assignToValue(Tensor* dst, T v) {
    dst->Resize(std::vector<int64_t>());
    math::Set(1, v, dst->template mutable_data<T>(), &context_);
  }
  int findImplementation(const OperatorDef& operator_def) {
    CAFFE_ENFORCE(HasArgument("operator"));
    std::string op = OperatorBase::GetSingleArgument<std::string>("operator", "");
    // construct descriptor string ([DESCRIPTORS]) given the attributes
    // and inputs of this operator_def, and look up the implementation key
    // for this variant
    std::stringstream descriptor;
    descriptor << op;
    std::vector<std::string> attrs;
    for(size_t i = 0; i < operator_def.arg_size(); i++) {
      auto & attr = operator_def.arg(i);
      if(attr.name() == "operator" || attr.name() == "type" )
        continue;
      attrs.push_back(attr.name());
    }
    std::sort(attrs.begin(), attrs.end());
    for(auto & a : attrs)
      descriptor << "-" << a;

    std::string descriptor_sized =
        descriptor.str() + "-" + c10::to_string(InputSize());
    std::string descriptor_var_args = descriptor.str() + "-*";
    if (op_to_key.count(descriptor_sized) > 0) {
      return op_to_key[descriptor_sized];
    }
    if (op_to_key.count(descriptor_var_args) > 0) {
      return op_to_key[descriptor_var_args];
    }
    std::stringstream ss;
    ss << "Attempting to run unknown ATen operator configuration: "
       << descriptor_sized;
    CAFFE_THROW(ss.str());
  }
  at::Scalar readScalarAttribute(const std::string & name) {
    if(OperatorBase::HasSingleArgumentOfType<int64_t>(name)) {
      return OperatorBase::GetSingleArgument<int64_t>(name, 0);
    } else {
      CAFFE_ENFORCE(OperatorBase::HasSingleArgumentOfType<float>(name));
      return OperatorBase::GetSingleArgument<float>(name, 0);
    }
  }
  template<typename T>
  T readAttribute(const std::string & name) {
    CAFFE_ENFORCE(OperatorBase::HasSingleArgumentOfType<T>(name));
    return OperatorBase::GetSingleArgument<T>(name, 0);
  }
  std::vector<int64_t> readIntArrayRef(const std::string & name) {
    CAFFE_ENFORCE(OperatorBase::HasArgument(name));
    return OperatorBase::GetRepeatedArgument<int64_t>(name, {});
  }
  template <int N>
  std::array<bool, N> readBoolMask(const std::string& name) {
    CAFFE_ENFORCE(OperatorBase::HasArgument(name));
    std::vector<int64_t> ints =
        OperatorBase::GetRepeatedArgument<int64_t>(name, {});
    std::array<bool, N> result;
    for (size_t i = 0; i < N; ++i) {
      result[i] = ints.at(i);
    }
    return result;
  }
};

}
