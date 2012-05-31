#include "measure.h"
#include "measure_private.h"

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if ((rtIsNaN(u0)) || (rtIsNaN(u1))) {
    y = (rtNaN);
  } else if ((rtIsInf(u0)) && (rtIsInf(u1))) {
    y = atan2((u0 > 0.0) ? 1.0 : -1.0, (u1 > 0.0) ? 1.0 : -1.0);
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

void measureModelClass::step()
{
  boolean_T rtb_UnitDelay4_hd;
  boolean_T rtb_UnitDelay4_ej;
  boolean_T rtb_LogicalOperator1_f;
  real_T rtb_Divide_jahfx;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_c2o;
  boolean_T rtb_Compare_f;
  real_T rtb_UnitDelay1;
  real_T rtb_UnitDelay1_a;
  real_T rtb_Switch_b;
  real_T rtb_UnitDelay1_i;
  real_T rtb_IpktoIrms_a;
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
  real_T rtb_Divide_jah;
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
  real_T rtb_Gain1_kh;
  real_T rtb_Unbalance;
  real_T rtb_MinMax1;
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
  real_T rtb_AbsVI;
  real_T rtb_AbsVI_e;
  real_T rtb_UnaryMinus_dv;
  real_T rtb_Divide_jahf;
  real_T rtb_Switch_b2;
  real_T rtb_UnitDelay1_l;
  real_T rtb_UnitDelay1_f;
  real_T rtb_UnaryMinus_p;
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
  real_T rtb_VpuIpktoVrmsIrms_re;

  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfuncti_c3[0];
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_i;
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunction_;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = *xD;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfunctio_g + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfunctio_g;
    measure_B.SF_FixedDiscreteDelaySfunction = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfunctio_g)
      *VDD_in = 0;
  }

  rtb_UnitDelay4_hd = measure_DWork.UnitDelay4_DSTATE_ep;
  if ((measure_DWork.UnitDelay4_DSTATE_ep) && (!measure_DWork.delay_DSTATE)) {
    rtb_Switch1 = measure_B.SF_FixedDiscreteDelaySfunction;
  } else {
    rtb_Switch1 = measure_DWork.UnitDelay_DSTATE;
  }

  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfunctio_l[0];
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_e;
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_c;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = *xD;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfuncti_o0 + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfuncti_o0;
    measure_B.SF_FixedDiscreteDelaySfunctio_k = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfuncti_o0)
      *VDD_in = 0;
  }

  rtb_UnitDelay4_ej = measure_DWork.UnitDelay4_DSTATE_krxzyrkobej;
  if ((measure_DWork.UnitDelay4_DSTATE_krxzyrkobej) &&
      (!measure_DWork.delay_DSTATE_b)) {
    rtb_Switch1_b = measure_B.SF_FixedDiscreteDelaySfunctio_k;
  } else {
    rtb_Switch1_b = measure_DWork.UnitDelay_DSTATE_i;
  }

  if (measure_DWork.UnitDelay4_DSTATE_krxzyrkobej) {
    rtb_Switch1_k = measure_DWork.UnitDelay_DSTATE_e;
  } else {
    rtb_Switch1_k = measure_P.Constant1_Value_n;
  }

  rtb_LogicalOperator1_f = ((measure_DWork.UnitDelay4_DSTATE_krxzyrkobej) ||
    (!measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b3));
  rtb_Divide_jahfx = ((((real_T)measure_DWork.clockTickCounter) <
                       measure_P.PulseGenerator1_Duty) &&
                      (measure_DWork.clockTickCounter >= 0)) ?
    measure_P.PulseGenerator1_Amp : 0.0;
  if (((real_T)measure_DWork.clockTickCounter) >=
      (measure_P.PulseGenerator1_Period - 1.0)) {
    measure_DWork.clockTickCounter = 0;
  } else {
    measure_DWork.clockTickCounter = measure_DWork.clockTickCounter + 1;
  }

  rtb_Compare = (rtb_Divide_jahfx > measure_P.Constant_Value_hpxmk);
  rtb_Compare_c2o = ((!rtb_Compare) && (measure_DWork.delay1_DSTATE));
  rtb_Divide_jahfx = ((((real_T)measure_DWork.clockTickCounter_f) <
                       measure_P.PulseGenerator1_Duty_h) &&
                      (measure_DWork.clockTickCounter_f >= 0)) ?
    measure_P.PulseGenerator1_Amp_h : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_f) >=
      (measure_P.PulseGenerator1_Period_h - 1.0)) {
    measure_DWork.clockTickCounter_f = 0;
  } else {
    measure_DWork.clockTickCounter_f = measure_DWork.clockTickCounter_f + 1;
  }

  rtb_Compare_f = (rtb_Divide_jahfx > measure_P.Constant_Value_hpxmkf);
  rtb_UnitDelay1 = measure_DWork.UnitDelay1_DSTATE;
  rtb_Gain_m = measure_P.Constant7_Value[0];
  for (i = 0; i < 5; i++) {
    tmp[0] = measure_P.Constant7_Value[0];
    tmp[1] = measure_P.Constant7_Value[1];
    tmp[2] = measure_P.Constant7_Value[2];
    tmp[3] = measure_P.Constant8_Value[0];
    tmp[4] = measure_P.Constant8_Value[1];
    tmp[5] = measure_P.Constant8_Value[2];
    rtb_Gain_m = fmax(rtb_Gain_m, tmp[i + 1]);
  }

  rtb_Add1_h_idx = rtb_Gain_m - measure_P.Constant8_Value[0];
  rtb_Add1_h_idx_0 = rtb_Gain_m - measure_P.Constant8_Value[1];
  rtb_Add1_h_idx_1 = rtb_Gain_m - measure_P.Constant8_Value[2];
  rtb_Divide_jahfx = ((rtb_Gain_m - measure_P.Constant7_Value[1]) *
                      measure_P.Gain_Gain_h) + measure_P.Bias_Bias_j;
  rtb_Divide_jahfx = ((((measure_U.Vabcpu[1] - measure_DWork.UnitDelay2_DSTATE) *
                        measure_P.Gain_Gain_g) * rtb_Divide_jahfx) +
                      measure_DWork.UnitDelay1_DSTATE) +
    ((((measure_DWork.UnitDelay2_DSTATE + measure_U.Vabcpu[1]) *
       measure_P.Gain1_Gain_dt) - measure_DWork.UnitDelay1_DSTATE) *
     (rtb_Divide_jahfx * rtb_Divide_jahfx));
  rtb_UnitDelay1_a = measure_DWork.UnitDelay1_DSTATE_i;
  rtb_Switch_b = ((rtb_Gain_m - measure_P.Constant7_Value[2]) *
                  measure_P.Gain_Gain_d) + measure_P.Bias_Bias_it;
  rtb_Switch_b = ((((measure_U.Vabcpu[2] - measure_DWork.UnitDelay2_DSTATE_a) *
                    measure_P.Gain_Gain_j) * rtb_Switch_b) +
                  measure_DWork.UnitDelay1_DSTATE_i) +
    ((((measure_DWork.UnitDelay2_DSTATE_a + measure_U.Vabcpu[2]) *
       measure_P.Gain1_Gain_a) - measure_DWork.UnitDelay1_DSTATE_i) *
     (rtb_Switch_b * rtb_Switch_b));
  rtb_UnitDelay1_i = measure_DWork.UnitDelay1_DSTATE_b;
  rtb_IpktoIrms_a = ((rtb_Gain_m - measure_P.Constant7_Value[0]) *
                     measure_P.Gain_Gain_b) + measure_P.Bias_Bias_pv;
  rtb_IpktoIrms_a = ((((measure_U.Vabcpu[0] - measure_DWork.UnitDelay2_DSTATE_c)
                       * measure_P.Gain_Gain_ew) * rtb_IpktoIrms_a) +
                     measure_DWork.UnitDelay1_DSTATE_b) +
    ((((measure_DWork.UnitDelay2_DSTATE_c + measure_U.Vabcpu[0]) *
       measure_P.Gain1_Gain_dy) - measure_DWork.UnitDelay1_DSTATE_b) *
     (rtb_IpktoIrms_a * rtb_IpktoIrms_a));
  rtb_TrigonometricFunction = rt_atan2d_snf((rtb_Divide_jahfx - rtb_Switch_b) *
    measure_P.Gain2_Gain, ((measure_P.Gain_Gain_n * rtb_IpktoIrms_a) -
    (rtb_Divide_jahfx + rtb_Switch_b)) * measure_P.Gain1_Gain_n);
  rtb_Sum2_g = rtb_TrigonometricFunction - measure_DWork.UnitDelay3_DSTATE;
  if (rtb_Sum2_g < measure_P.Constant_Value_ne) {
    rtb_Sum2_g += measure_P.Bias1_Bias_n;
  } else {
    if (rtb_Sum2_g > measure_P.Constant_Value_n) {
      rtb_Sum2_g += measure_P.Bias_Bias_n;
    }
  }

  measure_B.Gain = measure_P.Gain_Gain_ne * rtb_Sum2_g;
  if ((!rtb_Compare_f) && (measure_DWork.delay1_DSTATE_l)) {
    measure_B.Switch = measure_P.double_Value_ne;
  } else {
    measure_B.Switch = (measure_B.Gain + measure_DWork.UnitDelay4_DSTATE) +
      measure_DWork.UnitDelay2_DSTATE_l;
  }

  rtb_MathFunction1 = 1.0 / measure_DWork.UnitDelay_DSTATE_e;
  if (rtb_MathFunction1 < measure_P.Constant_Value_hpxmkfi) {
    rtb_Switch = measure_P.Constant_Value_hp;
  } else if (rtb_MathFunction1 > measure_P.Constant_Value_h) {
    rtb_Switch = measure_P.Constant1_Value_h;
  } else {
    rtb_Switch = rtb_MathFunction1;
  }

  rtb_Gain_m = measure_P.Gain_Gain_hp * rtb_Switch;
  if (0.0 != 0.0) {
    measure_B.Switch2 = rtb_Gain_m + measure_P.Bias1_Bias_h;
  } else if (rtb_Gain_m < measure_P.Constant_Value_hpxmkfin) {
    measure_B.Switch2 = rtb_Gain_m;
  } else {
    measure_B.Switch2 = rtb_Gain_m + measure_P.Bias_Bias_h;
  }

  {
    measure_B.SFunction = (int)measure_B.Switch2;
  }

  if (measure_B.SFunction < measure_P.Constant_Value_hpxmkfinoyshikv) {
    measure_B.Switch2_lr = measure_P.Constant_Value_hpxmkfinoysh;
  } else if (measure_B.SFunction > measure_P.Constant_Value_hpxmkfinoys) {
    measure_B.Switch2_lr = measure_P.Constant3_Value_h;
  } else {
    measure_B.Switch2_lr = measure_B.SFunction;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneTap[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_pz;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch;
    VDD_out = *VDD_in - measure_B.Switch2_lr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTap;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTap = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTap)
      *VDD_in = 0;
  }

  if (rtb_Compare_f && (!measure_DWork.delay_DSTATE_i)) {
    measure_B.Switch_j = measure_P.double_Value_nes;
  } else {
    measure_B.Switch_j = (measure_B.Gain + measure_DWork.UnitDelay4_DSTATE_k) +
      measure_DWork.UnitDelay2_DSTATE_ls;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_i[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_pzv;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_j;
    VDD_out = *VDD_in - measure_B.Switch2_lr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_n;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_n = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_n)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoTap[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_m;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Gain;
    VDD_out = *VDD_in - measure_B.Switch2_lr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTap;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTap)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator1_f) {
    measure_B.Switch2_p = rtb_Switch1_k;
  } else {
    rtb_Gain_m = ((real_T)measure_B.Switch2_lr) - rtb_Gain_m;
    rtb_Switch1_kt5c = rtb_Gain_m * rtb_Gain_m;
    rtb_Gain_m = (((measure_P.Gain1_Gain_h * rtb_Gain_m) - rtb_Switch1_kt5c) *
                  measure_B.VariableDiscreteDelaywithTwoTap) +
      (measure_B.VariableDiscreteDelaywithTwoT_g * rtb_Switch1_kt5c);
    if (rtb_Compare_f) {
      rtb_Switch1_kt5c = measure_B.Switch -
        measure_B.VariableDiscreteDelaywithOneTap;
    } else {
      rtb_Switch1_kt5c = measure_B.Switch_j -
        measure_B.VariableDiscreteDelaywithOneT_n;
    }

    rtb_Gain_m = ((1.0 / rtb_Switch) * measure_P.Gain_Gain) * (rtb_Switch1_kt5c
      - rtb_Gain_m);
    if (rtb_Gain_m < measure_P.Constant_Value_nes) {
      measure_B.Switch2_p = -rtb_Gain_m;
    } else {
      measure_B.Switch2_p = rtb_Gain_m;
    }
  }

  if (rtb_Compare_c2o) {
    measure_B.Switch_jc = measure_P.double_Value_nesm;
  } else {
    measure_B.Switch_jc = (measure_B.Switch2_p +
      measure_DWork.UnitDelay4_DSTATE_kr) + measure_DWork.UnitDelay2_DSTATE_lsc;
  }

  rtb_Gain_m = measure_P.Gain_Gain_ni * rtb_MathFunction1;
  if (rtb_Gain_m < measure_P.Constant_Value_hpxmkfino) {
    rtb_Sum2_g = measure_P.Constant_Value_hpxm;
  } else if (rtb_Gain_m > measure_P.Constant_Value_hpx) {
    rtb_Sum2_g = measure_P.Constant1_Value_hp;
  } else {
    rtb_Sum2_g = rtb_Gain_m;
  }

  rtb_Gain_m = measure_P.Gain_Gain_hpx * rtb_Sum2_g;
  if (0.0 != 0.0) {
    measure_B.Switch2_l = rtb_Gain_m + measure_P.Bias1_Bias_hp;
  } else if (rtb_Gain_m < measure_P.Constant_Value_hpxmkfinoy) {
    measure_B.Switch2_l = rtb_Gain_m;
  } else {
    measure_B.Switch2_l = rtb_Gain_m + measure_P.Bias_Bias_hp;
  }

  {
    measure_B.SFunction_i = (int)measure_B.Switch2_l;
  }

  if (measure_B.SFunction_i < measure_P.Constant_Value_n5) {
    measure_B.Switch2_lrp = measure_P.Constant_Value_hpxmkfinoyshik;
  } else if (measure_B.SFunction_i > measure_P.Constant_Value_hpxmkfinoyshi) {
    measure_B.Switch2_lrp = measure_P.Constant3_Value_hp;
  } else {
    measure_B.Switch2_lrp = measure_B.SFunction_i;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_iq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_pzv4;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jc;
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_ne;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_nd = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_ne)
      *VDD_in = 0;
  }

  rtb_Compare_c2os = (rtb_Compare && (!measure_DWork.delay_DSTATE_i2));
  if (rtb_Compare_c2os) {
    measure_B.Switch_jc4 = measure_P.double_Value_nesmw;
  } else {
    measure_B.Switch_jc4 = (measure_B.Switch2_p +
      measure_DWork.UnitDelay4_DSTATE_krx) +
      measure_DWork.UnitDelay2_DSTATE_lscn;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_iqv[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_pzv45;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jc4;
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_nes;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_ndl = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_nes)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_b[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_mw;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch2_p;
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_n;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_n)
      *VDD_in = 0;
  }

  rtb_Tps2dt_m = ((real_T)measure_B.Switch2_lrp) - rtb_Gain_m;
  rtb_Switch1_kt5c = rtb_Tps2dt_m * rtb_Tps2dt_m;
  rtb_Switch = (measure_P.Gain1_Gain_hp * rtb_Tps2dt_m) - rtb_Switch1_kt5c;
  rtb_MathFunction1 = (1.0 / rtb_Sum2_g) * measure_P.Gain_Gain_hpxm;
  if (rtb_LogicalOperator1_f) {
    measure_B.Switch4 = rtb_Switch1_k;
  } else {
    if (rtb_Compare) {
      rtb_Gain_m = measure_B.Switch_jc -
        measure_B.VariableDiscreteDelaywithOne_nd;
    } else {
      rtb_Gain_m = measure_B.Switch_jc4 -
        measure_B.VariableDiscreteDelaywithOn_ndl;
    }

    measure_B.Switch4 = (rtb_Gain_m -
                         ((measure_B.VariableDiscreteDelaywithTwoT_h *
      rtb_Switch) + (measure_B.VariableDiscreteDelaywithTwo_gt *
                     rtb_Switch1_kt5c))) * rtb_MathFunction1;
  }

  if (rtb_Compare_c2o) {
    measure_B.Switch_jc4w = measure_P.double_Value_nesmwp;
  } else {
    measure_B.Switch_jc4w = (measure_B.Switch4 +
      measure_DWork.UnitDelay4_DSTATE_krxz) +
      measure_DWork.UnitDelay2_DSTATE_lscnp;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_iqvv[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_pzv45h;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jc4w;
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_nesm;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithO_ndlj = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_nesm)
      *VDD_in = 0;
  }

  if (rtb_Compare_c2os) {
    measure_B.Switch_jc4wm = measure_P.double_Value_nesmwp2;
  } else {
    measure_B.Switch_jc4wm = (measure_B.Switch4 +
      measure_DWork.UnitDelay4_DSTATE_krxzy) +
      measure_DWork.UnitDelay2_DSTATE_lscnp0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_iqvvo[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_pzv45hn;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jc4wm;
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_nesmw;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywith_ndljw = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_nesmw)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_bq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_mw3;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch4;
    VDD_out = *VDD_in - measure_B.Switch2_lrp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_ne;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_ne)
      *VDD_in = 0;
  }

  rtb_Tps2dt_m = measure_P.Gain1_Gain_f * measure_P.Constant5_Value;
  rtb_Sum2_g = rtb_Tps2dt_m + measure_P.Bias_Bias_fk;
  if (rtb_Sum2_g > measure_P.Constant_Value_fk) {
    rtb_Sum2_g = measure_P.Constant_Value_f;
  }

  rtb_Compare_c2os = (((measure_B.Gain < rtb_Sum2_g) && (measure_B.Gain >
    (-rtb_Tps2dt_m))) || rtb_UnitDelay4_ej);
  if (rtb_Compare_c2os) {
    rtb_Switch1_bxh = measure_DWork.UnitDelay1_DSTATE_omtd1hdp;
  } else {
    rtb_Switch1_bxh = measure_P.const_Value_fk;
  }

  rtb_Compare_c2 = (rtb_Switch1_bxh == measure_P.Constant_Value_fkx);
  if (rtb_Compare_c2os) {
    rtb_UnitDelay1_pf = measure_DWork.UnitDelay1_DSTATE_omtd1hdpu;
  } else {
    rtb_UnitDelay1_pf = measure_P.const_Value_f;
  }

  rtb_Compare_c2o = (rtb_UnitDelay1_pf == measure_P.Constant_Value_fkxn);
  if (rtb_Compare_c2o) {
    if (rtb_Compare_c2) {
      if (!rtb_LogicalOperator1_f) {
        if (rtb_Compare) {
          rtb_Gain_m = measure_B.Switch_jc4w -
            measure_B.VariableDiscreteDelaywithO_ndlj;
        } else {
          rtb_Gain_m = measure_B.Switch_jc4wm -
            measure_B.VariableDiscreteDelaywith_ndljw;
        }

        rtb_Switch1_k = (rtb_Gain_m -
                         ((measure_B.VariableDiscreteDelaywithTwo_h0 *
                           rtb_Switch) +
                          (measure_B.VariableDiscreteDelaywithTw_gtq *
                           rtb_Switch1_kt5c))) * rtb_MathFunction1;
      }
    } else {
      rtb_Switch1_k = measure_B.Switch4;
    }

    measure_B.Switch2_c = rtb_Switch1_k;
  } else {
    measure_B.Switch2_c = measure_B.Switch2_p;
  }

  rtb_Tps2dt_m = ((((real_T)measure_DWork.clockTickCounter_n) <
                   measure_P.PulseGenerator1_Duty_e) &&
                  (measure_DWork.clockTickCounter_n >= 0)) ?
    measure_P.PulseGenerator1_Amp_e : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_n) >=
      (measure_P.PulseGenerator1_Period_e - 1.0)) {
    measure_DWork.clockTickCounter_n = 0;
  } else {
    measure_DWork.clockTickCounter_n = measure_DWork.clockTickCounter_n + 1;
  }

  rtb_Compare_d = (rtb_Tps2dt_m > measure_P.Constant_Value_li);
  rtb_LogicalOperator1_drl4 = ((!rtb_Compare_d) &&
    (measure_DWork.delay1_DSTATE_f));
  if (rtb_LogicalOperator1_drl4) {
    measure_B.Switch_i = measure_P.double_Value_e;
  } else {
    measure_B.Switch_i = (measure_B.Switch2_c +
                          measure_DWork.UnitDelay4_DSTATE_krxzyr) +
      measure_DWork.UnitDelay2_DSTATE_lscnp0r;
  }

  if (measure_DWork.UnitDelay2_DSTATE_lscnp0r3 < measure_P.Constant_Value_a2) {
    rtb_Tps2dt_m = measure_P.Constant_Value_epwu2gd3xoydf;
  } else if (measure_DWork.UnitDelay2_DSTATE_lscnp0r3 >
             measure_P.Constant_Value_epwu2gd3xoyd) {
    rtb_Tps2dt_m = measure_P.Constant1_Value_epwu;
  } else {
    rtb_Tps2dt_m = measure_DWork.UnitDelay2_DSTATE_lscnp0r3;
  }

  rtb_Gain_m = measure_P.Gain_Gain_ep * rtb_Tps2dt_m;
  if (0.0 != 0.0) {
    measure_B.Switch2_a = rtb_Gain_m + measure_P.Bias1_Bias_ep;
  } else if (rtb_Gain_m < measure_P.Constant_Value_pz) {
    measure_B.Switch2_a = rtb_Gain_m;
  } else {
    measure_B.Switch2_a = rtb_Gain_m + measure_P.Bias_Bias_ep;
  }

  {
    measure_B.SFunction_m = (int)measure_B.Switch2_a;
  }

  if (measure_B.SFunction_m < measure_P.Constant_Value_ds) {
    measure_B.Switch2_a4fq3 = measure_P.Constant_Value_h1;
  } else if (measure_B.SFunction_m > measure_P.Constant_Value_ng) {
    measure_B.Switch2_a4fq3 = measure_P.Constant3_Value_e;
  } else {
    measure_B.Switch2_a4fq3 = measure_B.SFunction_m;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_iqvvod[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_pzv45hn0;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_i;
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_e;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywit_ndljwv = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_e)
      *VDD_in = 0;
  }

  rtb_LogicalOperator_aiui = (rtb_Compare_d && (!measure_DWork.delay_DSTATE_n));
  if (rtb_LogicalOperator_aiui) {
    measure_B.Switch_iw = measure_P.double_Value_ep;
  } else {
    measure_B.Switch_iw = (measure_B.Switch2_c +
      measure_DWork.UnitDelay4_DSTATE_krxzyrk) +
      measure_DWork.UnitDelay2_DSTATE_lscnp0r3j;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_iqvvods[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_pzv45hn0c;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_iw;
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_ep;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywi_ndljwvw = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_ep)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Sum2_g = measure_B.Switch_i - measure_B.VariableDiscreteDelaywit_ndljwv;
  } else {
    rtb_Sum2_g = measure_B.Switch_iw - measure_B.VariableDiscreteDelaywi_ndljwvw;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_bqv[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_mw3l;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch2_c;
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_e;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_e)
      *VDD_in = 0;
  }

  rtb_Subtract3_o = ((real_T)measure_B.Switch2_a4fq3) - rtb_Gain_m;
  rtb_MathFunction_bdy = rtb_Subtract3_o * rtb_Subtract3_o;
  rtb_Subtract3_o = (measure_P.Gain1_Gain_e * rtb_Subtract3_o) -
    rtb_MathFunction_bdy;
  rtb_Tps2dt_m = (1.0 / rtb_Tps2dt_m) * measure_P.Gain_Gain_epw;
  rtb_Sum2_g = (rtb_Sum2_g - ((measure_B.VariableDiscreteDelaywithTw_h0q *
    rtb_Subtract3_o) + (measure_B.VariableDiscreteDelaywithT_gtqs *
                        rtb_MathFunction_bdy))) * rtb_Tps2dt_m;
  measure_B.ACripple1stestimate = measure_B.Switch2_c - rtb_Sum2_g;
  if (measure_B.ACripple1stestimate < measure_P.Constant_Value_ed) {
    rtb_UnaryMinus_a2 = -measure_B.ACripple1stestimate;
  } else {
    rtb_UnaryMinus_a2 = measure_B.ACripple1stestimate;
  }

  if (rtb_UnaryMinus_a2 > (measure_P.Gain1_Gain_n5 * measure_P.Constant2_Value_h))
  {
    rtb_UnitDelay1_nt = measure_P.int32_Value;
  } else {
    rtb_UnitDelay1_nt = measure_DWork.UnitDelay_DSTATE_ehb -
      measure_P.FixPtConstant_Value_e;
  }

  rtb_Compare_no = (rtb_UnitDelay1_nt > measure_P.Constant_Value_e3);
  if (rtb_Compare_no) {
    measure_B.Switch2_a4 = measure_B.Switch2_c;
  } else {
    measure_B.Switch2_a4 = rtb_Sum2_g;
  }

  if (rtb_UnitDelay4_ej) {
    rtb_Gain_m = rtb_Switch1_b;
  } else {
    rtb_Gain_m = measure_B.Switch2_a4;
  }

  if (rtb_Gain_m < measure_P.Constant_Value_aw) {
    rtb_Switch_j = measure_P.Constant_Value_m;
  } else if (rtb_Gain_m > measure_P.Constant_Value_a) {
    rtb_Switch_j = measure_P.Constant1_Value_m;
  } else {
    rtb_Switch_j = rtb_Gain_m;
  }

  if (rtb_Compare_c2os) {
    rtb_Switch1_c1 = measure_DWork.UnitDelay1_DSTATE_omtd1hdput;
  } else {
    rtb_Switch1_c1 = measure_P.const_Value;
  }

  rtb_Compare_c2os = (rtb_Switch1_c1 == measure_P.Constant_Value_fkxna);
  rtb_LogicalOperator1_i = (rtb_Compare_c2os || rtb_UnitDelay4_ej);
  if (rtb_LogicalOperator1_i) {
    rtb_Switch1_c = rtb_Switch_j;
  } else {
    rtb_Switch1_c = measure_P.Constant1_Value_g;
  }

  rtb_UnitDelay1_n0 = measure_DWork.UnitDelay1_DSTATE_gf;
  rtb_UnitDelay2_j = measure_DWork.UnitDelay2_DSTATE_h;
  rtb_LogicalOperator1_f = measure_DWork.UnitDelay4_DSTATE_ii;
  rtb_LogicalOperator16 = (rtb_LogicalOperator1_i && (!rtb_UnitDelay4_ej));
  rtb_UnitDelay1_k = measure_DWork.UnitDelay1_DSTATE_m4;
  rtb_UnaryMinus_a2 = ((((real_T)measure_DWork.clockTickCounter_e) <
                        measure_P.PulseGenerator1_Duty_a) &&
                       (measure_DWork.clockTickCounter_e >= 0)) ?
    measure_P.PulseGenerator1_Amp_a : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_e) >=
      (measure_P.PulseGenerator1_Period_a - 1.0)) {
    measure_DWork.clockTickCounter_e = 0;
  } else {
    measure_DWork.clockTickCounter_e = measure_DWork.clockTickCounter_e + 1;
  }

  rtb_Compare_o = (rtb_UnaryMinus_a2 > measure_P.Constant_Value_adhzk50wx);
  rtb_LogicalOperator1_b2ck = ((!rtb_Compare_o) &&
    (measure_DWork.delay1_DSTATE_n));
  rtb_Sum = (measure_P.Gain_Gain_a * measure_DWork.UnitDelay2_DSTATE_h) +
    measure_DWork.UnitDelay_DSTATE_f;
  if (rtb_Sum > measure_P.Constant_Value_adhzk50wx0) {
    rtb_Sum += measure_P.Bias_Bias_a;
  }

  rtb_UnaryMinus_a2 = std::sin(rtb_Sum);
  rtb_Sum2_g = std::cos(rtb_Sum);
  if (measure_DWork.UnitDelay2_DSTATE_h < measure_P.Constant_Value_adhzk50wx0e)
  {
    rtb_Switch4 = measure_P.Constant_Value_ad;
  } else {
    rtb_Switch4 = measure_DWork.UnitDelay2_DSTATE_h;
  }

  rtb_Divide_jah = ((measure_DWork.UnitDelay2_DSTATE_h - rtb_Switch4) *
                    measure_P.FCn3_Gain) + measure_P.Bias_Bias_adhzk;
  measure_B.Product[0] = (rtb_IpktoIrms_a * rtb_UnaryMinus_a2) * rtb_Divide_jah;
  measure_B.Product[1] = (rtb_IpktoIrms_a * rtb_Sum2_g) * rtb_Divide_jah;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_ix = measure_P.double_Value_bln4;
  } else {
    measure_B.Switch_ix = (measure_B.Product[0] +
      measure_DWork.UnitDelay4_DSTATE_j) + measure_DWork.UnitDelay2_DSTATE_lj;
  }

  rtb_Switch = 1.0 / rtb_Switch4;
  if (rtb_Switch < measure_P.Constant_Value_adhzk50wx0e4) {
    rtb_Switch4 = measure_P.Constant_Value_adhz;
  } else if (rtb_Switch > measure_P.Constant_Value_adh) {
    rtb_Switch4 = measure_P.Constant1_Value_a;
  } else {
    rtb_Switch4 = rtb_Switch;
  }

  rtb_Gain_m = measure_P.Gain_Gain_ad * rtb_Switch4;
  if (0.0 != 0.0) {
    measure_B.Switch2_h = rtb_Gain_m + measure_P.Bias1_Bias_a;
  } else if (rtb_Gain_m < measure_P.Constant_Value_adhzk50wx0e4y) {
    measure_B.Switch2_h = rtb_Gain_m;
  } else {
    measure_B.Switch2_h = rtb_Gain_m + measure_P.Bias_Bias_ad;
  }

  {
    measure_B.SFunction_m3 = (int)measure_B.Switch2_h;
  }

  if (measure_B.SFunction_m3 < measure_P.Constant_Value_a1) {
    measure_B.Switch2_hhsc = measure_P.Constant_Value_aj;
  } else if (measure_B.SFunction_m3 > measure_P.Constant_Value_jv) {
    measure_B.Switch2_hhsc = measure_P.Constant3_Value_a;
  } else {
    measure_B.Switch2_hhsc = measure_B.SFunction_m3;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_f[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_hg;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ix;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_b;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_p = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_b)
      *VDD_in = 0;
  }

  rtb_LogicalOperator_aj = (rtb_Compare_o && (!measure_DWork.delay_DSTATE_c));
  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_ixh = measure_P.double_Value_bln4d;
  } else {
    measure_B.Switch_ixh = (measure_B.Product[0] +
      measure_DWork.UnitDelay4_DSTATE_js) + measure_DWork.UnitDelay2_DSTATE_ljf;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_f2[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_hgo;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixh;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_bl;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_pd = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_bl)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Divide_ja = measure_B.Switch_ix -
      measure_B.VariableDiscreteDelaywithOneT_p;
  } else {
    rtb_Divide_ja = measure_B.Switch_ixh -
      measure_B.VariableDiscreteDelaywithOne_pd;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_a[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_o;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product[0];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_b;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_b)
      *VDD_in = 0;
  }

  rtb_Subtract3_c0 = ((real_T)measure_B.Switch2_hhsc) - rtb_Gain_m;
  rtb_MathFunction_ed1 = rtb_Subtract3_c0 * rtb_Subtract3_c0;
  rtb_Subtract3_c0 = (measure_P.Gain1_Gain_ad * rtb_Subtract3_c0) -
    rtb_MathFunction_ed1;
  rtb_Gain_m = rtb_Divide_ja - ((measure_B.VariableDiscreteDelaywithTwoT_i *
    rtb_Subtract3_c0) + (measure_B.VariableDiscreteDelaywithTwo_iz *
    rtb_MathFunction_ed1));
  rtb_Divide_ja = (1.0 / rtb_Switch4) * measure_P.Gain_Gain_adh;
  measure_B.Divide = rtb_Gain_m * rtb_Divide_ja;
  rtb_Gain_m = measure_B.Divide * measure_B.Divide;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_ixhv = measure_P.double_Value_bln4dj;
  } else {
    measure_B.Switch_ixhv = (measure_B.Product[1] +
      measure_DWork.UnitDelay4_DSTATE_js0) +
      measure_DWork.UnitDelay2_DSTATE_ljfw;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_f2j[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_hgow;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhv;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_bln;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_pdh = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_bln)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_ixhvn = measure_P.double_Value_bln4djb;
  } else {
    measure_B.Switch_ixhvn = (measure_B.Product[1] +
      measure_DWork.UnitDelay4_DSTATE_js0g) +
      measure_DWork.UnitDelay2_DSTATE_ljfwk;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_f2jg[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_hgowj;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvn;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_bln4;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithO_pdh5 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_bln4)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Switch4 = measure_B.Switch_ixhv -
      measure_B.VariableDiscreteDelaywithOn_pdh;
  } else {
    rtb_Switch4 = measure_B.Switch_ixhvn -
      measure_B.VariableDiscreteDelaywithO_pdh5;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_ab[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_oc;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product[1];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_bl;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_bl)
      *VDD_in = 0;
  }

  measure_B.Divide_h = (rtb_Switch4 -
                        ((measure_B.VariableDiscreteDelaywithTwo_im *
    rtb_Subtract3_c0) + (measure_B.VariableDiscreteDelaywithTw_izc *
    rtb_MathFunction_ed1))) * rtb_Divide_ja;
  rtb_Switch4 = (measure_B.Divide_h * measure_B.Divide_h) + rtb_Gain_m;
  rtb_MathFunction2 = (rtb_Switch4 < 0.0) ? (-std::sqrt(std::abs(rtb_Switch4))) :
    std::sqrt(rtb_Switch4);
  rtb_RelationalOperator_c = (rtb_MathFunction2 > measure_P.Constant5_Value);
  rtb_Compare_k1g = (rtb_RelationalOperator_c || rtb_UnitDelay4_hd);
  if (rtb_Compare_k1g) {
    rtb_Switch1_m = rtb_UnitDelay1_k;
  } else {
    rtb_Switch1_m = measure_P.const_Value_o;
  }

  rtb_Compare_ha = (rtb_Switch1_m == measure_P.Constant_Value_lo);
  rtb_UnitDelay1_k = measure_DWork.UnitDelay1_DSTATE_j4;
  measure_B.Product_j[0] = (rtb_Divide_jahfx * rtb_UnaryMinus_a2) *
    rtb_Divide_jah;
  measure_B.Product_j[1] = (rtb_Divide_jahfx * rtb_Sum2_g) * rtb_Divide_jah;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_d = measure_P.double_Value_eznc;
  } else {
    measure_B.Switch_d = (measure_B.Product_j[0] +
                          measure_DWork.UnitDelay4_DSTATE_e) +
      measure_DWork.UnitDelay2_DSTATE_ab;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_f2jgc[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_hgowjf;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_d;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_ez;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywith_pdh55 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_ez)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_dh = measure_P.double_Value_ezncl;
  } else {
    measure_B.Switch_dh = (measure_B.Product_j[0] +
      measure_DWork.UnitDelay4_DSTATE_e1) + measure_DWork.UnitDelay2_DSTATE_abj;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_f2jgc1[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_hgowjfv;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dh;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_ezn;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywit_pdh55d = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_ezn)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Switch4 = measure_B.Switch_d - measure_B.VariableDiscreteDelaywith_pdh55;
  } else {
    rtb_Switch4 = measure_B.Switch_dh -
      measure_B.VariableDiscreteDelaywit_pdh55d;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_ab4[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_oci;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_j[0];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_ez;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_ez)
      *VDD_in = 0;
  }

  measure_B.Divide_n = (rtb_Switch4 -
                        ((measure_B.VariableDiscreteDelaywithTw_imq *
    rtb_Subtract3_c0) + (measure_B.VariableDiscreteDelaywithT_izcm *
    rtb_MathFunction_ed1))) * rtb_Divide_ja;
  rtb_Gain_m = measure_B.Divide_n * measure_B.Divide_n;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_dh3 = measure_P.double_Value_eznclc;
  } else {
    measure_B.Switch_dh3 = (measure_B.Product_j[1] +
      measure_DWork.UnitDelay4_DSTATE_e10) +
      measure_DWork.UnitDelay2_DSTATE_abju;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_f2jgc1y[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_hgowjfvn;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_eznc;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywi_pdh55di = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_eznc)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_dh3i = measure_P.double_Value_eznclc5;
  } else {
    measure_B.Switch_dh3i = (measure_B.Product_j[1] +
      measure_DWork.UnitDelay4_DSTATE_e10c) +
      measure_DWork.UnitDelay2_DSTATE_abju3;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_f2jgc1yy[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_hgowjfvnn;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3i;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_ezncl;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelayw_pdh55dim = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_ezncl)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Switch4 = measure_B.Switch_dh3 -
      measure_B.VariableDiscreteDelaywi_pdh55di;
  } else {
    rtb_Switch4 = measure_B.Switch_dh3i -
      measure_B.VariableDiscreteDelayw_pdh55dim;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_ab4s[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_oci4;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_j[1];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_ezn;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_ezn)
      *VDD_in = 0;
  }

  measure_B.Divide_ny = (rtb_Switch4 -
    ((measure_B.VariableDiscreteDelaywithT_imqp * rtb_Subtract3_c0) +
     (measure_B.VariableDiscreteDelaywith_izcmu * rtb_MathFunction_ed1))) *
    rtb_Divide_ja;
  rtb_Switch4 = (measure_B.Divide_ny * measure_B.Divide_ny) + rtb_Gain_m;
  rtb_MathFunction2_c = (rtb_Switch4 < 0.0) ? (-std::sqrt(std::abs(rtb_Switch4)))
    : std::sqrt(rtb_Switch4);
  rtb_RelationalOperator_i = (rtb_MathFunction2_c > measure_P.Constant5_Value);
  rtb_Compare_aun = (rtb_RelationalOperator_i || rtb_UnitDelay4_hd);
  if (rtb_Compare_aun) {
    rtb_Switch1_o = rtb_UnitDelay1_k;
  } else {
    rtb_Switch1_o = measure_P.const_Value_ec;
  }

  rtb_Compare_df = (rtb_Switch1_o == measure_P.Constant_Value_cm);
  rtb_UnitDelay1_k = measure_DWork.UnitDelay1_DSTATE_g0;
  measure_B.Product_k[0] = (rtb_Switch_b * rtb_UnaryMinus_a2) * rtb_Divide_jah;
  measure_B.Product_k[1] = (rtb_Switch_b * rtb_Sum2_g) * rtb_Divide_jah;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_p = measure_P.double_Value_e0r1;
  } else {
    measure_B.Switch_p = (measure_B.Product_k[0] +
                          measure_DWork.UnitDelay4_DSTATE_o) +
      measure_DWork.UnitDelay2_DSTATE_g;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_f2jgc1yyu[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_hgowjfvnnx;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_e0;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelay_pdh55dim3 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_e0)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_p0 = measure_P.double_Value_e0r1h;
  } else {
    measure_B.Switch_p0 = (measure_B.Product_k[0] +
      measure_DWork.UnitDelay4_DSTATE_ot) + measure_DWork.UnitDelay2_DSTATE_gl;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_f2jgc1yyuf[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_hgowjfvnnxz;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p0;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_e0r;
      VDD_out++;
    }

    measure_B.VariableDiscreteDela_pdh55dim3o = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_e0r)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Switch4 = measure_B.Switch_p - measure_B.VariableDiscreteDelay_pdh55dim3;
  } else {
    rtb_Switch4 = measure_B.Switch_p0 -
      measure_B.VariableDiscreteDela_pdh55dim3o;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_ab4s3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_oci4c;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_k[0];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_e0;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_e0)
      *VDD_in = 0;
  }

  measure_B.Divide_j = (rtb_Switch4 -
                        ((measure_B.VariableDiscreteDelaywith_imqpt *
    rtb_Subtract3_c0) + (measure_B.VariableDiscreteDelaywit_izcmu0 *
    rtb_MathFunction_ed1))) * rtb_Divide_ja;
  rtb_Gain_m = measure_B.Divide_j * measure_B.Divide_j;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_p0n = measure_P.double_Value_e0r1hm;
  } else {
    measure_B.Switch_p0n = (measure_B.Product_k[1] +
      measure_DWork.UnitDelay4_DSTATE_otw) + measure_DWork.UnitDelay2_DSTATE_gll;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_f2jgc1yyufb[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_hgowjfvnnxzl;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p0n;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_e0r1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDel_pdh55dim3ox = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_e0r1)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_p0ny = measure_P.double_Value_e0r1hmw;
  } else {
    measure_B.Switch_p0ny = (measure_B.Product_k[1] +
      measure_DWork.UnitDelay4_DSTATE_otws) +
      measure_DWork.UnitDelay2_DSTATE_gllv;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_f2jgc1yyufbl[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_hgowjfvnnxzlo;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_e0r1h;
      VDD_out++;
    }

    measure_B.VariableDiscreteDe_pdh55dim3oxm = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_e0r1h)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Switch4 = measure_B.Switch_p0n -
      measure_B.VariableDiscreteDel_pdh55dim3ox;
  } else {
    rtb_Switch4 = measure_B.Switch_p0ny -
      measure_B.VariableDiscreteDe_pdh55dim3oxm;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_ab4s3q[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_oci4cw;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_k[1];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_e0r;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_e0r)
      *VDD_in = 0;
  }

  measure_B.Divide_jw = (rtb_Switch4 -
    ((measure_B.VariableDiscreteDelaywit_imqptq * rtb_Subtract3_c0) +
     (measure_B.VariableDiscreteDelaywi_izcmu0m * rtb_MathFunction_ed1))) *
    rtb_Divide_ja;
  rtb_Switch4 = (measure_B.Divide_jw * measure_B.Divide_jw) + rtb_Gain_m;
  rtb_MathFunction2_a = (rtb_Switch4 < 0.0) ? (-std::sqrt(std::abs(rtb_Switch4)))
    : std::sqrt(rtb_Switch4);
  rtb_RelationalOperator_h = (rtb_MathFunction2_a > measure_P.Constant5_Value);
  rtb_Compare_o1 = (rtb_RelationalOperator_h || rtb_UnitDelay4_hd);
  if (rtb_Compare_o1) {
    rtb_Switch1_k3g = rtb_UnitDelay1_k;
  } else {
    rtb_Switch1_k3g = measure_P.const_Value_l;
  }

  rtb_Compare_m3 = (rtb_Switch1_k3g == measure_P.Constant_Value_him);
  rtb_LogicalOperator9 = !((rtb_Compare_ha || rtb_Compare_df) || rtb_Compare_m3);
  if (rtb_UnitDelay4_hd) {
    rtb_Switch4 = rtb_UnitDelay2_j;
  } else if (rtb_LogicalOperator1_f) {
    rtb_Switch4 = rtb_Switch1_c;
  } else if (rtb_LogicalOperator9) {
    if (rtb_LogicalOperator16) {
      rtb_Switch4 = rtb_Switch1_c;
    } else {
      rtb_Switch4 = measure_P.Constant4_Value;
    }
  } else {
    rtb_Switch4 = rtb_UnitDelay2_j;
  }

  rtb_Compare_mp = ((rtb_UnitDelay4_hd || rtb_LogicalOperator1_f) ||
                    rtb_LogicalOperator9);
  rtb_Compare_go = (rtb_Compare_mp || (!(rtb_Compare_ha || rtb_LogicalOperator9)));
  rtb_Divide_h3 = ((((real_T)measure_DWork.clockTickCounter_ey) <
                    measure_P.PulseGenerator1_Duty_ad) &&
                   (measure_DWork.clockTickCounter_ey >= 0)) ?
    measure_P.PulseGenerator1_Amp_ad : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_ey) >=
      (measure_P.PulseGenerator1_Period_ad - 1.0)) {
    measure_DWork.clockTickCounter_ey = 0;
  } else {
    measure_DWork.clockTickCounter_ey = measure_DWork.clockTickCounter_ey + 1;
  }

  rtb_Compare_oafgue = (rtb_Divide_h3 > measure_P.Constant_Value_adhzk50wx0e4yn);
  rtb_Compare_k5 = ((!rtb_Compare_oafgue) && (measure_DWork.delay1_DSTATE_nm));
  rtb_Switch1_kt5c = measure_DWork.UnitDelay3_DSTATE_p;
  rtb_Divide_h3 = ((((real_T)measure_DWork.clockTickCounter_ey4) <
                    measure_P.PulseGenerator1_Duty_adh) &&
                   (measure_DWork.clockTickCounter_ey4 >= 0)) ?
    measure_P.PulseGenerator1_Amp_adh : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_ey4) >=
      (measure_P.PulseGenerator1_Period_adh - 1.0)) {
    measure_DWork.clockTickCounter_ey4 = 0;
  } else {
    measure_DWork.clockTickCounter_ey4 = measure_DWork.clockTickCounter_ey4 + 1;
  }

  rtb_Compare_oafguee = (rtb_Divide_h3 >
    measure_P.Constant_Value_adhzk50wx0e4yn1);
  rtb_Compare_bq = ((!rtb_Compare_oafguee) && (measure_DWork.delay1_DSTATE_nmq));
  if (rtb_Compare_bq) {
    measure_B.Switch_ixhvnq = measure_P.double_Value_bln4djb4gs;
  } else {
    measure_B.Switch_ixhvnq = (measure_B.Divide_h +
      measure_DWork.UnitDelay4_DSTATE_js0g0) +
      measure_DWork.UnitDelay2_DSTATE_ljfwkl;
  }

  rtb_Gain_m = measure_P.FCn1_Gain * rtb_Switch;
  if (rtb_Gain_m < measure_P.Constant_Value_d) {
    rtb_Divide_h3 = measure_P.Constant_Value_adhzk5;
  } else if (rtb_Gain_m > measure_P.Constant_Value_adhzk) {
    rtb_Divide_h3 = measure_P.Constant1_Value_ad;
  } else {
    rtb_Divide_h3 = rtb_Gain_m;
  }

  rtb_Gain_m = measure_P.Gain_Gain_adhz * rtb_Divide_h3;
  if (0.0 != 0.0) {
    measure_B.Switch2_hh = rtb_Gain_m + measure_P.Bias1_Bias_ad;
  } else if (rtb_Gain_m < measure_P.Constant_Value_gv) {
    measure_B.Switch2_hh = rtb_Gain_m;
  } else {
    measure_B.Switch2_hh = rtb_Gain_m + measure_P.Bias_Bias_adh;
  }

  {
    measure_B.SFunction_m3m = (int)measure_B.Switch2_hh;
  }

  if (measure_B.SFunction_m3m < measure_P.Constant_Value_ny) {
    measure_B.Switch2_hhsca = measure_P.Constant_Value_aa;
  } else if (measure_B.SFunction_m3m > measure_P.Constant_Value_cp) {
    measure_B.Switch2_hhsca = measure_P.Constant3_Value_ad;
  } else {
    measure_B.Switch2_hhsca = measure_B.SFunction_m3m;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_f2jgc1yyufbl2[0];
    int_T *VDD_in = &measure_DWork.VariableDiscrete_hgowjfvnnxzloq;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnq;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_bln4d;
      VDD_out++;
    }

    measure_B.VariableDiscreteD_pdh55dim3oxmt = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_bln4d)
      *VDD_in = 0;
  }

  rtb_Compare_cj = (rtb_Compare_oafguee && (!measure_DWork.delay_DSTATE_ci));
  if (rtb_Compare_cj) {
    measure_B.Switch_ixhvnql = measure_P.double_Value_bln4djb4gs5;
  } else {
    measure_B.Switch_ixhvnql = (measure_B.Divide_h +
      measure_DWork.UnitDelay4_DSTATE_js0g0x) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_f2jgc1yyufbl2v[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_hgowjfvnnxzloqs;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnql;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_bln4dj;
      VDD_out++;
    }

    measure_B.VariableDiscrete_pdh55dim3oxmtq = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_bln4dj)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_MinMax1 = measure_B.Switch_ixhvnq -
      measure_B.VariableDiscreteD_pdh55dim3oxmt;
  } else {
    rtb_MinMax1 = measure_B.Switch_ixhvnql -
      measure_B.VariableDiscrete_pdh55dim3oxmtq;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_ab4s3ql[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_oci4cw4;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_h;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_bln;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_bln)
      *VDD_in = 0;
  }

  rtb_Gain1_kh = ((real_T)measure_B.Switch2_hhsca) - rtb_Gain_m;
  rtb_Unbalance = rtb_Gain1_kh * rtb_Gain1_kh;
  rtb_Gain1_kh = (measure_P.Gain1_Gain_adh * rtb_Gain1_kh) - rtb_Unbalance;
  rtb_Gain_m = rtb_MinMax1 - ((measure_B.VariableDiscreteDelaywi_imqptqt *
    rtb_Gain1_kh) + (measure_B.VariableDiscreteDelayw_izcmu0mr * rtb_Unbalance));
  rtb_MinMax1 = (1.0 / rtb_Divide_h3) * measure_P.Gain_Gain_adhzk;
  rtb_Divide_h3 = rtb_Gain_m * rtb_MinMax1;
  if (rtb_Compare_bq) {
    measure_B.Switch_ixhvnqlu = measure_P.double_Value_bln4djb4;
  } else {
    measure_B.Switch_ixhvnqlu = (measure_B.Divide +
      measure_DWork.UnitDelay4_DSTATE_js0g0xc) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f2jgc1yyufbl2vd[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pkx;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqlu;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_bln4djb;
      VDD_out++;
    }

    measure_B.VariableDiscret_pdh55dim3oxmtqn = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_bln4djb)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_ixhvnqlui = measure_P.double_Value_bln4djb4g;
  } else {
    measure_B.Switch_ixhvnqlui = (measure_B.Divide +
      measure_DWork.UnitDelay4_DSTATE_js0g0xck) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5t;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_d[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_lw;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqlui;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_bln4djb4;
      VDD_out++;
    }

    measure_B.VariableDiscret_o = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_bln4djb4)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Divide_h = measure_B.Switch_ixhvnqlu -
      measure_B.VariableDiscret_pdh55dim3oxmtqn;
  } else {
    rtb_Divide_h = measure_B.Switch_ixhvnqlui - measure_B.VariableDiscret_o;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_ab4s3qlk[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_oci4cw4v;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_bln4;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_bln4)
      *VDD_in = 0;
  }

  rtb_Divide_h = (rtb_Divide_h - ((measure_B.VariableDiscreteDelayw_imqptqte *
    rtb_Gain1_kh) + (measure_B.VariableDiscreteDelay_izcmu0mrb * rtb_Unbalance)))
    * rtb_MinMax1;
  rtb_TrigonometricFunction_l = rt_atan2d_snf(rtb_Divide_h3, rtb_Divide_h);
  rtb_Add_a = rtb_TrigonometricFunction_l + rtb_Sum;
  if (rtb_Compare_go) {
    measure_B.Switch6 = rtb_Switch4;
  } else {
    rtb_Gain_m = rtb_Add_a - rtb_Switch1_kt5c;
    if (rtb_Gain_m < measure_P.Constant_Value_kkp) {
      rtb_Gain_m += measure_P.Bias1_Bias_k;
    } else {
      if (rtb_Gain_m > measure_P.Constant_Value_kk) {
        rtb_Gain_m += measure_P.Bias_Bias_k;
      }
    }

    rtb_Gain_m *= measure_P.Gain_Gain_k;
    if (rtb_Gain_m < measure_P.Constant_Value_bt) {
      measure_B.Switch6 = measure_P.Constant_Value_mm;
    } else if (rtb_Gain_m > measure_P.Constant_Value_hi) {
      measure_B.Switch6 = measure_P.Constant1_Value_jk;
    } else {
      measure_B.Switch6 = rtb_Gain_m;
    }
  }

  if (rtb_Compare_k5) {
    measure_B.Switch_dm = measure_P.double_Value_d1;
  } else {
    measure_B.Switch_dm = (measure_B.Switch6 + measure_DWork.UnitDelay4_DSTATE_i)
      + measure_DWork.UnitDelay2_DSTATE_l1;
  }

  rtb_Gain_m = measure_P.FCn2_Gain * rtb_Switch;
  if (rtb_Gain_m < measure_P.Constant_Value_h2) {
    rtb_Switch_l40f02 = measure_P.Constant_Value_adhzk50w;
  } else if (rtb_Gain_m > measure_P.Constant_Value_adhzk50) {
    rtb_Switch_l40f02 = measure_P.Constant1_Value_adh;
  } else {
    rtb_Switch_l40f02 = rtb_Gain_m;
  }

  rtb_Gain_m = measure_P.Gain_Gain_adhzk5 * rtb_Switch_l40f02;
  if (0.0 != 0.0) {
    measure_B.Switch2_hhs = rtb_Gain_m + measure_P.Bias1_Bias_adh;
  } else if (rtb_Gain_m < measure_P.Constant_Value_ec) {
    measure_B.Switch2_hhs = rtb_Gain_m;
  } else {
    measure_B.Switch2_hhs = rtb_Gain_m + measure_P.Bias_Bias_adhz;
  }

  {
    measure_B.SFunction_m3ml = (int)measure_B.Switch2_hhs;
  }

  if (measure_B.SFunction_m3ml < measure_P.Constant_Value_bq) {
    measure_B.Switch2_hhsca5 = measure_P.Constant_Value_po;
  } else if (measure_B.SFunction_m3ml > measure_P.Constant_Value_kf) {
    measure_B.Switch2_hhsca5 = measure_P.Constant3_Value_adh;
  } else {
    measure_B.Switch2_hhsca5 = measure_B.SFunction_m3ml;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_g[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_kq;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dm;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_h;
      VDD_out++;
    }

    measure_B.VariableDiscret_i = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_h)
      *VDD_in = 0;
  }

  rtb_LogicalOperator_ot = (rtb_Compare_oafgue &&
    (!measure_DWork.delay_DSTATE_cir));
  if (rtb_LogicalOperator_ot) {
    measure_B.Switch_dmo = measure_P.double_Value_d1r;
  } else {
    measure_B.Switch_dmo = (measure_B.Switch6 +
      measure_DWork.UnitDelay4_DSTATE_iv) + measure_DWork.UnitDelay2_DSTATE_l1a;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ak;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dmo;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_hk;
      VDD_out++;
    }

    measure_B.VariableDiscret_id = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_hk)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_ab4s3qlk5[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_oci4cw4vl;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch6;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_h;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_h)
      *VDD_in = 0;
  }

  rtb_Divide_ny = ((real_T)measure_B.Switch2_hhsca5) - rtb_Gain_m;
  rtb_Switch = rtb_Divide_ny * rtb_Divide_ny;
  rtb_MathFunction1 = (measure_P.Gain1_Gain_adhz * rtb_Divide_ny) - rtb_Switch;
  rtb_Switch1_k = (1.0 / rtb_Switch_l40f02) * measure_P.Gain_Gain_adhzk50;
  if (rtb_Compare_go) {
    rtb_Divide_ny = rtb_Switch4;
  } else {
    if (rtb_Compare_oafgue) {
      rtb_Gain_m = measure_B.Switch_dm - measure_B.VariableDiscret_i;
    } else {
      rtb_Gain_m = measure_B.Switch_dmo - measure_B.VariableDiscret_id;
    }

    rtb_Divide_ny = (rtb_Gain_m - ((measure_B.VariableDiscreteDelay_imqptqte5 *
      rtb_MathFunction1) + (measure_B.VariableDiscreteDela_izcmu0mrbj *
      rtb_Switch))) * rtb_Switch1_k;
  }

  rtb_Bias = rtb_MathFunction2 + measure_P.Bias_Bias_bc;
  if (rtb_Compare_k1g) {
    rtb_Switch1_d = measure_DWork.UnitDelay1_DSTATE_c;
  } else {
    rtb_Switch1_d = measure_P.const_Value_n;
  }

  rtb_Compare_go = (rtb_Switch1_d == measure_P.Constant_Value_e1g);
  rtb_UnitDelay_j = measure_DWork.UnitDelay_DSTATE_h;
  rtb_Compare_k1g = (measure_DWork.UnitDelay_DSTATE_h <
                     measure_P.Constant_Value_i);
  if (rtb_Compare_k1g) {
    rtb_Switch1_ce = measure_DWork.UnitDelay1_DSTATE_n;
  } else {
    rtb_Switch1_ce = measure_P.const_Value_ci1;
  }

  rtb_Compare_k1 = (rtb_Switch1_ce == measure_P.Constant_Value_ci);
  if (rtb_Compare_k1g) {
    rtb_UnitDelay1_k = measure_P.const_Value_ci;
  } else {
    rtb_UnitDelay1_k = measure_DWork.UnitDelay1_DSTATE_nr;
  }

  rtb_Compare_k1g = (rtb_UnitDelay1_k == measure_P.Constant_Value_ci1);
  rtb_LogicalOperator2_c1 = (((measure_DWork.UnitDelay_DSTATE_b) ||
    rtb_Compare_k1) && (!rtb_Compare_k1g));
  rtb_LogicalOperator1_f = (rtb_Compare_go && rtb_LogicalOperator2_c1);

  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfunctio_j[0];
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_h;
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_a;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = *xD;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfuncti_ic + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfuncti_ic;
    measure_B.SF_FixedDiscreteDelaySfunctio_i = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfuncti_ic)
      *VDD_in = 0;
  }

  rtb_Compare_eb = (measure_B.SF_FixedDiscreteDelaySfunctio_i >
                    measure_P.Constant_Value_fc);
  rtb_Switch_l40f02 = ((rtb_MathFunction2 - measure_DWork.UnitDelay1_DSTATE_m) *
                       measure_P.Gain_Gain_bl) * measure_P.Gain2_Gain_b;
  if (rtb_Switch_l40f02 < measure_P.Constant_Value_bln4d) {
    rtb_Switch_l40f02 = -rtb_Switch_l40f02;
  }

  if (rtb_Compare_eb && (rtb_Switch_l40f02 > measure_P.Constant_Value_bln4dj)) {
    rtb_Switch_jv = measure_P.int32_Value_g;
  } else {
    rtb_Switch_jv = measure_DWork.UnitDelay_DSTATE_j -
      measure_P.FixPtConstant_Value_g;
  }

  rtb_Compare_cz = (rtb_Switch_jv > measure_P.Constant_Value_gq);
  rtb_Switch_l40f02 = ((rtb_MathFunction2_c - measure_DWork.UnitDelay1_DSTATE_g)
                       * measure_P.Gain_Gain_ez) * measure_P.Gain2_Gain_e;
  if (rtb_Switch_l40f02 < measure_P.Constant_Value_ezncl) {
    rtb_Switch_l40f02 = -rtb_Switch_l40f02;
  }

  if (rtb_Compare_eb && (rtb_Switch_l40f02 > measure_P.Constant_Value_eznclc)) {
    rtb_Switch_jvw = measure_P.int32_Value_gq;
  } else {
    rtb_Switch_jvw = measure_DWork.UnitDelay_DSTATE_jq -
      measure_P.FixPtConstant_Value_gq;
  }

  rtb_Compare_czp = (rtb_Switch_jvw > measure_P.Constant_Value_gqo);
  rtb_Switch_l40f02 = ((rtb_MathFunction2_a - measure_DWork.UnitDelay1_DSTATE_o)
                       * measure_P.Gain_Gain_e0) * measure_P.Gain2_Gain_e0;
  if (rtb_Switch_l40f02 < measure_P.Constant_Value_e0r1h) {
    rtb_Switch_l40f02 = -rtb_Switch_l40f02;
  }

  if (rtb_Compare_eb && (rtb_Switch_l40f02 > measure_P.Constant_Value_e0r1hm)) {
    rtb_Switch_jvwj = measure_P.int32_Value_gqo;
  } else {
    rtb_Switch_jvwj = measure_DWork.UnitDelay_DSTATE_jqs -
      measure_P.FixPtConstant_Value_gqo;
  }

  rtb_Compare_czp1 = (rtb_Switch_jvwj > measure_P.Constant_Value_gqop);
  rtb_Disturbance_All_Phases = ((rtb_Compare_cz && rtb_Compare_czp) &&
    rtb_Compare_czp1);
  if (rtb_Compare_aun) {
    rtb_Switch1_cc = measure_DWork.UnitDelay1_DSTATE_cf;
  } else {
    rtb_Switch1_cc = measure_P.const_Value_o5;
  }

  rtb_Compare_eb = (rtb_Switch1_cc == measure_P.Constant_Value_oh);
  rtb_UnitDelay_n = measure_DWork.UnitDelay_DSTATE_g;
  rtb_Compare_aun = (measure_DWork.UnitDelay_DSTATE_g <
                     measure_P.Constant_Value_g1);
  if (rtb_Compare_aun) {
    rtb_Switch1_ky = measure_DWork.UnitDelay1_DSTATE_e;
  } else {
    rtb_Switch1_ky = measure_P.const_Value_hg0;
  }

  rtb_Compare_au = (rtb_Switch1_ky == measure_P.Constant_Value_hg);
  if (rtb_Compare_aun) {
    rtb_Switch1_kyp = measure_P.const_Value_hg;
  } else {
    rtb_Switch1_kyp = measure_DWork.UnitDelay1_DSTATE_ep;
  }

  rtb_Compare_aun = (rtb_Switch1_kyp == measure_P.Constant_Value_hg0);
  rtb_LogicalOperator2_bf = (((measure_DWork.UnitDelay_DSTATE_md) ||
    rtb_Compare_au) && (!rtb_Compare_aun));
  rtb_LogicalOperator2_b0 = (rtb_Compare_eb && rtb_LogicalOperator2_bf);
  if (rtb_Compare_o1) {
    rtb_Switch1_oi = measure_DWork.UnitDelay1_DSTATE_or;
  } else {
    rtb_Switch1_oi = measure_P.const_Value_d;
  }

  rtb_Compare_o1 = (rtb_Switch1_oi == measure_P.Constant_Value_oyw);
  rtb_UnitDelay_ic = measure_DWork.UnitDelay_DSTATE_d;
  rtb_Compare_ge = (measure_DWork.UnitDelay_DSTATE_d <
                    measure_P.Constant_Value_eza);
  if (rtb_Compare_ge) {
    rtb_Switch1_cg = measure_DWork.UnitDelay1_DSTATE_ir;
  } else {
    rtb_Switch1_cg = measure_P.const_Value_gu;
  }

  rtb_Compare_g = (rtb_Switch1_cg == measure_P.Constant_Value_gu);
  if (rtb_Compare_ge) {
    rtb_Switch1_cgb = measure_P.const_Value_g;
  } else {
    rtb_Switch1_cgb = measure_DWork.UnitDelay1_DSTATE_irs;
  }

  rtb_Compare_ge = (rtb_Switch1_cgb == measure_P.Constant_Value_gun);
  rtb_LogicalOperator2_bg = (((measure_DWork.UnitDelay_DSTATE_cn) ||
    rtb_Compare_g) && (!rtb_Compare_ge));
  rtb_LogicalOperator2_m = (rtb_Compare_o1 && rtb_LogicalOperator2_bg);
  rtb_LogicalOperator12 = ((rtb_LogicalOperator1_f || rtb_LogicalOperator2_b0) ||
    rtb_LogicalOperator2_m);
  if (rtb_LogicalOperator12) {
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

  if (rtb_Switch6_idx) {
    rtb_Gain_m = rtb_Bias * rtb_Bias;
    if (rtb_Gain_m < measure_P.Constant_Value_ookglyimv) {
      if (rtb_Gain_m < measure_P.Constant_Value_ookglyim) {
        rtb_Switch_l40f02 = measure_P.Constant_Value_ookglyi;
      } else {
        rtb_Switch_l40f02 = rtb_Gain_m;
      }
    } else {
      if (rtb_Gain_m < measure_P.Constant_Value_ookgly) {
        rtb_Gain_m = measure_P.Constant_Value_ookgl;
      }

      rtb_Switch_l40f02 = 1.0 / rtb_Gain_m;
    }
  } else {
    rtb_Switch_l40f02 = measure_P.Constant2_Value;
  }

  rtb_Product_i = rtb_Divide_ny * rtb_Switch_l40f02;
  rtb_LogicalOperator1_bbcu = (rtb_Compare_mp || (!(rtb_Compare_df ||
    rtb_LogicalOperator9)));
  rtb_Gain_m = measure_DWork.UnitDelay3_DSTATE_pz;
  if (rtb_Compare_bq) {
    measure_B.Switch_dh3io = measure_P.double_Value_eznclc5xg5;
  } else {
    measure_B.Switch_dh3io = (measure_B.Divide_ny +
      measure_DWork.UnitDelay4_DSTATE_e10ck) +
      measure_DWork.UnitDelay2_DSTATE_abju3r;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_bgs;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3io;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_eznclc;
      VDD_out++;
    }

    measure_B.VariableDiscret_op = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_eznclc)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_dh3ioo = measure_P.double_Value_eznclc5xg5q;
  } else {
    measure_B.Switch_dh3ioo = (measure_B.Divide_ny +
      measure_DWork.UnitDelay4_DSTATE_e10ck0) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c1[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_cv;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioo;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_eznclc5;
      VDD_out++;
    }

    measure_B.VariableDiscret_g = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_eznclc5)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Divide_ny = measure_B.Switch_dh3io - measure_B.VariableDiscret_op;
  } else {
    rtb_Divide_ny = measure_B.Switch_dh3ioo - measure_B.VariableDiscret_g;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_ab4s3qlk5c[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_oci4cw4vlo;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_ny;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_eznc;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_eznc)
      *VDD_in = 0;
  }

  rtb_Divide_ny = (rtb_Divide_ny - ((measure_B.VariableDiscreteDela_imqptqte5f *
    rtb_Gain1_kh) + (measure_B.VariableDiscreteDel_izcmu0mrbjz * rtb_Unbalance)))
    * rtb_MinMax1;
  if (rtb_Compare_bq) {
    measure_B.Switch_dh3ioos = measure_P.double_Value_eznclc5x;
  } else {
    measure_B.Switch_dh3ioos = (measure_B.Divide_n +
      measure_DWork.UnitDelay4_DSTATE_e10ck0c) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gf[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_j3;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioos;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_eznclc5x;
      VDD_out++;
    }

    measure_B.VariableDiscret_d = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_eznclc5x)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_dh3ioosv = measure_P.double_Value_eznclc5xg;
  } else {
    measure_B.Switch_dh3ioosv = (measure_B.Divide_n +
      measure_DWork.UnitDelay4_DSTATE_e10ck0ct) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3x;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_p[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_fr;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioosv;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_eznclc5xg;
      VDD_out++;
    }

    measure_B.VariableDiscret_k = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_eznclc5xg)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Divide_n = measure_B.Switch_dh3ioos - measure_B.VariableDiscret_d;
  } else {
    rtb_Divide_n = measure_B.Switch_dh3ioosv - measure_B.VariableDiscret_k;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_ab4s3qlk5cc[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_oci4cw4vloz;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_n;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_eznclc5xg5;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_eznclc5xg5)
      *VDD_in = 0;
  }

  rtb_Divide_n = (rtb_Divide_n - ((measure_B.VariableDiscreteDel_imqptqte5f3 *
    rtb_Gain1_kh) + (measure_B.VariableDiscreteDe_izcmu0mrbjza * rtb_Unbalance)))
    * rtb_MinMax1;
  rtb_TrigonometricFunction_c = rt_atan2d_snf(rtb_Divide_ny, rtb_Divide_n);
  rtb_Add_o = rtb_TrigonometricFunction_c + rtb_Sum;
  if (rtb_LogicalOperator1_bbcu) {
    measure_B.Switch6_n = rtb_Switch4;
  } else {
    rtb_Gain_m = rtb_Add_o - rtb_Gain_m;
    if (rtb_Gain_m < measure_P.Constant_Value_coy) {
      rtb_Gain_m += measure_P.Bias1_Bias_co;
    } else {
      if (rtb_Gain_m > measure_P.Constant_Value_co) {
        rtb_Gain_m += measure_P.Bias_Bias_co;
      }
    }

    rtb_Gain_m *= measure_P.Gain_Gain_c;
    if (rtb_Gain_m < measure_P.Constant_Value_kp) {
      measure_B.Switch6_n = measure_P.Constant_Value_kg;
    } else if (rtb_Gain_m > measure_P.Constant_Value_kh) {
      measure_B.Switch6_n = measure_P.Constant1_Value_mw;
    } else {
      measure_B.Switch6_n = rtb_Gain_m;
    }
  }

  if (rtb_Compare_k5) {
    measure_B.Switch_iu = measure_P.double_Value_fj;
  } else {
    measure_B.Switch_iu = (measure_B.Switch6_n +
      measure_DWork.UnitDelay4_DSTATE_b) + measure_DWork.UnitDelay2_DSTATE_k;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_cr[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ny;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_iu;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_h0;
      VDD_out++;
    }

    measure_B.VariableDiscret_j = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_h0)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_ot) {
    measure_B.Switch_iua = measure_P.double_Value_fjq;
  } else {
    measure_B.Switch_iua = (measure_B.Switch6_n +
      measure_DWork.UnitDelay4_DSTATE_bc) + measure_DWork.UnitDelay2_DSTATE_k1;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_e[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_gs3;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_iua;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_h0u;
      VDD_out++;
    }

    measure_B.VariableDiscret_f = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_h0u)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_ab4s3qlk5cc4[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_oci4cw4vloz5;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch6_n;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_p;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_p)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator1_bbcu) {
    rtb_Divide_jw = rtb_Switch4;
  } else {
    if (rtb_Compare_oafgue) {
      rtb_Gain_m = measure_B.Switch_iu - measure_B.VariableDiscret_j;
    } else {
      rtb_Gain_m = measure_B.Switch_iua - measure_B.VariableDiscret_f;
    }

    rtb_Divide_jw = (rtb_Gain_m - ((measure_B.VariableDiscreteDe_imqptqte5f3c *
      rtb_MathFunction1) + (measure_B.VariableDiscreteD_izcmu0mrbjzal *
      rtb_Switch))) * rtb_Switch1_k;
  }

  rtb_Bias1 = rtb_MathFunction2_c + measure_P.Bias1_Bias_dv;
  if (rtb_LogicalOperator2_b0) {
    rtb_Gain_m = rtb_Bias1 * rtb_Bias1;
    if (rtb_Gain_m < measure_P.Constant_Value_ookglyimven12a) {
      if (rtb_Gain_m < measure_P.Constant_Value_ookglyimven12) {
        rtb_Switch_l40f = measure_P.Constant_Value_ookglyimven1;
      } else {
        rtb_Switch_l40f = rtb_Gain_m;
      }
    } else {
      if (rtb_Gain_m < measure_P.Constant_Value_ookglyimven) {
        rtb_Gain_m = measure_P.Constant_Value_ookglyimve;
      }

      rtb_Switch_l40f = 1.0 / rtb_Gain_m;
    }
  } else {
    rtb_Switch_l40f = measure_P.Constant2_Value_o;
  }

  rtb_Switch1_kt5c = rtb_Divide_jw * rtb_Switch_l40f;
  rtb_Compare_mp = (rtb_Compare_mp || (!(rtb_Compare_m3 || rtb_LogicalOperator9)));
  rtb_Gain_m = measure_DWork.UnitDelay3_DSTATE_o;
  if (rtb_Compare_bq) {
    measure_B.Switch_p0ny3 = measure_P.double_Value_e0r1hmwtwq;
  } else {
    measure_B.Switch_p0ny3 = (measure_B.Divide_jw +
      measure_DWork.UnitDelay4_DSTATE_otwsj) +
      measure_DWork.UnitDelay2_DSTATE_gllvy;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_b[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_lz;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_e0r1hm;
      VDD_out++;
    }

    measure_B.VariableDiscret_k3 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_e0r1hm)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_p0ny3p = measure_P.double_Value_e0r1hmwtwqc;
  } else {
    measure_B.Switch_p0ny3p = (measure_B.Divide_jw +
      measure_DWork.UnitDelay4_DSTATE_otwsjg) +
      measure_DWork.UnitDelay2_DSTATE_gllvyy;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_n[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_jl;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3p;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_e0r1hmw;
      VDD_out++;
    }

    measure_B.VariableDiscret_e = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_e0r1hmw)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Divide_jw = measure_B.Switch_p0ny3 - measure_B.VariableDiscret_k3;
  } else {
    rtb_Divide_jw = measure_B.Switch_p0ny3p - measure_B.VariableDiscret_e;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_ab4s3qlk5cc4j[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_oci4cw4vloz5b;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_jw;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_e0r1;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_e0r1)
      *VDD_in = 0;
  }

  rtb_Divide_jw = (rtb_Divide_jw - ((measure_B.VariableDiscreteD_imqptqte5f3cu *
    rtb_Gain1_kh) + (measure_B.VariableDiscrete_izcmu0mrbjzali * rtb_Unbalance)))
    * rtb_MinMax1;
  if (rtb_Compare_bq) {
    measure_B.Switch_p0ny3pk = measure_P.double_Value_e0r1hmwt;
  } else {
    measure_B.Switch_p0ny3pk = (measure_B.Divide_j +
      measure_DWork.UnitDelay4_DSTATE_otwsjge) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gp[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ev;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pk;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_e0r1hmwt;
      VDD_out++;
    }

    measure_B.VariableDiscret_fz = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_e0r1hmwt)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_p0ny3pkq = measure_P.double_Value_e0r1hmwtw;
  } else {
    measure_B.Switch_p0ny3pkq = (measure_B.Divide_j +
      measure_DWork.UnitDelay4_DSTATE_otwsjget) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya5;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_i[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_edt;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pkq;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_e0r1hmwtw;
      VDD_out++;
    }

    measure_B.VariableDiscret_fv = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_e0r1hmwtw)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Divide_j = measure_B.Switch_p0ny3pk - measure_B.VariableDiscret_fz;
  } else {
    rtb_Divide_j = measure_B.Switch_p0ny3pkq - measure_B.VariableDiscret_fv;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_ab4s3qlk5cc4jf[0];
    int_T *VDD_in = &measure_DWork.VariableDiscrete_oci4cw4vloz5bs;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_j;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_e0r1hmwtwq;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_e0r1hmwtwq)
      *VDD_in = 0;
  }

  rtb_Divide_j = (rtb_Divide_j - ((measure_B.VariableDiscrete_imqptqte5f3cur *
    rtb_Gain1_kh) + (measure_B.VariableDiscret_izcmu0mrbjzalib * rtb_Unbalance)))
    * rtb_MinMax1;
  rtb_TrigonometricFunction_b = rt_atan2d_snf(rtb_Divide_jw, rtb_Divide_j);
  rtb_Add_h = rtb_TrigonometricFunction_b + rtb_Sum;
  if (rtb_Compare_mp) {
    measure_B.Switch6_a = rtb_Switch4;
  } else {
    rtb_Gain_m = rtb_Add_h - rtb_Gain_m;
    if (rtb_Gain_m < measure_P.Constant_Value_fgl) {
      rtb_Gain_m += measure_P.Bias1_Bias_f;
    } else {
      if (rtb_Gain_m > measure_P.Constant_Value_fg) {
        rtb_Gain_m += measure_P.Bias_Bias_f;
      }
    }

    rtb_Gain_m *= measure_P.Gain_Gain_f;
    if (rtb_Gain_m < measure_P.Constant_Value_nv) {
      measure_B.Switch6_a = measure_P.Constant_Value_a4;
    } else if (rtb_Gain_m > measure_P.Constant_Value_j) {
      measure_B.Switch6_a = measure_P.Constant1_Value_ob;
    } else {
      measure_B.Switch6_a = rtb_Gain_m;
    }
  }

  if (rtb_Compare_k5) {
    measure_B.Switch_ja = measure_P.double_Value_g0;
  } else {
    measure_B.Switch_ja = (measure_B.Switch6_a +
      measure_DWork.UnitDelay4_DSTATE_kw) + measure_DWork.UnitDelay2_DSTATE_o;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_jh;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ja;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_m;
      VDD_out++;
    }

    measure_B.VariableDiscret_a = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_m)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_ot) {
    measure_B.Switch_jag = measure_P.double_Value_g0w;
  } else {
    measure_B.Switch_jag = (measure_B.Switch6_a +
      measure_DWork.UnitDelay4_DSTATE_kwr) + measure_DWork.UnitDelay2_DSTATE_o2;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_mm[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_bm;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jag;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_mo;
      VDD_out++;
    }

    measure_B.VariableDiscret_f1 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_mo)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ab4s3qlk5cc4jfr[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_oci4cw4vloz5bse;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch6_a;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca5;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_en;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_en)
      *VDD_in = 0;
  }

  if (!rtb_Compare_mp) {
    if (rtb_Compare_oafgue) {
      rtb_Gain_m = measure_B.Switch_ja - measure_B.VariableDiscret_a;
    } else {
      rtb_Gain_m = measure_B.Switch_jag - measure_B.VariableDiscret_f1;
    }

    rtb_Switch4 = (rtb_Gain_m - ((measure_B.VariableDiscret_imqptqte5f3curu *
      rtb_MathFunction1) + (measure_B.VariableDiscret_h * rtb_Switch))) *
      rtb_Switch1_k;
  }

  rtb_Bias2 = rtb_MathFunction2_a + measure_P.Bias2_Bias;
  if (rtb_LogicalOperator1_f) {
    rtb_Gain_m = rtb_Bias2 * rtb_Bias2;
    if (rtb_Gain_m < measure_P.Constant_Value_k1) {
      if (rtb_Gain_m < measure_P.Constant_Value_b4) {
        rtb_Switch_l4 = measure_P.Constant_Value_oa;
      } else {
        rtb_Switch_l4 = rtb_Gain_m;
      }
    } else {
      if (rtb_Gain_m < measure_P.Constant_Value_md) {
        rtb_Gain_m = measure_P.Constant_Value_ookglyimven12av;
      }

      rtb_Switch_l4 = 1.0 / rtb_Gain_m;
    }
  } else {
    rtb_Switch_l4 = measure_P.Constant2_Value_oo;
  }

  rtb_Switch_l40f02 += rtb_Switch_l40f;
  rtb_Switch_l40f02 += rtb_Switch_l4;
  if (rtb_Switch_l40f02 < measure_P.Constant_Value_dz) {
    rtb_Switch_l40f02 = measure_P.Constant_Value_oo;
  }

  rtb_Gain_m = ((rtb_Product_i + rtb_Switch1_kt5c) + (rtb_Switch4 *
    rtb_Switch_l4)) / rtb_Switch_l40f02;
  if (rtb_Gain_m < measure_P.Constant_Value_oj) {
    measure_B.Switch_l = measure_P.Constant_Value_ookg;
  } else if (rtb_Gain_m > measure_P.Constant_Value_ook) {
    measure_B.Switch_l = measure_P.Constant1_Value_o;
  } else {
    measure_B.Switch_l = rtb_Gain_m;
  }

  rtb_Switch_l4 = ((((real_T)measure_DWork.clockTickCounter_ed) <
                    measure_P.PulseGenerator1_Duty_d) &&
                   (measure_DWork.clockTickCounter_ed >= 0)) ?
    measure_P.PulseGenerator1_Amp_d : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_ed) >=
      (measure_P.PulseGenerator1_Period_d - 1.0)) {
    measure_DWork.clockTickCounter_ed = 0;
  } else {
    measure_DWork.clockTickCounter_ed = measure_DWork.clockTickCounter_ed + 1;
  }

  rtb_Switch6_idx = (rtb_Switch_l4 > measure_P.Constant_Value_da);
  rtb_LogicalOperator1_bbcu = ((!rtb_Switch6_idx) &&
    (measure_DWork.delay1_DSTATE_g));
  if (rtb_LogicalOperator1_bbcu) {
    measure_B.Switch_il = measure_P.double_Value_ii;
  } else {
    measure_B.Switch_il = (measure_B.Switch_l +
      measure_DWork.UnitDelay4_DSTATE_c) + measure_DWork.UnitDelay2_DSTATE_d;
  }

  if (measure_DWork.UnitDelay2_DSTATE_aj < measure_P.Constant_Value_cjwa) {
    rtb_Switch_l4 = measure_P.Constant_Value_cjw;
  } else if (measure_DWork.UnitDelay2_DSTATE_aj > measure_P.Constant_Value_cj) {
    rtb_Switch_l4 = measure_P.Constant1_Value_c;
  } else {
    rtb_Switch_l4 = measure_DWork.UnitDelay2_DSTATE_aj;
  }

  rtb_Gain_m = measure_P.Gain_Gain_p * rtb_Switch_l4;
  if (0.0 != 0.0) {
    measure_B.Switch2_f = rtb_Gain_m + measure_P.Bias1_Bias_p;
  } else if (rtb_Gain_m < measure_P.Constant_Value_pf) {
    measure_B.Switch2_f = rtb_Gain_m;
  } else {
    measure_B.Switch2_f = rtb_Gain_m + measure_P.Bias_Bias_p;
  }

  {
    measure_B.SFunction_n = (int)measure_B.Switch2_f;
  }

  if (measure_B.SFunction_n < measure_P.Constant_Value_pfgws) {
    measure_B.Switch2_f4 = measure_P.Constant_Value_pfgw;
  } else if (measure_B.SFunction_n > measure_P.Constant_Value_pfg) {
    measure_B.Switch2_f4 = measure_P.Constant3_Value_p;
  } else {
    measure_B.Switch2_f4 = measure_B.SFunction_n;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_p[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOneT_c;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_il;
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_i;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_d = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_i)
      *VDD_in = 0;
  }

  rtb_LogicalOperator_ot = (rtb_Switch6_idx && (!measure_DWork.delay_DSTATE_h));
  if (rtb_LogicalOperator_ot) {
    measure_B.Switch_iln = measure_P.double_Value_ii1;
  } else {
    measure_B.Switch_iln = (measure_B.Switch_l +
      measure_DWork.UnitDelay4_DSTATE_cv) + measure_DWork.UnitDelay2_DSTATE_dg;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_pb[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_cj;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_iln;
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_ii;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_dr = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_ii)
      *VDD_in = 0;
  }

  if (rtb_Switch6_idx) {
    rtb_Switch_l40f = measure_B.Switch_il -
      measure_B.VariableDiscreteDelaywithOneT_d;
  } else {
    rtb_Switch_l40f = measure_B.Switch_iln -
      measure_B.VariableDiscreteDelaywithOne_dr;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_g[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_os;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch_l;
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_i;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_i)
      *VDD_in = 0;
  }

  rtb_Switch_l40f02 = ((real_T)measure_B.Switch2_f4) - rtb_Gain_m;
  rtb_Switch4 = rtb_Switch_l40f02 * rtb_Switch_l40f02;
  rtb_Switch_l40f02 = (measure_P.Gain1_Gain_p * rtb_Switch_l40f02) - rtb_Switch4;
  rtb_Switch_l4 = (1.0 / rtb_Switch_l4) * measure_P.Gain_Gain_am;
  rtb_Switch_l40f = (rtb_Switch_l40f -
                     ((measure_B.VariableDiscreteDelaywithTwoT_o *
                       rtb_Switch_l40f02) +
                      (measure_B.VariableDiscreteDelaywithTwo_i4 * rtb_Switch4)))
    * rtb_Switch_l4;
  measure_B.ACripple1stestimate_f = measure_B.Switch_l - rtb_Switch_l40f;
  if (measure_B.ACripple1stestimate_f < measure_P.Constant_Value_kz) {
    rtb_IpktoIrmsconversion = -measure_B.ACripple1stestimate_f;
  } else {
    rtb_IpktoIrmsconversion = measure_B.ACripple1stestimate_f;
  }

  if (rtb_IpktoIrmsconversion > (measure_P.Gain_Gain_l *
       measure_P.Constant2_Value_h)) {
    rtb_Switch_oh = measure_P.int32_Value_n;
  } else {
    rtb_Switch_oh = measure_DWork.UnitDelay_DSTATE_m -
      measure_P.FixPtConstant_Value_n;
  }

  rtb_Compare_k5 = (rtb_Switch_oh > measure_P.Constant_Value_nl);
  if (rtb_Compare_k5) {
    rtb_Switch_l40f = measure_B.Switch_l;
  }

  if (!(((rtb_Switch1_c < (rtb_Switch_l40f - measure_P.Constant6_Value)) ||
         (rtb_Switch1_c > (rtb_Switch_l40f + measure_P.Constant6_Value))) &&
        rtb_LogicalOperator16)) {
    rtb_UnitDelay1_n0 = measure_P.const_Value_oz;
  }

  rtb_Compare_mp = (rtb_UnitDelay1_n0 == measure_P.Constant_Value_na);
  if (rtb_Compare_mp) {
    rtb_Bias_hsr = measure_P.int32_Value_c;
  } else {
    rtb_Bias_hsr = measure_DWork.UnitDelay_DSTATE_hs -
      measure_P.FixPtConstant_Value_cm;
  }

  rtb_Compare_n = (rtb_Bias_hsr > measure_P.Constant_Value_cmk);
  rtb_LogicalOperator2_f = (rtb_Compare_mp || ((!((!rtb_LogicalOperator16) || ((
    !rtb_Compare_n) && (measure_DWork.delay1_DSTATE_no)))) &&
    (measure_DWork.UnitDelay1_DSTATE_p)));
  rtb_LogicalOperator2_fd = ((measure_P.Constant1_Value_p) &&
    (rtb_LogicalOperator2_f || ((rtb_LogicalOperator16 && (((rtb_Switch_l40f <
    measure_P.Constant_Value_i5) || (!rtb_LogicalOperator12)) || rtb_Compare_k5))
    || (measure_P.Constant_Value_py))));
  if (rtb_LogicalOperator2_fd) {
    measure_B.Switch_m = rtb_Switch1_c;
  } else {
    measure_B.Switch_m = rtb_Switch_l40f;
  }

  if (rtb_UnitDelay4_hd) {
    rtb_Switch_c = rtb_Switch1;
  } else {
    rtb_Switch_c = measure_B.Switch_m;
  }

  if (measure_P.Constant6_Value_n) {
    rtb_LogicalOperator1_f = rtb_LogicalOperator2_fd;
  } else {
    rtb_LogicalOperator1_f = measure_P.Constant5_Value_d;
  }

  if ((rtb_LogicalOperator12 || rtb_UnitDelay4_hd) || rtb_LogicalOperator1_f) {
    measure_Y.Frequency = rtb_Switch_c;
  } else {
    measure_Y.Frequency = measure_P.Constant1_Value_j;
  }

  rtb_IpktoIrmsconversion = measure_P.Gain3_Gain * measure_P.Constant1_Value_m2;
  rtb_Switch_l40f = (rtb_Divide_h * rtb_Divide_h) + (rtb_Divide_h3 *
    rtb_Divide_h3);
  rtb_Gain_m = (rtb_Switch_l40f < 0.0) ? (-std::sqrt(std::abs(rtb_Switch_l40f)))
    : std::sqrt(rtb_Switch_l40f);
  rtb_Switch_l40f = rtb_IpktoIrmsconversion * rtb_Gain_m;
  rtb_AbsVI = (rtb_Divide_n * rtb_Divide_n) + (rtb_Divide_ny * rtb_Divide_ny);
  rtb_Switch1_kt5c = (rtb_AbsVI < 0.0) ? (-std::sqrt(std::abs(rtb_AbsVI))) : std::
    sqrt(rtb_AbsVI);
  rtb_AbsVI = rtb_IpktoIrmsconversion * rtb_Switch1_kt5c;
  rtb_AbsVI_e = (rtb_Divide_j * rtb_Divide_j) + (rtb_Divide_jw * rtb_Divide_jw);
  rtb_Switch = (rtb_AbsVI_e < 0.0) ? (-std::sqrt(std::abs(rtb_AbsVI_e))) : std::
    sqrt(rtb_AbsVI_e);
  rtb_AbsVI_e = rtb_IpktoIrmsconversion * rtb_Switch;
  rtb_IpktoIrms_a *= measure_P.ScaleRMSoutputsto1pu_Gain;
  measure_B.MathFunction = rtb_IpktoIrms_a * rtb_IpktoIrms_a;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_ixhvnqluia = measure_P.double_Value_bln4djb4gs54;
  } else {
    measure_B.Switch_ixhvnqluia = (measure_B.MathFunction +
      measure_DWork.UnitDelay4_DSTATE_js0g0xcka) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5ta;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_i3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_bq;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqluia;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_bln4djb4g;
      VDD_out++;
    }

    measure_B.VariableDiscret_el = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_bln4djb4g)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_ixhvnqluiaa = measure_P.double_Value_bln4djb4gs54q;
  } else {
    measure_B.Switch_ixhvnqluiaa = (measure_B.MathFunction +
      measure_DWork.UnitDelay4_DSTATE_js0g0xckaa) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5tay;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_fqs;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqluiaa;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_bln4djb4gs;
      VDD_out++;
    }

    measure_B.VariableDiscret_g3 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_bln4djb4gs)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_IpktoIrms_a = measure_B.Switch_ixhvnqluia - measure_B.VariableDiscret_el;
  } else {
    rtb_IpktoIrms_a = measure_B.Switch_ixhvnqluiaa -
      measure_B.VariableDiscret_g3;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gg[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_mu;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_bln4djb4gs5;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_bln4djb4gs5)
      *VDD_in = 0;
  }

  rtb_IpktoIrms_a = (rtb_IpktoIrms_a - ((measure_B.VariableDiscret_jk *
    rtb_Subtract3_c0) + (measure_B.VariableDiscret_n * rtb_MathFunction_ed1))) *
    rtb_Divide_ja;
  measure_B.MathFunction1 = (rtb_IpktoIrms_a < 0.0) ? (-std::sqrt(std::abs
    (rtb_IpktoIrms_a))) : std::sqrt(rtb_IpktoIrms_a);
  if (rtb_Compare_bq) {
    measure_B.Switch_ixhvnqluiaai = measure_P.double_Value_bl;
  } else {
    measure_B.Switch_ixhvnqluiaai = (measure_B.MathFunction1 +
      measure_DWork.UnitDelay4_DSTATE_js0g0xckaam) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5tayt;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ex[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_mr;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqluiaai;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_bln4djb4gs54;
      VDD_out++;
    }

    measure_B.VariableDiscret_j2 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_bln4djb4gs54)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_ixhvnqluiaai5 = measure_P.double_Value_bln;
  } else {
    measure_B.Switch_ixhvnqluiaai5 = (measure_B.MathFunction1 +
      measure_DWork.UnitDelay4_DSTATE_js0g0xckaamb) +
      measure_DWork.UnitDelay2_DSTATE_ljfwklf5taytr;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_aj[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_eb;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixhvnqluiaai5;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_bln4djb4gs54q;
      VDD_out++;
    }

    measure_B.VariableDiscret_l = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_bln4djb4gs54q)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_IpktoIrms_a = measure_B.Switch_ixhvnqluiaai -
      measure_B.VariableDiscret_j2;
  } else {
    rtb_IpktoIrms_a = measure_B.Switch_ixhvnqluiaai5 -
      measure_B.VariableDiscret_l;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_aq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_oe;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_bln4djb4gs54qg;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_bln4djb4gs54qg)
      *VDD_in = 0;
  }

  rtb_IpktoIrms_a = (rtb_IpktoIrms_a - ((measure_B.VariableDiscret_hk *
    rtb_Gain1_kh) + (measure_B.VariableDiscret_js * rtb_Unbalance))) *
    rtb_MinMax1;
  rtb_IpktoIrms_a = (rtb_IpktoIrms_a * rtb_IpktoIrms_a) - (rtb_Gain_m *
    rtb_Gain_m);
  if (rtb_IpktoIrms_a < measure_P.Constant_Value_bln4djb) {
    rtb_IpktoIrms_a = measure_P.Constant_Value_bl;
  }

  if (rtb_Gain_m < measure_P.Constant_Value_bln4djb4) {
    rtb_VpuIpktoVrmsIrms_re = measure_P.Constant_Value_bln;
  } else {
    rtb_VpuIpktoVrmsIrms_re = rtb_Gain_m;
  }

  rtb_UnaryMinus_dv = (((rtb_IpktoIrms_a < 0.0) ? (-std::sqrt(std::abs
    (rtb_IpktoIrms_a))) : std::sqrt(rtb_IpktoIrms_a)) / rtb_VpuIpktoVrmsIrms_re)
    * measure_P.Gain_Gain_bln;
  if (rtb_UnaryMinus_dv > measure_P.Constant_Value_bln4djb4g) {
    rtb_UnaryMinus_dv = measure_P.Constant_Value_bln4;
  }

  rtb_Divide_jahfx *= measure_P.ScaleRMSoutputsto1pu_Gain_e;
  measure_B.MathFunction_c = rtb_Divide_jahfx * rtb_Divide_jahfx;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_dh3ioosv2 = measure_P.double_Value_eznclc5xg5q1;
  } else {
    measure_B.Switch_dh3ioosv2 = (measure_B.MathFunction_c +
      measure_DWork.UnitDelay4_DSTATE_e10ck0cti) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3xa;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_no[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ib;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioosv2;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_eznclc5xg5q;
      VDD_out++;
    }

    measure_B.VariableDiscret_fo = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_eznclc5xg5q)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_dh3ioosv2k = measure_P.double_Value_eznclc5xg5q1u;
  } else {
    measure_B.Switch_dh3ioosv2k = (measure_B.MathFunction_c +
      measure_DWork.UnitDelay4_DSTATE_e10ck0ctir) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3xak;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f5[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pz;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioosv2k;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_eznclc5xg5q1;
      VDD_out++;
    }

    measure_B.VariableDiscret_ew = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_eznclc5xg5q1)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_IpktoIrms_a = measure_B.Switch_dh3ioosv2 - measure_B.VariableDiscret_fo;
  } else {
    rtb_IpktoIrms_a = measure_B.Switch_dh3ioosv2k - measure_B.VariableDiscret_ew;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ef[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pei;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_c;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_eznclc5xg5q1u;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_eznclc5xg5q1u)
      *VDD_in = 0;
  }

  rtb_IpktoIrms_a = (rtb_IpktoIrms_a - ((measure_B.VariableDiscret_jg *
    rtb_Subtract3_c0) + (measure_B.VariableDiscret_p * rtb_MathFunction_ed1))) *
    rtb_Divide_ja;
  measure_B.MathFunction1_p = (rtb_IpktoIrms_a < 0.0) ? (-std::sqrt(std::abs
    (rtb_IpktoIrms_a))) : std::sqrt(rtb_IpktoIrms_a);
  if (rtb_Compare_bq) {
    measure_B.Switch_dh3ioosv2km = measure_P.double_Value_ez;
  } else {
    measure_B.Switch_dh3ioosv2km = (measure_B.MathFunction1_p +
      measure_DWork.UnitDelay4_DSTATE_e10ck0ctirr) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ed[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_fy;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioosv2km;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_eznclc5xg5q1ug;
      VDD_out++;
    }

    measure_B.VariableDiscret_m = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_eznclc5xg5q1ug)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_dh3ioosv2kma = measure_P.double_Value_ezn;
  } else {
    measure_B.Switch_dh3ioosv2kma = (measure_B.MathFunction1_p +
      measure_DWork.UnitDelay4_DSTATE_e10ck0ctirrv) +
      measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku5;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a0[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ej;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_dh3ioosv2kma;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_eznclc5xg5q1ugj;
      VDD_out++;
    }

    measure_B.VariableDiscret_b = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_eznclc5xg5q1ugj)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_IpktoIrms_a = measure_B.Switch_dh3ioosv2km - measure_B.VariableDiscret_m;
  } else {
    rtb_IpktoIrms_a = measure_B.Switch_dh3ioosv2kma -
      measure_B.VariableDiscret_b;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pk[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_nc;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_p;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_k;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_k)
      *VDD_in = 0;
  }

  rtb_IpktoIrms_a = (rtb_IpktoIrms_a - ((measure_B.VariableDiscret_al *
    rtb_Gain1_kh) + (measure_B.VariableDiscret_ki * rtb_Unbalance))) *
    rtb_MinMax1;
  rtb_IpktoIrms_a = (rtb_IpktoIrms_a * rtb_IpktoIrms_a) - (rtb_Switch1_kt5c *
    rtb_Switch1_kt5c);
  if (rtb_IpktoIrms_a < measure_P.Constant_Value_eznclc5) {
    rtb_IpktoIrms_a = measure_P.Constant_Value_ez;
  }

  if (rtb_Switch1_kt5c < measure_P.Constant_Value_eznclc5x) {
    rtb_VpuIpktoVrmsIrms_re = measure_P.Constant_Value_ezn;
  } else {
    rtb_VpuIpktoVrmsIrms_re = rtb_Switch1_kt5c;
  }

  rtb_IpktoIrms_a = (((rtb_IpktoIrms_a < 0.0) ? (-std::sqrt(std::abs
    (rtb_IpktoIrms_a))) : std::sqrt(rtb_IpktoIrms_a)) / rtb_VpuIpktoVrmsIrms_re)
    * measure_P.Gain_Gain_ezn;
  if (rtb_IpktoIrms_a > measure_P.Constant_Value_eznclc5xg) {
    rtb_IpktoIrms_a = measure_P.Constant_Value_eznc;
  }

  rtb_Switch_b *= measure_P.ScaleRMSoutputsto1pu_Gain_e0;
  measure_B.MathFunction_l = rtb_Switch_b * rtb_Switch_b;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_p0ny3pkqp = measure_P.double_Value_e0r1hmwtwqc2;
  } else {
    measure_B.Switch_p0ny3pkqp = (measure_B.MathFunction_l +
      measure_DWork.UnitDelay4_DSTATE_otwsjgetk) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya5a;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_dk[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_hf;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pkqp;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_e0r1hmwtwqc;
      VDD_out++;
    }

    measure_B.VariableDiscret_la = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_e0r1hmwtwqc)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_p0ny3pkqpe = measure_P.double_Value_e0r1hmwtwqc2e;
  } else {
    measure_B.Switch_p0ny3pkqpe = (measure_B.MathFunction_l +
      measure_DWork.UnitDelay4_DSTATE_otwsjgetko) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya5ah;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_o[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_a2;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pkqpe;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_e0r1hmwtwqc2;
      VDD_out++;
    }

    measure_B.VariableDiscret_hy = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_e0r1hmwtwqc2)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Switch_b = measure_B.Switch_p0ny3pkqp - measure_B.VariableDiscret_la;
  } else {
    rtb_Switch_b = measure_B.Switch_p0ny3pkqpe - measure_B.VariableDiscret_hy;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gs[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pl;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_l;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_e0r1hmwtwqc2e;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_e0r1hmwtwqc2e)
      *VDD_in = 0;
  }

  rtb_Switch_b = (rtb_Switch_b - ((measure_B.VariableDiscret_pk *
    rtb_Subtract3_c0) + (measure_B.VariableDiscret_p5 * rtb_MathFunction_ed1))) *
    rtb_Divide_ja;
  measure_B.MathFunction1_m = (rtb_Switch_b < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_b))) : std::sqrt(rtb_Switch_b);
  if (rtb_Compare_bq) {
    measure_B.Switch_p0ny3pkqpey = measure_P.double_Value_e0;
  } else {
    measure_B.Switch_p0ny3pkqpey = (measure_B.MathFunction1_m +
      measure_DWork.UnitDelay4_DSTATE_otwsjgetkod) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_bt[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_av;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pkqpey;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_e0r1hmwtwqc2ev;
      VDD_out++;
    }

    measure_B.VariableDiscret_ef = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_e0r1hmwtwqc2ev)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_p0ny3pkqpeyo = measure_P.double_Value_e0r;
  } else {
    measure_B.Switch_p0ny3pkqpeyo = (measure_B.MathFunction1_m +
      measure_DWork.UnitDelay4_DSTATE_otwsjgetkod3) +
      measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0l;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_e0[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_dg;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p0ny3pkqpeyo;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_e0r1hmwtwqc2evm;
      VDD_out++;
    }

    measure_B.VariableDiscret_ai = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_e0r1hmwtwqc2evm)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Switch_b = measure_B.Switch_p0ny3pkqpey - measure_B.VariableDiscret_ef;
  } else {
    rtb_Switch_b = measure_B.Switch_p0ny3pkqpeyo - measure_B.VariableDiscret_ai;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_l[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_lwr;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_m;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_kl;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_kl)
      *VDD_in = 0;
  }

  rtb_Switch_b = (rtb_Switch_b - ((measure_B.VariableDiscret_b5 * rtb_Gain1_kh)
    + (measure_B.VariableDiscret_jn * rtb_Unbalance))) * rtb_MinMax1;
  rtb_Switch_b = (rtb_Switch_b * rtb_Switch_b) - (rtb_Switch * rtb_Switch);
  if (rtb_Switch_b < measure_P.Constant_Value_e0r1hmw) {
    rtb_Switch_b = measure_P.Constant_Value_e0;
  }

  if (rtb_Switch < measure_P.Constant_Value_e0r1hmwt) {
    rtb_VpuIpktoVrmsIrms_re = measure_P.Constant_Value_e0r;
  } else {
    rtb_VpuIpktoVrmsIrms_re = rtb_Switch;
  }

  rtb_Switch_b = (((rtb_Switch_b < 0.0) ? (-std::sqrt(std::abs(rtb_Switch_b))) :
                   std::sqrt(rtb_Switch_b)) / rtb_VpuIpktoVrmsIrms_re) *
    measure_P.Gain_Gain_e0r;
  if (rtb_Switch_b > measure_P.Constant_Value_e0r1hmwtw) {
    rtb_Switch_b = measure_P.Constant_Value_e0r1;
  }

  rtb_VpuIpktoVrmsIrms_re = ((((measure_P.Gain5_Gain[0].re * rtb_Divide_h) -
    (measure_P.Gain5_Gain[0].im * rtb_Divide_h3)) + ((measure_P.Gain5_Gain[1].re
    * rtb_Divide_n) - (measure_P.Gain5_Gain[1].im * rtb_Divide_ny))) +
    ((measure_P.Gain5_Gain[2].re * rtb_Divide_j) - (measure_P.Gain5_Gain[2].im *
    rtb_Divide_jw))) * measure_P.Gain6_Gain;
  rtb_Switch1_c = ((((measure_P.Gain5_Gain[0].re * rtb_Divide_h3) +
                     (measure_P.Gain5_Gain[0].im * rtb_Divide_h)) +
                    ((measure_P.Gain5_Gain[1].re * rtb_Divide_ny) +
                     (measure_P.Gain5_Gain[1].im * rtb_Divide_n))) +
                   ((measure_P.Gain5_Gain[2].re * rtb_Divide_jw) +
                    (measure_P.Gain5_Gain[2].im * rtb_Divide_j))) *
    measure_P.Gain6_Gain;
  rtb_Divide_jahf = (rtb_VpuIpktoVrmsIrms_re * rtb_VpuIpktoVrmsIrms_re) +
    (rtb_Switch1_c * rtb_Switch1_c);
  rtb_MathFunction1 = (rtb_Divide_jahf < 0.0) ? (-std::sqrt(std::abs
    (rtb_Divide_jahf))) : std::sqrt(rtb_Divide_jahf);
  rtb_VpuIpktoVrmsIrms_re = ((((measure_P.Gain2_Gain_o[0].re * rtb_Divide_h) -
    (measure_P.Gain2_Gain_o[0].im * rtb_Divide_h3)) + ((measure_P.Gain2_Gain_o[1]
    .re * rtb_Divide_n) - (measure_P.Gain2_Gain_o[1].im * rtb_Divide_ny))) +
    ((measure_P.Gain2_Gain_o[2].re * rtb_Divide_j) - (measure_P.Gain2_Gain_o[2].
    im * rtb_Divide_jw))) * measure_P.Gain4_Gain;
  rtb_Switch1_c = ((((measure_P.Gain2_Gain_o[0].re * rtb_Divide_h3) +
                     (measure_P.Gain2_Gain_o[0].im * rtb_Divide_h)) +
                    ((measure_P.Gain2_Gain_o[1].re * rtb_Divide_ny) +
                     (measure_P.Gain2_Gain_o[1].im * rtb_Divide_n))) +
                   ((measure_P.Gain2_Gain_o[2].re * rtb_Divide_jw) +
                    (measure_P.Gain2_Gain_o[2].im * rtb_Divide_j))) *
    measure_P.Gain4_Gain;
  rtb_Switch_b2 = (rtb_VpuIpktoVrmsIrms_re * rtb_VpuIpktoVrmsIrms_re) +
    (rtb_Switch1_c * rtb_Switch1_c);
  rtb_Switch_b2 = (rtb_Switch_b2 < 0.0) ? (-std::sqrt(std::abs(rtb_Switch_b2))) :
    std::sqrt(rtb_Switch_b2);
  rtb_Divide_jahf = fmax(fmax(rtb_Gain_m, rtb_Switch1_kt5c), rtb_Switch);
  if (!((rtb_Divide_jahf - fmin(fmin(rtb_Gain_m, rtb_Switch1_kt5c), rtb_Switch))
        >= (measure_P.Gain_Gain_cg * rtb_Divide_jahf))) {
    rtb_Divide_jahf = ((rtb_Gain_m + rtb_Switch1_kt5c) + rtb_Switch) *
      measure_P.Gain1_Gain;
  }

  measure_Y.Voltage[0] = rtb_Switch_l40f;
  measure_Y.Voltage[1] = rtb_AbsVI;
  measure_Y.Voltage[2] = rtb_AbsVI_e;
  measure_Y.Voltage[3] = rtb_TrigonometricFunction_l;
  measure_Y.Voltage[4] = rtb_TrigonometricFunction_c;
  measure_Y.Voltage[5] = rtb_TrigonometricFunction_b;
  measure_Y.Voltage[6] = rtb_UnaryMinus_dv;
  measure_Y.Voltage[7] = rtb_IpktoIrms_a;
  measure_Y.Voltage[8] = rtb_Switch_b;
  if (rtb_Switch_b2 < measure_P.Constant_Value_jw) {
    rtb_Switch_b2 = measure_P.Constant_Value_b;
  }

  measure_Y.Voltage[9] = (rtb_MathFunction1 / rtb_Switch_b2) *
    measure_P.Gain3_Gain_i;
  measure_Y.Voltage[10] = rtb_Divide_jahf;
  rtb_UnitDelay1_l = measure_DWork.UnitDelay1_DSTATE_h;
  rtb_Switch_b2 = (measure_P.Gain_Gain_cep * rtb_Add1_h_idx) +
    measure_P.Bias_Bias_o;
  rtb_Switch_b2 = ((((measure_U.IabcAmps[0] - measure_DWork.UnitDelay2_DSTATE_gp)
                     * measure_P.Gain_Gain_d2) * rtb_Switch_b2) +
                   measure_DWork.UnitDelay1_DSTATE_h) +
    ((((measure_DWork.UnitDelay2_DSTATE_gp + measure_U.IabcAmps[0]) *
       measure_P.Gain1_Gain_b) - measure_DWork.UnitDelay1_DSTATE_h) *
     (rtb_Switch_b2 * rtb_Switch_b2));
  measure_B.Product_i[0] = (rtb_Switch_b2 * rtb_UnaryMinus_a2) * rtb_Divide_jah;
  measure_B.Product_i[1] = (rtb_Switch_b2 * rtb_Sum2_g) * rtb_Divide_jah;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_b = measure_P.double_Value_of;
  } else {
    measure_B.Switch_b = (measure_B.Product_i[0] +
                          measure_DWork.UnitDelay4_DSTATE_jn) +
      measure_DWork.UnitDelay2_DSTATE_n;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_h[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOneT_e;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_o;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_k = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_o)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_b2 = measure_P.double_Value_ofa;
  } else {
    measure_B.Switch_b2 = (measure_B.Product_i[0] +
      measure_DWork.UnitDelay4_DSTATE_jnq) + measure_DWork.UnitDelay2_DSTATE_np;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_hk[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_et;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_of;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_kn = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_of)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Divide_jahf = measure_B.Switch_b -
      measure_B.VariableDiscreteDelaywithOneT_k;
  } else {
    rtb_Divide_jahf = measure_B.Switch_b2 -
      measure_B.VariableDiscreteDelaywithOne_kn;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_h[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_p;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_i[0];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_o;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_o)
      *VDD_in = 0;
  }

  measure_B.Divide_ja = (rtb_Divide_jahf -
    ((measure_B.VariableDiscreteDelaywithTwoT_a * rtb_Subtract3_c0) +
     (measure_B.VariableDiscreteDelaywithTwoT_p * rtb_MathFunction_ed1))) *
    rtb_Divide_ja;
  if (rtb_Compare_bq) {
    measure_B.Switch_b2j = measure_P.double_Value_ofawrz;
  } else {
    measure_B.Switch_b2j = (measure_B.Divide_ja +
      measure_DWork.UnitDelay4_DSTATE_jnq1) +
      measure_DWork.UnitDelay2_DSTATE_npj;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_hkv[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_etx;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2j;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_ofa;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_kne = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_ofa)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_b2jb = measure_P.double_Value_ofawrzy;
  } else {
    measure_B.Switch_b2jb = (measure_B.Divide_ja +
      measure_DWork.UnitDelay4_DSTATE_jnq1h) +
      measure_DWork.UnitDelay2_DSTATE_npjj;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_hkvl[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_etx1;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jb;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_ofaw;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithO_knes = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_ofaw)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Divide_jahf = measure_B.Switch_b2j -
      measure_B.VariableDiscreteDelaywithOn_kne;
  } else {
    rtb_Divide_jahf = measure_B.Switch_b2jb -
      measure_B.VariableDiscreteDelaywithO_knes;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_hj[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_pv;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_ja;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_of;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_of)
      *VDD_in = 0;
  }

  rtb_Divide_jahf = (rtb_Divide_jahf -
                     ((measure_B.VariableDiscreteDelaywithTwo_a3 * rtb_Gain1_kh)
                      + (measure_B.VariableDiscreteDelaywithTwo_p2 *
    rtb_Unbalance))) * rtb_MinMax1;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_b2jbv = measure_P.double_Value_ofaw;
  } else {
    measure_B.Switch_b2jbv = (measure_B.Product_i[1] +
      measure_DWork.UnitDelay4_DSTATE_jnq1hm) +
      measure_DWork.UnitDelay2_DSTATE_npjj1;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_hkvl3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_etx1w;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_ofawr;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywith_knesb = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_ofawr)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_b2jbv3 = measure_P.double_Value_ofawr;
  } else {
    measure_B.Switch_b2jbv3 = (measure_B.Product_i[1] +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmy) +
      measure_DWork.UnitDelay2_DSTATE_npjj1p;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_hkvl35[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_etx1wx;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv3;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_ofawrz;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywit_knesbd = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_ofawrz)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_UnaryMinus_dv = measure_B.Switch_b2jbv -
      measure_B.VariableDiscreteDelaywith_knesb;
  } else {
    rtb_UnaryMinus_dv = measure_B.Switch_b2jbv3 -
      measure_B.VariableDiscreteDelaywit_knesbd;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_hjq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_pv2;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_i[1];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_ofa;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_ofa)
      *VDD_in = 0;
  }

  measure_B.Divide_jah = (rtb_UnaryMinus_dv -
    ((measure_B.VariableDiscreteDelaywithTw_a3z * rtb_Subtract3_c0) +
     (measure_B.VariableDiscreteDelaywithTw_p20 * rtb_MathFunction_ed1))) *
    rtb_Divide_ja;
  if (rtb_Compare_bq) {
    measure_B.Switch_b2jbv30 = measure_P.double_Value_ofawrzyw;
  } else {
    measure_B.Switch_b2jbv30 = (measure_B.Divide_jah +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyq) +
      measure_DWork.UnitDelay2_DSTATE_npjj1pt;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_hkvl35c[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_etx1wxm;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_ofawrzy;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywi_knesbdm = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_ofawrzy)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_b2jbv30z = measure_P.double_Value_ofawrzywp;
  } else {
    measure_B.Switch_b2jbv30z = (measure_B.Divide_jah +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyqy) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptk;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_hkvl35cs[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_etx1wxmc;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30z;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_ofawrzyw;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelayw_knesbdmu = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_ofawrzyw)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_UnaryMinus_dv = measure_B.Switch_b2jbv30 -
      measure_B.VariableDiscreteDelaywi_knesbdm;
  } else {
    rtb_UnaryMinus_dv = measure_B.Switch_b2jbv30z -
      measure_B.VariableDiscreteDelayw_knesbdmu;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_hjqf[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_pv2z;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_jah;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_ofaw;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_ofaw)
      *VDD_in = 0;
  }

  rtb_UnaryMinus_dv = (rtb_UnaryMinus_dv -
                       ((measure_B.VariableDiscreteDelaywithT_a3zz *
    rtb_Gain1_kh) + (measure_B.VariableDiscreteDelaywithT_p20b * rtb_Unbalance)))
    * rtb_MinMax1;
  rtb_IpktoIrms_a = (rtb_Divide_jahf * rtb_Divide_jahf) + (rtb_UnaryMinus_dv *
    rtb_UnaryMinus_dv);
  rtb_Switch1_kt5c = (rtb_IpktoIrms_a < 0.0) ? (-std::sqrt(std::abs
    (rtb_IpktoIrms_a))) : std::sqrt(rtb_IpktoIrms_a);
  rtb_IpktoIrms_a = measure_P.IpktoIrms_Gain * rtb_Switch1_kt5c;
  rtb_UnitDelay1_f = measure_DWork.UnitDelay1_DSTATE_ou;
  rtb_Switch_b = (measure_P.Gain_Gain_b4 * rtb_Add1_h_idx_0) +
    measure_P.Bias_Bias_m1;
  rtb_Switch_b = ((((measure_U.IabcAmps[1] - measure_DWork.UnitDelay2_DSTATE_f) *
                    measure_P.Gain_Gain_jf) * rtb_Switch_b) +
                  measure_DWork.UnitDelay1_DSTATE_ou) +
    ((((measure_DWork.UnitDelay2_DSTATE_f + measure_U.IabcAmps[1]) *
       measure_P.Gain1_Gain_l) - measure_DWork.UnitDelay1_DSTATE_ou) *
     (rtb_Switch_b * rtb_Switch_b));
  measure_B.Product_io[0] = (rtb_Switch_b * rtb_UnaryMinus_a2) * rtb_Divide_jah;
  measure_B.Product_io[1] = (rtb_Switch_b * rtb_Sum2_g) * rtb_Divide_jah;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_b2jbv30zm = measure_P.double_Value_ofawrzywpvfxm1;
  } else {
    measure_B.Switch_b2jbv30zm = (measure_B.Product_io[0] +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptkd;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_hkvl35css[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_etx1wxmcb;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zm;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_ofawrzywp;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelay_knesbdmu1 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_ofawrzywp)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_b2jbv30zmv = measure_P.double_Value_ofawrzywpvfxm1r;
  } else {
    measure_B.Switch_b2jbv30zmv = (measure_B.Product_io[0] +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptkda;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_hkvl35cssz[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_etx1wxmcbv;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmv;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_ofawrzywpv;
      VDD_out++;
    }

    measure_B.VariableDiscreteDela_knesbdmu1j = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_ofawrzywpv)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Divide_jahfx = measure_B.Switch_b2jbv30zm -
      measure_B.VariableDiscreteDelay_knesbdmu1;
  } else {
    rtb_Divide_jahfx = measure_B.Switch_b2jbv30zmv -
      measure_B.VariableDiscreteDela_knesbdmu1j;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_hjqfc[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_pv2zv;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_io[0];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_ofawrzywpvf;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_ofawrzywpvf)
      *VDD_in = 0;
  }

  measure_B.Divide_jahf = (rtb_Divide_jahfx -
    ((measure_B.VariableDiscreteDelaywith_a3zzb * rtb_Subtract3_c0) +
     (measure_B.VariableDiscreteDelaywith_p20bd * rtb_MathFunction_ed1))) *
    rtb_Divide_ja;
  if (rtb_Compare_bq) {
    measure_B.Switch_b2jbv30zmvu = measure_P.double_Value_h;
  } else {
    measure_B.Switch_b2jbv30zmvu = (measure_B.Divide_jahf +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1i) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_hkvl35cssz3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_etx1wxmcbvv;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmvu;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_ofawrzywpvfx;
      VDD_out++;
    }

    measure_B.VariableDiscreteDel_knesbdmu1jd = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_ofawrzywpvfx)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_b2jbv30zmvus = measure_P.double_Value_i;
  } else {
    measure_B.Switch_b2jbv30zmvus = (measure_B.Divide_jahf +
      measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1it) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_hkvl35cssz3u[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_etx1wxmcbvvw;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmvus;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_ofawrzywpvfxm;
      VDD_out++;
    }

    measure_B.VariableDiscreteDe_knesbdmu1jdz = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_ofawrzywpvfxm)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Divide_jahfx = measure_B.Switch_b2jbv30zmvu -
      measure_B.VariableDiscreteDel_knesbdmu1jd;
  } else {
    rtb_Divide_jahfx = measure_B.Switch_b2jbv30zmvus -
      measure_B.VariableDiscreteDe_knesbdmu1jdz;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_hjqfcq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_pv2zv2;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_jahf;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_ofawrzywpvfxm1;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_ofawrzywpvfxm1)
      *VDD_in = 0;
  }

  rtb_Divide_jahfx = (rtb_Divide_jahfx -
                      ((measure_B.VariableDiscreteDelaywit_a3zzbn * rtb_Gain1_kh)
                       + (measure_B.VariableDiscreteDelaywit_p20bdb *
    rtb_Unbalance))) * rtb_MinMax1;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_b2jbv30zmvusn = measure_P.double_Value_l;
  } else {
    measure_B.Switch_b2jbv30zmvusn = (measure_B.Product_io[1] +
      measure_DWork.UnitDelay4_DSTAT_jnq1hmyqya1it1) +
      measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2v;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_hkvl35cssz3uy[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_etx1wxmcbvvwx;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmvusn;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ofawrzywpvfxm1r;
      VDD_out++;
    }

    measure_B.VariableDiscreteD_knesbdmu1jdzx = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ofawrzywpvfxm1r)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_b2jbv30zmvusna = measure_P.double_Value_n;
  } else {
    measure_B.Switch_b2jbv30zmvusna = (measure_B.Product_io[1] +
      measure_DWork.UnitDelay4_DSTA_jnq1hmyqya1it1v) +
      measure_DWork.UnitDelay2_DSTAT_npjj1ptkdaf2v0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_hkvl35cssz3uyo[0];
    int_T *VDD_in = &measure_DWork.VariableDiscrete_etx1wxmcbvvwx0;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmvusna;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_l;
      VDD_out++;
    }

    measure_B.VariableDiscrete_knesbdmu1jdzx0 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_l)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_UnaryMinus_p = measure_B.Switch_b2jbv30zmvusn -
      measure_B.VariableDiscreteD_knesbdmu1jdzx;
  } else {
    rtb_UnaryMinus_p = measure_B.Switch_b2jbv30zmvusna -
      measure_B.VariableDiscrete_knesbdmu1jdzx0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_hjqfcqw[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_pv2zv24;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_io[1];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_h;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_h)
      *VDD_in = 0;
  }

  measure_B.Divide_jahfx = (rtb_UnaryMinus_p -
    ((measure_B.VariableDiscreteDelaywi_a3zzbnn * rtb_Subtract3_c0) +
     (measure_B.VariableDiscreteDelaywi_p20bdbu * rtb_MathFunction_ed1))) *
    rtb_Divide_ja;
  if (rtb_Compare_bq) {
    measure_B.Switch_b2jbv30zmvusnaw = measure_P.double_Value_k;
  } else {
    measure_B.Switch_b2jbv30zmvusnaw = (measure_B.Divide_jahfx +
      measure_DWork.UnitDelay4_DSTA_p) +
      measure_DWork.UnitDelay2_DSTA_npjj1ptkdaf2v0r;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_hkvl35cssz3uyos[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_etx1wxmcbvvwx03;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b2jbv30zmvusnaw;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_n;
      VDD_out++;
    }

    measure_B.VariableDiscret_knesbdmu1jdzx0j = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_n)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_n = measure_P.double_Value_a;
  } else {
    measure_B.Switch_n = (measure_B.Divide_jahfx +
                          measure_DWork.UnitDelay4_DSTA_o) +
      measure_DWork.UnitDelay2_DSTA_i;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a02[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ls;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_n;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_hy;
      VDD_out++;
    }

    measure_B.VariableDiscret_mc = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_hy)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_UnaryMinus_p = measure_B.Switch_b2jbv30zmvusnaw -
      measure_B.VariableDiscret_knesbdmu1jdzx0j;
  } else {
    rtb_UnaryMinus_p = measure_B.Switch_n - measure_B.VariableDiscret_mc;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_hjqfcqwr[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_pv2zv24n;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_jahfx;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_i;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_i)
      *VDD_in = 0;
  }

  rtb_UnaryMinus_p = (rtb_UnaryMinus_p -
                      ((measure_B.VariableDiscreteDelayw_a3zzbnny * rtb_Gain1_kh)
                       + (measure_B.VariableDiscreteDelayw_p20bdbus *
    rtb_Unbalance))) * rtb_MinMax1;
  rtb_Switch = (rtb_Divide_jahfx * rtb_Divide_jahfx) + (rtb_UnaryMinus_p *
    rtb_UnaryMinus_p);
  rtb_MathFunction1 = (rtb_Switch < 0.0) ? (-std::sqrt(std::abs(rtb_Switch))) :
    std::sqrt(rtb_Switch);
  rtb_Switch = measure_P.IpktoIrms_Gain_h * rtb_MathFunction1;
  rtb_UnitDelay1_lu = measure_DWork.UnitDelay1_DSTATE_bn;
  rtb_Switch1_k = (measure_P.Gain_Gain_jx * rtb_Add1_h_idx_1) +
    measure_P.Bias_Bias_oi;
  rtb_Switch1_k = ((((measure_U.IabcAmps[2] - measure_DWork.UnitDelay2_DSTATE_b)
                     * measure_P.Gain_Gain_o) * rtb_Switch1_k) +
                   measure_DWork.UnitDelay1_DSTATE_bn) +
    ((((measure_DWork.UnitDelay2_DSTATE_b + measure_U.IabcAmps[2]) *
       measure_P.Gain1_Gain_m) - measure_DWork.UnitDelay1_DSTATE_bn) *
     (rtb_Switch1_k * rtb_Switch1_k));
  measure_B.Product_io0[0] = (rtb_Switch1_k * rtb_UnaryMinus_a2) *
    rtb_Divide_jah;
  measure_B.Product_io0[1] = (rtb_Switch1_k * rtb_Sum2_g) * rtb_Divide_jah;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_lf = measure_P.double_Value_g;
  } else {
    measure_B.Switch_lf = (measure_B.Product_io0[0] +
      measure_DWork.UnitDelay4_DSTA_k) + measure_DWork.UnitDelay2_DSTA_g;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_iy[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_l3;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lf;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_iy;
      VDD_out++;
    }

    measure_B.VariableDiscret_pu = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_iy)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_jcx = measure_P.double_Value_fo;
  } else {
    measure_B.Switch_jcx = (measure_B.Product_io0[0] +
      measure_DWork.UnitDelay4_DSTA_c) + measure_DWork.UnitDelay2_DSTA_n;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ad[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_lb;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jcx;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ku;
      VDD_out++;
    }

    measure_B.VariableDiscret_mi = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ku)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Divide_jah = measure_B.Switch_lf - measure_B.VariableDiscret_pu;
  } else {
    rtb_Divide_jah = measure_B.Switch_jcx - measure_B.VariableDiscret_mi;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_hjqfcqwrz[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_pv2zv24nx;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_io0[0];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_kuf;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_kuf)
      *VDD_in = 0;
  }

  measure_B.Divide_jahfx5 = (rtb_Divide_jah -
    ((measure_B.VariableDiscreteDelay_a3zzbnnyv * rtb_Subtract3_c0) +
     (measure_B.VariableDiscreteDelay_p20bdbust * rtb_MathFunction_ed1))) *
    rtb_Divide_ja;
  if (rtb_Compare_bq) {
    measure_B.Switch_e = measure_P.double_Value_b;
  } else {
    measure_B.Switch_e = (measure_B.Divide_jahfx5 +
                          measure_DWork.UnitDelay4_DSTA_d) +
      measure_DWork.UnitDelay2_DSTA_k;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m1[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_a2h;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_e;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_a;
      VDD_out++;
    }

    measure_B.VariableDiscret_mt = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_a)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_bd = measure_P.double_Value_or;
  } else {
    measure_B.Switch_bd = (measure_B.Divide_jahfx5 +
      measure_DWork.UnitDelay4_DSTA_h) + measure_DWork.UnitDelay2_DSTA_p;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_g0[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_cm;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_bd;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_k3;
      VDD_out++;
    }

    measure_B.VariableDiscret_fv5 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_k3)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Divide_jah = measure_B.Switch_e - measure_B.VariableDiscret_mt;
  } else {
    rtb_Divide_jah = measure_B.Switch_bd - measure_B.VariableDiscret_fv5;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_hjqfcqwrzc[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_pv2zv24nxp;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_jahfx5;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_aa;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_aa)
      *VDD_in = 0;
  }

  rtb_Divide_jah = (rtb_Divide_jah - ((measure_B.VariableDiscreteDela_a3zzbnnyvg
    * rtb_Gain1_kh) + (measure_B.VariableDiscreteDela_p20bdbustl * rtb_Unbalance)))
    * rtb_MinMax1;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_c = measure_P.double_Value_hi;
  } else {
    measure_B.Switch_c = (measure_B.Product_io0[1] +
                          measure_DWork.UnitDelay4_DSTA_f) +
      measure_DWork.UnitDelay2_DSTA_ip;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_j[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pc;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_c;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_o;
      VDD_out++;
    }

    measure_B.VariableDiscret_lw = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_o)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_d5 = measure_P.double_Value_iw;
  } else {
    measure_B.Switch_d5 = (measure_B.Product_io0[1] +
      measure_DWork.UnitDelay4_DSTA_o2) + measure_DWork.UnitDelay2_DSTA_h;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ox[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_am;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_d5;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_d;
      VDD_out++;
    }

    measure_B.VariableDiscret_fc = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_d)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_UnaryMinus_a2 = measure_B.Switch_c - measure_B.VariableDiscret_lw;
  } else {
    rtb_UnaryMinus_a2 = measure_B.Switch_d5 - measure_B.VariableDiscret_fc;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_hjqfcqwrzc3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_pv2zv24nxpe;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_io0[1];
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_k35;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_k35)
      *VDD_in = 0;
  }

  measure_B.Divide_jahfx50 = (rtb_UnaryMinus_a2 -
    ((measure_B.VariableDiscreteDel_a3zzbnnyvg5 * rtb_Subtract3_c0) +
     (measure_B.VariableDiscreteDel_p20bdbustlf * rtb_MathFunction_ed1))) *
    rtb_Divide_ja;
  if (rtb_Compare_bq) {
    measure_B.Switch_ik = measure_P.double_Value_bv;
  } else {
    measure_B.Switch_ik = (measure_B.Divide_jahfx50 +
      measure_DWork.UnitDelay4_DSTA_cq) + measure_DWork.UnitDelay2_DSTA_pl;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m0[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_g05;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ik;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_f;
      VDD_out++;
    }

    measure_B.VariableDiscret_eg = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_f)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_nb = measure_P.double_Value_j;
  } else {
    measure_B.Switch_nb = (measure_B.Divide_jahfx50 +
      measure_DWork.UnitDelay4_DSTA_a) + measure_DWork.UnitDelay2_DSTA_c;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_fq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_f4;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nb;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_g;
      VDD_out++;
    }

    measure_B.VariableDiscret_d2 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_g)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_UnaryMinus_a2 = measure_B.Switch_ik - measure_B.VariableDiscret_eg;
  } else {
    rtb_UnaryMinus_a2 = measure_B.Switch_nb - measure_B.VariableDiscret_d2;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_hjqfcqwrzc31[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_pv2zv24nxpeb;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_jahfx50;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ow;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ow)
      *VDD_in = 0;
  }

  rtb_UnaryMinus_a2 = (rtb_UnaryMinus_a2 -
                       ((measure_B.VariableDiscreteDe_a3zzbnnyvg5z *
    rtb_Gain1_kh) + (measure_B.VariableDiscreteDe_p20bdbustlfs * rtb_Unbalance)))
    * rtb_MinMax1;
  rtb_Sum2_g = (rtb_Divide_jah * rtb_Divide_jah) + (rtb_UnaryMinus_a2 *
    rtb_UnaryMinus_a2);
  rtb_Add1_h_idx_0 = (rtb_Sum2_g < 0.0) ? (-std::sqrt(std::abs(rtb_Sum2_g))) :
    std::sqrt(rtb_Sum2_g);
  rtb_Sum2_g = measure_P.IpktoIrms_Gain_j * rtb_Add1_h_idx_0;
  rtb_Switch_b2 *= measure_P.ScaleRMSoutputsto1pu_Gain_o;
  measure_B.MathFunction_k = rtb_Switch_b2 * rtb_Switch_b2;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_o = measure_P.double_Value_ofawrzywpv;
  } else {
    measure_B.Switch_o = (measure_B.MathFunction_k +
                          measure_DWork.UnitDelay4_DSTA_n) +
      measure_DWork.UnitDelay2_DSTA_o;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ep[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_jx;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_o;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_fo;
      VDD_out++;
    }

    measure_B.VariableDiscret_fq = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_fo)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_oo = measure_P.double_Value_ofawrzywpvf;
  } else {
    measure_B.Switch_oo = (measure_B.MathFunction_k +
      measure_DWork.UnitDelay4_DSTA_i) + measure_DWork.UnitDelay2_DSTA_f;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_cp[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_kc;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_oo;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_hi;
      VDD_out++;
    }

    measure_B.VariableDiscret_eb = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_hi)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Switch_b2 = measure_B.Switch_o - measure_B.VariableDiscret_fq;
  } else {
    rtb_Switch_b2 = measure_B.Switch_oo - measure_B.VariableDiscret_eb;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_hjqfcqwrzc31p[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_pv2zv24nxpebh;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_k;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_db;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_db)
      *VDD_in = 0;
  }

  rtb_Switch_b2 = (rtb_Switch_b2 - ((measure_B.VariableDiscreteD_a3zzbnnyvg5zz *
    rtb_Subtract3_c0) + (measure_B.VariableDiscreteD_p20bdbustlfs4 *
    rtb_MathFunction_ed1))) * rtb_Divide_ja;
  measure_B.MathFunction1_g = (rtb_Switch_b2 < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_b2))) : std::sqrt(rtb_Switch_b2);
  if (rtb_Compare_bq) {
    measure_B.Switch_g = measure_P.double_Value;
  } else {
    measure_B.Switch_g = (measure_B.MathFunction1_g +
                          measure_DWork.UnitDelay4_DSTA_j) +
      measure_DWork.UnitDelay2_DSTA_j;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_h[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ld;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_g;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_iw;
      VDD_out++;
    }

    measure_B.VariableDiscret_je = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_iw)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_pp = measure_P.double_Value_o;
  } else {
    measure_B.Switch_pp = (measure_B.MathFunction1_g +
      measure_DWork.UnitDelay4_DSTA_jj) + measure_DWork.UnitDelay2_DSTA_ic;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c4[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_dd;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_pp;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_b;
      VDD_out++;
    }

    measure_B.VariableDiscret_pq = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_b)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Switch_b2 = measure_B.Switch_g - measure_B.VariableDiscret_je;
  } else {
    rtb_Switch_b2 = measure_B.Switch_pp - measure_B.VariableDiscret_pq;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_hjqfcqwrzc31p3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscrete_pv2zv24nxpebhu;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_g;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ff;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ff)
      *VDD_in = 0;
  }

  rtb_Switch_b2 = (rtb_Switch_b2 - ((measure_B.VariableDiscrete_a3zzbnnyvg5zz5 *
    rtb_Gain1_kh) + (measure_B.VariableDiscrete_p20bdbustlfs4u * rtb_Unbalance)))
    * rtb_MinMax1;
  rtb_Switch_b2 = (rtb_Switch_b2 * rtb_Switch_b2) - (rtb_Switch1_kt5c *
    rtb_Switch1_kt5c);
  if (rtb_Switch_b2 < measure_P.Constant_Value_ofawrzywpv) {
    rtb_Switch_b2 = measure_P.Constant_Value_o;
  }

  if (rtb_Switch1_kt5c < measure_P.Constant_Value_ofawrzywpvf) {
    rtb_VpuIpktoVrmsIrms_re = measure_P.Constant_Value_of;
  } else {
    rtb_VpuIpktoVrmsIrms_re = rtb_Switch1_kt5c;
  }

  rtb_Add1_h_idx_1 = (((rtb_Switch_b2 < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_b2))) : std::sqrt(rtb_Switch_b2)) / rtb_VpuIpktoVrmsIrms_re) *
    measure_P.Gain_Gain_of;
  if (rtb_Add1_h_idx_1 > measure_P.Constant_Value_ofawrzywpvfx) {
    rtb_Add1_h_idx_1 = measure_P.Constant_Value_ofa;
  }

  rtb_Switch_b *= measure_P.ScaleRMSoutputsto1pu_Gain_of;
  measure_B.MathFunction_k5 = rtb_Switch_b * rtb_Switch_b;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_cx = measure_P.double_Value_k3;
  } else {
    measure_B.Switch_cx = (measure_B.MathFunction_k5 +
      measure_DWork.UnitDelay4_DSTA_dk) + measure_DWork.UnitDelay2_DSTA_hv;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_jw[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_hx;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_cx;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_or;
      VDD_out++;
    }

    measure_B.VariableDiscret_on = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_or)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_ixo = measure_P.double_Value_ow;
  } else {
    measure_B.Switch_ixo = (measure_B.MathFunction_k5 +
      measure_DWork.UnitDelay4_DSTA_dx) + measure_DWork.UnitDelay2_DSTA_l;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_bg[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ok;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ixo;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_bv;
      VDD_out++;
    }

    measure_B.VariableDiscret_mb = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_bv)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Switch_b2 = measure_B.Switch_cx - measure_B.VariableDiscret_on;
  } else {
    rtb_Switch_b2 = measure_B.Switch_ixo - measure_B.VariableDiscret_mb;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_hjqfcqwrzc31p34[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pv2zv24nxpebhui;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_k5;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ga;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ga)
      *VDD_in = 0;
  }

  rtb_Switch_b2 = (rtb_Switch_b2 - ((measure_B.VariableDiscret_a3zzbnnyvg5zz54 *
    rtb_Subtract3_c0) + (measure_B.VariableDiscret_p20bdbustlfs4um *
    rtb_MathFunction_ed1))) * rtb_Divide_ja;
  measure_B.MathFunction1_ge = (rtb_Switch_b2 < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_b2))) : std::sqrt(rtb_Switch_b2);
  if (rtb_Compare_bq) {
    measure_B.Switch_ek = measure_P.double_Value_ofawrzywpvfx;
  } else {
    measure_B.Switch_ek = (measure_B.MathFunction1_ge +
      measure_DWork.UnitDelay4_DSTA_kd) + measure_DWork.UnitDelay2_DSTA_m;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_on[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_iv;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ek;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_j;
      VDD_out++;
    }

    measure_B.VariableDiscret_nz = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_j)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_j3 = measure_P.double_Value_ofawrzywpvfxm;
  } else {
    measure_B.Switch_j3 = (measure_B.MathFunction1_ge +
      measure_DWork.UnitDelay4_DSTA_dr) + measure_DWork.UnitDelay2_DSTA_lr;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_nr[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_gw;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_j3;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_c;
      VDD_out++;
    }

    measure_B.VariableDiscret_h5 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_c)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Switch_b2 = measure_B.Switch_ek - measure_B.VariableDiscret_nz;
  } else {
    rtb_Switch_b2 = measure_B.Switch_j3 - measure_B.VariableDiscret_h5;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_om[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ou;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_ge;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_foe;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_foe)
      *VDD_in = 0;
  }

  rtb_Switch_b2 = (rtb_Switch_b2 - ((measure_B.VariableDiscret_ho * rtb_Gain1_kh)
    + (measure_B.VariableDiscret_is * rtb_Unbalance))) * rtb_MinMax1;
  rtb_Switch_b2 = (rtb_Switch_b2 * rtb_Switch_b2) - (rtb_MathFunction1 *
    rtb_MathFunction1);
  if (rtb_Switch_b2 < measure_P.Constant_Value_ofawrzywpvfxm) {
    rtb_Switch_b2 = measure_P.Constant_Value_ofaw;
  }

  if (rtb_MathFunction1 < measure_P.Constant_Value_ofawrzywpvfxm1) {
    rtb_VpuIpktoVrmsIrms_re = measure_P.Constant_Value_ofawr;
  } else {
    rtb_VpuIpktoVrmsIrms_re = rtb_MathFunction1;
  }

  rtb_Switch_b2 = (((rtb_Switch_b2 < 0.0) ? (-std::sqrt(std::abs(rtb_Switch_b2)))
                    : std::sqrt(rtb_Switch_b2)) / rtb_VpuIpktoVrmsIrms_re) *
    measure_P.Gain_Gain_ofa;
  if (rtb_Switch_b2 > measure_P.Constant_Value_ofawrzywpvfxm1r) {
    rtb_Switch_b2 = measure_P.Constant_Value_ofawrz;
  }

  rtb_Switch1_k *= measure_P.ScaleRMSoutputsto1pu_Gain_ofa;
  measure_B.MathFunction_k5t = rtb_Switch1_k * rtb_Switch1_k;
  if (rtb_LogicalOperator1_b2ck) {
    measure_B.Switch_a = measure_P.double_Value_c;
  } else {
    measure_B.Switch_a = (measure_B.MathFunction_k5t +
                          measure_DWork.UnitDelay4_DSTA_ny) +
      measure_DWork.UnitDelay2_DSTA_oy;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pe[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_c2;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_a;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_p;
      VDD_out++;
    }

    measure_B.VariableDiscret_dl = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_p)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aj) {
    measure_B.Switch_d0 = measure_P.double_Value_p;
  } else {
    measure_B.Switch_d0 = (measure_B.MathFunction_k5t +
      measure_DWork.UnitDelay4_DSTA_k1) + measure_DWork.UnitDelay2_DSTA_a;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_k[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_au;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_d0;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_cu;
      VDD_out++;
    }

    measure_B.VariableDiscret_f2 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_cu)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Switch1_k = measure_B.Switch_a - measure_B.VariableDiscret_dl;
  } else {
    rtb_Switch1_k = measure_B.Switch_d0 - measure_B.VariableDiscret_f2;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_mf[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_l4;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_k5t;
    VDD_out = *VDD_in - measure_B.Switch2_hhsc;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_hin;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_hin)
      *VDD_in = 0;
  }

  rtb_Divide_ja *= rtb_Switch1_k - ((measure_B.VariableDiscret_gz *
    rtb_Subtract3_c0) + (measure_B.VariableDiscret_jb * rtb_MathFunction_ed1));
  measure_B.MathFunction1_ge3 = (rtb_Divide_ja < 0.0) ? (-std::sqrt(std::abs
    (rtb_Divide_ja))) : std::sqrt(rtb_Divide_ja);
  if (rtb_Compare_bq) {
    measure_B.Switch_h = measure_P.double_Value_d;
  } else {
    measure_B.Switch_h = (measure_B.MathFunction1_ge3 +
                          measure_DWork.UnitDelay4_DSTA_ip) +
      measure_DWork.UnitDelay2_DSTA_ay;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_p3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_l5;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_h;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_bq;
      VDD_out++;
    }

    measure_B.VariableDiscret_hx = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_bq)
      *VDD_in = 0;
  }

  if (rtb_Compare_cj) {
    measure_B.Switch_it = measure_P.double_Value_f;
  } else {
    measure_B.Switch_it = (measure_B.MathFunction1_ge3 +
      measure_DWork.UnitDelay4_DSTA_hx) + measure_DWork.UnitDelay2_DSTA_la;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_me[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_hd;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_it;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_f4;
      VDD_out++;
    }

    measure_B.VariableDiscret_my = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_f4)
      *VDD_in = 0;
  }

  if (rtb_Compare_oafguee) {
    rtb_Switch1_k = measure_B.Switch_h - measure_B.VariableDiscret_hx;
  } else {
    rtb_Switch1_k = measure_B.Switch_it - measure_B.VariableDiscret_my;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_onk[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_fe;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_ge3;
    VDD_out = *VDD_in - measure_B.Switch2_hhsca;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_iwf;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_iwf)
      *VDD_in = 0;
  }

  rtb_MinMax1 *= rtb_Switch1_k - ((measure_B.VariableDiscret_ed * rtb_Gain1_kh)
    + (measure_B.VariableDiscret_m2 * rtb_Unbalance));
  rtb_Switch1_k = (rtb_MinMax1 * rtb_MinMax1) - (rtb_Add1_h_idx_0 *
    rtb_Add1_h_idx_0);
  if (rtb_Switch1_k < measure_P.Constant_Value_jo) {
    rtb_Switch1_k = measure_P.Constant_Value_ofawrzy;
  }

  if (rtb_Add1_h_idx_0 < measure_P.Constant_Value_c5) {
    rtb_VpuIpktoVrmsIrms_re = measure_P.Constant_Value_ofawrzyw;
  } else {
    rtb_VpuIpktoVrmsIrms_re = rtb_Add1_h_idx_0;
  }

  rtb_Switch1_k = (((rtb_Switch1_k < 0.0) ? (-std::sqrt(std::abs(rtb_Switch1_k)))
                    : std::sqrt(rtb_Switch1_k)) / rtb_VpuIpktoVrmsIrms_re) *
    measure_P.Gain_Gain_ofaw;
  if (rtb_Switch1_k > measure_P.Constant_Value_ps) {
    rtb_Switch1_k = measure_P.Constant_Value_ofawrzywp;
  }

  rtb_VpuIpktoVrmsIrms_re = ((((measure_P.Gain5_Gain_d[0].re * rtb_Divide_jahf)
    - (measure_P.Gain5_Gain_d[0].im * rtb_UnaryMinus_dv)) +
    ((measure_P.Gain5_Gain_d[1].re * rtb_Divide_jahfx) -
     (measure_P.Gain5_Gain_d[1].im * rtb_UnaryMinus_p))) +
    ((measure_P.Gain5_Gain_d[2].re * rtb_Divide_jah) - (measure_P.Gain5_Gain_d[2]
    .im * rtb_UnaryMinus_a2))) * measure_P.Gain6_Gain_h;
  rtb_Add1_h_idx = ((((measure_P.Gain5_Gain_d[0].re * rtb_UnaryMinus_dv) +
                      (measure_P.Gain5_Gain_d[0].im * rtb_Divide_jahf)) +
                     ((measure_P.Gain5_Gain_d[1].re * rtb_UnaryMinus_p) +
                      (measure_P.Gain5_Gain_d[1].im * rtb_Divide_jahfx))) +
                    ((measure_P.Gain5_Gain_d[2].re * rtb_UnaryMinus_a2) +
                     (measure_P.Gain5_Gain_d[2].im * rtb_Divide_jah))) *
    measure_P.Gain6_Gain_h;
  rtb_Unbalance = (rtb_VpuIpktoVrmsIrms_re * rtb_VpuIpktoVrmsIrms_re) +
    (rtb_Add1_h_idx * rtb_Add1_h_idx);
  rtb_VpuIpktoVrmsIrms_re = ((((measure_P.Gain2_Gain_bc[0].re * rtb_Divide_jahf)
    - (measure_P.Gain2_Gain_bc[0].im * rtb_UnaryMinus_dv)) +
    ((measure_P.Gain2_Gain_bc[1].re * rtb_Divide_jahfx) -
     (measure_P.Gain2_Gain_bc[1].im * rtb_UnaryMinus_p))) +
    ((measure_P.Gain2_Gain_bc[2].re * rtb_Divide_jah) -
     (measure_P.Gain2_Gain_bc[2].im * rtb_UnaryMinus_a2))) *
    measure_P.Gain4_Gain_o;
  rtb_Switch1_c = ((((measure_P.Gain2_Gain_bc[0].re * rtb_UnaryMinus_dv) +
                     (measure_P.Gain2_Gain_bc[0].im * rtb_Divide_jahf)) +
                    ((measure_P.Gain2_Gain_bc[1].re * rtb_UnaryMinus_p) +
                     (measure_P.Gain2_Gain_bc[1].im * rtb_Divide_jahfx))) +
                   ((measure_P.Gain2_Gain_bc[2].re * rtb_UnaryMinus_a2) +
                    (measure_P.Gain2_Gain_bc[2].im * rtb_Divide_jah))) *
    measure_P.Gain4_Gain_o;
  rtb_Gain1_kh = (rtb_VpuIpktoVrmsIrms_re * rtb_VpuIpktoVrmsIrms_re) +
    (rtb_Switch1_c * rtb_Switch1_c);
  rtb_Gain_m = (rtb_Gain1_kh < 0.0) ? (-std::sqrt(std::abs(rtb_Gain1_kh))) : std::
    sqrt(rtb_Gain1_kh);
  rtb_Gain1_kh = fmax(fmax(rtb_Switch1_kt5c, rtb_MathFunction1),
                      rtb_Add1_h_idx_0);
  if (!((rtb_Gain1_kh - fmin(fmin(rtb_Switch1_kt5c, rtb_MathFunction1),
         rtb_Add1_h_idx_0)) >= (measure_P.Gain_Gain_g4 * rtb_Gain1_kh))) {
    rtb_Gain1_kh = ((rtb_Switch1_kt5c + rtb_MathFunction1) + rtb_Add1_h_idx_0) *
      measure_P.Gain1_Gain_d;
  }

  rtb_Gain1_kh *= measure_P.Gain1_Gain_br;
  measure_Y.Current[0] = rtb_IpktoIrms_a;
  measure_Y.Current[1] = rtb_Switch;
  measure_Y.Current[2] = rtb_Sum2_g;
  measure_Y.Current[3] = rt_atan2d_snf(rtb_UnaryMinus_dv, rtb_Divide_jahf);
  measure_Y.Current[4] = rt_atan2d_snf(rtb_UnaryMinus_p, rtb_Divide_jahfx);
  measure_Y.Current[5] = rt_atan2d_snf(rtb_UnaryMinus_a2, rtb_Divide_jah);
  measure_Y.Current[6] = rtb_Add1_h_idx_1;
  measure_Y.Current[7] = rtb_Switch_b2;
  measure_Y.Current[8] = rtb_Switch1_k;
  if (rtb_Gain_m < measure_P.Constant_Value_or) {
    rtb_Gain_m = measure_P.Constant_Value_bj;
  }

  measure_Y.Current[9] = (((rtb_Unbalance < 0.0) ? (-std::sqrt(std::abs
    (rtb_Unbalance))) : std::sqrt(rtb_Unbalance)) / rtb_Gain_m) *
    measure_P.Gain3_Gain_l;
  measure_Y.Current[10] = rtb_Gain1_kh;
  rtb_Switch_l40f *= rtb_IpktoIrms_a;
  rtb_AbsVI *= rtb_Switch;
  rtb_AbsVI_e *= rtb_Sum2_g;
  rtb_Switch_l40f += rtb_AbsVI;
  rtb_Switch_l40f += rtb_AbsVI_e;
  rtb_UnaryMinus_dv = -rtb_UnaryMinus_dv;
  rtb_Add1_h_idx_1 = ((rtb_Divide_h * rtb_Divide_jahf) - (rtb_Divide_h3 *
    rtb_UnaryMinus_dv)) * (measure_P.IpktoIrmsconversion_Gain *
    rtb_IpktoIrmsconversion);
  rtb_Divide_h = ((rtb_Divide_h * rtb_UnaryMinus_dv) + (rtb_Divide_h3 *
    rtb_Divide_jahf)) * (measure_P.IpktoIrmsconversion_Gain *
    rtb_IpktoIrmsconversion);
  rtb_UnaryMinus_p = -rtb_UnaryMinus_p;
  rtb_Gain_m = ((rtb_Divide_n * rtb_Divide_jahfx) - (rtb_Divide_ny *
    rtb_UnaryMinus_p)) * (measure_P.IpktoIrmsconversion_Gain_m *
    rtb_IpktoIrmsconversion);
  rtb_Switch1_kt5c = ((rtb_Divide_n * rtb_UnaryMinus_p) + (rtb_Divide_ny *
    rtb_Divide_jahfx)) * (measure_P.IpktoIrmsconversion_Gain_m *
    rtb_IpktoIrmsconversion);
  rtb_UnaryMinus_a2 = -rtb_UnaryMinus_a2;
  rtb_IpktoIrmsconversion *= measure_P.IpktoIrmsconversion_Gain_f;
  rtb_Add1_h_idx_1 += rtb_Gain_m;
  rtb_Add1_h_idx_1 += ((rtb_Divide_j * rtb_Divide_jah) - (rtb_Divide_jw *
    rtb_UnaryMinus_a2)) * rtb_IpktoIrmsconversion;
  rtb_Divide_h += rtb_Switch1_kt5c;
  rtb_Divide_h += ((rtb_Divide_j * rtb_UnaryMinus_a2) + (rtb_Divide_jw *
    rtb_Divide_jah)) * rtb_IpktoIrmsconversion;
  if (rtb_Switch_l40f < measure_P.Constant_Value_e4) {
    rtb_VpuIpktoVrmsIrms_re = measure_P.Constant_Value;
  } else {
    rtb_VpuIpktoVrmsIrms_re = rtb_Switch_l40f;
  }

  rtb_Gain_m = rtb_Add1_h_idx_1 / rtb_VpuIpktoVrmsIrms_re;
  if (rtb_Gain_m < measure_P.Constant_Value_ck) {
    rtb_Gain_m = measure_P.Constant_Value_p;
  } else {
    if (rtb_Gain_m > measure_P.Constant_Value_e) {
      rtb_Gain_m = measure_P.Constant1_Value;
    }
  }

  measure_Y.Power[0] = rtb_Switch_l40f;
  measure_Y.Power[1] = rtb_Add1_h_idx_1;
  measure_Y.Power[2] = rtb_Divide_h;
  measure_Y.Power[3] = rtb_Gain_m;
  if (rtb_Compare_c2os) {
    rtb_Switch1_c1 = measure_P.int2_Value;
  }

  rtb_FixPtSum1 = rtb_Switch1_c1 - measure_P.FixPtConstant_Value_f;
  if (rtb_Compare_c2o) {
    rtb_UnitDelay1_pf = measure_P.int2_Value_f;
  }

  rtb_FixPtSum1_j = rtb_UnitDelay1_pf - measure_P.FixPtConstant_Value_fk;
  if (rtb_Compare_c2) {
    rtb_Switch1_bxh = measure_P.int2_Value_fk;
  }

  rtb_FixPtSum1_ja = rtb_Switch1_bxh - measure_P.FixPtConstant_Value_fkx;
  if (rtb_Compare_c2) {
    rtb_Switch1_c1 = measure_DWork.UnitDelay1_DSTATE_omtd1hdputh;
  } else {
    rtb_Switch1_c1 = measure_P.const_Value_h;
  }

  rtb_LogicalOperator_aj = (rtb_Switch1_c1 == measure_P.Constant_Value_hnl);
  rtb_Compare_c2o = (rtb_LogicalOperator_aj && ((rtb_Compare_cz ||
    rtb_Compare_czp) || rtb_Compare_czp1));
  rtb_LogicalOperator1_f = (rtb_Compare_c2o && (!measure_DWork.delay_DSTATE_e));
  rtb_Gain_m = measure_P.Gain_Gain_ci * measure_P.Constant4_Value_g;
  if (0.0 != 0.0) {
    measure_B.Switch2_k = rtb_Gain_m + measure_P.Bias1_Bias;
  } else {
    measure_B.Switch2_k = rtb_Gain_m + measure_P.Bias_Bias;
  }

  {
    measure_B.SFunction_o = (unsigned int)measure_B.Switch2_k;
  }

  if (rtb_UnitDelay4_ej) {
    rtb_UnitDelay1_pf = measure_B.SFunction_o + measure_P.FixPtConstant_Value_c;
  } else {
    rtb_UnitDelay1_pf = measure_DWork.UnitDelay_DSTATE_im -
      measure_P.FixPtConstant_Value;
  }

  rtb_Compare_cj = (rtb_UnitDelay1_pf > measure_P.Constant_Value_civ);
  if (rtb_Compare_cj) {
    rtb_Switch1_bx = rtb_UnitDelay1_pf;
  } else {
    rtb_Switch1_bx = measure_P.int1_Value;
  }

  rtb_LogicalOperator2_m = ((measure_DWork.UnitDelay_DSTATE_imt) ||
    ((!rtb_Compare_cj) && rtb_LogicalOperator1_f));
  rtb_UnitDelay1_pf = measure_DWork.UnitDelay1_DSTATE_omtd1hdputhx;
  rtb_LogicalOperator1_f = (rtb_UnitDelay4_ej &&
    (measure_DWork.UnitDelay_DSTATE_imt2));
  rtb_Gain_m = measure_P.Gain_Gain_civ * measure_P.Constant3_Value;
  if (0.0 != 0.0) {
    measure_B.Switch2_k0 = rtb_Gain_m + measure_P.Bias1_Bias_c;
  } else {
    measure_B.Switch2_k0 = rtb_Gain_m + measure_P.Bias_Bias_c;
  }

  {
    measure_B.SFunction_os = (unsigned int)measure_B.Switch2_k0;
  }

  if (!rtb_LogicalOperator1_f) {
    rtb_UnitDelay1_pf = measure_B.SFunction_os +
      measure_P.FixPtConstant_Value_ci;
  }

  rtb_Compare_cj = (rtb_UnitDelay1_pf == measure_P.Constant_Value_civ2);
  if (rtb_UnitDelay4_ej && ((rtb_RelationalOperator_c &&
        rtb_RelationalOperator_i) && rtb_RelationalOperator_h)) {
    rtb_Switch1_bxh = measure_DWork.UnitDelay1_DSTATE_omtd1hdputhxn;
  } else {
    rtb_Switch1_bxh = measure_P.const_Value_c;
  }

  rtb_Compare_bq = (rtb_Switch1_bxh == measure_P.Constant_Value_civ2q);
  rtb_LogicalOperator1_b2ck = (rtb_LogicalOperator2_m && (!(rtb_Compare_cj ||
    rtb_Compare_bq)));
  if (rtb_Compare_bq) {
    rtb_Switch1_bxh = measure_P.int2_Value_c;
  }

  rtb_FixPtSum1_g = rtb_Switch1_bxh - measure_P.FixPtConstant_Value_civ;
  if (rtb_Compare_cj) {
    rtb_UnitDelay1_pf = measure_P.int1_Value_c;
  }

  rtb_FixPtSum1_go = rtb_UnitDelay1_pf - measure_P.FixPtConstant_Value_civ2;
  if (rtb_LogicalOperator1_drl4) {
    measure_B.Switch_iwl = measure_P.double_Value_epw;
  } else {
    measure_B.Switch_iwl = (measure_B.ACripple1stestimate +
      measure_DWork.UnitDelay4_DSTATE_krxzyrko) +
      measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_iqvvodsl[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_pzv45hn0c0;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_iwl;
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_epw;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelayw_ndljwvwq = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_epw)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_aiui) {
    measure_B.Switch_iwlt = measure_P.double_Value_epwu;
  } else {
    measure_B.Switch_iwlt = (measure_B.ACripple1stestimate +
      measure_DWork.UnitDelay4_DSTATE_krxzyrkob) +
      measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_iqvvodsli[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_pzv45hn0c03;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_iwlt;
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_epwu;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelay_ndljwvwq0 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_epwu)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Add1_h_idx_1 = measure_B.Switch_iwl -
      measure_B.VariableDiscreteDelayw_ndljwvwq;
  } else {
    rtb_Add1_h_idx_1 = measure_B.Switch_iwlt -
      measure_B.VariableDiscreteDelay_ndljwvwq0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_bqvb[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_mw3lz;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.ACripple1stestimate;
    VDD_out = *VDD_in - measure_B.Switch2_a4fq3;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_ep;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_ep)
      *VDD_in = 0;
  }

  rtb_Switch = measure_B.ACripple1stestimate - ((rtb_Add1_h_idx_1 -
    ((measure_B.VariableDiscreteDelaywithT_h0qt * rtb_Subtract3_o) +
     (measure_B.VariableDiscreteDelaywith_gtqs2 * rtb_MathFunction_bdy))) *
    rtb_Tps2dt_m);
  rtb_Switch_iwltec = measure_DWork.UnitDelay_DSTATE_ehbx +
    measure_P.Bias_Bias_epwu2g;
  if (rtb_Switch_iwltec < measure_DWork.UnitDelay_DSTATE_ehbx) {
    rtb_Switch_iwltec = MAX_uint32_T;
  }

  rtb_Unbalance = measure_DWork.UnitDelay_DSTATE_eh;
  rtb_LogicalOperator16 = (((measure_DWork.UnitDelay_DSTATE_eh < 0.0) ? -1.0 :
                            ((measure_DWork.UnitDelay_DSTATE_eh > 0.0) ? 1.0 :
                             ((measure_DWork.UnitDelay_DSTATE_eh == 0.0) ? 0.0 :
    measure_DWork.UnitDelay_DSTATE_eh))) > measure_P.Constant_Value_b5);
  if (measure_P.Constant_Value_adu) {
    rtb_Compare_cj = (rtb_LogicalOperator16 && (!measure_DWork.delay_DSTATE_n0));
  } else {
    rtb_Compare_cj = ((rtb_LogicalOperator16 ^ measure_DWork.delay1_DSTATE_fk) &&
                      (measure_DWork.UnitDelay_DSTATE_ehbxxq));
  }

  rtb_Compare_cj = ((!measure_DWork.UnitDelay2_DSTAT_lscnp0r3jm2b3r) &&
                    rtb_Compare_cj);
  if (rtb_Compare_cj) {
    rtb_Switch2_a = rtb_Switch_iwltec;
  } else {
    rtb_Switch2_a = measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b;
  }

  if (rtb_Compare_cj) {
    rtb_Gain_m = measure_DWork.UnitDelay_DSTATE_eh -
      measure_DWork.UnitDelay1_DSTATE_omt;
    if (rtb_Gain_m < measure_P.Constant_Value_mk) {
      rtb_Switch1_kt5c = -rtb_Gain_m;
    } else {
      rtb_Switch1_kt5c = rtb_Gain_m;
    }

    if (rtb_Switch1_kt5c < measure_P.Constant_Value_e1) {
      rtb_Gain_m = measure_P.Constant1_Value_epwu2g;
    }

    rtb_Divide_ny = (measure_DWork.UnitDelay1_DSTATE_omt / rtb_Gain_m) *
      measure_P.T2T1_Gain;
    rtb_MinMax1 = rtb_Divide_ny - measure_DWork.UnitDelay4_DSTATE_krxzyrkobe;
  } else {
    rtb_Divide_ny = measure_DWork.UnitDelay1_DSTATE_omtd;
    rtb_MinMax1 = measure_DWork.UnitDelay1_DSTATE_omtd1;
  }

  rtb_Add1_h_idx_1 = (measure_P.Gain_Gain_epwu * ((real_T)rtb_Switch2_a)) +
    rtb_MinMax1;
  if (rtb_Add1_h_idx_1 < measure_P.Constant_Value_o5) {
    rtb_Add1_h_idx_1 = measure_P.Constant_Value_c;
  }

  rtb_Gain1_kh = (1.0 / rtb_Add1_h_idx_1) * measure_P.Gain_Gain_epwu2;
  if (rtb_Compare_no) {
    rtb_Divide_n = measure_P.Constant_Value_epwu2gd3xo;
  } else {
    rtb_Gain_m = ((measure_DWork.UnitDelay1_DSTATE_om + rtb_Gain1_kh) *
                  measure_P.Gain_Gain_e) -
      measure_DWork.UnitDelay1_DSTATE_omtd1h;
    if (rtb_Gain_m < measure_P.Constant_Value_epwu2gd3) {
      rtb_Gain_m = measure_P.Constant_Value_epwu2;
    } else {
      if (rtb_Gain_m > measure_P.Constant_Value_epwu) {
        rtb_Gain_m = measure_P.Constant1_Value_ep;
      }
    }

    rtb_Gain_m += measure_DWork.UnitDelay1_DSTATE_omtd1h;
    if (rtb_Gain_m < measure_P.Constant_Value_epwu2gd3x) {
      rtb_Divide_n = measure_P.Constant_Value_epwu2gd;
    } else if (rtb_Gain_m > measure_P.Constant_Value_epwu2g) {
      rtb_Divide_n = measure_P.Constant1_Value_epw;
    } else {
      rtb_Divide_n = rtb_Gain_m;
    }
  }

  rtb_Gain_m = measure_P.Gain2_Gain_ep * rtb_Divide_n;
  if (0.0 != 0.0) {
    if (rtb_Gain_m > measure_P.Constant_Value_dh) {
      measure_B.Switch2_a4f = rtb_Gain_m + measure_P.Bias1_Bias_e;
    } else {
      measure_B.Switch2_a4f = rtb_Gain_m + measure_P.Bias_Bias_e;
    }
  } else {
    measure_B.Switch2_a4f = rtb_Gain_m;
  }

  {
    measure_B.SFunction_mp = (int)measure_B.Switch2_a4f;
  }

  if (((real_T)measure_B.SFunction_mp) < measure_P.Constant_Value_ef) {
    rtb_VpuIpktoVrmsIrms_re = measure_P.Constant_Value_epwu2gd3xoy;
  } else {
    rtb_VpuIpktoVrmsIrms_re = (real_T)measure_B.SFunction_mp;
  }

  rtb_Gain_m = ((1.0 / rtb_Divide_n) * rtb_VpuIpktoVrmsIrms_re) -
    measure_DWork.UnitDelay1_DSTATE_omtd1hd;
  if (rtb_Gain_m < measure_P.Constant_Value_hn) {
    rtb_Divide_h = measure_P.Constant_Value_epw;
  } else if (rtb_Gain_m > measure_P.Constant_Value_ep) {
    rtb_Divide_h = measure_P.Constant1_Value_e;
  } else {
    rtb_Divide_h = rtb_Gain_m;
  }

  rtb_Divide_jw = rtb_Divide_h + measure_DWork.UnitDelay1_DSTATE_omtd1hd;
  if (rtb_Compare_no) {
    rtb_Switch1_gmkuez3wo = rtb_UnitDelay1_nt;
  } else {
    rtb_Switch1_gmkuez3wo = measure_P.int1_Value_e;
  }

  rtb_Divide_h = std::exp((measure_P.Gain1_Gain_ep * rtb_Divide_n) *
    measure_P.Gain2_Gain_epw);
  rtb_Switch_l40f = (measure_P.double1_Value - rtb_Divide_h) * rtb_Switch;
  rtb_Divide_j = rtb_Unbalance * rtb_Divide_h;
  rtb_Add1_h_idx_1 = (measure_P.Gain1_Gain_epw * rtb_Add1_h_idx_1) +
    measure_P.Bias_Bias_epwu;
  if (rtb_Add1_h_idx_1 < measure_P.Constant_Value_oi) {
    rtb_Add1_h_idx_1 = measure_P.Constant_Value_k;
  }

  rtb_Gain_m = (measure_P.Gain_Gain_epwu2g * rtb_Add1_h_idx_1) +
    measure_P.Bias_Bias_epwu2;
  if (rtb_Gain_m < measure_P.Constant_Value_pc) {
    rtb_Gain_m = measure_P.Constant_Value_epwu2gd3xoydfl5;
  } else {
    if (rtb_Gain_m > measure_P.Constant_Value_epwu2gd3xoydfl) {
      rtb_Gain_m = measure_P.Constant1_Value_epwu2;
    }
  }

  if (0.0 != 0.0) {
    measure_B.Switch2_a4fq = rtb_Gain_m + measure_P.Bias1_Bias_epw;
  } else {
    measure_B.Switch2_a4fq = rtb_Gain_m + measure_P.Bias_Bias_epw;
  }

  {
    measure_B.SFunction_mpm = (unsigned int)measure_B.Switch2_a4fq;
  }

  if (rtb_Compare_cj && (measure_P.Constant2_Value_e)) {
    rtb_UnitDelay1_nt = measure_B.SFunction_mpm;
  } else {
    rtb_UnitDelay1_nt = measure_DWork.UnitDelay_DSTATE_ehbxx -
      measure_P.FixPtConstant_Value_ep;
  }

  rtb_LogicalOperator9 = (rtb_UnitDelay1_nt > measure_P.Constant_Value_a3);
  if (rtb_LogicalOperator9) {
    rtb_Switch1_gmkuez3woc = rtb_UnitDelay1_nt;
  } else {
    rtb_Switch1_gmkuez3woc = measure_P.int1_Value_ep;
  }

  if (rtb_Compare_cj) {
    rtb_Switch_iwltec = measure_P.Constant_Value_hw;
  }

  if (rtb_LogicalOperator_aj) {
    rtb_Switch1_c1 = measure_P.int2_Value_h;
  }

  rtb_FixPtSum1_m = rtb_Switch1_c1 - measure_P.FixPtConstant_Value_h;
  if (rtb_LogicalOperator12) {
    rtb_Switch1_c1 = measure_DWork.UnitDelay1_DSTATE_hf;
  } else {
    rtb_Switch1_c1 = measure_P.const_Value_p;
  }

  rtb_LogicalOperator_aj = (rtb_Switch1_c1 == measure_P.Constant_Value_a0);
  rtb_Any_Phases_Not_Disturbed = (rtb_LogicalOperator_aj &&
    rtb_Disturbance_All_Phases);
  rtb_LogicalOperator1_f = (rtb_Any_Phases_Not_Disturbed &&
    (!measure_DWork.delay_DSTATE_o));
  rtb_Gain_m = measure_P.Gain_Gain_m * measure_P.Constant4_Value_g;
  if (0.0 != 0.0) {
    measure_B.Switch2_co = rtb_Gain_m + measure_P.Bias1_Bias_d;
  } else {
    measure_B.Switch2_co = rtb_Gain_m + measure_P.Bias_Bias_d;
  }

  {
    measure_B.SFunction_nt = (unsigned int)measure_B.Switch2_co;
  }

  if (rtb_UnitDelay4_hd) {
    rtb_UnitDelay1_nt = measure_B.SFunction_nt + measure_P.FixPtConstant_Value_p;
  } else {
    rtb_UnitDelay1_nt = measure_DWork.UnitDelay_DSTATE_cx -
      measure_P.FixPtConstant_Value_m;
  }

  rtb_LogicalOperator12 = (rtb_UnitDelay1_nt > measure_P.Constant_Value_m4);
  if (rtb_LogicalOperator12) {
    rtb_Switch1_kn = rtb_UnitDelay1_nt;
  } else {
    rtb_Switch1_kn = measure_P.int1_Value_m;
  }

  rtb_LogicalOperator2_b0 = ((measure_DWork.UnitDelay_DSTATE_jqi) ||
    ((!rtb_LogicalOperator12) && rtb_LogicalOperator1_f));
  rtb_UnitDelay1_nt = measure_DWork.UnitDelay1_DSTATE_cx;
  rtb_LogicalOperator1_f = (rtb_UnitDelay4_hd &&
    (measure_DWork.UnitDelay_DSTATE_l));
  rtb_Gain_m = measure_P.Gain_Gain_ds * measure_P.Constant3_Value;
  if (0.0 != 0.0) {
    measure_B.Switch2_m = rtb_Gain_m + measure_P.Bias1_Bias_b;
  } else {
    measure_B.Switch2_m = rtb_Gain_m + measure_P.Bias_Bias_b;
  }

  {
    measure_B.SFunction_p3 = (unsigned int)measure_B.Switch2_m;
  }

  if (!rtb_LogicalOperator1_f) {
    rtb_UnitDelay1_nt = measure_B.SFunction_p3 + measure_P.FixPtConstant_Value_j;
  }

  rtb_LogicalOperator12 = (rtb_UnitDelay1_nt == measure_P.Constant_Value_cjo);
  if (rtb_UnitDelay4_hd && ((rtb_RelationalOperator_c ||
        rtb_RelationalOperator_i) || rtb_RelationalOperator_h)) {
    rtb_UnitDelay1_pf = measure_DWork.UnitDelay1_DSTATE_d5;
  } else {
    rtb_UnitDelay1_pf = measure_P.const_Value_e;
  }

  rtb_Compare_cj = (rtb_UnitDelay1_pf == measure_P.Constant_Value_f0);
  rtb_LogicalOperator2_m = (rtb_LogicalOperator2_b0 && (!(rtb_LogicalOperator12 ||
    rtb_Compare_cj)));
  if (rtb_Compare_cj) {
    rtb_UnitDelay1_pf = measure_P.int2_Value_c2;
  }

  rtb_FixPtSum1_l = rtb_UnitDelay1_pf - measure_P.FixPtConstant_Value_jh;
  if (rtb_LogicalOperator12) {
    rtb_UnitDelay1_nt = measure_P.int1_Value_m2;
  }

  rtb_FixPtSum1_h = rtb_UnitDelay1_nt - measure_P.FixPtConstant_Value_jl;
  rtb_Add1_h_idx_1 = rtb_TrigonometricFunction_l -
    measure_DWork.UnitDelay3_DSTATE_pg;
  if (rtb_Add1_h_idx_1 < measure_P.Constant_Value_e52) {
    rtb_Add1_h_idx_1 += measure_P.Bias1_Bias_e5;
  } else {
    if (rtb_Add1_h_idx_1 > measure_P.Constant_Value_e5) {
      rtb_Add1_h_idx_1 += measure_P.Bias_Bias_e5;
    }
  }

  rtb_Add1_h_idx_1 *= measure_P.Gain_Gain_ju;
  if (rtb_Compare_k1g) {
    rtb_UnitDelay1_k = measure_P.int1_Value_ci;
  }

  rtb_FixPtSum1_a = rtb_UnitDelay1_k - measure_P.FixPtConstant_Value_ci1;
  if (rtb_Compare_k1) {
    rtb_Switch1_ce = measure_P.int2_Value_ci;
  }

  rtb_FixPtSum1_an = rtb_Switch1_ce - measure_P.FixPtConstant_Value_ci1z;
  if (rtb_Add1_h_idx_1 < measure_P.Constant_Value_as) {
    rtb_Add1_h_idx_1 = -rtb_Add1_h_idx_1;
  }

  rtb_IpktoIrmsconversion = measure_P.Gain_Gain_h1 * rtb_Add1_h_idx_1;
  rtb_Switch_b2 = measure_P.Gain1_Gain_h1 * rtb_UnitDelay_j;
  if (rtb_Compare_ha) {
    rtb_Switch1_m = measure_P.int2_Value_k;
  }

  rtb_FixPtSum1_c = rtb_Switch1_m - measure_P.FixPtConstant_Value_eb;
  if (rtb_Compare_go) {
    rtb_Switch1_d = measure_P.int2_Value_a;
  }

  rtb_FixPtSum1_p = rtb_Switch1_d - measure_P.FixPtConstant_Value_b;
  rtb_Add1_h_idx_1 = rtb_TrigonometricFunction_c -
    measure_DWork.UnitDelay3_DSTATE_pzl;
  if (rtb_Add1_h_idx_1 < measure_P.Constant_Value_m0j) {
    rtb_Add1_h_idx_1 += measure_P.Bias1_Bias_m;
  } else {
    if (rtb_Add1_h_idx_1 > measure_P.Constant_Value_m0) {
      rtb_Add1_h_idx_1 += measure_P.Bias_Bias_m;
    }
  }

  rtb_Add1_h_idx_1 *= measure_P.Gain_Gain_fx;
  if (rtb_Compare_aun) {
    rtb_Switch1_kyp = measure_P.int1_Value_h;
  }

  rtb_FixPtSum1_ln = rtb_Switch1_kyp - measure_P.FixPtConstant_Value_hg;
  if (rtb_Compare_au) {
    rtb_Switch1_ky = measure_P.int2_Value_hg;
  }

  rtb_FixPtSum1_lnu = rtb_Switch1_ky - measure_P.FixPtConstant_Value_hg0;
  if (rtb_Add1_h_idx_1 < measure_P.Constant_Value_nb) {
    rtb_Add1_h_idx_1 = -rtb_Add1_h_idx_1;
  }

  rtb_Switch1_c = measure_P.Gain_Gain_g3 * rtb_Add1_h_idx_1;
  rtb_UnaryMinus_dv = measure_P.Gain1_Gain_g * rtb_UnitDelay_n;
  if (rtb_Compare_df) {
    rtb_Switch1_o = measure_P.int2_Value_n;
  }

  rtb_FixPtSum1_cy = rtb_Switch1_o - measure_P.FixPtConstant_Value_gy;
  if (rtb_Compare_eb) {
    rtb_Switch1_cc = measure_P.int2_Value_c5;
  }

  rtb_FixPtSum1_mz = rtb_Switch1_cc - measure_P.FixPtConstant_Value_bi;
  rtb_Add1_h_idx_1 = rtb_TrigonometricFunction_b -
    measure_DWork.UnitDelay3_DSTATE_ot;
  if (rtb_Add1_h_idx_1 < measure_P.Constant_Value_ki2) {
    rtb_Add1_h_idx_1 += measure_P.Bias1_Bias_ki;
  } else {
    if (rtb_Add1_h_idx_1 > measure_P.Constant_Value_ki) {
      rtb_Add1_h_idx_1 += measure_P.Bias_Bias_ki;
    }
  }

  rtb_Add1_h_idx_1 *= measure_P.Gain_Gain_kv;
  if (rtb_Compare_ge) {
    rtb_Switch1_cgb = measure_P.int1_Value_g;
  }

  rtb_FixPtSum1_f = rtb_Switch1_cgb - measure_P.FixPtConstant_Value_gu;
  if (rtb_Compare_g) {
    rtb_Switch1_cg = measure_P.int2_Value_g;
  }

  rtb_Switch1_cgb = rtb_Switch1_cg - measure_P.FixPtConstant_Value_gun;
  if (rtb_Add1_h_idx_1 < measure_P.Constant_Value_lz) {
    rtb_Add1_h_idx_1 = -rtb_Add1_h_idx_1;
  }

  rtb_Divide_jahf = measure_P.Gain_Gain_mh * rtb_Add1_h_idx_1;
  rtb_AbsVI_e = measure_P.Gain1_Gain_mh * rtb_UnitDelay_ic;
  if (rtb_Compare_m3) {
    rtb_Switch1_k3g = measure_P.int2_Value_c1;
  }

  rtb_Switch1_cc = rtb_Switch1_k3g - measure_P.FixPtConstant_Value_cp;
  if (rtb_Compare_o1) {
    rtb_Switch1_oi = measure_P.int2_Value_d;
  }

  rtb_Switch1_o = rtb_Switch1_oi - measure_P.FixPtConstant_Value_fkp;
  measure_B.DataTypeConversion = (real_T)(((rtb_UnitDelay2_j >
    measure_P.Constant_Value_p0) && (rtb_UnitDelay2_j <
    measure_P.Constant_Value_gby)) && ((((rtb_Bias > measure_P.Constant_Value_fv)
    && (rtb_Bias < measure_P.Constant_Value_oy)) && ((rtb_Bias1 >
    measure_P.Constant_Value_d4) && (rtb_Bias1 < measure_P.Constant_Value_bx))) &&
    ((rtb_Bias2 > measure_P.Constant_Value_no) && (rtb_Bias2 <
    measure_P.Constant_Value_h3))));
  if (rtb_Compare_cz) {
    rtb_Switch1_ky = rtb_Switch_jv;
  } else {
    rtb_Switch1_ky = measure_P.int1_Value_gq;
  }

  if (rtb_Compare_czp) {
    rtb_Switch1_kyp = rtb_Switch_jvw;
  } else {
    rtb_Switch1_kyp = measure_P.int1_Value_gqo;
  }

  if (rtb_Compare_czp1) {
    rtb_UnitDelay1_pf = rtb_Switch_jvwj;
  } else {
    rtb_UnitDelay1_pf = measure_P.int1_Value_gqop;
  }

  if (rtb_Compare_n) {
    rtb_UnitDelay1_nt = rtb_Bias_hsr;
  } else {
    rtb_UnitDelay1_nt = measure_P.int1_Value_cm;
  }

  if (rtb_Compare_mp) {
    rtb_UnitDelay1_n0 = measure_P.int2_Value_o;
  }

  rtb_Switch1_d = rtb_UnitDelay1_n0 - measure_P.FixPtConstant_Value_k;
  if (rtb_LogicalOperator1_bbcu) {
    measure_B.Switch_iln5 = measure_P.double_Value_ii12;
  } else {
    measure_B.Switch_iln5 = (measure_B.ACripple1stestimate_f +
      measure_DWork.UnitDelay4_DSTATE_cvz) + measure_DWork.UnitDelay2_DSTATE_dgh;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_pbu[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_cjw;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_iln5;
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_ii1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_dra = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_ii1)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_ot) {
    measure_B.Switch_iln5l = measure_P.double_Value_ii12h;
  } else {
    measure_B.Switch_iln5l = (measure_B.ACripple1stestimate_f +
      measure_DWork.UnitDelay4_DSTATE_cvzr) +
      measure_DWork.UnitDelay2_DSTATE_dghn;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_pbur[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_cjwa;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_iln5l;
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_ii12;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithO_drao = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_ii12)
      *VDD_in = 0;
  }

  if (rtb_Switch6_idx) {
    rtb_Add1_h_idx_1 = measure_B.Switch_iln5 -
      measure_B.VariableDiscreteDelaywithOn_dra;
  } else {
    rtb_Add1_h_idx_1 = measure_B.Switch_iln5l -
      measure_B.VariableDiscreteDelaywithO_drao;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_g0[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_oss;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.ACripple1stestimate_f;
    VDD_out = *VDD_in - measure_B.Switch2_f4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_ii;
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

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_ii)
      *VDD_in = 0;
  }

  rtb_Switch1_k = measure_B.ACripple1stestimate_f - ((rtb_Add1_h_idx_1 -
    ((measure_B.VariableDiscreteDelaywithTwo_oa * rtb_Switch_l40f02) +
     (measure_B.VariableDiscreteDelaywithTw_i44 * rtb_Switch4))) * rtb_Switch_l4);
  rtb_UnitDelay1_k = measure_DWork.UnitDelay_DSTATE_jm +
    measure_P.Bias_Bias_gbvu;
  if (rtb_UnitDelay1_k < measure_DWork.UnitDelay_DSTATE_jm) {
    rtb_UnitDelay1_k = MAX_uint32_T;
  }

  rtb_AbsVI = measure_DWork.UnitDelay_DSTATE_c;
  rtb_LogicalOperator2_b0 = (((measure_DWork.UnitDelay_DSTATE_c < 0.0) ? -1.0 :
                              ((measure_DWork.UnitDelay_DSTATE_c > 0.0) ? 1.0 :
                               ((measure_DWork.UnitDelay_DSTATE_c == 0.0) ? 0.0 :
    measure_DWork.UnitDelay_DSTATE_c))) > measure_P.Constant_Value_gbvuwp);
  if (measure_P.Constant_Value_gbvuwpgu2kml1) {
    rtb_LogicalOperator1_bbcu = (rtb_LogicalOperator2_b0 &&
      (!measure_DWork.delay_DSTATE_ep));
  } else {
    rtb_LogicalOperator1_bbcu = ((rtb_LogicalOperator2_b0 ^
      measure_DWork.delay1_DSTATE_l5) && (measure_DWork.UnitDelay_DSTATE_jmcy));
  }

  rtb_LogicalOperator1_bbcu = ((!measure_DWork.UnitDelay2_DSTATE_ocn) &&
    rtb_LogicalOperator1_bbcu);
  if (rtb_LogicalOperator1_bbcu) {
    rtb_Switch1_m = rtb_UnitDelay1_k;
  } else {
    rtb_Switch1_m = measure_DWork.UnitDelay2_DSTATE_oc;
  }

  if (rtb_LogicalOperator1_bbcu) {
    rtb_Gain_m = measure_DWork.UnitDelay_DSTATE_c -
      measure_DWork.UnitDelay1_DSTATE_gr;
    if (rtb_Gain_m < measure_P.Constant_Value_gbvuwpg) {
      rtb_Switch1_kt5c = -rtb_Gain_m;
    } else {
      rtb_Switch1_kt5c = rtb_Gain_m;
    }

    if (rtb_Switch1_kt5c < measure_P.Constant_Value_gbvuw) {
      rtb_Gain_m = measure_P.Constant1_Value_gbv;
    }

    rtb_Product_i = (measure_DWork.UnitDelay1_DSTATE_gr / rtb_Gain_m) *
      measure_P.T2T1_Gain_g;
    rtb_Add1_h_idx_0 = rtb_Product_i - measure_DWork.UnitDelay4_DSTATE_a;
  } else {
    rtb_Product_i = measure_DWork.UnitDelay1_DSTATE_grk;
    rtb_Add1_h_idx_0 = measure_DWork.UnitDelay1_DSTATE_grkf;
  }

  rtb_Add1_h_idx_1 = (measure_P.Gain_Gain_gb * ((real_T)rtb_Switch1_m)) +
    rtb_Add1_h_idx_0;
  if (rtb_Add1_h_idx_1 < measure_P.Constant_Value_gbvuwpgu) {
    rtb_Add1_h_idx_1 = measure_P.Constant_Value_gbvu;
  }

  rtb_UnaryMinus_p = (1.0 / rtb_Add1_h_idx_1) * measure_P.Gain_Gain_gbv;
  if (rtb_Compare_k5) {
    rtb_MathFunction1 = measure_P.Constant_Value_hper21c0u;
  } else {
    rtb_Gain_m = ((measure_DWork.UnitDelay1_DSTATE_k + rtb_UnaryMinus_p) *
                  measure_P.Gain_Gain_ce) - measure_DWork.UnitDelay1_DSTATE_j;
    if (rtb_Gain_m < measure_P.Constant_Value_hper21c) {
      rtb_Gain_m = measure_P.Constant_Value_hper;
    } else {
      if (rtb_Gain_m > measure_P.Constant_Value_hpe) {
        rtb_Gain_m = measure_P.Constant1_Value_hpe;
      }
    }

    rtb_Gain_m += measure_DWork.UnitDelay1_DSTATE_j;
    if (rtb_Gain_m < measure_P.Constant_Value_hper21c0) {
      rtb_MathFunction1 = measure_P.Constant_Value_hper21;
    } else if (rtb_Gain_m > measure_P.Constant_Value_hper2) {
      rtb_MathFunction1 = measure_P.Constant1_Value_hper;
    } else {
      rtb_MathFunction1 = rtb_Gain_m;
    }
  }

  rtb_Gain_m = measure_P.Gain2_Gain_j * rtb_MathFunction1;
  if (0.0 != 0.0) {
    if (rtb_Gain_m > measure_P.Constant_Value_ii) {
      measure_B.Switch2_o = rtb_Gain_m + measure_P.Bias1_Bias_i;
    } else {
      measure_B.Switch2_o = rtb_Gain_m + measure_P.Bias_Bias_i;
    }
  } else {
    measure_B.Switch2_o = rtb_Gain_m;
  }

  {
    measure_B.SFunction_p = (int)measure_B.Switch2_o;
  }

  if (((real_T)measure_B.SFunction_p) < measure_P.Constant_Value_gs) {
    rtb_VpuIpktoVrmsIrms_re = measure_P.Constant_Value_l;
  } else {
    rtb_VpuIpktoVrmsIrms_re = (real_T)measure_B.SFunction_p;
  }

  rtb_Gain_m = ((1.0 / rtb_MathFunction1) * rtb_VpuIpktoVrmsIrms_re) -
    measure_DWork.UnitDelay1_DSTATE_d;
  if (rtb_Gain_m < measure_P.Constant_Value_fg15t) {
    rtb_Divide_h = measure_P.Constant_Value_fg15;
  } else if (rtb_Gain_m > measure_P.Constant_Value_fg1) {
    rtb_Divide_h = measure_P.Constant1_Value_f;
  } else {
    rtb_Divide_h = rtb_Gain_m;
  }

  rtb_Switch = rtb_Divide_h + measure_DWork.UnitDelay1_DSTATE_d;
  if (rtb_Compare_k5) {
    rtb_Switch1_ce = rtb_Switch_oh;
  } else {
    rtb_Switch1_ce = measure_P.int1_Value_n;
  }

  rtb_Divide_h = std::exp((measure_P.Gain1_Gain_j * rtb_MathFunction1) *
    measure_P.Gain2_Gain_en);
  rtb_Switch1_kt5c = (measure_P.double1_Value_e - rtb_Divide_h) * rtb_Switch1_k;
  rtb_Add1_h_idx_1 = (measure_P.Gain1_Gain_gb * rtb_Add1_h_idx_1) +
    measure_P.Bias_Bias_gb;
  if (rtb_Add1_h_idx_1 < measure_P.Constant_Value_gbvuwpgu2) {
    rtb_Add1_h_idx_1 = measure_P.Constant_Value_gbv;
  }

  rtb_Gain_m = (measure_P.Gain_Gain_gbvu * rtb_Add1_h_idx_1) +
    measure_P.Bias_Bias_gbv;
  if (rtb_Gain_m < measure_P.Constant_Value_gbvuwpgu2k) {
    rtb_Gain_m = measure_P.Constant_Value_gb;
  } else {
    if (rtb_Gain_m > measure_P.Constant_Value_g) {
      rtb_Gain_m = measure_P.Constant1_Value_gb;
    }
  }

  if (0.0 != 0.0) {
    measure_B.Switch2_g = rtb_Gain_m + measure_P.Bias1_Bias_g;
  } else {
    measure_B.Switch2_g = rtb_Gain_m + measure_P.Bias_Bias_g;
  }

  {
    measure_B.SFunction_ne = (unsigned int)measure_B.Switch2_g;
  }

  if (rtb_LogicalOperator1_bbcu && (measure_P.Constant2_Value_g)) {
    rtb_UnitDelay1_n0 = measure_B.SFunction_ne;
  } else {
    rtb_UnitDelay1_n0 = measure_DWork.UnitDelay_DSTATE_jmc -
      measure_P.FixPtConstant_Value_gb;
  }

  rtb_LogicalOperator1_f = (rtb_UnitDelay1_n0 >
    measure_P.Constant_Value_gbvuwpgu2kml);
  if (rtb_LogicalOperator1_f) {
    rtb_Switch1_bxh = rtb_UnitDelay1_n0;
  } else {
    rtb_Switch1_bxh = measure_P.int1_Value_gb;
  }

  if (rtb_LogicalOperator1_bbcu) {
    rtb_UnitDelay1_n0 = measure_P.Constant_Value_gbvuwpgu2km;
  } else {
    rtb_UnitDelay1_n0 = rtb_UnitDelay1_k;
  }

  if (rtb_LogicalOperator_aj) {
    rtb_Switch1_c1 = measure_P.int2_Value_gx;
  }

  rtb_UnitDelay1_k = rtb_Switch1_c1 - measure_P.FixPtConstant_Value_mp;

  {
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunction_;
    *xD = measure_B.Switch_m;
  }

  measure_DWork.UnitDelay4_DSTATE_ep = rtb_LogicalOperator2_m;
  measure_DWork.delay_DSTATE = rtb_UnitDelay4_hd;
  measure_DWork.UnitDelay_DSTATE = rtb_Switch1;

  {
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_c;
    *xD = measure_B.Switch2_a4;
  }

  measure_DWork.UnitDelay4_DSTATE_krxzyrkobej = rtb_LogicalOperator1_b2ck;
  measure_DWork.delay_DSTATE_b = rtb_UnitDelay4_ej;
  measure_DWork.UnitDelay_DSTATE_i = rtb_Switch1_b;
  measure_DWork.UnitDelay_DSTATE_e = rtb_Switch_j;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b3 = rtb_LogicalOperator1_i;
  measure_DWork.delay1_DSTATE = rtb_Compare;
  measure_DWork.delay1_DSTATE_l = rtb_Compare_f;
  measure_DWork.UnitDelay3_DSTATE = rtb_TrigonometricFunction;
  measure_DWork.UnitDelay1_DSTATE = measure_U.Vabcpu[1];
  measure_DWork.UnitDelay2_DSTATE = rtb_UnitDelay1;
  measure_DWork.UnitDelay1_DSTATE_i = measure_U.Vabcpu[2];
  measure_DWork.UnitDelay2_DSTATE_a = rtb_UnitDelay1_a;
  measure_DWork.UnitDelay1_DSTATE_b = measure_U.Vabcpu[0];
  measure_DWork.UnitDelay2_DSTATE_c = rtb_UnitDelay1_i;
  measure_DWork.UnitDelay4_DSTATE = measure_B.Gain;
  measure_DWork.UnitDelay2_DSTATE_l = measure_B.Switch;
  measure_DWork.delay_DSTATE_i = rtb_Compare_f;
  measure_DWork.UnitDelay4_DSTATE_k = measure_B.Gain;
  measure_DWork.UnitDelay2_DSTATE_ls = measure_B.Switch_j;
  measure_DWork.UnitDelay4_DSTATE_kr = measure_B.Switch2_p;
  measure_DWork.UnitDelay2_DSTATE_lsc = measure_B.Switch_jc;
  measure_DWork.delay_DSTATE_i2 = rtb_Compare;
  measure_DWork.UnitDelay4_DSTATE_krx = measure_B.Switch2_p;
  measure_DWork.UnitDelay2_DSTATE_lscn = measure_B.Switch_jc4;
  measure_DWork.UnitDelay4_DSTATE_krxz = measure_B.Switch4;
  measure_DWork.UnitDelay2_DSTATE_lscnp = measure_B.Switch_jc4w;
  measure_DWork.UnitDelay4_DSTATE_krxzy = measure_B.Switch4;
  measure_DWork.UnitDelay2_DSTATE_lscnp0 = measure_B.Switch_jc4wm;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdp = rtb_FixPtSum1_ja;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdpu = rtb_FixPtSum1_j;
  measure_DWork.delay1_DSTATE_f = rtb_Compare_d;
  measure_DWork.UnitDelay4_DSTATE_krxzyr = measure_B.Switch2_c;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r = measure_B.Switch_i;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3 = rtb_Divide_jw;
  measure_DWork.delay_DSTATE_n = rtb_Compare_d;
  measure_DWork.UnitDelay4_DSTATE_krxzyrk = measure_B.Switch2_c;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3j = measure_B.Switch_iw;
  measure_DWork.UnitDelay_DSTATE_ehb = rtb_Switch1_gmkuez3wo;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdput = rtb_FixPtSum1;
  measure_DWork.UnitDelay1_DSTATE_gf = rtb_Switch1_d;
  measure_DWork.UnitDelay2_DSTATE_h = rtb_Switch_c;
  measure_DWork.UnitDelay4_DSTATE_ii = rtb_LogicalOperator2_fd;
  measure_DWork.UnitDelay1_DSTATE_m4 = rtb_FixPtSum1_c;
  measure_DWork.delay1_DSTATE_n = rtb_Compare_o;
  measure_DWork.UnitDelay_DSTATE_f = rtb_Sum;
  measure_DWork.UnitDelay4_DSTATE_j = measure_B.Product[0];
  measure_DWork.UnitDelay2_DSTATE_lj = measure_B.Switch_ix;
  measure_DWork.delay_DSTATE_c = rtb_Compare_o;
  measure_DWork.UnitDelay4_DSTATE_js = measure_B.Product[0];
  measure_DWork.UnitDelay2_DSTATE_ljf = measure_B.Switch_ixh;
  measure_DWork.UnitDelay4_DSTATE_js0 = measure_B.Product[1];
  measure_DWork.UnitDelay2_DSTATE_ljfw = measure_B.Switch_ixhv;
  measure_DWork.UnitDelay4_DSTATE_js0g = measure_B.Product[1];
  measure_DWork.UnitDelay2_DSTATE_ljfwk = measure_B.Switch_ixhvn;
  measure_DWork.UnitDelay1_DSTATE_j4 = rtb_FixPtSum1_cy;
  measure_DWork.UnitDelay4_DSTATE_e = measure_B.Product_j[0];
  measure_DWork.UnitDelay2_DSTATE_ab = measure_B.Switch_d;
  measure_DWork.UnitDelay4_DSTATE_e1 = measure_B.Product_j[0];
  measure_DWork.UnitDelay2_DSTATE_abj = measure_B.Switch_dh;
  measure_DWork.UnitDelay4_DSTATE_e10 = measure_B.Product_j[1];
  measure_DWork.UnitDelay2_DSTATE_abju = measure_B.Switch_dh3;
  measure_DWork.UnitDelay4_DSTATE_e10c = measure_B.Product_j[1];
  measure_DWork.UnitDelay2_DSTATE_abju3 = measure_B.Switch_dh3i;
  measure_DWork.UnitDelay1_DSTATE_g0 = rtb_Switch1_cc;
  measure_DWork.UnitDelay4_DSTATE_o = measure_B.Product_k[0];
  measure_DWork.UnitDelay2_DSTATE_g = measure_B.Switch_p;
  measure_DWork.UnitDelay4_DSTATE_ot = measure_B.Product_k[0];
  measure_DWork.UnitDelay2_DSTATE_gl = measure_B.Switch_p0;
  measure_DWork.UnitDelay4_DSTATE_otw = measure_B.Product_k[1];
  measure_DWork.UnitDelay2_DSTATE_gll = measure_B.Switch_p0n;
  measure_DWork.UnitDelay4_DSTATE_otws = measure_B.Product_k[1];
  measure_DWork.UnitDelay2_DSTATE_gllv = measure_B.Switch_p0ny;
  measure_DWork.delay1_DSTATE_nm = rtb_Compare_oafgue;
  measure_DWork.UnitDelay3_DSTATE_p = rtb_Add_a;
  measure_DWork.delay1_DSTATE_nmq = rtb_Compare_oafguee;
  measure_DWork.UnitDelay4_DSTATE_js0g0 = measure_B.Divide_h;
  measure_DWork.UnitDelay2_DSTATE_ljfwkl = measure_B.Switch_ixhvnq;
  measure_DWork.delay_DSTATE_ci = rtb_Compare_oafguee;
  measure_DWork.UnitDelay4_DSTATE_js0g0x = measure_B.Divide_h;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf = measure_B.Switch_ixhvnql;
  measure_DWork.UnitDelay4_DSTATE_js0g0xc = measure_B.Divide;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5 = measure_B.Switch_ixhvnqlu;
  measure_DWork.UnitDelay4_DSTATE_js0g0xck = measure_B.Divide;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5t = measure_B.Switch_ixhvnqlui;
  measure_DWork.UnitDelay4_DSTATE_i = measure_B.Switch6;
  measure_DWork.UnitDelay2_DSTATE_l1 = measure_B.Switch_dm;
  measure_DWork.delay_DSTATE_cir = rtb_Compare_oafgue;
  measure_DWork.UnitDelay4_DSTATE_iv = measure_B.Switch6;
  measure_DWork.UnitDelay2_DSTATE_l1a = measure_B.Switch_dmo;
  measure_DWork.UnitDelay1_DSTATE_c = rtb_FixPtSum1_p;
  measure_DWork.UnitDelay_DSTATE_b = rtb_LogicalOperator2_c1;
  measure_DWork.UnitDelay1_DSTATE_n = rtb_FixPtSum1_an;
  measure_DWork.UnitDelay_DSTATE_h = rtb_Switch_b2 + rtb_IpktoIrmsconversion;
  measure_DWork.UnitDelay1_DSTATE_nr = rtb_FixPtSum1_a;

  {
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_a;
    *xD = measure_B.DataTypeConversion;
  }

  measure_DWork.UnitDelay1_DSTATE_m = rtb_MathFunction2;
  measure_DWork.UnitDelay_DSTATE_j = rtb_Switch1_ky;
  measure_DWork.UnitDelay1_DSTATE_g = rtb_MathFunction2_c;
  measure_DWork.UnitDelay_DSTATE_jq = rtb_Switch1_kyp;
  measure_DWork.UnitDelay1_DSTATE_o = rtb_MathFunction2_a;
  measure_DWork.UnitDelay_DSTATE_jqs = rtb_UnitDelay1_pf;
  measure_DWork.UnitDelay1_DSTATE_cf = rtb_FixPtSum1_mz;
  measure_DWork.UnitDelay_DSTATE_md = rtb_LogicalOperator2_bf;
  measure_DWork.UnitDelay1_DSTATE_e = rtb_FixPtSum1_lnu;
  measure_DWork.UnitDelay_DSTATE_g = rtb_UnaryMinus_dv + rtb_Switch1_c;
  measure_DWork.UnitDelay1_DSTATE_ep = rtb_FixPtSum1_ln;
  measure_DWork.UnitDelay1_DSTATE_or = rtb_Switch1_o;
  measure_DWork.UnitDelay_DSTATE_cn = rtb_LogicalOperator2_bg;
  measure_DWork.UnitDelay1_DSTATE_ir = rtb_Switch1_cgb;
  measure_DWork.UnitDelay_DSTATE_d = rtb_AbsVI_e + rtb_Divide_jahf;
  measure_DWork.UnitDelay1_DSTATE_irs = rtb_FixPtSum1_f;
  measure_DWork.UnitDelay3_DSTATE_pz = rtb_Add_o;
  measure_DWork.UnitDelay4_DSTATE_e10ck = measure_B.Divide_ny;
  measure_DWork.UnitDelay2_DSTATE_abju3r = measure_B.Switch_dh3io;
  measure_DWork.UnitDelay4_DSTATE_e10ck0 = measure_B.Divide_ny;
  measure_DWork.UnitDelay2_DSTATE_abju3rc = measure_B.Switch_dh3ioo;
  measure_DWork.UnitDelay4_DSTATE_e10ck0c = measure_B.Divide_n;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3 = measure_B.Switch_dh3ioos;
  measure_DWork.UnitDelay4_DSTATE_e10ck0ct = measure_B.Divide_n;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3x = measure_B.Switch_dh3ioosv;
  measure_DWork.UnitDelay4_DSTATE_b = measure_B.Switch6_n;
  measure_DWork.UnitDelay2_DSTATE_k = measure_B.Switch_iu;
  measure_DWork.UnitDelay4_DSTATE_bc = measure_B.Switch6_n;
  measure_DWork.UnitDelay2_DSTATE_k1 = measure_B.Switch_iua;
  measure_DWork.UnitDelay3_DSTATE_o = rtb_Add_h;
  measure_DWork.UnitDelay4_DSTATE_otwsj = measure_B.Divide_jw;
  measure_DWork.UnitDelay2_DSTATE_gllvy = measure_B.Switch_p0ny3;
  measure_DWork.UnitDelay4_DSTATE_otwsjg = measure_B.Divide_jw;
  measure_DWork.UnitDelay2_DSTATE_gllvyy = measure_B.Switch_p0ny3p;
  measure_DWork.UnitDelay4_DSTATE_otwsjge = measure_B.Divide_j;
  measure_DWork.UnitDelay2_DSTATE_gllvyya = measure_B.Switch_p0ny3pk;
  measure_DWork.UnitDelay4_DSTATE_otwsjget = measure_B.Divide_j;
  measure_DWork.UnitDelay2_DSTATE_gllvyya5 = measure_B.Switch_p0ny3pkq;
  measure_DWork.UnitDelay4_DSTATE_kw = measure_B.Switch6_a;
  measure_DWork.UnitDelay2_DSTATE_o = measure_B.Switch_ja;
  measure_DWork.UnitDelay4_DSTATE_kwr = measure_B.Switch6_a;
  measure_DWork.UnitDelay2_DSTATE_o2 = measure_B.Switch_jag;
  measure_DWork.delay1_DSTATE_g = rtb_Switch6_idx;
  measure_DWork.UnitDelay4_DSTATE_c = measure_B.Switch_l;
  measure_DWork.UnitDelay2_DSTATE_d = measure_B.Switch_il;
  measure_DWork.UnitDelay2_DSTATE_aj = rtb_Switch;
  measure_DWork.delay_DSTATE_h = rtb_Switch6_idx;
  measure_DWork.UnitDelay4_DSTATE_cv = measure_B.Switch_l;
  measure_DWork.UnitDelay2_DSTATE_dg = measure_B.Switch_iln;
  measure_DWork.UnitDelay_DSTATE_m = rtb_Switch1_ce;
  measure_DWork.UnitDelay_DSTATE_hs = rtb_UnitDelay1_nt;
  measure_DWork.delay1_DSTATE_no = rtb_Compare_n;
  measure_DWork.UnitDelay1_DSTATE_p = rtb_LogicalOperator2_f;
  measure_DWork.UnitDelay4_DSTATE_js0g0xcka = measure_B.MathFunction;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5ta = measure_B.Switch_ixhvnqluia;
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaa = measure_B.MathFunction;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5tay = measure_B.Switch_ixhvnqluiaa;
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaam = measure_B.MathFunction1;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5tayt = measure_B.Switch_ixhvnqluiaai;
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaamb = measure_B.MathFunction1;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5taytr = measure_B.Switch_ixhvnqluiaai5;
  measure_DWork.UnitDelay4_DSTATE_e10ck0cti = measure_B.MathFunction_c;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xa = measure_B.Switch_dh3ioosv2;
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctir = measure_B.MathFunction_c;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xak = measure_B.Switch_dh3ioosv2k;
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctirr = measure_B.MathFunction1_p;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku = measure_B.Switch_dh3ioosv2km;
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctirrv = measure_B.MathFunction1_p;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku5 = measure_B.Switch_dh3ioosv2kma;
  measure_DWork.UnitDelay4_DSTATE_otwsjgetk = measure_B.MathFunction_l;
  measure_DWork.UnitDelay2_DSTATE_gllvyya5a = measure_B.Switch_p0ny3pkqp;
  measure_DWork.UnitDelay4_DSTATE_otwsjgetko = measure_B.MathFunction_l;
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah = measure_B.Switch_p0ny3pkqpe;
  measure_DWork.UnitDelay4_DSTATE_otwsjgetkod = measure_B.MathFunction1_m;
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0 = measure_B.Switch_p0ny3pkqpey;
  measure_DWork.UnitDelay4_DSTATE_otwsjgetkod3 = measure_B.MathFunction1_m;
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0l = measure_B.Switch_p0ny3pkqpeyo;
  measure_DWork.UnitDelay1_DSTATE_h = measure_U.IabcAmps[0];
  measure_DWork.UnitDelay2_DSTATE_gp = rtb_UnitDelay1_l;
  measure_DWork.UnitDelay4_DSTATE_jn = measure_B.Product_i[0];
  measure_DWork.UnitDelay2_DSTATE_n = measure_B.Switch_b;
  measure_DWork.UnitDelay4_DSTATE_jnq = measure_B.Product_i[0];
  measure_DWork.UnitDelay2_DSTATE_np = measure_B.Switch_b2;
  measure_DWork.UnitDelay4_DSTATE_jnq1 = measure_B.Divide_ja;
  measure_DWork.UnitDelay2_DSTATE_npj = measure_B.Switch_b2j;
  measure_DWork.UnitDelay4_DSTATE_jnq1h = measure_B.Divide_ja;
  measure_DWork.UnitDelay2_DSTATE_npjj = measure_B.Switch_b2jb;
  measure_DWork.UnitDelay4_DSTATE_jnq1hm = measure_B.Product_i[1];
  measure_DWork.UnitDelay2_DSTATE_npjj1 = measure_B.Switch_b2jbv;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmy = measure_B.Product_i[1];
  measure_DWork.UnitDelay2_DSTATE_npjj1p = measure_B.Switch_b2jbv3;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyq = measure_B.Divide_jah;
  measure_DWork.UnitDelay2_DSTATE_npjj1pt = measure_B.Switch_b2jbv30;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqy = measure_B.Divide_jah;
  measure_DWork.UnitDelay2_DSTATE_npjj1ptk = measure_B.Switch_b2jbv30z;
  measure_DWork.UnitDelay1_DSTATE_ou = measure_U.IabcAmps[1];
  measure_DWork.UnitDelay2_DSTATE_f = rtb_UnitDelay1_f;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya = measure_B.Product_io[0];
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkd = measure_B.Switch_b2jbv30zm;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1 = measure_B.Product_io[0];
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkda = measure_B.Switch_b2jbv30zmv;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1i = measure_B.Divide_jahf;
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf = measure_B.Switch_b2jbv30zmvu;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1it = measure_B.Divide_jahf;
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2 = measure_B.Switch_b2jbv30zmvus;
  measure_DWork.UnitDelay4_DSTAT_jnq1hmyqya1it1 = measure_B.Product_io[1];
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2v = measure_B.Switch_b2jbv30zmvusn;
  measure_DWork.UnitDelay4_DSTA_jnq1hmyqya1it1v = measure_B.Product_io[1];
  measure_DWork.UnitDelay2_DSTAT_npjj1ptkdaf2v0 =
    measure_B.Switch_b2jbv30zmvusna;
  measure_DWork.UnitDelay4_DSTA_p = measure_B.Divide_jahfx;
  measure_DWork.UnitDelay2_DSTA_npjj1ptkdaf2v0r =
    measure_B.Switch_b2jbv30zmvusnaw;
  measure_DWork.UnitDelay4_DSTA_o = measure_B.Divide_jahfx;
  measure_DWork.UnitDelay2_DSTA_i = measure_B.Switch_n;
  measure_DWork.UnitDelay1_DSTATE_bn = measure_U.IabcAmps[2];
  measure_DWork.UnitDelay2_DSTATE_b = rtb_UnitDelay1_lu;
  measure_DWork.UnitDelay4_DSTA_k = measure_B.Product_io0[0];
  measure_DWork.UnitDelay2_DSTA_g = measure_B.Switch_lf;
  measure_DWork.UnitDelay4_DSTA_c = measure_B.Product_io0[0];
  measure_DWork.UnitDelay2_DSTA_n = measure_B.Switch_jcx;
  measure_DWork.UnitDelay4_DSTA_d = measure_B.Divide_jahfx5;
  measure_DWork.UnitDelay2_DSTA_k = measure_B.Switch_e;
  measure_DWork.UnitDelay4_DSTA_h = measure_B.Divide_jahfx5;
  measure_DWork.UnitDelay2_DSTA_p = measure_B.Switch_bd;
  measure_DWork.UnitDelay4_DSTA_f = measure_B.Product_io0[1];
  measure_DWork.UnitDelay2_DSTA_ip = measure_B.Switch_c;
  measure_DWork.UnitDelay4_DSTA_o2 = measure_B.Product_io0[1];
  measure_DWork.UnitDelay2_DSTA_h = measure_B.Switch_d5;
  measure_DWork.UnitDelay4_DSTA_cq = measure_B.Divide_jahfx50;
  measure_DWork.UnitDelay2_DSTA_pl = measure_B.Switch_ik;
  measure_DWork.UnitDelay4_DSTA_a = measure_B.Divide_jahfx50;
  measure_DWork.UnitDelay2_DSTA_c = measure_B.Switch_nb;
  measure_DWork.UnitDelay4_DSTA_n = measure_B.MathFunction_k;
  measure_DWork.UnitDelay2_DSTA_o = measure_B.Switch_o;
  measure_DWork.UnitDelay4_DSTA_i = measure_B.MathFunction_k;
  measure_DWork.UnitDelay2_DSTA_f = measure_B.Switch_oo;
  measure_DWork.UnitDelay4_DSTA_j = measure_B.MathFunction1_g;
  measure_DWork.UnitDelay2_DSTA_j = measure_B.Switch_g;
  measure_DWork.UnitDelay4_DSTA_jj = measure_B.MathFunction1_g;
  measure_DWork.UnitDelay2_DSTA_ic = measure_B.Switch_pp;
  measure_DWork.UnitDelay4_DSTA_dk = measure_B.MathFunction_k5;
  measure_DWork.UnitDelay2_DSTA_hv = measure_B.Switch_cx;
  measure_DWork.UnitDelay4_DSTA_dx = measure_B.MathFunction_k5;
  measure_DWork.UnitDelay2_DSTA_l = measure_B.Switch_ixo;
  measure_DWork.UnitDelay4_DSTA_kd = measure_B.MathFunction1_ge;
  measure_DWork.UnitDelay2_DSTA_m = measure_B.Switch_ek;
  measure_DWork.UnitDelay4_DSTA_dr = measure_B.MathFunction1_ge;
  measure_DWork.UnitDelay2_DSTA_lr = measure_B.Switch_j3;
  measure_DWork.UnitDelay4_DSTA_ny = measure_B.MathFunction_k5t;
  measure_DWork.UnitDelay2_DSTA_oy = measure_B.Switch_a;
  measure_DWork.UnitDelay4_DSTA_k1 = measure_B.MathFunction_k5t;
  measure_DWork.UnitDelay2_DSTA_a = measure_B.Switch_d0;
  measure_DWork.UnitDelay4_DSTA_ip = measure_B.MathFunction1_ge3;
  measure_DWork.UnitDelay2_DSTA_ay = measure_B.Switch_h;
  measure_DWork.UnitDelay4_DSTA_hx = measure_B.MathFunction1_ge3;
  measure_DWork.UnitDelay2_DSTA_la = measure_B.Switch_it;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputh = rtb_FixPtSum1_m;
  measure_DWork.delay_DSTATE_e = rtb_Compare_c2o;
  measure_DWork.UnitDelay_DSTATE_im = rtb_Switch1_bx;
  measure_DWork.UnitDelay_DSTATE_imt = rtb_LogicalOperator1_b2ck;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputhx = rtb_FixPtSum1_go;
  measure_DWork.UnitDelay_DSTATE_imt2 = measure_P.Constant_Value_civ2qn;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputhxn = rtb_FixPtSum1_g;
  measure_DWork.UnitDelay4_DSTATE_krxzyrko = measure_B.ACripple1stestimate;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm = measure_B.Switch_iwl;
  measure_DWork.UnitDelay4_DSTATE_krxzyrkob = measure_B.ACripple1stestimate;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2 = measure_B.Switch_iwlt;
  measure_DWork.UnitDelay1_DSTATE_om = rtb_Gain1_kh;
  measure_DWork.UnitDelay_DSTATE_ehbx = rtb_Switch_iwltec;
  measure_DWork.UnitDelay2_DSTAT_lscnp0r3jm2b3r = rtb_LogicalOperator9;
  measure_DWork.UnitDelay_DSTATE_eh = rtb_Switch_l40f + rtb_Divide_j;
  measure_DWork.delay_DSTATE_n0 = rtb_LogicalOperator16;
  measure_DWork.delay1_DSTATE_fk = rtb_LogicalOperator16;
  measure_DWork.UnitDelay_DSTATE_ehbxxq = measure_P.Constant_Value_dso;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b = rtb_Switch2_a;
  measure_DWork.UnitDelay1_DSTATE_omt = rtb_Unbalance;
  measure_DWork.UnitDelay1_DSTATE_omtd = rtb_Divide_ny;
  measure_DWork.UnitDelay4_DSTATE_krxzyrkobe = rtb_Divide_ny;
  measure_DWork.UnitDelay1_DSTATE_omtd1 = rtb_MinMax1;
  measure_DWork.UnitDelay1_DSTATE_omtd1h = rtb_Divide_n;
  measure_DWork.UnitDelay1_DSTATE_omtd1hd = rtb_Divide_jw;
  measure_DWork.UnitDelay_DSTATE_ehbxx = rtb_Switch1_gmkuez3woc;
  measure_DWork.UnitDelay1_DSTATE_hf = rtb_UnitDelay1_k;
  measure_DWork.delay_DSTATE_o = rtb_Any_Phases_Not_Disturbed;
  measure_DWork.UnitDelay_DSTATE_cx = rtb_Switch1_kn;
  measure_DWork.UnitDelay_DSTATE_jqi = rtb_LogicalOperator2_m;
  measure_DWork.UnitDelay1_DSTATE_cx = rtb_FixPtSum1_h;
  measure_DWork.UnitDelay_DSTATE_l = measure_P.Constant_Value_mr;
  measure_DWork.UnitDelay1_DSTATE_d5 = rtb_FixPtSum1_l;
  measure_DWork.UnitDelay3_DSTATE_pg = rtb_TrigonometricFunction_l;
  measure_DWork.UnitDelay3_DSTATE_pzl = rtb_TrigonometricFunction_c;
  measure_DWork.UnitDelay3_DSTATE_ot = rtb_TrigonometricFunction_b;
  measure_DWork.UnitDelay4_DSTATE_cvz = measure_B.ACripple1stestimate_f;
  measure_DWork.UnitDelay2_DSTATE_dgh = measure_B.Switch_iln5;
  measure_DWork.UnitDelay4_DSTATE_cvzr = measure_B.ACripple1stestimate_f;
  measure_DWork.UnitDelay2_DSTATE_dghn = measure_B.Switch_iln5l;
  measure_DWork.UnitDelay1_DSTATE_k = rtb_UnaryMinus_p;
  measure_DWork.UnitDelay_DSTATE_jm = rtb_UnitDelay1_n0;
  measure_DWork.UnitDelay2_DSTATE_ocn = rtb_LogicalOperator1_f;
  measure_DWork.UnitDelay_DSTATE_c = (rtb_AbsVI * rtb_Divide_h) +
    rtb_Switch1_kt5c;
  measure_DWork.delay_DSTATE_ep = rtb_LogicalOperator2_b0;
  measure_DWork.delay1_DSTATE_l5 = rtb_LogicalOperator2_b0;
  measure_DWork.UnitDelay_DSTATE_jmcy = measure_P.Constant_Value_gbvuwpgu2kml14;
  measure_DWork.UnitDelay2_DSTATE_oc = rtb_Switch1_m;
  measure_DWork.UnitDelay1_DSTATE_gr = rtb_AbsVI;
  measure_DWork.UnitDelay1_DSTATE_grk = rtb_Product_i;
  measure_DWork.UnitDelay4_DSTATE_a = rtb_Product_i;
  measure_DWork.UnitDelay1_DSTATE_grkf = rtb_Add1_h_idx_0;
  measure_DWork.UnitDelay1_DSTATE_j = rtb_MathFunction1;
  measure_DWork.UnitDelay1_DSTATE_d = rtb_Switch;
  measure_DWork.UnitDelay_DSTATE_jmc = rtb_Switch1_bxh;
}

void measureModelClass::initialize()
{
  rt_InitInfAndNaN(sizeof(real_T));
  (void) memset(((void *) &measure_B), 0,
                sizeof(BlockIO_measure));
  (void) memset((void *)&measure_DWork, 0,
                sizeof(D_Work_measure));
  (void) memset((void *)&measure_U, 0,
                sizeof(ExternalInputs_measure));
  (void) memset((void *)&measure_Y, 0,
                sizeof(ExternalOutputs_measure));

  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfuncti_c3[0];
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_i;
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunction_;
    int_T i;
    for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfunctio_g; i++)
      VDD_buffer[i] = measure_P.SF_FixedDiscreteDelaySfunction_;
    xD[0] = measure_P.SF_FixedDiscreteDelaySfunction_;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfunctio_l[0];
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_e;
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_c;
    int_T i;
    for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfuncti_o0; i++)
      VDD_buffer[i] = measure_P.SF_FixedDiscreteDelaySfunctio_o;
    xD[0] = measure_P.SF_FixedDiscreteDelaySfunctio_o;
    *VDD_in = 0;
  }

  measure_DWork.clockTickCounter = 0;
  measure_DWork.clockTickCounter_f = 0;

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneTap[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_pz;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTap+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_i[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_pzv;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_n+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoTap[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_m;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTap+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_iq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_pzv4;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_ne+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_iqv[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_pzv45;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_nes+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_b[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_mw;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_n+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_iqvv[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_pzv45h;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_nesm+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_iqvvo[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_pzv45hn;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_nesmw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_bq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_mw3;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_ne+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  measure_DWork.clockTickCounter_n = 0;

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_iqvvod[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_pzv45hn0;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_e+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_iqvvods[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_pzv45hn0c;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_ep+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_bqv[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_mw3l;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_e+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  measure_DWork.clockTickCounter_e = 0;

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_f[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_hg;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_b+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_f2[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_hgo;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_bl+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_a[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_o;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_b+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_f2j[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_hgow;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_bln+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_f2jg[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_hgowj;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_bln4+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_ab[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_oc;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_bl+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_f2jgc[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_hgowjf;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_ez+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_f2jgc1[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_hgowjfv;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_ezn+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_ab4[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_oci;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_ez+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_f2jgc1y[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_hgowjfvn;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_eznc+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_f2jgc1yy[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_hgowjfvnn;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_ezncl+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_ab4s[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_oci4;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_ezn+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_f2jgc1yyu[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_hgowjfvnnx;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_e0+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_f2jgc1yyuf[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_hgowjfvnnxz;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_e0r+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_ab4s3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_oci4c;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_e0+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_f2jgc1yyufb[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_hgowjfvnnxzl;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_e0r1+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_f2jgc1yyufbl[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_hgowjfvnnxzlo;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_e0r1h+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_ab4s3q[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_oci4cw;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_e0r+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  measure_DWork.clockTickCounter_ey = 0;
  measure_DWork.clockTickCounter_ey4 = 0;

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_f2jgc1yyufbl2[0];
    int_T *VDD_in = &measure_DWork.VariableDiscrete_hgowjfvnnxzloq;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_bln4d+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_f2jgc1yyufbl2v[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_hgowjfvnnxzloqs;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_bln4dj+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_ab4s3ql[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_oci4cw4;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_bln+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f2jgc1yyufbl2vd[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pkx;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_bln4djb+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_d[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_lw;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_bln4djb4+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_ab4s3qlk[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_oci4cw4v;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_bln4+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_g[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_kq;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_h+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ak;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_hk+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_ab4s3qlk5[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_oci4cw4vl;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_h+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.SF_FixedDiscreteDelaySfunctio_j[0];
    int_T *VDD_in = &measure_DWork.SF_FixedDiscreteDelaySfunctio_h;
    real_T *xD = &measure_DWork.SF_FixedDiscreteDelaySfunctio_a;
    int_T i;
    for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfuncti_ic; i++)
      VDD_buffer[i] = measure_P.SF_FixedDiscreteDelaySfunctio_i;
    xD[0] = measure_P.SF_FixedDiscreteDelaySfunctio_i;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_bgs;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_eznclc+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c1[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_cv;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_eznclc5+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_ab4s3qlk5c[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_oci4cw4vlo;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_eznc+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gf[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_j3;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_eznclc5x+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_p[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_fr;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_eznclc5xg+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_ab4s3qlk5cc[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_oci4cw4vloz;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_eznclc5xg5+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_cr[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ny;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_h0+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_e[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_gs3;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_h0u+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_ab4s3qlk5cc4[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_oci4cw4vloz5;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_p+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_b[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_lz;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_e0r1hm+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_n[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_jl;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_e0r1hmw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_ab4s3qlk5cc4j[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_oci4cw4vloz5b;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_e0r1+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gp[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ev;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_e0r1hmwt+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_i[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_edt;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_e0r1hmwtw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_ab4s3qlk5cc4jf[0];
    int_T *VDD_in = &measure_DWork.VariableDiscrete_oci4cw4vloz5bs;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_e0r1hmwtwq+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_jh;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_m+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_mm[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_bm;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_mo+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ab4s3qlk5cc4jfr[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_oci4cw4vloz5bse;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_en+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  measure_DWork.clockTickCounter_ed = 0;

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_p[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOneT_c;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_i+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_pb[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_cj;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_ii+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_g[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_os;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_i+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_i3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_bq;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_bln4djb4g+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_fqs;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_bln4djb4gs+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gg[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_mu;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_bln4djb4gs5+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ex[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_mr;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_bln4djb4gs54+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_aj[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_eb;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_bln4djb4gs54q+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_aq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_oe;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_bln4djb4gs54qg+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_no[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ib;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_eznclc5xg5q+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_f5[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pz;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_eznclc5xg5q1+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ef[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pei;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_eznclc5xg5q1u+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ed[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_fy;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_eznclc5xg5q1ug+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a0[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ej;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_eznclc5xg5q1ugj+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pk[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_nc;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_k+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_dk[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_hf;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_e0r1hmwtwqc+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_o[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_a2;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_e0r1hmwtwqc2+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gs[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pl;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_e0r1hmwtwqc2e+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_bt[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_av;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_e0r1hmwtwqc2ev+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_e0[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_dg;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_e0r1hmwtwqc2evm+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_l[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_lwr;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_kl+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOneT_h[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOneT_e;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_o+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOne_hk[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOne_et;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_of+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_h[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwoT_p;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_o+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_hkv[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_etx;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_ofa+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_hkvl[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_etx1;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_ofaw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_hj[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTwo_pv;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_of+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_hkvl3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_etx1w;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_ofawr+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_hkvl35[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_etx1wx;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_ofawrz+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_hjq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_pv2;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_ofa+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_hkvl35c[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_etx1wxm;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_ofawrzy+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_hkvl35cs[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_etx1wxmc;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_ofawrzyw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_hjqf[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithT_pv2z;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_ofaw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_hkvl35css[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_etx1wxmcb;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_ofawrzywp+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_hkvl35cssz[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_etx1wxmcbv;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_ofawrzywpv+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_hjqfc[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_pv2zv;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_ofawrzywpvf+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_hkvl35cssz3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_etx1wxmcbvv;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_ofawrzywpvfx+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_hkvl35cssz3u[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_etx1wxmcbvvw;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_ofawrzywpvfxm+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_hjqfcq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywit_pv2zv2;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_ofawrzywpvfxm1+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_hkvl35cssz3uy[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_etx1wxmcbvvwx;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ofawrzywpvfxm1r+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_hkvl35cssz3uyo[0];
    int_T *VDD_in = &measure_DWork.VariableDiscrete_etx1wxmcbvvwx0;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_l+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_hjqfcqw[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywi_pv2zv24;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_h+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_hkvl35cssz3uyos[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_etx1wxmcbvvwx03;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_n+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a02[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ls;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_hy+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_hjqfcqwr[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelayw_pv2zv24n;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_i+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_iy[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_l3;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_iy+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ad[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_lb;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ku+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_hjqfcqwrz[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelay_pv2zv24nx;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_kuf+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m1[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_a2h;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_a+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_g0[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_cm;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_k3+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_hjqfcqwrzc[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_pv2zv24nxp;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_aa+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_j[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pc;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_o+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ox[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_am;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_d+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_hjqfcqwrzc3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_pv2zv24nxpe;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_k35+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_m0[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_g05;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_f+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_fq[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_f4;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_g+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_hjqfcqwrzc31[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDe_pv2zv24nxpeb;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ow+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ep[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_jx;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_fo+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_cp[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_kc;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_hi+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_hjqfcqwrzc31p[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteD_pv2zv24nxpebh;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_db+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_h[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ld;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_iw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_c4[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_dd;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_b+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_hjqfcqwrzc31p3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscrete_pv2zv24nxpebhu;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ff+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_jw[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_hx;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_or+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_bg[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ok;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_bv+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_hjqfcqwrzc31p34[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_pv2zv24nxpebhui;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ga+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_on[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_iv;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_j+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_nr[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_gw;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_c+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_om[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_ou;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_foe+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pe[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_c2;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_p+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_k[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_au;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_cu+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_mf[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_l4;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_hin+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_p3[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_l5;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_bq+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_me[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_hd;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_f4+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_onk[0];
    int_T *VDD_in = &measure_DWork.VariableDiscret_fe;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_iwf+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_iqvvodsl[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDela_pzv45hn0c0;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_epw+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_iqvvodsli[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDel_pzv45hn0c03;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_epwu+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_bqvb[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywith_mw3lz;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_ep+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithOn_pbu[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithOn_cjw;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_ii1+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithO_pbur[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithO_cjwa;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_ii12+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_g0[0];
    int_T *VDD_in = &measure_DWork.VariableDiscreteDelaywithTw_oss;
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_ii+1); i++)
      VDD_buffer[i] = 0.0;
    *VDD_in = 0;
  }

  measure_DWork.UnitDelay4_DSTATE_ep = measure_P.UnitDelay4_X0_oc;
  measure_DWork.delay_DSTATE = measure_P.delay_X0;
  measure_DWork.UnitDelay_DSTATE = measure_P.UnitDelay_X0;
  measure_DWork.UnitDelay4_DSTATE_krxzyrkobej = measure_P.UnitDelay4_X0_ci;
  measure_DWork.delay_DSTATE_b = measure_P.delay_X0_o;
  measure_DWork.UnitDelay_DSTATE_i = measure_P.UnitDelay_X0_o;
  measure_DWork.UnitDelay_DSTATE_e = measure_P.UnitDelay_X0_j;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b3 = measure_P.UnitDelay2_X0_ek;
  measure_DWork.delay1_DSTATE = measure_P.delay1_X0;
  measure_DWork.delay1_DSTATE_l = measure_P.delay1_X0_h;
  measure_DWork.UnitDelay3_DSTATE = measure_P.UnitDelay3_X0;
  measure_DWork.UnitDelay1_DSTATE = measure_P.UnitDelay1_X0;
  measure_DWork.UnitDelay2_DSTATE = measure_P.UnitDelay2_X0;
  measure_DWork.UnitDelay1_DSTATE_i = measure_P.UnitDelay1_X0_i;
  measure_DWork.UnitDelay2_DSTATE_a = measure_P.UnitDelay2_X0_l;
  measure_DWork.UnitDelay1_DSTATE_b = measure_P.UnitDelay1_X0_e;
  measure_DWork.UnitDelay2_DSTATE_c = measure_P.UnitDelay2_X0_g;
  measure_DWork.UnitDelay4_DSTATE = measure_P.UnitDelay4_X0;
  measure_DWork.UnitDelay2_DSTATE_l = measure_P.UnitDelay2_X0_n;
  measure_DWork.delay_DSTATE_i = measure_P.delay_X0_h;
  measure_DWork.UnitDelay4_DSTATE_k = measure_P.UnitDelay4_X0_n;
  measure_DWork.UnitDelay2_DSTATE_ls = measure_P.UnitDelay2_X0_ne;
  measure_DWork.UnitDelay4_DSTATE_kr = measure_P.UnitDelay4_X0_ne;
  measure_DWork.UnitDelay2_DSTATE_lsc = measure_P.UnitDelay2_X0_nes;
  measure_DWork.delay_DSTATE_i2 = measure_P.delay_X0_hp;
  measure_DWork.UnitDelay4_DSTATE_krx = measure_P.UnitDelay4_X0_nes;
  measure_DWork.UnitDelay2_DSTATE_lscn = measure_P.UnitDelay2_X0_nesm;
  measure_DWork.UnitDelay4_DSTATE_krxz = measure_P.UnitDelay4_X0_nesm;
  measure_DWork.UnitDelay2_DSTATE_lscnp = measure_P.UnitDelay2_X0_nesmw;
  measure_DWork.UnitDelay4_DSTATE_krxzy = measure_P.UnitDelay4_X0_nesmw;
  measure_DWork.UnitDelay2_DSTATE_lscnp0 = measure_P.UnitDelay2_X0_nesmwp;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdp = measure_P.UnitDelay1_X0_f;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdpu = measure_P.UnitDelay1_X0_fk;
  measure_DWork.delay1_DSTATE_f = measure_P.delay1_X0_e;
  measure_DWork.UnitDelay4_DSTATE_krxzyr = measure_P.UnitDelay4_X0_e;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r = measure_P.UnitDelay2_X0_e;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3 = measure_P.UnitDelay2_X0_ep;
  measure_DWork.delay_DSTATE_n = measure_P.delay_X0_e;
  measure_DWork.UnitDelay4_DSTATE_krxzyrk = measure_P.UnitDelay4_X0_ep;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3j = measure_P.UnitDelay2_X0_epw;
  measure_DWork.UnitDelay_DSTATE_ehb = measure_P.UnitDelay_X0_ep;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdput = measure_P.UnitDelay1_X0_fkx;
  measure_DWork.UnitDelay1_DSTATE_gf = measure_P.UnitDelay1_X0_fo;
  measure_DWork.UnitDelay2_DSTATE_h = measure_P.UnitDelay2_X0_nc;
  measure_DWork.UnitDelay4_DSTATE_ii = measure_P.UnitDelay4_X0_ol;
  measure_DWork.UnitDelay1_DSTATE_m4 = measure_P.UnitDelay1_X0_l3;
  measure_DWork.delay1_DSTATE_n = measure_P.delay1_X0_a;
  measure_DWork.UnitDelay_DSTATE_f = measure_P.UnitDelay_X0_a;
  measure_DWork.UnitDelay4_DSTATE_j = measure_P.UnitDelay4_X0_b;
  measure_DWork.UnitDelay2_DSTATE_lj = measure_P.UnitDelay2_X0_b;
  measure_DWork.delay_DSTATE_c = measure_P.delay_X0_a;
  measure_DWork.UnitDelay4_DSTATE_js = measure_P.UnitDelay4_X0_bl;
  measure_DWork.UnitDelay2_DSTATE_ljf = measure_P.UnitDelay2_X0_bl;
  measure_DWork.UnitDelay4_DSTATE_js0 = measure_P.UnitDelay4_X0_bln;
  measure_DWork.UnitDelay2_DSTATE_ljfw = measure_P.UnitDelay2_X0_bln;
  measure_DWork.UnitDelay4_DSTATE_js0g = measure_P.UnitDelay4_X0_bln4;
  measure_DWork.UnitDelay2_DSTATE_ljfwk = measure_P.UnitDelay2_X0_bln4;
  measure_DWork.UnitDelay1_DSTATE_j4 = measure_P.UnitDelay1_X0_j;
  measure_DWork.UnitDelay4_DSTATE_e = measure_P.UnitDelay4_X0_ez;
  measure_DWork.UnitDelay2_DSTATE_ab = measure_P.UnitDelay2_X0_ez;
  measure_DWork.UnitDelay4_DSTATE_e1 = measure_P.UnitDelay4_X0_ezn;
  measure_DWork.UnitDelay2_DSTATE_abj = measure_P.UnitDelay2_X0_ezn;
  measure_DWork.UnitDelay4_DSTATE_e10 = measure_P.UnitDelay4_X0_eznc;
  measure_DWork.UnitDelay2_DSTATE_abju = measure_P.UnitDelay2_X0_eznc;
  measure_DWork.UnitDelay4_DSTATE_e10c = measure_P.UnitDelay4_X0_ezncl;
  measure_DWork.UnitDelay2_DSTATE_abju3 = measure_P.UnitDelay2_X0_ezncl;
  measure_DWork.UnitDelay1_DSTATE_g0 = measure_P.UnitDelay1_X0_ex;
  measure_DWork.UnitDelay4_DSTATE_o = measure_P.UnitDelay4_X0_e0;
  measure_DWork.UnitDelay2_DSTATE_g = measure_P.UnitDelay2_X0_e0;
  measure_DWork.UnitDelay4_DSTATE_ot = measure_P.UnitDelay4_X0_e0r;
  measure_DWork.UnitDelay2_DSTATE_gl = measure_P.UnitDelay2_X0_e0r;
  measure_DWork.UnitDelay4_DSTATE_otw = measure_P.UnitDelay4_X0_e0r1;
  measure_DWork.UnitDelay2_DSTATE_gll = measure_P.UnitDelay2_X0_e0r1;
  measure_DWork.UnitDelay4_DSTATE_otws = measure_P.UnitDelay4_X0_e0r1h;
  measure_DWork.UnitDelay2_DSTATE_gllv = measure_P.UnitDelay2_X0_e0r1h;
  measure_DWork.delay1_DSTATE_nm = measure_P.delay1_X0_ad;
  measure_DWork.UnitDelay3_DSTATE_p = measure_P.UnitDelay3_X0_k;
  measure_DWork.delay1_DSTATE_nmq = measure_P.delay1_X0_adh;
  measure_DWork.UnitDelay4_DSTATE_js0g0 = measure_P.UnitDelay4_X0_bln4d;
  measure_DWork.UnitDelay2_DSTATE_ljfwkl = measure_P.UnitDelay2_X0_bln4d;
  measure_DWork.delay_DSTATE_ci = measure_P.delay_X0_ad;
  measure_DWork.UnitDelay4_DSTATE_js0g0x = measure_P.UnitDelay4_X0_bln4dj;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf = measure_P.UnitDelay2_X0_bln4dj;
  measure_DWork.UnitDelay4_DSTATE_js0g0xc = measure_P.UnitDelay4_X0_bln4djb;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5 = measure_P.UnitDelay2_X0_bln4djb;
  measure_DWork.UnitDelay4_DSTATE_js0g0xck = measure_P.UnitDelay4_X0_bln4djb4;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5t = measure_P.UnitDelay2_X0_bln4djb4;
  measure_DWork.UnitDelay4_DSTATE_i = measure_P.UnitDelay4_X0_d;
  measure_DWork.UnitDelay2_DSTATE_l1 = measure_P.UnitDelay2_X0_d;
  measure_DWork.delay_DSTATE_cir = measure_P.delay_X0_adh;
  measure_DWork.UnitDelay4_DSTATE_iv = measure_P.UnitDelay4_X0_d1;
  measure_DWork.UnitDelay2_DSTATE_l1a = measure_P.UnitDelay2_X0_d1;
  measure_DWork.UnitDelay1_DSTATE_c = measure_P.UnitDelay1_X0_l5;
  measure_DWork.UnitDelay_DSTATE_b = measure_P.UnitDelay_X0_ci1;
  measure_DWork.UnitDelay1_DSTATE_n = measure_P.UnitDelay1_X0_c;
  measure_DWork.UnitDelay_DSTATE_h = measure_P.UnitDelay_X0_h;
  measure_DWork.UnitDelay1_DSTATE_nr = measure_P.UnitDelay1_X0_ci;
  measure_DWork.UnitDelay1_DSTATE_m = measure_P.UnitDelay1_X0_b;
  measure_DWork.UnitDelay_DSTATE_j = measure_P.UnitDelay_X0_gq;
  measure_DWork.UnitDelay1_DSTATE_g = measure_P.UnitDelay1_X0_ez;
  measure_DWork.UnitDelay_DSTATE_jq = measure_P.UnitDelay_X0_gqo;
  measure_DWork.UnitDelay1_DSTATE_o = measure_P.UnitDelay1_X0_e0;
  measure_DWork.UnitDelay_DSTATE_jqs = measure_P.UnitDelay_X0_gqop;
  measure_DWork.UnitDelay1_DSTATE_cf = measure_P.UnitDelay1_X0_f0;
  measure_DWork.UnitDelay_DSTATE_md = measure_P.UnitDelay_X0_hg;
  measure_DWork.UnitDelay1_DSTATE_e = measure_P.UnitDelay1_X0_hg;
  measure_DWork.UnitDelay_DSTATE_g = measure_P.UnitDelay_X0_g;
  measure_DWork.UnitDelay1_DSTATE_ep = measure_P.UnitDelay1_X0_hg0;
  measure_DWork.UnitDelay1_DSTATE_or = measure_P.UnitDelay1_X0_k;
  measure_DWork.UnitDelay_DSTATE_cn = measure_P.UnitDelay_X0_gu;
  measure_DWork.UnitDelay1_DSTATE_ir = measure_P.UnitDelay1_X0_gu;
  measure_DWork.UnitDelay_DSTATE_d = measure_P.UnitDelay_X0_m;
  measure_DWork.UnitDelay1_DSTATE_irs = measure_P.UnitDelay1_X0_gun;
  measure_DWork.UnitDelay3_DSTATE_pz = measure_P.UnitDelay3_X0_c;
  measure_DWork.UnitDelay4_DSTATE_e10ck = measure_P.UnitDelay4_X0_eznclc;
  measure_DWork.UnitDelay2_DSTATE_abju3r = measure_P.UnitDelay2_X0_eznclc;
  measure_DWork.UnitDelay4_DSTATE_e10ck0 = measure_P.UnitDelay4_X0_eznclc5;
  measure_DWork.UnitDelay2_DSTATE_abju3rc = measure_P.UnitDelay2_X0_eznclc5;
  measure_DWork.UnitDelay4_DSTATE_e10ck0c = measure_P.UnitDelay4_X0_eznclc5x;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3 = measure_P.UnitDelay2_X0_eznclc5x;
  measure_DWork.UnitDelay4_DSTATE_e10ck0ct = measure_P.UnitDelay4_X0_eznclc5xg;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3x = measure_P.UnitDelay2_X0_eznclc5xg;
  measure_DWork.UnitDelay4_DSTATE_b = measure_P.UnitDelay4_X0_f;
  measure_DWork.UnitDelay2_DSTATE_k = measure_P.UnitDelay2_X0_f;
  measure_DWork.UnitDelay4_DSTATE_bc = measure_P.UnitDelay4_X0_fj;
  measure_DWork.UnitDelay2_DSTATE_k1 = measure_P.UnitDelay2_X0_fj;
  measure_DWork.UnitDelay3_DSTATE_o = measure_P.UnitDelay3_X0_f;
  measure_DWork.UnitDelay4_DSTATE_otwsj = measure_P.UnitDelay4_X0_e0r1hm;
  measure_DWork.UnitDelay2_DSTATE_gllvy = measure_P.UnitDelay2_X0_e0r1hm;
  measure_DWork.UnitDelay4_DSTATE_otwsjg = measure_P.UnitDelay4_X0_e0r1hmw;
  measure_DWork.UnitDelay2_DSTATE_gllvyy = measure_P.UnitDelay2_X0_e0r1hmw;
  measure_DWork.UnitDelay4_DSTATE_otwsjge = measure_P.UnitDelay4_X0_e0r1hmwt;
  measure_DWork.UnitDelay2_DSTATE_gllvyya = measure_P.UnitDelay2_X0_e0r1hmwt;
  measure_DWork.UnitDelay4_DSTATE_otwsjget = measure_P.UnitDelay4_X0_e0r1hmwtw;
  measure_DWork.UnitDelay2_DSTATE_gllvyya5 = measure_P.UnitDelay2_X0_e0r1hmwtw;
  measure_DWork.UnitDelay4_DSTATE_kw = measure_P.UnitDelay4_X0_g;
  measure_DWork.UnitDelay2_DSTATE_o = measure_P.UnitDelay2_X0_g0;
  measure_DWork.UnitDelay4_DSTATE_kwr = measure_P.UnitDelay4_X0_g0;
  measure_DWork.UnitDelay2_DSTATE_o2 = measure_P.UnitDelay2_X0_g0w;
  measure_DWork.delay1_DSTATE_g = measure_P.delay1_X0_d;
  measure_DWork.UnitDelay4_DSTATE_c = measure_P.UnitDelay4_X0_i;
  measure_DWork.UnitDelay2_DSTATE_d = measure_P.UnitDelay2_X0_i;
  measure_DWork.UnitDelay2_DSTATE_aj = measure_P.UnitDelay2_X0_gy;
  measure_DWork.delay_DSTATE_h = measure_P.delay_X0_d;
  measure_DWork.UnitDelay4_DSTATE_cv = measure_P.UnitDelay4_X0_ii;
  measure_DWork.UnitDelay2_DSTATE_dg = measure_P.UnitDelay2_X0_ii;
  measure_DWork.UnitDelay_DSTATE_m = measure_P.UnitDelay_X0_n;
  measure_DWork.UnitDelay_DSTATE_hs = measure_P.UnitDelay_X0_c;
  measure_DWork.delay1_DSTATE_no = measure_P.delay1_X0_k;
  measure_DWork.UnitDelay1_DSTATE_p = measure_P.UnitDelay1_X0_gd;
  measure_DWork.UnitDelay4_DSTATE_js0g0xcka = measure_P.UnitDelay4_X0_bln4djb4g;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5ta = measure_P.UnitDelay2_X0_bln4djb4g;
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaa =
    measure_P.UnitDelay4_X0_bln4djb4gs;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5tay =
    measure_P.UnitDelay2_X0_bln4djb4gs;
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaam =
    measure_P.UnitDelay4_X0_bln4djb4gs5;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5tayt =
    measure_P.UnitDelay2_X0_bln4djb4gs5;
  measure_DWork.UnitDelay4_DSTATE_js0g0xckaamb =
    measure_P.UnitDelay4_X0_bln4djb4gs54;
  measure_DWork.UnitDelay2_DSTATE_ljfwklf5taytr =
    measure_P.UnitDelay2_X0_bln4djb4gs54;
  measure_DWork.UnitDelay4_DSTATE_e10ck0cti = measure_P.UnitDelay4_X0_eznclc5xg5;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xa =
    measure_P.UnitDelay2_X0_eznclc5xg5;
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctir =
    measure_P.UnitDelay4_X0_eznclc5xg5q;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xak =
    measure_P.UnitDelay2_X0_eznclc5xg5q;
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctirr =
    measure_P.UnitDelay4_X0_eznclc5xg5q1;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku =
    measure_P.UnitDelay2_X0_eznclc5xg5q1;
  measure_DWork.UnitDelay4_DSTATE_e10ck0ctirrv =
    measure_P.UnitDelay4_X0_eznclc5xg5q1u;
  measure_DWork.UnitDelay2_DSTATE_abju3rc3xaku5 =
    measure_P.UnitDelay2_X0_eznclc5xg5q1u;
  measure_DWork.UnitDelay4_DSTATE_otwsjgetk = measure_P.UnitDelay4_X0_e0r1hmwtwq;
  measure_DWork.UnitDelay2_DSTATE_gllvyya5a = measure_P.UnitDelay2_X0_e0r1hmwtwq;
  measure_DWork.UnitDelay4_DSTATE_otwsjgetko =
    measure_P.UnitDelay4_X0_e0r1hmwtwqc;
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah =
    measure_P.UnitDelay2_X0_e0r1hmwtwqc;
  measure_DWork.UnitDelay4_DSTATE_otwsjgetkod =
    measure_P.UnitDelay4_X0_e0r1hmwtwqc2;
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0 =
    measure_P.UnitDelay2_X0_e0r1hmwtwqc2;
  measure_DWork.UnitDelay4_DSTATE_otwsjgetkod3 =
    measure_P.UnitDelay4_X0_e0r1hmwtwqc2e;
  measure_DWork.UnitDelay2_DSTATE_gllvyya5ah0l =
    measure_P.UnitDelay2_X0_e0r1hmwtwqc2e;
  measure_DWork.UnitDelay1_DSTATE_h = measure_P.UnitDelay1_X0_h;
  measure_DWork.UnitDelay2_DSTATE_gp = measure_P.UnitDelay2_X0_c;
  measure_DWork.UnitDelay4_DSTATE_jn = measure_P.UnitDelay4_X0_o;
  measure_DWork.UnitDelay2_DSTATE_n = measure_P.UnitDelay2_X0_o;
  measure_DWork.UnitDelay4_DSTATE_jnq = measure_P.UnitDelay4_X0_of;
  measure_DWork.UnitDelay2_DSTATE_np = measure_P.UnitDelay2_X0_of;
  measure_DWork.UnitDelay4_DSTATE_jnq1 = measure_P.UnitDelay4_X0_ofa;
  measure_DWork.UnitDelay2_DSTATE_npj = measure_P.UnitDelay2_X0_ofa;
  measure_DWork.UnitDelay4_DSTATE_jnq1h = measure_P.UnitDelay4_X0_ofaw;
  measure_DWork.UnitDelay2_DSTATE_npjj = measure_P.UnitDelay2_X0_ofaw;
  measure_DWork.UnitDelay4_DSTATE_jnq1hm = measure_P.UnitDelay4_X0_ofawr;
  measure_DWork.UnitDelay2_DSTATE_npjj1 = measure_P.UnitDelay2_X0_ofawr;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmy = measure_P.UnitDelay4_X0_ofawrz;
  measure_DWork.UnitDelay2_DSTATE_npjj1p = measure_P.UnitDelay2_X0_ofawrz;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyq = measure_P.UnitDelay4_X0_ofawrzy;
  measure_DWork.UnitDelay2_DSTATE_npjj1pt = measure_P.UnitDelay2_X0_ofawrzy;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqy = measure_P.UnitDelay4_X0_ofawrzyw;
  measure_DWork.UnitDelay2_DSTATE_npjj1ptk = measure_P.UnitDelay2_X0_ofawrzyw;
  measure_DWork.UnitDelay1_DSTATE_ou = measure_P.UnitDelay1_X0_l;
  measure_DWork.UnitDelay2_DSTATE_f = measure_P.UnitDelay2_X0_i3;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya = measure_P.UnitDelay4_X0_ofawrzywp;
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkd = measure_P.UnitDelay2_X0_ofawrzywp;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1 =
    measure_P.UnitDelay4_X0_ofawrzywpv;
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkda =
    measure_P.UnitDelay2_X0_ofawrzywpv;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1i =
    measure_P.UnitDelay4_X0_ofawrzywpvf;
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf =
    measure_P.UnitDelay2_X0_ofawrzywpvf;
  measure_DWork.UnitDelay4_DSTATE_jnq1hmyqya1it =
    measure_P.UnitDelay4_X0_ofawrzywpvfx;
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2 =
    measure_P.UnitDelay2_X0_ofawrzywpvfx;
  measure_DWork.UnitDelay4_DSTAT_jnq1hmyqya1it1 =
    measure_P.UnitDelay4_X0_ofawrzywpvfxm;
  measure_DWork.UnitDelay2_DSTATE_npjj1ptkdaf2v =
    measure_P.UnitDelay2_X0_ofawrzywpvfxm;
  measure_DWork.UnitDelay4_DSTA_jnq1hmyqya1it1v =
    measure_P.UnitDelay4_X0_ofawrzywpvfxm1;
  measure_DWork.UnitDelay2_DSTAT_npjj1ptkdaf2v0 =
    measure_P.UnitDelay2_X0_ofawrzywpvfxm1;
  measure_DWork.UnitDelay4_DSTA_p = measure_P.UnitDelay4_X0_ofawrzywpvfxm1r;
  measure_DWork.UnitDelay2_DSTA_npjj1ptkdaf2v0r =
    measure_P.UnitDelay2_X0_ofawrzywpvfxm1r;
  measure_DWork.UnitDelay4_DSTA_o = measure_P.UnitDelay4_X0_l;
  measure_DWork.UnitDelay2_DSTA_i = measure_P.UnitDelay2_X0_lt;
  measure_DWork.UnitDelay1_DSTATE_bn = measure_P.UnitDelay1_X0_d;
  measure_DWork.UnitDelay2_DSTATE_b = measure_P.UnitDelay2_X0_na;
  measure_DWork.UnitDelay4_DSTA_k = measure_P.UnitDelay4_X0_ng;
  measure_DWork.UnitDelay2_DSTA_g = measure_P.UnitDelay2_X0_ng;
  measure_DWork.UnitDelay4_DSTA_c = measure_P.UnitDelay4_X0_h;
  measure_DWork.UnitDelay2_DSTA_n = measure_P.UnitDelay2_X0_h;
  measure_DWork.UnitDelay4_DSTA_d = measure_P.UnitDelay4_X0_iy;
  measure_DWork.UnitDelay2_DSTA_k = measure_P.UnitDelay2_X0_iy;
  measure_DWork.UnitDelay4_DSTA_h = measure_P.UnitDelay4_X0_k;
  measure_DWork.UnitDelay2_DSTA_p = measure_P.UnitDelay2_X0_k;
  measure_DWork.UnitDelay4_DSTA_f = measure_P.UnitDelay4_X0_a;
  measure_DWork.UnitDelay2_DSTA_ip = measure_P.UnitDelay2_X0_a;
  measure_DWork.UnitDelay4_DSTA_o2 = measure_P.UnitDelay4_X0_k3;
  measure_DWork.UnitDelay2_DSTA_h = measure_P.UnitDelay2_X0_k3;
  measure_DWork.UnitDelay4_DSTA_cq = measure_P.UnitDelay4_X0_ow;
  measure_DWork.UnitDelay2_DSTA_pl = measure_P.UnitDelay2_X0_ow;
  measure_DWork.UnitDelay4_DSTA_a = measure_P.UnitDelay4_X0_db;
  measure_DWork.UnitDelay2_DSTA_c = measure_P.UnitDelay2_X0_db;
  measure_DWork.UnitDelay4_DSTA_n = measure_P.UnitDelay4_X0_ff;
  measure_DWork.UnitDelay2_DSTA_o = measure_P.UnitDelay2_X0_ff;
  measure_DWork.UnitDelay4_DSTA_i = measure_P.UnitDelay4_X0_ga;
  measure_DWork.UnitDelay2_DSTA_f = measure_P.UnitDelay2_X0_ga;
  measure_DWork.UnitDelay4_DSTA_j = measure_P.UnitDelay4_X0_fo;
  measure_DWork.UnitDelay2_DSTA_j = measure_P.UnitDelay2_X0_fo;
  measure_DWork.UnitDelay4_DSTA_jj = measure_P.UnitDelay4_X0_hi;
  measure_DWork.UnitDelay2_DSTA_ic = measure_P.UnitDelay2_X0_hi;
  measure_DWork.UnitDelay4_DSTA_dk = measure_P.UnitDelay4_X0_iw;
  measure_DWork.UnitDelay2_DSTA_hv = measure_P.UnitDelay2_X0_iw;
  measure_DWork.UnitDelay4_DSTA_dx = measure_P.UnitDelay4_X0_by;
  measure_DWork.UnitDelay2_DSTA_l = measure_P.UnitDelay2_X0_by;
  measure_DWork.UnitDelay4_DSTA_kd = measure_P.UnitDelay4_X0_or;
  measure_DWork.UnitDelay2_DSTA_m = measure_P.UnitDelay2_X0_or;
  measure_DWork.UnitDelay4_DSTA_dr = measure_P.UnitDelay4_X0_bv;
  measure_DWork.UnitDelay2_DSTA_lr = measure_P.UnitDelay2_X0_bv;
  measure_DWork.UnitDelay4_DSTA_ny = measure_P.UnitDelay4_X0_j;
  measure_DWork.UnitDelay2_DSTA_oy = measure_P.UnitDelay2_X0_j;
  measure_DWork.UnitDelay4_DSTA_k1 = measure_P.UnitDelay4_X0_c;
  measure_DWork.UnitDelay2_DSTA_a = measure_P.UnitDelay2_X0_c5;
  measure_DWork.UnitDelay4_DSTA_ip = measure_P.UnitDelay4_X0_p;
  measure_DWork.UnitDelay2_DSTA_ay = measure_P.UnitDelay2_X0_p;
  measure_DWork.UnitDelay4_DSTA_hx = measure_P.UnitDelay4_X0_cu;
  measure_DWork.UnitDelay2_DSTA_la = measure_P.UnitDelay2_X0_cu;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputh = measure_P.UnitDelay1_X0_hn;
  measure_DWork.delay_DSTATE_e = measure_P.delay_X0_c;
  measure_DWork.UnitDelay_DSTATE_im = measure_P.UnitDelay_X0_ci;
  measure_DWork.UnitDelay_DSTATE_imt = measure_P.UnitDelay_X0_civ;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputhx = measure_P.UnitDelay1_X0_civ;
  measure_DWork.UnitDelay_DSTATE_imt2 = measure_P.UnitDelay_X0_civ2;
  measure_DWork.UnitDelay1_DSTATE_omtd1hdputhxn = measure_P.UnitDelay1_X0_civ2;
  measure_DWork.UnitDelay4_DSTATE_krxzyrko = measure_P.UnitDelay4_X0_epw;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm = measure_P.UnitDelay2_X0_epwu;
  measure_DWork.UnitDelay4_DSTATE_krxzyrkob = measure_P.UnitDelay4_X0_epwu;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2 = measure_P.UnitDelay2_X0_epwu2;
  measure_DWork.UnitDelay1_DSTATE_om = measure_P.UnitDelay1_X0_ep;
  measure_DWork.UnitDelay_DSTATE_ehbx = measure_P.UnitDelay_X0_epw;
  measure_DWork.UnitDelay2_DSTAT_lscnp0r3jm2b3r =
    measure_P.UnitDelay2_X0_epwu2gd;
  measure_DWork.UnitDelay_DSTATE_eh = measure_P.UnitDelay_X0_e;
  measure_DWork.delay_DSTATE_n0 = measure_P.delay_X0_ep;
  measure_DWork.delay1_DSTATE_fk = measure_P.delay1_X0_ep;
  measure_DWork.UnitDelay_DSTATE_ehbxxq = measure_P.UnitDelay_X0_epwu2;
  measure_DWork.UnitDelay2_DSTATE_lscnp0r3jm2b = measure_P.UnitDelay2_X0_epwu2g;
  measure_DWork.UnitDelay1_DSTATE_omt = measure_P.UnitDelay1_X0_epw;
  measure_DWork.UnitDelay1_DSTATE_omtd = measure_P.UnitDelay1_X0_epwu;
  measure_DWork.UnitDelay4_DSTATE_krxzyrkobe = measure_P.UnitDelay4_X0_epwu2;
  measure_DWork.UnitDelay1_DSTATE_omtd1 = measure_P.UnitDelay1_X0_epwu2;
  measure_DWork.UnitDelay1_DSTATE_omtd1h = measure_P.UnitDelay1_X0_epwu2g;
  measure_DWork.UnitDelay1_DSTATE_omtd1hd = measure_P.UnitDelay1_X0_epwu2gd;
  measure_DWork.UnitDelay_DSTATE_ehbxx = measure_P.UnitDelay_X0_epwu;
  measure_DWork.UnitDelay1_DSTATE_hf = measure_P.UnitDelay1_X0_hi;
  measure_DWork.delay_DSTATE_o = measure_P.delay_X0_o0;
  measure_DWork.UnitDelay_DSTATE_cx = measure_P.UnitDelay_X0_m4;
  measure_DWork.UnitDelay_DSTATE_jqi = measure_P.UnitDelay_X0_i;
  measure_DWork.UnitDelay1_DSTATE_cx = measure_P.UnitDelay1_X0_m;
  measure_DWork.UnitDelay_DSTATE_l = measure_P.UnitDelay_X0_mr;
  measure_DWork.UnitDelay1_DSTATE_d5 = measure_P.UnitDelay1_X0_n;
  measure_DWork.UnitDelay3_DSTATE_pg = measure_P.UnitDelay3_X0_ka;
  measure_DWork.UnitDelay3_DSTATE_pzl = measure_P.UnitDelay3_X0_p;
  measure_DWork.UnitDelay3_DSTATE_ot = measure_P.UnitDelay3_X0_fw;
  measure_DWork.UnitDelay4_DSTATE_cvz = measure_P.UnitDelay4_X0_ii1;
  measure_DWork.UnitDelay2_DSTATE_dgh = measure_P.UnitDelay2_X0_ii1;
  measure_DWork.UnitDelay4_DSTATE_cvzr = measure_P.UnitDelay4_X0_ii12;
  measure_DWork.UnitDelay2_DSTATE_dghn = measure_P.UnitDelay2_X0_ii12;
  measure_DWork.UnitDelay1_DSTATE_k = measure_P.UnitDelay1_X0_hr;
  measure_DWork.UnitDelay_DSTATE_jm = measure_P.UnitDelay_X0_gb;
  measure_DWork.UnitDelay2_DSTATE_ocn = measure_P.UnitDelay2_X0_gbv;
  measure_DWork.UnitDelay_DSTATE_c = measure_P.UnitDelay_X0_en;
  measure_DWork.delay_DSTATE_ep = measure_P.delay_X0_g;
  measure_DWork.delay1_DSTATE_l5 = measure_P.delay1_X0_g;
  measure_DWork.UnitDelay_DSTATE_jmcy = measure_P.UnitDelay_X0_gbvu;
  measure_DWork.UnitDelay2_DSTATE_oc = measure_P.UnitDelay2_X0_gb;
  measure_DWork.UnitDelay1_DSTATE_gr = measure_P.UnitDelay1_X0_g;
  measure_DWork.UnitDelay1_DSTATE_grk = measure_P.UnitDelay1_X0_gb;
  measure_DWork.UnitDelay4_DSTATE_a = measure_P.UnitDelay4_X0_gb;
  measure_DWork.UnitDelay1_DSTATE_grkf = measure_P.UnitDelay1_X0_gbv;
  measure_DWork.UnitDelay1_DSTATE_j = measure_P.UnitDelay1_X0_hp;
  measure_DWork.UnitDelay1_DSTATE_d = measure_P.UnitDelay1_X0_ea;
  measure_DWork.UnitDelay_DSTATE_jmc = measure_P.UnitDelay_X0_gbv;
}

measureModelClass::measureModelClass()
{
  Parameters_measure measure_P_temp = {
    1.0E-9,
    1.0,
    1.0,
    0.0,
    1.0E-9,
    1.0E-9,
    0.33333333333333331,
    0.33333333333333331,
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
    5760.0,
    0.999999,
    0.499999,
    0.999999,
    0.499999,
    3.90625E-5,
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
    3.90625E-5,
    3.90625E-5,
    -3.90625E-5,
    0.0390625,
    0.0390625,
    -0.0390625,
    100.0,
    100.0,
    12.5,
    0.5,
    -0.0390625,
    12.5,
    100.0,
    0.499999,
    -0.499999,
    1.0,
    0.08,
    0.08,
    0.00015625,
    0.999999,
    0.499999,
    0.999999,
    0.499999,
    4.0E+9,
    4.0E+9,
    0.0,
    0.0,
    7.8125E-5,
    1.0E-9,
    1.0E-9,
    -7.8125E-5,
    0.025,
    0.025,
    0.00015625,
    0.999999,
    0.499999,
    0.05,
    0.05,
    0.00015625,
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
    0.00015625,
    0.999999,
    0.499999,
    0.02,
    0.02,
    0.00015625,
    0.999999,
    0.499999,
    0.14,
    0.14,
    0.00015625,
    0.999999,
    0.499999,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    100.0,
    100.0,
    1.0E-9,
    -3.1415926535897931,
    2037.1832715762603,
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
    2037.1832715762603,
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
    2037.1832715762603,
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
    3.90625E-5,
    3.90625E-5,
    -3.90625E-5,
    0.0390625,
    0.0390625,
    -0.0390625,
    100.0,
    100.0,
    12.5,
    0.5,
    -0.0390625,
    12.5,
    100.0,
    0.499999,
    -0.499999,
    1.0,
    0.08,
    0.08,
    0.00015625,
    0.999999,
    0.499999,
    0.999999,
    0.499999,
    4.0E+9,
    4.0E+9,
    0.0,
    0.0,
    7.8125E-5,
    1.0E-9,
    1.0E-9,
    -7.8125E-5,
    0.0,
    0.0,
    0.0,
    0.0,
    50.0,
    1.0,
    1300.0,
    650.0,
    0.0,
    0.5,
    1.0,
    660.0,
    330.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.5,

    { 0.0, 0.0, 0.0 },

    { 0.0, 0.0, 0.0 },
    -12800.0,
    1.0,
    0.5,
    0.0,
    0.0,
    0.5,
    -12800.0,
    1.0,
    0.5,
    0.57735026918962584,
    0.0,
    0.0,
    0.5,
    -12800.0,
    1.0,
    0.5,
    2.0,
    0.33333333333333331,
    -3.1415926535897931,
    2037.1832715762603,
    0.0,
    0.0,
    0.00015625,
    12800.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    2.0,
    0.00015625,
    12800.0,
    0.0,
    0.0,
    0.0,
    2.0,
    3.90625E-5,
    0.0,
    0.0,
    0.0,
    0.0,
    0.02,
    40743.6654315252,
    180.0,
    5760.0,
    1.0,
    2068.0,
    1034.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.00015625,
    12800.0,
    0.0,
    0.0,
    0.0,
    2.0,
    3.90625E-5,
    0.0,
    5.0,
    0.04,
    1.0E-9,
    50.0,
    1.0,
    1044.0,
    522.0,
    0.0,
    0.5,
    0.00049087385212340522,
    0.0,
    3.1415926535897931,
    25.0,
    0.04,
    2.0,
    0.0,
    0.0,
    0.00015625,
    12800.0,
    0.0,
    0.0,
    0.0,
    2.0,
    3.90625E-5,
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
    3605.0,
    1803.0,
    0.0,
    0.5,
    0.0,
    1.0,
    532.0,
    266.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.5,
    0.00015625,
    12800.0,
    0.0,
    0.0,
    0.0,
    2.0,
    3.90625E-5,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    3.5,
    0.00015625,
    12800.0,
    0.0,
    0.0,
    0.0,
    2.0,
    3.90625E-5,
    0.0,
    0.0,
    6.0,
    0.0,
    0.5,
    0.0,
    12800.0,
    0.02,
    0.0,
    0.3,
    0.0,
    12800.0,
    0.02,
    0.0,
    0.3,
    0.0,
    12800.0,
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
    2068.0,
    1034.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.00015625,
    12800.0,
    0.0,
    0.0,
    0.0,
    2.0,
    3.90625E-5,
    0.0,
    0.04,
    1.0,
    28.0,
    1.2247448713915889,
    0.57735026918962584,
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
    0.33333333333333331,
    0.33333333333333331,
    1.0E-9,
    100.0,
    0.05,
    0.0,
    0.0,
    0.5,
    -12800.0,
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
    -12800.0,
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
    -12800.0,
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
    0.33333333333333331,
    0.33333333333333331,
    1.0E-9,
    100.0,
    0.05,
    0.70710678118654746,
    0.70710678118654746,
    0.70710678118654746,
    0.70710678118654746,
    1.0E-9,
    0.0,
    0.14,
    0.2,
    12800.0,
    12800.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    7.8125E-5,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E+9,
    7.8125E-5,
    0.5,
    0.0,
    0.08,
    0.0,
    1.0,
    0.08,
    -3.90625E-5,
    0.5,
    -0.00049087385212340522,
    1.0,
    0.4,
    -0.00015625,
    0.0,
    12800.0,
    1.0,
    0.0,
    12800.0,
    12800.0,
    0.0,
    -3.1415926535897931,
    12800.0,
    0.0,
    0.019341750860461415,
    0.98065824913953858,
    0.0,
    -3.1415926535897931,
    12800.0,
    0.0,
    0.019341750860461415,
    0.98065824913953858,
    0.0,
    -3.1415926535897931,
    12800.0,
    0.0,
    0.019341750860461415,
    0.98065824913953858,
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
    7.8125E-5,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E+9,
    7.8125E-5,
    0.5,
    0.0,
    0.08,
    0.0,
    1.0,
    0.08,
    -3.90625E-5,
    0.5,
    -0.00049087385212340522,
    1.0,
    0.4,
    -0.00015625,
    0.0,
    12800.0,
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
    1025,
    1025,
    2,
    321,
    321,
    2,
    641,
    641,
    2,
    513,
    513,
    2,
    257,
    257,
    2,
    1794,
    1794,
    2,
    1025,
    1025,
    2,
    256,
    256,
    2,
    321,
    321,
    321,
    2,
    641,
    641,
    641,
    641,
    641,
    641,
    2,
    1025,
    1025,
    1025,
    2,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    2,
    257,
    257,
    257,
    257,
    257,
    257,
    2,
    1794,
    1794,
    1794,
    128,
    257,
    257,
    257,
    257,
    257,
    257,
    1794,
    1794,
    1794,
    257,
    257,
    257,
    257,
    257,
    257,
    1794,
    1794,
    1794,
    2,
    1025,
    1025,
    1025,
    513,
    513,
    513,
    257,
    257,
    257,
    513,
    513,
    513,
    257,
    257,
    257,
    513,
    513,
    513,
    257,
    257,
    257,
    513,
    513,
    513,
    257,
    257,
    257,
    513,
    513,
    513,
    257,
    257,
    257,
    513,
    513,
    513,
    257,
    257,
    257,
    513,
    513,
    513,
    257,
    257,
    257,
    513,
    513,
    513,
    257,
    257,
    257,
    513,
    513,
    513,
    257,
    257,
    257,
    513,
    513,
    513,
    257,
    257,
    257,
    513,
    513,
    513,
    257,
    257,
    257,
    513,
    513,
    513,
    257,
    257,
    257,
    1025,
    1025,
    1025,
    1025,
    1025,
    1025,
    1U,
    385U,
    1U,
    1281U,
    1U,
    2049U,
    1U,
    1U,
    1U,
    1U,
    450U,
    1U,
    1U,
    1U,
    1U,
    1024U,
    1U,
    1U,
    0U,
    1U,
    257U,
    1U,
    1U,
    1U,
    1U,
    577U,
    1U,
    1U,
    1U,
    513U,
    1U,
    1281U,
    1U,
    513U,
    1U,
    1281U,
    1U,
    513U,
    1U,
    1281U,
    1U,
    513U,
    1U,
    1281U,
    1U,
    513U,
    1U,
    1281U,
    1U,
    513U,
    1U,
    1281U,
    1U,
    1U,
    576U,
    1U,
    1U,
    576U,
    1U,
    1U,
    576U,
    1U,
    1U,
    1024U,
    1U,
    513U,
    1U,
    1U,
    1024U,
    1U,
    1U,
    0U,
    1U,
    257U,
    2049U,
    0U,
    1281U,
    0U,
    1U,
    0U,
    385U,
    0U,
    513U,
    513U,
    0U,
    513U,
    0U,
    513U,
    0U,
    1281U,
    0U,
    1281U,
    0U,
    513U,
    0U,
    1U,
    0U,
    1U,
    0U,
    1U,
    0U,
    1281U,
    0U,
    1281U,
    0U,
    513U,
    0U,
    1281U,
    0U,
    1281U,
    0U,
    513U,
    0U,
    1U,
    0U,
    0U,
    1U,
    0U,
    1U,
    1U,
    1U,
    257U,
    0U,
    1U,
    0U,
    0U,
    0U,
    450U,
    0U,
    1U,
    1U,
    0U,
    1U,
    0U,
    1U,
    0U,
    1U,
    257U,
    0U,
    1U,
    0U,
    0U,
    0U,
    577U,
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
  };

  measure_P = measure_P_temp;
}

measureModelClass::~measureModelClass()
{
}

const Parameters_measure & measureModelClass::getBlockParameters() const
{
  return measure_P;
}

void measureModelClass::setBlockParameters(const Parameters_measure *pmeasure_P)
{
  measure_P = *pmeasure_P;
}
