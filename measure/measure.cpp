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

void MWDSPCG_FFT_Interleave_R2BR_D(const real_T x[], creal_T y[], const int32_T
  nChans, const int32_T nRows)
{
  int32_T br_j;
  int32_T yIdx;
  int32_T uIdx;
  int32_T j;
  int32_T nChansBy;
  int32_T bit_fftLen;
  br_j = 0;
  yIdx = 0;
  uIdx = 0;
  for (nChansBy = (nChans >> 1); nChansBy != 0; nChansBy--) {
    for (j = nRows; (j - 1) > 0; j--) {
      y[yIdx + br_j].re = x[uIdx];
      y[yIdx + br_j].im = x[uIdx + nRows];
      uIdx++;
      bit_fftLen = nRows;
      do {
        bit_fftLen = (int32_T)(((uint32_T)bit_fftLen) >> 1);
        br_j ^= bit_fftLen;
      } while (!((br_j & bit_fftLen) != 0));
    }

    y[yIdx + br_j].re = x[uIdx];
    y[yIdx + br_j].im = x[uIdx + nRows];
    uIdx = (uIdx + nRows) + 1;
    yIdx += (nRows << 1);
    br_j = 0;
  }

  if ((nChans & 1) != 0) {
    for (j = (nRows >> 1); (j - 1) > 0; j--) {
      y[yIdx + br_j].re = x[uIdx];
      y[yIdx + br_j].im = x[uIdx + 1];
      uIdx += 2;
      bit_fftLen = (nRows >> 1);
      do {
        bit_fftLen = (int32_T)(((uint32_T)bit_fftLen) >> 1);
        br_j ^= bit_fftLen;
      } while (!((br_j & bit_fftLen) != 0));
    }

    y[yIdx + br_j].re = x[uIdx];
    y[yIdx + br_j].im = x[uIdx + 1];
  }
}

void MWDSPCG_R2DIT_TBLS_Z(creal_T y[], const int32_T nChans, const int32_T nRows,
  const int32_T fftLen, const int32_T offset, const real_T tablePtr[], const
  int32_T twiddleStep, const boolean_T isInverse)
{
  int32_T nHalf;
  real_T twidRe;
  real_T twidIm;
  int32_T nQtr;
  int32_T fwdInvFactor;
  int32_T iCh;
  int32_T offsetCh;
  int32_T idelta;
  int32_T ix;
  int32_T k;
  int32_T kratio;
  int32_T istart;
  int32_T i;
  int32_T j;
  int32_T i_0;
  real_T tmp_re;
  real_T tmp_im;
  nHalf = (fftLen >> 1) * twiddleStep;
  nQtr = (nHalf >> 1);
  fwdInvFactor = isInverse ? -1 : 1;
  offsetCh = offset;
  for (iCh = 0; iCh < nChans; iCh++) {
    for (ix = offsetCh; ix < ((fftLen + offsetCh) - 1); ix += 2) {
      i_0 = ix + 1;
      tmp_re = y[i_0].re;
      tmp_im = y[i_0].im;
      y[i_0].re = y[ix].re - tmp_re;
      y[i_0].im = y[ix].im - tmp_im;
      y[ix].re += tmp_re;
      y[ix].im += tmp_im;
    }

    idelta = 2;
    k = (fftLen >> 2);
    kratio = k * twiddleStep;
    while (k > 0) {
      i = offsetCh;
      for (ix = 0; ix < k; ix++) {
        i_0 = i + idelta;
        tmp_re = y[i_0].re;
        tmp_im = y[i_0].im;
        y[i_0].re = y[i].re - tmp_re;
        y[i_0].im = y[i].im - tmp_im;
        y[i].re += tmp_re;
        y[i].im += tmp_im;
        i += (idelta << 1);
      }

      istart = offsetCh;
      for (j = kratio; j < nHalf; j += kratio) {
        i = istart + 1;
        twidRe = tablePtr[j];
        twidIm = tablePtr[j + nQtr] * ((real_T)fwdInvFactor);
        for (ix = 0; ix < k; ix++) {
          i_0 = i + idelta;
          tmp_re = (y[i_0].re * twidRe) - (y[i_0].im * twidIm);
          tmp_im = (y[i_0].re * twidIm) + (y[i_0].im * twidRe);
          y[i_0].re = y[i].re - tmp_re;
          y[i_0].im = y[i].im - tmp_im;
          y[i].re += tmp_re;
          y[i].im += tmp_im;
          i += (idelta << 1);
        }

        istart++;
      }

      idelta <<= 1;
      k >>= 1;
      kratio >>= 1;
    }

    offsetCh += nRows;
  }
}

void MWDSPCG_FFT_DblLen_Z(creal_T y[], const int32_T nChans, const int32_T nRows,
  const real_T twiddleTable[], const int32_T twiddleStep)
{
  real_T tempOut0Re;
  real_T tempOut0Im;
  real_T tempOut1Re;
  real_T temp2Re;
  int32_T N;
  int32_T N_0;
  int32_T W;
  int32_T yIdx;
  int32_T ix;
  int32_T k;
  real_T cTemp_re;
  real_T cTemp_im;
  N = (nRows >> 1);
  N_0 = (N >> 1);
  W = N_0 * twiddleStep;
  yIdx = (nChans - 1) * nRows;
  if (nRows > 2) {
    tempOut0Re = y[N_0 + yIdx].re;
    tempOut0Im = y[N_0 + yIdx].im;
    y[(N + N_0) + yIdx].re = tempOut0Re;
    y[(N + N_0) + yIdx].im = tempOut0Im;
    y[N_0 + yIdx].re = tempOut0Re;
    y[N_0 + yIdx].im = -tempOut0Im;
  }

  if (nRows > 1) {
    tempOut0Re = y[yIdx].re;
    tempOut0Re -= y[yIdx].im;
    y[N + yIdx].re = tempOut0Re;
    y[N + yIdx].im = 0.0;
  }

  tempOut0Re = y[yIdx].re;
  tempOut0Re += y[yIdx].im;
  y[yIdx].re = tempOut0Re;
  y[yIdx].im = 0.0;
  k = twiddleStep;
  for (ix = 1; ix < N_0; ix++) {
    tempOut0Re = y[ix + yIdx].re;
    tempOut0Re += y[(N - ix) + yIdx].re;
    tempOut0Re /= 2.0;
    temp2Re = tempOut0Re;
    tempOut0Re = y[ix + yIdx].im;
    tempOut0Re -= y[(N - ix) + yIdx].im;
    tempOut0Re /= 2.0;
    tempOut0Im = tempOut0Re;
    tempOut0Re = y[ix + yIdx].im;
    tempOut0Re += y[(N - ix) + yIdx].im;
    tempOut0Re /= 2.0;
    tempOut1Re = tempOut0Re;
    tempOut0Re = y[(N - ix) + yIdx].re;
    tempOut0Re -= y[ix + yIdx].re;
    tempOut0Re /= 2.0;
    y[ix + yIdx].re = tempOut1Re;
    y[ix + yIdx].im = tempOut0Re;
    cTemp_re = (y[ix + yIdx].re * twiddleTable[k]) - ((-twiddleTable[W - k]) *
      y[ix + yIdx].im);
    cTemp_im = (y[ix + yIdx].im * twiddleTable[k]) + ((-twiddleTable[W - k]) *
      y[ix + yIdx].re);
    tempOut1Re = cTemp_re;
    tempOut0Re = cTemp_im;
    y[ix + yIdx].re = temp2Re + cTemp_re;
    y[ix + yIdx].im = tempOut0Im + cTemp_im;
    cTemp_re = y[ix + yIdx].re;
    cTemp_im = -y[ix + yIdx].im;
    y[(nRows - ix) + yIdx].re = cTemp_re;
    y[(nRows - ix) + yIdx].im = cTemp_im;
    y[(N + ix) + yIdx].re = temp2Re - tempOut1Re;
    y[(N + ix) + yIdx].im = tempOut0Im - tempOut0Re;
    tempOut0Re = y[(N + ix) + yIdx].re;
    tempOut0Im = y[(N + ix) + yIdx].im;
    y[(N - ix) + yIdx].re = tempOut0Re;
    y[(N - ix) + yIdx].im = -tempOut0Im;
    k += twiddleStep;
  }
}

void measureModelClass::step0()
{
  boolean_T rtb_UnitDelay4_dq;
  boolean_T rtb_UnitDelay4_dmwj4s1jwn3;
  boolean_T rtb_LogicalOperator1;
  real_T rtb_Sum1_p5;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_h4;
  boolean_T rtb_Compare_h;
  real_T rtb_UnitDelay1;
  real_T rtb_UnitDelay1_p;
  real_T rtb_Sum1_pz;
  real_T rtb_UnitDelay1_n;
  real_T rtb_Sum1_lle;
  real_T rtb_TrigonometricFunction;
  real_T rtb_Sum2_i;
  real_T rtb_MathFunction1;
  real_T rtb_Switch;
  real_T rtb_Gain_pj;
  boolean_T rtb_Compare_mt;
  real_T rtb_Tps2dt_cr;
  uint32_T rtb_Switch1_ia;
  boolean_T rtb_Compare_hpz455i0;
  boolean_T rtb_Compare_hpz455i02;
  boolean_T rtb_LogicalOperator_fwnazb5b22n;
  boolean_T rtb_LogicalOperator_cdf4d5ci;
  real_T rtb_Subtract3_ca;
  real_T rtb_MathFunction_mti;
  real_T rtb_UnaryMinus_o;
  boolean_T rtb_Compare_jm;
  uint32_T rtb_Switch1_a;
  boolean_T rtb_LogicalOperator1_fw;
  uint32_T rtb_UnitDelay1_b;
  real_T rtb_UnitDelay2_i;
  boolean_T rtb_LogicalOperator16;
  uint32_T rtb_UnitDelay1_lccp;
  boolean_T rtb_Compare_d;
  boolean_T rtb_LogicalOperator1_fmgwx;
  real_T rtb_Sum;
  real_T rtb_Divide_nfu;
  boolean_T rtb_LogicalOperator_nx;
  real_T rtb_Subtract3_lr;
  real_T rtb_MathFunction_gbn;
  real_T rtb_Tps2dt_dt;
  real_T rtb_MathFunction2;
  boolean_T rtb_RelationalOperator_o;
  boolean_T rtb_Compare_f;
  uint32_T rtb_Switch1_pwrm;
  boolean_T rtb_Compare_j1k4d50fkuukj;
  real_T rtb_MathFunction2_d;
  boolean_T rtb_RelationalOperator_os;
  boolean_T rtb_Compare_gw;
  uint32_T rtb_Switch1_dg2as;
  boolean_T rtb_Compare_g3iwu32gm4xoq;
  real_T rtb_MathFunction2_d0;
  boolean_T rtb_RelationalOperator_osa;
  boolean_T rtb_Compare_ji;
  uint32_T rtb_Switch1_mf0c;
  boolean_T rtb_Compare_dtgasgy1ciwmtj;
  boolean_T rtb_LogicalOperator9;
  boolean_T rtb_Compare_jsl;
  boolean_T rtb_Compare_j1k4d50fkuukjsr;
  real_T rtb_Divide_hh0;
  boolean_T rtb_Compare_ddcrdc;
  boolean_T rtb_Compare_ky;
  boolean_T rtb_Compare_ddcrdcv;
  boolean_T rtb_Compare_enj;
  boolean_T rtb_Compare_ks;
  real_T rtb_Subtract3_lri;
  real_T rtb_MathFunction_gbn2;
  real_T rtb_Divide_m;
  real_T rtb_Divide_hh;
  real_T rtb_TrigonometricFunction_i;
  boolean_T rtb_LogicalOperator_eg0;
  real_T rtb_Ts_FFT_c;
  uint32_T rtb_Switch1_pwrmj;
  real_T rtb_UnitDelay_i;
  uint32_T rtb_Switch1_pwrmjy;
  boolean_T rtb_Compare_j1k4d50fkuukjs;
  boolean_T rtb_LogicalOperator2_n;
  boolean_T rtb_Compare_g3iwu32gm4xoqly;
  uint32_T rtb_Switch_e;
  boolean_T rtb_Compare_k;
  uint32_T rtb_Switch_er;
  boolean_T rtb_Compare_k3;
  uint32_T rtb_Switch_ert;
  boolean_T rtb_Compare_k3k;
  boolean_T rtb_Disturbance_All_Phases;
  uint32_T rtb_Switch1_dg2as0;
  real_T rtb_UnitDelay_it;
  uint32_T rtb_Switch1_dg2as0w;
  boolean_T rtb_Compare_g3iwu32gm4xoql;
  uint32_T rtb_Switch1_dg2as0wb;
  boolean_T rtb_LogicalOperator2_npq;
  boolean_T rtb_LogicalOperator2_npqx;
  uint32_T rtb_Switch1_mf0c2;
  real_T rtb_UnitDelay_itx;
  boolean_T rtb_Compare_il;
  uint32_T rtb_Switch1_mf0c25;
  boolean_T rtb_Compare_dtgasgy1ciwmtjh;
  uint32_T rtb_Switch1_mf0c25z;
  boolean_T rtb_LogicalOperator2_npqxo;
  boolean_T rtb_LogicalOperator2_npqxol;
  boolean_T rtb_LogicalOperator12;
  boolean_T rtb_LogicalOperator1_pvh3;
  real_T rtb_Divide_b4h;
  real_T rtb_Divide_b4ha;
  real_T rtb_TrigonometricFunction_ix;
  real_T rtb_Ts_FFT;
  real_T rtb_Divide_nqz;
  real_T rtb_Divide_nqzy;
  real_T rtb_TrigonometricFunction_ixv;
  int32_T i;
  real_T rtb_MathFunction_pl;
  real_T rtb_IpktoIrmsconversion;
  uint32_T rtb_Switch_lli5ykm;
  real_T rtb_Switch1_iew;
  uint32_T rtb_Bias_aswd3;
  boolean_T rtb_Compare_js;
  boolean_T rtb_LogicalOperator2_f3;
  boolean_T rtb_LogicalOperator2_f3l;
  real_T rtb_SumofElements;
  real_T rtb_IpktoIrms_n;
  real_T rtb_AbsVI;
  real_T rtb_Switch_jpt;
  real_T rtb_AbsVI_k;
  real_T rtb_UnaryMinus_g;
  real_T rtb_Sum1_gh;
  real_T rtb_UnitDelay1_o;
  real_T rtb_UnitDelay1_f;
  real_T rtb_UnitDelay1_pu;
  real_T rtb_Sum1_g5i;
  real_T rtb_Switch1_np;
  uint32_T rtb_UnitDelay1_pu5rdhlnellvz;
  uint32_T rtb_Switch2_h;
  uint32_T rtb_UnitDelay1_c;
  real_T rtb_Bias1;
  real_T rtb_Bias;
  real_T rtb_Bias2;
  real_T rtb_Switch1;
  real_T rtb_Switch1_i;
  real_T rtb_Switch1_ie;
  real_T rtb_Switch_nu;
  real_T rtb_Add_p;
  real_T rtb_Add_n;
  real_T rtb_Add_gl;
  real_T rtb_Switch_k;
  uint32_T rtb_FixPtSum1;
  uint32_T rtb_FixPtSum1_c;
  uint32_T rtb_FixPtSum1_co;
  uint32_T rtb_Switch1_hb;
  uint32_T rtb_FixPtSum1_cot;
  uint32_T rtb_FixPtSum1_cotn;
  uint32_T rtb_Switch1_bt;
  uint32_T rtb_Switch1_fr;
  uint32_T rtb_Switch_nulzsg5ykq;
  uint32_T rtb_FixPtSum1_cotnt;
  uint32_T rtb_Switch1_j;
  uint32_T rtb_FixPtSum1_a;
  uint32_T rtb_FixPtSum1_ah;
  uint32_T rtb_FixPtSum1_e;
  uint32_T rtb_FixPtSum1_ec;
  uint32_T rtb_FixPtSum1_ecs;
  uint32_T rtb_FixPtSum1_ecsn;
  uint32_T rtb_FixPtSum1_ecsns;
  uint32_T rtb_FixPtSum1_ecsnsv;
  uint32_T rtb_FixPtSum1_ecsnsvo;
  uint32_T rtb_FixPtSum1_ecsnsvom;
  uint32_T rtb_FixPtSum1_ecsnsvomv;
  real_T rtb_Switch1_l;
  boolean_T rtb_Any_Phases_Not_Disturbed;
  real_T rtb_Switch_jkaja;
  real_T rtb_Switch_jka;
  real_T rtb_Switch_j;
  real_T rtb_Switch4;
  real_T tmp[6];
  boolean_T rtb_Switch6_idx;
  real_T rtb_Add1_fs_idx;
  real_T rtb_Add1_fs_idx_0;
  real_T rtb_Add1_fs_idx_1;
  real_T rtb_VpuIpktoVrmsIrms_im;
  (measure_M->Timing.RateInteraction.TID0_1)++;
  if ((measure_M->Timing.RateInteraction.TID0_1) > 399) {
    measure_M->Timing.RateInteraction.TID0_1 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.SF_FixedDiscreteDelaySfunctio_j[0];
    int_T *VDD_in = (int_T*)&measure_DWork.SF_FixedDiscreteDelaySfuncti_n5;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_DWork.SF_FixedDiscreteDelaySfunction_;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfunctio_n + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfunctio_n;
    measure_B.SF_FixedDiscreteDelaySfunction = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfunctio_n)
      *VDD_in = 0;
  }

  rtb_UnitDelay4_dq = measure_DWork.UnitDelay4_DSTATE_ir;
  if ((measure_DWork.UnitDelay4_DSTATE_ir) && (measure_DWork.delay_DSTATE)) {
    rtb_Switch1 = measure_B.SF_FixedDiscreteDelaySfunction;
  } else {
    rtb_Switch1 = measure_DWork.UnitDelay_DSTATE;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.SF_FixedDiscreteDelaySfuncti_bt[0];
    int_T *VDD_in = (int_T*)&measure_DWork.SF_FixedDiscreteDelaySfunctio_c;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_DWork.SF_FixedDiscreteDelaySfunctio_b;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfuncti_jc + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfuncti_jc;
    measure_B.SF_FixedDiscreteDelaySfunctio_h = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfuncti_jc)
      *VDD_in = 0;
  }

  rtb_UnitDelay4_dmwj4s1jwn3 = measure_DWork.UnitDelay4_DSTATE_czl44j1ipa1;
  if ((measure_DWork.UnitDelay4_DSTATE_czl44j1ipa1) &&
      (measure_DWork.delay_DSTATE_i)) {
    rtb_Switch1_i = measure_B.SF_FixedDiscreteDelaySfunctio_h;
  } else {
    rtb_Switch1_i = measure_DWork.UnitDelay_DSTATE_l;
  }

  if (measure_DWork.UnitDelay4_DSTATE_czl44j1ipa1) {
    rtb_Switch1_ie = measure_DWork.UnitDelay_DSTATE_lm;
  } else {
    rtb_Switch1_ie = measure_P.Constant1_Value_jc;
  }

  rtb_LogicalOperator1 = ((measure_DWork.UnitDelay4_DSTATE_czl44j1ipa1) ||
    (!measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j45));
  rtb_Sum1_p5 = ((((real_T)measure_DWork.clockTickCounter) <
                  measure_P.PulseGenerator1_Duty) &&
                 (measure_DWork.clockTickCounter >= 0)) ?
    measure_P.PulseGenerator1_Amp : 0.0;
  if (((real_T)measure_DWork.clockTickCounter) >=
      (measure_P.PulseGenerator1_Period - 1.0)) {
    measure_DWork.clockTickCounter = 0;
  } else {
    measure_DWork.clockTickCounter = measure_DWork.clockTickCounter + 1;
  }

  rtb_Compare = (rtb_Sum1_p5 > measure_P.Constant_Value_pk);
  rtb_Compare_h4 = ((!rtb_Compare) && (measure_DWork.delay1_DSTATE));
  rtb_Sum1_p5 = ((((real_T)measure_DWork.clockTickCounter_g) <
                  measure_P.PulseGenerator1_Duty_j) &&
                 (measure_DWork.clockTickCounter_g >= 0)) ?
    measure_P.PulseGenerator1_Amp_j : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_g) >=
      (measure_P.PulseGenerator1_Period_j - 1.0)) {
    measure_DWork.clockTickCounter_g = 0;
  } else {
    measure_DWork.clockTickCounter_g = measure_DWork.clockTickCounter_g + 1;
  }

  rtb_Compare_h = (rtb_Sum1_p5 > measure_P.Constant_Value_f);
  rtb_UnitDelay1 = measure_DWork.UnitDelay1_DSTATE;
  rtb_Gain_pj = measure_P.Constant7_Value[0];
  for (i = 0; i < 5; i++) {
    tmp[0] = measure_P.Constant7_Value[0];
    tmp[1] = measure_P.Constant7_Value[1];
    tmp[2] = measure_P.Constant7_Value[2];
    tmp[3] = measure_P.Constant8_Value[0];
    tmp[4] = measure_P.Constant8_Value[1];
    tmp[5] = measure_P.Constant8_Value[2];
    rtb_Gain_pj = fmax(rtb_Gain_pj, tmp[i + 1]);
  }

  rtb_Add1_fs_idx = rtb_Gain_pj - measure_P.Constant8_Value[0];
  rtb_Add1_fs_idx_0 = rtb_Gain_pj - measure_P.Constant8_Value[1];
  rtb_Add1_fs_idx_1 = rtb_Gain_pj - measure_P.Constant8_Value[2];
  rtb_Sum1_p5 = ((rtb_Gain_pj - measure_P.Constant7_Value[1]) *
                 measure_P.Gain_Gain_n) + measure_P.Bias_Bias_hz;
  rtb_Sum1_p5 = ((((measure_U.Vabcpu[1] - measure_DWork.UnitDelay2_DSTATE) *
                   measure_P.Gain_Gain_l) * rtb_Sum1_p5) +
                 measure_DWork.UnitDelay1_DSTATE) +
    ((((measure_DWork.UnitDelay2_DSTATE + measure_U.Vabcpu[1]) *
       measure_P.Gain1_Gain_l) - measure_DWork.UnitDelay1_DSTATE) * (rtb_Sum1_p5
      * rtb_Sum1_p5));
  rtb_UnitDelay1_p = measure_DWork.UnitDelay1_DSTATE_o;
  rtb_Sum1_pz = ((rtb_Gain_pj - measure_P.Constant7_Value[2]) *
                 measure_P.Gain_Gain_ig) + measure_P.Bias_Bias_is;
  rtb_Sum1_pz = ((((measure_U.Vabcpu[2] - measure_DWork.UnitDelay2_DSTATE_k) *
                   measure_P.Gain_Gain_f) * rtb_Sum1_pz) +
                 measure_DWork.UnitDelay1_DSTATE_o) +
    ((((measure_DWork.UnitDelay2_DSTATE_k + measure_U.Vabcpu[2]) *
       measure_P.Gain1_Gain_f) - measure_DWork.UnitDelay1_DSTATE_o) *
     (rtb_Sum1_pz * rtb_Sum1_pz));
  rtb_UnitDelay1_n = measure_DWork.UnitDelay1_DSTATE_g;
  rtb_Sum1_lle = ((rtb_Gain_pj - measure_P.Constant7_Value[0]) *
                  measure_P.Gain_Gain_h) + measure_P.Bias_Bias_e4;
  rtb_Sum1_lle = ((((measure_U.Vabcpu[0] - measure_DWork.UnitDelay2_DSTATE_e) *
                    measure_P.Gain_Gain_m4) * rtb_Sum1_lle) +
                  measure_DWork.UnitDelay1_DSTATE_g) +
    ((((measure_DWork.UnitDelay2_DSTATE_e + measure_U.Vabcpu[0]) *
       measure_P.Gain1_Gain_m) - measure_DWork.UnitDelay1_DSTATE_g) *
     (rtb_Sum1_lle * rtb_Sum1_lle));
  rtb_TrigonometricFunction = rt_atan2d_snf((rtb_Sum1_p5 - rtb_Sum1_pz) *
    measure_P.Gain2_Gain, ((measure_P.Gain_Gain_jc * rtb_Sum1_lle) -
    (rtb_Sum1_p5 + rtb_Sum1_pz)) * measure_P.Gain1_Gain_j);
  rtb_Sum2_i = rtb_TrigonometricFunction - measure_DWork.UnitDelay3_DSTATE;
  if (rtb_Sum2_i < measure_P.Constant_Value_fg) {
    rtb_Sum2_i += measure_P.Bias1_Bias_jc;
  } else {
    if (rtb_Sum2_i > measure_P.Constant_Value_jc) {
      rtb_Sum2_i += measure_P.Bias_Bias_jc;
    }
  }

  measure_B.Gain = measure_P.Gain_Gain_jcf * rtb_Sum2_i;
  if ((!rtb_Compare_h) && (measure_DWork.delay1_DSTATE_c)) {
    measure_B.Switch = measure_P.double_Value_j;
  } else {
    measure_B.Switch = (measure_B.Gain + measure_DWork.UnitDelay4_DSTATE) +
      measure_DWork.UnitDelay2_DSTATE_h;
  }

  rtb_MathFunction1 = 1.0 / measure_DWork.UnitDelay_DSTATE_lm;
  if (rtb_MathFunction1 < measure_P.Constant_Value_am) {
    rtb_Switch = measure_P.Constant_Value_d0;
  } else if (rtb_MathFunction1 > measure_P.Constant_Value_g) {
    rtb_Switch = measure_P.Constant1_Value_jcfawyw2o0;
  } else {
    rtb_Switch = rtb_MathFunction1;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_jcfa * rtb_Switch;
  if (measure_P.Constant1_Value_jcfawyw2o0os) {
    measure_B.Switch2 = rtb_Gain_pj + measure_P.Bias1_Bias_jcfawy;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_gg) {
    measure_B.Switch2 = rtb_Gain_pj;
  } else {
    measure_B.Switch2 = rtb_Gain_pj + measure_P.Bias_Bias_jcfawy;
  }

  {
    measure_B.SFunction = (int32_T)measure_B.Switch2;
  }

  if (measure_B.SFunction < measure_P.Constant_Value_nz) {
    measure_B.Switch2_h1wibj25mp = measure_P.Constant_Value_mwk;
  } else if (measure_B.SFunction > measure_P.Constant_Value_eom) {
    measure_B.Switch2_h1wibj25mp = measure_P.Constant3_Value_jc;
  } else {
    measure_B.Switch2_h1wibj25mp = measure_B.SFunction;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTap[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOneT_h;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTap;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTap = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTap)
      *VDD_in = 0;
  }

  if (rtb_Compare_h && (measure_DWork.delay_DSTATE_i2)) {
    measure_B.Switch_n = measure_P.double_Value_jc;
  } else {
    measure_B.Switch_n = (measure_B.Gain + measure_DWork.UnitDelay4_DSTATE_c) +
      measure_DWork.UnitDelay2_DSTATE_h5;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneT_b[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOne_h3;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_n;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_j;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_c = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_j)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoTap[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTwoT_j;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Gain;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTap;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTap = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTap)
      measure_B.VariableDiscreteDelaywithTwoT_f = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoT_f = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTap)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator1) {
    measure_B.Switch2_h = rtb_Switch1_ie;
  } else {
    rtb_Gain_pj = ((real_T)measure_B.Switch2_h1wibj25mp) - rtb_Gain_pj;
    rtb_Switch1_l = rtb_Gain_pj * rtb_Gain_pj;
    rtb_Gain_pj = (((measure_P.Gain1_Gain * rtb_Gain_pj) - rtb_Switch1_l) *
                   measure_B.VariableDiscreteDelaywithTwoTap) +
      (measure_B.VariableDiscreteDelaywithTwoT_f * rtb_Switch1_l);
    if (rtb_Compare_h) {
      rtb_Switch1_l = measure_B.Switch -
        measure_B.VariableDiscreteDelaywithOneTap;
    } else {
      rtb_Switch1_l = measure_B.Switch_n -
        measure_B.VariableDiscreteDelaywithOneT_c;
    }

    rtb_Gain_pj = ((1.0 / rtb_Switch) * measure_P.Gain_Gain) * (rtb_Switch1_l -
      rtb_Gain_pj);
    if (rtb_Gain_pj < measure_P.Constant_Value_oa) {
      measure_B.Switch2_h = -rtb_Gain_pj;
    } else {
      measure_B.Switch2_h = rtb_Gain_pj;
    }
  }

  if (rtb_Compare_h4) {
    measure_B.Switch_nu = measure_P.double_Value_jcf;
  } else {
    measure_B.Switch_nu = (measure_B.Switch2_h +
      measure_DWork.UnitDelay4_DSTATE_cz) + measure_DWork.UnitDelay2_DSTATE_h5b;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_jcfaw * rtb_MathFunction1;
  if (rtb_Gain_pj < measure_P.Constant_Value_dsl) {
    rtb_Sum2_i = measure_P.Constant_Value_ey;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_hv) {
    rtb_Sum2_i = measure_P.Constant1_Value_jcfawyw2o0o;
  } else {
    rtb_Sum2_i = rtb_Gain_pj;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_jcfawy * rtb_Sum2_i;
  if (measure_P.Constant1_Value_jcfawyw2o0osk) {
    measure_B.Switch2_h1 = rtb_Gain_pj + measure_P.Bias1_Bias_jcfawyw;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_ha) {
    measure_B.Switch2_h1 = rtb_Gain_pj;
  } else {
    measure_B.Switch2_h1 = rtb_Gain_pj + measure_P.Bias_Bias_jcfawyw;
  }

  {
    measure_B.SFunction_i = (int32_T)measure_B.Switch2_h1;
  }

  if (measure_B.SFunction_i < measure_P.Constant_Value_ir) {
    measure_B.Switch2_h1wibj25mpu = measure_P.Constant_Value_kb;
  } else if (measure_B.SFunction_i > measure_P.Constant_Value_o3) {
    measure_B.Switch2_h1wibj25mpu = measure_P.Constant3_Value_jcf;
  } else {
    measure_B.Switch2_h1wibj25mpu = measure_B.SFunction_i;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_b4[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOn_h3s;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nu;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_jc;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_co = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_jc)
      *VDD_in = 0;
  }

  rtb_Compare_mt = (rtb_Compare && (measure_DWork.delay_DSTATE_i2w));
  if (rtb_Compare_mt) {
    measure_B.Switch_nul = measure_P.double_Value_jcfa;
  } else {
    measure_B.Switch_nul = (measure_B.Switch2_h +
      measure_DWork.UnitDelay4_DSTATE_czl) +
      measure_DWork.UnitDelay2_DSTATE_h5br;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_b4n[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithO_h3se;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nul;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_jcf;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_co5 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_jcf)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_m[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTwo_jn;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch2_h;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_j;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoT_j = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_j)
      measure_B.VariableDiscreteDelaywithTwo_f1 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwo_f1 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_j)
      *VDD_in = 0;
  }

  rtb_Tps2dt_cr = ((real_T)measure_B.Switch2_h1wibj25mpu) - rtb_Gain_pj;
  rtb_Switch1_l = rtb_Tps2dt_cr * rtb_Tps2dt_cr;
  rtb_Switch = (measure_P.Gain1_Gain_jc * rtb_Tps2dt_cr) - rtb_Switch1_l;
  rtb_MathFunction1 = (1.0 / rtb_Sum2_i) * measure_P.Gain_Gain_jcfawyw;
  if (rtb_LogicalOperator1) {
    measure_B.Switch4 = rtb_Switch1_ie;
  } else {
    if (rtb_Compare) {
      rtb_Gain_pj = measure_B.Switch_nu -
        measure_B.VariableDiscreteDelaywithOne_co;
    } else {
      rtb_Gain_pj = measure_B.Switch_nul -
        measure_B.VariableDiscreteDelaywithOn_co5;
    }

    measure_B.Switch4 = (rtb_Gain_pj -
                         ((measure_B.VariableDiscreteDelaywithTwoT_j *
      rtb_Switch) + (measure_B.VariableDiscreteDelaywithTwo_f1 * rtb_Switch1_l)))
      * rtb_MathFunction1;
  }

  if (rtb_Compare_h4) {
    measure_B.Switch_nulz = measure_P.double_Value_jcfaw;
  } else {
    measure_B.Switch_nulz = (measure_B.Switch4 +
      measure_DWork.UnitDelay4_DSTATE_czl4) +
      measure_DWork.UnitDelay2_DSTATE_h5brd;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithO_b4np[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywith_h3see;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulz;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_jcfa;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithO_co5g = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_jcfa)
      *VDD_in = 0;
  }

  if (rtb_Compare_mt) {
    measure_B.Switch_nulzs = measure_P.double_Value_jcfawy;
  } else {
    measure_B.Switch_nulzs = (measure_B.Switch4 +
      measure_DWork.UnitDelay4_DSTATE_czl44) +
      measure_DWork.UnitDelay2_DSTATE_h5brdq;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywith_b4npp[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywit_h3seeh;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulzs;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_jcfaw;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywith_co5gw = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_jcfaw)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_mf[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTw_jng;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch4;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_jc;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwo_jw = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_jc)
      measure_B.VariableDiscreteDelaywithTw_f1u = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTw_f1u = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_jc)
      *VDD_in = 0;
  }

  rtb_Tps2dt_cr = measure_P.Gain1_Gain_jcf * measure_P.Constant5_Value;
  rtb_Sum2_i = rtb_Tps2dt_cr + measure_P.Bias_Bias_jcfawyw2;
  if (rtb_Sum2_i > measure_P.Constant_Value_o2) {
    rtb_Sum2_i = measure_P.Constant_Value_j;
  }

  rtb_Compare_mt = (((measure_B.Gain < rtb_Sum2_i) && (measure_B.Gain >
    (-rtb_Tps2dt_cr))) || rtb_UnitDelay4_dmwj4s1jwn3);
  if (rtb_Compare_mt) {
    rtb_Switch1_ia = measure_DWork.UnitDelay1_DSTATE_cmnb3jx;
  } else {
    rtb_Switch1_ia = measure_P.const_Value_jc;
  }

  rtb_Compare_hpz455i0 = (rtb_Switch1_ia == measure_P.Constant_Value_irv);
  if (rtb_Compare_mt) {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_DWork.UnitDelay1_DSTATE_cmnb3jxq;
  } else {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_P.const_Value_j;
  }

  rtb_Compare_h4 = (rtb_UnitDelay1_pu5rdhlnellvz == measure_P.Constant_Value_gl);
  if (rtb_Compare_h4) {
    if (rtb_Compare_hpz455i0) {
      if (!rtb_LogicalOperator1) {
        if (rtb_Compare) {
          rtb_Gain_pj = measure_B.Switch_nulz -
            measure_B.VariableDiscreteDelaywithO_co5g;
        } else {
          rtb_Gain_pj = measure_B.Switch_nulzs -
            measure_B.VariableDiscreteDelaywith_co5gw;
        }

        rtb_Switch1_ie = (rtb_Gain_pj -
                          ((measure_B.VariableDiscreteDelaywithTwo_jw *
                            rtb_Switch) +
                           (measure_B.VariableDiscreteDelaywithTw_f1u *
                            rtb_Switch1_l))) * rtb_MathFunction1;
      }
    } else {
      rtb_Switch1_ie = measure_B.Switch4;
    }

    measure_B.Switch2_h1w = rtb_Switch1_ie;
  } else {
    measure_B.Switch2_h1w = measure_B.Switch2_h;
  }

  rtb_Tps2dt_cr = ((((real_T)measure_DWork.clockTickCounter_ge) <
                    measure_P.PulseGenerator1_Duty_jc) &&
                   (measure_DWork.clockTickCounter_ge >= 0)) ?
    measure_P.PulseGenerator1_Amp_jc : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_ge) >=
      (measure_P.PulseGenerator1_Period_jc - 1.0)) {
    measure_DWork.clockTickCounter_ge = 0;
  } else {
    measure_DWork.clockTickCounter_ge = measure_DWork.clockTickCounter_ge + 1;
  }

  rtb_Compare_hpz455i02 = (rtb_Tps2dt_cr > measure_P.Constant_Value_kz);
  rtb_LogicalOperator_fwnazb5b22n = ((!rtb_Compare_hpz455i02) &&
    (measure_DWork.delay1_DSTATE_ce));
  if (rtb_LogicalOperator_fwnazb5b22n) {
    measure_B.Switch_nulzsg = measure_P.double_Value_jcfawyw;
  } else {
    measure_B.Switch_nulzsg = (measure_B.Switch2_h1w +
      measure_DWork.UnitDelay4_DSTATE_czl44j) +
      measure_DWork.UnitDelay2_DSTATE_h5brdqc;
  }

  if (measure_DWork.UnitDelay2_DSTATE_h5brdqci < measure_P.Constant_Value_mg) {
    rtb_Tps2dt_cr = measure_P.Constant_Value_k;
  } else if (measure_DWork.UnitDelay2_DSTATE_h5brdqci >
             measure_P.Constant_Value_jcfawyw2o0osk24) {
    rtb_Tps2dt_cr = measure_P.Constant1_Value_jcfawyw;
  } else {
    rtb_Tps2dt_cr = measure_DWork.UnitDelay2_DSTATE_h5brdqci;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_jcfawyw2 * rtb_Tps2dt_cr;
  if (measure_P.Constant1_Value_jcfawyw2o0osk2) {
    measure_B.Switch2_h1wi = rtb_Gain_pj + measure_P.Bias1_Bias_jcfa;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_de) {
    measure_B.Switch2_h1wi = rtb_Gain_pj;
  } else {
    measure_B.Switch2_h1wi = rtb_Gain_pj + measure_P.Bias_Bias_jcfa;
  }

  {
    measure_B.SFunction_il = (int32_T)measure_B.Switch2_h1wi;
  }

  if (measure_B.SFunction_il < measure_P.Constant_Value_bq) {
    measure_B.Switch2_h1wibj25mpus = measure_P.Constant_Value_eo;
  } else if (measure_B.SFunction_il > measure_P.Constant_Value_do) {
    measure_B.Switch2_h1wibj25mpus = measure_P.Constant3_Value_j;
  } else {
    measure_B.Switch2_h1wibj25mpus = measure_B.SFunction_il;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywit_b4npph[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywi_h3seeh3;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulzsg;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_jcfawy;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywit_co5gwo = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_jcfawy)
      *VDD_in = 0;
  }

  rtb_LogicalOperator_cdf4d5ci = (rtb_Compare_hpz455i02 &&
    (measure_DWork.delay_DSTATE_i2wj));
  if (rtb_LogicalOperator_cdf4d5ci) {
    measure_B.Switch_nulzsg5 = measure_P.double_Value_jcfawyw2;
  } else {
    measure_B.Switch_nulzsg5 = (measure_B.Switch2_h1w +
      measure_DWork.UnitDelay4_DSTATE_czl44j1) +
      measure_DWork.UnitDelay2_DSTATE_h5brdqciz;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywi_b4npphe[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelayw_h3seeh3o;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulzsg5;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_jcfawyw;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywi_co5gwoz = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_jcfawyw)
      *VDD_in = 0;
  }

  if (rtb_Compare_hpz455i02) {
    rtb_Sum2_i = measure_B.Switch_nulzsg -
      measure_B.VariableDiscreteDelaywit_co5gwo;
  } else {
    rtb_Sum2_i = measure_B.Switch_nulzsg5 -
      measure_B.VariableDiscreteDelaywi_co5gwoz;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_mf5[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithT_jngr;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch2_h1w;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_jcf;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTw_jwh = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTw_jcf)
      measure_B.VariableDiscreteDelaywithT_f1uv = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithT_f1uv = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_jcf)
      *VDD_in = 0;
  }

  rtb_Subtract3_ca = ((real_T)measure_B.Switch2_h1wibj25mpus) - rtb_Gain_pj;
  rtb_MathFunction_mti = rtb_Subtract3_ca * rtb_Subtract3_ca;
  rtb_Subtract3_ca = (measure_P.Gain1_Gain_jcfa * rtb_Subtract3_ca) -
    rtb_MathFunction_mti;
  rtb_Tps2dt_cr = (1.0 / rtb_Tps2dt_cr) * measure_P.Gain_Gain_jcfawyw2o;
  rtb_Sum2_i = (rtb_Sum2_i - ((measure_B.VariableDiscreteDelaywithTw_jwh *
    rtb_Subtract3_ca) + (measure_B.VariableDiscreteDelaywithT_f1uv *
    rtb_MathFunction_mti))) * rtb_Tps2dt_cr;
  measure_B.ACripple1stestimate = measure_B.Switch2_h1w - rtb_Sum2_i;
  if (measure_B.ACripple1stestimate < measure_P.Constant_Value_gv) {
    rtb_UnaryMinus_o = -measure_B.ACripple1stestimate;
  } else {
    rtb_UnaryMinus_o = measure_B.ACripple1stestimate;
  }

  if (rtb_UnaryMinus_o > (measure_P.Gain1_Gain_jcfaw *
                          measure_P.Constant2_Value_h)) {
    rtb_UnitDelay1_c = measure_P.int32_Value;
  } else {
    rtb_UnitDelay1_c = measure_DWork.UnitDelay_DSTATE_lmdw -
      measure_P.FixPtConstant_Value_jcf;
  }

  rtb_Compare_jm = (rtb_UnitDelay1_c > measure_P.Constant_Value_ku);
  if (rtb_Compare_jm) {
    measure_B.Switch2_h1wib = measure_B.Switch2_h1w;
  } else {
    measure_B.Switch2_h1wib = rtb_Sum2_i;
  }

  if (rtb_UnitDelay4_dmwj4s1jwn3) {
    rtb_Gain_pj = rtb_Switch1_i;
  } else {
    rtb_Gain_pj = measure_B.Switch2_h1wib;
  }

  if (rtb_Gain_pj < measure_P.Constant_Value_e5) {
    rtb_Switch_nu = measure_P.Constant_Value_jcfa;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_jcf) {
    rtb_Switch_nu = measure_P.Constant1_Value_jcf;
  } else {
    rtb_Switch_nu = rtb_Gain_pj;
  }

  if (rtb_Compare_mt) {
    rtb_Switch1_a = measure_DWork.UnitDelay1_DSTATE_cmnb3jxqh;
  } else {
    rtb_Switch1_a = measure_P.const_Value;
  }

  rtb_Compare_mt = (rtb_Switch1_a == measure_P.Constant_Value_kx);
  rtb_LogicalOperator1_fw = (rtb_Compare_mt || rtb_UnitDelay4_dmwj4s1jwn3);
  if (rtb_LogicalOperator1_fw) {
    rtb_Switch1_iew = rtb_Switch_nu;
  } else {
    rtb_Switch1_iew = measure_P.Constant1_Value_j;
  }

  rtb_UnitDelay1_b = measure_DWork.UnitDelay1_DSTATE_k;
  rtb_UnitDelay2_i = measure_DWork.UnitDelay2_DSTATE_kg;
  rtb_LogicalOperator1 = measure_DWork.UnitDelay4_DSTATE_h;
  rtb_LogicalOperator16 = (rtb_LogicalOperator1_fw &&
    (!rtb_UnitDelay4_dmwj4s1jwn3));
  rtb_UnitDelay1_lccp = measure_DWork.UnitDelay1_DSTATE_aqjz;
  rtb_UnaryMinus_o = ((((real_T)measure_DWork.clockTickCounter_i) <
                       measure_P.PulseGenerator1_Duty_e) &&
                      (measure_DWork.clockTickCounter_i >= 0)) ?
    measure_P.PulseGenerator1_Amp_e : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_i) >=
      (measure_P.PulseGenerator1_Period_e - 1.0)) {
    measure_DWork.clockTickCounter_i = 0;
  } else {
    measure_DWork.clockTickCounter_i = measure_DWork.clockTickCounter_i + 1;
  }

  rtb_Compare_d = (rtb_UnaryMinus_o > measure_P.Constant_Value_ep34emcng);
  rtb_LogicalOperator1_fmgwx = ((!rtb_Compare_d) &&
    (measure_DWork.delay1_DSTATE_d));
  rtb_Sum = (measure_P.Gain_Gain_e * measure_DWork.UnitDelay2_DSTATE_kg) +
    measure_DWork.UnitDelay_DSTATE_p;
  if (rtb_Sum > measure_P.Constant_Value_ep34emcngn) {
    rtb_Sum += measure_P.Bias_Bias_e;
  }

  rtb_UnaryMinus_o = std::sin(rtb_Sum);
  rtb_Sum2_i = std::cos(rtb_Sum);
  if (measure_DWork.UnitDelay2_DSTATE_kg < measure_P.Constant_Value_ep34emcngnx)
  {
    rtb_Switch4 = measure_P.Constant_Value_ep;
  } else {
    rtb_Switch4 = measure_DWork.UnitDelay2_DSTATE_kg;
  }

  rtb_Divide_nfu = ((measure_DWork.UnitDelay2_DSTATE_kg - rtb_Switch4) *
                    measure_P.FCn3_Gain) + measure_P.Bias_Bias_ep34e;
  measure_B.Product[0] = (rtb_Sum1_lle * rtb_UnaryMinus_o) * rtb_Divide_nfu;
  measure_B.Product[1] = (rtb_Sum1_lle * rtb_Sum2_i) * rtb_Divide_nfu;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_l = measure_P.double_Value_dsc5;
  } else {
    measure_B.Switch_l = (measure_B.Product[0] +
                          measure_DWork.UnitDelay4_DSTATE_j) +
      measure_DWork.UnitDelay2_DSTATE_g;
  }

  rtb_Switch = 1.0 / rtb_Switch4;
  if (rtb_Switch < measure_P.Constant_Value_ep34emcngnxm) {
    rtb_Switch4 = measure_P.Constant_Value_ep34;
  } else if (rtb_Switch > measure_P.Constant_Value_ep3) {
    rtb_Switch4 = measure_P.Constant1_Value_e;
  } else {
    rtb_Switch4 = rtb_Switch;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_ep * rtb_Switch4;
  if (measure_P.Constant1_Value_ep34) {
    measure_B.Switch2_f = rtb_Gain_pj + measure_P.Bias1_Bias_e;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_ep34emcngnxmt) {
    measure_B.Switch2_f = rtb_Gain_pj;
  } else {
    measure_B.Switch2_f = rtb_Gain_pj + measure_P.Bias_Bias_ep;
  }

  {
    measure_B.SFunction_c = (int32_T)measure_B.Switch2_f;
  }

  if (measure_B.SFunction_c < measure_P.Constant_Value_ap2) {
    measure_B.Switch2_f0yh = measure_P.Constant_Value_fgy;
  } else if (measure_B.SFunction_c > measure_P.Constant_Value_dea) {
    measure_B.Switch2_f0yh = measure_P.Constant3_Value_e;
  } else {
    measure_B.Switch2_f0yh = measure_B.SFunction_c;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneT_j[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOneT_o;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_l;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_d;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_a = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_d)
      *VDD_in = 0;
  }

  rtb_LogicalOperator_nx = (rtb_Compare_d && (measure_DWork.delay_DSTATE_iz));
  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_lv = measure_P.double_Value_dsc5t;
  } else {
    measure_B.Switch_lv = (measure_B.Product[0] +
      measure_DWork.UnitDelay4_DSTATE_jb) + measure_DWork.UnitDelay2_DSTATE_gb;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_je[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOne_ob;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_ds;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_am = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_ds)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Tps2dt_dt = measure_B.Switch_l -
      measure_B.VariableDiscreteDelaywithOneT_a;
  } else {
    rtb_Tps2dt_dt = measure_B.Switch_lv -
      measure_B.VariableDiscreteDelaywithOne_am;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_p[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTwoT_a;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_d;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoT_m = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_d)
      measure_B.VariableDiscreteDelaywithTwoT_g = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoT_g = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_d)
      *VDD_in = 0;
  }

  rtb_Subtract3_lr = ((real_T)measure_B.Switch2_f0yh) - rtb_Gain_pj;
  rtb_MathFunction_gbn = rtb_Subtract3_lr * rtb_Subtract3_lr;
  rtb_Subtract3_lr = (measure_P.Gain1_Gain_e * rtb_Subtract3_lr) -
    rtb_MathFunction_gbn;
  rtb_Gain_pj = rtb_Tps2dt_dt - ((measure_B.VariableDiscreteDelaywithTwoT_m *
    rtb_Subtract3_lr) + (measure_B.VariableDiscreteDelaywithTwoT_g *
    rtb_MathFunction_gbn));
  rtb_Tps2dt_dt = (1.0 / rtb_Switch4) * measure_P.Gain_Gain_ep3;
  measure_B.Divide = rtb_Gain_pj * rtb_Tps2dt_dt;
  rtb_Gain_pj = measure_B.Divide * measure_B.Divide;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_lv2 = measure_P.double_Value_dsc5tt;
  } else {
    measure_B.Switch_lv2 = (measure_B.Product[1] +
      measure_DWork.UnitDelay4_DSTATE_jbk) + measure_DWork.UnitDelay2_DSTATE_gbj;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_jel[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOn_obu;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_dsc;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_amg = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_dsc)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_lv2a = measure_P.double_Value_dsc5ttd;
  } else {
    measure_B.Switch_lv2a = (measure_B.Product[1] +
      measure_DWork.UnitDelay4_DSTATE_jbkw) +
      measure_DWork.UnitDelay2_DSTATE_gbjg;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithO_jelr[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithO_obui;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2a;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_dsc5;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithO_amg5 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_dsc5)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch4 = measure_B.Switch_lv2 -
      measure_B.VariableDiscreteDelaywithOn_amg;
  } else {
    rtb_Switch4 = measure_B.Switch_lv2a -
      measure_B.VariableDiscreteDelaywithO_amg5;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_p3[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTwo_as;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_ds;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwo_m0 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_ds)
      measure_B.VariableDiscreteDelaywithTwo_gp = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwo_gp = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_ds)
      *VDD_in = 0;
  }

  measure_B.Divide_h = (rtb_Switch4 -
                        ((measure_B.VariableDiscreteDelaywithTwo_m0 *
    rtb_Subtract3_lr) + (measure_B.VariableDiscreteDelaywithTwo_gp *
    rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  rtb_Switch4 = (measure_B.Divide_h * measure_B.Divide_h) + rtb_Gain_pj;
  rtb_MathFunction2 = (rtb_Switch4 < 0.0) ? (-std::sqrt(std::abs(rtb_Switch4))) :
    std::sqrt(rtb_Switch4);
  rtb_RelationalOperator_o = (rtb_MathFunction2 > measure_P.Constant5_Value);
  rtb_Compare_f = (rtb_RelationalOperator_o || rtb_UnitDelay4_dq);
  if (rtb_Compare_f) {
    rtb_Switch1_pwrm = rtb_UnitDelay1_lccp;
  } else {
    rtb_Switch1_pwrm = measure_P.const_Value_o;
  }

  rtb_Compare_j1k4d50fkuukj = (rtb_Switch1_pwrm == measure_P.Constant_Value_od);
  rtb_UnitDelay1_lccp = measure_DWork.UnitDelay1_DSTATE_aqjzx;
  measure_B.Product_e[0] = (rtb_Sum1_p5 * rtb_UnaryMinus_o) * rtb_Divide_nfu;
  measure_B.Product_e[1] = (rtb_Sum1_p5 * rtb_Sum2_i) * rtb_Divide_nfu;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_f = measure_P.double_Value_d1m1;
  } else {
    measure_B.Switch_f = (measure_B.Product_e[0] +
                          measure_DWork.UnitDelay4_DSTATE_jbkwm) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywith_jelr5[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywith_obui2;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_d1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywith_amg5c = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_d1)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_f0 = measure_P.double_Value_d1m1h;
  } else {
    measure_B.Switch_f0 = (measure_B.Product_e[0] +
      measure_DWork.UnitDelay4_DSTATE_jbkwms) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk5;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywit_jelr5a[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywit_obui2s;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_d1m;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywit_amg5cr = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_d1m)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch4 = measure_B.Switch_f - measure_B.VariableDiscreteDelaywith_amg5c;
  } else {
    rtb_Switch4 = measure_B.Switch_f0 -
      measure_B.VariableDiscreteDelaywit_amg5cr;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_p3o[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTw_asr;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_e[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_d1;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTw_m0k = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_d1)
      measure_B.VariableDiscreteDelaywithTw_gpk = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTw_gpk = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_d1)
      *VDD_in = 0;
  }

  measure_B.Divide_b = (rtb_Switch4 -
                        ((measure_B.VariableDiscreteDelaywithTw_m0k *
    rtb_Subtract3_lr) + (measure_B.VariableDiscreteDelaywithTw_gpk *
    rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  rtb_Gain_pj = measure_B.Divide_b * measure_B.Divide_b;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_f0o = measure_P.double_Value_d1m1hi;
  } else {
    measure_B.Switch_f0o = (measure_B.Product_e[1] +
      measure_DWork.UnitDelay4_DSTATE_jbkwmsq) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk5q;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywi_jelr5az[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywi_obui2sv;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_d1m1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywi_amg5cre = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_d1m1)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_f0o4 = measure_P.double_Value_d1m1hiq;
  } else {
    measure_B.Switch_f0o4 = (measure_B.Product_e[1] +
      measure_DWork.UnitDelay4_DSTATE_jbkwmsq2) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk5qb;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelayw_jelr5azs[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelayw_obui2svt;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_d1m1h;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelayw_amg5cres = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_d1m1h)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch4 = measure_B.Switch_f0o -
      measure_B.VariableDiscreteDelaywi_amg5cre;
  } else {
    rtb_Switch4 = measure_B.Switch_f0o4 -
      measure_B.VariableDiscreteDelayw_amg5cres;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_p3ok[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithT_asrw;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_e[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_d1m;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithT_m0kf = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTw_d1m)
      measure_B.VariableDiscreteDelaywithT_gpkw = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithT_gpkw = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_d1m)
      *VDD_in = 0;
  }

  measure_B.Divide_b4 = (rtb_Switch4 -
    ((measure_B.VariableDiscreteDelaywithT_m0kf * rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithT_gpkw * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  rtb_Switch4 = (measure_B.Divide_b4 * measure_B.Divide_b4) + rtb_Gain_pj;
  rtb_MathFunction2_d = (rtb_Switch4 < 0.0) ? (-std::sqrt(std::abs(rtb_Switch4)))
    : std::sqrt(rtb_Switch4);
  rtb_RelationalOperator_os = (rtb_MathFunction2_d > measure_P.Constant5_Value);
  rtb_Compare_gw = (rtb_RelationalOperator_os || rtb_UnitDelay4_dq);
  if (rtb_Compare_gw) {
    rtb_Switch1_dg2as = rtb_UnitDelay1_lccp;
  } else {
    rtb_Switch1_dg2as = measure_P.const_Value_kc;
  }

  rtb_Compare_g3iwu32gm4xoq = (rtb_Switch1_dg2as == measure_P.Constant_Value_kc);
  rtb_UnitDelay1_lccp = measure_DWork.UnitDelay1_DSTATE_aqjzxp;
  measure_B.Product_h[0] = (rtb_Sum1_pz * rtb_UnaryMinus_o) * rtb_Divide_nfu;
  measure_B.Product_h[1] = (rtb_Sum1_pz * rtb_Sum2_i) * rtb_Divide_nfu;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_ng = measure_P.double_Value_m041;
  } else {
    measure_B.Switch_ng = (measure_B.Product_h[0] +
      measure_DWork.UnitDelay4_DSTATE_jbkwmsq2k) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelay_jelr5azsa[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelay_obui2svtg;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ng;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_m;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelay_amg5cres2 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_m)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_nge = measure_P.double_Value_m0413;
  } else {
    measure_B.Switch_nge = (measure_B.Product_h[0] +
      measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx3;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDela_jelr5azsa0[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDela_obui2svtgp;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nge;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_m0;
      VDD_out++;
    }

    measure_B.VariableDiscreteDela_amg5cres2a = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_m0)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch4 = measure_B.Switch_ng -
      measure_B.VariableDiscreteDelay_amg5cres2;
  } else {
    rtb_Switch4 = measure_B.Switch_nge -
      measure_B.VariableDiscreteDela_amg5cres2a;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_p3ok0[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywith_asrwd;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_h[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_m;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywith_m0kft = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_m)
      measure_B.VariableDiscreteDelaywith_gpkwv = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywith_gpkwv = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_m)
      *VDD_in = 0;
  }

  measure_B.Divide_n = (rtb_Switch4 -
                        ((measure_B.VariableDiscreteDelaywith_m0kft *
    rtb_Subtract3_lr) + (measure_B.VariableDiscreteDelaywith_gpkwv *
    rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  rtb_Gain_pj = measure_B.Divide_n * measure_B.Divide_n;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_ngeq = measure_P.double_Value_m0413r;
  } else {
    measure_B.Switch_ngeq = (measure_B.Product_h[1] +
      measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDel_jelr5azsa0t[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDel_obui2svtgpu;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeq;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_m04;
      VDD_out++;
    }

    measure_B.VariableDiscreteDel_amg5cres2an = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_m04)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_ngeqq = measure_P.double_Value_m0413rf;
  } else {
    measure_B.Switch_ngeqq = (measure_B.Product_h[1] +
      measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35b;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDe_jelr5azsa0te[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDe_obui2svtgpup;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_m041;
      VDD_out++;
    }

    measure_B.VariableDiscreteDe_amg5cres2anr = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_m041)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch4 = measure_B.Switch_ngeq -
      measure_B.VariableDiscreteDel_amg5cres2an;
  } else {
    rtb_Switch4 = measure_B.Switch_ngeqq -
      measure_B.VariableDiscreteDe_amg5cres2anr;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_p3ok0i[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywit_asrwdn;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_h[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_m0;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywit_m0kftp = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_m0)
      measure_B.VariableDiscreteDelaywit_gpkwvf = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywit_gpkwvf = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_m0)
      *VDD_in = 0;
  }

  measure_B.Divide_nq = (rtb_Switch4 -
    ((measure_B.VariableDiscreteDelaywit_m0kftp * rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywit_gpkwvf * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  rtb_Switch4 = (measure_B.Divide_nq * measure_B.Divide_nq) + rtb_Gain_pj;
  rtb_MathFunction2_d0 = (rtb_Switch4 < 0.0) ? (-std::sqrt(std::abs(rtb_Switch4)))
    : std::sqrt(rtb_Switch4);
  rtb_RelationalOperator_osa = (rtb_MathFunction2_d0 > measure_P.Constant5_Value);
  rtb_Compare_ji = (rtb_RelationalOperator_osa || rtb_UnitDelay4_dq);
  if (rtb_Compare_ji) {
    rtb_Switch1_mf0c = rtb_UnitDelay1_lccp;
  } else {
    rtb_Switch1_mf0c = measure_P.const_Value_ok;
  }

  rtb_Compare_dtgasgy1ciwmtj = (rtb_Switch1_mf0c == measure_P.Constant_Value_okw);
  rtb_LogicalOperator9 = !((rtb_Compare_j1k4d50fkuukj ||
    rtb_Compare_g3iwu32gm4xoq) || rtb_Compare_dtgasgy1ciwmtj);
  if (rtb_UnitDelay4_dq) {
    rtb_Switch4 = rtb_UnitDelay2_i;
  } else if (rtb_LogicalOperator1) {
    rtb_Switch4 = rtb_Switch1_iew;
  } else if (rtb_LogicalOperator9) {
    if (rtb_LogicalOperator16) {
      rtb_Switch4 = rtb_Switch1_iew;
    } else {
      rtb_Switch4 = measure_P.Constant4_Value;
    }
  } else {
    rtb_Switch4 = rtb_UnitDelay2_i;
  }

  rtb_Compare_jsl = ((rtb_UnitDelay4_dq || rtb_LogicalOperator1) ||
                     rtb_LogicalOperator9);
  rtb_Compare_j1k4d50fkuukjsr = (rtb_Compare_jsl || (!(rtb_Compare_j1k4d50fkuukj
    || rtb_LogicalOperator9)));
  rtb_Divide_hh0 = ((((real_T)measure_DWork.clockTickCounter_io) <
                     measure_P.PulseGenerator1_Duty_ep) &&
                    (measure_DWork.clockTickCounter_io >= 0)) ?
    measure_P.PulseGenerator1_Amp_ep : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_io) >=
      (measure_P.PulseGenerator1_Period_ep - 1.0)) {
    measure_DWork.clockTickCounter_io = 0;
  } else {
    measure_DWork.clockTickCounter_io = measure_DWork.clockTickCounter_io + 1;
  }

  rtb_Compare_ddcrdc = (rtb_Divide_hh0 > measure_P.Constant_Value_ep34emcngnxmtm);
  rtb_Compare_ky = ((!rtb_Compare_ddcrdc) && (measure_DWork.delay1_DSTATE_dt));
  rtb_Switch1_l = measure_DWork.UnitDelay3_DSTATE_i;
  rtb_Divide_hh0 = ((((real_T)measure_DWork.clockTickCounter_iom) <
                     measure_P.PulseGenerator1_Duty_ep3) &&
                    (measure_DWork.clockTickCounter_iom >= 0)) ?
    measure_P.PulseGenerator1_Amp_ep3 : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_iom) >=
      (measure_P.PulseGenerator1_Period_ep3 - 1.0)) {
    measure_DWork.clockTickCounter_iom = 0;
  } else {
    measure_DWork.clockTickCounter_iom = measure_DWork.clockTickCounter_iom + 1;
  }

  rtb_Compare_ddcrdcv = (rtb_Divide_hh0 >
    measure_P.Constant_Value_ep34emcngnxmtmb);
  rtb_Compare_enj = ((!rtb_Compare_ddcrdcv) && (measure_DWork.delay1_DSTATE_dtd));
  if (rtb_Compare_enj) {
    measure_B.Switch_lv2ap = measure_P.double_Value_dsc5ttdhqk;
  } else {
    measure_B.Switch_lv2ap = (measure_B.Divide_h +
      measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s4) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35bv;
  }

  rtb_Gain_pj = measure_P.FCn1_Gain * rtb_Switch;
  if (rtb_Gain_pj < measure_P.Constant_Value_gq) {
    rtb_Divide_hh0 = measure_P.Constant_Value_ep34em;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_ep34e) {
    rtb_Divide_hh0 = measure_P.Constant1_Value_ep;
  } else {
    rtb_Divide_hh0 = rtb_Gain_pj;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_ep34 * rtb_Divide_hh0;
  if (measure_P.Constant1_Value_ep34e) {
    measure_B.Switch2_f0 = rtb_Gain_pj + measure_P.Bias1_Bias_ep;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_cw5) {
    measure_B.Switch2_f0 = rtb_Gain_pj;
  } else {
    measure_B.Switch2_f0 = rtb_Gain_pj + measure_P.Bias_Bias_ep3;
  }

  {
    measure_B.SFunction_ct = (int32_T)measure_B.Switch2_f0;
  }

  if (measure_B.SFunction_ct < measure_P.Constant_Value_a2) {
    measure_B.Switch2_f0yhy = measure_P.Constant_Value_fp;
  } else if (measure_B.SFunction_ct > measure_P.Constant_Value_aq) {
    measure_B.Switch2_f0yhy = measure_P.Constant3_Value_ep;
  } else {
    measure_B.Switch2_f0yhy = measure_B.SFunction_ct;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteD_jelr5azsa0tej[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteD_obui2svtgpupg;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2ap;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_dsc5t;
      VDD_out++;
    }

    measure_B.VariableDiscreteD_amg5cres2anrb = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_dsc5t)
      *VDD_in = 0;
  }

  rtb_Compare_ks = (rtb_Compare_ddcrdcv && (measure_DWork.delay_DSTATE_izx));
  if (rtb_Compare_ks) {
    measure_B.Switch_lv2aps = measure_P.double_Value_dsc5ttdhqkx;
  } else {
    measure_B.Switch_lv2aps = (measure_B.Divide_h +
      measure_DWork.UnitDelay4_DSTAT_jbkwmsq2kv2s4v) +
      measure_DWork.UnitDelay2_DSTAT_gbjgk5qbx35bvz;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscrete_jelr5azsa0tejd[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscrete_obui2svtgpupg2;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_dsc5tt;
      VDD_out++;
    }

    measure_B.VariableDiscrete_amg5cres2anrbl = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_dsc5tt)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_m = measure_B.Switch_lv2ap -
      measure_B.VariableDiscreteD_amg5cres2anrb;
  } else {
    rtb_Divide_m = measure_B.Switch_lv2aps -
      measure_B.VariableDiscrete_amg5cres2anrbl;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_p3ok0il[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywi_asrwdnf;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_h;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_dsc;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywi_m0kftpo = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTw_dsc)
      measure_B.VariableDiscreteDelaywi_gpkwvfa = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywi_gpkwvfa = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_dsc)
      *VDD_in = 0;
  }

  rtb_Subtract3_lri = ((real_T)measure_B.Switch2_f0yhy) - rtb_Gain_pj;
  rtb_MathFunction_gbn2 = rtb_Subtract3_lri * rtb_Subtract3_lri;
  rtb_Subtract3_lri = (measure_P.Gain1_Gain_ep * rtb_Subtract3_lri) -
    rtb_MathFunction_gbn2;
  rtb_Gain_pj = rtb_Divide_m - ((measure_B.VariableDiscreteDelaywi_m0kftpo *
    rtb_Subtract3_lri) + (measure_B.VariableDiscreteDelaywi_gpkwvfa *
    rtb_MathFunction_gbn2));
  rtb_Divide_m = (1.0 / rtb_Divide_hh0) * measure_P.Gain_Gain_ep34e;
  rtb_Divide_hh0 = rtb_Gain_pj * rtb_Divide_m;
  if (rtb_Compare_enj) {
    measure_B.Switch_lv2aps4 = measure_P.double_Value_dsc5ttdh;
  } else {
    measure_B.Switch_lv2aps4 = (measure_B.Divide +
      measure_DWork.UnitDelay4_DSTA_jbkwmsq2kv2s4vv) +
      measure_DWork.UnitDelay2_DSTA_gbjgk5qbx35bvzo;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscret_jelr5azsa0tejde[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_obui2svtgpupg2k;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_dsc5ttd;
      VDD_out++;
    }

    measure_B.VariableDiscret_amg5cres2anrbla = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_dsc5ttd)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_lv2aps4n = measure_P.double_Value_dsc5ttdhq;
  } else {
    measure_B.Switch_lv2aps4n = (measure_B.Divide +
      measure_DWork.UnitDelay4_DSTA_g) + measure_DWork.UnitDelay2_DSTA_i;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_p[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_fy;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4n;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_dsc5ttdh;
      VDD_out++;
    }

    measure_B.VariableDiscret_i = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_dsc5ttdh)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_hh = measure_B.Switch_lv2aps4 -
      measure_B.VariableDiscret_amg5cres2anrbla;
  } else {
    rtb_Divide_hh = measure_B.Switch_lv2aps4n - measure_B.VariableDiscret_i;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_p3ok0ilk[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelayw_asrwdnf2;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_dsc5;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelayw_m0kftpos = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithT_dsc5)
      measure_B.VariableDiscreteDelayw_gpkwvfaj = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelayw_gpkwvfaj = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_dsc5)
      *VDD_in = 0;
  }

  rtb_Divide_hh = (rtb_Divide_hh - ((measure_B.VariableDiscreteDelayw_m0kftpos *
    rtb_Subtract3_lri) + (measure_B.VariableDiscreteDelayw_gpkwvfaj *
    rtb_MathFunction_gbn2))) * rtb_Divide_m;
  rtb_TrigonometricFunction_i = rt_atan2d_snf(rtb_Divide_hh0, rtb_Divide_hh);
  rtb_Add_p = rtb_TrigonometricFunction_i + rtb_Sum;
  if (rtb_Compare_j1k4d50fkuukjsr) {
    measure_B.Switch6 = rtb_Switch4;
  } else {
    rtb_Gain_pj = rtb_Add_p - rtb_Switch1_l;
    if (rtb_Gain_pj < measure_P.Constant_Value_ap) {
      rtb_Gain_pj += measure_P.Bias1_Bias_a;
    } else {
      if (rtb_Gain_pj > measure_P.Constant_Value_a) {
        rtb_Gain_pj += measure_P.Bias_Bias_a;
      }
    }

    rtb_Gain_pj *= measure_P.Gain_Gain_a;
    if (rtb_Gain_pj < measure_P.Constant_Value_icw1) {
      measure_B.Switch6 = measure_P.Constant_Value_icw;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_ic) {
      measure_B.Switch6 = measure_P.Constant1_Value_i;
    } else {
      measure_B.Switch6 = rtb_Gain_pj;
    }
  }

  if (rtb_Compare_ky) {
    measure_B.Switch_b = measure_P.double_Value_mz;
  } else {
    measure_B.Switch_b = (measure_B.Switch6 + measure_DWork.UnitDelay4_DSTA_n) +
      measure_DWork.UnitDelay2_DSTA_a;
  }

  rtb_Gain_pj = measure_P.FCn2_Gain * rtb_Switch;
  if (rtb_Gain_pj < measure_P.Constant_Value_m4) {
    rtb_Switch_jkaja = measure_P.Constant_Value_ep34emcn;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_ep34emc) {
    rtb_Switch_jkaja = measure_P.Constant1_Value_ep3;
  } else {
    rtb_Switch_jkaja = rtb_Gain_pj;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_ep34em * rtb_Switch_jkaja;
  if (measure_P.Constant1_Value_ep34em) {
    measure_B.Switch2_f0y = rtb_Gain_pj + measure_P.Bias1_Bias_ep3;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_iv) {
    measure_B.Switch2_f0y = rtb_Gain_pj;
  } else {
    measure_B.Switch2_f0y = rtb_Gain_pj + measure_P.Bias_Bias_ep34;
  }

  {
    measure_B.SFunction_ct5 = (int32_T)measure_B.Switch2_f0y;
  }

  if (measure_B.SFunction_ct5 < measure_P.Constant_Value_n3) {
    measure_B.Switch2_f0yhyr = measure_P.Constant_Value_hm;
  } else if (measure_B.SFunction_ct5 > measure_P.Constant_Value_k0) {
    measure_B.Switch2_f0yhyr = measure_P.Constant3_Value_ep3;
  } else {
    measure_B.Switch2_f0yhyr = measure_B.SFunction_ct5;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_l[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_ja;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_mz;
      VDD_out++;
    }

    measure_B.VariableDiscret_f = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_mz)
      *VDD_in = 0;
  }

  rtb_LogicalOperator_eg0 = (rtb_Compare_ddcrdc &&
    (measure_DWork.delay_DSTATE_izxx));
  if (rtb_LogicalOperator_eg0) {
    measure_B.Switch_bo = measure_P.double_Value_mzl;
  } else {
    measure_B.Switch_bo = (measure_B.Switch6 + measure_DWork.UnitDelay4_DSTA_d)
      + measure_DWork.UnitDelay2_DSTA_ai;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_e[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_fd;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_bo;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_mzl;
      VDD_out++;
    }

    measure_B.VariableDiscret_g = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_mzl)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_p3ok0ilkv[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelay_asrwdnf25;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch6;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_mz;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelay_m0kftposv = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_mz)
      measure_B.VariableDiscreteDelay_gpkwvfajc = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelay_gpkwvfajc = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_mz)
      *VDD_in = 0;
  }

  rtb_Ts_FFT_c = ((real_T)measure_B.Switch2_f0yhyr) - rtb_Gain_pj;
  rtb_Switch1_l = rtb_Ts_FFT_c * rtb_Ts_FFT_c;
  rtb_Switch = (measure_P.Gain1_Gain_ep3 * rtb_Ts_FFT_c) - rtb_Switch1_l;
  rtb_MathFunction1 = (1.0 / rtb_Switch_jkaja) * measure_P.Gain_Gain_ep34emc;
  if (rtb_Compare_j1k4d50fkuukjsr) {
    rtb_Ts_FFT_c = rtb_Switch4;
  } else {
    if (rtb_Compare_ddcrdc) {
      rtb_Gain_pj = measure_B.Switch_b - measure_B.VariableDiscret_f;
    } else {
      rtb_Gain_pj = measure_B.Switch_bo - measure_B.VariableDiscret_g;
    }

    rtb_Ts_FFT_c = (rtb_Gain_pj - ((measure_B.VariableDiscreteDelay_m0kftposv *
      rtb_Switch) + (measure_B.VariableDiscreteDelay_gpkwvfajc * rtb_Switch1_l)))
      * rtb_MathFunction1;
  }

  rtb_Bias = rtb_MathFunction2 + measure_P.Bias_Bias_o4;
  if (rtb_Compare_f) {
    rtb_Switch1_pwrmj = measure_DWork.UnitDelay1_DSTATE_aqjzxpn;
  } else {
    rtb_Switch1_pwrmj = measure_P.const_Value_od;
  }

  rtb_Compare_j1k4d50fkuukjsr = (rtb_Switch1_pwrmj ==
    measure_P.Constant_Value_odj);
  rtb_UnitDelay_i = measure_DWork.UnitDelay_DSTATE_m;
  rtb_Compare_f = (measure_DWork.UnitDelay_DSTATE_m <
                   measure_P.Constant_Value_i5);
  if (rtb_Compare_f) {
    rtb_Switch1_pwrmjy = measure_DWork.UnitDelay1_DSTATE_aqjzxpnn;
  } else {
    rtb_Switch1_pwrmjy = measure_P.const_Value_ki;
  }

  rtb_Compare_j1k4d50fkuukjs = (rtb_Switch1_pwrmjy ==
    measure_P.Constant_Value_ki);
  if (rtb_Compare_f) {
    rtb_UnitDelay1_lccp = measure_P.const_Value_k;
  } else {
    rtb_UnitDelay1_lccp = measure_DWork.UnitDelay1_DSTATE_aqjzxpnno;
  }

  rtb_Compare_f = (rtb_UnitDelay1_lccp == measure_P.Constant_Value_kix);
  rtb_LogicalOperator2_n = (((measure_DWork.UnitDelay_DSTATE_mj2f) ||
    rtb_Compare_j1k4d50fkuukjs) && (!rtb_Compare_f));
  rtb_LogicalOperator1 = (rtb_Compare_j1k4d50fkuukjsr && rtb_LogicalOperator2_n);

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.SF_FixedDiscreteDelaySfuncti_j0[0];
    int_T *VDD_in = (int_T*)&measure_DWork.SF_FixedDiscreteDelaySfunct_n5w;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_DWork.SF_FixedDiscreteDelaySfunctio_n;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfuncti_fc + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfuncti_fc;
    measure_B.SF_FixedDiscreteDelaySfunctio_o = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfuncti_fc)
      *VDD_in = 0;
  }

  rtb_Compare_g3iwu32gm4xoqly = (measure_B.SF_FixedDiscreteDelaySfunctio_o >
    measure_P.Constant_Value_fc);
  rtb_Switch_jkaja = ((rtb_MathFunction2 - measure_DWork.UnitDelay1_DSTATE_a) *
                      measure_P.Gain_Gain_d) * measure_P.Gain2_Gain_d;
  if (rtb_Switch_jkaja < measure_P.Constant_Value_dsc5t) {
    rtb_Switch_jkaja = -rtb_Switch_jkaja;
  }

  if (rtb_Compare_g3iwu32gm4xoqly && (rtb_Switch_jkaja >
       measure_P.Constant_Value_dsc5tt)) {
    rtb_Switch_e = measure_P.int32_Value_f;
  } else {
    rtb_Switch_e = measure_DWork.UnitDelay_DSTATE_i -
      measure_P.FixPtConstant_Value_f;
  }

  rtb_Compare_k = (rtb_Switch_e > measure_P.Constant_Value_fcb2ml45ca1);
  rtb_Switch_jkaja = ((rtb_MathFunction2_d - measure_DWork.UnitDelay1_DSTATE_aq)
                      * measure_P.Gain_Gain_d1) * measure_P.Gain2_Gain_d1;
  if (rtb_Switch_jkaja < measure_P.Constant_Value_d1m1h) {
    rtb_Switch_jkaja = -rtb_Switch_jkaja;
  }

  if (rtb_Compare_g3iwu32gm4xoqly && (rtb_Switch_jkaja >
       measure_P.Constant_Value_d1m1hi)) {
    rtb_Switch_er = measure_P.int32_Value_fc;
  } else {
    rtb_Switch_er = measure_DWork.UnitDelay_DSTATE_ia -
      measure_P.FixPtConstant_Value_fc;
  }

  rtb_Compare_k3 = (rtb_Switch_er > measure_P.Constant_Value_fcb2ml45ca13);
  rtb_Switch_jkaja = ((rtb_MathFunction2_d0 -
                       measure_DWork.UnitDelay1_DSTATE_aqj) *
                      measure_P.Gain_Gain_m0) * measure_P.Gain2_Gain_m;
  if (rtb_Switch_jkaja < measure_P.Constant_Value_m0413) {
    rtb_Switch_jkaja = -rtb_Switch_jkaja;
  }

  if (rtb_Compare_g3iwu32gm4xoqly && (rtb_Switch_jkaja >
       measure_P.Constant_Value_m0413r)) {
    rtb_Switch_ert = measure_P.int32_Value_fcb;
  } else {
    rtb_Switch_ert = measure_DWork.UnitDelay_DSTATE_iah -
      measure_P.FixPtConstant_Value_fcb;
  }

  rtb_Compare_k3k = (rtb_Switch_ert > measure_P.Constant_Value_fcb2ml45ca13t);
  rtb_Disturbance_All_Phases = ((rtb_Compare_k && rtb_Compare_k3) &&
    rtb_Compare_k3k);
  if (rtb_Compare_gw) {
    rtb_Switch1_dg2as0 = measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4;
  } else {
    rtb_Switch1_dg2as0 = measure_P.const_Value_kcq;
  }

  rtb_Compare_g3iwu32gm4xoqly = (rtb_Switch1_dg2as0 ==
    measure_P.Constant_Value_kcq);
  rtb_UnitDelay_it = measure_DWork.UnitDelay_DSTATE_mj;
  rtb_Compare_gw = (measure_DWork.UnitDelay_DSTATE_mj <
                    measure_P.Constant_Value_mw);
  if (rtb_Compare_gw) {
    rtb_Switch1_dg2as0w = measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4m;
  } else {
    rtb_Switch1_dg2as0w = measure_P.const_Value_ma;
  }

  rtb_Compare_g3iwu32gm4xoql = (rtb_Switch1_dg2as0w ==
    measure_P.Constant_Value_ma);
  if (rtb_Compare_gw) {
    rtb_Switch1_dg2as0wb = measure_P.const_Value_m;
  } else {
    rtb_Switch1_dg2as0wb = measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml;
  }

  rtb_Compare_gw = (rtb_Switch1_dg2as0wb == measure_P.Constant_Value_maw);
  rtb_LogicalOperator2_npq = (((measure_DWork.UnitDelay_DSTATE_mj2fm) ||
    rtb_Compare_g3iwu32gm4xoql) && (!rtb_Compare_gw));
  rtb_LogicalOperator2_npqx = (rtb_Compare_g3iwu32gm4xoqly &&
    rtb_LogicalOperator2_npq);
  if (rtb_Compare_ji) {
    rtb_Switch1_mf0c2 = measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml3;
  } else {
    rtb_Switch1_mf0c2 = measure_P.const_Value_okw;
  }

  rtb_Compare_ji = (rtb_Switch1_mf0c2 == measure_P.Constant_Value_okw1);
  rtb_UnitDelay_itx = measure_DWork.UnitDelay_DSTATE_mj2;
  rtb_Compare_il = (measure_DWork.UnitDelay_DSTATE_mj2 <
                    measure_P.Constant_Value_pt);
  if (rtb_Compare_il) {
    rtb_Switch1_mf0c25 = measure_DWork.UnitDelay1_DSTAT_aqjzxpnno4ml3e;
  } else {
    rtb_Switch1_mf0c25 = measure_P.const_Value_my5;
  }

  rtb_Compare_dtgasgy1ciwmtjh = (rtb_Switch1_mf0c25 ==
    measure_P.Constant_Value_my);
  if (rtb_Compare_il) {
    rtb_Switch1_mf0c25z = measure_P.const_Value_my;
  } else {
    rtb_Switch1_mf0c25z = measure_DWork.UnitDelay1_DSTA_aqjzxpnno4ml3e2;
  }

  rtb_Compare_il = (rtb_Switch1_mf0c25z == measure_P.Constant_Value_my5);
  rtb_LogicalOperator2_npqxo = (((measure_DWork.UnitDelay_DSTATE_mj2fmb) ||
    rtb_Compare_dtgasgy1ciwmtjh) && (!rtb_Compare_il));
  rtb_LogicalOperator2_npqxol = (rtb_Compare_ji && rtb_LogicalOperator2_npqxo);
  rtb_LogicalOperator12 = ((rtb_LogicalOperator1 || rtb_LogicalOperator2_npqx) ||
    rtb_LogicalOperator2_npqxol);
  if (rtb_LogicalOperator12) {
    rtb_Any_Phases_Not_Disturbed = !rtb_Disturbance_All_Phases;
    rtb_Switch6_idx = (rtb_LogicalOperator1 && (!(rtb_Compare_k &&
      rtb_Any_Phases_Not_Disturbed)));
    rtb_LogicalOperator2_npqx = (rtb_LogicalOperator2_npqx && (!(rtb_Compare_k3 &&
      rtb_Any_Phases_Not_Disturbed)));
    rtb_LogicalOperator1 = (rtb_LogicalOperator2_npqxol && (!(rtb_Compare_k3k &&
      rtb_Any_Phases_Not_Disturbed)));
  } else {
    rtb_Switch6_idx = rtb_Compare_j1k4d50fkuukj;
    rtb_LogicalOperator2_npqx = rtb_Compare_g3iwu32gm4xoq;
    rtb_LogicalOperator1 = rtb_Compare_dtgasgy1ciwmtj;
  }

  if (rtb_Switch6_idx) {
    rtb_Gain_pj = rtb_Bias * rtb_Bias;
    if (rtb_Gain_pj < measure_P.Constant_Value_cw1ksr) {
      rtb_Switch_jkaja = measure_P.Constant_Value_cw1ks;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_cw1k) {
      rtb_Switch_jkaja = measure_P.Constant1_Value_cw;
    } else {
      rtb_Switch_jkaja = rtb_Gain_pj;
    }

    if (!(rtb_Switch_jkaja < measure_P.Constant_Value_cw1ksrz)) {
      rtb_Switch_jkaja = 1.0 / rtb_Switch_jkaja;
    }
  } else {
    rtb_Switch_jkaja = measure_P.Constant2_Value;
  }

  rtb_Switch1_ie = rtb_Ts_FFT_c * rtb_Switch_jkaja;
  rtb_LogicalOperator1_pvh3 = (rtb_Compare_jsl || (!(rtb_Compare_g3iwu32gm4xoq ||
    rtb_LogicalOperator9)));
  rtb_Gain_pj = measure_DWork.UnitDelay3_DSTATE_i5;
  if (rtb_Compare_enj) {
    measure_B.Switch_f0o4o = measure_P.double_Value_d1m1hiqruq;
  } else {
    measure_B.Switch_f0o4o = (measure_B.Divide_b4 +
      measure_DWork.UnitDelay4_DSTA_i) + measure_DWork.UnitDelay2_DSTA_m;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_c[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_ng;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4o;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_d1m1hi;
      VDD_out++;
    }

    measure_B.VariableDiscret_h = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_d1m1hi)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_f0o4ow = measure_P.double_Value_d1m1hiqruqx;
  } else {
    measure_B.Switch_f0o4ow = (measure_B.Divide_b4 +
      measure_DWork.UnitDelay4_DSTA_n3) + measure_DWork.UnitDelay2_DSTA_il;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_k[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_gm;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4ow;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_d1m1hiq;
      VDD_out++;
    }

    measure_B.VariableDiscret_hi = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_d1m1hiq)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_b4h = measure_B.Switch_f0o4o - measure_B.VariableDiscret_h;
  } else {
    rtb_Divide_b4h = measure_B.Switch_f0o4ow - measure_B.VariableDiscret_hi;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_p3ok0ilkvg[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDela_asrwdnf25g;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_b4;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_d1m1;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDela_m0kftposvc = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithT_d1m1)
      measure_B.VariableDiscreteDela_gpkwvfajco = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDela_gpkwvfajco = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_d1m1)
      *VDD_in = 0;
  }

  rtb_Divide_b4h = (rtb_Divide_b4h - ((measure_B.VariableDiscreteDela_m0kftposvc
    * rtb_Subtract3_lri) + (measure_B.VariableDiscreteDela_gpkwvfajco *
    rtb_MathFunction_gbn2))) * rtb_Divide_m;
  if (rtb_Compare_enj) {
    measure_B.Switch_f0o4owl = measure_P.double_Value_d1m1hiqr;
  } else {
    measure_B.Switch_f0o4owl = (measure_B.Divide_b +
      measure_DWork.UnitDelay4_DSTA_a) + measure_DWork.UnitDelay2_DSTA_b;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_i[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_lb;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owl;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_d1m1hiqr;
      VDD_out++;
    }

    measure_B.VariableDiscret_o = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_d1m1hiqr)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_f0o4owld = measure_P.double_Value_d1m1hiqru;
  } else {
    measure_B.Switch_f0o4owld = (measure_B.Divide_b +
      measure_DWork.UnitDelay4_DSTA_j) + measure_DWork.UnitDelay2_DSTA_h;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_p0[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_jso;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owld;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_d1m1hiqru;
      VDD_out++;
    }

    measure_B.VariableDiscret_oy = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_d1m1hiqru)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_b4ha = measure_B.Switch_f0o4owl - measure_B.VariableDiscret_o;
  } else {
    rtb_Divide_b4ha = measure_B.Switch_f0o4owld - measure_B.VariableDiscret_oy;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_p3ok0ilkvgc[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDel_asrwdnf25g3;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_b;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_d1m1hiqruq;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDel_m0kftposvcp = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDela_d1m1hiqruq)
      measure_B.VariableDiscreteDel_gpkwvfajco2 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDel_gpkwvfajco2 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_d1m1hiqruq)
      *VDD_in = 0;
  }

  rtb_Divide_b4ha = (rtb_Divide_b4ha -
                     ((measure_B.VariableDiscreteDel_m0kftposvcp *
                       rtb_Subtract3_lri) +
                      (measure_B.VariableDiscreteDel_gpkwvfajco2 *
                       rtb_MathFunction_gbn2))) * rtb_Divide_m;
  rtb_TrigonometricFunction_ix = rt_atan2d_snf(rtb_Divide_b4h, rtb_Divide_b4ha);
  rtb_Add_n = rtb_TrigonometricFunction_ix + rtb_Sum;
  if (rtb_LogicalOperator1_pvh3) {
    measure_B.Switch6_j = rtb_Switch4;
  } else {
    rtb_Gain_pj = rtb_Add_n - rtb_Gain_pj;
    if (rtb_Gain_pj < measure_P.Constant_Value_i2j) {
      rtb_Gain_pj += measure_P.Bias1_Bias_i;
    } else {
      if (rtb_Gain_pj > measure_P.Constant_Value_i2) {
        rtb_Gain_pj += measure_P.Bias_Bias_i;
      }
    }

    rtb_Gain_pj *= measure_P.Gain_Gain_i;
    if (rtb_Gain_pj < measure_P.Constant_Value_im3r) {
      measure_B.Switch6_j = measure_P.Constant_Value_im3;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_im) {
      measure_B.Switch6_j = measure_P.Constant1_Value_im;
    } else {
      measure_B.Switch6_j = rtb_Gain_pj;
    }
  }

  if (rtb_Compare_ky) {
    measure_B.Switch_f0o4owldo = measure_P.double_Value_on;
  } else {
    measure_B.Switch_f0o4owldo = (measure_B.Switch6_j +
      measure_DWork.UnitDelay4_DSTA_p) + measure_DWork.UnitDelay2_DSTA_o;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_a[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_fl;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldo;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_o;
      VDD_out++;
    }

    measure_B.VariableDiscret_j = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_o)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_eg0) {
    measure_B.Switch_f0o4owldoy = measure_P.double_Value_ony;
  } else {
    measure_B.Switch_f0o4owldoy = (measure_B.Switch6_j +
      measure_DWork.UnitDelay4_DSTA_jg) + measure_DWork.UnitDelay2_DSTA_f;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_m[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_ney;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldoy;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_on;
      VDD_out++;
    }

    measure_B.VariableDiscret_b = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_on)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_p3ok0ilkvgcl[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDe_asrwdnf25g35;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch6_j;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_o;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDe_m0kftposvcp0 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_o)
      measure_B.VariableDiscreteDe_gpkwvfajco2k = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDe_gpkwvfajco2k = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_o)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator1_pvh3) {
    rtb_Ts_FFT = rtb_Switch4;
  } else {
    if (rtb_Compare_ddcrdc) {
      rtb_Gain_pj = measure_B.Switch_f0o4owldo - measure_B.VariableDiscret_j;
    } else {
      rtb_Gain_pj = measure_B.Switch_f0o4owldoy - measure_B.VariableDiscret_b;
    }

    rtb_Ts_FFT = (rtb_Gain_pj - ((measure_B.VariableDiscreteDe_m0kftposvcp0 *
      rtb_Switch) + (measure_B.VariableDiscreteDe_gpkwvfajco2k * rtb_Switch1_l)))
      * rtb_MathFunction1;
  }

  rtb_Bias1 = rtb_MathFunction2_d + measure_P.Bias1_Bias_o4;
  if (rtb_LogicalOperator2_npqx) {
    rtb_Gain_pj = rtb_Bias1 * rtb_Bias1;
    if (rtb_Gain_pj < measure_P.Constant_Value_cw1ksrzc22) {
      rtb_Switch_jka = measure_P.Constant_Value_cw1ksrzc2;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_cw1ksrzc) {
      rtb_Switch_jka = measure_P.Constant1_Value_cw1;
    } else {
      rtb_Switch_jka = rtb_Gain_pj;
    }

    if (!(rtb_Switch_jka < measure_P.Constant_Value_cw1ksrzc22q)) {
      rtb_Switch_jka = 1.0 / rtb_Switch_jka;
    }
  } else {
    rtb_Switch_jka = measure_P.Constant2_Value_c;
  }

  rtb_Compare_jsl = (rtb_Compare_jsl || (!(rtb_Compare_dtgasgy1ciwmtj ||
    rtb_LogicalOperator9)));
  rtb_Gain_pj = measure_DWork.UnitDelay3_DSTATE_i5z;
  if (rtb_Compare_enj) {
    measure_B.Switch_ngeqq2 = measure_P.double_Value_m0413rfkrd;
  } else {
    measure_B.Switch_ngeqq2 = (measure_B.Divide_nq +
      measure_DWork.UnitDelay4_DSTA_ih) + measure_DWork.UnitDelay2_DSTA_j;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ci[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_hc;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_m0413;
      VDD_out++;
    }

    measure_B.VariableDiscret_b1 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_m0413)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_ngeqq2o = measure_P.double_Value_m0413rfkrd2;
  } else {
    measure_B.Switch_ngeqq2o = (measure_B.Divide_nq +
      measure_DWork.UnitDelay4_DSTA_m) + measure_DWork.UnitDelay2_DSTA_jm;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_f[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_gn;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2o;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_m0413r;
      VDD_out++;
    }

    measure_B.VariableDiscret_c = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_m0413r)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_nqz = measure_B.Switch_ngeqq2 - measure_B.VariableDiscret_b1;
  } else {
    rtb_Divide_nqz = measure_B.Switch_ngeqq2o - measure_B.VariableDiscret_c;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_p3ok0ilkvgclo[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteD_asrwdnf25g35f;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nq;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_m04;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteD_m0kftposvcp0f = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTw_m04)
      measure_B.VariableDiscreteD_gpkwvfajco2kr = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteD_gpkwvfajco2kr = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_m04)
      *VDD_in = 0;
  }

  rtb_Divide_nqz = (rtb_Divide_nqz - ((measure_B.VariableDiscreteD_m0kftposvcp0f
    * rtb_Subtract3_lri) + (measure_B.VariableDiscreteD_gpkwvfajco2kr *
    rtb_MathFunction_gbn2))) * rtb_Divide_m;
  if (rtb_Compare_enj) {
    measure_B.Switch_ngeqq2os = measure_P.double_Value_m0413rfk;
  } else {
    measure_B.Switch_ngeqq2os = (measure_B.Divide_n +
      measure_DWork.UnitDelay4_DSTA_j5) + measure_DWork.UnitDelay2_DSTA_c;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_g[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_ne3;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2os;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_m0413rf;
      VDD_out++;
    }

    measure_B.VariableDiscret_g3 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_m0413rf)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_ngeqq2osh = measure_P.double_Value_m0413rfkr;
  } else {
    measure_B.Switch_ngeqq2osh = (measure_B.Divide_n +
      measure_DWork.UnitDelay4_DSTA_dj) + measure_DWork.UnitDelay2_DSTA_cm;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_l2[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_it;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2osh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_m0413rfk;
      VDD_out++;
    }

    measure_B.VariableDiscret_l = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_m0413rfk)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_nqzy = measure_B.Switch_ngeqq2os - measure_B.VariableDiscret_g3;
  } else {
    rtb_Divide_nqzy = measure_B.Switch_ngeqq2osh - measure_B.VariableDiscret_l;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_p3ok0ilkvgclom[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscrete_asrwdnf25g35fl;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_n;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_m041;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscrete_m0kftposvcp0f2 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithT_m041)
      measure_B.VariableDiscrete_gpkwvfajco2krn = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscrete_gpkwvfajco2krn = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_m041)
      *VDD_in = 0;
  }

  rtb_Divide_nqzy = (rtb_Divide_nqzy -
                     ((measure_B.VariableDiscrete_m0kftposvcp0f2 *
                       rtb_Subtract3_lri) +
                      (measure_B.VariableDiscrete_gpkwvfajco2krn *
                       rtb_MathFunction_gbn2))) * rtb_Divide_m;
  rtb_TrigonometricFunction_ixv = rt_atan2d_snf(rtb_Divide_nqz, rtb_Divide_nqzy);
  rtb_Add_gl = rtb_TrigonometricFunction_ixv + rtb_Sum;
  if (rtb_Compare_jsl) {
    measure_B.Switch6_m = rtb_Switch4;
  } else {
    rtb_Gain_pj = rtb_Add_gl - rtb_Gain_pj;
    if (rtb_Gain_pj < measure_P.Constant_Value_or) {
      rtb_Gain_pj += measure_P.Bias1_Bias_o;
    } else {
      if (rtb_Gain_pj > measure_P.Constant_Value_o) {
        rtb_Gain_pj += measure_P.Bias_Bias_o;
      }
    }

    rtb_Gain_pj *= measure_P.Gain_Gain_o;
    if (rtb_Gain_pj < measure_P.Constant_Value_jjoq) {
      measure_B.Switch6_m = measure_P.Constant_Value_jjo;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_jj) {
      measure_B.Switch6_m = measure_P.Constant1_Value_jj;
    } else {
      measure_B.Switch6_m = rtb_Gain_pj;
    }
  }

  if (rtb_Compare_ky) {
    measure_B.Switch_ngeqq2oshh = measure_P.double_Value_ao;
  } else {
    measure_B.Switch_ngeqq2oshh = (measure_B.Switch6_m +
      measure_DWork.UnitDelay4_DSTA_l) + measure_DWork.UnitDelay2_DSTA_p;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ii[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_jh;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_a;
      VDD_out++;
    }

    measure_B.VariableDiscret_b4 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_a)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_eg0) {
    measure_B.Switch_ngeqq2oshhr = measure_P.double_Value_aov;
  } else {
    measure_B.Switch_ngeqq2oshhr = (measure_B.Switch6_m +
      measure_DWork.UnitDelay4_DSTA_h) + measure_DWork.UnitDelay2_DSTA_bf;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_id[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_bv;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshhr;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_ao;
      VDD_out++;
    }

    measure_B.VariableDiscret_a = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_ao)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_p3ok0ilkvgclom3[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_asrwdnf25g35flg;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch6_m;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_a;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_m0kftposvcp0f2x = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_a)
      measure_B.VariableDiscret_gpkwvfajco2krnd = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_gpkwvfajco2krnd = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_a)
      *VDD_in = 0;
  }

  if (!rtb_Compare_jsl) {
    if (rtb_Compare_ddcrdc) {
      rtb_Gain_pj = measure_B.Switch_ngeqq2oshh - measure_B.VariableDiscret_b4;
    } else {
      rtb_Gain_pj = measure_B.Switch_ngeqq2oshhr - measure_B.VariableDiscret_a;
    }

    rtb_Switch4 = (rtb_Gain_pj - ((measure_B.VariableDiscret_m0kftposvcp0f2x *
      rtb_Switch) + (measure_B.VariableDiscret_gpkwvfajco2krnd * rtb_Switch1_l)))
      * rtb_MathFunction1;
  }

  rtb_Bias2 = rtb_MathFunction2_d0 + measure_P.Bias2_Bias_o4;
  if (rtb_LogicalOperator1) {
    rtb_Gain_pj = rtb_Bias2 * rtb_Bias2;
    if (rtb_Gain_pj < measure_P.Constant_Value_cw1ksrzc22qlb1) {
      rtb_Switch_j = measure_P.Constant_Value_cw1ksrzc22qlb;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_cw1ksrzc22ql) {
      rtb_Switch_j = measure_P.Constant1_Value_cw1k;
    } else {
      rtb_Switch_j = rtb_Gain_pj;
    }

    if (!(rtb_Switch_j < measure_P.Constant_Value_cw1ksrzc22qlb13)) {
      rtb_Switch_j = 1.0 / rtb_Switch_j;
    }
  } else {
    rtb_Switch_j = measure_P.Constant2_Value_cw;
  }

  rtb_Switch_jkaja += rtb_Switch_jka;
  rtb_Switch_jkaja += rtb_Switch_j;
  if (rtb_Switch_jkaja < measure_P.Constant_Value_fe) {
    rtb_Switch_jkaja = measure_P.Constant_Value_c;
  }

  rtb_Gain_pj = (((rtb_Ts_FFT * rtb_Switch_jka) + rtb_Switch1_ie) + (rtb_Switch4
    * rtb_Switch_j)) / rtb_Switch_jkaja;
  if (rtb_Gain_pj < measure_P.Constant_Value_go) {
    measure_B.Switch_j = measure_P.Constant_Value_cw1;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_cw) {
    measure_B.Switch_j = measure_P.Constant1_Value_c;
  } else {
    measure_B.Switch_j = rtb_Gain_pj;
  }

  rtb_Switch_j = ((((real_T)measure_DWork.clockTickCounter_h) <
                   measure_P.PulseGenerator1_Duty_m) &&
                  (measure_DWork.clockTickCounter_h >= 0)) ?
    measure_P.PulseGenerator1_Amp_m : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_h) >=
      (measure_P.PulseGenerator1_Period_m - 1.0)) {
    measure_DWork.clockTickCounter_h = 0;
  } else {
    measure_DWork.clockTickCounter_h = measure_DWork.clockTickCounter_h + 1;
  }

  rtb_Switch6_idx = (rtb_Switch_j > measure_P.Constant_Value_goh);
  rtb_LogicalOperator1_pvh3 = ((!rtb_Switch6_idx) &&
    (measure_DWork.delay1_DSTATE_k));
  if (rtb_LogicalOperator1_pvh3) {
    measure_B.Switch_ll = measure_P.double_Value_mq;
  } else {
    measure_B.Switch_ll = (measure_B.Switch_j +
      measure_DWork.UnitDelay4_DSTATE_e) + measure_DWork.UnitDelay2_DSTATE_e5;
  }

  if (measure_DWork.UnitDelay2_DSTATE_e5y < measure_P.Constant_Value_ao) {
    rtb_Switch_j = measure_P.Constant_Value_mqco2gbunewgp;
  } else if (measure_DWork.UnitDelay2_DSTATE_e5y >
             measure_P.Constant_Value_mqco2gbunewg) {
    rtb_Switch_j = measure_P.Constant1_Value_mqco;
  } else {
    rtb_Switch_j = measure_DWork.UnitDelay2_DSTATE_e5y;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_mq * rtb_Switch_j;
  if (measure_P.Constant1_Value_mqco2gb) {
    measure_B.Switch2_d = rtb_Gain_pj + measure_P.Bias1_Bias_mq;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_imx) {
    measure_B.Switch2_d = rtb_Gain_pj;
  } else {
    measure_B.Switch2_d = rtb_Gain_pj + measure_P.Bias_Bias_mq;
  }

  {
    measure_B.SFunction_j = (int32_T)measure_B.Switch2_d;
  }

  if (measure_B.SFunction_j < measure_P.Constant_Value_eq) {
    measure_B.Switch2_dmf4 = measure_P.Constant_Value_m5;
  } else if (measure_B.SFunction_j > measure_P.Constant_Value_kt) {
    measure_B.Switch2_dmf4 = measure_P.Constant3_Value_m;
  } else {
    measure_B.Switch2_dmf4 = measure_B.SFunction_j;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_px[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_iq;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ll;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_mq;
      VDD_out++;
    }

    measure_B.VariableDiscret_e = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_mq)
      *VDD_in = 0;
  }

  rtb_LogicalOperator_eg0 = (rtb_Switch6_idx && (measure_DWork.delay_DSTATE_j));
  if (rtb_LogicalOperator_eg0) {
    measure_B.Switch_lli = measure_P.double_Value_mqc;
  } else {
    measure_B.Switch_lli = (measure_B.Switch_j +
      measure_DWork.UnitDelay4_DSTATE_ed) + measure_DWork.UnitDelay2_DSTATE_e5yc;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_b[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_ec;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lli;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_mqc;
      VDD_out++;
    }

    measure_B.VariableDiscret_hh = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_mqc)
      *VDD_in = 0;
  }

  if (rtb_Switch6_idx) {
    rtb_Switch_jka = measure_B.Switch_ll - measure_B.VariableDiscret_e;
  } else {
    rtb_Switch_jka = measure_B.Switch_lli - measure_B.VariableDiscret_hh;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a3[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_fz;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch_j;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_mq;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_os = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_mq)
      measure_B.VariableDiscret_d = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_d = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_mq)
      *VDD_in = 0;
  }

  rtb_Switch_jkaja = ((real_T)measure_B.Switch2_dmf4) - rtb_Gain_pj;
  rtb_MathFunction_pl = rtb_Switch_jkaja * rtb_Switch_jkaja;
  rtb_Switch_jkaja = (measure_P.Gain1_Gain_mq * rtb_Switch_jkaja) -
    rtb_MathFunction_pl;
  rtb_Switch_j = (1.0 / rtb_Switch_j) * measure_P.Gain_Gain_mqc;
  rtb_Switch_jka = (rtb_Switch_jka - ((measure_B.VariableDiscret_os *
    rtb_Switch_jkaja) + (measure_B.VariableDiscret_d * rtb_MathFunction_pl))) *
    rtb_Switch_j;
  measure_B.ACripple1stestimate_n = measure_B.Switch_j - rtb_Switch_jka;
  if (measure_B.ACripple1stestimate_n < measure_P.Constant_Value_ip) {
    rtb_IpktoIrmsconversion = -measure_B.ACripple1stestimate_n;
  } else {
    rtb_IpktoIrmsconversion = measure_B.ACripple1stestimate_n;
  }

  if (rtb_IpktoIrmsconversion > (measure_P.Gain_Gain_jo *
       measure_P.Constant2_Value_h)) {
    rtb_Switch_lli5ykm = measure_P.int32_Value_m;
  } else {
    rtb_Switch_lli5ykm = measure_DWork.UnitDelay_DSTATE_ot -
      measure_P.FixPtConstant_Value_m;
  }

  rtb_Compare_ky = (rtb_Switch_lli5ykm > measure_P.Constant_Value_jf);
  if (rtb_Compare_ky) {
    rtb_Switch_jka = measure_B.Switch_j;
  }

  if (!(((rtb_Switch1_iew < (rtb_Switch_jka - measure_P.Constant6_Value)) ||
         (rtb_Switch1_iew > (rtb_Switch_jka + measure_P.Constant6_Value))) &&
        rtb_LogicalOperator16)) {
    rtb_UnitDelay1_b = measure_P.const_Value_hu;
  }

  rtb_Compare_jsl = (rtb_UnitDelay1_b == measure_P.Constant_Value_hu);
  if (rtb_Compare_jsl) {
    rtb_Bias_aswd3 = measure_P.int32_Value_h;
  } else {
    rtb_Bias_aswd3 = measure_DWork.UnitDelay_DSTATE_k -
      measure_P.FixPtConstant_Value_hu;
  }

  rtb_Compare_js = (rtb_Bias_aswd3 > measure_P.Constant_Value_huy);
  rtb_LogicalOperator2_f3 = (rtb_Compare_jsl || ((!((!rtb_LogicalOperator16) ||
                                ((!rtb_Compare_js) &&
    (measure_DWork.delay1_DSTATE_b)))) && (measure_DWork.UnitDelay1_DSTATE_k2)));
  rtb_LogicalOperator2_f3l = ((measure_P.Constant1_Value_h) &&
    (rtb_LogicalOperator2_f3 || ((rtb_LogicalOperator16 && (((rtb_Switch_jka <
    measure_P.Constant_Value_fx) || (!rtb_LogicalOperator12)) || rtb_Compare_ky))
    || (measure_P.Constant_Value_b5))));
  if (rtb_LogicalOperator2_f3l) {
    measure_B.Switch_bn = rtb_Switch1_iew;
  } else {
    measure_B.Switch_bn = rtb_Switch_jka;
  }

  if (rtb_UnitDelay4_dq) {
    rtb_Switch_k = rtb_Switch1;
  } else {
    rtb_Switch_k = measure_B.Switch_bn;
  }

  if (measure_P.Constant6_Value_f) {
    rtb_LogicalOperator1 = rtb_LogicalOperator2_f3l;
  } else {
    rtb_LogicalOperator1 = measure_P.Constant5_Value_i;
  }

  if ((rtb_LogicalOperator12 || rtb_UnitDelay4_dq) || rtb_LogicalOperator1) {
    measure_Y.Frequency = rtb_Switch_k;
  } else {
    measure_Y.Frequency = measure_P.Constant1_Value_b;
  }

  rtb_IpktoIrmsconversion = measure_P.Gain3_Gain * measure_P.Constant1_Value_m2;
  rtb_Switch_jka = (rtb_Divide_hh * rtb_Divide_hh) + (rtb_Divide_hh0 *
    rtb_Divide_hh0);
  rtb_Gain_pj = (rtb_Switch_jka < 0.0) ? (-std::sqrt(std::abs(rtb_Switch_jka))) :
    std::sqrt(rtb_Switch_jka);
  rtb_SumofElements = rtb_IpktoIrmsconversion * rtb_Gain_pj;
  rtb_IpktoIrms_n = (rtb_Divide_b4ha * rtb_Divide_b4ha) + (rtb_Divide_b4h *
    rtb_Divide_b4h);
  rtb_IpktoIrms_n = (rtb_IpktoIrms_n < 0.0) ? (-std::sqrt(std::abs
    (rtb_IpktoIrms_n))) : std::sqrt(rtb_IpktoIrms_n);
  rtb_AbsVI = rtb_IpktoIrmsconversion * rtb_IpktoIrms_n;
  rtb_Switch_jpt = (rtb_Divide_nqzy * rtb_Divide_nqzy) + (rtb_Divide_nqz *
    rtb_Divide_nqz);
  rtb_Switch_jpt = (rtb_Switch_jpt < 0.0) ? (-std::sqrt(std::abs(rtb_Switch_jpt)))
    : std::sqrt(rtb_Switch_jpt);
  rtb_AbsVI_k = rtb_IpktoIrmsconversion * rtb_Switch_jpt;
  rtb_UnaryMinus_g = measure_P.ScaleRMSoutputsto1pu_Gain * rtb_Sum1_lle;
  measure_B.MathFunction = rtb_UnaryMinus_g * rtb_UnaryMinus_g;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_lv2aps4ne = measure_P.double_Value_dsc5ttdhqkxi;
  } else {
    measure_B.Switch_lv2aps4ne = (measure_B.MathFunction +
      measure_DWork.UnitDelay4_DSTA_mm) + measure_DWork.UnitDelay2_DSTA_hi;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_h[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_kd;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4ne;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_dsc5ttdhq;
      VDD_out++;
    }

    measure_B.VariableDiscret_m = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_dsc5ttdhq)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_lv2aps4ney = measure_P.double_Value_dsc5ttdhqkxiz;
  } else {
    measure_B.Switch_lv2aps4ney = (measure_B.MathFunction +
      measure_DWork.UnitDelay4_DSTA_pb) + measure_DWork.UnitDelay2_DSTA_iy;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_bo[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_ky;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4ney;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_dsc5ttdhqk;
      VDD_out++;
    }

    measure_B.VariableDiscret_of = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_dsc5ttdhqk)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_UnaryMinus_g = measure_B.Switch_lv2aps4ne - measure_B.VariableDiscret_m;
  } else {
    rtb_UnaryMinus_g = measure_B.Switch_lv2aps4ney -
      measure_B.VariableDiscret_of;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_o[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_cc;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_dsc5ttdhqkx;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_n = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDel_dsc5ttdhqkx)
      measure_B.VariableDiscret_eg = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_eg = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_dsc5ttdhqkx)
      *VDD_in = 0;
  }

  rtb_UnaryMinus_g = (rtb_UnaryMinus_g - ((measure_B.VariableDiscret_n *
    rtb_Subtract3_lr) + (measure_B.VariableDiscret_eg * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  measure_B.MathFunction1 = (rtb_UnaryMinus_g < 0.0) ? (-std::sqrt(std::abs
    (rtb_UnaryMinus_g))) : std::sqrt(rtb_UnaryMinus_g);
  if (rtb_Compare_enj) {
    measure_B.Switch_lv2aps4neyb = measure_P.double_Value_ds;
  } else {
    measure_B.Switch_lv2aps4neyb = (measure_B.MathFunction1 +
      measure_DWork.UnitDelay4_DSTA_md) + measure_DWork.UnitDelay2_DSTA_c0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_im[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_fn;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4neyb;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_dsc5ttdhqkxi;
      VDD_out++;
    }

    measure_B.VariableDiscret_bb = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_dsc5ttdhqkxi)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_lv2aps4neybf = measure_P.double_Value_dsc;
  } else {
    measure_B.Switch_lv2aps4neybf = (measure_B.MathFunction1 +
      measure_DWork.UnitDelay4_DSTA_f) + measure_DWork.UnitDelay2_DSTA_cq;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_hs[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_cn;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4neybf;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_dsc5ttdhqkxiz;
      VDD_out++;
    }

    measure_B.VariableDiscret_jo = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_dsc5ttdhqkxiz)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_UnaryMinus_g = measure_B.Switch_lv2aps4neyb -
      measure_B.VariableDiscret_bb;
  } else {
    rtb_UnaryMinus_g = measure_B.Switch_lv2aps4neybf -
      measure_B.VariableDiscret_jo;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pe[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_k3;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_dsc5ttdhqkxizv;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_ln = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscrete_dsc5ttdhqkxizv)
      measure_B.VariableDiscret_dh = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_dh = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_dsc5ttdhqkxizv)
      *VDD_in = 0;
  }

  rtb_UnaryMinus_g = (rtb_UnaryMinus_g - ((measure_B.VariableDiscret_ln *
    rtb_Subtract3_lri) + (measure_B.VariableDiscret_dh * rtb_MathFunction_gbn2)))
    * rtb_Divide_m;
  rtb_UnaryMinus_g = (rtb_UnaryMinus_g * rtb_UnaryMinus_g) - (rtb_Gain_pj *
    rtb_Gain_pj);
  if (rtb_UnaryMinus_g < measure_P.Constant_Value_dsc5ttd) {
    rtb_UnaryMinus_g = measure_P.Constant_Value_ds;
  }

  if (rtb_Gain_pj < measure_P.Constant_Value_dsc5ttdh) {
    rtb_Gain_pj = measure_P.Constant_Value_dsc;
  }

  rtb_UnaryMinus_g = (((rtb_UnaryMinus_g < 0.0) ? (-std::sqrt(std::abs
    (rtb_UnaryMinus_g))) : std::sqrt(rtb_UnaryMinus_g)) / rtb_Gain_pj) *
    measure_P.Gain_Gain_ds;
  if (rtb_UnaryMinus_g > measure_P.Constant_Value_dsc5ttdhq) {
    rtb_UnaryMinus_g = measure_P.Constant_Value_dsc5;
  }

  rtb_Switch_jka = measure_P.ScaleRMSoutputsto1pu_Gain_d * rtb_Sum1_p5;
  measure_B.MathFunction_j = rtb_Switch_jka * rtb_Switch_jka;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_f0o4owldoyu = measure_P.double_Value_d1m1hiqruqxi;
  } else {
    measure_B.Switch_f0o4owldoyu = (measure_B.MathFunction_j +
      measure_DWork.UnitDelay4_DSTA_ps) + measure_DWork.UnitDelay2_DSTA_d;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_n[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_h1;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldoyu;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_d1m1hiqruqx;
      VDD_out++;
    }

    measure_B.VariableDiscret_ch = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_d1m1hiqruqx)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_f0o4owldoyup = measure_P.double_Value_d1m1hiqruqxix;
  } else {
    measure_B.Switch_f0o4owldoyup = (measure_B.MathFunction_j +
      measure_DWork.UnitDelay4_DSTA_k) + measure_DWork.UnitDelay2_DSTA_o3;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_d[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_iw;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldoyup;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_d1m1hiqruqxi;
      VDD_out++;
    }

    measure_B.VariableDiscret_jo4 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_d1m1hiqruqxi)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch_jka = measure_B.Switch_f0o4owldoyu - measure_B.VariableDiscret_ch;
  } else {
    rtb_Switch_jka = measure_B.Switch_f0o4owldoyup -
      measure_B.VariableDiscret_jo4;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_j[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_am;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_j;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_d1m1hiqruqxix;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_jz = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteD_d1m1hiqruqxix)
      measure_B.VariableDiscret_hk = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_hk = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_d1m1hiqruqxix)
      *VDD_in = 0;
  }

  rtb_Switch_jka = (rtb_Switch_jka - ((measure_B.VariableDiscret_jz *
    rtb_Subtract3_lr) + (measure_B.VariableDiscret_hk * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  measure_B.MathFunction1_b = (rtb_Switch_jka < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_jka))) : std::sqrt(rtb_Switch_jka);
  if (rtb_Compare_enj) {
    measure_B.Switch_f0o4owldoyupv = measure_P.double_Value_d1;
  } else {
    measure_B.Switch_f0o4owldoyupv = (measure_B.MathFunction1_b +
      measure_DWork.UnitDelay4_DSTA_mw) + measure_DWork.UnitDelay2_DSTA_d1;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_em[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_jq;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldoyupv;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_d1m1hiqruqxix0;
      VDD_out++;
    }

    measure_B.VariableDiscret_gl = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_d1m1hiqruqxix0)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_f0o4owldoyupv1 = measure_P.double_Value_d1m;
  } else {
    measure_B.Switch_f0o4owldoyupv1 = (measure_B.MathFunction1_b +
      measure_DWork.UnitDelay4_DSTA_jz) + measure_DWork.UnitDelay2_DSTA_l;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_iz[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_aa;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldoyupv1;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_d1m1hiqruqxix0v;
      VDD_out++;
    }

    measure_B.VariableDiscret_gj = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_d1m1hiqruqxix0v)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Switch_jka = measure_B.Switch_f0o4owldoyupv -
      measure_B.VariableDiscret_gl;
  } else {
    rtb_Switch_jka = measure_B.Switch_f0o4owldoyupv1 -
      measure_B.VariableDiscret_gj;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_js[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_kz;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_b;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_o;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_egn = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_o)
      measure_B.VariableDiscret_mg = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_mg = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_o)
      *VDD_in = 0;
  }

  rtb_Switch_jka = (rtb_Switch_jka - ((measure_B.VariableDiscret_egn *
    rtb_Subtract3_lri) + (measure_B.VariableDiscret_mg * rtb_MathFunction_gbn2)))
    * rtb_Divide_m;
  rtb_Switch_jka = (rtb_Switch_jka * rtb_Switch_jka) - (rtb_IpktoIrms_n *
    rtb_IpktoIrms_n);
  if (rtb_Switch_jka < measure_P.Constant_Value_d1m1hiq) {
    rtb_Switch_jka = measure_P.Constant_Value_d1;
  }

  if (rtb_IpktoIrms_n < measure_P.Constant_Value_d1m1hiqr) {
    rtb_IpktoIrms_n = measure_P.Constant_Value_d1m;
  }

  rtb_IpktoIrms_n = (((rtb_Switch_jka < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_jka))) : std::sqrt(rtb_Switch_jka)) / rtb_IpktoIrms_n) *
    measure_P.Gain_Gain_d1m;
  if (rtb_IpktoIrms_n > measure_P.Constant_Value_d1m1hiqru) {
    rtb_IpktoIrms_n = measure_P.Constant_Value_d1m1;
  }

  rtb_Switch_jka = measure_P.ScaleRMSoutputsto1pu_Gain_m * rtb_Sum1_pz;
  measure_B.MathFunction_jy = rtb_Switch_jka * rtb_Switch_jka;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_ngeqq2oshhr5 = measure_P.double_Value_m0413rfkrd2o;
  } else {
    measure_B.Switch_ngeqq2oshhr5 = (measure_B.MathFunction_jy +
      measure_DWork.UnitDelay4_DSTA_hx) + measure_DWork.UnitDelay2_DSTA_k;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ih[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_db;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshhr5;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_m0413rfkr;
      VDD_out++;
    }

    measure_B.VariableDiscret_hl = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_m0413rfkr)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_ngeqq2oshhr5r = measure_P.double_Value_m0413rfkrd2oa;
  } else {
    measure_B.Switch_ngeqq2oshhr5r = (measure_B.MathFunction_jy +
      measure_DWork.UnitDelay4_DSTA_p4) + measure_DWork.UnitDelay2_DSTA_lz;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ej[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_py;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshhr5r;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_m0413rfkrd;
      VDD_out++;
    }

    measure_B.VariableDiscret_a4 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_m0413rfkrd)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch_jka = measure_B.Switch_ngeqq2oshhr5 -
      measure_B.VariableDiscret_hl;
  } else {
    rtb_Switch_jka = measure_B.Switch_ngeqq2oshhr5r -
      measure_B.VariableDiscret_a4;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_li[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_et;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_jy;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_m0413rfkrd2;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_ml = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDel_m0413rfkrd2)
      measure_B.VariableDiscret_b2 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_b2 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_m0413rfkrd2)
      *VDD_in = 0;
  }

  rtb_Switch_jka = (rtb_Switch_jka - ((measure_B.VariableDiscret_ml *
    rtb_Subtract3_lr) + (measure_B.VariableDiscret_b2 * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  measure_B.MathFunction1_bx = (rtb_Switch_jka < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_jka))) : std::sqrt(rtb_Switch_jka);
  if (rtb_Compare_enj) {
    measure_B.Switch_ngeqq2oshhr5rh = measure_P.double_Value_m0;
  } else {
    measure_B.Switch_ngeqq2oshhr5rh = (measure_B.MathFunction1_bx +
      measure_DWork.UnitDelay4_DSTA_b) + measure_DWork.UnitDelay2_DSTA_ls;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_gs[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_lbx;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshhr5rh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_m0413rfkrd2o;
      VDD_out++;
    }

    measure_B.VariableDiscret_k = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_m0413rfkrd2o)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_ngeqq2oshhr5rhh = measure_P.double_Value_m04;
  } else {
    measure_B.Switch_ngeqq2oshhr5rhh = (measure_B.MathFunction1_bx +
      measure_DWork.UnitDelay4_DSTA_ay) + measure_DWork.UnitDelay2_DSTA_a3;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ne[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_b1;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshhr5rhh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_m0413rfkrd2oa;
      VDD_out++;
    }

    measure_B.VariableDiscret_ab = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_m0413rfkrd2oa)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Switch_jka = measure_B.Switch_ngeqq2oshhr5rh -
      measure_B.VariableDiscret_k;
  } else {
    rtb_Switch_jka = measure_B.Switch_ngeqq2oshhr5rhh -
      measure_B.VariableDiscret_ab;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pg[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_bu;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_bx;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_m0413rfkrd2oak;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_by = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscrete_m0413rfkrd2oak)
      measure_B.VariableDiscret_bo = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_bo = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_m0413rfkrd2oak)
      *VDD_in = 0;
  }

  rtb_Switch_jka = (rtb_Switch_jka - ((measure_B.VariableDiscret_by *
    rtb_Subtract3_lri) + (measure_B.VariableDiscret_bo * rtb_MathFunction_gbn2)))
    * rtb_Divide_m;
  rtb_Switch_jka = (rtb_Switch_jka * rtb_Switch_jka) - (rtb_Switch_jpt *
    rtb_Switch_jpt);
  if (rtb_Switch_jka < measure_P.Constant_Value_m0413rf) {
    rtb_Switch_jka = measure_P.Constant_Value_m0;
  }

  if (rtb_Switch_jpt < measure_P.Constant_Value_m0413rfk) {
    rtb_Switch_jpt = measure_P.Constant_Value_m04;
  }

  rtb_Switch_jpt = (((rtb_Switch_jka < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_jka))) : std::sqrt(rtb_Switch_jka)) / rtb_Switch_jpt) *
    measure_P.Gain_Gain_m04;
  if (rtb_Switch_jpt > measure_P.Constant_Value_m0413rfkr) {
    rtb_Switch_jpt = measure_P.Constant_Value_m041;
  }

  rtb_Gain_pj = ((((measure_P.Gain5_Gain_h[0].re * rtb_Divide_hh) -
                   (measure_P.Gain5_Gain_h[0].im * rtb_Divide_hh0)) +
                  ((measure_P.Gain5_Gain_h[1].re * rtb_Divide_b4ha) -
                   (measure_P.Gain5_Gain_h[1].im * rtb_Divide_b4h))) +
                 ((measure_P.Gain5_Gain_h[2].re * rtb_Divide_nqzy) -
                  (measure_P.Gain5_Gain_h[2].im * rtb_Divide_nqz))) *
    measure_P.Gain6_Gain;
  rtb_VpuIpktoVrmsIrms_im = ((((measure_P.Gain5_Gain_h[0].re * rtb_Divide_hh0) +
                               (measure_P.Gain5_Gain_h[0].im * rtb_Divide_hh)) +
                              ((measure_P.Gain5_Gain_h[1].re * rtb_Divide_b4h) +
                               (measure_P.Gain5_Gain_h[1].im * rtb_Divide_b4ha)))
    + ((measure_P.Gain5_Gain_h[2].re * rtb_Divide_nqz) +
       (measure_P.Gain5_Gain_h[2].im * rtb_Divide_nqzy))) * measure_P.Gain6_Gain;
  rtb_Switch1_l = (rtb_Gain_pj * rtb_Gain_pj) + (rtb_VpuIpktoVrmsIrms_im *
    rtb_VpuIpktoVrmsIrms_im);
  rtb_Gain_pj = ((((measure_P.Gain2_Gain_h1[0].re * rtb_Divide_hh) -
                   (measure_P.Gain2_Gain_h1[0].im * rtb_Divide_hh0)) +
                  ((measure_P.Gain2_Gain_h1[1].re * rtb_Divide_b4ha) -
                   (measure_P.Gain2_Gain_h1[1].im * rtb_Divide_b4h))) +
                 ((measure_P.Gain2_Gain_h1[2].re * rtb_Divide_nqzy) -
                  (measure_P.Gain2_Gain_h1[2].im * rtb_Divide_nqz))) *
    measure_P.Gain4_Gain;
  rtb_VpuIpktoVrmsIrms_im = ((((measure_P.Gain2_Gain_h1[0].re * rtb_Divide_hh0)
    + (measure_P.Gain2_Gain_h1[0].im * rtb_Divide_hh)) +
    ((measure_P.Gain2_Gain_h1[1].re * rtb_Divide_b4h) +
     (measure_P.Gain2_Gain_h1[1].im * rtb_Divide_b4ha))) +
    ((measure_P.Gain2_Gain_h1[2].re * rtb_Divide_nqz) +
     (measure_P.Gain2_Gain_h1[2].im * rtb_Divide_nqzy))) * measure_P.Gain4_Gain;
  rtb_Sum1_gh = (rtb_Gain_pj * rtb_Gain_pj) + (rtb_VpuIpktoVrmsIrms_im *
    rtb_VpuIpktoVrmsIrms_im);
  rtb_Sum1_gh = (rtb_Sum1_gh < 0.0) ? (-std::sqrt(std::abs(rtb_Sum1_gh))) : std::
    sqrt(rtb_Sum1_gh);
  measure_Y.Voltage[0] = rtb_SumofElements;
  measure_Y.Voltage[1] = rtb_AbsVI;
  measure_Y.Voltage[2] = rtb_AbsVI_k;
  measure_Y.Voltage[3] = rtb_TrigonometricFunction_i;
  measure_Y.Voltage[4] = rtb_TrigonometricFunction_ix;
  measure_Y.Voltage[5] = rtb_TrigonometricFunction_ixv;
  measure_Y.Voltage[6] = rtb_UnaryMinus_g;
  measure_Y.Voltage[7] = rtb_IpktoIrms_n;
  measure_Y.Voltage[8] = rtb_Switch_jpt;
  if (rtb_Sum1_gh < measure_P.Constant_Value_h1r) {
    rtb_Sum1_gh = measure_P.Constant_Value_h;
  }

  measure_Y.Voltage[9] = (((rtb_Switch1_l < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch1_l))) : std::sqrt(rtb_Switch1_l)) / rtb_Sum1_gh) *
    measure_P.Gain3_Gain_h;
  rtb_UnitDelay1_o = measure_DWork.UnitDelay1_DSTATE_f;
  rtb_Sum1_gh = (measure_P.Gain_Gain_en * rtb_Add1_fs_idx) +
    measure_P.Bias_Bias_n;
  rtb_Sum1_gh = ((((measure_U.IabcAmps[0] - measure_DWork.UnitDelay2_DSTATE_m) *
                   measure_P.Gain_Gain_hf) * rtb_Sum1_gh) +
                 measure_DWork.UnitDelay1_DSTATE_f) +
    ((((measure_DWork.UnitDelay2_DSTATE_m + measure_U.IabcAmps[0]) *
       measure_P.Gain1_Gain_h) - measure_DWork.UnitDelay1_DSTATE_f) *
     (rtb_Sum1_gh * rtb_Sum1_gh));
  measure_B.Product_j[0] = (rtb_Sum1_gh * rtb_UnaryMinus_o) * rtb_Divide_nfu;
  measure_B.Product_j[1] = (rtb_Sum1_gh * rtb_Sum2_i) * rtb_Divide_nfu;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_jp = measure_P.double_Value_e1r;
  } else {
    measure_B.Switch_jp = (measure_B.Product_j[0] +
      measure_DWork.UnitDelay4_DSTATE_d) + measure_DWork.UnitDelay2_DSTATE_kx;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneT_f[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOneT_l;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jp;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_e;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_h = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_e)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_jpt = measure_P.double_Value_e1ro;
  } else {
    measure_B.Switch_jpt = (measure_B.Product_j[0] +
      measure_DWork.UnitDelay4_DSTATE_do) + measure_DWork.UnitDelay2_DSTATE_kxh;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_fx[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOne_ln;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jpt;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_e1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_hg = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_e1)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch1_l = measure_B.Switch_jp -
      measure_B.VariableDiscreteDelaywithOneT_h;
  } else {
    rtb_Switch1_l = measure_B.Switch_jpt -
      measure_B.VariableDiscreteDelaywithOne_hg;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_c[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTwo_mt;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_j[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_e;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoT_b = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_e)
      measure_B.VariableDiscreteDelaywithTwo_fr = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwo_fr = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_e)
      *VDD_in = 0;
  }

  measure_B.Divide_nf = (rtb_Switch1_l -
    ((measure_B.VariableDiscreteDelaywithTwoT_b * rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithTwo_fr * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_jptu = measure_P.double_Value_e1rorg3;
  } else {
    measure_B.Switch_jptu = (measure_B.Divide_nf +
      measure_DWork.UnitDelay4_DSTATE_dot) +
      measure_DWork.UnitDelay2_DSTATE_kxh1;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_fxf[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOn_lnk;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptu;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOn_e1r;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_hgf = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOn_e1r)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jptuz = measure_P.double_Value_e1rorg3e;
  } else {
    measure_B.Switch_jptuz = (measure_B.Divide_nf +
      measure_DWork.UnitDelay4_DSTATE_dotl) +
      measure_DWork.UnitDelay2_DSTATE_kxh1d;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithO_fxfz[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithO_lnk1;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuz;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_e1ro;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithO_hgfm = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_e1ro)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Switch1_l = measure_B.Switch_jptu -
      measure_B.VariableDiscreteDelaywithOn_hgf;
  } else {
    rtb_Switch1_l = measure_B.Switch_jptuz -
      measure_B.VariableDiscreteDelaywithO_hgfm;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_cb[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTw_mt3;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nf;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_e1;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwo_br = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_e1)
      measure_B.VariableDiscreteDelaywithTw_frq = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTw_frq = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_e1)
      *VDD_in = 0;
  }

  rtb_Switch1_l = (rtb_Switch1_l - ((measure_B.VariableDiscreteDelaywithTwo_br *
    rtb_Subtract3_lri) + (measure_B.VariableDiscreteDelaywithTw_frq *
    rtb_MathFunction_gbn2))) * rtb_Divide_m;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_jptuzr = measure_P.double_Value_e1ror;
  } else {
    measure_B.Switch_jptuzr = (measure_B.Product_j[1] +
      measure_DWork.UnitDelay4_DSTATE_dotln) +
      measure_DWork.UnitDelay2_DSTATE_kxh1dd;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywith_fxfzv[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywith_lnk1v;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzr;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_e1ror;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywith_hgfmt = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_e1ror)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_jptuzrl = measure_P.double_Value_e1rorg;
  } else {
    measure_B.Switch_jptuzrl = (measure_B.Product_j[1] +
      measure_DWork.UnitDelay4_DSTATE_dotlnl) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywit_fxfzvg[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywit_lnk1vh;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrl;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywit_e1rorg;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywit_hgfmtb = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywit_e1rorg)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_UnaryMinus_g = measure_B.Switch_jptuzr -
      measure_B.VariableDiscreteDelaywith_hgfmt;
  } else {
    rtb_UnaryMinus_g = measure_B.Switch_jptuzrl -
      measure_B.VariableDiscreteDelaywit_hgfmtb;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_cb3[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithT_mt3m;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_j[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_e1r;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTw_br4 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTw_e1r)
      measure_B.VariableDiscreteDelaywithT_frq2 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithT_frq2 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_e1r)
      *VDD_in = 0;
  }

  measure_B.Divide_nfu = (rtb_UnaryMinus_g -
    ((measure_B.VariableDiscreteDelaywithTw_br4 * rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithT_frq2 * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_jptuzrlj = measure_P.double_Value_e1rorg3e1;
  } else {
    measure_B.Switch_jptuzrlj = (measure_B.Divide_nfu +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb3;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywi_fxfzvgo[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywi_lnk1vhz;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrlj;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywi_e1rorg3;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywi_hgfmtba = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywi_e1rorg3)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jptuzrljf = measure_P.double_Value_e1rorg3e1h;
  } else {
    measure_B.Switch_jptuzrljf = (measure_B.Divide_nfu +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelayw_fxfzvgoh[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelayw_lnk1vhza;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_e1rorg3e;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelayw_hgfmtbat = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_e1rorg3e)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_UnaryMinus_g = measure_B.Switch_jptuzrlj -
      measure_B.VariableDiscreteDelaywi_hgfmtba;
  } else {
    rtb_UnaryMinus_g = measure_B.Switch_jptuzrljf -
      measure_B.VariableDiscreteDelayw_hgfmtbat;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_cb3y[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywith_mt3my;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nfu;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_e1ro;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithT_br4j = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithT_e1ro)
      measure_B.VariableDiscreteDelaywith_frq2e = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywith_frq2e = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_e1ro)
      *VDD_in = 0;
  }

  rtb_UnaryMinus_g = (rtb_UnaryMinus_g -
                      ((measure_B.VariableDiscreteDelaywithT_br4j *
                        rtb_Subtract3_lri) +
                       (measure_B.VariableDiscreteDelaywith_frq2e *
                        rtb_MathFunction_gbn2))) * rtb_Divide_m;
  rtb_Switch_jpt = (rtb_Switch1_l * rtb_Switch1_l) + (rtb_UnaryMinus_g *
    rtb_UnaryMinus_g);
  rtb_Switch_jpt = (rtb_Switch_jpt < 0.0) ? (-std::sqrt(std::abs(rtb_Switch_jpt)))
    : std::sqrt(rtb_Switch_jpt);
  rtb_IpktoIrms_n = measure_P.IpktoIrms_Gain * rtb_Switch_jpt;
  rtb_UnitDelay1_f = measure_DWork.UnitDelay1_DSTATE_d;
  rtb_Switch_jka = (measure_P.Gain_Gain_ad * rtb_Add1_fs_idx_0) +
    measure_P.Bias_Bias_n2;
  rtb_Switch_jka = ((((measure_U.IabcAmps[1] - measure_DWork.UnitDelay2_DSTATE_d)
                      * measure_P.Gain_Gain_c) * rtb_Switch_jka) +
                    measure_DWork.UnitDelay1_DSTATE_d) +
    ((((measure_DWork.UnitDelay2_DSTATE_d + measure_U.IabcAmps[1]) *
       measure_P.Gain1_Gain_c) - measure_DWork.UnitDelay1_DSTATE_d) *
     (rtb_Switch_jka * rtb_Switch_jka));
  measure_B.Product_jq[0] = (rtb_Switch_jka * rtb_UnaryMinus_o) * rtb_Divide_nfu;
  measure_B.Product_jq[1] = (rtb_Switch_jka * rtb_Sum2_i) * rtb_Divide_nfu;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_jptuzrljf0 = measure_P.double_Value_e1rorg3e1hupmn0;
  } else {
    measure_B.Switch_jptuzrljf0 = (measure_B.Product_jq[0] +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0w) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33g;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelay_fxfzvgohd[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelay_lnk1vhzad;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf0;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_e1rorg3e1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelay_hgfmtbat5 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_e1rorg3e1)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_jptuzrljf05 = measure_P.double_Value_cb;
  } else {
    measure_B.Switch_jptuzrljf05 = (measure_B.Product_jq[0] +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0wv) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gq;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDela_fxfzvgohdy[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDela_lnk1vhzad0;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf05;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDela_e1rorg3e1h;
      VDD_out++;
    }

    measure_B.VariableDiscreteDela_hgfmtbat5l = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDela_e1rorg3e1h)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch = measure_B.Switch_jptuzrljf0 -
      measure_B.VariableDiscreteDelay_hgfmtbat5;
  } else {
    rtb_Switch = measure_B.Switch_jptuzrljf05 -
      measure_B.VariableDiscreteDela_hgfmtbat5l;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_cb3yn[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywit_mt3myh;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_jq[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDel_e1rorg3e1hu;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywith_br4j5 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDel_e1rorg3e1hu)
      measure_B.VariableDiscreteDelaywit_frq2ej = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywit_frq2ej = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDel_e1rorg3e1hu)
      *VDD_in = 0;
  }

  measure_B.Divide_nfun = (rtb_Switch -
    ((measure_B.VariableDiscreteDelaywith_br4j5 * rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywit_frq2ej * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_jptuzrljf055 = measure_P.double_Value_kz;
  } else {
    measure_B.Switch_jptuzrljf055 = (measure_B.Divide_nfun +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvp) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqp;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDel_fxfzvgohdyf[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDel_lnk1vhzad0h;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf055;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDe_e1rorg3e1hup;
      VDD_out++;
    }

    measure_B.VariableDiscreteDel_hgfmtbat5ln = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDe_e1rorg3e1hup)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jptuzrljf055w = measure_P.double_Value_b;
  } else {
    measure_B.Switch_jptuzrljf055w = (measure_B.Divide_nfun +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpy) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpf;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDe_fxfzvgohdyfs[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDe_lnk1vhzad0hw;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf055w;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteD_e1rorg3e1hupm;
      VDD_out++;
    }

    measure_B.VariableDiscreteDe_hgfmtbat5ln1 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteD_e1rorg3e1hupm)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Switch = measure_B.Switch_jptuzrljf055 -
      measure_B.VariableDiscreteDel_hgfmtbat5ln;
  } else {
    rtb_Switch = measure_B.Switch_jptuzrljf055w -
      measure_B.VariableDiscreteDe_hgfmtbat5ln1;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_cb3ynu[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywi_mt3myh1;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nfun;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscrete_e1rorg3e1hupmn;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywit_br4j50 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscrete_e1rorg3e1hupmn)
      measure_B.VariableDiscreteDelaywi_frq2ejb = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywi_frq2ejb = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscrete_e1rorg3e1hupmn)
      *VDD_in = 0;
  }

  rtb_Switch = (rtb_Switch - ((measure_B.VariableDiscreteDelaywit_br4j50 *
    rtb_Subtract3_lri) + (measure_B.VariableDiscreteDelaywi_frq2ejb *
    rtb_MathFunction_gbn2))) * rtb_Divide_m;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_jptuzrljf055wg = measure_P.double_Value_h;
  } else {
    measure_B.Switch_jptuzrljf055wg = (measure_B.Product_jq[1] +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpya) +
      measure_DWork.UnitDelay2_DSTAT_kxh1ddb33gqpfj;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteD_fxfzvgohdyfso[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteD_lnk1vhzad0hw1;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf055wg;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_e1rorg3e1hupmn0;
      VDD_out++;
    }

    measure_B.VariableDiscreteD_hgfmtbat5ln1z = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_e1rorg3e1hupmn0)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_jptuzrljf055wg5 = measure_P.double_Value_om;
  } else {
    measure_B.Switch_jptuzrljf055wg5 = (measure_B.Product_jq[1] +
      measure_DWork.UnitDelay4_DSTAT_dotlnlp0wvpyar) +
      measure_DWork.UnitDelay2_DSTA_kxh1ddb33gqpfjt;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscrete_fxfzvgohdyfsol[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscrete_lnk1vhzad0hw1b;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf055wg5;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_c;
      VDD_out++;
    }

    measure_B.VariableDiscrete_hgfmtbat5ln1zt = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_c)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_MathFunction1 = measure_B.Switch_jptuzrljf055wg -
      measure_B.VariableDiscreteD_hgfmtbat5ln1z;
  } else {
    rtb_MathFunction1 = measure_B.Switch_jptuzrljf055wg5 -
      measure_B.VariableDiscrete_hgfmtbat5ln1zt;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_cb3ynuk[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelayw_mt3myh1u;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_jq[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_h;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywi_br4j50f = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_h)
      measure_B.VariableDiscreteDelayw_frq2ejbq = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelayw_frq2ejbq = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_h)
      *VDD_in = 0;
  }

  measure_B.Divide_nfunb = (rtb_MathFunction1 -
    ((measure_B.VariableDiscreteDelaywi_br4j50f * rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelayw_frq2ejbq * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_c = measure_P.double_Value_cj;
  } else {
    measure_B.Switch_c = (measure_B.Divide_nfunb +
                          measure_DWork.UnitDelay4_DSTA_dotlnlp0wvpyari) +
      measure_DWork.UnitDelay2_DSTA_n;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscret_fxfzvgohdyfsolg[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_lnk1vhzad0hw1bl;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_c;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_hm;
      VDD_out++;
    }

    measure_B.VariableDiscret_hgfmtbat5ln1zta = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_hm)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jc = measure_P.double_Value_di;
  } else {
    measure_B.Switch_jc = (measure_B.Divide_nfunb +
      measure_DWork.UnitDelay4_DSTA_ls) + measure_DWork.UnitDelay2_DSTA_oz;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ab[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_ed;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jc;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_om;
      VDD_out++;
    }

    measure_B.VariableDiscret_aj = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_om)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_MathFunction1 = measure_B.Switch_c -
      measure_B.VariableDiscret_hgfmtbat5ln1zta;
  } else {
    rtb_MathFunction1 = measure_B.Switch_jc - measure_B.VariableDiscret_aj;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_cb3ynukf[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelay_mt3myh1uz;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nfunb;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_omi;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelayw_br4j50fk = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_omi)
      measure_B.VariableDiscreteDelay_frq2ejbqm = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelay_frq2ejbqm = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_omi)
      *VDD_in = 0;
  }

  rtb_MathFunction1 = (rtb_MathFunction1 -
                       ((measure_B.VariableDiscreteDelayw_br4j50fk *
    rtb_Subtract3_lri) + (measure_B.VariableDiscreteDelay_frq2ejbqm *
    rtb_MathFunction_gbn2))) * rtb_Divide_m;
  rtb_Switch1_ie = (rtb_Switch * rtb_Switch) + (rtb_MathFunction1 *
    rtb_MathFunction1);
  rtb_Switch1_ie = (rtb_Switch1_ie < 0.0) ? (-std::sqrt(std::abs(rtb_Switch1_ie)))
    : std::sqrt(rtb_Switch1_ie);
  rtb_Switch1_iew = measure_P.IpktoIrms_Gain_g * rtb_Switch1_ie;
  rtb_UnitDelay1_pu = measure_DWork.UnitDelay1_DSTATE_b;
  rtb_Sum1_g5i = (measure_P.Gain_Gain_eb * rtb_Add1_fs_idx_1) +
    measure_P.Bias_Bias_ih;
  rtb_Sum1_g5i = ((((measure_U.IabcAmps[2] - measure_DWork.UnitDelay2_DSTATE_kb)
                    * measure_P.Gain_Gain_oc) * rtb_Sum1_g5i) +
                  measure_DWork.UnitDelay1_DSTATE_b) +
    ((((measure_DWork.UnitDelay2_DSTATE_kb + measure_U.IabcAmps[2]) *
       measure_P.Gain1_Gain_o) - measure_DWork.UnitDelay1_DSTATE_b) *
     (rtb_Sum1_g5i * rtb_Sum1_g5i));
  measure_B.Product_jqy[0] = (rtb_Sum1_g5i * rtb_UnaryMinus_o) * rtb_Divide_nfu;
  measure_B.Product_jqy[1] = (rtb_Sum1_g5i * rtb_Sum2_i) * rtb_Divide_nfu;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_i = measure_P.double_Value_m;
  } else {
    measure_B.Switch_i = (measure_B.Product_jqy[0] +
                          measure_DWork.UnitDelay4_DSTA_gs) +
      measure_DWork.UnitDelay2_DSTA_e;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_je[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_de;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_i;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_k;
      VDD_out++;
    }

    measure_B.VariableDiscret_bx = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_k)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_h = measure_P.double_Value_c1;
  } else {
    measure_B.Switch_h = (measure_B.Product_jqy[0] +
                          measure_DWork.UnitDelay4_DSTA_hxo) +
      measure_DWork.UnitDelay2_DSTA_pl;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_no[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_cw;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_h;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_b;
      VDD_out++;
    }

    measure_B.VariableDiscret_dd = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_b)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Divide_nfu = measure_B.Switch_i - measure_B.VariableDiscret_bx;
  } else {
    rtb_Divide_nfu = measure_B.Switch_h - measure_B.VariableDiscret_dd;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_cb3ynukfc[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDela_mt3myh1uz5;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_jqy[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_kz;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelay_br4j50fkf = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_kz)
      measure_B.VariableDiscreteDela_frq2ejbqmj = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDela_frq2ejbqmj = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_kz)
      *VDD_in = 0;
  }

  measure_B.Divide_nfunba = (rtb_Divide_nfu -
    ((measure_B.VariableDiscreteDelay_br4j50fkf * rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDela_frq2ejbqmj * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_e = measure_P.double_Value_hu;
  } else {
    measure_B.Switch_e = (measure_B.Divide_nfunba +
                          measure_DWork.UnitDelay4_DSTA_gn) +
      measure_DWork.UnitDelay2_DSTA_ck;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ni[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_ln;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_e;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_cj;
      VDD_out++;
    }

    measure_B.VariableDiscret_p = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_cj)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jce = measure_P.double_Value_bg;
  } else {
    measure_B.Switch_jce = (measure_B.Divide_nfunba +
      measure_DWork.UnitDelay4_DSTA_pz) + measure_DWork.UnitDelay2_DSTA_cs;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_b3[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_ch;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jce;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_d;
      VDD_out++;
    }

    measure_B.VariableDiscret_pr = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_d)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_nfu = measure_B.Switch_e - measure_B.VariableDiscret_p;
  } else {
    rtb_Divide_nfu = measure_B.Switch_jce - measure_B.VariableDiscret_pr;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_cb3ynukfcn[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDel_mt3myh1uz53;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nfunba;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_bx;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDela_br4j50fkfb = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_bx)
      measure_B.VariableDiscreteDel_frq2ejbqmjc = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDel_frq2ejbqmjc = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_bx)
      *VDD_in = 0;
  }

  rtb_Divide_nfu = (rtb_Divide_nfu - ((measure_B.VariableDiscreteDela_br4j50fkfb
    * rtb_Subtract3_lri) + (measure_B.VariableDiscreteDel_frq2ejbqmjc *
    rtb_MathFunction_gbn2))) * rtb_Divide_m;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_el = measure_P.double_Value_ai;
  } else {
    measure_B.Switch_el = (measure_B.Product_jqy[1] +
      measure_DWork.UnitDelay4_DSTA_d2) + measure_DWork.UnitDelay2_DSTA_fe;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_i0[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_eh;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_el;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_l;
      VDD_out++;
    }

    measure_B.VariableDiscret_jn = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_l)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_m = measure_P.double_Value_p;
  } else {
    measure_B.Switch_m = (measure_B.Product_jqy[1] +
                          measure_DWork.UnitDelay4_DSTA_mz) +
      measure_DWork.UnitDelay2_DSTA_cx;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_d5[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_hw;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_m;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ly;
      VDD_out++;
    }

    measure_B.VariableDiscret_ky = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ly)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_UnaryMinus_o = measure_B.Switch_el - measure_B.VariableDiscret_jn;
  } else {
    rtb_UnaryMinus_o = measure_B.Switch_m - measure_B.VariableDiscret_ky;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_cb3ynukfcns[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDe_mt3myh1uz53e;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_jqy[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_cjg;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDel_br4j50fkfbp = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_cjg)
      measure_B.VariableDiscreteDe_frq2ejbqmjcp = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDe_frq2ejbqmjcp = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_cjg)
      *VDD_in = 0;
  }

  measure_B.Divide_nfunbaw = (rtb_UnaryMinus_o -
    ((measure_B.VariableDiscreteDel_br4j50fkfbp * rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDe_frq2ejbqmjcp * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_jx = measure_P.double_Value_ob;
  } else {
    measure_B.Switch_jx = (measure_B.Divide_nfunbaw +
      measure_DWork.UnitDelay4_DSTA_am) + measure_DWork.UnitDelay2_DSTA_n1;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_nk[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_k3l;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jx;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_f;
      VDD_out++;
    }

    measure_B.VariableDiscret_mj = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_f)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_je = measure_P.double_Value_g;
  } else {
    measure_B.Switch_je = (measure_B.Divide_nfunbaw +
      measure_DWork.UnitDelay4_DSTA_nh) + measure_DWork.UnitDelay2_DSTA_ko;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_le[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_kx;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_je;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_hs;
      VDD_out++;
    }

    measure_B.VariableDiscret_d3 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_hs)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_UnaryMinus_o = measure_B.Switch_jx - measure_B.VariableDiscret_mj;
  } else {
    rtb_UnaryMinus_o = measure_B.Switch_je - measure_B.VariableDiscret_d3;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_cb3ynukfcns4[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteD_mt3myh1uz53er;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nfunbaw;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_di;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDe_br4j50fkfbp0 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_di)
      measure_B.VariableDiscreteD_frq2ejbqmjcpo = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteD_frq2ejbqmjcpo = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_di)
      *VDD_in = 0;
  }

  rtb_UnaryMinus_o = (rtb_UnaryMinus_o -
                      ((measure_B.VariableDiscreteDe_br4j50fkfbp0 *
                        rtb_Subtract3_lri) +
                       (measure_B.VariableDiscreteD_frq2ejbqmjcpo *
                        rtb_MathFunction_gbn2))) * rtb_Divide_m;
  rtb_Sum2_i = (rtb_Divide_nfu * rtb_Divide_nfu) + (rtb_UnaryMinus_o *
    rtb_UnaryMinus_o);
  rtb_Gain_pj = (rtb_Sum2_i < 0.0) ? (-std::sqrt(std::abs(rtb_Sum2_i))) : std::
    sqrt(rtb_Sum2_i);
  rtb_Sum2_i = measure_P.IpktoIrms_Gain_m * rtb_Gain_pj;
  rtb_Switch1_np = measure_P.ScaleRMSoutputsto1pu_Gain_e * rtb_Sum1_gh;
  measure_B.MathFunction_p = rtb_Switch1_np * rtb_Switch1_np;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_p = measure_P.double_Value_e1rorg3e1hu;
  } else {
    measure_B.Switch_p = (measure_B.MathFunction_p +
                          measure_DWork.UnitDelay4_DSTA_fu) +
      measure_DWork.UnitDelay2_DSTA_ef;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_pl[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_pgc;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_m;
      VDD_out++;
    }

    measure_B.VariableDiscret_db = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_m)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_pi = measure_P.double_Value_e1rorg3e1hup;
  } else {
    measure_B.Switch_pi = (measure_B.MathFunction_p +
      measure_DWork.UnitDelay4_DSTA_m5) + measure_DWork.UnitDelay2_DSTA_mh;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_e5[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_aa5;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_pi;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_c1;
      VDD_out++;
    }

    measure_B.VariableDiscret_lk = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_c1)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch1_np = measure_B.Switch_p - measure_B.VariableDiscret_db;
  } else {
    rtb_Switch1_np = measure_B.Switch_pi - measure_B.VariableDiscret_lk;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_cb3ynukfcns4k[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscrete_mt3myh1uz53erg;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_p;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_li;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteD_br4j50fkfbp0n = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_li)
      measure_B.VariableDiscrete_frq2ejbqmjcpoj = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscrete_frq2ejbqmjcpoj = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_li)
      *VDD_in = 0;
  }

  rtb_Switch1_np = (rtb_Switch1_np - ((measure_B.VariableDiscreteD_br4j50fkfbp0n
    * rtb_Subtract3_lr) + (measure_B.VariableDiscrete_frq2ejbqmjcpoj *
    rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  measure_B.MathFunction1_e = (rtb_Switch1_np < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch1_np))) : std::sqrt(rtb_Switch1_np);
  if (rtb_Compare_enj) {
    measure_B.Switch_i0 = measure_P.double_Value_e;
  } else {
    measure_B.Switch_i0 = (measure_B.MathFunction1_e +
      measure_DWork.UnitDelay4_DSTA_e) + measure_DWork.UnitDelay2_DSTA_or;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_dx[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_hy;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_i0;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_a;
      VDD_out++;
    }

    measure_B.VariableDiscret_pp = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_a)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jv = measure_P.double_Value_e1;
  } else {
    measure_B.Switch_jv = (measure_B.MathFunction1_e +
      measure_DWork.UnitDelay4_DSTA_ju) + measure_DWork.UnitDelay2_DSTA_lt;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_kt[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_pt;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jv;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_p;
      VDD_out++;
    }

    measure_B.VariableDiscret_nh = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_p)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Switch1_np = measure_B.Switch_i0 - measure_B.VariableDiscret_pp;
  } else {
    rtb_Switch1_np = measure_B.Switch_jv - measure_B.VariableDiscret_nh;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_cb3ynukfcns4km[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_mt3myh1uz53ergf;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_e;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_lyi;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscrete_br4j50fkfbp0na = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_lyi)
      measure_B.VariableDiscret_frq2ejbqmjcpojk = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_frq2ejbqmjcpojk = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_lyi)
      *VDD_in = 0;
  }

  rtb_Switch1_np = (rtb_Switch1_np - ((measure_B.VariableDiscrete_br4j50fkfbp0na
    * rtb_Subtract3_lri) + (measure_B.VariableDiscret_frq2ejbqmjcpojk *
    rtb_MathFunction_gbn2))) * rtb_Divide_m;
  rtb_Switch1_np = (rtb_Switch1_np * rtb_Switch1_np) - (rtb_Switch_jpt *
    rtb_Switch_jpt);
  if (rtb_Switch1_np < measure_P.Constant_Value_e1rorg3e1h) {
    rtb_Switch1_np = measure_P.Constant_Value_e;
  }

  if (rtb_Switch_jpt < measure_P.Constant_Value_e1rorg3e1hu) {
    rtb_Switch_jpt = measure_P.Constant_Value_e1;
  }

  rtb_Switch1_np = (((rtb_Switch1_np < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch1_np))) : std::sqrt(rtb_Switch1_np)) / rtb_Switch_jpt) *
    measure_P.Gain_Gain_e1;
  if (rtb_Switch1_np > measure_P.Constant_Value_e1rorg3e1hup) {
    rtb_Switch1_np = measure_P.Constant_Value_e1r;
  }

  rtb_Switch_jpt = measure_P.ScaleRMSoutputsto1pu_Gain_e1 * rtb_Switch_jka;
  measure_B.MathFunction_pc = rtb_Switch_jpt * rtb_Switch_jpt;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_k = measure_P.double_Value_li;
  } else {
    measure_B.Switch_k = (measure_B.MathFunction_pc +
                          measure_DWork.UnitDelay4_DSTA_hz) +
      measure_DWork.UnitDelay2_DSTA_fq;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_l5[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_pf;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_k;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_hu;
      VDD_out++;
    }

    measure_B.VariableDiscret_ny = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_hu)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_eh = measure_P.double_Value_ly;
  } else {
    measure_B.Switch_eh = (measure_B.MathFunction_pc +
      measure_DWork.UnitDelay4_DSTA_mb) + measure_DWork.UnitDelay2_DSTA_d0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_bz[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_bm;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_eh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_bg;
      VDD_out++;
    }

    measure_B.VariableDiscret_lp = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_bg)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch_jpt = measure_B.Switch_k - measure_B.VariableDiscret_ny;
  } else {
    rtb_Switch_jpt = measure_B.Switch_eh - measure_B.VariableDiscret_lp;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_cb3ynukfcns4kmg[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_dxq;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_pc;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_fu;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_br4j50fkfbp0nah = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_fu)
      measure_B.VariableDiscret_nz = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_nz = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_fu)
      *VDD_in = 0;
  }

  rtb_Switch_jpt = (rtb_Switch_jpt - ((measure_B.VariableDiscret_br4j50fkfbp0nah
    * rtb_Subtract3_lr) + (measure_B.VariableDiscret_nz * rtb_MathFunction_gbn)))
    * rtb_Tps2dt_dt;
  measure_B.MathFunction1_ew = (rtb_Switch_jpt < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_jpt))) : std::sqrt(rtb_Switch_jpt);
  if (rtb_Compare_enj) {
    measure_B.Switch_o = measure_P.double_Value_e1rorg3e1hupm;
  } else {
    measure_B.Switch_o = (measure_B.MathFunction1_ew +
                          measure_DWork.UnitDelay4_DSTA_fp) +
      measure_DWork.UnitDelay2_DSTA_mf;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ac[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_mb;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_o;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ob;
      VDD_out++;
    }

    measure_B.VariableDiscret_cx = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ob)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_d = measure_P.double_Value_e1rorg3e1hupmn;
  } else {
    measure_B.Switch_d = (measure_B.MathFunction1_ew +
                          measure_DWork.UnitDelay4_DSTA_pm) +
      measure_DWork.UnitDelay2_DSTA_pz;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_hz[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_b5;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_d;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_g;
      VDD_out++;
    }

    measure_B.VariableDiscret_ka = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_g)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Switch_jpt = measure_B.Switch_o - measure_B.VariableDiscret_cx;
  } else {
    rtb_Switch_jpt = measure_B.Switch_d - measure_B.VariableDiscret_ka;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a1[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_k5;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_ew;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_hsu;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_nc = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_hsu)
      measure_B.VariableDiscret_mf = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_mf = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_hsu)
      *VDD_in = 0;
  }

  rtb_Switch_jpt = (rtb_Switch_jpt - ((measure_B.VariableDiscret_nc *
    rtb_Subtract3_lri) + (measure_B.VariableDiscret_mf * rtb_MathFunction_gbn2)))
    * rtb_Divide_m;
  rtb_Switch_jpt = (rtb_Switch_jpt * rtb_Switch_jpt) - (rtb_Switch1_ie *
    rtb_Switch1_ie);
  if (rtb_Switch_jpt < measure_P.Constant_Value_e1rorg3e1hupm) {
    rtb_Switch_jpt = measure_P.Constant_Value_e1ro;
  }

  if (rtb_Switch1_ie < measure_P.Constant_Value_e1rorg3e1hupmn) {
    rtb_Switch1_ie = measure_P.Constant_Value_e1ror;
  }

  rtb_Switch1_ie = (((rtb_Switch_jpt < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_jpt))) : std::sqrt(rtb_Switch_jpt)) / rtb_Switch1_ie) *
    measure_P.Gain_Gain_e1r;
  if (rtb_Switch1_ie > measure_P.Constant_Value_e1rorg3e1hupmn0) {
    rtb_Switch1_ie = measure_P.Constant_Value_e1rorg;
  }

  rtb_Switch_jpt = measure_P.ScaleRMSoutputsto1pu_Gain_e1r * rtb_Sum1_g5i;
  measure_B.MathFunction_pcc = rtb_Switch_jpt * rtb_Switch_jpt;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_ia = measure_P.double_Value_nx;
  } else {
    measure_B.Switch_ia = (measure_B.MathFunction_pcc +
      measure_DWork.UnitDelay4_DSTA_gf) + measure_DWork.UnitDelay2_DSTA_g;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_i1[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_nj;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ia;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_n;
      VDD_out++;
    }

    measure_B.VariableDiscret_pi = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_n)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_cp = measure_P.double_Value_ec;
  } else {
    measure_B.Switch_cp = (measure_B.MathFunction_pcc +
      measure_DWork.UnitDelay4_DSTA_hc) + measure_DWork.UnitDelay2_DSTA_hh;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_on[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_cg;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_cp;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_e;
      VDD_out++;
    }

    measure_B.VariableDiscret_osw = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_e)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch_jpt = measure_B.Switch_ia - measure_B.VariableDiscret_pi;
  } else {
    rtb_Switch_jpt = measure_B.Switch_cp - measure_B.VariableDiscret_osw;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gx[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_pfv;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_pcc;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ma;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_bu = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_ma)
      measure_B.VariableDiscret_jx = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_jx = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ma)
      *VDD_in = 0;
  }

  rtb_Switch_jpt = (rtb_Switch_jpt - ((measure_B.VariableDiscret_bu *
    rtb_Subtract3_lr) + (measure_B.VariableDiscret_jx * rtb_MathFunction_gbn))) *
    rtb_Tps2dt_dt;
  measure_B.MathFunction1_ew0 = (rtb_Switch_jpt < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_jpt))) : std::sqrt(rtb_Switch_jpt);
  if (rtb_Compare_enj) {
    measure_B.Switch_cn = measure_P.double_Value_f;
  } else {
    measure_B.Switch_cn = (measure_B.MathFunction1_ew0 +
      measure_DWork.UnitDelay4_DSTA_gv) + measure_DWork.UnitDelay2_DSTA_cs5;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_kw[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_abz;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_cn;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_ks;
      VDD_out++;
    }

    measure_B.VariableDiscret_g0 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_ks)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_g = measure_P.double_Value_hs;
  } else {
    measure_B.Switch_g = (measure_B.MathFunction1_ew0 +
                          measure_DWork.UnitDelay4_DSTA_g0) +
      measure_DWork.UnitDelay2_DSTA_fb;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_gc[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_ar;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_g;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_pd;
      VDD_out++;
    }

    measure_B.VariableDiscret_p0 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_pd)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Switch_jpt = measure_B.Switch_cn - measure_B.VariableDiscret_g0;
  } else {
    rtb_Switch_jpt = measure_B.Switch_g - measure_B.VariableDiscret_p0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ig[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_boa;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_ew0;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscret_c1z;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_bt = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscret_c1z)
      measure_B.VariableDiscret_lc = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_lc = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscret_c1z)
      *VDD_in = 0;
  }

  rtb_Switch_jpt = (rtb_Switch_jpt - ((measure_B.VariableDiscret_bt *
    rtb_Subtract3_lri) + (measure_B.VariableDiscret_lc * rtb_MathFunction_gbn2)))
    * rtb_Divide_m;
  rtb_Switch_jpt = (rtb_Switch_jpt * rtb_Switch_jpt) - (rtb_Gain_pj *
    rtb_Gain_pj);
  if (rtb_Switch_jpt < measure_P.Constant_Value_l5) {
    rtb_Switch_jpt = measure_P.Constant_Value_e1rorg3;
  }

  if (rtb_Gain_pj < measure_P.Constant_Value_ch) {
    rtb_Gain_pj = measure_P.Constant_Value_e1rorg3e;
  }

  rtb_Switch_jpt = (((rtb_Switch_jpt < 0.0) ? (-std::sqrt(std::abs
    (rtb_Switch_jpt))) : std::sqrt(rtb_Switch_jpt)) / rtb_Gain_pj) *
    measure_P.Gain_Gain_e1ro;
  if (rtb_Switch_jpt > measure_P.Constant_Value_b) {
    rtb_Switch_jpt = measure_P.Constant_Value_e1rorg3e1;
  }

  rtb_Add1_fs_idx_0 = ((((measure_P.Gain5_Gain_h1[0].re * rtb_Switch1_l) -
    (measure_P.Gain5_Gain_h1[0].im * rtb_UnaryMinus_g)) +
                        ((measure_P.Gain5_Gain_h1[1].re * rtb_Switch) -
    (measure_P.Gain5_Gain_h1[1].im * rtb_MathFunction1))) +
                       ((measure_P.Gain5_Gain_h1[2].re * rtb_Divide_nfu) -
                        (measure_P.Gain5_Gain_h1[2].im * rtb_UnaryMinus_o))) *
    measure_P.Gain6_Gain_h;
  rtb_Add1_fs_idx = ((((measure_P.Gain5_Gain_h1[0].re * rtb_UnaryMinus_g) +
                       (measure_P.Gain5_Gain_h1[0].im * rtb_Switch1_l)) +
                      ((measure_P.Gain5_Gain_h1[1].re * rtb_MathFunction1) +
                       (measure_P.Gain5_Gain_h1[1].im * rtb_Switch))) +
                     ((measure_P.Gain5_Gain_h1[2].re * rtb_UnaryMinus_o) +
                      (measure_P.Gain5_Gain_h1[2].im * rtb_Divide_nfu))) *
    measure_P.Gain6_Gain_h;
  rtb_Add1_fs_idx_1 = (rtb_Add1_fs_idx_0 * rtb_Add1_fs_idx_0) + (rtb_Add1_fs_idx
    * rtb_Add1_fs_idx);
  rtb_Gain_pj = ((((measure_P.Gain2_Gain_h1r[0].re * rtb_Switch1_l) -
                   (measure_P.Gain2_Gain_h1r[0].im * rtb_UnaryMinus_g)) +
                  ((measure_P.Gain2_Gain_h1r[1].re * rtb_Switch) -
                   (measure_P.Gain2_Gain_h1r[1].im * rtb_MathFunction1))) +
                 ((measure_P.Gain2_Gain_h1r[2].re * rtb_Divide_nfu) -
                  (measure_P.Gain2_Gain_h1r[2].im * rtb_UnaryMinus_o))) *
    measure_P.Gain4_Gain_h;
  rtb_VpuIpktoVrmsIrms_im = ((((measure_P.Gain2_Gain_h1r[0].re *
    rtb_UnaryMinus_g) + (measure_P.Gain2_Gain_h1r[0].im * rtb_Switch1_l)) +
    ((measure_P.Gain2_Gain_h1r[1].re * rtb_MathFunction1) +
     (measure_P.Gain2_Gain_h1r[1].im * rtb_Switch))) +
    ((measure_P.Gain2_Gain_h1r[2].re * rtb_UnaryMinus_o) +
     (measure_P.Gain2_Gain_h1r[2].im * rtb_Divide_nfu))) *
    measure_P.Gain4_Gain_h;
  rtb_Add1_fs_idx_0 = (rtb_Gain_pj * rtb_Gain_pj) + (rtb_VpuIpktoVrmsIrms_im *
    rtb_VpuIpktoVrmsIrms_im);
  rtb_Gain_pj = (rtb_Add1_fs_idx_0 < 0.0) ? (-std::sqrt(std::abs
    (rtb_Add1_fs_idx_0))) : std::sqrt(rtb_Add1_fs_idx_0);
  measure_Y.Current[0] = rtb_IpktoIrms_n;
  measure_Y.Current[1] = rtb_Switch1_iew;
  measure_Y.Current[2] = rtb_Sum2_i;
  measure_Y.Current[3] = rt_atan2d_snf(rtb_UnaryMinus_g, rtb_Switch1_l);
  measure_Y.Current[4] = rt_atan2d_snf(rtb_MathFunction1, rtb_Switch);
  measure_Y.Current[5] = rt_atan2d_snf(rtb_UnaryMinus_o, rtb_Divide_nfu);
  measure_Y.Current[6] = rtb_Switch1_np;
  measure_Y.Current[7] = rtb_Switch1_ie;
  measure_Y.Current[8] = rtb_Switch_jpt;
  if (rtb_Gain_pj < measure_P.Constant_Value_h1rl) {
    rtb_Gain_pj = measure_P.Constant_Value_h1;
  }

  measure_Y.Current[9] = (((rtb_Add1_fs_idx_1 < 0.0) ? (-std::sqrt(std::abs
    (rtb_Add1_fs_idx_1))) : std::sqrt(rtb_Add1_fs_idx_1)) / rtb_Gain_pj) *
    measure_P.Gain3_Gain_h1;
  rtb_SumofElements *= rtb_IpktoIrms_n;
  rtb_AbsVI *= rtb_Switch1_iew;
  rtb_AbsVI_k *= rtb_Sum2_i;
  rtb_SumofElements += rtb_AbsVI;
  rtb_SumofElements += rtb_AbsVI_k;
  rtb_UnaryMinus_g = -rtb_UnaryMinus_g;
  rtb_Add1_fs_idx_0 = ((rtb_Divide_hh * rtb_Switch1_l) - (rtb_Divide_hh0 *
    rtb_UnaryMinus_g)) * (measure_P.IpktoIrmsconversion_Gain *
    rtb_IpktoIrmsconversion);
  rtb_Add1_fs_idx_1 = ((rtb_Divide_hh * rtb_UnaryMinus_g) + (rtb_Divide_hh0 *
    rtb_Switch1_l)) * (measure_P.IpktoIrmsconversion_Gain *
                       rtb_IpktoIrmsconversion);
  rtb_MathFunction1 = -rtb_MathFunction1;
  rtb_Switch1_np = ((rtb_Divide_b4ha * rtb_Switch) - (rtb_Divide_b4h *
    rtb_MathFunction1)) * (measure_P.IpktoIrmsconversion_Gain_b *
    rtb_IpktoIrmsconversion);
  rtb_Gain_pj = ((rtb_Divide_b4ha * rtb_MathFunction1) + (rtb_Divide_b4h *
    rtb_Switch)) * (measure_P.IpktoIrmsconversion_Gain_b *
                    rtb_IpktoIrmsconversion);
  rtb_UnaryMinus_o = -rtb_UnaryMinus_o;
  rtb_IpktoIrmsconversion *= measure_P.IpktoIrmsconversion_Gain_b4;
  rtb_Add1_fs_idx_0 += rtb_Switch1_np;
  rtb_Add1_fs_idx_0 += ((rtb_Divide_nqzy * rtb_Divide_nfu) - (rtb_Divide_nqz *
    rtb_UnaryMinus_o)) * rtb_IpktoIrmsconversion;
  rtb_Add1_fs_idx_1 += rtb_Gain_pj;
  rtb_Add1_fs_idx_1 += ((rtb_Divide_nqzy * rtb_UnaryMinus_o) + (rtb_Divide_nqz *
    rtb_Divide_nfu)) * rtb_IpktoIrmsconversion;
  if (rtb_SumofElements < measure_P.Constant_Value_kj) {
    rtb_Add1_fs_idx = measure_P.Constant_Value;
  } else {
    rtb_Add1_fs_idx = rtb_SumofElements;
  }

  rtb_Gain_pj = rtb_Add1_fs_idx_0 / rtb_Add1_fs_idx;
  if (rtb_Gain_pj < measure_P.Constant_Value_ej) {
    rtb_Switch1_np = measure_P.Constant_Value_d;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_i) {
    rtb_Switch1_np = measure_P.Constant1_Value;
  } else {
    rtb_Switch1_np = rtb_Gain_pj;
  }

  measure_Y.Power_fundamental[0] = rtb_SumofElements;
  measure_Y.Power_fundamental[1] = rtb_Add1_fs_idx_0;
  measure_Y.Power_fundamental[2] = rtb_Add1_fs_idx_1;
  measure_Y.Power_fundamental[3] = rtb_Switch1_np;
  rtb_Add1_fs_idx_0 = measure_P.Gain1_Gain_g * measure_P.Constant1_Value_m2;
  measure_B.VI[0] = (rtb_Sum1_lle * rtb_Sum1_gh) * rtb_Add1_fs_idx_0;
  measure_B.VI[1] = (rtb_Sum1_p5 * rtb_Switch_jka) * rtb_Add1_fs_idx_0;
  measure_B.VI[2] = (rtb_Sum1_pz * rtb_Sum1_g5i) * rtb_Add1_fs_idx_0;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_ez = measure_P.double_Value;
  } else {
    measure_B.Switch_ez = (measure_B.VI[0] + measure_DWork.UnitDelay4_DSTATE_o)
      + measure_DWork.UnitDelay2_DSTATE_n;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneT_e[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOneT_k;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ez;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_ae;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_b = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_ae)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_h5 = measure_P.double_Value_k;
  } else {
    measure_B.Switch_h5 = (measure_B.VI[0] + measure_DWork.UnitDelay4_DSTATE_eq)
      + measure_DWork.UnitDelay2_DSTATE_a;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_ec[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOne_kj;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_h5;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_c;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_bb = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_c)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Add1_fs_idx_0 = measure_B.Switch_ez -
      measure_B.VariableDiscreteDelaywithOneT_b;
  } else {
    rtb_Add1_fs_idx_0 = measure_B.Switch_h5 -
      measure_B.VariableDiscreteDelaywithOne_bb;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_pp[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTwo_ah;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.VI[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_l;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoT_h = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_l)
      measure_B.VariableDiscreteDelaywithTwoT_i = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoT_i = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_l)
      *VDD_in = 0;
  }

  measure_B.Divide_d = (rtb_Add1_fs_idx_0 -
                        ((measure_B.VariableDiscreteDelaywithTwoT_h *
    rtb_Subtract3_lr) + (measure_B.VariableDiscreteDelaywithTwoT_i *
    rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_nh = measure_P.double_Value_c;
  } else {
    measure_B.Switch_nh = (measure_B.Divide_d +
      measure_DWork.UnitDelay4_DSTATE_g) + measure_DWork.UnitDelay2_DSTATE_dq;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_fi[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOne_op;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_i;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_d = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_i)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_mm = measure_P.double_Value_o0;
  } else {
    measure_B.Switch_mm = (measure_B.Divide_d +
      measure_DWork.UnitDelay4_DSTATE_je) + measure_DWork.UnitDelay2_DSTATE_o;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_fie[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOn_opo;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_mm;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_l;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_dt = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_l)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Add1_fs_idx_0 = measure_B.Switch_nh -
      measure_B.VariableDiscreteDelaywithOneT_d;
  } else {
    rtb_Add1_fs_idx_0 = measure_B.Switch_mm -
      measure_B.VariableDiscreteDelaywithOne_dt;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_k[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTwo_ju;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_d;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_k;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoT_o = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_k)
      measure_B.VariableDiscreteDelaywithTwo_fu = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwo_fu = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_k)
      *VDD_in = 0;
  }

  rtb_Add1_fs_idx_0 = (rtb_Add1_fs_idx_0 -
                       ((measure_B.VariableDiscreteDelaywithTwoT_o *
    rtb_Subtract3_lri) + (measure_B.VariableDiscreteDelaywithTwo_fu *
    rtb_MathFunction_gbn2))) * rtb_Divide_m;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_gg = measure_P.double_Value_n;
  } else {
    measure_B.Switch_gg = (measure_B.VI[1] + measure_DWork.UnitDelay4_DSTATE_e1)
      + measure_DWork.UnitDelay2_DSTATE_c;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_ep[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOn_obd;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_gg;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_l4;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_dd = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_l4)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_p4 = measure_P.double_Value_d;
  } else {
    measure_B.Switch_p4 = (measure_B.VI[1] + measure_DWork.UnitDelay4_DSTATE_i)
      + measure_DWork.UnitDelay2_DSTATE_f;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_epo[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithO_obdq;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p4;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_n;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_dd4 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_n)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Add1_fs_idx_1 = measure_B.Switch_gg -
      measure_B.VariableDiscreteDelaywithOne_dd;
  } else {
    rtb_Add1_fs_idx_1 = measure_B.Switch_p4 -
      measure_B.VariableDiscreteDelaywithOn_dd4;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_mfe[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTwoT_f;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.VI[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_mv;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwo_mc = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_mv)
      measure_B.VariableDiscreteDelaywithTwo_hd = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwo_hd = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_mv)
      *VDD_in = 0;
  }

  measure_B.Divide_g = (rtb_Add1_fs_idx_1 -
                        ((measure_B.VariableDiscreteDelaywithTwo_mc *
    rtb_Subtract3_lr) + (measure_B.VariableDiscreteDelaywithTwo_hd *
    rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_ml = measure_P.double_Value_nw;
  } else {
    measure_B.Switch_ml = (measure_B.Divide_g +
      measure_DWork.UnitDelay4_DSTATE_m) + measure_DWork.UnitDelay2_DSTATE_gs;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_bb[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOne_of;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ml;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_p;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_ch = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_p)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_b1 = measure_P.double_Value_l;
  } else {
    measure_B.Switch_b1 = (measure_B.Divide_g +
      measure_DWork.UnitDelay4_DSTATE_n) + measure_DWork.UnitDelay2_DSTATE_p;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_bbn[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOn_of2;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b1;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_di;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOn_chw = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_di)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Add1_fs_idx_1 = measure_B.Switch_ml -
      measure_B.VariableDiscreteDelaywithOne_ch;
  } else {
    rtb_Add1_fs_idx_1 = measure_B.Switch_b1 -
      measure_B.VariableDiscreteDelaywithOn_chw;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_o[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTwoT_g;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_g;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_jx;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoT_c = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_jx)
      measure_B.VariableDiscreteDelaywithTwo_im = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwo_im = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_jx)
      *VDD_in = 0;
  }

  rtb_Add1_fs_idx_1 = (rtb_Add1_fs_idx_1 -
                       ((measure_B.VariableDiscreteDelaywithTwoT_c *
    rtb_Subtract3_lri) + (measure_B.VariableDiscreteDelaywithTwo_im *
    rtb_MathFunction_gbn2))) * rtb_Divide_m;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_ny = measure_P.double_Value_o;
  } else {
    measure_B.Switch_ny = (measure_B.VI[2] + measure_DWork.UnitDelay4_DSTATE_jf)
      + measure_DWork.UnitDelay2_DSTATE_h2;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_bm[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOne_jp;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ny;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_c3;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_o = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_c3)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_n2 = measure_P.double_Value_a;
  } else {
    measure_B.Switch_n2 = (measure_B.VI[2] + measure_DWork.UnitDelay4_DSTATE_l)
      + measure_DWork.UnitDelay2_DSTATE_ai;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_bmy[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOn_jpu;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_n2;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneT_h;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_ol = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneT_h)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch1_np = measure_B.Switch_ny -
      measure_B.VariableDiscreteDelaywithOneT_o;
  } else {
    rtb_Switch1_np = measure_B.Switch_n2 -
      measure_B.VariableDiscreteDelaywithOne_ol;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_mw[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTwoT_h;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.VI[2];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoT_c;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwo_iz = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoT_c)
      measure_B.VariableDiscreteDelaywithTwo_hy = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwo_hy = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoT_c)
      *VDD_in = 0;
  }

  measure_B.Divide_l = (rtb_Switch1_np -
                        ((measure_B.VariableDiscreteDelaywithTwo_iz *
    rtb_Subtract3_lr) + (measure_B.VariableDiscreteDelaywithTwo_hy *
    rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_bi = measure_P.double_Value_do;
  } else {
    measure_B.Switch_bi = (measure_B.Divide_l +
      measure_DWork.UnitDelay4_DSTATE_co) + measure_DWork.UnitDelay2_DSTATE_l;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneT_g[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOne_fn;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_bi;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_nc;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneT_j = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_nc)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_oh = measure_P.double_Value_c2;
  } else {
    measure_B.Switch_oh = (measure_B.Divide_l +
      measure_DWork.UnitDelay4_DSTATE_j5) + measure_DWork.UnitDelay2_DSTATE_cm;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_g5[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithOn_fny;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_oh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOne_o0;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOne_jn = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOne_o0)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Switch1_np = measure_B.Switch_bi -
      measure_B.VariableDiscreteDelaywithOneT_j;
  } else {
    rtb_Switch1_np = measure_B.Switch_oh -
      measure_B.VariableDiscreteDelaywithOne_jn;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_of[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywithTw_as5;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_l;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwo_d5;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwo_fb = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwo_d5)
      measure_B.VariableDiscreteDelaywithTw_m03 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTw_m03 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwo_d5)
      *VDD_in = 0;
  }

  rtb_Divide_m *= rtb_Switch1_np - ((measure_B.VariableDiscreteDelaywithTwo_fb *
    rtb_Subtract3_lri) + (measure_B.VariableDiscreteDelaywithTw_m03 *
    rtb_MathFunction_gbn2));
  rtb_Add1_fs_idx_0 += rtb_Add1_fs_idx_1;
  rtb_Add1_fs_idx_0 += rtb_Divide_m;
  measure_Y.Power_harmonic = rtb_Add1_fs_idx_0;
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition = measure_DWork.RateTransition_Buffer0;
    measure_B.RateTransition_f = measure_DWork.RateTransition_Buffer0_m;
    measure_B.RateTransition_b = measure_DWork.RateTransition_Buffer0_p;
  }

  measure_Y.Fundamentalvefreqc[0] = measure_B.RateTransition;
  measure_Y.Fundamentalvefreqc[1] = measure_B.RateTransition_f;
  measure_Y.Fundamentalvefreqc[2] = measure_B.RateTransition_b;
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_c = measure_DWork.RateTransition_Buffer0_f;
    measure_B.RateTransition_m = measure_DWork.RateTransition_Buffer0_n;
    measure_B.RateTransition_g = measure_DWork.RateTransition_Buffer0_c;
  }

  measure_Y.Fundamentalamplitudevefreq[0] = measure_B.RateTransition_c;
  measure_Y.Fundamentalamplitudevefreq[1] = measure_B.RateTransition_m;
  measure_Y.Fundamentalamplitudevefreq[2] = measure_B.RateTransition_g;
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_j[0] = measure_DWork.RateTransition_Buffer0_nm[0];
    measure_B.RateTransition_j[1] = measure_DWork.RateTransition_Buffer0_nm[1];
    measure_B.RateTransition_j[2] = measure_DWork.RateTransition_Buffer0_nm[2];
    measure_B.RateTransition_j[3] = measure_DWork.RateTransition_Buffer0_nm[3];
    measure_B.RateTransition_p[0] = measure_DWork.RateTransition_Buffer0_d[0];
    measure_B.RateTransition_p[1] = measure_DWork.RateTransition_Buffer0_d[1];
    measure_B.RateTransition_p[2] = measure_DWork.RateTransition_Buffer0_d[2];
    measure_B.RateTransition_p[3] = measure_DWork.RateTransition_Buffer0_d[3];
    measure_B.RateTransition_e[0] = measure_DWork.RateTransition_Buffer0_j[0];
    measure_B.RateTransition_e[1] = measure_DWork.RateTransition_Buffer0_j[1];
    measure_B.RateTransition_e[2] = measure_DWork.RateTransition_Buffer0_j[2];
    measure_B.RateTransition_e[3] = measure_DWork.RateTransition_Buffer0_j[3];
  }

  measure_Y.Amplitudesrelativetofundamental[0] = measure_B.RateTransition_j[0];
  measure_Y.Amplitudesrelativetofundamental[1] = measure_B.RateTransition_j[1];
  measure_Y.Amplitudesrelativetofundamental[2] = measure_B.RateTransition_j[2];
  measure_Y.Amplitudesrelativetofundamental[3] = measure_B.RateTransition_j[3];
  measure_Y.Amplitudesrelativetofundamental[4] = measure_B.RateTransition_p[0];
  measure_Y.Amplitudesrelativetofundamental[5] = measure_B.RateTransition_p[1];
  measure_Y.Amplitudesrelativetofundamental[6] = measure_B.RateTransition_p[2];
  measure_Y.Amplitudesrelativetofundamental[7] = measure_B.RateTransition_p[3];
  measure_Y.Amplitudesrelativetofundamental[8] = measure_B.RateTransition_e[0];
  measure_Y.Amplitudesrelativetofundamental[9] = measure_B.RateTransition_e[1];
  measure_Y.Amplitudesrelativetofundamental[10] = measure_B.RateTransition_e[2];
  measure_Y.Amplitudesrelativetofundamental[11] = measure_B.RateTransition_e[3];
  if (rtb_Compare_mt) {
    rtb_Switch1_a = measure_P.int2_Value;
  }

  rtb_FixPtSum1 = rtb_Switch1_a - measure_P.FixPtConstant_Value_jcfaw;
  if (rtb_Compare_h4) {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_P.int2_Value_j;
  }

  rtb_FixPtSum1_c = rtb_UnitDelay1_pu5rdhlnellvz -
    measure_P.FixPtConstant_Value_jcfawy;
  if (rtb_Compare_hpz455i0) {
    rtb_Switch1_ia = measure_P.int2_Value_jc;
  }

  rtb_FixPtSum1_co = rtb_Switch1_ia - measure_P.FixPtConstant_Value_jcfawyw;
  if (rtb_Compare_hpz455i0) {
    rtb_Switch1_a = measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhw;
  } else {
    rtb_Switch1_a = measure_P.const_Value_jcfa;
  }

  rtb_LogicalOperator_nx = (rtb_Switch1_a == measure_P.Constant_Value_h1f);
  rtb_Compare_ks = (rtb_LogicalOperator_nx && ((rtb_Compare_k || rtb_Compare_k3)
    || rtb_Compare_k3k));
  rtb_LogicalOperator1 = (rtb_Compare_ks && (measure_DWork.delay_DSTATE_i2wj4));
  rtb_Compare_h4 = !rtb_Compare_ks;
  rtb_Gain_pj = measure_P.Gain_Gain_jcfawyw2o0 * measure_P.Constant4_Value_g;
  if (measure_P.Constant6_Value_j) {
    measure_B.Switch2_h1wibj = rtb_Gain_pj + measure_P.Bias1_Bias;
  } else {
    measure_B.Switch2_h1wibj = rtb_Gain_pj + measure_P.Bias_Bias;
  }

  {
    measure_B.SFunction_ilzn = (uint32_T)measure_B.Switch2_h1wibj;
  }

  if (rtb_UnitDelay4_dmwj4s1jwn3) {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_B.SFunction_ilzn +
      measure_P.FixPtConstant_Value_j;
  } else {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_DWork.UnitDelay_DSTATE_lmdwo -
      measure_P.FixPtConstant_Value;
  }

  rtb_Compare_ks = (rtb_UnitDelay1_pu5rdhlnellvz > measure_P.Constant_Value_ck);
  if (rtb_Compare_ks) {
    rtb_Switch1_hb = rtb_UnitDelay1_pu5rdhlnellvz;
  } else {
    rtb_Switch1_hb = measure_P.int1_Value;
  }

  rtb_LogicalOperator2_npqxol = ((measure_DWork.UnitDelay_DSTATE_lmdwo300) || ((
    !rtb_Compare_ks) && rtb_LogicalOperator1));
  rtb_UnitDelay1_pu5rdhlnellvz = measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhwr;
  rtb_LogicalOperator1 = (rtb_UnitDelay4_dmwj4s1jwn3 &&
    (measure_DWork.UnitDelay_DSTATE_lmdwo300i));
  rtb_Gain_pj = measure_P.Gain_Gain_jcfawyw2o0o * measure_P.Constant3_Value;
  if (measure_P.Constant6_Value_jc) {
    measure_B.Switch2_h1wibj2 = rtb_Gain_pj + measure_P.Bias1_Bias_j;
  } else {
    measure_B.Switch2_h1wibj2 = rtb_Gain_pj + measure_P.Bias_Bias_j;
  }

  {
    measure_B.SFunction_ilzn5 = (uint32_T)measure_B.Switch2_h1wibj2;
  }

  if (!rtb_LogicalOperator1) {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_B.SFunction_ilzn5 +
      measure_P.FixPtConstant_Value_jc;
  }

  rtb_Compare_ks = (rtb_UnitDelay1_pu5rdhlnellvz == measure_P.Constant_Value_ka);
  if (rtb_UnitDelay4_dmwj4s1jwn3 && ((rtb_RelationalOperator_o &&
        rtb_RelationalOperator_os) && rtb_RelationalOperator_osa)) {
    rtb_Switch1_ia = measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhwrm;
  } else {
    rtb_Switch1_ia = measure_P.const_Value_jcf;
  }

  rtb_Compare_enj = (rtb_Switch1_ia == measure_P.Constant_Value_ci);
  rtb_LogicalOperator1_fmgwx = (rtb_LogicalOperator2_npqxol && (!(rtb_Compare_ks
    || rtb_Compare_enj)));
  if (rtb_Compare_enj) {
    rtb_Switch1_ia = measure_P.int2_Value_jcf;
  }

  rtb_FixPtSum1_cot = rtb_Switch1_ia - measure_P.FixPtConstant_Value_jcfawyw2;
  if (rtb_Compare_ks) {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_P.int1_Value_j;
  }

  rtb_FixPtSum1_cotn = rtb_UnitDelay1_pu5rdhlnellvz -
    measure_P.FixPtConstant_Value_jcfawyw2o;
  if (rtb_LogicalOperator_fwnazb5b22n) {
    measure_B.Switch_nulzsg5y = measure_P.double_Value_jcfawyw2o;
  } else {
    measure_B.Switch_nulzsg5y = (measure_B.ACripple1stestimate +
      measure_DWork.UnitDelay4_DSTATE_czl44j1i) +
      measure_DWork.UnitDelay2_DSTATE_h5brdqciz0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelayw_b4npphe4[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelay_h3seeh3od;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulzsg5y;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelayw_jcfawyw2;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelayw_co5gwoze = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelayw_jcfawyw2)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_cdf4d5ci) {
    measure_B.Switch_nulzsg5yk = measure_P.double_Value_jcfawyw2o0;
  } else {
    measure_B.Switch_nulzsg5yk = (measure_B.ACripple1stestimate +
      measure_DWork.UnitDelay4_DSTATE_czl44j1ip) +
      measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelay_b4npphe4j[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDela_h3seeh3odr;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulzsg5yk;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelay_jcfawyw2o;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelay_co5gwoze0 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelay_jcfawyw2o)
      *VDD_in = 0;
  }

  if (rtb_Compare_hpz455i02) {
    rtb_Add1_fs_idx_0 = measure_B.Switch_nulzsg5y -
      measure_B.VariableDiscreteDelayw_co5gwoze;
  } else {
    rtb_Add1_fs_idx_0 = measure_B.Switch_nulzsg5yk -
      measure_B.VariableDiscreteDelay_co5gwoze0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_mf50[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscreteDelaywith_jngrs;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.ACripple1stestimate;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithT_jcfa;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithT_jwh1 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithT_jcfa)
      measure_B.VariableDiscreteDelaywith_f1uva = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywith_f1uva = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithT_jcfa)
      *VDD_in = 0;
  }

  rtb_Switch = measure_B.ACripple1stestimate - ((rtb_Add1_fs_idx_0 -
    ((measure_B.VariableDiscreteDelaywithT_jwh1 * rtb_Subtract3_ca) +
     (measure_B.VariableDiscreteDelaywith_f1uva * rtb_MathFunction_mti))) *
    rtb_Tps2dt_cr);
  rtb_Switch_nulzsg5ykq = measure_DWork.UnitDelay_DSTATE_lmdwo3 +
    measure_P.Bias_Bias_jcfawyw2o0o;
  if (rtb_Switch_nulzsg5ykq < measure_DWork.UnitDelay_DSTATE_lmdwo3) {
    rtb_Switch_nulzsg5ykq = MAX_uint32_T;
  }

  rtb_Divide_hh = measure_DWork.UnitDelay_DSTATE_lmd;
  rtb_LogicalOperator16 = (measure_DWork.UnitDelay_DSTATE_lmd >
    measure_P.Constant_Value_oky);
  if (measure_P.Constant_Value_pe) {
    rtb_Compare_ks = (rtb_LogicalOperator16 &&
                      (measure_DWork.delay_DSTATE_i2wj4d));
  } else {
    rtb_Compare_ks = ((rtb_LogicalOperator16 ^ measure_DWork.delay1_DSTATE_ces) &&
                      (measure_DWork.UnitDelay_DSTATE_lmdwo300ig));
  }

  rtb_Compare_ks = ((!measure_DWork.UnitDelay2_DSTAT_h5brdqciz0j45w) &&
                    rtb_Compare_ks);
  if (rtb_Compare_ks) {
    rtb_Switch2_h = rtb_Switch_nulzsg5ykq;
  } else {
    rtb_Switch2_h = measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j4;
  }

  if (rtb_Compare_ks) {
    rtb_Gain_pj = measure_DWork.UnitDelay_DSTATE_lmd -
      measure_DWork.UnitDelay1_DSTATE_cm;
    if (rtb_Gain_pj < measure_P.Constant_Value_n) {
      rtb_Switch1_l = -rtb_Gain_pj;
    } else {
      rtb_Switch1_l = rtb_Gain_pj;
    }

    if (rtb_Switch1_l < measure_P.Constant_Value_jn) {
      rtb_Gain_pj = measure_P.Constant1_Value_jcfawyw2o;
    }

    rtb_Divide_nqzy = (measure_DWork.UnitDelay1_DSTATE_cm / rtb_Gain_pj) *
      measure_P.T2T1_Gain;
    rtb_Divide_b4h = rtb_Divide_nqzy -
      measure_DWork.UnitDelay4_DSTATE_czl44j1ipa;
  } else {
    rtb_Divide_nqzy = measure_DWork.UnitDelay1_DSTATE_cmn;
    rtb_Divide_b4h = measure_DWork.UnitDelay1_DSTATE_cmnb;
  }

  rtb_Add1_fs_idx_0 = (measure_P.Gain_Gain_jcfawyw2o0os * ((real_T)rtb_Switch2_h))
    + rtb_Divide_b4h;
  if (rtb_Add1_fs_idx_0 < measure_P.Constant_Value_ot) {
    rtb_Add1_fs_idx_0 = measure_P.Constant_Value_p4;
  }

  rtb_Divide_b4ha = (1.0 / rtb_Add1_fs_idx_0) *
    measure_P.Gain_Gain_jcfawyw2o0osk;
  if (rtb_Compare_jm) {
    rtb_Divide_nqz = measure_P.Constant_Value_jcfawyw2o0osk;
  } else {
    rtb_Gain_pj = ((measure_DWork.UnitDelay1_DSTATE_c + rtb_Divide_b4ha) *
                   measure_P.Gain_Gain_j) -
      measure_DWork.UnitDelay1_DSTATE_cmnb3;
    if (rtb_Gain_pj < measure_P.Constant_Value_jcfawyw2o0o) {
      rtb_Gain_pj = measure_P.Constant_Value_jcfawyw2;
    } else {
      if (rtb_Gain_pj > measure_P.Constant_Value_jcfawyw) {
        rtb_Gain_pj = measure_P.Constant1_Value_jcfaw;
      }
    }

    rtb_Gain_pj += measure_DWork.UnitDelay1_DSTATE_cmnb3;
    if (rtb_Gain_pj < measure_P.Constant_Value_jcfawyw2o0os) {
      rtb_Divide_nqz = measure_P.Constant_Value_jcfawyw2o0;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_jcfawyw2o) {
      rtb_Divide_nqz = measure_P.Constant1_Value_jcfawy;
    } else {
      rtb_Divide_nqz = rtb_Gain_pj;
    }
  }

  rtb_Gain_pj = measure_P.Gain2_Gain_j * rtb_Divide_nqz;
  if (measure_P.Constant6_Value_jcf) {
    if (rtb_Gain_pj > measure_P.Constant_Value_ipk) {
      measure_B.Switch2_h1wibj25 = rtb_Gain_pj + measure_P.Bias1_Bias_jcf;
    } else {
      measure_B.Switch2_h1wibj25 = rtb_Gain_pj + measure_P.Bias_Bias_jcf;
    }
  } else {
    measure_B.Switch2_h1wibj25 = rtb_Gain_pj;
  }

  {
    measure_B.SFunction_ilz = (int32_T)measure_B.Switch2_h1wibj25;
  }

  if (((real_T)measure_B.SFunction_ilz) < measure_P.Constant_Value_gp) {
    rtb_Add1_fs_idx = measure_P.Constant_Value_jcfawyw2o0osk2;
  } else {
    rtb_Add1_fs_idx = (real_T)measure_B.SFunction_ilz;
  }

  rtb_Gain_pj = ((1.0 / rtb_Divide_nqz) * rtb_Add1_fs_idx) -
    measure_DWork.UnitDelay1_DSTATE_cmnb3j;
  if (rtb_Gain_pj < measure_P.Constant_Value_eh) {
    rtb_Add1_fs_idx_1 = measure_P.Constant_Value_jcfawy;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_jcfaw) {
    rtb_Add1_fs_idx_1 = measure_P.Constant1_Value_jcfa;
  } else {
    rtb_Add1_fs_idx_1 = rtb_Gain_pj;
  }

  rtb_Switch_jka = rtb_Add1_fs_idx_1 + measure_DWork.UnitDelay1_DSTATE_cmnb3j;
  if (rtb_Compare_jm) {
    rtb_Switch1_bt = rtb_UnitDelay1_c;
  } else {
    rtb_Switch1_bt = measure_P.int1_Value_jc;
  }

  rtb_Add1_fs_idx_1 = std::exp((measure_P.Gain1_Gain_jcfawy * rtb_Divide_nqz) *
    measure_P.Gain2_Gain_jc);
  rtb_IpktoIrmsconversion = (measure_P.double1_Value - rtb_Add1_fs_idx_1) *
    rtb_Switch;
  rtb_SumofElements = rtb_Divide_hh * rtb_Add1_fs_idx_1;
  rtb_Add1_fs_idx_0 = (measure_P.Gain1_Gain_jcfawyw * rtb_Add1_fs_idx_0) +
    measure_P.Bias_Bias_jcfawyw2o;
  if (rtb_Add1_fs_idx_0 < measure_P.Constant_Value_li) {
    rtb_Add1_fs_idx_0 = measure_P.Constant_Value_p;
  }

  rtb_Gain_pj = (measure_P.Gain_Gain_jcfawyw2o0osk2 * rtb_Add1_fs_idx_0) +
    measure_P.Bias_Bias_jcfawyw2o0;
  if (rtb_Gain_pj < measure_P.Constant_Value_hb) {
    rtb_Gain_pj = measure_P.Constant_Value_dl;
  } else {
    if (rtb_Gain_pj > measure_P.Constant_Value_m) {
      rtb_Gain_pj = measure_P.Constant1_Value_jcfawyw2;
    }
  }

  if (measure_P.Constant6_Value_jcfa) {
    measure_B.Switch2_h1wibj25m = rtb_Gain_pj + measure_P.Bias1_Bias_jcfaw;
  } else {
    measure_B.Switch2_h1wibj25m = rtb_Gain_pj + measure_P.Bias_Bias_jcfaw;
  }

  {
    measure_B.SFunction_ilzn55 = (uint32_T)measure_B.Switch2_h1wibj25m;
  }

  if (rtb_Compare_ks && (measure_P.Constant2_Value_jc)) {
    rtb_UnitDelay1_c = measure_B.SFunction_ilzn55;
  } else {
    rtb_UnitDelay1_c = measure_DWork.UnitDelay_DSTATE_lmdwo30 -
      measure_P.FixPtConstant_Value_jcfa;
  }

  rtb_LogicalOperator9 = (rtb_UnitDelay1_c > measure_P.Constant_Value_ms3);
  if (rtb_LogicalOperator9) {
    rtb_Switch1_fr = rtb_UnitDelay1_c;
  } else {
    rtb_Switch1_fr = measure_P.int1_Value_jcf;
  }

  if (rtb_Compare_ks) {
    rtb_Switch_nulzsg5ykq = measure_P.Constant_Value_bm;
  }

  if (rtb_LogicalOperator_nx) {
    rtb_Switch1_a = measure_P.int2_Value_jcfa;
  }

  rtb_FixPtSum1_cotnt = rtb_Switch1_a - measure_P.FixPtConstant_Value_jcfawyw2o0;
  if (rtb_LogicalOperator12) {
    rtb_Switch1_a = measure_DWork.UnitDelay1_DSTATE_j;
  } else {
    rtb_Switch1_a = measure_P.const_Value_n;
  }

  rtb_LogicalOperator_nx = (rtb_Switch1_a == measure_P.Constant_Value_b4);
  rtb_LogicalOperator12 = (rtb_LogicalOperator_nx && rtb_Disturbance_All_Phases);
  rtb_LogicalOperator1 = (rtb_LogicalOperator12 && (measure_DWork.delay_DSTATE_h));
  rtb_Any_Phases_Not_Disturbed = !rtb_LogicalOperator12;
  rtb_Gain_pj = measure_P.Gain_Gain_he * measure_P.Constant4_Value_g;
  if (measure_P.Constant6_Value_h) {
    measure_B.Switch2_c = rtb_Gain_pj + measure_P.Bias1_Bias_h;
  } else {
    measure_B.Switch2_c = rtb_Gain_pj + measure_P.Bias_Bias_h;
  }

  {
    measure_B.SFunction_p = (uint32_T)measure_B.Switch2_c;
  }

  if (rtb_UnitDelay4_dq) {
    rtb_UnitDelay1_c = measure_B.SFunction_p + measure_P.FixPtConstant_Value_he;
  } else {
    rtb_UnitDelay1_c = measure_DWork.UnitDelay_DSTATE_pd -
      measure_P.FixPtConstant_Value_h;
  }

  rtb_LogicalOperator12 = (rtb_UnitDelay1_c > measure_P.Constant_Value_he);
  if (rtb_LogicalOperator12) {
    rtb_Switch1_j = rtb_UnitDelay1_c;
  } else {
    rtb_Switch1_j = measure_P.int1_Value_h;
  }

  rtb_LogicalOperator2_npqx = ((measure_DWork.UnitDelay_DSTATE_pdo) ||
    ((!rtb_LogicalOperator12) && rtb_LogicalOperator1));
  rtb_UnitDelay1_c = measure_DWork.UnitDelay1_DSTATE_ac;
  rtb_LogicalOperator1 = (rtb_UnitDelay4_dq &&
    (measure_DWork.UnitDelay_DSTATE_pdoi));
  rtb_Gain_pj = measure_P.Gain_Gain_heb * measure_P.Constant3_Value;
  if (measure_P.Constant6_Value_he) {
    measure_B.Switch2_c1 = rtb_Gain_pj + measure_P.Bias1_Bias_he;
  } else {
    measure_B.Switch2_c1 = rtb_Gain_pj + measure_P.Bias_Bias_he;
  }

  {
    measure_B.SFunction_pr = (uint32_T)measure_B.Switch2_c1;
  }

  if (!rtb_LogicalOperator1) {
    rtb_UnitDelay1_c = measure_B.SFunction_pr +
      measure_P.FixPtConstant_Value_heb;
  }

  rtb_LogicalOperator12 = (rtb_UnitDelay1_c == measure_P.Constant_Value_heb);
  if (rtb_UnitDelay4_dq && ((rtb_RelationalOperator_o ||
        rtb_RelationalOperator_os) || rtb_RelationalOperator_osa)) {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_DWork.UnitDelay1_DSTATE_ac4;
  } else {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_P.const_Value_h;
  }

  rtb_Compare_ks = (rtb_UnitDelay1_pu5rdhlnellvz ==
                    measure_P.Constant_Value_hebr);
  rtb_LogicalOperator2_npqxol = (rtb_LogicalOperator2_npqx &&
    (!(rtb_LogicalOperator12 || rtb_Compare_ks)));
  if (rtb_Compare_ks) {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_P.int2_Value_h;
  }

  rtb_FixPtSum1_a = rtb_UnitDelay1_pu5rdhlnellvz -
    measure_P.FixPtConstant_Value_hebr;
  if (rtb_LogicalOperator12) {
    rtb_UnitDelay1_c = measure_P.int1_Value_he;
  }

  rtb_FixPtSum1_ah = rtb_UnitDelay1_c - measure_P.FixPtConstant_Value_hebrs;
  rtb_Add1_fs_idx_0 = rtb_TrigonometricFunction_i -
    measure_DWork.UnitDelay3_DSTATE_i5z5;
  if (rtb_Add1_fs_idx_0 < measure_P.Constant_Value_apbn) {
    rtb_Add1_fs_idx_0 += measure_P.Bias1_Bias_ap;
  } else {
    if (rtb_Add1_fs_idx_0 > measure_P.Constant_Value_apb) {
      rtb_Add1_fs_idx_0 += measure_P.Bias_Bias_ap;
    }
  }

  rtb_Add1_fs_idx_0 *= measure_P.Gain_Gain_ap;
  if (rtb_Compare_f) {
    rtb_UnitDelay1_lccp = measure_P.int1_Value_k;
  }

  rtb_FixPtSum1_e = rtb_UnitDelay1_lccp - measure_P.FixPtConstant_Value_k;
  if (rtb_Compare_j1k4d50fkuukjs) {
    rtb_Switch1_pwrmjy = measure_P.int2_Value_k;
  }

  rtb_FixPtSum1_ec = rtb_Switch1_pwrmjy - measure_P.FixPtConstant_Value_ki;
  if (rtb_Add1_fs_idx_0 < measure_P.Constant_Value_mv) {
    rtb_Add1_fs_idx_0 = -rtb_Add1_fs_idx_0;
  }

  rtb_Sum1_g5i = measure_P.Gain_Gain_p * rtb_Add1_fs_idx_0;
  rtb_Switch1_np = measure_P.Gain1_Gain_p * rtb_UnitDelay_i;
  if (rtb_Compare_j1k4d50fkuukj) {
    rtb_Switch1_pwrm = measure_P.int2_Value_o;
  }

  rtb_FixPtSum1_ecs = rtb_Switch1_pwrm - measure_P.FixPtConstant_Value_o;
  if (rtb_Compare_j1k4d50fkuukjsr) {
    rtb_Switch1_pwrmj = measure_P.int2_Value_od;
  }

  rtb_FixPtSum1_ecsn = rtb_Switch1_pwrmj - measure_P.FixPtConstant_Value_od;
  rtb_Add1_fs_idx_0 = rtb_TrigonometricFunction_ix -
    measure_DWork.UnitDelay3_DSTATE_i5z5o;
  if (rtb_Add1_fs_idx_0 < measure_P.Constant_Value_i2jfb) {
    rtb_Add1_fs_idx_0 += measure_P.Bias1_Bias_i2;
  } else {
    if (rtb_Add1_fs_idx_0 > measure_P.Constant_Value_i2jf) {
      rtb_Add1_fs_idx_0 += measure_P.Bias_Bias_i2;
    }
  }

  rtb_Add1_fs_idx_0 *= measure_P.Gain_Gain_i2;
  if (rtb_Compare_gw) {
    rtb_Switch1_dg2as0wb = measure_P.int1_Value_m;
  }

  rtb_FixPtSum1_ecsns = rtb_Switch1_dg2as0wb - measure_P.FixPtConstant_Value_ma;
  if (rtb_Compare_g3iwu32gm4xoql) {
    rtb_Switch1_dg2as0w = measure_P.int2_Value_m;
  }

  rtb_FixPtSum1_ecsnsv = rtb_Switch1_dg2as0w - measure_P.FixPtConstant_Value_maw;
  if (rtb_Add1_fs_idx_0 < measure_P.Constant_Value_ij) {
    rtb_Add1_fs_idx_0 = -rtb_Add1_fs_idx_0;
  }

  rtb_Sum1_gh = measure_P.Gain_Gain_oe * rtb_Add1_fs_idx_0;
  rtb_AbsVI_k = measure_P.Gain1_Gain_oe * rtb_UnitDelay_it;
  if (rtb_Compare_g3iwu32gm4xoq) {
    rtb_Switch1_dg2as = measure_P.int2_Value_kc;
  }

  rtb_FixPtSum1_ecsnsvo = rtb_Switch1_dg2as - measure_P.FixPtConstant_Value_kc;
  if (rtb_Compare_g3iwu32gm4xoqly) {
    rtb_Switch1_dg2as0 = measure_P.int2_Value_kcq;
  }

  rtb_FixPtSum1_ecsnsvom = rtb_Switch1_dg2as0 -
    measure_P.FixPtConstant_Value_kcq;
  rtb_Add1_fs_idx_0 = rtb_TrigonometricFunction_ixv -
    measure_DWork.UnitDelay3_DSTATE_i5z5oq;
  if (rtb_Add1_fs_idx_0 < measure_P.Constant_Value_orgz) {
    rtb_Add1_fs_idx_0 += measure_P.Bias1_Bias_or;
  } else {
    if (rtb_Add1_fs_idx_0 > measure_P.Constant_Value_org) {
      rtb_Add1_fs_idx_0 += measure_P.Bias_Bias_or;
    }
  }

  rtb_Add1_fs_idx_0 *= measure_P.Gain_Gain_or;
  if (rtb_Compare_il) {
    rtb_Switch1_mf0c25z = measure_P.int1_Value_my;
  }

  rtb_FixPtSum1_ecsnsvomv = rtb_Switch1_mf0c25z -
    measure_P.FixPtConstant_Value_my;
  if (rtb_Compare_dtgasgy1ciwmtjh) {
    rtb_Switch1_mf0c25 = measure_P.int2_Value_my;
  }

  rtb_Switch1_mf0c25z = rtb_Switch1_mf0c25 - measure_P.FixPtConstant_Value_my5;
  if (rtb_Add1_fs_idx_0 < measure_P.Constant_Value_in) {
    rtb_Add1_fs_idx_0 = -rtb_Add1_fs_idx_0;
  }

  rtb_UnaryMinus_g = measure_P.Gain_Gain_jn * rtb_Add1_fs_idx_0;
  rtb_Switch_jpt = measure_P.Gain1_Gain_jn * rtb_UnitDelay_itx;
  if (rtb_Compare_dtgasgy1ciwmtj) {
    rtb_Switch1_mf0c = measure_P.int2_Value_ok;
  }

  rtb_Switch1_dg2as0 = rtb_Switch1_mf0c - measure_P.FixPtConstant_Value_ok;
  if (rtb_Compare_ji) {
    rtb_Switch1_mf0c2 = measure_P.int2_Value_okw;
  }

  rtb_Switch1_dg2as = rtb_Switch1_mf0c2 - measure_P.FixPtConstant_Value_okw;
  measure_B.DataTypeConversion = (real_T)(((rtb_UnitDelay2_i >
    measure_P.Constant_Value_fcb2m) && (rtb_UnitDelay2_i <
    measure_P.Constant_Value_fcb2)) && ((((rtb_Bias >
    measure_P.Constant_Value_fcb2ml45) && (rtb_Bias <
    measure_P.Constant_Value_fcb2ml4)) && ((rtb_Bias1 >
    measure_P.Constant_Value_fcb2ml) && (rtb_Bias1 <
    measure_P.Constant_Value_fcb))) && ((rtb_Bias2 >
    measure_P.Constant_Value_fcb2ml45ca) && (rtb_Bias2 <
    measure_P.Constant_Value_fcb2ml45c))));
  if (rtb_Compare_k) {
    rtb_Switch1_dg2as0w = rtb_Switch_e;
  } else {
    rtb_Switch1_dg2as0w = measure_P.int1_Value_f;
  }

  if (rtb_Compare_k3) {
    rtb_Switch1_dg2as0wb = rtb_Switch_er;
  } else {
    rtb_Switch1_dg2as0wb = measure_P.int1_Value_fc;
  }

  if (rtb_Compare_k3k) {
    rtb_UnitDelay1_pu5rdhlnellvz = rtb_Switch_ert;
  } else {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_P.int1_Value_fcb;
  }

  if (rtb_Compare_js) {
    rtb_UnitDelay1_c = rtb_Bias_aswd3;
  } else {
    rtb_UnitDelay1_c = measure_P.int1_Value_hu;
  }

  if (rtb_Compare_jsl) {
    rtb_UnitDelay1_b = measure_P.int2_Value_hu;
  }

  rtb_Switch1_pwrmj = rtb_UnitDelay1_b - measure_P.FixPtConstant_Value_huy;
  if (rtb_LogicalOperator1_pvh3) {
    measure_B.Switch_lli5 = measure_P.double_Value_mqco;
  } else {
    measure_B.Switch_lli5 = (measure_B.ACripple1stestimate_n +
      measure_DWork.UnitDelay4_DSTATE_edu) +
      measure_DWork.UnitDelay2_DSTATE_e5yc1;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_jp[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_jb;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lli5;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithO_mqco;
      VDD_out++;
    }

    measure_B.VariableDiscret_g0z = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithO_mqco)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_eg0) {
    measure_B.Switch_lli5y = measure_P.double_Value_mqco2;
  } else {
    measure_B.Switch_lli5y = (measure_B.ACripple1stestimate_n +
      measure_DWork.UnitDelay4_DSTATE_edua) +
      measure_DWork.UnitDelay2_DSTATE_e5yc1i;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_hh[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_hm;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lli5y;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywith_mqco2;
      VDD_out++;
    }

    measure_B.VariableDiscret_ay = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywith_mqco2)
      *VDD_in = 0;
  }

  if (rtb_Switch6_idx) {
    rtb_Add1_fs_idx_0 = measure_B.Switch_lli5 - measure_B.VariableDiscret_g0z;
  } else {
    rtb_Add1_fs_idx_0 = measure_B.Switch_lli5y - measure_B.VariableDiscret_ay;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_mj[0];
    int_T *VDD_in = (int_T*)&measure_DWork.VariableDiscret_gnb;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.ACripple1stestimate_n;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTw_mqc;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscret_iy = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTw_mqc)
      measure_B.VariableDiscret_mi = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscret_mi = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTw_mqc)
      *VDD_in = 0;
  }

  rtb_Switch = measure_B.ACripple1stestimate_n - ((rtb_Add1_fs_idx_0 -
    ((measure_B.VariableDiscret_iy * rtb_Switch_jkaja) +
     (measure_B.VariableDiscret_mi * rtb_MathFunction_pl))) * rtb_Switch_j);
  rtb_UnitDelay1_lccp = measure_DWork.UnitDelay_DSTATE_otr +
    measure_P.Bias_Bias_mqco2g;
  if (rtb_UnitDelay1_lccp < measure_DWork.UnitDelay_DSTATE_otr) {
    rtb_UnitDelay1_lccp = MAX_uint32_T;
  }

  rtb_AbsVI = measure_DWork.UnitDelay_DSTATE_o;
  rtb_LogicalOperator2_npqx = (measure_DWork.UnitDelay_DSTATE_o >
    measure_P.Constant_Value_pi);
  if (measure_P.Constant_Value_f4) {
    rtb_LogicalOperator1_pvh3 = (rtb_LogicalOperator2_npqx &&
      (measure_DWork.delay_DSTATE_j0));
  } else {
    rtb_LogicalOperator1_pvh3 = ((rtb_LogicalOperator2_npqx ^
      measure_DWork.delay1_DSTATE_kz) && (measure_DWork.UnitDelay_DSTATE_otrxo));
  }

  rtb_LogicalOperator1_pvh3 = ((!measure_DWork.UnitDelay2_DSTATE_e5yc1iho) &&
    rtb_LogicalOperator1_pvh3);
  if (rtb_LogicalOperator1_pvh3) {
    rtb_Switch1_pwrm = rtb_UnitDelay1_lccp;
  } else {
    rtb_Switch1_pwrm = measure_DWork.UnitDelay2_DSTATE_e5yc1ih;
  }

  if (rtb_LogicalOperator1_pvh3) {
    rtb_Gain_pj = measure_DWork.UnitDelay_DSTATE_o -
      measure_DWork.UnitDelay1_DSTATE_dgz;
    if (rtb_Gain_pj < measure_P.Constant_Value_m4s) {
      rtb_Switch1_l = -rtb_Gain_pj;
    } else {
      rtb_Switch1_l = rtb_Gain_pj;
    }

    if (rtb_Switch1_l < measure_P.Constant_Value_cq) {
      rtb_Gain_pj = measure_P.Constant1_Value_mqco2g;
    }

    rtb_Switch1_iew = (measure_DWork.UnitDelay1_DSTATE_dgz / rtb_Gain_pj) *
      measure_P.T2T1_Gain_m;
    rtb_Sum2_i = rtb_Switch1_iew - measure_DWork.UnitDelay4_DSTATE_eduao;
  } else {
    rtb_Switch1_iew = measure_DWork.UnitDelay1_DSTATE_dgzm;
    rtb_Sum2_i = measure_DWork.UnitDelay1_DSTATE_dgzmv;
  }

  rtb_Add1_fs_idx_0 = (measure_P.Gain_Gain_mqco * ((real_T)rtb_Switch1_pwrm)) +
    rtb_Sum2_i;
  if (rtb_Add1_fs_idx_0 < measure_P.Constant_Value_c5) {
    rtb_Add1_fs_idx_0 = measure_P.Constant_Value_h1s;
  }

  rtb_IpktoIrms_n = (1.0 / rtb_Add1_fs_idx_0) * measure_P.Gain_Gain_mqco2;
  if (rtb_Compare_ky) {
    rtb_Switch1_ie = measure_P.Constant_Value_mqco2gbune;
  } else {
    rtb_Gain_pj = ((measure_DWork.UnitDelay1_DSTATE_dg + rtb_IpktoIrms_n) *
                   measure_P.Gain_Gain_m) -
      measure_DWork.UnitDelay1_DSTATE_dgzmvr;
    if (rtb_Gain_pj < measure_P.Constant_Value_mqco2gbu) {
      rtb_Gain_pj = measure_P.Constant_Value_mqco2;
    } else {
      if (rtb_Gain_pj > measure_P.Constant_Value_mqco) {
        rtb_Gain_pj = measure_P.Constant1_Value_mq;
      }
    }

    rtb_Gain_pj += measure_DWork.UnitDelay1_DSTATE_dgzmvr;
    if (rtb_Gain_pj < measure_P.Constant_Value_mqco2gbun) {
      rtb_Switch1_ie = measure_P.Constant_Value_mqco2gb;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_mqco2g) {
      rtb_Switch1_ie = measure_P.Constant1_Value_mqc;
    } else {
      rtb_Switch1_ie = rtb_Gain_pj;
    }
  }

  rtb_Gain_pj = measure_P.Gain2_Gain_mq * rtb_Switch1_ie;
  if (measure_P.Constant6_Value_m) {
    if (rtb_Gain_pj > measure_P.Constant_Value_ipg) {
      measure_B.Switch2_dm = rtb_Gain_pj + measure_P.Bias1_Bias_m;
    } else {
      measure_B.Switch2_dm = rtb_Gain_pj + measure_P.Bias_Bias_m;
    }
  } else {
    measure_B.Switch2_dm = rtb_Gain_pj;
  }

  {
    measure_B.SFunction_jf = (int32_T)measure_B.Switch2_dm;
  }

  if (((real_T)measure_B.SFunction_jf) < measure_P.Constant_Value_m2) {
    rtb_Add1_fs_idx = measure_P.Constant_Value_mqco2gbunew;
  } else {
    rtb_Add1_fs_idx = (real_T)measure_B.SFunction_jf;
  }

  rtb_Gain_pj = ((1.0 / rtb_Switch1_ie) * rtb_Add1_fs_idx) -
    measure_DWork.UnitDelay1_DSTATE_dgzmvrp;
  if (rtb_Gain_pj < measure_P.Constant_Value_lc) {
    rtb_Add1_fs_idx_1 = measure_P.Constant_Value_mqc;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_mq) {
    rtb_Add1_fs_idx_1 = measure_P.Constant1_Value_m;
  } else {
    rtb_Add1_fs_idx_1 = rtb_Gain_pj;
  }

  rtb_MathFunction1 = rtb_Add1_fs_idx_1 +
    measure_DWork.UnitDelay1_DSTATE_dgzmvrp;
  if (rtb_Compare_ky) {
    rtb_Switch1_pwrmjy = rtb_Switch_lli5ykm;
  } else {
    rtb_Switch1_pwrmjy = measure_P.int1_Value_mq;
  }

  rtb_Add1_fs_idx_1 = std::exp((measure_P.Gain1_Gain_mqc * rtb_Switch1_ie) *
    measure_P.Gain2_Gain_mqc);
  rtb_Switch1_l = (measure_P.double1_Value_m - rtb_Add1_fs_idx_1) * rtb_Switch;
  rtb_Add1_fs_idx_0 = (measure_P.Gain1_Gain_mqco * rtb_Add1_fs_idx_0) +
    measure_P.Bias_Bias_mqco;
  if (rtb_Add1_fs_idx_0 < measure_P.Constant_Value_pu) {
    rtb_Add1_fs_idx_0 = measure_P.Constant_Value_l;
  }

  rtb_Gain_pj = (measure_P.Gain_Gain_mqco2g * rtb_Add1_fs_idx_0) +
    measure_P.Bias_Bias_mqco2;
  if (rtb_Gain_pj < measure_P.Constant_Value_lg) {
    rtb_Gain_pj = measure_P.Constant_Value_mqco2gbunewgpha;
  } else {
    if (rtb_Gain_pj > measure_P.Constant_Value_mqco2gbunewgph) {
      rtb_Gain_pj = measure_P.Constant1_Value_mqco2;
    }
  }

  if (measure_P.Constant6_Value_mq) {
    measure_B.Switch2_dmf = rtb_Gain_pj + measure_P.Bias1_Bias_mqc;
  } else {
    measure_B.Switch2_dmf = rtb_Gain_pj + measure_P.Bias_Bias_mqc;
  }

  {
    measure_B.SFunction_jft = (uint32_T)measure_B.Switch2_dmf;
  }

  if (rtb_LogicalOperator1_pvh3 && (measure_P.Constant2_Value_m)) {
    rtb_UnitDelay1_b = measure_B.SFunction_jft;
  } else {
    rtb_UnitDelay1_b = measure_DWork.UnitDelay_DSTATE_otrx -
      measure_P.FixPtConstant_Value_mq;
  }

  rtb_LogicalOperator1 = (rtb_UnitDelay1_b > measure_P.Constant_Value_ob);
  if (rtb_LogicalOperator1) {
    rtb_Switch1_ia = rtb_UnitDelay1_b;
  } else {
    rtb_Switch1_ia = measure_P.int1_Value_mqc;
  }

  if (rtb_LogicalOperator1_pvh3) {
    rtb_UnitDelay1_b = measure_P.Constant_Value_o2h;
  } else {
    rtb_UnitDelay1_b = rtb_UnitDelay1_lccp;
  }

  if (rtb_LogicalOperator_nx) {
    rtb_Switch1_a = measure_P.int2_Value_a;
  }

  rtb_UnitDelay1_lccp = rtb_Switch1_a - measure_P.FixPtConstant_Value_p;
  measure_B.Gain1 = measure_P.Gain1_Gain_k * measure_U.Vabcpu[0];
  rtb_Ts_FFT_c *= measure_P.Gain5_Gain;
  if (rtb_Ts_FFT_c < measure_P.Constant_Value_md) {
    rtb_Ts_FFT_c = measure_P.Constant_Value_ok;
  }

  rtb_Ts_FFT_c = 1.0 / rtb_Ts_FFT_c;
  measure_B.Gain8 = measure_P.Gain8_Gain * rtb_Ts_FFT_c;

  {
    int_T ok = 1;
    real_T t,a,D1,D2,D3;
    real_T* FFT_Data = (real_T*)measure_B.SFunction_o1;
    D1 = measure_DWork.SFunction_RWORK[0] - measure_B.Gain1;
    D2 = measure_DWork.SFunction_RWORK[1] - D1;
    D3 = measure_DWork.SFunction_RWORK[2] - D2;
    measure_B.SFunction_o2 = measure_DWork.SFunction_RWORK[3] + 1;
    while (ok) {
      t = measure_B.SFunction_o2 - measure_B.Gain8;
      ok = (t>=0);
      if (ok) {
        measure_B.SFunction_o2 = t;
        a = measure_B.Gain1 + D1*measure_B.SFunction_o2;
        t = measure_B.SFunction_o2 * (measure_B.SFunction_o2-1);
        a += D2*t*0.5;
        t *= (measure_B.SFunction_o2-2);
        a += D3*t/6;
        measure_DWork.SFunction_IWORK++;
        if (measure_DWork.SFunction_IWORK > (64-1) ) {
          measure_DWork.SFunction_IWORK= 0;
        }

        FFT_Data[measure_DWork.SFunction_IWORK]= a;
      }
    }

    measure_B.SFunction_o3 = measure_DWork.SFunction_IWORK;
    measure_DWork.SFunction_RWORK[0] = measure_B.Gain1;
    measure_DWork.SFunction_RWORK[1] = D1;
    measure_DWork.SFunction_RWORK[2] = D2;
    measure_DWork.SFunction_RWORK[3] = measure_B.SFunction_o2;
  }

  rtb_Gain_pj = ((real_T)(measure_B.SFunction_o3 - measure_P.Constant2_Value_c0))
    * rtb_Ts_FFT_c;
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_l = measure_DWork.RateTransition_Buffer0_h;
  }

  rtb_Add1_fs_idx_0 = (((((measure_P.Gain2_Gain_mf * measure_P.Constant9_Value[0])
    * rtb_Gain_pj) + measure_P.udegcompensationsinceusingvefre) +
                        measure_B.RateTransition_l) +
                       measure_P.Constant1_Value_b4) /
    measure_P.Constant2_Value_g;
  rtb_Add1_fs_idx = (((((measure_P.Gain2_Gain_mf * measure_P.Constant9_Value[1])
                        * rtb_Gain_pj) +
                       measure_P.udegcompensationsinceusingvefre) +
                      measure_B.RateTransition_l) + measure_P.Constant1_Value_b4)
    / measure_P.Constant2_Value_g;
  if (measure_P.Constant6_Value_g) {
    measure_B.Switch2_e[0] = rtb_Add1_fs_idx_0 + measure_P.Bias2_Bias;
    measure_B.Switch2_e[1] = rtb_Add1_fs_idx + measure_P.Bias2_Bias;
  } else {
    if (rtb_Add1_fs_idx_0 < measure_P.Constant_Value_ga) {
      measure_B.Switch2_e[0] = rtb_Add1_fs_idx_0 + measure_P.Bias_Bias_g;
    } else {
      measure_B.Switch2_e[0] = rtb_Add1_fs_idx_0;
    }

    if (rtb_Add1_fs_idx < measure_P.Constant_Value_ga) {
      measure_B.Switch2_e[1] = rtb_Add1_fs_idx + measure_P.Bias_Bias_g;
    } else {
      measure_B.Switch2_e[1] = rtb_Add1_fs_idx;
    }
  }

  measure_B.SFunction2[0] = (int32_T)measure_B.Switch2_e[0];
  measure_B.SFunction2[1] = (int32_T)measure_B.Switch2_e[1];
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    memcpy((void *)(&measure_B.RateTransition_a[0]), (void *)
           (&measure_B.SFunction_o1[0]), (sizeof(real_T)) << 6U);
  }

  measure_B.Gain1_f = measure_P.Gain1_Gain_n * measure_U.Vabcpu[1];
  rtb_Ts_FFT *= measure_P.Gain5_Gain_i;
  if (rtb_Ts_FFT < measure_P.Constant_Value_ll) {
    rtb_Ts_FFT = measure_P.Constant_Value_lv;
  }

  rtb_Ts_FFT = 1.0 / rtb_Ts_FFT;
  measure_B.Gain8_j = measure_P.Gain8_Gain_o * rtb_Ts_FFT;

  {
    int_T ok = 1;
    real_T t,a,D1,D2,D3;
    real_T* FFT_Data = (real_T*)measure_B.SFunction_o1_f;
    D1 = measure_DWork.SFunction_RWORK_m[0] - measure_B.Gain1_f;
    D2 = measure_DWork.SFunction_RWORK_m[1] - D1;
    D3 = measure_DWork.SFunction_RWORK_m[2] - D2;
    measure_B.SFunction_o2_l = measure_DWork.SFunction_RWORK_m[3] + 1;
    while (ok) {
      t = measure_B.SFunction_o2_l - measure_B.Gain8_j;
      ok = (t>=0);
      if (ok) {
        measure_B.SFunction_o2_l = t;
        a = measure_B.Gain1_f + D1*measure_B.SFunction_o2_l;
        t = measure_B.SFunction_o2_l * (measure_B.SFunction_o2_l-1);
        a += D2*t*0.5;
        t *= (measure_B.SFunction_o2_l-2);
        a += D3*t/6;
        measure_DWork.SFunction_IWORK_d++;
        if (measure_DWork.SFunction_IWORK_d > (64-1) ) {
          measure_DWork.SFunction_IWORK_d= 0;
        }

        FFT_Data[measure_DWork.SFunction_IWORK_d]= a;
      }
    }

    measure_B.SFunction_o3_n = measure_DWork.SFunction_IWORK_d;
    measure_DWork.SFunction_RWORK_m[0] = measure_B.Gain1_f;
    measure_DWork.SFunction_RWORK_m[1] = D1;
    measure_DWork.SFunction_RWORK_m[2] = D2;
    measure_DWork.SFunction_RWORK_m[3] = measure_B.SFunction_o2_l;
  }

  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_k = measure_DWork.RateTransition_Buffer0_po;
  }

  rtb_Gain_pj = (((((((real_T)(measure_B.SFunction_o3_n -
    measure_P.Constant2_Value_p)) * rtb_Ts_FFT) * (measure_P.Gain2_Gain_h *
    measure_P.Constant9_Value[2])) + measure_P.udegcompensationsinceusingvef_i)
                  + measure_B.RateTransition_k) + measure_P.Constant1_Value_p) /
    measure_P.Constant2_Value_ht;
  if (measure_P.Constant6_Value_o) {
    measure_B.Switch2_df = rtb_Gain_pj + measure_P.Bias2_Bias_o;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_oe) {
    measure_B.Switch2_df = rtb_Gain_pj + measure_P.Bias_Bias_oe;
  } else {
    measure_B.Switch2_df = rtb_Gain_pj;
  }

  measure_B.SFunction2_i = (int32_T)measure_B.Switch2_df;
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    memcpy((void *)(&measure_B.RateTransition_g5[0]), (void *)
           (&measure_B.SFunction_o1_f[0]), (sizeof(real_T)) << 6U);
  }

  measure_B.Gain1_p = measure_P.Gain1_Gain_oq * measure_U.Vabcpu[2];
  rtb_Switch4 *= measure_P.Gain5_Gain_f;
  if (rtb_Switch4 < measure_P.Constant_Value_j1) {
    rtb_Switch4 = measure_P.Constant_Value_gj;
  }

  rtb_Gain_pj = 1.0 / rtb_Switch4;
  measure_B.Gain8_d = measure_P.Gain8_Gain_n * rtb_Gain_pj;

  {
    int_T ok = 1;
    real_T t,a,D1,D2,D3;
    real_T* FFT_Data = (real_T*)measure_B.SFunction_o1_k;
    D1 = measure_DWork.SFunction_RWORK_o[0] - measure_B.Gain1_p;
    D2 = measure_DWork.SFunction_RWORK_o[1] - D1;
    D3 = measure_DWork.SFunction_RWORK_o[2] - D2;
    measure_B.SFunction_o2_h = measure_DWork.SFunction_RWORK_o[3] + 1;
    while (ok) {
      t = measure_B.SFunction_o2_h - measure_B.Gain8_d;
      ok = (t>=0);
      if (ok) {
        measure_B.SFunction_o2_h = t;
        a = measure_B.Gain1_p + D1*measure_B.SFunction_o2_h;
        t = measure_B.SFunction_o2_h * (measure_B.SFunction_o2_h-1);
        a += D2*t*0.5;
        t *= (measure_B.SFunction_o2_h-2);
        a += D3*t/6;
        measure_DWork.SFunction_IWORK_a++;
        if (measure_DWork.SFunction_IWORK_a > (64-1) ) {
          measure_DWork.SFunction_IWORK_a= 0;
        }

        FFT_Data[measure_DWork.SFunction_IWORK_a]= a;
      }
    }

    measure_B.SFunction_o3_n1 = measure_DWork.SFunction_IWORK_a;
    measure_DWork.SFunction_RWORK_o[0] = measure_B.Gain1_p;
    measure_DWork.SFunction_RWORK_o[1] = D1;
    measure_DWork.SFunction_RWORK_o[2] = D2;
    measure_DWork.SFunction_RWORK_o[3] = measure_B.SFunction_o2_h;
  }

  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_j2 = measure_DWork.RateTransition_Buffer0_e;
  }

  rtb_Gain_pj = (((((((real_T)(measure_B.SFunction_o3_n1 -
    measure_P.Constant2_Value_kj)) * rtb_Gain_pj) * (measure_P.Gain2_Gain_o *
    measure_P.Constant9_Value[3])) + measure_P.udegcompensationsinceusingvef_f)
                  + measure_B.RateTransition_j2) + measure_P.Constant1_Value_l) /
    measure_P.Constant2_Value_k;
  if (measure_P.Constant6_Value_fe) {
    measure_B.Switch2_b = rtb_Gain_pj + measure_P.Bias2_Bias_f;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_feg) {
    measure_B.Switch2_b = rtb_Gain_pj + measure_P.Bias_Bias_f;
  } else {
    measure_B.Switch2_b = rtb_Gain_pj;
  }

  measure_B.SFunction2_kp = (int32_T)measure_B.Switch2_b;
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    memcpy((void *)(&measure_B.RateTransition_gx[0]), (void *)
           (&measure_B.SFunction_o1_k[0]), (sizeof(real_T)) << 6U);
  }

  {
    measure_DWork.SF_FixedDiscreteDelaySfunction_ = measure_B.Switch_bn;
  }

  measure_DWork.UnitDelay4_DSTATE_ir = rtb_LogicalOperator2_npqxol;
  measure_DWork.delay_DSTATE = !rtb_UnitDelay4_dq;
  measure_DWork.UnitDelay_DSTATE = rtb_Switch1;

  {
    measure_DWork.SF_FixedDiscreteDelaySfunctio_b = measure_B.Switch2_h1wib;
  }

  measure_DWork.UnitDelay4_DSTATE_czl44j1ipa1 = rtb_LogicalOperator1_fmgwx;
  measure_DWork.delay_DSTATE_i = !rtb_UnitDelay4_dmwj4s1jwn3;
  measure_DWork.UnitDelay_DSTATE_l = rtb_Switch1_i;
  measure_DWork.UnitDelay_DSTATE_lm = rtb_Switch_nu;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j45 = rtb_LogicalOperator1_fw;
  measure_DWork.delay1_DSTATE = rtb_Compare;
  measure_DWork.delay1_DSTATE_c = rtb_Compare_h;
  measure_DWork.UnitDelay3_DSTATE = rtb_TrigonometricFunction;
  measure_DWork.UnitDelay1_DSTATE = measure_U.Vabcpu[1];
  measure_DWork.UnitDelay2_DSTATE = rtb_UnitDelay1;
  measure_DWork.UnitDelay1_DSTATE_o = measure_U.Vabcpu[2];
  measure_DWork.UnitDelay2_DSTATE_k = rtb_UnitDelay1_p;
  measure_DWork.UnitDelay1_DSTATE_g = measure_U.Vabcpu[0];
  measure_DWork.UnitDelay2_DSTATE_e = rtb_UnitDelay1_n;
  measure_DWork.UnitDelay4_DSTATE = measure_B.Gain;
  measure_DWork.UnitDelay2_DSTATE_h = measure_B.Switch;
  measure_DWork.delay_DSTATE_i2 = !rtb_Compare_h;
  measure_DWork.UnitDelay4_DSTATE_c = measure_B.Gain;
  measure_DWork.UnitDelay2_DSTATE_h5 = measure_B.Switch_n;
  measure_DWork.UnitDelay4_DSTATE_cz = measure_B.Switch2_h;
  measure_DWork.UnitDelay2_DSTATE_h5b = measure_B.Switch_nu;
  measure_DWork.delay_DSTATE_i2w = !rtb_Compare;
  measure_DWork.UnitDelay4_DSTATE_czl = measure_B.Switch2_h;
  measure_DWork.UnitDelay2_DSTATE_h5br = measure_B.Switch_nul;
  measure_DWork.UnitDelay4_DSTATE_czl4 = measure_B.Switch4;
  measure_DWork.UnitDelay2_DSTATE_h5brd = measure_B.Switch_nulz;
  measure_DWork.UnitDelay4_DSTATE_czl44 = measure_B.Switch4;
  measure_DWork.UnitDelay2_DSTATE_h5brdq = measure_B.Switch_nulzs;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jx = rtb_FixPtSum1_co;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxq = rtb_FixPtSum1_c;
  measure_DWork.delay1_DSTATE_ce = rtb_Compare_hpz455i02;
  measure_DWork.UnitDelay4_DSTATE_czl44j = measure_B.Switch2_h1w;
  measure_DWork.UnitDelay2_DSTATE_h5brdqc = measure_B.Switch_nulzsg;
  measure_DWork.UnitDelay2_DSTATE_h5brdqci = rtb_Switch_jka;
  measure_DWork.delay_DSTATE_i2wj = !rtb_Compare_hpz455i02;
  measure_DWork.UnitDelay4_DSTATE_czl44j1 = measure_B.Switch2_h1w;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz = measure_B.Switch_nulzsg5;
  measure_DWork.UnitDelay_DSTATE_lmdw = rtb_Switch1_bt;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqh = rtb_FixPtSum1;
  measure_DWork.UnitDelay1_DSTATE_k = rtb_Switch1_pwrmj;
  measure_DWork.UnitDelay2_DSTATE_kg = rtb_Switch_k;
  measure_DWork.UnitDelay4_DSTATE_h = rtb_LogicalOperator2_f3l;
  measure_DWork.UnitDelay1_DSTATE_aqjz = rtb_FixPtSum1_ecs;
  measure_DWork.delay1_DSTATE_d = rtb_Compare_d;
  measure_DWork.UnitDelay_DSTATE_p = rtb_Sum;
  measure_DWork.UnitDelay4_DSTATE_j = measure_B.Product[0];
  measure_DWork.UnitDelay2_DSTATE_g = measure_B.Switch_l;
  measure_DWork.delay_DSTATE_iz = !rtb_Compare_d;
  measure_DWork.UnitDelay4_DSTATE_jb = measure_B.Product[0];
  measure_DWork.UnitDelay2_DSTATE_gb = measure_B.Switch_lv;
  measure_DWork.UnitDelay4_DSTATE_jbk = measure_B.Product[1];
  measure_DWork.UnitDelay2_DSTATE_gbj = measure_B.Switch_lv2;
  measure_DWork.UnitDelay4_DSTATE_jbkw = measure_B.Product[1];
  measure_DWork.UnitDelay2_DSTATE_gbjg = measure_B.Switch_lv2a;
  measure_DWork.UnitDelay1_DSTATE_aqjzx = rtb_FixPtSum1_ecsnsvo;
  measure_DWork.UnitDelay4_DSTATE_jbkwm = measure_B.Product_e[0];
  measure_DWork.UnitDelay2_DSTATE_gbjgk = measure_B.Switch_f;
  measure_DWork.UnitDelay4_DSTATE_jbkwms = measure_B.Product_e[0];
  measure_DWork.UnitDelay2_DSTATE_gbjgk5 = measure_B.Switch_f0;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq = measure_B.Product_e[1];
  measure_DWork.UnitDelay2_DSTATE_gbjgk5q = measure_B.Switch_f0o;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2 = measure_B.Product_e[1];
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qb = measure_B.Switch_f0o4;
  measure_DWork.UnitDelay1_DSTATE_aqjzxp = rtb_Switch1_dg2as0;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2k = measure_B.Product_h[0];
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx = measure_B.Switch_ng;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv = measure_B.Product_h[0];
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx3 = measure_B.Switch_nge;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2 = measure_B.Product_h[1];
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35 = measure_B.Switch_ngeq;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s = measure_B.Product_h[1];
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35b = measure_B.Switch_ngeqq;
  measure_DWork.delay1_DSTATE_dt = rtb_Compare_ddcrdc;
  measure_DWork.UnitDelay3_DSTATE_i = rtb_Add_p;
  measure_DWork.delay1_DSTATE_dtd = rtb_Compare_ddcrdcv;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s4 = measure_B.Divide_h;
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35bv = measure_B.Switch_lv2ap;
  measure_DWork.delay_DSTATE_izx = !rtb_Compare_ddcrdcv;
  measure_DWork.UnitDelay4_DSTAT_jbkwmsq2kv2s4v = measure_B.Divide_h;
  measure_DWork.UnitDelay2_DSTAT_gbjgk5qbx35bvz = measure_B.Switch_lv2aps;
  measure_DWork.UnitDelay4_DSTA_jbkwmsq2kv2s4vv = measure_B.Divide;
  measure_DWork.UnitDelay2_DSTA_gbjgk5qbx35bvzo = measure_B.Switch_lv2aps4;
  measure_DWork.UnitDelay4_DSTA_g = measure_B.Divide;
  measure_DWork.UnitDelay2_DSTA_i = measure_B.Switch_lv2aps4n;
  measure_DWork.UnitDelay4_DSTA_n = measure_B.Switch6;
  measure_DWork.UnitDelay2_DSTA_a = measure_B.Switch_b;
  measure_DWork.delay_DSTATE_izxx = !rtb_Compare_ddcrdc;
  measure_DWork.UnitDelay4_DSTA_d = measure_B.Switch6;
  measure_DWork.UnitDelay2_DSTA_ai = measure_B.Switch_bo;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpn = rtb_FixPtSum1_ecsn;
  measure_DWork.UnitDelay_DSTATE_mj2f = rtb_LogicalOperator2_n;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnn = rtb_FixPtSum1_ec;
  measure_DWork.UnitDelay_DSTATE_m = rtb_Switch1_np + rtb_Sum1_g5i;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno = rtb_FixPtSum1_e;

  {
    measure_DWork.SF_FixedDiscreteDelaySfunctio_n = measure_B.DataTypeConversion;
  }

  measure_DWork.UnitDelay1_DSTATE_a = rtb_MathFunction2;
  measure_DWork.UnitDelay_DSTATE_i = rtb_Switch1_dg2as0w;
  measure_DWork.UnitDelay1_DSTATE_aq = rtb_MathFunction2_d;
  measure_DWork.UnitDelay_DSTATE_ia = rtb_Switch1_dg2as0wb;
  measure_DWork.UnitDelay1_DSTATE_aqj = rtb_MathFunction2_d0;
  measure_DWork.UnitDelay_DSTATE_iah = rtb_UnitDelay1_pu5rdhlnellvz;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4 = rtb_FixPtSum1_ecsnsvom;
  measure_DWork.UnitDelay_DSTATE_mj2fm = rtb_LogicalOperator2_npq;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4m = rtb_FixPtSum1_ecsnsv;
  measure_DWork.UnitDelay_DSTATE_mj = rtb_AbsVI_k + rtb_Sum1_gh;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml = rtb_FixPtSum1_ecsns;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml3 = rtb_Switch1_dg2as;
  measure_DWork.UnitDelay_DSTATE_mj2fmb = rtb_LogicalOperator2_npqxo;
  measure_DWork.UnitDelay1_DSTAT_aqjzxpnno4ml3e = rtb_Switch1_mf0c25z;
  measure_DWork.UnitDelay_DSTATE_mj2 = rtb_Switch_jpt + rtb_UnaryMinus_g;
  measure_DWork.UnitDelay1_DSTA_aqjzxpnno4ml3e2 = rtb_FixPtSum1_ecsnsvomv;
  measure_DWork.UnitDelay3_DSTATE_i5 = rtb_Add_n;
  measure_DWork.UnitDelay4_DSTA_i = measure_B.Divide_b4;
  measure_DWork.UnitDelay2_DSTA_m = measure_B.Switch_f0o4o;
  measure_DWork.UnitDelay4_DSTA_n3 = measure_B.Divide_b4;
  measure_DWork.UnitDelay2_DSTA_il = measure_B.Switch_f0o4ow;
  measure_DWork.UnitDelay4_DSTA_a = measure_B.Divide_b;
  measure_DWork.UnitDelay2_DSTA_b = measure_B.Switch_f0o4owl;
  measure_DWork.UnitDelay4_DSTA_j = measure_B.Divide_b;
  measure_DWork.UnitDelay2_DSTA_h = measure_B.Switch_f0o4owld;
  measure_DWork.UnitDelay4_DSTA_p = measure_B.Switch6_j;
  measure_DWork.UnitDelay2_DSTA_o = measure_B.Switch_f0o4owldo;
  measure_DWork.UnitDelay4_DSTA_jg = measure_B.Switch6_j;
  measure_DWork.UnitDelay2_DSTA_f = measure_B.Switch_f0o4owldoy;
  measure_DWork.UnitDelay3_DSTATE_i5z = rtb_Add_gl;
  measure_DWork.UnitDelay4_DSTA_ih = measure_B.Divide_nq;
  measure_DWork.UnitDelay2_DSTA_j = measure_B.Switch_ngeqq2;
  measure_DWork.UnitDelay4_DSTA_m = measure_B.Divide_nq;
  measure_DWork.UnitDelay2_DSTA_jm = measure_B.Switch_ngeqq2o;
  measure_DWork.UnitDelay4_DSTA_j5 = measure_B.Divide_n;
  measure_DWork.UnitDelay2_DSTA_c = measure_B.Switch_ngeqq2os;
  measure_DWork.UnitDelay4_DSTA_dj = measure_B.Divide_n;
  measure_DWork.UnitDelay2_DSTA_cm = measure_B.Switch_ngeqq2osh;
  measure_DWork.UnitDelay4_DSTA_l = measure_B.Switch6_m;
  measure_DWork.UnitDelay2_DSTA_p = measure_B.Switch_ngeqq2oshh;
  measure_DWork.UnitDelay4_DSTA_h = measure_B.Switch6_m;
  measure_DWork.UnitDelay2_DSTA_bf = measure_B.Switch_ngeqq2oshhr;
  measure_DWork.delay1_DSTATE_k = rtb_Switch6_idx;
  measure_DWork.UnitDelay4_DSTATE_e = measure_B.Switch_j;
  measure_DWork.UnitDelay2_DSTATE_e5 = measure_B.Switch_ll;
  measure_DWork.UnitDelay2_DSTATE_e5y = rtb_MathFunction1;
  measure_DWork.delay_DSTATE_j = !rtb_Switch6_idx;
  measure_DWork.UnitDelay4_DSTATE_ed = measure_B.Switch_j;
  measure_DWork.UnitDelay2_DSTATE_e5yc = measure_B.Switch_lli;
  measure_DWork.UnitDelay_DSTATE_ot = rtb_Switch1_pwrmjy;
  measure_DWork.UnitDelay_DSTATE_k = rtb_UnitDelay1_c;
  measure_DWork.delay1_DSTATE_b = rtb_Compare_js;
  measure_DWork.UnitDelay1_DSTATE_k2 = rtb_LogicalOperator2_f3;
  measure_DWork.UnitDelay4_DSTA_mm = measure_B.MathFunction;
  measure_DWork.UnitDelay2_DSTA_hi = measure_B.Switch_lv2aps4ne;
  measure_DWork.UnitDelay4_DSTA_pb = measure_B.MathFunction;
  measure_DWork.UnitDelay2_DSTA_iy = measure_B.Switch_lv2aps4ney;
  measure_DWork.UnitDelay4_DSTA_md = measure_B.MathFunction1;
  measure_DWork.UnitDelay2_DSTA_c0 = measure_B.Switch_lv2aps4neyb;
  measure_DWork.UnitDelay4_DSTA_f = measure_B.MathFunction1;
  measure_DWork.UnitDelay2_DSTA_cq = measure_B.Switch_lv2aps4neybf;
  measure_DWork.UnitDelay4_DSTA_ps = measure_B.MathFunction_j;
  measure_DWork.UnitDelay2_DSTA_d = measure_B.Switch_f0o4owldoyu;
  measure_DWork.UnitDelay4_DSTA_k = measure_B.MathFunction_j;
  measure_DWork.UnitDelay2_DSTA_o3 = measure_B.Switch_f0o4owldoyup;
  measure_DWork.UnitDelay4_DSTA_mw = measure_B.MathFunction1_b;
  measure_DWork.UnitDelay2_DSTA_d1 = measure_B.Switch_f0o4owldoyupv;
  measure_DWork.UnitDelay4_DSTA_jz = measure_B.MathFunction1_b;
  measure_DWork.UnitDelay2_DSTA_l = measure_B.Switch_f0o4owldoyupv1;
  measure_DWork.UnitDelay4_DSTA_hx = measure_B.MathFunction_jy;
  measure_DWork.UnitDelay2_DSTA_k = measure_B.Switch_ngeqq2oshhr5;
  measure_DWork.UnitDelay4_DSTA_p4 = measure_B.MathFunction_jy;
  measure_DWork.UnitDelay2_DSTA_lz = measure_B.Switch_ngeqq2oshhr5r;
  measure_DWork.UnitDelay4_DSTA_b = measure_B.MathFunction1_bx;
  measure_DWork.UnitDelay2_DSTA_ls = measure_B.Switch_ngeqq2oshhr5rh;
  measure_DWork.UnitDelay4_DSTA_ay = measure_B.MathFunction1_bx;
  measure_DWork.UnitDelay2_DSTA_a3 = measure_B.Switch_ngeqq2oshhr5rhh;
  measure_DWork.UnitDelay1_DSTATE_f = measure_U.IabcAmps[0];
  measure_DWork.UnitDelay2_DSTATE_m = rtb_UnitDelay1_o;
  measure_DWork.UnitDelay4_DSTATE_d = measure_B.Product_j[0];
  measure_DWork.UnitDelay2_DSTATE_kx = measure_B.Switch_jp;
  measure_DWork.UnitDelay4_DSTATE_do = measure_B.Product_j[0];
  measure_DWork.UnitDelay2_DSTATE_kxh = measure_B.Switch_jpt;
  measure_DWork.UnitDelay4_DSTATE_dot = measure_B.Divide_nf;
  measure_DWork.UnitDelay2_DSTATE_kxh1 = measure_B.Switch_jptu;
  measure_DWork.UnitDelay4_DSTATE_dotl = measure_B.Divide_nf;
  measure_DWork.UnitDelay2_DSTATE_kxh1d = measure_B.Switch_jptuz;
  measure_DWork.UnitDelay4_DSTATE_dotln = measure_B.Product_j[1];
  measure_DWork.UnitDelay2_DSTATE_kxh1dd = measure_B.Switch_jptuzr;
  measure_DWork.UnitDelay4_DSTATE_dotlnl = measure_B.Product_j[1];
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb = measure_B.Switch_jptuzrl;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp = measure_B.Divide_nfu;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb3 = measure_B.Switch_jptuzrlj;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0 = measure_B.Divide_nfu;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33 = measure_B.Switch_jptuzrljf;
  measure_DWork.UnitDelay1_DSTATE_d = measure_U.IabcAmps[1];
  measure_DWork.UnitDelay2_DSTATE_d = rtb_UnitDelay1_f;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0w = measure_B.Product_jq[0];
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33g = measure_B.Switch_jptuzrljf0;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wv = measure_B.Product_jq[0];
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gq = measure_B.Switch_jptuzrljf05;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvp = measure_B.Divide_nfun;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqp = measure_B.Switch_jptuzrljf055;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpy = measure_B.Divide_nfun;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpf = measure_B.Switch_jptuzrljf055w;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpya = measure_B.Product_jq[1];
  measure_DWork.UnitDelay2_DSTAT_kxh1ddb33gqpfj =
    measure_B.Switch_jptuzrljf055wg;
  measure_DWork.UnitDelay4_DSTAT_dotlnlp0wvpyar = measure_B.Product_jq[1];
  measure_DWork.UnitDelay2_DSTA_kxh1ddb33gqpfjt =
    measure_B.Switch_jptuzrljf055wg5;
  measure_DWork.UnitDelay4_DSTA_dotlnlp0wvpyari = measure_B.Divide_nfunb;
  measure_DWork.UnitDelay2_DSTA_n = measure_B.Switch_c;
  measure_DWork.UnitDelay4_DSTA_ls = measure_B.Divide_nfunb;
  measure_DWork.UnitDelay2_DSTA_oz = measure_B.Switch_jc;
  measure_DWork.UnitDelay1_DSTATE_b = measure_U.IabcAmps[2];
  measure_DWork.UnitDelay2_DSTATE_kb = rtb_UnitDelay1_pu;
  measure_DWork.UnitDelay4_DSTA_gs = measure_B.Product_jqy[0];
  measure_DWork.UnitDelay2_DSTA_e = measure_B.Switch_i;
  measure_DWork.UnitDelay4_DSTA_hxo = measure_B.Product_jqy[0];
  measure_DWork.UnitDelay2_DSTA_pl = measure_B.Switch_h;
  measure_DWork.UnitDelay4_DSTA_gn = measure_B.Divide_nfunba;
  measure_DWork.UnitDelay2_DSTA_ck = measure_B.Switch_e;
  measure_DWork.UnitDelay4_DSTA_pz = measure_B.Divide_nfunba;
  measure_DWork.UnitDelay2_DSTA_cs = measure_B.Switch_jce;
  measure_DWork.UnitDelay4_DSTA_d2 = measure_B.Product_jqy[1];
  measure_DWork.UnitDelay2_DSTA_fe = measure_B.Switch_el;
  measure_DWork.UnitDelay4_DSTA_mz = measure_B.Product_jqy[1];
  measure_DWork.UnitDelay2_DSTA_cx = measure_B.Switch_m;
  measure_DWork.UnitDelay4_DSTA_am = measure_B.Divide_nfunbaw;
  measure_DWork.UnitDelay2_DSTA_n1 = measure_B.Switch_jx;
  measure_DWork.UnitDelay4_DSTA_nh = measure_B.Divide_nfunbaw;
  measure_DWork.UnitDelay2_DSTA_ko = measure_B.Switch_je;
  measure_DWork.UnitDelay4_DSTA_fu = measure_B.MathFunction_p;
  measure_DWork.UnitDelay2_DSTA_ef = measure_B.Switch_p;
  measure_DWork.UnitDelay4_DSTA_m5 = measure_B.MathFunction_p;
  measure_DWork.UnitDelay2_DSTA_mh = measure_B.Switch_pi;
  measure_DWork.UnitDelay4_DSTA_e = measure_B.MathFunction1_e;
  measure_DWork.UnitDelay2_DSTA_or = measure_B.Switch_i0;
  measure_DWork.UnitDelay4_DSTA_ju = measure_B.MathFunction1_e;
  measure_DWork.UnitDelay2_DSTA_lt = measure_B.Switch_jv;
  measure_DWork.UnitDelay4_DSTA_hz = measure_B.MathFunction_pc;
  measure_DWork.UnitDelay2_DSTA_fq = measure_B.Switch_k;
  measure_DWork.UnitDelay4_DSTA_mb = measure_B.MathFunction_pc;
  measure_DWork.UnitDelay2_DSTA_d0 = measure_B.Switch_eh;
  measure_DWork.UnitDelay4_DSTA_fp = measure_B.MathFunction1_ew;
  measure_DWork.UnitDelay2_DSTA_mf = measure_B.Switch_o;
  measure_DWork.UnitDelay4_DSTA_pm = measure_B.MathFunction1_ew;
  measure_DWork.UnitDelay2_DSTA_pz = measure_B.Switch_d;
  measure_DWork.UnitDelay4_DSTA_gf = measure_B.MathFunction_pcc;
  measure_DWork.UnitDelay2_DSTA_g = measure_B.Switch_ia;
  measure_DWork.UnitDelay4_DSTA_hc = measure_B.MathFunction_pcc;
  measure_DWork.UnitDelay2_DSTA_hh = measure_B.Switch_cp;
  measure_DWork.UnitDelay4_DSTA_gv = measure_B.MathFunction1_ew0;
  measure_DWork.UnitDelay2_DSTA_cs5 = measure_B.Switch_cn;
  measure_DWork.UnitDelay4_DSTA_g0 = measure_B.MathFunction1_ew0;
  measure_DWork.UnitDelay2_DSTA_fb = measure_B.Switch_g;
  measure_DWork.UnitDelay4_DSTATE_o = measure_B.VI[0];
  measure_DWork.UnitDelay2_DSTATE_n = measure_B.Switch_ez;
  measure_DWork.UnitDelay4_DSTATE_eq = measure_B.VI[0];
  measure_DWork.UnitDelay2_DSTATE_a = measure_B.Switch_h5;
  measure_DWork.UnitDelay4_DSTATE_g = measure_B.Divide_d;
  measure_DWork.UnitDelay2_DSTATE_dq = measure_B.Switch_nh;
  measure_DWork.UnitDelay4_DSTATE_je = measure_B.Divide_d;
  measure_DWork.UnitDelay2_DSTATE_o = measure_B.Switch_mm;
  measure_DWork.UnitDelay4_DSTATE_e1 = measure_B.VI[1];
  measure_DWork.UnitDelay2_DSTATE_c = measure_B.Switch_gg;
  measure_DWork.UnitDelay4_DSTATE_i = measure_B.VI[1];
  measure_DWork.UnitDelay2_DSTATE_f = measure_B.Switch_p4;
  measure_DWork.UnitDelay4_DSTATE_m = measure_B.Divide_g;
  measure_DWork.UnitDelay2_DSTATE_gs = measure_B.Switch_ml;
  measure_DWork.UnitDelay4_DSTATE_n = measure_B.Divide_g;
  measure_DWork.UnitDelay2_DSTATE_p = measure_B.Switch_b1;
  measure_DWork.UnitDelay4_DSTATE_jf = measure_B.VI[2];
  measure_DWork.UnitDelay2_DSTATE_h2 = measure_B.Switch_ny;
  measure_DWork.UnitDelay4_DSTATE_l = measure_B.VI[2];
  measure_DWork.UnitDelay2_DSTATE_ai = measure_B.Switch_n2;
  measure_DWork.UnitDelay4_DSTATE_co = measure_B.Divide_l;
  measure_DWork.UnitDelay2_DSTATE_l = measure_B.Switch_bi;
  measure_DWork.UnitDelay4_DSTATE_j5 = measure_B.Divide_l;
  measure_DWork.UnitDelay2_DSTATE_cm = measure_B.Switch_oh;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhw = rtb_FixPtSum1_cotnt;
  measure_DWork.delay_DSTATE_i2wj4 = rtb_Compare_h4;
  measure_DWork.UnitDelay_DSTATE_lmdwo = rtb_Switch1_hb;
  measure_DWork.UnitDelay_DSTATE_lmdwo300 = rtb_LogicalOperator1_fmgwx;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhwr = rtb_FixPtSum1_cotn;
  measure_DWork.UnitDelay_DSTATE_lmdwo300i = measure_P.Constant_Value_fw;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhwrm = rtb_FixPtSum1_cot;
  measure_DWork.UnitDelay4_DSTATE_czl44j1i = measure_B.ACripple1stestimate;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0 = measure_B.Switch_nulzsg5y;
  measure_DWork.UnitDelay4_DSTATE_czl44j1ip = measure_B.ACripple1stestimate;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j = measure_B.Switch_nulzsg5yk;
  measure_DWork.UnitDelay1_DSTATE_c = rtb_Divide_b4ha;
  measure_DWork.UnitDelay_DSTATE_lmdwo3 = rtb_Switch_nulzsg5ykq;
  measure_DWork.UnitDelay2_DSTAT_h5brdqciz0j45w = rtb_LogicalOperator9;
  measure_DWork.UnitDelay_DSTATE_lmd = rtb_IpktoIrmsconversion +
    rtb_SumofElements;
  measure_DWork.delay_DSTATE_i2wj4d = !rtb_LogicalOperator16;
  measure_DWork.delay1_DSTATE_ces = rtb_LogicalOperator16;
  measure_DWork.UnitDelay_DSTATE_lmdwo300ig = measure_P.Constant_Value_aqm;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j4 = rtb_Switch2_h;
  measure_DWork.UnitDelay1_DSTATE_cm = rtb_Divide_hh;
  measure_DWork.UnitDelay1_DSTATE_cmn = rtb_Divide_nqzy;
  measure_DWork.UnitDelay4_DSTATE_czl44j1ipa = rtb_Divide_nqzy;
  measure_DWork.UnitDelay1_DSTATE_cmnb = rtb_Divide_b4h;
  measure_DWork.UnitDelay1_DSTATE_cmnb3 = rtb_Divide_nqz;
  measure_DWork.UnitDelay1_DSTATE_cmnb3j = rtb_Switch_jka;
  measure_DWork.UnitDelay_DSTATE_lmdwo30 = rtb_Switch1_fr;
  measure_DWork.UnitDelay1_DSTATE_j = rtb_UnitDelay1_lccp;
  measure_DWork.delay_DSTATE_h = rtb_Any_Phases_Not_Disturbed;
  measure_DWork.UnitDelay_DSTATE_pd = rtb_Switch1_j;
  measure_DWork.UnitDelay_DSTATE_pdo = rtb_LogicalOperator2_npqxol;
  measure_DWork.UnitDelay1_DSTATE_ac = rtb_FixPtSum1_ah;
  measure_DWork.UnitDelay_DSTATE_pdoi = measure_P.Constant_Value_hebrs;
  measure_DWork.UnitDelay1_DSTATE_ac4 = rtb_FixPtSum1_a;
  measure_DWork.UnitDelay3_DSTATE_i5z5 = rtb_TrigonometricFunction_i;
  measure_DWork.UnitDelay3_DSTATE_i5z5o = rtb_TrigonometricFunction_ix;
  measure_DWork.UnitDelay3_DSTATE_i5z5oq = rtb_TrigonometricFunction_ixv;
  measure_DWork.UnitDelay4_DSTATE_edu = measure_B.ACripple1stestimate_n;
  measure_DWork.UnitDelay2_DSTATE_e5yc1 = measure_B.Switch_lli5;
  measure_DWork.UnitDelay4_DSTATE_edua = measure_B.ACripple1stestimate_n;
  measure_DWork.UnitDelay2_DSTATE_e5yc1i = measure_B.Switch_lli5y;
  measure_DWork.UnitDelay1_DSTATE_dg = rtb_IpktoIrms_n;
  measure_DWork.UnitDelay_DSTATE_otr = rtb_UnitDelay1_b;
  measure_DWork.UnitDelay2_DSTATE_e5yc1iho = rtb_LogicalOperator1;
  measure_DWork.UnitDelay_DSTATE_o = (rtb_AbsVI * rtb_Add1_fs_idx_1) +
    rtb_Switch1_l;
  measure_DWork.delay_DSTATE_j0 = !rtb_LogicalOperator2_npqx;
  measure_DWork.delay1_DSTATE_kz = rtb_LogicalOperator2_npqx;
  measure_DWork.UnitDelay_DSTATE_otrxo = measure_P.Constant_Value_hj;
  measure_DWork.UnitDelay2_DSTATE_e5yc1ih = rtb_Switch1_pwrm;
  measure_DWork.UnitDelay1_DSTATE_dgz = rtb_AbsVI;
  measure_DWork.UnitDelay1_DSTATE_dgzm = rtb_Switch1_iew;
  measure_DWork.UnitDelay4_DSTATE_eduao = rtb_Switch1_iew;
  measure_DWork.UnitDelay1_DSTATE_dgzmv = rtb_Sum2_i;
  measure_DWork.UnitDelay1_DSTATE_dgzmvr = rtb_Switch1_ie;
  measure_DWork.UnitDelay1_DSTATE_dgzmvrp = rtb_MathFunction1;
  measure_DWork.UnitDelay_DSTATE_otrx = rtb_Switch1_ia;
}

void measureModelClass::step1()
{
  real_T rtb_ComplextoMagnitudeAngle2_o2;
  real_T rtb_ComplextoMagnitudeAngle2_o1;
  real_T rtb_Product1_mc[4];
  real_T rtb_ComplextoMagnitudeAngle2_ek;
  real_T rtb_ComplextoMagnitudeAngle2__e;
  real_T rtb_Product1_j[4];
  real_T rtb_ComplextoMagnitudeAngle2_jw;
  real_T rtb_ComplextoMagnitudeAngle2__j;
  creal_T rtb_FFT[64];
  creal_T rtb_FFT_n[64];
  creal_T rtb_FFT_o[64];
  real_T rtb_Divide_g_idx;
  real_T rtb_Divide_g_idx_0;
  real_T rtb_Divide_g_idx_1;
  real_T rtb_Divide_g_idx_2;
  MWDSPCG_FFT_Interleave_R2BR_D(&measure_B.RateTransition_a[0], &rtb_FFT[0U], 1,
    64);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT[0U], 1, 64, 32, 0, measure_ConstP.pooled1, 2,
                       FALSE);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT[0U], 1, 64, measure_ConstP.pooled1, 1);
  rtb_ComplextoMagnitudeAngle2_o1 = hypot(rtb_FFT[1].re, rtb_FFT[1].im);
  rtb_ComplextoMagnitudeAngle2_o2 = rt_atan2d_snf(rtb_FFT[1].im, rtb_FFT[1].re);
  rtb_Divide_g_idx_2 = ((rt_atan2d_snf(rtb_FFT[2].im, rtb_FFT[2].re) -
    ((measure_P.Gain3_Gain_o[0] * rtb_ComplextoMagnitudeAngle2_o2) +
     measure_P.Bias1_Bias_ar[0])) + measure_P.Constant1_Value_o) /
    measure_P.Constant2_Value_hr;
  rtb_Divide_g_idx_1 = ((rt_atan2d_snf(rtb_FFT[3].im, rtb_FFT[3].re) -
    ((measure_P.Gain3_Gain_o[1] * rtb_ComplextoMagnitudeAngle2_o2) +
     measure_P.Bias1_Bias_ar[1])) + measure_P.Constant1_Value_o) /
    measure_P.Constant2_Value_hr;
  rtb_Divide_g_idx_0 = ((rt_atan2d_snf(rtb_FFT[4].im, rtb_FFT[4].re) -
    ((measure_P.Gain3_Gain_o[2] * rtb_ComplextoMagnitudeAngle2_o2) +
     measure_P.Bias1_Bias_ar[2])) + measure_P.Constant1_Value_o) /
    measure_P.Constant2_Value_hr;
  rtb_Divide_g_idx = ((rt_atan2d_snf(rtb_FFT[5].im, rtb_FFT[5].re) -
                       ((measure_P.Gain3_Gain_o[3] *
    rtb_ComplextoMagnitudeAngle2_o2) + measure_P.Bias1_Bias_ar[3])) +
                      measure_P.Constant1_Value_o) /
    measure_P.Constant2_Value_hr;
  if (measure_P.Constant6_Value_p) {
    measure_B.Switch2_l[0] = rtb_Divide_g_idx_2 + measure_P.Bias2_Bias_e;
    measure_B.Switch2_l[1] = rtb_Divide_g_idx_1 + measure_P.Bias2_Bias_e;
    measure_B.Switch2_l[2] = rtb_Divide_g_idx_0 + measure_P.Bias2_Bias_e;
    measure_B.Switch2_l[3] = rtb_Divide_g_idx + measure_P.Bias2_Bias_e;
  } else {
    if (rtb_Divide_g_idx_2 < measure_P.Constant_Value_ms) {
      measure_B.Switch2_l[0] = rtb_Divide_g_idx_2 + measure_P.Bias_Bias_l;
    } else {
      measure_B.Switch2_l[0] = rtb_Divide_g_idx_2;
    }

    if (rtb_Divide_g_idx_1 < measure_P.Constant_Value_ms) {
      measure_B.Switch2_l[1] = rtb_Divide_g_idx_1 + measure_P.Bias_Bias_l;
    } else {
      measure_B.Switch2_l[1] = rtb_Divide_g_idx_1;
    }

    if (rtb_Divide_g_idx_0 < measure_P.Constant_Value_ms) {
      measure_B.Switch2_l[2] = rtb_Divide_g_idx_0 + measure_P.Bias_Bias_l;
    } else {
      measure_B.Switch2_l[2] = rtb_Divide_g_idx_0;
    }

    if (rtb_Divide_g_idx < measure_P.Constant_Value_ms) {
      measure_B.Switch2_l[3] = rtb_Divide_g_idx + measure_P.Bias_Bias_l;
    } else {
      measure_B.Switch2_l[3] = rtb_Divide_g_idx;
    }
  }

  measure_B.SFunction2_g[0] = (int32_T)measure_B.Switch2_l[0];
  measure_B.SFunction2_g[1] = (int32_T)measure_B.Switch2_l[1];
  measure_B.SFunction2_g[2] = (int32_T)measure_B.Switch2_l[2];
  measure_B.SFunction2_g[3] = (int32_T)measure_B.Switch2_l[3];
  if (rtb_ComplextoMagnitudeAngle2_o1 < measure_P.Constant_Value_lj) {
    rtb_Divide_g_idx_2 = measure_P.Constant_Value_ko;
  } else {
    rtb_Divide_g_idx_2 = rtb_ComplextoMagnitudeAngle2_o1;
  }

  rtb_Product1_mc[0] = (1.0 / rtb_Divide_g_idx_2) * hypot(rtb_FFT[2].re,
    rtb_FFT[2].im);
  rtb_Product1_mc[1] = (1.0 / rtb_Divide_g_idx_2) * hypot(rtb_FFT[3].re,
    rtb_FFT[3].im);
  rtb_Product1_mc[2] = (1.0 / rtb_Divide_g_idx_2) * hypot(rtb_FFT[4].re,
    rtb_FFT[4].im);
  rtb_Product1_mc[3] = (1.0 / rtb_Divide_g_idx_2) * hypot(rtb_FFT[5].re,
    rtb_FFT[5].im);
  MWDSPCG_FFT_Interleave_R2BR_D(&measure_B.RateTransition_g5[0], &rtb_FFT_n[0U],
    1, 64);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT_n[0U], 1, 64, 32, 0, measure_ConstP.pooled1, 2,
                       FALSE);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT_n[0U], 1, 64, measure_ConstP.pooled1, 1);
  rtb_ComplextoMagnitudeAngle2__e = hypot(rtb_FFT_n[1].re, rtb_FFT_n[1].im);
  rtb_ComplextoMagnitudeAngle2_ek = rt_atan2d_snf(rtb_FFT_n[1].im, rtb_FFT_n[1].
    re);
  rtb_Divide_g_idx_2 = ((rt_atan2d_snf(rtb_FFT_n[2].im, rtb_FFT_n[2].re) -
    ((measure_P.Gain3_Gain_l[0] * rtb_ComplextoMagnitudeAngle2_ek) +
     measure_P.Bias1_Bias_l[0])) + measure_P.Constant1_Value_px) /
    measure_P.Constant2_Value_j;
  rtb_Divide_g_idx_1 = ((rt_atan2d_snf(rtb_FFT_n[3].im, rtb_FFT_n[3].re) -
    ((measure_P.Gain3_Gain_l[1] * rtb_ComplextoMagnitudeAngle2_ek) +
     measure_P.Bias1_Bias_l[1])) + measure_P.Constant1_Value_px) /
    measure_P.Constant2_Value_j;
  rtb_Divide_g_idx_0 = ((rt_atan2d_snf(rtb_FFT_n[4].im, rtb_FFT_n[4].re) -
    ((measure_P.Gain3_Gain_l[2] * rtb_ComplextoMagnitudeAngle2_ek) +
     measure_P.Bias1_Bias_l[2])) + measure_P.Constant1_Value_px) /
    measure_P.Constant2_Value_j;
  rtb_Divide_g_idx = ((rt_atan2d_snf(rtb_FFT_n[5].im, rtb_FFT_n[5].re) -
                       ((measure_P.Gain3_Gain_l[3] *
    rtb_ComplextoMagnitudeAngle2_ek) + measure_P.Bias1_Bias_l[3])) +
                      measure_P.Constant1_Value_px) /
    measure_P.Constant2_Value_j;
  if (measure_P.Constant6_Value_n) {
    measure_B.Switch2_g[0] = rtb_Divide_g_idx_2 + measure_P.Bias2_Bias_g;
    measure_B.Switch2_g[1] = rtb_Divide_g_idx_1 + measure_P.Bias2_Bias_g;
    measure_B.Switch2_g[2] = rtb_Divide_g_idx_0 + measure_P.Bias2_Bias_g;
    measure_B.Switch2_g[3] = rtb_Divide_g_idx + measure_P.Bias2_Bias_g;
  } else {
    if (rtb_Divide_g_idx_2 < measure_P.Constant_Value_br) {
      measure_B.Switch2_g[0] = rtb_Divide_g_idx_2 + measure_P.Bias_Bias_lc;
    } else {
      measure_B.Switch2_g[0] = rtb_Divide_g_idx_2;
    }

    if (rtb_Divide_g_idx_1 < measure_P.Constant_Value_br) {
      measure_B.Switch2_g[1] = rtb_Divide_g_idx_1 + measure_P.Bias_Bias_lc;
    } else {
      measure_B.Switch2_g[1] = rtb_Divide_g_idx_1;
    }

    if (rtb_Divide_g_idx_0 < measure_P.Constant_Value_br) {
      measure_B.Switch2_g[2] = rtb_Divide_g_idx_0 + measure_P.Bias_Bias_lc;
    } else {
      measure_B.Switch2_g[2] = rtb_Divide_g_idx_0;
    }

    if (rtb_Divide_g_idx < measure_P.Constant_Value_br) {
      measure_B.Switch2_g[3] = rtb_Divide_g_idx + measure_P.Bias_Bias_lc;
    } else {
      measure_B.Switch2_g[3] = rtb_Divide_g_idx;
    }
  }

  measure_B.SFunction2_k[0] = (int32_T)measure_B.Switch2_g[0];
  measure_B.SFunction2_k[1] = (int32_T)measure_B.Switch2_g[1];
  measure_B.SFunction2_k[2] = (int32_T)measure_B.Switch2_g[2];
  measure_B.SFunction2_k[3] = (int32_T)measure_B.Switch2_g[3];
  if (rtb_ComplextoMagnitudeAngle2__e < measure_P.Constant_Value_iz) {
    rtb_Divide_g_idx_2 = measure_P.Constant_Value_av;
  } else {
    rtb_Divide_g_idx_2 = rtb_ComplextoMagnitudeAngle2__e;
  }

  rtb_Product1_j[0] = (1.0 / rtb_Divide_g_idx_2) * hypot(rtb_FFT_n[2].re,
    rtb_FFT_n[2].im);
  rtb_Product1_j[1] = (1.0 / rtb_Divide_g_idx_2) * hypot(rtb_FFT_n[3].re,
    rtb_FFT_n[3].im);
  rtb_Product1_j[2] = (1.0 / rtb_Divide_g_idx_2) * hypot(rtb_FFT_n[4].re,
    rtb_FFT_n[4].im);
  rtb_Product1_j[3] = (1.0 / rtb_Divide_g_idx_2) * hypot(rtb_FFT_n[5].re,
    rtb_FFT_n[5].im);
  MWDSPCG_FFT_Interleave_R2BR_D(&measure_B.RateTransition_gx[0], &rtb_FFT_o[0U],
    1, 64);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT_o[0U], 1, 64, 32, 0, measure_ConstP.pooled1, 2,
                       FALSE);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT_o[0U], 1, 64, measure_ConstP.pooled1, 1);
  rtb_ComplextoMagnitudeAngle2__j = hypot(rtb_FFT_o[1].re, rtb_FFT_o[1].im);
  rtb_ComplextoMagnitudeAngle2_jw = rt_atan2d_snf(rtb_FFT_o[1].im, rtb_FFT_o[1].
    re);
  rtb_Divide_g_idx_2 = ((rt_atan2d_snf(rtb_FFT_o[2].im, rtb_FFT_o[2].re) -
    ((measure_P.Gain3_Gain_d[0] * rtb_ComplextoMagnitudeAngle2_jw) +
     measure_P.Bias1_Bias_a4[0])) + measure_P.Constant1_Value_n) /
    measure_P.Constant2_Value_o;
  rtb_Divide_g_idx_1 = ((rt_atan2d_snf(rtb_FFT_o[3].im, rtb_FFT_o[3].re) -
    ((measure_P.Gain3_Gain_d[1] * rtb_ComplextoMagnitudeAngle2_jw) +
     measure_P.Bias1_Bias_a4[1])) + measure_P.Constant1_Value_n) /
    measure_P.Constant2_Value_o;
  rtb_Divide_g_idx_0 = ((rt_atan2d_snf(rtb_FFT_o[4].im, rtb_FFT_o[4].re) -
    ((measure_P.Gain3_Gain_d[2] * rtb_ComplextoMagnitudeAngle2_jw) +
     measure_P.Bias1_Bias_a4[2])) + measure_P.Constant1_Value_n) /
    measure_P.Constant2_Value_o;
  rtb_Divide_g_idx = ((rt_atan2d_snf(rtb_FFT_o[5].im, rtb_FFT_o[5].re) -
                       ((measure_P.Gain3_Gain_d[3] *
    rtb_ComplextoMagnitudeAngle2_jw) + measure_P.Bias1_Bias_a4[3])) +
                      measure_P.Constant1_Value_n) / measure_P.Constant2_Value_o;
  if (measure_P.Constant6_Value_e) {
    measure_B.Switch2_b2[0] = rtb_Divide_g_idx_2 + measure_P.Bias2_Bias_gx;
    measure_B.Switch2_b2[1] = rtb_Divide_g_idx_1 + measure_P.Bias2_Bias_gx;
    measure_B.Switch2_b2[2] = rtb_Divide_g_idx_0 + measure_P.Bias2_Bias_gx;
    measure_B.Switch2_b2[3] = rtb_Divide_g_idx + measure_P.Bias2_Bias_gx;
  } else {
    if (rtb_Divide_g_idx_2 < measure_P.Constant_Value_or0) {
      measure_B.Switch2_b2[0] = rtb_Divide_g_idx_2 + measure_P.Bias_Bias_lz;
    } else {
      measure_B.Switch2_b2[0] = rtb_Divide_g_idx_2;
    }

    if (rtb_Divide_g_idx_1 < measure_P.Constant_Value_or0) {
      measure_B.Switch2_b2[1] = rtb_Divide_g_idx_1 + measure_P.Bias_Bias_lz;
    } else {
      measure_B.Switch2_b2[1] = rtb_Divide_g_idx_1;
    }

    if (rtb_Divide_g_idx_0 < measure_P.Constant_Value_or0) {
      measure_B.Switch2_b2[2] = rtb_Divide_g_idx_0 + measure_P.Bias_Bias_lz;
    } else {
      measure_B.Switch2_b2[2] = rtb_Divide_g_idx_0;
    }

    if (rtb_Divide_g_idx < measure_P.Constant_Value_or0) {
      measure_B.Switch2_b2[3] = rtb_Divide_g_idx + measure_P.Bias_Bias_lz;
    } else {
      measure_B.Switch2_b2[3] = rtb_Divide_g_idx;
    }
  }

  measure_B.SFunction2_n[0] = (int32_T)measure_B.Switch2_b2[0];
  measure_B.SFunction2_n[1] = (int32_T)measure_B.Switch2_b2[1];
  measure_B.SFunction2_n[2] = (int32_T)measure_B.Switch2_b2[2];
  measure_B.SFunction2_n[3] = (int32_T)measure_B.Switch2_b2[3];
  if (rtb_ComplextoMagnitudeAngle2__j < measure_P.Constant_Value_h4) {
    rtb_Divide_g_idx_2 = measure_P.Constant_Value_ht;
  } else {
    rtb_Divide_g_idx_2 = rtb_ComplextoMagnitudeAngle2__j;
  }

  measure_DWork.RateTransition_Buffer0 = rtb_FFT[1];
  measure_DWork.RateTransition_Buffer0_m = rtb_FFT_n[1];
  measure_DWork.RateTransition_Buffer0_p = rtb_FFT_o[1];
  measure_DWork.RateTransition_Buffer0_f = rtb_ComplextoMagnitudeAngle2_o1;
  measure_DWork.RateTransition_Buffer0_n = rtb_ComplextoMagnitudeAngle2__e;
  measure_DWork.RateTransition_Buffer0_c = rtb_ComplextoMagnitudeAngle2__j;
  measure_DWork.RateTransition_Buffer0_nm[0] = rtb_Product1_mc[0];
  measure_DWork.RateTransition_Buffer0_nm[1] = rtb_Product1_mc[1];
  measure_DWork.RateTransition_Buffer0_nm[2] = rtb_Product1_mc[2];
  measure_DWork.RateTransition_Buffer0_nm[3] = rtb_Product1_mc[3];
  measure_DWork.RateTransition_Buffer0_d[0] = rtb_Product1_j[0];
  measure_DWork.RateTransition_Buffer0_d[1] = rtb_Product1_j[1];
  measure_DWork.RateTransition_Buffer0_d[2] = rtb_Product1_j[2];
  measure_DWork.RateTransition_Buffer0_d[3] = rtb_Product1_j[3];
  measure_DWork.RateTransition_Buffer0_j[0] = (1.0 / rtb_Divide_g_idx_2) * hypot
    (rtb_FFT_o[2].re, rtb_FFT_o[2].im);
  measure_DWork.RateTransition_Buffer0_j[1] = (1.0 / rtb_Divide_g_idx_2) * hypot
    (rtb_FFT_o[3].re, rtb_FFT_o[3].im);
  measure_DWork.RateTransition_Buffer0_j[2] = (1.0 / rtb_Divide_g_idx_2) * hypot
    (rtb_FFT_o[4].re, rtb_FFT_o[4].im);
  measure_DWork.RateTransition_Buffer0_j[3] = (1.0 / rtb_Divide_g_idx_2) * hypot
    (rtb_FFT_o[5].re, rtb_FFT_o[5].im);
  measure_DWork.RateTransition_Buffer0_h = rtb_ComplextoMagnitudeAngle2_o2;
  measure_DWork.RateTransition_Buffer0_po = rtb_ComplextoMagnitudeAngle2_ek;
  measure_DWork.RateTransition_Buffer0_e = rtb_ComplextoMagnitudeAngle2_jw;
}

void measureModelClass::initialize()
{
  rt_InitInfAndNaN(sizeof(real_T));
  (void) memset((void *)measure_M, 0,
                sizeof(RT_MODEL_measure));
  (void) memset(((void *) &measure_B), 0,
                sizeof(BlockIO_measure));
  (void) memset((void *)&measure_DWork, 0,
                sizeof(D_Work_measure));
  (void) memset((void *)&measure_U, 0,
                sizeof(ExternalInputs_measure));
  (void) memset((void *)&measure_Y, 0,
                sizeof(ExternalOutputs_measure));

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.SF_FixedDiscreteDelaySfunctio_j[0];
    int_T i;
    for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfunctio_n; i++)
      *(VDD_buffer++) = measure_P.SF_FixedDiscreteDelaySfunction_;
    measure_DWork.SF_FixedDiscreteDelaySfunction_ =
      measure_P.SF_FixedDiscreteDelaySfunction_;
    measure_DWork.SF_FixedDiscreteDelaySfuncti_n5 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.SF_FixedDiscreteDelaySfuncti_bt[0];
    int_T i;
    for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfuncti_jc; i++)
      *(VDD_buffer++) = measure_P.SF_FixedDiscreteDelaySfunctio_j;
    measure_DWork.SF_FixedDiscreteDelaySfunctio_b =
      measure_P.SF_FixedDiscreteDelaySfunctio_j;
    measure_DWork.SF_FixedDiscreteDelaySfunctio_c = 0;
  }

  measure_DWork.clockTickCounter = 0;
  measure_DWork.clockTickCounter_g = 0;

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTap[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTap+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOneT_h = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneT_b[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_j+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOne_h3 = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoTap[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTap+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTwoT_j = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_b4[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_jc+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOn_h3s = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_b4n[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_jcf+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithO_h3se = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_m[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_j+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTwo_jn = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithO_b4np[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_jcfa+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywith_h3see = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywith_b4npp[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_jcfaw+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywit_h3seeh = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_mf[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_jc+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTw_jng = 0;
  }

  measure_DWork.clockTickCounter_ge = 0;

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywit_b4npph[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_jcfawy+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywi_h3seeh3 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywi_b4npphe[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_jcfawyw+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelayw_h3seeh3o = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_mf5[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_jcf+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithT_jngr = 0;
  }

  measure_DWork.clockTickCounter_i = 0;

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneT_j[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_d+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOneT_o = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_je[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_ds+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOne_ob = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_p[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_d+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTwoT_a = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_jel[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_dsc+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOn_obu = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithO_jelr[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_dsc5+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithO_obui = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_p3[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_ds+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTwo_as = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywith_jelr5[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_d1+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywith_obui2 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywit_jelr5a[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_d1m+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywit_obui2s = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_p3o[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_d1+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTw_asr = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywi_jelr5az[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_d1m1+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywi_obui2sv = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelayw_jelr5azs[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_d1m1h+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelayw_obui2svt = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_p3ok[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_d1m+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithT_asrw = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelay_jelr5azsa[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_m+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelay_obui2svtg = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDela_jelr5azsa0[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_m0+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDela_obui2svtgp = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_p3ok0[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_m+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywith_asrwd = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDel_jelr5azsa0t[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_m04+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDel_obui2svtgpu = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDe_jelr5azsa0te[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_m041+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDe_obui2svtgpup = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_p3ok0i[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_m0+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywit_asrwdn = 0;
  }

  measure_DWork.clockTickCounter_io = 0;
  measure_DWork.clockTickCounter_iom = 0;

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteD_jelr5azsa0tej[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_dsc5t+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteD_obui2svtgpupg = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscrete_jelr5azsa0tejd[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_dsc5tt+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscrete_obui2svtgpupg2 = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_p3ok0il[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_dsc+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywi_asrwdnf = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscret_jelr5azsa0tejde[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_dsc5ttd+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_obui2svtgpupg2k = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_p[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_dsc5ttdh+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_fy = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_p3ok0ilk[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_dsc5+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelayw_asrwdnf2 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_l[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_mz+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_ja = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_e[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_mzl+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_fd = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_p3ok0ilkv[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_mz+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelay_asrwdnf25 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.SF_FixedDiscreteDelaySfuncti_j0[0];
    int_T i;
    for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfuncti_fc; i++)
      *(VDD_buffer++) = measure_P.SF_FixedDiscreteDelaySfunctio_f;
    measure_DWork.SF_FixedDiscreteDelaySfunctio_n =
      measure_P.SF_FixedDiscreteDelaySfunctio_f;
    measure_DWork.SF_FixedDiscreteDelaySfunct_n5w = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_c[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_d1m1hi+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_ng = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_k[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_d1m1hiq+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_gm = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_p3ok0ilkvg[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_d1m1+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDela_asrwdnf25g = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_i[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_d1m1hiqr+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_lb = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_p0[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_d1m1hiqru+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_jso = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_p3ok0ilkvgc[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_d1m1hiqruq+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDel_asrwdnf25g3 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_a[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_o+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_fl = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_m[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_on+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_ney = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_p3ok0ilkvgcl[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_o+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDe_asrwdnf25g35 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ci[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_m0413+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_hc = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_f[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_m0413r+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_gn = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_p3ok0ilkvgclo[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_m04+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteD_asrwdnf25g35f = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_g[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_m0413rf+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_ne3 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_l2[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_m0413rfk+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_it = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_p3ok0ilkvgclom[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_m041+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscrete_asrwdnf25g35fl = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ii[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_a+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_jh = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_id[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_ao+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_bv = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_p3ok0ilkvgclom3[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_a+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_asrwdnf25g35flg = 0;
  }

  measure_DWork.clockTickCounter_h = 0;

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_px[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_mq+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_iq = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_b[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_mqc+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_ec = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a3[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_mq+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_fz = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_h[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_dsc5ttdhq+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_kd = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_bo[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_dsc5ttdhqk+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_ky = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_o[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_dsc5ttdhqkx+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_cc = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_im[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_dsc5ttdhqkxi+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_fn = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_hs[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_dsc5ttdhqkxiz+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_cn = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pe[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_dsc5ttdhqkxizv+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_k3 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_n[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_d1m1hiqruqx+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_h1 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_d[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_d1m1hiqruqxi+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_iw = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_j[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_d1m1hiqruqxix+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_am = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_em[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_d1m1hiqruqxix0+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_jq = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_iz[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_d1m1hiqruqxix0v+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_aa = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_js[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_o+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_kz = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ih[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_m0413rfkr+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_db = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ej[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_m0413rfkrd+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_py = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_li[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_m0413rfkrd2+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_et = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_gs[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_m0413rfkrd2o+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_lbx = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ne[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_m0413rfkrd2oa+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_b1 = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_pg[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_m0413rfkrd2oak+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_bu = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneT_f[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_e+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOneT_l = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_fx[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_e1+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOne_ln = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_c[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_e+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTwo_mt = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_fxf[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOn_e1r+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOn_lnk = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithO_fxfz[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_e1ro+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithO_lnk1 = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_cb[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_e1+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTw_mt3 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywith_fxfzv[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_e1ror+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywith_lnk1v = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywit_fxfzvg[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywit_e1rorg+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywit_lnk1vh = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_cb3[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_e1r+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithT_mt3m = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywi_fxfzvgo[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywi_e1rorg3+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywi_lnk1vhz = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelayw_fxfzvgoh[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_e1rorg3e+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelayw_lnk1vhza = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_cb3y[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_e1ro+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywith_mt3my = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelay_fxfzvgohd[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_e1rorg3e1+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelay_lnk1vhzad = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDela_fxfzvgohdy[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDela_e1rorg3e1h+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDela_lnk1vhzad0 = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywith_cb3yn[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDel_e1rorg3e1hu+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywit_mt3myh = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDel_fxfzvgohdyf[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDe_e1rorg3e1hup+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDel_lnk1vhzad0h = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDe_fxfzvgohdyfs[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteD_e1rorg3e1hupm+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDe_lnk1vhzad0hw = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywit_cb3ynu[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscrete_e1rorg3e1hupmn+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywi_mt3myh1 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteD_fxfzvgohdyfso[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_e1rorg3e1hupmn0+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteD_lnk1vhzad0hw1 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscrete_fxfzvgohdyfsol[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_c+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscrete_lnk1vhzad0hw1b = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywi_cb3ynuk[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_h+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelayw_mt3myh1u = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscret_fxfzvgohdyfsolg[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_hm+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_lnk1vhzad0hw1bl = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ab[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_om+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_ed = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelayw_cb3ynukf[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_omi+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelay_mt3myh1uz = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_je[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_k+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_de = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_no[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_b+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_cw = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelay_cb3ynukfc[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_kz+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDela_mt3myh1uz5 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ni[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_cj+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_ln = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_b3[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_d+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_ch = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDela_cb3ynukfcn[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_bx+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDel_mt3myh1uz53 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_i0[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_l+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_eh = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_d5[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ly+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_hw = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDel_cb3ynukfcns[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_cjg+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDe_mt3myh1uz53e = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_nk[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_f+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_k3l = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_le[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_hs+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_kx = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDe_cb3ynukfcns4[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_di+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteD_mt3myh1uz53er = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_pl[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_m+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_pgc = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_e5[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_c1+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_aa5 = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteD_cb3ynukfcns4k[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_li+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscrete_mt3myh1uz53erg = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_dx[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_a+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_hy = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_kt[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_p+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_pt = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscrete_cb3ynukfcns4km[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_lyi+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_mt3myh1uz53ergf = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_l5[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_hu+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_pf = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_bz[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_bg+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_bm = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_cb3ynukfcns4kmg[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_fu+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_dxq = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_ac[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ob+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_mb = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_hz[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_g+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_b5 = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_a1[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_hsu+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_k5 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_i1[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_n+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_nj = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_on[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_e+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_cg = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_gx[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ma+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_pfv = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_kw[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_ks+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_abz = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_gc[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_pd+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_ar = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_ig[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscret_c1z+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_boa = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneT_e[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_ae+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOneT_k = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_ec[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_c+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOne_kj = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_pp[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_l+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTwo_ah = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_fi[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_i+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOne_op = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_fie[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_l+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOn_opo = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_k[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_k+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTwo_ju = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_ep[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_l4+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOn_obd = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_epo[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_n+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithO_obdq = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTw_mfe[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_mv+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTwoT_f = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_bb[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_p+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOne_of = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_bbn[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_di+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOn_of2 = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwoT_o[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_jx+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTwoT_g = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_bm[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_c3+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOne_jp = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOn_bmy[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneT_h+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOn_jpu = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_mw[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoT_c+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTwoT_h = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneT_g[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_nc+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOne_fn = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOne_g5[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithOne_o0+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithOn_fny = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithTwo_of[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwo_d5+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywithTw_as5 = 0;
  }

  measure_B.RateTransition.re = measure_P.RateTransition_X0;
  measure_B.RateTransition.im = 0.0;
  measure_B.RateTransition_f.re = measure_P.RateTransition_X0_h;
  measure_B.RateTransition_f.im = 0.0;
  measure_B.RateTransition_b.re = measure_P.RateTransition_X0_m;
  measure_B.RateTransition_b.im = 0.0;
  measure_B.RateTransition_c = measure_P.RateTransition_X0_d;
  measure_B.RateTransition_m = measure_P.RateTransition_X0_mf;
  measure_B.RateTransition_g = measure_P.RateTransition_X0_mn;
  measure_B.RateTransition_j[0] = measure_P.RateTransition_X0_mk;
  measure_B.RateTransition_j[1] = measure_P.RateTransition_X0_mk;
  measure_B.RateTransition_j[2] = measure_P.RateTransition_X0_mk;
  measure_B.RateTransition_j[3] = measure_P.RateTransition_X0_mk;
  measure_B.RateTransition_p[0] = measure_P.RateTransition_X0_l;
  measure_B.RateTransition_p[1] = measure_P.RateTransition_X0_l;
  measure_B.RateTransition_p[2] = measure_P.RateTransition_X0_l;
  measure_B.RateTransition_p[3] = measure_P.RateTransition_X0_l;
  measure_B.RateTransition_e[0] = measure_P.RateTransition_X0_n;
  measure_B.RateTransition_e[1] = measure_P.RateTransition_X0_n;
  measure_B.RateTransition_e[2] = measure_P.RateTransition_X0_n;
  measure_B.RateTransition_e[3] = measure_P.RateTransition_X0_n;

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelayw_b4npphe4[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelayw_jcfawyw2+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelay_h3seeh3od = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelay_b4npphe4j[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelay_jcfawyw2o+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDela_h3seeh3odr = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscreteDelaywithT_mf50[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithT_jcfa+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscreteDelaywith_jngrs = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_jp[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithO_mqco+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_jb = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)&measure_DWork.VariableDiscret_hh[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywith_mqco2+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_hm = 0;
  }

  {
    real_T *VDD_buffer = &measure_DWork.VariableDiscret_mj[0];
    int_T i;
    for (i = 0; i < (measure_P.VariableDiscreteDelaywithTw_mqc+1); i++)
      *(VDD_buffer++) = 0.0;
    measure_DWork.VariableDiscret_gnb = 0;
  }

  {
    measure_DWork.SFunction_RWORK[0] = 0.0;
    measure_DWork.SFunction_RWORK[1] = 0.0;
    measure_DWork.SFunction_RWORK[2] = 0.0;
    measure_DWork.SFunction_RWORK[3] = 0.0;
    measure_DWork.SFunction_IWORK = -1;
  }

  measure_B.RateTransition_l = measure_P.RateTransition_X0_la;

  {
    measure_DWork.SFunction_RWORK_m[0] = 0.0;
    measure_DWork.SFunction_RWORK_m[1] = 0.0;
    measure_DWork.SFunction_RWORK_m[2] = 0.0;
    measure_DWork.SFunction_RWORK_m[3] = 0.0;
    measure_DWork.SFunction_IWORK_d = -1;
  }

  measure_B.RateTransition_k = measure_P.RateTransition_X0_i;

  {
    measure_DWork.SFunction_RWORK_o[0] = 0.0;
    measure_DWork.SFunction_RWORK_o[1] = 0.0;
    measure_DWork.SFunction_RWORK_o[2] = 0.0;
    measure_DWork.SFunction_RWORK_o[3] = 0.0;
    measure_DWork.SFunction_IWORK_a = -1;
  }

  measure_B.RateTransition_j2 = measure_P.RateTransition_X0_d5;
  measure_DWork.UnitDelay4_DSTATE_ir = measure_P.UnitDelay4_X0_he;
  measure_DWork.delay_DSTATE = measure_P.delay_X0;
  measure_DWork.UnitDelay_DSTATE = measure_P.UnitDelay_X0;
  measure_DWork.UnitDelay4_DSTATE_czl44j1ipa1 =
    measure_P.UnitDelay4_X0_jcfawyw2o0o;
  measure_DWork.delay_DSTATE_i = measure_P.delay_X0_j;
  measure_DWork.UnitDelay_DSTATE_l = measure_P.UnitDelay_X0_j;
  measure_DWork.UnitDelay_DSTATE_lm = measure_P.UnitDelay_X0_jc;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j45 =
    measure_P.UnitDelay2_X0_jcfawyw2o0osk;
  measure_DWork.delay1_DSTATE = measure_P.delay1_X0;
  measure_DWork.delay1_DSTATE_c = measure_P.delay1_X0_j;
  measure_DWork.UnitDelay3_DSTATE = measure_P.UnitDelay3_X0;
  measure_DWork.UnitDelay1_DSTATE = measure_P.UnitDelay1_X0;
  measure_DWork.UnitDelay2_DSTATE = measure_P.UnitDelay2_X0;
  measure_DWork.UnitDelay1_DSTATE_o = measure_P.UnitDelay1_X0_a;
  measure_DWork.UnitDelay2_DSTATE_k = measure_P.UnitDelay2_X0_c;
  measure_DWork.UnitDelay1_DSTATE_g = measure_P.UnitDelay1_X0_m;
  measure_DWork.UnitDelay2_DSTATE_e = measure_P.UnitDelay2_X0_e;
  measure_DWork.UnitDelay4_DSTATE = measure_P.UnitDelay4_X0;
  measure_DWork.UnitDelay2_DSTATE_h = measure_P.UnitDelay2_X0_j;
  measure_DWork.delay_DSTATE_i2 = measure_P.delay_X0_jc;
  measure_DWork.UnitDelay4_DSTATE_c = measure_P.UnitDelay4_X0_j;
  measure_DWork.UnitDelay2_DSTATE_h5 = measure_P.UnitDelay2_X0_jc;
  measure_DWork.UnitDelay4_DSTATE_cz = measure_P.UnitDelay4_X0_jc;
  measure_DWork.UnitDelay2_DSTATE_h5b = measure_P.UnitDelay2_X0_jcf;
  measure_DWork.delay_DSTATE_i2w = measure_P.delay_X0_jcf;
  measure_DWork.UnitDelay4_DSTATE_czl = measure_P.UnitDelay4_X0_jcf;
  measure_DWork.UnitDelay2_DSTATE_h5br = measure_P.UnitDelay2_X0_jcfa;
  measure_DWork.UnitDelay4_DSTATE_czl4 = measure_P.UnitDelay4_X0_jcfa;
  measure_DWork.UnitDelay2_DSTATE_h5brd = measure_P.UnitDelay2_X0_jcfaw;
  measure_DWork.UnitDelay4_DSTATE_czl44 = measure_P.UnitDelay4_X0_jcfaw;
  measure_DWork.UnitDelay2_DSTATE_h5brdq = measure_P.UnitDelay2_X0_jcfawy;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jx = measure_P.UnitDelay1_X0_jcfawyw;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxq = measure_P.UnitDelay1_X0_jcfawyw2;
  measure_DWork.delay1_DSTATE_ce = measure_P.delay1_X0_jc;
  measure_DWork.UnitDelay4_DSTATE_czl44j = measure_P.UnitDelay4_X0_jcfawy;
  measure_DWork.UnitDelay2_DSTATE_h5brdqc = measure_P.UnitDelay2_X0_jcfawyw;
  measure_DWork.UnitDelay2_DSTATE_h5brdqci = measure_P.UnitDelay2_X0_jcfawyw2;
  measure_DWork.delay_DSTATE_i2wj = measure_P.delay_X0_jcfa;
  measure_DWork.UnitDelay4_DSTATE_czl44j1 = measure_P.UnitDelay4_X0_jcfawyw;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz = measure_P.UnitDelay2_X0_jcfawyw2o;
  measure_DWork.UnitDelay_DSTATE_lmdw = measure_P.UnitDelay_X0_jcfa;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqh = measure_P.UnitDelay1_X0_jcfawyw2o;
  measure_DWork.UnitDelay1_DSTATE_k = measure_P.UnitDelay1_X0_h;
  measure_DWork.UnitDelay2_DSTATE_kg = measure_P.UnitDelay2_X0_m;
  measure_DWork.UnitDelay4_DSTATE_h = measure_P.UnitDelay4_X0_ll;
  measure_DWork.UnitDelay1_DSTATE_aqjz = measure_P.UnitDelay1_X0_o;
  measure_DWork.delay1_DSTATE_d = measure_P.delay1_X0_e;
  measure_DWork.UnitDelay_DSTATE_p = measure_P.UnitDelay_X0_e;
  measure_DWork.UnitDelay4_DSTATE_j = measure_P.UnitDelay4_X0_d;
  measure_DWork.UnitDelay2_DSTATE_g = measure_P.UnitDelay2_X0_d;
  measure_DWork.delay_DSTATE_iz = measure_P.delay_X0_e;
  measure_DWork.UnitDelay4_DSTATE_jb = measure_P.UnitDelay4_X0_ds;
  measure_DWork.UnitDelay2_DSTATE_gb = measure_P.UnitDelay2_X0_ds;
  measure_DWork.UnitDelay4_DSTATE_jbk = measure_P.UnitDelay4_X0_dsc;
  measure_DWork.UnitDelay2_DSTATE_gbj = measure_P.UnitDelay2_X0_dsc;
  measure_DWork.UnitDelay4_DSTATE_jbkw = measure_P.UnitDelay4_X0_dsc5;
  measure_DWork.UnitDelay2_DSTATE_gbjg = measure_P.UnitDelay2_X0_dsc5;
  measure_DWork.UnitDelay1_DSTATE_aqjzx = measure_P.UnitDelay1_X0_k;
  measure_DWork.UnitDelay4_DSTATE_jbkwm = measure_P.UnitDelay4_X0_d1;
  measure_DWork.UnitDelay2_DSTATE_gbjgk = measure_P.UnitDelay2_X0_d1;
  measure_DWork.UnitDelay4_DSTATE_jbkwms = measure_P.UnitDelay4_X0_d1m;
  measure_DWork.UnitDelay2_DSTATE_gbjgk5 = measure_P.UnitDelay2_X0_d1m;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq = measure_P.UnitDelay4_X0_d1m1;
  measure_DWork.UnitDelay2_DSTATE_gbjgk5q = measure_P.UnitDelay2_X0_d1m1;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2 = measure_P.UnitDelay4_X0_d1m1h;
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qb = measure_P.UnitDelay2_X0_d1m1h;
  measure_DWork.UnitDelay1_DSTATE_aqjzxp = measure_P.UnitDelay1_X0_ok;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2k = measure_P.UnitDelay4_X0_m;
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx = measure_P.UnitDelay2_X0_m0;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv = measure_P.UnitDelay4_X0_m0;
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx3 = measure_P.UnitDelay2_X0_m04;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2 = measure_P.UnitDelay4_X0_m04;
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35 = measure_P.UnitDelay2_X0_m041;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s = measure_P.UnitDelay4_X0_m041;
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35b = measure_P.UnitDelay2_X0_m0413;
  measure_DWork.delay1_DSTATE_dt = measure_P.delay1_X0_ep;
  measure_DWork.UnitDelay3_DSTATE_i = measure_P.UnitDelay3_X0_a;
  measure_DWork.delay1_DSTATE_dtd = measure_P.delay1_X0_ep3;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s4 = measure_P.UnitDelay4_X0_dsc5t;
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35bv = measure_P.UnitDelay2_X0_dsc5t;
  measure_DWork.delay_DSTATE_izx = measure_P.delay_X0_ep;
  measure_DWork.UnitDelay4_DSTAT_jbkwmsq2kv2s4v = measure_P.UnitDelay4_X0_dsc5tt;
  measure_DWork.UnitDelay2_DSTAT_gbjgk5qbx35bvz = measure_P.UnitDelay2_X0_dsc5tt;
  measure_DWork.UnitDelay4_DSTA_jbkwmsq2kv2s4vv =
    measure_P.UnitDelay4_X0_dsc5ttd;
  measure_DWork.UnitDelay2_DSTA_gbjgk5qbx35bvzo =
    measure_P.UnitDelay2_X0_dsc5ttd;
  measure_DWork.UnitDelay4_DSTA_g = measure_P.UnitDelay4_X0_dsc5ttdh;
  measure_DWork.UnitDelay2_DSTA_i = measure_P.UnitDelay2_X0_dsc5ttdh;
  measure_DWork.UnitDelay4_DSTA_n = measure_P.UnitDelay4_X0_mz;
  measure_DWork.UnitDelay2_DSTA_a = measure_P.UnitDelay2_X0_mz;
  measure_DWork.delay_DSTATE_izxx = measure_P.delay_X0_ep3;
  measure_DWork.UnitDelay4_DSTA_d = measure_P.UnitDelay4_X0_mzl;
  measure_DWork.UnitDelay2_DSTA_ai = measure_P.UnitDelay2_X0_mzl;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpn = measure_P.UnitDelay1_X0_od;
  measure_DWork.UnitDelay_DSTATE_mj2f = measure_P.UnitDelay_X0_k;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnn = measure_P.UnitDelay1_X0_ki;
  measure_DWork.UnitDelay_DSTATE_m = measure_P.UnitDelay_X0_p;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno = measure_P.UnitDelay1_X0_kix;
  measure_DWork.UnitDelay1_DSTATE_a = measure_P.UnitDelay1_X0_d;
  measure_DWork.UnitDelay_DSTATE_i = measure_P.UnitDelay_X0_f;
  measure_DWork.UnitDelay1_DSTATE_aq = measure_P.UnitDelay1_X0_d1;
  measure_DWork.UnitDelay_DSTATE_ia = measure_P.UnitDelay_X0_fc;
  measure_DWork.UnitDelay1_DSTATE_aqj = measure_P.UnitDelay1_X0_m0;
  measure_DWork.UnitDelay_DSTATE_iah = measure_P.UnitDelay_X0_fcb;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4 = measure_P.UnitDelay1_X0_kc;
  measure_DWork.UnitDelay_DSTATE_mj2fm = measure_P.UnitDelay_X0_ma;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4m = measure_P.UnitDelay1_X0_ma;
  measure_DWork.UnitDelay_DSTATE_mj = measure_P.UnitDelay_X0_o;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml = measure_P.UnitDelay1_X0_maw;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml3 = measure_P.UnitDelay1_X0_okw;
  measure_DWork.UnitDelay_DSTATE_mj2fmb = measure_P.UnitDelay_X0_my;
  measure_DWork.UnitDelay1_DSTAT_aqjzxpnno4ml3e = measure_P.UnitDelay1_X0_my;
  measure_DWork.UnitDelay_DSTATE_mj2 = measure_P.UnitDelay_X0_jn;
  measure_DWork.UnitDelay1_DSTA_aqjzxpnno4ml3e2 = measure_P.UnitDelay1_X0_my5;
  measure_DWork.UnitDelay3_DSTATE_i5 = measure_P.UnitDelay3_X0_i;
  measure_DWork.UnitDelay4_DSTA_i = measure_P.UnitDelay4_X0_d1m1hi;
  measure_DWork.UnitDelay2_DSTA_m = measure_P.UnitDelay2_X0_d1m1hi;
  measure_DWork.UnitDelay4_DSTA_n3 = measure_P.UnitDelay4_X0_d1m1hiq;
  measure_DWork.UnitDelay2_DSTA_il = measure_P.UnitDelay2_X0_d1m1hiq;
  measure_DWork.UnitDelay4_DSTA_a = measure_P.UnitDelay4_X0_d1m1hiqr;
  measure_DWork.UnitDelay2_DSTA_b = measure_P.UnitDelay2_X0_d1m1hiqr;
  measure_DWork.UnitDelay4_DSTA_j = measure_P.UnitDelay4_X0_d1m1hiqru;
  measure_DWork.UnitDelay2_DSTA_h = measure_P.UnitDelay2_X0_d1m1hiqru;
  measure_DWork.UnitDelay4_DSTA_p = measure_P.UnitDelay4_X0_o;
  measure_DWork.UnitDelay2_DSTA_o = measure_P.UnitDelay2_X0_o;
  measure_DWork.UnitDelay4_DSTA_jg = measure_P.UnitDelay4_X0_on;
  measure_DWork.UnitDelay2_DSTA_f = measure_P.UnitDelay2_X0_on;
  measure_DWork.UnitDelay3_DSTATE_i5z = measure_P.UnitDelay3_X0_o;
  measure_DWork.UnitDelay4_DSTA_ih = measure_P.UnitDelay4_X0_m0413;
  measure_DWork.UnitDelay2_DSTA_j = measure_P.UnitDelay2_X0_m0413r;
  measure_DWork.UnitDelay4_DSTA_m = measure_P.UnitDelay4_X0_m0413r;
  measure_DWork.UnitDelay2_DSTA_jm = measure_P.UnitDelay2_X0_m0413rf;
  measure_DWork.UnitDelay4_DSTA_j5 = measure_P.UnitDelay4_X0_m0413rf;
  measure_DWork.UnitDelay2_DSTA_c = measure_P.UnitDelay2_X0_m0413rfk;
  measure_DWork.UnitDelay4_DSTA_dj = measure_P.UnitDelay4_X0_m0413rfk;
  measure_DWork.UnitDelay2_DSTA_cm = measure_P.UnitDelay2_X0_m0413rfkr;
  measure_DWork.UnitDelay4_DSTA_l = measure_P.UnitDelay4_X0_a;
  measure_DWork.UnitDelay2_DSTA_p = measure_P.UnitDelay2_X0_a;
  measure_DWork.UnitDelay4_DSTA_h = measure_P.UnitDelay4_X0_ao;
  measure_DWork.UnitDelay2_DSTA_bf = measure_P.UnitDelay2_X0_ao;
  measure_DWork.delay1_DSTATE_k = measure_P.delay1_X0_m;
  measure_DWork.UnitDelay4_DSTATE_e = measure_P.UnitDelay4_X0_mq;
  measure_DWork.UnitDelay2_DSTATE_e5 = measure_P.UnitDelay2_X0_mq;
  measure_DWork.UnitDelay2_DSTATE_e5y = measure_P.UnitDelay2_X0_mqc;
  measure_DWork.delay_DSTATE_j = measure_P.delay_X0_m;
  measure_DWork.UnitDelay4_DSTATE_ed = measure_P.UnitDelay4_X0_mqc;
  measure_DWork.UnitDelay2_DSTATE_e5yc = measure_P.UnitDelay2_X0_mqco;
  measure_DWork.UnitDelay_DSTATE_ot = measure_P.UnitDelay_X0_mq;
  measure_DWork.UnitDelay_DSTATE_k = measure_P.UnitDelay_X0_h;
  measure_DWork.delay1_DSTATE_b = measure_P.delay1_X0_h;
  measure_DWork.UnitDelay1_DSTATE_k2 = measure_P.UnitDelay1_X0_hu;
  measure_DWork.UnitDelay4_DSTA_mm = measure_P.UnitDelay4_X0_dsc5ttdhq;
  measure_DWork.UnitDelay2_DSTA_hi = measure_P.UnitDelay2_X0_dsc5ttdhq;
  measure_DWork.UnitDelay4_DSTA_pb = measure_P.UnitDelay4_X0_dsc5ttdhqk;
  measure_DWork.UnitDelay2_DSTA_iy = measure_P.UnitDelay2_X0_dsc5ttdhqk;
  measure_DWork.UnitDelay4_DSTA_md = measure_P.UnitDelay4_X0_dsc5ttdhqkx;
  measure_DWork.UnitDelay2_DSTA_c0 = measure_P.UnitDelay2_X0_dsc5ttdhqkx;
  measure_DWork.UnitDelay4_DSTA_f = measure_P.UnitDelay4_X0_dsc5ttdhqkxi;
  measure_DWork.UnitDelay2_DSTA_cq = measure_P.UnitDelay2_X0_dsc5ttdhqkxi;
  measure_DWork.UnitDelay4_DSTA_ps = measure_P.UnitDelay4_X0_d1m1hiqruq;
  measure_DWork.UnitDelay2_DSTA_d = measure_P.UnitDelay2_X0_d1m1hiqruq;
  measure_DWork.UnitDelay4_DSTA_k = measure_P.UnitDelay4_X0_d1m1hiqruqx;
  measure_DWork.UnitDelay2_DSTA_o3 = measure_P.UnitDelay2_X0_d1m1hiqruqx;
  measure_DWork.UnitDelay4_DSTA_mw = measure_P.UnitDelay4_X0_d1m1hiqruqxi;
  measure_DWork.UnitDelay2_DSTA_d1 = measure_P.UnitDelay2_X0_d1m1hiqruqxi;
  measure_DWork.UnitDelay4_DSTA_jz = measure_P.UnitDelay4_X0_d1m1hiqruqxix;
  measure_DWork.UnitDelay2_DSTA_l = measure_P.UnitDelay2_X0_d1m1hiqruqxix;
  measure_DWork.UnitDelay4_DSTA_hx = measure_P.UnitDelay4_X0_m0413rfkr;
  measure_DWork.UnitDelay2_DSTA_k = measure_P.UnitDelay2_X0_m0413rfkrd;
  measure_DWork.UnitDelay4_DSTA_p4 = measure_P.UnitDelay4_X0_m0413rfkrd;
  measure_DWork.UnitDelay2_DSTA_lz = measure_P.UnitDelay2_X0_m0413rfkrd2;
  measure_DWork.UnitDelay4_DSTA_b = measure_P.UnitDelay4_X0_m0413rfkrd2;
  measure_DWork.UnitDelay2_DSTA_ls = measure_P.UnitDelay2_X0_m0413rfkrd2o;
  measure_DWork.UnitDelay4_DSTA_ay = measure_P.UnitDelay4_X0_m0413rfkrd2o;
  measure_DWork.UnitDelay2_DSTA_a3 = measure_P.UnitDelay2_X0_m0413rfkrd2oa;
  measure_DWork.UnitDelay1_DSTATE_f = measure_P.UnitDelay1_X0_f;
  measure_DWork.UnitDelay2_DSTATE_m = measure_P.UnitDelay2_X0_mu;
  measure_DWork.UnitDelay4_DSTATE_d = measure_P.UnitDelay4_X0_e;
  measure_DWork.UnitDelay2_DSTATE_kx = measure_P.UnitDelay2_X0_e1;
  measure_DWork.UnitDelay4_DSTATE_do = measure_P.UnitDelay4_X0_e1;
  measure_DWork.UnitDelay2_DSTATE_kxh = measure_P.UnitDelay2_X0_e1r;
  measure_DWork.UnitDelay4_DSTATE_dot = measure_P.UnitDelay4_X0_e1r;
  measure_DWork.UnitDelay2_DSTATE_kxh1 = measure_P.UnitDelay2_X0_e1ro;
  measure_DWork.UnitDelay4_DSTATE_dotl = measure_P.UnitDelay4_X0_e1ro;
  measure_DWork.UnitDelay2_DSTATE_kxh1d = measure_P.UnitDelay2_X0_e1ror;
  measure_DWork.UnitDelay4_DSTATE_dotln = measure_P.UnitDelay4_X0_e1ror;
  measure_DWork.UnitDelay2_DSTATE_kxh1dd = measure_P.UnitDelay2_X0_e1rorg;
  measure_DWork.UnitDelay4_DSTATE_dotlnl = measure_P.UnitDelay4_X0_e1rorg;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb = measure_P.UnitDelay2_X0_e1rorg3;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp = measure_P.UnitDelay4_X0_e1rorg3;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb3 = measure_P.UnitDelay2_X0_e1rorg3e;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0 = measure_P.UnitDelay4_X0_e1rorg3e;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33 = measure_P.UnitDelay2_X0_e1rorg3e1;
  measure_DWork.UnitDelay1_DSTATE_d = measure_P.UnitDelay1_X0_az;
  measure_DWork.UnitDelay2_DSTATE_d = measure_P.UnitDelay2_X0_n;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0w = measure_P.UnitDelay4_X0_e1rorg3e1;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33g =
    measure_P.UnitDelay2_X0_e1rorg3e1h;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wv =
    measure_P.UnitDelay4_X0_e1rorg3e1h;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gq =
    measure_P.UnitDelay2_X0_e1rorg3e1hu;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvp =
    measure_P.UnitDelay4_X0_e1rorg3e1hu;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqp =
    measure_P.UnitDelay2_X0_e1rorg3e1hup;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpy =
    measure_P.UnitDelay4_X0_e1rorg3e1hup;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpf =
    measure_P.UnitDelay2_X0_e1rorg3e1hupm;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpya =
    measure_P.UnitDelay4_X0_e1rorg3e1hupm;
  measure_DWork.UnitDelay2_DSTAT_kxh1ddb33gqpfj =
    measure_P.UnitDelay2_X0_e1rorg3e1hupmn;
  measure_DWork.UnitDelay4_DSTAT_dotlnlp0wvpyar =
    measure_P.UnitDelay4_X0_e1rorg3e1hupmn;
  measure_DWork.UnitDelay2_DSTA_kxh1ddb33gqpfjt =
    measure_P.UnitDelay2_X0_e1rorg3e1hupmn0;
  measure_DWork.UnitDelay4_DSTA_dotlnlp0wvpyari =
    measure_P.UnitDelay4_X0_e1rorg3e1hupmn0;
  measure_DWork.UnitDelay2_DSTA_n = measure_P.UnitDelay2_X0_cb;
  measure_DWork.UnitDelay4_DSTA_ls = measure_P.UnitDelay4_X0_c;
  measure_DWork.UnitDelay2_DSTA_oz = measure_P.UnitDelay2_X0_h;
  measure_DWork.UnitDelay1_DSTATE_b = measure_P.UnitDelay1_X0_mx;
  measure_DWork.UnitDelay2_DSTATE_kb = measure_P.UnitDelay2_X0_ne;
  measure_DWork.UnitDelay4_DSTA_gs = measure_P.UnitDelay4_X0_h;
  measure_DWork.UnitDelay2_DSTA_e = measure_P.UnitDelay2_X0_om;
  measure_DWork.UnitDelay4_DSTA_hxo = measure_P.UnitDelay4_X0_om;
  measure_DWork.UnitDelay2_DSTA_pl = measure_P.UnitDelay2_X0_k;
  measure_DWork.UnitDelay4_DSTA_gn = measure_P.UnitDelay4_X0_k;
  measure_DWork.UnitDelay2_DSTA_ck = measure_P.UnitDelay2_X0_b;
  measure_DWork.UnitDelay4_DSTA_pz = measure_P.UnitDelay4_X0_b;
  measure_DWork.UnitDelay2_DSTA_cs = measure_P.UnitDelay2_X0_cj;
  measure_DWork.UnitDelay4_DSTA_d2 = measure_P.UnitDelay4_X0_cj;
  measure_DWork.UnitDelay2_DSTA_fe = measure_P.UnitDelay2_X0_di;
  measure_DWork.UnitDelay4_DSTA_mz = measure_P.UnitDelay4_X0_di;
  measure_DWork.UnitDelay2_DSTA_cx = measure_P.UnitDelay2_X0_l;
  measure_DWork.UnitDelay4_DSTA_am = measure_P.UnitDelay4_X0_l;
  measure_DWork.UnitDelay2_DSTA_n1 = measure_P.UnitDelay2_X0_ly;
  measure_DWork.UnitDelay4_DSTA_nh = measure_P.UnitDelay4_X0_ly;
  measure_DWork.UnitDelay2_DSTA_ko = measure_P.UnitDelay2_X0_f;
  measure_DWork.UnitDelay4_DSTA_fu = measure_P.UnitDelay4_X0_f;
  measure_DWork.UnitDelay2_DSTA_ef = measure_P.UnitDelay2_X0_hs;
  measure_DWork.UnitDelay4_DSTA_m5 = measure_P.UnitDelay4_X0_hs;
  measure_DWork.UnitDelay2_DSTA_mh = measure_P.UnitDelay2_X0_ma;
  measure_DWork.UnitDelay4_DSTA_e = measure_P.UnitDelay4_X0_ma;
  measure_DWork.UnitDelay2_DSTA_or = measure_P.UnitDelay2_X0_c1;
  measure_DWork.UnitDelay4_DSTA_ju = measure_P.UnitDelay4_X0_c1;
  measure_DWork.UnitDelay2_DSTA_lt = measure_P.UnitDelay2_X0_ai;
  measure_DWork.UnitDelay4_DSTA_hz = measure_P.UnitDelay4_X0_ai;
  measure_DWork.UnitDelay2_DSTA_fq = measure_P.UnitDelay2_X0_p;
  measure_DWork.UnitDelay4_DSTA_mb = measure_P.UnitDelay4_X0_p;
  measure_DWork.UnitDelay2_DSTA_d0 = measure_P.UnitDelay2_X0_hu;
  measure_DWork.UnitDelay4_DSTA_fp = measure_P.UnitDelay4_X0_hu;
  measure_DWork.UnitDelay2_DSTA_mf = measure_P.UnitDelay2_X0_bg;
  measure_DWork.UnitDelay4_DSTA_pm = measure_P.UnitDelay4_X0_bg;
  measure_DWork.UnitDelay2_DSTA_pz = measure_P.UnitDelay2_X0_ob;
  measure_DWork.UnitDelay4_DSTA_gf = measure_P.UnitDelay4_X0_ob;
  measure_DWork.UnitDelay2_DSTA_g = measure_P.UnitDelay2_X0_g;
  measure_DWork.UnitDelay4_DSTA_hc = measure_P.UnitDelay4_X0_g;
  measure_DWork.UnitDelay2_DSTA_hh = measure_P.UnitDelay2_X0_nx;
  measure_DWork.UnitDelay4_DSTA_gv = measure_P.UnitDelay4_X0_n;
  measure_DWork.UnitDelay2_DSTA_cs5 = measure_P.UnitDelay2_X0_ec;
  measure_DWork.UnitDelay4_DSTA_g0 = measure_P.UnitDelay4_X0_ec;
  measure_DWork.UnitDelay2_DSTA_fb = measure_P.UnitDelay2_X0_ks;
  measure_DWork.UnitDelay4_DSTATE_o = measure_P.UnitDelay4_X0_ph;
  measure_DWork.UnitDelay2_DSTATE_n = measure_P.UnitDelay2_X0_db;
  measure_DWork.UnitDelay4_DSTATE_eq = measure_P.UnitDelay4_X0_gm;
  measure_DWork.UnitDelay2_DSTATE_a = measure_P.UnitDelay2_X0_lt;
  measure_DWork.UnitDelay4_DSTATE_g = measure_P.UnitDelay4_X0_lh;
  measure_DWork.UnitDelay2_DSTATE_dq = measure_P.UnitDelay2_X0_gs;
  measure_DWork.UnitDelay4_DSTATE_je = measure_P.UnitDelay4_X0_hh;
  measure_DWork.UnitDelay2_DSTATE_o = measure_P.UnitDelay2_X0_pu;
  measure_DWork.UnitDelay4_DSTATE_e1 = measure_P.UnitDelay4_X0_hp;
  measure_DWork.UnitDelay2_DSTATE_c = measure_P.UnitDelay2_X0_d2;
  measure_DWork.UnitDelay4_DSTATE_i = measure_P.UnitDelay4_X0_jg;
  measure_DWork.UnitDelay2_DSTATE_f = measure_P.UnitDelay2_X0_oe;
  measure_DWork.UnitDelay4_DSTATE_m = measure_P.UnitDelay4_X0_n1;
  measure_DWork.UnitDelay2_DSTATE_gs = measure_P.UnitDelay2_X0_i;
  measure_DWork.UnitDelay4_DSTATE_n = measure_P.UnitDelay4_X0_i;
  measure_DWork.UnitDelay2_DSTATE_p = measure_P.UnitDelay2_X0_gr;
  measure_DWork.UnitDelay4_DSTATE_jf = measure_P.UnitDelay4_X0_at;
  measure_DWork.UnitDelay2_DSTATE_h2 = measure_P.UnitDelay2_X0_j3;
  measure_DWork.UnitDelay4_DSTATE_l = measure_P.UnitDelay4_X0_ce;
  measure_DWork.UnitDelay2_DSTATE_ai = measure_P.UnitDelay2_X0_kr;
  measure_DWork.UnitDelay4_DSTATE_co = measure_P.UnitDelay4_X0_ga;
  measure_DWork.UnitDelay2_DSTATE_l = measure_P.UnitDelay2_X0_il;
  measure_DWork.UnitDelay4_DSTATE_j5 = measure_P.UnitDelay4_X0_b1;
  measure_DWork.UnitDelay2_DSTATE_cm = measure_P.UnitDelay2_X0_h0;
  measure_DWork.RateTransition_Buffer0.re = measure_P.RateTransition_X0;
  measure_DWork.RateTransition_Buffer0.im = 0.0;
  measure_DWork.RateTransition_Buffer0_m.re = measure_P.RateTransition_X0_h;
  measure_DWork.RateTransition_Buffer0_m.im = 0.0;
  measure_DWork.RateTransition_Buffer0_p.re = measure_P.RateTransition_X0_m;
  measure_DWork.RateTransition_Buffer0_p.im = 0.0;
  measure_DWork.RateTransition_Buffer0_f = measure_P.RateTransition_X0_d;
  measure_DWork.RateTransition_Buffer0_n = measure_P.RateTransition_X0_mf;
  measure_DWork.RateTransition_Buffer0_c = measure_P.RateTransition_X0_mn;
  measure_DWork.RateTransition_Buffer0_nm[0] = measure_P.RateTransition_X0_mk;
  measure_DWork.RateTransition_Buffer0_nm[1] = measure_P.RateTransition_X0_mk;
  measure_DWork.RateTransition_Buffer0_nm[2] = measure_P.RateTransition_X0_mk;
  measure_DWork.RateTransition_Buffer0_nm[3] = measure_P.RateTransition_X0_mk;
  measure_DWork.RateTransition_Buffer0_d[0] = measure_P.RateTransition_X0_l;
  measure_DWork.RateTransition_Buffer0_d[1] = measure_P.RateTransition_X0_l;
  measure_DWork.RateTransition_Buffer0_d[2] = measure_P.RateTransition_X0_l;
  measure_DWork.RateTransition_Buffer0_d[3] = measure_P.RateTransition_X0_l;
  measure_DWork.RateTransition_Buffer0_j[0] = measure_P.RateTransition_X0_n;
  measure_DWork.RateTransition_Buffer0_j[1] = measure_P.RateTransition_X0_n;
  measure_DWork.RateTransition_Buffer0_j[2] = measure_P.RateTransition_X0_n;
  measure_DWork.RateTransition_Buffer0_j[3] = measure_P.RateTransition_X0_n;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhw =
    measure_P.UnitDelay1_X0_jcfawyw2o0;
  measure_DWork.delay_DSTATE_i2wj4 = measure_P.delay_X0_jcfaw;
  measure_DWork.UnitDelay_DSTATE_lmdwo = measure_P.UnitDelay_X0_jcfaw;
  measure_DWork.UnitDelay_DSTATE_lmdwo300 = measure_P.UnitDelay_X0_jcfawyw2;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhwr =
    measure_P.UnitDelay1_X0_jcfawyw2o0o;
  measure_DWork.UnitDelay_DSTATE_lmdwo300i = measure_P.UnitDelay_X0_jcfawyw2o;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhwrm =
    measure_P.UnitDelay1_X0_jcfawyw2o0os;
  measure_DWork.UnitDelay4_DSTATE_czl44j1i = measure_P.UnitDelay4_X0_jcfawyw2;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0 =
    measure_P.UnitDelay2_X0_jcfawyw2o0;
  measure_DWork.UnitDelay4_DSTATE_czl44j1ip = measure_P.UnitDelay4_X0_jcfawyw2o;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j =
    measure_P.UnitDelay2_X0_jcfawyw2o0o;
  measure_DWork.UnitDelay1_DSTATE_c = measure_P.UnitDelay1_X0_j;
  measure_DWork.UnitDelay_DSTATE_lmdwo3 = measure_P.UnitDelay_X0_jcfawy;
  measure_DWork.UnitDelay2_DSTAT_h5brdqciz0j45w =
    measure_P.UnitDelay2_X0_jcfawyw2o0osk2;
  measure_DWork.UnitDelay_DSTATE_lmd = measure_P.UnitDelay_X0_jcf;
  measure_DWork.delay_DSTATE_i2wj4d = measure_P.delay_X0_jcfawy;
  measure_DWork.delay1_DSTATE_ces = measure_P.delay1_X0_jcf;
  measure_DWork.UnitDelay_DSTATE_lmdwo300ig = measure_P.UnitDelay_X0_jcfawyw2o0;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j4 =
    measure_P.UnitDelay2_X0_jcfawyw2o0os;
  measure_DWork.UnitDelay1_DSTATE_cm = measure_P.UnitDelay1_X0_jc;
  measure_DWork.UnitDelay1_DSTATE_cmn = measure_P.UnitDelay1_X0_jcf;
  measure_DWork.UnitDelay4_DSTATE_czl44j1ipa =
    measure_P.UnitDelay4_X0_jcfawyw2o0;
  measure_DWork.UnitDelay1_DSTATE_cmnb = measure_P.UnitDelay1_X0_jcfa;
  measure_DWork.UnitDelay1_DSTATE_cmnb3 = measure_P.UnitDelay1_X0_jcfaw;
  measure_DWork.UnitDelay1_DSTATE_cmnb3j = measure_P.UnitDelay1_X0_jcfawy;
  measure_DWork.UnitDelay_DSTATE_lmdwo30 = measure_P.UnitDelay_X0_jcfawyw;
  measure_DWork.UnitDelay1_DSTATE_j = measure_P.UnitDelay1_X0_b;
  measure_DWork.delay_DSTATE_h = measure_P.delay_X0_h;
  measure_DWork.UnitDelay_DSTATE_pd = measure_P.UnitDelay_X0_he;
  measure_DWork.UnitDelay_DSTATE_pdo = measure_P.UnitDelay_X0_heb;
  measure_DWork.UnitDelay1_DSTATE_ac = measure_P.UnitDelay1_X0_he;
  measure_DWork.UnitDelay_DSTATE_pdoi = measure_P.UnitDelay_X0_hebr;
  measure_DWork.UnitDelay1_DSTATE_ac4 = measure_P.UnitDelay1_X0_heb;
  measure_DWork.UnitDelay3_DSTATE_i5z5 = measure_P.UnitDelay3_X0_ap;
  measure_DWork.UnitDelay3_DSTATE_i5z5o = measure_P.UnitDelay3_X0_i2;
  measure_DWork.UnitDelay3_DSTATE_i5z5oq = measure_P.UnitDelay3_X0_or;
  measure_DWork.UnitDelay4_DSTATE_edu = measure_P.UnitDelay4_X0_mqco;
  measure_DWork.UnitDelay2_DSTATE_e5yc1 = measure_P.UnitDelay2_X0_mqco2;
  measure_DWork.UnitDelay4_DSTATE_edua = measure_P.UnitDelay4_X0_mqco2;
  measure_DWork.UnitDelay2_DSTATE_e5yc1i = measure_P.UnitDelay2_X0_mqco2g;
  measure_DWork.UnitDelay1_DSTATE_dg = measure_P.UnitDelay1_X0_mq;
  measure_DWork.UnitDelay_DSTATE_otr = measure_P.UnitDelay_X0_mqc;
  measure_DWork.UnitDelay2_DSTATE_e5yc1iho = measure_P.UnitDelay2_X0_mqco2gbu;
  measure_DWork.UnitDelay_DSTATE_o = measure_P.UnitDelay_X0_m;
  measure_DWork.delay_DSTATE_j0 = measure_P.delay_X0_mq;
  measure_DWork.delay1_DSTATE_kz = measure_P.delay1_X0_mq;
  measure_DWork.UnitDelay_DSTATE_otrxo = measure_P.UnitDelay_X0_mqco2;
  measure_DWork.UnitDelay2_DSTATE_e5yc1ih = measure_P.UnitDelay2_X0_mqco2gb;
  measure_DWork.UnitDelay1_DSTATE_dgz = measure_P.UnitDelay1_X0_mqc;
  measure_DWork.UnitDelay1_DSTATE_dgzm = measure_P.UnitDelay1_X0_mqco;
  measure_DWork.UnitDelay4_DSTATE_eduao = measure_P.UnitDelay4_X0_mqco2g;
  measure_DWork.UnitDelay1_DSTATE_dgzmv = measure_P.UnitDelay1_X0_mqco2;
  measure_DWork.UnitDelay1_DSTATE_dgzmvr = measure_P.UnitDelay1_X0_mqco2g;
  measure_DWork.UnitDelay1_DSTATE_dgzmvrp = measure_P.UnitDelay1_X0_mqco2gb;
  measure_DWork.UnitDelay_DSTATE_otrx = measure_P.UnitDelay_X0_mqco;
  measure_DWork.RateTransition_Buffer0_h = measure_P.RateTransition_X0_la;
  measure_DWork.RateTransition_Buffer0_po = measure_P.RateTransition_X0_i;
  measure_DWork.RateTransition_Buffer0_e = measure_P.RateTransition_X0_d5;
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
    3600.0,
    0.999999,
    0.499999,
    0.999999,
    0.499999,
    6.25E-5,
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
    6.25E-5,
    6.25E-5,
    -6.25E-5,
    0.0625,
    0.0625,
    -0.0625,
    100.0,
    100.0,
    12.5,
    0.5,
    -0.0625,
    12.5,
    100.0,
    0.499999,
    -0.499999,
    1.0,
    0.08,
    0.08,
    0.00025,
    0.999999,
    0.499999,
    0.999999,
    0.499999,
    4.0E+9,
    4.0E+9,
    0.0,
    0.0,
    0.000125,
    1.0E-9,
    1.0E-9,
    -0.000125,
    0.025,
    0.025,
    0.00025,
    0.999999,
    0.499999,
    0.05,
    0.05,
    0.00025,
    0.999999,
    0.499999,
    50.0,
    50.0,
    1.0E-9,
    100.0,
    100.0,
    25.0,
    1.0E-9,
    1.0E+9,
    1.0E+9,
    1.0E-9,
    1.0E-9,
    1.0,
    1.0E-9,
    1.0E+9,
    1.0E+9,
    1.0E-9,
    1.0E-9,
    1.0,
    1.0E-9,
    1.0E+9,
    1.0E+9,
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
    0.00025,
    0.999999,
    0.499999,
    0.02,
    0.02,
    0.00025,
    0.999999,
    0.499999,
    0.14,
    0.14,
    0.00025,
    0.999999,
    0.499999,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    100.0,
    100.0,
    1.0E-9,
    -3.1415926535897931,
    1273.2395447351626,
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
    1273.2395447351626,
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
    1273.2395447351626,
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
    6.25E-5,
    6.25E-5,
    -6.25E-5,
    0.0625,
    0.0625,
    -0.0625,
    100.0,
    100.0,
    12.5,
    0.5,
    -0.0625,
    12.5,
    100.0,
    0.499999,
    -0.499999,
    1.0,
    0.08,
    0.08,
    0.00025,
    0.999999,
    0.499999,
    0.999999,
    0.499999,
    4.0E+9,
    4.0E+9,
    0.0,
    0.0,
    0.000125,
    1.0E-9,
    1.0E-9,
    -0.000125,
    -0.999999,
    -0.499999,
    1.0E-9,
    -0.999999,
    -0.499999,
    1.0E-9,
    -0.999999,
    -0.499999,
    1.0E-9,
    -0.999999,
    -0.499999,
    1.0E-9,
    -0.999999,
    -0.499999,
    1.0E-9,
    -0.999999,
    -0.499999,
    1.0E-9,
    0.0,
    0.0,
    0.0,
    0.0,
    50.0,
    1.0,
    820.0,
    410.0,
    0.0,
    0.5,
    1.0,
    420.0,
    210.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.5,

    { 0.0, 0.0, 0.0 },

    { 0.0, 0.0, 0.0 },
    -8000.0,
    1.0,
    0.5,
    0.0,
    0.0,
    0.5,
    -8000.0,
    1.0,
    0.5,
    0.57735026918962584,
    0.0,
    0.0,
    0.5,
    -8000.0,
    1.0,
    0.5,
    2.0,
    0.33333333333333331,
    -3.1415926535897931,
    1273.2395447351626,
    0.0,
    0.0,
    0.00025,
    8000.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    2.0,
    0.00025,
    8000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    6.25E-5,
    0.0,
    0.0,
    0.0,
    0.0,
    0.02,
    25464.790894703252,
    180.0,
    3600.0,
    1.0,
    1300.0,
    650.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.00025,
    8000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    6.25E-5,
    0.0,
    5.0,
    0.04,
    1.0E-9,
    50.0,
    1.0,
    660.0,
    330.0,
    0.0,
    0.5,
    0.00078539816339744833,
    0.0,
    3.1415926535897931,
    25.0,
    0.04,
    2.0,
    0.0,
    0.0,
    0.00025,
    8000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    6.25E-5,
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
    2260.0,
    1130.0,
    0.0,
    0.5,
    0.0,
    1.0,
    340.0,
    170.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.5,
    0.00025,
    8000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    6.25E-5,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    3.5,
    0.00025,
    8000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    6.25E-5,
    0.0,
    0.0,
    6.0,
    0.0,
    0.5,
    0.0,
    8000.0,
    0.02,
    0.0,
    0.3,
    0.0,
    8000.0,
    0.02,
    0.0,
    0.3,
    0.0,
    8000.0,
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
    1300.0,
    650.0,
    0.0,
    0.5,
    0.0,
    0.0,
    0.0,
    0.00025,
    8000.0,
    0.0,
    0.0,
    0.0,
    2.0,
    6.25E-5,
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
    0.0,
    0.0,
    0.5,
    -8000.0,
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
    -8000.0,
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
    -8000.0,
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
    0.70710678118654746,
    0.70710678118654746,
    0.70710678118654746,
    1.0E-9,
    0.0,
    0.81649658092772615,
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
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.14,
    0.2,

    { 2.0, 3.0, 4.0, 5.0 },
    8000.0,
    8000.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.000125,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E+9,
    0.000125,
    0.5,
    0.0,
    0.08,
    0.0,
    1.0,
    0.08,
    -6.25E-5,
    0.5,
    -0.00078539816339744833,
    1.0,
    0.4,
    -0.00025,
    0.0,
    8000.0,
    1.0,
    0.0,
    8000.0,
    8000.0,
    0.0,
    -3.1415926535897931,
    8000.0,
    0.0,
    0.03076676552365587,
    0.96923323447634413,
    0.0,
    -3.1415926535897931,
    8000.0,
    0.0,
    0.03076676552365587,
    0.96923323447634413,
    0.0,
    -3.1415926535897931,
    8000.0,
    0.0,
    0.03076676552365587,
    0.96923323447634413,
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
    0.000125,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0E+9,
    0.000125,
    0.5,
    0.0,
    0.08,
    0.0,
    1.0,
    0.08,
    -6.25E-5,
    0.5,
    -0.00078539816339744833,
    1.0,
    0.4,
    -0.00025,
    0.0,
    8000.0,
    1.0,
    0.0,
    3.1415926535897931,
    6.2831853071795862,
    0.03125,
    64.0,
    1.0E-9,
    8000.0,
    6.2831853071795862,
    -1.5707963267948966,
    0.0,
    0.0,
    3.1415926535897931,
    6.2831853071795862,

    { 2.0, 3.0, 4.0, 5.0 },

    { 1.5707963267948966, 3.1415926535897931, 4.71238898038469,
      6.2831853071795862 },
    0.0,
    1.0E-9,
    3.1415926535897931,
    6.2831853071795862,
    0.03125,
    64.0,
    1.0E-9,
    8000.0,
    6.2831853071795862,
    -1.5707963267948966,
    0.0,
    0.0,
    3.1415926535897931,
    6.2831853071795862,

    { 2.0, 3.0, 4.0, 5.0 },

    { 1.5707963267948966, 3.1415926535897931, 4.71238898038469,
      6.2831853071795862 },
    0.0,
    1.0E-9,
    3.1415926535897931,
    6.2831853071795862,
    0.03125,
    64.0,
    1.0E-9,
    8000.0,
    6.2831853071795862,
    -1.5707963267948966,
    0.0,
    0.0,
    3.1415926535897931,
    6.2831853071795862,

    { 2.0, 3.0, 4.0, 5.0 },

    { 1.5707963267948966, 3.1415926535897931, 4.71238898038469,
      6.2831853071795862 },
    0.0,
    1.0E-9,

    { { 1.0, 0.0 }, { -0.49999999999999978, -0.86602540378443871 }, { -
        0.49999999999999978, 0.86602540378443871 } },

    { { 1.0, 0.0 }, { -0.49999999999999978, 0.86602540378443871 }, { -
        0.49999999999999978, -0.86602540378443871 } },

    { { 1.0, 0.0 }, { -0.49999999999999978, -0.86602540378443871 }, { -
        0.49999999999999978, 0.86602540378443871 } },

    { { 1.0, 0.0 }, { -0.49999999999999978, 0.86602540378443871 }, { -
        0.49999999999999978, -0.86602540378443871 } },
    641,
    641,
    2,
    201,
    201,
    2,
    401,
    401,
    2,
    321,
    321,
    2,
    161,
    161,
    2,
    1121,
    1121,
    2,
    641,
    641,
    2,
    160,
    160,
    2,
    201,
    201,
    201,
    2,
    401,
    401,
    401,
    401,
    401,
    401,
    2,
    641,
    641,
    641,
    2,
    321,
    321,
    321,
    321,
    321,
    321,
    321,
    321,
    321,
    321,
    321,
    321,
    321,
    321,
    321,
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
    2,
    1121,
    1121,
    1121,
    80,
    161,
    161,
    161,
    161,
    161,
    161,
    1121,
    1121,
    1121,
    161,
    161,
    161,
    161,
    161,
    161,
    1121,
    1121,
    1121,
    2,
    641,
    641,
    641,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    321,
    321,
    321,
    161,
    161,
    161,
    641,
    641,
    641,
    641,
    641,
    641,
    32,
    32,
    32,
    1U,
    241U,
    1U,
    801U,
    1U,
    1281U,
    1U,
    1U,
    1U,
    1U,
    281U,
    1U,
    1U,
    1U,
    1U,
    640U,
    1U,
    1U,
    0U,
    1U,
    161U,
    1U,
    1U,
    1U,
    1U,
    361U,
    1U,
    1U,
    1U,
    321U,
    1U,
    801U,
    1U,
    321U,
    1U,
    801U,
    1U,
    321U,
    1U,
    801U,
    1U,
    321U,
    1U,
    801U,
    1U,
    321U,
    1U,
    801U,
    1U,
    321U,
    1U,
    801U,
    1U,
    1U,
    360U,
    1U,
    1U,
    360U,
    1U,
    1U,
    360U,
    1U,
    1U,
    640U,
    1U,
    321U,
    1U,
    1U,
    640U,
    1U,
    1U,
    0U,
    1U,
    161U,
    1281U,
    0U,
    801U,
    0U,
    1U,
    0U,
    241U,
    0U,
    321U,
    321U,
    0U,
    321U,
    0U,
    321U,
    0U,
    801U,
    0U,
    801U,
    0U,
    321U,
    0U,
    1U,
    0U,
    1U,
    0U,
    1U,
    0U,
    801U,
    0U,
    801U,
    0U,
    321U,
    0U,
    801U,
    0U,
    801U,
    0U,
    321U,
    0U,
    1U,
    0U,
    0U,
    1U,
    0U,
    1U,
    1U,
    1U,
    161U,
    0U,
    1U,
    0U,
    0U,
    0U,
    281U,
    0U,
    1U,
    1U,
    0U,
    1U,
    0U,
    1U,
    0U,
    1U,
    161U,
    0U,
    1U,
    0U,
    0U,
    0U,
    361U,
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
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0
  };

  measure_P = measure_P_temp;
  measure_M = &measure_M_;
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

RT_MODEL_measure * measureModelClass::getRTM() const
{
  return measure_M;
}
