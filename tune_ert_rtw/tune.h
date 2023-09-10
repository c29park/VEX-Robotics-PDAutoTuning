/*
 * tune.h
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

#ifndef RTW_HEADER_tune_h_
#define RTW_HEADER_tune_h_
#ifndef tune_COMMON_INCLUDES_
#define tune_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_work.h"
#include "MW_SupportFunc_Wrapper.h"
#endif                                 /* tune_COMMON_INCLUDES_ */

#include "tune_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_zcfcn.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<S19>/RLS' */
typedef struct {
  real_T b_A[132];
  real_T L[121];                       /* '<S19>/RLS' */
  real_T A[121];
  real_T y[121];
  real_T b_A_m[12];
  real_T Pxy[11];
  real_T C[11];
  real_T TmpSignalConversionAtSFun_o[11];/* '<S19>/RLS' */
  real_T tau[11];
  real_T work[11];
  real_T yBuffer;                      /* '<S19>/RLS' */
  real_T HBuffer;                      /* '<S19>/RLS' */
  real_T x[11];                        /* '<S19>/RLS' */
  real_T Sy;
  real_T prodVal;
  real_T Sy_tmp;
  real_T rtb_TmpSignalConversionAtSFun_c;
  real_T s;
  real_T atmp;
  real_T temp;
  real_T s_k;
  real_T c;
  real_T scale;
} B_RLS_tune_T;

/* Block states (default storage) for system '<S19>/RLS' */
typedef struct {
  d_controllib_internal_blocks__T rlsEstimator;/* '<S19>/RLS' */
  boolean_T rlsEstimator_not_empty;    /* '<S19>/RLS' */
} DW_RLS_tune_T;

/* Block signals (default storage) */
typedef struct {
  real_T f[100];
  real_T c_xtau[100];
  real_T dv[100];
  creal_T dcv[50];
  real_T b_xtau[80];
  real_T Q[64];
  real_T Q_m[64];
  real_T xtau[60];
  real_T wLow[50];
  real_T wHigh[50];
  real_T f_c[50];
  real_T f_k[50];
  real_T b_y[50];
  real_T Q_c[49];
  real_T Q_b[49];
  real_T d_A[40];
  real_T d_A_p[40];
  real_T w_tmp[40];
  real_T A[40];
  real_T w_tmp_c[40];
  real_T c_A[32];
  real_T c_A_f[32];
  real_T w_tmp_g[32];
  real_T A_g[32];
  real_T w_tmp_m[32];
  real_T b_A[21];
  real_T b_A_n[21];
  real_T w_tmp_p[21];
  real_T A_l[21];
  real_T w_tmp_j[21];
  real_T tau[20];
  real_T gap[20];
  real_T dv1[20];
  real_T b_y_d[20];
  real_T responses[18];
  real_T pp_coefs[16];
  real_T A_gu[14];
  real_T A_ld[14];
  real_T w_tmp_d[14];
  real_T A_d[14];
  real_T responses_l[12];
  creal_T Gain[5];                     /* '<S15>/Gain' */
  creal_T RealImagtoComplex1[5];       /* '<S15>/Real-Imag to Complex1' */
  creal_T RealImagtoComplex[5];        /* '<S15>/Real-Imag to Complex' */
  real_T b_b[8];
  real_T d[8];
  real_T qtd[8];
  real_T work[8];
  real_T vn1[8];
  real_T vn2[8];
  real_T d_o[8];
  real_T qtd_b[8];
  real_T work_n[8];
  real_T resid[8];
  real_T resid_b[8];
  real_T b[7];
  real_T d_l[7];
  real_T qtd_h[7];
  real_T work_b[7];
  real_T vn1_d[7];
  real_T vn2_e[7];
  real_T d_b[7];
  real_T qtd_j[7];
  real_T work_f[7];
  real_T resid_a[7];
  creal_T hL3[3];
  real_T responses_j[6];
  real_T w[5];                         /* '<S1>/GainWC' */
  real_T c_x[5];
  real_T j[5];
  real_T wz[5];
  real_T w_j[5];
  real_T z[5];
  real_T z_o[5];
  real_T wz_n[5];
  real_T w_i[5];
  real_T b_x[5];
  real_T b_x_n[4];
  real_T wz_m[4];
  real_T w_c[4];
  real_T z_m[4];
  real_T z_m3[4];
  real_T wz_j[4];
  real_T w_h[4];
  real_T b_x_c[4];
  int32_T jpvt1[8];
  int32_T jpvt1_o[8];
  int32_T jpvt1_c[7];
  int32_T jpvt1_p[7];
  real_T rG3[3];
  real_T wz_p[3];
  real_T w_a[3];
  real_T z_e[3];
  real_T z_a[3];
  real_T wz_a[3];
  real_T w_if[3];
  real_T b_x_l[3];
  int32_T jpvt[5];
  int32_T jpvt_o[4];
  real_T x[2];
  real_T w_o[2];
  real_T z_i[2];
  real_T z_f[2];
  creal_T tempKp;
  creal_T Kp;
  creal_T responses_i;
  int32_T jpvt_f[3];
  int32_T jpvt_g[2];
  real_T startstop;                    /* '<S1>/Zero-Order Hold' */
  real_T GainTs;                       /* '<S1>/GainTs' */
  real_T y;                            /* '<S7>/Enabled Delay Y' */
  real_T ref;                          /* '<Root>/ref' */
  real_T Sum;                          /* '<S115>/Sum' */
  real_T u;                            /* '<S7>/Enabled Delay U' */
  real_T GainPM;                       /* '<S1>/GainPM' */
  real_T P;                            /* '<S1>/Gain Switch' */
  real_T SignalCopy;                   /* '<Root>/Signal Copy' */
  real_T D;                            /* '<S1>/Gain Switch' */
  real_T SignalCopy2;                  /* '<Root>/Signal Copy2' */
  real_T SmartMotorRead;               /* '<Root>/Smart Motor Read' */
  real_T P_c;                          /* '<S71>/DeployedMode' */
  real_T D_d;                          /* '<S71>/DeployedMode' */
  real_T Product1[5];                  /* '<S14>/Product1' */
  real_T Product2[5];                  /* '<S14>/Product2' */
  real_T Sum_p;                        /* '<S14>/Sum' */
  real_T Switch1;                      /* '<S14>/Switch1' */
  real_T ComplextoMagnitudeAngle;      /* '<S3>/Complex to Magnitude-Angle' */
  real_T Sum2;                         /* '<S3>/Sum2' */
  real_T SumofElements;                /* '<S14>/Sum of Elements' */
  real_T Sum_o;                        /* '<Root>/Sum' */
  real_T FilterCoefficient;            /* '<S109>/Filter Coefficient' */
  real_T Sum_c;                        /* '<S13>/Sum' */
  real_T IntegralGain;                 /* '<S103>/Integral Gain' */
  real_T rtb_Product_a_o;
  real_T br;
  real_T bi;
  real_T brm;
  real_T bim;
  real_T gammaHigh;
  real_T rLast;
  real_T Ki;
  real_T Kd;
  real_T realhD;
  real_T tau_l;
  real_T sgnbr;
  real_T hD_idx_0_im;
  real_T hD_idx_1_re;
  real_T hD_idx_1_im;
  real_T hD_idx_2_re;
  real_T hI_idx_0_re;
  real_T hI_idx_0_im;
  real_T hI_idx_1_re;
  real_T hI_idx_1_im;
  real_T hI_idx_2_re;
  real_T hI_idx_2_im;
  real_T responses_tmp_tmp;
  real_T tol;
  real_T a__4;
  real_T C;
  real_T ncols;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T smax;
  real_T scale_m;
  real_T absxk_m;
  real_T t_c;
  real_T tol_f;
  real_T C_p;
  real_T x_e;
  real_T ncols_o;
  real_T temp;
  real_T tol_h;
  real_T C_l;
  real_T x_h;
  real_T ncols_m;
  real_T scale_mc;
  real_T absxk_h;
  real_T t_cs;
  real_T smax_k;
  real_T scale_p;
  real_T absxk_p;
  real_T t_p;
  real_T tol_a;
  real_T s;
  real_T x_j;
  real_T wz_idx_0;
  real_T wz_idx_1;
  real_T ncols_e;
  real_T temp_o;
  real_T tol_b;
  real_T a__4_a;
  real_T C_g;
  real_T x_ex;
  real_T tol_fi;
  real_T C_h;
  real_T x_ei;
  real_T delta1;
  real_T delta2;
  real_T d_c;
  real_T d1;
  real_T u0;
  real_T w3;
  real_T u1_tmp;
  real_T delta1_a;
  real_T delta2_d;
  real_T tol_af;
  real_T C_pb;
  real_T x_m;
  real_T c;
  real_T hs;
  real_T hs3;
  real_T dzzdx;
  real_T xloc;
  real_T signd1;
  real_T h_idx_0;
  real_T h_idx_1;
  real_T del_idx_0;
  real_T del_idx_1;
  real_T h_idx_2;
  real_T del_idx_3;
  real_T del_idx_2;
  real_T c_s_idx_1;
  real_T hs_tmp;
  real_T hs_tmp_o;
  real_T theta;
  real_T a;
  real_T a_tmp;
  real_T c_x_tmp;
  real_T c_a_tmp;
  real_T c_a_tmp_tmp;
  real_T c_n;
  real_T r;
  real_T x_l;
  real_T Ts;
  real_T imagX;
  real_T varargin_1;
  real_T s_p;
  real_T s_pt;
  real_T s_f;
  real_T b_y_i;
  real_T a_o;
  boolean_T P_k[5];
  boolean_T Z[5];
  boolean_T z_ie[5];
  boolean_T P_o[5];
  boolean_T Z_m[5];
  boolean_T w_cu[5];
  int32_T i;
  int32_T imin;
  int32_T i_b;
  int32_T i_c;
  int32_T i_n;
  int32_T rankA;
  int32_T j_i;
  int32_T b_i;
  int32_T i_m;
  int32_T z_tmp;
  int32_T k;
  int32_T ii;
  int32_T pvt;
  int32_T itemp;
  int32_T ix0;
  int32_T ix;
  int32_T b_ix;
  int32_T temp_tmp;
  int32_T i1;
  int32_T kend;
  int32_T k_j;
  int32_T b_ct;
  int32_T w_tmp_tmp;
  int32_T rankA_e;
  int32_T j_m;
  int32_T k_m;
  int32_T b_i_j;
  int32_T z_tmp_f;
  int32_T itau;
  int32_T iaii;
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T b_ia;
  int32_T i_a;
  int32_T jA;
  int32_T jy;
  int32_T ix_g;
  int32_T j_n;
  int32_T b_d;
  int32_T ijA;
  int32_T b_ct_n;
  int32_T i2;
  int32_T rankA_c;
  int32_T j_f;
  int32_T k_p;
  int32_T b_i_p;
  int32_T k_n;
  int32_T ii_k;
  int32_T pvt_n;
  int32_T ix0_o;
  int32_T ix_gg;
  int32_T b_ix_c;
  int32_T iy;
  int32_T temp_tmp_c;
  int32_T i3;
  int32_T kend_m;
  int32_T k_jp;
  int32_T j_k;
  int32_T i_mx;
  int32_T rankA_p;
  int32_T j_d;
  int32_T k_g;
  int32_T b_i_c;
  int32_T itau_c;
  int32_T iaii_i;
  int32_T lastv_d;
  int32_T lastc_g;
  int32_T coltop_l;
  int32_T b_ia_f;
  int32_T i_d;
  int32_T jA_j;
  int32_T jy_i;
  int32_T ix_h;
  int32_T j_nm;
  int32_T b_o;
  int32_T ijA_c;
  int32_T i_bd;
  int32_T i4;
  int32_T k_e;
  int32_T ct;
  int32_T b_ct_d;
  int32_T w_tmp_tmp_i;
  int32_T idx;
  int32_T k_gs;
  int32_T c_k;
  int32_T i5;
  int32_T c_k_n;
  int32_T b_ct_l;
  int32_T i6;
  int32_T ix_c;
  int32_T b_iy;
  int32_T b_n;
  int32_T iac;
  int32_T d_p;
  int32_T ia;
  int32_T ix_d;
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  int32_T ix_o;
  int32_T b_iy_j;
  int32_T b_c;
  int32_T iac_h;
  int32_T d_d;
  int32_T ia_c;
  int32_T idx_p;
  int32_T k_pi;
  int32_T u0_a;
  int32_T u1;
  int32_T j_o;
  int32_T i_j;
  int32_T j_p;
  int32_T i_o;
  int32_T j_l;
  int32_T i_k;
  int32_T k_jk;
  int32_T k_f;
  int32_T idx_c;
  int32_T k_fq;
  int32_T idx_n;
  int32_T k_i;
  int32_T idx_l;
  int32_T k_i3;
  int32_T idx_k;
  int32_T k_fc;
  int32_T i7;
  int32_T i8;
  int32_T i9;
  int32_T i10;
  int32_T i11;
  int32_T i12;
  int32_T k_a;
  int32_T k_d;
  int32_T k_ey;
  int32_T k_eh;
  int32_T k_b;
  int32_T i13;
  int32_T k_a0;
  int32_T k_il;
  int32_T k_fa;
  int32_T k_ji;
  ZCEventType zcEvent;
  boolean_T P_f[4];
  boolean_T Z_h[4];
  boolean_T z_m4[4];
  boolean_T P_a[4];
  boolean_T Z_k[4];
  boolean_T w_p[4];
  boolean_T P_oo[3];
  boolean_T Z_f[3];
  boolean_T z_oy[3];
  boolean_T P_l[3];
  boolean_T Z_l[3];
  boolean_T w_g[3];
  int16_T iter;
  int16_T iter_j;
  int16_T iter_f;
  int16_T iter_js;
  int16_T iter_h;
  int16_T iter_c;
  int16_T iter_n;
  boolean_T P_d[2];
  boolean_T Z_d[2];
  boolean_T IsDiscrete;
  boolean_T found;
  boolean_T found_k;
  boolean_T found_a;
  boolean_T found_f;
  boolean_T found_j;
  boolean_T found_kl;
  boolean_T b_bn;
  boolean_T found_h;
  B_RLS_tune_T sf_RLS_j;               /* '<S20>/RLS' */
  B_RLS_tune_T sf_RLS;                 /* '<S19>/RLS' */
} B_tune_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  vexv5_SmartMotorRead_tune_T obj;     /* '<Root>/Smart Motor Read' */
  vexv5_SmartMotorWrite_tune_T obj_e;  /* '<Root>/Smart Motor Write' */
  real_T EnabledDelayY_DSTATE;         /* '<S7>/Enabled Delay Y' */
  real_T Integrator_DSTATE;            /* '<S106>/Integrator' */
  real_T Filter_DSTATE;                /* '<S101>/Filter' */
  real_T EnabledDelayU_DSTATE;         /* '<S7>/Enabled Delay U' */
  real_T PP;                           /* '<S1>/ExternalModeMonitor' */
  real_T II;                           /* '<S1>/ExternalModeMonitor' */
  real_T DD;                           /* '<S1>/ExternalModeMonitor' */
  real_T NN;                           /* '<S1>/ExternalModeMonitor' */
  real_T PM;                           /* '<S1>/ExternalModeMonitor' */
  real_T LastStartStop;                /* '<S1>/ExternalModeMonitor' */
  real_T delayL_DSTATE[121];           /* '<S20>/delayL' */
  real_T delayBuffery_DSTATE;          /* '<S20>/delayBuffery' */
  real_T delayBufferH_DSTATE;          /* '<S20>/delayBufferH' */
  real_T delayTheta_DSTATE[11];        /* '<S20>/delayTheta' */
  real_T delayL_DSTATE_k[121];         /* '<S19>/delayL' */
  real_T delayBuffery_DSTATE_c;        /* '<S19>/delayBuffery' */
  real_T delayBufferH_DSTATE_h;        /* '<S19>/delayBufferH' */
  real_T delayTheta_DSTATE_o[11];      /* '<S19>/delayTheta' */
  real_T TappedDelay_X[64];            /* '<S3>/Tapped Delay' */
  real_T UD_DSTATE;                    /* '<S10>/UD' */
  uint32_T Output_DSTATE;              /* '<S16>/Output' */
  int8_T GainsFromOnlineTuningModule_Sub;
                                    /* '<S1>/Gains From Online Tuning Module' */
  int8_T ResponseEstimation_SubsysRanBC;/* '<S12>/Response Estimation' */
  int8_T PerturbationGenerator_SubsysRan;/* '<S12>/Perturbation Generator' */
  int8_T ConvergenceCalculator_SubsysRan;/* '<S1>/Convergence Calculator' */
  boolean_T icLoad;                    /* '<S7>/Enabled Delay Y' */
  boolean_T icLoad_h;                  /* '<S7>/Enabled Delay U' */
  boolean_T objisempty;                /* '<Root>/Smart Motor Write' */
  boolean_T objisempty_a;              /* '<Root>/Smart Motor Read' */
  boolean_T icLoad_hd;                 /* '<S20>/delayL' */
  boolean_T icLoad_l;                  /* '<S20>/delayBuffery' */
  boolean_T icLoad_d;                  /* '<S20>/delayBufferH' */
  boolean_T icLoad_p;                  /* '<S20>/delayTheta' */
  boolean_T icLoad_dw;                 /* '<S19>/delayL' */
  boolean_T icLoad_j;                  /* '<S19>/delayBuffery' */
  boolean_T icLoad_c;                  /* '<S19>/delayBufferH' */
  boolean_T icLoad_a;                  /* '<S19>/delayTheta' */
  boolean_T ResponseEstimation_MODE;   /* '<S12>/Response Estimation' */
  boolean_T PerturbationGenerator_MODE;/* '<S12>/Perturbation Generator' */
  boolean_T ConvergenceCalculator_MODE;/* '<S1>/Convergence Calculator' */
  DW_RLS_tune_T sf_RLS_j;              /* '<S20>/RLS' */
  DW_RLS_tune_T sf_RLS;                /* '<S19>/RLS' */
} DW_tune_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState EnabledDelayY_Reset_ZCE;  /* '<S7>/Enabled Delay Y' */
  ZCSigState EnabledDelayU_Reset_ZCE;  /* '<S7>/Enabled Delay U' */
  ZCSigState GainsFromOnlineTuningModule_Tri;
                                    /* '<S1>/Gains From Online Tuning Module' */
} PrevZCX_tune_T;

/* Parameters (default storage) */
struct P_tune_T_ {
  real_T ClosedLoopPIDAutotuner_AmpSine;
                               /* Mask Parameter: ClosedLoopPIDAutotuner_AmpSine
                                * Referenced by: '<S1>/sine Amp constant'
                                */
  real_T ClosedLoopPIDAutotuner_Bandwidt;
                              /* Mask Parameter: ClosedLoopPIDAutotuner_Bandwidt
                               * Referenced by: '<S1>/bandwidth constant'
                               */
  real_T DiscretePIDController_D;     /* Mask Parameter: DiscretePIDController_D
                                       * Referenced by: '<S100>/Derivative Gain'
                                       */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S103>/Integral Gain'
                                       */
  real_T Difference1_ICPrevInput;     /* Mask Parameter: Difference1_ICPrevInput
                                       * Referenced by: '<S10>/UD'
                                       */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S101>/Filter'
                               */
  real_T DiscretePIDController_Initial_m;
                              /* Mask Parameter: DiscretePIDController_Initial_m
                               * Referenced by: '<S106>/Integrator'
                               */
  real_T DiscretePIDController_N;     /* Mask Parameter: DiscretePIDController_N
                                       * Referenced by: '<S109>/Filter Coefficient'
                                       */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S111>/Proportional Gain'
                                       */
  real_T ClosedLoopPIDAutotuner_PIDType;
                               /* Mask Parameter: ClosedLoopPIDAutotuner_PIDType
                                * Referenced by: '<S1>/PID type constant'
                                */
  real_T ClosedLoopPIDAutotuner_PlantSig;
                              /* Mask Parameter: ClosedLoopPIDAutotuner_PlantSig
                               * Referenced by: '<S1>/plant sign constant'
                               */
  real_T ClosedLoopPIDAutotuner_PlantTyp;
                              /* Mask Parameter: ClosedLoopPIDAutotuner_PlantTyp
                               * Referenced by: '<S1>/plant type constant'
                               */
  real_T ClosedLoopPIDAutotuner_TargetPM;
                              /* Mask Parameter: ClosedLoopPIDAutotuner_TargetPM
                               * Referenced by: '<S1>/target PM constant'
                               */
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S3>/Tapped Delay'
                                        */
  uint32_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S18>/FixPt Switch'
                                        */
  uint16_T ClosedLoopPIDAutotuner_PIDForm;
                               /* Mask Parameter: ClosedLoopPIDAutotuner_PIDForm
                                * Referenced by: '<S1>/PID form constant'
                                */
  real_T Constant_Value;               /* Expression: 1e-6
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: -1e-6
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S11>/Switch'
                                        */
  real_T convergence_Y0;               /* Computed Parameter: convergence_Y0
                                        * Referenced by: '<S3>/convergence'
                                        */
  real_T Gain_Gain;                    /* Expression: cast(1/64,DataType)
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Switch1_Threshold;            /* Expression: 1e-6
                                        * Referenced by: '<S11>/Switch1'
                                        */
  real_T Gain2_Gain;                   /* Expression: cast(100,DataType)
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Constant2_Value;              /* Expression: 100
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T one_constant_Value;           /* Expression: 1
                                        * Referenced by: '<S14>/one_constant'
                                        */
  real_T zero_constant_Value;          /* Expression: 0
                                        * Referenced by: '<S14>/zero_constant'
                                        */
  real_T signal_Y0;                    /* Computed Parameter: signal_Y0
                                        * Referenced by: '<S14>/signal'
                                        */
  real_T regressors_Y0;                /* Computed Parameter: regressors_Y0
                                        * Referenced by: '<S14>/regressors'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S14>/Switch2'
                                        */
  real_T Switch1_Threshold_i;          /* Expression: 0
                                        * Referenced by: '<S14>/Switch1'
                                        */
  real_T FreqResp_Y0;                  /* Computed Parameter: FreqResp_Y0
                                        * Referenced by: '<S15>/FreqResp'
                                        */
  real_T InitialCovariance_Value[121]; /* Expression: initializationParams.L0
                                        * Referenced by: '<S20>/InitialCovariance'
                                        */
  real_T NormalizationBias_Value;      /* Expression: initializationParams.adg2
                                        * Referenced by: '<S20>/Normalization Bias'
                                        */
  real_T InitialOutputs_Value;/* Expression: initializationParams.initialOutputs
                               * Referenced by: '<S20>/InitialOutputs'
                               */
  real_T InitialRegressors_Value;
                           /* Expression: initializationParams.initialRegressors
                            * Referenced by: '<S20>/InitialRegressors'
                            */
  real_T InitialParameters_Value[11]; /* Expression: initializationParams.theta0
                                       * Referenced by: '<S20>/InitialParameters'
                                       */
  real_T InitialCovariance_Value_k[121];/* Expression: initializationParams.L0
                                         * Referenced by: '<S19>/InitialCovariance'
                                         */
  real_T NormalizationBias_Value_j;    /* Expression: initializationParams.adg2
                                        * Referenced by: '<S19>/Normalization Bias'
                                        */
  real_T InitialOutputs_Value_i;
                              /* Expression: initializationParams.initialOutputs
                               * Referenced by: '<S19>/InitialOutputs'
                               */
  real_T InitialRegressors_Value_o;
                           /* Expression: initializationParams.initialRegressors
                            * Referenced by: '<S19>/InitialRegressors'
                            */
  real_T InitialParameters_Value_k[11];
                                      /* Expression: initializationParams.theta0
                                       * Referenced by: '<S19>/InitialParameters'
                                       */
  real_T Gain_Gain_n[5];               /* Expression: cast(ones(5,1),DataType)
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T GainP_Value;                  /* Expression: cast(tunedP,DataType)
                                        * Referenced by: '<S5>/GainP'
                                        */
  real_T GainD_Value;                  /* Expression: cast(tunedD,DataType)
                                        * Referenced by: '<S5>/GainD'
                                        */
  real_T P_Y0;                         /* Expression: 0
                                        * Referenced by: '<S6>/P'
                                        */
  real_T I_Y0;                         /* Expression: 0
                                        * Referenced by: '<S6>/I'
                                        */
  real_T D_Y0;                         /* Expression: 0
                                        * Referenced by: '<S6>/D'
                                        */
  real_T N_Y0;                         /* Expression: 100
                                        * Referenced by: '<S6>/N'
                                        */
  real_T achievedPM_Y0;                /* Expression: 0
                                        * Referenced by: '<S6>/achievedPM'
                                        */
  real_T Negative_Value;               /* Expression: -1
                                        * Referenced by: '<S1>/Negative'
                                        */
  real_T Positive_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Positive'
                                        */
  real_T Integrating_Value;            /* Expression: 1
                                        * Referenced by: '<S1>/Integrating'
                                        */
  real_T Stable_Value;                 /* Expression: 0
                                        * Referenced by: '<S1>/Stable'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/Zero'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<Root>/One'
                                        */
  real_T GainWC_Gain[5];         /* Expression: cast([1/10 1/3 1 3 10],DataType)
                                  * Referenced by: '<S1>/GainWC'
                                  */
  real_T has_integrator_constant1_Value;/* Expression: 1
                                         * Referenced by: '<S12>/has_integrator_constant1'
                                         */
  real_T WeightedTs_WtEt;              /* Computed Parameter: WeightedTs_WtEt
                                        * Referenced by: '<S1>/Weighted Ts'
                                        */
  real_T GainTs_Gain;                  /* Expression: 1
                                        * Referenced by: '<S1>/GainTs'
                                        */
  real_T ref_Value;                    /* Expression: 0
                                        * Referenced by: '<Root>/ref'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S106>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S101>/Filter'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<S74>/Switch'
                                        */
  real_T Constant1_Value_k;            /* Expression: EstimationWindowSize
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant2_Value_b;            /* Expression: 60
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T PlantTypeSwitch_Threshold;    /* Expression: 1.5
                                        * Referenced by: '<S1>/Plant Type Switch'
                                        */
  real_T PlantSignSwitch_Threshold;    /* Expression: 1.5
                                        * Referenced by: '<S1>/Plant Sign Switch'
                                        */
  real_T GainPM_Gain;                  /* Expression: cast(1,DataType)
                                        * Referenced by: '<S1>/GainPM'
                                        */
  real_T Constant_Value_e;             /* Expression: NotDeployTuningModule
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T GainSwitch_1_Threshold;       /* Expression: 0
                                        * Referenced by: '<S1>/Gain Switch'
                                        */
  real_T GainSwitch_3_Threshold;       /* Expression: 0
                                        * Referenced by: '<S1>/Gain Switch'
                                        */
  uint32_T Constant_Value_ek;          /* Computed Parameter: Constant_Value_ek
                                        * Referenced by: '<S18>/Constant'
                                        */
  uint32_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S16>/Output'
                                   */
  uint32_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S17>/FixPt Constant'
                                       */
  uint16_T DeployedMode_TimeDomain;
                                  /* Computed Parameter: DeployedMode_TimeDomain
                                   * Referenced by: '<S71>/DeployedMode'
                                   */
  uint16_T integratorformulaconstant_Value;
                          /* Computed Parameter: integratorformulaconstant_Value
                           * Referenced by: '<S1>/integrator formula constant'
                           */
  uint16_T filterformulaconstant_Value;
                              /* Computed Parameter: filterformulaconstant_Value
                               * Referenced by: '<S1>/filter formula constant'
                               */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S20>/Enable'
                                        */
  boolean_T Delay_InitialCondition;    /* Expression: true()
                                        * Referenced by: '<S63>/Delay'
                                        */
  boolean_T Enable_Value_h;            /* Expression: true()
                                        * Referenced by: '<S19>/Enable'
                                        */
  boolean_T Delay_InitialCondition_i;  /* Expression: true()
                                        * Referenced by: '<S38>/Delay'
                                        */
  boolean_T Constant_Value_o;          /* Expression: false()
                                        * Referenced by: '<S38>/Constant'
                                        */
  boolean_T Constant_Value_oc;         /* Expression: false()
                                        * Referenced by: '<S63>/Constant'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_tune_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_tune_T tune_P;

/* Block signals (default storage) */
extern B_tune_T tune_B;

/* Block states (default storage) */
extern DW_tune_T tune_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_tune_T tune_PrevZCX;

/* Model entry point functions */
extern void tune_initialize(void);
extern void tune_step(void);
extern void tune_terminate(void);

/* Real-time Model object */
extern RT_MODEL_tune_T *const tune_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S16>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S17>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S19>/Check Same Ts' : Unused code path elimination
 * Block '<S26>/Output Dimension' : Unused code path elimination
 * Block '<S26>/Regressors Dimension' : Unused code path elimination
 * Block '<S26>/Sample Times and Data Type' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/S-Function' : Unused code path elimination
 * Block '<S44>/Gain' : Unused code path elimination
 * Block '<S44>/Selector' : Unused code path elimination
 * Block '<S20>/Check Same Ts' : Unused code path elimination
 * Block '<S51>/Output Dimension' : Unused code path elimination
 * Block '<S51>/Regressors Dimension' : Unused code path elimination
 * Block '<S51>/Sample Times and Data Type' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/S-Function' : Unused code path elimination
 * Block '<S69>/Gain' : Unused code path elimination
 * Block '<S69>/Selector' : Unused code path elimination
 * Block '<S5>/GainI' : Unused code path elimination
 * Block '<S5>/GainN' : Unused code path elimination
 * Block '<S5>/acheivedPM' : Unused code path elimination
 * Block '<S1>/PM Switch' : Unused code path elimination
 * Block '<S3>/MinMax1' : Eliminated since input is scalar
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion_Ts' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_PM' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_StartStop' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_ampSine' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_ui' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_wC' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_y' : Eliminate redundant data type conversion
 * Block '<S27>/Conversion' : Eliminate redundant data type conversion
 * Block '<S33>/Conversion' : Eliminate redundant data type conversion
 * Block '<S34>/Conversion' : Eliminate redundant data type conversion
 * Block '<S35>/Conversion' : Eliminate redundant data type conversion
 * Block '<S36>/Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S52>/Conversion' : Eliminate redundant data type conversion
 * Block '<S58>/Conversion' : Eliminate redundant data type conversion
 * Block '<S59>/Conversion' : Eliminate redundant data type conversion
 * Block '<S60>/Conversion' : Eliminate redundant data type conversion
 * Block '<S61>/Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S74>/Zero-Order Hold2' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'tune'
 * '<S1>'   : 'tune/Closed-Loop PID Autotuner'
 * '<S2>'   : 'tune/Discrete PID Controller'
 * '<S3>'   : 'tune/Closed-Loop PID Autotuner/Convergence Calculator'
 * '<S4>'   : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator'
 * '<S5>'   : 'tune/Closed-Loop PID Autotuner/Gains From Offline Tuning Module'
 * '<S6>'   : 'tune/Closed-Loop PID Autotuner/Gains From Online Tuning Module'
 * '<S7>'   : 'tune/Closed-Loop PID Autotuner/New Nominal Detector'
 * '<S8>'   : 'tune/Closed-Loop PID Autotuner/Tuning Module Sample Time Parameters'
 * '<S9>'   : 'tune/Closed-Loop PID Autotuner/Variant Subsystem'
 * '<S10>'  : 'tune/Closed-Loop PID Autotuner/Convergence Calculator/Difference1'
 * '<S11>'  : 'tune/Closed-Loop PID Autotuner/Convergence Calculator/Zero protection'
 * '<S12>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed'
 * '<S13>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/FF Calculation'
 * '<S14>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Perturbation Generator'
 * '<S15>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation'
 * '<S16>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Perturbation Generator/Counter Free-Running'
 * '<S17>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Perturbation Generator/Counter Free-Running/Increment Real World'
 * '<S18>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Perturbation Generator/Counter Free-Running/Wrap To Zero'
 * '<S19>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)'
 * '<S20>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)'
 * '<S21>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Check Enable Signal'
 * '<S22>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Check Initial Covariance'
 * '<S23>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Check Initial Outputs'
 * '<S24>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Check Initial Parameters'
 * '<S25>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Check Initial Regressors'
 * '<S26>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Check Signals'
 * '<S27>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Data Type Conversion - AdaptationParameter1'
 * '<S28>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Data Type Conversion - AdaptationParameter2'
 * '<S29>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Data Type Conversion - InitialCovariance'
 * '<S30>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Data Type Conversion - InitialOutputs'
 * '<S31>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Data Type Conversion - InitialParameters'
 * '<S32>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Data Type Conversion - InitialRegressors'
 * '<S33>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Data Type Conversion - L'
 * '<S34>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Data Type Conversion - Theta'
 * '<S35>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Data Type Conversion - bufferH'
 * '<S36>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Data Type Conversion - buffery'
 * '<S37>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/MultiplyWithTranspose'
 * '<S38>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Process Reset'
 * '<S39>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/ProcessInitialCovariance'
 * '<S40>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/ProcessInitialOutputs'
 * '<S41>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/ProcessInitialParameters'
 * '<S42>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/ProcessInitialRegressors'
 * '<S43>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/RLS'
 * '<S44>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Reset'
 * '<S45>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator 1//(1+GC)/Process Reset/Check Reset'
 * '<S46>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Check Enable Signal'
 * '<S47>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Check Initial Covariance'
 * '<S48>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Check Initial Outputs'
 * '<S49>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Check Initial Parameters'
 * '<S50>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Check Initial Regressors'
 * '<S51>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Check Signals'
 * '<S52>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Data Type Conversion - AdaptationParameter1'
 * '<S53>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Data Type Conversion - AdaptationParameter2'
 * '<S54>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Data Type Conversion - InitialCovariance'
 * '<S55>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Data Type Conversion - InitialOutputs'
 * '<S56>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Data Type Conversion - InitialParameters'
 * '<S57>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Data Type Conversion - InitialRegressors'
 * '<S58>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Data Type Conversion - L'
 * '<S59>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Data Type Conversion - Theta'
 * '<S60>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Data Type Conversion - bufferH'
 * '<S61>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Data Type Conversion - buffery'
 * '<S62>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/MultiplyWithTranspose'
 * '<S63>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Process Reset'
 * '<S64>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/ProcessInitialCovariance'
 * '<S65>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/ProcessInitialOutputs'
 * '<S66>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/ProcessInitialParameters'
 * '<S67>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/ProcessInitialRegressors'
 * '<S68>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/RLS'
 * '<S69>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Reset'
 * '<S70>'  : 'tune/Closed-Loop PID Autotuner/Frequency Response Estimator/Superimposed/Response Estimation/RLS Estimator G//(1+GC)/Process Reset/Check Reset'
 * '<S71>'  : 'tune/Closed-Loop PID Autotuner/Gains From Online Tuning Module/Tune Subsystem'
 * '<S72>'  : 'tune/Closed-Loop PID Autotuner/Gains From Online Tuning Module/Tune Subsystem/DeployedMode'
 * '<S73>'  : 'tune/Closed-Loop PID Autotuner/Tuning Module Sample Time Parameters/single rate'
 * '<S74>'  : 'tune/Closed-Loop PID Autotuner/Variant Subsystem/ControlPlusPerturb'
 * '<S75>'  : 'tune/Discrete PID Controller/Anti-windup'
 * '<S76>'  : 'tune/Discrete PID Controller/D Gain'
 * '<S77>'  : 'tune/Discrete PID Controller/Filter'
 * '<S78>'  : 'tune/Discrete PID Controller/Filter ICs'
 * '<S79>'  : 'tune/Discrete PID Controller/I Gain'
 * '<S80>'  : 'tune/Discrete PID Controller/Ideal P Gain'
 * '<S81>'  : 'tune/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S82>'  : 'tune/Discrete PID Controller/Integrator'
 * '<S83>'  : 'tune/Discrete PID Controller/Integrator ICs'
 * '<S84>'  : 'tune/Discrete PID Controller/N Copy'
 * '<S85>'  : 'tune/Discrete PID Controller/N Gain'
 * '<S86>'  : 'tune/Discrete PID Controller/P Copy'
 * '<S87>'  : 'tune/Discrete PID Controller/Parallel P Gain'
 * '<S88>'  : 'tune/Discrete PID Controller/Reset Signal'
 * '<S89>'  : 'tune/Discrete PID Controller/Saturation'
 * '<S90>'  : 'tune/Discrete PID Controller/Saturation Fdbk'
 * '<S91>'  : 'tune/Discrete PID Controller/Sum'
 * '<S92>'  : 'tune/Discrete PID Controller/Sum Fdbk'
 * '<S93>'  : 'tune/Discrete PID Controller/Tracking Mode'
 * '<S94>'  : 'tune/Discrete PID Controller/Tracking Mode Sum'
 * '<S95>'  : 'tune/Discrete PID Controller/Tsamp - Integral'
 * '<S96>'  : 'tune/Discrete PID Controller/Tsamp - Ngain'
 * '<S97>'  : 'tune/Discrete PID Controller/postSat Signal'
 * '<S98>'  : 'tune/Discrete PID Controller/preSat Signal'
 * '<S99>'  : 'tune/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S100>' : 'tune/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S101>' : 'tune/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S102>' : 'tune/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S103>' : 'tune/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S104>' : 'tune/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S105>' : 'tune/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S106>' : 'tune/Discrete PID Controller/Integrator/Discrete'
 * '<S107>' : 'tune/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S108>' : 'tune/Discrete PID Controller/N Copy/Disabled'
 * '<S109>' : 'tune/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S110>' : 'tune/Discrete PID Controller/P Copy/Disabled'
 * '<S111>' : 'tune/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S112>' : 'tune/Discrete PID Controller/Reset Signal/Disabled'
 * '<S113>' : 'tune/Discrete PID Controller/Saturation/Passthrough'
 * '<S114>' : 'tune/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S115>' : 'tune/Discrete PID Controller/Sum/Sum_PID'
 * '<S116>' : 'tune/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S117>' : 'tune/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S118>' : 'tune/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S119>' : 'tune/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S120>' : 'tune/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S121>' : 'tune/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S122>' : 'tune/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_tune_h_ */
