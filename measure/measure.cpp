/*
 * File: measure.cpp
 *
 * Code generated for Simulink model 'measure'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Fri May 25 14:57:35 2012
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "measure.h"
#include "measure_private.h"

/* Model step function */
void measureModelClass::step()
{
  boolean_T rtb_UnitDelay4_hd;
  boolean_T rtb_UnitDelay4_ej;
  boolean_T rtb_LogicalOperator1_f;
  real_T rtb_Switch_b2;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_c2o;
  boolean_T rtb_Compare_f;
  real_T rtb_UnitDelay1;
  real_T rtb_UnitDelay1_a;
  real_T rtb_UnaryMinus_p;
  real_T rtb_UnitDelay1_i;
  real_T rtb_Divide_jahfx;
  real_T rtb_TrigonometricFunction;
  real_T rtb_Sum2_g;
  real_T rtb_MathFunction1;
  real_T rtb_Switch;
  real_T rtb_Gain_m;
  boolean_T rtb_Compare_c2os;
  real_T rtb_Tps2dt_m;
  uint32_T rtb_Switch1_bxh;
  boolean_T rtb_Compare_c2;
  boolean_T rtb_Compare_d;
  boolean_T rtb_LogicalOperator1_drl4;
  boolean_T rtb_LogicalOperator_aiui;
  real_T rtb_Subtract3_o;
  real_T rtb_MathFunction_bdy;
  real_T rtb_UnaryMinus_a2;
  boolean_T rtb_Compare_no;
  uint32_T rtb_Switch1_c1;
  boolean_T rtb_LogicalOperator1_i;
  uint32_T rtb_UnitDelay1_n0;
  real_T rtb_UnitDelay2_j;
  boolean_T rtb_LogicalOperator16;
  uint32_T rtb_UnitDelay1_k;
  boolean_T rtb_Compare_o;
  boolean_T rtb_LogicalOperator1_b2ck;
  real_T rtb_Sum;
  real_T rtb_Divide_jahf;
  boolean_T rtb_LogicalOperator_aj;
  real_T rtb_Subtract3_c0;
  real_T rtb_MathFunction_ed1;
  real_T rtb_Divide_ja;
  real_T rtb_MathFunction2;
  boolean_T rtb_RelationalOperator_c;
  boolean_T rtb_Compare_k1g;
  uint32_T rtb_Switch1_m;
  boolean_T rtb_Compare_ha;
  real_T rtb_MathFunction2_c;
  boolean_T rtb_RelationalOperator_i;
  boolean_T rtb_Compare_aun;
  uint32_T rtb_Switch1_o;
  boolean_T rtb_Compare_df;
  real_T rtb_MathFunction2_a;
  boolean_T rtb_RelationalOperator_h;
  boolean_T rtb_Compare_o1;
  uint32_T rtb_Switch1_k3g;
  boolean_T rtb_Compare_m3;
  boolean_T rtb_LogicalOperator9;
  boolean_T rtb_Compare_mp;
  boolean_T rtb_Compare_go;
  real_T rtb_Divide_h3;
  boolean_T rtb_Compare_oafgue;
  boolean_T rtb_Compare_k5;
  boolean_T rtb_Compare_oafguee;
  boolean_T rtb_Compare_bq;
  boolean_T rtb_Compare_cj;
  real_T rtb_Subtract3_c04;
  real_T rtb_MathFunction_ed12;
  real_T rtb_Divide_jah;
  real_T rtb_Divide_h;
  real_T rtb_TrigonometricFunction_l;
  boolean_T rtb_LogicalOperator_ot;
  real_T rtb_Divide_ny;
  uint32_T rtb_Switch1_d;
  real_T rtb_UnitDelay_j;
  uint32_T rtb_Switch1_ce;
  boolean_T rtb_Compare_k1;
  boolean_T rtb_LogicalOperator2_c1;
  boolean_T rtb_Compare_eb;
  uint32_T rtb_Switch_jv;
  boolean_T rtb_Compare_cz;
  uint32_T rtb_Switch_jvw;
  boolean_T rtb_Compare_czp;
  uint32_T rtb_Switch_jvwj;
  boolean_T rtb_Compare_czp1;
  boolean_T rtb_Disturbance_All_Phases;
  uint32_T rtb_Switch1_cc;
  real_T rtb_UnitDelay_n;
  uint32_T rtb_Switch1_ky;
  boolean_T rtb_Compare_au;
  uint32_T rtb_Switch1_kyp;
  boolean_T rtb_LogicalOperator2_bf;
  boolean_T rtb_LogicalOperator2_b0;
  uint32_T rtb_Switch1_oi;
  real_T rtb_UnitDelay_ic;
  boolean_T rtb_Compare_ge;
  uint32_T rtb_Switch1_cg;
  boolean_T rtb_Compare_g;
  uint32_T rtb_Switch1_cgb;
  boolean_T rtb_LogicalOperator2_bg;
  boolean_T rtb_LogicalOperator2_m;
  boolean_T rtb_LogicalOperator12;
  real_T rtb_Product_i;
  boolean_T rtb_LogicalOperator1_bbcu;
  real_T rtb_Divide_n;
  real_T rtb_TrigonometricFunction_c;
  real_T rtb_Divide_jw;
  real_T rtb_Divide_j;
  real_T rtb_TrigonometricFunction_b;
  int32_T i;
  real_T rtb_IpktoIrmsconversion;
  uint32_T rtb_Switch_oh;
  real_T rtb_Switch1_c;
  uint32_T rtb_Bias_hsr;
  boolean_T rtb_Compare_n;
  boolean_T rtb_LogicalOperator2_f;
  boolean_T rtb_LogicalOperator2_fd;
  real_T rtb_IpktoIrms_a;
  real_T rtb_AbsVI;
  real_T rtb_Switch_b;
  real_T rtb_AbsVI_e;
  real_T rtb_UnaryMinus_dv;
  real_T rtb_Divide_jahfx5;
  real_T rtb_ScaleRMSoutputsto1pu;
  real_T rtb_UnitDelay1_l;
  real_T rtb_UnitDelay1_f;
  real_T rtb_UnitDelay1_lu;
  uint32_T rtb_UnitDelay1_pf;
  uint32_T rtb_Switch2_a;
  uint32_T rtb_UnitDelay1_nt;
  real_T rtb_Bias1;
  real_T rtb_Bias;
  real_T rtb_Bias2;
  real_T rtb_Switch1;
  real_T rtb_Switch1_b;
  real_T rtb_Switch1_k;
  real_T rtb_Switch_j;
  real_T rtb_Add_a;
  real_T rtb_Switch_l40f02;
  real_T rtb_Add_o;
  real_T rtb_Switch_l40f;
  real_T rtb_Add_h;
  real_T rtb_Switch_l4;
  real_T rtb_Switch_c;
  uint32_T rtb_FixPtSum1;
  uint32_T rtb_FixPtSum1_j;
  uint32_T rtb_FixPtSum1_ja;
  uint32_T rtb_Switch1_bx;
  uint32_T rtb_FixPtSum1_g;
  uint32_T rtb_FixPtSum1_go;
  uint32_T rtb_Switch1_gmkuez3wo;
  uint32_T rtb_Switch1_gmkuez3woc;
  uint32_T rtb_Switch_iwltec;
  uint32_T rtb_FixPtSum1_m;
  uint32_T rtb_Switch1_kn;
  uint32_T rtb_FixPtSum1_l;
  uint32_T rtb_FixPtSum1_h;
  uint32_T rtb_FixPtSum1_a;
  uint32_T rtb_FixPtSum1_an;
  uint32_T rtb_FixPtSum1_c;
  uint32_T rtb_FixPtSum1_p;
  uint32_T rtb_FixPtSum1_ln;
  uint32_T rtb_FixPtSum1_lnu;
  uint32_T rtb_FixPtSum1_cy;
  uint32_T rtb_FixPtSum1_mz;
  uint32_T rtb_FixPtSum1_f;
  real_T rtb_Switch1_kt5c;
  boolean_T rtb_Any_Phases_Not_Disturbed;
  real_T rtb_Switch4;
  real_T tmp[6];
  boolean_T rtb_Switch6_idx;
  real_T rtb_Add1_h_idx;
  real_T rtb_Add1_h_idx_0;
  real_T rtb_Add1_h_idx_1;

  /* S-Function "SF_FixedDiscreteDelay" Block: <S1027>/SF_FixedDiscreteDelay S-function */
  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfuncti_c3[0];
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_i;
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunction_;
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = *xD;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfunctio_g + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfunctio_g;
    measure_B.SF_FixedDiscreteDelaySfunction = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfunctio_g)
      *VDD_in = 0;
  }

  /* UnitDelay: '<S494>/Unit Delay4' */
  rtb_UnitDelay4_hd = measure_DWork.UnitDelay4_DSTATE_ep;

  /* Switch: '<S504>/Switch1' incorporates:
   *  Logic: '<S1025>/Logical Operator'
   *  Logic: '<S1025>/Logical Operator1'
   *  UnitDelay: '<S1025>/delay'
   *  UnitDelay: '<S494>/Unit Delay4'
   *  UnitDelay: '<S504>/Unit Delay'
   */
  if (measure_DWork.UnitDelay4_DSTATE_ep && (!measure_DWork.delay_DSTATE)) {
    rtb_Switch1 = measure_B.SF_FixedDiscreteDelaySfunction;
  } else {
    rtb_Switch1 = measure_DWork.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S504>/Switch1' */
  /* S-Function "SF_FixedDiscreteDelay" Block: <S459>/SF_FixedDiscreteDelay S-function */
  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfunctio_l[0];
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_e;
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_c;
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = *xD;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfuncti_o0 + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfuncti_o0;
    measure_B.SF_FixedDiscreteDelaySfunctio_k = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfuncti_o0)
      *VDD_in = 0;
  }

  /* UnitDelay: '<S312>/Unit Delay4' */
  rtb_UnitDelay4_ej = measure_DWork.UnitDelay4_DSTATE_krxzyrkobej;

  /* Switch: '<S316>/Switch1' incorporates:
   *  Logic: '<S457>/Logical Operator'
   *  Logic: '<S457>/Logical Operator1'
   *  UnitDelay: '<S312>/Unit Delay4'
   *  UnitDelay: '<S316>/Unit Delay'
   *  UnitDelay: '<S457>/delay'
   */
  if (measure_DWork.UnitDelay4_DSTATE_krxzyrkobej &&
      (!measure_DWork.delay_DSTATE_b)) {
    rtb_Switch1_b = measure_B.SF_FixedDiscreteDelaySfunctio_k;
  } else {
    rtb_Switch1_b = measure_DWork.UnitDelay_DSTATE_i;
  }

  /* End of Switch: '<S316>/Switch1' */

  /* Switch: '<S313>/Switch1' incorporates:
   *  Constant: '<S313>/Constant1'
   *  UnitDelay: '<S309>/Unit Delay'
   *  UnitDelay: '<S312>/Unit Delay4'
   */
  if (measure_DWork.UnitDelay4_DSTATE_krxzyrkobej) {
    rtb_Switch1_k = measure_DWork.UnitDelay_DSTATE_e;
  } else {
    rtb_Switch1_k = measure_P.Constant1_Value_n;
  }

  /* End of Switch: '<S313>/Switch1' */

  /* Logic: '<S313>/Logical Operator1' incorporates:
   *  Logic: '<S309>/Logical Operator2'
   *  UnitDelay: '<S309>/Unit Delay2'
   *  UnitDelay: '<S312>/Unit Delay4'
   */
  rtb_LogicalOperator1_f = (measure_DWork.UnitDelay4_DSTATE_krxzyrkobej ||
    (!measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b3));

  /* DiscretePulseGenerator: '<S475>/Pulse Generator1' */
  rtb_Switch_b2 = ((real_T)measure_DWork.clockTickCounter <
                   measure_P.PulseGenerator1_Duty) &&
    (measure_DWork.clockTickCounter >= 0) ? measure_P.PulseGenerator1_Amp : 0.0;
  if ((real_T)measure_DWork.clockTickCounter >= measure_P.PulseGenerator1_Period
      - 1.0) {
    measure_DWork.clockTickCounter = 0;
  } else {
    measure_DWork.clockTickCounter = measure_DWork.clockTickCounter + 1;
  }

  /* End of DiscretePulseGenerator: '<S475>/Pulse Generator1' */

  /* RelationalOperator: '<S481>/Compare' incorporates:
   *  Constant: '<S481>/Constant'
   */
  rtb_Compare = (rtb_Switch_b2 > measure_P.Constant_Value_hpxmk);

  /* Logic: '<S479>/Logical Operator1' incorporates:
   *  Logic: '<S479>/Logical Operator2'
   *  UnitDelay: '<S479>/delay1'
   */
  rtb_Compare_c2o = ((!rtb_Compare) && measure_DWork.delay1_DSTATE);

  /* DiscretePulseGenerator: '<S460>/Pulse Generator1' */
  rtb_Switch_b2 = ((real_T)measure_DWork.clockTickCounter_f <
                   measure_P.PulseGenerator1_Duty_h) &&
    (measure_DWork.clockTickCounter_f >= 0) ? measure_P.PulseGenerator1_Amp_h :
    0.0;
  if ((real_T)measure_DWork.clockTickCounter_f >=
      measure_P.PulseGenerator1_Period_h - 1.0) {
    measure_DWork.clockTickCounter_f = 0;
  } else {
    measure_DWork.clockTickCounter_f = measure_DWork.clockTickCounter_f + 1;
  }

  /* End of DiscretePulseGenerator: '<S460>/Pulse Generator1' */

  /* RelationalOperator: '<S466>/Compare' incorporates:
   *  Constant: '<S466>/Constant'
   */
  rtb_Compare_f = (rtb_Switch_b2 > measure_P.Constant_Value_hpxmkf);

  /* UnitDelay: '<S85>/Unit Delay1' */
  rtb_UnitDelay1 = measure_DWork.UnitDelay1_DSTATE;

  /* MinMax: '<S1>/MinMax' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Constant: '<Root>/Constant8'
   */
  rtb_Gain_m = measure_P.Constant7_Value[0];
  for (i = 0; i < 5; i++) {
    tmp[0] = measure_P.Constant7_Value[0];
    tmp[1] = measure_P.Constant7_Value[1];
    tmp[2] = measure_P.Constant7_Value[2];
    tmp[3] = measure_P.Constant8_Value[0];
    tmp[4] = measure_P.Constant8_Value[1];
    tmp[5] = measure_P.Constant8_Value[2];
    rtb_Gain_m = rtb_Gain_m >= tmp[i + 1] ? rtb_Gain_m : tmp[i + 1];
  }

  /* Sum: '<S1>/Add1' incorporates:
   *  Constant: '<Root>/Constant8'
   *  MinMax: '<S1>/MinMax'
   */
  rtb_Add1_h_idx = rtb_Gain_m - measure_P.Constant8_Value[0];
  rtb_Add1_h_idx_0 = rtb_Gain_m - measure_P.Constant8_Value[1];
  rtb_Add1_h_idx_1 = rtb_Gain_m - measure_P.Constant8_Value[2];

  /* Bias: '<S85>/Bias' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Gain: '<S85>/Gain'
   *  MinMax: '<S1>/MinMax'
   *  Sum: '<S1>/Add1'
   */
  rtb_Switch_b2 = (rtb_Gain_m - measure_P.Constant7_Value[1]) *
    measure_P.Gain_Gain_h + measure_P.Bias_Bias_j;

  /* Sum: '<S92>/Sum1' incorporates:
   *  Gain: '<S93>/Gain'
   *  Gain: '<S93>/Gain1'
   *  Inport: '<Root>/Vabc (pu)'
   *  Math: '<S92>/Math Function'
   *  Product: '<S92>/Product'
   *  Product: '<S92>/Product1'
   *  Sum: '<S93>/Sum1'
   *  Sum: '<S93>/Sum2'
   *  Sum: '<S93>/Sum7'
   *  UnitDelay: '<S85>/Unit Delay1'
   *  UnitDelay: '<S85>/Unit Delay2'
   */
  rtb_Switch_b2 = ((measure_U.Vabcpu[1] - measure_DWork.UnitDelay2_DSTATE) *
                   measure_P.Gain_Gain_g * rtb_Switch_b2 +
                   measure_DWork.UnitDelay1_DSTATE) +
    ((measure_DWork.UnitDelay2_DSTATE + measure_U.Vabcpu[1]) *
     measure_P.Gain1_Gain_d - measure_DWork.UnitDelay1_DSTATE) * (rtb_Switch_b2 *
    rtb_Switch_b2);

  /* UnitDelay: '<S86>/Unit Delay1' */
  rtb_UnitDelay1_a = measure_DWork.UnitDelay1_DSTATE_i;

  /* Bias: '<S86>/Bias' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Gain: '<S86>/Gain'
   *  MinMax: '<S1>/MinMax'
   *  Sum: '<S1>/Add1'
   */
  rtb_UnaryMinus_p = (rtb_Gain_m - measure_P.Constant7_Value[2]) *
    measure_P.Gain_Gain_d + measure_P.Bias_Bias_it;

  /* Sum: '<S94>/Sum1' incorporates:
   *  Gain: '<S95>/Gain'
   *  Gain: '<S95>/Gain1'
   *  Inport: '<Root>/Vabc (pu)'
   *  Math: '<S94>/Math Function'
   *  Product: '<S94>/Product'
   *  Product: '<S94>/Product1'
   *  Sum: '<S95>/Sum1'
   *  Sum: '<S95>/Sum2'
   *  Sum: '<S95>/Sum7'
   *  UnitDelay: '<S86>/Unit Delay1'
   *  UnitDelay: '<S86>/Unit Delay2'
   */
  rtb_UnaryMinus_p = ((measure_U.Vabcpu[2] - measure_DWork.UnitDelay2_DSTATE_a) *
                      measure_P.Gain_Gain_j * rtb_UnaryMinus_p +
                      measure_DWork.UnitDelay1_DSTATE_i) +
    ((measure_DWork.UnitDelay2_DSTATE_a + measure_U.Vabcpu[2]) *
     measure_P.Gain1_Gain_a - measure_DWork.UnitDelay1_DSTATE_i) *
    (rtb_UnaryMinus_p * rtb_UnaryMinus_p);

  /* UnitDelay: '<S84>/Unit Delay1' */
  rtb_UnitDelay1_i = measure_DWork.UnitDelay1_DSTATE_b;

  /* Bias: '<S84>/Bias' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Gain: '<S84>/Gain'
   *  MinMax: '<S1>/MinMax'
   *  Sum: '<S1>/Add1'
   */
  rtb_Divide_jahfx = (rtb_Gain_m - measure_P.Constant7_Value[0]) *
    measure_P.Gain_Gain_b + measure_P.Bias_Bias_pv;

  /* Sum: '<S90>/Sum1' incorporates:
   *  Gain: '<S91>/Gain'
   *  Gain: '<S91>/Gain1'
   *  Inport: '<Root>/Vabc (pu)'
   *  Math: '<S90>/Math Function'
   *  Product: '<S90>/Product'
   *  Product: '<S90>/Product1'
   *  Sum: '<S91>/Sum1'
   *  Sum: '<S91>/Sum2'
   *  Sum: '<S91>/Sum7'
   *  UnitDelay: '<S84>/Unit Delay1'
   *  UnitDelay: '<S84>/Unit Delay2'
   */
  rtb_Divide_jahfx = ((measure_U.Vabcpu[0] - measure_DWork.UnitDelay2_DSTATE_c) *
                      measure_P.Gain_Gain_ew * rtb_Divide_jahfx +
                      measure_DWork.UnitDelay1_DSTATE_b) +
    ((measure_DWork.UnitDelay2_DSTATE_c + measure_U.Vabcpu[0]) *
     measure_P.Gain1_Gain_dy - measure_DWork.UnitDelay1_DSTATE_b) *
    (rtb_Divide_jahfx * rtb_Divide_jahfx);

  /* Trigonometry: '<S354>/Trigonometric Function' incorporates:
   *  Gain: '<S352>/Gain'
   *  Gain: '<S352>/Gain1'
   *  Gain: '<S352>/Gain2'
   *  Sum: '<S352>/Add'
   *  Sum: '<S352>/Add1'
   *  Sum: '<S352>/Add2'
   */
  rtb_TrigonometricFunction = atan2((rtb_Switch_b2 - rtb_UnaryMinus_p) *
    measure_P.Gain2_Gain, (measure_P.Gain_Gain_n * rtb_Divide_jahfx -
    (rtb_Switch_b2 + rtb_UnaryMinus_p)) * measure_P.Gain1_Gain_n);

  /* Sum: '<S348>/Sum2' incorporates:
   *  UnitDelay: '<S348>/Unit Delay3'
   */
  rtb_Sum2_g = rtb_TrigonometricFunction - measure_DWork.UnitDelay3_DSTATE;

  /* Switch: '<S355>/Switch1' incorporates:
   *  Bias: '<S355>/Bias1'
   *  Constant: '<S356>/Constant'
   *  Constant: '<S357>/Constant'
   *  RelationalOperator: '<S356>/Compare'
   *  RelationalOperator: '<S357>/Compare'
   *  Switch: '<S355>/Switch'
   */
  if (rtb_Sum2_g < measure_P.Constant_Value_ne) {
    rtb_Sum2_g += measure_P.Bias1_Bias_n;
  } else {
    if (rtb_Sum2_g > measure_P.Constant_Value_n) {
      /* Switch: '<S355>/Switch' incorporates:
       *  Bias: '<S355>/Bias'
       */
      rtb_Sum2_g += measure_P.Bias_Bias_n;
    }
  }

  /* End of Switch: '<S355>/Switch1' */

  /* Gain: '<S348>/Gain' */
  measure_B.Gain = measure_P.Gain_Gain_ne * rtb_Sum2_g;

  /* Switch: '<S361>/Switch' incorporates:
   *  Constant: '<S361>/double'
   *  Logic: '<S464>/Logical Operator1'
   *  Logic: '<S464>/Logical Operator2'
   *  Sum: '<S361>/Sum2'
   *  UnitDelay: '<S361>/Unit Delay2'
   *  UnitDelay: '<S361>/Unit Delay4'
   *  UnitDelay: '<S464>/delay1'
   */
  if ((!rtb_Compare_f) && measure_DWork.delay1_DSTATE_l) {
    measure_B.Switch = measure_P.double_Value_ne;
  } else {
    measure_B.Switch = (measure_B.Gain + measure_DWork.UnitDelay4_DSTATE) +
      measure_DWork.UnitDelay2_DSTATE_l;
  }

  /* End of Switch: '<S361>/Switch' */

  /* Math: '<S309>/Math Function1' incorporates:
   *  UnitDelay: '<S309>/Unit Delay'
   *
   * About '<S309>/Math Function1':
   *  Operator: reciprocal
   */
  rtb_MathFunction1 = 1.0 / measure_DWork.UnitDelay_DSTATE_e;

  /* Switch: '<S461>/Switch' incorporates:
   *  Constant: '<S461>/Constant'
   *  Constant: '<S467>/Constant'
   *  Constant: '<S468>/Constant'
   *  RelationalOperator: '<S467>/Compare'
   *  RelationalOperator: '<S468>/Compare'
   *  Switch: '<S461>/Switch1'
   */
  if (rtb_MathFunction1 < measure_P.Constant_Value_hpxmkfi) {
    rtb_Switch = measure_P.Constant_Value_hp;
  } else if (rtb_MathFunction1 > measure_P.Constant_Value_h) {
    /* Switch: '<S461>/Switch1' incorporates:
     *  Constant: '<S461>/Constant1'
     */
    rtb_Switch = measure_P.Constant1_Value_h;
  } else {
    rtb_Switch = rtb_MathFunction1;
  }

  /* End of Switch: '<S461>/Switch' */

  /* Gain: '<S462>/Gain' */
  rtb_Gain_m = measure_P.Gain_Gain_hp * rtb_Switch;

  /* Switch: '<S469>/Switch2' incorporates:
   *  Bias: '<S469>/Bias1'
   *  Constant: '<S472>/Constant'
   *  RelationalOperator: '<S472>/Compare'
   *  Switch: '<S469>/Switch1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2 = rtb_Gain_m + measure_P.Bias1_Bias_h;
  } else if (rtb_Gain_m < measure_P.Constant_Value_hpxmkfin) {
    /* Switch: '<S469>/Switch1' */
    measure_B.Switch2 = rtb_Gain_m;
  } else {
    /* Switch: '<S469>/Switch1' incorporates:
     *  Bias: '<S469>/Bias'
     */
    measure_B.Switch2 = rtb_Gain_m + measure_P.Bias_Bias_h;
  }

  /* End of Switch: '<S469>/Switch2' */
  /* S-Function "SF_Cast_double_to_int32" Block: <S469>/S-Function */
  {
    measure_B.SFunction = (int)measure_B.Switch2;
  }

  /* Switch: '<S470>/Switch2' incorporates:
   *  Constant: '<S470>/Constant'
   *  Constant: '<S473>/Constant'
   *  Constant: '<S474>/Constant'
   *  RelationalOperator: '<S473>/Compare'
   *  RelationalOperator: '<S474>/Compare'
   *  Switch: '<S470>/Switch3'
   */
  if (measure_B.SFunction < measure_P.Constant_Value_hpxmkfinoyshikv) {
    measure_B.Switch2_lr = measure_P.Constant_Value_hpxmkfinoysh;
  } else if (measure_B.SFunction > measure_P.Constant_Value_hpxmkfinoys) {
    /* Switch: '<S470>/Switch3' incorporates:
     *  Constant: '<S470>/Constant3'
     */
    measure_B.Switch2_lr = measure_P.Constant3_Value_h;
  } else {
    measure_B.Switch2_lr = measure_B.SFunction;
  }

  /* End of Switch: '<S470>/Switch2' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S358>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneTap[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_pz;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch;

    /*    Offset = measure_B.Switch2_lr;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOneTap) Offset = measure_P.VariableDiscreteDelaywithOneTap;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_lr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTap;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTap = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTap)
      *VDD_in = 0;
  }

  /* Switch: '<S362>/Switch' incorporates:
   *  Constant: '<S362>/double'
   *  Logic: '<S463>/Logical Operator'
   *  Logic: '<S463>/Logical Operator1'
   *  Sum: '<S362>/Sum2'
   *  UnitDelay: '<S362>/Unit Delay2'
   *  UnitDelay: '<S362>/Unit Delay4'
   *  UnitDelay: '<S463>/delay'
   */
  if (rtb_Compare_f && (!measure_DWork.delay_DSTATE_i)) {
    measure_B.Switch_j = measure_P.double_Value_nes;
  } else {
    measure_B.Switch_j = (measure_B.Gain + measure_DWork.UnitDelay4_DSTATE_k) +
      measure_DWork.UnitDelay2_DSTATE_ls;
  }

  /* End of Switch: '<S362>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S359>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_i[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_pzv;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_j;

    /*    Offset = measure_B.Switch2_lr;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOneT_n) Offset = measure_P.VariableDiscreteDelaywithOneT_n;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_lr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_n;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_n = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_n)
      *VDD_in = 0;
  }

  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S363>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoTap[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_m;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Gain;

    /*    Offset = measure_B.Switch2_lr;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwoTap) Offset = measure_P.VariableDiscreteDelaywithTwoTap;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_lr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTap;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTap = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTap)
      measure_B.VariableDiscreteDelaywithTwoT_g = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoT_g = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTap)
      *VDD_in = 0;
  }

  /* Switch: '<S313>/Switch2' */
  if (rtb_LogicalOperator1_f) {
    measure_B.Switch2_p = rtb_Switch1_k;
  } else {
    /* Sum: '<S462>/Subtract1' incorporates:
     *  DataTypeConversion: '<S471>/Data Type Conversion'
     */
    rtb_Gain_m = (real_T)measure_B.Switch2_lr - rtb_Gain_m;

    /* Math: '<S462>/Math Function' */
    rtb_Switch1_kt5c = rtb_Gain_m * rtb_Gain_m;

    /* Sum: '<S360>/Sum1' incorporates:
     *  Gain: '<S462>/Gain1'
     *  Product: '<S360>/Product'
     *  Product: '<S360>/Product1'
     *  Sum: '<S462>/Subtract3'
     */
    rtb_Gain_m = (measure_P.Gain1_Gain * rtb_Gain_m - rtb_Switch1_kt5c) *
      measure_B.VariableDiscreteDelaywithTwoTap +
      measure_B.VariableDiscreteDelaywithTwoT_g * rtb_Switch1_kt5c;

    /* Switch: '<S349>/Switch1' incorporates:
     *  Sum: '<S349>/Sum1'
     *  Sum: '<S349>/Sum2'
     */
    if (rtb_Compare_f) {
      rtb_Switch1_kt5c = measure_B.Switch -
        measure_B.VariableDiscreteDelaywithOneTap;
    } else {
      rtb_Switch1_kt5c = measure_B.Switch_j -
        measure_B.VariableDiscreteDelaywithOneT_n;
    }

    /* End of Switch: '<S349>/Switch1' */

    /* Product: '<S360>/Divide' incorporates:
     *  Gain: '<S317>/Gain'
     *  Math: '<S317>/Math Function'
     *  Sum: '<S360>/Sum7'
     *
     * About '<S317>/Math Function':
     *  Operator: reciprocal
     */
    rtb_Gain_m = 1.0 / rtb_Switch * measure_P.Gain_Gain * (rtb_Switch1_kt5c -
      rtb_Gain_m);

    /* Switch: '<S353>/Switch' incorporates:
     *  Constant: '<S376>/Constant'
     *  RelationalOperator: '<S376>/Compare'
     *  UnaryMinus: '<S353>/Unary Minus'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_nes) {
      measure_B.Switch2_p = -rtb_Gain_m;
    } else {
      measure_B.Switch2_p = rtb_Gain_m;
    }

    /* End of Switch: '<S353>/Switch' */
  }

  /* End of Switch: '<S313>/Switch2' */

  /* Switch: '<S367>/Switch' incorporates:
   *  Constant: '<S367>/double'
   *  Sum: '<S367>/Sum2'
   *  UnitDelay: '<S367>/Unit Delay2'
   *  UnitDelay: '<S367>/Unit Delay4'
   */
  if (rtb_Compare_c2o) {
    measure_B.Switch_jc = measure_P.double_Value_nesm;
  } else {
    measure_B.Switch_jc = (measure_B.Switch2_p +
      measure_DWork.UnitDelay4_DSTATE_kr) + measure_DWork.UnitDelay2_DSTATE_lsc;
  }

  /* End of Switch: '<S367>/Switch' */

  /* Gain: '<S309>/Gain' */
  rtb_Gain_m = measure_P.Gain_Gain_ni * rtb_MathFunction1;

  /* Switch: '<S476>/Switch' incorporates:
   *  Constant: '<S476>/Constant'
   *  Constant: '<S482>/Constant'
   *  Constant: '<S483>/Constant'
   *  RelationalOperator: '<S482>/Compare'
   *  RelationalOperator: '<S483>/Compare'
   *  Switch: '<S476>/Switch1'
   */
  if (rtb_Gain_m < measure_P.Constant_Value_hpxmkfino) {
    rtb_Sum2_g = measure_P.Constant_Value_hpxm;
  } else if (rtb_Gain_m > measure_P.Constant_Value_hpx) {
    /* Switch: '<S476>/Switch1' incorporates:
     *  Constant: '<S476>/Constant1'
     */
    rtb_Sum2_g = measure_P.Constant1_Value_hp;
  } else {
    rtb_Sum2_g = rtb_Gain_m;
  }

  /* End of Switch: '<S476>/Switch' */

  /* Gain: '<S477>/Gain' */
  rtb_Gain_m = measure_P.Gain_Gain_hpx * rtb_Sum2_g;

  /* Switch: '<S484>/Switch2' incorporates:
   *  Bias: '<S484>/Bias1'
   *  Constant: '<S487>/Constant'
   *  RelationalOperator: '<S487>/Compare'
   *  Switch: '<S484>/Switch1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_l = rtb_Gain_m + measure_P.Bias1_Bias_hp;
  } else if (rtb_Gain_m < measure_P.Constant_Value_hpxmkfinoy) {
    /* Switch: '<S484>/Switch1' */
    measure_B.Switch2_l = rtb_Gain_m;
  } else {
    /* Switch: '<S484>/Switch1' incorporates:
     *  Bias: '<S484>/Bias'
     */
    measure_B.Switch2_l = rtb_Gain_m + measure_P.Bias_Bias_hp;
  }

  /* End of Switch: '<S484>/Switch2' */
  /* S-Function "SF_Cast_double_to_int32" Block: <S484>/S-Function */
  {
    measure_B.SFunction_i = (int)measure_B.Switch2_l;
  }

  /* Switch: '<S485>/Switch2' incorporates:
   *  Constant: '<S485>/Constant'
   *  Constant: '<S488>/Constant'
   *  Constant: '<S489>/Constant'
   *  RelationalOperator: '<S488>/Compare'
   *  RelationalOperator: '<S489>/Compare'
   *  Switch: '<S485>/Switch3'
   */
  if (measure_B.SFunction_i < measure_P.Constant_Value_n5) {
    measure_B.Switch2_lrp = measure_P.Constant_Value_hpxmkfinoyshik;
  } else if (measure_B.SFunction_i > measure_P.Constant_Value_hpxmkfinoyshi) {
    /* Switch: '<S485>/Switch3' incorporates:
     *  Constant: '<S485>/Constant3'
     */
    measure_B.Switch2_lrp = measure_P.Constant3_Value_hp;
  } else {
    measure_B.Switch2_lrp = measure_B.SFunction_i;
  }

  /* End of Switch: '<S485>/Switch2' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S364>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_iq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_pzv4;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_jc;

    /*    Offset = measure_B.Switch2_lrp;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOne_ne) Offset = measure_P.VariableDiscreteDelaywithOne_ne;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_ne;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_nd = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_ne)
      *VDD_in = 0;
  }

  /* Logic: '<S478>/Logical Operator' incorporates:
   *  Logic: '<S478>/Logical Operator1'
   *  UnitDelay: '<S478>/delay'
   */
  rtb_Compare_c2os = (rtb_Compare && (!measure_DWork.delay_DSTATE_i2));

  /* Switch: '<S368>/Switch' incorporates:
   *  Constant: '<S368>/double'
   *  Sum: '<S368>/Sum2'
   *  UnitDelay: '<S368>/Unit Delay2'
   *  UnitDelay: '<S368>/Unit Delay4'
   */
  if (rtb_Compare_c2os) {
    measure_B.Switch_jc4 = measure_P.double_Value_nesmw;
  } else {
    measure_B.Switch_jc4 = (measure_B.Switch2_p +
      measure_DWork.UnitDelay4_DSTATE_krx) +
      measure_DWork.UnitDelay2_DSTATE_lscn;
  }

  /* End of Switch: '<S368>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S365>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_iqv[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_pzv45;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_jc4;

    /*    Offset = measure_B.Switch2_lrp;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOn_nes) Offset = measure_P.VariableDiscreteDelaywithOn_nes;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_nes;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_ndl = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_nes)
      *VDD_in = 0;
  }

  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S369>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_b[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_mw;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch2_p;

    /*    Offset = measure_B.Switch2_lrp;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwoT_n) Offset = measure_P.VariableDiscreteDelaywithTwoT_n;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_n;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoT_h = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_n)
      measure_B.VariableDiscreteDelaywithTwo_gt = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwo_gt = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_n)
      *VDD_in = 0;
  }

  /* Sum: '<S477>/Subtract1' incorporates:
   *  DataTypeConversion: '<S486>/Data Type Conversion'
   */
  rtb_Tps2dt_m = (real_T)measure_B.Switch2_lrp - rtb_Gain_m;

  /* Math: '<S477>/Math Function' */
  rtb_Switch1_kt5c = rtb_Tps2dt_m * rtb_Tps2dt_m;

  /* Sum: '<S477>/Subtract3' incorporates:
   *  Gain: '<S477>/Gain1'
   */
  rtb_Switch = measure_P.Gain1_Gain_h * rtb_Tps2dt_m - rtb_Switch1_kt5c;

  /* Gain: '<S318>/Gain' incorporates:
   *  Math: '<S318>/Math Function'
   *
   * About '<S318>/Math Function':
   *  Operator: reciprocal
   */
  rtb_MathFunction1 = 1.0 / rtb_Sum2_g * measure_P.Gain_Gain_hpxm;

  /* Switch: '<S313>/Switch4' incorporates:
   *  Product: '<S366>/Divide'
   *  Product: '<S366>/Product'
   *  Product: '<S366>/Product1'
   *  Sum: '<S366>/Sum1'
   *  Sum: '<S366>/Sum7'
   *  Switch: '<S350>/Switch1'
   */
  if (rtb_LogicalOperator1_f) {
    measure_B.Switch4 = rtb_Switch1_k;
  } else {
    if (rtb_Compare) {
      /* Switch: '<S350>/Switch1' incorporates:
       *  Sum: '<S350>/Sum2'
       */
      rtb_Gain_m = measure_B.Switch_jc -
        measure_B.VariableDiscreteDelaywithOne_nd;
    } else {
      /* Switch: '<S350>/Switch1' incorporates:
       *  Sum: '<S350>/Sum1'
       */
      rtb_Gain_m = measure_B.Switch_jc4 -
        measure_B.VariableDiscreteDelaywithOn_ndl;
    }

    measure_B.Switch4 = (rtb_Gain_m - (measure_B.VariableDiscreteDelaywithTwoT_h
      * rtb_Switch + measure_B.VariableDiscreteDelaywithTwo_gt *
      rtb_Switch1_kt5c)) * rtb_MathFunction1;
  }

  /* End of Switch: '<S313>/Switch4' */

  /* Switch: '<S373>/Switch' incorporates:
   *  Constant: '<S373>/double'
   *  Sum: '<S373>/Sum2'
   *  UnitDelay: '<S373>/Unit Delay2'
   *  UnitDelay: '<S373>/Unit Delay4'
   */
  if (rtb_Compare_c2o) {
    measure_B.Switch_jc4w = measure_P.double_Value_nesmwp;
  } else {
    measure_B.Switch_jc4w = (measure_B.Switch4 +
      measure_DWork.UnitDelay4_DSTATE_krxz) +
      measure_DWork.UnitDelay2_DSTATE_lscnp;
  }

  /* End of Switch: '<S373>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S370>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_iqvv[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_pzv45h;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_jc4w;

    /*    Offset = measure_B.Switch2_lrp;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithO_nesm) Offset = measure_P.VariableDiscreteDelaywithO_nesm;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_nesm;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithO_ndlj = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_nesm)
      *VDD_in = 0;
  }

  /* Switch: '<S374>/Switch' incorporates:
   *  Constant: '<S374>/double'
   *  Sum: '<S374>/Sum2'
   *  UnitDelay: '<S374>/Unit Delay2'
   *  UnitDelay: '<S374>/Unit Delay4'
   */
  if (rtb_Compare_c2os) {
    measure_B.Switch_jc4wm = measure_P.double_Value_nesmwp2;
  } else {
    measure_B.Switch_jc4wm = (measure_B.Switch4 +
      measure_DWork.UnitDelay4_DSTATE_krxzy) +
      measure_DWork.UnitDelay2_DSTATE_lscnp0;
  }

  /* End of Switch: '<S374>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S371>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_iqvvo[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_pzv45hn;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_jc4wm;

    /*    Offset = measure_B.Switch2_lrp;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywith_nesmw) Offset = measure_P.VariableDiscreteDelaywith_nesmw;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_nesmw;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywith_ndljw = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_nesmw)
      *VDD_in = 0;
  }

  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S375>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_bq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_mw3;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch4;

    /*    Offset = measure_B.Switch2_lrp;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwo_ne) Offset = measure_P.VariableDiscreteDelaywithTwo_ne;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_ne;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwo_h0 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_ne)
      measure_B.VariableDiscreteDelaywithTw_gtq = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTw_gtq = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_ne)
      *VDD_in = 0;
  }

  /* Gain: '<S311>/Gain1' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  rtb_Tps2dt_m = measure_P.Gain1_Gain_f * measure_P.Constant5_Value;

  /* Bias: '<S311>/Bias' */
  rtb_Sum2_g = rtb_Tps2dt_m + measure_P.Bias_Bias_fk;

  /* Switch: '<S323>/Switch' incorporates:
   *  Constant: '<S323>/Constant'
   *  Constant: '<S330>/Constant'
   *  RelationalOperator: '<S330>/Compare'
   */
  if (rtb_Sum2_g > measure_P.Constant_Value_fk) {
    rtb_Sum2_g = measure_P.Constant_Value_f;
  }

  /* End of Switch: '<S323>/Switch' */

  /* Logic: '<S311>/Logical Operator1' incorporates:
   *  Logic: '<S311>/Logical Operator2'
   *  RelationalOperator: '<S311>/Check for gross measurement noise'
   *  RelationalOperator: '<S311>/Check for gross measurement noise1'
   *  UnaryMinus: '<S311>/Unary Minus'
   */
  rtb_Compare_c2os = (((measure_B.Gain < rtb_Sum2_g) && (measure_B.Gain >
    -rtb_Tps2dt_m)) || rtb_UnitDelay4_ej);

  /* Switch: '<S322>/Switch' incorporates:
   *  Constant: '<S322>/const'
   *  UnitDelay: '<S322>/Unit Delay1'
   */
  if (rtb_Compare_c2os) {
    rtb_Switch1_bxh = measure_DWork.UnitDelay1_DSTATE_omtd1hdp;
  } else {
    rtb_Switch1_bxh = measure_P.const_Value_fk;
  }

  /* End of Switch: '<S322>/Switch' */

  /* RelationalOperator: '<S328>/Compare' incorporates:
   *  Constant: '<S328>/Constant'
   */
  rtb_Compare_c2 = (rtb_Switch1_bxh == measure_P.Constant_Value_fkx);

  /* Switch: '<S321>/Switch' incorporates:
   *  Constant: '<S321>/const'
   *  UnitDelay: '<S321>/Unit Delay1'
   */
  if (rtb_Compare_c2os) {
    rtb_UnitDelay1_pf = measure_DWork.UnitDelay1_DSTATE_omtd1hdpu;
  } else {
    rtb_UnitDelay1_pf = measure_P.const_Value_f;
  }

  /* End of Switch: '<S321>/Switch' */

  /* RelationalOperator: '<S326>/Compare' incorporates:
   *  Constant: '<S326>/Constant'
   */
  rtb_Compare_c2o = (rtb_UnitDelay1_pf == measure_P.Constant_Value_fkxn);

  /* Switch: '<S309>/Switch2' */
  if (rtb_Compare_c2o) {
    /* Switch: '<S309>/Switch3' */
    if (rtb_Compare_c2) {
      /* Switch: '<S313>/Switch3' incorporates:
       *  Product: '<S372>/Divide'
       *  Product: '<S372>/Product'
       *  Product: '<S372>/Product1'
       *  Sum: '<S372>/Sum1'
       *  Sum: '<S372>/Sum7'
       */
      if (!rtb_LogicalOperator1_f) {
        /* Switch: '<S351>/Switch1' incorporates:
         *  Sum: '<S351>/Sum1'
         *  Sum: '<S351>/Sum2'
         */
        if (rtb_Compare) {
          rtb_Gain_m = measure_B.Switch_jc4w -
            measure_B.VariableDiscreteDelaywithO_ndlj;
        } else {
          rtb_Gain_m = measure_B.Switch_jc4wm -
            measure_B.VariableDiscreteDelaywith_ndljw;
        }

        /* End of Switch: '<S351>/Switch1' */
        rtb_Switch1_k = (rtb_Gain_m - (measure_B.VariableDiscreteDelaywithTwo_h0
          * rtb_Switch + measure_B.VariableDiscreteDelaywithTw_gtq *
          rtb_Switch1_kt5c)) * rtb_MathFunction1;
      }

      /* End of Switch: '<S313>/Switch3' */
    } else {
      rtb_Switch1_k = measure_B.Switch4;
    }

    /* End of Switch: '<S309>/Switch3' */
    measure_B.Switch2_c = rtb_Switch1_k;
  } else {
    measure_B.Switch2_c = measure_B.Switch2_p;
  }

  /* End of Switch: '<S309>/Switch2' */

  /* DiscretePulseGenerator: '<S419>/Pulse Generator1' */
  rtb_Tps2dt_m = ((real_T)measure_DWork.clockTickCounter_n <
                  measure_P.PulseGenerator1_Duty_e) &&
    (measure_DWork.clockTickCounter_n >= 0) ? measure_P.PulseGenerator1_Amp_e :
    0.0;
  if ((real_T)measure_DWork.clockTickCounter_n >=
      measure_P.PulseGenerator1_Period_e - 1.0) {
    measure_DWork.clockTickCounter_n = 0;
  } else {
    measure_DWork.clockTickCounter_n = measure_DWork.clockTickCounter_n + 1;
  }

  /* End of DiscretePulseGenerator: '<S419>/Pulse Generator1' */

  /* RelationalOperator: '<S425>/Compare' incorporates:
   *  Constant: '<S425>/Constant'
   */
  rtb_Compare_d = (rtb_Tps2dt_m > measure_P.Constant_Value_li);

  /* Logic: '<S423>/Logical Operator1' incorporates:
   *  Logic: '<S423>/Logical Operator2'
   *  UnitDelay: '<S423>/delay1'
   */
  rtb_LogicalOperator1_drl4 = ((!rtb_Compare_d) && measure_DWork.delay1_DSTATE_f);

  /* Switch: '<S394>/Switch' incorporates:
   *  Constant: '<S394>/double'
   *  Sum: '<S394>/Sum2'
   *  UnitDelay: '<S394>/Unit Delay2'
   *  UnitDelay: '<S394>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_drl4) {
    measure_B.Switch_i = measure_P.double_Value_e;
  } else {
    measure_B.Switch_i = (measure_B.Switch2_c +
                          measure_DWork.UnitDelay4_DSTATE_krxzyr) +
      measure_DWork.UnitDelay2_DSTATE_lscnp0r;
  }

  /* End of Switch: '<S394>/Switch' */

  /* Switch: '<S420>/Switch' incorporates:
   *  Constant: '<S420>/Constant'
   *  Constant: '<S426>/Constant'
   *  Constant: '<S427>/Constant'
   *  RelationalOperator: '<S426>/Compare'
   *  RelationalOperator: '<S427>/Compare'
   *  Switch: '<S420>/Switch1'
   *  UnitDelay: '<S315>/Unit Delay2'
   */
  if (measure_DWork.UnitDelay2_DSTATE_lscnp0r3 < measure_P.Constant_Value_a2) {
    rtb_Tps2dt_m = measure_P.Constant_Value_epwu2gd3xoydf;
  } else if (measure_DWork.UnitDelay2_DSTATE_lscnp0r3 >
             measure_P.Constant_Value_epwu2gd3xoyd) {
    /* Switch: '<S420>/Switch1' incorporates:
     *  Constant: '<S420>/Constant1'
     */
    rtb_Tps2dt_m = measure_P.Constant1_Value_epwu;
  } else {
    rtb_Tps2dt_m = measure_DWork.UnitDelay2_DSTATE_lscnp0r3;
  }

  /* End of Switch: '<S420>/Switch' */

  /* Gain: '<S421>/Gain' */
  rtb_Gain_m = measure_P.Gain_Gain_ep * rtb_Tps2dt_m;

  /* Switch: '<S428>/Switch2' incorporates:
   *  Bias: '<S428>/Bias1'
   *  Constant: '<S431>/Constant'
   *  RelationalOperator: '<S431>/Compare'
   *  Switch: '<S428>/Switch1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_a = rtb_Gain_m + measure_P.Bias1_Bias_ep;
  } else if (rtb_Gain_m < measure_P.Constant_Value_pz) {
    /* Switch: '<S428>/Switch1' */
    measure_B.Switch2_a = rtb_Gain_m;
  } else {
    /* Switch: '<S428>/Switch1' incorporates:
     *  Bias: '<S428>/Bias'
     */
    measure_B.Switch2_a = rtb_Gain_m + measure_P.Bias_Bias_ep;
  }

  /* End of Switch: '<S428>/Switch2' */
  /* S-Function "SF_Cast_double_to_int32" Block: <S428>/S-Function */
  {
    measure_B.SFunction_m = (int)measure_B.Switch2_a;
  }

  /* Switch: '<S429>/Switch2' incorporates:
   *  Constant: '<S429>/Constant'
   *  Constant: '<S432>/Constant'
   *  Constant: '<S433>/Constant'
   *  RelationalOperator: '<S432>/Compare'
   *  RelationalOperator: '<S433>/Compare'
   *  Switch: '<S429>/Switch3'
   */
  if (measure_B.SFunction_m < measure_P.Constant_Value_ds) {
    measure_B.Switch2_a4fq3 = measure_P.Constant_Value_h1;
  } else if (measure_B.SFunction_m > measure_P.Constant_Value_ng) {
    /* Switch: '<S429>/Switch3' incorporates:
     *  Constant: '<S429>/Constant3'
     */
    measure_B.Switch2_a4fq3 = measure_P.Constant3_Value_e;
  } else {
    measure_B.Switch2_a4fq3 = measure_B.SFunction_m;
  }

  /* End of Switch: '<S429>/Switch2' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S391>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_iqvvod[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_pzv45hn0;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_i;

    /*    Offset = measure_B.Switch2_a4fq3;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOneT_e) Offset = measure_P.VariableDiscreteDelaywithOneT_e;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_e;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywit_ndljwv = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_e)
      *VDD_in = 0;
  }

  /* Logic: '<S422>/Logical Operator' incorporates:
   *  Logic: '<S422>/Logical Operator1'
   *  UnitDelay: '<S422>/delay'
   */
  rtb_LogicalOperator_aiui = (rtb_Compare_d && (!measure_DWork.delay_DSTATE_n));

  /* Switch: '<S395>/Switch' incorporates:
   *  Constant: '<S395>/double'
   *  Sum: '<S395>/Sum2'
   *  UnitDelay: '<S395>/Unit Delay2'
   *  UnitDelay: '<S395>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aiui) {
    measure_B.Switch_iw = measure_P.double_Value_ep;
  } else {
    measure_B.Switch_iw = (measure_B.Switch2_c +
      measure_DWork.UnitDelay4_DSTATE_krxzyrk) +
      measure_DWork.UnitDelay2_DSTATE_lscnp0r3j;
  }

  /* End of Switch: '<S395>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S392>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_iqvvods[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_pzv45hn0c;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_iw;

    /*    Offset = measure_B.Switch2_a4fq3;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOne_ep) Offset = measure_P.VariableDiscreteDelaywithOne_ep;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_ep;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywi_ndljwvw = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_ep)
      *VDD_in = 0;
  }

  /* Switch: '<S379>/Switch1' incorporates:
   *  Sum: '<S379>/Sum1'
   *  Sum: '<S379>/Sum2'
   */
  if (rtb_Compare_d) {
    rtb_Sum2_g = measure_B.Switch_i - measure_B.VariableDiscreteDelaywit_ndljwv;
  } else {
    rtb_Sum2_g = measure_B.Switch_iw - measure_B.VariableDiscreteDelaywi_ndljwvw;
  }

  /* End of Switch: '<S379>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S396>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_bqv[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_mw3l;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch2_c;

    /*    Offset = measure_B.Switch2_a4fq3;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwoT_e) Offset = measure_P.VariableDiscreteDelaywithTwoT_e;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_e;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTw_h0q = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_e)
      measure_B.VariableDiscreteDelaywithT_gtqs = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithT_gtqs = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_e)
      *VDD_in = 0;
  }

  /* Sum: '<S421>/Subtract1' incorporates:
   *  DataTypeConversion: '<S430>/Data Type Conversion'
   */
  rtb_Subtract3_o = (real_T)measure_B.Switch2_a4fq3 - rtb_Gain_m;

  /* Math: '<S421>/Math Function' */
  rtb_MathFunction_bdy = rtb_Subtract3_o * rtb_Subtract3_o;

  /* Sum: '<S421>/Subtract3' incorporates:
   *  Gain: '<S421>/Gain1'
   */
  rtb_Subtract3_o = measure_P.Gain1_Gain_e * rtb_Subtract3_o -
    rtb_MathFunction_bdy;

  /* Gain: '<S387>/Gain' incorporates:
   *  Math: '<S387>/Math Function'
   *
   * About '<S387>/Math Function':
   *  Operator: reciprocal
   */
  rtb_Tps2dt_m = 1.0 / rtb_Tps2dt_m * measure_P.Gain_Gain_epw;

  /* Product: '<S393>/Divide' incorporates:
   *  Product: '<S393>/Product'
   *  Product: '<S393>/Product1'
   *  Sum: '<S393>/Sum1'
   *  Sum: '<S393>/Sum7'
   */
  rtb_Sum2_g = (rtb_Sum2_g - (measure_B.VariableDiscreteDelaywithTw_h0q *
    rtb_Subtract3_o + measure_B.VariableDiscreteDelaywithT_gtqs *
    rtb_MathFunction_bdy)) * rtb_Tps2dt_m;

  /* Sum: '<S315>/Add' */
  measure_B.ACripple1stestimate = measure_B.Switch2_c - rtb_Sum2_g;

  /* Switch: '<S389>/Switch' incorporates:
   *  Constant: '<S456>/Constant'
   *  RelationalOperator: '<S456>/Compare'
   *  UnaryMinus: '<S389>/Unary Minus'
   */
  if (measure_B.ACripple1stestimate < measure_P.Constant_Value_ed) {
    rtb_UnaryMinus_a2 = -measure_B.ACripple1stestimate;
  } else {
    rtb_UnaryMinus_a2 = measure_B.ACripple1stestimate;
  }

  /* End of Switch: '<S389>/Switch' */

  /* Switch: '<S413>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S413>/int32'
   *  Constant: '<S415>/FixPt Constant'
   *  Gain: '<S309>/Gain1'
   *  RelationalOperator: '<S315>/Relational Operator1'
   *  Sum: '<S415>/FixPt Sum1'
   *  UnitDelay: '<S413>/Unit Delay'
   */
  if (rtb_UnaryMinus_a2 > measure_P.Gain1_Gain_n5 * measure_P.Constant2_Value_h)
  {
    rtb_UnitDelay1_nt = measure_P.int32_Value;
  } else {
    rtb_UnitDelay1_nt = measure_DWork.UnitDelay_DSTATE_ehb -
      measure_P.FixPtConstant_Value_e;
  }

  /* End of Switch: '<S413>/Switch' */

  /* RelationalOperator: '<S414>/Compare' incorporates:
   *  Constant: '<S414>/Constant'
   */
  rtb_Compare_no = (rtb_UnitDelay1_nt > measure_P.Constant_Value_e3);

  /* Switch: '<S315>/Switch2' */
  if (rtb_Compare_no) {
    measure_B.Switch2_a4 = measure_B.Switch2_c;
  } else {
    measure_B.Switch2_a4 = rtb_Sum2_g;
  }

  /* End of Switch: '<S315>/Switch2' */

  /* Switch: '<S316>/Switch' */
  if (rtb_UnitDelay4_ej) {
    rtb_Gain_m = rtb_Switch1_b;
  } else {
    rtb_Gain_m = measure_B.Switch2_a4;
  }

  /* End of Switch: '<S316>/Switch' */

  /* Switch: '<S314>/Switch' incorporates:
   *  Constant: '<S314>/Constant'
   *  Constant: '<S377>/Constant'
   *  Constant: '<S378>/Constant'
   *  RelationalOperator: '<S377>/Compare'
   *  RelationalOperator: '<S378>/Compare'
   *  Switch: '<S314>/Switch1'
   */
  if (rtb_Gain_m < measure_P.Constant_Value_aw) {
    rtb_Switch_j = measure_P.Constant_Value_m;
  } else if (rtb_Gain_m > measure_P.Constant_Value_a) {
    /* Switch: '<S314>/Switch1' incorporates:
     *  Constant: '<S314>/Constant1'
     */
    rtb_Switch_j = measure_P.Constant1_Value_m;
  } else {
    rtb_Switch_j = rtb_Gain_m;
  }

  /* End of Switch: '<S314>/Switch' */

  /* Switch: '<S320>/Switch' incorporates:
   *  Constant: '<S320>/const'
   *  UnitDelay: '<S320>/Unit Delay1'
   */
  if (rtb_Compare_c2os) {
    rtb_Switch1_c1 = measure_DWork.UnitDelay1_DSTATE_omtd1hdput;
  } else {
    rtb_Switch1_c1 = measure_P.const_Value;
  }

  /* End of Switch: '<S320>/Switch' */

  /* RelationalOperator: '<S324>/Compare' incorporates:
   *  Constant: '<S324>/Constant'
   */
  rtb_Compare_c2os = (rtb_Switch1_c1 == measure_P.Constant_Value_fkxna);

  /* Logic: '<S309>/Logical Operator1' */
  rtb_LogicalOperator1_i = (rtb_Compare_c2os || rtb_UnitDelay4_ej);

  /* Switch: '<S309>/Switch1' incorporates:
   *  Constant: '<S309>/Constant1'
   */
  if (rtb_LogicalOperator1_i) {
    rtb_Switch1_c = rtb_Switch_j;
  } else {
    rtb_Switch1_c = measure_P.Constant1_Value_g;
  }

  /* End of Switch: '<S309>/Switch1' */

  /* UnitDelay: '<S941>/Unit Delay1' */
  rtb_UnitDelay1_n0 = measure_DWork.UnitDelay1_DSTATE_gf;

  /* UnitDelay: '<S310>/Unit Delay2' */
  rtb_UnitDelay2_j = measure_DWork.UnitDelay2_DSTATE_h;

  /* UnitDelay: '<S310>/Unit Delay4' */
  rtb_LogicalOperator1_f = measure_DWork.UnitDelay4_DSTATE_ii;

  /* Logic: '<S103>/Logical Operator16' incorporates:
   *  Logic: '<S103>/Logical Operator1'
   */
  rtb_LogicalOperator16 = (rtb_LogicalOperator1_i && (!rtb_UnitDelay4_ej));

  /* UnitDelay: '<S607>/Unit Delay1' */
  rtb_UnitDelay1_k = measure_DWork.UnitDelay1_DSTATE_m4;

  /* DiscretePulseGenerator: '<S554>/Pulse Generator1' */
  rtb_UnaryMinus_a2 = ((real_T)measure_DWork.clockTickCounter_e <
                       measure_P.PulseGenerator1_Duty_a) &&
    (measure_DWork.clockTickCounter_e >= 0) ? measure_P.PulseGenerator1_Amp_a :
    0.0;
  if ((real_T)measure_DWork.clockTickCounter_e >=
      measure_P.PulseGenerator1_Period_a - 1.0) {
    measure_DWork.clockTickCounter_e = 0;
  } else {
    measure_DWork.clockTickCounter_e = measure_DWork.clockTickCounter_e + 1;
  }

  /* End of DiscretePulseGenerator: '<S554>/Pulse Generator1' */

  /* RelationalOperator: '<S560>/Compare' incorporates:
   *  Constant: '<S560>/Constant'
   */
  rtb_Compare_o = (rtb_UnaryMinus_a2 > measure_P.Constant_Value_adhzk50wx);

  /* Logic: '<S558>/Logical Operator1' incorporates:
   *  Logic: '<S558>/Logical Operator2'
   *  UnitDelay: '<S558>/delay1'
   */
  rtb_LogicalOperator1_b2ck = ((!rtb_Compare_o) && measure_DWork.delay1_DSTATE_n);

  /* Sum: '<S495>/Sum' incorporates:
   *  Gain: '<S495>/Gain'
   *  UnitDelay: '<S310>/Unit Delay2'
   *  UnitDelay: '<S495>/Unit Delay'
   */
  rtb_Sum = measure_P.Gain_Gain_a * measure_DWork.UnitDelay2_DSTATE_h +
    measure_DWork.UnitDelay_DSTATE_f;

  /* Switch: '<S547>/Switch' incorporates:
   *  Bias: '<S547>/Bias'
   *  Constant: '<S552>/Constant'
   *  RelationalOperator: '<S552>/Compare'
   */
  if (rtb_Sum > measure_P.Constant_Value_adhzk50wx0) {
    rtb_Sum += measure_P.Bias_Bias_a;
  }

  /* End of Switch: '<S547>/Switch' */

  /* Trigonometry: '<S495>/Trigonometric Function2' */
  rtb_UnaryMinus_a2 = sin(rtb_Sum);

  /* Trigonometry: '<S495>/Trigonometric Function3' */
  rtb_Sum2_g = cos(rtb_Sum);

  /* Switch: '<S548>/Switch' incorporates:
   *  Constant: '<S548>/Constant'
   *  Constant: '<S553>/Constant'
   *  RelationalOperator: '<S553>/Compare'
   *  UnitDelay: '<S310>/Unit Delay2'
   */
  if (measure_DWork.UnitDelay2_DSTATE_h < measure_P.Constant_Value_adhzk50wx0e)
  {
    rtb_Switch4 = measure_P.Constant_Value_ad;
  } else {
    rtb_Switch4 = measure_DWork.UnitDelay2_DSTATE_h;
  }

  /* End of Switch: '<S548>/Switch' */

  /* Bias: '<S495>/Bias' incorporates:
   *  Gain: '<S495>/F//Cn3'
   *  Sum: '<S495>/Add'
   *  UnitDelay: '<S310>/Unit Delay2'
   */
  rtb_Divide_jahf = (measure_DWork.UnitDelay2_DSTATE_h - rtb_Switch4) *
    measure_P.FCn3_Gain + measure_P.Bias_Bias_adhzk;

  /* Product: '<S623>/Product' */
  measure_B.Product[0] = rtb_Divide_jahfx * rtb_UnaryMinus_a2 * rtb_Divide_jahf;
  measure_B.Product[1] = rtb_Divide_jahfx * rtb_Sum2_g * rtb_Divide_jahf;

  /* Switch: '<S642>/Switch' incorporates:
   *  Constant: '<S642>/double'
   *  Sum: '<S642>/Sum2'
   *  UnitDelay: '<S642>/Unit Delay2'
   *  UnitDelay: '<S642>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_ix = measure_P.double_Value_bln4;
  } else {
    measure_B.Switch_ix = (measure_B.Product[0] +
      measure_DWork.UnitDelay4_DSTATE_j) + measure_DWork.UnitDelay2_DSTATE_lj;
  }

  /* End of Switch: '<S642>/Switch' */

  /* Math: '<S495>/Math Function'
   *
   * About '<S495>/Math Function':
   *  Operator: reciprocal
   */
  rtb_Switch = 1.0 / rtb_Switch4;

  /* Switch: '<S555>/Switch' incorporates:
   *  Constant: '<S555>/Constant'
   *  Constant: '<S561>/Constant'
   *  Constant: '<S562>/Constant'
   *  RelationalOperator: '<S561>/Compare'
   *  RelationalOperator: '<S562>/Compare'
   *  Switch: '<S555>/Switch1'
   */
  if (rtb_Switch < measure_P.Constant_Value_adhzk50wx0e4) {
    rtb_Switch4 = measure_P.Constant_Value_adhz;
  } else if (rtb_Switch > measure_P.Constant_Value_adh) {
    /* Switch: '<S555>/Switch1' incorporates:
     *  Constant: '<S555>/Constant1'
     */
    rtb_Switch4 = measure_P.Constant1_Value_a;
  } else {
    rtb_Switch4 = rtb_Switch;
  }

  /* End of Switch: '<S555>/Switch' */

  /* Gain: '<S556>/Gain' */
  rtb_Gain_m = measure_P.Gain_Gain_ad * rtb_Switch4;

  /* Switch: '<S563>/Switch2' incorporates:
   *  Bias: '<S563>/Bias1'
   *  Constant: '<S566>/Constant'
   *  RelationalOperator: '<S566>/Compare'
   *  Switch: '<S563>/Switch1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_h = rtb_Gain_m + measure_P.Bias1_Bias_a;
  } else if (rtb_Gain_m < measure_P.Constant_Value_adhzk50wx0e4y) {
    /* Switch: '<S563>/Switch1' */
    measure_B.Switch2_h = rtb_Gain_m;
  } else {
    /* Switch: '<S563>/Switch1' incorporates:
     *  Bias: '<S563>/Bias'
     */
    measure_B.Switch2_h = rtb_Gain_m + measure_P.Bias_Bias_ad;
  }

  /* End of Switch: '<S563>/Switch2' */
  /* S-Function "SF_Cast_double_to_int32" Block: <S563>/S-Function */
  {
    measure_B.SFunction_m3 = (int)measure_B.Switch2_h;
  }

  /* Switch: '<S564>/Switch2' incorporates:
   *  Constant: '<S564>/Constant'
   *  Constant: '<S567>/Constant'
   *  Constant: '<S568>/Constant'
   *  RelationalOperator: '<S567>/Compare'
   *  RelationalOperator: '<S568>/Compare'
   *  Switch: '<S564>/Switch3'
   */
  if (measure_B.SFunction_m3 < measure_P.Constant_Value_a1) {
    measure_B.Switch2_hhsc = measure_P.Constant_Value_aj;
  } else if (measure_B.SFunction_m3 > measure_P.Constant_Value_jv) {
    /* Switch: '<S564>/Switch3' incorporates:
     *  Constant: '<S564>/Constant3'
     */
    measure_B.Switch2_hhsc = measure_P.Constant3_Value_a;
  } else {
    measure_B.Switch2_hhsc = measure_B.SFunction_m3;
  }

  /* End of Switch: '<S564>/Switch2' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S639>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_f[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_hg;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ix;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOneT_b) Offset = measure_P.VariableDiscreteDelaywithOneT_b;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_b;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_p = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_b)
      *VDD_in = 0;
  }

  /* Logic: '<S557>/Logical Operator' incorporates:
   *  Logic: '<S557>/Logical Operator1'
   *  UnitDelay: '<S557>/delay'
   */
  rtb_LogicalOperator_aj = (rtb_Compare_o && (!measure_DWork.delay_DSTATE_c));

  /* Switch: '<S643>/Switch' incorporates:
   *  Constant: '<S643>/double'
   *  Sum: '<S643>/Sum2'
   *  UnitDelay: '<S643>/Unit Delay2'
   *  UnitDelay: '<S643>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_ixh = measure_P.double_Value_bln4d;
  } else {
    measure_B.Switch_ixh = (measure_B.Product[0] +
      measure_DWork.UnitDelay4_DSTATE_js) + measure_DWork.UnitDelay2_DSTATE_ljf;
  }

  /* End of Switch: '<S643>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S640>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_f2[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_hgo;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixh;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOne_bl) Offset = measure_P.VariableDiscreteDelaywithOne_bl;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_bl;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_pd = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_bl)
      *VDD_in = 0;
  }

  /* Switch: '<S634>/Switch1' incorporates:
   *  Sum: '<S634>/Sum1'
   *  Sum: '<S634>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Divide_ja = measure_B.Switch_ix -
      measure_B.VariableDiscreteDelaywithOneT_p;
  } else {
    rtb_Divide_ja = measure_B.Switch_ixh -
      measure_B.VariableDiscreteDelaywithOne_pd;
  }

  /* End of Switch: '<S634>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S644>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_a[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_o;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product[0];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwoT_b) Offset = measure_P.VariableDiscreteDelaywithTwoT_b;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_b;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoT_i = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_b)
      measure_B.VariableDiscreteDelaywithTwo_iz = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwo_iz = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_b)
      *VDD_in = 0;
  }

  /* Sum: '<S556>/Subtract1' incorporates:
   *  DataTypeConversion: '<S565>/Data Type Conversion'
   */
  rtb_Subtract3_c0 = (real_T)measure_B.Switch2_hhsc - rtb_Gain_m;

  /* Math: '<S556>/Math Function' */
  rtb_MathFunction_ed1 = rtb_Subtract3_c0 * rtb_Subtract3_c0;

  /* Sum: '<S556>/Subtract3' incorporates:
   *  Gain: '<S556>/Gain1'
   */
  rtb_Subtract3_c0 = measure_P.Gain1_Gain_ad * rtb_Subtract3_c0 -
    rtb_MathFunction_ed1;

  /* Sum: '<S641>/Sum7' incorporates:
   *  Product: '<S641>/Product'
   *  Product: '<S641>/Product1'
   *  Sum: '<S641>/Sum1'
   */
  rtb_Gain_m = rtb_Divide_ja - (measure_B.VariableDiscreteDelaywithTwoT_i *
    rtb_Subtract3_c0 + measure_B.VariableDiscreteDelaywithTwo_iz *
    rtb_MathFunction_ed1);

  /* Gain: '<S549>/Gain' incorporates:
   *  Math: '<S549>/Math Function'
   *
   * About '<S549>/Math Function':
   *  Operator: reciprocal
   */
  rtb_Divide_ja = 1.0 / rtb_Switch4 * measure_P.Gain_Gain_adh;

  /* Product: '<S641>/Divide' */
  measure_B.Divide = rtb_Gain_m * rtb_Divide_ja;

  /* Math: '<S652>/Math Function1' */
  rtb_Gain_m = measure_B.Divide * measure_B.Divide;

  /* Switch: '<S648>/Switch' incorporates:
   *  Constant: '<S648>/double'
   *  Sum: '<S648>/Sum2'
   *  UnitDelay: '<S648>/Unit Delay2'
   *  UnitDelay: '<S648>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_ixhv = measure_P.double_Value_bln4dj;
  } else {
    measure_B.Switch_ixhv = (measure_B.Product[1] +
      measure_DWork.UnitDelay4_DSTATE_js0) +
      measure_DWork.UnitDelay2_DSTATE_ljfw;
  }

  /* End of Switch: '<S648>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S645>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_f2j[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_hgow;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhv;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOn_bln) Offset = measure_P.VariableDiscreteDelaywithOn_bln;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_bln;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_pdh = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_bln)
      *VDD_in = 0;
  }

  /* Switch: '<S649>/Switch' incorporates:
   *  Constant: '<S649>/double'
   *  Sum: '<S649>/Sum2'
   *  UnitDelay: '<S649>/Unit Delay2'
   *  UnitDelay: '<S649>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_ixhvn = measure_P.double_Value_bln4djb;
  } else {
    measure_B.Switch_ixhvn = (measure_B.Product[1] +
      measure_DWork.UnitDelay4_DSTATE_js0g) +
      measure_DWork.UnitDelay2_DSTATE_ljfwk;
  }

  /* End of Switch: '<S649>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S646>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_f2jg[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_hgowj;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvn;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithO_bln4) Offset = measure_P.VariableDiscreteDelaywithO_bln4;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_bln4;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithO_pdh5 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_bln4)
      *VDD_in = 0;
  }

  /* Switch: '<S635>/Switch1' incorporates:
   *  Sum: '<S635>/Sum1'
   *  Sum: '<S635>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Switch4 = measure_B.Switch_ixhv -
      measure_B.VariableDiscreteDelaywithOn_pdh;
  } else {
    rtb_Switch4 = measure_B.Switch_ixhvn -
      measure_B.VariableDiscreteDelaywithO_pdh5;
  }

  /* End of Switch: '<S635>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S650>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_ab[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_oc;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product[1];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwo_bl) Offset = measure_P.VariableDiscreteDelaywithTwo_bl;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_bl;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwo_im = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_bl)
      measure_B.VariableDiscreteDelaywithTw_izc = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTw_izc = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_bl)
      *VDD_in = 0;
  }

  /* Product: '<S647>/Divide' incorporates:
   *  Product: '<S647>/Product'
   *  Product: '<S647>/Product1'
   *  Sum: '<S647>/Sum1'
   *  Sum: '<S647>/Sum7'
   */
  measure_B.Divide_h = (rtb_Switch4 - (measure_B.VariableDiscreteDelaywithTwo_im
    * rtb_Subtract3_c0 + measure_B.VariableDiscreteDelaywithTw_izc *
    rtb_MathFunction_ed1)) * rtb_Divide_ja;

  /* Sum: '<S652>/Subtract' incorporates:
   *  Math: '<S652>/Math Function3'
   */
  rtb_Switch4 = measure_B.Divide_h * measure_B.Divide_h + rtb_Gain_m;

  /* Math: '<S652>/Math Function2'
   *
   * About '<S652>/Math Function2':
   *  Operator: sqrt
   */
  rtb_MathFunction2 = rtb_Switch4 < 0.0 ? -sqrt(fabs(rtb_Switch4)) : sqrt
    (rtb_Switch4);

  /* RelationalOperator: '<S496>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  rtb_RelationalOperator_c = (rtb_MathFunction2 > measure_P.Constant5_Value);

  /* Logic: '<S496>/Logical Operator1' */
  rtb_Compare_k1g = (rtb_RelationalOperator_c || rtb_UnitDelay4_hd);

  /* Switch: '<S607>/Switch' incorporates:
   *  Constant: '<S607>/const'
   */
  if (rtb_Compare_k1g) {
    rtb_Switch1_m = rtb_UnitDelay1_k;
  } else {
    rtb_Switch1_m = measure_P.const_Value_o;
  }

  /* End of Switch: '<S607>/Switch' */

  /* RelationalOperator: '<S695>/Compare' incorporates:
   *  Constant: '<S695>/Constant'
   */
  rtb_Compare_ha = (rtb_Switch1_m == measure_P.Constant_Value_lo);

  /* UnitDelay: '<S708>/Unit Delay1' */
  rtb_UnitDelay1_k = measure_DWork.UnitDelay1_DSTATE_j4;

  /* Product: '<S724>/Product' */
  measure_B.Product_j[0] = rtb_Switch_b2 * rtb_UnaryMinus_a2 * rtb_Divide_jahf;
  measure_B.Product_j[1] = rtb_Switch_b2 * rtb_Sum2_g * rtb_Divide_jahf;

  /* Switch: '<S743>/Switch' incorporates:
   *  Constant: '<S743>/double'
   *  Sum: '<S743>/Sum2'
   *  UnitDelay: '<S743>/Unit Delay2'
   *  UnitDelay: '<S743>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_d = measure_P.double_Value_eznc;
  } else {
    measure_B.Switch_d = (measure_B.Product_j[0] +
                          measure_DWork.UnitDelay4_DSTATE_e) +
      measure_DWork.UnitDelay2_DSTATE_ab;
  }

  /* End of Switch: '<S743>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S740>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_f2jgc[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_hgowjf;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_d;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOne_ez) Offset = measure_P.VariableDiscreteDelaywithOne_ez;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_ez;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywith_pdh55 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_ez)
      *VDD_in = 0;
  }

  /* Switch: '<S744>/Switch' incorporates:
   *  Constant: '<S744>/double'
   *  Sum: '<S744>/Sum2'
   *  UnitDelay: '<S744>/Unit Delay2'
   *  UnitDelay: '<S744>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_dh = measure_P.double_Value_ezncl;
  } else {
    measure_B.Switch_dh = (measure_B.Product_j[0] +
      measure_DWork.UnitDelay4_DSTATE_e1) + measure_DWork.UnitDelay2_DSTATE_abj;
  }

  /* End of Switch: '<S744>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S741>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_f2jgc1[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_hgowjfv;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dh;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOn_ezn) Offset = measure_P.VariableDiscreteDelaywithOn_ezn;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_ezn;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywit_pdh55d = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_ezn)
      *VDD_in = 0;
  }

  /* Switch: '<S735>/Switch1' incorporates:
   *  Sum: '<S735>/Sum1'
   *  Sum: '<S735>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Switch4 = measure_B.Switch_d - measure_B.VariableDiscreteDelaywith_pdh55;
  } else {
    rtb_Switch4 = measure_B.Switch_dh -
      measure_B.VariableDiscreteDelaywit_pdh55d;
  }

  /* End of Switch: '<S735>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S745>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_ab4[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_oci;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product_j[0];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwo_ez) Offset = measure_P.VariableDiscreteDelaywithTwo_ez;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_ez;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTw_imq = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_ez)
      measure_B.VariableDiscreteDelaywithT_izcm = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithT_izcm = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_ez)
      *VDD_in = 0;
  }

  /* Product: '<S742>/Divide' incorporates:
   *  Product: '<S742>/Product'
   *  Product: '<S742>/Product1'
   *  Sum: '<S742>/Sum1'
   *  Sum: '<S742>/Sum7'
   */
  measure_B.Divide_n = (rtb_Switch4 - (measure_B.VariableDiscreteDelaywithTw_imq
    * rtb_Subtract3_c0 + measure_B.VariableDiscreteDelaywithT_izcm *
    rtb_MathFunction_ed1)) * rtb_Divide_ja;

  /* Math: '<S753>/Math Function1' */
  rtb_Gain_m = measure_B.Divide_n * measure_B.Divide_n;

  /* Switch: '<S749>/Switch' incorporates:
   *  Constant: '<S749>/double'
   *  Sum: '<S749>/Sum2'
   *  UnitDelay: '<S749>/Unit Delay2'
   *  UnitDelay: '<S749>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_dh3 = measure_P.double_Value_eznclc;
  } else {
    measure_B.Switch_dh3 = (measure_B.Product_j[1] +
      measure_DWork.UnitDelay4_DSTATE_e10) +
      measure_DWork.UnitDelay2_DSTATE_abju;
  }

  /* End of Switch: '<S749>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S746>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_f2jgc1y[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_hgowjfvn;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithO_eznc) Offset = measure_P.VariableDiscreteDelaywithO_eznc;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_eznc;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywi_pdh55di = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_eznc)
      *VDD_in = 0;
  }

  /* Switch: '<S750>/Switch' incorporates:
   *  Constant: '<S750>/double'
   *  Sum: '<S750>/Sum2'
   *  UnitDelay: '<S750>/Unit Delay2'
   *  UnitDelay: '<S750>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_dh3i = measure_P.double_Value_eznclc5;
  } else {
    measure_B.Switch_dh3i = (measure_B.Product_j[1] +
      measure_DWork.UnitDelay4_DSTATE_e10c) +
      measure_DWork.UnitDelay2_DSTATE_abju3;
  }

  /* End of Switch: '<S750>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S747>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_f2jgc1yy[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_hgowjfvnn;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3i;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywith_ezncl) Offset = measure_P.VariableDiscreteDelaywith_ezncl;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_ezncl;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelayw_pdh55dim = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_ezncl)
      *VDD_in = 0;
  }

  /* Switch: '<S736>/Switch1' incorporates:
   *  Sum: '<S736>/Sum1'
   *  Sum: '<S736>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Switch4 = measure_B.Switch_dh3 -
      measure_B.VariableDiscreteDelaywi_pdh55di;
  } else {
    rtb_Switch4 = measure_B.Switch_dh3i -
      measure_B.VariableDiscreteDelayw_pdh55dim;
  }

  /* End of Switch: '<S736>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S751>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_ab4s[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_oci4;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product_j[1];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTw_ezn) Offset = measure_P.VariableDiscreteDelaywithTw_ezn;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_ezn;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithT_imqp = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTw_ezn)
      measure_B.VariableDiscreteDelaywith_izcmu = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywith_izcmu = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_ezn)
      *VDD_in = 0;
  }

  /* Product: '<S748>/Divide' incorporates:
   *  Product: '<S748>/Product'
   *  Product: '<S748>/Product1'
   *  Sum: '<S748>/Sum1'
   *  Sum: '<S748>/Sum7'
   */
  measure_B.Divide_ny = (rtb_Switch4 -
    (measure_B.VariableDiscreteDelaywithT_imqp * rtb_Subtract3_c0 +
     measure_B.VariableDiscreteDelaywith_izcmu * rtb_MathFunction_ed1)) *
    rtb_Divide_ja;

  /* Sum: '<S753>/Subtract' incorporates:
   *  Math: '<S753>/Math Function3'
   */
  rtb_Switch4 = measure_B.Divide_ny * measure_B.Divide_ny + rtb_Gain_m;

  /* Math: '<S753>/Math Function2'
   *
   * About '<S753>/Math Function2':
   *  Operator: sqrt
   */
  rtb_MathFunction2_c = rtb_Switch4 < 0.0 ? -sqrt(fabs(rtb_Switch4)) : sqrt
    (rtb_Switch4);

  /* RelationalOperator: '<S497>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  rtb_RelationalOperator_i = (rtb_MathFunction2_c > measure_P.Constant5_Value);

  /* Logic: '<S497>/Logical Operator1' */
  rtb_Compare_aun = (rtb_RelationalOperator_i || rtb_UnitDelay4_hd);

  /* Switch: '<S708>/Switch' incorporates:
   *  Constant: '<S708>/const'
   */
  if (rtb_Compare_aun) {
    rtb_Switch1_o = rtb_UnitDelay1_k;
  } else {
    rtb_Switch1_o = measure_P.const_Value_ec;
  }

  /* End of Switch: '<S708>/Switch' */

  /* RelationalOperator: '<S796>/Compare' incorporates:
   *  Constant: '<S796>/Constant'
   */
  rtb_Compare_df = (rtb_Switch1_o == measure_P.Constant_Value_cm);

  /* UnitDelay: '<S809>/Unit Delay1' */
  rtb_UnitDelay1_k = measure_DWork.UnitDelay1_DSTATE_g0;

  /* Product: '<S825>/Product' */
  measure_B.Product_k[0] = rtb_UnaryMinus_p * rtb_UnaryMinus_a2 *
    rtb_Divide_jahf;
  measure_B.Product_k[1] = rtb_UnaryMinus_p * rtb_Sum2_g * rtb_Divide_jahf;

  /* Switch: '<S844>/Switch' incorporates:
   *  Constant: '<S844>/double'
   *  Sum: '<S844>/Sum2'
   *  UnitDelay: '<S844>/Unit Delay2'
   *  UnitDelay: '<S844>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_p = measure_P.double_Value_e0r1;
  } else {
    measure_B.Switch_p = (measure_B.Product_k[0] +
                          measure_DWork.UnitDelay4_DSTATE_o) +
      measure_DWork.UnitDelay2_DSTATE_g;
  }

  /* End of Switch: '<S844>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S841>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_f2jgc1yyu[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_hgowjfvnnx;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOne_e0) Offset = measure_P.VariableDiscreteDelaywithOne_e0;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_e0;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelay_pdh55dim3 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_e0)
      *VDD_in = 0;
  }

  /* Switch: '<S845>/Switch' incorporates:
   *  Constant: '<S845>/double'
   *  Sum: '<S845>/Sum2'
   *  UnitDelay: '<S845>/Unit Delay2'
   *  UnitDelay: '<S845>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_p0 = measure_P.double_Value_e0r1h;
  } else {
    measure_B.Switch_p0 = (measure_B.Product_k[0] +
      measure_DWork.UnitDelay4_DSTATE_ot) + measure_DWork.UnitDelay2_DSTATE_gl;
  }

  /* End of Switch: '<S845>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S842>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_f2jgc1yyuf[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_hgowjfvnnxz;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p0;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOn_e0r) Offset = measure_P.VariableDiscreteDelaywithOn_e0r;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_e0r;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDela_pdh55dim3o = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_e0r)
      *VDD_in = 0;
  }

  /* Switch: '<S836>/Switch1' incorporates:
   *  Sum: '<S836>/Sum1'
   *  Sum: '<S836>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Switch4 = measure_B.Switch_p - measure_B.VariableDiscreteDelay_pdh55dim3;
  } else {
    rtb_Switch4 = measure_B.Switch_p0 -
      measure_B.VariableDiscreteDela_pdh55dim3o;
  }

  /* End of Switch: '<S836>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S846>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_ab4s3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_oci4c;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product_k[0];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwo_e0) Offset = measure_P.VariableDiscreteDelaywithTwo_e0;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_e0;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywith_imqpt = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_e0)
      measure_B.VariableDiscreteDelaywit_izcmu0 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywit_izcmu0 = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_e0)
      *VDD_in = 0;
  }

  /* Product: '<S843>/Divide' incorporates:
   *  Product: '<S843>/Product'
   *  Product: '<S843>/Product1'
   *  Sum: '<S843>/Sum1'
   *  Sum: '<S843>/Sum7'
   */
  measure_B.Divide_j = (rtb_Switch4 - (measure_B.VariableDiscreteDelaywith_imqpt
    * rtb_Subtract3_c0 + measure_B.VariableDiscreteDelaywit_izcmu0 *
    rtb_MathFunction_ed1)) * rtb_Divide_ja;

  /* Math: '<S854>/Math Function1' */
  rtb_Gain_m = measure_B.Divide_j * measure_B.Divide_j;

  /* Switch: '<S850>/Switch' incorporates:
   *  Constant: '<S850>/double'
   *  Sum: '<S850>/Sum2'
   *  UnitDelay: '<S850>/Unit Delay2'
   *  UnitDelay: '<S850>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_p0n = measure_P.double_Value_e0r1hm;
  } else {
    measure_B.Switch_p0n = (measure_B.Product_k[1] +
      measure_DWork.UnitDelay4_DSTATE_otw) + measure_DWork.UnitDelay2_DSTATE_gll;
  }

  /* End of Switch: '<S850>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S847>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_f2jgc1yyufb[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_hgowjfvnnxzl;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p0n;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithO_e0r1) Offset = measure_P.VariableDiscreteDelaywithO_e0r1;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_e0r1;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDel_pdh55dim3ox = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_e0r1)
      *VDD_in = 0;
  }

  /* Switch: '<S851>/Switch' incorporates:
   *  Constant: '<S851>/double'
   *  Sum: '<S851>/Sum2'
   *  UnitDelay: '<S851>/Unit Delay2'
   *  UnitDelay: '<S851>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_p0ny = measure_P.double_Value_e0r1hmw;
  } else {
    measure_B.Switch_p0ny = (measure_B.Product_k[1] +
      measure_DWork.UnitDelay4_DSTATE_otws) +
      measure_DWork.UnitDelay2_DSTATE_gllv;
  }

  /* End of Switch: '<S851>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S848>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_f2jgc1yyufbl[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_hgowjfvnnxzlo;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywith_e0r1h) Offset = measure_P.VariableDiscreteDelaywith_e0r1h;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_e0r1h;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDe_pdh55dim3oxm = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_e0r1h)
      *VDD_in = 0;
  }

  /* Switch: '<S837>/Switch1' incorporates:
   *  Sum: '<S837>/Sum1'
   *  Sum: '<S837>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Switch4 = measure_B.Switch_p0n -
      measure_B.VariableDiscreteDel_pdh55dim3ox;
  } else {
    rtb_Switch4 = measure_B.Switch_p0ny -
      measure_B.VariableDiscreteDe_pdh55dim3oxm;
  }

  /* End of Switch: '<S837>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S852>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_ab4s3q[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_oci4cw;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product_k[1];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTw_e0r) Offset = measure_P.VariableDiscreteDelaywithTw_e0r;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_e0r;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywit_imqptq = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTw_e0r)
      measure_B.VariableDiscreteDelaywi_izcmu0m = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywi_izcmu0m = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_e0r)
      *VDD_in = 0;
  }

  /* Product: '<S849>/Divide' incorporates:
   *  Product: '<S849>/Product'
   *  Product: '<S849>/Product1'
   *  Sum: '<S849>/Sum1'
   *  Sum: '<S849>/Sum7'
   */
  measure_B.Divide_jw = (rtb_Switch4 -
    (measure_B.VariableDiscreteDelaywit_imqptq * rtb_Subtract3_c0 +
     measure_B.VariableDiscreteDelaywi_izcmu0m * rtb_MathFunction_ed1)) *
    rtb_Divide_ja;

  /* Sum: '<S854>/Subtract' incorporates:
   *  Math: '<S854>/Math Function3'
   */
  rtb_Switch4 = measure_B.Divide_jw * measure_B.Divide_jw + rtb_Gain_m;

  /* Math: '<S854>/Math Function2'
   *
   * About '<S854>/Math Function2':
   *  Operator: sqrt
   */
  rtb_MathFunction2_a = rtb_Switch4 < 0.0 ? -sqrt(fabs(rtb_Switch4)) : sqrt
    (rtb_Switch4);

  /* RelationalOperator: '<S498>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  rtb_RelationalOperator_h = (rtb_MathFunction2_a > measure_P.Constant5_Value);

  /* Logic: '<S498>/Logical Operator1' */
  rtb_Compare_o1 = (rtb_RelationalOperator_h || rtb_UnitDelay4_hd);

  /* Switch: '<S809>/Switch' incorporates:
   *  Constant: '<S809>/const'
   */
  if (rtb_Compare_o1) {
    rtb_Switch1_k3g = rtb_UnitDelay1_k;
  } else {
    rtb_Switch1_k3g = measure_P.const_Value_l;
  }

  /* End of Switch: '<S809>/Switch' */

  /* RelationalOperator: '<S897>/Compare' incorporates:
   *  Constant: '<S897>/Constant'
   */
  rtb_Compare_m3 = (rtb_Switch1_k3g == measure_P.Constant_Value_him);

  /* Logic: '<S310>/Logical Operator9' */
  rtb_LogicalOperator9 = !(rtb_Compare_ha || rtb_Compare_df || rtb_Compare_m3);

  /* Switch: '<S310>/Switch2' incorporates:
   *  Switch: '<S310>/Switch3'
   *  Switch: '<S310>/Switch4'
   */
  if (rtb_UnitDelay4_hd) {
    rtb_Switch4 = rtb_UnitDelay2_j;
  } else if (rtb_LogicalOperator1_f) {
    /* Switch: '<S310>/Switch3' */
    rtb_Switch4 = rtb_Switch1_c;
  } else if (rtb_LogicalOperator9) {
    /* Switch: '<S310>/Switch5' incorporates:
     *  Constant: '<S310>/Constant4'
     *  Switch: '<S310>/Switch3'
     *  Switch: '<S310>/Switch4'
     */
    if (rtb_LogicalOperator16) {
      rtb_Switch4 = rtb_Switch1_c;
    } else {
      rtb_Switch4 = measure_P.Constant4_Value;
    }

    /* End of Switch: '<S310>/Switch5' */
  } else {
    /* Switch: '<S310>/Switch4' incorporates:
     *  Switch: '<S310>/Switch3'
     */
    rtb_Switch4 = rtb_UnitDelay2_j;
  }

  /* End of Switch: '<S310>/Switch2' */

  /* Logic: '<S310>/Logical Operator3' */
  rtb_Compare_mp = (rtb_UnitDelay4_hd || rtb_LogicalOperator1_f ||
                    rtb_LogicalOperator9);

  /* Logic: '<S310>/Logical Operator14' incorporates:
   *  Logic: '<S310>/Logical Operator17'
   */
  rtb_Compare_go = (rtb_Compare_mp || (!(rtb_Compare_ha || rtb_LogicalOperator9)));

  /* DiscretePulseGenerator: '<S584>/Pulse Generator1' */
  rtb_Divide_h3 = ((real_T)measure_DWork.clockTickCounter_ey <
                   measure_P.PulseGenerator1_Duty_ad) &&
    (measure_DWork.clockTickCounter_ey >= 0) ? measure_P.PulseGenerator1_Amp_ad :
    0.0;
  if ((real_T)measure_DWork.clockTickCounter_ey >=
      measure_P.PulseGenerator1_Period_ad - 1.0) {
    measure_DWork.clockTickCounter_ey = 0;
  } else {
    measure_DWork.clockTickCounter_ey = measure_DWork.clockTickCounter_ey + 1;
  }

  /* End of DiscretePulseGenerator: '<S584>/Pulse Generator1' */

  /* RelationalOperator: '<S590>/Compare' incorporates:
   *  Constant: '<S590>/Constant'
   */
  rtb_Compare_oafgue = (rtb_Divide_h3 > measure_P.Constant_Value_adhzk50wx0e4yn);

  /* Logic: '<S588>/Logical Operator1' incorporates:
   *  Logic: '<S588>/Logical Operator2'
   *  UnitDelay: '<S588>/delay1'
   */
  rtb_Compare_k5 = ((!rtb_Compare_oafgue) && measure_DWork.delay1_DSTATE_nm);

  /* UnitDelay: '<S600>/Unit Delay3' */
  rtb_Switch1_kt5c = measure_DWork.UnitDelay3_DSTATE_p;

  /* DiscretePulseGenerator: '<S569>/Pulse Generator1' */
  rtb_Divide_h3 = ((real_T)measure_DWork.clockTickCounter_ey4 <
                   measure_P.PulseGenerator1_Duty_adh) &&
    (measure_DWork.clockTickCounter_ey4 >= 0) ?
    measure_P.PulseGenerator1_Amp_adh : 0.0;
  if ((real_T)measure_DWork.clockTickCounter_ey4 >=
      measure_P.PulseGenerator1_Period_adh - 1.0) {
    measure_DWork.clockTickCounter_ey4 = 0;
  } else {
    measure_DWork.clockTickCounter_ey4 = measure_DWork.clockTickCounter_ey4 + 1;
  }

  /* End of DiscretePulseGenerator: '<S569>/Pulse Generator1' */

  /* RelationalOperator: '<S575>/Compare' incorporates:
   *  Constant: '<S575>/Constant'
   */
  rtb_Compare_oafguee = (rtb_Divide_h3 >
    measure_P.Constant_Value_adhzk50wx0e4yn1);

  /* Logic: '<S573>/Logical Operator1' incorporates:
   *  Logic: '<S573>/Logical Operator2'
   *  UnitDelay: '<S573>/delay1'
   */
  rtb_Compare_bq = ((!rtb_Compare_oafguee) && measure_DWork.delay1_DSTATE_nmq);

  /* Switch: '<S666>/Switch' incorporates:
   *  Constant: '<S666>/double'
   *  Sum: '<S666>/Sum2'
   *  UnitDelay: '<S666>/Unit Delay2'
   *  UnitDelay: '<S666>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_ixhvnq = measure_P.double_Value_bln4djb4gs;
  } else {
    measure_B.Switch_ixhvnq = (measure_B.Divide_h +
      measure_DWork.UnitDelay4_DSTATE_js0g0) +
      measure_DWork.UnitDelay2_DSTATE_ljfwkl;
  }

  /* End of Switch: '<S666>/Switch' */

  /* Gain: '<S495>/F//Cn1' */
  rtb_Gain_m = measure_P.FCn1_Gain * rtb_Switch;

  /* Switch: '<S570>/Switch' incorporates:
   *  Constant: '<S570>/Constant'
   *  Constant: '<S576>/Constant'
   *  Constant: '<S577>/Constant'
   *  RelationalOperator: '<S576>/Compare'
   *  RelationalOperator: '<S577>/Compare'
   *  Switch: '<S570>/Switch1'
   */
  if (rtb_Gain_m < measure_P.Constant_Value_d) {
    rtb_Divide_h3 = measure_P.Constant_Value_adhzk5;
  } else if (rtb_Gain_m > measure_P.Constant_Value_adhzk) {
    /* Switch: '<S570>/Switch1' incorporates:
     *  Constant: '<S570>/Constant1'
     */
    rtb_Divide_h3 = measure_P.Constant1_Value_ad;
  } else {
    rtb_Divide_h3 = rtb_Gain_m;
  }

  /* End of Switch: '<S570>/Switch' */

  /* Gain: '<S571>/Gain' */
  rtb_Gain_m = measure_P.Gain_Gain_adhz * rtb_Divide_h3;

  /* Switch: '<S578>/Switch2' incorporates:
   *  Bias: '<S578>/Bias1'
   *  Constant: '<S581>/Constant'
   *  RelationalOperator: '<S581>/Compare'
   *  Switch: '<S578>/Switch1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_hh = rtb_Gain_m + measure_P.Bias1_Bias_ad;
  } else if (rtb_Gain_m < measure_P.Constant_Value_gv) {
    /* Switch: '<S578>/Switch1' */
    measure_B.Switch2_hh = rtb_Gain_m;
  } else {
    /* Switch: '<S578>/Switch1' incorporates:
     *  Bias: '<S578>/Bias'
     */
    measure_B.Switch2_hh = rtb_Gain_m + measure_P.Bias_Bias_adh;
  }

  /* End of Switch: '<S578>/Switch2' */
  /* S-Function "SF_Cast_double_to_int32" Block: <S578>/S-Function */
  {
    measure_B.SFunction_m3m = (int)measure_B.Switch2_hh;
  }

  /* Switch: '<S579>/Switch2' incorporates:
   *  Constant: '<S579>/Constant'
   *  Constant: '<S582>/Constant'
   *  Constant: '<S583>/Constant'
   *  RelationalOperator: '<S582>/Compare'
   *  RelationalOperator: '<S583>/Compare'
   *  Switch: '<S579>/Switch3'
   */
  if (measure_B.SFunction_m3m < measure_P.Constant_Value_ny) {
    measure_B.Switch2_hhsca = measure_P.Constant_Value_aa;
  } else if (measure_B.SFunction_m3m > measure_P.Constant_Value_cp) {
    /* Switch: '<S579>/Switch3' incorporates:
     *  Constant: '<S579>/Constant3'
     */
    measure_B.Switch2_hhsca = measure_P.Constant3_Value_ad;
  } else {
    measure_B.Switch2_hhsca = measure_B.SFunction_m3m;
  }

  /* End of Switch: '<S579>/Switch2' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S663>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_f2jgc1yyufbl2[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscrete_hgowjfvnnxzloq;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnq;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywith_bln4d) Offset = measure_P.VariableDiscreteDelaywith_bln4d;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_bln4d;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteD_pdh55dim3oxmt = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_bln4d)
      *VDD_in = 0;
  }

  /* Logic: '<S572>/Logical Operator' incorporates:
   *  Logic: '<S572>/Logical Operator1'
   *  UnitDelay: '<S572>/delay'
   */
  rtb_Compare_cj = (rtb_Compare_oafguee && (!measure_DWork.delay_DSTATE_ci));

  /* Switch: '<S667>/Switch' incorporates:
   *  Constant: '<S667>/double'
   *  Sum: '<S667>/Sum2'
   *  UnitDelay: '<S667>/Unit Delay2'
   *  UnitDelay: '<S667>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_ixhvnql = measure_P.double_Value_bln4djb4gs5;
  } else {
    measure_B.Switch_ixhvnql = (measure_B.Divide_h +
      measure_DWork.UnitDelay4_DSTATE_js0g0x) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf;
  }

  /* End of Switch: '<S667>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S664>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_f2jgc1yyufbl2v[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_hgowjfvnnxzloqs;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnql;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywit_bln4dj) Offset = measure_P.VariableDiscreteDelaywit_bln4dj;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_bln4dj;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscrete_pdh55dim3oxmtq = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_bln4dj)
      *VDD_in = 0;
  }

  /* Switch: '<S655>/Switch1' incorporates:
   *  Sum: '<S655>/Sum1'
   *  Sum: '<S655>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Divide_jah = measure_B.Switch_ixhvnq -
      measure_B.VariableDiscreteD_pdh55dim3oxmt;
  } else {
    rtb_Divide_jah = measure_B.Switch_ixhvnql -
      measure_B.VariableDiscrete_pdh55dim3oxmtq;
  }

  /* End of Switch: '<S655>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S668>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_ab4s3ql[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_oci4cw4;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide_h;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTw_bln) Offset = measure_P.VariableDiscreteDelaywithTw_bln;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_bln;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywi_imqptqt = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTw_bln)
      measure_B.VariableDiscreteDelayw_izcmu0mr = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelayw_izcmu0mr = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_bln)
      *VDD_in = 0;
  }

  /* Sum: '<S571>/Subtract1' incorporates:
   *  DataTypeConversion: '<S580>/Data Type Conversion'
   */
  rtb_Subtract3_c04 = (real_T)measure_B.Switch2_hhsca - rtb_Gain_m;

  /* Math: '<S571>/Math Function' */
  rtb_MathFunction_ed12 = rtb_Subtract3_c04 * rtb_Subtract3_c04;

  /* Sum: '<S571>/Subtract3' incorporates:
   *  Gain: '<S571>/Gain1'
   */
  rtb_Subtract3_c04 = measure_P.Gain1_Gain_adh * rtb_Subtract3_c04 -
    rtb_MathFunction_ed12;

  /* Sum: '<S665>/Sum7' incorporates:
   *  Product: '<S665>/Product'
   *  Product: '<S665>/Product1'
   *  Sum: '<S665>/Sum1'
   */
  rtb_Gain_m = rtb_Divide_jah - (measure_B.VariableDiscreteDelaywi_imqptqt *
    rtb_Subtract3_c04 + measure_B.VariableDiscreteDelayw_izcmu0mr *
    rtb_MathFunction_ed12);

  /* Gain: '<S550>/Gain' incorporates:
   *  Math: '<S550>/Math Function'
   *
   * About '<S550>/Math Function':
   *  Operator: reciprocal
   */
  rtb_Divide_jah = 1.0 / rtb_Divide_h3 * measure_P.Gain_Gain_adhzk;

  /* Product: '<S665>/Divide' */
  rtb_Divide_h3 = rtb_Gain_m * rtb_Divide_jah;

  /* Switch: '<S660>/Switch' incorporates:
   *  Constant: '<S660>/double'
   *  Sum: '<S660>/Sum2'
   *  UnitDelay: '<S660>/Unit Delay2'
   *  UnitDelay: '<S660>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_ixhvnqlu = measure_P.double_Value_bln4djb4;
  } else {
    measure_B.Switch_ixhvnqlu = (measure_B.Divide +
      measure_DWork.UnitDelay4_DSTATE_js0g0xc) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5;
  }

  /* End of Switch: '<S660>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S657>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f2jgc1yyufbl2vd[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pkx;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqlu;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywi_bln4djb) Offset = measure_P.VariableDiscreteDelaywi_bln4djb;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_bln4djb;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_pdh55dim3oxmtqn = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_bln4djb)
      *VDD_in = 0;
  }

  /* Switch: '<S661>/Switch' incorporates:
   *  Constant: '<S661>/double'
   *  Sum: '<S661>/Sum2'
   *  UnitDelay: '<S661>/Unit Delay2'
   *  UnitDelay: '<S661>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_ixhvnqlui = measure_P.double_Value_bln4djb4g;
  } else {
    measure_B.Switch_ixhvnqlui = (measure_B.Divide +
      measure_DWork.UnitDelay4_DSTATE_js0g0xck) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5t;
  }

  /* End of Switch: '<S661>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S658>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_d[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_lw;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqlui;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelayw_bln4djb4) Offset = measure_P.VariableDiscreteDelayw_bln4djb4;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_bln4djb4;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_o = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_bln4djb4)
      *VDD_in = 0;
  }

  /* Switch: '<S654>/Switch1' incorporates:
   *  Sum: '<S654>/Sum1'
   *  Sum: '<S654>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Divide_h = measure_B.Switch_ixhvnqlu -
      measure_B.VariableDiscret_pdh55dim3oxmtqn;
  } else {
    rtb_Divide_h = measure_B.Switch_ixhvnqlui - measure_B.VariableDiscret_o;
  }

  /* End of Switch: '<S654>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S662>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_ab4s3qlk[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_oci4cw4v;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithT_bln4) Offset = measure_P.VariableDiscreteDelaywithT_bln4;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_bln4;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelayw_imqptqte = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithT_bln4)
      measure_B.VariableDiscreteDelay_izcmu0mrb = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelay_izcmu0mrb = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_bln4)
      *VDD_in = 0;
  }

  /* Product: '<S659>/Divide' incorporates:
   *  Product: '<S659>/Product'
   *  Product: '<S659>/Product1'
   *  Sum: '<S659>/Sum1'
   *  Sum: '<S659>/Sum7'
   */
  rtb_Divide_h = (rtb_Divide_h - (measure_B.VariableDiscreteDelayw_imqptqte *
    rtb_Subtract3_c04 + measure_B.VariableDiscreteDelay_izcmu0mrb *
    rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Trigonometry: '<S669>/Trigonometric Function' */
  rtb_TrigonometricFunction_l = atan2(rtb_Divide_h3, rtb_Divide_h);

  /* Sum: '<S496>/Add' */
  rtb_Add_a = rtb_TrigonometricFunction_l + rtb_Sum;

  /* Switch: '<S496>/Switch6' */
  if (rtb_Compare_go) {
    measure_B.Switch6 = rtb_Switch4;
  } else {
    /* Sum: '<S600>/Sum2' */
    rtb_Gain_m = rtb_Add_a - rtb_Switch1_kt5c;

    /* Switch: '<S613>/Switch1' incorporates:
     *  Bias: '<S613>/Bias1'
     *  Constant: '<S614>/Constant'
     *  Constant: '<S615>/Constant'
     *  RelationalOperator: '<S614>/Compare'
     *  RelationalOperator: '<S615>/Compare'
     *  Switch: '<S613>/Switch'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_kkp) {
      rtb_Gain_m += measure_P.Bias1_Bias_k;
    } else {
      if (rtb_Gain_m > measure_P.Constant_Value_kk) {
        /* Switch: '<S613>/Switch' incorporates:
         *  Bias: '<S613>/Bias'
         */
        rtb_Gain_m += measure_P.Bias_Bias_k;
      }
    }

    /* End of Switch: '<S613>/Switch1' */

    /* Gain: '<S600>/Gain' */
    rtb_Gain_m *= measure_P.Gain_Gain_k;

    /* Switch: '<S606>/Switch' incorporates:
     *  Constant: '<S606>/Constant'
     *  Constant: '<S693>/Constant'
     *  Constant: '<S694>/Constant'
     *  RelationalOperator: '<S693>/Compare'
     *  RelationalOperator: '<S694>/Compare'
     *  Switch: '<S606>/Switch1'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_bt) {
      measure_B.Switch6 = measure_P.Constant_Value_mm;
    } else if (rtb_Gain_m > measure_P.Constant_Value_hi) {
      /* Switch: '<S606>/Switch1' incorporates:
       *  Constant: '<S606>/Constant1'
       */
      measure_B.Switch6 = measure_P.Constant1_Value_jk;
    } else {
      measure_B.Switch6 = rtb_Gain_m;
    }

    /* End of Switch: '<S606>/Switch' */
  }

  /* End of Switch: '<S496>/Switch6' */

  /* Switch: '<S619>/Switch' incorporates:
   *  Constant: '<S619>/double'
   *  Sum: '<S619>/Sum2'
   *  UnitDelay: '<S619>/Unit Delay2'
   *  UnitDelay: '<S619>/Unit Delay4'
   */
  if (rtb_Compare_k5) {
    measure_B.Switch_dm = measure_P.double_Value_d1;
  } else {
    measure_B.Switch_dm = (measure_B.Switch6 + measure_DWork.UnitDelay4_DSTATE_i)
      + measure_DWork.UnitDelay2_DSTATE_l1;
  }

  /* End of Switch: '<S619>/Switch' */

  /* Gain: '<S495>/F//Cn2' */
  rtb_Gain_m = measure_P.FCn2_Gain * rtb_Switch;

  /* Switch: '<S585>/Switch' incorporates:
   *  Constant: '<S585>/Constant'
   *  Constant: '<S591>/Constant'
   *  Constant: '<S592>/Constant'
   *  RelationalOperator: '<S591>/Compare'
   *  RelationalOperator: '<S592>/Compare'
   *  Switch: '<S585>/Switch1'
   */
  if (rtb_Gain_m < measure_P.Constant_Value_h2) {
    rtb_Switch_l40f02 = measure_P.Constant_Value_adhzk50w;
  } else if (rtb_Gain_m > measure_P.Constant_Value_adhzk50) {
    /* Switch: '<S585>/Switch1' incorporates:
     *  Constant: '<S585>/Constant1'
     */
    rtb_Switch_l40f02 = measure_P.Constant1_Value_adh;
  } else {
    rtb_Switch_l40f02 = rtb_Gain_m;
  }

  /* End of Switch: '<S585>/Switch' */

  /* Gain: '<S586>/Gain' */
  rtb_Gain_m = measure_P.Gain_Gain_adhzk5 * rtb_Switch_l40f02;

  /* Switch: '<S593>/Switch2' incorporates:
   *  Bias: '<S593>/Bias1'
   *  Constant: '<S596>/Constant'
   *  RelationalOperator: '<S596>/Compare'
   *  Switch: '<S593>/Switch1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_hhs = rtb_Gain_m + measure_P.Bias1_Bias_adh;
  } else if (rtb_Gain_m < measure_P.Constant_Value_ec) {
    /* Switch: '<S593>/Switch1' */
    measure_B.Switch2_hhs = rtb_Gain_m;
  } else {
    /* Switch: '<S593>/Switch1' incorporates:
     *  Bias: '<S593>/Bias'
     */
    measure_B.Switch2_hhs = rtb_Gain_m + measure_P.Bias_Bias_adhz;
  }

  /* End of Switch: '<S593>/Switch2' */
  /* S-Function "SF_Cast_double_to_int32" Block: <S593>/S-Function */
  {
    measure_B.SFunction_m3ml = (int)measure_B.Switch2_hhs;
  }

  /* Switch: '<S594>/Switch2' incorporates:
   *  Constant: '<S594>/Constant'
   *  Constant: '<S597>/Constant'
   *  Constant: '<S598>/Constant'
   *  RelationalOperator: '<S597>/Compare'
   *  RelationalOperator: '<S598>/Compare'
   *  Switch: '<S594>/Switch3'
   */
  if (measure_B.SFunction_m3ml < measure_P.Constant_Value_bq) {
    measure_B.Switch2_hhsca5 = measure_P.Constant_Value_po;
  } else if (measure_B.SFunction_m3ml > measure_P.Constant_Value_kf) {
    /* Switch: '<S594>/Switch3' incorporates:
     *  Constant: '<S594>/Constant3'
     */
    measure_B.Switch2_hhsca5 = measure_P.Constant3_Value_adh;
  } else {
    measure_B.Switch2_hhsca5 = measure_B.SFunction_m3ml;
  }

  /* End of Switch: '<S594>/Switch2' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S616>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_g[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_kq;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dm;

    /*    Offset = measure_B.Switch2_hhsca5;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOneT_h) Offset = measure_P.VariableDiscreteDelaywithOneT_h;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_h;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_i = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_h)
      *VDD_in = 0;
  }

  /* Logic: '<S587>/Logical Operator' incorporates:
   *  Logic: '<S587>/Logical Operator1'
   *  UnitDelay: '<S587>/delay'
   */
  rtb_LogicalOperator_ot = (rtb_Compare_oafgue &&
    (!measure_DWork.delay_DSTATE_cir));

  /* Switch: '<S620>/Switch' incorporates:
   *  Constant: '<S620>/double'
   *  Sum: '<S620>/Sum2'
   *  UnitDelay: '<S620>/Unit Delay2'
   *  UnitDelay: '<S620>/Unit Delay4'
   */
  if (rtb_LogicalOperator_ot) {
    measure_B.Switch_dmo = measure_P.double_Value_d1r;
  } else {
    measure_B.Switch_dmo = (measure_B.Switch6 +
      measure_DWork.UnitDelay4_DSTATE_iv) + measure_DWork.UnitDelay2_DSTATE_l1a;
  }

  /* End of Switch: '<S620>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S617>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ak;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dmo;

    /*    Offset = measure_B.Switch2_hhsca5;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOne_hk) Offset = measure_P.VariableDiscreteDelaywithOne_hk;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_hk;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_id = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_hk)
      *VDD_in = 0;
  }

  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S621>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_ab4s3qlk5[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_oci4cw4vl;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch6;

    /*    Offset = measure_B.Switch2_hhsca5;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwoT_h) Offset = measure_P.VariableDiscreteDelaywithTwoT_h;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_h;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelay_imqptqte5 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_h)
      measure_B.VariableDiscreteDela_izcmu0mrbj = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDela_izcmu0mrbj = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_h)
      *VDD_in = 0;
  }

  /* Sum: '<S586>/Subtract1' incorporates:
   *  DataTypeConversion: '<S595>/Data Type Conversion'
   */
  rtb_Divide_ny = (real_T)measure_B.Switch2_hhsca5 - rtb_Gain_m;

  /* Math: '<S586>/Math Function' */
  rtb_Switch = rtb_Divide_ny * rtb_Divide_ny;

  /* Sum: '<S586>/Subtract3' incorporates:
   *  Gain: '<S586>/Gain1'
   */
  rtb_MathFunction1 = measure_P.Gain1_Gain_adhz * rtb_Divide_ny - rtb_Switch;

  /* Gain: '<S551>/Gain' incorporates:
   *  Math: '<S551>/Math Function'
   *
   * About '<S551>/Math Function':
   *  Operator: reciprocal
   */
  rtb_Switch1_k = 1.0 / rtb_Switch_l40f02 * measure_P.Gain_Gain_adhzk50;

  /* Switch: '<S496>/Switch3' incorporates:
   *  Product: '<S618>/Divide'
   *  Product: '<S618>/Product'
   *  Product: '<S618>/Product1'
   *  Sum: '<S618>/Sum1'
   *  Sum: '<S618>/Sum7'
   *  Switch: '<S601>/Switch1'
   */
  if (rtb_Compare_go) {
    rtb_Divide_ny = rtb_Switch4;
  } else {
    if (rtb_Compare_oafgue) {
      /* Switch: '<S601>/Switch1' incorporates:
       *  Sum: '<S601>/Sum2'
       */
      rtb_Gain_m = measure_B.Switch_dm - measure_B.VariableDiscret_i;
    } else {
      /* Switch: '<S601>/Switch1' incorporates:
       *  Sum: '<S601>/Sum1'
       */
      rtb_Gain_m = measure_B.Switch_dmo - measure_B.VariableDiscret_id;
    }

    rtb_Divide_ny = (rtb_Gain_m - (measure_B.VariableDiscreteDelay_imqptqte5 *
      rtb_MathFunction1 + measure_B.VariableDiscreteDela_izcmu0mrbj * rtb_Switch))
      * rtb_Switch1_k;
  }

  /* End of Switch: '<S496>/Switch3' */

  /* Bias: '<S500>/Bias' */
  rtb_Bias = rtb_MathFunction2 + measure_P.Bias_Bias_bc;

  /* Switch: '<S608>/Switch' incorporates:
   *  Constant: '<S608>/const'
   *  UnitDelay: '<S608>/Unit Delay1'
   */
  if (rtb_Compare_k1g) {
    rtb_Switch1_d = measure_DWork.UnitDelay1_DSTATE_c;
  } else {
    rtb_Switch1_d = measure_P.const_Value_n;
  }

  /* End of Switch: '<S608>/Switch' */

  /* RelationalOperator: '<S697>/Compare' incorporates:
   *  Constant: '<S697>/Constant'
   */
  rtb_Compare_go = (rtb_Switch1_d == measure_P.Constant_Value_e1g);

  /* UnitDelay: '<S692>/Unit Delay' */
  rtb_UnitDelay_j = measure_DWork.UnitDelay_DSTATE_h;

  /* RelationalOperator: '<S602>/Compare' incorporates:
   *  Constant: '<S602>/Constant'
   *  UnitDelay: '<S692>/Unit Delay'
   */
  rtb_Compare_k1g = (measure_DWork.UnitDelay_DSTATE_h <
                     measure_P.Constant_Value_i);

  /* Switch: '<S687>/Switch' incorporates:
   *  Constant: '<S687>/const'
   *  UnitDelay: '<S687>/Unit Delay1'
   */
  if (rtb_Compare_k1g) {
    rtb_Switch1_ce = measure_DWork.UnitDelay1_DSTATE_n;
  } else {
    rtb_Switch1_ce = measure_P.const_Value_ci1;
  }

  /* End of Switch: '<S687>/Switch' */

  /* RelationalOperator: '<S690>/Compare' incorporates:
   *  Constant: '<S690>/Constant'
   */
  rtb_Compare_k1 = (rtb_Switch1_ce == measure_P.Constant_Value_ci);

  /* Switch: '<S685>/Switch' incorporates:
   *  Constant: '<S685>/const'
   *  UnitDelay: '<S685>/Unit Delay1'
   */
  if (rtb_Compare_k1g) {
    rtb_UnitDelay1_k = measure_P.const_Value_ci;
  } else {
    rtb_UnitDelay1_k = measure_DWork.UnitDelay1_DSTATE_nr;
  }

  /* End of Switch: '<S685>/Switch' */

  /* RelationalOperator: '<S688>/Compare' incorporates:
   *  Constant: '<S688>/Constant'
   */
  rtb_Compare_k1g = (rtb_UnitDelay1_k == measure_P.Constant_Value_ci1);

  /* Logic: '<S686>/Logical Operator2' incorporates:
   *  Logic: '<S686>/Logical Operator'
   *  Logic: '<S686>/Logical Operator1'
   *  UnitDelay: '<S686>/Unit Delay'
   */
  rtb_LogicalOperator2_c1 = ((measure_DWork.UnitDelay_DSTATE_b || rtb_Compare_k1)
    && (!rtb_Compare_k1g));

  /* Logic: '<S496>/Logical Operator2' */
  rtb_LogicalOperator1_f = (rtb_Compare_go && rtb_LogicalOperator2_c1);

  /* S-Function "SF_FixedDiscreteDelay" Block: <S928>/SF_FixedDiscreteDelay S-function */
  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfunctio_j[0];
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_h;
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_a;
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = *xD;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfuncti_ic + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfuncti_ic;
    measure_B.SF_FixedDiscreteDelaySfunctio_i = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfuncti_ic)
      *VDD_in = 0;
  }

  /* RelationalOperator: '<S927>/Compare' incorporates:
   *  Constant: '<S927>/Constant'
   */
  rtb_Compare_eb = (measure_B.SF_FixedDiscreteDelaySfunctio_i >
                    measure_P.Constant_Value_fc);

  /* Gain: '<S623>/Gain2' incorporates:
   *  Gain: '<S633>/Gain'
   *  Sum: '<S633>/Sum2'
   *  UnitDelay: '<S633>/Unit Delay1'
   */
  rtb_Switch_l40f02 = (rtb_MathFunction2 - measure_DWork.UnitDelay1_DSTATE_m) *
    measure_P.Gain_Gain_bl * measure_P.Gain2_Gain_b;

  /* Switch: '<S638>/Switch' incorporates:
   *  Constant: '<S653>/Constant'
   *  RelationalOperator: '<S653>/Compare'
   *  UnaryMinus: '<S638>/Unary Minus'
   */
  if (rtb_Switch_l40f02 < measure_P.Constant_Value_bln4d) {
    rtb_Switch_l40f02 = -rtb_Switch_l40f02;
  }

  /* End of Switch: '<S638>/Switch' */

  /* Switch: '<S929>/Switch' incorporates:
   *  Constant: '<S637>/Constant'
   *  Constant: '<S929>/int32'
   *  Constant: '<S931>/FixPt Constant'
   *  Logic: '<S501>/Logical Operator3'
   *  RelationalOperator: '<S637>/Compare'
   *  Sum: '<S931>/FixPt Sum1'
   *  UnitDelay: '<S929>/Unit Delay'
   */
  if (rtb_Compare_eb && (rtb_Switch_l40f02 > measure_P.Constant_Value_bln4dj)) {
    rtb_Switch_jv = measure_P.int32_Value_g;
  } else {
    rtb_Switch_jv = measure_DWork.UnitDelay_DSTATE_j -
      measure_P.FixPtConstant_Value_g;
  }

  /* End of Switch: '<S929>/Switch' */

  /* RelationalOperator: '<S930>/Compare' incorporates:
   *  Constant: '<S930>/Constant'
   */
  rtb_Compare_cz = (rtb_Switch_jv > measure_P.Constant_Value_gq);

  /* Gain: '<S724>/Gain2' incorporates:
   *  Gain: '<S734>/Gain'
   *  Sum: '<S734>/Sum2'
   *  UnitDelay: '<S734>/Unit Delay1'
   */
  rtb_Switch_l40f02 = (rtb_MathFunction2_c - measure_DWork.UnitDelay1_DSTATE_g) *
    measure_P.Gain_Gain_ez * measure_P.Gain2_Gain_e;

  /* Switch: '<S739>/Switch' incorporates:
   *  Constant: '<S754>/Constant'
   *  RelationalOperator: '<S754>/Compare'
   *  UnaryMinus: '<S739>/Unary Minus'
   */
  if (rtb_Switch_l40f02 < measure_P.Constant_Value_ezncl) {
    rtb_Switch_l40f02 = -rtb_Switch_l40f02;
  }

  /* End of Switch: '<S739>/Switch' */

  /* Switch: '<S932>/Switch' incorporates:
   *  Constant: '<S738>/Constant'
   *  Constant: '<S932>/int32'
   *  Constant: '<S934>/FixPt Constant'
   *  Logic: '<S501>/Logical Operator4'
   *  RelationalOperator: '<S738>/Compare'
   *  Sum: '<S934>/FixPt Sum1'
   *  UnitDelay: '<S932>/Unit Delay'
   */
  if (rtb_Compare_eb && (rtb_Switch_l40f02 > measure_P.Constant_Value_eznclc)) {
    rtb_Switch_jvw = measure_P.int32_Value_gq;
  } else {
    rtb_Switch_jvw = measure_DWork.UnitDelay_DSTATE_jq -
      measure_P.FixPtConstant_Value_gq;
  }

  /* End of Switch: '<S932>/Switch' */

  /* RelationalOperator: '<S933>/Compare' incorporates:
   *  Constant: '<S933>/Constant'
   */
  rtb_Compare_czp = (rtb_Switch_jvw > measure_P.Constant_Value_gqo);

  /* Gain: '<S825>/Gain2' incorporates:
   *  Gain: '<S835>/Gain'
   *  Sum: '<S835>/Sum2'
   *  UnitDelay: '<S835>/Unit Delay1'
   */
  rtb_Switch_l40f02 = (rtb_MathFunction2_a - measure_DWork.UnitDelay1_DSTATE_o) *
    measure_P.Gain_Gain_e0 * measure_P.Gain2_Gain_e0;

  /* Switch: '<S840>/Switch' incorporates:
   *  Constant: '<S855>/Constant'
   *  RelationalOperator: '<S855>/Compare'
   *  UnaryMinus: '<S840>/Unary Minus'
   */
  if (rtb_Switch_l40f02 < measure_P.Constant_Value_e0r1h) {
    rtb_Switch_l40f02 = -rtb_Switch_l40f02;
  }

  /* End of Switch: '<S840>/Switch' */

  /* Switch: '<S935>/Switch' incorporates:
   *  Constant: '<S839>/Constant'
   *  Constant: '<S935>/int32'
   *  Constant: '<S937>/FixPt Constant'
   *  Logic: '<S501>/Logical Operator9'
   *  RelationalOperator: '<S839>/Compare'
   *  Sum: '<S937>/FixPt Sum1'
   *  UnitDelay: '<S935>/Unit Delay'
   */
  if (rtb_Compare_eb && (rtb_Switch_l40f02 > measure_P.Constant_Value_e0r1hm)) {
    rtb_Switch_jvwj = measure_P.int32_Value_gqo;
  } else {
    rtb_Switch_jvwj = measure_DWork.UnitDelay_DSTATE_jqs -
      measure_P.FixPtConstant_Value_gqo;
  }

  /* End of Switch: '<S935>/Switch' */

  /* RelationalOperator: '<S936>/Compare' incorporates:
   *  Constant: '<S936>/Constant'
   */
  rtb_Compare_czp1 = (rtb_Switch_jvwj > measure_P.Constant_Value_gqop);

  /* Logic: '<S501>/Logical Operator13' */
  rtb_Disturbance_All_Phases = (rtb_Compare_cz && rtb_Compare_czp &&
    rtb_Compare_czp1);

  /* Switch: '<S709>/Switch' incorporates:
   *  Constant: '<S709>/const'
   *  UnitDelay: '<S709>/Unit Delay1'
   */
  if (rtb_Compare_aun) {
    rtb_Switch1_cc = measure_DWork.UnitDelay1_DSTATE_cf;
  } else {
    rtb_Switch1_cc = measure_P.const_Value_o5;
  }

  /* End of Switch: '<S709>/Switch' */

  /* RelationalOperator: '<S798>/Compare' incorporates:
   *  Constant: '<S798>/Constant'
   */
  rtb_Compare_eb = (rtb_Switch1_cc == measure_P.Constant_Value_oh);

  /* UnitDelay: '<S793>/Unit Delay' */
  rtb_UnitDelay_n = measure_DWork.UnitDelay_DSTATE_g;

  /* RelationalOperator: '<S703>/Compare' incorporates:
   *  Constant: '<S703>/Constant'
   *  UnitDelay: '<S793>/Unit Delay'
   */
  rtb_Compare_aun = (measure_DWork.UnitDelay_DSTATE_g <
                     measure_P.Constant_Value_g1);

  /* Switch: '<S788>/Switch' incorporates:
   *  Constant: '<S788>/const'
   *  UnitDelay: '<S788>/Unit Delay1'
   */
  if (rtb_Compare_aun) {
    rtb_Switch1_ky = measure_DWork.UnitDelay1_DSTATE_e;
  } else {
    rtb_Switch1_ky = measure_P.const_Value_hg0;
  }

  /* End of Switch: '<S788>/Switch' */

  /* RelationalOperator: '<S791>/Compare' incorporates:
   *  Constant: '<S791>/Constant'
   */
  rtb_Compare_au = (rtb_Switch1_ky == measure_P.Constant_Value_hg);

  /* Switch: '<S786>/Switch' incorporates:
   *  Constant: '<S786>/const'
   *  UnitDelay: '<S786>/Unit Delay1'
   */
  if (rtb_Compare_aun) {
    rtb_Switch1_kyp = measure_P.const_Value_hg;
  } else {
    rtb_Switch1_kyp = measure_DWork.UnitDelay1_DSTATE_ep;
  }

  /* End of Switch: '<S786>/Switch' */

  /* RelationalOperator: '<S789>/Compare' incorporates:
   *  Constant: '<S789>/Constant'
   */
  rtb_Compare_aun = (rtb_Switch1_kyp == measure_P.Constant_Value_hg0);

  /* Logic: '<S787>/Logical Operator2' incorporates:
   *  Logic: '<S787>/Logical Operator'
   *  Logic: '<S787>/Logical Operator1'
   *  UnitDelay: '<S787>/Unit Delay'
   */
  rtb_LogicalOperator2_bf = ((measure_DWork.UnitDelay_DSTATE_md ||
    rtb_Compare_au) && (!rtb_Compare_aun));

  /* Logic: '<S497>/Logical Operator2' */
  rtb_LogicalOperator2_b0 = (rtb_Compare_eb && rtb_LogicalOperator2_bf);

  /* Switch: '<S810>/Switch' incorporates:
   *  Constant: '<S810>/const'
   *  UnitDelay: '<S810>/Unit Delay1'
   */
  if (rtb_Compare_o1) {
    rtb_Switch1_oi = measure_DWork.UnitDelay1_DSTATE_or;
  } else {
    rtb_Switch1_oi = measure_P.const_Value_d;
  }

  /* End of Switch: '<S810>/Switch' */

  /* RelationalOperator: '<S899>/Compare' incorporates:
   *  Constant: '<S899>/Constant'
   */
  rtb_Compare_o1 = (rtb_Switch1_oi == measure_P.Constant_Value_oyw);

  /* UnitDelay: '<S894>/Unit Delay' */
  rtb_UnitDelay_ic = measure_DWork.UnitDelay_DSTATE_d;

  /* RelationalOperator: '<S804>/Compare' incorporates:
   *  Constant: '<S804>/Constant'
   *  UnitDelay: '<S894>/Unit Delay'
   */
  rtb_Compare_ge = (measure_DWork.UnitDelay_DSTATE_d <
                    measure_P.Constant_Value_eza);

  /* Switch: '<S889>/Switch' incorporates:
   *  Constant: '<S889>/const'
   *  UnitDelay: '<S889>/Unit Delay1'
   */
  if (rtb_Compare_ge) {
    rtb_Switch1_cg = measure_DWork.UnitDelay1_DSTATE_ir;
  } else {
    rtb_Switch1_cg = measure_P.const_Value_gu;
  }

  /* End of Switch: '<S889>/Switch' */

  /* RelationalOperator: '<S892>/Compare' incorporates:
   *  Constant: '<S892>/Constant'
   */
  rtb_Compare_g = (rtb_Switch1_cg == measure_P.Constant_Value_gu);

  /* Switch: '<S887>/Switch' incorporates:
   *  Constant: '<S887>/const'
   *  UnitDelay: '<S887>/Unit Delay1'
   */
  if (rtb_Compare_ge) {
    rtb_Switch1_cgb = measure_P.const_Value_g;
  } else {
    rtb_Switch1_cgb = measure_DWork.UnitDelay1_DSTATE_irs;
  }

  /* End of Switch: '<S887>/Switch' */

  /* RelationalOperator: '<S890>/Compare' incorporates:
   *  Constant: '<S890>/Constant'
   */
  rtb_Compare_ge = (rtb_Switch1_cgb == measure_P.Constant_Value_gun);

  /* Logic: '<S888>/Logical Operator2' incorporates:
   *  Logic: '<S888>/Logical Operator'
   *  Logic: '<S888>/Logical Operator1'
   *  UnitDelay: '<S888>/Unit Delay'
   */
  rtb_LogicalOperator2_bg = ((measure_DWork.UnitDelay_DSTATE_cn || rtb_Compare_g)
    && (!rtb_Compare_ge));

  /* Logic: '<S498>/Logical Operator2' */
  rtb_LogicalOperator2_m = (rtb_Compare_o1 && rtb_LogicalOperator2_bg);

  /* Logic: '<S310>/Logical Operator6' */
  rtb_LogicalOperator12 = (rtb_LogicalOperator1_f || rtb_LogicalOperator2_b0 ||
    rtb_LogicalOperator2_m);

  /* Switch: '<S310>/Switch6' incorporates:
   *  Logic: '<S501>/Logical Operator14'
   *  Logic: '<S501>/Logical Operator15'
   *  Logic: '<S501>/Logical Operator16'
   *  Logic: '<S506>/Logical Operator1'
   *  Logic: '<S506>/Logical Operator2'
   *  Logic: '<S506>/Logical Operator5'
   */
  if (rtb_LogicalOperator12) {
    /* Logic: '<S501>/Logical Operator17' */
    rtb_Any_Phases_Not_Disturbed = !rtb_Disturbance_All_Phases;
    rtb_Switch6_idx = (rtb_LogicalOperator1_f && (!(rtb_Compare_cz &&
      rtb_Any_Phases_Not_Disturbed)));
    rtb_LogicalOperator2_b0 = (rtb_LogicalOperator2_b0 && (!(rtb_Compare_czp &&
      rtb_Any_Phases_Not_Disturbed)));
    rtb_LogicalOperator1_f = (rtb_LogicalOperator2_m && (!(rtb_Compare_czp1 &&
      rtb_Any_Phases_Not_Disturbed)));
  } else {
    rtb_Switch6_idx = rtb_Compare_ha;
    rtb_LogicalOperator2_b0 = rtb_Compare_df;
    rtb_LogicalOperator1_f = rtb_Compare_m3;
  }

  /* End of Switch: '<S310>/Switch6' */

  /* Switch: '<S509>/Switch1' incorporates:
   *  Constant: '<S509>/Constant2'
   */
  if (rtb_Switch6_idx) {
    /* Math: '<S509>/Math Function1' */
    rtb_Gain_m = rtb_Bias * rtb_Bias;

    /* Switch: '<S509>/Switch' incorporates:
     *  Constant: '<S515>/Constant'
     *  Constant: '<S518>/Constant'
     *  Math: '<S509>/Math Function'
     *  RelationalOperator: '<S515>/Compare'
     *  RelationalOperator: '<S518>/Compare'
     *  Switch: '<S516>/Switch'
     *
     * About '<S509>/Math Function':
     *  Operator: reciprocal
     */
    if (rtb_Gain_m < measure_P.Constant_Value_ookglyimv) {
      /* Switch: '<S517>/Switch' incorporates:
       *  Constant: '<S517>/Constant'
       *  Constant: '<S519>/Constant'
       *  RelationalOperator: '<S519>/Compare'
       */
      if (rtb_Gain_m < measure_P.Constant_Value_ookglyim) {
        rtb_Switch_l40f02 = measure_P.Constant_Value_ookglyi;
      } else {
        rtb_Switch_l40f02 = rtb_Gain_m;
      }

      /* End of Switch: '<S517>/Switch' */
    } else {
      if (rtb_Gain_m < measure_P.Constant_Value_ookgly) {
        /* Switch: '<S516>/Switch' incorporates:
         *  Constant: '<S516>/Constant'
         */
        rtb_Gain_m = measure_P.Constant_Value_ookgl;
      }

      rtb_Switch_l40f02 = 1.0 / rtb_Gain_m;
    }

    /* End of Switch: '<S509>/Switch' */
  } else {
    rtb_Switch_l40f02 = measure_P.Constant2_Value;
  }

  /* End of Switch: '<S509>/Switch1' */

  /* Product: '<S492>/Product' */
  rtb_Product_i = rtb_Divide_ny * rtb_Switch_l40f02;

  /* Logic: '<S310>/Logical Operator18' incorporates:
   *  Logic: '<S310>/Logical Operator20'
   */
  rtb_LogicalOperator1_bbcu = (rtb_Compare_mp || (!(rtb_Compare_df ||
    rtb_LogicalOperator9)));

  /* UnitDelay: '<S701>/Unit Delay3' */
  rtb_Gain_m = measure_DWork.UnitDelay3_DSTATE_pz;

  /* Switch: '<S767>/Switch' incorporates:
   *  Constant: '<S767>/double'
   *  Sum: '<S767>/Sum2'
   *  UnitDelay: '<S767>/Unit Delay2'
   *  UnitDelay: '<S767>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_dh3io = measure_P.double_Value_eznclc5xg5;
  } else {
    measure_B.Switch_dh3io = (measure_B.Divide_ny +
      measure_DWork.UnitDelay4_DSTATE_e10ck) +
      measure_DWork.UnitDelay2_DSTATE_abju3r;
  }

  /* End of Switch: '<S767>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S764>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_bgs;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3io;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywit_eznclc) Offset = measure_P.VariableDiscreteDelaywit_eznclc;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_eznclc;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_op = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_eznclc)
      *VDD_in = 0;
  }

  /* Switch: '<S768>/Switch' incorporates:
   *  Constant: '<S768>/double'
   *  Sum: '<S768>/Sum2'
   *  UnitDelay: '<S768>/Unit Delay2'
   *  UnitDelay: '<S768>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_dh3ioo = measure_P.double_Value_eznclc5xg5q;
  } else {
    measure_B.Switch_dh3ioo = (measure_B.Divide_ny +
      measure_DWork.UnitDelay4_DSTATE_e10ck0) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc;
  }

  /* End of Switch: '<S768>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S765>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c1[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_cv;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioo;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywi_eznclc5) Offset = measure_P.VariableDiscreteDelaywi_eznclc5;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_eznclc5;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_g = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_eznclc5)
      *VDD_in = 0;
  }

  /* Switch: '<S756>/Switch1' incorporates:
   *  Sum: '<S756>/Sum1'
   *  Sum: '<S756>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Divide_ny = measure_B.Switch_dh3io - measure_B.VariableDiscret_op;
  } else {
    rtb_Divide_ny = measure_B.Switch_dh3ioo - measure_B.VariableDiscret_g;
  }

  /* End of Switch: '<S756>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S769>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_ab4s3qlk5c[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_oci4cw4vlo;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide_ny;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithT_eznc) Offset = measure_P.VariableDiscreteDelaywithT_eznc;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_eznc;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDela_imqptqte5f = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithT_eznc)
      measure_B.VariableDiscreteDel_izcmu0mrbjz = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDel_izcmu0mrbjz = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_eznc)
      *VDD_in = 0;
  }

  /* Product: '<S766>/Divide' incorporates:
   *  Product: '<S766>/Product'
   *  Product: '<S766>/Product1'
   *  Sum: '<S766>/Sum1'
   *  Sum: '<S766>/Sum7'
   */
  rtb_Divide_ny = (rtb_Divide_ny - (measure_B.VariableDiscreteDela_imqptqte5f *
    rtb_Subtract3_c04 + measure_B.VariableDiscreteDel_izcmu0mrbjz *
    rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Switch: '<S761>/Switch' incorporates:
   *  Constant: '<S761>/double'
   *  Sum: '<S761>/Sum2'
   *  UnitDelay: '<S761>/Unit Delay2'
   *  UnitDelay: '<S761>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_dh3ioos = measure_P.double_Value_eznclc5x;
  } else {
    measure_B.Switch_dh3ioos = (measure_B.Divide_n +
      measure_DWork.UnitDelay4_DSTATE_e10ck0c) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3;
  }

  /* End of Switch: '<S761>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S758>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gf[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_j3;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioos;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelayw_eznclc5x) Offset = measure_P.VariableDiscreteDelayw_eznclc5x;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_eznclc5x;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_d = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_eznclc5x)
      *VDD_in = 0;
  }

  /* Switch: '<S762>/Switch' incorporates:
   *  Constant: '<S762>/double'
   *  Sum: '<S762>/Sum2'
   *  UnitDelay: '<S762>/Unit Delay2'
   *  UnitDelay: '<S762>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_dh3ioosv = measure_P.double_Value_eznclc5xg;
  } else {
    measure_B.Switch_dh3ioosv = (measure_B.Divide_n +
      measure_DWork.UnitDelay4_DSTATE_e10ck0ct) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3x;
  }

  /* End of Switch: '<S762>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S759>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_p[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_fr;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioosv;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelay_eznclc5xg) Offset = measure_P.VariableDiscreteDelay_eznclc5xg;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_eznclc5xg;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_k = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_eznclc5xg)
      *VDD_in = 0;
  }

  /* Switch: '<S755>/Switch1' incorporates:
   *  Sum: '<S755>/Sum1'
   *  Sum: '<S755>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Divide_n = measure_B.Switch_dh3ioos - measure_B.VariableDiscret_d;
  } else {
    rtb_Divide_n = measure_B.Switch_dh3ioosv - measure_B.VariableDiscret_k;
  }

  /* End of Switch: '<S755>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S763>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_ab4s3qlk5cc[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_oci4cw4vloz;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide_n;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDela_eznclc5xg5) Offset = measure_P.VariableDiscreteDela_eznclc5xg5;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_eznclc5xg5;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDel_imqptqte5f3 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDela_eznclc5xg5)
      measure_B.VariableDiscreteDe_izcmu0mrbjza = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDe_izcmu0mrbjza = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_eznclc5xg5)
      *VDD_in = 0;
  }

  /* Product: '<S760>/Divide' incorporates:
   *  Product: '<S760>/Product'
   *  Product: '<S760>/Product1'
   *  Sum: '<S760>/Sum1'
   *  Sum: '<S760>/Sum7'
   */
  rtb_Divide_n = (rtb_Divide_n - (measure_B.VariableDiscreteDel_imqptqte5f3 *
    rtb_Subtract3_c04 + measure_B.VariableDiscreteDe_izcmu0mrbjza *
    rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Trigonometry: '<S770>/Trigonometric Function' */
  rtb_TrigonometricFunction_c = atan2(rtb_Divide_ny, rtb_Divide_n);

  /* Sum: '<S497>/Add' */
  rtb_Add_o = rtb_TrigonometricFunction_c + rtb_Sum;

  /* Switch: '<S497>/Switch6' */
  if (rtb_LogicalOperator1_bbcu) {
    measure_B.Switch6_n = rtb_Switch4;
  } else {
    /* Sum: '<S701>/Sum2' */
    rtb_Gain_m = rtb_Add_o - rtb_Gain_m;

    /* Switch: '<S714>/Switch1' incorporates:
     *  Bias: '<S714>/Bias1'
     *  Constant: '<S715>/Constant'
     *  Constant: '<S716>/Constant'
     *  RelationalOperator: '<S715>/Compare'
     *  RelationalOperator: '<S716>/Compare'
     *  Switch: '<S714>/Switch'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_coy) {
      rtb_Gain_m += measure_P.Bias1_Bias_co;
    } else {
      if (rtb_Gain_m > measure_P.Constant_Value_co) {
        /* Switch: '<S714>/Switch' incorporates:
         *  Bias: '<S714>/Bias'
         */
        rtb_Gain_m += measure_P.Bias_Bias_co;
      }
    }

    /* End of Switch: '<S714>/Switch1' */

    /* Gain: '<S701>/Gain' */
    rtb_Gain_m *= measure_P.Gain_Gain_c;

    /* Switch: '<S707>/Switch' incorporates:
     *  Constant: '<S707>/Constant'
     *  Constant: '<S794>/Constant'
     *  Constant: '<S795>/Constant'
     *  RelationalOperator: '<S794>/Compare'
     *  RelationalOperator: '<S795>/Compare'
     *  Switch: '<S707>/Switch1'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_kp) {
      measure_B.Switch6_n = measure_P.Constant_Value_kg;
    } else if (rtb_Gain_m > measure_P.Constant_Value_kh) {
      /* Switch: '<S707>/Switch1' incorporates:
       *  Constant: '<S707>/Constant1'
       */
      measure_B.Switch6_n = measure_P.Constant1_Value_mw;
    } else {
      measure_B.Switch6_n = rtb_Gain_m;
    }

    /* End of Switch: '<S707>/Switch' */
  }

  /* End of Switch: '<S497>/Switch6' */

  /* Switch: '<S720>/Switch' incorporates:
   *  Constant: '<S720>/double'
   *  Sum: '<S720>/Sum2'
   *  UnitDelay: '<S720>/Unit Delay2'
   *  UnitDelay: '<S720>/Unit Delay4'
   */
  if (rtb_Compare_k5) {
    measure_B.Switch_iu = measure_P.double_Value_fj;
  } else {
    measure_B.Switch_iu = (measure_B.Switch6_n +
      measure_DWork.UnitDelay4_DSTATE_b) + measure_DWork.UnitDelay2_DSTATE_k;
  }

  /* End of Switch: '<S720>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S717>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_cr[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ny;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_iu;

    /*    Offset = measure_B.Switch2_hhsca5;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOne_h0) Offset = measure_P.VariableDiscreteDelaywithOne_h0;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_h0;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_j = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_h0)
      *VDD_in = 0;
  }

  /* Switch: '<S721>/Switch' incorporates:
   *  Constant: '<S721>/double'
   *  Sum: '<S721>/Sum2'
   *  UnitDelay: '<S721>/Unit Delay2'
   *  UnitDelay: '<S721>/Unit Delay4'
   */
  if (rtb_LogicalOperator_ot) {
    measure_B.Switch_iua = measure_P.double_Value_fjq;
  } else {
    measure_B.Switch_iua = (measure_B.Switch6_n +
      measure_DWork.UnitDelay4_DSTATE_bc) + measure_DWork.UnitDelay2_DSTATE_k1;
  }

  /* End of Switch: '<S721>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S718>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_e[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_gs3;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_iua;

    /*    Offset = measure_B.Switch2_hhsca5;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOn_h0u) Offset = measure_P.VariableDiscreteDelaywithOn_h0u;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_h0u;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_f = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_h0u)
      *VDD_in = 0;
  }

  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S722>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_ab4s3qlk5cc4[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_oci4cw4vloz5;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch6_n;

    /*    Offset = measure_B.Switch2_hhsca5;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwoT_p) Offset = measure_P.VariableDiscreteDelaywithTwoT_p;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_p;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDe_imqptqte5f3c = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_p)
      measure_B.VariableDiscreteD_izcmu0mrbjzal = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteD_izcmu0mrbjzal = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_p)
      *VDD_in = 0;
  }

  /* Switch: '<S497>/Switch3' incorporates:
   *  Product: '<S719>/Divide'
   *  Product: '<S719>/Product'
   *  Product: '<S719>/Product1'
   *  Sum: '<S719>/Sum1'
   *  Sum: '<S719>/Sum7'
   *  Switch: '<S702>/Switch1'
   */
  if (rtb_LogicalOperator1_bbcu) {
    rtb_Divide_jw = rtb_Switch4;
  } else {
    if (rtb_Compare_oafgue) {
      /* Switch: '<S702>/Switch1' incorporates:
       *  Sum: '<S702>/Sum2'
       */
      rtb_Gain_m = measure_B.Switch_iu - measure_B.VariableDiscret_j;
    } else {
      /* Switch: '<S702>/Switch1' incorporates:
       *  Sum: '<S702>/Sum1'
       */
      rtb_Gain_m = measure_B.Switch_iua - measure_B.VariableDiscret_f;
    }

    rtb_Divide_jw = (rtb_Gain_m - (measure_B.VariableDiscreteDe_imqptqte5f3c *
      rtb_MathFunction1 + measure_B.VariableDiscreteD_izcmu0mrbjzal * rtb_Switch))
      * rtb_Switch1_k;
  }

  /* End of Switch: '<S497>/Switch3' */

  /* Bias: '<S500>/Bias1' */
  rtb_Bias1 = rtb_MathFunction2_c + measure_P.Bias1_Bias_dv;

  /* Switch: '<S510>/Switch1' incorporates:
   *  Constant: '<S510>/Constant2'
   */
  if (rtb_LogicalOperator2_b0) {
    /* Math: '<S510>/Math Function1' */
    rtb_Gain_m = rtb_Bias1 * rtb_Bias1;

    /* Switch: '<S510>/Switch' incorporates:
     *  Constant: '<S520>/Constant'
     *  Constant: '<S523>/Constant'
     *  Math: '<S510>/Math Function'
     *  RelationalOperator: '<S520>/Compare'
     *  RelationalOperator: '<S523>/Compare'
     *  Switch: '<S521>/Switch'
     *
     * About '<S510>/Math Function':
     *  Operator: reciprocal
     */
    if (rtb_Gain_m < measure_P.Constant_Value_ookglyimven12a) {
      /* Switch: '<S522>/Switch' incorporates:
       *  Constant: '<S522>/Constant'
       *  Constant: '<S524>/Constant'
       *  RelationalOperator: '<S524>/Compare'
       */
      if (rtb_Gain_m < measure_P.Constant_Value_ookglyimven12) {
        rtb_Switch_l40f = measure_P.Constant_Value_ookglyimven1;
      } else {
        rtb_Switch_l40f = rtb_Gain_m;
      }

      /* End of Switch: '<S522>/Switch' */
    } else {
      if (rtb_Gain_m < measure_P.Constant_Value_ookglyimven) {
        /* Switch: '<S521>/Switch' incorporates:
         *  Constant: '<S521>/Constant'
         */
        rtb_Gain_m = measure_P.Constant_Value_ookglyimve;
      }

      rtb_Switch_l40f = 1.0 / rtb_Gain_m;
    }

    /* End of Switch: '<S510>/Switch' */
  } else {
    rtb_Switch_l40f = measure_P.Constant2_Value_o;
  }

  /* End of Switch: '<S510>/Switch1' */

  /* Product: '<S492>/Product1' */
  rtb_Switch1_kt5c = rtb_Divide_jw * rtb_Switch_l40f;

  /* Logic: '<S310>/Logical Operator15' incorporates:
   *  Logic: '<S310>/Logical Operator16'
   */
  rtb_Compare_mp = (rtb_Compare_mp || (!(rtb_Compare_m3 || rtb_LogicalOperator9)));

  /* UnitDelay: '<S802>/Unit Delay3' */
  rtb_Gain_m = measure_DWork.UnitDelay3_DSTATE_o;

  /* Switch: '<S868>/Switch' incorporates:
   *  Constant: '<S868>/double'
   *  Sum: '<S868>/Sum2'
   *  UnitDelay: '<S868>/Unit Delay2'
   *  UnitDelay: '<S868>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_p0ny3 = measure_P.double_Value_e0r1hmwtwq;
  } else {
    measure_B.Switch_p0ny3 = (measure_B.Divide_jw +
      measure_DWork.UnitDelay4_DSTATE_otwsj) +
      measure_DWork.UnitDelay2_DSTATE_gllvy;
  }

  /* End of Switch: '<S868>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S865>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_b[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_lz;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywit_e0r1hm) Offset = measure_P.VariableDiscreteDelaywit_e0r1hm;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_e0r1hm;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_k3 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_e0r1hm)
      *VDD_in = 0;
  }

  /* Switch: '<S869>/Switch' incorporates:
   *  Constant: '<S869>/double'
   *  Sum: '<S869>/Sum2'
   *  UnitDelay: '<S869>/Unit Delay2'
   *  UnitDelay: '<S869>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_p0ny3p = measure_P.double_Value_e0r1hmwtwqc;
  } else {
    measure_B.Switch_p0ny3p = (measure_B.Divide_jw +
      measure_DWork.UnitDelay4_DSTATE_otwsjg) +
      measure_DWork.UnitDelay2_DSTATE_gllvyy;
  }

  /* End of Switch: '<S869>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S866>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_n[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_jl;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3p;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywi_e0r1hmw) Offset = measure_P.VariableDiscreteDelaywi_e0r1hmw;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_e0r1hmw;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_e = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_e0r1hmw)
      *VDD_in = 0;
  }

  /* Switch: '<S857>/Switch1' incorporates:
   *  Sum: '<S857>/Sum1'
   *  Sum: '<S857>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Divide_jw = measure_B.Switch_p0ny3 - measure_B.VariableDiscret_k3;
  } else {
    rtb_Divide_jw = measure_B.Switch_p0ny3p - measure_B.VariableDiscret_e;
  }

  /* End of Switch: '<S857>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S870>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_ab4s3qlk5cc4j[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_oci4cw4vloz5b;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide_jw;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithT_e0r1) Offset = measure_P.VariableDiscreteDelaywithT_e0r1;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_e0r1;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteD_imqptqte5f3cu = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithT_e0r1)
      measure_B.VariableDiscrete_izcmu0mrbjzali = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscrete_izcmu0mrbjzali = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_e0r1)
      *VDD_in = 0;
  }

  /* Product: '<S867>/Divide' incorporates:
   *  Product: '<S867>/Product'
   *  Product: '<S867>/Product1'
   *  Sum: '<S867>/Sum1'
   *  Sum: '<S867>/Sum7'
   */
  rtb_Divide_jw = (rtb_Divide_jw - (measure_B.VariableDiscreteD_imqptqte5f3cu *
    rtb_Subtract3_c04 + measure_B.VariableDiscrete_izcmu0mrbjzali *
    rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Switch: '<S862>/Switch' incorporates:
   *  Constant: '<S862>/double'
   *  Sum: '<S862>/Sum2'
   *  UnitDelay: '<S862>/Unit Delay2'
   *  UnitDelay: '<S862>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_p0ny3pk = measure_P.double_Value_e0r1hmwt;
  } else {
    measure_B.Switch_p0ny3pk = (measure_B.Divide_j +
      measure_DWork.UnitDelay4_DSTATE_otwsjge) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya;
  }

  /* End of Switch: '<S862>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S859>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gp[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ev;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pk;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelayw_e0r1hmwt) Offset = measure_P.VariableDiscreteDelayw_e0r1hmwt;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_e0r1hmwt;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_fz = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_e0r1hmwt)
      *VDD_in = 0;
  }

  /* Switch: '<S863>/Switch' incorporates:
   *  Constant: '<S863>/double'
   *  Sum: '<S863>/Sum2'
   *  UnitDelay: '<S863>/Unit Delay2'
   *  UnitDelay: '<S863>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_p0ny3pkq = measure_P.double_Value_e0r1hmwtw;
  } else {
    measure_B.Switch_p0ny3pkq = (measure_B.Divide_j +
      measure_DWork.UnitDelay4_DSTATE_otwsjget) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya5;
  }

  /* End of Switch: '<S863>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S860>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_i[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_edt;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pkq;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelay_e0r1hmwtw) Offset = measure_P.VariableDiscreteDelay_e0r1hmwtw;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_e0r1hmwtw;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_fv = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_e0r1hmwtw)
      *VDD_in = 0;
  }

  /* Switch: '<S856>/Switch1' incorporates:
   *  Sum: '<S856>/Sum1'
   *  Sum: '<S856>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Divide_j = measure_B.Switch_p0ny3pk - measure_B.VariableDiscret_fz;
  } else {
    rtb_Divide_j = measure_B.Switch_p0ny3pkq - measure_B.VariableDiscret_fv;
  }

  /* End of Switch: '<S856>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S864>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_ab4s3qlk5cc4jf[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscrete_oci4cw4vloz5bs;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide_j;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDela_e0r1hmwtwq) Offset = measure_P.VariableDiscreteDela_e0r1hmwtwq;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_e0r1hmwtwq;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscrete_imqptqte5f3cur = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDela_e0r1hmwtwq)
      measure_B.VariableDiscret_izcmu0mrbjzalib = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_izcmu0mrbjzalib = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_e0r1hmwtwq)
      *VDD_in = 0;
  }

  /* Product: '<S861>/Divide' incorporates:
   *  Product: '<S861>/Product'
   *  Product: '<S861>/Product1'
   *  Sum: '<S861>/Sum1'
   *  Sum: '<S861>/Sum7'
   */
  rtb_Divide_j = (rtb_Divide_j - (measure_B.VariableDiscrete_imqptqte5f3cur *
    rtb_Subtract3_c04 + measure_B.VariableDiscret_izcmu0mrbjzalib *
    rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Trigonometry: '<S871>/Trigonometric Function' */
  rtb_TrigonometricFunction_b = atan2(rtb_Divide_jw, rtb_Divide_j);

  /* Sum: '<S498>/Add' */
  rtb_Add_h = rtb_TrigonometricFunction_b + rtb_Sum;

  /* Switch: '<S498>/Switch6' */
  if (rtb_Compare_mp) {
    measure_B.Switch6_a = rtb_Switch4;
  } else {
    /* Sum: '<S802>/Sum2' */
    rtb_Gain_m = rtb_Add_h - rtb_Gain_m;

    /* Switch: '<S815>/Switch1' incorporates:
     *  Bias: '<S815>/Bias1'
     *  Constant: '<S816>/Constant'
     *  Constant: '<S817>/Constant'
     *  RelationalOperator: '<S816>/Compare'
     *  RelationalOperator: '<S817>/Compare'
     *  Switch: '<S815>/Switch'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_fgl) {
      rtb_Gain_m += measure_P.Bias1_Bias_f;
    } else {
      if (rtb_Gain_m > measure_P.Constant_Value_fg) {
        /* Switch: '<S815>/Switch' incorporates:
         *  Bias: '<S815>/Bias'
         */
        rtb_Gain_m += measure_P.Bias_Bias_f;
      }
    }

    /* End of Switch: '<S815>/Switch1' */

    /* Gain: '<S802>/Gain' */
    rtb_Gain_m *= measure_P.Gain_Gain_f;

    /* Switch: '<S808>/Switch' incorporates:
     *  Constant: '<S808>/Constant'
     *  Constant: '<S895>/Constant'
     *  Constant: '<S896>/Constant'
     *  RelationalOperator: '<S895>/Compare'
     *  RelationalOperator: '<S896>/Compare'
     *  Switch: '<S808>/Switch1'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_nv) {
      measure_B.Switch6_a = measure_P.Constant_Value_a4;
    } else if (rtb_Gain_m > measure_P.Constant_Value_j) {
      /* Switch: '<S808>/Switch1' incorporates:
       *  Constant: '<S808>/Constant1'
       */
      measure_B.Switch6_a = measure_P.Constant1_Value_ob;
    } else {
      measure_B.Switch6_a = rtb_Gain_m;
    }

    /* End of Switch: '<S808>/Switch' */
  }

  /* End of Switch: '<S498>/Switch6' */

  /* Switch: '<S821>/Switch' incorporates:
   *  Constant: '<S821>/double'
   *  Sum: '<S821>/Sum2'
   *  UnitDelay: '<S821>/Unit Delay2'
   *  UnitDelay: '<S821>/Unit Delay4'
   */
  if (rtb_Compare_k5) {
    measure_B.Switch_ja = measure_P.double_Value_g0;
  } else {
    measure_B.Switch_ja = (measure_B.Switch6_a +
      measure_DWork.UnitDelay4_DSTATE_kw) + measure_DWork.UnitDelay2_DSTATE_o;
  }

  /* End of Switch: '<S821>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S818>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_jh;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ja;

    /*    Offset = measure_B.Switch2_hhsca5;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOneT_m) Offset = measure_P.VariableDiscreteDelaywithOneT_m;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_m;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_a = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_m)
      *VDD_in = 0;
  }

  /* Switch: '<S822>/Switch' incorporates:
   *  Constant: '<S822>/double'
   *  Sum: '<S822>/Sum2'
   *  UnitDelay: '<S822>/Unit Delay2'
   *  UnitDelay: '<S822>/Unit Delay4'
   */
  if (rtb_LogicalOperator_ot) {
    measure_B.Switch_jag = measure_P.double_Value_g0w;
  } else {
    measure_B.Switch_jag = (measure_B.Switch6_a +
      measure_DWork.UnitDelay4_DSTATE_kwr) + measure_DWork.UnitDelay2_DSTATE_o2;
  }

  /* End of Switch: '<S822>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S819>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_mm[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_bm;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_jag;

    /*    Offset = measure_B.Switch2_hhsca5;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOne_mo) Offset = measure_P.VariableDiscreteDelaywithOne_mo;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_mo;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_f1 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_mo)
      *VDD_in = 0;
  }

  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S823>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ab4s3qlk5cc4jfr[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_oci4cw4vloz5bse;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch6_a;

    /*    Offset = measure_B.Switch2_hhsca5;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwo_en) Offset = measure_P.VariableDiscreteDelaywithTwo_en;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_en;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_imqptqte5f3curu = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_en)
      measure_B.VariableDiscret_h = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_h = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_en)
      *VDD_in = 0;
  }

  /* Switch: '<S498>/Switch3' incorporates:
   *  Product: '<S820>/Divide'
   *  Product: '<S820>/Product'
   *  Product: '<S820>/Product1'
   *  Sum: '<S820>/Sum1'
   *  Sum: '<S820>/Sum7'
   */
  if (!rtb_Compare_mp) {
    /* Switch: '<S803>/Switch1' incorporates:
     *  Sum: '<S803>/Sum1'
     *  Sum: '<S803>/Sum2'
     */
    if (rtb_Compare_oafgue) {
      rtb_Gain_m = measure_B.Switch_ja - measure_B.VariableDiscret_a;
    } else {
      rtb_Gain_m = measure_B.Switch_jag - measure_B.VariableDiscret_f1;
    }

    /* End of Switch: '<S803>/Switch1' */
    rtb_Switch4 = (rtb_Gain_m - (measure_B.VariableDiscret_imqptqte5f3curu *
      rtb_MathFunction1 + measure_B.VariableDiscret_h * rtb_Switch)) *
      rtb_Switch1_k;
  }

  /* End of Switch: '<S498>/Switch3' */

  /* Bias: '<S500>/Bias2' */
  rtb_Bias2 = rtb_MathFunction2_a + measure_P.Bias2_Bias;

  /* Switch: '<S511>/Switch1' incorporates:
   *  Constant: '<S511>/Constant2'
   */
  if (rtb_LogicalOperator1_f) {
    /* Math: '<S511>/Math Function1' */
    rtb_Gain_m = rtb_Bias2 * rtb_Bias2;

    /* Switch: '<S511>/Switch' incorporates:
     *  Constant: '<S525>/Constant'
     *  Constant: '<S528>/Constant'
     *  Math: '<S511>/Math Function'
     *  RelationalOperator: '<S525>/Compare'
     *  RelationalOperator: '<S528>/Compare'
     *  Switch: '<S526>/Switch'
     *
     * About '<S511>/Math Function':
     *  Operator: reciprocal
     */
    if (rtb_Gain_m < measure_P.Constant_Value_k1) {
      /* Switch: '<S527>/Switch' incorporates:
       *  Constant: '<S527>/Constant'
       *  Constant: '<S529>/Constant'
       *  RelationalOperator: '<S529>/Compare'
       */
      if (rtb_Gain_m < measure_P.Constant_Value_b4) {
        rtb_Switch_l4 = measure_P.Constant_Value_oa;
      } else {
        rtb_Switch_l4 = rtb_Gain_m;
      }

      /* End of Switch: '<S527>/Switch' */
    } else {
      if (rtb_Gain_m < measure_P.Constant_Value_md) {
        /* Switch: '<S526>/Switch' incorporates:
         *  Constant: '<S526>/Constant'
         */
        rtb_Gain_m = measure_P.Constant_Value_ookglyimven12av;
      }

      rtb_Switch_l4 = 1.0 / rtb_Gain_m;
    }

    /* End of Switch: '<S511>/Switch' */
  } else {
    rtb_Switch_l4 = measure_P.Constant2_Value_oo;
  }

  /* End of Switch: '<S511>/Switch1' */

  /* Sum: '<S492>/Add2' */
  rtb_Switch_l40f02 += rtb_Switch_l40f;
  rtb_Switch_l40f02 += rtb_Switch_l4;

  /* Switch: '<S507>/Switch' incorporates:
   *  Constant: '<S507>/Constant'
   *  Constant: '<S512>/Constant'
   *  RelationalOperator: '<S512>/Compare'
   */
  if (rtb_Switch_l40f02 < measure_P.Constant_Value_dz) {
    rtb_Switch_l40f02 = measure_P.Constant_Value_oo;
  }

  /* End of Switch: '<S507>/Switch' */

  /* Product: '<S492>/Divide' incorporates:
   *  Product: '<S492>/Product2'
   *  Sum: '<S492>/Add1'
   */
  rtb_Gain_m = ((rtb_Product_i + rtb_Switch1_kt5c) + rtb_Switch4 * rtb_Switch_l4)
    / rtb_Switch_l40f02;

  /* Switch: '<S508>/Switch' incorporates:
   *  Constant: '<S508>/Constant'
   *  Constant: '<S513>/Constant'
   *  Constant: '<S514>/Constant'
   *  RelationalOperator: '<S513>/Compare'
   *  RelationalOperator: '<S514>/Compare'
   *  Switch: '<S508>/Switch1'
   */
  if (rtb_Gain_m < measure_P.Constant_Value_oj) {
    measure_B.Switch_l = measure_P.Constant_Value_ookg;
  } else if (rtb_Gain_m > measure_P.Constant_Value_ook) {
    /* Switch: '<S508>/Switch1' incorporates:
     *  Constant: '<S508>/Constant1'
     */
    measure_B.Switch_l = measure_P.Constant1_Value_o;
  } else {
    measure_B.Switch_l = rtb_Gain_m;
  }

  /* End of Switch: '<S508>/Switch' */

  /* DiscretePulseGenerator: '<S987>/Pulse Generator1' */
  rtb_Switch_l4 = ((real_T)measure_DWork.clockTickCounter_ed <
                   measure_P.PulseGenerator1_Duty_d) &&
    (measure_DWork.clockTickCounter_ed >= 0) ? measure_P.PulseGenerator1_Amp_d :
    0.0;
  if ((real_T)measure_DWork.clockTickCounter_ed >=
      measure_P.PulseGenerator1_Period_d - 1.0) {
    measure_DWork.clockTickCounter_ed = 0;
  } else {
    measure_DWork.clockTickCounter_ed = measure_DWork.clockTickCounter_ed + 1;
  }

  /* End of DiscretePulseGenerator: '<S987>/Pulse Generator1' */

  /* RelationalOperator: '<S993>/Compare' incorporates:
   *  Constant: '<S993>/Constant'
   */
  rtb_Switch6_idx = (rtb_Switch_l4 > measure_P.Constant_Value_da);

  /* Logic: '<S991>/Logical Operator1' incorporates:
   *  Logic: '<S991>/Logical Operator2'
   *  UnitDelay: '<S991>/delay1'
   */
  rtb_LogicalOperator1_bbcu = ((!rtb_Switch6_idx) &&
    measure_DWork.delay1_DSTATE_g);

  /* Switch: '<S962>/Switch' incorporates:
   *  Constant: '<S962>/double'
   *  Sum: '<S962>/Sum2'
   *  UnitDelay: '<S962>/Unit Delay2'
   *  UnitDelay: '<S962>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_bbcu) {
    measure_B.Switch_il = measure_P.double_Value_ii;
  } else {
    measure_B.Switch_il = (measure_B.Switch_l +
      measure_DWork.UnitDelay4_DSTATE_c) + measure_DWork.UnitDelay2_DSTATE_d;
  }

  /* End of Switch: '<S962>/Switch' */

  /* Switch: '<S988>/Switch' incorporates:
   *  Constant: '<S988>/Constant'
   *  Constant: '<S994>/Constant'
   *  Constant: '<S995>/Constant'
   *  RelationalOperator: '<S994>/Compare'
   *  RelationalOperator: '<S995>/Compare'
   *  Switch: '<S988>/Switch1'
   *  UnitDelay: '<S503>/Unit Delay2'
   */
  if (measure_DWork.UnitDelay2_DSTATE_aj < measure_P.Constant_Value_cjwa) {
    rtb_Switch_l4 = measure_P.Constant_Value_cjw;
  } else if (measure_DWork.UnitDelay2_DSTATE_aj > measure_P.Constant_Value_cj) {
    /* Switch: '<S988>/Switch1' incorporates:
     *  Constant: '<S988>/Constant1'
     */
    rtb_Switch_l4 = measure_P.Constant1_Value_c;
  } else {
    rtb_Switch_l4 = measure_DWork.UnitDelay2_DSTATE_aj;
  }

  /* End of Switch: '<S988>/Switch' */

  /* Gain: '<S989>/Gain' */
  rtb_Gain_m = measure_P.Gain_Gain_p * rtb_Switch_l4;

  /* Switch: '<S996>/Switch2' incorporates:
   *  Bias: '<S996>/Bias1'
   *  Constant: '<S999>/Constant'
   *  RelationalOperator: '<S999>/Compare'
   *  Switch: '<S996>/Switch1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_f = rtb_Gain_m + measure_P.Bias1_Bias_p;
  } else if (rtb_Gain_m < measure_P.Constant_Value_pf) {
    /* Switch: '<S996>/Switch1' */
    measure_B.Switch2_f = rtb_Gain_m;
  } else {
    /* Switch: '<S996>/Switch1' incorporates:
     *  Bias: '<S996>/Bias'
     */
    measure_B.Switch2_f = rtb_Gain_m + measure_P.Bias_Bias_p;
  }

  /* End of Switch: '<S996>/Switch2' */
  /* S-Function "SF_Cast_double_to_int32" Block: <S996>/S-Function */
  {
    measure_B.SFunction_n = (int)measure_B.Switch2_f;
  }

  /* Switch: '<S997>/Switch2' incorporates:
   *  Constant: '<S1000>/Constant'
   *  Constant: '<S1001>/Constant'
   *  Constant: '<S997>/Constant'
   *  RelationalOperator: '<S1000>/Compare'
   *  RelationalOperator: '<S1001>/Compare'
   *  Switch: '<S997>/Switch3'
   */
  if (measure_B.SFunction_n < measure_P.Constant_Value_pfgws) {
    measure_B.Switch2_f4 = measure_P.Constant_Value_pfgw;
  } else if (measure_B.SFunction_n > measure_P.Constant_Value_pfg) {
    /* Switch: '<S997>/Switch3' incorporates:
     *  Constant: '<S997>/Constant3'
     */
    measure_B.Switch2_f4 = measure_P.Constant3_Value_p;
  } else {
    measure_B.Switch2_f4 = measure_B.SFunction_n;
  }

  /* End of Switch: '<S997>/Switch2' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S959>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_p[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOneT_c;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_il;

    /*    Offset = measure_B.Switch2_f4;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOneT_i) Offset = measure_P.VariableDiscreteDelaywithOneT_i;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_i;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_d = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_i)
      *VDD_in = 0;
  }

  /* Logic: '<S990>/Logical Operator' incorporates:
   *  Logic: '<S990>/Logical Operator1'
   *  UnitDelay: '<S990>/delay'
   */
  rtb_LogicalOperator_ot = (rtb_Switch6_idx && (!measure_DWork.delay_DSTATE_h));

  /* Switch: '<S963>/Switch' incorporates:
   *  Constant: '<S963>/double'
   *  Sum: '<S963>/Sum2'
   *  UnitDelay: '<S963>/Unit Delay2'
   *  UnitDelay: '<S963>/Unit Delay4'
   */
  if (rtb_LogicalOperator_ot) {
    measure_B.Switch_iln = measure_P.double_Value_ii1;
  } else {
    measure_B.Switch_iln = (measure_B.Switch_l +
      measure_DWork.UnitDelay4_DSTATE_cv) + measure_DWork.UnitDelay2_DSTATE_dg;
  }

  /* End of Switch: '<S963>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S960>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_pb[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_cj;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_iln;

    /*    Offset = measure_B.Switch2_f4;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOne_ii) Offset = measure_P.VariableDiscreteDelaywithOne_ii;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_ii;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_dr = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_ii)
      *VDD_in = 0;
  }

  /* Switch: '<S947>/Switch1' incorporates:
   *  Sum: '<S947>/Sum1'
   *  Sum: '<S947>/Sum2'
   */
  if (rtb_Switch6_idx) {
    rtb_Switch_l40f = measure_B.Switch_il -
      measure_B.VariableDiscreteDelaywithOneT_d;
  } else {
    rtb_Switch_l40f = measure_B.Switch_iln -
      measure_B.VariableDiscreteDelaywithOne_dr;
  }

  /* End of Switch: '<S947>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S964>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_g[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_os;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_l;

    /*    Offset = measure_B.Switch2_f4;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwoT_i) Offset = measure_P.VariableDiscreteDelaywithTwoT_i;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_i;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoT_o = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_i)
      measure_B.VariableDiscreteDelaywithTwo_i4 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwo_i4 = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_i)
      *VDD_in = 0;
  }

  /* Sum: '<S989>/Subtract1' incorporates:
   *  DataTypeConversion: '<S998>/Data Type Conversion'
   */
  rtb_Switch_l40f02 = (real_T)measure_B.Switch2_f4 - rtb_Gain_m;

  /* Math: '<S989>/Math Function' */
  rtb_Switch4 = rtb_Switch_l40f02 * rtb_Switch_l40f02;

  /* Sum: '<S989>/Subtract3' incorporates:
   *  Gain: '<S989>/Gain1'
   */
  rtb_Switch_l40f02 = measure_P.Gain1_Gain_p * rtb_Switch_l40f02 - rtb_Switch4;

  /* Gain: '<S955>/Gain' incorporates:
   *  Math: '<S955>/Math Function'
   *
   * About '<S955>/Math Function':
   *  Operator: reciprocal
   */
  rtb_Switch_l4 = 1.0 / rtb_Switch_l4 * measure_P.Gain_Gain_am;

  /* Product: '<S961>/Divide' incorporates:
   *  Product: '<S961>/Product'
   *  Product: '<S961>/Product1'
   *  Sum: '<S961>/Sum1'
   *  Sum: '<S961>/Sum7'
   */
  rtb_Switch_l40f = (rtb_Switch_l40f -
                     (measure_B.VariableDiscreteDelaywithTwoT_o *
                      rtb_Switch_l40f02 +
                      measure_B.VariableDiscreteDelaywithTwo_i4 * rtb_Switch4)) *
    rtb_Switch_l4;

  /* Sum: '<S503>/Add' */
  measure_B.ACripple1stestimate_f = measure_B.Switch_l - rtb_Switch_l40f;

  /* Switch: '<S957>/Switch' incorporates:
   *  Constant: '<S1024>/Constant'
   *  RelationalOperator: '<S1024>/Compare'
   *  UnaryMinus: '<S957>/Unary Minus'
   */
  if (measure_B.ACripple1stestimate_f < measure_P.Constant_Value_kz) {
    rtb_IpktoIrmsconversion = -measure_B.ACripple1stestimate_f;
  } else {
    rtb_IpktoIrmsconversion = measure_B.ACripple1stestimate_f;
  }

  /* End of Switch: '<S957>/Switch' */

  /* Switch: '<S981>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S981>/int32'
   *  Constant: '<S983>/FixPt Constant'
   *  Gain: '<S310>/Gain'
   *  RelationalOperator: '<S503>/Relational Operator1'
   *  Sum: '<S983>/FixPt Sum1'
   *  UnitDelay: '<S981>/Unit Delay'
   */
  if (rtb_IpktoIrmsconversion > measure_P.Gain_Gain_l *
      measure_P.Constant2_Value_h) {
    rtb_Switch_oh = measure_P.int32_Value_n;
  } else {
    rtb_Switch_oh = measure_DWork.UnitDelay_DSTATE_m -
      measure_P.FixPtConstant_Value_n;
  }

  /* End of Switch: '<S981>/Switch' */

  /* RelationalOperator: '<S982>/Compare' incorporates:
   *  Constant: '<S982>/Constant'
   */
  rtb_Compare_k5 = (rtb_Switch_oh > measure_P.Constant_Value_nl);

  /* Switch: '<S503>/Switch2' */
  if (rtb_Compare_k5) {
    rtb_Switch_l40f = measure_B.Switch_l;
  }

  /* End of Switch: '<S503>/Switch2' */

  /* Switch: '<S941>/Switch' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S941>/const'
   *  Logic: '<S502>/Logical Operator'
   *  Logic: '<S502>/Logical Operator3'
   *  RelationalOperator: '<S502>/Relational Operator'
   *  RelationalOperator: '<S502>/Relational Operator1'
   *  Sum: '<S310>/Add'
   *  Sum: '<S310>/Add1'
   */
  if (!(((rtb_Switch1_c < rtb_Switch_l40f - measure_P.Constant6_Value) ||
         (rtb_Switch1_c > rtb_Switch_l40f + measure_P.Constant6_Value)) &&
        rtb_LogicalOperator16)) {
    rtb_UnitDelay1_n0 = measure_P.const_Value_oz;
  }

  /* End of Switch: '<S941>/Switch' */

  /* RelationalOperator: '<S945>/Compare' incorporates:
   *  Constant: '<S945>/Constant'
   */
  rtb_Compare_mp = (rtb_UnitDelay1_n0 == measure_P.Constant_Value_na);

  /* Switch: '<S942>/Switch' incorporates:
   *  Constant: '<S942>/int32'
   *  Constant: '<S944>/FixPt Constant'
   *  Sum: '<S944>/FixPt Sum1'
   *  UnitDelay: '<S942>/Unit Delay'
   */
  if (rtb_Compare_mp) {
    rtb_Bias_hsr = measure_P.int32_Value_c;
  } else {
    rtb_Bias_hsr = measure_DWork.UnitDelay_DSTATE_hs -
      measure_P.FixPtConstant_Value_cm;
  }

  /* End of Switch: '<S942>/Switch' */

  /* RelationalOperator: '<S943>/Compare' incorporates:
   *  Constant: '<S943>/Constant'
   */
  rtb_Compare_n = (rtb_Bias_hsr > measure_P.Constant_Value_cmk);

  /* Logic: '<S940>/Logical Operator2' incorporates:
   *  Logic: '<S502>/Logical Operator1'
   *  Logic: '<S502>/Logical Operator4'
   *  Logic: '<S938>/Logical Operator1'
   *  Logic: '<S938>/Logical Operator2'
   *  Logic: '<S940>/Logical Operator'
   *  Logic: '<S940>/Logical Operator1'
   *  UnitDelay: '<S938>/delay1'
   *  UnitDelay: '<S940>/Unit Delay1'
   */
  rtb_LogicalOperator2_f = (rtb_Compare_mp || ((!((!rtb_LogicalOperator16) || ((
    !rtb_Compare_n) && measure_DWork.delay1_DSTATE_no))) &&
    measure_DWork.UnitDelay1_DSTATE_p));

  /* Logic: '<S502>/Logical Operator2' incorporates:
   *  Constant: '<S103>/Constant'
   *  Constant: '<S493>/Constant'
   *  Constant: '<S502>/Constant1'
   *  Logic: '<S310>/Logical Operator'
   *  Logic: '<S310>/Logical Operator1'
   *  Logic: '<S310>/Logical Operator2'
   *  Logic: '<S310>/Logical Operator7'
   *  Logic: '<S502>/Logical Operator5'
   *  RelationalOperator: '<S493>/Compare'
   */
  rtb_LogicalOperator2_fd = (measure_P.Constant1_Value_p &&
    (rtb_LogicalOperator2_f || ((rtb_LogicalOperator16 && ((rtb_Switch_l40f <
    measure_P.Constant_Value_i5) || (!rtb_LogicalOperator12) || rtb_Compare_k5))
    || measure_P.Constant_Value_py)));

  /* Switch: '<S502>/Switch' */
  if (rtb_LogicalOperator2_fd) {
    measure_B.Switch_m = rtb_Switch1_c;
  } else {
    measure_B.Switch_m = rtb_Switch_l40f;
  }

  /* End of Switch: '<S502>/Switch' */

  /* Switch: '<S504>/Switch' */
  if (rtb_UnitDelay4_hd) {
    rtb_Switch_c = rtb_Switch1;
  } else {
    rtb_Switch_c = measure_B.Switch_m;
  }

  /* End of Switch: '<S504>/Switch' */

  /* Switch: '<S310>/Switch' incorporates:
   *  Constant: '<S310>/Constant5'
   *  Constant: '<S310>/Constant6'
   */
  if (measure_P.Constant6_Value_n) {
    rtb_LogicalOperator1_f = rtb_LogicalOperator2_fd;
  } else {
    rtb_LogicalOperator1_f = measure_P.Constant5_Value_d;
  }

  /* End of Switch: '<S310>/Switch' */

  /* Switch: '<S310>/Switch1' incorporates:
   *  Logic: '<S310>/Logical Operator4'
   */
  if (rtb_LogicalOperator12 || rtb_UnitDelay4_hd || rtb_LogicalOperator1_f) {
    /* Outport: '<Root>/Frequency' */
    measure_Y.Frequency = rtb_Switch_c;
  } else {
    /* Outport: '<Root>/Frequency' incorporates:
     *  Constant: '<S310>/Constant1'
     */
    measure_Y.Frequency = measure_P.Constant1_Value_j;
  }

  /* End of Switch: '<S310>/Switch1' */

  /* Gain: '<S1>/Gain3' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_IpktoIrmsconversion = measure_P.Gain3_Gain * measure_P.Constant1_Value_m2;

  /* Sum: '<S670>/Subtract' incorporates:
   *  Math: '<S670>/Math Function1'
   *  Math: '<S670>/Math Function3'
   */
  rtb_Switch_l40f = rtb_Divide_h * rtb_Divide_h + rtb_Divide_h3 * rtb_Divide_h3;

  /* Math: '<S670>/Math Function2'
   *
   * About '<S670>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Gain_m = rtb_Switch_l40f < 0.0 ? -sqrt(fabs(rtb_Switch_l40f)) : sqrt
    (rtb_Switch_l40f);

  /* Product: '<S12>/Vpu to Vrms' incorporates:
   *  Math: '<S670>/Math Function2'
   *
   * About '<S670>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Product_i = rtb_IpktoIrmsconversion * rtb_Gain_m;

  /* Sum: '<S771>/Subtract' incorporates:
   *  Math: '<S771>/Math Function1'
   *  Math: '<S771>/Math Function3'
   */
  rtb_IpktoIrms_a = rtb_Divide_n * rtb_Divide_n + rtb_Divide_ny * rtb_Divide_ny;

  /* Math: '<S771>/Math Function2'
   *
   * About '<S771>/Math Function2':
   *  Operator: sqrt
   */
  rtb_IpktoIrms_a = rtb_IpktoIrms_a < 0.0 ? -sqrt(fabs(rtb_IpktoIrms_a)) : sqrt
    (rtb_IpktoIrms_a);

  /* Product: '<S13>/Vpu to Vrms' incorporates:
   *  Math: '<S771>/Math Function2'
   *
   * About '<S771>/Math Function2':
   *  Operator: sqrt
   */
  rtb_AbsVI = rtb_IpktoIrmsconversion * rtb_IpktoIrms_a;

  /* Sum: '<S872>/Subtract' incorporates:
   *  Math: '<S872>/Math Function1'
   *  Math: '<S872>/Math Function3'
   */
  rtb_Switch_b = rtb_Divide_j * rtb_Divide_j + rtb_Divide_jw * rtb_Divide_jw;

  /* Math: '<S872>/Math Function2'
   *
   * About '<S872>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Switch_b = rtb_Switch_b < 0.0 ? -sqrt(fabs(rtb_Switch_b)) : sqrt
    (rtb_Switch_b);

  /* Product: '<S14>/Vpu to Vrms' incorporates:
   *  Math: '<S872>/Math Function2'
   *
   * About '<S872>/Math Function2':
   *  Operator: sqrt
   */
  rtb_AbsVI_e = rtb_IpktoIrmsconversion * rtb_Switch_b;

  /* Gain: '<S33>/Gain6' incorporates:
   *  Gain: '<S33>/Gain5'
   *  RealImagToComplex: '<S33>/Real-Imag to Complex'
   *  RealImagToComplex: '<S33>/Real-Imag to Complex1'
   *  RealImagToComplex: '<S33>/Real-Imag to Complex2'
   *  Sum: '<S33>/Sum2'
   */
  rtb_MathFunction1 = (((measure_P.Gain5_Gain[0].re * rtb_Divide_h -
    measure_P.Gain5_Gain[0].im * rtb_Divide_h3) + (measure_P.Gain5_Gain[1].re *
    rtb_Divide_n - measure_P.Gain5_Gain[1].im * rtb_Divide_ny)) +
                       (measure_P.Gain5_Gain[2].re * rtb_Divide_j -
                        measure_P.Gain5_Gain[2].im * rtb_Divide_jw)) *
    measure_P.Gain6_Gain;
  rtb_Switch1_c = (((measure_P.Gain5_Gain[0].re * rtb_Divide_h3 +
                     measure_P.Gain5_Gain[0].im * rtb_Divide_h) +
                    (measure_P.Gain5_Gain[1].re * rtb_Divide_ny +
                     measure_P.Gain5_Gain[1].im * rtb_Divide_n)) +
                   (measure_P.Gain5_Gain[2].re * rtb_Divide_jw +
                    measure_P.Gain5_Gain[2].im * rtb_Divide_j)) *
    measure_P.Gain6_Gain;

  /* Sum: '<S45>/Subtract' incorporates:
   *  ComplexToRealImag: '<S33>/Complex to Real-Imag1'
   *  Math: '<S45>/Math Function1'
   *  Math: '<S45>/Math Function3'
   */
  rtb_Divide_jahfx5 = rtb_MathFunction1 * rtb_MathFunction1 + rtb_Switch1_c *
    rtb_Switch1_c;

  /* Gain: '<S33>/Gain4' incorporates:
   *  Gain: '<S33>/Gain2'
   *  RealImagToComplex: '<S33>/Real-Imag to Complex'
   *  RealImagToComplex: '<S33>/Real-Imag to Complex1'
   *  RealImagToComplex: '<S33>/Real-Imag to Complex2'
   *  Sum: '<S33>/Sum1'
   */
  rtb_MathFunction1 = (((measure_P.Gain2_Gain_o[0].re * rtb_Divide_h -
    measure_P.Gain2_Gain_o[0].im * rtb_Divide_h3) + (measure_P.Gain2_Gain_o[1].
    re * rtb_Divide_n - measure_P.Gain2_Gain_o[1].im * rtb_Divide_ny)) +
                       (measure_P.Gain2_Gain_o[2].re * rtb_Divide_j -
                        measure_P.Gain2_Gain_o[2].im * rtb_Divide_jw)) *
    measure_P.Gain4_Gain;
  rtb_Switch1_c = (((measure_P.Gain2_Gain_o[0].re * rtb_Divide_h3 +
                     measure_P.Gain2_Gain_o[0].im * rtb_Divide_h) +
                    (measure_P.Gain2_Gain_o[1].re * rtb_Divide_ny +
                     measure_P.Gain2_Gain_o[1].im * rtb_Divide_n)) +
                   (measure_P.Gain2_Gain_o[2].re * rtb_Divide_jw +
                    measure_P.Gain2_Gain_o[2].im * rtb_Divide_j)) *
    measure_P.Gain4_Gain;

  /* Sum: '<S43>/Subtract' incorporates:
   *  ComplexToRealImag: '<S33>/Complex to Real-Imag'
   *  Math: '<S43>/Math Function1'
   *  Math: '<S43>/Math Function3'
   */
  rtb_ScaleRMSoutputsto1pu = rtb_MathFunction1 * rtb_MathFunction1 +
    rtb_Switch1_c * rtb_Switch1_c;

  /* Math: '<S43>/Math Function2'
   *
   * About '<S43>/Math Function2':
   *  Operator: sqrt
   */
  rtb_ScaleRMSoutputsto1pu = rtb_ScaleRMSoutputsto1pu < 0.0 ? -sqrt(fabs
    (rtb_ScaleRMSoutputsto1pu)) : sqrt(rtb_ScaleRMSoutputsto1pu);

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S48>/Constant'
   *  Math: '<S43>/Math Function2'
   *  RelationalOperator: '<S48>/Compare'
   *
   * About '<S43>/Math Function2':
   *  Operator: sqrt
   */
  if (rtb_ScaleRMSoutputsto1pu < measure_P.Constant_Value_jw) {
    rtb_ScaleRMSoutputsto1pu = measure_P.Constant_Value_b;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Gain: '<S33>/Gain3' incorporates:
   *  Math: '<S45>/Math Function2'
   *  Product: '<S33>/Product'
   *
   * About '<S45>/Math Function2':
   *  Operator: sqrt
   */
  rtb_ScaleRMSoutputsto1pu = (rtb_Divide_jahfx5 < 0.0 ? -sqrt(fabs
    (rtb_Divide_jahfx5)) : sqrt(rtb_Divide_jahfx5)) / rtb_ScaleRMSoutputsto1pu *
    measure_P.Gain3_Gain_i;

  /* Gain: '<S626>/Scale RMS outputs to 1pu' */
  rtb_Divide_jahfx *= measure_P.ScaleRMSoutputsto1pu_Gain;

  /* Math: '<S677>/Math Function' */
  measure_B.MathFunction = rtb_Divide_jahfx * rtb_Divide_jahfx;

  /* Switch: '<S682>/Switch' incorporates:
   *  Constant: '<S682>/double'
   *  Sum: '<S682>/Sum2'
   *  UnitDelay: '<S682>/Unit Delay2'
   *  UnitDelay: '<S682>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_ixhvnqluia = measure_P.double_Value_bln4djb4gs54;
  } else {
    measure_B.Switch_ixhvnqluia = (measure_B.MathFunction +
      measure_DWork.UnitDelay4_DSTATE_js0g0xcka) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5ta;
  }

  /* End of Switch: '<S682>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S679>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_i3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_bq;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqluia;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelay_bln4djb4g) Offset = measure_P.VariableDiscreteDelay_bln4djb4g;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_bln4djb4g;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_el = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_bln4djb4g)
      *VDD_in = 0;
  }

  /* Switch: '<S683>/Switch' incorporates:
   *  Constant: '<S683>/double'
   *  Sum: '<S683>/Sum2'
   *  UnitDelay: '<S683>/Unit Delay2'
   *  UnitDelay: '<S683>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_ixhvnqluiaa = measure_P.double_Value_bln4djb4gs54q;
  } else {
    measure_B.Switch_ixhvnqluiaa = (measure_B.MathFunction +
      measure_DWork.UnitDelay4_DSTATE_js0g0xckaa) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5tay;
  }

  /* End of Switch: '<S683>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S680>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_fqs;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqluiaa;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDela_bln4djb4gs) Offset = measure_P.VariableDiscreteDela_bln4djb4gs;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_bln4djb4gs;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_g3 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_bln4djb4gs)
      *VDD_in = 0;
  }

  /* Switch: '<S678>/Switch1' incorporates:
   *  Sum: '<S678>/Sum1'
   *  Sum: '<S678>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Divide_jahfx5 = measure_B.Switch_ixhvnqluia -
      measure_B.VariableDiscret_el;
  } else {
    rtb_Divide_jahfx5 = measure_B.Switch_ixhvnqluiaa -
      measure_B.VariableDiscret_g3;
  }

  /* End of Switch: '<S678>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S684>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gg[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_mu;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDel_bln4djb4gs5) Offset = measure_P.VariableDiscreteDel_bln4djb4gs5;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_bln4djb4gs5;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_jk = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDel_bln4djb4gs5)
      measure_B.VariableDiscret_n = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_n = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_bln4djb4gs5)
      *VDD_in = 0;
  }

  /* Product: '<S681>/Divide' incorporates:
   *  Product: '<S681>/Product'
   *  Product: '<S681>/Product1'
   *  Sum: '<S681>/Sum1'
   *  Sum: '<S681>/Sum7'
   */
  rtb_Divide_jahfx5 = (rtb_Divide_jahfx5 - (measure_B.VariableDiscret_jk *
    rtb_Subtract3_c0 + measure_B.VariableDiscret_n * rtb_MathFunction_ed1)) *
    rtb_Divide_ja;

  /* Math: '<S677>/Math Function1'
   *
   * About '<S677>/Math Function1':
   *  Operator: sqrt
   */
  measure_B.MathFunction1 = rtb_Divide_jahfx5 < 0.0 ? -sqrt(fabs
    (rtb_Divide_jahfx5)) : sqrt(rtb_Divide_jahfx5);

  /* Switch: '<S630>/Switch' incorporates:
   *  Constant: '<S630>/double'
   *  Sum: '<S630>/Sum2'
   *  UnitDelay: '<S630>/Unit Delay2'
   *  UnitDelay: '<S630>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_ixhvnqluiaai = measure_P.double_Value_bl;
  } else {
    measure_B.Switch_ixhvnqluiaai = (measure_B.MathFunction1 +
      measure_DWork.UnitDelay4_DSTATE_js0g0xckaam) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5tayt;
  }

  /* End of Switch: '<S630>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S627>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ex[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_mr;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqluiaai;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDe_bln4djb4gs54) Offset = measure_P.VariableDiscreteDe_bln4djb4gs54;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_bln4djb4gs54;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_j2 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_bln4djb4gs54)
      *VDD_in = 0;
  }

  /* Switch: '<S631>/Switch' incorporates:
   *  Constant: '<S631>/double'
   *  Sum: '<S631>/Sum2'
   *  UnitDelay: '<S631>/Unit Delay2'
   *  UnitDelay: '<S631>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_ixhvnqluiaai5 = measure_P.double_Value_bln;
  } else {
    measure_B.Switch_ixhvnqluiaai5 = (measure_B.MathFunction1 +
      measure_DWork.UnitDelay4_DSTATE_js0g0xckaamb) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5taytr;
  }

  /* End of Switch: '<S631>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S628>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_aj[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_eb;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqluiaai5;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteD_bln4djb4gs54q) Offset = measure_P.VariableDiscreteD_bln4djb4gs54q;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_bln4djb4gs54q;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_l = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_bln4djb4gs54q)
      *VDD_in = 0;
  }

  /* Switch: '<S622>/Switch1' incorporates:
   *  Sum: '<S622>/Sum1'
   *  Sum: '<S622>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Divide_jahfx5 = measure_B.Switch_ixhvnqluiaai -
      measure_B.VariableDiscret_j2;
  } else {
    rtb_Divide_jahfx5 = measure_B.Switch_ixhvnqluiaai5 -
      measure_B.VariableDiscret_l;
  }

  /* End of Switch: '<S622>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S632>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_aq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_oe;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction1;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscrete_bln4djb4gs54qg) Offset = measure_P.VariableDiscrete_bln4djb4gs54qg;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_bln4djb4gs54qg;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_hk = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscrete_bln4djb4gs54qg)
      measure_B.VariableDiscret_js = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_js = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_bln4djb4gs54qg)
      *VDD_in = 0;
  }

  /* Product: '<S629>/Divide' incorporates:
   *  Product: '<S629>/Product'
   *  Product: '<S629>/Product1'
   *  Sum: '<S629>/Sum1'
   *  Sum: '<S629>/Sum7'
   */
  rtb_Divide_jahfx5 = (rtb_Divide_jahfx5 - (measure_B.VariableDiscret_hk *
    rtb_Subtract3_c04 + measure_B.VariableDiscret_js * rtb_MathFunction_ed12)) *
    rtb_Divide_jah;

  /* Sum: '<S625>/Sum' incorporates:
   *  Math: '<S625>/Math Function1'
   *  Math: '<S625>/Math Function3'
   *  Math: '<S670>/Math Function2'
   *
   * About '<S670>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Divide_jahfx5 = rtb_Divide_jahfx5 * rtb_Divide_jahfx5 - rtb_Gain_m *
    rtb_Gain_m;

  /* Switch: '<S671>/Switch' incorporates:
   *  Constant: '<S671>/Constant'
   *  Constant: '<S674>/Constant'
   *  RelationalOperator: '<S674>/Compare'
   */
  if (rtb_Divide_jahfx5 < measure_P.Constant_Value_bln4djb) {
    rtb_Divide_jahfx5 = measure_P.Constant_Value_bl;
  }

  /* End of Switch: '<S671>/Switch' */

  /* Switch: '<S672>/Switch' incorporates:
   *  Constant: '<S672>/Constant'
   *  Constant: '<S675>/Constant'
   *  Math: '<S670>/Math Function2'
   *  RelationalOperator: '<S675>/Compare'
   *
   * About '<S670>/Math Function2':
   *  Operator: sqrt
   */
  if (rtb_Gain_m < measure_P.Constant_Value_bln4djb4) {
    rtb_Gain_m = measure_P.Constant_Value_bln;
  }

  /* End of Switch: '<S672>/Switch' */

  /* Gain: '<S625>/Gain' incorporates:
   *  Math: '<S625>/Math Function2'
   *  Product: '<S625>/Product1'
   *
   * About '<S625>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Divide_jahfx5 = (rtb_Divide_jahfx5 < 0.0 ? -sqrt(fabs(rtb_Divide_jahfx5)) :
                       sqrt(rtb_Divide_jahfx5)) / rtb_Gain_m *
    measure_P.Gain_Gain_bln;

  /* Switch: '<S673>/Switch' incorporates:
   *  Constant: '<S673>/Constant'
   *  Constant: '<S676>/Constant'
   *  RelationalOperator: '<S676>/Compare'
   */
  if (rtb_Divide_jahfx5 > measure_P.Constant_Value_bln4djb4g) {
    rtb_Divide_jahfx5 = measure_P.Constant_Value_bln4;
  }

  /* End of Switch: '<S673>/Switch' */

  /* Gain: '<S727>/Scale RMS outputs to 1pu' */
  rtb_Switch_b2 *= measure_P.ScaleRMSoutputsto1pu_Gain_e;

  /* Math: '<S778>/Math Function' */
  measure_B.MathFunction_c = rtb_Switch_b2 * rtb_Switch_b2;

  /* Switch: '<S783>/Switch' incorporates:
   *  Constant: '<S783>/double'
   *  Sum: '<S783>/Sum2'
   *  UnitDelay: '<S783>/Unit Delay2'
   *  UnitDelay: '<S783>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_dh3ioosv2 = measure_P.double_Value_eznclc5xg5q1;
  } else {
    measure_B.Switch_dh3ioosv2 = (measure_B.MathFunction_c +
      measure_DWork.UnitDelay4_DSTATE_e10ck0cti) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3xa;
  }

  /* End of Switch: '<S783>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S780>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_no[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ib;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioosv2;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDel_eznclc5xg5q) Offset = measure_P.VariableDiscreteDel_eznclc5xg5q;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_eznclc5xg5q;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_fo = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_eznclc5xg5q)
      *VDD_in = 0;
  }

  /* Switch: '<S784>/Switch' incorporates:
   *  Constant: '<S784>/double'
   *  Sum: '<S784>/Sum2'
   *  UnitDelay: '<S784>/Unit Delay2'
   *  UnitDelay: '<S784>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_dh3ioosv2k = measure_P.double_Value_eznclc5xg5q1u;
  } else {
    measure_B.Switch_dh3ioosv2k = (measure_B.MathFunction_c +
      measure_DWork.UnitDelay4_DSTATE_e10ck0ctir) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3xak;
  }

  /* End of Switch: '<S784>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S781>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f5[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pz;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioosv2k;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDe_eznclc5xg5q1) Offset = measure_P.VariableDiscreteDe_eznclc5xg5q1;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_eznclc5xg5q1;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_ew = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_eznclc5xg5q1)
      *VDD_in = 0;
  }

  /* Switch: '<S779>/Switch1' incorporates:
   *  Sum: '<S779>/Sum1'
   *  Sum: '<S779>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_UnaryMinus_dv = measure_B.Switch_dh3ioosv2 -
      measure_B.VariableDiscret_fo;
  } else {
    rtb_UnaryMinus_dv = measure_B.Switch_dh3ioosv2k -
      measure_B.VariableDiscret_ew;
  }

  /* End of Switch: '<S779>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S785>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ef[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pei;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction_c;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteD_eznclc5xg5q1u) Offset = measure_P.VariableDiscreteD_eznclc5xg5q1u;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_eznclc5xg5q1u;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_jg = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteD_eznclc5xg5q1u)
      measure_B.VariableDiscret_p = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_p = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_eznclc5xg5q1u)
      *VDD_in = 0;
  }

  /* Product: '<S782>/Divide' incorporates:
   *  Product: '<S782>/Product'
   *  Product: '<S782>/Product1'
   *  Sum: '<S782>/Sum1'
   *  Sum: '<S782>/Sum7'
   */
  rtb_UnaryMinus_dv = (rtb_UnaryMinus_dv - (measure_B.VariableDiscret_jg *
    rtb_Subtract3_c0 + measure_B.VariableDiscret_p * rtb_MathFunction_ed1)) *
    rtb_Divide_ja;

  /* Math: '<S778>/Math Function1'
   *
   * About '<S778>/Math Function1':
   *  Operator: sqrt
   */
  measure_B.MathFunction1_p = rtb_UnaryMinus_dv < 0.0 ? -sqrt(fabs
    (rtb_UnaryMinus_dv)) : sqrt(rtb_UnaryMinus_dv);

  /* Switch: '<S731>/Switch' incorporates:
   *  Constant: '<S731>/double'
   *  Sum: '<S731>/Sum2'
   *  UnitDelay: '<S731>/Unit Delay2'
   *  UnitDelay: '<S731>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_dh3ioosv2km = measure_P.double_Value_ez;
  } else {
    measure_B.Switch_dh3ioosv2km = (measure_B.MathFunction1_p +
      measure_DWork.UnitDelay4_DSTATE_e10ck0ctirr) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku;
  }

  /* End of Switch: '<S731>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S728>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ed[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_fy;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioosv2km;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscrete_eznclc5xg5q1ug) Offset = measure_P.VariableDiscrete_eznclc5xg5q1ug;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_eznclc5xg5q1ug;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_m = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_eznclc5xg5q1ug)
      *VDD_in = 0;
  }

  /* Switch: '<S732>/Switch' incorporates:
   *  Constant: '<S732>/double'
   *  Sum: '<S732>/Sum2'
   *  UnitDelay: '<S732>/Unit Delay2'
   *  UnitDelay: '<S732>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_dh3ioosv2kma = measure_P.double_Value_ezn;
  } else {
    measure_B.Switch_dh3ioosv2kma = (measure_B.MathFunction1_p +
      measure_DWork.UnitDelay4_DSTATE_e10ck0ctirrv) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku5;
  }

  /* End of Switch: '<S732>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S729>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a0[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ej;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioosv2kma;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_eznclc5xg5q1ugj) Offset = measure_P.VariableDiscret_eznclc5xg5q1ugj;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_eznclc5xg5q1ugj;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_b = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_eznclc5xg5q1ugj)
      *VDD_in = 0;
  }

  /* Switch: '<S723>/Switch1' incorporates:
   *  Sum: '<S723>/Sum1'
   *  Sum: '<S723>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_UnaryMinus_dv = measure_B.Switch_dh3ioosv2km -
      measure_B.VariableDiscret_m;
  } else {
    rtb_UnaryMinus_dv = measure_B.Switch_dh3ioosv2kma -
      measure_B.VariableDiscret_b;
  }

  /* End of Switch: '<S723>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S733>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pk[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_nc;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_p;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_k) Offset = measure_P.VariableDiscret_k;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_k;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_al = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_k)
      measure_B.VariableDiscret_ki = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_ki = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_k)
      *VDD_in = 0;
  }

  /* Product: '<S730>/Divide' incorporates:
   *  Product: '<S730>/Product'
   *  Product: '<S730>/Product1'
   *  Sum: '<S730>/Sum1'
   *  Sum: '<S730>/Sum7'
   */
  rtb_UnaryMinus_dv = (rtb_UnaryMinus_dv - (measure_B.VariableDiscret_al *
    rtb_Subtract3_c04 + measure_B.VariableDiscret_ki * rtb_MathFunction_ed12)) *
    rtb_Divide_jah;

  /* Sum: '<S726>/Sum' incorporates:
   *  Math: '<S726>/Math Function1'
   *  Math: '<S726>/Math Function3'
   *  Math: '<S771>/Math Function2'
   *
   * About '<S771>/Math Function2':
   *  Operator: sqrt
   */
  rtb_UnaryMinus_dv = rtb_UnaryMinus_dv * rtb_UnaryMinus_dv - rtb_IpktoIrms_a *
    rtb_IpktoIrms_a;

  /* Switch: '<S772>/Switch' incorporates:
   *  Constant: '<S772>/Constant'
   *  Constant: '<S775>/Constant'
   *  RelationalOperator: '<S775>/Compare'
   */
  if (rtb_UnaryMinus_dv < measure_P.Constant_Value_eznclc5) {
    rtb_UnaryMinus_dv = measure_P.Constant_Value_ez;
  }

  /* End of Switch: '<S772>/Switch' */

  /* Switch: '<S773>/Switch' incorporates:
   *  Constant: '<S773>/Constant'
   *  Constant: '<S776>/Constant'
   *  Math: '<S771>/Math Function2'
   *  RelationalOperator: '<S776>/Compare'
   *
   * About '<S771>/Math Function2':
   *  Operator: sqrt
   */
  if (rtb_IpktoIrms_a < measure_P.Constant_Value_eznclc5x) {
    rtb_IpktoIrms_a = measure_P.Constant_Value_ezn;
  }

  /* End of Switch: '<S773>/Switch' */

  /* Gain: '<S726>/Gain' incorporates:
   *  Math: '<S726>/Math Function2'
   *  Product: '<S726>/Product1'
   *
   * About '<S726>/Math Function2':
   *  Operator: sqrt
   */
  rtb_UnaryMinus_dv = (rtb_UnaryMinus_dv < 0.0 ? -sqrt(fabs(rtb_UnaryMinus_dv)) :
                       sqrt(rtb_UnaryMinus_dv)) / rtb_IpktoIrms_a *
    measure_P.Gain_Gain_ezn;

  /* Switch: '<S774>/Switch' incorporates:
   *  Constant: '<S774>/Constant'
   *  Constant: '<S777>/Constant'
   *  RelationalOperator: '<S777>/Compare'
   */
  if (rtb_UnaryMinus_dv > measure_P.Constant_Value_eznclc5xg) {
    rtb_UnaryMinus_dv = measure_P.Constant_Value_eznc;
  }

  /* End of Switch: '<S774>/Switch' */

  /* Gain: '<S828>/Scale RMS outputs to 1pu' */
  rtb_UnaryMinus_p *= measure_P.ScaleRMSoutputsto1pu_Gain_e0;

  /* Math: '<S879>/Math Function' */
  measure_B.MathFunction_l = rtb_UnaryMinus_p * rtb_UnaryMinus_p;

  /* Switch: '<S884>/Switch' incorporates:
   *  Constant: '<S884>/double'
   *  Sum: '<S884>/Sum2'
   *  UnitDelay: '<S884>/Unit Delay2'
   *  UnitDelay: '<S884>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_p0ny3pkqp = measure_P.double_Value_e0r1hmwtwqc2;
  } else {
    measure_B.Switch_p0ny3pkqp = (measure_B.MathFunction_l +
      measure_DWork.UnitDelay4_DSTATE_otwsjgetk) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya5a;
  }

  /* End of Switch: '<S884>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S881>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_dk[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_hf;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pkqp;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDel_e0r1hmwtwqc) Offset = measure_P.VariableDiscreteDel_e0r1hmwtwqc;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_e0r1hmwtwqc;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_la = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_e0r1hmwtwqc)
      *VDD_in = 0;
  }

  /* Switch: '<S885>/Switch' incorporates:
   *  Constant: '<S885>/double'
   *  Sum: '<S885>/Sum2'
   *  UnitDelay: '<S885>/Unit Delay2'
   *  UnitDelay: '<S885>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_p0ny3pkqpe = measure_P.double_Value_e0r1hmwtwqc2e;
  } else {
    measure_B.Switch_p0ny3pkqpe = (measure_B.MathFunction_l +
      measure_DWork.UnitDelay4_DSTATE_otwsjgetko) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya5ah;
  }

  /* End of Switch: '<S885>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S882>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_o[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_a2;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pkqpe;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDe_e0r1hmwtwqc2) Offset = measure_P.VariableDiscreteDe_e0r1hmwtwqc2;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_e0r1hmwtwqc2;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_hy = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_e0r1hmwtwqc2)
      *VDD_in = 0;
  }

  /* Switch: '<S880>/Switch1' incorporates:
   *  Sum: '<S880>/Sum1'
   *  Sum: '<S880>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_IpktoIrms_a = measure_B.Switch_p0ny3pkqp - measure_B.VariableDiscret_la;
  } else {
    rtb_IpktoIrms_a = measure_B.Switch_p0ny3pkqpe - measure_B.VariableDiscret_hy;
  }

  /* End of Switch: '<S880>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S886>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gs[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pl;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction_l;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteD_e0r1hmwtwqc2e) Offset = measure_P.VariableDiscreteD_e0r1hmwtwqc2e;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_e0r1hmwtwqc2e;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_pk = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteD_e0r1hmwtwqc2e)
      measure_B.VariableDiscret_p5 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_p5 = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_e0r1hmwtwqc2e)
      *VDD_in = 0;
  }

  /* Product: '<S883>/Divide' incorporates:
   *  Product: '<S883>/Product'
   *  Product: '<S883>/Product1'
   *  Sum: '<S883>/Sum1'
   *  Sum: '<S883>/Sum7'
   */
  rtb_IpktoIrms_a = (rtb_IpktoIrms_a - (measure_B.VariableDiscret_pk *
    rtb_Subtract3_c0 + measure_B.VariableDiscret_p5 * rtb_MathFunction_ed1)) *
    rtb_Divide_ja;

  /* Math: '<S879>/Math Function1'
   *
   * About '<S879>/Math Function1':
   *  Operator: sqrt
   */
  measure_B.MathFunction1_m = rtb_IpktoIrms_a < 0.0 ? -sqrt(fabs(rtb_IpktoIrms_a))
    : sqrt(rtb_IpktoIrms_a);

  /* Switch: '<S832>/Switch' incorporates:
   *  Constant: '<S832>/double'
   *  Sum: '<S832>/Sum2'
   *  UnitDelay: '<S832>/Unit Delay2'
   *  UnitDelay: '<S832>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_p0ny3pkqpey = measure_P.double_Value_e0;
  } else {
    measure_B.Switch_p0ny3pkqpey = (measure_B.MathFunction1_m +
      measure_DWork.UnitDelay4_DSTATE_otwsjgetkod) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0;
  }

  /* End of Switch: '<S832>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S829>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_bt[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_av;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pkqpey;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscrete_e0r1hmwtwqc2ev) Offset = measure_P.VariableDiscrete_e0r1hmwtwqc2ev;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_e0r1hmwtwqc2ev;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_ef = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_e0r1hmwtwqc2ev)
      *VDD_in = 0;
  }

  /* Switch: '<S833>/Switch' incorporates:
   *  Constant: '<S833>/double'
   *  Sum: '<S833>/Sum2'
   *  UnitDelay: '<S833>/Unit Delay2'
   *  UnitDelay: '<S833>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_p0ny3pkqpeyo = measure_P.double_Value_e0r;
  } else {
    measure_B.Switch_p0ny3pkqpeyo = (measure_B.MathFunction1_m +
      measure_DWork.UnitDelay4_DSTATE_otwsjgetkod3) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0l;
  }

  /* End of Switch: '<S833>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S830>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_e0[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_dg;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pkqpeyo;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_e0r1hmwtwqc2evm) Offset = measure_P.VariableDiscret_e0r1hmwtwqc2evm;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_e0r1hmwtwqc2evm;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_ai = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_e0r1hmwtwqc2evm)
      *VDD_in = 0;
  }

  /* Switch: '<S824>/Switch1' incorporates:
   *  Sum: '<S824>/Sum1'
   *  Sum: '<S824>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_IpktoIrms_a = measure_B.Switch_p0ny3pkqpey -
      measure_B.VariableDiscret_ef;
  } else {
    rtb_IpktoIrms_a = measure_B.Switch_p0ny3pkqpeyo -
      measure_B.VariableDiscret_ai;
  }

  /* End of Switch: '<S824>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S834>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_l[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_lwr;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_m;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_kl) Offset = measure_P.VariableDiscret_kl;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_kl;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_b5 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_kl)
      measure_B.VariableDiscret_jn = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_jn = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_kl)
      *VDD_in = 0;
  }

  /* Product: '<S831>/Divide' incorporates:
   *  Product: '<S831>/Product'
   *  Product: '<S831>/Product1'
   *  Sum: '<S831>/Sum1'
   *  Sum: '<S831>/Sum7'
   */
  rtb_IpktoIrms_a = (rtb_IpktoIrms_a - (measure_B.VariableDiscret_b5 *
    rtb_Subtract3_c04 + measure_B.VariableDiscret_jn * rtb_MathFunction_ed12)) *
    rtb_Divide_jah;

  /* Sum: '<S827>/Sum' incorporates:
   *  Math: '<S827>/Math Function1'
   *  Math: '<S827>/Math Function3'
   *  Math: '<S872>/Math Function2'
   *
   * About '<S872>/Math Function2':
   *  Operator: sqrt
   */
  rtb_IpktoIrms_a = rtb_IpktoIrms_a * rtb_IpktoIrms_a - rtb_Switch_b *
    rtb_Switch_b;

  /* Switch: '<S873>/Switch' incorporates:
   *  Constant: '<S873>/Constant'
   *  Constant: '<S876>/Constant'
   *  RelationalOperator: '<S876>/Compare'
   */
  if (rtb_IpktoIrms_a < measure_P.Constant_Value_e0r1hmw) {
    rtb_IpktoIrms_a = measure_P.Constant_Value_e0;
  }

  /* End of Switch: '<S873>/Switch' */

  /* Switch: '<S874>/Switch' incorporates:
   *  Constant: '<S874>/Constant'
   *  Constant: '<S877>/Constant'
   *  Math: '<S872>/Math Function2'
   *  RelationalOperator: '<S877>/Compare'
   *
   * About '<S872>/Math Function2':
   *  Operator: sqrt
   */
  if (rtb_Switch_b < measure_P.Constant_Value_e0r1hmwt) {
    rtb_Switch_b = measure_P.Constant_Value_e0r;
  }

  /* End of Switch: '<S874>/Switch' */

  /* Gain: '<S827>/Gain' incorporates:
   *  Math: '<S827>/Math Function2'
   *  Product: '<S827>/Product1'
   *
   * About '<S827>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Switch_b = (rtb_IpktoIrms_a < 0.0 ? -sqrt(fabs(rtb_IpktoIrms_a)) : sqrt
                  (rtb_IpktoIrms_a)) / rtb_Switch_b * measure_P.Gain_Gain_e0r;

  /* Switch: '<S875>/Switch' incorporates:
   *  Constant: '<S875>/Constant'
   *  Constant: '<S878>/Constant'
   *  RelationalOperator: '<S878>/Compare'
   */
  if (rtb_Switch_b > measure_P.Constant_Value_e0r1hmwtw) {
    rtb_Switch_b = measure_P.Constant_Value_e0r1;
  }

  /* End of Switch: '<S875>/Switch' */

  /* Outport: '<Root>/Voltage' */
  measure_Y.Voltage[0] = rtb_Product_i;
  measure_Y.Voltage[1] = rtb_AbsVI;
  measure_Y.Voltage[2] = rtb_AbsVI_e;
  measure_Y.Voltage[3] = rtb_TrigonometricFunction_l;
  measure_Y.Voltage[4] = rtb_TrigonometricFunction_c;
  measure_Y.Voltage[5] = rtb_TrigonometricFunction_b;
  measure_Y.Voltage[6] = rtb_ScaleRMSoutputsto1pu;
  measure_Y.Voltage[7] = rtb_Divide_jahfx5;
  measure_Y.Voltage[8] = rtb_UnaryMinus_dv;
  measure_Y.Voltage[9] = rtb_Switch_b;

  /* UnitDelay: '<S87>/Unit Delay1' */
  rtb_UnitDelay1_l = measure_DWork.UnitDelay1_DSTATE_h;

  /* Bias: '<S87>/Bias' incorporates:
   *  Gain: '<S87>/Gain'
   */
  rtb_ScaleRMSoutputsto1pu = measure_P.Gain_Gain_cep * rtb_Add1_h_idx +
    measure_P.Bias_Bias_o;

  /* Sum: '<S96>/Sum1' incorporates:
   *  Gain: '<S97>/Gain'
   *  Gain: '<S97>/Gain1'
   *  Inport: '<Root>/Iabc (Amps)'
   *  Math: '<S96>/Math Function'
   *  Product: '<S96>/Product'
   *  Product: '<S96>/Product1'
   *  Sum: '<S97>/Sum1'
   *  Sum: '<S97>/Sum2'
   *  Sum: '<S97>/Sum7'
   *  UnitDelay: '<S87>/Unit Delay1'
   *  UnitDelay: '<S87>/Unit Delay2'
   */
  rtb_ScaleRMSoutputsto1pu = ((measure_U.IabcAmps[0] -
    measure_DWork.UnitDelay2_DSTATE_gp) * measure_P.Gain_Gain_d2 *
    rtb_ScaleRMSoutputsto1pu + measure_DWork.UnitDelay1_DSTATE_h) +
    ((measure_DWork.UnitDelay2_DSTATE_gp + measure_U.IabcAmps[0]) *
     measure_P.Gain1_Gain_b - measure_DWork.UnitDelay1_DSTATE_h) *
    (rtb_ScaleRMSoutputsto1pu * rtb_ScaleRMSoutputsto1pu);

  /* Product: '<S109>/Product' */
  measure_B.Product_i[0] = rtb_ScaleRMSoutputsto1pu * rtb_UnaryMinus_a2 *
    rtb_Divide_jahf;
  measure_B.Product_i[1] = rtb_ScaleRMSoutputsto1pu * rtb_Sum2_g *
    rtb_Divide_jahf;

  /* Switch: '<S128>/Switch' incorporates:
   *  Constant: '<S128>/double'
   *  Sum: '<S128>/Sum2'
   *  UnitDelay: '<S128>/Unit Delay2'
   *  UnitDelay: '<S128>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_b = measure_P.double_Value_of;
  } else {
    measure_B.Switch_b = (measure_B.Product_i[0] +
                          measure_DWork.UnitDelay4_DSTATE_jn) +
      measure_DWork.UnitDelay2_DSTATE_n;
  }

  /* End of Switch: '<S128>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S125>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_h[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOneT_e;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOneT_o) Offset = measure_P.VariableDiscreteDelaywithOneT_o;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_o;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_k = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_o)
      *VDD_in = 0;
  }

  /* Switch: '<S129>/Switch' incorporates:
   *  Constant: '<S129>/double'
   *  Sum: '<S129>/Sum2'
   *  UnitDelay: '<S129>/Unit Delay2'
   *  UnitDelay: '<S129>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_b2 = measure_P.double_Value_ofa;
  } else {
    measure_B.Switch_b2 = (measure_B.Product_i[0] +
      measure_DWork.UnitDelay4_DSTATE_jnq) + measure_DWork.UnitDelay2_DSTATE_np;
  }

  /* End of Switch: '<S129>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S126>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_hk[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_et;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOne_of) Offset = measure_P.VariableDiscreteDelaywithOne_of;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_of;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_kn = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_of)
      *VDD_in = 0;
  }

  /* Switch: '<S120>/Switch1' incorporates:
   *  Sum: '<S120>/Sum1'
   *  Sum: '<S120>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Divide_jahfx5 = measure_B.Switch_b -
      measure_B.VariableDiscreteDelaywithOneT_k;
  } else {
    rtb_Divide_jahfx5 = measure_B.Switch_b2 -
      measure_B.VariableDiscreteDelaywithOne_kn;
  }

  /* End of Switch: '<S120>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S130>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_h[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_p;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product_i[0];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwoT_o) Offset = measure_P.VariableDiscreteDelaywithTwoT_o;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_o;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoT_a = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_o)
      measure_B.VariableDiscreteDelaywithTwoT_p = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoT_p = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_o)
      *VDD_in = 0;
  }

  /* Product: '<S127>/Divide' incorporates:
   *  Product: '<S127>/Product'
   *  Product: '<S127>/Product1'
   *  Sum: '<S127>/Sum1'
   *  Sum: '<S127>/Sum7'
   */
  measure_B.Divide_ja = (rtb_Divide_jahfx5 -
    (measure_B.VariableDiscreteDelaywithTwoT_a * rtb_Subtract3_c0 +
     measure_B.VariableDiscreteDelaywithTwoT_p * rtb_MathFunction_ed1)) *
    rtb_Divide_ja;

  /* Switch: '<S146>/Switch' incorporates:
   *  Constant: '<S146>/double'
   *  Sum: '<S146>/Sum2'
   *  UnitDelay: '<S146>/Unit Delay2'
   *  UnitDelay: '<S146>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_b2j = measure_P.double_Value_ofawrz;
  } else {
    measure_B.Switch_b2j = (measure_B.Divide_ja +
      measure_DWork.UnitDelay4_DSTATE_jnq1) +
      measure_DWork.UnitDelay2_DSTATE_npj;
  }

  /* End of Switch: '<S146>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S143>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_hkv[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_etx;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2j;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOn_ofa) Offset = measure_P.VariableDiscreteDelaywithOn_ofa;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_ofa;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_kne = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_ofa)
      *VDD_in = 0;
  }

  /* Switch: '<S147>/Switch' incorporates:
   *  Constant: '<S147>/double'
   *  Sum: '<S147>/Sum2'
   *  UnitDelay: '<S147>/Unit Delay2'
   *  UnitDelay: '<S147>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_b2jb = measure_P.double_Value_ofawrzy;
  } else {
    measure_B.Switch_b2jb = (measure_B.Divide_ja +
      measure_DWork.UnitDelay4_DSTATE_jnq1h) +
      measure_DWork.UnitDelay2_DSTATE_npjj;
  }

  /* End of Switch: '<S147>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S144>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_hkvl[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_etx1;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jb;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithO_ofaw) Offset = measure_P.VariableDiscreteDelaywithO_ofaw;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_ofaw;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithO_knes = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_ofaw)
      *VDD_in = 0;
  }

  /* Switch: '<S140>/Switch1' incorporates:
   *  Sum: '<S140>/Sum1'
   *  Sum: '<S140>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Divide_jahfx5 = measure_B.Switch_b2j -
      measure_B.VariableDiscreteDelaywithOn_kne;
  } else {
    rtb_Divide_jahfx5 = measure_B.Switch_b2jb -
      measure_B.VariableDiscreteDelaywithO_knes;
  }

  /* End of Switch: '<S140>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S148>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_hj[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_pv;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide_ja;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwo_of) Offset = measure_P.VariableDiscreteDelaywithTwo_of;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_of;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwo_a3 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_of)
      measure_B.VariableDiscreteDelaywithTwo_p2 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwo_p2 = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_of)
      *VDD_in = 0;
  }

  /* Product: '<S145>/Divide' incorporates:
   *  Product: '<S145>/Product'
   *  Product: '<S145>/Product1'
   *  Sum: '<S145>/Sum1'
   *  Sum: '<S145>/Sum7'
   */
  rtb_Divide_jahfx5 = (rtb_Divide_jahfx5 -
                       (measure_B.VariableDiscreteDelaywithTwo_a3 *
                        rtb_Subtract3_c04 +
                        measure_B.VariableDiscreteDelaywithTwo_p2 *
                        rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Switch: '<S134>/Switch' incorporates:
   *  Constant: '<S134>/double'
   *  Sum: '<S134>/Sum2'
   *  UnitDelay: '<S134>/Unit Delay2'
   *  UnitDelay: '<S134>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_b2jbv = measure_P.double_Value_ofaw;
  } else {
    measure_B.Switch_b2jbv = (measure_B.Product_i[1] +
      measure_DWork.UnitDelay4_DSTATE_jnq1hm) +
      measure_DWork.UnitDelay2_DSTATE_npjj1;
  }

  /* End of Switch: '<S134>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S131>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_hkvl3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_etx1w;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywith_ofawr) Offset = measure_P.VariableDiscreteDelaywith_ofawr;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_ofawr;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywith_knesb = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_ofawr)
      *VDD_in = 0;
  }

  /* Switch: '<S135>/Switch' incorporates:
   *  Constant: '<S135>/double'
   *  Sum: '<S135>/Sum2'
   *  UnitDelay: '<S135>/Unit Delay2'
   *  UnitDelay: '<S135>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_b2jbv3 = measure_P.double_Value_ofawr;
  } else {
    measure_B.Switch_b2jbv3 = (measure_B.Product_i[1] +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmy) +
      measure_DWork.UnitDelay2_DSTATE_npjj1p;
  }

  /* End of Switch: '<S135>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S132>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_hkvl35[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_etx1wx;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv3;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywit_ofawrz) Offset = measure_P.VariableDiscreteDelaywit_ofawrz;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_ofawrz;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywit_knesbd = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_ofawrz)
      *VDD_in = 0;
  }

  /* Switch: '<S121>/Switch1' incorporates:
   *  Sum: '<S121>/Sum1'
   *  Sum: '<S121>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_UnaryMinus_dv = measure_B.Switch_b2jbv -
      measure_B.VariableDiscreteDelaywith_knesb;
  } else {
    rtb_UnaryMinus_dv = measure_B.Switch_b2jbv3 -
      measure_B.VariableDiscreteDelaywit_knesbd;
  }

  /* End of Switch: '<S121>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S136>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_hjq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_pv2;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product_i[1];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTw_ofa) Offset = measure_P.VariableDiscreteDelaywithTw_ofa;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_ofa;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTw_a3z = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTw_ofa)
      measure_B.VariableDiscreteDelaywithTw_p20 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTw_p20 = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_ofa)
      *VDD_in = 0;
  }

  /* Product: '<S133>/Divide' incorporates:
   *  Product: '<S133>/Product'
   *  Product: '<S133>/Product1'
   *  Sum: '<S133>/Sum1'
   *  Sum: '<S133>/Sum7'
   */
  measure_B.Divide_jah = (rtb_UnaryMinus_dv -
    (measure_B.VariableDiscreteDelaywithTw_a3z * rtb_Subtract3_c0 +
     measure_B.VariableDiscreteDelaywithTw_p20 * rtb_MathFunction_ed1)) *
    rtb_Divide_ja;

  /* Switch: '<S152>/Switch' incorporates:
   *  Constant: '<S152>/double'
   *  Sum: '<S152>/Sum2'
   *  UnitDelay: '<S152>/Unit Delay2'
   *  UnitDelay: '<S152>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_b2jbv30 = measure_P.double_Value_ofawrzyw;
  } else {
    measure_B.Switch_b2jbv30 = (measure_B.Divide_jah +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyq) +
      measure_DWork.UnitDelay2_DSTATE_npjj1pt;
  }

  /* End of Switch: '<S152>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S149>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_hkvl35c[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_etx1wxm;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywi_ofawrzy) Offset = measure_P.VariableDiscreteDelaywi_ofawrzy;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_ofawrzy;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywi_knesbdm = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_ofawrzy)
      *VDD_in = 0;
  }

  /* Switch: '<S153>/Switch' incorporates:
   *  Constant: '<S153>/double'
   *  Sum: '<S153>/Sum2'
   *  UnitDelay: '<S153>/Unit Delay2'
   *  UnitDelay: '<S153>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_b2jbv30z = measure_P.double_Value_ofawrzywp;
  } else {
    measure_B.Switch_b2jbv30z = (measure_B.Divide_jah +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyqy) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptk;
  }

  /* End of Switch: '<S153>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S150>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_hkvl35cs[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_etx1wxmc;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30z;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelayw_ofawrzyw) Offset = measure_P.VariableDiscreteDelayw_ofawrzyw;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_ofawrzyw;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelayw_knesbdmu = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_ofawrzyw)
      *VDD_in = 0;
  }

  /* Switch: '<S141>/Switch1' incorporates:
   *  Sum: '<S141>/Sum1'
   *  Sum: '<S141>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_UnaryMinus_dv = measure_B.Switch_b2jbv30 -
      measure_B.VariableDiscreteDelaywi_knesbdm;
  } else {
    rtb_UnaryMinus_dv = measure_B.Switch_b2jbv30z -
      measure_B.VariableDiscreteDelayw_knesbdmu;
  }

  /* End of Switch: '<S141>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S154>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_hjqf[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_pv2z;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide_jah;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithT_ofaw) Offset = measure_P.VariableDiscreteDelaywithT_ofaw;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_ofaw;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithT_a3zz = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithT_ofaw)
      measure_B.VariableDiscreteDelaywithT_p20b = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithT_p20b = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_ofaw)
      *VDD_in = 0;
  }

  /* Product: '<S151>/Divide' incorporates:
   *  Product: '<S151>/Product'
   *  Product: '<S151>/Product1'
   *  Sum: '<S151>/Sum1'
   *  Sum: '<S151>/Sum7'
   */
  rtb_UnaryMinus_dv = (rtb_UnaryMinus_dv -
                       (measure_B.VariableDiscreteDelaywithT_a3zz *
                        rtb_Subtract3_c04 +
                        measure_B.VariableDiscreteDelaywithT_p20b *
                        rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Sum: '<S156>/Subtract' incorporates:
   *  Math: '<S156>/Math Function1'
   *  Math: '<S156>/Math Function3'
   */
  rtb_Switch_b = rtb_Divide_jahfx5 * rtb_Divide_jahfx5 + rtb_UnaryMinus_dv *
    rtb_UnaryMinus_dv;

  /* Math: '<S156>/Math Function2'
   *
   * About '<S156>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Switch_b = rtb_Switch_b < 0.0 ? -sqrt(fabs(rtb_Switch_b)) : sqrt
    (rtb_Switch_b);

  /* Gain: '<S12>/Ipk to Irms' incorporates:
   *  Math: '<S156>/Math Function2'
   *
   * About '<S156>/Math Function2':
   *  Operator: sqrt
   */
  rtb_IpktoIrms_a = measure_P.IpktoIrms_Gain * rtb_Switch_b;

  /* UnitDelay: '<S88>/Unit Delay1' */
  rtb_UnitDelay1_f = measure_DWork.UnitDelay1_DSTATE_ou;

  /* Bias: '<S88>/Bias' incorporates:
   *  Gain: '<S88>/Gain'
   */
  rtb_Switch_l40f = measure_P.Gain_Gain_b4 * rtb_Add1_h_idx_0 +
    measure_P.Bias_Bias_m1;

  /* Sum: '<S98>/Sum1' incorporates:
   *  Gain: '<S99>/Gain'
   *  Gain: '<S99>/Gain1'
   *  Inport: '<Root>/Iabc (Amps)'
   *  Math: '<S98>/Math Function'
   *  Product: '<S98>/Product'
   *  Product: '<S98>/Product1'
   *  Sum: '<S99>/Sum1'
   *  Sum: '<S99>/Sum2'
   *  Sum: '<S99>/Sum7'
   *  UnitDelay: '<S88>/Unit Delay1'
   *  UnitDelay: '<S88>/Unit Delay2'
   */
  rtb_Switch_l40f = ((measure_U.IabcAmps[1] - measure_DWork.UnitDelay2_DSTATE_f)
                     * measure_P.Gain_Gain_jf * rtb_Switch_l40f +
                     measure_DWork.UnitDelay1_DSTATE_ou) +
    ((measure_DWork.UnitDelay2_DSTATE_f + measure_U.IabcAmps[1]) *
     measure_P.Gain1_Gain_l - measure_DWork.UnitDelay1_DSTATE_ou) *
    (rtb_Switch_l40f * rtb_Switch_l40f);

  /* Product: '<S172>/Product' */
  measure_B.Product_io[0] = rtb_Switch_l40f * rtb_UnaryMinus_a2 *
    rtb_Divide_jahf;
  measure_B.Product_io[1] = rtb_Switch_l40f * rtb_Sum2_g * rtb_Divide_jahf;

  /* Switch: '<S191>/Switch' incorporates:
   *  Constant: '<S191>/double'
   *  Sum: '<S191>/Sum2'
   *  UnitDelay: '<S191>/Unit Delay2'
   *  UnitDelay: '<S191>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_b2jbv30zm = measure_P.double_Value_ofawrzywpvfxm1;
  } else {
    measure_B.Switch_b2jbv30zm = (measure_B.Product_io[0] +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptkd;
  }

  /* End of Switch: '<S191>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S188>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_hkvl35css[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_etx1wxmcb;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zm;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDelay_ofawrzywp) Offset = measure_P.VariableDiscreteDelay_ofawrzywp;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_ofawrzywp;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelay_knesbdmu1 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_ofawrzywp)
      *VDD_in = 0;
  }

  /* Switch: '<S192>/Switch' incorporates:
   *  Constant: '<S192>/double'
   *  Sum: '<S192>/Sum2'
   *  UnitDelay: '<S192>/Unit Delay2'
   *  UnitDelay: '<S192>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_b2jbv30zmv = measure_P.double_Value_ofawrzywpvfxm1r;
  } else {
    measure_B.Switch_b2jbv30zmv = (measure_B.Product_io[0] +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptkda;
  }

  /* End of Switch: '<S192>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S189>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_hkvl35cssz[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_etx1wxmcbv;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmv;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDela_ofawrzywpv) Offset = measure_P.VariableDiscreteDela_ofawrzywpv;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_ofawrzywpv;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDela_knesbdmu1j = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_ofawrzywpv)
      *VDD_in = 0;
  }

  /* Switch: '<S183>/Switch1' incorporates:
   *  Sum: '<S183>/Sum1'
   *  Sum: '<S183>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Divide_jahfx = measure_B.Switch_b2jbv30zm -
      measure_B.VariableDiscreteDelay_knesbdmu1;
  } else {
    rtb_Divide_jahfx = measure_B.Switch_b2jbv30zmv -
      measure_B.VariableDiscreteDela_knesbdmu1j;
  }

  /* End of Switch: '<S183>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S193>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_hjqfc[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_pv2zv;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product_io[0];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscreteDel_ofawrzywpvf) Offset = measure_P.VariableDiscreteDel_ofawrzywpvf;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_ofawrzywpvf;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywith_a3zzb = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDel_ofawrzywpvf)
      measure_B.VariableDiscreteDelaywith_p20bd = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywith_p20bd = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_ofawrzywpvf)
      *VDD_in = 0;
  }

  /* Product: '<S190>/Divide' incorporates:
   *  Product: '<S190>/Product'
   *  Product: '<S190>/Product1'
   *  Sum: '<S190>/Sum1'
   *  Sum: '<S190>/Sum7'
   */
  measure_B.Divide_jahf = (rtb_Divide_jahfx -
    (measure_B.VariableDiscreteDelaywith_a3zzb * rtb_Subtract3_c0 +
     measure_B.VariableDiscreteDelaywith_p20bd * rtb_MathFunction_ed1)) *
    rtb_Divide_ja;

  /* Switch: '<S209>/Switch' incorporates:
   *  Constant: '<S209>/double'
   *  Sum: '<S209>/Sum2'
   *  UnitDelay: '<S209>/Unit Delay2'
   *  UnitDelay: '<S209>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_b2jbv30zmvu = measure_P.double_Value_h;
  } else {
    measure_B.Switch_b2jbv30zmvu = (measure_B.Divide_jahf +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1i) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf;
  }

  /* End of Switch: '<S209>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S206>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_hkvl35cssz3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_etx1wxmcbvv;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmvu;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteDe_ofawrzywpvfx) Offset = measure_P.VariableDiscreteDe_ofawrzywpvfx;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_ofawrzywpvfx;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDel_knesbdmu1jd = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_ofawrzywpvfx)
      *VDD_in = 0;
  }

  /* Switch: '<S210>/Switch' incorporates:
   *  Constant: '<S210>/double'
   *  Sum: '<S210>/Sum2'
   *  UnitDelay: '<S210>/Unit Delay2'
   *  UnitDelay: '<S210>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_b2jbv30zmvus = measure_P.double_Value_i;
  } else {
    measure_B.Switch_b2jbv30zmvus = (measure_B.Divide_jahf +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1it) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2;
  }

  /* End of Switch: '<S210>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S207>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_hkvl35cssz3u[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_etx1wxmcbvvw;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmvus;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscreteD_ofawrzywpvfxm) Offset = measure_P.VariableDiscreteD_ofawrzywpvfxm;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_ofawrzywpvfxm;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDe_knesbdmu1jdz = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_ofawrzywpvfxm)
      *VDD_in = 0;
  }

  /* Switch: '<S203>/Switch1' incorporates:
   *  Sum: '<S203>/Sum1'
   *  Sum: '<S203>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Divide_jahfx = measure_B.Switch_b2jbv30zmvu -
      measure_B.VariableDiscreteDel_knesbdmu1jd;
  } else {
    rtb_Divide_jahfx = measure_B.Switch_b2jbv30zmvus -
      measure_B.VariableDiscreteDe_knesbdmu1jdz;
  }

  /* End of Switch: '<S203>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S211>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_hjqfcq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_pv2zv2;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide_jahf;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscrete_ofawrzywpvfxm1) Offset = measure_P.VariableDiscrete_ofawrzywpvfxm1;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_ofawrzywpvfxm1;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywit_a3zzbn = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscrete_ofawrzywpvfxm1)
      measure_B.VariableDiscreteDelaywit_p20bdb = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywit_p20bdb = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_ofawrzywpvfxm1)
      *VDD_in = 0;
  }

  /* Product: '<S208>/Divide' incorporates:
   *  Product: '<S208>/Product'
   *  Product: '<S208>/Product1'
   *  Sum: '<S208>/Sum1'
   *  Sum: '<S208>/Sum7'
   */
  rtb_Divide_jahfx = (rtb_Divide_jahfx -
                      (measure_B.VariableDiscreteDelaywit_a3zzbn *
                       rtb_Subtract3_c04 +
                       measure_B.VariableDiscreteDelaywit_p20bdb *
                       rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Switch: '<S197>/Switch' incorporates:
   *  Constant: '<S197>/double'
   *  Sum: '<S197>/Sum2'
   *  UnitDelay: '<S197>/Unit Delay2'
   *  UnitDelay: '<S197>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_b2jbv30zmvusn = measure_P.double_Value_l;
  } else {
    measure_B.Switch_b2jbv30zmvusn = (measure_B.Product_io[1] +
      measure_DWork.UnitDelay4_DSTAT_jnq1hmyqya1it1) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2v;
  }

  /* End of Switch: '<S197>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S194>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_hkvl35cssz3uy[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_etx1wxmcbvvwx;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmvusn;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_ofawrzywpvfxm1r) Offset = measure_P.VariableDiscret_ofawrzywpvfxm1r;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ofawrzywpvfxm1r;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteD_knesbdmu1jdzx = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ofawrzywpvfxm1r)
      *VDD_in = 0;
  }

  /* Switch: '<S198>/Switch' incorporates:
   *  Constant: '<S198>/double'
   *  Sum: '<S198>/Sum2'
   *  UnitDelay: '<S198>/Unit Delay2'
   *  UnitDelay: '<S198>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_b2jbv30zmvusna = measure_P.double_Value_n;
  } else {
    measure_B.Switch_b2jbv30zmvusna = (measure_B.Product_io[1] +
      measure_DWork.UnitDelay4_DSTA_jnq1hmyqya1it1v) +
      measure_DWork.UnitDelay2_DSTAT_npjj1ptkdaf2v0;
  }

  /* End of Switch: '<S198>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S195>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_hkvl35cssz3uyo[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscrete_etx1wxmcbvvwx0;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmvusna;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_l) Offset = measure_P.VariableDiscret_l;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_l;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscrete_knesbdmu1jdzx0 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_l)
      *VDD_in = 0;
  }

  /* Switch: '<S184>/Switch1' incorporates:
   *  Sum: '<S184>/Sum1'
   *  Sum: '<S184>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_UnaryMinus_p = measure_B.Switch_b2jbv30zmvusn -
      measure_B.VariableDiscreteD_knesbdmu1jdzx;
  } else {
    rtb_UnaryMinus_p = measure_B.Switch_b2jbv30zmvusna -
      measure_B.VariableDiscrete_knesbdmu1jdzx0;
  }

  /* End of Switch: '<S184>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S199>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_hjqfcqw[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_pv2zv24;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product_io[1];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_h) Offset = measure_P.VariableDiscret_h;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_h;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywi_a3zzbnn = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_h)
      measure_B.VariableDiscreteDelaywi_p20bdbu = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywi_p20bdbu = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_h)
      *VDD_in = 0;
  }

  /* Product: '<S196>/Divide' incorporates:
   *  Product: '<S196>/Product'
   *  Product: '<S196>/Product1'
   *  Sum: '<S196>/Sum1'
   *  Sum: '<S196>/Sum7'
   */
  measure_B.Divide_jahfx = (rtb_UnaryMinus_p -
    (measure_B.VariableDiscreteDelaywi_a3zzbnn * rtb_Subtract3_c0 +
     measure_B.VariableDiscreteDelaywi_p20bdbu * rtb_MathFunction_ed1)) *
    rtb_Divide_ja;

  /* Switch: '<S215>/Switch' incorporates:
   *  Constant: '<S215>/double'
   *  Sum: '<S215>/Sum2'
   *  UnitDelay: '<S215>/Unit Delay2'
   *  UnitDelay: '<S215>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_b2jbv30zmvusnaw = measure_P.double_Value_k;
  } else {
    measure_B.Switch_b2jbv30zmvusnaw = (measure_B.Divide_jahfx +
      measure_DWork.UnitDelay4_DSTA_p) +
      measure_DWork.UnitDelay2_DSTA_npjj1ptkdaf2v0r;
  }

  /* End of Switch: '<S215>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S212>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_hkvl35cssz3uyos[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_etx1wxmcbvvwx03;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmvusnaw;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_n) Offset = measure_P.VariableDiscret_n;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_n;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_knesbdmu1jdzx0j = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_n)
      *VDD_in = 0;
  }

  /* Switch: '<S216>/Switch' incorporates:
   *  Constant: '<S216>/double'
   *  Sum: '<S216>/Sum2'
   *  UnitDelay: '<S216>/Unit Delay2'
   *  UnitDelay: '<S216>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_n = measure_P.double_Value_a;
  } else {
    measure_B.Switch_n = (measure_B.Divide_jahfx +
                          measure_DWork.UnitDelay4_DSTA_o) +
      measure_DWork.UnitDelay2_DSTA_i;
  }

  /* End of Switch: '<S216>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S213>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a02[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ls;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_n;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_hy) Offset = measure_P.VariableDiscret_hy;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_hy;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_mc = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_hy)
      *VDD_in = 0;
  }

  /* Switch: '<S204>/Switch1' incorporates:
   *  Sum: '<S204>/Sum1'
   *  Sum: '<S204>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_UnaryMinus_p = measure_B.Switch_b2jbv30zmvusnaw -
      measure_B.VariableDiscret_knesbdmu1jdzx0j;
  } else {
    rtb_UnaryMinus_p = measure_B.Switch_n - measure_B.VariableDiscret_mc;
  }

  /* End of Switch: '<S204>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S217>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_hjqfcqwr[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_pv2zv24n;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide_jahfx;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_i) Offset = measure_P.VariableDiscret_i;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_i;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelayw_a3zzbnny = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_i)
      measure_B.VariableDiscreteDelayw_p20bdbus = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelayw_p20bdbus = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_i)
      *VDD_in = 0;
  }

  /* Product: '<S214>/Divide' incorporates:
   *  Product: '<S214>/Product'
   *  Product: '<S214>/Product1'
   *  Sum: '<S214>/Sum1'
   *  Sum: '<S214>/Sum7'
   */
  rtb_UnaryMinus_p = (rtb_UnaryMinus_p -
                      (measure_B.VariableDiscreteDelayw_a3zzbnny *
                       rtb_Subtract3_c04 +
                       measure_B.VariableDiscreteDelayw_p20bdbus *
                       rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Sum: '<S219>/Subtract' incorporates:
   *  Math: '<S219>/Math Function1'
   *  Math: '<S219>/Math Function3'
   */
  rtb_Switch_b2 = rtb_Divide_jahfx * rtb_Divide_jahfx + rtb_UnaryMinus_p *
    rtb_UnaryMinus_p;

  /* Math: '<S219>/Math Function2'
   *
   * About '<S219>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Switch_b2 = rtb_Switch_b2 < 0.0 ? -sqrt(fabs(rtb_Switch_b2)) : sqrt
    (rtb_Switch_b2);

  /* Gain: '<S13>/Ipk to Irms' incorporates:
   *  Math: '<S219>/Math Function2'
   *
   * About '<S219>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Switch1_k = measure_P.IpktoIrms_Gain_h * rtb_Switch_b2;

  /* UnitDelay: '<S89>/Unit Delay1' */
  rtb_UnitDelay1_lu = measure_DWork.UnitDelay1_DSTATE_bn;

  /* Bias: '<S89>/Bias' incorporates:
   *  Gain: '<S89>/Gain'
   */
  rtb_Add1_h_idx_1 = measure_P.Gain_Gain_jx * rtb_Add1_h_idx_1 +
    measure_P.Bias_Bias_oi;

  /* Sum: '<S100>/Sum1' incorporates:
   *  Gain: '<S101>/Gain'
   *  Gain: '<S101>/Gain1'
   *  Inport: '<Root>/Iabc (Amps)'
   *  Math: '<S100>/Math Function'
   *  Product: '<S100>/Product'
   *  Product: '<S100>/Product1'
   *  Sum: '<S101>/Sum1'
   *  Sum: '<S101>/Sum2'
   *  Sum: '<S101>/Sum7'
   *  UnitDelay: '<S89>/Unit Delay1'
   *  UnitDelay: '<S89>/Unit Delay2'
   */
  rtb_Add1_h_idx_1 = ((measure_U.IabcAmps[2] - measure_DWork.UnitDelay2_DSTATE_b)
                      * measure_P.Gain_Gain_o * rtb_Add1_h_idx_1 +
                      measure_DWork.UnitDelay1_DSTATE_bn) +
    ((measure_DWork.UnitDelay2_DSTATE_b + measure_U.IabcAmps[2]) *
     measure_P.Gain1_Gain_m - measure_DWork.UnitDelay1_DSTATE_bn) *
    (rtb_Add1_h_idx_1 * rtb_Add1_h_idx_1);

  /* Product: '<S235>/Product' */
  measure_B.Product_io0[0] = rtb_Add1_h_idx_1 * rtb_UnaryMinus_a2 *
    rtb_Divide_jahf;
  measure_B.Product_io0[1] = rtb_Add1_h_idx_1 * rtb_Sum2_g * rtb_Divide_jahf;

  /* Switch: '<S254>/Switch' incorporates:
   *  Constant: '<S254>/double'
   *  Sum: '<S254>/Sum2'
   *  UnitDelay: '<S254>/Unit Delay2'
   *  UnitDelay: '<S254>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_lf = measure_P.double_Value_g;
  } else {
    measure_B.Switch_lf = (measure_B.Product_io0[0] +
      measure_DWork.UnitDelay4_DSTA_k) + measure_DWork.UnitDelay2_DSTA_g;
  }

  /* End of Switch: '<S254>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S251>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_iy[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_l3;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_lf;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_iy) Offset = measure_P.VariableDiscret_iy;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_iy;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_pu = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_iy)
      *VDD_in = 0;
  }

  /* Switch: '<S255>/Switch' incorporates:
   *  Constant: '<S255>/double'
   *  Sum: '<S255>/Sum2'
   *  UnitDelay: '<S255>/Unit Delay2'
   *  UnitDelay: '<S255>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_jcx = measure_P.double_Value_fo;
  } else {
    measure_B.Switch_jcx = (measure_B.Product_io0[0] +
      measure_DWork.UnitDelay4_DSTA_c) + measure_DWork.UnitDelay2_DSTA_n;
  }

  /* End of Switch: '<S255>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S252>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ad[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_lb;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_jcx;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_ku) Offset = measure_P.VariableDiscret_ku;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ku;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_mi = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ku)
      *VDD_in = 0;
  }

  /* Switch: '<S246>/Switch1' incorporates:
   *  Sum: '<S246>/Sum1'
   *  Sum: '<S246>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Divide_jahf = measure_B.Switch_lf - measure_B.VariableDiscret_pu;
  } else {
    rtb_Divide_jahf = measure_B.Switch_jcx - measure_B.VariableDiscret_mi;
  }

  /* End of Switch: '<S246>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S256>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_hjqfcqwrz[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_pv2zv24nx;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product_io0[0];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_kuf) Offset = measure_P.VariableDiscret_kuf;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_kuf;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelay_a3zzbnnyv = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_kuf)
      measure_B.VariableDiscreteDelay_p20bdbust = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelay_p20bdbust = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_kuf)
      *VDD_in = 0;
  }

  /* Product: '<S253>/Divide' incorporates:
   *  Product: '<S253>/Product'
   *  Product: '<S253>/Product1'
   *  Sum: '<S253>/Sum1'
   *  Sum: '<S253>/Sum7'
   */
  measure_B.Divide_jahfx5 = (rtb_Divide_jahf -
    (measure_B.VariableDiscreteDelay_a3zzbnnyv * rtb_Subtract3_c0 +
     measure_B.VariableDiscreteDelay_p20bdbust * rtb_MathFunction_ed1)) *
    rtb_Divide_ja;

  /* Switch: '<S272>/Switch' incorporates:
   *  Constant: '<S272>/double'
   *  Sum: '<S272>/Sum2'
   *  UnitDelay: '<S272>/Unit Delay2'
   *  UnitDelay: '<S272>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_e = measure_P.double_Value_b;
  } else {
    measure_B.Switch_e = (measure_B.Divide_jahfx5 +
                          measure_DWork.UnitDelay4_DSTA_d) +
      measure_DWork.UnitDelay2_DSTA_k;
  }

  /* End of Switch: '<S272>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S269>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m1[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_a2h;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_e;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_a) Offset = measure_P.VariableDiscret_a;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_a;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_mt = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_a)
      *VDD_in = 0;
  }

  /* Switch: '<S273>/Switch' incorporates:
   *  Constant: '<S273>/double'
   *  Sum: '<S273>/Sum2'
   *  UnitDelay: '<S273>/Unit Delay2'
   *  UnitDelay: '<S273>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_bd = measure_P.double_Value_or;
  } else {
    measure_B.Switch_bd = (measure_B.Divide_jahfx5 +
      measure_DWork.UnitDelay4_DSTA_h) + measure_DWork.UnitDelay2_DSTA_p;
  }

  /* End of Switch: '<S273>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S270>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_g0[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_cm;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_bd;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_k3) Offset = measure_P.VariableDiscret_k3;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_k3;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_fv5 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_k3)
      *VDD_in = 0;
  }

  /* Switch: '<S266>/Switch1' incorporates:
   *  Sum: '<S266>/Sum1'
   *  Sum: '<S266>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Divide_jahf = measure_B.Switch_e - measure_B.VariableDiscret_mt;
  } else {
    rtb_Divide_jahf = measure_B.Switch_bd - measure_B.VariableDiscret_fv5;
  }

  /* End of Switch: '<S266>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S274>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_hjqfcqwrzc[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_pv2zv24nxp;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide_jahfx5;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_aa) Offset = measure_P.VariableDiscret_aa;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_aa;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDela_a3zzbnnyvg = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_aa)
      measure_B.VariableDiscreteDela_p20bdbustl = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDela_p20bdbustl = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_aa)
      *VDD_in = 0;
  }

  /* Product: '<S271>/Divide' incorporates:
   *  Product: '<S271>/Product'
   *  Product: '<S271>/Product1'
   *  Sum: '<S271>/Sum1'
   *  Sum: '<S271>/Sum7'
   */
  rtb_Divide_jahf = (rtb_Divide_jahf -
                     (measure_B.VariableDiscreteDela_a3zzbnnyvg *
                      rtb_Subtract3_c04 +
                      measure_B.VariableDiscreteDela_p20bdbustl *
                      rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Switch: '<S260>/Switch' incorporates:
   *  Constant: '<S260>/double'
   *  Sum: '<S260>/Sum2'
   *  UnitDelay: '<S260>/Unit Delay2'
   *  UnitDelay: '<S260>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_c = measure_P.double_Value_hi;
  } else {
    measure_B.Switch_c = (measure_B.Product_io0[1] +
                          measure_DWork.UnitDelay4_DSTA_f) +
      measure_DWork.UnitDelay2_DSTA_ip;
  }

  /* End of Switch: '<S260>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S257>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_j[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pc;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_c;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_o) Offset = measure_P.VariableDiscret_o;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_o;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_lw = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_o)
      *VDD_in = 0;
  }

  /* Switch: '<S261>/Switch' incorporates:
   *  Constant: '<S261>/double'
   *  Sum: '<S261>/Sum2'
   *  UnitDelay: '<S261>/Unit Delay2'
   *  UnitDelay: '<S261>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_d5 = measure_P.double_Value_iw;
  } else {
    measure_B.Switch_d5 = (measure_B.Product_io0[1] +
      measure_DWork.UnitDelay4_DSTA_o2) + measure_DWork.UnitDelay2_DSTA_h;
  }

  /* End of Switch: '<S261>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S258>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ox[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_am;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_d5;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_d) Offset = measure_P.VariableDiscret_d;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_d;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_fc = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_d)
      *VDD_in = 0;
  }

  /* Switch: '<S247>/Switch1' incorporates:
   *  Sum: '<S247>/Sum1'
   *  Sum: '<S247>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_UnaryMinus_a2 = measure_B.Switch_c - measure_B.VariableDiscret_lw;
  } else {
    rtb_UnaryMinus_a2 = measure_B.Switch_d5 - measure_B.VariableDiscret_fc;
  }

  /* End of Switch: '<S247>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S262>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_hjqfcqwrzc3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_pv2zv24nxpe;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Product_io0[1];

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_k35) Offset = measure_P.VariableDiscret_k35;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_k35;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDel_a3zzbnnyvg5 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_k35)
      measure_B.VariableDiscreteDel_p20bdbustlf = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDel_p20bdbustlf = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_k35)
      *VDD_in = 0;
  }

  /* Product: '<S259>/Divide' incorporates:
   *  Product: '<S259>/Product'
   *  Product: '<S259>/Product1'
   *  Sum: '<S259>/Sum1'
   *  Sum: '<S259>/Sum7'
   */
  measure_B.Divide_jahfx50 = (rtb_UnaryMinus_a2 -
    (measure_B.VariableDiscreteDel_a3zzbnnyvg5 * rtb_Subtract3_c0 +
     measure_B.VariableDiscreteDel_p20bdbustlf * rtb_MathFunction_ed1)) *
    rtb_Divide_ja;

  /* Switch: '<S278>/Switch' incorporates:
   *  Constant: '<S278>/double'
   *  Sum: '<S278>/Sum2'
   *  UnitDelay: '<S278>/Unit Delay2'
   *  UnitDelay: '<S278>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_ik = measure_P.double_Value_bv;
  } else {
    measure_B.Switch_ik = (measure_B.Divide_jahfx50 +
      measure_DWork.UnitDelay4_DSTA_cq) + measure_DWork.UnitDelay2_DSTA_pl;
  }

  /* End of Switch: '<S278>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S275>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m0[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_g05;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ik;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_f) Offset = measure_P.VariableDiscret_f;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_f;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_eg = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_f)
      *VDD_in = 0;
  }

  /* Switch: '<S279>/Switch' incorporates:
   *  Constant: '<S279>/double'
   *  Sum: '<S279>/Sum2'
   *  UnitDelay: '<S279>/Unit Delay2'
   *  UnitDelay: '<S279>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_nb = measure_P.double_Value_j;
  } else {
    measure_B.Switch_nb = (measure_B.Divide_jahfx50 +
      measure_DWork.UnitDelay4_DSTA_a) + measure_DWork.UnitDelay2_DSTA_c;
  }

  /* End of Switch: '<S279>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S276>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_fq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_f4;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_nb;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_g) Offset = measure_P.VariableDiscret_g;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_g;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_d2 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_g)
      *VDD_in = 0;
  }

  /* Switch: '<S267>/Switch1' incorporates:
   *  Sum: '<S267>/Sum1'
   *  Sum: '<S267>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_UnaryMinus_a2 = measure_B.Switch_ik - measure_B.VariableDiscret_eg;
  } else {
    rtb_UnaryMinus_a2 = measure_B.Switch_nb - measure_B.VariableDiscret_d2;
  }

  /* End of Switch: '<S267>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S280>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_hjqfcqwrzc31[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_pv2zv24nxpeb;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Divide_jahfx50;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_ow) Offset = measure_P.VariableDiscret_ow;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ow;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDe_a3zzbnnyvg5z = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_ow)
      measure_B.VariableDiscreteDe_p20bdbustlfs = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDe_p20bdbustlfs = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ow)
      *VDD_in = 0;
  }

  /* Product: '<S277>/Divide' incorporates:
   *  Product: '<S277>/Product'
   *  Product: '<S277>/Product1'
   *  Sum: '<S277>/Sum1'
   *  Sum: '<S277>/Sum7'
   */
  rtb_UnaryMinus_a2 = (rtb_UnaryMinus_a2 -
                       (measure_B.VariableDiscreteDe_a3zzbnnyvg5z *
                        rtb_Subtract3_c04 +
                        measure_B.VariableDiscreteDe_p20bdbustlfs *
                        rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Sum: '<S282>/Subtract' incorporates:
   *  Math: '<S282>/Math Function1'
   *  Math: '<S282>/Math Function3'
   */
  rtb_Sum2_g = rtb_Divide_jahf * rtb_Divide_jahf + rtb_UnaryMinus_a2 *
    rtb_UnaryMinus_a2;

  /* Math: '<S282>/Math Function2'
   *
   * About '<S282>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Switch1_kt5c = rtb_Sum2_g < 0.0 ? -sqrt(fabs(rtb_Sum2_g)) : sqrt
    (rtb_Sum2_g);

  /* Gain: '<S14>/Ipk to Irms' incorporates:
   *  Math: '<S282>/Math Function2'
   *
   * About '<S282>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Switch = measure_P.IpktoIrms_Gain_j * rtb_Switch1_kt5c;

  /* Gain: '<S34>/Gain6' incorporates:
   *  Gain: '<S34>/Gain5'
   *  RealImagToComplex: '<S34>/Real-Imag to Complex'
   *  RealImagToComplex: '<S34>/Real-Imag to Complex1'
   *  RealImagToComplex: '<S34>/Real-Imag to Complex2'
   *  Sum: '<S34>/Sum2'
   */
  rtb_Add1_h_idx = (((measure_P.Gain5_Gain_d[0].re * rtb_Divide_jahfx5 -
                      measure_P.Gain5_Gain_d[0].im * rtb_UnaryMinus_dv) +
                     (measure_P.Gain5_Gain_d[1].re * rtb_Divide_jahfx -
                      measure_P.Gain5_Gain_d[1].im * rtb_UnaryMinus_p)) +
                    (measure_P.Gain5_Gain_d[2].re * rtb_Divide_jahf -
                     measure_P.Gain5_Gain_d[2].im * rtb_UnaryMinus_a2)) *
    measure_P.Gain6_Gain_h;
  rtb_Add1_h_idx_0 = (((measure_P.Gain5_Gain_d[0].re * rtb_UnaryMinus_dv +
                        measure_P.Gain5_Gain_d[0].im * rtb_Divide_jahfx5) +
                       (measure_P.Gain5_Gain_d[1].re * rtb_UnaryMinus_p +
                        measure_P.Gain5_Gain_d[1].im * rtb_Divide_jahfx)) +
                      (measure_P.Gain5_Gain_d[2].re * rtb_UnaryMinus_a2 +
                       measure_P.Gain5_Gain_d[2].im * rtb_Divide_jahf)) *
    measure_P.Gain6_Gain_h;

  /* Sum: '<S56>/Subtract' incorporates:
   *  ComplexToRealImag: '<S34>/Complex to Real-Imag1'
   *  Math: '<S56>/Math Function1'
   *  Math: '<S56>/Math Function3'
   */
  rtb_Sum2_g = rtb_Add1_h_idx * rtb_Add1_h_idx + rtb_Add1_h_idx_0 *
    rtb_Add1_h_idx_0;

  /* Gain: '<S34>/Gain4' incorporates:
   *  Gain: '<S34>/Gain2'
   *  RealImagToComplex: '<S34>/Real-Imag to Complex'
   *  RealImagToComplex: '<S34>/Real-Imag to Complex1'
   *  RealImagToComplex: '<S34>/Real-Imag to Complex2'
   *  Sum: '<S34>/Sum1'
   */
  rtb_MathFunction1 = (((measure_P.Gain2_Gain_bc[0].re * rtb_Divide_jahfx5 -
    measure_P.Gain2_Gain_bc[0].im * rtb_UnaryMinus_dv) +
                        (measure_P.Gain2_Gain_bc[1].re * rtb_Divide_jahfx -
    measure_P.Gain2_Gain_bc[1].im * rtb_UnaryMinus_p)) +
                       (measure_P.Gain2_Gain_bc[2].re * rtb_Divide_jahf -
                        measure_P.Gain2_Gain_bc[2].im * rtb_UnaryMinus_a2)) *
    measure_P.Gain4_Gain_o;
  rtb_Switch1_c = (((measure_P.Gain2_Gain_bc[0].re * rtb_UnaryMinus_dv +
                     measure_P.Gain2_Gain_bc[0].im * rtb_Divide_jahfx5) +
                    (measure_P.Gain2_Gain_bc[1].re * rtb_UnaryMinus_p +
                     measure_P.Gain2_Gain_bc[1].im * rtb_Divide_jahfx)) +
                   (measure_P.Gain2_Gain_bc[2].re * rtb_UnaryMinus_a2 +
                    measure_P.Gain2_Gain_bc[2].im * rtb_Divide_jahf)) *
    measure_P.Gain4_Gain_o;

  /* Sum: '<S54>/Subtract' incorporates:
   *  ComplexToRealImag: '<S34>/Complex to Real-Imag'
   *  Math: '<S54>/Math Function1'
   *  Math: '<S54>/Math Function3'
   */
  rtb_Add1_h_idx_0 = rtb_MathFunction1 * rtb_MathFunction1 + rtb_Switch1_c *
    rtb_Switch1_c;

  /* Math: '<S54>/Math Function2'
   *
   * About '<S54>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Gain_m = rtb_Add1_h_idx_0 < 0.0 ? -sqrt(fabs(rtb_Add1_h_idx_0)) : sqrt
    (rtb_Add1_h_idx_0);

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant'
   *  Constant: '<S59>/Constant'
   *  Math: '<S54>/Math Function2'
   *  RelationalOperator: '<S59>/Compare'
   *
   * About '<S54>/Math Function2':
   *  Operator: sqrt
   */
  if (rtb_Gain_m < measure_P.Constant_Value_or) {
    rtb_Gain_m = measure_P.Constant_Value_bj;
  }

  /* End of Switch: '<S52>/Switch' */

  /* Gain: '<S34>/Gain3' incorporates:
   *  Math: '<S56>/Math Function2'
   *  Product: '<S34>/Product'
   *
   * About '<S56>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Add1_h_idx_0 = (rtb_Sum2_g < 0.0 ? -sqrt(fabs(rtb_Sum2_g)) : sqrt
                      (rtb_Sum2_g)) / rtb_Gain_m * measure_P.Gain3_Gain_l;

  /* Gain: '<S112>/Scale RMS outputs to 1pu' */
  rtb_ScaleRMSoutputsto1pu *= measure_P.ScaleRMSoutputsto1pu_Gain_o;

  /* Math: '<S163>/Math Function' */
  measure_B.MathFunction_k = rtb_ScaleRMSoutputsto1pu * rtb_ScaleRMSoutputsto1pu;

  /* Switch: '<S168>/Switch' incorporates:
   *  Constant: '<S168>/double'
   *  Sum: '<S168>/Sum2'
   *  UnitDelay: '<S168>/Unit Delay2'
   *  UnitDelay: '<S168>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_o = measure_P.double_Value_ofawrzywpv;
  } else {
    measure_B.Switch_o = (measure_B.MathFunction_k +
                          measure_DWork.UnitDelay4_DSTA_n) +
      measure_DWork.UnitDelay2_DSTA_o;
  }

  /* End of Switch: '<S168>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S165>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ep[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_jx;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_o;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_fo) Offset = measure_P.VariableDiscret_fo;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_fo;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_fq = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_fo)
      *VDD_in = 0;
  }

  /* Switch: '<S169>/Switch' incorporates:
   *  Constant: '<S169>/double'
   *  Sum: '<S169>/Sum2'
   *  UnitDelay: '<S169>/Unit Delay2'
   *  UnitDelay: '<S169>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_oo = measure_P.double_Value_ofawrzywpvf;
  } else {
    measure_B.Switch_oo = (measure_B.MathFunction_k +
      measure_DWork.UnitDelay4_DSTA_i) + measure_DWork.UnitDelay2_DSTA_f;
  }

  /* End of Switch: '<S169>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S166>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_cp[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_kc;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_oo;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_hi) Offset = measure_P.VariableDiscret_hi;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_hi;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_eb = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_hi)
      *VDD_in = 0;
  }

  /* Switch: '<S164>/Switch1' incorporates:
   *  Sum: '<S164>/Sum1'
   *  Sum: '<S164>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Sum2_g = measure_B.Switch_o - measure_B.VariableDiscret_fq;
  } else {
    rtb_Sum2_g = measure_B.Switch_oo - measure_B.VariableDiscret_eb;
  }

  /* End of Switch: '<S164>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S170>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_hjqfcqwrzc31p[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_pv2zv24nxpebh;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction_k;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_db) Offset = measure_P.VariableDiscret_db;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_db;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteD_a3zzbnnyvg5zz = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_db)
      measure_B.VariableDiscreteD_p20bdbustlfs4 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteD_p20bdbustlfs4 = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_db)
      *VDD_in = 0;
  }

  /* Product: '<S167>/Divide' incorporates:
   *  Product: '<S167>/Product'
   *  Product: '<S167>/Product1'
   *  Sum: '<S167>/Sum1'
   *  Sum: '<S167>/Sum7'
   */
  rtb_Sum2_g = (rtb_Sum2_g - (measure_B.VariableDiscreteD_a3zzbnnyvg5zz *
    rtb_Subtract3_c0 + measure_B.VariableDiscreteD_p20bdbustlfs4 *
    rtb_MathFunction_ed1)) * rtb_Divide_ja;

  /* Math: '<S163>/Math Function1'
   *
   * About '<S163>/Math Function1':
   *  Operator: sqrt
   */
  measure_B.MathFunction1_g = rtb_Sum2_g < 0.0 ? -sqrt(fabs(rtb_Sum2_g)) : sqrt
    (rtb_Sum2_g);

  /* Switch: '<S116>/Switch' incorporates:
   *  Constant: '<S116>/double'
   *  Sum: '<S116>/Sum2'
   *  UnitDelay: '<S116>/Unit Delay2'
   *  UnitDelay: '<S116>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_g = measure_P.double_Value;
  } else {
    measure_B.Switch_g = (measure_B.MathFunction1_g +
                          measure_DWork.UnitDelay4_DSTA_j) +
      measure_DWork.UnitDelay2_DSTA_j;
  }

  /* End of Switch: '<S116>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S113>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_h[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ld;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_g;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_iw) Offset = measure_P.VariableDiscret_iw;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_iw;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_je = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_iw)
      *VDD_in = 0;
  }

  /* Switch: '<S117>/Switch' incorporates:
   *  Constant: '<S117>/double'
   *  Sum: '<S117>/Sum2'
   *  UnitDelay: '<S117>/Unit Delay2'
   *  UnitDelay: '<S117>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_pp = measure_P.double_Value_o;
  } else {
    measure_B.Switch_pp = (measure_B.MathFunction1_g +
      measure_DWork.UnitDelay4_DSTA_jj) + measure_DWork.UnitDelay2_DSTA_ic;
  }

  /* End of Switch: '<S117>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S114>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c4[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_dd;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_pp;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_b) Offset = measure_P.VariableDiscret_b;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_b;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_pq = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_b)
      *VDD_in = 0;
  }

  /* Switch: '<S108>/Switch1' incorporates:
   *  Sum: '<S108>/Sum1'
   *  Sum: '<S108>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Sum2_g = measure_B.Switch_g - measure_B.VariableDiscret_je;
  } else {
    rtb_Sum2_g = measure_B.Switch_pp - measure_B.VariableDiscret_pq;
  }

  /* End of Switch: '<S108>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S118>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_hjqfcqwrzc31p3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscrete_pv2zv24nxpebhu;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_g;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_ff) Offset = measure_P.VariableDiscret_ff;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ff;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscrete_a3zzbnnyvg5zz5 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_ff)
      measure_B.VariableDiscrete_p20bdbustlfs4u = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscrete_p20bdbustlfs4u = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ff)
      *VDD_in = 0;
  }

  /* Product: '<S115>/Divide' incorporates:
   *  Product: '<S115>/Product'
   *  Product: '<S115>/Product1'
   *  Sum: '<S115>/Sum1'
   *  Sum: '<S115>/Sum7'
   */
  rtb_Sum2_g = (rtb_Sum2_g - (measure_B.VariableDiscrete_a3zzbnnyvg5zz5 *
    rtb_Subtract3_c04 + measure_B.VariableDiscrete_p20bdbustlfs4u *
    rtb_MathFunction_ed12)) * rtb_Divide_jah;

  /* Sum: '<S111>/Sum' incorporates:
   *  Math: '<S111>/Math Function1'
   *  Math: '<S111>/Math Function3'
   *  Math: '<S156>/Math Function2'
   *
   * About '<S156>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Sum2_g = rtb_Sum2_g * rtb_Sum2_g - rtb_Switch_b * rtb_Switch_b;

  /* Switch: '<S157>/Switch' incorporates:
   *  Constant: '<S157>/Constant'
   *  Constant: '<S160>/Constant'
   *  RelationalOperator: '<S160>/Compare'
   */
  if (rtb_Sum2_g < measure_P.Constant_Value_ofawrzywpv) {
    rtb_Sum2_g = measure_P.Constant_Value_o;
  }

  /* End of Switch: '<S157>/Switch' */

  /* Switch: '<S158>/Switch' incorporates:
   *  Constant: '<S158>/Constant'
   *  Constant: '<S161>/Constant'
   *  Math: '<S156>/Math Function2'
   *  RelationalOperator: '<S161>/Compare'
   *
   * About '<S156>/Math Function2':
   *  Operator: sqrt
   */
  if (rtb_Switch_b < measure_P.Constant_Value_ofawrzywpvf) {
    rtb_Switch_b = measure_P.Constant_Value_of;
  }

  /* End of Switch: '<S158>/Switch' */

  /* Gain: '<S111>/Gain' incorporates:
   *  Math: '<S111>/Math Function2'
   *  Product: '<S111>/Product1'
   *
   * About '<S111>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Sum2_g = (rtb_Sum2_g < 0.0 ? -sqrt(fabs(rtb_Sum2_g)) : sqrt(rtb_Sum2_g)) /
    rtb_Switch_b * measure_P.Gain_Gain_of;

  /* Switch: '<S159>/Switch' incorporates:
   *  Constant: '<S159>/Constant'
   *  Constant: '<S162>/Constant'
   *  RelationalOperator: '<S162>/Compare'
   */
  if (rtb_Sum2_g > measure_P.Constant_Value_ofawrzywpvfx) {
    rtb_Sum2_g = measure_P.Constant_Value_ofa;
  }

  /* End of Switch: '<S159>/Switch' */

  /* Gain: '<S175>/Scale RMS outputs to 1pu' */
  rtb_Switch_l40f *= measure_P.ScaleRMSoutputsto1pu_Gain_of;

  /* Math: '<S226>/Math Function' */
  measure_B.MathFunction_k5 = rtb_Switch_l40f * rtb_Switch_l40f;

  /* Switch: '<S231>/Switch' incorporates:
   *  Constant: '<S231>/double'
   *  Sum: '<S231>/Sum2'
   *  UnitDelay: '<S231>/Unit Delay2'
   *  UnitDelay: '<S231>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_cx = measure_P.double_Value_k3;
  } else {
    measure_B.Switch_cx = (measure_B.MathFunction_k5 +
      measure_DWork.UnitDelay4_DSTA_dk) + measure_DWork.UnitDelay2_DSTA_hv;
  }

  /* End of Switch: '<S231>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S228>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_jw[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_hx;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_cx;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_or) Offset = measure_P.VariableDiscret_or;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_or;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_on = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_or)
      *VDD_in = 0;
  }

  /* Switch: '<S232>/Switch' incorporates:
   *  Constant: '<S232>/double'
   *  Sum: '<S232>/Sum2'
   *  UnitDelay: '<S232>/Unit Delay2'
   *  UnitDelay: '<S232>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_ixo = measure_P.double_Value_ow;
  } else {
    measure_B.Switch_ixo = (measure_B.MathFunction_k5 +
      measure_DWork.UnitDelay4_DSTA_dx) + measure_DWork.UnitDelay2_DSTA_l;
  }

  /* End of Switch: '<S232>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S229>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_bg[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ok;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ixo;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_bv) Offset = measure_P.VariableDiscret_bv;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_bv;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_mb = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_bv)
      *VDD_in = 0;
  }

  /* Switch: '<S227>/Switch1' incorporates:
   *  Sum: '<S227>/Sum1'
   *  Sum: '<S227>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_MathFunction1 = measure_B.Switch_cx - measure_B.VariableDiscret_on;
  } else {
    rtb_MathFunction1 = measure_B.Switch_ixo - measure_B.VariableDiscret_mb;
  }

  /* End of Switch: '<S227>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S233>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_hjqfcqwrzc31p34[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pv2zv24nxpebhui;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction_k5;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_ga) Offset = measure_P.VariableDiscret_ga;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ga;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_a3zzbnnyvg5zz54 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_ga)
      measure_B.VariableDiscret_p20bdbustlfs4um = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_p20bdbustlfs4um = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ga)
      *VDD_in = 0;
  }

  /* Product: '<S230>/Divide' incorporates:
   *  Product: '<S230>/Product'
   *  Product: '<S230>/Product1'
   *  Sum: '<S230>/Sum1'
   *  Sum: '<S230>/Sum7'
   */
  rtb_MathFunction1 = (rtb_MathFunction1 -
                       (measure_B.VariableDiscret_a3zzbnnyvg5zz54 *
                        rtb_Subtract3_c0 +
                        measure_B.VariableDiscret_p20bdbustlfs4um *
                        rtb_MathFunction_ed1)) * rtb_Divide_ja;

  /* Math: '<S226>/Math Function1'
   *
   * About '<S226>/Math Function1':
   *  Operator: sqrt
   */
  measure_B.MathFunction1_ge = rtb_MathFunction1 < 0.0 ? -sqrt(fabs
    (rtb_MathFunction1)) : sqrt(rtb_MathFunction1);

  /* Switch: '<S179>/Switch' incorporates:
   *  Constant: '<S179>/double'
   *  Sum: '<S179>/Sum2'
   *  UnitDelay: '<S179>/Unit Delay2'
   *  UnitDelay: '<S179>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_ek = measure_P.double_Value_ofawrzywpvfx;
  } else {
    measure_B.Switch_ek = (measure_B.MathFunction1_ge +
      measure_DWork.UnitDelay4_DSTA_kd) + measure_DWork.UnitDelay2_DSTA_m;
  }

  /* End of Switch: '<S179>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S176>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_on[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_iv;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_ek;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_j) Offset = measure_P.VariableDiscret_j;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_j;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_nz = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_j)
      *VDD_in = 0;
  }

  /* Switch: '<S180>/Switch' incorporates:
   *  Constant: '<S180>/double'
   *  Sum: '<S180>/Sum2'
   *  UnitDelay: '<S180>/Unit Delay2'
   *  UnitDelay: '<S180>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_j3 = measure_P.double_Value_ofawrzywpvfxm;
  } else {
    measure_B.Switch_j3 = (measure_B.MathFunction1_ge +
      measure_DWork.UnitDelay4_DSTA_dr) + measure_DWork.UnitDelay2_DSTA_lr;
  }

  /* End of Switch: '<S180>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S177>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_nr[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_gw;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_j3;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_c) Offset = measure_P.VariableDiscret_c;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_c;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_h5 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_c)
      *VDD_in = 0;
  }

  /* Switch: '<S171>/Switch1' incorporates:
   *  Sum: '<S171>/Sum1'
   *  Sum: '<S171>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_MathFunction1 = measure_B.Switch_ek - measure_B.VariableDiscret_nz;
  } else {
    rtb_MathFunction1 = measure_B.Switch_j3 - measure_B.VariableDiscret_h5;
  }

  /* End of Switch: '<S171>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S181>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_om[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ou;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_ge;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_foe) Offset = measure_P.VariableDiscret_foe;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_foe;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_ho = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_foe)
      measure_B.VariableDiscret_is = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_is = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_foe)
      *VDD_in = 0;
  }

  /* Product: '<S178>/Divide' incorporates:
   *  Product: '<S178>/Product'
   *  Product: '<S178>/Product1'
   *  Sum: '<S178>/Sum1'
   *  Sum: '<S178>/Sum7'
   */
  rtb_MathFunction1 = (rtb_MathFunction1 - (measure_B.VariableDiscret_ho *
    rtb_Subtract3_c04 + measure_B.VariableDiscret_is * rtb_MathFunction_ed12)) *
    rtb_Divide_jah;

  /* Sum: '<S174>/Sum' incorporates:
   *  Math: '<S174>/Math Function1'
   *  Math: '<S174>/Math Function3'
   *  Math: '<S219>/Math Function2'
   *
   * About '<S219>/Math Function2':
   *  Operator: sqrt
   */
  rtb_MathFunction1 = rtb_MathFunction1 * rtb_MathFunction1 - rtb_Switch_b2 *
    rtb_Switch_b2;

  /* Switch: '<S220>/Switch' incorporates:
   *  Constant: '<S220>/Constant'
   *  Constant: '<S223>/Constant'
   *  RelationalOperator: '<S223>/Compare'
   */
  if (rtb_MathFunction1 < measure_P.Constant_Value_ofawrzywpvfxm) {
    rtb_MathFunction1 = measure_P.Constant_Value_ofaw;
  }

  /* End of Switch: '<S220>/Switch' */

  /* Switch: '<S221>/Switch' incorporates:
   *  Constant: '<S221>/Constant'
   *  Constant: '<S224>/Constant'
   *  Math: '<S219>/Math Function2'
   *  RelationalOperator: '<S224>/Compare'
   *
   * About '<S219>/Math Function2':
   *  Operator: sqrt
   */
  if (rtb_Switch_b2 < measure_P.Constant_Value_ofawrzywpvfxm1) {
    rtb_Switch_b2 = measure_P.Constant_Value_ofawr;
  }

  /* End of Switch: '<S221>/Switch' */

  /* Gain: '<S174>/Gain' incorporates:
   *  Math: '<S174>/Math Function2'
   *  Product: '<S174>/Product1'
   *
   * About '<S174>/Math Function2':
   *  Operator: sqrt
   */
  rtb_MathFunction1 = (rtb_MathFunction1 < 0.0 ? -sqrt(fabs(rtb_MathFunction1)) :
                       sqrt(rtb_MathFunction1)) / rtb_Switch_b2 *
    measure_P.Gain_Gain_ofa;

  /* Switch: '<S222>/Switch' incorporates:
   *  Constant: '<S222>/Constant'
   *  Constant: '<S225>/Constant'
   *  RelationalOperator: '<S225>/Compare'
   */
  if (rtb_MathFunction1 > measure_P.Constant_Value_ofawrzywpvfxm1r) {
    rtb_MathFunction1 = measure_P.Constant_Value_ofawrz;
  }

  /* End of Switch: '<S222>/Switch' */

  /* Gain: '<S238>/Scale RMS outputs to 1pu' */
  rtb_Add1_h_idx_1 *= measure_P.ScaleRMSoutputsto1pu_Gain_ofa;

  /* Math: '<S289>/Math Function' */
  measure_B.MathFunction_k5t = rtb_Add1_h_idx_1 * rtb_Add1_h_idx_1;

  /* Switch: '<S294>/Switch' incorporates:
   *  Constant: '<S294>/double'
   *  Sum: '<S294>/Sum2'
   *  UnitDelay: '<S294>/Unit Delay2'
   *  UnitDelay: '<S294>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_a = measure_P.double_Value_c;
  } else {
    measure_B.Switch_a = (measure_B.MathFunction_k5t +
                          measure_DWork.UnitDelay4_DSTA_ny) +
      measure_DWork.UnitDelay2_DSTA_oy;
  }

  /* End of Switch: '<S294>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S291>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pe[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_c2;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_a;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_p) Offset = measure_P.VariableDiscret_p;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_p;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_dl = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_p)
      *VDD_in = 0;
  }

  /* Switch: '<S295>/Switch' incorporates:
   *  Constant: '<S295>/double'
   *  Sum: '<S295>/Sum2'
   *  UnitDelay: '<S295>/Unit Delay2'
   *  UnitDelay: '<S295>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_d0 = measure_P.double_Value_p;
  } else {
    measure_B.Switch_d0 = (measure_B.MathFunction_k5t +
      measure_DWork.UnitDelay4_DSTA_k1) + measure_DWork.UnitDelay2_DSTA_a;
  }

  /* End of Switch: '<S295>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S292>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_k[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_au;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_d0;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_cu) Offset = measure_P.VariableDiscret_cu;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_cu;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_f2 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_cu)
      *VDD_in = 0;
  }

  /* Switch: '<S290>/Switch1' incorporates:
   *  Sum: '<S290>/Sum1'
   *  Sum: '<S290>/Sum2'
   */
  if (rtb_Compare_o) {
    rtb_Add1_h_idx_1 = measure_B.Switch_a - measure_B.VariableDiscret_dl;
  } else {
    rtb_Add1_h_idx_1 = measure_B.Switch_d0 - measure_B.VariableDiscret_f2;
  }

  /* End of Switch: '<S290>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S296>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_mf[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_l4;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction_k5t;

    /*    Offset = measure_B.Switch2_hhsc;  */
    /*    if (Offset > measure_P.VariableDiscret_hin) Offset = measure_P.VariableDiscret_hin;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_hin;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_gz = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_hin)
      measure_B.VariableDiscret_jb = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_jb = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_hin)
      *VDD_in = 0;
  }

  /* Product: '<S293>/Divide' incorporates:
   *  Product: '<S293>/Product'
   *  Product: '<S293>/Product1'
   *  Sum: '<S293>/Sum1'
   *  Sum: '<S293>/Sum7'
   */
  rtb_Divide_ja *= rtb_Add1_h_idx_1 - (measure_B.VariableDiscret_gz *
    rtb_Subtract3_c0 + measure_B.VariableDiscret_jb * rtb_MathFunction_ed1);

  /* Math: '<S289>/Math Function1'
   *
   * About '<S289>/Math Function1':
   *  Operator: sqrt
   */
  measure_B.MathFunction1_ge3 = rtb_Divide_ja < 0.0 ? -sqrt(fabs(rtb_Divide_ja))
    : sqrt(rtb_Divide_ja);

  /* Switch: '<S242>/Switch' incorporates:
   *  Constant: '<S242>/double'
   *  Sum: '<S242>/Sum2'
   *  UnitDelay: '<S242>/Unit Delay2'
   *  UnitDelay: '<S242>/Unit Delay4'
   */
  if (rtb_Compare_bq) {
    measure_B.Switch_h = measure_P.double_Value_d;
  } else {
    measure_B.Switch_h = (measure_B.MathFunction1_ge3 +
                          measure_DWork.UnitDelay4_DSTA_ip) +
      measure_DWork.UnitDelay2_DSTA_ay;
  }

  /* End of Switch: '<S242>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S239>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_p3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_l5;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_h;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_bq) Offset = measure_P.VariableDiscret_bq;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_bq;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_hx = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_bq)
      *VDD_in = 0;
  }

  /* Switch: '<S243>/Switch' incorporates:
   *  Constant: '<S243>/double'
   *  Sum: '<S243>/Sum2'
   *  UnitDelay: '<S243>/Unit Delay2'
   *  UnitDelay: '<S243>/Unit Delay4'
   */
  if (rtb_Compare_cj) {
    measure_B.Switch_it = measure_P.double_Value_f;
  } else {
    measure_B.Switch_it = (measure_B.MathFunction1_ge3 +
      measure_DWork.UnitDelay4_DSTA_hx) + measure_DWork.UnitDelay2_DSTA_la;
  }

  /* End of Switch: '<S243>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S240>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_me[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_hd;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_it;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_f4) Offset = measure_P.VariableDiscret_f4;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_f4;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscret_my = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_f4)
      *VDD_in = 0;
  }

  /* Switch: '<S234>/Switch1' incorporates:
   *  Sum: '<S234>/Sum1'
   *  Sum: '<S234>/Sum2'
   */
  if (rtb_Compare_oafguee) {
    rtb_Add1_h_idx_1 = measure_B.Switch_h - measure_B.VariableDiscret_hx;
  } else {
    rtb_Add1_h_idx_1 = measure_B.Switch_it - measure_B.VariableDiscret_my;
  }

  /* End of Switch: '<S234>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S244>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_onk[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_fe;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_ge3;

    /*    Offset = measure_B.Switch2_hhsca;  */
    /*    if (Offset > measure_P.VariableDiscret_iwf) Offset = measure_P.VariableDiscret_iwf;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_iwf;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_ed = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_iwf)
      measure_B.VariableDiscret_m2 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_m2 = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_iwf)
      *VDD_in = 0;
  }

  /* Product: '<S241>/Divide' incorporates:
   *  Product: '<S241>/Product'
   *  Product: '<S241>/Product1'
   *  Sum: '<S241>/Sum1'
   *  Sum: '<S241>/Sum7'
   */
  rtb_Divide_jah *= rtb_Add1_h_idx_1 - (measure_B.VariableDiscret_ed *
    rtb_Subtract3_c04 + measure_B.VariableDiscret_m2 * rtb_MathFunction_ed12);

  /* Sum: '<S237>/Sum' incorporates:
   *  Math: '<S237>/Math Function1'
   *  Math: '<S237>/Math Function3'
   *  Math: '<S282>/Math Function2'
   *
   * About '<S282>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Add1_h_idx_1 = rtb_Divide_jah * rtb_Divide_jah - rtb_Switch1_kt5c *
    rtb_Switch1_kt5c;

  /* Switch: '<S283>/Switch' incorporates:
   *  Constant: '<S283>/Constant'
   *  Constant: '<S286>/Constant'
   *  RelationalOperator: '<S286>/Compare'
   */
  if (rtb_Add1_h_idx_1 < measure_P.Constant_Value_jo) {
    rtb_Add1_h_idx_1 = measure_P.Constant_Value_ofawrzy;
  }

  /* End of Switch: '<S283>/Switch' */

  /* Switch: '<S284>/Switch' incorporates:
   *  Constant: '<S284>/Constant'
   *  Constant: '<S287>/Constant'
   *  Math: '<S282>/Math Function2'
   *  RelationalOperator: '<S287>/Compare'
   *
   * About '<S282>/Math Function2':
   *  Operator: sqrt
   */
  if (rtb_Switch1_kt5c < measure_P.Constant_Value_c5) {
    rtb_Switch1_kt5c = measure_P.Constant_Value_ofawrzyw;
  }

  /* End of Switch: '<S284>/Switch' */

  /* Gain: '<S237>/Gain' incorporates:
   *  Math: '<S237>/Math Function2'
   *  Product: '<S237>/Product1'
   *
   * About '<S237>/Math Function2':
   *  Operator: sqrt
   */
  rtb_Add1_h_idx_1 = (rtb_Add1_h_idx_1 < 0.0 ? -sqrt(fabs(rtb_Add1_h_idx_1)) :
                      sqrt(rtb_Add1_h_idx_1)) / rtb_Switch1_kt5c *
    measure_P.Gain_Gain_ofaw;

  /* Switch: '<S285>/Switch' incorporates:
   *  Constant: '<S285>/Constant'
   *  Constant: '<S288>/Constant'
   *  RelationalOperator: '<S288>/Compare'
   */
  if (rtb_Add1_h_idx_1 > measure_P.Constant_Value_ps) {
    rtb_Add1_h_idx_1 = measure_P.Constant_Value_ofawrzywp;
  }

  /* End of Switch: '<S285>/Switch' */

  /* Outport: '<Root>/Current' incorporates:
   *  Trigonometry: '<S155>/Trigonometric Function'
   *  Trigonometry: '<S218>/Trigonometric Function'
   *  Trigonometry: '<S281>/Trigonometric Function'
   */
  measure_Y.Current[0] = rtb_IpktoIrms_a;
  measure_Y.Current[1] = rtb_Switch1_k;
  measure_Y.Current[2] = rtb_Switch;
  measure_Y.Current[3] = atan2(rtb_UnaryMinus_dv, rtb_Divide_jahfx5);
  measure_Y.Current[4] = atan2(rtb_UnaryMinus_p, rtb_Divide_jahfx);
  measure_Y.Current[5] = atan2(rtb_UnaryMinus_a2, rtb_Divide_jahf);
  measure_Y.Current[6] = rtb_Add1_h_idx_0;
  measure_Y.Current[7] = rtb_Sum2_g;
  measure_Y.Current[8] = rtb_MathFunction1;
  measure_Y.Current[9] = rtb_Add1_h_idx_1;

  /* Product: '<S12>/Abs(V * I)' */
  rtb_Product_i *= rtb_IpktoIrms_a;

  /* Product: '<S13>/Abs(V * I)' */
  rtb_AbsVI *= rtb_Switch1_k;

  /* Product: '<S14>/Abs(V * I)' */
  rtb_AbsVI_e *= rtb_Switch;

  /* Sum: '<S2>/Sum of Elements' */
  rtb_Product_i += rtb_AbsVI;
  rtb_Product_i += rtb_AbsVI_e;

  /* UnaryMinus: '<S12>/Unary Minus' */
  rtb_UnaryMinus_dv = -rtb_UnaryMinus_dv;

  /* ComplexToRealImag: '<S12>/Complex to Real-Imag' incorporates:
   *  Gain: '<S12>/Ipk to Irms conversion'
   *  Product: '<S12>/Product1'
   *  Product: '<S12>/Vpu, Ipk to Vrms, Irms'
   *  RealImagToComplex: '<S12>/Real-Imag to Complex'
   *  RealImagToComplex: '<S12>/Real-Imag to Complex1'
   */
  rtb_Add1_h_idx_0 = (rtb_Divide_h * rtb_Divide_jahfx5 - rtb_Divide_h3 *
                      rtb_UnaryMinus_dv) * (measure_P.IpktoIrmsconversion_Gain *
    rtb_IpktoIrmsconversion);
  rtb_Sum2_g = (rtb_Divide_h * rtb_UnaryMinus_dv + rtb_Divide_h3 *
                rtb_Divide_jahfx5) * (measure_P.IpktoIrmsconversion_Gain *
    rtb_IpktoIrmsconversion);

  /* UnaryMinus: '<S13>/Unary Minus' */
  rtb_UnaryMinus_p = -rtb_UnaryMinus_p;

  /* ComplexToRealImag: '<S13>/Complex to Real-Imag' incorporates:
   *  Gain: '<S13>/Ipk to Irms conversion'
   *  Product: '<S13>/Product1'
   *  Product: '<S13>/Vpu, Ipk to Vrms, Irms'
   *  RealImagToComplex: '<S13>/Real-Imag to Complex'
   *  RealImagToComplex: '<S13>/Real-Imag to Complex1'
   */
  rtb_MathFunction1 = (rtb_Divide_n * rtb_Divide_jahfx - rtb_Divide_ny *
                       rtb_UnaryMinus_p) * (measure_P.IpktoIrmsconversion_Gain_m
    * rtb_IpktoIrmsconversion);
  rtb_Gain_m = (rtb_Divide_n * rtb_UnaryMinus_p + rtb_Divide_ny *
                rtb_Divide_jahfx) * (measure_P.IpktoIrmsconversion_Gain_m *
    rtb_IpktoIrmsconversion);

  /* UnaryMinus: '<S14>/Unary Minus' */
  rtb_UnaryMinus_a2 = -rtb_UnaryMinus_a2;

  /* Gain: '<S14>/Ipk to Irms conversion' */
  rtb_IpktoIrmsconversion *= measure_P.IpktoIrmsconversion_Gain_f;

  /* Sum: '<S2>/Sum of Elements1' incorporates:
   *  Product: '<S14>/Product1'
   *  Product: '<S14>/Vpu, Ipk to Vrms, Irms'
   *  RealImagToComplex: '<S14>/Real-Imag to Complex'
   *  RealImagToComplex: '<S14>/Real-Imag to Complex1'
   */
  rtb_Add1_h_idx_0 += rtb_MathFunction1;
  rtb_Add1_h_idx_0 += (rtb_Divide_j * rtb_Divide_jahf - rtb_Divide_jw *
                       rtb_UnaryMinus_a2) * rtb_IpktoIrmsconversion;

  /* Sum: '<S2>/Sum of Elements2' incorporates:
   *  Product: '<S14>/Product1'
   *  Product: '<S14>/Vpu, Ipk to Vrms, Irms'
   *  RealImagToComplex: '<S14>/Real-Imag to Complex'
   *  RealImagToComplex: '<S14>/Real-Imag to Complex1'
   */
  rtb_Sum2_g += rtb_Gain_m;
  rtb_Sum2_g += (rtb_Divide_j * rtb_UnaryMinus_a2 + rtb_Divide_jw *
                 rtb_Divide_jahf) * rtb_IpktoIrmsconversion;

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S15>/Constant'
   *  RelationalOperator: '<S15>/Compare'
   */
  if (rtb_Product_i < measure_P.Constant_Value_e4) {
    rtb_Add1_h_idx = measure_P.Constant_Value;
  } else {
    rtb_Add1_h_idx = rtb_Product_i;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Product: '<S2>/Product' */
  rtb_Gain_m = rtb_Add1_h_idx_0 / rtb_Add1_h_idx;

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S16>/Compare'
   *  RelationalOperator: '<S17>/Compare'
   *  Switch: '<S11>/Switch1'
   */
  if (rtb_Gain_m < measure_P.Constant_Value_ck) {
    rtb_MathFunction1 = measure_P.Constant_Value_p;
  } else if (rtb_Gain_m > measure_P.Constant_Value_e) {
    /* Switch: '<S11>/Switch1' incorporates:
     *  Constant: '<S11>/Constant1'
     */
    rtb_MathFunction1 = measure_P.Constant1_Value;
  } else {
    rtb_MathFunction1 = rtb_Gain_m;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Outport: '<Root>/Power' */
  measure_Y.Power[0] = rtb_Product_i;
  measure_Y.Power[1] = rtb_Add1_h_idx_0;
  measure_Y.Power[2] = rtb_Sum2_g;
  measure_Y.Power[3] = rtb_MathFunction1;

  /* Switch: '<S320>/Switch1' incorporates:
   *  Constant: '<S320>/int2'
   */
  if (rtb_Compare_c2os) {
    rtb_Switch1_c1 = measure_P.int2_Value;
  }

  /* End of Switch: '<S320>/Switch1' */

  /* Sum: '<S325>/FixPt Sum1' incorporates:
   *  Constant: '<S325>/FixPt Constant'
   */
  rtb_FixPtSum1 = rtb_Switch1_c1 - measure_P.FixPtConstant_Value_f;

  /* Switch: '<S321>/Switch1' incorporates:
   *  Constant: '<S321>/int2'
   */
  if (rtb_Compare_c2o) {
    rtb_UnitDelay1_pf = measure_P.int2_Value_f;
  }

  /* End of Switch: '<S321>/Switch1' */

  /* Sum: '<S327>/FixPt Sum1' incorporates:
   *  Constant: '<S327>/FixPt Constant'
   */
  rtb_FixPtSum1_j = rtb_UnitDelay1_pf - measure_P.FixPtConstant_Value_fk;

  /* Switch: '<S322>/Switch1' incorporates:
   *  Constant: '<S322>/int2'
   */
  if (rtb_Compare_c2) {
    rtb_Switch1_bxh = measure_P.int2_Value_fk;
  }

  /* End of Switch: '<S322>/Switch1' */

  /* Sum: '<S329>/FixPt Sum1' incorporates:
   *  Constant: '<S329>/FixPt Constant'
   */
  rtb_FixPtSum1_ja = rtb_Switch1_bxh - measure_P.FixPtConstant_Value_fkx;

  /* Switch: '<S319>/Switch' incorporates:
   *  Constant: '<S319>/const'
   *  UnitDelay: '<S319>/Unit Delay1'
   */
  if (rtb_Compare_c2) {
    rtb_Switch1_c1 = measure_DWork.UnitDelay1_DSTATE_omtd1hdputh;
  } else {
    rtb_Switch1_c1 = measure_P.const_Value_h;
  }

  /* End of Switch: '<S319>/Switch' */

  /* RelationalOperator: '<S490>/Compare' incorporates:
   *  Constant: '<S490>/Constant'
   */
  rtb_LogicalOperator_aj = (rtb_Switch1_c1 == measure_P.Constant_Value_hnl);

  /* Logic: '<S312>/Logical Operator8' incorporates:
   *  Logic: '<S501>/Logical Operator1'
   */
  rtb_Compare_c2o = (rtb_LogicalOperator_aj && (rtb_Compare_cz ||
    rtb_Compare_czp || rtb_Compare_czp1));

  /* Logic: '<S331>/Logical Operator' incorporates:
   *  Logic: '<S331>/Logical Operator1'
   *  UnitDelay: '<S331>/delay'
   */
  rtb_LogicalOperator1_f = (rtb_Compare_c2o && (!measure_DWork.delay_DSTATE_e));

  /* Gain: '<S332>/Gain' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  rtb_Gain_m = measure_P.Gain_Gain_ci * measure_P.Constant4_Value_g;

  /* Switch: '<S336>/Switch2' incorporates:
   *  Bias: '<S336>/Bias'
   *  Bias: '<S336>/Bias1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_k = rtb_Gain_m + measure_P.Bias1_Bias;
  } else {
    measure_B.Switch2_k = rtb_Gain_m + measure_P.Bias_Bias;
  }

  /* End of Switch: '<S336>/Switch2' */
  /* S-Function "SF_Cast_double_to_uint32" Block: <S336>/S-Function */
  {
    measure_B.SFunction_o = (unsigned int)measure_B.Switch2_k;
  }

  /* Switch: '<S337>/Switch' incorporates:
   *  Constant: '<S338>/FixPt Constant'
   *  Constant: '<S340>/FixPt Constant'
   *  Sum: '<S338>/FixPt Sum1'
   *  Sum: '<S340>/FixPt Sum1'
   *  UnitDelay: '<S337>/Unit Delay'
   */
  if (rtb_UnitDelay4_ej) {
    rtb_UnitDelay1_pf = measure_B.SFunction_o + measure_P.FixPtConstant_Value_c;
  } else {
    rtb_UnitDelay1_pf = measure_DWork.UnitDelay_DSTATE_im -
      measure_P.FixPtConstant_Value;
  }

  /* End of Switch: '<S337>/Switch' */

  /* RelationalOperator: '<S339>/Compare' incorporates:
   *  Constant: '<S339>/Constant'
   */
  rtb_Compare_cj = (rtb_UnitDelay1_pf > measure_P.Constant_Value_civ);

  /* Switch: '<S337>/Switch1' incorporates:
   *  Constant: '<S337>/int1'
   */
  if (rtb_Compare_cj) {
    rtb_Switch1_bx = rtb_UnitDelay1_pf;
  } else {
    rtb_Switch1_bx = measure_P.int1_Value;
  }

  /* End of Switch: '<S337>/Switch1' */

  /* Logic: '<S333>/Logical Operator' incorporates:
   *  Logic: '<S312>/Logical Operator7'
   *  Logic: '<S312>/Logical Operator9'
   *  UnitDelay: '<S333>/Unit Delay'
   */
  rtb_LogicalOperator2_m = (measure_DWork.UnitDelay_DSTATE_imt ||
    ((!rtb_Compare_cj) && rtb_LogicalOperator1_f));

  /* UnitDelay: '<S335>/Unit Delay1' */
  rtb_UnitDelay1_pf = measure_DWork.UnitDelay1_DSTATE_omtd1hdputhx;

  /* Logic: '<S335>/Logical Operator' incorporates:
   *  UnitDelay: '<S346>/Unit Delay'
   */
  rtb_LogicalOperator1_f = (rtb_UnitDelay4_ej &&
    measure_DWork.UnitDelay_DSTATE_imt2);

  /* Gain: '<S335>/Gain' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtb_Gain_m = measure_P.Gain_Gain_civ * measure_P.Constant3_Value;

  /* Switch: '<S345>/Switch2' incorporates:
   *  Bias: '<S345>/Bias'
   *  Bias: '<S345>/Bias1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_k0 = rtb_Gain_m + measure_P.Bias1_Bias_c;
  } else {
    measure_B.Switch2_k0 = rtb_Gain_m + measure_P.Bias_Bias_c;
  }

  /* End of Switch: '<S345>/Switch2' */
  /* S-Function "SF_Cast_double_to_uint32" Block: <S345>/S-Function */
  {
    measure_B.SFunction_os = (unsigned int)measure_B.Switch2_k0;
  }

  /* Switch: '<S335>/Switch' incorporates:
   *  Constant: '<S347>/FixPt Constant'
   *  Sum: '<S347>/FixPt Sum1'
   */
  if (!rtb_LogicalOperator1_f) {
    rtb_UnitDelay1_pf = measure_B.SFunction_os +
      measure_P.FixPtConstant_Value_ci;
  }

  /* End of Switch: '<S335>/Switch' */

  /* RelationalOperator: '<S343>/Compare' incorporates:
   *  Constant: '<S343>/Constant'
   */
  rtb_Compare_cj = (rtb_UnitDelay1_pf == measure_P.Constant_Value_civ2);

  /* Switch: '<S334>/Switch' incorporates:
   *  Constant: '<S334>/const'
   *  Logic: '<S312>/Logical Operator4'
   *  Logic: '<S501>/Logical Operator7'
   *  UnitDelay: '<S334>/Unit Delay1'
   */
  if (rtb_UnitDelay4_ej && (rtb_RelationalOperator_c && rtb_RelationalOperator_i
       && rtb_RelationalOperator_h)) {
    rtb_Switch1_bxh = measure_DWork.UnitDelay1_DSTATE_omtd1hdputhxn;
  } else {
    rtb_Switch1_bxh = measure_P.const_Value_c;
  }

  /* End of Switch: '<S334>/Switch' */

  /* RelationalOperator: '<S341>/Compare' incorporates:
   *  Constant: '<S341>/Constant'
   */
  rtb_Compare_bq = (rtb_Switch1_bxh == measure_P.Constant_Value_civ2q);

  /* Logic: '<S333>/Logical Operator2' incorporates:
   *  Logic: '<S312>/Logical Operator2'
   *  Logic: '<S333>/Logical Operator1'
   */
  rtb_LogicalOperator1_b2ck = (rtb_LogicalOperator2_m && (!(rtb_Compare_cj ||
    rtb_Compare_bq)));

  /* Switch: '<S334>/Switch1' incorporates:
   *  Constant: '<S334>/int2'
   */
  if (rtb_Compare_bq) {
    rtb_Switch1_bxh = measure_P.int2_Value_c;
  }

  /* End of Switch: '<S334>/Switch1' */

  /* Sum: '<S342>/FixPt Sum1' incorporates:
   *  Constant: '<S342>/FixPt Constant'
   */
  rtb_FixPtSum1_g = rtb_Switch1_bxh - measure_P.FixPtConstant_Value_civ;

  /* Switch: '<S335>/Switch1' incorporates:
   *  Constant: '<S335>/int1'
   */
  if (rtb_Compare_cj) {
    rtb_UnitDelay1_pf = measure_P.int1_Value_c;
  }

  /* End of Switch: '<S335>/Switch1' */

  /* Sum: '<S344>/FixPt Sum1' incorporates:
   *  Constant: '<S344>/FixPt Constant'
   */
  rtb_FixPtSum1_go = rtb_UnitDelay1_pf - measure_P.FixPtConstant_Value_civ2;

  /* Switch: '<S400>/Switch' incorporates:
   *  Constant: '<S400>/double'
   *  Sum: '<S400>/Sum2'
   *  UnitDelay: '<S400>/Unit Delay2'
   *  UnitDelay: '<S400>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_drl4) {
    measure_B.Switch_iwl = measure_P.double_Value_epw;
  } else {
    measure_B.Switch_iwl = (measure_B.ACripple1stestimate +
      measure_DWork.UnitDelay4_DSTATE_krxzyrko) +
      measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm;
  }

  /* End of Switch: '<S400>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S397>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_iqvvodsl[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_pzv45hn0c0;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_iwl;

    /*    Offset = measure_B.Switch2_a4fq3;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOn_epw) Offset = measure_P.VariableDiscreteDelaywithOn_epw;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_epw;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelayw_ndljwvwq = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_epw)
      *VDD_in = 0;
  }

  /* Switch: '<S401>/Switch' incorporates:
   *  Constant: '<S401>/double'
   *  Sum: '<S401>/Sum2'
   *  UnitDelay: '<S401>/Unit Delay2'
   *  UnitDelay: '<S401>/Unit Delay4'
   */
  if (rtb_LogicalOperator_aiui) {
    measure_B.Switch_iwlt = measure_P.double_Value_epwu;
  } else {
    measure_B.Switch_iwlt = (measure_B.ACripple1stestimate +
      measure_DWork.UnitDelay4_DSTATE_krxzyrkob) +
      measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2;
  }

  /* End of Switch: '<S401>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S398>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_iqvvodsli[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_pzv45hn0c03;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_iwlt;

    /*    Offset = measure_B.Switch2_a4fq3;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithO_epwu) Offset = measure_P.VariableDiscreteDelaywithO_epwu;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_epwu;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelay_ndljwvwq0 = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_epwu)
      *VDD_in = 0;
  }

  /* Switch: '<S380>/Switch1' incorporates:
   *  Sum: '<S380>/Sum1'
   *  Sum: '<S380>/Sum2'
   */
  if (rtb_Compare_d) {
    rtb_Add1_h_idx_0 = measure_B.Switch_iwl -
      measure_B.VariableDiscreteDelayw_ndljwvwq;
  } else {
    rtb_Add1_h_idx_0 = measure_B.Switch_iwlt -
      measure_B.VariableDiscreteDelay_ndljwvwq0;
  }

  /* End of Switch: '<S380>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S402>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_bqvb[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_mw3lz;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.ACripple1stestimate;

    /*    Offset = measure_B.Switch2_a4fq3;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwo_ep) Offset = measure_P.VariableDiscreteDelaywithTwo_ep;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_ep;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithT_h0qt = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_ep)
      measure_B.VariableDiscreteDelaywith_gtqs2 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywith_gtqs2 = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_ep)
      *VDD_in = 0;
  }

  /* Sum: '<S315>/Add1' incorporates:
   *  Product: '<S399>/Divide'
   *  Product: '<S399>/Product'
   *  Product: '<S399>/Product1'
   *  Sum: '<S399>/Sum1'
   *  Sum: '<S399>/Sum7'
   */
  rtb_Switch = measure_B.ACripple1stestimate - (rtb_Add1_h_idx_0 -
    (measure_B.VariableDiscreteDelaywithT_h0qt * rtb_Subtract3_o +
     measure_B.VariableDiscreteDelaywith_gtqs2 * rtb_MathFunction_bdy)) *
    rtb_Tps2dt_m;

  /* Bias: '<S443>/Bias' incorporates:
   *  UnitDelay: '<S443>/Unit Delay'
   */
  rtb_Switch_iwltec = measure_DWork.UnitDelay_DSTATE_ehbx +
    measure_P.Bias_Bias_epwu2g;
  if (rtb_Switch_iwltec < measure_DWork.UnitDelay_DSTATE_ehbx) {
    rtb_Switch_iwltec = MAX_uint32_T;
  }

  /* UnitDelay: '<S418>/Unit Delay' */
  rtb_Subtract3_c04 = measure_DWork.UnitDelay_DSTATE_eh;

  /* RelationalOperator: '<S437>/Compare' incorporates:
   *  Constant: '<S437>/Constant'
   *  Signum: '<S388>/Sign'
   *  UnitDelay: '<S418>/Unit Delay'
   */
  rtb_LogicalOperator16 = ((measure_DWork.UnitDelay_DSTATE_eh < 0.0 ? -1.0 :
    measure_DWork.UnitDelay_DSTATE_eh > 0.0 ? 1.0 :
    measure_DWork.UnitDelay_DSTATE_eh) > measure_P.Constant_Value_b5);

  /* Switch: '<S388>/Switch' incorporates:
   *  Constant: '<S388>/Constant'
   *  Logic: '<S434>/Logical Operator'
   *  Logic: '<S434>/Logical Operator1'
   *  Logic: '<S435>/Logical Operator1'
   *  Logic: '<S435>/Logical Operator2'
   *  UnitDelay: '<S434>/delay'
   *  UnitDelay: '<S435>/delay1'
   *  UnitDelay: '<S445>/Unit Delay'
   */
  if (measure_P.Constant_Value_adu) {
    rtb_Compare_cj = (rtb_LogicalOperator16 && (!measure_DWork.delay_DSTATE_n0));
  } else {
    rtb_Compare_cj = ((rtb_LogicalOperator16 ^ measure_DWork.delay1_DSTATE_fk) &&
                      measure_DWork.UnitDelay_DSTATE_ehbxxq);
  }

  /* End of Switch: '<S388>/Switch' */

  /* Logic: '<S388>/Logical Operator1' incorporates:
   *  Logic: '<S388>/Logical Operator2'
   *  UnitDelay: '<S388>/Unit Delay2'
   */
  rtb_Compare_cj = ((!measure_DWork.UnitDelay2_DSTAT_lscnp0r3jm2b3r) &&
                    rtb_Compare_cj);

  /* Switch: '<S443>/Switch2' incorporates:
   *  Bias: '<S443>/Bias'
   *  UnitDelay: '<S443>/Unit Delay2'
   */
  if (rtb_Compare_cj) {
    rtb_Switch2_a = rtb_Switch_iwltec;
  } else {
    rtb_Switch2_a = measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b;
  }

  /* End of Switch: '<S443>/Switch2' */

  /* Switch: '<S441>/Switch' incorporates:
   *  Gain: '<S388>/T2-T1'
   *  Product: '<S388>/Product1'
   *  Sum: '<S388>/Sum'
   *  Switch: '<S442>/Switch'
   *  UnitDelay: '<S388>/Unit Delay1'
   *  UnitDelay: '<S388>/Unit Delay4'
   *  UnitDelay: '<S441>/Unit Delay1'
   *  UnitDelay: '<S442>/Unit Delay1'
   */
  if (rtb_Compare_cj) {
    /* Sum: '<S388>/Sum2' incorporates:
     *  UnitDelay: '<S388>/Unit Delay1'
     *  UnitDelay: '<S418>/Unit Delay'
     */
    rtb_Gain_m = measure_DWork.UnitDelay_DSTATE_eh -
      measure_DWork.UnitDelay1_DSTATE_omt;

    /* Switch: '<S444>/Switch' incorporates:
     *  Constant: '<S455>/Constant'
     *  RelationalOperator: '<S455>/Compare'
     *  UnaryMinus: '<S444>/Unary Minus'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_mk) {
      rtb_Switch1_kt5c = -rtb_Gain_m;
    } else {
      rtb_Switch1_kt5c = rtb_Gain_m;
    }

    /* End of Switch: '<S444>/Switch' */

    /* Switch: '<S388>/Switch1' incorporates:
     *  Constant: '<S388>/Constant1'
     *  Constant: '<S436>/Constant'
     *  RelationalOperator: '<S436>/Compare'
     */
    if (rtb_Switch1_kt5c < measure_P.Constant_Value_e1) {
      rtb_Gain_m = measure_P.Constant1_Value_epwu2g;
    }

    /* End of Switch: '<S388>/Switch1' */
    rtb_Divide_n = measure_DWork.UnitDelay1_DSTATE_omt / rtb_Gain_m *
      measure_P.T2T1_Gain;
    rtb_Divide_ny = rtb_Divide_n - measure_DWork.UnitDelay4_DSTATE_krxzyrkobe;
  } else {
    rtb_Divide_n = measure_DWork.UnitDelay1_DSTATE_omtd;
    rtb_Divide_ny = measure_DWork.UnitDelay1_DSTATE_omtd1;
  }

  /* End of Switch: '<S441>/Switch' */

  /* Sum: '<S388>/Sum1' incorporates:
   *  DataTypeConversion: '<S443>/Data Type Conversion'
   *  Gain: '<S443>/Gain'
   */
  rtb_Add1_h_idx_0 = measure_P.Gain_Gain_epwu * (real_T)rtb_Switch2_a +
    rtb_Divide_ny;

  /* Switch: '<S440>/Switch' incorporates:
   *  Constant: '<S440>/Constant'
   *  Constant: '<S454>/Constant'
   *  RelationalOperator: '<S454>/Compare'
   */
  if (rtb_Add1_h_idx_0 < measure_P.Constant_Value_o5) {
    rtb_Add1_h_idx_0 = measure_P.Constant_Value_c;
  }

  /* End of Switch: '<S440>/Switch' */

  /* Gain: '<S388>/Gain' incorporates:
   *  Math: '<S388>/Math Function'
   *
   * About '<S388>/Math Function':
   *  Operator: reciprocal
   */
  rtb_Divide_h = 1.0 / rtb_Add1_h_idx_0 * measure_P.Gain_Gain_epwu2;

  /* Switch: '<S382>/Switch2' incorporates:
   *  Constant: '<S382>/Constant'
   */
  if (rtb_Compare_no) {
    rtb_Divide_jw = measure_P.Constant_Value_epwu2gd3xo;
  } else {
    /* Sum: '<S382>/Sum1' incorporates:
     *  Gain: '<S315>/Gain'
     *  Sum: '<S315>/Add2'
     *  UnitDelay: '<S315>/Unit Delay1'
     *  UnitDelay: '<S382>/Unit Delay1'
     */
    rtb_Gain_m = (measure_DWork.UnitDelay1_DSTATE_om + rtb_Divide_h) *
      measure_P.Gain_Gain_e - measure_DWork.UnitDelay1_DSTATE_omtd1h;

    /* Switch: '<S406>/Switch' incorporates:
     *  Constant: '<S406>/Constant'
     *  Constant: '<S408>/Constant'
     *  Constant: '<S409>/Constant'
     *  RelationalOperator: '<S408>/Compare'
     *  RelationalOperator: '<S409>/Compare'
     *  Switch: '<S406>/Switch1'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_epwu2gd3) {
      rtb_Gain_m = measure_P.Constant_Value_epwu2;
    } else {
      if (rtb_Gain_m > measure_P.Constant_Value_epwu) {
        /* Switch: '<S406>/Switch1' incorporates:
         *  Constant: '<S406>/Constant1'
         */
        rtb_Gain_m = measure_P.Constant1_Value_ep;
      }
    }

    /* End of Switch: '<S406>/Switch' */

    /* Sum: '<S382>/Sum' incorporates:
     *  UnitDelay: '<S382>/Unit Delay1'
     */
    rtb_Gain_m += measure_DWork.UnitDelay1_DSTATE_omtd1h;

    /* Switch: '<S407>/Switch' incorporates:
     *  Constant: '<S407>/Constant'
     *  Constant: '<S410>/Constant'
     *  Constant: '<S411>/Constant'
     *  RelationalOperator: '<S410>/Compare'
     *  RelationalOperator: '<S411>/Compare'
     *  Switch: '<S407>/Switch1'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_epwu2gd3x) {
      rtb_Divide_jw = measure_P.Constant_Value_epwu2gd;
    } else if (rtb_Gain_m > measure_P.Constant_Value_epwu2g) {
      /* Switch: '<S407>/Switch1' incorporates:
       *  Constant: '<S407>/Constant1'
       */
      rtb_Divide_jw = measure_P.Constant1_Value_epw;
    } else {
      rtb_Divide_jw = rtb_Gain_m;
    }

    /* End of Switch: '<S407>/Switch' */
  }

  /* End of Switch: '<S382>/Switch2' */

  /* Gain: '<S315>/Gain2' */
  rtb_Gain_m = measure_P.Gain2_Gain_ep * rtb_Divide_jw;

  /* Switch: '<S383>/Switch2' */
  if (0.0 != 0.0) {
    /* Switch: '<S383>/Switch1' incorporates:
     *  Bias: '<S383>/Bias'
     *  Bias: '<S383>/Bias1'
     *  Constant: '<S412>/Constant'
     *  RelationalOperator: '<S412>/Compare'
     */
    if (rtb_Gain_m > measure_P.Constant_Value_dh) {
      measure_B.Switch2_a4f = rtb_Gain_m + measure_P.Bias1_Bias_e;
    } else {
      measure_B.Switch2_a4f = rtb_Gain_m + measure_P.Bias_Bias_e;
    }

    /* End of Switch: '<S383>/Switch1' */
  } else {
    measure_B.Switch2_a4f = rtb_Gain_m;
  }

  /* End of Switch: '<S383>/Switch2' */
  /* S-Function "SF_Cast_double_to_int32" Block: <S383>/S-Function */
  {
    measure_B.SFunction_mp = (int)measure_B.Switch2_a4f;
  }

  /* Switch: '<S385>/Switch' incorporates:
   *  Constant: '<S385>/Constant'
   *  Constant: '<S416>/Constant'
   *  DataTypeConversion: '<S390>/Data Type Conversion'
   *  RelationalOperator: '<S416>/Compare'
   */
  if ((real_T)measure_B.SFunction_mp < measure_P.Constant_Value_ef) {
    rtb_Add1_h_idx = measure_P.Constant_Value_epwu2gd3xoy;
  } else {
    rtb_Add1_h_idx = (real_T)measure_B.SFunction_mp;
  }

  /* End of Switch: '<S385>/Switch' */

  /* Sum: '<S381>/Sum1' incorporates:
   *  Math: '<S315>/Math Function1'
   *  Product: '<S315>/Product'
   *  UnitDelay: '<S381>/Unit Delay1'
   *
   * About '<S315>/Math Function1':
   *  Operator: reciprocal
   */
  rtb_Gain_m = 1.0 / rtb_Divide_jw * rtb_Add1_h_idx -
    measure_DWork.UnitDelay1_DSTATE_omtd1hd;

  /* Switch: '<S403>/Switch' incorporates:
   *  Constant: '<S403>/Constant'
   *  Constant: '<S404>/Constant'
   *  Constant: '<S405>/Constant'
   *  RelationalOperator: '<S404>/Compare'
   *  RelationalOperator: '<S405>/Compare'
   *  Switch: '<S403>/Switch1'
   */
  if (rtb_Gain_m < measure_P.Constant_Value_hn) {
    rtb_Sum2_g = measure_P.Constant_Value_epw;
  } else if (rtb_Gain_m > measure_P.Constant_Value_ep) {
    /* Switch: '<S403>/Switch1' incorporates:
     *  Constant: '<S403>/Constant1'
     */
    rtb_Sum2_g = measure_P.Constant1_Value_e;
  } else {
    rtb_Sum2_g = rtb_Gain_m;
  }

  /* End of Switch: '<S403>/Switch' */

  /* Sum: '<S381>/Sum' incorporates:
   *  UnitDelay: '<S381>/Unit Delay1'
   */
  rtb_Divide_j = rtb_Sum2_g + measure_DWork.UnitDelay1_DSTATE_omtd1hd;

  /* Switch: '<S413>/Switch1' incorporates:
   *  Constant: '<S413>/int1'
   */
  if (rtb_Compare_no) {
    rtb_Switch1_gmkuez3wo = rtb_UnitDelay1_nt;
  } else {
    rtb_Switch1_gmkuez3wo = measure_P.int1_Value_e;
  }

  /* End of Switch: '<S413>/Switch1' */

  /* Math: '<S417>/Math Function' incorporates:
   *  Gain: '<S315>/Gain1'
   *  Gain: '<S417>/Gain2'
   *
   * About '<S417>/Math Function':
   *  Operator: exp
   */
  rtb_Sum2_g = exp(measure_P.Gain1_Gain_ep * rtb_Divide_jw *
                   measure_P.Gain2_Gain_epw);

  /* Product: '<S418>/A' incorporates:
   *  Constant: '<S417>/double1'
   *  Sum: '<S417>/Add1'
   */
  rtb_Switch_l40f = (measure_P.double1_Value - rtb_Sum2_g) * rtb_Switch;

  /* Product: '<S418>/B' */
  rtb_Switch1_c = rtb_Subtract3_c04 * rtb_Sum2_g;

  /* Bias: '<S388>/Bias' incorporates:
   *  Gain: '<S388>/Gain1'
   */
  rtb_Add1_h_idx_0 = measure_P.Gain1_Gain_epw * rtb_Add1_h_idx_0 +
    measure_P.Bias_Bias_epwu;

  /* Switch: '<S439>/Switch' incorporates:
   *  Constant: '<S439>/Constant'
   *  Constant: '<S453>/Constant'
   *  RelationalOperator: '<S453>/Compare'
   */
  if (rtb_Add1_h_idx_0 < measure_P.Constant_Value_oi) {
    rtb_Add1_h_idx_0 = measure_P.Constant_Value_k;
  }

  /* End of Switch: '<S439>/Switch' */

  /* Bias: '<S438>/Bias' incorporates:
   *  Gain: '<S438>/Gain'
   */
  rtb_Gain_m = measure_P.Gain_Gain_epwu2g * rtb_Add1_h_idx_0 +
    measure_P.Bias_Bias_epwu2;

  /* Switch: '<S447>/Switch' incorporates:
   *  Constant: '<S447>/Constant'
   *  Constant: '<S449>/Constant'
   *  Constant: '<S450>/Constant'
   *  RelationalOperator: '<S449>/Compare'
   *  RelationalOperator: '<S450>/Compare'
   *  Switch: '<S447>/Switch1'
   */
  if (rtb_Gain_m < measure_P.Constant_Value_pc) {
    rtb_Gain_m = measure_P.Constant_Value_epwu2gd3xoydfl5;
  } else {
    if (rtb_Gain_m > measure_P.Constant_Value_epwu2gd3xoydfl) {
      /* Switch: '<S447>/Switch1' incorporates:
       *  Constant: '<S447>/Constant1'
       */
      rtb_Gain_m = measure_P.Constant1_Value_epwu2;
    }
  }

  /* End of Switch: '<S447>/Switch' */

  /* Switch: '<S446>/Switch2' incorporates:
   *  Bias: '<S446>/Bias'
   *  Bias: '<S446>/Bias1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_a4fq = rtb_Gain_m + measure_P.Bias1_Bias_epw;
  } else {
    measure_B.Switch2_a4fq = rtb_Gain_m + measure_P.Bias_Bias_epw;
  }

  /* End of Switch: '<S446>/Switch2' */
  /* S-Function "SF_Cast_double_to_uint32" Block: <S446>/S-Function */
  {
    measure_B.SFunction_mpm = (unsigned int)measure_B.Switch2_a4fq;
  }

  /* Switch: '<S448>/Switch' incorporates:
   *  Constant: '<S388>/Constant2'
   *  Constant: '<S452>/FixPt Constant'
   *  Logic: '<S388>/Logical Operator'
   *  Sum: '<S452>/FixPt Sum1'
   *  UnitDelay: '<S448>/Unit Delay'
   */
  if (rtb_Compare_cj && measure_P.Constant2_Value_e) {
    rtb_UnitDelay1_nt = measure_B.SFunction_mpm;
  } else {
    rtb_UnitDelay1_nt = measure_DWork.UnitDelay_DSTATE_ehbxx -
      measure_P.FixPtConstant_Value_ep;
  }

  /* End of Switch: '<S448>/Switch' */

  /* RelationalOperator: '<S451>/Compare' incorporates:
   *  Constant: '<S451>/Constant'
   */
  rtb_LogicalOperator9 = (rtb_UnitDelay1_nt > measure_P.Constant_Value_a3);

  /* Switch: '<S448>/Switch1' incorporates:
   *  Constant: '<S448>/int1'
   */
  if (rtb_LogicalOperator9) {
    rtb_Switch1_gmkuez3woc = rtb_UnitDelay1_nt;
  } else {
    rtb_Switch1_gmkuez3woc = measure_P.int1_Value_ep;
  }

  /* End of Switch: '<S448>/Switch1' */

  /* Switch: '<S443>/Switch' incorporates:
   *  Constant: '<S443>/Constant'
   */
  if (rtb_Compare_cj) {
    rtb_Switch_iwltec = measure_P.Constant_Value_hw;
  }

  /* End of Switch: '<S443>/Switch' */

  /* Switch: '<S319>/Switch1' incorporates:
   *  Constant: '<S319>/int2'
   */
  if (rtb_LogicalOperator_aj) {
    rtb_Switch1_c1 = measure_P.int2_Value_h;
  }

  /* End of Switch: '<S319>/Switch1' */

  /* Sum: '<S491>/FixPt Sum1' incorporates:
   *  Constant: '<S491>/FixPt Constant'
   */
  rtb_FixPtSum1_m = rtb_Switch1_c1 - measure_P.FixPtConstant_Value_h;

  /* Switch: '<S505>/Switch' incorporates:
   *  Constant: '<S505>/const'
   *  UnitDelay: '<S505>/Unit Delay1'
   */
  if (rtb_LogicalOperator12) {
    rtb_Switch1_c1 = measure_DWork.UnitDelay1_DSTATE_hf;
  } else {
    rtb_Switch1_c1 = measure_P.const_Value_p;
  }

  /* End of Switch: '<S505>/Switch' */

  /* RelationalOperator: '<S1028>/Compare' incorporates:
   *  Constant: '<S1028>/Constant'
   */
  rtb_LogicalOperator_aj = (rtb_Switch1_c1 == measure_P.Constant_Value_a0);

  /* Logic: '<S494>/Logical Operator8' */
  rtb_Any_Phases_Not_Disturbed = (rtb_LogicalOperator_aj &&
    rtb_Disturbance_All_Phases);

  /* Logic: '<S530>/Logical Operator' incorporates:
   *  Logic: '<S530>/Logical Operator1'
   *  UnitDelay: '<S530>/delay'
   */
  rtb_LogicalOperator1_f = (rtb_Any_Phases_Not_Disturbed &&
    (!measure_DWork.delay_DSTATE_o));

  /* Gain: '<S531>/Gain' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  rtb_Gain_m = measure_P.Gain_Gain_m * measure_P.Constant4_Value_g;

  /* Switch: '<S535>/Switch2' incorporates:
   *  Bias: '<S535>/Bias'
   *  Bias: '<S535>/Bias1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_co = rtb_Gain_m + measure_P.Bias1_Bias_d;
  } else {
    measure_B.Switch2_co = rtb_Gain_m + measure_P.Bias_Bias_d;
  }

  /* End of Switch: '<S535>/Switch2' */
  /* S-Function "SF_Cast_double_to_uint32" Block: <S535>/S-Function */
  {
    measure_B.SFunction_nt = (unsigned int)measure_B.Switch2_co;
  }

  /* Switch: '<S536>/Switch' incorporates:
   *  Constant: '<S537>/FixPt Constant'
   *  Constant: '<S539>/FixPt Constant'
   *  Sum: '<S537>/FixPt Sum1'
   *  Sum: '<S539>/FixPt Sum1'
   *  UnitDelay: '<S536>/Unit Delay'
   */
  if (rtb_UnitDelay4_hd) {
    rtb_UnitDelay1_nt = measure_B.SFunction_nt + measure_P.FixPtConstant_Value_p;
  } else {
    rtb_UnitDelay1_nt = measure_DWork.UnitDelay_DSTATE_cx -
      measure_P.FixPtConstant_Value_m;
  }

  /* End of Switch: '<S536>/Switch' */

  /* RelationalOperator: '<S538>/Compare' incorporates:
   *  Constant: '<S538>/Constant'
   */
  rtb_LogicalOperator12 = (rtb_UnitDelay1_nt > measure_P.Constant_Value_m4);

  /* Switch: '<S536>/Switch1' incorporates:
   *  Constant: '<S536>/int1'
   */
  if (rtb_LogicalOperator12) {
    rtb_Switch1_kn = rtb_UnitDelay1_nt;
  } else {
    rtb_Switch1_kn = measure_P.int1_Value_m;
  }

  /* End of Switch: '<S536>/Switch1' */

  /* Logic: '<S532>/Logical Operator' incorporates:
   *  Logic: '<S494>/Logical Operator7'
   *  Logic: '<S494>/Logical Operator9'
   *  UnitDelay: '<S532>/Unit Delay'
   */
  rtb_LogicalOperator2_b0 = (measure_DWork.UnitDelay_DSTATE_jqi ||
    ((!rtb_LogicalOperator12) && rtb_LogicalOperator1_f));

  /* UnitDelay: '<S534>/Unit Delay1' */
  rtb_UnitDelay1_nt = measure_DWork.UnitDelay1_DSTATE_cx;

  /* Logic: '<S534>/Logical Operator' incorporates:
   *  UnitDelay: '<S545>/Unit Delay'
   */
  rtb_LogicalOperator1_f = (rtb_UnitDelay4_hd &&
    measure_DWork.UnitDelay_DSTATE_l);

  /* Gain: '<S534>/Gain' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtb_Gain_m = measure_P.Gain_Gain_ds * measure_P.Constant3_Value;

  /* Switch: '<S544>/Switch2' incorporates:
   *  Bias: '<S544>/Bias'
   *  Bias: '<S544>/Bias1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_m = rtb_Gain_m + measure_P.Bias1_Bias_b;
  } else {
    measure_B.Switch2_m = rtb_Gain_m + measure_P.Bias_Bias_b;
  }

  /* End of Switch: '<S544>/Switch2' */
  /* S-Function "SF_Cast_double_to_uint32" Block: <S544>/S-Function */
  {
    measure_B.SFunction_p3 = (unsigned int)measure_B.Switch2_m;
  }

  /* Switch: '<S534>/Switch' incorporates:
   *  Constant: '<S546>/FixPt Constant'
   *  Sum: '<S546>/FixPt Sum1'
   */
  if (!rtb_LogicalOperator1_f) {
    rtb_UnitDelay1_nt = measure_B.SFunction_p3 + measure_P.FixPtConstant_Value_j;
  }

  /* End of Switch: '<S534>/Switch' */

  /* RelationalOperator: '<S542>/Compare' incorporates:
   *  Constant: '<S542>/Constant'
   */
  rtb_LogicalOperator12 = (rtb_UnitDelay1_nt == measure_P.Constant_Value_cjo);

  /* Switch: '<S533>/Switch' incorporates:
   *  Constant: '<S533>/const'
   *  Logic: '<S494>/Logical Operator4'
   *  Logic: '<S501>/Logical Operator2'
   *  UnitDelay: '<S533>/Unit Delay1'
   */
  if (rtb_UnitDelay4_hd && (rtb_RelationalOperator_c || rtb_RelationalOperator_i
       || rtb_RelationalOperator_h)) {
    rtb_UnitDelay1_pf = measure_DWork.UnitDelay1_DSTATE_d5;
  } else {
    rtb_UnitDelay1_pf = measure_P.const_Value_e;
  }

  /* End of Switch: '<S533>/Switch' */

  /* RelationalOperator: '<S540>/Compare' incorporates:
   *  Constant: '<S540>/Constant'
   */
  rtb_Compare_cj = (rtb_UnitDelay1_pf == measure_P.Constant_Value_f0);

  /* Logic: '<S532>/Logical Operator2' incorporates:
   *  Logic: '<S494>/Logical Operator2'
   *  Logic: '<S532>/Logical Operator1'
   */
  rtb_LogicalOperator2_m = (rtb_LogicalOperator2_b0 && (!(rtb_LogicalOperator12 ||
    rtb_Compare_cj)));

  /* Switch: '<S533>/Switch1' incorporates:
   *  Constant: '<S533>/int2'
   */
  if (rtb_Compare_cj) {
    rtb_UnitDelay1_pf = measure_P.int2_Value_c2;
  }

  /* End of Switch: '<S533>/Switch1' */

  /* Sum: '<S541>/FixPt Sum1' incorporates:
   *  Constant: '<S541>/FixPt Constant'
   */
  rtb_FixPtSum1_l = rtb_UnitDelay1_pf - measure_P.FixPtConstant_Value_jh;

  /* Switch: '<S534>/Switch1' incorporates:
   *  Constant: '<S534>/int1'
   */
  if (rtb_LogicalOperator12) {
    rtb_UnitDelay1_nt = measure_P.int1_Value_m2;
  }

  /* End of Switch: '<S534>/Switch1' */

  /* Sum: '<S543>/FixPt Sum1' incorporates:
   *  Constant: '<S543>/FixPt Constant'
   */
  rtb_FixPtSum1_h = rtb_UnitDelay1_nt - measure_P.FixPtConstant_Value_jl;

  /* Sum: '<S599>/Sum2' incorporates:
   *  UnitDelay: '<S599>/Unit Delay3'
   */
  rtb_Add1_h_idx_0 = rtb_TrigonometricFunction_l -
    measure_DWork.UnitDelay3_DSTATE_pg;

  /* Switch: '<S610>/Switch1' incorporates:
   *  Bias: '<S610>/Bias1'
   *  Constant: '<S611>/Constant'
   *  Constant: '<S612>/Constant'
   *  RelationalOperator: '<S611>/Compare'
   *  RelationalOperator: '<S612>/Compare'
   *  Switch: '<S610>/Switch'
   */
  if (rtb_Add1_h_idx_0 < measure_P.Constant_Value_e52) {
    rtb_Add1_h_idx_0 += measure_P.Bias1_Bias_e5;
  } else {
    if (rtb_Add1_h_idx_0 > measure_P.Constant_Value_e5) {
      /* Switch: '<S610>/Switch' incorporates:
       *  Bias: '<S610>/Bias'
       */
      rtb_Add1_h_idx_0 += measure_P.Bias_Bias_e5;
    }
  }

  /* End of Switch: '<S610>/Switch1' */

  /* Gain: '<S599>/Gain' */
  rtb_Add1_h_idx_0 *= measure_P.Gain_Gain_ju;

  /* Switch: '<S685>/Switch1' incorporates:
   *  Constant: '<S685>/int1'
   */
  if (rtb_Compare_k1g) {
    rtb_UnitDelay1_k = measure_P.int1_Value_ci;
  }

  /* End of Switch: '<S685>/Switch1' */

  /* Sum: '<S689>/FixPt Sum1' incorporates:
   *  Constant: '<S689>/FixPt Constant'
   */
  rtb_FixPtSum1_a = rtb_UnitDelay1_k - measure_P.FixPtConstant_Value_ci1;

  /* Switch: '<S687>/Switch1' incorporates:
   *  Constant: '<S687>/int2'
   */
  if (rtb_Compare_k1) {
    rtb_Switch1_ce = measure_P.int2_Value_ci;
  }

  /* End of Switch: '<S687>/Switch1' */

  /* Sum: '<S691>/FixPt Sum1' incorporates:
   *  Constant: '<S691>/FixPt Constant'
   */
  rtb_FixPtSum1_an = rtb_Switch1_ce - measure_P.FixPtConstant_Value_ci1z;

  /* Switch: '<S609>/Switch' incorporates:
   *  Constant: '<S699>/Constant'
   *  RelationalOperator: '<S699>/Compare'
   *  UnaryMinus: '<S609>/Unary Minus'
   */
  if (rtb_Add1_h_idx_0 < measure_P.Constant_Value_as) {
    rtb_Add1_h_idx_0 = -rtb_Add1_h_idx_0;
  }

  /* End of Switch: '<S609>/Switch' */

  /* Gain: '<S692>/Gain' */
  rtb_IpktoIrmsconversion = measure_P.Gain_Gain_h1 * rtb_Add1_h_idx_0;

  /* Gain: '<S692>/Gain1' */
  rtb_Divide_jahfx5 = measure_P.Gain1_Gain_h1 * rtb_UnitDelay_j;

  /* Switch: '<S607>/Switch1' incorporates:
   *  Constant: '<S607>/int2'
   */
  if (rtb_Compare_ha) {
    rtb_Switch1_m = measure_P.int2_Value_k;
  }

  /* End of Switch: '<S607>/Switch1' */

  /* Sum: '<S696>/FixPt Sum1' incorporates:
   *  Constant: '<S696>/FixPt Constant'
   */
  rtb_FixPtSum1_c = rtb_Switch1_m - measure_P.FixPtConstant_Value_eb;

  /* Switch: '<S608>/Switch1' incorporates:
   *  Constant: '<S608>/int2'
   */
  if (rtb_Compare_go) {
    rtb_Switch1_d = measure_P.int2_Value_a;
  }

  /* End of Switch: '<S608>/Switch1' */

  /* Sum: '<S698>/FixPt Sum1' incorporates:
   *  Constant: '<S698>/FixPt Constant'
   */
  rtb_FixPtSum1_p = rtb_Switch1_d - measure_P.FixPtConstant_Value_b;

  /* Sum: '<S700>/Sum2' incorporates:
   *  UnitDelay: '<S700>/Unit Delay3'
   */
  rtb_Add1_h_idx_0 = rtb_TrigonometricFunction_c -
    measure_DWork.UnitDelay3_DSTATE_pzl;

  /* Switch: '<S711>/Switch1' incorporates:
   *  Bias: '<S711>/Bias1'
   *  Constant: '<S712>/Constant'
   *  Constant: '<S713>/Constant'
   *  RelationalOperator: '<S712>/Compare'
   *  RelationalOperator: '<S713>/Compare'
   *  Switch: '<S711>/Switch'
   */
  if (rtb_Add1_h_idx_0 < measure_P.Constant_Value_m0j) {
    rtb_Add1_h_idx_0 += measure_P.Bias1_Bias_m;
  } else {
    if (rtb_Add1_h_idx_0 > measure_P.Constant_Value_m0) {
      /* Switch: '<S711>/Switch' incorporates:
       *  Bias: '<S711>/Bias'
       */
      rtb_Add1_h_idx_0 += measure_P.Bias_Bias_m;
    }
  }

  /* End of Switch: '<S711>/Switch1' */

  /* Gain: '<S700>/Gain' */
  rtb_Add1_h_idx_0 *= measure_P.Gain_Gain_fx;

  /* Switch: '<S786>/Switch1' incorporates:
   *  Constant: '<S786>/int1'
   */
  if (rtb_Compare_aun) {
    rtb_Switch1_kyp = measure_P.int1_Value_h;
  }

  /* End of Switch: '<S786>/Switch1' */

  /* Sum: '<S790>/FixPt Sum1' incorporates:
   *  Constant: '<S790>/FixPt Constant'
   */
  rtb_FixPtSum1_ln = rtb_Switch1_kyp - measure_P.FixPtConstant_Value_hg;

  /* Switch: '<S788>/Switch1' incorporates:
   *  Constant: '<S788>/int2'
   */
  if (rtb_Compare_au) {
    rtb_Switch1_ky = measure_P.int2_Value_hg;
  }

  /* End of Switch: '<S788>/Switch1' */

  /* Sum: '<S792>/FixPt Sum1' incorporates:
   *  Constant: '<S792>/FixPt Constant'
   */
  rtb_FixPtSum1_lnu = rtb_Switch1_ky - measure_P.FixPtConstant_Value_hg0;

  /* Switch: '<S710>/Switch' incorporates:
   *  Constant: '<S800>/Constant'
   *  RelationalOperator: '<S800>/Compare'
   *  UnaryMinus: '<S710>/Unary Minus'
   */
  if (rtb_Add1_h_idx_0 < measure_P.Constant_Value_nb) {
    rtb_Add1_h_idx_0 = -rtb_Add1_h_idx_0;
  }

  /* End of Switch: '<S710>/Switch' */

  /* Gain: '<S793>/Gain' */
  rtb_ScaleRMSoutputsto1pu = measure_P.Gain_Gain_g3 * rtb_Add1_h_idx_0;

  /* Gain: '<S793>/Gain1' */
  rtb_AbsVI_e = measure_P.Gain1_Gain_g * rtb_UnitDelay_n;

  /* Switch: '<S708>/Switch1' incorporates:
   *  Constant: '<S708>/int2'
   */
  if (rtb_Compare_df) {
    rtb_Switch1_o = measure_P.int2_Value_n;
  }

  /* End of Switch: '<S708>/Switch1' */

  /* Sum: '<S797>/FixPt Sum1' incorporates:
   *  Constant: '<S797>/FixPt Constant'
   */
  rtb_FixPtSum1_cy = rtb_Switch1_o - measure_P.FixPtConstant_Value_gy;

  /* Switch: '<S709>/Switch1' incorporates:
   *  Constant: '<S709>/int2'
   */
  if (rtb_Compare_eb) {
    rtb_Switch1_cc = measure_P.int2_Value_c5;
  }

  /* End of Switch: '<S709>/Switch1' */

  /* Sum: '<S799>/FixPt Sum1' incorporates:
   *  Constant: '<S799>/FixPt Constant'
   */
  rtb_FixPtSum1_mz = rtb_Switch1_cc - measure_P.FixPtConstant_Value_bi;

  /* Sum: '<S801>/Sum2' incorporates:
   *  UnitDelay: '<S801>/Unit Delay3'
   */
  rtb_Add1_h_idx_0 = rtb_TrigonometricFunction_b -
    measure_DWork.UnitDelay3_DSTATE_ot;

  /* Switch: '<S812>/Switch1' incorporates:
   *  Bias: '<S812>/Bias1'
   *  Constant: '<S813>/Constant'
   *  Constant: '<S814>/Constant'
   *  RelationalOperator: '<S813>/Compare'
   *  RelationalOperator: '<S814>/Compare'
   *  Switch: '<S812>/Switch'
   */
  if (rtb_Add1_h_idx_0 < measure_P.Constant_Value_ki2) {
    rtb_Add1_h_idx_0 += measure_P.Bias1_Bias_ki;
  } else {
    if (rtb_Add1_h_idx_0 > measure_P.Constant_Value_ki) {
      /* Switch: '<S812>/Switch' incorporates:
       *  Bias: '<S812>/Bias'
       */
      rtb_Add1_h_idx_0 += measure_P.Bias_Bias_ki;
    }
  }

  /* End of Switch: '<S812>/Switch1' */

  /* Gain: '<S801>/Gain' */
  rtb_Add1_h_idx_0 *= measure_P.Gain_Gain_kv;

  /* Switch: '<S887>/Switch1' incorporates:
   *  Constant: '<S887>/int1'
   */
  if (rtb_Compare_ge) {
    rtb_Switch1_cgb = measure_P.int1_Value_g;
  }

  /* End of Switch: '<S887>/Switch1' */

  /* Sum: '<S891>/FixPt Sum1' incorporates:
   *  Constant: '<S891>/FixPt Constant'
   */
  rtb_FixPtSum1_f = rtb_Switch1_cgb - measure_P.FixPtConstant_Value_gu;

  /* Switch: '<S889>/Switch1' incorporates:
   *  Constant: '<S889>/int2'
   */
  if (rtb_Compare_g) {
    rtb_Switch1_cg = measure_P.int2_Value_g;
  }

  /* End of Switch: '<S889>/Switch1' */

  /* Sum: '<S893>/FixPt Sum1' incorporates:
   *  Constant: '<S893>/FixPt Constant'
   */
  rtb_Switch1_cgb = rtb_Switch1_cg - measure_P.FixPtConstant_Value_gun;

  /* Switch: '<S811>/Switch' incorporates:
   *  Constant: '<S901>/Constant'
   *  RelationalOperator: '<S901>/Compare'
   *  UnaryMinus: '<S811>/Unary Minus'
   */
  if (rtb_Add1_h_idx_0 < measure_P.Constant_Value_lz) {
    rtb_Add1_h_idx_0 = -rtb_Add1_h_idx_0;
  }

  /* End of Switch: '<S811>/Switch' */

  /* Gain: '<S894>/Gain' */
  rtb_UnaryMinus_dv = measure_P.Gain_Gain_mh * rtb_Add1_h_idx_0;

  /* Gain: '<S894>/Gain1' */
  rtb_Switch_b = measure_P.Gain1_Gain_mh * rtb_UnitDelay_ic;

  /* Switch: '<S809>/Switch1' incorporates:
   *  Constant: '<S809>/int2'
   */
  if (rtb_Compare_m3) {
    rtb_Switch1_k3g = measure_P.int2_Value_c1;
  }

  /* End of Switch: '<S809>/Switch1' */

  /* Sum: '<S898>/FixPt Sum1' incorporates:
   *  Constant: '<S898>/FixPt Constant'
   */
  rtb_Switch1_cc = rtb_Switch1_k3g - measure_P.FixPtConstant_Value_cp;

  /* Switch: '<S810>/Switch1' incorporates:
   *  Constant: '<S810>/int2'
   */
  if (rtb_Compare_o1) {
    rtb_Switch1_oi = measure_P.int2_Value_d;
  }

  /* End of Switch: '<S810>/Switch1' */

  /* Sum: '<S900>/FixPt Sum1' incorporates:
   *  Constant: '<S900>/FixPt Constant'
   */
  rtb_Switch1_o = rtb_Switch1_oi - measure_P.FixPtConstant_Value_fkp;

  /* DataTypeConversion: '<S501>/Data Type Conversion' incorporates:
   *  Constant: '<S914>/Constant'
   *  Constant: '<S915>/Constant'
   *  Constant: '<S916>/Constant'
   *  Constant: '<S917>/Constant'
   *  Constant: '<S918>/Constant'
   *  Constant: '<S919>/Constant'
   *  Constant: '<S920>/Constant'
   *  Constant: '<S921>/Constant'
   *  Logic: '<S501>/Logical Operator10'
   *  Logic: '<S501>/Logical Operator11'
   *  Logic: '<S501>/Logical Operator12'
   *  Logic: '<S501>/Logical Operator5'
   *  Logic: '<S501>/Logical Operator6'
   *  Logic: '<S501>/Logical Operator8'
   *  RelationalOperator: '<S914>/Compare'
   *  RelationalOperator: '<S915>/Compare'
   *  RelationalOperator: '<S916>/Compare'
   *  RelationalOperator: '<S917>/Compare'
   *  RelationalOperator: '<S918>/Compare'
   *  RelationalOperator: '<S919>/Compare'
   *  RelationalOperator: '<S920>/Compare'
   *  RelationalOperator: '<S921>/Compare'
   */
  measure_B.DataTypeConversion = (real_T)((rtb_UnitDelay2_j >
    measure_P.Constant_Value_p0) && (rtb_UnitDelay2_j <
    measure_P.Constant_Value_gby) && ((rtb_Bias > measure_P.Constant_Value_fv) &&
    (rtb_Bias < measure_P.Constant_Value_oy) && ((rtb_Bias1 >
    measure_P.Constant_Value_d4) && (rtb_Bias1 < measure_P.Constant_Value_bx)) &&
    ((rtb_Bias2 > measure_P.Constant_Value_no) && (rtb_Bias2 <
    measure_P.Constant_Value_h3))));

  /* Switch: '<S929>/Switch1' incorporates:
   *  Constant: '<S929>/int1'
   */
  if (rtb_Compare_cz) {
    rtb_Switch1_ky = rtb_Switch_jv;
  } else {
    rtb_Switch1_ky = measure_P.int1_Value_gq;
  }

  /* End of Switch: '<S929>/Switch1' */

  /* Switch: '<S932>/Switch1' incorporates:
   *  Constant: '<S932>/int1'
   */
  if (rtb_Compare_czp) {
    rtb_Switch1_kyp = rtb_Switch_jvw;
  } else {
    rtb_Switch1_kyp = measure_P.int1_Value_gqo;
  }

  /* End of Switch: '<S932>/Switch1' */

  /* Switch: '<S935>/Switch1' incorporates:
   *  Constant: '<S935>/int1'
   */
  if (rtb_Compare_czp1) {
    rtb_UnitDelay1_pf = rtb_Switch_jvwj;
  } else {
    rtb_UnitDelay1_pf = measure_P.int1_Value_gqop;
  }

  /* End of Switch: '<S935>/Switch1' */

  /* Switch: '<S942>/Switch1' incorporates:
   *  Constant: '<S942>/int1'
   */
  if (rtb_Compare_n) {
    rtb_UnitDelay1_nt = rtb_Bias_hsr;
  } else {
    rtb_UnitDelay1_nt = measure_P.int1_Value_cm;
  }

  /* End of Switch: '<S942>/Switch1' */

  /* Switch: '<S941>/Switch1' incorporates:
   *  Constant: '<S941>/int2'
   */
  if (rtb_Compare_mp) {
    rtb_UnitDelay1_n0 = measure_P.int2_Value_o;
  }

  /* End of Switch: '<S941>/Switch1' */

  /* Sum: '<S946>/FixPt Sum1' incorporates:
   *  Constant: '<S946>/FixPt Constant'
   */
  rtb_Switch1_d = rtb_UnitDelay1_n0 - measure_P.FixPtConstant_Value_k;

  /* Switch: '<S968>/Switch' incorporates:
   *  Constant: '<S968>/double'
   *  Sum: '<S968>/Sum2'
   *  UnitDelay: '<S968>/Unit Delay2'
   *  UnitDelay: '<S968>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_bbcu) {
    measure_B.Switch_iln5 = measure_P.double_Value_ii12;
  } else {
    measure_B.Switch_iln5 = (measure_B.ACripple1stestimate_f +
      measure_DWork.UnitDelay4_DSTATE_cvz) + measure_DWork.UnitDelay2_DSTATE_dgh;
  }

  /* End of Switch: '<S968>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S965>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_pbu[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_cjw;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_iln5;

    /*    Offset = measure_B.Switch2_f4;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithOn_ii1) Offset = measure_P.VariableDiscreteDelaywithOn_ii1;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_ii1;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_dra = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_ii1)
      *VDD_in = 0;
  }

  /* Switch: '<S969>/Switch' incorporates:
   *  Constant: '<S969>/double'
   *  Sum: '<S969>/Sum2'
   *  UnitDelay: '<S969>/Unit Delay2'
   *  UnitDelay: '<S969>/Unit Delay4'
   */
  if (rtb_LogicalOperator_ot) {
    measure_B.Switch_iln5l = measure_P.double_Value_ii12h;
  } else {
    measure_B.Switch_iln5l = (measure_B.ACripple1stestimate_f +
      measure_DWork.UnitDelay4_DSTATE_cvzr) +
      measure_DWork.UnitDelay2_DSTATE_dghn;
  }

  /* End of Switch: '<S969>/Switch' */
  /* S-Function Output "SF_VariableDiscreteDelayFaster" Block: <S966>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_pbur[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_cjwa;/* VDD_in integer work vector */
    int_T VDD_out;

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.Switch_iln5l;

    /*    Offset = measure_B.Switch2_f4;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithO_ii12) Offset = measure_P.VariableDiscreteDelaywithO_ii12;    Check omitted in this faster implementation */
    /*    if (Offset < 0) Offset = 0;                                  Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_ii12;/* VDD_out=VDD_out+*MaxDelaySamples+1 */
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithO_drao = VDD_buffer[VDD_out];

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_ii12)
      *VDD_in = 0;
  }

  /* Switch: '<S948>/Switch1' incorporates:
   *  Sum: '<S948>/Sum1'
   *  Sum: '<S948>/Sum2'
   */
  if (rtb_Switch6_idx) {
    rtb_Add1_h_idx_0 = measure_B.Switch_iln5 -
      measure_B.VariableDiscreteDelaywithOn_dra;
  } else {
    rtb_Add1_h_idx_0 = measure_B.Switch_iln5l -
      measure_B.VariableDiscreteDelaywithO_drao;
  }

  /* End of Switch: '<S948>/Switch1' */
  /* S-Function Output "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S970>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_g0[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_oss;/* VDD_in integer work vector */
    int_T VDD_out;
    real_T *Out_ptr;

    /*    int_T   Offset;  */

    /* DelayBufferCountTag    This comment allows a count of these blocks in the RTW c-code file */
    VDD_buffer[*VDD_in] = measure_B.ACripple1stestimate_f;

    /*    Offset = measure_B.Switch2_f4;  */
    /*    if (Offset > measure_P.VariableDiscreteDelaywithTwo_ii) Offset = measure_P.VariableDiscreteDelaywithTwo_ii;    Check omitted in this faster implementation */
    /*    if (Offset < 1) Offset = 1;              Check omitted in this faster implementation */
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_ii;/* VDD_out=VDD_out+MaxDelaySamples+1 */
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwo_oa = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_ii)
      measure_B.VariableDiscreteDelaywithTw_i44 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTw_i44 = *Out_ptr;
    }

    /* Leave VDD_in ready to take the next sample */
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_ii)
      *VDD_in = 0;
  }

  /* Sum: '<S503>/Add1' incorporates:
   *  Product: '<S967>/Divide'
   *  Product: '<S967>/Product'
   *  Product: '<S967>/Product1'
   *  Sum: '<S967>/Sum1'
   *  Sum: '<S967>/Sum7'
   */
  rtb_Switch1_k = measure_B.ACripple1stestimate_f - (rtb_Add1_h_idx_0 -
    (measure_B.VariableDiscreteDelaywithTwo_oa * rtb_Switch_l40f02 +
     measure_B.VariableDiscreteDelaywithTw_i44 * rtb_Switch4)) * rtb_Switch_l4;

  /* Bias: '<S1011>/Bias' incorporates:
   *  UnitDelay: '<S1011>/Unit Delay'
   */
  rtb_UnitDelay1_k = measure_DWork.UnitDelay_DSTATE_jm +
    measure_P.Bias_Bias_gbvu;
  if (rtb_UnitDelay1_k < measure_DWork.UnitDelay_DSTATE_jm) {
    rtb_UnitDelay1_k = MAX_uint32_T;
  }

  /* UnitDelay: '<S986>/Unit Delay' */
  rtb_AbsVI = measure_DWork.UnitDelay_DSTATE_c;

  /* RelationalOperator: '<S1005>/Compare' incorporates:
   *  Constant: '<S1005>/Constant'
   *  Signum: '<S956>/Sign'
   *  UnitDelay: '<S986>/Unit Delay'
   */
  rtb_LogicalOperator2_b0 = ((measure_DWork.UnitDelay_DSTATE_c < 0.0 ? -1.0 :
    measure_DWork.UnitDelay_DSTATE_c > 0.0 ? 1.0 :
    measure_DWork.UnitDelay_DSTATE_c) > measure_P.Constant_Value_gbvuwp);

  /* Switch: '<S956>/Switch' incorporates:
   *  Constant: '<S956>/Constant'
   *  Logic: '<S1002>/Logical Operator'
   *  Logic: '<S1002>/Logical Operator1'
   *  Logic: '<S1003>/Logical Operator1'
   *  Logic: '<S1003>/Logical Operator2'
   *  UnitDelay: '<S1002>/delay'
   *  UnitDelay: '<S1003>/delay1'
   *  UnitDelay: '<S1013>/Unit Delay'
   */
  if (measure_P.Constant_Value_gbvuwpgu2kml1) {
    rtb_LogicalOperator1_bbcu = (rtb_LogicalOperator2_b0 &&
      (!measure_DWork.delay_DSTATE_ep));
  } else {
    rtb_LogicalOperator1_bbcu = ((rtb_LogicalOperator2_b0 ^
      measure_DWork.delay1_DSTATE_l5) && measure_DWork.UnitDelay_DSTATE_jmcy);
  }

  /* End of Switch: '<S956>/Switch' */

  /* Logic: '<S956>/Logical Operator1' incorporates:
   *  Logic: '<S956>/Logical Operator2'
   *  UnitDelay: '<S956>/Unit Delay2'
   */
  rtb_LogicalOperator1_bbcu = ((!measure_DWork.UnitDelay2_DSTATE_ocn) &&
    rtb_LogicalOperator1_bbcu);

  /* Switch: '<S1011>/Switch2' incorporates:
   *  Bias: '<S1011>/Bias'
   *  UnitDelay: '<S1011>/Unit Delay2'
   */
  if (rtb_LogicalOperator1_bbcu) {
    rtb_Switch1_m = rtb_UnitDelay1_k;
  } else {
    rtb_Switch1_m = measure_DWork.UnitDelay2_DSTATE_oc;
  }

  /* End of Switch: '<S1011>/Switch2' */

  /* Switch: '<S1009>/Switch' incorporates:
   *  Gain: '<S956>/T2-T1'
   *  Product: '<S956>/Product1'
   *  Sum: '<S956>/Sum'
   *  Switch: '<S1010>/Switch'
   *  UnitDelay: '<S1009>/Unit Delay1'
   *  UnitDelay: '<S1010>/Unit Delay1'
   *  UnitDelay: '<S956>/Unit Delay1'
   *  UnitDelay: '<S956>/Unit Delay4'
   */
  if (rtb_LogicalOperator1_bbcu) {
    /* Sum: '<S956>/Sum2' incorporates:
     *  UnitDelay: '<S956>/Unit Delay1'
     *  UnitDelay: '<S986>/Unit Delay'
     */
    rtb_Gain_m = measure_DWork.UnitDelay_DSTATE_c -
      measure_DWork.UnitDelay1_DSTATE_gr;

    /* Switch: '<S1012>/Switch' incorporates:
     *  Constant: '<S1023>/Constant'
     *  RelationalOperator: '<S1023>/Compare'
     *  UnaryMinus: '<S1012>/Unary Minus'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_gbvuwpg) {
      rtb_Switch1_kt5c = -rtb_Gain_m;
    } else {
      rtb_Switch1_kt5c = rtb_Gain_m;
    }

    /* End of Switch: '<S1012>/Switch' */

    /* Switch: '<S956>/Switch1' incorporates:
     *  Constant: '<S1004>/Constant'
     *  Constant: '<S956>/Constant1'
     *  RelationalOperator: '<S1004>/Compare'
     */
    if (rtb_Switch1_kt5c < measure_P.Constant_Value_gbvuw) {
      rtb_Gain_m = measure_P.Constant1_Value_gbv;
    }

    /* End of Switch: '<S956>/Switch1' */
    rtb_Product_i = measure_DWork.UnitDelay1_DSTATE_gr / rtb_Gain_m *
      measure_P.T2T1_Gain_g;
    rtb_Add1_h_idx_1 = rtb_Product_i - measure_DWork.UnitDelay4_DSTATE_a;
  } else {
    rtb_Product_i = measure_DWork.UnitDelay1_DSTATE_grk;
    rtb_Add1_h_idx_1 = measure_DWork.UnitDelay1_DSTATE_grkf;
  }

  /* End of Switch: '<S1009>/Switch' */

  /* Sum: '<S956>/Sum1' incorporates:
   *  DataTypeConversion: '<S1011>/Data Type Conversion'
   *  Gain: '<S1011>/Gain'
   */
  rtb_Add1_h_idx_0 = measure_P.Gain_Gain_gb * (real_T)rtb_Switch1_m +
    rtb_Add1_h_idx_1;

  /* Switch: '<S1008>/Switch' incorporates:
   *  Constant: '<S1008>/Constant'
   *  Constant: '<S1022>/Constant'
   *  RelationalOperator: '<S1022>/Compare'
   */
  if (rtb_Add1_h_idx_0 < measure_P.Constant_Value_gbvuwpgu) {
    rtb_Add1_h_idx_0 = measure_P.Constant_Value_gbvu;
  }

  /* End of Switch: '<S1008>/Switch' */

  /* Gain: '<S956>/Gain' incorporates:
   *  Math: '<S956>/Math Function'
   *
   * About '<S956>/Math Function':
   *  Operator: reciprocal
   */
  rtb_IpktoIrms_a = 1.0 / rtb_Add1_h_idx_0 * measure_P.Gain_Gain_gbv;

  /* Switch: '<S950>/Switch2' incorporates:
   *  Constant: '<S950>/Constant'
   */
  if (rtb_Compare_k5) {
    rtb_MathFunction1 = measure_P.Constant_Value_hper21c0u;
  } else {
    /* Sum: '<S950>/Sum1' incorporates:
     *  Gain: '<S503>/Gain'
     *  Sum: '<S503>/Add2'
     *  UnitDelay: '<S503>/Unit Delay1'
     *  UnitDelay: '<S950>/Unit Delay1'
     */
    rtb_Gain_m = (measure_DWork.UnitDelay1_DSTATE_k + rtb_IpktoIrms_a) *
      measure_P.Gain_Gain_ce - measure_DWork.UnitDelay1_DSTATE_j;

    /* Switch: '<S974>/Switch' incorporates:
     *  Constant: '<S974>/Constant'
     *  Constant: '<S976>/Constant'
     *  Constant: '<S977>/Constant'
     *  RelationalOperator: '<S976>/Compare'
     *  RelationalOperator: '<S977>/Compare'
     *  Switch: '<S974>/Switch1'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_hper21c) {
      rtb_Gain_m = measure_P.Constant_Value_hper;
    } else {
      if (rtb_Gain_m > measure_P.Constant_Value_hpe) {
        /* Switch: '<S974>/Switch1' incorporates:
         *  Constant: '<S974>/Constant1'
         */
        rtb_Gain_m = measure_P.Constant1_Value_hpe;
      }
    }

    /* End of Switch: '<S974>/Switch' */

    /* Sum: '<S950>/Sum' incorporates:
     *  UnitDelay: '<S950>/Unit Delay1'
     */
    rtb_Gain_m += measure_DWork.UnitDelay1_DSTATE_j;

    /* Switch: '<S975>/Switch' incorporates:
     *  Constant: '<S975>/Constant'
     *  Constant: '<S978>/Constant'
     *  Constant: '<S979>/Constant'
     *  RelationalOperator: '<S978>/Compare'
     *  RelationalOperator: '<S979>/Compare'
     *  Switch: '<S975>/Switch1'
     */
    if (rtb_Gain_m < measure_P.Constant_Value_hper21c0) {
      rtb_MathFunction1 = measure_P.Constant_Value_hper21;
    } else if (rtb_Gain_m > measure_P.Constant_Value_hper2) {
      /* Switch: '<S975>/Switch1' incorporates:
       *  Constant: '<S975>/Constant1'
       */
      rtb_MathFunction1 = measure_P.Constant1_Value_hper;
    } else {
      rtb_MathFunction1 = rtb_Gain_m;
    }

    /* End of Switch: '<S975>/Switch' */
  }

  /* End of Switch: '<S950>/Switch2' */

  /* Gain: '<S503>/Gain2' */
  rtb_Gain_m = measure_P.Gain2_Gain_j * rtb_MathFunction1;

  /* Switch: '<S951>/Switch2' */
  if (0.0 != 0.0) {
    /* Switch: '<S951>/Switch1' incorporates:
     *  Bias: '<S951>/Bias'
     *  Bias: '<S951>/Bias1'
     *  Constant: '<S980>/Constant'
     *  RelationalOperator: '<S980>/Compare'
     */
    if (rtb_Gain_m > measure_P.Constant_Value_ii) {
      measure_B.Switch2_o = rtb_Gain_m + measure_P.Bias1_Bias_i;
    } else {
      measure_B.Switch2_o = rtb_Gain_m + measure_P.Bias_Bias_i;
    }

    /* End of Switch: '<S951>/Switch1' */
  } else {
    measure_B.Switch2_o = rtb_Gain_m;
  }

  /* End of Switch: '<S951>/Switch2' */
  /* S-Function "SF_Cast_double_to_int32" Block: <S951>/S-Function */
  {
    measure_B.SFunction_p = (int)measure_B.Switch2_o;
  }

  /* Switch: '<S953>/Switch' incorporates:
   *  Constant: '<S953>/Constant'
   *  Constant: '<S984>/Constant'
   *  DataTypeConversion: '<S958>/Data Type Conversion'
   *  RelationalOperator: '<S984>/Compare'
   */
  if ((real_T)measure_B.SFunction_p < measure_P.Constant_Value_gs) {
    rtb_Add1_h_idx = measure_P.Constant_Value_l;
  } else {
    rtb_Add1_h_idx = (real_T)measure_B.SFunction_p;
  }

  /* End of Switch: '<S953>/Switch' */

  /* Sum: '<S949>/Sum1' incorporates:
   *  Math: '<S503>/Math Function1'
   *  Product: '<S503>/Product'
   *  UnitDelay: '<S949>/Unit Delay1'
   *
   * About '<S503>/Math Function1':
   *  Operator: reciprocal
   */
  rtb_Gain_m = 1.0 / rtb_MathFunction1 * rtb_Add1_h_idx -
    measure_DWork.UnitDelay1_DSTATE_d;

  /* Switch: '<S971>/Switch' incorporates:
   *  Constant: '<S971>/Constant'
   *  Constant: '<S972>/Constant'
   *  Constant: '<S973>/Constant'
   *  RelationalOperator: '<S972>/Compare'
   *  RelationalOperator: '<S973>/Compare'
   *  Switch: '<S971>/Switch1'
   */
  if (rtb_Gain_m < measure_P.Constant_Value_fg15t) {
    rtb_Sum2_g = measure_P.Constant_Value_fg15;
  } else if (rtb_Gain_m > measure_P.Constant_Value_fg1) {
    /* Switch: '<S971>/Switch1' incorporates:
     *  Constant: '<S971>/Constant1'
     */
    rtb_Sum2_g = measure_P.Constant1_Value_f;
  } else {
    rtb_Sum2_g = rtb_Gain_m;
  }

  /* End of Switch: '<S971>/Switch' */

  /* Sum: '<S949>/Sum' incorporates:
   *  UnitDelay: '<S949>/Unit Delay1'
   */
  rtb_Switch = rtb_Sum2_g + measure_DWork.UnitDelay1_DSTATE_d;

  /* Switch: '<S981>/Switch1' incorporates:
   *  Constant: '<S981>/int1'
   */
  if (rtb_Compare_k5) {
    rtb_Switch1_ce = rtb_Switch_oh;
  } else {
    rtb_Switch1_ce = measure_P.int1_Value_n;
  }

  /* End of Switch: '<S981>/Switch1' */

  /* Math: '<S985>/Math Function' incorporates:
   *  Gain: '<S503>/Gain1'
   *  Gain: '<S985>/Gain2'
   *
   * About '<S985>/Math Function':
   *  Operator: exp
   */
  rtb_Sum2_g = exp(measure_P.Gain1_Gain_j * rtb_MathFunction1 *
                   measure_P.Gain2_Gain_en);

  /* Product: '<S986>/A' incorporates:
   *  Constant: '<S985>/double1'
   *  Sum: '<S985>/Add1'
   */
  rtb_Switch1_kt5c = (measure_P.double1_Value_e - rtb_Sum2_g) * rtb_Switch1_k;

  /* Bias: '<S956>/Bias' incorporates:
   *  Gain: '<S956>/Gain1'
   */
  rtb_Add1_h_idx_0 = measure_P.Gain1_Gain_gb * rtb_Add1_h_idx_0 +
    measure_P.Bias_Bias_gb;

  /* Switch: '<S1007>/Switch' incorporates:
   *  Constant: '<S1007>/Constant'
   *  Constant: '<S1021>/Constant'
   *  RelationalOperator: '<S1021>/Compare'
   */
  if (rtb_Add1_h_idx_0 < measure_P.Constant_Value_gbvuwpgu2) {
    rtb_Add1_h_idx_0 = measure_P.Constant_Value_gbv;
  }

  /* End of Switch: '<S1007>/Switch' */

  /* Bias: '<S1006>/Bias' incorporates:
   *  Gain: '<S1006>/Gain'
   */
  rtb_Gain_m = measure_P.Gain_Gain_gbvu * rtb_Add1_h_idx_0 +
    measure_P.Bias_Bias_gbv;

  /* Switch: '<S1015>/Switch' incorporates:
   *  Constant: '<S1015>/Constant'
   *  Constant: '<S1017>/Constant'
   *  Constant: '<S1018>/Constant'
   *  RelationalOperator: '<S1017>/Compare'
   *  RelationalOperator: '<S1018>/Compare'
   *  Switch: '<S1015>/Switch1'
   */
  if (rtb_Gain_m < measure_P.Constant_Value_gbvuwpgu2k) {
    rtb_Gain_m = measure_P.Constant_Value_gb;
  } else {
    if (rtb_Gain_m > measure_P.Constant_Value_g) {
      /* Switch: '<S1015>/Switch1' incorporates:
       *  Constant: '<S1015>/Constant1'
       */
      rtb_Gain_m = measure_P.Constant1_Value_gb;
    }
  }

  /* End of Switch: '<S1015>/Switch' */

  /* Switch: '<S1014>/Switch2' incorporates:
   *  Bias: '<S1014>/Bias'
   *  Bias: '<S1014>/Bias1'
   */
  if (0.0 != 0.0) {
    measure_B.Switch2_g = rtb_Gain_m + measure_P.Bias1_Bias_g;
  } else {
    measure_B.Switch2_g = rtb_Gain_m + measure_P.Bias_Bias_g;
  }

  /* End of Switch: '<S1014>/Switch2' */
  /* S-Function "SF_Cast_double_to_uint32" Block: <S1014>/S-Function */
  {
    measure_B.SFunction_ne = (unsigned int)measure_B.Switch2_g;
  }

  /* Switch: '<S1016>/Switch' incorporates:
   *  Constant: '<S1020>/FixPt Constant'
   *  Constant: '<S956>/Constant2'
   *  Logic: '<S956>/Logical Operator'
   *  Sum: '<S1020>/FixPt Sum1'
   *  UnitDelay: '<S1016>/Unit Delay'
   */
  if (rtb_LogicalOperator1_bbcu && measure_P.Constant2_Value_g) {
    rtb_UnitDelay1_n0 = measure_B.SFunction_ne;
  } else {
    rtb_UnitDelay1_n0 = measure_DWork.UnitDelay_DSTATE_jmc -
      measure_P.FixPtConstant_Value_gb;
  }

  /* End of Switch: '<S1016>/Switch' */

  /* RelationalOperator: '<S1019>/Compare' incorporates:
   *  Constant: '<S1019>/Constant'
   */
  rtb_LogicalOperator1_f = (rtb_UnitDelay1_n0 >
    measure_P.Constant_Value_gbvuwpgu2kml);

  /* Switch: '<S1016>/Switch1' incorporates:
   *  Constant: '<S1016>/int1'
   */
  if (rtb_LogicalOperator1_f) {
    rtb_Switch1_bxh = rtb_UnitDelay1_n0;
  } else {
    rtb_Switch1_bxh = measure_P.int1_Value_gb;
  }

  /* End of Switch: '<S1016>/Switch1' */

  /* Switch: '<S1011>/Switch' incorporates:
   *  Bias: '<S1011>/Bias'
   *  Constant: '<S1011>/Constant'
   */
  if (rtb_LogicalOperator1_bbcu) {
    rtb_UnitDelay1_n0 = measure_P.Constant_Value_gbvuwpgu2km;
  } else {
    rtb_UnitDelay1_n0 = rtb_UnitDelay1_k;
  }

  /* End of Switch: '<S1011>/Switch' */

  /* Switch: '<S505>/Switch1' incorporates:
   *  Constant: '<S505>/int2'
   */
  if (rtb_LogicalOperator_aj) {
    rtb_Switch1_c1 = measure_P.int2_Value_gx;
  }

  /* End of Switch: '<S505>/Switch1' */

  /* Sum: '<S1029>/FixPt Sum1' incorporates:
   *  Constant: '<S1029>/FixPt Constant'
   */
  rtb_UnitDelay1_k = rtb_Switch1_c1 - measure_P.FixPtConstant_Value_mp;

  /* S-Function "SF_SingleSampleDelay" Block: <S1027>/SF_FixedDiscreteDelay S-function */
  {
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunction_;
    *xD = measure_B.Switch_m;
  }

  /* Update for UnitDelay: '<S494>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_ep = rtb_LogicalOperator2_m;

  /* Update for UnitDelay: '<S1025>/delay' */
  measure_DWork.delay_DSTATE = rtb_UnitDelay4_hd;

  /* Update for UnitDelay: '<S504>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE = rtb_Switch1;

  /* S-Function "SF_SingleSampleDelay" Block: <S459>/SF_FixedDiscreteDelay S-function */
  {
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_c;
    *xD = measure_B.Switch2_a4;
  }

  /* Update for UnitDelay: '<S312>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyrkobej = rtb_LogicalOperator1_b2ck;

  /* Update for UnitDelay: '<S457>/delay' */
  measure_DWork.delay_DSTATE_b = rtb_UnitDelay4_ej;

  /* Update for UnitDelay: '<S316>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_i = rtb_Switch1_b;

  /* Update for UnitDelay: '<S309>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_e = rtb_Switch_j;

  /* Update for UnitDelay: '<S309>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b3 = rtb_LogicalOperator1_i;

  /* Update for UnitDelay: '<S479>/delay1' */
  measure_DWork.delay1_DSTATE = rtb_Compare;

  /* Update for UnitDelay: '<S464>/delay1' */
  measure_DWork.delay1_DSTATE_l = rtb_Compare_f;

  /* Update for UnitDelay: '<S348>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE = rtb_TrigonometricFunction;

  /* Update for UnitDelay: '<S85>/Unit Delay1' incorporates:
   *  Inport: '<Root>/Vabc (pu)'
   */
  measure_DWork.UnitDelay1_DSTATE = measure_U.Vabcpu[1];

  /* Update for UnitDelay: '<S85>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE = rtb_UnitDelay1;

  /* Update for UnitDelay: '<S86>/Unit Delay1' incorporates:
   *  Inport: '<Root>/Vabc (pu)'
   */
  measure_DWork.UnitDelay1_DSTATE_i = measure_U.Vabcpu[2];

  /* Update for UnitDelay: '<S86>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_a = rtb_UnitDelay1_a;

  /* Update for UnitDelay: '<S84>/Unit Delay1' incorporates:
   *  Inport: '<Root>/Vabc (pu)'
   */
  measure_DWork.UnitDelay1_DSTATE_b = measure_U.Vabcpu[0];

  /* Update for UnitDelay: '<S84>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_c = rtb_UnitDelay1_i;

  /* Update for UnitDelay: '<S361>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE = measure_B.Gain;

  /* Update for UnitDelay: '<S361>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_l = measure_B.Switch;

  /* Update for UnitDelay: '<S463>/delay' */
  measure_DWork.delay_DSTATE_i = rtb_Compare_f;

  /* Update for UnitDelay: '<S362>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_k = measure_B.Gain;

  /* Update for UnitDelay: '<S362>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ls = measure_B.Switch_j;

  /* Update for UnitDelay: '<S367>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_kr = measure_B.Switch2_p;

  /* Update for UnitDelay: '<S367>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lsc = measure_B.Switch_jc;

  /* Update for UnitDelay: '<S478>/delay' */
  measure_DWork.delay_DSTATE_i2 = rtb_Compare;

  /* Update for UnitDelay: '<S368>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krx = measure_B.Switch2_p;

  /* Update for UnitDelay: '<S368>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscn = measure_B.Switch_jc4;

  /* Update for UnitDelay: '<S373>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxz = measure_B.Switch4;

  /* Update for UnitDelay: '<S373>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp = measure_B.Switch_jc4w;

  /* Update for UnitDelay: '<S374>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzy = measure_B.Switch4;

  /* Update for UnitDelay: '<S374>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0 = measure_B.Switch_jc4wm;

  /* Update for UnitDelay: '<S322>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdp = rtb_FixPtSum1_ja;

  /* Update for UnitDelay: '<S321>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdpu = rtb_FixPtSum1_j;

  /* Update for UnitDelay: '<S423>/delay1' */
  measure_DWork.delay1_DSTATE_f = rtb_Compare_d;

  /* Update for UnitDelay: '<S394>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyr = measure_B.Switch2_c;

  /* Update for UnitDelay: '<S394>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r = measure_B.Switch_i;

  /* Update for UnitDelay: '<S315>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3 = rtb_Divide_j;

  /* Update for UnitDelay: '<S422>/delay' */
  measure_DWork.delay_DSTATE_n = rtb_Compare_d;

  /* Update for UnitDelay: '<S395>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyrk = measure_B.Switch2_c;

  /* Update for UnitDelay: '<S395>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3j = measure_B.Switch_iw;

  /* Update for UnitDelay: '<S413>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_ehb = rtb_Switch1_gmkuez3wo;

  /* Update for UnitDelay: '<S320>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdput = rtb_FixPtSum1;

  /* Update for UnitDelay: '<S941>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_gf = rtb_Switch1_d;

  /* Update for UnitDelay: '<S310>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_h = rtb_Switch_c;

  /* Update for UnitDelay: '<S310>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_ii = rtb_LogicalOperator2_fd;

  /* Update for UnitDelay: '<S607>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_m4 = rtb_FixPtSum1_c;

  /* Update for UnitDelay: '<S558>/delay1' */
  measure_DWork.delay1_DSTATE_n = rtb_Compare_o;

  /* Update for UnitDelay: '<S495>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_f = rtb_Sum;

  /* Update for UnitDelay: '<S642>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_j = measure_B.Product[0];

  /* Update for UnitDelay: '<S642>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lj = measure_B.Switch_ix;

  /* Update for UnitDelay: '<S557>/delay' */
  measure_DWork.delay_DSTATE_c = rtb_Compare_o;

  /* Update for UnitDelay: '<S643>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js = measure_B.Product[0];

  /* Update for UnitDelay: '<S643>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljf = measure_B.Switch_ixh;

  /* Update for UnitDelay: '<S648>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0 = measure_B.Product[1];

  /* Update for UnitDelay: '<S648>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfw = measure_B.Switch_ixhv;

  /* Update for UnitDelay: '<S649>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g = measure_B.Product[1];

  /* Update for UnitDelay: '<S649>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwk = measure_B.Switch_ixhvn;

  /* Update for UnitDelay: '<S708>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_j4 = rtb_FixPtSum1_cy;

  /* Update for UnitDelay: '<S743>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e = measure_B.Product_j[0];

  /* Update for UnitDelay: '<S743>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ab = measure_B.Switch_d;

  /* Update for UnitDelay: '<S744>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e1 = measure_B.Product_j[0];

  /* Update for UnitDelay: '<S744>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abj = measure_B.Switch_dh;

  /* Update for UnitDelay: '<S749>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10 = measure_B.Product_j[1];

  /* Update for UnitDelay: '<S749>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju = measure_B.Switch_dh3;

  /* Update for UnitDelay: '<S750>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10c = measure_B.Product_j[1];

  /* Update for UnitDelay: '<S750>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3 = measure_B.Switch_dh3i;

  /* Update for UnitDelay: '<S809>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_g0 = rtb_Switch1_cc;

  /* Update for UnitDelay: '<S844>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_o = measure_B.Product_k[0];

  /* Update for UnitDelay: '<S844>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_g = measure_B.Switch_p;

  /* Update for UnitDelay: '<S845>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_ot = measure_B.Product_k[0];

  /* Update for UnitDelay: '<S845>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gl = measure_B.Switch_p0;

  /* Update for UnitDelay: '<S850>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otw = measure_B.Product_k[1];

  /* Update for UnitDelay: '<S850>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gll = measure_B.Switch_p0n;

  /* Update for UnitDelay: '<S851>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otws = measure_B.Product_k[1];

  /* Update for UnitDelay: '<S851>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllv = measure_B.Switch_p0ny;

  /* Update for UnitDelay: '<S588>/delay1' */
  measure_DWork.delay1_DSTATE_nm = rtb_Compare_oafgue;

  /* Update for UnitDelay: '<S600>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_p = rtb_Add_a;

  /* Update for UnitDelay: '<S573>/delay1' */
  measure_DWork.delay1_DSTATE_nmq = rtb_Compare_oafguee;

  /* Update for UnitDelay: '<S666>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0 = measure_B.Divide_h;

  /* Update for UnitDelay: '<S666>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwkl = measure_B.Switch_ixhvnq;

  /* Update for UnitDelay: '<S572>/delay' */
  measure_DWork.delay_DSTATE_ci = rtb_Compare_oafguee;

  /* Update for UnitDelay: '<S667>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0x = measure_B.Divide_h;

  /* Update for UnitDelay: '<S667>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf = measure_B.Switch_ixhvnql;

  /* Update for UnitDelay: '<S660>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xc = measure_B.Divide;

  /* Update for UnitDelay: '<S660>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5 = measure_B.Switch_ixhvnqlu;

  /* Update for UnitDelay: '<S661>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xck = measure_B.Divide;

  /* Update for UnitDelay: '<S661>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5t = measure_B.Switch_ixhvnqlui;

  /* Update for UnitDelay: '<S619>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_i = measure_B.Switch6;

  /* Update for UnitDelay: '<S619>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_l1 = measure_B.Switch_dm;

  /* Update for UnitDelay: '<S587>/delay' */
  measure_DWork.delay_DSTATE_cir = rtb_Compare_oafgue;

  /* Update for UnitDelay: '<S620>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_iv = measure_B.Switch6;

  /* Update for UnitDelay: '<S620>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_l1a = measure_B.Switch_dmo;

  /* Update for UnitDelay: '<S608>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_c = rtb_FixPtSum1_p;

  /* Update for UnitDelay: '<S686>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_b = rtb_LogicalOperator2_c1;

  /* Update for UnitDelay: '<S687>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_n = rtb_FixPtSum1_an;

  /* Update for UnitDelay: '<S692>/Unit Delay' incorporates:
   *  Sum: '<S692>/Sum'
   */
  measure_DWork.UnitDelay_DSTATE_h = rtb_Divide_jahfx5 + rtb_IpktoIrmsconversion;

  /* Update for UnitDelay: '<S685>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_nr = rtb_FixPtSum1_a;

  /* S-Function "SF_SingleSampleDelay" Block: <S928>/SF_FixedDiscreteDelay S-function */
  {
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_a;
    *xD = measure_B.DataTypeConversion;
  }

  /* Update for UnitDelay: '<S633>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_m = rtb_MathFunction2;

  /* Update for UnitDelay: '<S929>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_j = rtb_Switch1_ky;

  /* Update for UnitDelay: '<S734>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_g = rtb_MathFunction2_c;

  /* Update for UnitDelay: '<S932>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_jq = rtb_Switch1_kyp;

  /* Update for UnitDelay: '<S835>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_o = rtb_MathFunction2_a;

  /* Update for UnitDelay: '<S935>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_jqs = rtb_UnitDelay1_pf;

  /* Update for UnitDelay: '<S709>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_cf = rtb_FixPtSum1_mz;

  /* Update for UnitDelay: '<S787>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_md = rtb_LogicalOperator2_bf;

  /* Update for UnitDelay: '<S788>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_e = rtb_FixPtSum1_lnu;

  /* Update for UnitDelay: '<S793>/Unit Delay' incorporates:
   *  Sum: '<S793>/Sum'
   */
  measure_DWork.UnitDelay_DSTATE_g = rtb_AbsVI_e + rtb_ScaleRMSoutputsto1pu;

  /* Update for UnitDelay: '<S786>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_ep = rtb_FixPtSum1_ln;

  /* Update for UnitDelay: '<S810>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_or = rtb_Switch1_o;

  /* Update for UnitDelay: '<S888>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_cn = rtb_LogicalOperator2_bg;

  /* Update for UnitDelay: '<S889>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_ir = rtb_Switch1_cgb;

  /* Update for UnitDelay: '<S894>/Unit Delay' incorporates:
   *  Sum: '<S894>/Sum'
   */
  measure_DWork.UnitDelay_DSTATE_d = rtb_Switch_b + rtb_UnaryMinus_dv;

  /* Update for UnitDelay: '<S887>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_irs = rtb_FixPtSum1_f;

  /* Update for UnitDelay: '<S701>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_pz = rtb_Add_o;

  /* Update for UnitDelay: '<S767>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck = measure_B.Divide_ny;

  /* Update for UnitDelay: '<S767>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3r = measure_B.Switch_dh3io;

  /* Update for UnitDelay: '<S768>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0 = measure_B.Divide_ny;

  /* Update for UnitDelay: '<S768>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc = measure_B.Switch_dh3ioo;

  /* Update for UnitDelay: '<S761>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0c = measure_B.Divide_n;

  /* Update for UnitDelay: '<S761>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3 = measure_B.Switch_dh3ioos;

  /* Update for UnitDelay: '<S762>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0ct = measure_B.Divide_n;

  /* Update for UnitDelay: '<S762>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3x = measure_B.Switch_dh3ioosv;

  /* Update for UnitDelay: '<S720>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_b = measure_B.Switch6_n;

  /* Update for UnitDelay: '<S720>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_k = measure_B.Switch_iu;

  /* Update for UnitDelay: '<S721>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_bc = measure_B.Switch6_n;

  /* Update for UnitDelay: '<S721>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_k1 = measure_B.Switch_iua;

  /* Update for UnitDelay: '<S802>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_o = rtb_Add_h;

  /* Update for UnitDelay: '<S868>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsj = measure_B.Divide_jw;

  /* Update for UnitDelay: '<S868>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvy = measure_B.Switch_p0ny3;

  /* Update for UnitDelay: '<S869>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjg = measure_B.Divide_jw;

  /* Update for UnitDelay: '<S869>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyy = measure_B.Switch_p0ny3p;

  /* Update for UnitDelay: '<S862>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjge = measure_B.Divide_j;

  /* Update for UnitDelay: '<S862>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya = measure_B.Switch_p0ny3pk;

  /* Update for UnitDelay: '<S863>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjget = measure_B.Divide_j;

  /* Update for UnitDelay: '<S863>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya5 = measure_B.Switch_p0ny3pkq;

  /* Update for UnitDelay: '<S821>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_kw = measure_B.Switch6_a;

  /* Update for UnitDelay: '<S821>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_o = measure_B.Switch_ja;

  /* Update for UnitDelay: '<S822>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_kwr = measure_B.Switch6_a;

  /* Update for UnitDelay: '<S822>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_o2 = measure_B.Switch_jag;

  /* Update for UnitDelay: '<S991>/delay1' */
  measure_DWork.delay1_DSTATE_g = rtb_Switch6_idx;

  /* Update for UnitDelay: '<S962>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_c = measure_B.Switch_l;

  /* Update for UnitDelay: '<S962>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_d = measure_B.Switch_il;

  /* Update for UnitDelay: '<S503>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_aj = rtb_Switch;

  /* Update for UnitDelay: '<S990>/delay' */
  measure_DWork.delay_DSTATE_h = rtb_Switch6_idx;

  /* Update for UnitDelay: '<S963>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_cv = measure_B.Switch_l;

  /* Update for UnitDelay: '<S963>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_dg = measure_B.Switch_iln;

  /* Update for UnitDelay: '<S981>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_m = rtb_Switch1_ce;

  /* Update for UnitDelay: '<S942>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_hs = rtb_UnitDelay1_nt;

  /* Update for UnitDelay: '<S938>/delay1' */
  measure_DWork.delay1_DSTATE_no = rtb_Compare_n;

  /* Update for UnitDelay: '<S940>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_p = rtb_LogicalOperator2_f;

  /* Update for UnitDelay: '<S682>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xcka = measure_B.MathFunction;

  /* Update for UnitDelay: '<S682>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5ta = measure_B.Switch_ixhvnqluia;

  /* Update for UnitDelay: '<S683>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaa = measure_B.MathFunction;

  /* Update for UnitDelay: '<S683>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5tay = measure_B.Switch_ixhvnqluiaa;

  /* Update for UnitDelay: '<S630>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaam = measure_B.MathFunction1;

  /* Update for UnitDelay: '<S630>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5tayt = measure_B.Switch_ixhvnqluiaai;

  /* Update for UnitDelay: '<S631>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaamb = measure_B.MathFunction1;

  /* Update for UnitDelay: '<S631>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5taytr = measure_B.Switch_ixhvnqluiaai5;

  /* Update for UnitDelay: '<S783>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0cti = measure_B.MathFunction_c;

  /* Update for UnitDelay: '<S783>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xa = measure_B.Switch_dh3ioosv2;

  /* Update for UnitDelay: '<S784>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctir = measure_B.MathFunction_c;

  /* Update for UnitDelay: '<S784>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xak = measure_B.Switch_dh3ioosv2k;

  /* Update for UnitDelay: '<S731>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctirr = measure_B.MathFunction1_p;

  /* Update for UnitDelay: '<S731>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku = measure_B.Switch_dh3ioosv2km;

  /* Update for UnitDelay: '<S732>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctirrv = measure_B.MathFunction1_p;

  /* Update for UnitDelay: '<S732>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku5 = measure_B.Switch_dh3ioosv2kma;

  /* Update for UnitDelay: '<S884>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjgetk = measure_B.MathFunction_l;

  /* Update for UnitDelay: '<S884>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya5a = measure_B.Switch_p0ny3pkqp;

  /* Update for UnitDelay: '<S885>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjgetko = measure_B.MathFunction_l;

  /* Update for UnitDelay: '<S885>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah = measure_B.Switch_p0ny3pkqpe;

  /* Update for UnitDelay: '<S832>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjgetkod = measure_B.MathFunction1_m;

  /* Update for UnitDelay: '<S832>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0 = measure_B.Switch_p0ny3pkqpey;

  /* Update for UnitDelay: '<S833>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjgetkod3 = measure_B.MathFunction1_m;

  /* Update for UnitDelay: '<S833>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0l = measure_B.Switch_p0ny3pkqpeyo;

  /* Update for UnitDelay: '<S87>/Unit Delay1' incorporates:
   *  Inport: '<Root>/Iabc (Amps)'
   */
  measure_DWork.UnitDelay1_DSTATE_h = measure_U.IabcAmps[0];

  /* Update for UnitDelay: '<S87>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gp = rtb_UnitDelay1_l;

  /* Update for UnitDelay: '<S128>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jn = measure_B.Product_i[0];

  /* Update for UnitDelay: '<S128>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_n = measure_B.Switch_b;

  /* Update for UnitDelay: '<S129>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq = measure_B.Product_i[0];

  /* Update for UnitDelay: '<S129>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_np = measure_B.Switch_b2;

  /* Update for UnitDelay: '<S146>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1 = measure_B.Divide_ja;

  /* Update for UnitDelay: '<S146>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npj = measure_B.Switch_b2j;

  /* Update for UnitDelay: '<S147>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1h = measure_B.Divide_ja;

  /* Update for UnitDelay: '<S147>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj = measure_B.Switch_b2jb;

  /* Update for UnitDelay: '<S134>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hm = measure_B.Product_i[1];

  /* Update for UnitDelay: '<S134>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1 = measure_B.Switch_b2jbv;

  /* Update for UnitDelay: '<S135>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmy = measure_B.Product_i[1];

  /* Update for UnitDelay: '<S135>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1p = measure_B.Switch_b2jbv3;

  /* Update for UnitDelay: '<S152>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyq = measure_B.Divide_jah;

  /* Update for UnitDelay: '<S152>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1pt = measure_B.Switch_b2jbv30;

  /* Update for UnitDelay: '<S153>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqy = measure_B.Divide_jah;

  /* Update for UnitDelay: '<S153>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptk = measure_B.Switch_b2jbv30z;

  /* Update for UnitDelay: '<S88>/Unit Delay1' incorporates:
   *  Inport: '<Root>/Iabc (Amps)'
   */
  measure_DWork.UnitDelay1_DSTATE_ou = measure_U.IabcAmps[1];

  /* Update for UnitDelay: '<S88>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_f = rtb_UnitDelay1_f;

  /* Update for UnitDelay: '<S191>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya = measure_B.Product_io[0];

  /* Update for UnitDelay: '<S191>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkd = measure_B.Switch_b2jbv30zm;

  /* Update for UnitDelay: '<S192>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1 = measure_B.Product_io[0];

  /* Update for UnitDelay: '<S192>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkda = measure_B.Switch_b2jbv30zmv;

  /* Update for UnitDelay: '<S209>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1i = measure_B.Divide_jahf;

  /* Update for UnitDelay: '<S209>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf = measure_B.Switch_b2jbv30zmvu;

  /* Update for UnitDelay: '<S210>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1it = measure_B.Divide_jahf;

  /* Update for UnitDelay: '<S210>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2 = measure_B.Switch_b2jbv30zmvus;

  /* Update for UnitDelay: '<S197>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTAT_jnq1hmyqya1it1 = measure_B.Product_io[1];

  /* Update for UnitDelay: '<S197>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2v = measure_B.Switch_b2jbv30zmvusn;

  /* Update for UnitDelay: '<S198>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_jnq1hmyqya1it1v = measure_B.Product_io[1];

  /* Update for UnitDelay: '<S198>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTAT_npjj1ptkdaf2v0 =
    measure_B.Switch_b2jbv30zmvusna;

  /* Update for UnitDelay: '<S215>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_p = measure_B.Divide_jahfx;

  /* Update for UnitDelay: '<S215>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_npjj1ptkdaf2v0r =
    measure_B.Switch_b2jbv30zmvusnaw;

  /* Update for UnitDelay: '<S216>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_o = measure_B.Divide_jahfx;

  /* Update for UnitDelay: '<S216>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_i = measure_B.Switch_n;

  /* Update for UnitDelay: '<S89>/Unit Delay1' incorporates:
   *  Inport: '<Root>/Iabc (Amps)'
   */
  measure_DWork.UnitDelay1_DSTATE_bn = measure_U.IabcAmps[2];

  /* Update for UnitDelay: '<S89>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_b = rtb_UnitDelay1_lu;

  /* Update for UnitDelay: '<S254>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_k = measure_B.Product_io0[0];

  /* Update for UnitDelay: '<S254>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_g = measure_B.Switch_lf;

  /* Update for UnitDelay: '<S255>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_c = measure_B.Product_io0[0];

  /* Update for UnitDelay: '<S255>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_n = measure_B.Switch_jcx;

  /* Update for UnitDelay: '<S272>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_d = measure_B.Divide_jahfx5;

  /* Update for UnitDelay: '<S272>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_k = measure_B.Switch_e;

  /* Update for UnitDelay: '<S273>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_h = measure_B.Divide_jahfx5;

  /* Update for UnitDelay: '<S273>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_p = measure_B.Switch_bd;

  /* Update for UnitDelay: '<S260>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_f = measure_B.Product_io0[1];

  /* Update for UnitDelay: '<S260>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_ip = measure_B.Switch_c;

  /* Update for UnitDelay: '<S261>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_o2 = measure_B.Product_io0[1];

  /* Update for UnitDelay: '<S261>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_h = measure_B.Switch_d5;

  /* Update for UnitDelay: '<S278>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_cq = measure_B.Divide_jahfx50;

  /* Update for UnitDelay: '<S278>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_pl = measure_B.Switch_ik;

  /* Update for UnitDelay: '<S279>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_a = measure_B.Divide_jahfx50;

  /* Update for UnitDelay: '<S279>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_c = measure_B.Switch_nb;

  /* Update for UnitDelay: '<S168>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_n = measure_B.MathFunction_k;

  /* Update for UnitDelay: '<S168>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_o = measure_B.Switch_o;

  /* Update for UnitDelay: '<S169>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_i = measure_B.MathFunction_k;

  /* Update for UnitDelay: '<S169>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_f = measure_B.Switch_oo;

  /* Update for UnitDelay: '<S116>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_j = measure_B.MathFunction1_g;

  /* Update for UnitDelay: '<S116>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_j = measure_B.Switch_g;

  /* Update for UnitDelay: '<S117>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_jj = measure_B.MathFunction1_g;

  /* Update for UnitDelay: '<S117>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_ic = measure_B.Switch_pp;

  /* Update for UnitDelay: '<S231>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_dk = measure_B.MathFunction_k5;

  /* Update for UnitDelay: '<S231>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_hv = measure_B.Switch_cx;

  /* Update for UnitDelay: '<S232>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_dx = measure_B.MathFunction_k5;

  /* Update for UnitDelay: '<S232>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_l = measure_B.Switch_ixo;

  /* Update for UnitDelay: '<S179>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_kd = measure_B.MathFunction1_ge;

  /* Update for UnitDelay: '<S179>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_m = measure_B.Switch_ek;

  /* Update for UnitDelay: '<S180>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_dr = measure_B.MathFunction1_ge;

  /* Update for UnitDelay: '<S180>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_lr = measure_B.Switch_j3;

  /* Update for UnitDelay: '<S294>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_ny = measure_B.MathFunction_k5t;

  /* Update for UnitDelay: '<S294>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_oy = measure_B.Switch_a;

  /* Update for UnitDelay: '<S295>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_k1 = measure_B.MathFunction_k5t;

  /* Update for UnitDelay: '<S295>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_a = measure_B.Switch_d0;

  /* Update for UnitDelay: '<S242>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_ip = measure_B.MathFunction1_ge3;

  /* Update for UnitDelay: '<S242>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_ay = measure_B.Switch_h;

  /* Update for UnitDelay: '<S243>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_hx = measure_B.MathFunction1_ge3;

  /* Update for UnitDelay: '<S243>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_la = measure_B.Switch_it;

  /* Update for UnitDelay: '<S319>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputh = rtb_FixPtSum1_m;

  /* Update for UnitDelay: '<S331>/delay' */
  measure_DWork.delay_DSTATE_e = rtb_Compare_c2o;

  /* Update for UnitDelay: '<S337>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_im = rtb_Switch1_bx;

  /* Update for UnitDelay: '<S333>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_imt = rtb_LogicalOperator1_b2ck;

  /* Update for UnitDelay: '<S335>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputhx = rtb_FixPtSum1_go;

  /* Update for UnitDelay: '<S346>/Unit Delay' incorporates:
   *  Constant: '<S346>/Constant'
   */
  measure_DWork.UnitDelay_DSTATE_imt2 = measure_P.Constant_Value_civ2qn;

  /* Update for UnitDelay: '<S334>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputhxn = rtb_FixPtSum1_g;

  /* Update for UnitDelay: '<S400>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyrko = measure_B.ACripple1stestimate;

  /* Update for UnitDelay: '<S400>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm = measure_B.Switch_iwl;

  /* Update for UnitDelay: '<S401>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyrkob = measure_B.ACripple1stestimate;

  /* Update for UnitDelay: '<S401>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2 = measure_B.Switch_iwlt;

  /* Update for UnitDelay: '<S315>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_om = rtb_Divide_h;

  /* Update for UnitDelay: '<S443>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_ehbx = rtb_Switch_iwltec;

  /* Update for UnitDelay: '<S388>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTAT_lscnp0r3jm2b3r = rtb_LogicalOperator9;

  /* Update for UnitDelay: '<S418>/Unit Delay' incorporates:
   *  Sum: '<S418>/Sum'
   */
  measure_DWork.UnitDelay_DSTATE_eh = rtb_Switch_l40f + rtb_Switch1_c;

  /* Update for UnitDelay: '<S434>/delay' */
  measure_DWork.delay_DSTATE_n0 = rtb_LogicalOperator16;

  /* Update for UnitDelay: '<S435>/delay1' */
  measure_DWork.delay1_DSTATE_fk = rtb_LogicalOperator16;

  /* Update for UnitDelay: '<S445>/Unit Delay' incorporates:
   *  Constant: '<S445>/Constant'
   */
  measure_DWork.UnitDelay_DSTATE_ehbxxq = measure_P.Constant_Value_dso;

  /* Update for UnitDelay: '<S443>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b = rtb_Switch2_a;

  /* Update for UnitDelay: '<S388>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omt = rtb_Subtract3_c04;

  /* Update for UnitDelay: '<S441>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd = rtb_Divide_n;

  /* Update for UnitDelay: '<S388>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyrkobe = rtb_Divide_n;

  /* Update for UnitDelay: '<S442>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1 = rtb_Divide_ny;

  /* Update for UnitDelay: '<S382>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1h = rtb_Divide_jw;

  /* Update for UnitDelay: '<S381>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hd = rtb_Divide_j;

  /* Update for UnitDelay: '<S448>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_ehbxx = rtb_Switch1_gmkuez3woc;

  /* Update for UnitDelay: '<S505>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_hf = rtb_UnitDelay1_k;

  /* Update for UnitDelay: '<S530>/delay' */
  measure_DWork.delay_DSTATE_o = rtb_Any_Phases_Not_Disturbed;

  /* Update for UnitDelay: '<S536>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_cx = rtb_Switch1_kn;

  /* Update for UnitDelay: '<S532>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_jqi = rtb_LogicalOperator2_m;

  /* Update for UnitDelay: '<S534>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_cx = rtb_FixPtSum1_h;

  /* Update for UnitDelay: '<S545>/Unit Delay' incorporates:
   *  Constant: '<S545>/Constant'
   */
  measure_DWork.UnitDelay_DSTATE_l = measure_P.Constant_Value_mr;

  /* Update for UnitDelay: '<S533>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_d5 = rtb_FixPtSum1_l;

  /* Update for UnitDelay: '<S599>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_pg = rtb_TrigonometricFunction_l;

  /* Update for UnitDelay: '<S700>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_pzl = rtb_TrigonometricFunction_c;

  /* Update for UnitDelay: '<S801>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_ot = rtb_TrigonometricFunction_b;

  /* Update for UnitDelay: '<S968>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_cvz = measure_B.ACripple1stestimate_f;

  /* Update for UnitDelay: '<S968>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_dgh = measure_B.Switch_iln5;

  /* Update for UnitDelay: '<S969>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_cvzr = measure_B.ACripple1stestimate_f;

  /* Update for UnitDelay: '<S969>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_dghn = measure_B.Switch_iln5l;

  /* Update for UnitDelay: '<S503>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_k = rtb_IpktoIrms_a;

  /* Update for UnitDelay: '<S1011>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_jm = rtb_UnitDelay1_n0;

  /* Update for UnitDelay: '<S956>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ocn = rtb_LogicalOperator1_f;

  /* Update for UnitDelay: '<S986>/Unit Delay' incorporates:
   *  Product: '<S986>/B'
   *  Sum: '<S986>/Sum'
   */
  measure_DWork.UnitDelay_DSTATE_c = rtb_AbsVI * rtb_Sum2_g + rtb_Switch1_kt5c;

  /* Update for UnitDelay: '<S1002>/delay' */
  measure_DWork.delay_DSTATE_ep = rtb_LogicalOperator2_b0;

  /* Update for UnitDelay: '<S1003>/delay1' */
  measure_DWork.delay1_DSTATE_l5 = rtb_LogicalOperator2_b0;

  /* Update for UnitDelay: '<S1013>/Unit Delay' incorporates:
   *  Constant: '<S1013>/Constant'
   */
  measure_DWork.UnitDelay_DSTATE_jmcy = measure_P.Constant_Value_gbvuwpgu2kml14;

  /* Update for UnitDelay: '<S1011>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_oc = rtb_Switch1_m;

  /* Update for UnitDelay: '<S956>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_gr = rtb_AbsVI;

  /* Update for UnitDelay: '<S1009>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_grk = rtb_Product_i;

  /* Update for UnitDelay: '<S956>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_a = rtb_Product_i;

  /* Update for UnitDelay: '<S1010>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_grkf = rtb_Add1_h_idx_1;

  /* Update for UnitDelay: '<S950>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_j = rtb_MathFunction1;

  /* Update for UnitDelay: '<S949>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_d = rtb_Switch;

  /* Update for UnitDelay: '<S1016>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_jmc = rtb_Switch1_bxh;
}

/* Model initialize function */
void measureModelClass::initialize()
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(measure_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &measure_B), 0,
                sizeof(BlockIO_measure));

  /* states (dwork) */
  (void) memset((void *)&measure_DWork, 0,
                sizeof(D_Work_measure));

  /* external inputs */
  (void) memset((void *)&measure_U, 0,
                sizeof(ExternalInputs_measure));

  /* external outputs */
  (void) memset((void *)&measure_Y, 0,
                sizeof(ExternalOutputs_measure));

  /* S-Function "SF_FixedDiscreteDelay" Block: <S1027>/SF_FixedDiscreteDelay S-function */
  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfuncti_c3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_i;/* VDD_in integer work vector */
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunction_;
    int_T i;
    for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfunctio_g; i++)
      VDD_buffer[i] = measure_P.SF_FixedDiscreteDelaySfunction_;
    xD[0] = measure_P.SF_FixedDiscreteDelaySfunction_;
    *VDD_in = 0;
  }

  /* S-Function "SF_FixedDiscreteDelay" Block: <S459>/SF_FixedDiscreteDelay S-function */
  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfunctio_l[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_e;/* VDD_in integer work vector */
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_c;
    int_T i;
    for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfuncti_o0; i++)
      VDD_buffer[i] = measure_P.SF_FixedDiscreteDelaySfunctio_o;
    xD[0] = measure_P.SF_FixedDiscreteDelaySfunctio_o;
    *VDD_in = 0;
  }

  /* Start for DiscretePulseGenerator: '<S475>/Pulse Generator1' */
  measure_DWork.clockTickCounter = 0;

  /* Start for DiscretePulseGenerator: '<S460>/Pulse Generator1' */
  measure_DWork.clockTickCounter_f = 0;

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S358>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneTap[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_pz;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTap+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S359>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_i[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_pzv;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_n+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S363>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoTap[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_m;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTap+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S364>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_iq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_pzv4;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_ne+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S365>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_iqv[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_pzv45;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_nes+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S369>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_b[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_mw;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_n+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S370>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_iqvv[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_pzv45h;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_nesm+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S371>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_iqvvo[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_pzv45hn;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_nesmw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S375>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_bq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_mw3;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_ne+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* Start for DiscretePulseGenerator: '<S419>/Pulse Generator1' */
  measure_DWork.clockTickCounter_n = 0;

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S391>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_iqvvod[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_pzv45hn0;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_e+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S392>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_iqvvods[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_pzv45hn0c;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_ep+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S396>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_bqv[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_mw3l;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_e+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* Start for DiscretePulseGenerator: '<S554>/Pulse Generator1' */
  measure_DWork.clockTickCounter_e = 0;

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S639>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_f[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_hg;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_b+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S640>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_f2[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_hgo;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_bl+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S644>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_a[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_o;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_b+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S645>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_f2j[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_hgow;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_bln+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S646>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_f2jg[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_hgowj;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_bln4+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S650>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_ab[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_oc;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_bl+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S740>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_f2jgc[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_hgowjf;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_ez+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S741>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_f2jgc1[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_hgowjfv;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_ezn+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S745>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_ab4[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_oci;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_ez+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S746>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_f2jgc1y[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_hgowjfvn;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_eznc+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S747>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_f2jgc1yy[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_hgowjfvnn;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_ezncl+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S751>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_ab4s[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_oci4;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_ezn+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S841>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_f2jgc1yyu[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_hgowjfvnnx;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_e0+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S842>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_f2jgc1yyuf[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_hgowjfvnnxz;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_e0r+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S846>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_ab4s3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_oci4c;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_e0+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S847>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_f2jgc1yyufb[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_hgowjfvnnxzl;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_e0r1+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S848>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_f2jgc1yyufbl[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_hgowjfvnnxzlo;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_e0r1h+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S852>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_ab4s3q[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_oci4cw;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_e0r+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* Start for DiscretePulseGenerator: '<S584>/Pulse Generator1' */
  measure_DWork.clockTickCounter_ey = 0;

  /* Start for DiscretePulseGenerator: '<S569>/Pulse Generator1' */
  measure_DWork.clockTickCounter_ey4 = 0;

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S663>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_f2jgc1yyufbl2[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscrete_hgowjfvnnxzloq;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_bln4d+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S664>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_f2jgc1yyufbl2v[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_hgowjfvnnxzloqs;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_bln4dj+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S668>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_ab4s3ql[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_oci4cw4;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_bln+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S657>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f2jgc1yyufbl2vd[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pkx;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_bln4djb+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S658>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_d[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_lw;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_bln4djb4+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S662>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_ab4s3qlk[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_oci4cw4v;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_bln4+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S616>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_g[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_kq;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_h+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S617>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ak;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_hk+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S621>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_ab4s3qlk5[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_oci4cw4vl;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_h+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function "SF_FixedDiscreteDelay" Block: <S928>/SF_FixedDiscreteDelay S-function */
  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfunctio_j[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_h;/* VDD_in integer work vector */
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_a;
    int_T i;
    for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfuncti_ic; i++)
      VDD_buffer[i] = measure_P.SF_FixedDiscreteDelaySfunctio_i;
    xD[0] = measure_P.SF_FixedDiscreteDelaySfunctio_i;
    *VDD_in = 0;
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S764>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_bgs;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_eznclc+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S765>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c1[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_cv;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_eznclc5+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S769>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_ab4s3qlk5c[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_oci4cw4vlo;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_eznc+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S758>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gf[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_j3;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_eznclc5x+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S759>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_p[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_fr;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_eznclc5xg+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S763>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_ab4s3qlk5cc[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_oci4cw4vloz;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_eznclc5xg5+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S717>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_cr[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ny;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_h0+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S718>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_e[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_gs3;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_h0u+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S722>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_ab4s3qlk5cc4[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_oci4cw4vloz5;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_p+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S865>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_b[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_lz;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_e0r1hm+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S866>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_n[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_jl;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_e0r1hmw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S870>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_ab4s3qlk5cc4j[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_oci4cw4vloz5b;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_e0r1+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S859>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gp[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ev;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_e0r1hmwt+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S860>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_i[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_edt;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_e0r1hmwtw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S864>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_ab4s3qlk5cc4jf[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscrete_oci4cw4vloz5bs;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_e0r1hmwtwq+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S818>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_jh;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_m+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S819>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_mm[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_bm;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_mo+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S823>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ab4s3qlk5cc4jfr[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_oci4cw4vloz5bse;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_en+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* Start for DiscretePulseGenerator: '<S987>/Pulse Generator1' */
  measure_DWork.clockTickCounter_ed = 0;

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S959>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_p[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOneT_c;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_i+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S960>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_pb[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_cj;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_ii+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S964>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_g[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_os;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_i+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S679>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_i3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_bq;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_bln4djb4g+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S680>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_fqs;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_bln4djb4gs+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S684>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gg[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_mu;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_bln4djb4gs5+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S627>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ex[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_mr;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_bln4djb4gs54+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S628>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_aj[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_eb;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_bln4djb4gs54q+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S632>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_aq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_oe;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_bln4djb4gs54qg+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S780>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_no[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ib;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_eznclc5xg5q+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S781>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f5[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pz;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_eznclc5xg5q1+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S785>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ef[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pei;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_eznclc5xg5q1u+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S728>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ed[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_fy;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_eznclc5xg5q1ug+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S729>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a0[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ej;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_eznclc5xg5q1ugj+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S733>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pk[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_nc;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_k+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S881>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_dk[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_hf;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_e0r1hmwtwqc+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S882>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_o[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_a2;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_e0r1hmwtwqc2+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S886>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gs[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pl;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_e0r1hmwtwqc2e+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S829>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_bt[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_av;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_e0r1hmwtwqc2ev+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S830>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_e0[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_dg;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_e0r1hmwtwqc2evm+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S834>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_l[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_lwr;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_kl+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S125>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_h[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOneT_e;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_o+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S126>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_hk[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_et;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_of+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S130>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_h[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_p;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_o+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S143>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_hkv[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_etx;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_ofa+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S144>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_hkvl[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_etx1;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_ofaw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S148>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_hj[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_pv;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_of+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S131>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_hkvl3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_etx1w;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_ofawr+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S132>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_hkvl35[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_etx1wx;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_ofawrz+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S136>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_hjq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_pv2;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_ofa+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S149>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_hkvl35c[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_etx1wxm;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_ofawrzy+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S150>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_hkvl35cs[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_etx1wxmc;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_ofawrzyw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S154>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_hjqf[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_pv2z;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_ofaw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S188>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_hkvl35css[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_etx1wxmcb;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_ofawrzywp+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S189>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_hkvl35cssz[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_etx1wxmcbv;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_ofawrzywpv+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S193>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_hjqfc[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_pv2zv;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_ofawrzywpvf+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S206>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_hkvl35cssz3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_etx1wxmcbvv;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_ofawrzywpvfx+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S207>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_hkvl35cssz3u[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_etx1wxmcbvvw;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_ofawrzywpvfxm+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S211>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_hjqfcq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_pv2zv2;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_ofawrzywpvfxm1+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S194>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_hkvl35cssz3uy[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_etx1wxmcbvvwx;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ofawrzywpvfxm1r+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S195>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_hkvl35cssz3uyo[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscrete_etx1wxmcbvvwx0;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_l+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S199>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_hjqfcqw[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_pv2zv24;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_h+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S212>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_hkvl35cssz3uyos[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_etx1wxmcbvvwx03;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_n+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S213>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a02[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ls;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_hy+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S217>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_hjqfcqwr[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_pv2zv24n;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_i+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S251>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_iy[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_l3;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_iy+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S252>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ad[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_lb;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ku+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S256>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_hjqfcqwrz[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_pv2zv24nx;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_kuf+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S269>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m1[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_a2h;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_a+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S270>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_g0[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_cm;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_k3+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S274>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_hjqfcqwrzc[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_pv2zv24nxp;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_aa+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S257>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_j[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pc;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_o+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S258>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ox[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_am;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_d+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S262>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_hjqfcqwrzc3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_pv2zv24nxpe;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_k35+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S275>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m0[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_g05;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_f+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S276>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_fq[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_f4;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_g+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S280>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_hjqfcqwrzc31[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_pv2zv24nxpeb;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ow+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S165>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ep[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_jx;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_fo+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S166>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_cp[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_kc;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_hi+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S170>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_hjqfcqwrzc31p[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_pv2zv24nxpebh;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_db+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S113>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_h[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ld;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_iw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S114>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c4[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_dd;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_b+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S118>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_hjqfcqwrzc31p3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscrete_pv2zv24nxpebhu;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ff+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S228>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_jw[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_hx;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_or+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S229>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_bg[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ok;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_bv+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S233>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_hjqfcqwrzc31p34[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_pv2zv24nxpebhui;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ga+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S176>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_on[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_iv;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_j+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S177>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_nr[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_gw;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_c+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S181>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_om[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_ou;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_foe+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S291>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pe[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_c2;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_p+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S292>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_k[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_au;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_cu+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S296>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_mf[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_l4;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_hin+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S239>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_p3[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_l5;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_bq+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S240>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_me[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_hd;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_f4+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S244>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_onk[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscret_fe;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_iwf+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S397>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_iqvvodsl[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_pzv45hn0c0;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_epw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S398>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_iqvvodsli[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_pzv45hn0c03;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_epwu+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S402>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_bqvb[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_mw3lz;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_ep+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S965>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_pbu[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_cjw;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_ii1+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayFaster" Block: <S966>/Variable Discrete Delay with One Tap S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_pbur[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_cjwa;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_ii12+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* S-Function Initialise "SF_VariableDiscreteDelayTwoTapsFaster" Block: <S970>/Variable Discrete Delay with Two Taps S-function */
  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_g0[0];/* VDD_buffer real work vector */
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_oss;/* VDD_in integer work vector */
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_ii+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;                       /* This is the index of the buffer where we want the data to start going into */
  }

  /* InitializeConditions for UnitDelay: '<S494>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_ep = measure_P.UnitDelay4_X0_oc;

  /* InitializeConditions for UnitDelay: '<S1025>/delay' */
  measure_DWork.delay_DSTATE = measure_P.delay_X0;

  /* InitializeConditions for UnitDelay: '<S504>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE = measure_P.UnitDelay_X0;

  /* InitializeConditions for UnitDelay: '<S312>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyrkobej = measure_P.UnitDelay4_X0_ci;

  /* InitializeConditions for UnitDelay: '<S457>/delay' */
  measure_DWork.delay_DSTATE_b = measure_P.delay_X0_o;

  /* InitializeConditions for UnitDelay: '<S316>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_i = measure_P.UnitDelay_X0_o;

  /* InitializeConditions for UnitDelay: '<S309>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_e = measure_P.UnitDelay_X0_j;

  /* InitializeConditions for UnitDelay: '<S309>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b3 = measure_P.UnitDelay2_X0_ek;

  /* InitializeConditions for UnitDelay: '<S479>/delay1' */
  measure_DWork.delay1_DSTATE = measure_P.delay1_X0;

  /* InitializeConditions for UnitDelay: '<S464>/delay1' */
  measure_DWork.delay1_DSTATE_l = measure_P.delay1_X0_h;

  /* InitializeConditions for UnitDelay: '<S348>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE = measure_P.UnitDelay3_X0;

  /* InitializeConditions for UnitDelay: '<S85>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE = measure_P.UnitDelay1_X0;

  /* InitializeConditions for UnitDelay: '<S85>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE = measure_P.UnitDelay2_X0;

  /* InitializeConditions for UnitDelay: '<S86>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_i = measure_P.UnitDelay1_X0_i;

  /* InitializeConditions for UnitDelay: '<S86>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_a = measure_P.UnitDelay2_X0_l;

  /* InitializeConditions for UnitDelay: '<S84>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_b = measure_P.UnitDelay1_X0_e;

  /* InitializeConditions for UnitDelay: '<S84>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_c = measure_P.UnitDelay2_X0_g;

  /* InitializeConditions for UnitDelay: '<S361>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE = measure_P.UnitDelay4_X0;

  /* InitializeConditions for UnitDelay: '<S361>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_l = measure_P.UnitDelay2_X0_n;

  /* InitializeConditions for UnitDelay: '<S463>/delay' */
  measure_DWork.delay_DSTATE_i = measure_P.delay_X0_h;

  /* InitializeConditions for UnitDelay: '<S362>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_k = measure_P.UnitDelay4_X0_n;

  /* InitializeConditions for UnitDelay: '<S362>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ls = measure_P.UnitDelay2_X0_ne;

  /* InitializeConditions for UnitDelay: '<S367>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_kr = measure_P.UnitDelay4_X0_ne;

  /* InitializeConditions for UnitDelay: '<S367>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lsc = measure_P.UnitDelay2_X0_nes;

  /* InitializeConditions for UnitDelay: '<S478>/delay' */
  measure_DWork.delay_DSTATE_i2 = measure_P.delay_X0_hp;

  /* InitializeConditions for UnitDelay: '<S368>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krx = measure_P.UnitDelay4_X0_nes;

  /* InitializeConditions for UnitDelay: '<S368>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscn = measure_P.UnitDelay2_X0_nesm;

  /* InitializeConditions for UnitDelay: '<S373>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxz = measure_P.UnitDelay4_X0_nesm;

  /* InitializeConditions for UnitDelay: '<S373>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp = measure_P.UnitDelay2_X0_nesmw;

  /* InitializeConditions for UnitDelay: '<S374>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzy = measure_P.UnitDelay4_X0_nesmw;

  /* InitializeConditions for UnitDelay: '<S374>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0 = measure_P.UnitDelay2_X0_nesmwp;

  /* InitializeConditions for UnitDelay: '<S322>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdp = measure_P.UnitDelay1_X0_f;

  /* InitializeConditions for UnitDelay: '<S321>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdpu = measure_P.UnitDelay1_X0_fk;

  /* InitializeConditions for UnitDelay: '<S423>/delay1' */
  measure_DWork.delay1_DSTATE_f = measure_P.delay1_X0_e;

  /* InitializeConditions for UnitDelay: '<S394>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyr = measure_P.UnitDelay4_X0_e;

  /* InitializeConditions for UnitDelay: '<S394>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r = measure_P.UnitDelay2_X0_e;

  /* InitializeConditions for UnitDelay: '<S315>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3 = measure_P.UnitDelay2_X0_ep;

  /* InitializeConditions for UnitDelay: '<S422>/delay' */
  measure_DWork.delay_DSTATE_n = measure_P.delay_X0_e;

  /* InitializeConditions for UnitDelay: '<S395>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyrk = measure_P.UnitDelay4_X0_ep;

  /* InitializeConditions for UnitDelay: '<S395>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3j = measure_P.UnitDelay2_X0_epw;

  /* InitializeConditions for UnitDelay: '<S413>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_ehb = measure_P.UnitDelay_X0_ep;

  /* InitializeConditions for UnitDelay: '<S320>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdput = measure_P.UnitDelay1_X0_fkx;

  /* InitializeConditions for UnitDelay: '<S941>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_gf = measure_P.UnitDelay1_X0_fo;

  /* InitializeConditions for UnitDelay: '<S310>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_h = measure_P.UnitDelay2_X0_nc;

  /* InitializeConditions for UnitDelay: '<S310>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_ii = measure_P.UnitDelay4_X0_ol;

  /* InitializeConditions for UnitDelay: '<S607>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_m4 = measure_P.UnitDelay1_X0_l3;

  /* InitializeConditions for UnitDelay: '<S558>/delay1' */
  measure_DWork.delay1_DSTATE_n = measure_P.delay1_X0_a;

  /* InitializeConditions for UnitDelay: '<S495>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_f = measure_P.UnitDelay_X0_a;

  /* InitializeConditions for UnitDelay: '<S642>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_j = measure_P.UnitDelay4_X0_b;

  /* InitializeConditions for UnitDelay: '<S642>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lj = measure_P.UnitDelay2_X0_b;

  /* InitializeConditions for UnitDelay: '<S557>/delay' */
  measure_DWork.delay_DSTATE_c = measure_P.delay_X0_a;

  /* InitializeConditions for UnitDelay: '<S643>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js = measure_P.UnitDelay4_X0_bl;

  /* InitializeConditions for UnitDelay: '<S643>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljf = measure_P.UnitDelay2_X0_bl;

  /* InitializeConditions for UnitDelay: '<S648>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0 = measure_P.UnitDelay4_X0_bln;

  /* InitializeConditions for UnitDelay: '<S648>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfw = measure_P.UnitDelay2_X0_bln;

  /* InitializeConditions for UnitDelay: '<S649>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g = measure_P.UnitDelay4_X0_bln4;

  /* InitializeConditions for UnitDelay: '<S649>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwk = measure_P.UnitDelay2_X0_bln4;

  /* InitializeConditions for UnitDelay: '<S708>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_j4 = measure_P.UnitDelay1_X0_j;

  /* InitializeConditions for UnitDelay: '<S743>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e = measure_P.UnitDelay4_X0_ez;

  /* InitializeConditions for UnitDelay: '<S743>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ab = measure_P.UnitDelay2_X0_ez;

  /* InitializeConditions for UnitDelay: '<S744>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e1 = measure_P.UnitDelay4_X0_ezn;

  /* InitializeConditions for UnitDelay: '<S744>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abj = measure_P.UnitDelay2_X0_ezn;

  /* InitializeConditions for UnitDelay: '<S749>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10 = measure_P.UnitDelay4_X0_eznc;

  /* InitializeConditions for UnitDelay: '<S749>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju = measure_P.UnitDelay2_X0_eznc;

  /* InitializeConditions for UnitDelay: '<S750>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10c = measure_P.UnitDelay4_X0_ezncl;

  /* InitializeConditions for UnitDelay: '<S750>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3 = measure_P.UnitDelay2_X0_ezncl;

  /* InitializeConditions for UnitDelay: '<S809>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_g0 = measure_P.UnitDelay1_X0_ex;

  /* InitializeConditions for UnitDelay: '<S844>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_o = measure_P.UnitDelay4_X0_e0;

  /* InitializeConditions for UnitDelay: '<S844>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_g = measure_P.UnitDelay2_X0_e0;

  /* InitializeConditions for UnitDelay: '<S845>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_ot = measure_P.UnitDelay4_X0_e0r;

  /* InitializeConditions for UnitDelay: '<S845>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gl = measure_P.UnitDelay2_X0_e0r;

  /* InitializeConditions for UnitDelay: '<S850>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otw = measure_P.UnitDelay4_X0_e0r1;

  /* InitializeConditions for UnitDelay: '<S850>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gll = measure_P.UnitDelay2_X0_e0r1;

  /* InitializeConditions for UnitDelay: '<S851>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otws = measure_P.UnitDelay4_X0_e0r1h;

  /* InitializeConditions for UnitDelay: '<S851>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllv = measure_P.UnitDelay2_X0_e0r1h;

  /* InitializeConditions for UnitDelay: '<S588>/delay1' */
  measure_DWork.delay1_DSTATE_nm = measure_P.delay1_X0_ad;

  /* InitializeConditions for UnitDelay: '<S600>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_p = measure_P.UnitDelay3_X0_k;

  /* InitializeConditions for UnitDelay: '<S573>/delay1' */
  measure_DWork.delay1_DSTATE_nmq = measure_P.delay1_X0_adh;

  /* InitializeConditions for UnitDelay: '<S666>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0 = measure_P.UnitDelay4_X0_bln4d;

  /* InitializeConditions for UnitDelay: '<S666>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwkl = measure_P.UnitDelay2_X0_bln4d;

  /* InitializeConditions for UnitDelay: '<S572>/delay' */
  measure_DWork.delay_DSTATE_ci = measure_P.delay_X0_ad;

  /* InitializeConditions for UnitDelay: '<S667>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0x = measure_P.UnitDelay4_X0_bln4dj;

  /* InitializeConditions for UnitDelay: '<S667>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf = measure_P.UnitDelay2_X0_bln4dj;

  /* InitializeConditions for UnitDelay: '<S660>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xc = measure_P.UnitDelay4_X0_bln4djb;

  /* InitializeConditions for UnitDelay: '<S660>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5 = measure_P.UnitDelay2_X0_bln4djb;

  /* InitializeConditions for UnitDelay: '<S661>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xck = measure_P.UnitDelay4_X0_bln4djb4;

  /* InitializeConditions for UnitDelay: '<S661>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5t = measure_P.UnitDelay2_X0_bln4djb4;

  /* InitializeConditions for UnitDelay: '<S619>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_i = measure_P.UnitDelay4_X0_d;

  /* InitializeConditions for UnitDelay: '<S619>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_l1 = measure_P.UnitDelay2_X0_d;

  /* InitializeConditions for UnitDelay: '<S587>/delay' */
  measure_DWork.delay_DSTATE_cir = measure_P.delay_X0_adh;

  /* InitializeConditions for UnitDelay: '<S620>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_iv = measure_P.UnitDelay4_X0_d1;

  /* InitializeConditions for UnitDelay: '<S620>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_l1a = measure_P.UnitDelay2_X0_d1;

  /* InitializeConditions for UnitDelay: '<S608>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_c = measure_P.UnitDelay1_X0_l5;

  /* InitializeConditions for UnitDelay: '<S686>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_b = measure_P.UnitDelay_X0_ci1;

  /* InitializeConditions for UnitDelay: '<S687>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_n = measure_P.UnitDelay1_X0_c;

  /* InitializeConditions for UnitDelay: '<S692>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_h = measure_P.UnitDelay_X0_h;

  /* InitializeConditions for UnitDelay: '<S685>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_nr = measure_P.UnitDelay1_X0_ci;

  /* InitializeConditions for UnitDelay: '<S633>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_m = measure_P.UnitDelay1_X0_b;

  /* InitializeConditions for UnitDelay: '<S929>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_j = measure_P.UnitDelay_X0_gq;

  /* InitializeConditions for UnitDelay: '<S734>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_g = measure_P.UnitDelay1_X0_ez;

  /* InitializeConditions for UnitDelay: '<S932>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_jq = measure_P.UnitDelay_X0_gqo;

  /* InitializeConditions for UnitDelay: '<S835>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_o = measure_P.UnitDelay1_X0_e0;

  /* InitializeConditions for UnitDelay: '<S935>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_jqs = measure_P.UnitDelay_X0_gqop;

  /* InitializeConditions for UnitDelay: '<S709>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_cf = measure_P.UnitDelay1_X0_f0;

  /* InitializeConditions for UnitDelay: '<S787>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_md = measure_P.UnitDelay_X0_hg;

  /* InitializeConditions for UnitDelay: '<S788>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_e = measure_P.UnitDelay1_X0_hg;

  /* InitializeConditions for UnitDelay: '<S793>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_g = measure_P.UnitDelay_X0_g;

  /* InitializeConditions for UnitDelay: '<S786>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_ep = measure_P.UnitDelay1_X0_hg0;

  /* InitializeConditions for UnitDelay: '<S810>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_or = measure_P.UnitDelay1_X0_k;

  /* InitializeConditions for UnitDelay: '<S888>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_cn = measure_P.UnitDelay_X0_gu;

  /* InitializeConditions for UnitDelay: '<S889>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_ir = measure_P.UnitDelay1_X0_gu;

  /* InitializeConditions for UnitDelay: '<S894>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_d = measure_P.UnitDelay_X0_m;

  /* InitializeConditions for UnitDelay: '<S887>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_irs = measure_P.UnitDelay1_X0_gun;

  /* InitializeConditions for UnitDelay: '<S701>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_pz = measure_P.UnitDelay3_X0_c;

  /* InitializeConditions for UnitDelay: '<S767>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck = measure_P.UnitDelay4_X0_eznclc;

  /* InitializeConditions for UnitDelay: '<S767>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3r = measure_P.UnitDelay2_X0_eznclc;

  /* InitializeConditions for UnitDelay: '<S768>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0 = measure_P.UnitDelay4_X0_eznclc5;

  /* InitializeConditions for UnitDelay: '<S768>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc = measure_P.UnitDelay2_X0_eznclc5;

  /* InitializeConditions for UnitDelay: '<S761>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0c = measure_P.UnitDelay4_X0_eznclc5x;

  /* InitializeConditions for UnitDelay: '<S761>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3 = measure_P.UnitDelay2_X0_eznclc5x;

  /* InitializeConditions for UnitDelay: '<S762>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0ct = measure_P.UnitDelay4_X0_eznclc5xg;

  /* InitializeConditions for UnitDelay: '<S762>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3x = measure_P.UnitDelay2_X0_eznclc5xg;

  /* InitializeConditions for UnitDelay: '<S720>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_b = measure_P.UnitDelay4_X0_f;

  /* InitializeConditions for UnitDelay: '<S720>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_k = measure_P.UnitDelay2_X0_f;

  /* InitializeConditions for UnitDelay: '<S721>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_bc = measure_P.UnitDelay4_X0_fj;

  /* InitializeConditions for UnitDelay: '<S721>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_k1 = measure_P.UnitDelay2_X0_fj;

  /* InitializeConditions for UnitDelay: '<S802>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_o = measure_P.UnitDelay3_X0_f;

  /* InitializeConditions for UnitDelay: '<S868>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsj = measure_P.UnitDelay4_X0_e0r1hm;

  /* InitializeConditions for UnitDelay: '<S868>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvy = measure_P.UnitDelay2_X0_e0r1hm;

  /* InitializeConditions for UnitDelay: '<S869>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjg = measure_P.UnitDelay4_X0_e0r1hmw;

  /* InitializeConditions for UnitDelay: '<S869>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyy = measure_P.UnitDelay2_X0_e0r1hmw;

  /* InitializeConditions for UnitDelay: '<S862>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjge = measure_P.UnitDelay4_X0_e0r1hmwt;

  /* InitializeConditions for UnitDelay: '<S862>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya = measure_P.UnitDelay2_X0_e0r1hmwt;

  /* InitializeConditions for UnitDelay: '<S863>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjget = measure_P.UnitDelay4_X0_e0r1hmwtw;

  /* InitializeConditions for UnitDelay: '<S863>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya5 = measure_P.UnitDelay2_X0_e0r1hmwtw;

  /* InitializeConditions for UnitDelay: '<S821>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_kw = measure_P.UnitDelay4_X0_g;

  /* InitializeConditions for UnitDelay: '<S821>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_o = measure_P.UnitDelay2_X0_g0;

  /* InitializeConditions for UnitDelay: '<S822>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_kwr = measure_P.UnitDelay4_X0_g0;

  /* InitializeConditions for UnitDelay: '<S822>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_o2 = measure_P.UnitDelay2_X0_g0w;

  /* InitializeConditions for UnitDelay: '<S991>/delay1' */
  measure_DWork.delay1_DSTATE_g = measure_P.delay1_X0_d;

  /* InitializeConditions for UnitDelay: '<S962>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_c = measure_P.UnitDelay4_X0_i;

  /* InitializeConditions for UnitDelay: '<S962>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_d = measure_P.UnitDelay2_X0_i;

  /* InitializeConditions for UnitDelay: '<S503>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_aj = measure_P.UnitDelay2_X0_gy;

  /* InitializeConditions for UnitDelay: '<S990>/delay' */
  measure_DWork.delay_DSTATE_h = measure_P.delay_X0_d;

  /* InitializeConditions for UnitDelay: '<S963>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_cv = measure_P.UnitDelay4_X0_ii;

  /* InitializeConditions for UnitDelay: '<S963>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_dg = measure_P.UnitDelay2_X0_ii;

  /* InitializeConditions for UnitDelay: '<S981>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_m = measure_P.UnitDelay_X0_n;

  /* InitializeConditions for UnitDelay: '<S942>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_hs = measure_P.UnitDelay_X0_c;

  /* InitializeConditions for UnitDelay: '<S938>/delay1' */
  measure_DWork.delay1_DSTATE_no = measure_P.delay1_X0_k;

  /* InitializeConditions for UnitDelay: '<S940>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_p = measure_P.UnitDelay1_X0_gd;

  /* InitializeConditions for UnitDelay: '<S682>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xcka = measure_P.UnitDelay4_X0_bln4djb4g;

  /* InitializeConditions for UnitDelay: '<S682>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5ta = measure_P.UnitDelay2_X0_bln4djb4g;

  /* InitializeConditions for UnitDelay: '<S683>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaa =
    measure_P.UnitDelay4_X0_bln4djb4gs;

  /* InitializeConditions for UnitDelay: '<S683>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5tay =
    measure_P.UnitDelay2_X0_bln4djb4gs;

  /* InitializeConditions for UnitDelay: '<S630>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaam =
    measure_P.UnitDelay4_X0_bln4djb4gs5;

  /* InitializeConditions for UnitDelay: '<S630>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5tayt =
    measure_P.UnitDelay2_X0_bln4djb4gs5;

  /* InitializeConditions for UnitDelay: '<S631>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaamb =
    measure_P.UnitDelay4_X0_bln4djb4gs54;

  /* InitializeConditions for UnitDelay: '<S631>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5taytr =
    measure_P.UnitDelay2_X0_bln4djb4gs54;

  /* InitializeConditions for UnitDelay: '<S783>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0cti = measure_P.UnitDelay4_X0_eznclc5xg5;

  /* InitializeConditions for UnitDelay: '<S783>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xa =
    measure_P.UnitDelay2_X0_eznclc5xg5;

  /* InitializeConditions for UnitDelay: '<S784>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctir =
    measure_P.UnitDelay4_X0_eznclc5xg5q;

  /* InitializeConditions for UnitDelay: '<S784>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xak =
    measure_P.UnitDelay2_X0_eznclc5xg5q;

  /* InitializeConditions for UnitDelay: '<S731>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctirr =
    measure_P.UnitDelay4_X0_eznclc5xg5q1;

  /* InitializeConditions for UnitDelay: '<S731>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku =
    measure_P.UnitDelay2_X0_eznclc5xg5q1;

  /* InitializeConditions for UnitDelay: '<S732>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctirrv =
    measure_P.UnitDelay4_X0_eznclc5xg5q1u;

  /* InitializeConditions for UnitDelay: '<S732>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku5 =
    measure_P.UnitDelay2_X0_eznclc5xg5q1u;

  /* InitializeConditions for UnitDelay: '<S884>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjgetk = measure_P.UnitDelay4_X0_e0r1hmwtwq;

  /* InitializeConditions for UnitDelay: '<S884>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya5a = measure_P.UnitDelay2_X0_e0r1hmwtwq;

  /* InitializeConditions for UnitDelay: '<S885>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjgetko =
    measure_P.UnitDelay4_X0_e0r1hmwtwqc;

  /* InitializeConditions for UnitDelay: '<S885>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah =
    measure_P.UnitDelay2_X0_e0r1hmwtwqc;

  /* InitializeConditions for UnitDelay: '<S832>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjgetkod =
    measure_P.UnitDelay4_X0_e0r1hmwtwqc2;

  /* InitializeConditions for UnitDelay: '<S832>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0 =
    measure_P.UnitDelay2_X0_e0r1hmwtwqc2;

  /* InitializeConditions for UnitDelay: '<S833>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_otwsjgetkod3 =
    measure_P.UnitDelay4_X0_e0r1hmwtwqc2e;

  /* InitializeConditions for UnitDelay: '<S833>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0l =
    measure_P.UnitDelay2_X0_e0r1hmwtwqc2e;

  /* InitializeConditions for UnitDelay: '<S87>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_h = measure_P.UnitDelay1_X0_h;

  /* InitializeConditions for UnitDelay: '<S87>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_gp = measure_P.UnitDelay2_X0_c;

  /* InitializeConditions for UnitDelay: '<S128>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jn = measure_P.UnitDelay4_X0_o;

  /* InitializeConditions for UnitDelay: '<S128>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_n = measure_P.UnitDelay2_X0_o;

  /* InitializeConditions for UnitDelay: '<S129>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq = measure_P.UnitDelay4_X0_of;

  /* InitializeConditions for UnitDelay: '<S129>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_np = measure_P.UnitDelay2_X0_of;

  /* InitializeConditions for UnitDelay: '<S146>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1 = measure_P.UnitDelay4_X0_ofa;

  /* InitializeConditions for UnitDelay: '<S146>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npj = measure_P.UnitDelay2_X0_ofa;

  /* InitializeConditions for UnitDelay: '<S147>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1h = measure_P.UnitDelay4_X0_ofaw;

  /* InitializeConditions for UnitDelay: '<S147>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj = measure_P.UnitDelay2_X0_ofaw;

  /* InitializeConditions for UnitDelay: '<S134>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hm = measure_P.UnitDelay4_X0_ofawr;

  /* InitializeConditions for UnitDelay: '<S134>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1 = measure_P.UnitDelay2_X0_ofawr;

  /* InitializeConditions for UnitDelay: '<S135>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmy = measure_P.UnitDelay4_X0_ofawrz;

  /* InitializeConditions for UnitDelay: '<S135>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1p = measure_P.UnitDelay2_X0_ofawrz;

  /* InitializeConditions for UnitDelay: '<S152>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyq = measure_P.UnitDelay4_X0_ofawrzy;

  /* InitializeConditions for UnitDelay: '<S152>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1pt = measure_P.UnitDelay2_X0_ofawrzy;

  /* InitializeConditions for UnitDelay: '<S153>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqy = measure_P.UnitDelay4_X0_ofawrzyw;

  /* InitializeConditions for UnitDelay: '<S153>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptk = measure_P.UnitDelay2_X0_ofawrzyw;

  /* InitializeConditions for UnitDelay: '<S88>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_ou = measure_P.UnitDelay1_X0_l;

  /* InitializeConditions for UnitDelay: '<S88>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_f = measure_P.UnitDelay2_X0_i3;

  /* InitializeConditions for UnitDelay: '<S191>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya = measure_P.UnitDelay4_X0_ofawrzywp;

  /* InitializeConditions for UnitDelay: '<S191>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkd = measure_P.UnitDelay2_X0_ofawrzywp;

  /* InitializeConditions for UnitDelay: '<S192>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1 =
    measure_P.UnitDelay4_X0_ofawrzywpv;

  /* InitializeConditions for UnitDelay: '<S192>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkda =
    measure_P.UnitDelay2_X0_ofawrzywpv;

  /* InitializeConditions for UnitDelay: '<S209>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1i =
    measure_P.UnitDelay4_X0_ofawrzywpvf;

  /* InitializeConditions for UnitDelay: '<S209>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf =
    measure_P.UnitDelay2_X0_ofawrzywpvf;

  /* InitializeConditions for UnitDelay: '<S210>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1it =
    measure_P.UnitDelay4_X0_ofawrzywpvfx;

  /* InitializeConditions for UnitDelay: '<S210>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2 =
    measure_P.UnitDelay2_X0_ofawrzywpvfx;

  /* InitializeConditions for UnitDelay: '<S197>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTAT_jnq1hmyqya1it1 =
    measure_P.UnitDelay4_X0_ofawrzywpvfxm;

  /* InitializeConditions for UnitDelay: '<S197>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2v =
    measure_P.UnitDelay2_X0_ofawrzywpvfxm;

  /* InitializeConditions for UnitDelay: '<S198>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_jnq1hmyqya1it1v =
    measure_P.UnitDelay4_X0_ofawrzywpvfxm1;

  /* InitializeConditions for UnitDelay: '<S198>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTAT_npjj1ptkdaf2v0 =
    measure_P.UnitDelay2_X0_ofawrzywpvfxm1;

  /* InitializeConditions for UnitDelay: '<S215>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_p = measure_P.UnitDelay4_X0_ofawrzywpvfxm1r;

  /* InitializeConditions for UnitDelay: '<S215>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_npjj1ptkdaf2v0r =
    measure_P.UnitDelay2_X0_ofawrzywpvfxm1r;

  /* InitializeConditions for UnitDelay: '<S216>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_o = measure_P.UnitDelay4_X0_l;

  /* InitializeConditions for UnitDelay: '<S216>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_i = measure_P.UnitDelay2_X0_lt;

  /* InitializeConditions for UnitDelay: '<S89>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_bn = measure_P.UnitDelay1_X0_d;

  /* InitializeConditions for UnitDelay: '<S89>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_b = measure_P.UnitDelay2_X0_na;

  /* InitializeConditions for UnitDelay: '<S254>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_k = measure_P.UnitDelay4_X0_ng;

  /* InitializeConditions for UnitDelay: '<S254>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_g = measure_P.UnitDelay2_X0_ng;

  /* InitializeConditions for UnitDelay: '<S255>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_c = measure_P.UnitDelay4_X0_h;

  /* InitializeConditions for UnitDelay: '<S255>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_n = measure_P.UnitDelay2_X0_h;

  /* InitializeConditions for UnitDelay: '<S272>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_d = measure_P.UnitDelay4_X0_iy;

  /* InitializeConditions for UnitDelay: '<S272>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_k = measure_P.UnitDelay2_X0_iy;

  /* InitializeConditions for UnitDelay: '<S273>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_h = measure_P.UnitDelay4_X0_k;

  /* InitializeConditions for UnitDelay: '<S273>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_p = measure_P.UnitDelay2_X0_k;

  /* InitializeConditions for UnitDelay: '<S260>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_f = measure_P.UnitDelay4_X0_a;

  /* InitializeConditions for UnitDelay: '<S260>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_ip = measure_P.UnitDelay2_X0_a;

  /* InitializeConditions for UnitDelay: '<S261>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_o2 = measure_P.UnitDelay4_X0_k3;

  /* InitializeConditions for UnitDelay: '<S261>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_h = measure_P.UnitDelay2_X0_k3;

  /* InitializeConditions for UnitDelay: '<S278>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_cq = measure_P.UnitDelay4_X0_ow;

  /* InitializeConditions for UnitDelay: '<S278>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_pl = measure_P.UnitDelay2_X0_ow;

  /* InitializeConditions for UnitDelay: '<S279>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_a = measure_P.UnitDelay4_X0_db;

  /* InitializeConditions for UnitDelay: '<S279>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_c = measure_P.UnitDelay2_X0_db;

  /* InitializeConditions for UnitDelay: '<S168>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_n = measure_P.UnitDelay4_X0_ff;

  /* InitializeConditions for UnitDelay: '<S168>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_o = measure_P.UnitDelay2_X0_ff;

  /* InitializeConditions for UnitDelay: '<S169>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_i = measure_P.UnitDelay4_X0_ga;

  /* InitializeConditions for UnitDelay: '<S169>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_f = measure_P.UnitDelay2_X0_ga;

  /* InitializeConditions for UnitDelay: '<S116>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_j = measure_P.UnitDelay4_X0_fo;

  /* InitializeConditions for UnitDelay: '<S116>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_j = measure_P.UnitDelay2_X0_fo;

  /* InitializeConditions for UnitDelay: '<S117>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_jj = measure_P.UnitDelay4_X0_hi;

  /* InitializeConditions for UnitDelay: '<S117>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_ic = measure_P.UnitDelay2_X0_hi;

  /* InitializeConditions for UnitDelay: '<S231>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_dk = measure_P.UnitDelay4_X0_iw;

  /* InitializeConditions for UnitDelay: '<S231>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_hv = measure_P.UnitDelay2_X0_iw;

  /* InitializeConditions for UnitDelay: '<S232>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_dx = measure_P.UnitDelay4_X0_by;

  /* InitializeConditions for UnitDelay: '<S232>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_l = measure_P.UnitDelay2_X0_by;

  /* InitializeConditions for UnitDelay: '<S179>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_kd = measure_P.UnitDelay4_X0_or;

  /* InitializeConditions for UnitDelay: '<S179>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_m = measure_P.UnitDelay2_X0_or;

  /* InitializeConditions for UnitDelay: '<S180>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_dr = measure_P.UnitDelay4_X0_bv;

  /* InitializeConditions for UnitDelay: '<S180>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_lr = measure_P.UnitDelay2_X0_bv;

  /* InitializeConditions for UnitDelay: '<S294>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_ny = measure_P.UnitDelay4_X0_j;

  /* InitializeConditions for UnitDelay: '<S294>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_oy = measure_P.UnitDelay2_X0_j;

  /* InitializeConditions for UnitDelay: '<S295>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_k1 = measure_P.UnitDelay4_X0_c;

  /* InitializeConditions for UnitDelay: '<S295>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_a = measure_P.UnitDelay2_X0_c5;

  /* InitializeConditions for UnitDelay: '<S242>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_ip = measure_P.UnitDelay4_X0_p;

  /* InitializeConditions for UnitDelay: '<S242>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_ay = measure_P.UnitDelay2_X0_p;

  /* InitializeConditions for UnitDelay: '<S243>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTA_hx = measure_P.UnitDelay4_X0_cu;

  /* InitializeConditions for UnitDelay: '<S243>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTA_la = measure_P.UnitDelay2_X0_cu;

  /* InitializeConditions for UnitDelay: '<S319>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputh = measure_P.UnitDelay1_X0_hn;

  /* InitializeConditions for UnitDelay: '<S331>/delay' */
  measure_DWork.delay_DSTATE_e = measure_P.delay_X0_c;

  /* InitializeConditions for UnitDelay: '<S337>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_im = measure_P.UnitDelay_X0_ci;

  /* InitializeConditions for UnitDelay: '<S333>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_imt = measure_P.UnitDelay_X0_civ;

  /* InitializeConditions for UnitDelay: '<S335>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputhx = measure_P.UnitDelay1_X0_civ;

  /* InitializeConditions for UnitDelay: '<S346>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_imt2 = measure_P.UnitDelay_X0_civ2;

  /* InitializeConditions for UnitDelay: '<S334>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputhxn = measure_P.UnitDelay1_X0_civ2;

  /* InitializeConditions for UnitDelay: '<S400>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyrko = measure_P.UnitDelay4_X0_epw;

  /* InitializeConditions for UnitDelay: '<S400>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm = measure_P.UnitDelay2_X0_epwu;

  /* InitializeConditions for UnitDelay: '<S401>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyrkob = measure_P.UnitDelay4_X0_epwu;

  /* InitializeConditions for UnitDelay: '<S401>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2 = measure_P.UnitDelay2_X0_epwu2;

  /* InitializeConditions for UnitDelay: '<S315>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_om = measure_P.UnitDelay1_X0_ep;

  /* InitializeConditions for UnitDelay: '<S443>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_ehbx = measure_P.UnitDelay_X0_epw;

  /* InitializeConditions for UnitDelay: '<S388>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTAT_lscnp0r3jm2b3r =
    measure_P.UnitDelay2_X0_epwu2gd;

  /* InitializeConditions for UnitDelay: '<S418>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_eh = measure_P.UnitDelay_X0_e;

  /* InitializeConditions for UnitDelay: '<S434>/delay' */
  measure_DWork.delay_DSTATE_n0 = measure_P.delay_X0_ep;

  /* InitializeConditions for UnitDelay: '<S435>/delay1' */
  measure_DWork.delay1_DSTATE_fk = measure_P.delay1_X0_ep;

  /* InitializeConditions for UnitDelay: '<S445>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_ehbxxq = measure_P.UnitDelay_X0_epwu2;

  /* InitializeConditions for UnitDelay: '<S443>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b = measure_P.UnitDelay2_X0_epwu2g;

  /* InitializeConditions for UnitDelay: '<S388>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omt = measure_P.UnitDelay1_X0_epw;

  /* InitializeConditions for UnitDelay: '<S441>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd = measure_P.UnitDelay1_X0_epwu;

  /* InitializeConditions for UnitDelay: '<S388>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_krxzyrkobe = measure_P.UnitDelay4_X0_epwu2;

  /* InitializeConditions for UnitDelay: '<S442>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1 = measure_P.UnitDelay1_X0_epwu2;

  /* InitializeConditions for UnitDelay: '<S382>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1h = measure_P.UnitDelay1_X0_epwu2g;

  /* InitializeConditions for UnitDelay: '<S381>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_omtd1hd = measure_P.UnitDelay1_X0_epwu2gd;

  /* InitializeConditions for UnitDelay: '<S448>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_ehbxx = measure_P.UnitDelay_X0_epwu;

  /* InitializeConditions for UnitDelay: '<S505>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_hf = measure_P.UnitDelay1_X0_hi;

  /* InitializeConditions for UnitDelay: '<S530>/delay' */
  measure_DWork.delay_DSTATE_o = measure_P.delay_X0_o0;

  /* InitializeConditions for UnitDelay: '<S536>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_cx = measure_P.UnitDelay_X0_m4;

  /* InitializeConditions for UnitDelay: '<S532>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_jqi = measure_P.UnitDelay_X0_i;

  /* InitializeConditions for UnitDelay: '<S534>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_cx = measure_P.UnitDelay1_X0_m;

  /* InitializeConditions for UnitDelay: '<S545>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_l = measure_P.UnitDelay_X0_mr;

  /* InitializeConditions for UnitDelay: '<S533>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_d5 = measure_P.UnitDelay1_X0_n;

  /* InitializeConditions for UnitDelay: '<S599>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_pg = measure_P.UnitDelay3_X0_ka;

  /* InitializeConditions for UnitDelay: '<S700>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_pzl = measure_P.UnitDelay3_X0_p;

  /* InitializeConditions for UnitDelay: '<S801>/Unit Delay3' */
  measure_DWork.UnitDelay3_DSTATE_ot = measure_P.UnitDelay3_X0_fw;

  /* InitializeConditions for UnitDelay: '<S968>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_cvz = measure_P.UnitDelay4_X0_ii1;

  /* InitializeConditions for UnitDelay: '<S968>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_dgh = measure_P.UnitDelay2_X0_ii1;

  /* InitializeConditions for UnitDelay: '<S969>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_cvzr = measure_P.UnitDelay4_X0_ii12;

  /* InitializeConditions for UnitDelay: '<S969>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_dghn = measure_P.UnitDelay2_X0_ii12;

  /* InitializeConditions for UnitDelay: '<S503>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_k = measure_P.UnitDelay1_X0_hr;

  /* InitializeConditions for UnitDelay: '<S1011>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_jm = measure_P.UnitDelay_X0_gb;

  /* InitializeConditions for UnitDelay: '<S956>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_ocn = measure_P.UnitDelay2_X0_gbv;

  /* InitializeConditions for UnitDelay: '<S986>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_c = measure_P.UnitDelay_X0_en;

  /* InitializeConditions for UnitDelay: '<S1002>/delay' */
  measure_DWork.delay_DSTATE_ep = measure_P.delay_X0_g;

  /* InitializeConditions for UnitDelay: '<S1003>/delay1' */
  measure_DWork.delay1_DSTATE_l5 = measure_P.delay1_X0_g;

  /* InitializeConditions for UnitDelay: '<S1013>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_jmcy = measure_P.UnitDelay_X0_gbvu;

  /* InitializeConditions for UnitDelay: '<S1011>/Unit Delay2' */
  measure_DWork.UnitDelay2_DSTATE_oc = measure_P.UnitDelay2_X0_gb;

  /* InitializeConditions for UnitDelay: '<S956>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_gr = measure_P.UnitDelay1_X0_g;

  /* InitializeConditions for UnitDelay: '<S1009>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_grk = measure_P.UnitDelay1_X0_gb;

  /* InitializeConditions for UnitDelay: '<S956>/Unit Delay4' */
  measure_DWork.UnitDelay4_DSTATE_a = measure_P.UnitDelay4_X0_gb;

  /* InitializeConditions for UnitDelay: '<S1010>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_grkf = measure_P.UnitDelay1_X0_gbv;

  /* InitializeConditions for UnitDelay: '<S950>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_j = measure_P.UnitDelay1_X0_hp;

  /* InitializeConditions for UnitDelay: '<S949>/Unit Delay1' */
  measure_DWork.UnitDelay1_DSTATE_d = measure_P.UnitDelay1_X0_ea;

  /* InitializeConditions for UnitDelay: '<S1016>/Unit Delay' */
  measure_DWork.UnitDelay_DSTATE_jmc = measure_P.UnitDelay_X0_gbv;
}

/* Model terminate function */
void measureModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
measureModelClass::measureModelClass()
{
  Parameters_measure measure_P_temp = {
    1.0E-9,
    1.0,
    1.0,
    0.0,
    1.0E-9,
    1.0E-9,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    1000.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    1000.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    1000.0,
    0.0,
    0.0,
    50.0,
    1800.0,
    0.999999,
    0.499999,
    0.999999,
    0.499999,
    0.000125,
    2.0,
    50.0,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    100.0,
    100.0,
    1.0E-9,
    0.0,
    0.0,
    0.0,
    0.0,
    0.000125,
    0.000125,
    -0.000125,
    0.125,
    0.125,
    -0.125,
    100.0,
    100.0,
    12.5,
    0.5,
    -0.125,
    12.5,
    100.0,
    0.499999,
    -0.499999,
    1.0,
    0.08,
    0.08,
    0.0005,
    0.999999,
    0.499999,
    0.999999,
    0.499999,
    4.0E+9,
    4.0E+9,
    0.0,
    0.0,
    0.00025,
    1.0E-9,
    1.0E-9,
    -0.00025,
    0.025,
    0.025,
    0.0005,
    0.999999,
    0.499999,
    0.05,
    0.05,
    0.0005,
    0.999999,
    0.499999,
    50.0,
    50.0,
    1.0E-9,
    100.0,
    100.0,
    25.0,
    1.0E-9,
    1.0,
    1.0,
    1.0E-9,
    1.0E-9,
    1.0,
    1.0E-9,
    1.0,
    1.0,
    1.0E-9,
    1.0E-9,
    1.0,
    1.0E-9,
    1.0,
    1.0,
    1.0E-9,
    1.0E-9,
    1.0,
    0.999999,
    0.499999,
    0.999999,
    0.499999,
    -6.2831853071795862,
    25.0,
    0.04,
    0.04,
    0.0005,
    0.999999,
    0.499999,
    0.02,
    0.02,
    0.0005,
    0.999999,
    0.499999,
    0.14,
    0.14,
    0.0005,
    0.999999,
    0.499999,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    100.0,
    100.0,
    1.0E-9,
    -3.1415926535897931,
    636.61977236758128,
    1.0E-9,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    1000.0,
    0.0,
    0.0,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    100.0,
    100.0,
    1.0E-9,
    -3.1415926535897931,
    636.61977236758128,
    1.0E-9,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    1000.0,
    0.0,
    0.0,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    100.0,
    100.0,
    1.0E-9,
    -3.1415926535897931,
    636.61977236758128,
    1.0E-9,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    1000.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.000125,
    0.000125,
    -0.000125,
    0.125,
    0.125,
    -0.125,
    100.0,
    100.0,
    12.5,
    0.5,
    -0.125,
    12.5,
    100.0,
    0.499999,
    -0.499999,
    1.0,
    0.08,
    0.08,
    0.0005,
    0.999999,
    0.499999,
    0.999999,
    0.499999,
    4.0E+9,
    4.0E+9,
    0.0,
    0.0,
    0.00025,
    1.0E-9,
    1.0E-9,
    -0.00025,
    0.0,
    0.0,
    0.0,
    0.0,
    50.0,
    1.0,
    420.0,
    210.0,
    0.0,
    0.5,
    1.0,
    220.0,
    110.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.5,

    { 0.0, 0.0, 0.0 },

    { 0.0, 0.0, 0.0 },
    -4000.0,
    1.0,
    0.5,
    0.0,
    0.0,
    0.5,
    -4000.0,
    1.0,
    0.5,
    0.57735026918962584,
    0.0,
    0.0,
    0.5,
    -4000.0,
    1.0,
    0.5,
    2.0,
    0.33333333333333331,
    -3.1415926535897931,
    636.61977236758128,
    0.0,
    0.0,
    0.0005,
    4000.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    2.0,
    0.0005,
    4000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    0.000125,
    0.0,
    0.0,
    0.0,
    0.0,
    0.02,
    12732.395447351626,
    180.0,
    1800.0,
    1.0,
    660.0,
    330.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.0005,
    4000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    0.000125,
    0.0,
    5.0,
    0.04,
    1.0E-9,
    50.0,
    1.0,
    340.0,
    170.0,
    0.0,
    0.5,
    0.0015707963267948967,
    0.0,
    3.1415926535897931,
    25.0,
    0.04,
    2.0,
    0.0,
    0.0,
    0.0005,
    4000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    0.000125,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0,
    1140.0,
    570.0,
    0.0,
    0.5,
    0.0,
    1.0,
    180.0,
    90.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.5,
    0.0005,
    4000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    0.000125,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    3.5,
    0.0005,
    4000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    0.000125,
    0.0,
    0.0,
    6.0,
    0.0,
    0.5,
    0.0,
    4000.0,
    0.02,
    0.0,
    0.3,
    0.0,
    4000.0,
    0.02,
    0.0,
    0.3,
    0.0,
    4000.0,
    0.02,
    0.0,
    0.3,
    0.0,
    6.0,
    0.0,
    6.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    25.0,
    1.0,
    660.0,
    330.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.0005,
    4000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    0.000125,
    0.0,
    0.04,
    1.0,
    28.0,
    1.2247448713915889,
    0.57735026918962584,
    0.33333333333333331,
    0.33333333333333331,
    1.0E-9,
    100.0,
    1.4142135623730951,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    100.0,
    1000.0,
    1.4142135623730951,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    100.0,
    1000.0,
    1.4142135623730951,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    100.0,
    1000.0,
    0.0,
    0.0,
    0.5,
    -4000.0,
    1.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.70710678118654746,
    0.0,
    0.0,
    0.5,
    -4000.0,
    1.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.70710678118654746,
    0.0,
    0.0,
    0.5,
    -4000.0,
    1.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.70710678118654746,
    0.33333333333333331,
    0.33333333333333331,
    1.0E-9,
    100.0,
    1.4142135623730951,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    100.0,
    1000.0,
    1.4142135623730951,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    100.0,
    1000.0,
    1.4142135623730951,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E-9,
    100.0,
    1000.0,
    0.70710678118654746,
    0.70710678118654746,
    0.70710678118654746,
    1.0E-9,
    0.0,
    0.14,
    0.2,
    4000.0,
    4000.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.00025,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E+9,
    0.00025,
    0.5,
    0.0,
    0.08,
    0.0,
    1.0,
    0.08,
    -0.000125,
    0.5,
    -0.0015707963267948967,
    1.0,
    0.4,
    -0.0005,
    0.0,
    4000.0,
    1.0,
    0.0,
    4000.0,
    4000.0,
    0.0,
    -3.1415926535897931,
    4000.0,
    0.0,
    0.060586937186524192,
    0.93941306281347581,
    0.0,
    -3.1415926535897931,
    4000.0,
    0.0,
    0.060586937186524192,
    0.93941306281347581,
    0.0,
    -3.1415926535897931,
    4000.0,
    0.0,
    0.060586937186524192,
    0.93941306281347581,
    1.2,
    55.000000000000007,
    40.0,
    0.8,
    1.2,
    0.8,
    1.2,
    0.8,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.00025,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E+9,
    0.00025,
    0.5,
    0.0,
    0.08,
    0.0,
    1.0,
    0.08,
    -0.000125,
    0.5,
    -0.0015707963267948967,
    1.0,
    0.4,
    -0.0005,
    0.0,
    4000.0,
    1.0,
    0.0,

    { { 1.0, 0.0 }, { -0.49999999999999978, -0.86602540378443871 }, { -
        0.49999999999999978, 0.86602540378443871 } },

    { { 1.0, 0.0 }, { -0.49999999999999978, 0.86602540378443871 }, { -
        0.49999999999999978, -0.86602540378443871 } },

    { { 1.0, 0.0 }, { -0.49999999999999978, -0.86602540378443871 }, { -
        0.49999999999999978, 0.86602540378443871 } },

    { { 1.0, 0.0 }, { -0.49999999999999978, 0.86602540378443871 }, { -
        0.49999999999999978, -0.86602540378443871 } },
    321,
    321,
    2,
    101,
    101,
    2,
    201,
    201,
    2,
    161,
    161,
    2,
    81,
    81,
    2,
    561,
    561,
    2,
    321,
    321,
    2,
    80,
    80,
    2,
    101,
    101,
    101,
    2,
    201,
    201,
    201,
    201,
    201,
    201,
    2,
    321,
    321,
    321,
    2,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    161,
    2,
    81,
    81,
    81,
    81,
    81,
    81,
    2,
    561,
    561,
    561,
    40,
    81,
    81,
    81,
    81,
    81,
    81,
    561,
    561,
    561,
    81,
    81,
    81,
    81,
    81,
    81,
    561,
    561,
    561,
    2,
    321,
    321,
    321,
    161,
    161,
    161,
    81,
    81,
    81,
    161,
    161,
    161,
    81,
    81,
    81,
    161,
    161,
    161,
    81,
    81,
    81,
    161,
    161,
    161,
    81,
    81,
    81,
    161,
    161,
    161,
    81,
    81,
    81,
    161,
    161,
    161,
    81,
    81,
    81,
    161,
    161,
    161,
    81,
    81,
    81,
    161,
    161,
    161,
    81,
    81,
    81,
    161,
    161,
    161,
    81,
    81,
    81,
    161,
    161,
    161,
    81,
    81,
    81,
    161,
    161,
    161,
    81,
    81,
    81,
    161,
    161,
    161,
    81,
    81,
    81,
    321,
    321,
    321,
    321,
    321,
    321,
    1U,
    121U,
    1U,
    401U,
    1U,
    641U,
    1U,
    1U,
    1U,
    1U,
    141U,
    1U,
    1U,
    1U,
    1U,
    320U,
    1U,
    1U,
    0U,
    1U,
    81U,
    1U,
    1U,
    1U,
    1U,
    181U,
    1U,
    1U,
    1U,
    161U,
    1U,
    401U,
    1U,
    161U,
    1U,
    401U,
    1U,
    161U,
    1U,
    401U,
    1U,
    161U,
    1U,
    401U,
    1U,
    161U,
    1U,
    401U,
    1U,
    161U,
    1U,
    401U,
    1U,
    1U,
    180U,
    1U,
    1U,
    180U,
    1U,
    1U,
    180U,
    1U,
    1U,
    320U,
    1U,
    161U,
    1U,
    1U,
    320U,
    1U,
    1U,
    0U,
    1U,
    81U,
    641U,
    0U,
    401U,
    0U,
    1U,
    0U,
    121U,
    0U,
    161U,
    161U,
    0U,
    161U,
    0U,
    161U,
    0U,
    401U,
    0U,
    401U,
    0U,
    161U,
    0U,
    1U,
    0U,
    1U,
    0U,
    1U,
    0U,
    401U,
    0U,
    401U,
    0U,
    161U,
    0U,
    401U,
    0U,
    401U,
    0U,
    161U,
    0U,
    1U,
    0U,
    0U,
    1U,
    0U,
    1U,
    1U,
    1U,
    81U,
    0U,
    1U,
    0U,
    0U,
    0U,
    141U,
    0U,
    1U,
    1U,
    0U,
    1U,
    0U,
    1U,
    0U,
    1U,
    81U,
    0U,
    1U,
    0U,
    0U,
    0U,
    181U,
    0U,
    1U,
    1U,
    1U,
    1U,
    1U,
    1U,
    1U,
    1U,
    1U,
    1U,
    1U,
    1U,
    1U,
    1U,
    1U,
    0U,
    1U,
    0U,
    1U,
    0U,
    1U,
    0,
    0,
    1,
    0,
    1,
    0,
    0,
    0,
    1,
    1,
    0,
    1,
    1,
    0,
    0,
    1,
    0,
    0,
    1,
    1,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    1,
    1,
    0,
    0,
    1,
    0,
    1,
    0,
    0,
    0,
    1,
    1,
    1,
    0,
    0,
    1,
    0,
    1,
    0,
    0,
    0,
    1,
    1
  };                                   /* Modifiable parameters */

  /* Initialize tunable parameters */
  measure_P = measure_P_temp;

  /* Real-Time Model */
  measure_M = &measure_M_;
}

/* Destructor */
measureModelClass::~measureModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Block parameters get method */
const Parameters_measure & measureModelClass::getBlockParameters() const
{
  return measure_P;
}

/* Block parameters set method */
void measureModelClass::setBlockParameters(const Parameters_measure *pmeasure_P)
{
  measure_P = *pmeasure_P;
}

/* Real-Time Model get method */
RT_MODEL_measure * measureModelClass::getRTM() const
{
  return measure_M;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
