/*
 * tune.c
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

#include "tune.h"
#include "rtwtypes.h"
#include "tune_private.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "zero_crossing_types.h"

/* Block signals (default storage) */
B_tune_T tune_B;

/* Block states (default storage) */
DW_tune_T tune_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_tune_T tune_PrevZCX;

/* Real-time model */
static RT_MODEL_tune_T tune_M_;
RT_MODEL_tune_T *const tune_M = &tune_M_;

/* Forward declaration for local functions */
static void tune_resetInfValue(real_T A[121]);
static real_T tune_xnrm2(int32_T n, const real_T x[12], int32_T ix0);
static real_T tune_qrFactor(const real_T A[11], const real_T S[121], real_T Ns,
  B_RLS_tune_T *localB);
static void tune_trisolve(real_T A, real_T B[11]);
static real_T tune_xnrm2_h(int32_T n, const real_T x[132], int32_T ix0,
  B_RLS_tune_T *localB);
static void tune_xgemv(int32_T m, int32_T n, const real_T A[132], int32_T ia0,
  const real_T x[132], int32_T ix0, real_T y[11], B_RLS_tune_T *localB);
static void tune_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
  real_T y[11], real_T A[132], int32_T ia0, B_RLS_tune_T *localB);
static void tune_qrFactor_j(const real_T A[121], real_T S[121], const real_T Ns
  [11], B_RLS_tune_T *localB);

/* Forward declaration for local functions */
static real_T tune_rt_powd_snf(real_T u0, real_T u1);
static void tune_generateTargetLoop(const real_T w[3], real_T targetPM, creal_T
  L[3]);
static real_T tune_rt_hypotd_snf(real_T u0, real_T u1);
static void tune_logspace(real_T d1, real_T d2, real_T y[50]);
static void tune_abs(const creal_T x[3], real_T y[3]);
static void tune_log10(real_T x[5]);
static void tune_abs_l(const creal_T x[5], real_T y[5]);
static void tune_log10_j(real_T x[100]);
static void tune_pchip(const real_T x[5], const real_T y[5], const real_T xx[100],
  real_T v[100]);
static void tune_power(const real_T b[100], real_T y[100]);
static void tune_localGetRealImag(real_T Ts, const real_T w[3], uint16_T Formula,
  real_T *realX, real_T imagX[3]);
static void tune_blkdiag(const real_T varargin_1[6], real_T y[14]);
static real_T tune_minimum(const real_T x[50]);
static boolean_T tune_vectorAny(const boolean_T x_data[], const int32_T *x_size);
static real_T tune_xnrm2_l(int32_T n, const real_T x[49], int32_T ix0);
static void tune_xgemv_g(int32_T m, int32_T n, const real_T A[49], int32_T ia0,
  const real_T x[49], int32_T ix0, real_T y[7]);
static void tune_xgerc_i(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
  real_T y[7], real_T A[49], int32_T ia0);
static void tune_xgeqp3(real_T A[49], real_T tau[7], int32_T jpvt[7]);
static void tune_xorgqr(int32_T k, real_T A[49], const real_T tau[7]);
static void tune_computeZ(real_T Z[2], const real_T C[14], const real_T d[7],
  const boolean_T p[2]);
static void tune_utilLSQFixedSizeData(const real_T C[14], const real_T d[7],
  real_T x[2]);
static void tune_blkdiag_f(const real_T varargin_1[12], real_T y[21]);
static real_T tune_norm(const real_T x[21]);
static void tune_maximum(const real_T x[3], real_T *ex, int32_T *idx);
static void tune_computeZ_n(real_T Z[3], const real_T C[21], const real_T d[7],
  const boolean_T p[3]);
static real_T tune_computeAlpha(const real_T x[3], const real_T z[3], const
  boolean_T Q[3]);
static void tune_utilLSQFixedSizeData_m(const real_T C[21], const real_T d[7],
  real_T x[3]);
static real_T tune_rt_atan2d_snf(real_T u0, real_T u1);
static real_T tune_computePM(const creal_T L);
static real_T tune_maximum_b(const real_T x[50]);
static void tune_blkdiag_f0(const real_T varargin_1[12], real_T y[32]);
static real_T tune_norm_e(const real_T x[32]);
static void tune_maximum_bt(const real_T x[4], real_T *ex, int32_T *idx);
static real_T tune_xnrm2_la(int32_T n, const real_T x[64], int32_T ix0);
static void tune_xgemv_ge(int32_T m, int32_T n, const real_T A[64], int32_T ia0,
  const real_T x[64], int32_T ix0, real_T y[8]);
static void tune_xgerc_i2(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[8], real_T A[64], int32_T ia0);
static void tune_xgeqp3_g(real_T A[64], real_T tau[8], int32_T jpvt[8]);
static void tune_xorgqr_g(int32_T k, real_T A[64], const real_T tau[8]);
static void tune_computeZ_ni(real_T Z[4], const real_T C[32], const real_T d[8],
  const boolean_T p[4]);
static real_T tune_computeAlpha_l(const real_T x[4], const real_T z[4], const
  boolean_T Q[4]);
static void tune_utilLSQFixedSizeData_mb(const real_T C[32], const real_T d[8],
  real_T x[4]);
static void tune_logspace_d(real_T d1, real_T d2, real_T y[20]);
static void tune_computeTAU(boolean_T IsDiscrete, const real_T w3[3], real_T Ts,
  uint16_T DF, real_T tau[20]);
static void tune_abs_lb(const creal_T x[50], real_T y[50]);
static void tune_utilLSQFixedSizeData_mbll(const real_T C[21], const real_T d[7],
  real_T x[3], real_T *resnorm);
static real_T tune_maximum_bt0(const real_T x[20]);
static real_T tune_minimum_n(const real_T x[20]);
static real_T tune_mean(const real_T x[20]);
static void tune_minimum_nv(const real_T x[20], real_T *ex, int32_T *idx);
static void tune_utilLSQFixedSizeData_mbl(const real_T C[32], const real_T d[8],
  real_T x[4], real_T *resnorm);
static void tune_blkdiag_f0i(const real_T varargin_1[18], real_T y[40]);
static real_T tune_norm_eb(const real_T x[40]);
static void tune_maximum_bt0s(const real_T x[5], real_T *ex, int32_T *idx);
static void tune_computeZ_ni2(real_T Z[5], const real_T C[40], const real_T d[8],
  const boolean_T p[5]);
static real_T tune_computeAlpha_lk(const real_T x[5], const real_T z[5], const
  boolean_T Q[5]);
static void tune_utilLSQFixedSizeData_mbllg(const real_T C[40], const real_T d[8],
  real_T x[5]);
static void tun_utilLSQFixedSizeData_mbllga(const real_T C[40], const real_T d[8],
  real_T x[5], real_T *resnorm);
static void tune_slpidfivepoint(real_T type, uint16_T form, const real_T
  frequencies[5], creal_T responses[5], real_T targetPM, real_T HasIntegrator,
  real_T LoopSign, real_T Ts, uint16_T IF, uint16_T DF, real_T *P, real_T *b_I,
  real_T *D, real_T *N, real_T *achievedPM);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (tune_M->Timing.TaskCounters.TID[1])++;
  if ((tune_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.2s, 0.0s] */
    tune_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for MATLAB Function: '<S19>/RLS' */
static void tune_resetInfValue(real_T A[121])
{
  real_T u;
  int32_T i;
  int32_T j;
  int32_T tmp;
  for (j = 0; j < 11; j++) {
    for (i = 0; i < 11; i++) {
      tmp = 11 * j + i;
      u = A[tmp];
      if (rtIsInf(u)) {
        if (!rtIsNaN(u)) {
          if (u < 0.0) {
            u = -1.0;
          } else {
            u = (u > 0.0);
          }
        }

        A[tmp] = u * 1.7976931348623157E+308;
      }
    }
  }
}

/* Function for MATLAB Function: '<S19>/RLS' */
static real_T tune_xnrm2(int32_T n, const real_T x[12], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S19>/RLS' */
static real_T tune_qrFactor(const real_T A[11], const real_T S[121], real_T Ns,
  B_RLS_tune_T *localB)
{
  real_T b_S;
  int32_T aoffset;
  int32_T k;
  int32_T knt;
  for (knt = 0; knt < 11; knt++) {
    aoffset = knt * 11;
    localB->s_k = 0.0;
    for (k = 0; k < 11; k++) {
      localB->s_k += S[aoffset + k] * A[k];
    }

    localB->b_A_m[knt] = localB->s_k;
  }

  localB->b_A_m[11] = Ns;
  b_S = localB->b_A_m[0];
  localB->s_k = tune_xnrm2(11, localB->b_A_m, 2);
  if (localB->s_k != 0.0) {
    localB->s_k = rt_hypotd_snf(localB->b_A_m[0], localB->s_k);
    if (localB->b_A_m[0] >= 0.0) {
      localB->s_k = -localB->s_k;
    }

    if (fabs(localB->s_k) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (aoffset = 1; aoffset < 12; aoffset++) {
          localB->b_A_m[aoffset] *= 9.9792015476736E+291;
        }

        localB->s_k *= 9.9792015476736E+291;
        b_S *= 9.9792015476736E+291;
      } while ((fabs(localB->s_k) < 1.0020841800044864E-292) && (knt < 20));

      localB->s_k = rt_hypotd_snf(b_S, tune_xnrm2(11, localB->b_A_m, 2));
      if (b_S >= 0.0) {
        localB->s_k = -localB->s_k;
      }

      for (aoffset = 0; aoffset < knt; aoffset++) {
        localB->s_k *= 1.0020841800044864E-292;
      }

      b_S = localB->s_k;
    } else {
      b_S = localB->s_k;
    }
  }

  return b_S;
}

/* Function for MATLAB Function: '<S19>/RLS' */
static void tune_trisolve(real_T A, real_T B[11])
{
  int32_T j;
  for (j = 0; j < 11; j++) {
    if (B[j] != 0.0) {
      B[j] /= A;
    }
  }
}

/* Function for MATLAB Function: '<S19>/RLS' */
static real_T tune_xnrm2_h(int32_T n, const real_T x[132], int32_T ix0,
  B_RLS_tune_T *localB)
{
  real_T absxk;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      localB->scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > localB->scale) {
          t = localB->scale / absxk;
          y = y * t * t + 1.0;
          localB->scale = absxk;
        } else {
          t = absxk / localB->scale;
          y += t * t;
        }
      }

      y = localB->scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S19>/RLS' */
static void tune_xgemv(int32_T m, int32_T n, const real_T A[132], int32_T ia0,
  const real_T x[132], int32_T ix0, real_T y[11], B_RLS_tune_T *localB)
{
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if ((m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 12 + ia0;
    for (iac = ia0; iac <= b; iac += 12) {
      ix = ix0;
      localB->c = 0.0;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        localB->c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += localB->c;
      b_iy++;
    }
  }
}

/* Function for MATLAB Function: '<S19>/RLS' */
static void tune_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
  real_T y[11], real_T A[132], int32_T ia0, B_RLS_tune_T *localB)
{
  int32_T b;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T jy;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        localB->temp = y[jy] * alpha1;
        ix = ix0;
        ijA = jA;
        b = m + jA;
        while (ijA + 1 <= b) {
          A[ijA] += A[ix - 1] * localB->temp;
          ix++;
          ijA++;
        }
      }

      jy++;
      jA += 12;
    }
  }
}

/* Function for MATLAB Function: '<S19>/RLS' */
static void tune_qrFactor_j(const real_T A[121], real_T S[121], const real_T Ns
  [11], B_RLS_tune_T *localB)
{
  int32_T aoffset;
  int32_T coffset;
  int32_T exitg1;
  int32_T ia;
  int32_T ii;
  int32_T j;
  int32_T knt;
  boolean_T exitg2;
  for (j = 0; j < 11; j++) {
    coffset = j * 11;
    for (ii = 0; ii < 11; ii++) {
      aoffset = ii * 11;
      localB->s = 0.0;
      for (knt = 0; knt < 11; knt++) {
        localB->s += A[knt * 11 + j] * S[aoffset + knt];
      }

      localB->y[coffset + ii] = localB->s;
      localB->b_A[ii + 12 * j] = localB->y[11 * j + ii];
    }
  }

  for (ii = 0; ii < 11; ii++) {
    localB->b_A[12 * ii + 11] = Ns[ii];
    localB->work[ii] = 0.0;
  }

  for (j = 0; j < 11; j++) {
    ii = j * 12 + j;
    localB->atmp = localB->b_A[ii];
    localB->tau[j] = 0.0;
    localB->s = tune_xnrm2_h(11 - j, localB->b_A, ii + 2, localB);
    if (localB->s != 0.0) {
      localB->s = rt_hypotd_snf(localB->b_A[ii], localB->s);
      if (localB->b_A[ii] >= 0.0) {
        localB->s = -localB->s;
      }

      if (fabs(localB->s) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          coffset = (ii - j) + 12;
          for (aoffset = ii + 1; aoffset < coffset; aoffset++) {
            localB->b_A[aoffset] *= 9.9792015476736E+291;
          }

          localB->s *= 9.9792015476736E+291;
          localB->atmp *= 9.9792015476736E+291;
        } while ((fabs(localB->s) < 1.0020841800044864E-292) && (knt < 20));

        localB->s = rt_hypotd_snf(localB->atmp, tune_xnrm2_h(11 - j, localB->b_A,
          ii + 2, localB));
        if (localB->atmp >= 0.0) {
          localB->s = -localB->s;
        }

        localB->tau[j] = (localB->s - localB->atmp) / localB->s;
        localB->atmp = 1.0 / (localB->atmp - localB->s);
        for (aoffset = ii + 1; aoffset < coffset; aoffset++) {
          localB->b_A[aoffset] *= localB->atmp;
        }

        for (coffset = 0; coffset < knt; coffset++) {
          localB->s *= 1.0020841800044864E-292;
        }

        localB->atmp = localB->s;
      } else {
        localB->tau[j] = (localB->s - localB->b_A[ii]) / localB->s;
        localB->atmp = 1.0 / (localB->b_A[ii] - localB->s);
        knt = (ii - j) + 12;
        for (coffset = ii + 1; coffset < knt; coffset++) {
          localB->b_A[coffset] *= localB->atmp;
        }

        localB->atmp = localB->s;
      }
    }

    localB->b_A[ii] = localB->atmp;
    if (j + 1 < 11) {
      localB->s = localB->b_A[ii];
      localB->b_A[ii] = 1.0;
      if (localB->tau[j] != 0.0) {
        knt = 12 - j;
        coffset = (ii - j) + 11;
        while ((knt > 0) && (localB->b_A[coffset] == 0.0)) {
          knt--;
          coffset--;
        }

        coffset = 10 - j;
        exitg2 = false;
        while ((!exitg2) && (coffset > 0)) {
          aoffset = ((coffset - 1) * 12 + ii) + 12;
          ia = aoffset;
          do {
            exitg1 = 0;
            if (ia + 1 <= aoffset + knt) {
              if (localB->b_A[ia] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              coffset--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        knt = 0;
        coffset = 0;
      }

      if (knt > 0) {
        tune_xgemv(knt, coffset, localB->b_A, ii + 13, localB->b_A, ii + 1,
                   localB->work, localB);
        tune_xgerc(knt, coffset, -localB->tau[j], ii + 1, localB->work,
                   localB->b_A, ii + 13, localB);
      }

      localB->b_A[ii] = localB->s;
    }
  }

  for (j = 0; j < 11; j++) {
    for (ii = 0; ii <= j; ii++) {
      localB->y[ii + 11 * j] = localB->b_A[12 * j + ii];
    }

    for (ii = j + 1; ii + 1 < 12; ii++) {
      localB->y[ii + 11 * j] = 0.0;
    }
  }

  for (j = 0; j < 11; j++) {
    for (ii = 0; ii < 11; ii++) {
      S[ii + 11 * j] = localB->y[11 * ii + j];
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S19>/RLS'
 *    '<S20>/RLS'
 */
void tune_RLS_Init(DW_RLS_tune_T *localDW)
{
  localDW->rlsEstimator_not_empty = false;
}

/*
 * System reset for atomic system:
 *    '<S19>/RLS'
 *    '<S20>/RLS'
 */
void tune_RLS_Reset(DW_RLS_tune_T *localDW)
{
  localDW->rlsEstimator_not_empty = false;
}

/*
 * Output and update for atomic system:
 *    '<S19>/RLS'
 *    '<S20>/RLS'
 */
void tune_RLS(const real_T rtu_H[5], const real_T rtu_H_i[5], real_T rtu_H_m,
              real_T rtu_y, boolean_T rtu_isEnabled, real_T rtu_adg1, real_T
              rtu_yBuffer, real_T rtu_HBuffer, const real_T rtu_x[11], const
              real_T rtu_L[121], B_RLS_tune_T *localB, DW_RLS_tune_T *localDW)
{
  int32_T A_tmp;
  int32_T L_tmp;
  int32_T i;
  int32_T k;

  /* SignalConversion generated from: '<S43>/ SFunction ' */
  for (i = 0; i < 5; i++) {
    localB->TmpSignalConversionAtSFun_o[i] = rtu_H[i];
    localB->TmpSignalConversionAtSFun_o[i + 5] = rtu_H_i[i];
  }

  localB->TmpSignalConversionAtSFun_o[10] = rtu_H_m;

  /* End of SignalConversion generated from: '<S43>/ SFunction ' */
  localB->yBuffer = rtu_yBuffer;
  localB->HBuffer = rtu_HBuffer;
  memcpy(&localB->x[0], &rtu_x[0], 11U * sizeof(real_T));
  memcpy(&localB->L[0], &rtu_L[0], 121U * sizeof(real_T));
  localDW->rlsEstimator_not_empty = true;
  localDW->rlsEstimator.DataIterator.IteratorPosition = 1;
  if (localDW->rlsEstimator.DataIterator.IteratorPosition + 1 <= 2) {
    localDW->rlsEstimator.DataIterator.IteratorPosition++;
  } else {
    localDW->rlsEstimator.DataIterator.IteratorPosition = 2;
  }

  localB->rtb_TmpSignalConversionAtSFun_c = 0.0;
  for (i = 0; i < 11; i++) {
    localB->rtb_TmpSignalConversionAtSFun_c +=
      localB->TmpSignalConversionAtSFun_o[i] * localB->x[i];
  }

  localB->rtb_TmpSignalConversionAtSFun_c = rtu_y -
    localB->rtb_TmpSignalConversionAtSFun_c;
  if (rtu_isEnabled) {
    for (i = 0; i < 11; i++) {
      memset(&localB->A[i * 11], 0, 11U * sizeof(real_T));
    }

    for (L_tmp = 0; L_tmp < 11; L_tmp++) {
      for (i = 0; i < 11; i++) {
        for (k = 0; k < 11; k++) {
          A_tmp = 11 * i + k;
          localB->A[A_tmp] += localB->L[11 * L_tmp + k] * localB->L[11 * L_tmp +
            i];
        }
      }
    }

    tune_resetInfValue(localB->A);
    localB->Sy_tmp = sqrt(rtu_adg1);
    localB->Sy = tune_qrFactor(localB->TmpSignalConversionAtSFun_o, localB->L,
      localB->Sy_tmp, localB);
    for (i = 0; i < 11; i++) {
      localB->Pxy[i] = 0.0;
      for (k = 0; k < 11; k++) {
        localB->prodVal = localB->A[11 * k + i] *
          localB->TmpSignalConversionAtSFun_o[k];
        if (rtIsInf(localB->prodVal)) {
          if (!rtIsNaN(localB->prodVal)) {
            if (localB->prodVal < 0.0) {
              localB->prodVal = -1.0;
            } else {
              localB->prodVal = (localB->prodVal > 0.0);
            }
          }

          localB->prodVal *= 1.7976931348623157E+308;
        }

        localB->prodVal += localB->Pxy[i];
        if (rtIsInf(localB->prodVal)) {
          if (!rtIsNaN(localB->prodVal)) {
            if (localB->prodVal < 0.0) {
              localB->prodVal = -1.0;
            } else {
              localB->prodVal = (localB->prodVal > 0.0);
            }
          }

          localB->prodVal *= 1.7976931348623157E+308;
        }

        localB->Pxy[i] = localB->prodVal;
      }

      localB->C[i] = localB->Pxy[i];
    }

    tune_trisolve(localB->Sy, localB->C);
    memcpy(&localB->Pxy[0], &localB->C[0], 11U * sizeof(real_T));
    tune_trisolve(localB->Sy, localB->Pxy);
    for (i = 0; i < 11; i++) {
      localB->Sy = localB->Pxy[i];
      if (rtIsInf(localB->Sy)) {
        if (!rtIsNaN(localB->Sy)) {
          if (localB->Sy < 0.0) {
            localB->Sy = -1.0;
          } else {
            localB->Sy = (localB->Sy > 0.0);
          }
        }

        localB->Sy *= 1.7976931348623157E+308;
      }

      localB->C[i] = -localB->Sy;
      localB->Pxy[i] = localB->Sy;
    }

    for (i = 0; i < 11; i++) {
      for (k = 0; k < 11; k++) {
        localB->A[k + 11 * i] = localB->C[k] *
          localB->TmpSignalConversionAtSFun_o[i];
      }
    }

    for (i = 0; i < 11; i++) {
      localB->C[i] = localB->Pxy[i] * localB->Sy_tmp;
      A_tmp = 11 * i + i;
      localB->A[A_tmp]++;
    }

    tune_qrFactor_j(localB->A, localB->L, localB->C, localB);
    tune_resetInfValue(localB->L);
    for (i = 0; i < 11; i++) {
      for (k = 0; k <= i; k++) {
        L_tmp = (((10 - i) * 11 + k) - i) + 10;
        localB->L[L_tmp] /= localB->Sy_tmp;
      }
    }

    tune_resetInfValue(localB->L);
    for (i = 0; i < 11; i++) {
      localB->x[i] += localB->Pxy[i] * localB->rtb_TmpSignalConversionAtSFun_c;
    }
  }
}

static real_T tune_rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tune_B.d_c = fabs(u0);
    tune_B.d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tune_B.d_c == 1.0) {
        y = 1.0;
      } else if (tune_B.d_c > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tune_B.d1 == 0.0) {
      y = 1.0;
    } else if (tune_B.d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_generateTargetLoop(const real_T w[3], real_T targetPM, creal_T
  L[3])
{
  tune_B.theta = 1.5707963267948966 - targetPM / 180.0 * 3.1415926535897931;
  tune_B.a_tmp = sin(tune_B.theta);
  tune_B.a = tune_B.a_tmp * tune_B.a_tmp;
  tune_B.a_tmp = -tune_B.a_tmp * w[1] * w[1];
  tune_B.c_x_tmp = cos(tune_B.theta);
  tune_B.theta = sin(tune_B.theta) * sin(tune_B.theta);
  tune_B.c_a_tmp_tmp = w[1] * w[1];
  tune_B.c_a_tmp = tune_B.c_a_tmp_tmp * tune_B.c_x_tmp * tune_B.c_x_tmp;
  tune_B.c_x_tmp = -tune_B.c_x_tmp * w[1] * w[1] * w[1];
  L[0].re = tune_B.a_tmp / (w[0] * w[0] * tune_B.a + tune_B.c_a_tmp);
  L[0].im = tune_B.c_x_tmp / (tune_B.theta * tune_rt_powd_snf(w[0], 3.0) +
    tune_B.c_a_tmp * w[0]);
  L[1].re = tune_B.a_tmp / (tune_B.c_a_tmp_tmp * tune_B.a + tune_B.c_a_tmp);
  L[1].im = tune_B.c_x_tmp / (tune_B.theta * tune_rt_powd_snf(w[1], 3.0) +
    tune_B.c_a_tmp * w[1]);
  L[2].re = tune_B.a_tmp / (w[2] * w[2] * tune_B.a + tune_B.c_a_tmp);
  L[2].im = tune_B.c_x_tmp / (tune_B.theta * tune_rt_powd_snf(w[2], 3.0) +
    tune_B.c_a_tmp * w[2]);
}

static real_T tune_rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  tune_B.a_o = fabs(u0);
  y = fabs(u1);
  if (tune_B.a_o < y) {
    tune_B.a_o /= y;
    y *= sqrt(tune_B.a_o * tune_B.a_o + 1.0);
  } else if (tune_B.a_o > y) {
    y /= tune_B.a_o;
    y = sqrt(y * y + 1.0) * tune_B.a_o;
  } else if (!rtIsNaN(y)) {
    y = tune_B.a_o * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_logspace(real_T d1, real_T d2, real_T y[50])
{
  tune_B.b_y[49] = d2;
  tune_B.b_y[0] = d1;
  if (d1 == -d2) {
    tune_B.delta1 = d2 / 49.0;
    for (tune_B.c_k = 0; tune_B.c_k < 48; tune_B.c_k++) {
      tune_B.b_y[tune_B.c_k + 1] = (((real_T)tune_B.c_k + 2.0) * 2.0 - 51.0) *
        tune_B.delta1;
    }
  } else if (((d1 < 0.0) != (d2 < 0.0)) && ((fabs(d1) > 8.9884656743115785E+307)
              || (fabs(d2) > 8.9884656743115785E+307))) {
    tune_B.delta1 = d1 / 49.0;
    tune_B.delta2 = d2 / 49.0;
    for (tune_B.c_k = 0; tune_B.c_k < 48; tune_B.c_k++) {
      tune_B.b_y[tune_B.c_k + 1] = (((real_T)tune_B.c_k + 1.0) * tune_B.delta2 +
        d1) - ((real_T)tune_B.c_k + 1.0) * tune_B.delta1;
    }
  } else {
    tune_B.delta1 = (d2 - d1) / 49.0;
    for (tune_B.c_k = 0; tune_B.c_k < 48; tune_B.c_k++) {
      tune_B.b_y[tune_B.c_k + 1] = ((real_T)tune_B.c_k + 1.0) * tune_B.delta1 +
        d1;
    }
  }

  for (tune_B.c_k = 0; tune_B.c_k < 50; tune_B.c_k++) {
    y[tune_B.c_k] = tune_rt_powd_snf(10.0, tune_B.b_y[tune_B.c_k]);
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_abs(const creal_T x[3], real_T y[3])
{
  y[0] = tune_rt_hypotd_snf(x[0].re, x[0].im);
  y[1] = tune_rt_hypotd_snf(x[1].re, x[1].im);
  y[2] = tune_rt_hypotd_snf(x[2].re, x[2].im);
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_log10(real_T x[5])
{
  for (tune_B.k_fa = 0; tune_B.k_fa < 5; tune_B.k_fa++) {
    x[tune_B.k_fa] = log10(x[tune_B.k_fa]);
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_abs_l(const creal_T x[5], real_T y[5])
{
  for (tune_B.k_ji = 0; tune_B.k_ji < 5; tune_B.k_ji++) {
    y[tune_B.k_ji] = tune_rt_hypotd_snf(x[tune_B.k_ji].re, x[tune_B.k_ji].im);
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_log10_j(real_T x[100])
{
  for (tune_B.k_il = 0; tune_B.k_il < 100; tune_B.k_il++) {
    x[tune_B.k_il] = log10(x[tune_B.k_il]);
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_pchip(const real_T x[5], const real_T y[5], const real_T xx[100],
  real_T v[100])
{
  tune_B.xloc = x[1] - x[0];
  tune_B.del_idx_0 = (y[1] - y[0]) / tune_B.xloc;
  tune_B.h_idx_0 = tune_B.xloc;
  tune_B.xloc = x[2] - x[1];
  tune_B.del_idx_1 = (y[2] - y[1]) / tune_B.xloc;
  tune_B.h_idx_1 = tune_B.xloc;
  tune_B.xloc = x[3] - x[2];
  tune_B.del_idx_2 = (y[3] - y[2]) / tune_B.xloc;
  tune_B.h_idx_2 = tune_B.xloc;
  tune_B.xloc = x[4] - x[3];
  tune_B.del_idx_3 = (y[4] - y[3]) / tune_B.xloc;
  tune_B.hs_tmp = tune_B.h_idx_0 + tune_B.h_idx_1;
  tune_B.hs3 = 3.0 * tune_B.hs_tmp;
  tune_B.dzzdx = (tune_B.h_idx_0 + tune_B.hs_tmp) / tune_B.hs3;
  tune_B.signd1 = (tune_B.h_idx_1 + tune_B.hs_tmp) / tune_B.hs3;
  tune_B.c_s_idx_1 = 0.0;
  if (tune_B.del_idx_0 < 0.0) {
    if (tune_B.del_idx_1 <= tune_B.del_idx_0) {
      tune_B.c_s_idx_1 = tune_B.del_idx_0 / (tune_B.del_idx_0 / tune_B.del_idx_1
        * tune_B.dzzdx + tune_B.signd1);
    } else if (tune_B.del_idx_1 < 0.0) {
      tune_B.c_s_idx_1 = tune_B.del_idx_1 / (tune_B.del_idx_1 / tune_B.del_idx_0
        * tune_B.signd1 + tune_B.dzzdx);
    }
  } else if (tune_B.del_idx_0 > 0.0) {
    if (tune_B.del_idx_1 >= tune_B.del_idx_0) {
      tune_B.c_s_idx_1 = tune_B.del_idx_0 / (tune_B.del_idx_0 / tune_B.del_idx_1
        * tune_B.dzzdx + tune_B.signd1);
    } else if (tune_B.del_idx_1 > 0.0) {
      tune_B.c_s_idx_1 = tune_B.del_idx_1 / (tune_B.del_idx_1 / tune_B.del_idx_0
        * tune_B.signd1 + tune_B.dzzdx);
    }
  }

  tune_B.hs = tune_B.h_idx_1 + tune_B.h_idx_2;
  tune_B.hs3 = 3.0 * tune_B.hs;
  tune_B.dzzdx = (tune_B.h_idx_1 + tune_B.hs) / tune_B.hs3;
  tune_B.signd1 = (tune_B.h_idx_2 + tune_B.hs) / tune_B.hs3;
  tune_B.hs = 0.0;
  if (tune_B.del_idx_1 < 0.0) {
    if (tune_B.del_idx_2 <= tune_B.del_idx_1) {
      tune_B.hs = tune_B.del_idx_1 / (tune_B.del_idx_1 / tune_B.del_idx_2 *
        tune_B.dzzdx + tune_B.signd1);
    } else if (tune_B.del_idx_2 < 0.0) {
      tune_B.hs = tune_B.del_idx_2 / (tune_B.del_idx_2 / tune_B.del_idx_1 *
        tune_B.signd1 + tune_B.dzzdx);
    }
  } else if (tune_B.del_idx_1 > 0.0) {
    if (tune_B.del_idx_2 >= tune_B.del_idx_1) {
      tune_B.hs = tune_B.del_idx_1 / (tune_B.del_idx_1 / tune_B.del_idx_2 *
        tune_B.dzzdx + tune_B.signd1);
    } else if (tune_B.del_idx_2 > 0.0) {
      tune_B.hs = tune_B.del_idx_2 / (tune_B.del_idx_2 / tune_B.del_idx_1 *
        tune_B.signd1 + tune_B.dzzdx);
    }
  }

  tune_B.hs_tmp_o = tune_B.h_idx_2 + tune_B.xloc;
  tune_B.hs3 = 3.0 * tune_B.hs_tmp_o;
  tune_B.dzzdx = (tune_B.h_idx_2 + tune_B.hs_tmp_o) / tune_B.hs3;
  tune_B.signd1 = (tune_B.xloc + tune_B.hs_tmp_o) / tune_B.hs3;
  tune_B.hs3 = 0.0;
  if (tune_B.del_idx_2 < 0.0) {
    if (tune_B.del_idx_3 <= tune_B.del_idx_2) {
      tune_B.hs3 = tune_B.del_idx_2 / (tune_B.del_idx_2 / tune_B.del_idx_3 *
        tune_B.dzzdx + tune_B.signd1);
    } else if (tune_B.del_idx_3 < 0.0) {
      tune_B.hs3 = tune_B.del_idx_3 / (tune_B.del_idx_3 / tune_B.del_idx_2 *
        tune_B.signd1 + tune_B.dzzdx);
    }
  } else if (tune_B.del_idx_2 > 0.0) {
    if (tune_B.del_idx_3 >= tune_B.del_idx_2) {
      tune_B.hs3 = tune_B.del_idx_2 / (tune_B.del_idx_2 / tune_B.del_idx_3 *
        tune_B.dzzdx + tune_B.signd1);
    } else if (tune_B.del_idx_3 > 0.0) {
      tune_B.hs3 = tune_B.del_idx_3 / (tune_B.del_idx_3 / tune_B.del_idx_2 *
        tune_B.signd1 + tune_B.dzzdx);
    }
  }

  tune_B.hs_tmp = ((2.0 * tune_B.h_idx_0 + tune_B.h_idx_1) * tune_B.del_idx_0 -
                   tune_B.h_idx_0 * tune_B.del_idx_1) / tune_B.hs_tmp;
  if (rtIsNaN(tune_B.del_idx_0)) {
    tune_B.signd1 = tune_B.del_idx_0;
  } else if (tune_B.del_idx_0 < 0.0) {
    tune_B.signd1 = -1.0;
  } else {
    tune_B.signd1 = (tune_B.del_idx_0 > 0.0);
  }

  if (rtIsNaN(tune_B.hs_tmp)) {
    tune_B.dzzdx = tune_B.hs_tmp;
  } else if (tune_B.hs_tmp < 0.0) {
    tune_B.dzzdx = -1.0;
  } else {
    tune_B.dzzdx = (tune_B.hs_tmp > 0.0);
  }

  if (tune_B.dzzdx != tune_B.signd1) {
    tune_B.hs_tmp = 0.0;
  } else {
    if (rtIsNaN(tune_B.del_idx_1)) {
      tune_B.dzzdx = tune_B.del_idx_1;
    } else if (tune_B.del_idx_1 < 0.0) {
      tune_B.dzzdx = -1.0;
    } else {
      tune_B.dzzdx = (tune_B.del_idx_1 > 0.0);
    }

    if ((tune_B.signd1 != tune_B.dzzdx) && (fabs(tune_B.hs_tmp) > fabs(3.0 *
          tune_B.del_idx_0))) {
      tune_B.hs_tmp = 3.0 * tune_B.del_idx_0;
    }
  }

  tune_B.hs_tmp_o = ((2.0 * tune_B.xloc + tune_B.h_idx_2) * tune_B.del_idx_3 -
                     tune_B.del_idx_2 * tune_B.xloc) / tune_B.hs_tmp_o;
  if (rtIsNaN(tune_B.del_idx_3)) {
    tune_B.signd1 = tune_B.del_idx_3;
  } else if (tune_B.del_idx_3 < 0.0) {
    tune_B.signd1 = -1.0;
  } else {
    tune_B.signd1 = (tune_B.del_idx_3 > 0.0);
  }

  if (rtIsNaN(tune_B.hs_tmp_o)) {
    tune_B.dzzdx = tune_B.hs_tmp_o;
  } else if (tune_B.hs_tmp_o < 0.0) {
    tune_B.dzzdx = -1.0;
  } else {
    tune_B.dzzdx = (tune_B.hs_tmp_o > 0.0);
  }

  if (tune_B.dzzdx != tune_B.signd1) {
    tune_B.hs_tmp_o = 0.0;
  } else {
    if (rtIsNaN(tune_B.del_idx_2)) {
      tune_B.dzzdx = tune_B.del_idx_2;
    } else if (tune_B.del_idx_2 < 0.0) {
      tune_B.dzzdx = -1.0;
    } else {
      tune_B.dzzdx = (tune_B.del_idx_2 > 0.0);
    }

    if ((tune_B.signd1 != tune_B.dzzdx) && (fabs(tune_B.hs_tmp_o) > fabs(3.0 *
          tune_B.del_idx_3))) {
      tune_B.hs_tmp_o = 3.0 * tune_B.del_idx_3;
    }
  }

  tune_B.dzzdx = (tune_B.del_idx_0 - tune_B.hs_tmp) / tune_B.h_idx_0;
  tune_B.del_idx_0 = (tune_B.c_s_idx_1 - tune_B.del_idx_0) / tune_B.h_idx_0;
  tune_B.pp_coefs[0] = (tune_B.del_idx_0 - tune_B.dzzdx) / tune_B.h_idx_0;
  tune_B.pp_coefs[4] = 2.0 * tune_B.dzzdx - tune_B.del_idx_0;
  tune_B.pp_coefs[8] = tune_B.hs_tmp;
  tune_B.pp_coefs[12] = y[0];
  tune_B.dzzdx = (tune_B.del_idx_1 - tune_B.c_s_idx_1) / tune_B.h_idx_1;
  tune_B.del_idx_0 = (tune_B.hs - tune_B.del_idx_1) / tune_B.h_idx_1;
  tune_B.pp_coefs[1] = (tune_B.del_idx_0 - tune_B.dzzdx) / tune_B.h_idx_1;
  tune_B.pp_coefs[5] = 2.0 * tune_B.dzzdx - tune_B.del_idx_0;
  tune_B.pp_coefs[9] = tune_B.c_s_idx_1;
  tune_B.pp_coefs[13] = y[1];
  tune_B.dzzdx = (tune_B.del_idx_2 - tune_B.hs) / tune_B.h_idx_2;
  tune_B.del_idx_0 = (tune_B.hs3 - tune_B.del_idx_2) / tune_B.h_idx_2;
  tune_B.pp_coefs[2] = (tune_B.del_idx_0 - tune_B.dzzdx) / tune_B.h_idx_2;
  tune_B.pp_coefs[6] = 2.0 * tune_B.dzzdx - tune_B.del_idx_0;
  tune_B.pp_coefs[10] = tune_B.hs;
  tune_B.pp_coefs[14] = y[2];
  tune_B.dzzdx = (tune_B.del_idx_3 - tune_B.hs3) / tune_B.xloc;
  tune_B.del_idx_0 = (tune_B.hs_tmp_o - tune_B.del_idx_3) / tune_B.xloc;
  tune_B.pp_coefs[3] = (tune_B.del_idx_0 - tune_B.dzzdx) / tune_B.xloc;
  tune_B.pp_coefs[7] = 2.0 * tune_B.dzzdx - tune_B.del_idx_0;
  tune_B.pp_coefs[11] = tune_B.hs3;
  tune_B.pp_coefs[15] = y[3];
  for (tune_B.ix_d = 0; tune_B.ix_d < 100; tune_B.ix_d++) {
    if (rtIsNaN(xx[tune_B.ix_d])) {
      v[tune_B.ix_d] = xx[tune_B.ix_d];
    } else {
      tune_B.low_i = 0;
      tune_B.low_ip1 = 2;
      tune_B.high_i = 5;
      while (tune_B.high_i > tune_B.low_ip1) {
        tune_B.mid_i = ((tune_B.low_i + tune_B.high_i) + 1) >> 1;
        if (xx[tune_B.ix_d] >= x[tune_B.mid_i - 1]) {
          tune_B.low_i = tune_B.mid_i - 1;
          tune_B.low_ip1 = tune_B.mid_i + 1;
        } else {
          tune_B.high_i = tune_B.mid_i;
        }
      }

      tune_B.xloc = xx[tune_B.ix_d] - x[tune_B.low_i];
      v[tune_B.ix_d] = ((tune_B.xloc * tune_B.pp_coefs[tune_B.low_i] +
                         tune_B.pp_coefs[tune_B.low_i + 4]) * tune_B.xloc +
                        tune_B.pp_coefs[tune_B.low_i + 8]) * tune_B.xloc +
        tune_B.pp_coefs[tune_B.low_i + 12];
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_power(const real_T b[100], real_T y[100])
{
  for (tune_B.k_a0 = 0; tune_B.k_a0 < 100; tune_B.k_a0++) {
    y[tune_B.k_a0] = tune_rt_powd_snf(10.0, b[tune_B.k_a0]);
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_localGetRealImag(real_T Ts, const real_T w[3], uint16_T Formula,
  real_T *realX, real_T imagX[3])
{
  if (Formula == 1) {
    *realX = -Ts / 2.0;
  } else if (Formula == 2) {
    *realX = Ts / 2.0;
  } else {
    *realX = 0.0;
  }

  tune_B.Ts = -Ts / 2.0;
  tune_B.imagX = w[0] * Ts;
  tune_B.varargin_1 = cos(tune_B.imagX);
  if (!(tune_B.varargin_1 <= 0.999999999999999)) {
    tune_B.varargin_1 = 0.999999999999999;
  }

  imagX[0] = tune_B.Ts * sin(tune_B.imagX) / (1.0 - tune_B.varargin_1);
  tune_B.imagX = w[1] * Ts;
  tune_B.varargin_1 = cos(tune_B.imagX);
  if (!(tune_B.varargin_1 <= 0.999999999999999)) {
    tune_B.varargin_1 = 0.999999999999999;
  }

  imagX[1] = tune_B.Ts * sin(tune_B.imagX) / (1.0 - tune_B.varargin_1);
  tune_B.imagX = w[2] * Ts;
  tune_B.varargin_1 = cos(tune_B.imagX);
  if (!(tune_B.varargin_1 <= 0.999999999999999)) {
    tune_B.varargin_1 = 0.999999999999999;
  }

  imagX[2] = tune_B.Ts * sin(tune_B.imagX) / (1.0 - tune_B.varargin_1);
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_blkdiag(const real_T varargin_1[6], real_T y[14])
{
  memset(&y[0], 0, 14U * sizeof(real_T));
  for (tune_B.i13 = 0; tune_B.i13 < 6; tune_B.i13++) {
    y[tune_B.i13] = varargin_1[tune_B.i13];
  }

  y[13] = 1.0;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_minimum(const real_T x[50])
{
  real_T ex;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    tune_B.idx_k = 1;
  } else {
    tune_B.idx_k = 0;
    tune_B.k_fc = 2;
    exitg1 = false;
    while ((!exitg1) && (tune_B.k_fc < 51)) {
      if (!rtIsNaN(x[tune_B.k_fc - 1])) {
        tune_B.idx_k = tune_B.k_fc;
        exitg1 = true;
      } else {
        tune_B.k_fc++;
      }
    }
  }

  if (tune_B.idx_k == 0) {
    ex = x[0];
  } else {
    ex = x[tune_B.idx_k - 1];
    while (tune_B.idx_k + 1 < 51) {
      if (ex > x[tune_B.idx_k]) {
        ex = x[tune_B.idx_k];
      }

      tune_B.idx_k++;
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static boolean_T tune_vectorAny(const boolean_T x_data[], const int32_T *x_size)
{
  boolean_T exitg1;
  boolean_T y;
  y = false;
  tune_B.k_ey = 0;
  exitg1 = false;
  while ((!exitg1) && (tune_B.k_ey <= *x_size - 1)) {
    if (x_data[tune_B.k_ey]) {
      y = true;
      exitg1 = true;
    } else {
      tune_B.k_ey++;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_xnrm2_l(int32_T n, const real_T x[49], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      tune_B.scale_p = 3.3121686421112381E-170;
      tune_B.kend_m = (ix0 + n) - 1;
      tune_B.k_jp = ix0;
      while (tune_B.k_jp <= tune_B.kend_m) {
        tune_B.absxk_p = fabs(x[tune_B.k_jp - 1]);
        if (tune_B.absxk_p > tune_B.scale_p) {
          tune_B.t_p = tune_B.scale_p / tune_B.absxk_p;
          y = y * tune_B.t_p * tune_B.t_p + 1.0;
          tune_B.scale_p = tune_B.absxk_p;
        } else {
          tune_B.t_p = tune_B.absxk_p / tune_B.scale_p;
          y += tune_B.t_p * tune_B.t_p;
        }

        tune_B.k_jp++;
      }

      y = tune_B.scale_p * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_xgemv_g(int32_T m, int32_T n, const real_T A[49], int32_T ia0,
  const real_T x[49], int32_T ix0, real_T y[7])
{
  if (n != 0) {
    tune_B.b_iy = 0;
    while (tune_B.b_iy <= n - 1) {
      y[tune_B.b_iy] = 0.0;
      tune_B.b_iy++;
    }

    tune_B.b_iy = 0;
    tune_B.b_n = (n - 1) * 7 + ia0;
    tune_B.iac = ia0;
    while (tune_B.iac <= tune_B.b_n) {
      tune_B.ix_c = ix0;
      tune_B.c = 0.0;
      tune_B.d_p = (tune_B.iac + m) - 1;
      tune_B.ia = tune_B.iac;
      while (tune_B.ia <= tune_B.d_p) {
        tune_B.c += A[tune_B.ia - 1] * x[tune_B.ix_c - 1];
        tune_B.ix_c++;
        tune_B.ia++;
      }

      y[tune_B.b_iy] += tune_B.c;
      tune_B.b_iy++;
      tune_B.iac += 7;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_xgerc_i(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
  real_T y[7], real_T A[49], int32_T ia0)
{
  if (!(alpha1 == 0.0)) {
    tune_B.jA_j = ia0 - 1;
    tune_B.jy_i = 0;
    tune_B.j_nm = 0;
    while (tune_B.j_nm <= n - 1) {
      if (y[tune_B.jy_i] != 0.0) {
        tune_B.temp_o = y[tune_B.jy_i] * alpha1;
        tune_B.ix_h = ix0;
        tune_B.ijA_c = tune_B.jA_j;
        tune_B.b_o = m + tune_B.jA_j;
        while (tune_B.ijA_c + 1 <= tune_B.b_o) {
          A[tune_B.ijA_c] += A[tune_B.ix_h - 1] * tune_B.temp_o;
          tune_B.ix_h++;
          tune_B.ijA_c++;
        }
      }

      tune_B.jy_i++;
      tune_B.jA_j += 7;
      tune_B.j_nm++;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_xgeqp3(real_T A[49], real_T tau[7], int32_T jpvt[7])
{
  int32_T exitg1;
  boolean_T exitg2;
  for (tune_B.k_n = 0; tune_B.k_n < 7; tune_B.k_n++) {
    jpvt[tune_B.k_n] = tune_B.k_n + 1;
    tau[tune_B.k_n] = 0.0;
    tune_B.work_b[tune_B.k_n] = 0.0;
    tune_B.ix0_o = tune_B.k_n * 7 + 1;
    tune_B.smax_k = 0.0;
    tune_B.scale_mc = 3.3121686421112381E-170;
    tune_B.ii_k = tune_B.ix0_o;
    while (tune_B.ii_k <= tune_B.ix0_o + 6) {
      tune_B.absxk_h = fabs(A[tune_B.ii_k - 1]);
      if (tune_B.absxk_h > tune_B.scale_mc) {
        tune_B.t_cs = tune_B.scale_mc / tune_B.absxk_h;
        tune_B.smax_k = tune_B.smax_k * tune_B.t_cs * tune_B.t_cs + 1.0;
        tune_B.scale_mc = tune_B.absxk_h;
      } else {
        tune_B.t_cs = tune_B.absxk_h / tune_B.scale_mc;
        tune_B.smax_k += tune_B.t_cs * tune_B.t_cs;
      }

      tune_B.ii_k++;
    }

    tune_B.vn1_d[tune_B.k_n] = tune_B.scale_mc * sqrt(tune_B.smax_k);
    tune_B.vn2_e[tune_B.k_n] = tune_B.vn1_d[tune_B.k_n];
  }

  for (tune_B.k_n = 0; tune_B.k_n < 7; tune_B.k_n++) {
    tune_B.ix0_o = tune_B.k_n + 1;
    tune_B.ii_k = tune_B.k_n * 7 + tune_B.k_n;
    tune_B.pvt_n = 0;
    if (7 - tune_B.k_n > 1) {
      tune_B.ix_gg = tune_B.k_n;
      tune_B.smax_k = fabs(tune_B.vn1_d[tune_B.k_n]);
      tune_B.b_ix_c = 2;
      while (tune_B.b_ix_c <= 7 - tune_B.k_n) {
        tune_B.ix_gg++;
        tune_B.scale_mc = fabs(tune_B.vn1_d[tune_B.ix_gg]);
        if (tune_B.scale_mc > tune_B.smax_k) {
          tune_B.pvt_n = tune_B.b_ix_c - 1;
          tune_B.smax_k = tune_B.scale_mc;
        }

        tune_B.b_ix_c++;
      }
    }

    tune_B.pvt_n += tune_B.k_n;
    if (tune_B.pvt_n != tune_B.k_n) {
      tune_B.b_ix_c = tune_B.pvt_n * 7;
      tune_B.iy = tune_B.k_n * 7;
      for (tune_B.ix_gg = 0; tune_B.ix_gg < 7; tune_B.ix_gg++) {
        tune_B.temp_tmp_c = tune_B.b_ix_c + tune_B.ix_gg;
        tune_B.smax_k = A[tune_B.temp_tmp_c];
        tune_B.i3 = tune_B.iy + tune_B.ix_gg;
        A[tune_B.temp_tmp_c] = A[tune_B.i3];
        A[tune_B.i3] = tune_B.smax_k;
      }

      tune_B.ix_gg = jpvt[tune_B.pvt_n];
      jpvt[tune_B.pvt_n] = jpvt[tune_B.k_n];
      jpvt[tune_B.k_n] = tune_B.ix_gg;
      tune_B.vn1_d[tune_B.pvt_n] = tune_B.vn1_d[tune_B.k_n];
      tune_B.vn2_e[tune_B.pvt_n] = tune_B.vn2_e[tune_B.k_n];
    }

    if (tune_B.k_n + 1 < 7) {
      tune_B.scale_mc = A[tune_B.ii_k];
      tau[tune_B.k_n] = 0.0;
      tune_B.smax_k = tune_xnrm2_l(6 - tune_B.k_n, A, tune_B.ii_k + 2);
      if (tune_B.smax_k != 0.0) {
        tune_B.smax_k = tune_rt_hypotd_snf(A[tune_B.ii_k], tune_B.smax_k);
        if (A[tune_B.ii_k] >= 0.0) {
          tune_B.smax_k = -tune_B.smax_k;
        }

        if (fabs(tune_B.smax_k) < 1.0020841800044864E-292) {
          tune_B.pvt_n = 0;
          do {
            tune_B.pvt_n++;
            tune_B.ix_gg = (tune_B.ii_k - tune_B.k_n) + 7;
            tune_B.b_ix_c = tune_B.ii_k + 1;
            while (tune_B.b_ix_c + 1 <= tune_B.ix_gg) {
              A[tune_B.b_ix_c] *= 9.9792015476736E+291;
              tune_B.b_ix_c++;
            }

            tune_B.smax_k *= 9.9792015476736E+291;
            tune_B.scale_mc *= 9.9792015476736E+291;
          } while ((fabs(tune_B.smax_k) < 1.0020841800044864E-292) &&
                   (tune_B.pvt_n < 20));

          tune_B.smax_k = tune_rt_hypotd_snf(tune_B.scale_mc, tune_xnrm2_l(6 -
            tune_B.k_n, A, tune_B.ii_k + 2));
          if (tune_B.scale_mc >= 0.0) {
            tune_B.smax_k = -tune_B.smax_k;
          }

          tau[tune_B.k_n] = (tune_B.smax_k - tune_B.scale_mc) / tune_B.smax_k;
          tune_B.scale_mc = 1.0 / (tune_B.scale_mc - tune_B.smax_k);
          tune_B.b_ix_c = tune_B.ii_k + 1;
          while (tune_B.b_ix_c + 1 <= tune_B.ix_gg) {
            A[tune_B.b_ix_c] *= tune_B.scale_mc;
            tune_B.b_ix_c++;
          }

          tune_B.ix_gg = 0;
          while (tune_B.ix_gg <= tune_B.pvt_n - 1) {
            tune_B.smax_k *= 1.0020841800044864E-292;
            tune_B.ix_gg++;
          }

          tune_B.scale_mc = tune_B.smax_k;
        } else {
          tau[tune_B.k_n] = (tune_B.smax_k - A[tune_B.ii_k]) / tune_B.smax_k;
          tune_B.scale_mc = 1.0 / (A[tune_B.ii_k] - tune_B.smax_k);
          tune_B.pvt_n = (tune_B.ii_k - tune_B.k_n) + 7;
          tune_B.ix_gg = tune_B.ii_k + 1;
          while (tune_B.ix_gg + 1 <= tune_B.pvt_n) {
            A[tune_B.ix_gg] *= tune_B.scale_mc;
            tune_B.ix_gg++;
          }

          tune_B.scale_mc = tune_B.smax_k;
        }
      }

      A[tune_B.ii_k] = tune_B.scale_mc;
      tune_B.smax_k = A[tune_B.ii_k];
      A[tune_B.ii_k] = 1.0;
      if (tau[tune_B.k_n] != 0.0) {
        tune_B.pvt_n = 7 - tune_B.k_n;
        tune_B.ix_gg = (tune_B.ii_k - tune_B.k_n) + 6;
        while ((tune_B.pvt_n > 0) && (A[tune_B.ix_gg] == 0.0)) {
          tune_B.pvt_n--;
          tune_B.ix_gg--;
        }

        tune_B.ix_gg = 6 - tune_B.k_n;
        exitg2 = false;
        while ((!exitg2) && (tune_B.ix_gg > 0)) {
          tune_B.b_ix_c = ((tune_B.ix_gg - 1) * 7 + tune_B.ii_k) + 7;
          tune_B.iy = tune_B.b_ix_c;
          do {
            exitg1 = 0;
            if (tune_B.iy + 1 <= tune_B.b_ix_c + tune_B.pvt_n) {
              if (A[tune_B.iy] != 0.0) {
                exitg1 = 1;
              } else {
                tune_B.iy++;
              }
            } else {
              tune_B.ix_gg--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        tune_B.pvt_n = 0;
        tune_B.ix_gg = 0;
      }

      if (tune_B.pvt_n > 0) {
        tune_xgemv_g(tune_B.pvt_n, tune_B.ix_gg, A, tune_B.ii_k + 8, A,
                     tune_B.ii_k + 1, tune_B.work_b);
        tune_xgerc_i(tune_B.pvt_n, tune_B.ix_gg, -tau[tune_B.k_n], tune_B.ii_k +
                     1, tune_B.work_b, A, tune_B.ii_k + 8);
      }

      A[tune_B.ii_k] = tune_B.smax_k;
    } else {
      tau[6] = 0.0;
    }

    while (tune_B.ix0_o + 1 < 8) {
      tune_B.ii_k = tune_B.ix0_o * 7 + tune_B.k_n;
      if (tune_B.vn1_d[tune_B.ix0_o] != 0.0) {
        tune_B.smax_k = fabs(A[tune_B.ii_k]) / tune_B.vn1_d[tune_B.ix0_o];
        tune_B.smax_k = 1.0 - tune_B.smax_k * tune_B.smax_k;
        if (tune_B.smax_k < 0.0) {
          tune_B.smax_k = 0.0;
        }

        tune_B.scale_mc = tune_B.vn1_d[tune_B.ix0_o] / tune_B.vn2_e[tune_B.ix0_o];
        tune_B.scale_mc = tune_B.scale_mc * tune_B.scale_mc * tune_B.smax_k;
        if (tune_B.scale_mc <= 1.4901161193847656E-8) {
          if (tune_B.k_n + 1 < 7) {
            tune_B.vn1_d[tune_B.ix0_o] = tune_xnrm2_l(6 - tune_B.k_n, A,
              tune_B.ii_k + 2);
            tune_B.vn2_e[tune_B.ix0_o] = tune_B.vn1_d[tune_B.ix0_o];
          } else {
            tune_B.vn1_d[tune_B.ix0_o] = 0.0;
            tune_B.vn2_e[tune_B.ix0_o] = 0.0;
          }
        } else {
          tune_B.vn1_d[tune_B.ix0_o] *= sqrt(tune_B.smax_k);
        }
      }

      tune_B.ix0_o++;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_xorgqr(int32_T k, real_T A[49], const real_T tau[7])
{
  int32_T exitg1;
  boolean_T exitg2;
  tune_B.itau_c = k;
  while (tune_B.itau_c < 7) {
    tune_B.iaii_i = tune_B.itau_c * 7;
    for (tune_B.i_d = 0; tune_B.i_d < 7; tune_B.i_d++) {
      A[tune_B.iaii_i + tune_B.i_d] = 0.0;
    }

    A[tune_B.iaii_i + tune_B.itau_c] = 1.0;
    tune_B.itau_c++;
  }

  tune_B.itau_c = k - 1;
  for (tune_B.i_d = 0; tune_B.i_d < 7; tune_B.i_d++) {
    tune_B.work_f[tune_B.i_d] = 0.0;
  }

  tune_B.i_d = k;
  while (tune_B.i_d >= 1) {
    tune_B.iaii_i = ((tune_B.i_d - 1) * 7 + tune_B.i_d) + 7;
    A[tune_B.iaii_i - 8] = 1.0;
    if (tau[tune_B.itau_c] != 0.0) {
      tune_B.lastv_d = 8 - tune_B.i_d;
      tune_B.lastc_g = tune_B.iaii_i - tune_B.i_d;
      while ((tune_B.lastv_d > 0) && (A[tune_B.lastc_g - 1] == 0.0)) {
        tune_B.lastv_d--;
        tune_B.lastc_g--;
      }

      tune_B.lastc_g = 7 - tune_B.i_d;
      exitg2 = false;
      while ((!exitg2) && (tune_B.lastc_g > 0)) {
        tune_B.coltop_l = (tune_B.lastc_g - 1) * 7 + tune_B.iaii_i;
        tune_B.b_ia_f = tune_B.coltop_l;
        do {
          exitg1 = 0;
          if (tune_B.b_ia_f <= (tune_B.coltop_l + tune_B.lastv_d) - 1) {
            if (A[tune_B.b_ia_f - 1] != 0.0) {
              exitg1 = 1;
            } else {
              tune_B.b_ia_f++;
            }
          } else {
            tune_B.lastc_g--;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    } else {
      tune_B.lastv_d = 0;
      tune_B.lastc_g = 0;
    }

    if (tune_B.lastv_d > 0) {
      tune_xgemv_g(tune_B.lastv_d, tune_B.lastc_g, A, tune_B.iaii_i, A,
                   tune_B.iaii_i - 7, tune_B.work_f);
      tune_xgerc_i(tune_B.lastv_d, tune_B.lastc_g, -tau[tune_B.itau_c],
                   tune_B.iaii_i - 7, tune_B.work_f, A, tune_B.iaii_i);
    }

    tune_B.lastv_d = tune_B.iaii_i - tune_B.i_d;
    tune_B.lastc_g = tune_B.iaii_i - 7;
    while (tune_B.lastc_g + 1 <= tune_B.lastv_d) {
      A[tune_B.lastc_g] *= -tau[tune_B.itau_c];
      tune_B.lastc_g++;
    }

    A[tune_B.iaii_i - 8] = 1.0 - tau[tune_B.itau_c];
    tune_B.lastv_d = 0;
    while (tune_B.lastv_d <= tune_B.i_d - 2) {
      A[(tune_B.iaii_i - tune_B.lastv_d) - 9] = 0.0;
      tune_B.lastv_d++;
    }

    tune_B.itau_c--;
    tune_B.i_d--;
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_computeZ(real_T Z[2], const real_T C[14], const real_T d[7],
  const boolean_T p[2])
{
  memset(&tune_B.A_d[0], 0, 14U * sizeof(real_T));
  tune_B.ncols_e = 0.0;
  for (tune_B.k_g = 0; tune_B.k_g < 2; tune_B.k_g++) {
    if (p[tune_B.k_g]) {
      tune_B.ncols_e++;
      for (tune_B.rankA_p = 0; tune_B.rankA_p < 7; tune_B.rankA_p++) {
        tune_B.A_d[tune_B.rankA_p + 7 * ((int32_T)tune_B.ncols_e - 1)] = C[7 *
          tune_B.k_g + tune_B.rankA_p];
      }
    }
  }

  for (tune_B.rankA_p = 0; tune_B.rankA_p < 2; tune_B.rankA_p++) {
    for (tune_B.k_g = 0; tune_B.k_g < 7; tune_B.k_g++) {
      tune_B.Q_b[tune_B.k_g + 7 * tune_B.rankA_p] = tune_B.A_d[7 *
        tune_B.rankA_p + tune_B.k_g];
    }
  }

  for (tune_B.rankA_p = 0; tune_B.rankA_p < 5; tune_B.rankA_p++) {
    for (tune_B.k_g = 0; tune_B.k_g < 7; tune_B.k_g++) {
      tune_B.Q_b[tune_B.k_g + 7 * (tune_B.rankA_p + 2)] = 0.0;
    }
  }

  tune_xgeqp3(tune_B.Q_b, tune_B.qtd_j, tune_B.jpvt1_p);
  tune_B.jpvt_g[0] = tune_B.jpvt1_p[0];
  tune_B.A_d[0] = tune_B.Q_b[0];
  tune_B.rankA_p = 1;
  while (tune_B.rankA_p + 1 < 8) {
    tune_B.A_d[tune_B.rankA_p] = 0.0;
    tune_B.rankA_p++;
  }

  tune_B.jpvt_g[1] = tune_B.jpvt1_p[1];
  tune_B.rankA_p = 0;
  while (tune_B.rankA_p <= 1) {
    tune_B.A_d[tune_B.rankA_p + 7] = tune_B.Q_b[tune_B.rankA_p + 7];
    tune_B.rankA_p++;
  }

  tune_B.rankA_p = 2;
  while (tune_B.rankA_p + 1 < 8) {
    tune_B.A_d[tune_B.rankA_p + 7] = 0.0;
    tune_B.rankA_p++;
  }

  tune_xorgqr(2, tune_B.Q_b, tune_B.qtd_j);
  for (tune_B.rankA_p = 0; tune_B.rankA_p < 7; tune_B.rankA_p++) {
    tune_B.qtd_j[tune_B.rankA_p] = 0.0;
    for (tune_B.k_g = 0; tune_B.k_g < 7; tune_B.k_g++) {
      tune_B.qtd_j[tune_B.rankA_p] += tune_B.Q_b[7 * tune_B.rankA_p + tune_B.k_g]
        * d[tune_B.k_g];
    }
  }

  if (tune_B.ncols_e >= 7.0) {
    tune_B.ncols_e = 7.0;
  }

  tune_B.rankA_p = (int32_T)tune_B.ncols_e - 1;
  tune_B.z_f[0] = 0.0;
  tune_B.z_f[1] = 0.0;
  tune_B.k_g = 0;
  while (tune_B.k_g <= tune_B.rankA_p) {
    tune_B.z_f[tune_B.jpvt_g[tune_B.k_g] - 1] = tune_B.qtd_j[tune_B.k_g];
    tune_B.k_g++;
  }

  tune_B.k_g = 0;
  while (tune_B.k_g <= tune_B.rankA_p) {
    tune_B.j_d = tune_B.rankA_p - tune_B.k_g;
    tune_B.z_f[tune_B.jpvt_g[tune_B.j_d] - 1] /= tune_B.A_d[7 * tune_B.j_d +
      tune_B.j_d];
    tune_B.b_i_c = 0;
    while (tune_B.b_i_c <= tune_B.j_d - 1) {
      tune_B.z_f[tune_B.jpvt_g[0] - 1] -= tune_B.z_f[tune_B.jpvt_g[tune_B.j_d] -
        1] * tune_B.A_d[7 * tune_B.j_d];
      tune_B.b_i_c++;
    }

    tune_B.k_g++;
  }

  tune_B.rankA_p = 1;
  if (p[0]) {
    Z[0] = tune_B.z_f[0];
    tune_B.rankA_p = 2;
  }

  if (p[1]) {
    Z[1] = tune_B.z_f[tune_B.rankA_p - 1];
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_utilLSQFixedSizeData(const real_T C[14], const real_T d[7],
  real_T x[2])
{
  static const int32_T tmp = 2;
  int32_T exitg2;
  boolean_T exitg1;
  boolean_T exitg3;
  tune_B.wz_idx_0 = 0.0;
  tune_B.wz_idx_1 = 0.0;
  tune_B.tol_a = 0.0;
  tune_B.j_k = 0;
  exitg1 = false;
  while ((!exitg1) && (tune_B.j_k < 2)) {
    tune_B.s = 0.0;
    for (tune_B.i_mx = 0; tune_B.i_mx < 7; tune_B.i_mx++) {
      tune_B.s += fabs(C[7 * tune_B.j_k + tune_B.i_mx]);
    }

    if (rtIsNaN(tune_B.s)) {
      tune_B.tol_a = (rtNaN);
      exitg1 = true;
    } else {
      if (tune_B.s > tune_B.tol_a) {
        tune_B.tol_a = tune_B.s;
      }

      tune_B.j_k++;
    }
  }

  tune_B.tol_a = 2.2204460492503131E-15 * tune_B.tol_a * 7.0;
  tune_B.P_d[0] = false;
  tune_B.Z_d[0] = true;
  x[0] = 0.0;
  tune_B.P_d[1] = false;
  tune_B.Z_d[1] = true;
  x[1] = 0.0;
  for (tune_B.j_k = 0; tune_B.j_k < 7; tune_B.j_k++) {
    tune_B.s = C[tune_B.j_k];
    tune_B.i_mx = tune_B.j_k << 1;
    tune_B.w_tmp_d[tune_B.i_mx] = tune_B.s;
    tune_B.x_j = tune_B.s * 0.0;
    tune_B.s = C[tune_B.j_k + 7];
    tune_B.w_tmp_d[tune_B.i_mx + 1] = tune_B.s;
    tune_B.d_b[tune_B.j_k] = d[tune_B.j_k] - (tune_B.s * 0.0 + tune_B.x_j);
  }

  for (tune_B.j_k = 0; tune_B.j_k < 2; tune_B.j_k++) {
    tune_B.w_o[tune_B.j_k] = 0.0;
    for (tune_B.i_mx = 0; tune_B.i_mx < 7; tune_B.i_mx++) {
      tune_B.w_o[tune_B.j_k] += tune_B.w_tmp_d[(tune_B.i_mx << 1) + tune_B.j_k] *
        tune_B.d_b[tune_B.i_mx];
    }
  }

  tune_B.iter_js = 0;
  exitg1 = false;
  while ((!exitg1) && tune_vectorAny(tune_B.Z_d, &tmp)) {
    tune_B.found_f = false;
    tune_B.j_k = 1;
    exitg3 = false;
    while ((!exitg3) && (tune_B.j_k - 1 < 2)) {
      if (tune_B.Z_d[(int16_T)tune_B.j_k - 1] && (tune_B.w_o[(int16_T)tune_B.j_k
           - 1] > tune_B.tol_a)) {
        tune_B.found_f = true;
        exitg3 = true;
      } else {
        tune_B.j_k++;
      }
    }

    if (tune_B.found_f) {
      if (tune_B.P_d[0]) {
        tune_B.wz_idx_0 = -1.7976931348623157E+308;
      }

      if (tune_B.Z_d[0]) {
        tune_B.wz_idx_0 = tune_B.w_o[0];
      }

      if (tune_B.P_d[1]) {
        tune_B.wz_idx_1 = -1.7976931348623157E+308;
      }

      if (tune_B.Z_d[1]) {
        tune_B.wz_idx_1 = tune_B.w_o[1];
      }

      if ((tune_B.wz_idx_0 < tune_B.wz_idx_1) || (rtIsNaN(tune_B.wz_idx_0) &&
           (!rtIsNaN(tune_B.wz_idx_1)))) {
        tune_B.j_k = 1;
      } else {
        tune_B.j_k = 0;
      }

      tune_B.P_d[tune_B.j_k] = true;
      tune_B.Z_d[tune_B.j_k] = false;
      tune_B.z_i[0] = 0.0;
      tune_B.z_i[1] = 0.0;
      tune_computeZ(tune_B.z_i, C, d, tune_B.P_d);
      do {
        exitg2 = 0;
        tune_B.found_f = false;
        tune_B.j_k = 1;
        exitg3 = false;
        while ((!exitg3) && (tune_B.j_k - 1 < 2)) {
          if (tune_B.P_d[(int16_T)tune_B.j_k - 1] && (tune_B.z_i[(int16_T)
               tune_B.j_k - 1] <= 0.0)) {
            tune_B.found_f = true;
            exitg3 = true;
          } else {
            tune_B.j_k++;
          }
        }

        if (tune_B.found_f) {
          tune_B.iter_js++;
          if (tune_B.iter_js > 6) {
            x[0] = tune_B.z_i[0];
            x[1] = tune_B.z_i[1];
            exitg2 = 1;
          } else {
            tune_B.w_o[0] = 1.7976931348623157E+308;
            tune_B.w_o[1] = 1.7976931348623157E+308;
            if ((tune_B.z_i[0] <= 0.0) && tune_B.P_d[0]) {
              tune_B.w_o[0] = x[0] / (x[0] - tune_B.z_i[0]);
            }

            if ((tune_B.z_i[1] <= 0.0) && tune_B.P_d[1]) {
              tune_B.w_o[1] = x[1] / (x[1] - tune_B.z_i[1]);
            }

            if ((tune_B.w_o[0] > tune_B.w_o[1]) || (rtIsNaN(tune_B.w_o[0]) &&
                 (!rtIsNaN(tune_B.w_o[1])))) {
              tune_B.s = tune_B.w_o[1];
            } else {
              tune_B.s = tune_B.w_o[0];
            }

            tune_B.x_j = (tune_B.z_i[0] - x[0]) * tune_B.s + x[0];
            tune_B.found_f = (((fabs(tune_B.x_j) < tune_B.tol_a) && tune_B.P_d[0])
                              || tune_B.Z_d[0]);
            x[0] = tune_B.x_j;
            tune_B.z_i[0] = 0.0;
            tune_B.P_d[0] = !tune_B.found_f;
            tune_B.Z_d[0] = tune_B.found_f;
            tune_B.x_j = (tune_B.z_i[1] - x[1]) * tune_B.s + x[1];
            tune_B.found_f = (((fabs(tune_B.x_j) < tune_B.tol_a) && tune_B.P_d[1])
                              || tune_B.Z_d[1]);
            x[1] = tune_B.x_j;
            tune_B.z_i[1] = 0.0;
            tune_B.P_d[1] = !tune_B.found_f;
            tune_B.Z_d[1] = tune_B.found_f;
            tune_computeZ(tune_B.z_i, C, d, tune_B.P_d);
          }
        } else {
          x[0] = tune_B.z_i[0];
          x[1] = tune_B.z_i[1];
          for (tune_B.j_k = 0; tune_B.j_k < 7; tune_B.j_k++) {
            tune_B.d_b[tune_B.j_k] = d[tune_B.j_k] - (C[tune_B.j_k + 7] *
              tune_B.z_i[1] + C[tune_B.j_k] * tune_B.z_i[0]);
          }

          for (tune_B.j_k = 0; tune_B.j_k < 2; tune_B.j_k++) {
            tune_B.w_o[tune_B.j_k] = 0.0;
            for (tune_B.i_mx = 0; tune_B.i_mx < 7; tune_B.i_mx++) {
              tune_B.w_o[tune_B.j_k] += tune_B.w_tmp_d[(tune_B.i_mx << 1) +
                tune_B.j_k] * tune_B.d_b[tune_B.i_mx];
            }
          }

          exitg2 = 2;
        }
      } while (exitg2 == 0);

      if (exitg2 == 1) {
        exitg1 = true;
      }
    } else {
      exitg1 = true;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_blkdiag_f(const real_T varargin_1[12], real_T y[21])
{
  memset(&y[0], 0, 21U * sizeof(real_T));
  for (tune_B.i11 = 0; tune_B.i11 < 2; tune_B.i11++) {
    for (tune_B.i12 = 0; tune_B.i12 < 6; tune_B.i12++) {
      y[tune_B.i12 + 7 * tune_B.i11] = varargin_1[6 * tune_B.i11 + tune_B.i12];
    }
  }

  y[20] = 1.0;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_norm(const real_T x[21])
{
  real_T y;
  boolean_T exitg1;
  y = 0.0;
  tune_B.j_l = 0;
  exitg1 = false;
  while ((!exitg1) && (tune_B.j_l < 3)) {
    tune_B.s_f = 0.0;
    for (tune_B.i_k = 0; tune_B.i_k < 7; tune_B.i_k++) {
      tune_B.s_f += fabs(x[7 * tune_B.j_l + tune_B.i_k]);
    }

    if (rtIsNaN(tune_B.s_f)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (tune_B.s_f > y) {
        y = tune_B.s_f;
      }

      tune_B.j_l++;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_maximum(const real_T x[3], real_T *ex, int32_T *idx)
{
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    *idx = 1;
  } else {
    *idx = 0;
    tune_B.k_b = 2;
    exitg1 = false;
    while ((!exitg1) && (tune_B.k_b < 4)) {
      if (!rtIsNaN(x[tune_B.k_b - 1])) {
        *idx = tune_B.k_b;
        exitg1 = true;
      } else {
        tune_B.k_b++;
      }
    }
  }

  if (*idx == 0) {
    *ex = x[0];
    *idx = 1;
  } else {
    *ex = x[*idx - 1];
    tune_B.k_b = *idx;
    while (tune_B.k_b + 1 < 4) {
      if (*ex < x[tune_B.k_b]) {
        *ex = x[tune_B.k_b];
        *idx = tune_B.k_b + 1;
      }

      tune_B.k_b++;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_computeZ_n(real_T Z[3], const real_T C[21], const real_T d[7],
  const boolean_T p[3])
{
  memset(&tune_B.A_l[0], 0, 21U * sizeof(real_T));
  tune_B.ncols_m = 0.0;
  for (tune_B.k_p = 0; tune_B.k_p < 3; tune_B.k_p++) {
    if (p[tune_B.k_p]) {
      tune_B.ncols_m++;
      for (tune_B.rankA_c = 0; tune_B.rankA_c < 7; tune_B.rankA_c++) {
        tune_B.A_l[tune_B.rankA_c + 7 * ((int32_T)tune_B.ncols_m - 1)] = C[7 *
          tune_B.k_p + tune_B.rankA_c];
      }
    }
  }

  for (tune_B.rankA_c = 0; tune_B.rankA_c < 3; tune_B.rankA_c++) {
    for (tune_B.k_p = 0; tune_B.k_p < 7; tune_B.k_p++) {
      tune_B.Q_c[tune_B.k_p + 7 * tune_B.rankA_c] = tune_B.A_l[7 *
        tune_B.rankA_c + tune_B.k_p];
    }
  }

  for (tune_B.rankA_c = 0; tune_B.rankA_c < 4; tune_B.rankA_c++) {
    for (tune_B.k_p = 0; tune_B.k_p < 7; tune_B.k_p++) {
      tune_B.Q_c[tune_B.k_p + 7 * (tune_B.rankA_c + 3)] = 0.0;
    }
  }

  tune_xgeqp3(tune_B.Q_c, tune_B.qtd_h, tune_B.jpvt1_c);
  tune_B.jpvt_f[0] = tune_B.jpvt1_c[0];
  tune_B.A_l[0] = tune_B.Q_c[0];
  tune_B.rankA_c = 1;
  while (tune_B.rankA_c + 1 < 8) {
    tune_B.A_l[tune_B.rankA_c] = 0.0;
    tune_B.rankA_c++;
  }

  tune_B.jpvt_f[1] = tune_B.jpvt1_c[1];
  tune_B.rankA_c = 0;
  while (tune_B.rankA_c <= 1) {
    tune_B.A_l[tune_B.rankA_c + 7] = tune_B.Q_c[tune_B.rankA_c + 7];
    tune_B.rankA_c++;
  }

  tune_B.rankA_c = 2;
  while (tune_B.rankA_c + 1 < 8) {
    tune_B.A_l[tune_B.rankA_c + 7] = 0.0;
    tune_B.rankA_c++;
  }

  tune_B.jpvt_f[2] = tune_B.jpvt1_c[2];
  tune_B.rankA_c = 0;
  while (tune_B.rankA_c <= 2) {
    tune_B.A_l[tune_B.rankA_c + 14] = tune_B.Q_c[tune_B.rankA_c + 14];
    tune_B.rankA_c++;
  }

  tune_B.rankA_c = 3;
  while (tune_B.rankA_c + 1 < 8) {
    tune_B.A_l[tune_B.rankA_c + 14] = 0.0;
    tune_B.rankA_c++;
  }

  tune_xorgqr(3, tune_B.Q_c, tune_B.qtd_h);
  for (tune_B.rankA_c = 0; tune_B.rankA_c < 7; tune_B.rankA_c++) {
    tune_B.qtd_h[tune_B.rankA_c] = 0.0;
    for (tune_B.k_p = 0; tune_B.k_p < 7; tune_B.k_p++) {
      tune_B.qtd_h[tune_B.rankA_c] += tune_B.Q_c[7 * tune_B.rankA_c + tune_B.k_p]
        * d[tune_B.k_p];
    }
  }

  if (tune_B.ncols_m >= 7.0) {
    tune_B.ncols_m = 7.0;
  }

  tune_B.rankA_c = (int32_T)tune_B.ncols_m - 1;
  tune_B.z_a[0] = 0.0;
  tune_B.z_a[1] = 0.0;
  tune_B.z_a[2] = 0.0;
  tune_B.k_p = 0;
  while (tune_B.k_p <= tune_B.rankA_c) {
    tune_B.z_a[tune_B.jpvt_f[tune_B.k_p] - 1] = tune_B.qtd_h[tune_B.k_p];
    tune_B.k_p++;
  }

  tune_B.k_p = 0;
  while (tune_B.k_p <= tune_B.rankA_c) {
    tune_B.j_f = tune_B.rankA_c - tune_B.k_p;
    tune_B.z_a[tune_B.jpvt_f[tune_B.j_f] - 1] /= tune_B.A_l[7 * tune_B.j_f +
      tune_B.j_f];
    tune_B.b_i_p = 0;
    while (tune_B.b_i_p <= tune_B.j_f - 1) {
      tune_B.z_a[tune_B.jpvt_f[tune_B.b_i_p] - 1] -= tune_B.A_l[7 * tune_B.j_f +
        tune_B.b_i_p] * tune_B.z_a[tune_B.jpvt_f[tune_B.j_f] - 1];
      tune_B.b_i_p++;
    }

    tune_B.k_p++;
  }

  tune_B.rankA_c = 1;
  if (p[0]) {
    Z[0] = tune_B.z_a[0];
    tune_B.rankA_c = 2;
  }

  if (p[1]) {
    Z[1] = tune_B.z_a[tune_B.rankA_c - 1];
    tune_B.rankA_c++;
  }

  if (p[2]) {
    Z[2] = tune_B.z_a[tune_B.rankA_c - 1];
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_computeAlpha(const real_T x[3], const real_T z[3], const
  boolean_T Q[3])
{
  real_T result;
  boolean_T exitg1;
  tune_B.b_x_l[0] = 1.7976931348623157E+308;
  tune_B.b_x_l[1] = 1.7976931348623157E+308;
  tune_B.b_x_l[2] = 1.7976931348623157E+308;
  if (Q[0]) {
    tune_B.b_x_l[0] = x[0] / (x[0] - z[0]);
  }

  if (Q[1]) {
    tune_B.b_x_l[1] = x[1] / (x[1] - z[1]);
  }

  if (Q[2]) {
    tune_B.b_x_l[2] = x[2] / (x[2] - z[2]);
  }

  if (!rtIsNaN(tune_B.b_x_l[0])) {
    tune_B.idx_p = 1;
  } else {
    tune_B.idx_p = 0;
    tune_B.k_pi = 2;
    exitg1 = false;
    while ((!exitg1) && (tune_B.k_pi <= 3)) {
      if (!rtIsNaN(tune_B.b_x_l[tune_B.k_pi - 1])) {
        tune_B.idx_p = tune_B.k_pi;
        exitg1 = true;
      } else {
        tune_B.k_pi++;
      }
    }
  }

  if (tune_B.idx_p == 0) {
    result = tune_B.b_x_l[0];
  } else {
    result = tune_B.b_x_l[tune_B.idx_p - 1];
    while (tune_B.idx_p + 1 <= 3) {
      if (result > tune_B.b_x_l[tune_B.idx_p]) {
        result = tune_B.b_x_l[tune_B.idx_p];
      }

      tune_B.idx_p++;
    }
  }

  return result;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_utilLSQFixedSizeData_m(const real_T C[21], const real_T d[7],
  real_T x[3])
{
  static const int32_T tmp = 3;
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  tune_B.tol_h = 2.2204460492503131E-15 * tune_norm(C) * 7.0;
  tune_B.wz_p[0] = 0.0;
  tune_B.P_oo[0] = false;
  tune_B.Z_f[0] = true;
  x[0] = 0.0;
  tune_B.wz_p[1] = 0.0;
  tune_B.P_oo[1] = false;
  tune_B.Z_f[1] = true;
  x[1] = 0.0;
  tune_B.wz_p[2] = 0.0;
  tune_B.P_oo[2] = false;
  tune_B.Z_f[2] = true;
  x[2] = 0.0;
  for (tune_B.b_ct_n = 0; tune_B.b_ct_n < 7; tune_B.b_ct_n++) {
    tune_B.C_l = C[tune_B.b_ct_n];
    tune_B.w_tmp_p[3 * tune_B.b_ct_n] = tune_B.C_l;
    tune_B.x_h = tune_B.C_l * 0.0;
    tune_B.C_l = C[tune_B.b_ct_n + 7];
    tune_B.w_tmp_p[3 * tune_B.b_ct_n + 1] = tune_B.C_l;
    tune_B.x_h += tune_B.C_l * 0.0;
    tune_B.C_l = C[tune_B.b_ct_n + 14];
    tune_B.w_tmp_p[3 * tune_B.b_ct_n + 2] = tune_B.C_l;
    tune_B.d_l[tune_B.b_ct_n] = d[tune_B.b_ct_n] - (tune_B.C_l * 0.0 +
      tune_B.x_h);
  }

  for (tune_B.b_ct_n = 0; tune_B.b_ct_n < 3; tune_B.b_ct_n++) {
    tune_B.w_a[tune_B.b_ct_n] = 0.0;
    for (tune_B.i2 = 0; tune_B.i2 < 7; tune_B.i2++) {
      tune_B.w_a[tune_B.b_ct_n] += tune_B.w_tmp_p[3 * tune_B.i2 + tune_B.b_ct_n]
        * tune_B.d_l[tune_B.i2];
    }
  }

  tune_B.iter_f = 0;
  exitg2 = false;
  while ((!exitg2) && tune_vectorAny(tune_B.Z_f, &tmp)) {
    tune_B.found_a = false;
    tune_B.b_ct_n = 1;
    exitg3 = false;
    while ((!exitg3) && (tune_B.b_ct_n - 1 < 3)) {
      if (tune_B.Z_f[(int16_T)tune_B.b_ct_n - 1] && (tune_B.w_a[(int16_T)
           tune_B.b_ct_n - 1] > tune_B.tol_h)) {
        tune_B.found_a = true;
        exitg3 = true;
      } else {
        tune_B.b_ct_n++;
      }
    }

    if (tune_B.found_a) {
      if (tune_B.P_oo[0]) {
        tune_B.wz_p[0] = -1.7976931348623157E+308;
      }

      if (tune_B.Z_f[0]) {
        tune_B.wz_p[0] = tune_B.w_a[0];
      }

      tune_B.z_e[0] = 0.0;
      if (tune_B.P_oo[1]) {
        tune_B.wz_p[1] = -1.7976931348623157E+308;
      }

      if (tune_B.Z_f[1]) {
        tune_B.wz_p[1] = tune_B.w_a[1];
      }

      tune_B.z_e[1] = 0.0;
      if (tune_B.P_oo[2]) {
        tune_B.wz_p[2] = -1.7976931348623157E+308;
      }

      if (tune_B.Z_f[2]) {
        tune_B.wz_p[2] = tune_B.w_a[2];
      }

      tune_B.z_e[2] = 0.0;
      tune_maximum(tune_B.wz_p, &tune_B.C_l, &tune_B.b_ct_n);
      tune_B.P_oo[tune_B.b_ct_n - 1] = true;
      tune_B.Z_f[tune_B.b_ct_n - 1] = false;
      tune_computeZ_n(tune_B.z_e, C, d, tune_B.P_oo);
      do {
        exitg1 = 0;
        tune_B.found_a = false;
        tune_B.b_ct_n = 1;
        exitg3 = false;
        while ((!exitg3) && (tune_B.b_ct_n - 1 < 3)) {
          if (tune_B.P_oo[(int16_T)tune_B.b_ct_n - 1] && (tune_B.z_e[(int16_T)
               tune_B.b_ct_n - 1] <= 0.0)) {
            tune_B.found_a = true;
            exitg3 = true;
          } else {
            tune_B.b_ct_n++;
          }
        }

        if (tune_B.found_a) {
          tune_B.iter_f++;
          if (tune_B.iter_f > 9) {
            x[0] = tune_B.z_e[0];
            x[1] = tune_B.z_e[1];
            x[2] = tune_B.z_e[2];
            exitg1 = 1;
          } else {
            tune_B.z_oy[0] = ((tune_B.z_e[0] <= 0.0) && tune_B.P_oo[0]);
            tune_B.z_oy[1] = ((tune_B.z_e[1] <= 0.0) && tune_B.P_oo[1]);
            tune_B.z_oy[2] = ((tune_B.z_e[2] <= 0.0) && tune_B.P_oo[2]);
            tune_B.C_l = tune_computeAlpha(x, tune_B.z_e, tune_B.z_oy);
            tune_B.x_h = (tune_B.z_e[0] - x[0]) * tune_B.C_l + x[0];
            tune_B.found_a = (((fabs(tune_B.x_h) < tune_B.tol_h) && tune_B.P_oo
                               [0]) || tune_B.Z_f[0]);
            x[0] = tune_B.x_h;
            tune_B.z_e[0] = 0.0;
            tune_B.P_oo[0] = !tune_B.found_a;
            tune_B.Z_f[0] = tune_B.found_a;
            tune_B.x_h = (tune_B.z_e[1] - x[1]) * tune_B.C_l + x[1];
            tune_B.found_a = (((fabs(tune_B.x_h) < tune_B.tol_h) && tune_B.P_oo
                               [1]) || tune_B.Z_f[1]);
            x[1] = tune_B.x_h;
            tune_B.z_e[1] = 0.0;
            tune_B.P_oo[1] = !tune_B.found_a;
            tune_B.Z_f[1] = tune_B.found_a;
            tune_B.x_h = (tune_B.z_e[2] - x[2]) * tune_B.C_l + x[2];
            tune_B.found_a = (((fabs(tune_B.x_h) < tune_B.tol_h) && tune_B.P_oo
                               [2]) || tune_B.Z_f[2]);
            x[2] = tune_B.x_h;
            tune_B.z_e[2] = 0.0;
            tune_B.P_oo[2] = !tune_B.found_a;
            tune_B.Z_f[2] = tune_B.found_a;
            tune_computeZ_n(tune_B.z_e, C, d, tune_B.P_oo);
          }
        } else {
          x[0] = tune_B.z_e[0];
          x[1] = tune_B.z_e[1];
          x[2] = tune_B.z_e[2];
          for (tune_B.b_ct_n = 0; tune_B.b_ct_n < 7; tune_B.b_ct_n++) {
            tune_B.d_l[tune_B.b_ct_n] = d[tune_B.b_ct_n] - ((C[tune_B.b_ct_n + 7]
              * tune_B.z_e[1] + C[tune_B.b_ct_n] * tune_B.z_e[0]) +
              C[tune_B.b_ct_n + 14] * tune_B.z_e[2]);
          }

          for (tune_B.b_ct_n = 0; tune_B.b_ct_n < 3; tune_B.b_ct_n++) {
            tune_B.w_a[tune_B.b_ct_n] = 0.0;
            for (tune_B.i2 = 0; tune_B.i2 < 7; tune_B.i2++) {
              tune_B.w_a[tune_B.b_ct_n] += tune_B.w_tmp_p[3 * tune_B.i2 +
                tune_B.b_ct_n] * tune_B.d_l[tune_B.i2];
            }
          }

          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    } else {
      exitg2 = true;
    }
  }
}

static real_T tune_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      tune_B.u0_a = 1;
    } else {
      tune_B.u0_a = -1;
    }

    if (u1 > 0.0) {
      tune_B.u1 = 1;
    } else {
      tune_B.u1 = -1;
    }

    y = atan2(tune_B.u0_a, tune_B.u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_computePM(const creal_T L)
{
  real_T PM;
  tune_B.x_l = tune_rt_atan2d_snf(L.im, L.re) * 180.0 / 3.1415926535897931;
  if (rtIsNaN(tune_B.x_l) || rtIsInf(tune_B.x_l)) {
    tune_B.r = (rtNaN);
  } else if (tune_B.x_l == 0.0) {
    tune_B.r = 0.0;
  } else {
    tune_B.r = fmod(tune_B.x_l, 360.0);
    if (tune_B.r == 0.0) {
      tune_B.r = 0.0;
    } else if (tune_B.x_l < 0.0) {
      tune_B.r += 360.0;
    }
  }

  PM = tune_B.r - 180.0;
  return PM;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_maximum_b(const real_T x[50])
{
  real_T ex;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    tune_B.idx_l = 1;
  } else {
    tune_B.idx_l = 0;
    tune_B.k_i3 = 2;
    exitg1 = false;
    while ((!exitg1) && (tune_B.k_i3 < 51)) {
      if (!rtIsNaN(x[tune_B.k_i3 - 1])) {
        tune_B.idx_l = tune_B.k_i3;
        exitg1 = true;
      } else {
        tune_B.k_i3++;
      }
    }
  }

  if (tune_B.idx_l == 0) {
    ex = x[0];
  } else {
    ex = x[tune_B.idx_l - 1];
    while (tune_B.idx_l + 1 < 51) {
      if (ex < x[tune_B.idx_l]) {
        ex = x[tune_B.idx_l];
      }

      tune_B.idx_l++;
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_blkdiag_f0(const real_T varargin_1[12], real_T y[32])
{
  memset(&y[0], 0, sizeof(real_T) << 5U);
  for (tune_B.i9 = 0; tune_B.i9 < 2; tune_B.i9++) {
    for (tune_B.i10 = 0; tune_B.i10 < 6; tune_B.i10++) {
      y[tune_B.i10 + (tune_B.i9 << 3)] = varargin_1[6 * tune_B.i9 + tune_B.i10];
    }
  }

  y[22] = 1.0;
  y[31] = 1.0;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_norm_e(const real_T x[32])
{
  real_T y;
  boolean_T exitg1;
  y = 0.0;
  tune_B.j_p = 0;
  exitg1 = false;
  while ((!exitg1) && (tune_B.j_p < 4)) {
    tune_B.s_pt = 0.0;
    for (tune_B.i_o = 0; tune_B.i_o < 8; tune_B.i_o++) {
      tune_B.s_pt += fabs(x[(tune_B.j_p << 3) + tune_B.i_o]);
    }

    if (rtIsNaN(tune_B.s_pt)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (tune_B.s_pt > y) {
        y = tune_B.s_pt;
      }

      tune_B.j_p++;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_maximum_bt(const real_T x[4], real_T *ex, int32_T *idx)
{
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    *idx = 1;
  } else {
    *idx = 0;
    tune_B.k_eh = 2;
    exitg1 = false;
    while ((!exitg1) && (tune_B.k_eh < 5)) {
      if (!rtIsNaN(x[tune_B.k_eh - 1])) {
        *idx = tune_B.k_eh;
        exitg1 = true;
      } else {
        tune_B.k_eh++;
      }
    }
  }

  if (*idx == 0) {
    *ex = x[0];
    *idx = 1;
  } else {
    *ex = x[*idx - 1];
    tune_B.k_eh = *idx;
    while (tune_B.k_eh + 1 < 5) {
      if (*ex < x[tune_B.k_eh]) {
        *ex = x[tune_B.k_eh];
        *idx = tune_B.k_eh + 1;
      }

      tune_B.k_eh++;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_xnrm2_la(int32_T n, const real_T x[64], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      tune_B.scale_m = 3.3121686421112381E-170;
      tune_B.kend = (ix0 + n) - 1;
      tune_B.k_j = ix0;
      while (tune_B.k_j <= tune_B.kend) {
        tune_B.absxk_m = fabs(x[tune_B.k_j - 1]);
        if (tune_B.absxk_m > tune_B.scale_m) {
          tune_B.t_c = tune_B.scale_m / tune_B.absxk_m;
          y = y * tune_B.t_c * tune_B.t_c + 1.0;
          tune_B.scale_m = tune_B.absxk_m;
        } else {
          tune_B.t_c = tune_B.absxk_m / tune_B.scale_m;
          y += tune_B.t_c * tune_B.t_c;
        }

        tune_B.k_j++;
      }

      y = tune_B.scale_m * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_xgemv_ge(int32_T m, int32_T n, const real_T A[64], int32_T ia0,
  const real_T x[64], int32_T ix0, real_T y[8])
{
  if (n != 0) {
    tune_B.b_iy_j = 0;
    while (tune_B.b_iy_j <= n - 1) {
      y[tune_B.b_iy_j] = 0.0;
      tune_B.b_iy_j++;
    }

    tune_B.b_iy_j = 0;
    tune_B.b_c = ((n - 1) << 3) + ia0;
    tune_B.iac_h = ia0;
    while (tune_B.iac_h <= tune_B.b_c) {
      tune_B.ix_o = ix0;
      tune_B.c_n = 0.0;
      tune_B.d_d = (tune_B.iac_h + m) - 1;
      tune_B.ia_c = tune_B.iac_h;
      while (tune_B.ia_c <= tune_B.d_d) {
        tune_B.c_n += A[tune_B.ia_c - 1] * x[tune_B.ix_o - 1];
        tune_B.ix_o++;
        tune_B.ia_c++;
      }

      y[tune_B.b_iy_j] += tune_B.c_n;
      tune_B.b_iy_j++;
      tune_B.iac_h += 8;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_xgerc_i2(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[8], real_T A[64], int32_T ia0)
{
  if (!(alpha1 == 0.0)) {
    tune_B.jA = ia0 - 1;
    tune_B.jy = 0;
    tune_B.j_n = 0;
    while (tune_B.j_n <= n - 1) {
      if (y[tune_B.jy] != 0.0) {
        tune_B.temp = y[tune_B.jy] * alpha1;
        tune_B.ix_g = ix0;
        tune_B.ijA = tune_B.jA;
        tune_B.b_d = m + tune_B.jA;
        while (tune_B.ijA + 1 <= tune_B.b_d) {
          A[tune_B.ijA] += A[tune_B.ix_g - 1] * tune_B.temp;
          tune_B.ix_g++;
          tune_B.ijA++;
        }
      }

      tune_B.jy++;
      tune_B.jA += 8;
      tune_B.j_n++;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_xgeqp3_g(real_T A[64], real_T tau[8], int32_T jpvt[8])
{
  int32_T exitg1;
  boolean_T exitg2;
  for (tune_B.k = 0; tune_B.k < 8; tune_B.k++) {
    jpvt[tune_B.k] = tune_B.k + 1;
    tau[tune_B.k] = 0.0;
    tune_B.work[tune_B.k] = 0.0;
    tune_B.ix0 = (tune_B.k << 3) + 1;
    tune_B.smax = 0.0;
    tune_B.scale = 3.3121686421112381E-170;
    tune_B.ii = tune_B.ix0;
    while (tune_B.ii <= tune_B.ix0 + 7) {
      tune_B.absxk = fabs(A[tune_B.ii - 1]);
      if (tune_B.absxk > tune_B.scale) {
        tune_B.t = tune_B.scale / tune_B.absxk;
        tune_B.smax = tune_B.smax * tune_B.t * tune_B.t + 1.0;
        tune_B.scale = tune_B.absxk;
      } else {
        tune_B.t = tune_B.absxk / tune_B.scale;
        tune_B.smax += tune_B.t * tune_B.t;
      }

      tune_B.ii++;
    }

    tune_B.vn1[tune_B.k] = tune_B.scale * sqrt(tune_B.smax);
    tune_B.vn2[tune_B.k] = tune_B.vn1[tune_B.k];
  }

  for (tune_B.k = 0; tune_B.k < 8; tune_B.k++) {
    tune_B.ix0 = tune_B.k + 1;
    tune_B.itemp = tune_B.k << 3;
    tune_B.ii = tune_B.itemp + tune_B.k;
    tune_B.pvt = 0;
    if (8 - tune_B.k > 1) {
      tune_B.ix = tune_B.k;
      tune_B.smax = fabs(tune_B.vn1[tune_B.k]);
      tune_B.b_ix = 2;
      while (tune_B.b_ix <= 8 - tune_B.k) {
        tune_B.ix++;
        tune_B.scale = fabs(tune_B.vn1[tune_B.ix]);
        if (tune_B.scale > tune_B.smax) {
          tune_B.pvt = tune_B.b_ix - 1;
          tune_B.smax = tune_B.scale;
        }

        tune_B.b_ix++;
      }
    }

    tune_B.pvt += tune_B.k;
    if (tune_B.pvt != tune_B.k) {
      tune_B.b_ix = tune_B.pvt << 3;
      for (tune_B.ix = 0; tune_B.ix < 8; tune_B.ix++) {
        tune_B.temp_tmp = tune_B.b_ix + tune_B.ix;
        tune_B.smax = A[tune_B.temp_tmp];
        tune_B.i1 = tune_B.itemp + tune_B.ix;
        A[tune_B.temp_tmp] = A[tune_B.i1];
        A[tune_B.i1] = tune_B.smax;
      }

      tune_B.itemp = jpvt[tune_B.pvt];
      jpvt[tune_B.pvt] = jpvt[tune_B.k];
      jpvt[tune_B.k] = tune_B.itemp;
      tune_B.vn1[tune_B.pvt] = tune_B.vn1[tune_B.k];
      tune_B.vn2[tune_B.pvt] = tune_B.vn2[tune_B.k];
    }

    if (tune_B.k + 1 < 8) {
      tune_B.scale = A[tune_B.ii];
      tau[tune_B.k] = 0.0;
      tune_B.smax = tune_xnrm2_la(7 - tune_B.k, A, tune_B.ii + 2);
      if (tune_B.smax != 0.0) {
        tune_B.smax = tune_rt_hypotd_snf(A[tune_B.ii], tune_B.smax);
        if (A[tune_B.ii] >= 0.0) {
          tune_B.smax = -tune_B.smax;
        }

        if (fabs(tune_B.smax) < 1.0020841800044864E-292) {
          tune_B.itemp = 0;
          do {
            tune_B.itemp++;
            tune_B.pvt = (tune_B.ii - tune_B.k) + 8;
            tune_B.ix = tune_B.ii + 1;
            while (tune_B.ix + 1 <= tune_B.pvt) {
              A[tune_B.ix] *= 9.9792015476736E+291;
              tune_B.ix++;
            }

            tune_B.smax *= 9.9792015476736E+291;
            tune_B.scale *= 9.9792015476736E+291;
          } while ((fabs(tune_B.smax) < 1.0020841800044864E-292) &&
                   (tune_B.itemp < 20));

          tune_B.smax = tune_rt_hypotd_snf(tune_B.scale, tune_xnrm2_la(7 -
            tune_B.k, A, tune_B.ii + 2));
          if (tune_B.scale >= 0.0) {
            tune_B.smax = -tune_B.smax;
          }

          tau[tune_B.k] = (tune_B.smax - tune_B.scale) / tune_B.smax;
          tune_B.scale = 1.0 / (tune_B.scale - tune_B.smax);
          tune_B.ix = tune_B.ii + 1;
          while (tune_B.ix + 1 <= tune_B.pvt) {
            A[tune_B.ix] *= tune_B.scale;
            tune_B.ix++;
          }

          tune_B.pvt = 0;
          while (tune_B.pvt <= tune_B.itemp - 1) {
            tune_B.smax *= 1.0020841800044864E-292;
            tune_B.pvt++;
          }

          tune_B.scale = tune_B.smax;
        } else {
          tau[tune_B.k] = (tune_B.smax - A[tune_B.ii]) / tune_B.smax;
          tune_B.scale = 1.0 / (A[tune_B.ii] - tune_B.smax);
          tune_B.itemp = (tune_B.ii - tune_B.k) + 8;
          tune_B.pvt = tune_B.ii + 1;
          while (tune_B.pvt + 1 <= tune_B.itemp) {
            A[tune_B.pvt] *= tune_B.scale;
            tune_B.pvt++;
          }

          tune_B.scale = tune_B.smax;
        }
      }

      A[tune_B.ii] = tune_B.scale;
      tune_B.smax = A[tune_B.ii];
      A[tune_B.ii] = 1.0;
      if (tau[tune_B.k] != 0.0) {
        tune_B.itemp = 8 - tune_B.k;
        tune_B.pvt = (tune_B.ii - tune_B.k) + 7;
        while ((tune_B.itemp > 0) && (A[tune_B.pvt] == 0.0)) {
          tune_B.itemp--;
          tune_B.pvt--;
        }

        tune_B.pvt = 7 - tune_B.k;
        exitg2 = false;
        while ((!exitg2) && (tune_B.pvt > 0)) {
          tune_B.ix = (((tune_B.pvt - 1) << 3) + tune_B.ii) + 8;
          tune_B.b_ix = tune_B.ix;
          do {
            exitg1 = 0;
            if (tune_B.b_ix + 1 <= tune_B.ix + tune_B.itemp) {
              if (A[tune_B.b_ix] != 0.0) {
                exitg1 = 1;
              } else {
                tune_B.b_ix++;
              }
            } else {
              tune_B.pvt--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        tune_B.itemp = 0;
        tune_B.pvt = 0;
      }

      if (tune_B.itemp > 0) {
        tune_xgemv_ge(tune_B.itemp, tune_B.pvt, A, tune_B.ii + 9, A, tune_B.ii +
                      1, tune_B.work);
        tune_xgerc_i2(tune_B.itemp, tune_B.pvt, -tau[tune_B.k], tune_B.ii + 1,
                      tune_B.work, A, tune_B.ii + 9);
      }

      A[tune_B.ii] = tune_B.smax;
    } else {
      tau[7] = 0.0;
    }

    while (tune_B.ix0 + 1 < 9) {
      tune_B.ii = (tune_B.ix0 << 3) + tune_B.k;
      if (tune_B.vn1[tune_B.ix0] != 0.0) {
        tune_B.smax = fabs(A[tune_B.ii]) / tune_B.vn1[tune_B.ix0];
        tune_B.smax = 1.0 - tune_B.smax * tune_B.smax;
        if (tune_B.smax < 0.0) {
          tune_B.smax = 0.0;
        }

        tune_B.scale = tune_B.vn1[tune_B.ix0] / tune_B.vn2[tune_B.ix0];
        tune_B.scale = tune_B.scale * tune_B.scale * tune_B.smax;
        if (tune_B.scale <= 1.4901161193847656E-8) {
          if (tune_B.k + 1 < 8) {
            tune_B.vn1[tune_B.ix0] = tune_xnrm2_la(7 - tune_B.k, A, tune_B.ii +
              2);
            tune_B.vn2[tune_B.ix0] = tune_B.vn1[tune_B.ix0];
          } else {
            tune_B.vn1[tune_B.ix0] = 0.0;
            tune_B.vn2[tune_B.ix0] = 0.0;
          }
        } else {
          tune_B.vn1[tune_B.ix0] *= sqrt(tune_B.smax);
        }
      }

      tune_B.ix0++;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_xorgqr_g(int32_T k, real_T A[64], const real_T tau[8])
{
  int32_T exitg1;
  boolean_T exitg2;
  tune_B.itau = k;
  while (tune_B.itau < 8) {
    tune_B.iaii = tune_B.itau << 3;
    memset(&A[tune_B.iaii], 0, sizeof(real_T) << 3U);
    A[tune_B.iaii + tune_B.itau] = 1.0;
    tune_B.itau++;
  }

  tune_B.itau = k - 1;
  memset(&tune_B.work_n[0], 0, sizeof(real_T) << 3U);
  tune_B.i_a = k;
  while (tune_B.i_a >= 1) {
    tune_B.iaii = (((tune_B.i_a - 1) << 3) + tune_B.i_a) + 8;
    A[tune_B.iaii - 9] = 1.0;
    if (tau[tune_B.itau] != 0.0) {
      tune_B.lastv = 9 - tune_B.i_a;
      tune_B.lastc = tune_B.iaii - tune_B.i_a;
      while ((tune_B.lastv > 0) && (A[tune_B.lastc - 1] == 0.0)) {
        tune_B.lastv--;
        tune_B.lastc--;
      }

      tune_B.lastc = 8 - tune_B.i_a;
      exitg2 = false;
      while ((!exitg2) && (tune_B.lastc > 0)) {
        tune_B.coltop = ((tune_B.lastc - 1) << 3) + tune_B.iaii;
        tune_B.b_ia = tune_B.coltop;
        do {
          exitg1 = 0;
          if (tune_B.b_ia <= (tune_B.coltop + tune_B.lastv) - 1) {
            if (A[tune_B.b_ia - 1] != 0.0) {
              exitg1 = 1;
            } else {
              tune_B.b_ia++;
            }
          } else {
            tune_B.lastc--;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    } else {
      tune_B.lastv = 0;
      tune_B.lastc = 0;
    }

    if (tune_B.lastv > 0) {
      tune_xgemv_ge(tune_B.lastv, tune_B.lastc, A, tune_B.iaii, A, tune_B.iaii -
                    8, tune_B.work_n);
      tune_xgerc_i2(tune_B.lastv, tune_B.lastc, -tau[tune_B.itau], tune_B.iaii -
                    8, tune_B.work_n, A, tune_B.iaii);
    }

    tune_B.lastv = tune_B.iaii - tune_B.i_a;
    tune_B.lastc = tune_B.iaii - 8;
    while (tune_B.lastc + 1 <= tune_B.lastv) {
      A[tune_B.lastc] *= -tau[tune_B.itau];
      tune_B.lastc++;
    }

    A[tune_B.iaii - 9] = 1.0 - tau[tune_B.itau];
    tune_B.lastv = 0;
    while (tune_B.lastv <= tune_B.i_a - 2) {
      A[(tune_B.iaii - tune_B.lastv) - 10] = 0.0;
      tune_B.lastv++;
    }

    tune_B.itau--;
    tune_B.i_a--;
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_computeZ_ni(real_T Z[4], const real_T C[32], const real_T d[8],
  const boolean_T p[4])
{
  memset(&tune_B.A_g[0], 0, sizeof(real_T) << 5U);
  tune_B.ncols_o = 0.0;
  for (tune_B.k_m = 0; tune_B.k_m < 4; tune_B.k_m++) {
    if (p[tune_B.k_m]) {
      tune_B.ncols_o++;
      for (tune_B.rankA_e = 0; tune_B.rankA_e < 8; tune_B.rankA_e++) {
        tune_B.A_g[tune_B.rankA_e + (((int32_T)tune_B.ncols_o - 1) << 3)] = C
          [(tune_B.k_m << 3) + tune_B.rankA_e];
      }
    }
  }

  for (tune_B.rankA_e = 0; tune_B.rankA_e < 4; tune_B.rankA_e++) {
    for (tune_B.k_m = 0; tune_B.k_m < 8; tune_B.k_m++) {
      tune_B.Q_m[tune_B.k_m + (tune_B.rankA_e << 3)] = tune_B.A_g
        [(tune_B.rankA_e << 3) + tune_B.k_m];
      tune_B.Q_m[tune_B.k_m + ((tune_B.rankA_e + 4) << 3)] = 0.0;
    }
  }

  tune_xgeqp3_g(tune_B.Q_m, tune_B.qtd_b, tune_B.jpvt1_o);
  tune_B.jpvt_o[0] = tune_B.jpvt1_o[0];
  tune_B.A_g[0] = tune_B.Q_m[0];
  tune_B.rankA_e = 1;
  while (tune_B.rankA_e + 1 < 9) {
    tune_B.A_g[tune_B.rankA_e] = 0.0;
    tune_B.rankA_e++;
  }

  tune_B.jpvt_o[1] = tune_B.jpvt1_o[1];
  tune_B.rankA_e = 0;
  while (tune_B.rankA_e <= 1) {
    tune_B.A_g[tune_B.rankA_e + 8] = tune_B.Q_m[tune_B.rankA_e + 8];
    tune_B.rankA_e++;
  }

  tune_B.rankA_e = 2;
  while (tune_B.rankA_e + 1 < 9) {
    tune_B.A_g[tune_B.rankA_e + 8] = 0.0;
    tune_B.rankA_e++;
  }

  tune_B.jpvt_o[2] = tune_B.jpvt1_o[2];
  tune_B.rankA_e = 0;
  while (tune_B.rankA_e <= 2) {
    tune_B.A_g[tune_B.rankA_e + 16] = tune_B.Q_m[tune_B.rankA_e + 16];
    tune_B.rankA_e++;
  }

  tune_B.rankA_e = 3;
  while (tune_B.rankA_e + 1 < 9) {
    tune_B.A_g[tune_B.rankA_e + 16] = 0.0;
    tune_B.rankA_e++;
  }

  tune_B.jpvt_o[3] = tune_B.jpvt1_o[3];
  tune_B.rankA_e = 0;
  while (tune_B.rankA_e <= 3) {
    tune_B.A_g[tune_B.rankA_e + 24] = tune_B.Q_m[tune_B.rankA_e + 24];
    tune_B.rankA_e++;
  }

  tune_B.rankA_e = 4;
  while (tune_B.rankA_e + 1 < 9) {
    tune_B.A_g[tune_B.rankA_e + 24] = 0.0;
    tune_B.rankA_e++;
  }

  tune_xorgqr_g(4, tune_B.Q_m, tune_B.qtd_b);
  for (tune_B.rankA_e = 0; tune_B.rankA_e < 8; tune_B.rankA_e++) {
    tune_B.qtd_b[tune_B.rankA_e] = 0.0;
    for (tune_B.k_m = 0; tune_B.k_m < 8; tune_B.k_m++) {
      tune_B.qtd_b[tune_B.rankA_e] += tune_B.Q_m[(tune_B.rankA_e << 3) +
        tune_B.k_m] * d[tune_B.k_m];
    }
  }

  if (tune_B.ncols_o >= 8.0) {
    tune_B.ncols_o = 8.0;
  }

  tune_B.rankA_e = (int32_T)tune_B.ncols_o - 1;
  tune_B.z_m3[0] = 0.0;
  tune_B.z_m3[1] = 0.0;
  tune_B.z_m3[2] = 0.0;
  tune_B.z_m3[3] = 0.0;
  tune_B.k_m = 0;
  while (tune_B.k_m <= tune_B.rankA_e) {
    tune_B.z_m3[tune_B.jpvt_o[tune_B.k_m] - 1] = tune_B.qtd_b[tune_B.k_m];
    tune_B.k_m++;
  }

  tune_B.k_m = 0;
  while (tune_B.k_m <= tune_B.rankA_e) {
    tune_B.j_m = tune_B.rankA_e - tune_B.k_m;
    tune_B.z_tmp_f = tune_B.j_m << 3;
    tune_B.z_m3[tune_B.jpvt_o[tune_B.j_m] - 1] /= tune_B.A_g[tune_B.z_tmp_f +
      tune_B.j_m];
    tune_B.b_i_j = 0;
    while (tune_B.b_i_j <= tune_B.j_m - 1) {
      tune_B.z_m3[tune_B.jpvt_o[tune_B.b_i_j] - 1] -= tune_B.A_g[tune_B.z_tmp_f
        + tune_B.b_i_j] * tune_B.z_m3[tune_B.jpvt_o[tune_B.j_m] - 1];
      tune_B.b_i_j++;
    }

    tune_B.k_m++;
  }

  tune_B.rankA_e = 1;
  if (p[0]) {
    Z[0] = tune_B.z_m3[0];
    tune_B.rankA_e = 2;
  }

  if (p[1]) {
    Z[1] = tune_B.z_m3[tune_B.rankA_e - 1];
    tune_B.rankA_e++;
  }

  if (p[2]) {
    Z[2] = tune_B.z_m3[tune_B.rankA_e - 1];
    tune_B.rankA_e++;
  }

  if (p[3]) {
    Z[3] = tune_B.z_m3[tune_B.rankA_e - 1];
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_computeAlpha_l(const real_T x[4], const real_T z[4], const
  boolean_T Q[4])
{
  real_T result;
  boolean_T exitg1;
  tune_B.b_x_c[0] = 1.7976931348623157E+308;
  tune_B.b_x_c[1] = 1.7976931348623157E+308;
  tune_B.b_x_c[2] = 1.7976931348623157E+308;
  tune_B.b_x_c[3] = 1.7976931348623157E+308;
  if (Q[0]) {
    tune_B.b_x_c[0] = x[0] / (x[0] - z[0]);
  }

  if (Q[1]) {
    tune_B.b_x_c[1] = x[1] / (x[1] - z[1]);
  }

  if (Q[2]) {
    tune_B.b_x_c[2] = x[2] / (x[2] - z[2]);
  }

  if (Q[3]) {
    tune_B.b_x_c[3] = x[3] / (x[3] - z[3]);
  }

  if (!rtIsNaN(tune_B.b_x_c[0])) {
    tune_B.idx = 1;
  } else {
    tune_B.idx = 0;
    tune_B.k_gs = 2;
    exitg1 = false;
    while ((!exitg1) && (tune_B.k_gs <= 4)) {
      if (!rtIsNaN(tune_B.b_x_c[tune_B.k_gs - 1])) {
        tune_B.idx = tune_B.k_gs;
        exitg1 = true;
      } else {
        tune_B.k_gs++;
      }
    }
  }

  if (tune_B.idx == 0) {
    result = tune_B.b_x_c[0];
  } else {
    result = tune_B.b_x_c[tune_B.idx - 1];
    while (tune_B.idx + 1 <= 4) {
      if (result > tune_B.b_x_c[tune_B.idx]) {
        result = tune_B.b_x_c[tune_B.idx];
      }

      tune_B.idx++;
    }
  }

  return result;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_utilLSQFixedSizeData_mb(const real_T C[32], const real_T d[8],
  real_T x[4])
{
  static const int32_T tmp = 4;
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  tune_B.tol_f = 2.2204460492503131E-15 * tune_norm_e(C) * 8.0;
  tune_B.wz_m[0] = 0.0;
  tune_B.P_f[0] = false;
  tune_B.Z_h[0] = true;
  x[0] = 0.0;
  tune_B.wz_m[1] = 0.0;
  tune_B.P_f[1] = false;
  tune_B.Z_h[1] = true;
  x[1] = 0.0;
  tune_B.wz_m[2] = 0.0;
  tune_B.P_f[2] = false;
  tune_B.Z_h[2] = true;
  x[2] = 0.0;
  tune_B.wz_m[3] = 0.0;
  tune_B.P_f[3] = false;
  tune_B.Z_h[3] = true;
  x[3] = 0.0;
  for (tune_B.b_ct = 0; tune_B.b_ct < 8; tune_B.b_ct++) {
    tune_B.C_p = C[tune_B.b_ct];
    tune_B.w_tmp_tmp = tune_B.b_ct << 2;
    tune_B.w_tmp_g[tune_B.w_tmp_tmp] = tune_B.C_p;
    tune_B.x_e = tune_B.C_p * 0.0;
    tune_B.C_p = C[tune_B.b_ct + 8];
    tune_B.w_tmp_g[tune_B.w_tmp_tmp + 1] = tune_B.C_p;
    tune_B.x_e += tune_B.C_p * 0.0;
    tune_B.C_p = C[tune_B.b_ct + 16];
    tune_B.w_tmp_g[tune_B.w_tmp_tmp + 2] = tune_B.C_p;
    tune_B.x_e += tune_B.C_p * 0.0;
    tune_B.C_p = C[tune_B.b_ct + 24];
    tune_B.w_tmp_g[tune_B.w_tmp_tmp + 3] = tune_B.C_p;
    tune_B.d_o[tune_B.b_ct] = d[tune_B.b_ct] - (tune_B.C_p * 0.0 + tune_B.x_e);
  }

  for (tune_B.b_ct = 0; tune_B.b_ct < 4; tune_B.b_ct++) {
    tune_B.w_c[tune_B.b_ct] = 0.0;
    for (tune_B.w_tmp_tmp = 0; tune_B.w_tmp_tmp < 8; tune_B.w_tmp_tmp++) {
      tune_B.w_c[tune_B.b_ct] += tune_B.w_tmp_g[(tune_B.w_tmp_tmp << 2) +
        tune_B.b_ct] * tune_B.d_o[tune_B.w_tmp_tmp];
    }
  }

  tune_B.iter_j = 0;
  exitg2 = false;
  while ((!exitg2) && tune_vectorAny(tune_B.Z_h, &tmp)) {
    tune_B.found_k = false;
    tune_B.b_ct = 1;
    exitg3 = false;
    while ((!exitg3) && (tune_B.b_ct - 1 < 4)) {
      if (tune_B.Z_h[(int16_T)tune_B.b_ct - 1] && (tune_B.w_c[(int16_T)
           tune_B.b_ct - 1] > tune_B.tol_f)) {
        tune_B.found_k = true;
        exitg3 = true;
      } else {
        tune_B.b_ct++;
      }
    }

    if (tune_B.found_k) {
      if (tune_B.P_f[0]) {
        tune_B.wz_m[0] = -1.7976931348623157E+308;
      }

      if (tune_B.Z_h[0]) {
        tune_B.wz_m[0] = tune_B.w_c[0];
      }

      tune_B.z_m[0] = 0.0;
      if (tune_B.P_f[1]) {
        tune_B.wz_m[1] = -1.7976931348623157E+308;
      }

      if (tune_B.Z_h[1]) {
        tune_B.wz_m[1] = tune_B.w_c[1];
      }

      tune_B.z_m[1] = 0.0;
      if (tune_B.P_f[2]) {
        tune_B.wz_m[2] = -1.7976931348623157E+308;
      }

      if (tune_B.Z_h[2]) {
        tune_B.wz_m[2] = tune_B.w_c[2];
      }

      tune_B.z_m[2] = 0.0;
      if (tune_B.P_f[3]) {
        tune_B.wz_m[3] = -1.7976931348623157E+308;
      }

      if (tune_B.Z_h[3]) {
        tune_B.wz_m[3] = tune_B.w_c[3];
      }

      tune_B.z_m[3] = 0.0;
      tune_maximum_bt(tune_B.wz_m, &tune_B.C_p, &tune_B.b_ct);
      tune_B.P_f[tune_B.b_ct - 1] = true;
      tune_B.Z_h[tune_B.b_ct - 1] = false;
      tune_computeZ_ni(tune_B.z_m, C, d, tune_B.P_f);
      do {
        exitg1 = 0;
        tune_B.found_k = false;
        tune_B.b_ct = 1;
        exitg3 = false;
        while ((!exitg3) && (tune_B.b_ct - 1 < 4)) {
          if (tune_B.P_f[(int16_T)tune_B.b_ct - 1] && (tune_B.z_m[(int16_T)
               tune_B.b_ct - 1] <= 0.0)) {
            tune_B.found_k = true;
            exitg3 = true;
          } else {
            tune_B.b_ct++;
          }
        }

        if (tune_B.found_k) {
          tune_B.iter_j++;
          if (tune_B.iter_j > 12) {
            x[0] = tune_B.z_m[0];
            x[1] = tune_B.z_m[1];
            x[2] = tune_B.z_m[2];
            x[3] = tune_B.z_m[3];
            exitg1 = 1;
          } else {
            tune_B.z_m4[0] = ((tune_B.z_m[0] <= 0.0) && tune_B.P_f[0]);
            tune_B.z_m4[1] = ((tune_B.z_m[1] <= 0.0) && tune_B.P_f[1]);
            tune_B.z_m4[2] = ((tune_B.z_m[2] <= 0.0) && tune_B.P_f[2]);
            tune_B.z_m4[3] = ((tune_B.z_m[3] <= 0.0) && tune_B.P_f[3]);
            tune_B.C_p = tune_computeAlpha_l(x, tune_B.z_m, tune_B.z_m4);
            tune_B.x_e = (tune_B.z_m[0] - x[0]) * tune_B.C_p + x[0];
            tune_B.found_k = (((fabs(tune_B.x_e) < tune_B.tol_f) && tune_B.P_f[0])
                              || tune_B.Z_h[0]);
            x[0] = tune_B.x_e;
            tune_B.z_m[0] = 0.0;
            tune_B.P_f[0] = !tune_B.found_k;
            tune_B.Z_h[0] = tune_B.found_k;
            tune_B.x_e = (tune_B.z_m[1] - x[1]) * tune_B.C_p + x[1];
            tune_B.found_k = (((fabs(tune_B.x_e) < tune_B.tol_f) && tune_B.P_f[1])
                              || tune_B.Z_h[1]);
            x[1] = tune_B.x_e;
            tune_B.z_m[1] = 0.0;
            tune_B.P_f[1] = !tune_B.found_k;
            tune_B.Z_h[1] = tune_B.found_k;
            tune_B.x_e = (tune_B.z_m[2] - x[2]) * tune_B.C_p + x[2];
            tune_B.found_k = (((fabs(tune_B.x_e) < tune_B.tol_f) && tune_B.P_f[2])
                              || tune_B.Z_h[2]);
            x[2] = tune_B.x_e;
            tune_B.z_m[2] = 0.0;
            tune_B.P_f[2] = !tune_B.found_k;
            tune_B.Z_h[2] = tune_B.found_k;
            tune_B.x_e = (tune_B.z_m[3] - x[3]) * tune_B.C_p + x[3];
            tune_B.found_k = (((fabs(tune_B.x_e) < tune_B.tol_f) && tune_B.P_f[3])
                              || tune_B.Z_h[3]);
            x[3] = tune_B.x_e;
            tune_B.z_m[3] = 0.0;
            tune_B.P_f[3] = !tune_B.found_k;
            tune_B.Z_h[3] = tune_B.found_k;
            tune_computeZ_ni(tune_B.z_m, C, d, tune_B.P_f);
          }
        } else {
          x[0] = tune_B.z_m[0];
          x[1] = tune_B.z_m[1];
          x[2] = tune_B.z_m[2];
          x[3] = tune_B.z_m[3];
          for (tune_B.b_ct = 0; tune_B.b_ct < 8; tune_B.b_ct++) {
            tune_B.d_o[tune_B.b_ct] = d[tune_B.b_ct] - (((C[tune_B.b_ct + 8] *
              tune_B.z_m[1] + C[tune_B.b_ct] * tune_B.z_m[0]) + C[tune_B.b_ct +
              16] * tune_B.z_m[2]) + C[tune_B.b_ct + 24] * tune_B.z_m[3]);
          }

          for (tune_B.b_ct = 0; tune_B.b_ct < 4; tune_B.b_ct++) {
            tune_B.w_c[tune_B.b_ct] = 0.0;
            for (tune_B.w_tmp_tmp = 0; tune_B.w_tmp_tmp < 8; tune_B.w_tmp_tmp++)
            {
              tune_B.w_c[tune_B.b_ct] += tune_B.w_tmp_g[(tune_B.w_tmp_tmp << 2)
                + tune_B.b_ct] * tune_B.d_o[tune_B.w_tmp_tmp];
            }
          }

          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    } else {
      exitg2 = true;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_logspace_d(real_T d1, real_T d2, real_T y[20])
{
  tune_B.b_y_d[19] = d2;
  tune_B.b_y_d[0] = d1;
  if (d1 == -d2) {
    tune_B.delta1_a = d2 / 19.0;
    for (tune_B.c_k_n = 0; tune_B.c_k_n < 18; tune_B.c_k_n++) {
      tune_B.b_y_d[tune_B.c_k_n + 1] = (((real_T)tune_B.c_k_n + 2.0) * 2.0 -
        21.0) * tune_B.delta1_a;
    }
  } else if (((d1 < 0.0) != (d2 < 0.0)) && ((fabs(d1) > 8.9884656743115785E+307)
              || (fabs(d2) > 8.9884656743115785E+307))) {
    tune_B.delta1_a = d1 / 19.0;
    tune_B.delta2_d = d2 / 19.0;
    for (tune_B.c_k_n = 0; tune_B.c_k_n < 18; tune_B.c_k_n++) {
      tune_B.b_y_d[tune_B.c_k_n + 1] = (((real_T)tune_B.c_k_n + 1.0) *
        tune_B.delta2_d + d1) - ((real_T)tune_B.c_k_n + 1.0) * tune_B.delta1_a;
    }
  } else {
    tune_B.delta1_a = (d2 - d1) / 19.0;
    for (tune_B.c_k_n = 0; tune_B.c_k_n < 18; tune_B.c_k_n++) {
      tune_B.b_y_d[tune_B.c_k_n + 1] = ((real_T)tune_B.c_k_n + 1.0) *
        tune_B.delta1_a + d1;
    }
  }

  for (tune_B.c_k_n = 0; tune_B.c_k_n < 20; tune_B.c_k_n++) {
    y[tune_B.c_k_n] = tune_rt_powd_snf(10.0, tune_B.b_y_d[tune_B.c_k_n]);
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_computeTAU(boolean_T IsDiscrete, const real_T w3[3], real_T Ts,
  uint16_T DF, real_T tau[20])
{
  if (IsDiscrete && (DF == 1)) {
    tune_B.u1_tmp = 1.99 / Ts;
    tune_B.u0 = w3[2] * 10.0;
    tune_B.b_bn = rtIsNaN(tune_B.u1_tmp);
    if ((w3[2] <= tune_B.u1_tmp) || tune_B.b_bn) {
      tune_B.w3 = w3[2];
    } else {
      tune_B.w3 = tune_B.u1_tmp;
    }

    if ((tune_B.u0 <= tune_B.u1_tmp) || tune_B.b_bn) {
      tune_B.u1_tmp = tune_B.u0;
    }

    tune_logspace_d(log10(tune_B.w3), log10(tune_B.u1_tmp), tune_B.dv1);
    for (tune_B.i5 = 0; tune_B.i5 < 20; tune_B.i5++) {
      tau[tune_B.i5] = 1.0 / tune_B.dv1[tune_B.i5];
    }
  } else {
    tune_logspace_d(log10(w3[2]), log10(w3[2] * 10.0), tune_B.dv1);
    for (tune_B.i5 = 0; tune_B.i5 < 20; tune_B.i5++) {
      tau[tune_B.i5] = 1.0 / tune_B.dv1[tune_B.i5];
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_abs_lb(const creal_T x[50], real_T y[50])
{
  for (tune_B.k_f = 0; tune_B.k_f < 50; tune_B.k_f++) {
    y[tune_B.k_f] = tune_rt_hypotd_snf(x[tune_B.k_f].re, x[tune_B.k_f].im);
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_utilLSQFixedSizeData_mbll(const real_T C[21], const real_T d[7],
  real_T x[3], real_T *resnorm)
{
  static const int32_T tmp = 3;
  int32_T exitg1;
  int32_T exitg2;
  boolean_T exitg3;
  boolean_T guard1 = false;
  tune_B.tol_af = 2.2204460492503131E-15 * tune_norm(C) * 7.0;
  tune_B.wz_a[0] = 0.0;
  tune_B.P_l[0] = false;
  tune_B.Z_l[0] = true;
  x[0] = 0.0;
  tune_B.wz_a[1] = 0.0;
  tune_B.P_l[1] = false;
  tune_B.Z_l[1] = true;
  x[1] = 0.0;
  tune_B.wz_a[2] = 0.0;
  tune_B.P_l[2] = false;
  tune_B.Z_l[2] = true;
  x[2] = 0.0;
  for (tune_B.b_ct_l = 0; tune_B.b_ct_l < 7; tune_B.b_ct_l++) {
    tune_B.C_pb = C[tune_B.b_ct_l];
    tune_B.x_m = tune_B.C_pb * 0.0;
    tune_B.w_tmp_j[3 * tune_B.b_ct_l] = tune_B.C_pb;
    tune_B.C_pb = C[tune_B.b_ct_l + 7];
    tune_B.x_m += tune_B.C_pb * 0.0;
    tune_B.w_tmp_j[3 * tune_B.b_ct_l + 1] = tune_B.C_pb;
    tune_B.C_pb = C[tune_B.b_ct_l + 14];
    tune_B.w_tmp_j[3 * tune_B.b_ct_l + 2] = tune_B.C_pb;
    tune_B.resid_a[tune_B.b_ct_l] = d[tune_B.b_ct_l] - (tune_B.C_pb * 0.0 +
      tune_B.x_m);
  }

  for (tune_B.b_ct_l = 0; tune_B.b_ct_l < 3; tune_B.b_ct_l++) {
    tune_B.w_if[tune_B.b_ct_l] = 0.0;
    for (tune_B.i6 = 0; tune_B.i6 < 7; tune_B.i6++) {
      tune_B.w_if[tune_B.b_ct_l] += tune_B.w_tmp_j[3 * tune_B.i6 + tune_B.b_ct_l]
        * tune_B.resid_a[tune_B.i6];
    }
  }

  tune_B.iter_n = 0;
  guard1 = false;
  do {
    exitg2 = 0;
    if (tune_vectorAny(tune_B.Z_l, &tmp)) {
      tune_B.found_h = false;
      tune_B.b_ct_l = 1;
      exitg3 = false;
      while ((!exitg3) && (tune_B.b_ct_l - 1 < 3)) {
        if (tune_B.Z_l[(int16_T)tune_B.b_ct_l - 1] && (tune_B.w_if[(int16_T)
             tune_B.b_ct_l - 1] > tune_B.tol_af)) {
          tune_B.found_h = true;
          exitg3 = true;
        } else {
          tune_B.b_ct_l++;
        }
      }

      if (tune_B.found_h) {
        if (tune_B.P_l[0]) {
          tune_B.wz_a[0] = -1.7976931348623157E+308;
        }

        if (tune_B.Z_l[0]) {
          tune_B.wz_a[0] = tune_B.w_if[0];
        }

        if (tune_B.P_l[1]) {
          tune_B.wz_a[1] = -1.7976931348623157E+308;
        }

        if (tune_B.Z_l[1]) {
          tune_B.wz_a[1] = tune_B.w_if[1];
        }

        if (tune_B.P_l[2]) {
          tune_B.wz_a[2] = -1.7976931348623157E+308;
        }

        if (tune_B.Z_l[2]) {
          tune_B.wz_a[2] = tune_B.w_if[2];
        }

        tune_maximum(tune_B.wz_a, &tune_B.C_pb, &tune_B.b_ct_l);
        tune_B.P_l[tune_B.b_ct_l - 1] = true;
        tune_B.Z_l[tune_B.b_ct_l - 1] = false;
        tune_B.w_if[0] = 0.0;
        tune_B.w_if[1] = 0.0;
        tune_B.w_if[2] = 0.0;
        tune_computeZ_n(tune_B.w_if, C, d, tune_B.P_l);
        do {
          exitg1 = 0;
          tune_B.found_h = false;
          tune_B.b_ct_l = 1;
          exitg3 = false;
          while ((!exitg3) && (tune_B.b_ct_l - 1 < 3)) {
            if (tune_B.P_l[(int16_T)tune_B.b_ct_l - 1] && (tune_B.w_if[(int16_T)
                 tune_B.b_ct_l - 1] <= 0.0)) {
              tune_B.found_h = true;
              exitg3 = true;
            } else {
              tune_B.b_ct_l++;
            }
          }

          if (tune_B.found_h) {
            tune_B.iter_n++;
            if (tune_B.iter_n > 9) {
              for (tune_B.b_ct_l = 0; tune_B.b_ct_l < 7; tune_B.b_ct_l++) {
                tune_B.tol_af = tune_B.resid_a[tune_B.b_ct_l];
                tune_B.resid_a[tune_B.b_ct_l] = tune_B.tol_af * tune_B.tol_af;
              }

              *resnorm = tune_B.resid_a[0];
              for (tune_B.b_ct_l = 0; tune_B.b_ct_l < 6; tune_B.b_ct_l++) {
                *resnorm += tune_B.resid_a[tune_B.b_ct_l + 1];
              }

              x[0] = tune_B.w_if[0];
              x[1] = tune_B.w_if[1];
              x[2] = tune_B.w_if[2];
              exitg1 = 1;
            } else {
              tune_B.w_g[0] = ((tune_B.w_if[0] <= 0.0) && tune_B.P_l[0]);
              tune_B.w_g[1] = ((tune_B.w_if[1] <= 0.0) && tune_B.P_l[1]);
              tune_B.w_g[2] = ((tune_B.w_if[2] <= 0.0) && tune_B.P_l[2]);
              tune_B.C_pb = tune_computeAlpha(x, tune_B.w_if, tune_B.w_g);
              tune_B.x_m = (tune_B.w_if[0] - x[0]) * tune_B.C_pb + x[0];
              tune_B.found_h = (((fabs(tune_B.x_m) < tune_B.tol_af) &&
                                 tune_B.P_l[0]) || tune_B.Z_l[0]);
              x[0] = tune_B.x_m;
              tune_B.w_if[0] = 0.0;
              tune_B.P_l[0] = !tune_B.found_h;
              tune_B.Z_l[0] = tune_B.found_h;
              tune_B.x_m = (tune_B.w_if[1] - x[1]) * tune_B.C_pb + x[1];
              tune_B.found_h = (((fabs(tune_B.x_m) < tune_B.tol_af) &&
                                 tune_B.P_l[1]) || tune_B.Z_l[1]);
              x[1] = tune_B.x_m;
              tune_B.w_if[1] = 0.0;
              tune_B.P_l[1] = !tune_B.found_h;
              tune_B.Z_l[1] = tune_B.found_h;
              tune_B.x_m = (tune_B.w_if[2] - x[2]) * tune_B.C_pb + x[2];
              tune_B.found_h = (((fabs(tune_B.x_m) < tune_B.tol_af) &&
                                 tune_B.P_l[2]) || tune_B.Z_l[2]);
              x[2] = tune_B.x_m;
              tune_B.w_if[2] = 0.0;
              tune_B.P_l[2] = !tune_B.found_h;
              tune_B.Z_l[2] = tune_B.found_h;
              tune_computeZ_n(tune_B.w_if, C, d, tune_B.P_l);
            }
          } else {
            x[0] = tune_B.w_if[0];
            x[1] = tune_B.w_if[1];
            x[2] = tune_B.w_if[2];
            for (tune_B.b_ct_l = 0; tune_B.b_ct_l < 7; tune_B.b_ct_l++) {
              tune_B.resid_a[tune_B.b_ct_l] = d[tune_B.b_ct_l] -
                ((C[tune_B.b_ct_l + 7] * tune_B.w_if[1] + C[tune_B.b_ct_l] *
                  tune_B.w_if[0]) + C[tune_B.b_ct_l + 14] * tune_B.w_if[2]);
            }

            for (tune_B.b_ct_l = 0; tune_B.b_ct_l < 3; tune_B.b_ct_l++) {
              tune_B.w_if[tune_B.b_ct_l] = 0.0;
              for (tune_B.i6 = 0; tune_B.i6 < 7; tune_B.i6++) {
                tune_B.w_if[tune_B.b_ct_l] += tune_B.w_tmp_j[3 * tune_B.i6 +
                  tune_B.b_ct_l] * tune_B.resid_a[tune_B.i6];
              }
            }

            guard1 = false;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = 1;
        }
      } else {
        guard1 = true;
        exitg2 = 1;
      }
    } else {
      guard1 = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (guard1) {
    *resnorm = 0.0;
    for (tune_B.b_ct_l = 0; tune_B.b_ct_l < 7; tune_B.b_ct_l++) {
      tune_B.tol_af = tune_B.resid_a[tune_B.b_ct_l];
      *resnorm += tune_B.tol_af * tune_B.tol_af;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_maximum_bt0(const real_T x[20])
{
  real_T ex;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    tune_B.idx_n = 1;
  } else {
    tune_B.idx_n = 0;
    tune_B.k_i = 2;
    exitg1 = false;
    while ((!exitg1) && (tune_B.k_i <= 20)) {
      if (!rtIsNaN(x[tune_B.k_i - 1])) {
        tune_B.idx_n = tune_B.k_i;
        exitg1 = true;
      } else {
        tune_B.k_i++;
      }
    }
  }

  if (tune_B.idx_n == 0) {
    ex = x[0];
  } else {
    ex = x[tune_B.idx_n - 1];
    while (tune_B.idx_n + 1 < 21) {
      if (ex < x[tune_B.idx_n]) {
        ex = x[tune_B.idx_n];
      }

      tune_B.idx_n++;
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_minimum_n(const real_T x[20])
{
  real_T ex;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    tune_B.idx_c = 1;
  } else {
    tune_B.idx_c = 0;
    tune_B.k_fq = 2;
    exitg1 = false;
    while ((!exitg1) && (tune_B.k_fq <= 20)) {
      if (!rtIsNaN(x[tune_B.k_fq - 1])) {
        tune_B.idx_c = tune_B.k_fq;
        exitg1 = true;
      } else {
        tune_B.k_fq++;
      }
    }
  }

  if (tune_B.idx_c == 0) {
    ex = x[0];
  } else {
    ex = x[tune_B.idx_c - 1];
    while (tune_B.idx_c + 1 <= 20) {
      if (ex > x[tune_B.idx_c]) {
        ex = x[tune_B.idx_c];
      }

      tune_B.idx_c++;
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_mean(const real_T x[20])
{
  tune_B.b_y_i = x[0];
  for (tune_B.k_jk = 0; tune_B.k_jk < 19; tune_B.k_jk++) {
    tune_B.b_y_i += x[tune_B.k_jk + 1];
  }

  return tune_B.b_y_i / 20.0;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_minimum_nv(const real_T x[20], real_T *ex, int32_T *idx)
{
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    *idx = 1;
  } else {
    *idx = 0;
    tune_B.k_a = 2;
    exitg1 = false;
    while ((!exitg1) && (tune_B.k_a < 21)) {
      if (!rtIsNaN(x[tune_B.k_a - 1])) {
        *idx = tune_B.k_a;
        exitg1 = true;
      } else {
        tune_B.k_a++;
      }
    }
  }

  if (*idx == 0) {
    *ex = x[0];
    *idx = 1;
  } else {
    *ex = x[*idx - 1];
    tune_B.k_a = *idx;
    while (tune_B.k_a + 1 < 21) {
      if (*ex > x[tune_B.k_a]) {
        *ex = x[tune_B.k_a];
        *idx = tune_B.k_a + 1;
      }

      tune_B.k_a++;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_utilLSQFixedSizeData_mbl(const real_T C[32], const real_T d[8],
  real_T x[4], real_T *resnorm)
{
  static const int32_T tmp = 4;
  int32_T exitg1;
  int32_T exitg2;
  boolean_T exitg3;
  boolean_T guard1 = false;
  tune_B.tol_fi = 2.2204460492503131E-15 * tune_norm_e(C) * 8.0;
  tune_B.wz_j[0] = 0.0;
  tune_B.P_a[0] = false;
  tune_B.Z_k[0] = true;
  x[0] = 0.0;
  tune_B.wz_j[1] = 0.0;
  tune_B.P_a[1] = false;
  tune_B.Z_k[1] = true;
  x[1] = 0.0;
  tune_B.wz_j[2] = 0.0;
  tune_B.P_a[2] = false;
  tune_B.Z_k[2] = true;
  x[2] = 0.0;
  tune_B.wz_j[3] = 0.0;
  tune_B.P_a[3] = false;
  tune_B.Z_k[3] = true;
  x[3] = 0.0;
  for (tune_B.b_ct_d = 0; tune_B.b_ct_d < 8; tune_B.b_ct_d++) {
    tune_B.C_h = C[tune_B.b_ct_d];
    tune_B.x_ei = tune_B.C_h * 0.0;
    tune_B.w_tmp_tmp_i = tune_B.b_ct_d << 2;
    tune_B.w_tmp_m[tune_B.w_tmp_tmp_i] = tune_B.C_h;
    tune_B.C_h = C[tune_B.b_ct_d + 8];
    tune_B.x_ei += tune_B.C_h * 0.0;
    tune_B.w_tmp_m[tune_B.w_tmp_tmp_i + 1] = tune_B.C_h;
    tune_B.C_h = C[tune_B.b_ct_d + 16];
    tune_B.x_ei += tune_B.C_h * 0.0;
    tune_B.w_tmp_m[tune_B.w_tmp_tmp_i + 2] = tune_B.C_h;
    tune_B.C_h = C[tune_B.b_ct_d + 24];
    tune_B.w_tmp_m[tune_B.w_tmp_tmp_i + 3] = tune_B.C_h;
    tune_B.resid_b[tune_B.b_ct_d] = d[tune_B.b_ct_d] - (tune_B.C_h * 0.0 +
      tune_B.x_ei);
  }

  for (tune_B.b_ct_d = 0; tune_B.b_ct_d < 4; tune_B.b_ct_d++) {
    tune_B.w_h[tune_B.b_ct_d] = 0.0;
    for (tune_B.w_tmp_tmp_i = 0; tune_B.w_tmp_tmp_i < 8; tune_B.w_tmp_tmp_i++) {
      tune_B.w_h[tune_B.b_ct_d] += tune_B.w_tmp_m[(tune_B.w_tmp_tmp_i << 2) +
        tune_B.b_ct_d] * tune_B.resid_b[tune_B.w_tmp_tmp_i];
    }
  }

  tune_B.iter_c = 0;
  guard1 = false;
  do {
    exitg2 = 0;
    if (tune_vectorAny(tune_B.Z_k, &tmp)) {
      tune_B.found_kl = false;
      tune_B.b_ct_d = 1;
      exitg3 = false;
      while ((!exitg3) && (tune_B.b_ct_d - 1 < 4)) {
        if (tune_B.Z_k[(int16_T)tune_B.b_ct_d - 1] && (tune_B.w_h[(int16_T)
             tune_B.b_ct_d - 1] > tune_B.tol_fi)) {
          tune_B.found_kl = true;
          exitg3 = true;
        } else {
          tune_B.b_ct_d++;
        }
      }

      if (tune_B.found_kl) {
        if (tune_B.P_a[0]) {
          tune_B.wz_j[0] = -1.7976931348623157E+308;
        }

        if (tune_B.Z_k[0]) {
          tune_B.wz_j[0] = tune_B.w_h[0];
        }

        if (tune_B.P_a[1]) {
          tune_B.wz_j[1] = -1.7976931348623157E+308;
        }

        if (tune_B.Z_k[1]) {
          tune_B.wz_j[1] = tune_B.w_h[1];
        }

        if (tune_B.P_a[2]) {
          tune_B.wz_j[2] = -1.7976931348623157E+308;
        }

        if (tune_B.Z_k[2]) {
          tune_B.wz_j[2] = tune_B.w_h[2];
        }

        if (tune_B.P_a[3]) {
          tune_B.wz_j[3] = -1.7976931348623157E+308;
        }

        if (tune_B.Z_k[3]) {
          tune_B.wz_j[3] = tune_B.w_h[3];
        }

        tune_maximum_bt(tune_B.wz_j, &tune_B.C_h, &tune_B.b_ct_d);
        tune_B.P_a[tune_B.b_ct_d - 1] = true;
        tune_B.Z_k[tune_B.b_ct_d - 1] = false;
        tune_B.w_h[0] = 0.0;
        tune_B.w_h[1] = 0.0;
        tune_B.w_h[2] = 0.0;
        tune_B.w_h[3] = 0.0;
        tune_computeZ_ni(tune_B.w_h, C, d, tune_B.P_a);
        do {
          exitg1 = 0;
          tune_B.found_kl = false;
          tune_B.b_ct_d = 1;
          exitg3 = false;
          while ((!exitg3) && (tune_B.b_ct_d - 1 < 4)) {
            if (tune_B.P_a[(int16_T)tune_B.b_ct_d - 1] && (tune_B.w_h[(int16_T)
                 tune_B.b_ct_d - 1] <= 0.0)) {
              tune_B.found_kl = true;
              exitg3 = true;
            } else {
              tune_B.b_ct_d++;
            }
          }

          if (tune_B.found_kl) {
            tune_B.iter_c++;
            if (tune_B.iter_c > 12) {
              for (tune_B.b_ct_d = 0; tune_B.b_ct_d < 8; tune_B.b_ct_d++) {
                tune_B.tol_fi = tune_B.resid_b[tune_B.b_ct_d];
                tune_B.resid_b[tune_B.b_ct_d] = tune_B.tol_fi * tune_B.tol_fi;
              }

              *resnorm = tune_B.resid_b[0];
              for (tune_B.b_ct_d = 0; tune_B.b_ct_d < 7; tune_B.b_ct_d++) {
                *resnorm += tune_B.resid_b[tune_B.b_ct_d + 1];
              }

              x[0] = tune_B.w_h[0];
              x[1] = tune_B.w_h[1];
              x[2] = tune_B.w_h[2];
              x[3] = tune_B.w_h[3];
              exitg1 = 1;
            } else {
              tune_B.w_p[0] = ((tune_B.w_h[0] <= 0.0) && tune_B.P_a[0]);
              tune_B.w_p[1] = ((tune_B.w_h[1] <= 0.0) && tune_B.P_a[1]);
              tune_B.w_p[2] = ((tune_B.w_h[2] <= 0.0) && tune_B.P_a[2]);
              tune_B.w_p[3] = ((tune_B.w_h[3] <= 0.0) && tune_B.P_a[3]);
              tune_B.C_h = tune_computeAlpha_l(x, tune_B.w_h, tune_B.w_p);
              tune_B.x_ei = (tune_B.w_h[0] - x[0]) * tune_B.C_h + x[0];
              tune_B.found_kl = (((fabs(tune_B.x_ei) < tune_B.tol_fi) &&
                                  tune_B.P_a[0]) || tune_B.Z_k[0]);
              x[0] = tune_B.x_ei;
              tune_B.w_h[0] = 0.0;
              tune_B.P_a[0] = !tune_B.found_kl;
              tune_B.Z_k[0] = tune_B.found_kl;
              tune_B.x_ei = (tune_B.w_h[1] - x[1]) * tune_B.C_h + x[1];
              tune_B.found_kl = (((fabs(tune_B.x_ei) < tune_B.tol_fi) &&
                                  tune_B.P_a[1]) || tune_B.Z_k[1]);
              x[1] = tune_B.x_ei;
              tune_B.w_h[1] = 0.0;
              tune_B.P_a[1] = !tune_B.found_kl;
              tune_B.Z_k[1] = tune_B.found_kl;
              tune_B.x_ei = (tune_B.w_h[2] - x[2]) * tune_B.C_h + x[2];
              tune_B.found_kl = (((fabs(tune_B.x_ei) < tune_B.tol_fi) &&
                                  tune_B.P_a[2]) || tune_B.Z_k[2]);
              x[2] = tune_B.x_ei;
              tune_B.w_h[2] = 0.0;
              tune_B.P_a[2] = !tune_B.found_kl;
              tune_B.Z_k[2] = tune_B.found_kl;
              tune_B.x_ei = (tune_B.w_h[3] - x[3]) * tune_B.C_h + x[3];
              tune_B.found_kl = (((fabs(tune_B.x_ei) < tune_B.tol_fi) &&
                                  tune_B.P_a[3]) || tune_B.Z_k[3]);
              x[3] = tune_B.x_ei;
              tune_B.w_h[3] = 0.0;
              tune_B.P_a[3] = !tune_B.found_kl;
              tune_B.Z_k[3] = tune_B.found_kl;
              tune_computeZ_ni(tune_B.w_h, C, d, tune_B.P_a);
            }
          } else {
            x[0] = tune_B.w_h[0];
            x[1] = tune_B.w_h[1];
            x[2] = tune_B.w_h[2];
            x[3] = tune_B.w_h[3];
            for (tune_B.b_ct_d = 0; tune_B.b_ct_d < 8; tune_B.b_ct_d++) {
              tune_B.resid_b[tune_B.b_ct_d] = d[tune_B.b_ct_d] -
                (((C[tune_B.b_ct_d + 8] * tune_B.w_h[1] + C[tune_B.b_ct_d] *
                   tune_B.w_h[0]) + C[tune_B.b_ct_d + 16] * tune_B.w_h[2]) +
                 C[tune_B.b_ct_d + 24] * tune_B.w_h[3]);
            }

            for (tune_B.b_ct_d = 0; tune_B.b_ct_d < 4; tune_B.b_ct_d++) {
              tune_B.w_h[tune_B.b_ct_d] = 0.0;
              for (tune_B.w_tmp_tmp_i = 0; tune_B.w_tmp_tmp_i < 8;
                   tune_B.w_tmp_tmp_i++) {
                tune_B.w_h[tune_B.b_ct_d] += tune_B.w_tmp_m[(tune_B.w_tmp_tmp_i <<
                  2) + tune_B.b_ct_d] * tune_B.resid_b[tune_B.w_tmp_tmp_i];
              }
            }

            guard1 = false;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = 1;
        }
      } else {
        guard1 = true;
        exitg2 = 1;
      }
    } else {
      guard1 = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (guard1) {
    *resnorm = 0.0;
    for (tune_B.b_ct_d = 0; tune_B.b_ct_d < 8; tune_B.b_ct_d++) {
      tune_B.tol_fi = tune_B.resid_b[tune_B.b_ct_d];
      *resnorm += tune_B.tol_fi * tune_B.tol_fi;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_blkdiag_f0i(const real_T varargin_1[18], real_T y[40])
{
  memset(&y[0], 0, 40U * sizeof(real_T));
  for (tune_B.i7 = 0; tune_B.i7 < 3; tune_B.i7++) {
    for (tune_B.i8 = 0; tune_B.i8 < 6; tune_B.i8++) {
      y[tune_B.i8 + (tune_B.i7 << 3)] = varargin_1[6 * tune_B.i7 + tune_B.i8];
    }
  }

  y[30] = 1.0;
  y[39] = 1.0;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_norm_eb(const real_T x[40])
{
  real_T y;
  boolean_T exitg1;
  y = 0.0;
  tune_B.j_o = 0;
  exitg1 = false;
  while ((!exitg1) && (tune_B.j_o < 5)) {
    tune_B.s_p = 0.0;
    for (tune_B.i_j = 0; tune_B.i_j < 8; tune_B.i_j++) {
      tune_B.s_p += fabs(x[(tune_B.j_o << 3) + tune_B.i_j]);
    }

    if (rtIsNaN(tune_B.s_p)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (tune_B.s_p > y) {
        y = tune_B.s_p;
      }

      tune_B.j_o++;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_maximum_bt0s(const real_T x[5], real_T *ex, int32_T *idx)
{
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    *idx = 1;
  } else {
    *idx = 0;
    tune_B.k_d = 2;
    exitg1 = false;
    while ((!exitg1) && (tune_B.k_d < 6)) {
      if (!rtIsNaN(x[tune_B.k_d - 1])) {
        *idx = tune_B.k_d;
        exitg1 = true;
      } else {
        tune_B.k_d++;
      }
    }
  }

  if (*idx == 0) {
    *ex = x[0];
    *idx = 1;
  } else {
    *ex = x[*idx - 1];
    tune_B.k_d = *idx;
    while (tune_B.k_d + 1 < 6) {
      if (*ex < x[tune_B.k_d]) {
        *ex = x[tune_B.k_d];
        *idx = tune_B.k_d + 1;
      }

      tune_B.k_d++;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_computeZ_ni2(real_T Z[5], const real_T C[40], const real_T d[8],
  const boolean_T p[5])
{
  memset(&tune_B.A[0], 0, 40U * sizeof(real_T));
  tune_B.ncols = 0.0;
  for (tune_B.i_m = 0; tune_B.i_m < 5; tune_B.i_m++) {
    if (p[tune_B.i_m]) {
      tune_B.ncols++;
      for (tune_B.rankA = 0; tune_B.rankA < 8; tune_B.rankA++) {
        tune_B.A[tune_B.rankA + (((int32_T)tune_B.ncols - 1) << 3)] = C
          [(tune_B.i_m << 3) + tune_B.rankA];
      }
    }
  }

  for (tune_B.rankA = 0; tune_B.rankA < 5; tune_B.rankA++) {
    memcpy(&tune_B.Q[tune_B.rankA << 3], &tune_B.A[tune_B.rankA << 3], sizeof
           (real_T) << 3U);
  }

  for (tune_B.rankA = 0; tune_B.rankA < 3; tune_B.rankA++) {
    memset(&tune_B.Q[(tune_B.rankA << 3) + 40], 0, sizeof(real_T) << 3U);
  }

  tune_xgeqp3_g(tune_B.Q, tune_B.qtd, tune_B.jpvt1);
  for (tune_B.rankA = 0; tune_B.rankA < 5; tune_B.rankA++) {
    tune_B.jpvt[tune_B.rankA] = tune_B.jpvt1[tune_B.rankA];
    tune_B.i_m = 0;
    while (tune_B.i_m <= tune_B.rankA) {
      tune_B.A[tune_B.i_m + (tune_B.rankA << 3)] = tune_B.Q[(tune_B.rankA << 3)
        + tune_B.i_m];
      tune_B.i_m++;
    }

    tune_B.i_m = tune_B.rankA + 1;
    while (tune_B.i_m + 1 < 9) {
      tune_B.A[tune_B.i_m + (tune_B.rankA << 3)] = 0.0;
      tune_B.i_m++;
    }
  }

  tune_xorgqr_g(5, tune_B.Q, tune_B.qtd);
  for (tune_B.rankA = 0; tune_B.rankA < 8; tune_B.rankA++) {
    tune_B.qtd[tune_B.rankA] = 0.0;
    for (tune_B.i_m = 0; tune_B.i_m < 8; tune_B.i_m++) {
      tune_B.qtd[tune_B.rankA] += tune_B.Q[(tune_B.rankA << 3) + tune_B.i_m] *
        d[tune_B.i_m];
    }
  }

  if (tune_B.ncols >= 8.0) {
    tune_B.ncols = 8.0;
  }

  tune_B.rankA = (int32_T)tune_B.ncols - 1;
  for (tune_B.i_m = 0; tune_B.i_m < 5; tune_B.i_m++) {
    tune_B.z_o[tune_B.i_m] = 0.0;
  }

  tune_B.i_m = 0;
  while (tune_B.i_m <= tune_B.rankA) {
    tune_B.z_o[tune_B.jpvt[tune_B.i_m] - 1] = tune_B.qtd[tune_B.i_m];
    tune_B.i_m++;
  }

  tune_B.i_m = 0;
  while (tune_B.i_m <= tune_B.rankA) {
    tune_B.j_i = tune_B.rankA - tune_B.i_m;
    tune_B.z_tmp = tune_B.j_i << 3;
    tune_B.z_o[tune_B.jpvt[tune_B.j_i] - 1] /= tune_B.A[tune_B.z_tmp +
      tune_B.j_i];
    tune_B.b_i = 0;
    while (tune_B.b_i <= tune_B.j_i - 1) {
      tune_B.z_o[tune_B.jpvt[tune_B.b_i] - 1] -= tune_B.A[tune_B.z_tmp +
        tune_B.b_i] * tune_B.z_o[tune_B.jpvt[tune_B.j_i] - 1];
      tune_B.b_i++;
    }

    tune_B.i_m++;
  }

  tune_B.ncols = 1.0;
  for (tune_B.rankA = 0; tune_B.rankA < 5; tune_B.rankA++) {
    if (p[tune_B.rankA]) {
      Z[tune_B.rankA] = tune_B.z_o[(int32_T)tune_B.ncols - 1];
      tune_B.ncols++;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static real_T tune_computeAlpha_lk(const real_T x[5], const real_T z[5], const
  boolean_T Q[5])
{
  real_T result;
  boolean_T exitg1;
  for (tune_B.ct = 0; tune_B.ct < 5; tune_B.ct++) {
    tune_B.x_ex = x[tune_B.ct];
    tune_B.b_x[tune_B.ct] = 1.7976931348623157E+308;
    if (Q[tune_B.ct]) {
      tune_B.b_x[tune_B.ct] = tune_B.x_ex / (tune_B.x_ex - z[tune_B.ct]);
    }
  }

  if (!rtIsNaN(tune_B.b_x[0])) {
    tune_B.ct = 1;
  } else {
    tune_B.ct = 0;
    tune_B.k_e = 2;
    exitg1 = false;
    while ((!exitg1) && (tune_B.k_e <= 5)) {
      if (!rtIsNaN(tune_B.b_x[tune_B.k_e - 1])) {
        tune_B.ct = tune_B.k_e;
        exitg1 = true;
      } else {
        tune_B.k_e++;
      }
    }
  }

  if (tune_B.ct == 0) {
    result = tune_B.b_x[0];
  } else {
    result = tune_B.b_x[tune_B.ct - 1];
    while (tune_B.ct + 1 <= 5) {
      if (result > tune_B.b_x[tune_B.ct]) {
        result = tune_B.b_x[tune_B.ct];
      }

      tune_B.ct++;
    }
  }

  return result;
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_utilLSQFixedSizeData_mbllg(const real_T C[40], const real_T d[8],
  real_T x[5])
{
  static const int32_T tmp = 5;
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  tune_B.tol = 2.2204460492503131E-15 * tune_norm_eb(C) * 8.0;
  for (tune_B.i_c = 0; tune_B.i_c < 5; tune_B.i_c++) {
    tune_B.wz[tune_B.i_c] = 0.0;
    tune_B.P_k[tune_B.i_c] = false;
    tune_B.Z[tune_B.i_c] = true;
    x[tune_B.i_c] = 0.0;
  }

  for (tune_B.i_c = 0; tune_B.i_c < 8; tune_B.i_c++) {
    tune_B.a__4 = 0.0;
    for (tune_B.i_n = 0; tune_B.i_n < 5; tune_B.i_n++) {
      tune_B.C = C[(tune_B.i_n << 3) + tune_B.i_c];
      tune_B.w_tmp[tune_B.i_n + 5 * tune_B.i_c] = tune_B.C;
      tune_B.a__4 += tune_B.C * 0.0;
    }

    tune_B.d[tune_B.i_c] = d[tune_B.i_c] - tune_B.a__4;
  }

  for (tune_B.i_c = 0; tune_B.i_c < 5; tune_B.i_c++) {
    tune_B.w_j[tune_B.i_c] = 0.0;
    for (tune_B.i_n = 0; tune_B.i_n < 8; tune_B.i_n++) {
      tune_B.w_j[tune_B.i_c] += tune_B.w_tmp[5 * tune_B.i_n + tune_B.i_c] *
        tune_B.d[tune_B.i_n];
    }
  }

  tune_B.iter = 0;
  exitg2 = false;
  while ((!exitg2) && tune_vectorAny(tune_B.Z, &tmp)) {
    tune_B.found = false;
    tune_B.i_c = 1;
    exitg3 = false;
    while ((!exitg3) && (tune_B.i_c - 1 < 5)) {
      if (tune_B.Z[(int16_T)tune_B.i_c - 1] && (tune_B.w_j[(int16_T)tune_B.i_c -
           1] > tune_B.tol)) {
        tune_B.found = true;
        exitg3 = true;
      } else {
        tune_B.i_c++;
      }
    }

    if (tune_B.found) {
      for (tune_B.i_c = 0; tune_B.i_c < 5; tune_B.i_c++) {
        if (tune_B.P_k[tune_B.i_c]) {
          tune_B.wz[tune_B.i_c] = -1.7976931348623157E+308;
        }

        if (tune_B.Z[tune_B.i_c]) {
          tune_B.wz[tune_B.i_c] = tune_B.w_j[tune_B.i_c];
        }

        tune_B.z[tune_B.i_c] = 0.0;
      }

      tune_maximum_bt0s(tune_B.wz, &tune_B.a__4, &tune_B.i_c);
      tune_B.P_k[tune_B.i_c - 1] = true;
      tune_B.Z[tune_B.i_c - 1] = false;
      tune_computeZ_ni2(tune_B.z, C, d, tune_B.P_k);
      do {
        exitg1 = 0;
        tune_B.found = false;
        tune_B.i_c = 1;
        exitg3 = false;
        while ((!exitg3) && (tune_B.i_c - 1 < 5)) {
          if (tune_B.P_k[(int16_T)tune_B.i_c - 1] && (tune_B.z[(int16_T)
               tune_B.i_c - 1] <= 0.0)) {
            tune_B.found = true;
            exitg3 = true;
          } else {
            tune_B.i_c++;
          }
        }

        if (tune_B.found) {
          tune_B.iter++;
          if (tune_B.iter > 15) {
            for (tune_B.i_c = 0; tune_B.i_c < 5; tune_B.i_c++) {
              x[tune_B.i_c] = tune_B.z[tune_B.i_c];
            }

            exitg1 = 1;
          } else {
            for (tune_B.i_c = 0; tune_B.i_c < 5; tune_B.i_c++) {
              tune_B.z_ie[tune_B.i_c] = ((tune_B.z[tune_B.i_c] <= 0.0) &&
                tune_B.P_k[tune_B.i_c]);
            }

            tune_B.a__4 = tune_computeAlpha_lk(x, tune_B.z, tune_B.z_ie);
            for (tune_B.i_c = 0; tune_B.i_c < 5; tune_B.i_c++) {
              tune_B.C = x[tune_B.i_c];
              tune_B.C += (tune_B.z[tune_B.i_c] - tune_B.C) * tune_B.a__4;
              tune_B.found = (((fabs(tune_B.C) < tune_B.tol) &&
                               tune_B.P_k[tune_B.i_c]) || tune_B.Z[tune_B.i_c]);
              x[tune_B.i_c] = tune_B.C;
              tune_B.z[tune_B.i_c] = 0.0;
              tune_B.P_k[tune_B.i_c] = !tune_B.found;
              tune_B.Z[tune_B.i_c] = tune_B.found;
            }

            tune_computeZ_ni2(tune_B.z, C, d, tune_B.P_k);
          }
        } else {
          for (tune_B.i_c = 0; tune_B.i_c < 5; tune_B.i_c++) {
            x[tune_B.i_c] = tune_B.z[tune_B.i_c];
          }

          for (tune_B.i_c = 0; tune_B.i_c < 8; tune_B.i_c++) {
            tune_B.a__4 = 0.0;
            for (tune_B.i_n = 0; tune_B.i_n < 5; tune_B.i_n++) {
              tune_B.a__4 += C[(tune_B.i_n << 3) + tune_B.i_c] *
                tune_B.z[tune_B.i_n];
            }

            tune_B.d[tune_B.i_c] = d[tune_B.i_c] - tune_B.a__4;
          }

          for (tune_B.i_c = 0; tune_B.i_c < 5; tune_B.i_c++) {
            tune_B.w_j[tune_B.i_c] = 0.0;
            for (tune_B.i_n = 0; tune_B.i_n < 8; tune_B.i_n++) {
              tune_B.w_j[tune_B.i_c] += tune_B.w_tmp[5 * tune_B.i_n + tune_B.i_c]
                * tune_B.d[tune_B.i_n];
            }
          }

          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    } else {
      exitg2 = true;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tun_utilLSQFixedSizeData_mbllga(const real_T C[40], const real_T d[8],
  real_T x[5], real_T *resnorm)
{
  static const int32_T tmp = 5;
  int32_T exitg1;
  int32_T exitg2;
  boolean_T exitg3;
  boolean_T guard1 = false;
  tune_B.tol_b = 2.2204460492503131E-15 * tune_norm_eb(C) * 8.0;
  for (tune_B.i_bd = 0; tune_B.i_bd < 5; tune_B.i_bd++) {
    tune_B.wz_n[tune_B.i_bd] = 0.0;
    tune_B.P_o[tune_B.i_bd] = false;
    tune_B.Z_m[tune_B.i_bd] = true;
    x[tune_B.i_bd] = 0.0;
  }

  for (tune_B.i_bd = 0; tune_B.i_bd < 8; tune_B.i_bd++) {
    tune_B.a__4_a = 0.0;
    for (tune_B.i4 = 0; tune_B.i4 < 5; tune_B.i4++) {
      tune_B.C_g = C[(tune_B.i4 << 3) + tune_B.i_bd];
      tune_B.a__4_a += tune_B.C_g * 0.0;
      tune_B.w_tmp_c[tune_B.i4 + 5 * tune_B.i_bd] = tune_B.C_g;
    }

    tune_B.resid[tune_B.i_bd] = d[tune_B.i_bd] - tune_B.a__4_a;
  }

  for (tune_B.i_bd = 0; tune_B.i_bd < 5; tune_B.i_bd++) {
    tune_B.w_i[tune_B.i_bd] = 0.0;
    for (tune_B.i4 = 0; tune_B.i4 < 8; tune_B.i4++) {
      tune_B.w_i[tune_B.i_bd] += tune_B.w_tmp_c[5 * tune_B.i4 + tune_B.i_bd] *
        tune_B.resid[tune_B.i4];
    }
  }

  tune_B.iter_h = 0;
  guard1 = false;
  do {
    exitg2 = 0;
    if (tune_vectorAny(tune_B.Z_m, &tmp)) {
      tune_B.found_j = false;
      tune_B.i_bd = 1;
      exitg3 = false;
      while ((!exitg3) && (tune_B.i_bd - 1 < 5)) {
        if (tune_B.Z_m[(int16_T)tune_B.i_bd - 1] && (tune_B.w_i[(int16_T)
             tune_B.i_bd - 1] > tune_B.tol_b)) {
          tune_B.found_j = true;
          exitg3 = true;
        } else {
          tune_B.i_bd++;
        }
      }

      if (tune_B.found_j) {
        for (tune_B.i_bd = 0; tune_B.i_bd < 5; tune_B.i_bd++) {
          if (tune_B.P_o[tune_B.i_bd]) {
            tune_B.wz_n[tune_B.i_bd] = -1.7976931348623157E+308;
          }

          if (tune_B.Z_m[tune_B.i_bd]) {
            tune_B.wz_n[tune_B.i_bd] = tune_B.w_i[tune_B.i_bd];
          }

          tune_B.w_i[tune_B.i_bd] = 0.0;
        }

        tune_maximum_bt0s(tune_B.wz_n, &tune_B.a__4_a, &tune_B.i_bd);
        tune_B.P_o[tune_B.i_bd - 1] = true;
        tune_B.Z_m[tune_B.i_bd - 1] = false;
        tune_computeZ_ni2(tune_B.w_i, C, d, tune_B.P_o);
        do {
          exitg1 = 0;
          tune_B.found_j = false;
          tune_B.i_bd = 1;
          exitg3 = false;
          while ((!exitg3) && (tune_B.i_bd - 1 < 5)) {
            if (tune_B.P_o[(int16_T)tune_B.i_bd - 1] && (tune_B.w_i[(int16_T)
                 tune_B.i_bd - 1] <= 0.0)) {
              tune_B.found_j = true;
              exitg3 = true;
            } else {
              tune_B.i_bd++;
            }
          }

          if (tune_B.found_j) {
            tune_B.iter_h++;
            if (tune_B.iter_h > 15) {
              for (tune_B.i_bd = 0; tune_B.i_bd < 8; tune_B.i_bd++) {
                tune_B.tol_b = tune_B.resid[tune_B.i_bd];
                tune_B.resid[tune_B.i_bd] = tune_B.tol_b * tune_B.tol_b;
              }

              *resnorm = tune_B.resid[0];
              for (tune_B.i_bd = 0; tune_B.i_bd < 7; tune_B.i_bd++) {
                *resnorm += tune_B.resid[tune_B.i_bd + 1];
              }

              for (tune_B.i_bd = 0; tune_B.i_bd < 5; tune_B.i_bd++) {
                x[tune_B.i_bd] = tune_B.w_i[tune_B.i_bd];
              }

              exitg1 = 1;
            } else {
              for (tune_B.i_bd = 0; tune_B.i_bd < 5; tune_B.i_bd++) {
                tune_B.w_cu[tune_B.i_bd] = ((tune_B.w_i[tune_B.i_bd] <= 0.0) &&
                  tune_B.P_o[tune_B.i_bd]);
              }

              tune_B.a__4_a = tune_computeAlpha_lk(x, tune_B.w_i, tune_B.w_cu);
              for (tune_B.i_bd = 0; tune_B.i_bd < 5; tune_B.i_bd++) {
                tune_B.C_g = x[tune_B.i_bd];
                tune_B.C_g += (tune_B.w_i[tune_B.i_bd] - tune_B.C_g) *
                  tune_B.a__4_a;
                tune_B.found_j = (((fabs(tune_B.C_g) < tune_B.tol_b) &&
                                   tune_B.P_o[tune_B.i_bd]) ||
                                  tune_B.Z_m[tune_B.i_bd]);
                x[tune_B.i_bd] = tune_B.C_g;
                tune_B.w_i[tune_B.i_bd] = 0.0;
                tune_B.P_o[tune_B.i_bd] = !tune_B.found_j;
                tune_B.Z_m[tune_B.i_bd] = tune_B.found_j;
              }

              tune_computeZ_ni2(tune_B.w_i, C, d, tune_B.P_o);
            }
          } else {
            for (tune_B.i_bd = 0; tune_B.i_bd < 5; tune_B.i_bd++) {
              x[tune_B.i_bd] = tune_B.w_i[tune_B.i_bd];
            }

            for (tune_B.i_bd = 0; tune_B.i_bd < 8; tune_B.i_bd++) {
              tune_B.a__4_a = 0.0;
              for (tune_B.i4 = 0; tune_B.i4 < 5; tune_B.i4++) {
                tune_B.a__4_a += C[(tune_B.i4 << 3) + tune_B.i_bd] *
                  tune_B.w_i[tune_B.i4];
              }

              tune_B.resid[tune_B.i_bd] = d[tune_B.i_bd] - tune_B.a__4_a;
            }

            for (tune_B.i_bd = 0; tune_B.i_bd < 5; tune_B.i_bd++) {
              tune_B.w_i[tune_B.i_bd] = 0.0;
              for (tune_B.i4 = 0; tune_B.i4 < 8; tune_B.i4++) {
                tune_B.w_i[tune_B.i_bd] += tune_B.w_tmp_c[5 * tune_B.i4 +
                  tune_B.i_bd] * tune_B.resid[tune_B.i4];
              }
            }

            guard1 = false;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = 1;
        }
      } else {
        guard1 = true;
        exitg2 = 1;
      }
    } else {
      guard1 = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (guard1) {
    *resnorm = 0.0;
    for (tune_B.i_bd = 0; tune_B.i_bd < 8; tune_B.i_bd++) {
      tune_B.tol_b = tune_B.resid[tune_B.i_bd];
      *resnorm += tune_B.tol_b * tune_B.tol_b;
    }
  }
}

/* Function for MATLAB Function: '<S71>/DeployedMode' */
static void tune_slpidfivepoint(real_T type, uint16_T form, const real_T
  frequencies[5], creal_T responses[5], real_T targetPM, real_T HasIntegrator,
  real_T LoopSign, real_T Ts, uint16_T IF, uint16_T DF, real_T *P, real_T *b_I,
  real_T *D, real_T *N, real_T *achievedPM)
{
  static const int8_T d[14] = { 1, 5, 1, 1, 5, 1, 1, 1, 5, 1, 1, 5, 1, 1 };

  static const int8_T e[21] = { 1, 5, 1, 1, 5, 1, 1, 1, 5, 1, 1, 5, 1, 1, 1, 5,
    1, 1, 5, 1, 1 };

  static const int8_T g[32] = { 1, 5, 1, 1, 5, 1, 1, 1, 1, 5, 1, 1, 5, 1, 1, 1,
    1, 5, 1, 1, 5, 1, 1, 1, 1, 5, 1, 1, 5, 1, 1, 1 };

  static const int8_T h[40] = { 1, 5, 1, 1, 5, 1, 1, 1, 1, 5, 1, 1, 5, 1, 1, 1,
    1, 5, 1, 1, 5, 1, 1, 1, 1, 5, 1, 1, 5, 1, 1, 1, 1, 5, 1, 1, 5, 1, 1, 1 };

  tune_B.IsDiscrete = (Ts > 0.0);
  tune_generateTargetLoop(&frequencies[1], targetPM, tune_B.hL3);
  tune_B.gammaHigh = tune_rt_hypotd_snf(tune_B.hL3[2].re, tune_B.hL3[2].im);
  tune_logspace(log10(frequencies[0]), log10(frequencies[2] / 5.0), tune_B.wLow);
  tune_logspace(log10(5.0 * frequencies[2]), log10(frequencies[4]), tune_B.wHigh);
  for (tune_B.i_b = 0; tune_B.i_b < 5; tune_B.i_b++) {
    tune_B.responses_i = responses[tune_B.i_b];
    tune_B.c_x[tune_B.i_b] = frequencies[tune_B.i_b];
    tune_B.responses_i.re *= LoopSign;
    tune_B.responses_i.im *= LoopSign;
    responses[tune_B.i_b] = tune_B.responses_i;
  }

  tune_abs(&responses[1], tune_B.rG3);
  tune_B.rLast = tune_rt_hypotd_snf(responses[4].re, responses[4].im);
  tune_log10(tune_B.c_x);
  tune_abs_l(responses, tune_B.j);
  tune_log10(tune_B.j);
  for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
    tune_B.c_xtau[tune_B.i_b] = tune_B.wLow[tune_B.i_b];
    tune_B.c_xtau[tune_B.i_b + 50] = tune_B.wHigh[tune_B.i_b];
  }

  tune_log10_j(tune_B.c_xtau);
  tune_pchip(tune_B.c_x, tune_B.j, tune_B.c_xtau, tune_B.dv);
  tune_power(tune_B.dv, tune_B.f);
  if (((type == 6.0) || (type == 7.0)) && (tune_B.rG3[2] < tune_B.rLast)) {
    type = 3.0;
  }

  if (((type == 4.0) || (type == 5.0)) && (HasIntegrator != 0.0) && (tune_B.rG3
       [2] < tune_B.rLast)) {
    type = 1.0;
  }

  if (tune_B.IsDiscrete) {
    tune_localGetRealImag(Ts, &frequencies[1], IF, &tune_B.hI_idx_0_re,
                          tune_B.rG3);
    tune_B.hI_idx_0_im = tune_B.rG3[0];
    tune_B.hI_idx_1_re = tune_B.hI_idx_0_re;
    tune_B.hI_idx_1_im = tune_B.rG3[1];
    tune_B.hI_idx_2_re = tune_B.hI_idx_0_re;
    tune_B.hI_idx_2_im = tune_B.rG3[2];
  } else {
    tune_B.hI_idx_0_re = 0.0;
    tune_B.hI_idx_0_im = -1.0 / frequencies[1];
    tune_B.hI_idx_1_re = 0.0;
    tune_B.hI_idx_1_im = -1.0 / frequencies[2];
    tune_B.hI_idx_2_re = 0.0;
    tune_B.hI_idx_2_im = -1.0 / frequencies[3];
  }

  tune_localGetRealImag(Ts, &frequencies[1], DF, &tune_B.realhD, tune_B.rG3);
  switch ((int32_T)type) {
   case 1:
    if (HasIntegrator != 0.0) {
      tune_B.responses_j[0] = responses[1].re;
      tune_B.responses_j[3] = responses[1].im;
      tune_B.responses_j[1] = responses[2].re;
      tune_B.responses_j[4] = responses[2].im;
      tune_B.responses_j[2] = responses[3].re;
      tune_B.responses_j[5] = responses[3].im;
      tune_blkdiag(tune_B.responses_j, tune_B.A_gu);
      for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
        tune_B.f_c[tune_B.i_b] = tune_B.f[tune_B.i_b] * tune_B.wLow[tune_B.i_b];
      }

      tune_B.A_gu[6] = -tune_minimum(tune_B.f_c);
      for (tune_B.i_b = 0; tune_B.i_b < 14; tune_B.i_b++) {
        tune_B.A_ld[tune_B.i_b] = tune_B.A_gu[tune_B.i_b] * (real_T)d[tune_B.i_b];
      }

      tune_B.b[0] = tune_B.hL3[0].re;
      tune_B.b[3] = tune_B.hL3[0].im;
      tune_B.b[1] = tune_B.hL3[1].re * 5.0;
      tune_B.b[4] = tune_B.hL3[1].im * 5.0;
      tune_B.b[2] = tune_B.hL3[2].re;
      tune_B.b[5] = tune_B.hL3[2].im;
      tune_B.b[6] = -frequencies[1];
      tune_utilLSQFixedSizeData(tune_B.A_ld, tune_B.b, tune_B.x);
      *P = tune_B.x[0];
      tune_B.Ki = 0.0;
      tune_B.Kd = 0.0;
      tune_B.rLast = 0.0;
    } else {
      *P = 1.0 / tune_rt_hypotd_snf(responses[2].re, responses[2].im);
      tune_B.Ki = 0.0;
      tune_B.Kd = 0.0;
      tune_B.rLast = 0.0;
    }
    break;

   case 2:
    tune_B.responses_j[0] = responses[1].re * tune_B.hI_idx_0_re - responses[1].
      im * tune_B.hI_idx_0_im;
    tune_B.responses_j[3] = responses[1].re * tune_B.hI_idx_0_im + responses[1].
      im * tune_B.hI_idx_0_re;
    tune_B.responses_j[1] = responses[2].re * tune_B.hI_idx_1_re - responses[2].
      im * tune_B.hI_idx_1_im;
    tune_B.responses_j[4] = responses[2].re * tune_B.hI_idx_1_im + responses[2].
      im * tune_B.hI_idx_1_re;
    tune_B.responses_j[2] = responses[3].re * tune_B.hI_idx_2_re - responses[3].
      im * tune_B.hI_idx_2_im;
    tune_B.responses_j[5] = responses[3].re * tune_B.hI_idx_2_im + responses[3].
      im * tune_B.hI_idx_2_re;
    tune_blkdiag(tune_B.responses_j, tune_B.A_gu);
    tune_B.A_gu[6] = -tune_minimum(&tune_B.f[0]);
    for (tune_B.i_b = 0; tune_B.i_b < 14; tune_B.i_b++) {
      tune_B.A_ld[tune_B.i_b] = tune_B.A_gu[tune_B.i_b] * (real_T)d[tune_B.i_b];
    }

    tune_B.b[0] = tune_B.hL3[0].re;
    tune_B.b[3] = tune_B.hL3[0].im;
    tune_B.b[1] = tune_B.hL3[1].re * 5.0;
    tune_B.b[4] = tune_B.hL3[1].im * 5.0;
    tune_B.b[2] = tune_B.hL3[2].re;
    tune_B.b[5] = tune_B.hL3[2].im;
    tune_B.b[6] = -frequencies[1];
    tune_utilLSQFixedSizeData(tune_B.A_ld, tune_B.b, tune_B.x);
    *P = 0.0;
    tune_B.Ki = tune_B.x[0];
    tune_B.Kd = 0.0;
    tune_B.rLast = 0.0;
    break;

   case 3:
    tune_B.responses_l[0] = responses[1].re;
    tune_B.responses_l[6] = responses[1].re * tune_B.hI_idx_0_re - responses[1].
      im * tune_B.hI_idx_0_im;
    tune_B.responses_l[3] = responses[1].im;
    tune_B.responses_l[9] = responses[1].re * tune_B.hI_idx_0_im + responses[1].
      im * tune_B.hI_idx_0_re;
    tune_B.responses_l[1] = responses[2].re;
    tune_B.responses_l[7] = responses[2].re * tune_B.hI_idx_1_re - responses[2].
      im * tune_B.hI_idx_1_im;
    tune_B.responses_l[4] = responses[2].im;
    tune_B.responses_l[10] = responses[2].re * tune_B.hI_idx_1_im + responses[2]
      .im * tune_B.hI_idx_1_re;
    tune_B.responses_l[2] = responses[3].re;
    tune_B.responses_l[8] = responses[3].re * tune_B.hI_idx_2_re - responses[3].
      im * tune_B.hI_idx_2_im;
    tune_B.responses_l[5] = responses[3].im;
    tune_B.responses_l[11] = responses[3].re * tune_B.hI_idx_2_im + responses[3]
      .im * tune_B.hI_idx_2_re;
    tune_blkdiag_f(tune_B.responses_l, tune_B.b_A);
    tune_B.b_A[13] = -tune_minimum(&tune_B.f[0]);
    for (tune_B.i_b = 0; tune_B.i_b < 21; tune_B.i_b++) {
      tune_B.b_A_n[tune_B.i_b] = tune_B.b_A[tune_B.i_b] * (real_T)e[tune_B.i_b];
    }

    tune_B.b[0] = tune_B.hL3[0].re;
    tune_B.b[3] = tune_B.hL3[0].im;
    tune_B.b[1] = tune_B.hL3[1].re * 5.0;
    tune_B.b[4] = tune_B.hL3[1].im * 5.0;
    tune_B.b[2] = tune_B.hL3[2].re;
    tune_B.b[5] = tune_B.hL3[2].im;
    tune_B.b[6] = -frequencies[1];
    tune_utilLSQFixedSizeData_m(tune_B.b_A_n, tune_B.b, tune_B.rG3);
    *P = tune_B.rG3[0];
    tune_B.Ki = tune_B.rG3[1];
    tune_B.Kd = 0.0;
    tune_B.rLast = 0.0;
    break;

   case 4:
    if (HasIntegrator != 0.0) {
      if (tune_B.IsDiscrete) {
        if (tune_B.rG3[0] == 0.0) {
          tune_B.Ki = 1.0 / tune_B.realhD;
          tune_B.hD_idx_0_im = 0.0;
        } else if (tune_B.realhD == 0.0) {
          tune_B.Ki = 0.0;
          tune_B.hD_idx_0_im = -(1.0 / tune_B.rG3[0]);
        } else {
          tune_B.Kd = fabs(tune_B.realhD);
          tune_B.rLast = fabs(tune_B.rG3[0]);
          if (tune_B.Kd > tune_B.rLast) {
            tune_B.rLast = tune_B.rG3[0] / tune_B.realhD;
            tune_B.Kd = tune_B.rLast * tune_B.rG3[0] + tune_B.realhD;
            tune_B.Ki = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
            tune_B.hD_idx_0_im = (0.0 - tune_B.rLast) / tune_B.Kd;
          } else if (tune_B.rLast == tune_B.Kd) {
            tune_B.sgnbr = tune_B.realhD > 0.0 ? 0.5 : -0.5;
            tune_B.rLast = tune_B.rG3[0] > 0.0 ? 0.5 : -0.5;
            tune_B.Ki = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
            tune_B.hD_idx_0_im = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
          } else {
            tune_B.rLast = tune_B.realhD / tune_B.rG3[0];
            tune_B.Kd = tune_B.rLast * tune_B.realhD + tune_B.rG3[0];
            tune_B.Ki = tune_B.rLast / tune_B.Kd;
            tune_B.hD_idx_0_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
          }
        }

        if (tune_B.rG3[1] == 0.0) {
          tune_B.hD_idx_1_re = 1.0 / tune_B.realhD;
          tune_B.hD_idx_1_im = 0.0;
        } else if (tune_B.realhD == 0.0) {
          tune_B.hD_idx_1_re = 0.0;
          tune_B.hD_idx_1_im = -(1.0 / tune_B.rG3[1]);
        } else {
          tune_B.Kd = fabs(tune_B.realhD);
          tune_B.rLast = fabs(tune_B.rG3[1]);
          if (tune_B.Kd > tune_B.rLast) {
            tune_B.rLast = tune_B.rG3[1] / tune_B.realhD;
            tune_B.Kd = tune_B.rLast * tune_B.rG3[1] + tune_B.realhD;
            tune_B.hD_idx_1_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
            tune_B.hD_idx_1_im = (0.0 - tune_B.rLast) / tune_B.Kd;
          } else if (tune_B.rLast == tune_B.Kd) {
            tune_B.sgnbr = tune_B.realhD > 0.0 ? 0.5 : -0.5;
            tune_B.rLast = tune_B.rG3[1] > 0.0 ? 0.5 : -0.5;
            tune_B.hD_idx_1_re = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
            tune_B.hD_idx_1_im = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
          } else {
            tune_B.rLast = tune_B.realhD / tune_B.rG3[1];
            tune_B.Kd = tune_B.rLast * tune_B.realhD + tune_B.rG3[1];
            tune_B.hD_idx_1_re = tune_B.rLast / tune_B.Kd;
            tune_B.hD_idx_1_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
          }
        }

        if (tune_B.rG3[2] == 0.0) {
          tune_B.hD_idx_2_re = 1.0 / tune_B.realhD;
          tune_B.rLast = 0.0;
        } else if (tune_B.realhD == 0.0) {
          tune_B.hD_idx_2_re = 0.0;
          tune_B.rLast = -(1.0 / tune_B.rG3[2]);
        } else {
          tune_B.Kd = fabs(tune_B.realhD);
          tune_B.rLast = fabs(tune_B.rG3[2]);
          if (tune_B.Kd > tune_B.rLast) {
            tune_B.rLast = tune_B.rG3[2] / tune_B.realhD;
            tune_B.Kd = tune_B.rLast * tune_B.rG3[2] + tune_B.realhD;
            tune_B.hD_idx_2_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
            tune_B.rLast = (0.0 - tune_B.rLast) / tune_B.Kd;
          } else if (tune_B.rLast == tune_B.Kd) {
            tune_B.sgnbr = tune_B.realhD > 0.0 ? 0.5 : -0.5;
            tune_B.rLast = tune_B.rG3[2] > 0.0 ? 0.5 : -0.5;
            tune_B.hD_idx_2_re = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
            tune_B.rLast = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
          } else {
            tune_B.rLast = tune_B.realhD / tune_B.rG3[2];
            tune_B.Kd = tune_B.rLast * tune_B.realhD + tune_B.rG3[2];
            tune_B.hD_idx_2_re = tune_B.rLast / tune_B.Kd;
            tune_B.rLast = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
          }
        }
      } else {
        tune_B.Ki = 0.0;
        tune_B.hD_idx_0_im = frequencies[1];
        tune_B.hD_idx_1_re = 0.0;
        tune_B.hD_idx_1_im = frequencies[2];
        tune_B.hD_idx_2_re = 0.0;
        tune_B.rLast = frequencies[3];
      }

      tune_B.responses_l[0] = responses[1].re;
      tune_B.responses_l[6] = responses[1].re * tune_B.Ki - responses[1].im *
        tune_B.hD_idx_0_im;
      tune_B.responses_l[3] = responses[1].im;
      tune_B.responses_l[9] = responses[1].im * tune_B.Ki + responses[1].re *
        tune_B.hD_idx_0_im;
      tune_B.responses_l[1] = responses[2].re;
      tune_B.responses_l[7] = responses[2].re * tune_B.hD_idx_1_re - responses[2]
        .im * tune_B.hD_idx_1_im;
      tune_B.responses_l[4] = responses[2].im;
      tune_B.responses_l[10] = responses[2].im * tune_B.hD_idx_1_re + responses
        [2].re * tune_B.hD_idx_1_im;
      tune_B.responses_l[2] = responses[3].re;
      tune_B.responses_l[8] = responses[3].re * tune_B.hD_idx_2_re - responses[3]
        .im * tune_B.rLast;
      tune_B.responses_l[5] = responses[3].im;
      tune_B.responses_l[11] = responses[3].im * tune_B.hD_idx_2_re + responses
        [3].re * tune_B.rLast;
      tune_blkdiag_f0(tune_B.responses_l, tune_B.c_A);
      for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
        tune_B.f_c[tune_B.i_b] = tune_B.f[tune_B.i_b] * tune_B.wLow[tune_B.i_b];
      }

      tune_B.c_A[6] = -tune_minimum(tune_B.f_c);
      tune_B.c_A[7] = tune_maximum_b(&tune_B.f[50]);
      for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
        tune_B.f_c[tune_B.i_b] = tune_B.f[tune_B.i_b + 50] *
          tune_B.wHigh[tune_B.i_b];
      }

      tune_B.c_A[15] = tune_maximum_b(tune_B.f_c);
      for (tune_B.i_b = 0; tune_B.i_b < 32; tune_B.i_b++) {
        tune_B.c_A_f[tune_B.i_b] = tune_B.c_A[tune_B.i_b] * (real_T)g[tune_B.i_b];
      }

      tune_B.b_b[0] = tune_B.hL3[0].re;
      tune_B.b_b[3] = tune_B.hL3[0].im;
      tune_B.b_b[1] = tune_B.hL3[1].re * 5.0;
      tune_B.b_b[4] = tune_B.hL3[1].im * 5.0;
      tune_B.b_b[2] = tune_B.hL3[2].re;
      tune_B.b_b[5] = tune_B.hL3[2].im;
      tune_B.b_b[6] = -frequencies[1];
      tune_B.b_b[7] = tune_B.gammaHigh;
      tune_utilLSQFixedSizeData_mb(tune_B.c_A_f, tune_B.b_b, tune_B.b_x_n);
      *P = tune_B.b_x_n[0];
      tune_B.Ki = 0.0;
      tune_B.Kd = tune_B.b_x_n[1];
      tune_B.rLast = 0.0;
    } else {
      *P = 1.0 / tune_rt_hypotd_snf(responses[2].re, responses[2].im);
      tune_B.tempKp.re = *P * responses[2].re;
      tune_B.tempKp.im = *P * responses[2].im;
      if (tune_computePM(tune_B.tempKp) > targetPM) {
        tune_B.Ki = 0.0;
        tune_B.Kd = 0.0;
        tune_B.rLast = 0.0;
      } else {
        if (tune_B.IsDiscrete) {
          if (tune_B.rG3[0] == 0.0) {
            tune_B.Ki = 1.0 / tune_B.realhD;
            tune_B.hD_idx_0_im = 0.0;
          } else if (tune_B.realhD == 0.0) {
            tune_B.Ki = 0.0;
            tune_B.hD_idx_0_im = -(1.0 / tune_B.rG3[0]);
          } else {
            tune_B.Kd = fabs(tune_B.realhD);
            tune_B.rLast = fabs(tune_B.rG3[0]);
            if (tune_B.Kd > tune_B.rLast) {
              tune_B.rLast = tune_B.rG3[0] / tune_B.realhD;
              tune_B.Kd = tune_B.rLast * tune_B.rG3[0] + tune_B.realhD;
              tune_B.Ki = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
              tune_B.hD_idx_0_im = (0.0 - tune_B.rLast) / tune_B.Kd;
            } else if (tune_B.rLast == tune_B.Kd) {
              tune_B.sgnbr = tune_B.realhD > 0.0 ? 0.5 : -0.5;
              tune_B.rLast = tune_B.rG3[0] > 0.0 ? 0.5 : -0.5;
              tune_B.Ki = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
              tune_B.hD_idx_0_im = (0.0 * tune_B.sgnbr - tune_B.rLast) /
                tune_B.Kd;
            } else {
              tune_B.rLast = tune_B.realhD / tune_B.rG3[0];
              tune_B.Kd = tune_B.rLast * tune_B.realhD + tune_B.rG3[0];
              tune_B.Ki = tune_B.rLast / tune_B.Kd;
              tune_B.hD_idx_0_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
            }
          }

          if (tune_B.rG3[1] == 0.0) {
            tune_B.hD_idx_1_re = 1.0 / tune_B.realhD;
            tune_B.hD_idx_1_im = 0.0;
          } else if (tune_B.realhD == 0.0) {
            tune_B.hD_idx_1_re = 0.0;
            tune_B.hD_idx_1_im = -(1.0 / tune_B.rG3[1]);
          } else {
            tune_B.Kd = fabs(tune_B.realhD);
            tune_B.rLast = fabs(tune_B.rG3[1]);
            if (tune_B.Kd > tune_B.rLast) {
              tune_B.rLast = tune_B.rG3[1] / tune_B.realhD;
              tune_B.Kd = tune_B.rLast * tune_B.rG3[1] + tune_B.realhD;
              tune_B.hD_idx_1_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
              tune_B.hD_idx_1_im = (0.0 - tune_B.rLast) / tune_B.Kd;
            } else if (tune_B.rLast == tune_B.Kd) {
              tune_B.sgnbr = tune_B.realhD > 0.0 ? 0.5 : -0.5;
              tune_B.rLast = tune_B.rG3[1] > 0.0 ? 0.5 : -0.5;
              tune_B.hD_idx_1_re = (0.0 * tune_B.rLast + tune_B.sgnbr) /
                tune_B.Kd;
              tune_B.hD_idx_1_im = (0.0 * tune_B.sgnbr - tune_B.rLast) /
                tune_B.Kd;
            } else {
              tune_B.rLast = tune_B.realhD / tune_B.rG3[1];
              tune_B.Kd = tune_B.rLast * tune_B.realhD + tune_B.rG3[1];
              tune_B.hD_idx_1_re = tune_B.rLast / tune_B.Kd;
              tune_B.hD_idx_1_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
            }
          }

          if (tune_B.rG3[2] == 0.0) {
            tune_B.hD_idx_2_re = 1.0 / tune_B.realhD;
            tune_B.rLast = 0.0;
          } else if (tune_B.realhD == 0.0) {
            tune_B.hD_idx_2_re = 0.0;
            tune_B.rLast = -(1.0 / tune_B.rG3[2]);
          } else {
            tune_B.Kd = fabs(tune_B.realhD);
            tune_B.rLast = fabs(tune_B.rG3[2]);
            if (tune_B.Kd > tune_B.rLast) {
              tune_B.rLast = tune_B.rG3[2] / tune_B.realhD;
              tune_B.Kd = tune_B.rLast * tune_B.rG3[2] + tune_B.realhD;
              tune_B.hD_idx_2_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
              tune_B.rLast = (0.0 - tune_B.rLast) / tune_B.Kd;
            } else if (tune_B.rLast == tune_B.Kd) {
              tune_B.sgnbr = tune_B.realhD > 0.0 ? 0.5 : -0.5;
              tune_B.rLast = tune_B.rG3[2] > 0.0 ? 0.5 : -0.5;
              tune_B.hD_idx_2_re = (0.0 * tune_B.rLast + tune_B.sgnbr) /
                tune_B.Kd;
              tune_B.rLast = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
            } else {
              tune_B.rLast = tune_B.realhD / tune_B.rG3[2];
              tune_B.Kd = tune_B.rLast * tune_B.realhD + tune_B.rG3[2];
              tune_B.hD_idx_2_re = tune_B.rLast / tune_B.Kd;
              tune_B.rLast = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
            }
          }
        } else {
          tune_B.Ki = 0.0;
          tune_B.hD_idx_0_im = frequencies[1];
          tune_B.hD_idx_1_re = 0.0;
          tune_B.hD_idx_1_im = frequencies[2];
          tune_B.hD_idx_2_re = 0.0;
          tune_B.rLast = frequencies[3];
        }

        tune_B.responses_l[0] = responses[1].re;
        tune_B.responses_l[6] = responses[1].re * tune_B.Ki - responses[1].im *
          tune_B.hD_idx_0_im;
        tune_B.responses_l[3] = responses[1].im;
        tune_B.responses_l[9] = responses[1].im * tune_B.Ki + responses[1].re *
          tune_B.hD_idx_0_im;
        tune_B.responses_l[1] = responses[2].re;
        tune_B.responses_l[7] = responses[2].re * tune_B.hD_idx_1_re -
          responses[2].im * tune_B.hD_idx_1_im;
        tune_B.responses_l[4] = responses[2].im;
        tune_B.responses_l[10] = responses[2].im * tune_B.hD_idx_1_re +
          responses[2].re * tune_B.hD_idx_1_im;
        tune_B.responses_l[2] = responses[3].re;
        tune_B.responses_l[8] = responses[3].re * tune_B.hD_idx_2_re -
          responses[3].im * tune_B.rLast;
        tune_B.responses_l[5] = responses[3].im;
        tune_B.responses_l[11] = responses[3].im * tune_B.hD_idx_2_re +
          responses[3].re * tune_B.rLast;
        tune_blkdiag_f(tune_B.responses_l, tune_B.b_A);
        tune_B.b_A[6] = tune_maximum_b(&tune_B.f[50]);
        for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
          tune_B.f_c[tune_B.i_b] = tune_B.f[tune_B.i_b + 50] *
            tune_B.wHigh[tune_B.i_b];
        }

        tune_B.b_A[13] = tune_maximum_b(tune_B.f_c);
        for (tune_B.i_b = 0; tune_B.i_b < 21; tune_B.i_b++) {
          tune_B.b_A_n[tune_B.i_b] = tune_B.b_A[tune_B.i_b] * (real_T)
            e[tune_B.i_b];
        }

        tune_B.b[0] = tune_B.hL3[0].re;
        tune_B.b[3] = tune_B.hL3[0].im;
        tune_B.b[1] = tune_B.hL3[1].re * 5.0;
        tune_B.b[4] = tune_B.hL3[1].im * 5.0;
        tune_B.b[2] = tune_B.hL3[2].re;
        tune_B.b[5] = tune_B.hL3[2].im;
        tune_B.b[6] = tune_B.gammaHigh;
        tune_utilLSQFixedSizeData_m(tune_B.b_A_n, tune_B.b, tune_B.rG3);
        *P = tune_B.rG3[0];
        tune_B.Ki = 0.0;
        tune_B.Kd = tune_B.rG3[1];
        tune_B.rLast = 0.0;
      }
    }
    break;

   case 5:
    if (HasIntegrator != 0.0) {
      tune_computeTAU(tune_B.IsDiscrete, &frequencies[1], Ts, DF, tune_B.tau);
      tune_B.b_b[0] = tune_B.hL3[0].re;
      tune_B.b_b[3] = tune_B.hL3[0].im;
      tune_B.b_b[1] = tune_B.hL3[1].re * 5.0;
      tune_B.b_b[4] = tune_B.hL3[1].im * 5.0;
      tune_B.b_b[2] = tune_B.hL3[2].re;
      tune_B.b_b[5] = tune_B.hL3[2].im;
      tune_B.b_b[6] = -frequencies[1];
      tune_B.b_b[7] = tune_B.gammaHigh;
      tune_B.gammaHigh = responses[1].re;
      tune_B.responses_l[0] = responses[1].re;
      tune_B.responses_tmp_tmp = responses[1].im;
      tune_B.responses_l[3] = responses[1].im;
      tune_B.hI_idx_0_re = responses[2].re;
      tune_B.responses_l[1] = responses[2].re;
      tune_B.hI_idx_0_im = responses[2].im;
      tune_B.responses_l[4] = responses[2].im;
      tune_B.hI_idx_1_re = responses[3].re;
      tune_B.responses_l[2] = responses[3].re;
      tune_B.hI_idx_1_im = responses[3].im;
      tune_B.responses_l[5] = responses[3].im;
      for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
        tune_B.f_c[tune_B.i_b] = tune_B.f[tune_B.i_b] * tune_B.wLow[tune_B.i_b];
      }

      for (tune_B.imin = 0; tune_B.imin < 20; tune_B.imin++) {
        tune_B.tau_l = tune_B.tau[tune_B.imin];
        if (tune_B.IsDiscrete) {
          tune_B.hI_idx_2_re = tune_B.tau_l + tune_B.realhD;
          if (tune_B.rG3[0] == 0.0) {
            tune_B.Ki = 1.0 / tune_B.hI_idx_2_re;
            tune_B.hD_idx_0_im = 0.0;
          } else if (tune_B.hI_idx_2_re == 0.0) {
            tune_B.Ki = 0.0;
            tune_B.hD_idx_0_im = -(1.0 / tune_B.rG3[0]);
          } else {
            tune_B.Kd = fabs(tune_B.hI_idx_2_re);
            tune_B.rLast = fabs(tune_B.rG3[0]);
            if (tune_B.Kd > tune_B.rLast) {
              tune_B.rLast = tune_B.rG3[0] / tune_B.hI_idx_2_re;
              tune_B.Kd = tune_B.rLast * tune_B.rG3[0] + tune_B.hI_idx_2_re;
              tune_B.Ki = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
              tune_B.hD_idx_0_im = (0.0 - tune_B.rLast) / tune_B.Kd;
            } else if (tune_B.rLast == tune_B.Kd) {
              tune_B.sgnbr = tune_B.hI_idx_2_re > 0.0 ? 0.5 : -0.5;
              tune_B.rLast = tune_B.rG3[0] > 0.0 ? 0.5 : -0.5;
              tune_B.Ki = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
              tune_B.hD_idx_0_im = (0.0 * tune_B.sgnbr - tune_B.rLast) /
                tune_B.Kd;
            } else {
              tune_B.rLast = tune_B.hI_idx_2_re / tune_B.rG3[0];
              tune_B.Kd = tune_B.rLast * tune_B.hI_idx_2_re + tune_B.rG3[0];
              tune_B.Ki = tune_B.rLast / tune_B.Kd;
              tune_B.hD_idx_0_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
            }
          }

          if (tune_B.rG3[1] == 0.0) {
            tune_B.hD_idx_1_re = 1.0 / tune_B.hI_idx_2_re;
            tune_B.hD_idx_1_im = 0.0;
          } else if (tune_B.hI_idx_2_re == 0.0) {
            tune_B.hD_idx_1_re = 0.0;
            tune_B.hD_idx_1_im = -(1.0 / tune_B.rG3[1]);
          } else {
            tune_B.Kd = fabs(tune_B.hI_idx_2_re);
            tune_B.rLast = fabs(tune_B.rG3[1]);
            if (tune_B.Kd > tune_B.rLast) {
              tune_B.rLast = tune_B.rG3[1] / tune_B.hI_idx_2_re;
              tune_B.Kd = tune_B.rLast * tune_B.rG3[1] + tune_B.hI_idx_2_re;
              tune_B.hD_idx_1_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
              tune_B.hD_idx_1_im = (0.0 - tune_B.rLast) / tune_B.Kd;
            } else if (tune_B.rLast == tune_B.Kd) {
              tune_B.sgnbr = tune_B.hI_idx_2_re > 0.0 ? 0.5 : -0.5;
              tune_B.rLast = tune_B.rG3[1] > 0.0 ? 0.5 : -0.5;
              tune_B.hD_idx_1_re = (0.0 * tune_B.rLast + tune_B.sgnbr) /
                tune_B.Kd;
              tune_B.hD_idx_1_im = (0.0 * tune_B.sgnbr - tune_B.rLast) /
                tune_B.Kd;
            } else {
              tune_B.rLast = tune_B.hI_idx_2_re / tune_B.rG3[1];
              tune_B.Kd = tune_B.rLast * tune_B.hI_idx_2_re + tune_B.rG3[1];
              tune_B.hD_idx_1_re = tune_B.rLast / tune_B.Kd;
              tune_B.hD_idx_1_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
            }
          }

          if (tune_B.rG3[2] == 0.0) {
            tune_B.hD_idx_2_re = 1.0 / tune_B.hI_idx_2_re;
            tune_B.rLast = 0.0;
          } else if (tune_B.hI_idx_2_re == 0.0) {
            tune_B.hD_idx_2_re = 0.0;
            tune_B.rLast = -(1.0 / tune_B.rG3[2]);
          } else {
            tune_B.Kd = fabs(tune_B.hI_idx_2_re);
            tune_B.rLast = fabs(tune_B.rG3[2]);
            if (tune_B.Kd > tune_B.rLast) {
              tune_B.rLast = tune_B.rG3[2] / tune_B.hI_idx_2_re;
              tune_B.Kd = tune_B.rLast * tune_B.rG3[2] + tune_B.hI_idx_2_re;
              tune_B.hD_idx_2_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
              tune_B.rLast = (0.0 - tune_B.rLast) / tune_B.Kd;
            } else if (tune_B.rLast == tune_B.Kd) {
              tune_B.sgnbr = tune_B.hI_idx_2_re > 0.0 ? 0.5 : -0.5;
              tune_B.rLast = tune_B.rG3[2] > 0.0 ? 0.5 : -0.5;
              tune_B.hD_idx_2_re = (0.0 * tune_B.rLast + tune_B.sgnbr) /
                tune_B.Kd;
              tune_B.rLast = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
            } else {
              tune_B.rLast = tune_B.hI_idx_2_re / tune_B.rG3[2];
              tune_B.Kd = tune_B.rLast * tune_B.hI_idx_2_re + tune_B.rG3[2];
              tune_B.hD_idx_2_re = tune_B.rLast / tune_B.Kd;
              tune_B.rLast = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
            }
          }
        } else {
          tune_B.hI_idx_2_re = 0.0 * frequencies[1];
          tune_B.hI_idx_2_im = tune_B.tau_l * frequencies[1];
          if (tune_B.hI_idx_2_im == 0.0) {
            if (frequencies[1] == 0.0) {
              tune_B.Ki = tune_B.hI_idx_2_re;
              tune_B.hD_idx_0_im = 0.0;
            } else if (tune_B.hI_idx_2_re == 0.0) {
              tune_B.Ki = 0.0;
              tune_B.hD_idx_0_im = frequencies[1];
            } else {
              tune_B.Ki = (rtNaN);
              tune_B.hD_idx_0_im = frequencies[1];
            }
          } else {
            tune_B.rLast = fabs(tune_B.hI_idx_2_im);
            if (tune_B.rLast < 1.0) {
              tune_B.Kd = tune_B.hI_idx_2_im * tune_B.hI_idx_2_im + 1.0;
              tune_B.Ki = (tune_B.hI_idx_2_im * frequencies[1] +
                           tune_B.hI_idx_2_re) / tune_B.Kd;
              tune_B.hD_idx_0_im = (frequencies[1] - tune_B.hI_idx_2_im *
                                    tune_B.hI_idx_2_re) / tune_B.Kd;
            } else if (tune_B.rLast == 1.0) {
              tune_B.rLast = tune_B.hI_idx_2_im > 0.0 ? 0.5 : -0.5;
              tune_B.Ki = tune_B.hI_idx_2_re * 0.5 + frequencies[1] *
                tune_B.rLast;
              tune_B.hD_idx_0_im = frequencies[1] * 0.5 - tune_B.hI_idx_2_re *
                tune_B.rLast;
            } else {
              tune_B.rLast = 1.0 / tune_B.hI_idx_2_im;
              tune_B.Kd = tune_B.hI_idx_2_im + tune_B.rLast;
              tune_B.Ki = (tune_B.rLast * tune_B.hI_idx_2_re + frequencies[1]) /
                tune_B.Kd;
              tune_B.hD_idx_0_im = (tune_B.rLast * frequencies[1] -
                                    tune_B.hI_idx_2_re) / tune_B.Kd;
            }
          }

          tune_B.hI_idx_2_re = 0.0 * frequencies[2];
          tune_B.hI_idx_2_im = tune_B.tau_l * frequencies[2];
          if (tune_B.hI_idx_2_im == 0.0) {
            if (frequencies[2] == 0.0) {
              tune_B.hD_idx_1_re = tune_B.hI_idx_2_re;
              tune_B.hD_idx_1_im = 0.0;
            } else if (tune_B.hI_idx_2_re == 0.0) {
              tune_B.hD_idx_1_re = 0.0;
              tune_B.hD_idx_1_im = frequencies[2];
            } else {
              tune_B.hD_idx_1_re = (rtNaN);
              tune_B.hD_idx_1_im = frequencies[2];
            }
          } else {
            tune_B.rLast = fabs(tune_B.hI_idx_2_im);
            if (tune_B.rLast < 1.0) {
              tune_B.Kd = tune_B.hI_idx_2_im * tune_B.hI_idx_2_im + 1.0;
              tune_B.hD_idx_1_re = (tune_B.hI_idx_2_im * frequencies[2] +
                                    tune_B.hI_idx_2_re) / tune_B.Kd;
              tune_B.hD_idx_1_im = (frequencies[2] - tune_B.hI_idx_2_im *
                                    tune_B.hI_idx_2_re) / tune_B.Kd;
            } else if (tune_B.rLast == 1.0) {
              tune_B.rLast = tune_B.hI_idx_2_im > 0.0 ? 0.5 : -0.5;
              tune_B.hD_idx_1_re = tune_B.hI_idx_2_re * 0.5 + frequencies[2] *
                tune_B.rLast;
              tune_B.hD_idx_1_im = frequencies[2] * 0.5 - tune_B.hI_idx_2_re *
                tune_B.rLast;
            } else {
              tune_B.rLast = 1.0 / tune_B.hI_idx_2_im;
              tune_B.Kd = tune_B.hI_idx_2_im + tune_B.rLast;
              tune_B.hD_idx_1_re = (tune_B.rLast * tune_B.hI_idx_2_re +
                                    frequencies[2]) / tune_B.Kd;
              tune_B.hD_idx_1_im = (tune_B.rLast * frequencies[2] -
                                    tune_B.hI_idx_2_re) / tune_B.Kd;
            }
          }

          tune_B.hI_idx_2_re = 0.0 * frequencies[3];
          tune_B.hI_idx_2_im = tune_B.tau_l * frequencies[3];
          if (tune_B.hI_idx_2_im == 0.0) {
            if (frequencies[3] == 0.0) {
              tune_B.hD_idx_2_re = tune_B.hI_idx_2_re;
              tune_B.rLast = 0.0;
            } else if (tune_B.hI_idx_2_re == 0.0) {
              tune_B.hD_idx_2_re = 0.0;
              tune_B.rLast = frequencies[3];
            } else {
              tune_B.hD_idx_2_re = (rtNaN);
              tune_B.rLast = frequencies[3];
            }
          } else {
            tune_B.rLast = fabs(tune_B.hI_idx_2_im);
            if (tune_B.rLast < 1.0) {
              tune_B.Kd = tune_B.hI_idx_2_im * tune_B.hI_idx_2_im + 1.0;
              tune_B.hD_idx_2_re = (tune_B.hI_idx_2_im * frequencies[3] +
                                    tune_B.hI_idx_2_re) / tune_B.Kd;
              tune_B.rLast = (frequencies[3] - tune_B.hI_idx_2_im *
                              tune_B.hI_idx_2_re) / tune_B.Kd;
            } else if (tune_B.rLast == 1.0) {
              tune_B.rLast = tune_B.hI_idx_2_im > 0.0 ? 0.5 : -0.5;
              tune_B.hD_idx_2_re = tune_B.hI_idx_2_re * 0.5 + frequencies[3] *
                tune_B.rLast;
              tune_B.rLast = frequencies[3] * 0.5 - tune_B.hI_idx_2_re *
                tune_B.rLast;
            } else {
              tune_B.rLast = 1.0 / tune_B.hI_idx_2_im;
              tune_B.Kd = tune_B.hI_idx_2_im + tune_B.rLast;
              tune_B.hD_idx_2_re = (tune_B.rLast * tune_B.hI_idx_2_re +
                                    frequencies[3]) / tune_B.Kd;
              tune_B.rLast = (tune_B.rLast * frequencies[3] - tune_B.hI_idx_2_re)
                / tune_B.Kd;
            }
          }
        }

        tune_B.responses_l[6] = tune_B.gammaHigh * tune_B.Ki -
          tune_B.responses_tmp_tmp * tune_B.hD_idx_0_im;
        tune_B.responses_l[9] = tune_B.responses_tmp_tmp * tune_B.Ki +
          tune_B.gammaHigh * tune_B.hD_idx_0_im;
        tune_B.responses_l[7] = tune_B.hI_idx_0_re * tune_B.hD_idx_1_re -
          tune_B.hI_idx_0_im * tune_B.hD_idx_1_im;
        tune_B.responses_l[10] = tune_B.hI_idx_0_im * tune_B.hD_idx_1_re +
          tune_B.hI_idx_0_re * tune_B.hD_idx_1_im;
        tune_B.responses_l[8] = tune_B.hI_idx_1_re * tune_B.hD_idx_2_re -
          tune_B.hI_idx_1_im * tune_B.rLast;
        tune_B.responses_l[11] = tune_B.hI_idx_1_im * tune_B.hD_idx_2_re +
          tune_B.hI_idx_1_re * tune_B.rLast;
        tune_blkdiag_f0(tune_B.responses_l, tune_B.c_A);
        tune_B.c_A[6] = -tune_minimum(tune_B.f_c);
        tune_B.c_A[7] = tune_maximum_b(&tune_B.f[50]);
        for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
          tune_B.dcv[tune_B.i_b].re = 1.0;
          tune_B.dcv[tune_B.i_b].im = tune_B.wHigh[tune_B.i_b] * tune_B.tau_l;
        }

        tune_abs_lb(tune_B.dcv, tune_B.wLow);
        for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
          tune_B.f_k[tune_B.i_b] = tune_B.f[tune_B.i_b + 50] *
            tune_B.wHigh[tune_B.i_b] / tune_B.wLow[tune_B.i_b];
        }

        tune_B.c_A[15] = tune_maximum_b(tune_B.f_k);
        for (tune_B.i_b = 0; tune_B.i_b < 32; tune_B.i_b++) {
          tune_B.c_A_f[tune_B.i_b] = tune_B.c_A[tune_B.i_b] * (real_T)
            g[tune_B.i_b];
        }

        tune_utilLSQFixedSizeData_mbl(tune_B.c_A_f, tune_B.b_b,
          &tune_B.b_xtau[tune_B.imin << 2], &tune_B.gap[tune_B.imin]);
      }

      if ((tune_maximum_bt0(tune_B.gap) - tune_minimum_n(tune_B.gap)) /
          tune_mean(tune_B.gap) < 0.1) {
        tune_B.imin = 0;
      } else {
        tune_minimum_nv(tune_B.gap, &tune_B.rLast, &tune_B.i_b);
        tune_B.imin = tune_B.i_b - 1;
      }

      tune_B.i_b = tune_B.imin << 2;
      tune_B.Kd = tune_B.b_xtau[tune_B.i_b + 1];
      if (tune_B.Kd == 0.0) {
        *P = tune_B.b_xtau[tune_B.i_b];
        tune_B.Ki = 0.0;
        tune_B.rLast = 0.0;
      } else {
        *P = tune_B.b_xtau[tune_B.i_b];
        tune_B.Ki = 0.0;
        tune_B.rLast = tune_B.tau[tune_B.imin];
      }
    } else {
      *P = 1.0 / tune_rt_hypotd_snf(responses[2].re, responses[2].im);
      tune_B.tempKp.re = *P * responses[2].re;
      tune_B.tempKp.im = *P * responses[2].im;
      if (tune_computePM(tune_B.tempKp) > targetPM) {
        tune_B.Ki = 0.0;
        tune_B.Kd = 0.0;
        tune_B.rLast = 0.0;
      } else {
        tune_computeTAU(tune_B.IsDiscrete, &frequencies[1], Ts, DF, tune_B.tau);
        tune_B.b[0] = tune_B.hL3[0].re;
        tune_B.b[3] = tune_B.hL3[0].im;
        tune_B.b[1] = tune_B.hL3[1].re * 5.0;
        tune_B.b[4] = tune_B.hL3[1].im * 5.0;
        tune_B.b[2] = tune_B.hL3[2].re;
        tune_B.b[5] = tune_B.hL3[2].im;
        tune_B.b[6] = tune_B.gammaHigh;
        tune_B.gammaHigh = responses[1].re;
        tune_B.responses_l[0] = responses[1].re;
        tune_B.responses_tmp_tmp = responses[1].im;
        tune_B.responses_l[3] = responses[1].im;
        tune_B.hI_idx_0_re = responses[2].re;
        tune_B.responses_l[1] = responses[2].re;
        tune_B.hI_idx_0_im = responses[2].im;
        tune_B.responses_l[4] = responses[2].im;
        tune_B.hI_idx_1_re = responses[3].re;
        tune_B.responses_l[2] = responses[3].re;
        tune_B.hI_idx_1_im = responses[3].im;
        tune_B.responses_l[5] = responses[3].im;
        for (tune_B.imin = 0; tune_B.imin < 20; tune_B.imin++) {
          tune_B.tau_l = tune_B.tau[tune_B.imin];
          if (tune_B.IsDiscrete) {
            tune_B.hI_idx_2_re = tune_B.tau_l + tune_B.realhD;
            if (tune_B.rG3[0] == 0.0) {
              tune_B.Ki = 1.0 / tune_B.hI_idx_2_re;
              tune_B.hD_idx_0_im = 0.0;
            } else if (tune_B.hI_idx_2_re == 0.0) {
              tune_B.Ki = 0.0;
              tune_B.hD_idx_0_im = -(1.0 / tune_B.rG3[0]);
            } else {
              tune_B.Kd = fabs(tune_B.hI_idx_2_re);
              tune_B.rLast = fabs(tune_B.rG3[0]);
              if (tune_B.Kd > tune_B.rLast) {
                tune_B.rLast = tune_B.rG3[0] / tune_B.hI_idx_2_re;
                tune_B.Kd = tune_B.rLast * tune_B.rG3[0] + tune_B.hI_idx_2_re;
                tune_B.Ki = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
                tune_B.hD_idx_0_im = (0.0 - tune_B.rLast) / tune_B.Kd;
              } else if (tune_B.rLast == tune_B.Kd) {
                tune_B.sgnbr = tune_B.hI_idx_2_re > 0.0 ? 0.5 : -0.5;
                tune_B.rLast = tune_B.rG3[0] > 0.0 ? 0.5 : -0.5;
                tune_B.Ki = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
                tune_B.hD_idx_0_im = (0.0 * tune_B.sgnbr - tune_B.rLast) /
                  tune_B.Kd;
              } else {
                tune_B.rLast = tune_B.hI_idx_2_re / tune_B.rG3[0];
                tune_B.Kd = tune_B.rLast * tune_B.hI_idx_2_re + tune_B.rG3[0];
                tune_B.Ki = tune_B.rLast / tune_B.Kd;
                tune_B.hD_idx_0_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
              }
            }

            if (tune_B.rG3[1] == 0.0) {
              tune_B.hD_idx_1_re = 1.0 / tune_B.hI_idx_2_re;
              tune_B.hD_idx_1_im = 0.0;
            } else if (tune_B.hI_idx_2_re == 0.0) {
              tune_B.hD_idx_1_re = 0.0;
              tune_B.hD_idx_1_im = -(1.0 / tune_B.rG3[1]);
            } else {
              tune_B.Kd = fabs(tune_B.hI_idx_2_re);
              tune_B.rLast = fabs(tune_B.rG3[1]);
              if (tune_B.Kd > tune_B.rLast) {
                tune_B.rLast = tune_B.rG3[1] / tune_B.hI_idx_2_re;
                tune_B.Kd = tune_B.rLast * tune_B.rG3[1] + tune_B.hI_idx_2_re;
                tune_B.hD_idx_1_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
                tune_B.hD_idx_1_im = (0.0 - tune_B.rLast) / tune_B.Kd;
              } else if (tune_B.rLast == tune_B.Kd) {
                tune_B.sgnbr = tune_B.hI_idx_2_re > 0.0 ? 0.5 : -0.5;
                tune_B.rLast = tune_B.rG3[1] > 0.0 ? 0.5 : -0.5;
                tune_B.hD_idx_1_re = (0.0 * tune_B.rLast + tune_B.sgnbr) /
                  tune_B.Kd;
                tune_B.hD_idx_1_im = (0.0 * tune_B.sgnbr - tune_B.rLast) /
                  tune_B.Kd;
              } else {
                tune_B.rLast = tune_B.hI_idx_2_re / tune_B.rG3[1];
                tune_B.Kd = tune_B.rLast * tune_B.hI_idx_2_re + tune_B.rG3[1];
                tune_B.hD_idx_1_re = tune_B.rLast / tune_B.Kd;
                tune_B.hD_idx_1_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
              }
            }

            if (tune_B.rG3[2] == 0.0) {
              tune_B.hD_idx_2_re = 1.0 / tune_B.hI_idx_2_re;
              tune_B.rLast = 0.0;
            } else if (tune_B.hI_idx_2_re == 0.0) {
              tune_B.hD_idx_2_re = 0.0;
              tune_B.rLast = -(1.0 / tune_B.rG3[2]);
            } else {
              tune_B.Kd = fabs(tune_B.hI_idx_2_re);
              tune_B.rLast = fabs(tune_B.rG3[2]);
              if (tune_B.Kd > tune_B.rLast) {
                tune_B.rLast = tune_B.rG3[2] / tune_B.hI_idx_2_re;
                tune_B.Kd = tune_B.rLast * tune_B.rG3[2] + tune_B.hI_idx_2_re;
                tune_B.hD_idx_2_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
                tune_B.rLast = (0.0 - tune_B.rLast) / tune_B.Kd;
              } else if (tune_B.rLast == tune_B.Kd) {
                tune_B.sgnbr = tune_B.hI_idx_2_re > 0.0 ? 0.5 : -0.5;
                tune_B.rLast = tune_B.rG3[2] > 0.0 ? 0.5 : -0.5;
                tune_B.hD_idx_2_re = (0.0 * tune_B.rLast + tune_B.sgnbr) /
                  tune_B.Kd;
                tune_B.rLast = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
              } else {
                tune_B.rLast = tune_B.hI_idx_2_re / tune_B.rG3[2];
                tune_B.Kd = tune_B.rLast * tune_B.hI_idx_2_re + tune_B.rG3[2];
                tune_B.hD_idx_2_re = tune_B.rLast / tune_B.Kd;
                tune_B.rLast = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
              }
            }
          } else {
            tune_B.hI_idx_2_re = 0.0 * frequencies[1];
            tune_B.hI_idx_2_im = tune_B.tau_l * frequencies[1];
            if (tune_B.hI_idx_2_im == 0.0) {
              if (frequencies[1] == 0.0) {
                tune_B.Ki = tune_B.hI_idx_2_re;
                tune_B.hD_idx_0_im = 0.0;
              } else if (tune_B.hI_idx_2_re == 0.0) {
                tune_B.Ki = 0.0;
                tune_B.hD_idx_0_im = frequencies[1];
              } else {
                tune_B.Ki = (rtNaN);
                tune_B.hD_idx_0_im = frequencies[1];
              }
            } else {
              tune_B.rLast = fabs(tune_B.hI_idx_2_im);
              if (tune_B.rLast < 1.0) {
                tune_B.Kd = tune_B.hI_idx_2_im * tune_B.hI_idx_2_im + 1.0;
                tune_B.Ki = (tune_B.hI_idx_2_im * frequencies[1] +
                             tune_B.hI_idx_2_re) / tune_B.Kd;
                tune_B.hD_idx_0_im = (frequencies[1] - tune_B.hI_idx_2_im *
                                      tune_B.hI_idx_2_re) / tune_B.Kd;
              } else if (tune_B.rLast == 1.0) {
                tune_B.rLast = tune_B.hI_idx_2_im > 0.0 ? 0.5 : -0.5;
                tune_B.Ki = tune_B.hI_idx_2_re * 0.5 + frequencies[1] *
                  tune_B.rLast;
                tune_B.hD_idx_0_im = frequencies[1] * 0.5 - tune_B.hI_idx_2_re *
                  tune_B.rLast;
              } else {
                tune_B.rLast = 1.0 / tune_B.hI_idx_2_im;
                tune_B.Kd = tune_B.hI_idx_2_im + tune_B.rLast;
                tune_B.Ki = (tune_B.rLast * tune_B.hI_idx_2_re + frequencies[1])
                  / tune_B.Kd;
                tune_B.hD_idx_0_im = (tune_B.rLast * frequencies[1] -
                                      tune_B.hI_idx_2_re) / tune_B.Kd;
              }
            }

            tune_B.hI_idx_2_re = 0.0 * frequencies[2];
            tune_B.hI_idx_2_im = tune_B.tau_l * frequencies[2];
            if (tune_B.hI_idx_2_im == 0.0) {
              if (frequencies[2] == 0.0) {
                tune_B.hD_idx_1_re = tune_B.hI_idx_2_re;
                tune_B.hD_idx_1_im = 0.0;
              } else if (tune_B.hI_idx_2_re == 0.0) {
                tune_B.hD_idx_1_re = 0.0;
                tune_B.hD_idx_1_im = frequencies[2];
              } else {
                tune_B.hD_idx_1_re = (rtNaN);
                tune_B.hD_idx_1_im = frequencies[2];
              }
            } else {
              tune_B.rLast = fabs(tune_B.hI_idx_2_im);
              if (tune_B.rLast < 1.0) {
                tune_B.Kd = tune_B.hI_idx_2_im * tune_B.hI_idx_2_im + 1.0;
                tune_B.hD_idx_1_re = (tune_B.hI_idx_2_im * frequencies[2] +
                                      tune_B.hI_idx_2_re) / tune_B.Kd;
                tune_B.hD_idx_1_im = (frequencies[2] - tune_B.hI_idx_2_im *
                                      tune_B.hI_idx_2_re) / tune_B.Kd;
              } else if (tune_B.rLast == 1.0) {
                tune_B.rLast = tune_B.hI_idx_2_im > 0.0 ? 0.5 : -0.5;
                tune_B.hD_idx_1_re = tune_B.hI_idx_2_re * 0.5 + frequencies[2] *
                  tune_B.rLast;
                tune_B.hD_idx_1_im = frequencies[2] * 0.5 - tune_B.hI_idx_2_re *
                  tune_B.rLast;
              } else {
                tune_B.rLast = 1.0 / tune_B.hI_idx_2_im;
                tune_B.Kd = tune_B.hI_idx_2_im + tune_B.rLast;
                tune_B.hD_idx_1_re = (tune_B.rLast * tune_B.hI_idx_2_re +
                                      frequencies[2]) / tune_B.Kd;
                tune_B.hD_idx_1_im = (tune_B.rLast * frequencies[2] -
                                      tune_B.hI_idx_2_re) / tune_B.Kd;
              }
            }

            tune_B.hI_idx_2_re = 0.0 * frequencies[3];
            tune_B.hI_idx_2_im = tune_B.tau_l * frequencies[3];
            if (tune_B.hI_idx_2_im == 0.0) {
              if (frequencies[3] == 0.0) {
                tune_B.hD_idx_2_re = tune_B.hI_idx_2_re;
                tune_B.rLast = 0.0;
              } else if (tune_B.hI_idx_2_re == 0.0) {
                tune_B.hD_idx_2_re = 0.0;
                tune_B.rLast = frequencies[3];
              } else {
                tune_B.hD_idx_2_re = (rtNaN);
                tune_B.rLast = frequencies[3];
              }
            } else {
              tune_B.rLast = fabs(tune_B.hI_idx_2_im);
              if (tune_B.rLast < 1.0) {
                tune_B.Kd = tune_B.hI_idx_2_im * tune_B.hI_idx_2_im + 1.0;
                tune_B.hD_idx_2_re = (tune_B.hI_idx_2_im * frequencies[3] +
                                      tune_B.hI_idx_2_re) / tune_B.Kd;
                tune_B.rLast = (frequencies[3] - tune_B.hI_idx_2_im *
                                tune_B.hI_idx_2_re) / tune_B.Kd;
              } else if (tune_B.rLast == 1.0) {
                tune_B.rLast = tune_B.hI_idx_2_im > 0.0 ? 0.5 : -0.5;
                tune_B.hD_idx_2_re = tune_B.hI_idx_2_re * 0.5 + frequencies[3] *
                  tune_B.rLast;
                tune_B.rLast = frequencies[3] * 0.5 - tune_B.hI_idx_2_re *
                  tune_B.rLast;
              } else {
                tune_B.rLast = 1.0 / tune_B.hI_idx_2_im;
                tune_B.Kd = tune_B.hI_idx_2_im + tune_B.rLast;
                tune_B.hD_idx_2_re = (tune_B.rLast * tune_B.hI_idx_2_re +
                                      frequencies[3]) / tune_B.Kd;
                tune_B.rLast = (tune_B.rLast * frequencies[3] -
                                tune_B.hI_idx_2_re) / tune_B.Kd;
              }
            }
          }

          tune_B.responses_l[6] = tune_B.gammaHigh * tune_B.Ki -
            tune_B.responses_tmp_tmp * tune_B.hD_idx_0_im;
          tune_B.responses_l[9] = tune_B.responses_tmp_tmp * tune_B.Ki +
            tune_B.gammaHigh * tune_B.hD_idx_0_im;
          tune_B.responses_l[7] = tune_B.hI_idx_0_re * tune_B.hD_idx_1_re -
            tune_B.hI_idx_0_im * tune_B.hD_idx_1_im;
          tune_B.responses_l[10] = tune_B.hI_idx_0_im * tune_B.hD_idx_1_re +
            tune_B.hI_idx_0_re * tune_B.hD_idx_1_im;
          tune_B.responses_l[8] = tune_B.hI_idx_1_re * tune_B.hD_idx_2_re -
            tune_B.hI_idx_1_im * tune_B.rLast;
          tune_B.responses_l[11] = tune_B.hI_idx_1_im * tune_B.hD_idx_2_re +
            tune_B.hI_idx_1_re * tune_B.rLast;
          tune_blkdiag_f(tune_B.responses_l, tune_B.b_A);
          tune_B.b_A[6] = tune_maximum_b(&tune_B.f[50]);
          for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
            tune_B.dcv[tune_B.i_b].re = 1.0;
            tune_B.dcv[tune_B.i_b].im = tune_B.wHigh[tune_B.i_b] * tune_B.tau_l;
          }

          tune_abs_lb(tune_B.dcv, tune_B.wLow);
          for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
            tune_B.f_c[tune_B.i_b] = tune_B.f[tune_B.i_b + 50] *
              tune_B.wHigh[tune_B.i_b] / tune_B.wLow[tune_B.i_b];
          }

          tune_B.b_A[13] = tune_maximum_b(tune_B.f_c);
          for (tune_B.i_b = 0; tune_B.i_b < 21; tune_B.i_b++) {
            tune_B.b_A_n[tune_B.i_b] = tune_B.b_A[tune_B.i_b] * (real_T)
              e[tune_B.i_b];
          }

          tune_utilLSQFixedSizeData_mbll(tune_B.b_A_n, tune_B.b, &tune_B.xtau[3 *
            tune_B.imin], &tune_B.gap[tune_B.imin]);
        }

        if ((tune_maximum_bt0(tune_B.gap) - tune_minimum_n(tune_B.gap)) /
            tune_mean(tune_B.gap) < 0.1) {
          tune_B.imin = 0;
        } else {
          tune_minimum_nv(tune_B.gap, &tune_B.rLast, &tune_B.i_b);
          tune_B.imin = tune_B.i_b - 1;
        }

        tune_B.Kd = tune_B.xtau[3 * tune_B.imin + 1];
        if (tune_B.Kd == 0.0) {
          *P = tune_B.xtau[3 * tune_B.imin];
          tune_B.Ki = 0.0;
          tune_B.rLast = 0.0;
        } else {
          *P = tune_B.xtau[3 * tune_B.imin];
          tune_B.Ki = 0.0;
          tune_B.rLast = tune_B.tau[tune_B.imin];
        }
      }
    }
    break;

   case 6:
    if (tune_B.IsDiscrete) {
      if (tune_B.rG3[0] == 0.0) {
        tune_B.Ki = 1.0 / tune_B.realhD;
        tune_B.hD_idx_0_im = 0.0;
      } else if (tune_B.realhD == 0.0) {
        tune_B.Ki = 0.0;
        tune_B.hD_idx_0_im = -(1.0 / tune_B.rG3[0]);
      } else {
        tune_B.Kd = fabs(tune_B.realhD);
        tune_B.rLast = fabs(tune_B.rG3[0]);
        if (tune_B.Kd > tune_B.rLast) {
          tune_B.rLast = tune_B.rG3[0] / tune_B.realhD;
          tune_B.Kd = tune_B.rLast * tune_B.rG3[0] + tune_B.realhD;
          tune_B.Ki = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
          tune_B.hD_idx_0_im = (0.0 - tune_B.rLast) / tune_B.Kd;
        } else if (tune_B.rLast == tune_B.Kd) {
          tune_B.sgnbr = tune_B.realhD > 0.0 ? 0.5 : -0.5;
          tune_B.rLast = tune_B.rG3[0] > 0.0 ? 0.5 : -0.5;
          tune_B.Ki = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
          tune_B.hD_idx_0_im = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
        } else {
          tune_B.rLast = tune_B.realhD / tune_B.rG3[0];
          tune_B.Kd = tune_B.rLast * tune_B.realhD + tune_B.rG3[0];
          tune_B.Ki = tune_B.rLast / tune_B.Kd;
          tune_B.hD_idx_0_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
        }
      }

      if (tune_B.rG3[1] == 0.0) {
        tune_B.hD_idx_1_re = 1.0 / tune_B.realhD;
        tune_B.hD_idx_1_im = 0.0;
      } else if (tune_B.realhD == 0.0) {
        tune_B.hD_idx_1_re = 0.0;
        tune_B.hD_idx_1_im = -(1.0 / tune_B.rG3[1]);
      } else {
        tune_B.Kd = fabs(tune_B.realhD);
        tune_B.rLast = fabs(tune_B.rG3[1]);
        if (tune_B.Kd > tune_B.rLast) {
          tune_B.rLast = tune_B.rG3[1] / tune_B.realhD;
          tune_B.Kd = tune_B.rLast * tune_B.rG3[1] + tune_B.realhD;
          tune_B.hD_idx_1_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
          tune_B.hD_idx_1_im = (0.0 - tune_B.rLast) / tune_B.Kd;
        } else if (tune_B.rLast == tune_B.Kd) {
          tune_B.sgnbr = tune_B.realhD > 0.0 ? 0.5 : -0.5;
          tune_B.rLast = tune_B.rG3[1] > 0.0 ? 0.5 : -0.5;
          tune_B.hD_idx_1_re = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
          tune_B.hD_idx_1_im = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
        } else {
          tune_B.rLast = tune_B.realhD / tune_B.rG3[1];
          tune_B.Kd = tune_B.rLast * tune_B.realhD + tune_B.rG3[1];
          tune_B.hD_idx_1_re = tune_B.rLast / tune_B.Kd;
          tune_B.hD_idx_1_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
        }
      }

      if (tune_B.rG3[2] == 0.0) {
        tune_B.hD_idx_2_re = 1.0 / tune_B.realhD;
        tune_B.rLast = 0.0;
      } else if (tune_B.realhD == 0.0) {
        tune_B.hD_idx_2_re = 0.0;
        tune_B.rLast = -(1.0 / tune_B.rG3[2]);
      } else {
        tune_B.Kd = fabs(tune_B.realhD);
        tune_B.rLast = fabs(tune_B.rG3[2]);
        if (tune_B.Kd > tune_B.rLast) {
          tune_B.rLast = tune_B.rG3[2] / tune_B.realhD;
          tune_B.Kd = tune_B.rLast * tune_B.rG3[2] + tune_B.realhD;
          tune_B.hD_idx_2_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
          tune_B.rLast = (0.0 - tune_B.rLast) / tune_B.Kd;
        } else if (tune_B.rLast == tune_B.Kd) {
          tune_B.sgnbr = tune_B.realhD > 0.0 ? 0.5 : -0.5;
          tune_B.rLast = tune_B.rG3[2] > 0.0 ? 0.5 : -0.5;
          tune_B.hD_idx_2_re = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
          tune_B.rLast = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
        } else {
          tune_B.rLast = tune_B.realhD / tune_B.rG3[2];
          tune_B.Kd = tune_B.rLast * tune_B.realhD + tune_B.rG3[2];
          tune_B.hD_idx_2_re = tune_B.rLast / tune_B.Kd;
          tune_B.rLast = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
        }
      }
    } else {
      tune_B.Ki = 0.0;
      tune_B.hD_idx_0_im = frequencies[1];
      tune_B.hD_idx_1_re = 0.0;
      tune_B.hD_idx_1_im = frequencies[2];
      tune_B.hD_idx_2_re = 0.0;
      tune_B.rLast = frequencies[3];
    }

    tune_B.responses[0] = responses[1].re;
    tune_B.responses[6] = responses[1].re * tune_B.hI_idx_0_re - responses[1].im
      * tune_B.hI_idx_0_im;
    tune_B.responses[12] = responses[1].re * tune_B.Ki - responses[1].im *
      tune_B.hD_idx_0_im;
    tune_B.responses[3] = responses[1].im;
    tune_B.responses[9] = responses[1].re * tune_B.hI_idx_0_im + responses[1].im
      * tune_B.hI_idx_0_re;
    tune_B.responses[15] = responses[1].im * tune_B.Ki + responses[1].re *
      tune_B.hD_idx_0_im;
    tune_B.responses[1] = responses[2].re;
    tune_B.responses[7] = responses[2].re * tune_B.hI_idx_1_re - responses[2].im
      * tune_B.hI_idx_1_im;
    tune_B.responses[13] = responses[2].re * tune_B.hD_idx_1_re - responses[2].
      im * tune_B.hD_idx_1_im;
    tune_B.responses[4] = responses[2].im;
    tune_B.responses[10] = responses[2].re * tune_B.hI_idx_1_im + responses[2].
      im * tune_B.hI_idx_1_re;
    tune_B.responses[16] = responses[2].im * tune_B.hD_idx_1_re + responses[2].
      re * tune_B.hD_idx_1_im;
    tune_B.responses[2] = responses[3].re;
    tune_B.responses[8] = responses[3].re * tune_B.hI_idx_2_re - responses[3].im
      * tune_B.hI_idx_2_im;
    tune_B.responses[14] = responses[3].re * tune_B.hD_idx_2_re - responses[3].
      im * tune_B.rLast;
    tune_B.responses[5] = responses[3].im;
    tune_B.responses[11] = responses[3].re * tune_B.hI_idx_2_im + responses[3].
      im * tune_B.hI_idx_2_re;
    tune_B.responses[17] = responses[3].im * tune_B.hD_idx_2_re + responses[3].
      re * tune_B.rLast;
    tune_blkdiag_f0i(tune_B.responses, tune_B.d_A);
    tune_B.d_A[14] = -tune_minimum(&tune_B.f[0]);
    tune_B.d_A[7] = tune_maximum_b(&tune_B.f[50]);
    for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
      tune_B.f_c[tune_B.i_b] = tune_B.f[tune_B.i_b + 50] /
        tune_B.wHigh[tune_B.i_b];
    }

    tune_B.d_A[15] = tune_maximum_b(tune_B.f_c);
    for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
      tune_B.f_c[tune_B.i_b] = tune_B.f[tune_B.i_b + 50] *
        tune_B.wHigh[tune_B.i_b];
    }

    tune_B.d_A[23] = tune_maximum_b(tune_B.f_c);
    for (tune_B.i_b = 0; tune_B.i_b < 40; tune_B.i_b++) {
      tune_B.d_A_p[tune_B.i_b] = tune_B.d_A[tune_B.i_b] * (real_T)h[tune_B.i_b];
    }

    tune_B.b_b[0] = tune_B.hL3[0].re;
    tune_B.b_b[3] = tune_B.hL3[0].im;
    tune_B.b_b[1] = tune_B.hL3[1].re * 5.0;
    tune_B.b_b[4] = tune_B.hL3[1].im * 5.0;
    tune_B.b_b[2] = tune_B.hL3[2].re;
    tune_B.b_b[5] = tune_B.hL3[2].im;
    tune_B.b_b[6] = -frequencies[1];
    tune_B.b_b[7] = tune_B.gammaHigh;
    tune_utilLSQFixedSizeData_mbllg(tune_B.d_A_p, tune_B.b_b, tune_B.c_x);
    *P = tune_B.c_x[0];
    tune_B.Ki = tune_B.c_x[1];
    tune_B.Kd = tune_B.c_x[2];
    tune_B.rLast = 0.0;
    break;

   case 7:
    tune_computeTAU(tune_B.IsDiscrete, &frequencies[1], Ts, DF, tune_B.tau);
    tune_B.b_b[0] = tune_B.hL3[0].re;
    tune_B.b_b[3] = tune_B.hL3[0].im;
    tune_B.b_b[1] = tune_B.hL3[1].re * 5.0;
    tune_B.b_b[4] = tune_B.hL3[1].im * 5.0;
    tune_B.b_b[2] = tune_B.hL3[2].re;
    tune_B.b_b[5] = tune_B.hL3[2].im;
    tune_B.b_b[6] = -frequencies[1];
    tune_B.b_b[7] = tune_B.gammaHigh;
    tune_B.gammaHigh = responses[1].re;
    tune_B.responses[0] = responses[1].re;
    tune_B.responses[6] = responses[1].re * tune_B.hI_idx_0_re - responses[1].im
      * tune_B.hI_idx_0_im;
    tune_B.responses_tmp_tmp = responses[1].im;
    tune_B.responses[3] = responses[1].im;
    tune_B.responses[9] = responses[1].re * tune_B.hI_idx_0_im + responses[1].im
      * tune_B.hI_idx_0_re;
    tune_B.hI_idx_0_re = responses[2].re;
    tune_B.responses[1] = responses[2].re;
    tune_B.responses[7] = responses[2].re * tune_B.hI_idx_1_re - responses[2].im
      * tune_B.hI_idx_1_im;
    tune_B.hI_idx_0_im = responses[2].im;
    tune_B.responses[4] = responses[2].im;
    tune_B.responses[10] = responses[2].re * tune_B.hI_idx_1_im + responses[2].
      im * tune_B.hI_idx_1_re;
    tune_B.hI_idx_1_re = responses[3].re;
    tune_B.responses[2] = responses[3].re;
    tune_B.responses[8] = responses[3].re * tune_B.hI_idx_2_re - responses[3].im
      * tune_B.hI_idx_2_im;
    tune_B.hI_idx_1_im = responses[3].im;
    tune_B.responses[5] = responses[3].im;
    tune_B.responses[11] = responses[3].re * tune_B.hI_idx_2_im + responses[3].
      im * tune_B.hI_idx_2_re;
    for (tune_B.imin = 0; tune_B.imin < 20; tune_B.imin++) {
      tune_B.tau_l = tune_B.tau[tune_B.imin];
      if (tune_B.IsDiscrete) {
        tune_B.hI_idx_2_re = tune_B.tau_l + tune_B.realhD;
        if (tune_B.rG3[0] == 0.0) {
          tune_B.Ki = 1.0 / tune_B.hI_idx_2_re;
          tune_B.hD_idx_0_im = 0.0;
        } else if (tune_B.hI_idx_2_re == 0.0) {
          tune_B.Ki = 0.0;
          tune_B.hD_idx_0_im = -(1.0 / tune_B.rG3[0]);
        } else {
          tune_B.Kd = fabs(tune_B.hI_idx_2_re);
          tune_B.rLast = fabs(tune_B.rG3[0]);
          if (tune_B.Kd > tune_B.rLast) {
            tune_B.rLast = tune_B.rG3[0] / tune_B.hI_idx_2_re;
            tune_B.Kd = tune_B.rLast * tune_B.rG3[0] + tune_B.hI_idx_2_re;
            tune_B.Ki = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
            tune_B.hD_idx_0_im = (0.0 - tune_B.rLast) / tune_B.Kd;
          } else if (tune_B.rLast == tune_B.Kd) {
            tune_B.sgnbr = tune_B.hI_idx_2_re > 0.0 ? 0.5 : -0.5;
            tune_B.rLast = tune_B.rG3[0] > 0.0 ? 0.5 : -0.5;
            tune_B.Ki = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
            tune_B.hD_idx_0_im = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
          } else {
            tune_B.rLast = tune_B.hI_idx_2_re / tune_B.rG3[0];
            tune_B.Kd = tune_B.rLast * tune_B.hI_idx_2_re + tune_B.rG3[0];
            tune_B.Ki = tune_B.rLast / tune_B.Kd;
            tune_B.hD_idx_0_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
          }
        }

        if (tune_B.rG3[1] == 0.0) {
          tune_B.hD_idx_1_re = 1.0 / tune_B.hI_idx_2_re;
          tune_B.hD_idx_1_im = 0.0;
        } else if (tune_B.hI_idx_2_re == 0.0) {
          tune_B.hD_idx_1_re = 0.0;
          tune_B.hD_idx_1_im = -(1.0 / tune_B.rG3[1]);
        } else {
          tune_B.Kd = fabs(tune_B.hI_idx_2_re);
          tune_B.rLast = fabs(tune_B.rG3[1]);
          if (tune_B.Kd > tune_B.rLast) {
            tune_B.rLast = tune_B.rG3[1] / tune_B.hI_idx_2_re;
            tune_B.Kd = tune_B.rLast * tune_B.rG3[1] + tune_B.hI_idx_2_re;
            tune_B.hD_idx_1_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
            tune_B.hD_idx_1_im = (0.0 - tune_B.rLast) / tune_B.Kd;
          } else if (tune_B.rLast == tune_B.Kd) {
            tune_B.sgnbr = tune_B.hI_idx_2_re > 0.0 ? 0.5 : -0.5;
            tune_B.rLast = tune_B.rG3[1] > 0.0 ? 0.5 : -0.5;
            tune_B.hD_idx_1_re = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
            tune_B.hD_idx_1_im = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
          } else {
            tune_B.rLast = tune_B.hI_idx_2_re / tune_B.rG3[1];
            tune_B.Kd = tune_B.rLast * tune_B.hI_idx_2_re + tune_B.rG3[1];
            tune_B.hD_idx_1_re = tune_B.rLast / tune_B.Kd;
            tune_B.hD_idx_1_im = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
          }
        }

        if (tune_B.rG3[2] == 0.0) {
          tune_B.hD_idx_2_re = 1.0 / tune_B.hI_idx_2_re;
          tune_B.rLast = 0.0;
        } else if (tune_B.hI_idx_2_re == 0.0) {
          tune_B.hD_idx_2_re = 0.0;
          tune_B.rLast = -(1.0 / tune_B.rG3[2]);
        } else {
          tune_B.Kd = fabs(tune_B.hI_idx_2_re);
          tune_B.rLast = fabs(tune_B.rG3[2]);
          if (tune_B.Kd > tune_B.rLast) {
            tune_B.rLast = tune_B.rG3[2] / tune_B.hI_idx_2_re;
            tune_B.Kd = tune_B.rLast * tune_B.rG3[2] + tune_B.hI_idx_2_re;
            tune_B.hD_idx_2_re = (tune_B.rLast * 0.0 + 1.0) / tune_B.Kd;
            tune_B.rLast = (0.0 - tune_B.rLast) / tune_B.Kd;
          } else if (tune_B.rLast == tune_B.Kd) {
            tune_B.sgnbr = tune_B.hI_idx_2_re > 0.0 ? 0.5 : -0.5;
            tune_B.rLast = tune_B.rG3[2] > 0.0 ? 0.5 : -0.5;
            tune_B.hD_idx_2_re = (0.0 * tune_B.rLast + tune_B.sgnbr) / tune_B.Kd;
            tune_B.rLast = (0.0 * tune_B.sgnbr - tune_B.rLast) / tune_B.Kd;
          } else {
            tune_B.rLast = tune_B.hI_idx_2_re / tune_B.rG3[2];
            tune_B.Kd = tune_B.rLast * tune_B.hI_idx_2_re + tune_B.rG3[2];
            tune_B.hD_idx_2_re = tune_B.rLast / tune_B.Kd;
            tune_B.rLast = (tune_B.rLast * 0.0 - 1.0) / tune_B.Kd;
          }
        }
      } else {
        tune_B.hI_idx_2_re = 0.0 * frequencies[1];
        tune_B.hI_idx_2_im = tune_B.tau_l * frequencies[1];
        if (tune_B.hI_idx_2_im == 0.0) {
          if (frequencies[1] == 0.0) {
            tune_B.Ki = tune_B.hI_idx_2_re;
            tune_B.hD_idx_0_im = 0.0;
          } else if (tune_B.hI_idx_2_re == 0.0) {
            tune_B.Ki = 0.0;
            tune_B.hD_idx_0_im = frequencies[1];
          } else {
            tune_B.Ki = (rtNaN);
            tune_B.hD_idx_0_im = frequencies[1];
          }
        } else {
          tune_B.rLast = fabs(tune_B.hI_idx_2_im);
          if (tune_B.rLast < 1.0) {
            tune_B.Kd = tune_B.hI_idx_2_im * tune_B.hI_idx_2_im + 1.0;
            tune_B.Ki = (tune_B.hI_idx_2_im * frequencies[1] +
                         tune_B.hI_idx_2_re) / tune_B.Kd;
            tune_B.hD_idx_0_im = (frequencies[1] - tune_B.hI_idx_2_im *
                                  tune_B.hI_idx_2_re) / tune_B.Kd;
          } else if (tune_B.rLast == 1.0) {
            tune_B.rLast = tune_B.hI_idx_2_im > 0.0 ? 0.5 : -0.5;
            tune_B.Ki = tune_B.hI_idx_2_re * 0.5 + frequencies[1] * tune_B.rLast;
            tune_B.hD_idx_0_im = frequencies[1] * 0.5 - tune_B.hI_idx_2_re *
              tune_B.rLast;
          } else {
            tune_B.rLast = 1.0 / tune_B.hI_idx_2_im;
            tune_B.Kd = tune_B.hI_idx_2_im + tune_B.rLast;
            tune_B.Ki = (tune_B.rLast * tune_B.hI_idx_2_re + frequencies[1]) /
              tune_B.Kd;
            tune_B.hD_idx_0_im = (tune_B.rLast * frequencies[1] -
                                  tune_B.hI_idx_2_re) / tune_B.Kd;
          }
        }

        tune_B.hI_idx_2_re = 0.0 * frequencies[2];
        tune_B.hI_idx_2_im = tune_B.tau_l * frequencies[2];
        if (tune_B.hI_idx_2_im == 0.0) {
          if (frequencies[2] == 0.0) {
            tune_B.hD_idx_1_re = tune_B.hI_idx_2_re;
            tune_B.hD_idx_1_im = 0.0;
          } else if (tune_B.hI_idx_2_re == 0.0) {
            tune_B.hD_idx_1_re = 0.0;
            tune_B.hD_idx_1_im = frequencies[2];
          } else {
            tune_B.hD_idx_1_re = (rtNaN);
            tune_B.hD_idx_1_im = frequencies[2];
          }
        } else {
          tune_B.rLast = fabs(tune_B.hI_idx_2_im);
          if (tune_B.rLast < 1.0) {
            tune_B.Kd = tune_B.hI_idx_2_im * tune_B.hI_idx_2_im + 1.0;
            tune_B.hD_idx_1_re = (tune_B.hI_idx_2_im * frequencies[2] +
                                  tune_B.hI_idx_2_re) / tune_B.Kd;
            tune_B.hD_idx_1_im = (frequencies[2] - tune_B.hI_idx_2_im *
                                  tune_B.hI_idx_2_re) / tune_B.Kd;
          } else if (tune_B.rLast == 1.0) {
            tune_B.rLast = tune_B.hI_idx_2_im > 0.0 ? 0.5 : -0.5;
            tune_B.hD_idx_1_re = tune_B.hI_idx_2_re * 0.5 + frequencies[2] *
              tune_B.rLast;
            tune_B.hD_idx_1_im = frequencies[2] * 0.5 - tune_B.hI_idx_2_re *
              tune_B.rLast;
          } else {
            tune_B.rLast = 1.0 / tune_B.hI_idx_2_im;
            tune_B.Kd = tune_B.hI_idx_2_im + tune_B.rLast;
            tune_B.hD_idx_1_re = (tune_B.rLast * tune_B.hI_idx_2_re +
                                  frequencies[2]) / tune_B.Kd;
            tune_B.hD_idx_1_im = (tune_B.rLast * frequencies[2] -
                                  tune_B.hI_idx_2_re) / tune_B.Kd;
          }
        }

        tune_B.hI_idx_2_re = 0.0 * frequencies[3];
        tune_B.hI_idx_2_im = tune_B.tau_l * frequencies[3];
        if (tune_B.hI_idx_2_im == 0.0) {
          if (frequencies[3] == 0.0) {
            tune_B.hD_idx_2_re = tune_B.hI_idx_2_re;
            tune_B.rLast = 0.0;
          } else if (tune_B.hI_idx_2_re == 0.0) {
            tune_B.hD_idx_2_re = 0.0;
            tune_B.rLast = frequencies[3];
          } else {
            tune_B.hD_idx_2_re = (rtNaN);
            tune_B.rLast = frequencies[3];
          }
        } else {
          tune_B.rLast = fabs(tune_B.hI_idx_2_im);
          if (tune_B.rLast < 1.0) {
            tune_B.Kd = tune_B.hI_idx_2_im * tune_B.hI_idx_2_im + 1.0;
            tune_B.hD_idx_2_re = (tune_B.hI_idx_2_im * frequencies[3] +
                                  tune_B.hI_idx_2_re) / tune_B.Kd;
            tune_B.rLast = (frequencies[3] - tune_B.hI_idx_2_im *
                            tune_B.hI_idx_2_re) / tune_B.Kd;
          } else if (tune_B.rLast == 1.0) {
            tune_B.rLast = tune_B.hI_idx_2_im > 0.0 ? 0.5 : -0.5;
            tune_B.hD_idx_2_re = tune_B.hI_idx_2_re * 0.5 + frequencies[3] *
              tune_B.rLast;
            tune_B.rLast = frequencies[3] * 0.5 - tune_B.hI_idx_2_re *
              tune_B.rLast;
          } else {
            tune_B.rLast = 1.0 / tune_B.hI_idx_2_im;
            tune_B.Kd = tune_B.hI_idx_2_im + tune_B.rLast;
            tune_B.hD_idx_2_re = (tune_B.rLast * tune_B.hI_idx_2_re +
                                  frequencies[3]) / tune_B.Kd;
            tune_B.rLast = (tune_B.rLast * frequencies[3] - tune_B.hI_idx_2_re) /
              tune_B.Kd;
          }
        }
      }

      tune_B.responses[12] = tune_B.gammaHigh * tune_B.Ki -
        tune_B.responses_tmp_tmp * tune_B.hD_idx_0_im;
      tune_B.responses[15] = tune_B.responses_tmp_tmp * tune_B.Ki +
        tune_B.gammaHigh * tune_B.hD_idx_0_im;
      tune_B.responses[13] = tune_B.hI_idx_0_re * tune_B.hD_idx_1_re -
        tune_B.hI_idx_0_im * tune_B.hD_idx_1_im;
      tune_B.responses[16] = tune_B.hI_idx_0_im * tune_B.hD_idx_1_re +
        tune_B.hI_idx_0_re * tune_B.hD_idx_1_im;
      tune_B.responses[14] = tune_B.hI_idx_1_re * tune_B.hD_idx_2_re -
        tune_B.hI_idx_1_im * tune_B.rLast;
      tune_B.responses[17] = tune_B.hI_idx_1_im * tune_B.hD_idx_2_re +
        tune_B.hI_idx_1_re * tune_B.rLast;
      tune_blkdiag_f0i(tune_B.responses, tune_B.d_A);
      tune_B.d_A[14] = -tune_minimum(&tune_B.f[0]);
      tune_B.d_A[7] = tune_maximum_b(&tune_B.f[50]);
      for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
        tune_B.rLast = tune_B.wHigh[tune_B.i_b];
        tune_B.f_c[tune_B.i_b] = tune_B.f[tune_B.i_b + 50] / tune_B.rLast;
        tune_B.dcv[tune_B.i_b].re = 1.0;
        tune_B.dcv[tune_B.i_b].im = tune_B.rLast * tune_B.tau_l;
      }

      tune_B.d_A[15] = tune_maximum_b(tune_B.f_c);
      tune_abs_lb(tune_B.dcv, tune_B.wLow);
      for (tune_B.i_b = 0; tune_B.i_b < 50; tune_B.i_b++) {
        tune_B.f_c[tune_B.i_b] = tune_B.f[tune_B.i_b + 50] *
          tune_B.wHigh[tune_B.i_b] / tune_B.wLow[tune_B.i_b];
      }

      tune_B.d_A[23] = tune_maximum_b(tune_B.f_c);
      for (tune_B.i_b = 0; tune_B.i_b < 40; tune_B.i_b++) {
        tune_B.d_A_p[tune_B.i_b] = tune_B.d_A[tune_B.i_b] * (real_T)h[tune_B.i_b];
      }

      tun_utilLSQFixedSizeData_mbllga(tune_B.d_A_p, tune_B.b_b, &tune_B.c_xtau[5
        * tune_B.imin], &tune_B.gap[tune_B.imin]);
    }

    if ((tune_maximum_bt0(tune_B.gap) - tune_minimum_n(tune_B.gap)) / tune_mean
        (tune_B.gap) < 0.1) {
      tune_B.imin = 0;
    } else {
      tune_minimum_nv(tune_B.gap, &tune_B.rLast, &tune_B.i_b);
      tune_B.imin = tune_B.i_b - 1;
    }

    tune_B.Kd = tune_B.c_xtau[5 * tune_B.imin + 2];
    if (tune_B.Kd == 0.0) {
      *P = tune_B.c_xtau[5 * tune_B.imin];
      tune_B.Ki = tune_B.c_xtau[5 * tune_B.imin + 1];
      tune_B.Kd = 0.0;
      tune_B.rLast = 0.0;
    } else {
      *P = tune_B.c_xtau[5 * tune_B.imin];
      tune_B.Ki = tune_B.c_xtau[5 * tune_B.imin + 1];
      tune_B.rLast = tune_B.tau[tune_B.imin];
    }
    break;

   default:
    *P = 0.0;
    tune_B.Ki = 0.0;
    tune_B.Kd = 0.0;
    tune_B.rLast = 0.0;
    break;
  }

  *P *= LoopSign;
  tune_B.Ki *= LoopSign;
  tune_B.Kd *= LoopSign;
  if (form == 1) {
    *b_I = tune_B.Ki;
    *D = tune_B.Kd;
    if (tune_B.rLast == 0.0) {
      *N = 100.0;
    } else {
      *N = 1.0 / tune_B.rLast;
    }
  } else {
    if (*P == 0.0) {
      *b_I = 0.0;
      *D = 0.0;
    } else {
      *b_I = tune_B.Ki / *P;
      *D = tune_B.Kd / *P;
    }

    if (tune_B.rLast == 0.0) {
      *N = 100.0;
    } else {
      *N = 1.0 / tune_B.rLast;
    }
  }

  if (frequencies[2] == 0.0) {
    tune_B.realhD = tune_B.Ki > 0.0 ? (rtInf) : tune_B.Ki < 0.0 ? (rtMinusInf) :
      (rtNaN);
    tune_B.Ki = 0.0;
  } else if (tune_B.Ki == 0.0) {
    tune_B.realhD = 0.0 / frequencies[2];
    tune_B.Ki = 0.0;
  } else {
    tune_B.realhD = 0.0;
    tune_B.Ki = -(tune_B.Ki / frequencies[2]);
  }

  tune_B.hI_idx_2_re = tune_B.Kd * 0.0;
  tune_B.hD_idx_0_im = tune_B.Kd * frequencies[2];
  tune_B.hI_idx_2_im = tune_B.rLast * frequencies[2];
  if (tune_B.hI_idx_2_im == 0.0) {
    if (tune_B.hD_idx_0_im == 0.0) {
      tune_B.hD_idx_1_re = tune_B.hI_idx_2_re;
      tune_B.hD_idx_0_im = 0.0;
    } else if (tune_B.hI_idx_2_re == 0.0) {
      tune_B.hD_idx_1_re = 0.0;
    } else {
      tune_B.hD_idx_1_re = (rtNaN);
    }
  } else {
    tune_B.rLast = fabs(tune_B.hI_idx_2_im);
    if (tune_B.rLast < 1.0) {
      tune_B.Kd = tune_B.hI_idx_2_im * tune_B.hI_idx_2_im + 1.0;
      tune_B.hD_idx_1_re = (tune_B.hI_idx_2_im * tune_B.hD_idx_0_im +
                            tune_B.hI_idx_2_re) / tune_B.Kd;
      tune_B.hD_idx_0_im = (tune_B.hD_idx_0_im - tune_B.hI_idx_2_im *
                            tune_B.hI_idx_2_re) / tune_B.Kd;
    } else if (tune_B.rLast == 1.0) {
      tune_B.rLast = tune_B.hI_idx_2_im > 0.0 ? 0.5 : -0.5;
      tune_B.hD_idx_1_re = tune_B.hI_idx_2_re * 0.5 + tune_B.hD_idx_0_im *
        tune_B.rLast;
      tune_B.hD_idx_0_im = tune_B.hD_idx_0_im * 0.5 - tune_B.hI_idx_2_re *
        tune_B.rLast;
    } else {
      tune_B.rLast = 1.0 / tune_B.hI_idx_2_im;
      tune_B.Kd = tune_B.hI_idx_2_im + tune_B.rLast;
      tune_B.hD_idx_1_re = (tune_B.rLast * tune_B.hI_idx_2_re +
                            tune_B.hD_idx_0_im) / tune_B.Kd;
      tune_B.hD_idx_0_im = (tune_B.rLast * tune_B.hD_idx_0_im -
                            tune_B.hI_idx_2_re) / tune_B.Kd;
    }
  }

  tune_B.rLast = (*P + tune_B.realhD) + tune_B.hD_idx_1_re;
  tune_B.Kd = tune_B.Ki + tune_B.hD_idx_0_im;
  tune_B.Kp.re = (tune_B.rLast * responses[2].re - tune_B.Kd * responses[2].im) *
    LoopSign;
  tune_B.Kp.im = (tune_B.rLast * responses[2].im + tune_B.Kd * responses[2].re) *
    LoopSign;
  *achievedPM = tune_computePM(tune_B.Kp);
}

/* Model step function */
void tune_step(void)
{
  /* Reset subsysRan breadcrumbs */
  srClearBC(tune_DW.ConvergenceCalculator_SubsysRan);

  /* Reset subsysRan breadcrumbs */
  srClearBC(tune_DW.PerturbationGenerator_SubsysRan);

  /* Reset subsysRan breadcrumbs */
  srClearBC(tune_DW.ResponseEstimation_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(tune_DW.GainsFromOnlineTuningModule_Sub);
  for (tune_B.i = 0; tune_B.i < 5; tune_B.i++) {
    /* Gain: '<S1>/GainWC' incorporates:
     *  Constant: '<S1>/bandwidth constant'
     */
    tune_B.w[tune_B.i] = tune_P.GainWC_Gain[tune_B.i] *
      tune_P.ClosedLoopPIDAutotuner_Bandwidt;
  }

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (tune_P.ManualSwitch_CurrentSetting == 1) {
    /* ZeroOrderHold: '<S1>/Zero-Order Hold' incorporates:
     *  Constant: '<Root>/Zero'
     */
    tune_B.startstop = tune_P.Zero_Value;
  } else {
    /* ZeroOrderHold: '<S1>/Zero-Order Hold' incorporates:
     *  Constant: '<Root>/One'
     */
    tune_B.startstop = tune_P.One_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Gain: '<S1>/GainTs' incorporates:
   *  SampleTimeMath: '<S1>/Weighted Ts'
   *
   * About '<S1>/Weighted Ts':
   *  y = K where K = ( w * Ts )
   */
  tune_B.GainTs = tune_P.GainTs_Gain * tune_P.WeightedTs_WtEt;

  /* Outputs for Enabled SubSystem: '<S12>/Perturbation Generator' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (tune_B.startstop > 0.0) {
    if (!tune_DW.PerturbationGenerator_MODE) {
      /* InitializeConditions for Sum: '<S17>/FixPt Sum1' incorporates:
       *  UnitDelay: '<S16>/Output'
       */
      tune_DW.Output_DSTATE = tune_P.Output_InitialCondition;
      tune_DW.PerturbationGenerator_MODE = true;
    }

    /* Signum: '<S14>/Sign' incorporates:
     *  Constant: '<S12>/has_integrator_constant1'
     */
    if (rtIsNaN(tune_P.has_integrator_constant1_Value)) {
      tune_B.Sum_c = tune_P.has_integrator_constant1_Value;
    } else if (tune_P.has_integrator_constant1_Value < 0.0) {
      tune_B.Sum_c = -1.0;
    } else {
      tune_B.Sum_c = (tune_P.has_integrator_constant1_Value > 0.0);
    }

    /* End of Signum: '<S14>/Sign' */

    /* Product: '<S14>/Product3' incorporates:
     *  Constant: '<S1>/sine Amp constant'
     */
    tune_B.SumofElements = tune_P.ClosedLoopPIDAutotuner_AmpSine * tune_B.Sum_c;

    /* Sum: '<S14>/Sum of Elements' */
    tune_B.Sum_c = -0.0;
    for (tune_B.i = 0; tune_B.i < 5; tune_B.i++) {
      /* Product: '<S14>/Product' incorporates:
       *  UnitDelay: '<S16>/Output'
       */
      tune_B.rtb_Product_a_o = tune_B.GainTs * (real_T)tune_DW.Output_DSTATE *
        tune_B.w[tune_B.i];

      /* Product: '<S14>/Product1' incorporates:
       *  Trigonometry: '<S14>/Trigonometric Function'
       */
      tune_B.Product1[tune_B.i] = sin(tune_B.rtb_Product_a_o) *
        tune_B.SumofElements;

      /* Product: '<S14>/Product2' incorporates:
       *  Trigonometry: '<S14>/Trigonometric Function1'
       */
      tune_B.Product2[tune_B.i] = cos(tune_B.rtb_Product_a_o) *
        tune_B.SumofElements;

      /* Sum: '<S14>/Sum of Elements' */
      tune_B.Sum_c += tune_B.Product1[tune_B.i];
    }

    /* Switch: '<S14>/Switch2' incorporates:
     *  Constant: '<S12>/has_integrator_constant1'
     *  Constant: '<S14>/zero_constant'
     */
    if (tune_P.has_integrator_constant1_Value > tune_P.Switch2_Threshold) {
      tune_B.rtb_Product_a_o = tune_P.zero_constant_Value;
    } else {
      tune_B.rtb_Product_a_o = tune_P.has_integrator_constant1_Value;
    }

    /* End of Switch: '<S14>/Switch2' */

    /* Sum: '<S14>/Sum' incorporates:
     *  Sum: '<S14>/Sum of Elements'
     */
    tune_B.Sum_p = tune_B.Sum_c + tune_B.rtb_Product_a_o;

    /* Sum: '<S17>/FixPt Sum1' incorporates:
     *  Constant: '<S17>/FixPt Constant'
     *  UnitDelay: '<S16>/Output'
     */
    tune_DW.Output_DSTATE += tune_P.FixPtConstant_Value;

    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S12>/has_integrator_constant1'
     */
    if (tune_P.has_integrator_constant1_Value > tune_P.Switch1_Threshold_i) {
      /* Switch: '<S14>/Switch1' incorporates:
       *  Constant: '<S14>/one_constant'
       */
      tune_B.Switch1 = tune_P.one_constant_Value;
    } else {
      /* Switch: '<S14>/Switch1' */
      tune_B.Switch1 = tune_P.has_integrator_constant1_Value;
    }

    /* End of Switch: '<S14>/Switch1' */

    /* Switch: '<S18>/FixPt Switch' */
    if (tune_DW.Output_DSTATE > tune_P.WrapToZero_Threshold) {
      /* Sum: '<S17>/FixPt Sum1' incorporates:
       *  Constant: '<S18>/Constant'
       *  UnitDelay: '<S16>/Output'
       */
      tune_DW.Output_DSTATE = tune_P.Constant_Value_ek;
    }

    /* End of Switch: '<S18>/FixPt Switch' */
    srUpdateBC(tune_DW.PerturbationGenerator_SubsysRan);
  } else {
    tune_DW.PerturbationGenerator_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S12>/Perturbation Generator' */
  if (tune_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Smart Motor Read' */
    DevicePresent(kDeviceTypeMotorSensor, 0);

    /* MATLABSystem: '<Root>/Smart Motor Read' */
    tune_B.SmartMotorRead = vexMotorPositionGet(0);
  }

  /* Delay: '<S7>/Enabled Delay Y' incorporates:
   *  ZeroOrderHold: '<S1>/Zero-Order Hold1'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&tune_PrevZCX.EnabledDelayY_Reset_ZCE,
               (tune_B.startstop)) != NO_ZCEVENT) {
    tune_DW.icLoad = true;
  }

  if (tune_DW.icLoad) {
    tune_DW.EnabledDelayY_DSTATE = tune_B.SmartMotorRead;
  }

  /* Delay: '<S7>/Enabled Delay Y' */
  tune_B.y = tune_DW.EnabledDelayY_DSTATE;
  if (tune_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<Root>/ref' */
    tune_B.ref = tune_P.ref_Value;

    /* Sum: '<Root>/Sum' */
    tune_B.Sum_o = tune_B.ref - tune_B.SmartMotorRead;

    /* Gain: '<S109>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S101>/Filter'
     *  Gain: '<S100>/Derivative Gain'
     *  Sum: '<S101>/SumD'
     */
    tune_B.FilterCoefficient = (tune_P.DiscretePIDController_D * tune_B.Sum_o -
      tune_DW.Filter_DSTATE) * tune_P.DiscretePIDController_N;

    /* Sum: '<S115>/Sum' incorporates:
     *  DiscreteIntegrator: '<S106>/Integrator'
     *  Gain: '<S111>/Proportional Gain'
     */
    tune_B.Sum = (tune_P.DiscretePIDController_P * tune_B.Sum_o +
                  tune_DW.Integrator_DSTATE) + tune_B.FilterCoefficient;
  }

  /* Switch: '<S74>/Switch' incorporates:
   *  Sum: '<S74>/Sum3'
   *  ZeroOrderHold: '<S74>/Zero-Order Hold1'
   */
  if (tune_B.startstop > tune_P.Switch_Threshold_j) {
    tune_B.SumofElements = tune_B.Sum + tune_B.Sum_p;
  } else {
    tune_B.SumofElements = tune_B.Sum;
  }

  /* End of Switch: '<S74>/Switch' */

  /* Delay: '<S7>/Enabled Delay U' */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&tune_PrevZCX.EnabledDelayU_Reset_ZCE,
               (tune_B.startstop)) != NO_ZCEVENT) {
    tune_DW.icLoad_h = true;
  }

  if (tune_DW.icLoad_h) {
    tune_DW.EnabledDelayU_DSTATE = tune_B.SumofElements;
  }

  /* Delay: '<S7>/Enabled Delay U' */
  tune_B.u = tune_DW.EnabledDelayU_DSTATE;

  /* Sum: '<S13>/Sum' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S13>/Constant2'
   *  Constant: '<S1>/bandwidth constant'
   *  Product: '<S13>/Divide'
   *  Product: '<S13>/Product'
   *  Product: '<S13>/Product1'
   */
  tune_B.Sum_c = tune_P.Constant_Value_i - tune_B.GainTs *
    tune_P.ClosedLoopPIDAutotuner_Bandwidt / (tune_P.Constant1_Value_k *
    tune_P.Constant2_Value_b);

  /* Outputs for Enabled SubSystem: '<S12>/Response Estimation' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (tune_B.startstop > 0.0) {
    if (!tune_DW.ResponseEstimation_MODE) {
      /* InitializeConditions for Delay: '<S20>/delayL' */
      tune_DW.icLoad_hd = true;

      /* InitializeConditions for Delay: '<S20>/delayBuffery' */
      tune_DW.icLoad_l = true;

      /* InitializeConditions for Delay: '<S20>/delayBufferH' */
      tune_DW.icLoad_d = true;

      /* InitializeConditions for Delay: '<S20>/delayTheta' */
      tune_DW.icLoad_p = true;

      /* InitializeConditions for Delay: '<S19>/delayL' */
      tune_DW.icLoad_dw = true;

      /* InitializeConditions for Delay: '<S19>/delayBuffery' */
      tune_DW.icLoad_j = true;

      /* InitializeConditions for Delay: '<S19>/delayBufferH' */
      tune_DW.icLoad_c = true;

      /* InitializeConditions for Delay: '<S19>/delayTheta' */
      tune_DW.icLoad_a = true;

      /* SystemReset for MATLAB Function: '<S20>/RLS' */
      tune_RLS_Reset(&tune_DW.sf_RLS_j);

      /* SystemReset for MATLAB Function: '<S19>/RLS' */
      tune_RLS_Reset(&tune_DW.sf_RLS);
      tune_DW.ResponseEstimation_MODE = true;
    }

    /* Delay: '<S20>/delayL' incorporates:
     *  Constant: '<S20>/InitialCovariance'
     */
    if (tune_DW.icLoad_hd) {
      memcpy(&tune_DW.delayL_DSTATE[0], &tune_P.InitialCovariance_Value[0], 121U
             * sizeof(real_T));
    }

    /* Delay: '<S20>/delayBuffery' incorporates:
     *  Constant: '<S20>/InitialOutputs'
     */
    if (tune_DW.icLoad_l) {
      tune_DW.delayBuffery_DSTATE = tune_P.InitialOutputs_Value;
    }

    /* Delay: '<S20>/delayBufferH' incorporates:
     *  Constant: '<S20>/InitialRegressors'
     */
    if (tune_DW.icLoad_d) {
      tune_DW.delayBufferH_DSTATE = tune_P.InitialRegressors_Value;
    }

    /* Delay: '<S20>/delayTheta' incorporates:
     *  Constant: '<S20>/InitialParameters'
     */
    if (tune_DW.icLoad_p) {
      memcpy(&tune_DW.delayTheta_DSTATE[0], &tune_P.InitialParameters_Value[0],
             11U * sizeof(real_T));
    }

    /* MATLAB Function: '<S20>/RLS' incorporates:
     *  Constant: '<S20>/Enable'
     *  Delay: '<S20>/delayBufferH'
     *  Delay: '<S20>/delayBuffery'
     *  Delay: '<S20>/delayL'
     *  Delay: '<S20>/delayTheta'
     *  Sum: '<S12>/Sum2'
     *  ZeroOrderHold: '<S1>/Zero-Order Hold1'
     */
    tune_RLS(tune_B.Product2, tune_B.Product1, tune_B.Switch1,
             tune_B.SmartMotorRead - tune_B.y, tune_P.Enable_Value, tune_B.Sum_c,
             tune_DW.delayBuffery_DSTATE, tune_DW.delayBufferH_DSTATE,
             tune_DW.delayTheta_DSTATE, tune_DW.delayL_DSTATE, &tune_B.sf_RLS_j,
             &tune_DW.sf_RLS_j);

    /* Delay: '<S19>/delayL' incorporates:
     *  Constant: '<S19>/InitialCovariance'
     */
    if (tune_DW.icLoad_dw) {
      memcpy(&tune_DW.delayL_DSTATE_k[0], &tune_P.InitialCovariance_Value_k[0],
             121U * sizeof(real_T));
    }

    /* Delay: '<S19>/delayBuffery' incorporates:
     *  Constant: '<S19>/InitialOutputs'
     */
    if (tune_DW.icLoad_j) {
      tune_DW.delayBuffery_DSTATE_c = tune_P.InitialOutputs_Value_i;
    }

    /* Delay: '<S19>/delayBufferH' incorporates:
     *  Constant: '<S19>/InitialRegressors'
     */
    if (tune_DW.icLoad_c) {
      tune_DW.delayBufferH_DSTATE_h = tune_P.InitialRegressors_Value_o;
    }

    /* Delay: '<S19>/delayTheta' incorporates:
     *  Constant: '<S19>/InitialParameters'
     */
    if (tune_DW.icLoad_a) {
      memcpy(&tune_DW.delayTheta_DSTATE_o[0], &tune_P.InitialParameters_Value_k
             [0], 11U * sizeof(real_T));
    }

    /* MATLAB Function: '<S19>/RLS' incorporates:
     *  Constant: '<S19>/Enable'
     *  Delay: '<S19>/delayBufferH'
     *  Delay: '<S19>/delayBuffery'
     *  Delay: '<S19>/delayL'
     *  Delay: '<S19>/delayTheta'
     *  Sum: '<S12>/Sum3'
     */
    tune_RLS(tune_B.Product2, tune_B.Product1, tune_B.Switch1,
             tune_B.SumofElements - tune_B.u, tune_P.Enable_Value_h,
             tune_B.Sum_c, tune_DW.delayBuffery_DSTATE_c,
             tune_DW.delayBufferH_DSTATE_h, tune_DW.delayTheta_DSTATE_o,
             tune_DW.delayL_DSTATE_k, &tune_B.sf_RLS, &tune_DW.sf_RLS);

    /* RealImagToComplex: '<S15>/Real-Imag to Complex1' */
    for (tune_B.i = 0; tune_B.i < 5; tune_B.i++) {
      tune_B.RealImagtoComplex1[tune_B.i].re = tune_B.sf_RLS.x[tune_B.i + 5];
      tune_B.RealImagtoComplex1[tune_B.i].im = tune_B.sf_RLS.x[tune_B.i];
    }

    /* End of RealImagToComplex: '<S15>/Real-Imag to Complex1' */

    /* RealImagToComplex: '<S15>/Real-Imag to Complex' */
    for (tune_B.i = 0; tune_B.i < 5; tune_B.i++) {
      tune_B.RealImagtoComplex[tune_B.i].re = tune_B.sf_RLS_j.x[tune_B.i + 5];
      tune_B.RealImagtoComplex[tune_B.i].im = tune_B.sf_RLS_j.x[tune_B.i];
    }

    /* End of RealImagToComplex: '<S15>/Real-Imag to Complex' */
    for (tune_B.i = 0; tune_B.i < 5; tune_B.i++) {
      /* Product: '<S15>/Divide1' incorporates:
       *  RealImagToComplex: '<S15>/Real-Imag to Complex'
       *  RealImagToComplex: '<S15>/Real-Imag to Complex1'
       */
      tune_B.Sum_c = tune_B.RealImagtoComplex[tune_B.i].re;
      tune_B.rtb_Product_a_o = tune_B.RealImagtoComplex[tune_B.i].im;
      tune_B.br = tune_B.RealImagtoComplex1[tune_B.i].re;
      tune_B.bi = tune_B.RealImagtoComplex1[tune_B.i].im;
      if (tune_B.bi == 0.0) {
        if (tune_B.rtb_Product_a_o == 0.0) {
          /* Product: '<S15>/Divide1' */
          tune_B.Gain[tune_B.i].re = tune_B.Sum_c / tune_B.br;
          tune_B.Gain[tune_B.i].im = 0.0;
        } else if (tune_B.Sum_c == 0.0) {
          /* Product: '<S15>/Divide1' */
          tune_B.Gain[tune_B.i].re = 0.0;
          tune_B.Gain[tune_B.i].im = tune_B.rtb_Product_a_o / tune_B.br;
        } else {
          /* Product: '<S15>/Divide1' */
          tune_B.Gain[tune_B.i].re = tune_B.Sum_c / tune_B.br;
          tune_B.Gain[tune_B.i].im = tune_B.rtb_Product_a_o / tune_B.br;
        }
      } else if (tune_B.br == 0.0) {
        if (tune_B.Sum_c == 0.0) {
          /* Product: '<S15>/Divide1' */
          tune_B.Gain[tune_B.i].re = tune_B.rtb_Product_a_o / tune_B.bi;
          tune_B.Gain[tune_B.i].im = 0.0;
        } else if (tune_B.rtb_Product_a_o == 0.0) {
          /* Product: '<S15>/Divide1' */
          tune_B.Gain[tune_B.i].re = 0.0;
          tune_B.Gain[tune_B.i].im = -(tune_B.Sum_c / tune_B.bi);
        } else {
          /* Product: '<S15>/Divide1' */
          tune_B.Gain[tune_B.i].re = tune_B.rtb_Product_a_o / tune_B.bi;
          tune_B.Gain[tune_B.i].im = -(tune_B.Sum_c / tune_B.bi);
        }
      } else {
        tune_B.brm = fabs(tune_B.br);
        tune_B.bim = fabs(tune_B.bi);
        if (tune_B.brm > tune_B.bim) {
          tune_B.brm = tune_B.bi / tune_B.br;
          tune_B.bi = tune_B.brm * tune_B.bi + tune_B.br;

          /* Product: '<S15>/Divide1' */
          tune_B.Gain[tune_B.i].re = (tune_B.brm * tune_B.rtb_Product_a_o +
            tune_B.Sum_c) / tune_B.bi;
          tune_B.Gain[tune_B.i].im = (tune_B.rtb_Product_a_o - tune_B.brm *
            tune_B.Sum_c) / tune_B.bi;
        } else if (tune_B.bim == tune_B.brm) {
          tune_B.br = tune_B.br > 0.0 ? 0.5 : -0.5;
          tune_B.bi = tune_B.bi > 0.0 ? 0.5 : -0.5;

          /* Product: '<S15>/Divide1' */
          tune_B.Gain[tune_B.i].re = (tune_B.Sum_c * tune_B.br +
            tune_B.rtb_Product_a_o * tune_B.bi) / tune_B.brm;
          tune_B.Gain[tune_B.i].im = (tune_B.rtb_Product_a_o * tune_B.br -
            tune_B.Sum_c * tune_B.bi) / tune_B.brm;
        } else {
          tune_B.brm = tune_B.br / tune_B.bi;
          tune_B.bi += tune_B.brm * tune_B.br;

          /* Product: '<S15>/Divide1' */
          tune_B.Gain[tune_B.i].re = (tune_B.brm * tune_B.Sum_c +
            tune_B.rtb_Product_a_o) / tune_B.bi;
          tune_B.Gain[tune_B.i].im = (tune_B.brm * tune_B.rtb_Product_a_o -
            tune_B.Sum_c) / tune_B.bi;
        }
      }

      /* End of Product: '<S15>/Divide1' */

      /* Gain: '<S15>/Gain' incorporates:
       *  Product: '<S15>/Divide1'
       */
      tune_B.Gain[tune_B.i].re *= tune_P.Gain_Gain_n[tune_B.i];
      tune_B.Gain[tune_B.i].im *= tune_P.Gain_Gain_n[tune_B.i];
    }

    /* Update for Delay: '<S20>/delayL' */
    tune_DW.icLoad_hd = false;
    memcpy(&tune_DW.delayL_DSTATE[0], &tune_B.sf_RLS_j.L[0], 121U * sizeof
           (real_T));

    /* Update for Delay: '<S20>/delayBuffery' */
    tune_DW.icLoad_l = false;
    tune_DW.delayBuffery_DSTATE = tune_B.sf_RLS_j.yBuffer;

    /* Update for Delay: '<S20>/delayBufferH' */
    tune_DW.icLoad_d = false;
    tune_DW.delayBufferH_DSTATE = tune_B.sf_RLS_j.HBuffer;

    /* Update for Delay: '<S20>/delayTheta' */
    tune_DW.icLoad_p = false;
    memcpy(&tune_DW.delayTheta_DSTATE[0], &tune_B.sf_RLS_j.x[0], 11U * sizeof
           (real_T));

    /* Update for Delay: '<S19>/delayL' */
    tune_DW.icLoad_dw = false;
    memcpy(&tune_DW.delayL_DSTATE_k[0], &tune_B.sf_RLS.L[0], 121U * sizeof
           (real_T));

    /* Update for Delay: '<S19>/delayBuffery' */
    tune_DW.icLoad_j = false;
    tune_DW.delayBuffery_DSTATE_c = tune_B.sf_RLS.yBuffer;

    /* Update for Delay: '<S19>/delayBufferH' */
    tune_DW.icLoad_c = false;
    tune_DW.delayBufferH_DSTATE_h = tune_B.sf_RLS.HBuffer;

    /* Update for Delay: '<S19>/delayTheta' */
    tune_DW.icLoad_a = false;
    memcpy(&tune_DW.delayTheta_DSTATE_o[0], &tune_B.sf_RLS.x[0], 11U * sizeof
           (real_T));
    srUpdateBC(tune_DW.ResponseEstimation_SubsysRanBC);
  } else {
    tune_DW.ResponseEstimation_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S12>/Response Estimation' */
  /* Gain: '<S1>/GainPM' incorporates:
   *  Constant: '<S1>/target PM constant'
   */
  tune_B.GainPM = tune_P.GainPM_Gain * tune_P.ClosedLoopPIDAutotuner_TargetPM;

  /* Outputs for Triggered SubSystem: '<S1>/Gains From Online Tuning Module' incorporates:
   *  TriggerPort: '<S6>/Trigger'
   */
  tune_B.zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
    &tune_PrevZCX.GainsFromOnlineTuningModule_Tri,
    (tune_B.startstop));
  if (tune_B.zcEvent != NO_ZCEVENT) {
    /* MATLAB Function: '<S71>/DeployedMode' incorporates:
     *  Constant: '<S1>/PID form constant'
     *  Constant: '<S1>/PID type constant'
     *  Constant: '<S1>/filter formula constant'
     *  Constant: '<S1>/integrator formula constant'
     *  Constant: '<S1>/plant type constant'
     *  Gain: '<S15>/Gain'
     *  SignalConversion generated from: '<S72>/ SFunction '
     *  Switch: '<S1>/Plant Type Switch'
     */
    if (tune_P.DeployedMode_TimeDomain == 1) {
      /* Switch: '<S1>/Plant Type Switch' incorporates:
       *  Constant: '<S1>/Integrating'
       *  Constant: '<S1>/Stable'
       *  Constant: '<S1>/plant type constant'
       */
      if (tune_P.ClosedLoopPIDAutotuner_PlantTyp >
          tune_P.PlantTypeSwitch_Threshold) {
        tune_B.Sum_c = tune_P.Integrating_Value;
      } else {
        tune_B.Sum_c = tune_P.Stable_Value;
      }

      /* Switch: '<S1>/Plant Sign Switch' incorporates:
       *  Constant: '<S1>/Negative'
       *  Constant: '<S1>/Positive'
       *  Constant: '<S1>/plant sign constant'
       */
      if (tune_P.ClosedLoopPIDAutotuner_PlantSig >
          tune_P.PlantSignSwitch_Threshold) {
        tune_B.rtb_Product_a_o = tune_P.Negative_Value;
      } else {
        tune_B.rtb_Product_a_o = tune_P.Positive_Value;
      }

      memcpy(&tune_B.RealImagtoComplex1[0], &tune_B.Gain[0], 5U * sizeof(creal_T));
      tune_slpidfivepoint(tune_P.ClosedLoopPIDAutotuner_PIDType,
                          tune_P.ClosedLoopPIDAutotuner_PIDForm, tune_B.w,
                          tune_B.RealImagtoComplex1, tune_B.GainPM, tune_B.Sum_c,
                          tune_B.rtb_Product_a_o, tune_B.GainTs,
                          tune_P.integratorformulaconstant_Value,
                          tune_P.filterformulaconstant_Value, &tune_B.P_c,
                          &tune_B.bi, &tune_B.D_d, &tune_B.brm, &tune_B.br);
    } else {
      if (tune_P.ClosedLoopPIDAutotuner_PlantTyp >
          tune_P.PlantTypeSwitch_Threshold) {
        /* Switch: '<S1>/Plant Type Switch' incorporates:
         *  Constant: '<S1>/Integrating'
         */
        tune_B.Sum_c = tune_P.Integrating_Value;
      } else {
        /* Switch: '<S1>/Plant Type Switch' incorporates:
         *  Constant: '<S1>/Stable'
         */
        tune_B.Sum_c = tune_P.Stable_Value;
      }

      /* Switch: '<S1>/Plant Sign Switch' incorporates:
       *  Constant: '<S1>/Negative'
       *  Constant: '<S1>/Positive'
       *  Constant: '<S1>/plant sign constant'
       */
      if (tune_P.ClosedLoopPIDAutotuner_PlantSig >
          tune_P.PlantSignSwitch_Threshold) {
        tune_B.rtb_Product_a_o = tune_P.Negative_Value;
      } else {
        tune_B.rtb_Product_a_o = tune_P.Positive_Value;
      }

      memcpy(&tune_B.RealImagtoComplex1[0], &tune_B.Gain[0], 5U * sizeof(creal_T));
      tune_slpidfivepoint(tune_P.ClosedLoopPIDAutotuner_PIDType,
                          tune_P.ClosedLoopPIDAutotuner_PIDForm, tune_B.w,
                          tune_B.RealImagtoComplex1, tune_B.GainPM, tune_B.Sum_c,
                          tune_B.rtb_Product_a_o, 0.0,
                          tune_P.integratorformulaconstant_Value,
                          tune_P.filterformulaconstant_Value, &tune_B.P_c,
                          &tune_B.bi, &tune_B.D_d, &tune_B.brm, &tune_B.br);
    }

    /* End of MATLAB Function: '<S71>/DeployedMode' */
    tune_DW.GainsFromOnlineTuningModule_Sub = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/Gains From Online Tuning Module' */

  /* Switch generated from: '<S1>/Gain Switch' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (tune_P.Constant_Value_e > tune_P.GainSwitch_1_Threshold) {
    /* Switch generated from: '<S1>/Gain Switch' incorporates:
     *  Constant: '<S5>/GainP'
     */
    tune_B.P = tune_P.GainP_Value;
  } else {
    /* Switch generated from: '<S1>/Gain Switch' */
    tune_B.P = tune_B.P_c;
  }

  /* End of Switch generated from: '<S1>/Gain Switch' */
  /* SignalConversion: '<Root>/Signal Copy' */
  tune_B.SignalCopy = tune_B.P;

  /* Switch generated from: '<S1>/Gain Switch' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (tune_P.Constant_Value_e > tune_P.GainSwitch_3_Threshold) {
    /* Switch generated from: '<S1>/Gain Switch' incorporates:
     *  Constant: '<S5>/GainD'
     */
    tune_B.D = tune_P.GainD_Value;
  } else {
    /* Switch generated from: '<S1>/Gain Switch' */
    tune_B.D = tune_B.D_d;
  }

  /* End of Switch generated from: '<S1>/Gain Switch' */
  /* SignalConversion: '<Root>/Signal Copy2' */
  tune_B.SignalCopy2 = tune_B.D;

  /* Outputs for Enabled SubSystem: '<S1>/Convergence Calculator' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (tune_B.startstop > 0.0) {
    if (!tune_DW.ConvergenceCalculator_MODE) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
      for (tune_B.i = 0; tune_B.i < 64; tune_B.i++) {
        tune_DW.TappedDelay_X[tune_B.i] = tune_P.TappedDelay_vinit;
      }

      /* End of InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */

      /* InitializeConditions for UnitDelay: '<S10>/UD' */
      tune_DW.UD_DSTATE = tune_P.Difference1_ICPrevInput;
      tune_DW.ConvergenceCalculator_MODE = true;
    }

    /* Sum: '<S3>/Sum of Elements' incorporates:
     *  S-Function (sfix_udelay): '<S3>/Tapped Delay'
     */
    tune_B.Sum_c = -0.0;
    for (tune_B.i = 0; tune_B.i < 64; tune_B.i++) {
      tune_B.Sum_c += tune_DW.TappedDelay_X[tune_B.i];
    }

    /* Gain: '<S3>/Gain' incorporates:
     *  Sum: '<S3>/Sum of Elements'
     */
    tune_B.Sum_c *= tune_P.Gain_Gain;

    /* ComplexToMagnitudeAngle: '<S3>/Complex to Magnitude-Angle' */
    tune_B.ComplextoMagnitudeAngle = tune_rt_hypotd_snf(tune_B.Gain[2].re,
      tune_B.Gain[2].im);

    /* Switch: '<S11>/Switch1' incorporates:
     *  Abs: '<S11>/Abs3'
     */
    if (!(fabs(tune_B.Sum_c) > tune_P.Switch1_Threshold)) {
      /* Switch: '<S11>/Switch' incorporates:
       *  Constant: '<S11>/Constant'
       *  Constant: '<S11>/Constant1'
       */
      if (tune_B.Sum_c > tune_P.Switch_Threshold) {
        tune_B.Sum_c = tune_P.Constant_Value;
      } else {
        tune_B.Sum_c = tune_P.Constant1_Value;
      }

      /* End of Switch: '<S11>/Switch' */
    }

    /* End of Switch: '<S11>/Switch1' */

    /* Gain: '<S3>/Gain2' incorporates:
     *  Abs: '<S3>/Abs3'
     *  Product: '<S3>/Divide1'
     *  Sum: '<S10>/Diff'
     *  UnitDelay: '<S10>/UD'
     */
    tune_B.Sum_c = fabs((tune_B.ComplextoMagnitudeAngle - tune_DW.UD_DSTATE) /
                        tune_B.Sum_c) * tune_P.Gain2_Gain;

    /* Saturate: '<S3>/Saturation' */
    if (tune_B.Sum_c > tune_P.Saturation_UpperSat) {
      tune_B.Sum_c = tune_P.Saturation_UpperSat;
    } else if (tune_B.Sum_c < tune_P.Saturation_LowerSat) {
      tune_B.Sum_c = tune_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S3>/Saturation' */

    /* Sum: '<S3>/Sum2' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    tune_B.Sum2 = tune_P.Constant2_Value - tune_B.Sum_c;

    /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
    for (tune_B.i = 0; tune_B.i < 63; tune_B.i++) {
      tune_DW.TappedDelay_X[tune_B.i] = tune_DW.TappedDelay_X[tune_B.i + 1];
    }

    tune_DW.TappedDelay_X[63] = tune_B.ComplextoMagnitudeAngle;

    /* End of Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */

    /* Update for UnitDelay: '<S10>/UD' */
    tune_DW.UD_DSTATE = tune_B.ComplextoMagnitudeAngle;
    srUpdateBC(tune_DW.ConvergenceCalculator_SubsysRan);
  } else {
    tune_DW.ConvergenceCalculator_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S1>/Convergence Calculator' */
  /* MATLABSystem: '<Root>/Smart Motor Write' */
  if (tune_B.SumofElements > 200.0) {
    tune_B.SumofElements = 200.0;
  } else if (tune_B.SumofElements < -200.0) {
    tune_B.SumofElements = -200.0;
  }

  DevicePresent(kDeviceTypeMotorSensor, 0);
  vexMotorVelocitySet(0, tune_B.SumofElements);

  /* End of MATLABSystem: '<Root>/Smart Motor Write' */
  if (tune_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S103>/Integral Gain' */
    tune_B.IntegralGain = tune_P.DiscretePIDController_I * tune_B.Sum_o;
  }

  if (tune_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Update for Delay: '<S7>/Enabled Delay Y' */
  tune_DW.icLoad = false;
  tune_DW.EnabledDelayY_DSTATE = tune_B.y;
  if (tune_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteIntegrator: '<S106>/Integrator' */
    tune_DW.Integrator_DSTATE += tune_P.Integrator_gainval * tune_B.IntegralGain;

    /* Update for DiscreteIntegrator: '<S101>/Filter' */
    tune_DW.Filter_DSTATE += tune_P.Filter_gainval * tune_B.FilterCoefficient;
  }

  /* Update for Delay: '<S7>/Enabled Delay U' */
  tune_DW.icLoad_h = false;
  tune_DW.EnabledDelayU_DSTATE = tune_B.u;

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, (real_T)tune_M->Timing.taskTime0);
  }

  if (tune_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(1, (real_T)(((tune_M->Timing.clockTick1+
      tune_M->Timing.clockTickH1* 4294967296.0)) * 0.2));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(tune_M)!=-1) &&
        !((rtmGetTFinal(tune_M)-tune_M->Timing.taskTime0) >
          tune_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(tune_M, "Simulation finished");
    }

    if (rtmGetStopRequested(tune_M)) {
      rtmSetErrorStatus(tune_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++tune_M->Timing.clockTick0)) {
    ++tune_M->Timing.clockTickH0;
  }

  tune_M->Timing.taskTime0 = tune_M->Timing.clockTick0 *
    tune_M->Timing.stepSize0 + tune_M->Timing.clockTickH0 *
    tune_M->Timing.stepSize0 * 4294967296.0;
  if (tune_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    tune_M->Timing.clockTick1++;
    if (!tune_M->Timing.clockTick1) {
      tune_M->Timing.clockTickH1++;
    }
  }

  rate_scheduler();
}

/* Model initialize function */
void tune_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)tune_M, 0,
                sizeof(RT_MODEL_tune_T));
  rtmSetTFinal(tune_M, -1);
  tune_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  tune_M->Sizes.checksums[0] = (1144356867U);
  tune_M->Sizes.checksums[1] = (630412148U);
  tune_M->Sizes.checksums[2] = (1686277292U);
  tune_M->Sizes.checksums[3] = (2493771149U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[24];
    tune_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&tune_DW.ConvergenceCalculator_SubsysRan;
    systemRan[2] = (sysRanDType *)&tune_DW.ConvergenceCalculator_SubsysRan;
    systemRan[3] = (sysRanDType *)&tune_DW.ConvergenceCalculator_SubsysRan;
    systemRan[4] = (sysRanDType *)&tune_DW.ConvergenceCalculator_SubsysRan;
    systemRan[5] = (sysRanDType *)&tune_DW.PerturbationGenerator_SubsysRan;
    systemRan[6] = (sysRanDType *)&tune_DW.PerturbationGenerator_SubsysRan;
    systemRan[7] = (sysRanDType *)&tune_DW.PerturbationGenerator_SubsysRan;
    systemRan[8] = (sysRanDType *)&tune_DW.PerturbationGenerator_SubsysRan;
    systemRan[9] = (sysRanDType *)&tune_DW.ResponseEstimation_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&tune_DW.ResponseEstimation_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&tune_DW.ResponseEstimation_SubsysRanBC;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)&tune_DW.GainsFromOnlineTuningModule_Sub;
    systemRan[14] = (sysRanDType *)&tune_DW.GainsFromOnlineTuningModule_Sub;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(tune_M->extModeInfo,
      &tune_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(tune_M->extModeInfo, tune_M->Sizes.checksums);
    rteiSetTPtr(tune_M->extModeInfo, rtmGetTPtr(tune_M));
  }

  /* block I/O */
  (void) memset(((void *) &tune_B), 0,
                sizeof(B_tune_T));

  /* states (dwork) */
  (void) memset((void *)&tune_DW, 0,
                sizeof(DW_tune_T));

  /* Start for Enabled SubSystem: '<S12>/Perturbation Generator' */
  tune_DW.PerturbationGenerator_MODE = false;

  /* End of Start for SubSystem: '<S12>/Perturbation Generator' */

  /* Start for MATLABSystem: '<Root>/Smart Motor Read' */
  tune_DW.obj.matlabCodegenIsDeleted = false;
  tune_DW.objisempty_a = true;
  tune_DW.obj.isInitialized = 1;
  vexMotorEncoderUnitsSet(0, kMotorEncoderCounts);
  vexMotorPositionReset(0);
  tune_DW.obj.isSetupComplete = true;

  /* Start for Enabled SubSystem: '<S12>/Response Estimation' */
  tune_DW.ResponseEstimation_MODE = false;

  /* End of Start for SubSystem: '<S12>/Response Estimation' */
  /* Start for Enabled SubSystem: '<S1>/Convergence Calculator' */
  tune_DW.ConvergenceCalculator_MODE = false;

  /* End of Start for SubSystem: '<S1>/Convergence Calculator' */
  /* Start for MATLABSystem: '<Root>/Smart Motor Write' */
  tune_DW.obj_e.matlabCodegenIsDeleted = false;
  tune_DW.objisempty = true;
  tune_DW.obj_e.isInitialized = 1;
  vexMotorBrakeModeSet(0, kV5MotorBrakeModeCoast);
  vexMotorGearingSet(0, kMotorGearSet_18);
  vexMotorPositionReset(0);
  tune_DW.obj_e.isSetupComplete = true;
  tune_PrevZCX.EnabledDelayY_Reset_ZCE = UNINITIALIZED_ZCSIG;
  tune_PrevZCX.EnabledDelayU_Reset_ZCE = UNINITIALIZED_ZCSIG;
  tune_PrevZCX.GainsFromOnlineTuningModule_Tri = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for Delay: '<S7>/Enabled Delay Y' */
    tune_DW.icLoad = true;

    /* InitializeConditions for DiscreteIntegrator: '<S106>/Integrator' */
    tune_DW.Integrator_DSTATE = tune_P.DiscretePIDController_Initial_m;

    /* InitializeConditions for DiscreteIntegrator: '<S101>/Filter' */
    tune_DW.Filter_DSTATE = tune_P.DiscretePIDController_InitialCo;

    /* InitializeConditions for Delay: '<S7>/Enabled Delay U' */
    tune_DW.icLoad_h = true;

    /* SystemInitialize for Enabled SubSystem: '<S12>/Perturbation Generator' */
    /* InitializeConditions for Sum: '<S17>/FixPt Sum1' incorporates:
     *  UnitDelay: '<S16>/Output'
     */
    tune_DW.Output_DSTATE = tune_P.Output_InitialCondition;

    /* SystemInitialize for Sum: '<S14>/Sum' incorporates:
     *  Outport: '<S14>/signal'
     */
    tune_B.Sum_p = tune_P.signal_Y0;
    for (i = 0; i < 5; i++) {
      /* SystemInitialize for Product: '<S14>/Product2' incorporates:
       *  Outport: '<S14>/regressors'
       */
      tune_B.Product2[i] = tune_P.regressors_Y0;

      /* SystemInitialize for Product: '<S14>/Product1' incorporates:
       *  Outport: '<S14>/regressors'
       */
      tune_B.Product1[i] = tune_P.regressors_Y0;
    }

    /* SystemInitialize for Switch: '<S14>/Switch1' incorporates:
     *  Outport: '<S14>/regressors'
     */
    tune_B.Switch1 = tune_P.regressors_Y0;

    /* End of SystemInitialize for SubSystem: '<S12>/Perturbation Generator' */

    /* SystemInitialize for Enabled SubSystem: '<S12>/Response Estimation' */
    /* InitializeConditions for Delay: '<S20>/delayL' */
    tune_DW.icLoad_hd = true;

    /* InitializeConditions for Delay: '<S20>/delayBuffery' */
    tune_DW.icLoad_l = true;

    /* InitializeConditions for Delay: '<S20>/delayBufferH' */
    tune_DW.icLoad_d = true;

    /* InitializeConditions for Delay: '<S20>/delayTheta' */
    tune_DW.icLoad_p = true;

    /* InitializeConditions for Delay: '<S19>/delayL' */
    tune_DW.icLoad_dw = true;

    /* InitializeConditions for Delay: '<S19>/delayBuffery' */
    tune_DW.icLoad_j = true;

    /* InitializeConditions for Delay: '<S19>/delayBufferH' */
    tune_DW.icLoad_c = true;

    /* InitializeConditions for Delay: '<S19>/delayTheta' */
    tune_DW.icLoad_a = true;

    /* SystemInitialize for MATLAB Function: '<S20>/RLS' */
    tune_RLS_Init(&tune_DW.sf_RLS_j);

    /* SystemInitialize for MATLAB Function: '<S19>/RLS' */
    tune_RLS_Init(&tune_DW.sf_RLS);
    for (i = 0; i < 5; i++) {
      /* SystemInitialize for Gain: '<S15>/Gain' incorporates:
       *  Outport: '<S15>/FreqResp'
       *  Product: '<S15>/Divide1'
       */
      tune_B.Gain[i].re = tune_P.FreqResp_Y0;
      tune_B.Gain[i].im = 0.0;
    }

    /* End of SystemInitialize for SubSystem: '<S12>/Response Estimation' */

    /* SystemInitialize for Triggered SubSystem: '<S1>/Gains From Online Tuning Module' */
    /* SystemInitialize for Outport: '<S6>/P' */
    tune_B.P_c = tune_P.P_Y0;

    /* SystemInitialize for Outport: '<S6>/D' */
    tune_B.D_d = tune_P.D_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Gains From Online Tuning Module' */

    /* SystemInitialize for Enabled SubSystem: '<S1>/Convergence Calculator' */
    /* InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
    for (i = 0; i < 64; i++) {
      tune_DW.TappedDelay_X[i] = tune_P.TappedDelay_vinit;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */

    /* InitializeConditions for UnitDelay: '<S10>/UD' */
    tune_DW.UD_DSTATE = tune_P.Difference1_ICPrevInput;

    /* SystemInitialize for Sum: '<S3>/Sum2' incorporates:
     *  Outport: '<S3>/convergence'
     */
    tune_B.Sum2 = tune_P.convergence_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Convergence Calculator' */
  }
}

/* Model terminate function */
void tune_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Smart Motor Read' */
  if (!tune_DW.obj.matlabCodegenIsDeleted) {
    tune_DW.obj.matlabCodegenIsDeleted = true;
    if ((tune_DW.obj.isInitialized == 1) && tune_DW.obj.isSetupComplete) {
      vexMotorPositionReset(0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Smart Motor Read' */
  /* Terminate for MATLABSystem: '<Root>/Smart Motor Write' */
  if (!tune_DW.obj_e.matlabCodegenIsDeleted) {
    tune_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((tune_DW.obj_e.isInitialized == 1) && tune_DW.obj_e.isSetupComplete) {
      vexMotorPositionReset(0);
      vexMotorVelocitySet(0, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Smart Motor Write' */
}
