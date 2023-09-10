/*
 * tune_types.h
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "tune".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Thu Jun  9 14:50:32 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_tune_types_h_
#define RTW_HEADER_tune_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_struct_k8WKy8tDBVlN8BL9RXVTiF_
#define DEFINED_TYPEDEF_FOR_struct_k8WKy8tDBVlN8BL9RXVTiF_

typedef struct {
  uint8_T estimationMethod;
  int32_T nParameters;
  boolean_T isUsingFrames;
  int32_T windowLength;
} struct_k8WKy8tDBVlN8BL9RXVTiF;

#endif

/* Custom Type definition for MATLAB Function: '<S19>/RLS' */
#ifndef struct_tag_HZDQUiKJdbppd6Ynv5kv3C
#define struct_tag_HZDQUiKJdbppd6Ynv5kv3C

struct tag_HZDQUiKJdbppd6Ynv5kv3C
{
  int32_T IteratorPosition;
};

#endif                                 /* struct_tag_HZDQUiKJdbppd6Ynv5kv3C */

#ifndef typedef_c_controllib_internal_blocks__T
#define typedef_c_controllib_internal_blocks__T

typedef struct tag_HZDQUiKJdbppd6Ynv5kv3C c_controllib_internal_blocks__T;

#endif                             /* typedef_c_controllib_internal_blocks__T */

#ifndef struct_tag_nal1ty5uCRoYnQRcgMaETG
#define struct_tag_nal1ty5uCRoYnQRcgMaETG

struct tag_nal1ty5uCRoYnQRcgMaETG
{
  c_controllib_internal_blocks__T DataIterator;
};

#endif                                 /* struct_tag_nal1ty5uCRoYnQRcgMaETG */

#ifndef typedef_d_controllib_internal_blocks__T
#define typedef_d_controllib_internal_blocks__T

typedef struct tag_nal1ty5uCRoYnQRcgMaETG d_controllib_internal_blocks__T;

#endif                             /* typedef_d_controllib_internal_blocks__T */

#ifndef struct_tag_sH9NKjQGzPvJtiC9dM3z0G
#define struct_tag_sH9NKjQGzPvJtiC9dM3z0G

struct tag_sH9NKjQGzPvJtiC9dM3z0G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_sH9NKjQGzPvJtiC9dM3z0G */

#ifndef typedef_vexv5_SmartMotorRead_tune_T
#define typedef_vexv5_SmartMotorRead_tune_T

typedef struct tag_sH9NKjQGzPvJtiC9dM3z0G vexv5_SmartMotorRead_tune_T;

#endif                                 /* typedef_vexv5_SmartMotorRead_tune_T */

#ifndef struct_tag_nuEcAzuxd9Ns5d4N9pEuvH
#define struct_tag_nuEcAzuxd9Ns5d4N9pEuvH

struct tag_nuEcAzuxd9Ns5d4N9pEuvH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_nuEcAzuxd9Ns5d4N9pEuvH */

#ifndef typedef_vexv5_SmartMotorWrite_tune_T
#define typedef_vexv5_SmartMotorWrite_tune_T

typedef struct tag_nuEcAzuxd9Ns5d4N9pEuvH vexv5_SmartMotorWrite_tune_T;

#endif                                /* typedef_vexv5_SmartMotorWrite_tune_T */

/* Parameters (default storage) */
typedef struct P_tune_T_ P_tune_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_tune_T RT_MODEL_tune_T;

#endif                                 /* RTW_HEADER_tune_types_h_ */
