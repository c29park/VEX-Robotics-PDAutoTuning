/*
 * tune_private.h
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

#ifndef RTW_HEADER_tune_private_h_
#define RTW_HEADER_tune_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "tune.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern void tune_RLS_Init(DW_RLS_tune_T *localDW);
extern void tune_RLS_Reset(DW_RLS_tune_T *localDW);
extern void tune_RLS(const real_T rtu_H[5], const real_T rtu_H_i[5], real_T
                     rtu_H_m, real_T rtu_y, boolean_T rtu_isEnabled, real_T
                     rtu_adg1, real_T rtu_yBuffer, real_T rtu_HBuffer, const
                     real_T rtu_x[11], const real_T rtu_L[121], B_RLS_tune_T
                     *localB, DW_RLS_tune_T *localDW);

#endif                                 /* RTW_HEADER_tune_private_h_ */
