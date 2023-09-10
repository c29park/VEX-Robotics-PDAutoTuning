/*
 * tune_data.c
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

/* Block parameters (default storage) */
P_tune_T tune_P = {
  /* Mask Parameter: ClosedLoopPIDAutotuner_AmpSine
   * Referenced by: '<S1>/sine Amp constant'
   */
  10.0,

  /* Mask Parameter: ClosedLoopPIDAutotuner_Bandwidt
   * Referenced by: '<S1>/bandwidth constant'
   */
  12.56,

  /* Mask Parameter: DiscretePIDController_D
   * Referenced by: '<S100>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S103>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: Difference1_ICPrevInput
   * Referenced by: '<S10>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S101>/Filter'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_Initial_m
   * Referenced by: '<S106>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_N
   * Referenced by: '<S109>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S111>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: ClosedLoopPIDAutotuner_PIDType
   * Referenced by: '<S1>/PID type constant'
   */
  4.0,

  /* Mask Parameter: ClosedLoopPIDAutotuner_PlantSig
   * Referenced by: '<S1>/plant sign constant'
   */
  1.0,

  /* Mask Parameter: ClosedLoopPIDAutotuner_PlantTyp
   * Referenced by: '<S1>/plant type constant'
   */
  1.0,

  /* Mask Parameter: ClosedLoopPIDAutotuner_TargetPM
   * Referenced by: '<S1>/target PM constant'
   */
  60.0,

  /* Mask Parameter: TappedDelay_vinit
   * Referenced by: '<S3>/Tapped Delay'
   */
  1.0,

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S18>/FixPt Switch'
   */
  4294967295U,

  /* Mask Parameter: ClosedLoopPIDAutotuner_PIDForm
   * Referenced by: '<S1>/PID form constant'
   */
  1U,

  /* Expression: 1e-6
   * Referenced by: '<S11>/Constant'
   */
  1.0E-6,

  /* Expression: -1e-6
   * Referenced by: '<S11>/Constant1'
   */
  -1.0E-6,

  /* Expression: 0
   * Referenced by: '<S11>/Switch'
   */
  0.0,

  /* Computed Parameter: convergence_Y0
   * Referenced by: '<S3>/convergence'
   */
  0.0,

  /* Expression: cast(1/64,DataType)
   * Referenced by: '<S3>/Gain'
   */
  0.015625,

  /* Expression: 1e-6
   * Referenced by: '<S11>/Switch1'
   */
  1.0E-6,

  /* Expression: cast(100,DataType)
   * Referenced by: '<S3>/Gain2'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S3>/Saturation'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S3>/Saturation'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S3>/Constant2'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<S14>/one_constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S14>/zero_constant'
   */
  0.0,

  /* Computed Parameter: signal_Y0
   * Referenced by: '<S14>/signal'
   */
  0.0,

  /* Computed Parameter: regressors_Y0
   * Referenced by: '<S14>/regressors'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/Switch2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/Switch1'
   */
  0.0,

  /* Computed Parameter: FreqResp_Y0
   * Referenced by: '<S15>/FreqResp'
   */
  0.0,

  /* Expression: initializationParams.L0
   * Referenced by: '<S20>/InitialCovariance'
   */
  { 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 100.0 },

  /* Expression: initializationParams.adg2
   * Referenced by: '<S20>/Normalization Bias'
   */
  0.0,

  /* Expression: initializationParams.initialOutputs
   * Referenced by: '<S20>/InitialOutputs'
   */
  0.0,

  /* Expression: initializationParams.initialRegressors
   * Referenced by: '<S20>/InitialRegressors'
   */
  0.0,

  /* Expression: initializationParams.theta0
   * Referenced by: '<S20>/InitialParameters'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /* Expression: initializationParams.L0
   * Referenced by: '<S19>/InitialCovariance'
   */
  { 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 100.0 },

  /* Expression: initializationParams.adg2
   * Referenced by: '<S19>/Normalization Bias'
   */
  0.0,

  /* Expression: initializationParams.initialOutputs
   * Referenced by: '<S19>/InitialOutputs'
   */
  0.0,

  /* Expression: initializationParams.initialRegressors
   * Referenced by: '<S19>/InitialRegressors'
   */
  0.0,

  /* Expression: initializationParams.theta0
   * Referenced by: '<S19>/InitialParameters'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /* Expression: cast(ones(5,1),DataType)
   * Referenced by: '<S15>/Gain'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0 },

  /* Expression: cast(tunedP,DataType)
   * Referenced by: '<S5>/GainP'
   */
  0.0,

  /* Expression: cast(tunedD,DataType)
   * Referenced by: '<S5>/GainD'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/P'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/I'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/D'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S6>/N'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S6>/achievedPM'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/Negative'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Positive'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Integrating'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Stable'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Zero'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/One'
   */
  1.0,

  /* Expression: cast([1/10 1/3 1 3 10],DataType)
   * Referenced by: '<S1>/GainWC'
   */
  { 0.1, 0.33333333333333331, 1.0, 3.0, 10.0 },

  /* Expression: 1
   * Referenced by: '<S12>/has_integrator_constant1'
   */
  1.0,

  /* Computed Parameter: WeightedTs_WtEt
   * Referenced by: '<S1>/Weighted Ts'
   */
  0.02,

  /* Expression: 1
   * Referenced by: '<S1>/GainTs'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/ref'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S106>/Integrator'
   */
  0.2,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S101>/Filter'
   */
  0.2,

  /* Expression: 0
   * Referenced by: '<S74>/Switch'
   */
  0.0,

  /* Expression: EstimationWindowSize
   * Referenced by: '<S13>/Constant1'
   */
  3.0,

  /* Expression: 60
   * Referenced by: '<S13>/Constant2'
   */
  60.0,

  /* Expression: 1
   * Referenced by: '<S13>/Constant'
   */
  1.0,

  /* Expression: 1.5
   * Referenced by: '<S1>/Plant Type Switch'
   */
  1.5,

  /* Expression: 1.5
   * Referenced by: '<S1>/Plant Sign Switch'
   */
  1.5,

  /* Expression: cast(1,DataType)
   * Referenced by: '<S1>/GainPM'
   */
  1.0,

  /* Expression: NotDeployTuningModule
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Gain Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Gain Switch'
   */
  0.0,

  /* Computed Parameter: Constant_Value_ek
   * Referenced by: '<S18>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S16>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S17>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: DeployedMode_TimeDomain
   * Referenced by: '<S71>/DeployedMode'
   */
  1U,

  /* Computed Parameter: integratorformulaconstant_Value
   * Referenced by: '<S1>/integrator formula constant'
   */
  1U,

  /* Computed Parameter: filterformulaconstant_Value
   * Referenced by: '<S1>/filter formula constant'
   */
  1U,

  /* Expression: true()
   * Referenced by: '<S20>/Enable'
   */
  true,

  /* Expression: true()
   * Referenced by: '<S63>/Delay'
   */
  true,

  /* Expression: true()
   * Referenced by: '<S19>/Enable'
   */
  true,

  /* Expression: true()
   * Referenced by: '<S38>/Delay'
   */
  true,

  /* Expression: false()
   * Referenced by: '<S38>/Constant'
   */
  false,

  /* Expression: false()
   * Referenced by: '<S63>/Constant'
   */
  false,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U
};
