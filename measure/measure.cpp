/**
 * discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
 *
 * Copyright (c) 2012 Andrew Roscoe, Steven Blair
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

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
  real_T rtb_UnaryMinus_l;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_h4;
  boolean_T rtb_Compare_h;
  real_T rtb_UnitDelay1;
  real_T rtb_Sum1_p5;
  real_T rtb_UnitDelay1_p;
  real_T rtb_Sum1_pz;
  real_T rtb_UnitDelay1_n;
  real_T rtb_Sum1_lle;
  real_T rtb_TrigonometricFunction;
  real_T rtb_Sum2_i;
  real_T rtb_MathFunction1;
  real_T rtb_Switch;
  real_T rtb_Gain_pj;
  boolean_T rtb_Compare_mtg;
  real_T rtb_Tps2dt_cr;
  uint32_T rtb_Switch1_ia;
  boolean_T rtb_Compare_hpz455i0;
  boolean_T rtb_Compare_hpz455i02;
  boolean_T rtb_LogicalOperator1_fwnazb5b22n;
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
  real_T rtb_Divide_nf;
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
  real_T rtb_Divide_hh;
  boolean_T rtb_Compare_ddcrdc;
  boolean_T rtb_Compare_ky;
  boolean_T rtb_Compare_ddcrdcv;
  boolean_T rtb_Compare_enj;
  boolean_T rtb_Compare_ks;
  real_T rtb_Subtract3_lri;
  real_T rtb_MathFunction_gbn2;
  real_T rtb_Divide_mg;
  real_T rtb_Divide_h;
  real_T rtb_TrigonometricFunction_i;
  boolean_T rtb_LogicalOperator_eg0;
  real_T rtb_Ts_FFT_k;
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
  boolean_T rtb_Compare_o;
  real_T rtb_MathFunction_pl;
  real_T rtb_Divide_nfu;
  uint32_T rtb_Switch_lli5ykm;
  real_T rtb_Switch1_iew;
  uint32_T rtb_Bias_aswd3;
  boolean_T rtb_Compare_js;
  boolean_T rtb_LogicalOperator2_f3;
  boolean_T rtb_LogicalOperator2_f3l;
  real_T rtb_Sum1_dat;
  real_T rtb_Divide_la;
  real_T rtb_Divide_i;
  real_T rtb_Divide_o1;
  real_T rtb_SumofElements1;
  real_T rtb_ComplextoRealImag_o2_l;
  real_T rtb_OutputWatts;
  real_T rtb_UnitDelay1_o;
  real_T rtb_UnitDelay1_f;
  real_T rtb_UnitDelay1_pu;
  real_T rtb_Divide_cv;
  real_T rtb_TrigonometricFunction_hr;
  real_T rtb_TrigonometricFunction_hrx;
  real_T rtb_Sum1_kv;
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
  boolean_T rtb_Any_Phases_Not_Disturbed;
  real_T rtb_Switch_jkaja;
  real_T rtb_Switch_jka;
  real_T rtb_Switch_j;
  real_T rtb_Switch4;
  int32_T i;
  real_T tmp[6];
  boolean_T rtb_Switch6_idx;
  real_T rtb_Add1_f_idx;
  real_T rtb_Add1_f_idx_0;
  real_T rtb_Add1_f_idx_1;
  real_T rtb_VpuIpktoVrmsIrms_re;
  real_T rtb_VpuIpktoVrmsIrms_im;
  real_T rtb_Gain6_re;
  (measure_M->Timing.RateInteraction.TID0_1)++;
  if ((measure_M->Timing.RateInteraction.TID0_1) > 199) {
    measure_M->Timing.RateInteraction.TID0_1 = 0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.SF_FixedDiscreteDelaySfunction_RWORK[0];
    int_T *VDD_in = (int_T*)&measure_DWork.SF_FixedDiscreteDelaySfunction_IWORK;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_DWork.SF_FixedDiscreteDelaySfunction_DSTATE;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfunction_P1 + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfunction_P1;
    measure_B.SF_FixedDiscreteDelaySfunction = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfunction_P1)
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
      &measure_DWork.SF_FixedDiscreteDelaySfunction_RWORK_b[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.SF_FixedDiscreteDelaySfunction_IWORK_c;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_DWork.SF_FixedDiscreteDelaySfunction_DSTATE_b;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfunction_P1_j + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfunction_P1_j;
    measure_B.SF_FixedDiscreteDelaySfunction_h = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfunction_P1_j)
      *VDD_in = 0;
  }

  rtb_UnitDelay4_dmwj4s1jwn3 = measure_DWork.UnitDelay4_DSTATE_czl44j1ipa1;
  if ((measure_DWork.UnitDelay4_DSTATE_czl44j1ipa1) &&
      (measure_DWork.delay_DSTATE_i)) {
    rtb_Switch1_i = measure_B.SF_FixedDiscreteDelaySfunction_h;
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
  rtb_UnaryMinus_l = ((((real_T)measure_DWork.clockTickCounter) <
                       measure_P.PulseGenerator1_Duty) &&
                      (measure_DWork.clockTickCounter >= 0)) ?
    measure_P.PulseGenerator1_Amp : 0.0;
  if (((real_T)measure_DWork.clockTickCounter) >=
      (measure_P.PulseGenerator1_Period - 1.0)) {
    measure_DWork.clockTickCounter = 0;
  } else {
    measure_DWork.clockTickCounter = measure_DWork.clockTickCounter + 1;
  }

  rtb_Compare = (rtb_UnaryMinus_l > measure_P.Constant_Value_f);
  rtb_Compare_h4 = ((!rtb_Compare) && (measure_DWork.delay1_DSTATE));
  rtb_UnaryMinus_l = ((((real_T)measure_DWork.clockTickCounter_g) <
                       measure_P.PulseGenerator1_Duty_j) &&
                      (measure_DWork.clockTickCounter_g >= 0)) ?
    measure_P.PulseGenerator1_Amp_j : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_g) >=
      (measure_P.PulseGenerator1_Period_j - 1.0)) {
    measure_DWork.clockTickCounter_g = 0;
  } else {
    measure_DWork.clockTickCounter_g = measure_DWork.clockTickCounter_g + 1;
  }

  rtb_Compare_h = (rtb_UnaryMinus_l > measure_P.Constant_Value_fg);
  rtb_UnitDelay1 = measure_DWork.UnitDelay1_DSTATE;
  rtb_Divide_cv = measure_P.Constant7_Value[0];
  for (i = 0; i < 5; i++) {
    tmp[0] = measure_P.Constant7_Value[0];
    tmp[1] = measure_P.Constant7_Value[1];
    tmp[2] = measure_P.Constant7_Value[2];
    tmp[3] = measure_P.Constant8_Value[0];
    tmp[4] = measure_P.Constant8_Value[1];
    tmp[5] = measure_P.Constant8_Value[2];
    rtb_Divide_cv = fmax(rtb_Divide_cv, tmp[i + 1]);
  }

  rtb_Add1_f_idx = rtb_Divide_cv - measure_P.Constant8_Value[0];
  rtb_Add1_f_idx_0 = rtb_Divide_cv - measure_P.Constant8_Value[1];
  rtb_Add1_f_idx_1 = rtb_Divide_cv - measure_P.Constant8_Value[2];
  rtb_Sum1_p5 = ((rtb_Divide_cv - measure_P.Constant7_Value[1]) *
                 measure_P.Gain_Gain_n) + measure_P.Bias_Bias_hz;
  rtb_Sum1_p5 = ((((measure_U.Vabcpu[1] - measure_DWork.UnitDelay2_DSTATE) *
                   measure_P.Gain_Gain_l) * rtb_Sum1_p5) +
                 measure_DWork.UnitDelay1_DSTATE) +
    ((((measure_DWork.UnitDelay2_DSTATE + measure_U.Vabcpu[1]) *
       measure_P.Gain1_Gain_l) - measure_DWork.UnitDelay1_DSTATE) * (rtb_Sum1_p5
      * rtb_Sum1_p5));
  rtb_UnitDelay1_p = measure_DWork.UnitDelay1_DSTATE_o;
  rtb_Sum1_pz = ((rtb_Divide_cv - measure_P.Constant7_Value[2]) *
                 measure_P.Gain_Gain_ig) + measure_P.Bias_Bias_is;
  rtb_Sum1_pz = ((((measure_U.Vabcpu[2] - measure_DWork.UnitDelay2_DSTATE_k) *
                   measure_P.Gain_Gain_f) * rtb_Sum1_pz) +
                 measure_DWork.UnitDelay1_DSTATE_o) +
    ((((measure_DWork.UnitDelay2_DSTATE_k + measure_U.Vabcpu[2]) *
       measure_P.Gain1_Gain_f) - measure_DWork.UnitDelay1_DSTATE_o) *
     (rtb_Sum1_pz * rtb_Sum1_pz));
  rtb_UnitDelay1_n = measure_DWork.UnitDelay1_DSTATE_g;
  rtb_Sum1_lle = ((rtb_Divide_cv - measure_P.Constant7_Value[0]) *
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
  if (rtb_Sum2_i < measure_P.Constant_Value_am) {
    rtb_Sum2_i += measure_P.Bias1_Bias_jcf;
  } else {
    if (rtb_Sum2_i > measure_P.Constant_Value_jc) {
      rtb_Sum2_i += measure_P.Bias_Bias_jcf;
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
  if (rtb_MathFunction1 < measure_P.Constant_Value_gg) {
    rtb_Switch = measure_P.Constant_Value_d0;
  } else if (rtb_MathFunction1 > measure_P.Constant_Value_gr) {
    rtb_Switch = measure_P.Constant1_Value_jcfawyw2o0;
  } else {
    rtb_Switch = rtb_MathFunction1;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_jcfa * rtb_Switch;
  if (measure_P.Constant1_Value_jcfawyw2o0os) {
    measure_B.Switch2 = rtb_Gain_pj + measure_P.Bias1_Bias_jcfawyw;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_oa) {
    measure_B.Switch2 = rtb_Gain_pj;
  } else {
    measure_B.Switch2 = rtb_Gain_pj + measure_P.Bias_Bias_jcfawyw;
  }

  {
    measure_B.SFunction = (int32_T)measure_B.Switch2;
  }

  if (measure_B.SFunction < measure_P.Constant_Value_bq) {
    measure_B.Switch2_h1wibj25mp = measure_P.Constant_Value_kbv;
  } else if (measure_B.SFunction > measure_P.Constant_Value_o3) {
    measure_B.Switch2_h1wibj25mp = measure_P.Constant3_Value_jc;
  } else {
    measure_B.Switch2_h1wibj25mp = measure_B.SFunction;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1)
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_n;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_j;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_c = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_j)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Gain;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mp;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator1) {
    measure_B.Switch2_h = rtb_Switch1_ie;
  } else {
    rtb_Gain_pj = ((real_T)measure_B.Switch2_h1wibj25mp) - rtb_Gain_pj;
    rtb_UnaryMinus_l = rtb_Gain_pj * rtb_Gain_pj;
    rtb_Gain_pj = (((measure_P.Gain1_Gain * rtb_Gain_pj) - rtb_UnaryMinus_l) *
                   measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1) +
      (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2 * rtb_UnaryMinus_l);
    if (rtb_Compare_h) {
      rtb_UnaryMinus_l = measure_B.Switch -
        measure_B.VariableDiscreteDelaywithOneTapSfunction;
    } else {
      rtb_UnaryMinus_l = measure_B.Switch_n -
        measure_B.VariableDiscreteDelaywithOneTapSfunction_c;
    }

    rtb_Gain_pj = ((1.0 / rtb_Switch) * measure_P.Gain_Gain) * (rtb_UnaryMinus_l
      - rtb_Gain_pj);
    if (rtb_Gain_pj < measure_P.Constant_Value_dsl) {
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
  if (rtb_Gain_pj < measure_P.Constant_Value_ha) {
    rtb_Sum2_i = measure_P.Constant_Value_ey;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_hv) {
    rtb_Sum2_i = measure_P.Constant1_Value_jcfawyw2o0o;
  } else {
    rtb_Sum2_i = rtb_Gain_pj;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_jcfawy * rtb_Sum2_i;
  if (measure_P.Constant1_Value_jcfawyw2o0osk) {
    measure_B.Switch2_h1 = rtb_Gain_pj + measure_P.Bias1_Bias_jcfawyw2;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_o2) {
    measure_B.Switch2_h1 = rtb_Gain_pj;
  } else {
    measure_B.Switch2_h1 = rtb_Gain_pj + measure_P.Bias_Bias_jcfawyw2;
  }

  {
    measure_B.SFunction_i = (int32_T)measure_B.Switch2_h1;
  }

  if (measure_B.SFunction_i < measure_P.Constant_Value_pk) {
    measure_B.Switch2_h1wibj25mpu = measure_P.Constant_Value_po3;
  } else if (measure_B.SFunction_i > measure_P.Constant_Value_ob) {
    measure_B.Switch2_h1wibj25mpu = measure_P.Constant3_Value_jcf;
  } else {
    measure_B.Switch2_h1wibj25mpu = measure_B.SFunction_i;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nu;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jc;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_co = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jc)
      *VDD_in = 0;
  }

  rtb_Compare_mtg = (rtb_Compare && (measure_DWork.delay_DSTATE_i2w));
  if (rtb_Compare_mtg) {
    measure_B.Switch_nul = measure_P.double_Value_jcfa;
  } else {
    measure_B.Switch_nul = (measure_B.Switch2_h +
      measure_DWork.UnitDelay4_DSTATE_czl) +
      measure_DWork.UnitDelay2_DSTATE_h5br;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4n[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3s;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nul;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcf;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_co5 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcf)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_m[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_j;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch2_h;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_j;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_j = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_j)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_j)
      *VDD_in = 0;
  }

  rtb_Tps2dt_cr = ((real_T)measure_B.Switch2_h1wibj25mpu) - rtb_Gain_pj;
  rtb_UnaryMinus_l = rtb_Tps2dt_cr * rtb_Tps2dt_cr;
  rtb_Switch = (measure_P.Gain1_Gain_jc * rtb_Tps2dt_cr) - rtb_UnaryMinus_l;
  rtb_MathFunction1 = (1.0 / rtb_Sum2_i) * measure_P.Gain_Gain_jcfawyw;
  if (rtb_LogicalOperator1) {
    measure_B.Switch4 = rtb_Switch1_ie;
  } else {
    if (rtb_Compare) {
      rtb_Gain_pj = measure_B.Switch_nu -
        measure_B.VariableDiscreteDelaywithOneTapSfunction_co;
    } else {
      rtb_Gain_pj = measure_B.Switch_nul -
        measure_B.VariableDiscreteDelaywithOneTapSfunction_co5;
    }

    measure_B.Switch4 = (rtb_Gain_pj -
                         ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_j
      * rtb_Switch) + (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f *
                       rtb_UnaryMinus_l))) * rtb_MathFunction1;
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4np[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3se;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulz;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfa;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_co5g = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfa)
      *VDD_in = 0;
  }

  if (rtb_Compare_mtg) {
    measure_B.Switch_nulzs = measure_P.double_Value_jcfawy;
  } else {
    measure_B.Switch_nulzs = (measure_B.Switch4 +
      measure_DWork.UnitDelay4_DSTATE_czl44) +
      measure_DWork.UnitDelay2_DSTATE_h5brdq;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4npp[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3see;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulzs;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfaw;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_co5gw =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfaw)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mf[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_jn;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch4;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpu;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jc;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_jw = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jc)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f1 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f1 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jc)
      *VDD_in = 0;
  }

  rtb_Tps2dt_cr = measure_P.Gain1_Gain_jcf * measure_P.Constant5_Value;
  rtb_Sum2_i = rtb_Tps2dt_cr + measure_P.Bias_Bias_jcfawyw2o;
  if (rtb_Sum2_i > measure_P.Constant_Value_kz) {
    rtb_Sum2_i = measure_P.Constant_Value_j;
  }

  rtb_Compare_mtg = (((measure_B.Gain < rtb_Sum2_i) && (measure_B.Gain >
    (-rtb_Tps2dt_cr))) || rtb_UnitDelay4_dmwj4s1jwn3);
  if (rtb_Compare_mtg) {
    rtb_Switch1_ia = measure_DWork.UnitDelay1_DSTATE_cmnb3jx;
  } else {
    rtb_Switch1_ia = measure_P.const_Value_jc;
  }

  rtb_Compare_hpz455i0 = (rtb_Switch1_ia == measure_P.Constant_Value_kug);
  if (rtb_Compare_mtg) {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_DWork.UnitDelay1_DSTATE_cmnb3jxq;
  } else {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_P.const_Value_j;
  }

  rtb_Compare_h4 = (rtb_UnitDelay1_pu5rdhlnellvz == measure_P.Constant_Value_kx);
  if (rtb_Compare_h4) {
    if (rtb_Compare_hpz455i0) {
      if (!rtb_LogicalOperator1) {
        if (rtb_Compare) {
          rtb_Gain_pj = measure_B.Switch_nulz -
            measure_B.VariableDiscreteDelaywithOneTapSfunction_co5g;
        } else {
          rtb_Gain_pj = measure_B.Switch_nulzs -
            measure_B.VariableDiscreteDelaywithOneTapSfunction_co5gw;
        }

        rtb_Switch1_ie = (rtb_Gain_pj -
                          ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_jw
                            * rtb_Switch) +
                           (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f1
                            * rtb_UnaryMinus_l))) * rtb_MathFunction1;
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

  rtb_Compare_hpz455i02 = (rtb_Tps2dt_cr > measure_P.Constant_Value_mg);
  rtb_LogicalOperator1_fwnazb5b22n = ((!rtb_Compare_hpz455i02) &&
    (measure_DWork.delay1_DSTATE_ce));
  if (rtb_LogicalOperator1_fwnazb5b22n) {
    measure_B.Switch_nulzsg = measure_P.double_Value_jcfawyw;
  } else {
    measure_B.Switch_nulzsg = (measure_B.Switch2_h1w +
      measure_DWork.UnitDelay4_DSTATE_czl44j) +
      measure_DWork.UnitDelay2_DSTATE_h5brdqc;
  }

  if (measure_DWork.UnitDelay2_DSTATE_h5brdqci < measure_P.Constant_Value_de) {
    rtb_Tps2dt_cr = measure_P.Constant_Value_kj;
  } else if (measure_DWork.UnitDelay2_DSTATE_h5brdqci >
             measure_P.Constant_Value_jcfawyw2o0osk24) {
    rtb_Tps2dt_cr = measure_P.Constant1_Value_jcfawyw;
  } else {
    rtb_Tps2dt_cr = measure_DWork.UnitDelay2_DSTATE_h5brdqci;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_jcfawyw2 * rtb_Tps2dt_cr;
  if (measure_P.Constant1_Value_jcfawyw2o0osk2) {
    measure_B.Switch2_h1wi = rtb_Gain_pj + measure_P.Bias1_Bias_jcfaw;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_gv) {
    measure_B.Switch2_h1wi = rtb_Gain_pj;
  } else {
    measure_B.Switch2_h1wi = rtb_Gain_pj + measure_P.Bias_Bias_jcfaw;
  }

  {
    measure_B.SFunction_il = (int32_T)measure_B.Switch2_h1wi;
  }

  if (measure_B.SFunction_il < measure_P.Constant_Value_op) {
    measure_B.Switch2_h1wibj25mpus = measure_P.Constant_Value_mwk;
  } else if (measure_B.SFunction_il > measure_P.Constant_Value_eo) {
    measure_B.Switch2_h1wibj25mpus = measure_P.Constant3_Value_j;
  } else {
    measure_B.Switch2_h1wibj25mpus = measure_B.SFunction_il;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4npph[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3seeh;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulzsg;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawy;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_co5gwo =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawy)
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4npphe[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3seeh3;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulzsg5;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawyw;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_co5gwoz =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawyw)
      *VDD_in = 0;
  }

  if (rtb_Compare_hpz455i02) {
    rtb_Sum2_i = measure_B.Switch_nulzsg -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_co5gwo;
  } else {
    rtb_Sum2_i = measure_B.Switch_nulzsg5 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_co5gwoz;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mf5[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_jng;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch2_h1w;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jcf;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_jwh = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jcf)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f1u = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f1u = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jcf)
      *VDD_in = 0;
  }

  rtb_Subtract3_ca = ((real_T)measure_B.Switch2_h1wibj25mpus) - rtb_Gain_pj;
  rtb_MathFunction_mti = rtb_Subtract3_ca * rtb_Subtract3_ca;
  rtb_Subtract3_ca = (measure_P.Gain1_Gain_jcfa * rtb_Subtract3_ca) -
    rtb_MathFunction_mti;
  rtb_Tps2dt_cr = (1.0 / rtb_Tps2dt_cr) * measure_P.Gain_Gain_jcfawyw2o;
  rtb_Sum2_i = (rtb_Sum2_i -
                ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_jwh *
                  rtb_Subtract3_ca) +
                 (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f1u *
                  rtb_MathFunction_mti))) * rtb_Tps2dt_cr;
  measure_B.ACripple1stestimate = measure_B.Switch2_h1w - rtb_Sum2_i;
  if (measure_B.ACripple1stestimate < measure_P.Constant_Value_e5) {
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

  rtb_Compare_jm = (rtb_UnitDelay1_c > measure_P.Constant_Value_ocr);
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

  if (rtb_Gain_pj < measure_P.Constant_Value_ci) {
    rtb_Switch_nu = measure_P.Constant_Value_jcfa;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_jcf) {
    rtb_Switch_nu = measure_P.Constant1_Value_jcf;
  } else {
    rtb_Switch_nu = rtb_Gain_pj;
  }

  if (rtb_Compare_mtg) {
    rtb_Switch1_a = measure_DWork.UnitDelay1_DSTATE_cmnb3jxqh;
  } else {
    rtb_Switch1_a = measure_P.const_Value;
  }

  rtb_Compare_mtg = (rtb_Switch1_a == measure_P.Constant_Value_h1f);
  rtb_LogicalOperator1_fw = (rtb_Compare_mtg || rtb_UnitDelay4_dmwj4s1jwn3);
  if (rtb_LogicalOperator1_fw) {
    rtb_Switch1_iew = rtb_Switch_nu;
  } else {
    rtb_Switch1_iew = measure_P.Constant1_Value_j;
  }

  rtb_UnitDelay1_b = measure_DWork.UnitDelay1_DSTATE_k;
  rtb_UnitDelay2_i = measure_DWork.UnitDelay2_DSTATE_kg;
  rtb_LogicalOperator1 = measure_DWork.UnitDelay4_DSTATE_hj;
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
    rtb_Sum += measure_P.Bias_Bias_ep;
  }

  rtb_UnaryMinus_o = std::sin(rtb_Sum);
  rtb_Sum2_i = std::cos(rtb_Sum);
  if (measure_DWork.UnitDelay2_DSTATE_kg < measure_P.Constant_Value_ep34emcngnx)
  {
    rtb_Switch4 = measure_P.Constant_Value_ep;
  } else {
    rtb_Switch4 = measure_DWork.UnitDelay2_DSTATE_kg;
  }

  rtb_Divide_nf = ((measure_DWork.UnitDelay2_DSTATE_kg - rtb_Switch4) *
                   measure_P.FCn3_Gain) + measure_P.Bias_Bias_ep34em;
  measure_B.Product[0] = (rtb_Sum1_lle * rtb_UnaryMinus_o) * rtb_Divide_nf;
  measure_B.Product[1] = (rtb_Sum1_lle * rtb_Sum2_i) * rtb_Divide_nf;
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
    measure_B.Switch2_f = rtb_Gain_pj + measure_P.Bias_Bias_ep3;
  }

  {
    measure_B.SFunction_c = (int32_T)measure_B.Switch2_f;
  }

  if (measure_B.SFunction_c < measure_P.Constant_Value_n3) {
    measure_B.Switch2_f0yh = measure_P.Constant_Value_fp;
  } else if (measure_B.SFunction_c > measure_P.Constant_Value_aq) {
    measure_B.Switch2_f0yh = measure_P.Constant3_Value_e;
  } else {
    measure_B.Switch2_f0yh = measure_B.SFunction_c;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_j[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_o;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_l;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_a = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d)
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_je[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ob;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ds;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_am = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ds)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Tps2dt_dt = measure_B.Switch_l -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_a;
  } else {
    rtb_Tps2dt_dt = measure_B.Switch_lv -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_am;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_a;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_g = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_g = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d)
      *VDD_in = 0;
  }

  rtb_Subtract3_lr = ((real_T)measure_B.Switch2_f0yh) - rtb_Gain_pj;
  rtb_MathFunction_gbn = rtb_Subtract3_lr * rtb_Subtract3_lr;
  rtb_Subtract3_lr = (measure_P.Gain1_Gain_e * rtb_Subtract3_lr) -
    rtb_MathFunction_gbn;
  rtb_Gain_pj = rtb_Tps2dt_dt -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m *
      rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_g *
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jel[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obu;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc)
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2a;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch4 = measure_B.Switch_lv2 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg;
  } else {
    rtb_Switch4 = measure_B.Switch_lv2a -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_as;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_ds;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_ds)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gp = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gp = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_ds)
      *VDD_in = 0;
  }

  measure_B.Divide_h = (rtb_Switch4 -
                        ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0
    * rtb_Subtract3_lr) +
    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gp *
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
  measure_B.Product_e[0] = (rtb_Sum1_p5 * rtb_UnaryMinus_o) * rtb_Divide_nf;
  measure_B.Product_e[1] = (rtb_Sum1_p5 * rtb_Sum2_i) * rtb_Divide_nf;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_f = measure_P.double_Value_d1m1;
  } else {
    measure_B.Switch_f = (measure_B.Product_e[0] +
                          measure_DWork.UnitDelay4_DSTATE_jbkwm) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5c =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1)
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5a[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2s;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cr =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch4 = measure_B.Switch_f -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5c;
  } else {
    rtb_Switch4 = measure_B.Switch_f0 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cr;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3o[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asr;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_e[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0k = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpk = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpk = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1)
      *VDD_in = 0;
  }

  measure_B.Divide_b = (rtb_Switch4 -
                        ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0k
    * rtb_Subtract3_lr) +
    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpk *
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5az[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2sv;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cre =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1)
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azs[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svt;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1h;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1h)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch4 = measure_B.Switch_f0o -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cre;
  } else {
    rtb_Switch4 = measure_B.Switch_f0o4 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrw;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_e[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kf = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkw = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkw = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m)
      *VDD_in = 0;
  }

  measure_B.Divide_b4 = (rtb_Switch4 -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kf *
      rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkw *
      rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
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
  measure_B.Product_h[0] = (rtb_Sum1_pz * rtb_UnaryMinus_o) * rtb_Divide_nf;
  measure_B.Product_h[1] = (rtb_Sum1_pz * rtb_Sum2_i) * rtb_Divide_nf;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_ng = measure_P.double_Value_m041;
  } else {
    measure_B.Switch_ng = (measure_B.Product_h[0] +
      measure_DWork.UnitDelay4_DSTATE_jbkwmsq2k) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtg;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ng;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2 =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m)
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgp;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nge;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2a =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch4 = measure_B.Switch_ng -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2;
  } else {
    rtb_Switch4 = measure_B.Switch_nge -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2a;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwd;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_h[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kft = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwv = VDD_buffer
        [0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwv = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m)
      *VDD_in = 0;
  }

  measure_B.Divide_n = (rtb_Switch4 -
                        ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kft
    * rtb_Subtract3_lr) +
    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwv *
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0t
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgpu;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeq;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m04;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2an =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m04)
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0te[
      0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgpup;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m041;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2anr =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m041)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Switch4 = measure_B.Switch_ngeq -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2an;
  } else {
    rtb_Switch4 = measure_B.Switch_ngeqq -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2anr;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0i[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdn;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_h[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftp = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvf =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvf = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0)
      *VDD_in = 0;
  }

  measure_B.Divide_nq = (rtb_Switch4 -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftp *
      rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvf *
      rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
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

  rtb_Compare_dtgasgy1ciwmtj = (rtb_Switch1_mf0c == measure_P.Constant_Value_ok);
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
  rtb_Divide_hh = ((((real_T)measure_DWork.clockTickCounter_io) <
                    measure_P.PulseGenerator1_Duty_ep) &&
                   (measure_DWork.clockTickCounter_io >= 0)) ?
    measure_P.PulseGenerator1_Amp_ep : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_io) >=
      (measure_P.PulseGenerator1_Period_ep - 1.0)) {
    measure_DWork.clockTickCounter_io = 0;
  } else {
    measure_DWork.clockTickCounter_io = measure_DWork.clockTickCounter_io + 1;
  }

  rtb_Compare_ddcrdc = (rtb_Divide_hh > measure_P.Constant_Value_ep34emcngnxmtm);
  rtb_Compare_ky = ((!rtb_Compare_ddcrdc) && (measure_DWork.delay1_DSTATE_dt));
  rtb_UnaryMinus_l = measure_DWork.UnitDelay3_DSTATE_i;
  rtb_Divide_hh = ((((real_T)measure_DWork.clockTickCounter_iom) <
                    measure_P.PulseGenerator1_Duty_ep3) &&
                   (measure_DWork.clockTickCounter_iom >= 0)) ?
    measure_P.PulseGenerator1_Amp_ep3 : 0.0;
  if (((real_T)measure_DWork.clockTickCounter_iom) >=
      (measure_P.PulseGenerator1_Period_ep3 - 1.0)) {
    measure_DWork.clockTickCounter_iom = 0;
  } else {
    measure_DWork.clockTickCounter_iom = measure_DWork.clockTickCounter_iom + 1;
  }

  rtb_Compare_ddcrdcv = (rtb_Divide_hh >
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
  if (rtb_Gain_pj < measure_P.Constant_Value_cw5) {
    rtb_Divide_hh = measure_P.Constant_Value_ep34em;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_ep34e) {
    rtb_Divide_hh = measure_P.Constant1_Value_ep;
  } else {
    rtb_Divide_hh = rtb_Gain_pj;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_ep34 * rtb_Divide_hh;
  if (measure_P.Constant1_Value_ep34e) {
    measure_B.Switch2_f0 = rtb_Gain_pj + measure_P.Bias1_Bias_ep;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_m4) {
    measure_B.Switch2_f0 = rtb_Gain_pj;
  } else {
    measure_B.Switch2_f0 = rtb_Gain_pj + measure_P.Bias_Bias_ep34;
  }

  {
    measure_B.SFunction_ct = (int32_T)measure_B.Switch2_f0;
  }

  if (measure_B.SFunction_ct < measure_P.Constant_Value_oo) {
    measure_B.Switch2_f0yhy = measure_P.Constant_Value_hm;
  } else if (measure_B.SFunction_ct > measure_P.Constant_Value_k0) {
    measure_B.Switch2_f0yhy = measure_P.Constant3_Value_ep;
  } else {
    measure_B.Switch2_f0yhy = measure_B.SFunction_ct;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0tej
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgpupg;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2ap;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5t;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2anrb =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5t)
      *VDD_in = 0;
  }

  rtb_Compare_ks = (rtb_Compare_ddcrdcv && (measure_DWork.delay_DSTATE_izx));
  if (rtb_Compare_ks) {
    measure_B.Switch_lv2aps = measure_P.double_Value_dsc5ttdhqkx;
  } else {
    measure_B.Switch_lv2aps = (measure_B.Divide_h +
      measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s4v) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35bvz;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0tejd
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgpupg2;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5tt;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2anrbl =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5tt)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_mg = measure_B.Switch_lv2ap -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2anrb;
  } else {
    rtb_Divide_mg = measure_B.Switch_lv2aps -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2anrbl;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0il[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_h;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftpo = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfa =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfa = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc)
      *VDD_in = 0;
  }

  rtb_Subtract3_lri = ((real_T)measure_B.Switch2_f0yhy) - rtb_Gain_pj;
  rtb_MathFunction_gbn2 = rtb_Subtract3_lri * rtb_Subtract3_lri;
  rtb_Subtract3_lri = (measure_P.Gain1_Gain_ep * rtb_Subtract3_lri) -
    rtb_MathFunction_gbn2;
  rtb_Gain_pj = rtb_Divide_mg -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftpo *
      rtb_Subtract3_lri) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfa *
      rtb_MathFunction_gbn2));
  rtb_Divide_mg = (1.0 / rtb_Divide_hh) * measure_P.Gain_Gain_ep34e;
  rtb_Divide_hh = rtb_Gain_pj * rtb_Divide_mg;
  if (rtb_Compare_enj) {
    measure_B.Switch_lv2aps4 = measure_P.double_Value_dsc5ttdh;
  } else {
    measure_B.Switch_lv2aps4 = (measure_B.Divide +
      measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s4vv) +
      measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35bvzo;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0tejde
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgpupg2k;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttd;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2anrbla =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttd)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_lv2aps4n = measure_P.double_Value_dsc5ttdhq;
  } else {
    measure_B.Switch_lv2aps4n = (measure_B.Divide +
      measure_DWork.UnitDelay4_DSTATE_g) + measure_DWork.UnitDelay2_DSTATE_i;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_p[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_n;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4n;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdh;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_i = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdh)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_h = measure_B.Switch_lv2aps4 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_amg5cres2anrbla;
  } else {
    rtb_Divide_h = measure_B.Switch_lv2aps4n -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_i;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilk[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf2;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftpos = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfaj =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfaj = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5)
      *VDD_in = 0;
  }

  rtb_Divide_h = (rtb_Divide_h -
                  ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftpos
                    * rtb_Subtract3_lri) +
                   (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfaj
                    * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  rtb_TrigonometricFunction_i = rt_atan2d_snf(rtb_Divide_hh, rtb_Divide_h);
  rtb_Add_p = rtb_TrigonometricFunction_i + rtb_Sum;
  if (rtb_Compare_j1k4d50fkuukjsr) {
    measure_B.Switch6 = rtb_Switch4;
  } else {
    rtb_Gain_pj = rtb_Add_p - rtb_UnaryMinus_l;
    if (rtb_Gain_pj < measure_P.Constant_Value_apb) {
      rtb_Gain_pj += measure_P.Bias1_Bias_ap;
    } else {
      if (rtb_Gain_pj > measure_P.Constant_Value_ap) {
        rtb_Gain_pj += measure_P.Bias_Bias_ap;
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
    measure_B.Switch_b = (measure_B.Switch6 + measure_DWork.UnitDelay4_DSTATE_n)
      + measure_DWork.UnitDelay2_DSTATE_a;
  }

  rtb_Gain_pj = measure_P.FCn2_Gain * rtb_Switch;
  if (rtb_Gain_pj < measure_P.Constant_Value_iv) {
    rtb_Switch_jkaja = measure_P.Constant_Value_ep34emcn;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_ep34emc) {
    rtb_Switch_jkaja = measure_P.Constant1_Value_ep3;
  } else {
    rtb_Switch_jkaja = rtb_Gain_pj;
  }

  rtb_Gain_pj = measure_P.Gain_Gain_ep34em * rtb_Switch_jkaja;
  if (measure_P.Constant1_Value_ep34em) {
    measure_B.Switch2_f0y = rtb_Gain_pj + measure_P.Bias1_Bias_ep3;
  } else if (rtb_Gain_pj < measure_P.Constant_Value_bn) {
    measure_B.Switch2_f0y = rtb_Gain_pj;
  } else {
    measure_B.Switch2_f0y = rtb_Gain_pj + measure_P.Bias_Bias_ep34e;
  }

  {
    measure_B.SFunction_ct5 = (int32_T)measure_B.Switch2_f0y;
  }

  if (measure_B.SFunction_ct5 < measure_P.Constant_Value_gq) {
    measure_B.Switch2_f0yhyr = measure_P.Constant_Value_lo;
  } else if (measure_B.SFunction_ct5 > measure_P.Constant_Value_es) {
    measure_B.Switch2_f0yhyr = measure_P.Constant3_Value_ep3;
  } else {
    measure_B.Switch2_f0yhyr = measure_B.SFunction_ct5;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_l[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ny;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mz;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_f = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mz)
      *VDD_in = 0;
  }

  rtb_LogicalOperator_eg0 = (rtb_Compare_ddcrdc &&
    (measure_DWork.delay_DSTATE_izxx));
  if (rtb_LogicalOperator_eg0) {
    measure_B.Switch_bo = measure_P.double_Value_mzl;
  } else {
    measure_B.Switch_bo = (measure_B.Switch6 + measure_DWork.UnitDelay4_DSTATE_d)
      + measure_DWork.UnitDelay2_DSTATE_ai;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_e[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_nv;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_bo;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mzl;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_g = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mzl)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkv[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch6;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mz;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposv = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mz)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajc =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajc =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mz)
      *VDD_in = 0;
  }

  rtb_Ts_FFT_k = ((real_T)measure_B.Switch2_f0yhyr) - rtb_Gain_pj;
  rtb_UnaryMinus_l = rtb_Ts_FFT_k * rtb_Ts_FFT_k;
  rtb_Switch = (measure_P.Gain1_Gain_ep3 * rtb_Ts_FFT_k) - rtb_UnaryMinus_l;
  rtb_MathFunction1 = (1.0 / rtb_Switch_jkaja) * measure_P.Gain_Gain_ep34emc;
  if (rtb_Compare_j1k4d50fkuukjsr) {
    rtb_Ts_FFT_k = rtb_Switch4;
  } else {
    if (rtb_Compare_ddcrdc) {
      rtb_Gain_pj = measure_B.Switch_b -
        measure_B.VariableDiscreteDelaywithOneTapSfunction_f;
    } else {
      rtb_Gain_pj = measure_B.Switch_bo -
        measure_B.VariableDiscreteDelaywithOneTapSfunction_g;
    }

    rtb_Ts_FFT_k = (rtb_Gain_pj -
                    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposv
                      * rtb_Switch) +
                     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajc
                      * rtb_UnaryMinus_l))) * rtb_MathFunction1;
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
      &measure_DWork.SF_FixedDiscreteDelaySfunction_RWORK_j[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.SF_FixedDiscreteDelaySfunction_IWORK_n;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_DWork.SF_FixedDiscreteDelaySfunction_DSTATE_n;
    VDD_out = *VDD_in - measure_P.SF_FixedDiscreteDelaySfunction_P1_f + 1;
    if (VDD_out < 0)
      VDD_out = VDD_out + measure_P.SF_FixedDiscreteDelaySfunction_P1_f;
    measure_B.SF_FixedDiscreteDelaySfunction_o = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in == measure_P.SF_FixedDiscreteDelaySfunction_P1_f)
      *VDD_in = 0;
  }

  rtb_Compare_g3iwu32gm4xoqly = (measure_B.SF_FixedDiscreteDelaySfunction_o >
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
    measure_P.Constant_Value_maw);
  if (rtb_Compare_gw) {
    rtb_Switch1_dg2as0wb = measure_P.const_Value_m;
  } else {
    rtb_Switch1_dg2as0wb = measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml;
  }

  rtb_Compare_gw = (rtb_Switch1_dg2as0wb == measure_P.Constant_Value_mawl);
  rtb_LogicalOperator2_npq = (((measure_DWork.UnitDelay_DSTATE_mj2fm) ||
    rtb_Compare_g3iwu32gm4xoql) && (!rtb_Compare_gw));
  rtb_LogicalOperator2_npqx = (rtb_Compare_g3iwu32gm4xoqly &&
    rtb_LogicalOperator2_npq);
  if (rtb_Compare_ji) {
    rtb_Switch1_mf0c2 = measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml3;
  } else {
    rtb_Switch1_mf0c2 = measure_P.const_Value_okw;
  }

  rtb_Compare_ji = (rtb_Switch1_mf0c2 == measure_P.Constant_Value_okw);
  rtb_UnitDelay_itx = measure_DWork.UnitDelay_DSTATE_mj2;
  rtb_Compare_il = (measure_DWork.UnitDelay_DSTATE_mj2 <
                    measure_P.Constant_Value_pt);
  if (rtb_Compare_il) {
    rtb_Switch1_mf0c25 = measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml3e;
  } else {
    rtb_Switch1_mf0c25 = measure_P.const_Value_my5;
  }

  rtb_Compare_dtgasgy1ciwmtjh = (rtb_Switch1_mf0c25 ==
    measure_P.Constant_Value_my);
  if (rtb_Compare_il) {
    rtb_Switch1_mf0c25z = measure_P.const_Value_my;
  } else {
    rtb_Switch1_mf0c25z = measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml3e2;
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
    if (rtb_Gain_pj < measure_P.Constant_Value_cw1ksrz) {
      rtb_Switch_jkaja = measure_P.Constant_Value_cw1ksr;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_cw1ks) {
      rtb_Switch_jkaja = measure_P.Constant1_Value_cw;
    } else {
      rtb_Switch_jkaja = rtb_Gain_pj;
    }

    if (!(rtb_Switch_jkaja < measure_P.Constant_Value_cw1ksrzc)) {
      rtb_Switch_jkaja = 1.0 / rtb_Switch_jkaja;
    }
  } else {
    rtb_Switch_jkaja = measure_P.Constant2_Value;
  }

  rtb_Switch1_ie = rtb_Ts_FFT_k * rtb_Switch_jkaja;
  rtb_LogicalOperator1_pvh3 = (rtb_Compare_jsl || (!(rtb_Compare_g3iwu32gm4xoq ||
    rtb_LogicalOperator9)));
  rtb_Gain_pj = measure_DWork.UnitDelay3_DSTATE_i5;
  if (rtb_Compare_enj) {
    measure_B.Switch_f0o4o = measure_P.double_Value_d1m1hiqruq;
  } else {
    measure_B.Switch_f0o4o = (measure_B.Divide_b4 +
      measure_DWork.UnitDelay4_DSTATE_i) + measure_DWork.UnitDelay2_DSTATE_m;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_c[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_b;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4o;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hi;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_h = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hi)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_f0o4ow = measure_P.double_Value_d1m1hiqruqx;
  } else {
    measure_B.Switch_f0o4ow = (measure_B.Divide_b4 +
      measure_DWork.UnitDelay4_DSTATE_n3) + measure_DWork.UnitDelay2_DSTATE_il;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_k[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_g;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4ow;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiq;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hi = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiq)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_b4h = measure_B.Switch_f0o4o -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_h;
  } else {
    rtb_Divide_b4h = measure_B.Switch_f0o4ow -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hi;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvg
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_b4;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvc = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1)
      *VDD_in = 0;
  }

  rtb_Divide_b4h = (rtb_Divide_b4h -
                    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvc
                      * rtb_Subtract3_lri) +
                     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco
                      * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  if (rtb_Compare_enj) {
    measure_B.Switch_f0o4owl = measure_P.double_Value_d1m1hiqr;
  } else {
    measure_B.Switch_f0o4owl = (measure_B.Divide_b +
      measure_DWork.UnitDelay4_DSTATE_a) + measure_DWork.UnitDelay2_DSTATE_b;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_i[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_k;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owl;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqr;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_o = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqr)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_f0o4owld = measure_P.double_Value_d1m1hiqru;
  } else {
    measure_B.Switch_f0o4owld = (measure_B.Divide_b +
      measure_DWork.UnitDelay4_DSTATE_jk) + measure_DWork.UnitDelay2_DSTATE_hq;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_p0[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_e;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owld;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqru;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_oy = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqru)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_b4ha = measure_B.Switch_f0o4owl -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_o;
  } else {
    rtb_Divide_b4ha = measure_B.Switch_f0o4owld -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_oy;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvgc[
      0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g3;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_b;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1h;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvcp =
      *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1h)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2 =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2 =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1h)
      *VDD_in = 0;
  }

  rtb_Divide_b4ha = (rtb_Divide_b4ha -
                     ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvcp
                       * rtb_Subtract3_lri) +
                      (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2
                       * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  rtb_TrigonometricFunction_ix = rt_atan2d_snf(rtb_Divide_b4h, rtb_Divide_b4ha);
  rtb_Add_n = rtb_TrigonometricFunction_ix + rtb_Sum;
  if (rtb_LogicalOperator1_pvh3) {
    measure_B.Switch6_j = rtb_Switch4;
  } else {
    rtb_Gain_pj = rtb_Add_n - rtb_Gain_pj;
    if (rtb_Gain_pj < measure_P.Constant_Value_i2j) {
      rtb_Gain_pj += measure_P.Bias1_Bias_i2;
    } else {
      if (rtb_Gain_pj > measure_P.Constant_Value_i2) {
        rtb_Gain_pj += measure_P.Bias_Bias_i2;
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
      measure_DWork.UnitDelay4_DSTATE_p) + measure_DWork.UnitDelay2_DSTATE_o;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_a[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_l;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldo;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_o;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_j = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_o)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_eg0) {
    measure_B.Switch_f0o4owldoy = measure_P.double_Value_ony;
  } else {
    measure_B.Switch_f0o4owldoy = (measure_B.Switch6_j +
      measure_DWork.UnitDelay4_DSTATE_jg) + measure_DWork.UnitDelay2_DSTATE_f;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_m[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_bh;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldoy;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_on;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_b = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_on)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvgcl
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g35;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch6_j;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_o;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvcp0 =
      *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_o)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2k =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2k =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_o)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator1_pvh3) {
    rtb_Ts_FFT = rtb_Switch4;
  } else {
    if (rtb_Compare_ddcrdc) {
      rtb_Gain_pj = measure_B.Switch_f0o4owldo -
        measure_B.VariableDiscreteDelaywithOneTapSfunction_j;
    } else {
      rtb_Gain_pj = measure_B.Switch_f0o4owldoy -
        measure_B.VariableDiscreteDelaywithOneTapSfunction_b;
    }

    rtb_Ts_FFT = (rtb_Gain_pj -
                  ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvcp0
                    * rtb_Switch) +
                   (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2k
                    * rtb_UnaryMinus_l))) * rtb_MathFunction1;
  }

  rtb_Bias1 = rtb_MathFunction2_d + measure_P.Bias1_Bias_o4;
  if (rtb_LogicalOperator2_npqx) {
    rtb_Gain_pj = rtb_Bias1 * rtb_Bias1;
    if (rtb_Gain_pj < measure_P.Constant_Value_cw1ksrzc22q) {
      rtb_Switch_jka = measure_P.Constant_Value_cw1ksrzc22;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_cw1ksrzc2) {
      rtb_Switch_jka = measure_P.Constant1_Value_cw1;
    } else {
      rtb_Switch_jka = rtb_Gain_pj;
    }

    if (!(rtb_Switch_jka < measure_P.Constant_Value_cw1ksrzc22ql)) {
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
      measure_DWork.UnitDelay4_DSTATE_ih) + measure_DWork.UnitDelay2_DSTATE_j;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ci[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_hh;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_b1 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_ngeqq2o = measure_P.double_Value_m0413rfkrd2;
  } else {
    measure_B.Switch_ngeqq2o = (measure_B.Divide_nq +
      measure_DWork.UnitDelay4_DSTATE_m) + measure_DWork.UnitDelay2_DSTATE_jm;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_f[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_c;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2o;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413r;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_cg = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413r)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_nqz = measure_B.Switch_ngeqq2 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_b1;
  } else {
    rtb_Divide_nqz = measure_B.Switch_ngeqq2o -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_cg;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvgclo
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g35f;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nq;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m04;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvcp0f =
      *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m04)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2kr =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2kr =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m04)
      *VDD_in = 0;
  }

  rtb_Divide_nqz = (rtb_Divide_nqz -
                    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvcp0f
                      * rtb_Subtract3_lri) +
                     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2kr
                      * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  if (rtb_Compare_enj) {
    measure_B.Switch_ngeqq2os = measure_P.double_Value_m0413rfk;
  } else {
    measure_B.Switch_ngeqq2os = (measure_B.Divide_n +
      measure_DWork.UnitDelay4_DSTATE_j5) + measure_DWork.UnitDelay2_DSTATE_c;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_g[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_d;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2os;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rf;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_g3 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rf)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_ngeqq2osh = measure_P.double_Value_m0413rfkr;
  } else {
    measure_B.Switch_ngeqq2osh = (measure_B.Divide_n +
      measure_DWork.UnitDelay4_DSTATE_dj) + measure_DWork.UnitDelay2_DSTATE_cm;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_l2[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_m;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2osh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfk;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_l = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfk)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_nqzy = measure_B.Switch_ngeqq2os -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_g3;
  } else {
    rtb_Divide_nqzy = measure_B.Switch_ngeqq2osh -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_l;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvgclom
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g35fl;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_n;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m041;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvcp0f2 =
      *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m041)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2krn =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2krn =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m041)
      *VDD_in = 0;
  }

  rtb_Divide_nqzy = (rtb_Divide_nqzy -
                     ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvcp0f2
                       * rtb_Subtract3_lri) +
                      (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2krn
                       * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  rtb_TrigonometricFunction_ixv = rt_atan2d_snf(rtb_Divide_nqz, rtb_Divide_nqzy);
  rtb_Add_gl = rtb_TrigonometricFunction_ixv + rtb_Sum;
  if (rtb_Compare_jsl) {
    measure_B.Switch6_m = rtb_Switch4;
  } else {
    rtb_Gain_pj = rtb_Add_gl - rtb_Gain_pj;
    if (rtb_Gain_pj < measure_P.Constant_Value_org) {
      rtb_Gain_pj += measure_P.Bias1_Bias_o;
    } else {
      if (rtb_Gain_pj > measure_P.Constant_Value_or) {
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
      measure_DWork.UnitDelay4_DSTATE_l) + measure_DWork.UnitDelay2_DSTATE_p;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ii[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_i;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_a;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_b4 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_a)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_eg0) {
    measure_B.Switch_ngeqq2oshhr = measure_P.double_Value_aov;
  } else {
    measure_B.Switch_ngeqq2oshhr = (measure_B.Switch6_m +
      measure_DWork.UnitDelay4_DSTATE_h) + measure_DWork.UnitDelay2_DSTATE_bf;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_id[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ep;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshhr;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ao;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_ag = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ao)
      *VDD_in = 0;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvgclom3
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g35flg;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch6_m;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhyr;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_a;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvcp0f2x =
      *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_a)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2krnd =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2krnd =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_a)
      *VDD_in = 0;
  }

  if (!rtb_Compare_jsl) {
    if (rtb_Compare_ddcrdc) {
      rtb_Gain_pj = measure_B.Switch_ngeqq2oshh -
        measure_B.VariableDiscreteDelaywithOneTapSfunction_b4;
    } else {
      rtb_Gain_pj = measure_B.Switch_ngeqq2oshhr -
        measure_B.VariableDiscreteDelaywithOneTapSfunction_ag;
    }

    rtb_Switch4 = (rtb_Gain_pj -
                   ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_m0kftposvcp0f2x
                     * rtb_Switch) +
                    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_gpkwvfajco2krnd
                     * rtb_UnaryMinus_l))) * rtb_MathFunction1;
  }

  rtb_Bias2 = rtb_MathFunction2_d0 + measure_P.Bias2_Bias_o;
  if (rtb_LogicalOperator1) {
    rtb_Gain_pj = rtb_Bias2 * rtb_Bias2;
    if (rtb_Gain_pj < measure_P.Constant_Value_cw1ksrzc22qlb13) {
      rtb_Switch_j = measure_P.Constant_Value_cw1ksrzc22qlb1;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_cw1ksrzc22qlb) {
      rtb_Switch_j = measure_P.Constant1_Value_cw1k;
    } else {
      rtb_Switch_j = rtb_Gain_pj;
    }

    if (!(rtb_Switch_j < measure_P.Constant_Value_ee)) {
      rtb_Switch_j = 1.0 / rtb_Switch_j;
    }
  } else {
    rtb_Switch_j = measure_P.Constant2_Value_cw;
  }

  rtb_Switch_jkaja += rtb_Switch_jka;
  rtb_Switch_jkaja += rtb_Switch_j;
  if (rtb_Switch_jkaja < measure_P.Constant_Value_go) {
    rtb_Switch_jkaja = measure_P.Constant_Value_cw;
  }

  rtb_Gain_pj = (((rtb_Ts_FFT * rtb_Switch_jka) + rtb_Switch1_ie) + (rtb_Switch4
    * rtb_Switch_j)) / rtb_Switch_jkaja;
  if (rtb_Gain_pj < measure_P.Constant_Value_ku) {
    measure_B.Switch_j = measure_P.Constant_Value_cw1k;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_cw1) {
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

  rtb_Compare_o = (rtb_Switch_j > measure_P.Constant_Value_aow);
  rtb_LogicalOperator1_pvh3 = ((!rtb_Compare_o) &&
    (measure_DWork.delay1_DSTATE_k));
  if (rtb_LogicalOperator1_pvh3) {
    measure_B.Switch_ll = measure_P.double_Value_mq;
  } else {
    measure_B.Switch_ll = (measure_B.Switch_j +
      measure_DWork.UnitDelay4_DSTATE_e) + measure_DWork.UnitDelay2_DSTATE_e5;
  }

  if (measure_DWork.UnitDelay2_DSTATE_e5y < measure_P.Constant_Value_imx) {
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
  } else if (rtb_Gain_pj < measure_P.Constant_Value_ip) {
    measure_B.Switch2_d = rtb_Gain_pj;
  } else {
    measure_B.Switch2_d = rtb_Gain_pj + measure_P.Bias_Bias_mq;
  }

  {
    measure_B.SFunction_j = (int32_T)measure_B.Switch2_d;
  }

  if (measure_B.SFunction_j < measure_P.Constant_Value_o2h) {
    measure_B.Switch2_dmf4 = measure_P.Constant_Value_lj;
  } else if (measure_B.SFunction_j > measure_P.Constant_Value_d2) {
    measure_B.Switch2_dmf4 = measure_P.Constant3_Value_m;
  } else {
    measure_B.Switch2_dmf4 = measure_B.SFunction_j;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_px[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_gx;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ll;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mq;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_e = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mq)
      *VDD_in = 0;
  }

  rtb_LogicalOperator_eg0 = (rtb_Compare_o && (measure_DWork.delay_DSTATE_j));
  if (rtb_LogicalOperator_eg0) {
    measure_B.Switch_lli = measure_P.double_Value_mqc;
  } else {
    measure_B.Switch_lli = (measure_B.Switch_j +
      measure_DWork.UnitDelay4_DSTATE_ed) + measure_DWork.UnitDelay2_DSTATE_e5yc;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bd[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_mn;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lli;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mqc;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hh = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mqc)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Switch_jka = measure_B.Switch_ll -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_e;
  } else {
    rtb_Switch_jka = measure_B.Switch_lli -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hh;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_a[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_i;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Switch_j;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mq;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_o = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mq)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_o = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_o = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mq)
      *VDD_in = 0;
  }

  rtb_Switch_jkaja = ((real_T)measure_B.Switch2_dmf4) - rtb_Gain_pj;
  rtb_MathFunction_pl = rtb_Switch_jkaja * rtb_Switch_jkaja;
  rtb_Switch_jkaja = (measure_P.Gain1_Gain_mq * rtb_Switch_jkaja) -
    rtb_MathFunction_pl;
  rtb_Switch_j = (1.0 / rtb_Switch_j) * measure_P.Gain_Gain_mqc;
  rtb_Switch_jka = (rtb_Switch_jka -
                    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_o *
                      rtb_Switch_jkaja) +
                     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_o *
                      rtb_MathFunction_pl))) * rtb_Switch_j;
  measure_B.ACripple1stestimate_n = measure_B.Switch_j - rtb_Switch_jka;
  if (measure_B.ACripple1stestimate_n < measure_P.Constant_Value_ne) {
    rtb_Divide_nfu = -measure_B.ACripple1stestimate_n;
  } else {
    rtb_Divide_nfu = measure_B.ACripple1stestimate_n;
  }

  if (rtb_Divide_nfu > (measure_P.Gain_Gain_jo * measure_P.Constant2_Value_h)) {
    rtb_Switch_lli5ykm = measure_P.int32_Value_m;
  } else {
    rtb_Switch_lli5ykm = measure_DWork.UnitDelay_DSTATE_ot -
      measure_P.FixPtConstant_Value_m;
  }

  rtb_Compare_ky = (rtb_Switch_lli5ykm > measure_P.Constant_Value_jg);
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

  rtb_Switch6_idx = ((rtb_LogicalOperator12 || rtb_UnitDelay4_dq) ||
                     rtb_LogicalOperator1);
  if (rtb_Switch6_idx) {
    rtb_Divide_nfu = rtb_Switch_k;
  } else {
    rtb_Divide_nfu = measure_P.Constant1_Value_b;
  }

  measure_Y.Frequency = rtb_Divide_nfu;
  measure_Y.FrequencyValid = rtb_Switch6_idx;
  rtb_Switch_jka = measure_P.Gain3_Gain * measure_P.Constant1_Value_m2;
  rtb_Sum1_dat = (rtb_Divide_h * rtb_Divide_h) + (rtb_Divide_hh * rtb_Divide_hh);
  rtb_Sum1_dat = (rtb_Sum1_dat < 0.0) ? (-std::sqrt(std::abs(rtb_Sum1_dat))) :
    std::sqrt(rtb_Sum1_dat);
  rtb_Divide_la = rtb_Switch_jka * rtb_Sum1_dat;
  rtb_Switch = (rtb_Divide_b4ha * rtb_Divide_b4ha) + (rtb_Divide_b4h *
    rtb_Divide_b4h);
  rtb_Switch = (rtb_Switch < 0.0) ? (-std::sqrt(std::abs(rtb_Switch))) : std::
    sqrt(rtb_Switch);
  rtb_Divide_i = rtb_Switch_jka * rtb_Switch;
  rtb_MathFunction1 = (rtb_Divide_nqzy * rtb_Divide_nqzy) + (rtb_Divide_nqz *
    rtb_Divide_nqz);
  rtb_MathFunction1 = (rtb_MathFunction1 < 0.0) ? (-std::sqrt(std::abs
    (rtb_MathFunction1))) : std::sqrt(rtb_MathFunction1);
  rtb_Divide_o1 = rtb_Switch_jka * rtb_MathFunction1;
  measure_Y.VoltageFundMagVoltsRMS3[0] = rtb_Divide_la;
  measure_Y.VoltageFundMagVoltsRMS3[1] = rtb_Divide_i;
  measure_Y.VoltageFundMagVoltsRMS3[2] = rtb_Divide_o1;
  measure_Y.VoltageFundPhaseRelPhiCorr3[0] = rtb_TrigonometricFunction_i;
  measure_Y.VoltageFundPhaseRelPhiCorr3[1] = rtb_TrigonometricFunction_ix;
  measure_Y.VoltageFundPhaseRelPhiCorr3[2] = rtb_TrigonometricFunction_ixv;
  rtb_SumofElements1 = measure_P.ScaleRMSoutputsto1pu_Gain * rtb_Sum1_lle;
  measure_B.MathFunction = rtb_SumofElements1 * rtb_SumofElements1;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_lv2aps4ne = measure_P.double_Value_dsc5ttdhqkxi;
  } else {
    measure_B.Switch_lv2aps4ne = (measure_B.MathFunction +
      measure_DWork.UnitDelay4_DSTATE_mm) + measure_DWork.UnitDelay2_DSTATE_hi;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_h[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_bf;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4ne;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhq;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_m = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhq)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_lv2aps4ney = measure_P.double_Value_dsc5ttdhqkxiz;
  } else {
    measure_B.Switch_lv2aps4ney = (measure_B.MathFunction +
      measure_DWork.UnitDelay4_DSTATE_pb) + measure_DWork.UnitDelay2_DSTATE_iy;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bo[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_c0;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4ney;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhqk;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_of = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhqk)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_SumofElements1 = measure_B.Switch_lv2aps4ne -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_m;
  } else {
    rtb_SumofElements1 = measure_B.Switch_lv2aps4ney -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_of;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_o[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_h;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5t;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_d = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5t)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_d = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_d = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5t)
      *VDD_in = 0;
  }

  rtb_SumofElements1 = (rtb_SumofElements1 -
                        ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_d
    * rtb_Subtract3_lr) +
    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_d *
     rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  measure_B.MathFunction1 = (rtb_SumofElements1 < 0.0) ? (-std::sqrt(std::abs
    (rtb_SumofElements1))) : std::sqrt(rtb_SumofElements1);
  if (rtb_Compare_enj) {
    measure_B.Switch_lv2aps4neyb = measure_P.double_Value_ds;
  } else {
    measure_B.Switch_lv2aps4neyb = (measure_B.MathFunction1 +
      measure_DWork.UnitDelay4_DSTATE_md) + measure_DWork.UnitDelay2_DSTATE_c0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_im[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_gm;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4neyb;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhqkx;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_bb = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhqkx)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_lv2aps4neybf = measure_P.double_Value_dsc;
  } else {
    measure_B.Switch_lv2aps4neybf = (measure_B.MathFunction1 +
      measure_DWork.UnitDelay4_DSTATE_f) + measure_DWork.UnitDelay2_DSTATE_cq;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_hs[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_p;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lv2aps4neybf;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhqkxi;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_jo = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhqkxi)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_SumofElements1 = measure_B.Switch_lv2aps4neyb -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_bb;
  } else {
    rtb_SumofElements1 = measure_B.Switch_lv2aps4neybf -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_jo;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_pe[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_m;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5tt;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_n = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5tt)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_c = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_c = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5tt)
      *VDD_in = 0;
  }

  rtb_SumofElements1 = (rtb_SumofElements1 -
                        ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_n
    * rtb_Subtract3_lri) +
    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_c *
     rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  rtb_ComplextoRealImag_o2_l = measure_P.ScaleRMSoutputsto1pu_Gain_d *
    rtb_Sum1_p5;
  measure_B.MathFunction_j = rtb_ComplextoRealImag_o2_l *
    rtb_ComplextoRealImag_o2_l;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_f0o4owldoyu = measure_P.double_Value_d1m1hiqruqxi;
  } else {
    measure_B.Switch_f0o4owldoyu = (measure_B.MathFunction_j +
      measure_DWork.UnitDelay4_DSTATE_ps) + measure_DWork.UnitDelay2_DSTATE_d;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_n[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_dt;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldoyu;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruq;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_ch = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruq)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_f0o4owldoyup = measure_P.double_Value_d1m1hiqruqxix;
  } else {
    measure_B.Switch_f0o4owldoyup = (measure_B.MathFunction_j +
      measure_DWork.UnitDelay4_DSTATE_k) + measure_DWork.UnitDelay2_DSTATE_o3;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_d[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_pt;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldoyup;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruqx;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_jo4 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruqx)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_ComplextoRealImag_o2_l = measure_B.Switch_f0o4owldoyu -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_ch;
  } else {
    rtb_ComplextoRealImag_o2_l = measure_B.Switch_f0o4owldoyup -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_jo4;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_j[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_k;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_j;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1hi;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_i = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1hi)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_e = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_e = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1hi)
      *VDD_in = 0;
  }

  rtb_ComplextoRealImag_o2_l = (rtb_ComplextoRealImag_o2_l -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_i *
      rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_e *
      rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  measure_B.MathFunction1_b = (rtb_ComplextoRealImag_o2_l < 0.0) ? (-std::sqrt
    (std::abs(rtb_ComplextoRealImag_o2_l))) : std::sqrt
    (rtb_ComplextoRealImag_o2_l);
  if (rtb_Compare_enj) {
    measure_B.Switch_f0o4owldoyupv = measure_P.double_Value_d1;
  } else {
    measure_B.Switch_f0o4owldoyupv = (measure_B.MathFunction1_b +
      measure_DWork.UnitDelay4_DSTATE_mw) + measure_DWork.UnitDelay2_DSTATE_d1;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_em[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_pv;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldoyupv;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruqxi;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_gl = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruqxi)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_f0o4owldoyupv1 = measure_P.double_Value_d1m;
  } else {
    measure_B.Switch_f0o4owldoyupv1 = (measure_B.MathFunction1_b +
      measure_DWork.UnitDelay4_DSTATE_jz) + measure_DWork.UnitDelay2_DSTATE_l;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_iz[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_eu;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_f0o4owldoyupv1;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruqxix;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_gj = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruqxix)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_ComplextoRealImag_o2_l = measure_B.Switch_f0o4owldoyupv -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_gl;
  } else {
    rtb_ComplextoRealImag_o2_l = measure_B.Switch_f0o4owldoyupv1 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_gj;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_js[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_ka;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_b;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1hiq;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_l = *Out_ptr;
    if (VDD_out ==
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1hiq)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_k = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_k = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1hiq)
      *VDD_in = 0;
  }

  rtb_ComplextoRealImag_o2_l = (rtb_ComplextoRealImag_o2_l -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_l *
      rtb_Subtract3_lri) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_k *
      rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  rtb_OutputWatts = measure_P.ScaleRMSoutputsto1pu_Gain_m * rtb_Sum1_pz;
  measure_B.MathFunction_jy = rtb_OutputWatts * rtb_OutputWatts;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_ngeqq2oshhr5 = measure_P.double_Value_m0413rfkrd2o;
  } else {
    measure_B.Switch_ngeqq2oshhr5 = (measure_B.MathFunction_jy +
      measure_DWork.UnitDelay4_DSTATE_hx) + measure_DWork.UnitDelay2_DSTATE_k0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ih[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_a;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshhr5;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkr;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hl = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkr)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_ngeqq2oshhr5r = measure_P.double_Value_m0413rfkrd2oa;
  } else {
    measure_B.Switch_ngeqq2oshhr5r = (measure_B.MathFunction_jy +
      measure_DWork.UnitDelay4_DSTATE_p4) + measure_DWork.UnitDelay2_DSTATE_lz;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ej[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ls;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshhr5r;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkrd;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_a4 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkrd)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_OutputWatts = measure_B.Switch_ngeqq2oshhr5 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hl;
  } else {
    rtb_OutputWatts = measure_B.Switch_ngeqq2oshhr5r -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_a4;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_l[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_iy;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_jy;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0413;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_d4 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0413)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_dh = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_dh = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0413)
      *VDD_in = 0;
  }

  rtb_OutputWatts = (rtb_OutputWatts -
                     ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_d4
                       * rtb_Subtract3_lr) +
                      (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_dh
                       * rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  measure_B.MathFunction1_bx = (rtb_OutputWatts < 0.0) ? (-std::sqrt(std::abs
    (rtb_OutputWatts))) : std::sqrt(rtb_OutputWatts);
  if (rtb_Compare_enj) {
    measure_B.Switch_ngeqq2oshhr5rh = measure_P.double_Value_m0;
  } else {
    measure_B.Switch_ngeqq2oshhr5rh = (measure_B.MathFunction1_bx +
      measure_DWork.UnitDelay4_DSTATE_b) + measure_DWork.UnitDelay2_DSTATE_ls;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_gs[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_bx;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshhr5rh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkrd2;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_k = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkrd2)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_ngeqq2oshhr5rhh = measure_P.double_Value_m04;
  } else {
    measure_B.Switch_ngeqq2oshhr5rhh = (measure_B.MathFunction1_bx +
      measure_DWork.UnitDelay4_DSTATE_ay) + measure_DWork.UnitDelay2_DSTATE_a3;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ne[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_mo;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ngeqq2oshhr5rhh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkrd2o;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_ab = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkrd2o)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_OutputWatts = measure_B.Switch_ngeqq2oshhr5rh -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_k;
  } else {
    rtb_OutputWatts = measure_B.Switch_ngeqq2oshhr5rhh -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_ab;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_pg[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_e;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_bx;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0413r;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_jz = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0413r)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_i = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_i = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0413r)
      *VDD_in = 0;
  }

  rtb_OutputWatts = (rtb_OutputWatts -
                     ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_jz
                       * rtb_Subtract3_lri) +
                      (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_i *
                       rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  measure_Y.VoltageAllHarmonicMagPuRMS3[0] = rtb_SumofElements1;
  measure_Y.VoltageAllHarmonicMagPuRMS3[1] = rtb_ComplextoRealImag_o2_l;
  measure_Y.VoltageAllHarmonicMagPuRMS3[2] = rtb_OutputWatts;
  rtb_SumofElements1 = (rtb_SumofElements1 * rtb_SumofElements1) - (rtb_Sum1_dat
    * rtb_Sum1_dat);
  if (rtb_SumofElements1 < measure_P.Constant_Value_dsc5ttd) {
    rtb_SumofElements1 = measure_P.Constant_Value_ds;
  }

  if (rtb_Sum1_dat < measure_P.Constant_Value_dsc5ttdh) {
    rtb_Sum1_dat = measure_P.Constant_Value_dsc;
  }

  rtb_SumofElements1 = (((rtb_SumofElements1 < 0.0) ? (-std::sqrt(std::abs
    (rtb_SumofElements1))) : std::sqrt(rtb_SumofElements1)) / rtb_Sum1_dat) *
    measure_P.Gain_Gain_ds;
  if (rtb_SumofElements1 > measure_P.Constant_Value_dsc5ttdhq) {
    rtb_SumofElements1 = measure_P.Constant_Value_dsc5;
  }

  rtb_ComplextoRealImag_o2_l = (rtb_ComplextoRealImag_o2_l *
    rtb_ComplextoRealImag_o2_l) - (rtb_Switch * rtb_Switch);
  if (rtb_ComplextoRealImag_o2_l < measure_P.Constant_Value_d1m1hiq) {
    rtb_ComplextoRealImag_o2_l = measure_P.Constant_Value_d1;
  }

  if (rtb_Switch < measure_P.Constant_Value_d1m1hiqr) {
    rtb_Switch = measure_P.Constant_Value_d1m;
  }

  rtb_ComplextoRealImag_o2_l = (((rtb_ComplextoRealImag_o2_l < 0.0) ? (-std::
    sqrt(std::abs(rtb_ComplextoRealImag_o2_l))) : std::sqrt
    (rtb_ComplextoRealImag_o2_l)) / rtb_Switch) * measure_P.Gain_Gain_d1m;
  if (rtb_ComplextoRealImag_o2_l > measure_P.Constant_Value_d1m1hiqru) {
    rtb_ComplextoRealImag_o2_l = measure_P.Constant_Value_d1m1;
  }

  rtb_OutputWatts = (rtb_OutputWatts * rtb_OutputWatts) - (rtb_MathFunction1 *
    rtb_MathFunction1);
  if (rtb_OutputWatts < measure_P.Constant_Value_m0413rf) {
    rtb_OutputWatts = measure_P.Constant_Value_m0;
  }

  if (rtb_MathFunction1 < measure_P.Constant_Value_m0413rfk) {
    rtb_MathFunction1 = measure_P.Constant_Value_m04;
  }

  rtb_OutputWatts = (((rtb_OutputWatts < 0.0) ? (-std::sqrt(std::abs
    (rtb_OutputWatts))) : std::sqrt(rtb_OutputWatts)) / rtb_MathFunction1) *
    measure_P.Gain_Gain_m04;
  if (rtb_OutputWatts > measure_P.Constant_Value_m0413rfkr) {
    rtb_OutputWatts = measure_P.Constant_Value_m041;
  }

  measure_Y.VoltageTHDPercent3[0] = rtb_SumofElements1;
  measure_Y.VoltageTHDPercent3[1] = rtb_ComplextoRealImag_o2_l;
  measure_Y.VoltageTHDPercent3[2] = rtb_OutputWatts;
  rtb_VpuIpktoVrmsIrms_re = ((((measure_P.Gain5_Gain_h[0].re * rtb_Divide_h) -
    (measure_P.Gain5_Gain_h[0].im * rtb_Divide_hh)) + ((measure_P.Gain5_Gain_h[1]
    .re * rtb_Divide_b4ha) - (measure_P.Gain5_Gain_h[1].im * rtb_Divide_b4h))) +
                             ((measure_P.Gain5_Gain_h[2].re * rtb_Divide_nqzy) -
                              (measure_P.Gain5_Gain_h[2].im * rtb_Divide_nqz))) *
    measure_P.Gain6_Gain;
  rtb_VpuIpktoVrmsIrms_im = ((((measure_P.Gain5_Gain_h[0].re * rtb_Divide_hh) +
                               (measure_P.Gain5_Gain_h[0].im * rtb_Divide_h)) +
                              ((measure_P.Gain5_Gain_h[1].re * rtb_Divide_b4h) +
                               (measure_P.Gain5_Gain_h[1].im * rtb_Divide_b4ha)))
    + ((measure_P.Gain5_Gain_h[2].re * rtb_Divide_nqz) +
       (measure_P.Gain5_Gain_h[2].im * rtb_Divide_nqzy))) * measure_P.Gain6_Gain;
  rtb_OutputWatts = (rtb_VpuIpktoVrmsIrms_re * rtb_VpuIpktoVrmsIrms_re) +
    (rtb_VpuIpktoVrmsIrms_im * rtb_VpuIpktoVrmsIrms_im);
  rtb_VpuIpktoVrmsIrms_re = ((((measure_P.Gain2_Gain_h1[0].re * rtb_Divide_h) -
                               (measure_P.Gain2_Gain_h1[0].im * rtb_Divide_hh))
    + ((measure_P.Gain2_Gain_h1[1].re * rtb_Divide_b4ha) -
       (measure_P.Gain2_Gain_h1[1].im * rtb_Divide_b4h))) +
    ((measure_P.Gain2_Gain_h1[2].re * rtb_Divide_nqzy) -
     (measure_P.Gain2_Gain_h1[2].im * rtb_Divide_nqz))) * measure_P.Gain4_Gain;
  rtb_VpuIpktoVrmsIrms_im = ((((measure_P.Gain2_Gain_h1[0].re * rtb_Divide_hh) +
                               (measure_P.Gain2_Gain_h1[0].im * rtb_Divide_h)) +
                              ((measure_P.Gain2_Gain_h1[1].re * rtb_Divide_b4h)
    + (measure_P.Gain2_Gain_h1[1].im * rtb_Divide_b4ha))) +
    ((measure_P.Gain2_Gain_h1[2].re * rtb_Divide_nqz) +
     (measure_P.Gain2_Gain_h1[2].im * rtb_Divide_nqzy))) * measure_P.Gain4_Gain;
  rtb_MathFunction1 = (rtb_VpuIpktoVrmsIrms_re * rtb_VpuIpktoVrmsIrms_re) +
    (rtb_VpuIpktoVrmsIrms_im * rtb_VpuIpktoVrmsIrms_im);
  rtb_MathFunction1 = (rtb_MathFunction1 < 0.0) ? (-std::sqrt(std::abs
    (rtb_MathFunction1))) : std::sqrt(rtb_MathFunction1);
  if (rtb_MathFunction1 < measure_P.Constant_Value_h1r) {
    rtb_Gain6_re = measure_P.Constant_Value_h;
  } else {
    rtb_Gain6_re = rtb_MathFunction1;
  }

  measure_Y.VoltageUnbalancePercent = (((rtb_OutputWatts < 0.0) ? (-std::sqrt
    (std::abs(rtb_OutputWatts))) : std::sqrt(rtb_OutputWatts)) / rtb_Gain6_re) *
    measure_P.Gain3_Gain_h;
  measure_Y.VoltagePosSeqMagPu = rtb_MathFunction1;
  rtb_Gain_pj = (((measure_P.Gain_Gain_p * rtb_Divide_nfu) * rtb_Divide_cv) +
                 rtb_Sum) + rt_atan2d_snf(rtb_VpuIpktoVrmsIrms_im,
    rtb_VpuIpktoVrmsIrms_re);
  if (rtb_Gain_pj < measure_P.Constant_Value_by) {
    rtb_Gain_pj += measure_P.Bias1_Bias_i;
  } else {
    if (rtb_Gain_pj > measure_P.Constant_Value_e2) {
      rtb_Gain_pj += measure_P.Bias_Bias_c;
    }
  }

  if (rtb_Gain_pj < measure_P.Constant_Value_k3) {
    measure_Y.VoltagePosSeqPhaseRad = rtb_Gain_pj + measure_P.Bias1_Bias_a;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_c) {
    measure_Y.VoltagePosSeqPhaseRad = rtb_Gain_pj + measure_P.Bias_Bias_b;
  } else {
    measure_Y.VoltagePosSeqPhaseRad = rtb_Gain_pj;
  }

  rtb_Gain6_re = ((rtb_Divide_h + rtb_Divide_b4ha) + rtb_Divide_nqzy) *
    measure_P.Gain7_Gain;
  rtb_VpuIpktoVrmsIrms_re = ((rtb_Divide_hh + rtb_Divide_b4h) + rtb_Divide_nqz) *
    measure_P.Gain7_Gain;
  rtb_OutputWatts = (rtb_Gain6_re * rtb_Gain6_re) + (rtb_VpuIpktoVrmsIrms_re *
    rtb_VpuIpktoVrmsIrms_re);
  measure_Y.VoltageZeroSeqMagPu = (rtb_OutputWatts < 0.0) ? (-std::sqrt(std::abs
    (rtb_OutputWatts))) : std::sqrt(rtb_OutputWatts);
  rtb_UnitDelay1_o = measure_DWork.UnitDelay1_DSTATE_f;
  rtb_OutputWatts = (measure_P.Gain_Gain_en * rtb_Add1_f_idx) +
    measure_P.Bias_Bias_n;
  rtb_OutputWatts = ((((measure_U.IabcAmps[0] -
                        measure_DWork.UnitDelay2_DSTATE_mk) *
                       measure_P.Gain_Gain_hf) * rtb_OutputWatts) +
                     measure_DWork.UnitDelay1_DSTATE_f) +
    ((((measure_DWork.UnitDelay2_DSTATE_mk + measure_U.IabcAmps[0]) *
       measure_P.Gain1_Gain_h) - measure_DWork.UnitDelay1_DSTATE_f) *
     (rtb_OutputWatts * rtb_OutputWatts));
  measure_B.Product_j[0] = (rtb_OutputWatts * rtb_UnaryMinus_o) * rtb_Divide_nf;
  measure_B.Product_j[1] = (rtb_OutputWatts * rtb_Sum2_i) * rtb_Divide_nf;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_jp = measure_P.double_Value_e1r;
  } else {
    measure_B.Switch_jp = (measure_B.Product_j[0] +
      measure_DWork.UnitDelay4_DSTATE_do) + measure_DWork.UnitDelay2_DSTATE_kx;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fx[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ln;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jp;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hg = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_jpt = measure_P.double_Value_e1ro;
  } else {
    measure_B.Switch_jpt = (measure_B.Product_j[0] +
      measure_DWork.UnitDelay4_DSTATE_dot) + measure_DWork.UnitDelay2_DSTATE_kxh;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxf[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jpt;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgf = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_ComplextoRealImag_o2_l = measure_B.Switch_jp -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hg;
  } else {
    rtb_ComplextoRealImag_o2_l = measure_B.Switch_jpt -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgf;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_c[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_j[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_b = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_fr = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_fr = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e)
      *VDD_in = 0;
  }

  measure_B.Divide_nf = (rtb_ComplextoRealImag_o2_l -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_b *
      rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_fr *
      rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_jptu = measure_P.double_Value_e1rorg3;
  } else {
    measure_B.Switch_jptu = (measure_B.Divide_nf +
      measure_DWork.UnitDelay4_DSTATE_dotl) +
      measure_DWork.UnitDelay2_DSTATE_kxh1;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfz[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptu;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1r;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfm = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1r)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jptuz = measure_P.double_Value_e1rorg3e;
  } else {
    measure_B.Switch_jptuz = (measure_B.Divide_nf +
      measure_DWork.UnitDelay4_DSTATE_dotln) +
      measure_DWork.UnitDelay2_DSTATE_kxh1d;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzv[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1v;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuz;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1ro;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmt =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1ro)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_ComplextoRealImag_o2_l = measure_B.Switch_jptu -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfm;
  } else {
    rtb_ComplextoRealImag_o2_l = measure_B.Switch_jptuz -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmt;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nf;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1)
      *VDD_in = 0;
  }

  rtb_ComplextoRealImag_o2_l = (rtb_ComplextoRealImag_o2_l -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br *
      rtb_Subtract3_lri) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq *
      rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_jptuzr = measure_P.double_Value_e1ror;
  } else {
    measure_B.Switch_jptuzr = (measure_B.Product_j[1] +
      measure_DWork.UnitDelay4_DSTATE_dotlnl) +
      measure_DWork.UnitDelay2_DSTATE_kxh1dd;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvg[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vh;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzr;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1ror;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtb =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1ror)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_jptuzrl = measure_P.double_Value_e1rorg;
  } else {
    measure_B.Switch_jptuzrl = (measure_B.Product_j[1] +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgo[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhz;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrl;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtba =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_SumofElements1 = measure_B.Switch_jptuzr -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtb;
  } else {
    rtb_SumofElements1 = measure_B.Switch_jptuzrl -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtba;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3m;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_j[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1r;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1r)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1r)
      *VDD_in = 0;
  }

  measure_B.Divide_nfu = (rtb_SumofElements1 -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4 *
      rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2 *
      rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_jptuzrlj = measure_P.double_Value_e1rorg3e1;
  } else {
    measure_B.Switch_jptuzrlj = (measure_B.Divide_nfu +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb3;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgoh[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhza;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrlj;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jptuzrljf = measure_P.double_Value_e1rorg3e1h;
  } else {
    measure_B.Switch_jptuzrljf = (measure_B.Divide_nfu +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0w) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohd[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5 =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_SumofElements1 = measure_B.Switch_jptuzrlj -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat;
  } else {
    rtb_SumofElements1 = measure_B.Switch_jptuzrljf -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3y[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3my;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nfu;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1ro;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1ro)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2e = VDD_buffer
        [0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2e = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1ro)
      *VDD_in = 0;
  }

  rtb_SumofElements1 = (rtb_SumofElements1 -
                        ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j
    * rtb_Subtract3_lri) +
    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2e *
     rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  rtb_MathFunction1 = (rtb_ComplextoRealImag_o2_l * rtb_ComplextoRealImag_o2_l)
    + (rtb_SumofElements1 * rtb_SumofElements1);
  rtb_MathFunction1 = (rtb_MathFunction1 < 0.0) ? (-std::sqrt(std::abs
    (rtb_MathFunction1))) : std::sqrt(rtb_MathFunction1);
  rtb_Switch = measure_P.IpktoIrms_Gain * rtb_MathFunction1;
  rtb_UnitDelay1_f = measure_DWork.UnitDelay1_DSTATE_d;
  rtb_Sum1_dat = (measure_P.Gain_Gain_ad * rtb_Add1_f_idx_0) +
    measure_P.Bias_Bias_n2;
  rtb_Sum1_dat = ((((measure_U.IabcAmps[1] - measure_DWork.UnitDelay2_DSTATE_dz)
                    * measure_P.Gain_Gain_c) * rtb_Sum1_dat) +
                  measure_DWork.UnitDelay1_DSTATE_d) +
    ((((measure_DWork.UnitDelay2_DSTATE_dz + measure_U.IabcAmps[1]) *
       measure_P.Gain1_Gain_c) - measure_DWork.UnitDelay1_DSTATE_d) *
     (rtb_Sum1_dat * rtb_Sum1_dat));
  measure_B.Product_jq[0] = (rtb_Sum1_dat * rtb_UnaryMinus_o) * rtb_Divide_nf;
  measure_B.Product_jq[1] = (rtb_Sum1_dat * rtb_Sum2_i) * rtb_Divide_nf;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_jptuzrljf0 = measure_P.double_Value_e1rorg3e1hupmn0;
  } else {
    measure_B.Switch_jptuzrljf0 = (measure_B.Product_jq[0] +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0wv) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33g;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdy[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf0;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5l =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_jptuzrljf05 = measure_P.double_Value_cb;
  } else {
    measure_B.Switch_jptuzrljf05 = (measure_B.Product_jq[0] +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvp) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gq;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdyf
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0h;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf05;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1h;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5ln =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1h)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Divide_nfu = measure_B.Switch_jptuzrljf0 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5l;
  } else {
    rtb_Divide_nfu = measure_B.Switch_jptuzrljf05 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5ln;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3yn[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_jq[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1ror;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j5 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1ror)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ej =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ej = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1ror)
      *VDD_in = 0;
  }

  measure_B.Divide_nfun = (rtb_Divide_nfu -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j5 *
      rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ej *
      rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_jptuzrljf055 = measure_P.double_Value_kz;
  } else {
    measure_B.Switch_jptuzrljf055 = (measure_B.Divide_nfun +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpy) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqp;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdyfs[
      0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0hw;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf055;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hu;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5ln1 =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hu)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jptuzrljf055w = measure_P.double_Value_b;
  } else {
    measure_B.Switch_jptuzrljf055w = (measure_B.Divide_nfun +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpya) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpf;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdyfso
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0hw1;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf055w;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hup;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5ln1z =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hup)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_nfu = measure_B.Switch_jptuzrljf055 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5ln1;
  } else {
    rtb_Divide_nfu = measure_B.Switch_jptuzrljf055w -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5ln1z;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynu[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nfun;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejb =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejb = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg)
      *VDD_in = 0;
  }

  rtb_Divide_nfu = (rtb_Divide_nfu -
                    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50
                      * rtb_Subtract3_lri) +
                     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejb
                      * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_jptuzrljf055wg = measure_P.double_Value_h;
  } else {
    measure_B.Switch_jptuzrljf055wg = (measure_B.Product_jq[1] +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpyar) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpfj;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdyfsol
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0hw1b;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf055wg;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hupm;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5ln1zt =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hupm)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_jptuzrljf055wg5 = measure_P.double_Value_om;
  } else {
    measure_B.Switch_jptuzrljf055wg5 = (measure_B.Product_jq[1] +
      measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpyari) +
      measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpfjt;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdyfsolg
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0hw1bl;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jptuzrljf055wg5;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hupmn;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5ln1zta =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hupmn)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_UnaryMinus_l = measure_B.Switch_jptuzrljf055wg -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5ln1zt;
  } else {
    rtb_UnaryMinus_l = measure_B.Switch_jptuzrljf055wg5 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_hgfmtbat5ln1zta;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynuk[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1u;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_jq[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50f = *Out_ptr;
    if (VDD_out ==
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbq =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbq = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3)
      *VDD_in = 0;
  }

  measure_B.Divide_nfunb = (rtb_UnaryMinus_l -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50f *
      rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbq *
      rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_c = measure_P.double_Value_cj;
  } else {
    measure_B.Switch_c = (measure_B.Divide_nfunb +
                          measure_DWork.UnitDelay4_DSTATE_ls) +
      measure_DWork.UnitDelay2_DSTATE_n;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ab[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_j;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_c;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hupmn0;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_aj = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hupmn0)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jc = measure_P.double_Value_di;
  } else {
    measure_B.Switch_jc = (measure_B.Divide_nfunb +
      measure_DWork.UnitDelay4_DSTATE_gs) + measure_DWork.UnitDelay2_DSTATE_oz;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jec[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_go;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jc;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_c;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_bx = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_c)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_UnaryMinus_l = measure_B.Switch_c -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_aj;
  } else {
    rtb_UnaryMinus_l = measure_B.Switch_jc -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_bx;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukf[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nfunb;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fk = *Out_ptr;
    if (VDD_out ==
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqm =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqm =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e)
      *VDD_in = 0;
  }

  rtb_UnaryMinus_l = (rtb_UnaryMinus_l -
                      ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fk
                        * rtb_Subtract3_lri) +
                       (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqm
                        * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  rtb_Switch1_ie = (rtb_Divide_nfu * rtb_Divide_nfu) + (rtb_UnaryMinus_l *
    rtb_UnaryMinus_l);
  rtb_Switch1_ie = (rtb_Switch1_ie < 0.0) ? (-std::sqrt(std::abs(rtb_Switch1_ie)))
    : std::sqrt(rtb_Switch1_ie);
  rtb_Switch1_iew = measure_P.IpktoIrms_Gain_g * rtb_Switch1_ie;
  rtb_UnitDelay1_pu = measure_DWork.UnitDelay1_DSTATE_b;
  rtb_Divide_cv = (measure_P.Gain_Gain_eb * rtb_Add1_f_idx_1) +
    measure_P.Bias_Bias_ih;
  rtb_Divide_cv = ((((measure_U.IabcAmps[2] - measure_DWork.UnitDelay2_DSTATE_kb)
                     * measure_P.Gain_Gain_oc) * rtb_Divide_cv) +
                   measure_DWork.UnitDelay1_DSTATE_b) +
    ((((measure_DWork.UnitDelay2_DSTATE_kb + measure_U.IabcAmps[2]) *
       measure_P.Gain1_Gain_o) - measure_DWork.UnitDelay1_DSTATE_b) *
     (rtb_Divide_cv * rtb_Divide_cv));
  measure_B.Product_jqy[0] = (rtb_Divide_cv * rtb_UnaryMinus_o) * rtb_Divide_nf;
  measure_B.Product_jqy[1] = (rtb_Divide_cv * rtb_Sum2_i) * rtb_Divide_nf;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_i = measure_P.double_Value_m;
  } else {
    measure_B.Switch_i = (measure_B.Product_jqy[0] +
                          measure_DWork.UnitDelay4_DSTATE_hxo) +
      measure_DWork.UnitDelay2_DSTATE_eo;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_no[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_od;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_i;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_h;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_d = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_h)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_h = measure_P.double_Value_c1;
  } else {
    measure_B.Switch_h = (measure_B.Product_jqy[0] +
                          measure_DWork.UnitDelay4_DSTATE_gn) +
      measure_DWork.UnitDelay2_DSTATE_pl;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ni[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_b1;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_h;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_om;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_p = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_om)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Divide_nf = measure_B.Switch_i -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_d;
  } else {
    rtb_Divide_nf = measure_B.Switch_h -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_p;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfc[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz5;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_jqy[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkf = *Out_ptr;
    if (VDD_out ==
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmj =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmj =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1)
      *VDD_in = 0;
  }

  measure_B.Divide_nfunba = (rtb_Divide_nf -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkf *
      rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmj *
      rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_e = measure_P.double_Value_hu;
  } else {
    measure_B.Switch_e = (measure_B.Divide_nfunba +
                          measure_DWork.UnitDelay4_DSTATE_pz) +
      measure_DWork.UnitDelay2_DSTATE_ck;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b3[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ir;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_e;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_k;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_pr = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_k)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jce = measure_P.double_Value_bg;
  } else {
    measure_B.Switch_jce = (measure_B.Divide_nfunba +
      measure_DWork.UnitDelay4_DSTATE_d2) + measure_DWork.UnitDelay2_DSTATE_cs;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_i0[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_nf;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jce;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_b;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_jn = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_b)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_nf = measure_B.Switch_e -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_pr;
  } else {
    rtb_Divide_nf = measure_B.Switch_jce -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_jn;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcn
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz53;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nfunba;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1h;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfb = *Out_ptr;
    if (VDD_out ==
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1h)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjc =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjc =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1h)
      *VDD_in = 0;
  }

  rtb_Divide_nf = (rtb_Divide_nf -
                   ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfb
                     * rtb_Subtract3_lri) +
                    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjc
                     * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_el = measure_P.double_Value_ai;
  } else {
    measure_B.Switch_el = (measure_B.Product_jqy[1] +
      measure_DWork.UnitDelay4_DSTATE_mz) + measure_DWork.UnitDelay2_DSTATE_fe;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_d5[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_f;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_el;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_cj;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_ky = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_cj)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_m = measure_P.double_Value_p;
  } else {
    measure_B.Switch_m = (measure_B.Product_jqy[1] +
                          measure_DWork.UnitDelay4_DSTATE_am) +
      measure_DWork.UnitDelay2_DSTATE_cx;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_nk[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_cg;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_m;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_di;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_mj = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_di)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_UnaryMinus_o = measure_B.Switch_el -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_ky;
  } else {
    rtb_UnaryMinus_o = measure_B.Switch_m -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_mj;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcns[
      0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz53e;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Product_jqy[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hu;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfbp =
      *Out_ptr;
    if (VDD_out ==
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hu)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcp =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcp =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hu)
      *VDD_in = 0;
  }

  measure_B.Divide_nfunbaw = (rtb_UnaryMinus_o -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfbp *
      rtb_Subtract3_lr) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcp *
      rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_jx = measure_P.double_Value_ob;
  } else {
    measure_B.Switch_jx = (measure_B.Divide_nfunbaw +
      measure_DWork.UnitDelay4_DSTATE_nh) + measure_DWork.UnitDelay2_DSTATE_n1;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_le[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_cp;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jx;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_l;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_d3 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_l)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_je = measure_P.double_Value_g;
  } else {
    measure_B.Switch_je = (measure_B.Divide_nfunbaw +
      measure_DWork.UnitDelay4_DSTATE_fu) + measure_DWork.UnitDelay2_DSTATE_ko;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_pl[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ox;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_je;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ly;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_db = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ly)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_UnaryMinus_o = measure_B.Switch_jx -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_d3;
  } else {
    rtb_UnaryMinus_o = measure_B.Switch_je -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_db;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcns4
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz53er;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_nfunbaw;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hup;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfbp0 =
      *Out_ptr;
    if (VDD_out ==
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hup)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcpo =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcpo =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hup)
      *VDD_in = 0;
  }

  rtb_UnaryMinus_o = (rtb_UnaryMinus_o -
                      ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfbp0
                        * rtb_Subtract3_lri) +
                       (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcpo
                        * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  rtb_Sum2_i = (rtb_Divide_nf * rtb_Divide_nf) + (rtb_UnaryMinus_o *
    rtb_UnaryMinus_o);
  rtb_Gain_pj = (rtb_Sum2_i < 0.0) ? (-std::sqrt(std::abs(rtb_Sum2_i))) : std::
    sqrt(rtb_Sum2_i);
  rtb_Add1_f_idx_1 = measure_P.IpktoIrms_Gain_m * rtb_Gain_pj;
  rtb_Sum2_i = rt_atan2d_snf(rtb_SumofElements1, rtb_ComplextoRealImag_o2_l);
  rtb_TrigonometricFunction_hr = rt_atan2d_snf(rtb_UnaryMinus_l, rtb_Divide_nfu);
  rtb_TrigonometricFunction_hrx = rt_atan2d_snf(rtb_UnaryMinus_o, rtb_Divide_nf);
  rtb_Sum1_kv = measure_P.ScaleRMSoutputsto1pu_Gain_e * rtb_OutputWatts;
  measure_B.MathFunction_p = rtb_Sum1_kv * rtb_Sum1_kv;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_p = measure_P.double_Value_e1rorg3e1hu;
  } else {
    measure_B.Switch_p = (measure_B.MathFunction_p +
                          measure_DWork.UnitDelay4_DSTATE_m5) +
      measure_DWork.UnitDelay2_DSTATE_ef;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_e5[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_gs;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_f;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_lk = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_f)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_pi = measure_P.double_Value_e1rorg3e1hup;
  } else {
    measure_B.Switch_pi = (measure_B.MathFunction_p +
      measure_DWork.UnitDelay4_DSTATE_ee) + measure_DWork.UnitDelay2_DSTATE_mh;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_dx[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_bt;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_pi;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_hs;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_pp = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_hs)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Sum1_kv = measure_B.Switch_p -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_lk;
  } else {
    rtb_Sum1_kv = measure_B.Switch_pi -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_pp;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcns4k
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz53erg;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_p;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupm;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfbp0n =
      *Out_ptr;
    if (VDD_out ==
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupm)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcpoj =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcpoj =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupm)
      *VDD_in = 0;
  }

  rtb_Sum1_kv = (rtb_Sum1_kv -
                 ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfbp0n
                   * rtb_Subtract3_lr) +
                  (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcpoj
                   * rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  measure_B.MathFunction1_e = (rtb_Sum1_kv < 0.0) ? (-std::sqrt(std::abs
    (rtb_Sum1_kv))) : std::sqrt(rtb_Sum1_kv);
  if (rtb_Compare_enj) {
    measure_B.Switch_i0 = measure_P.double_Value_e;
  } else {
    measure_B.Switch_i0 = (measure_B.MathFunction1_e +
      measure_DWork.UnitDelay4_DSTATE_ju) + measure_DWork.UnitDelay2_DSTATE_or;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_kt[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_nyj;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_i0;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ma;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_n = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ma)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_jv = measure_P.double_Value_e1;
  } else {
    measure_B.Switch_jv = (measure_B.MathFunction1_e +
      measure_DWork.UnitDelay4_DSTATE_hz) + measure_DWork.UnitDelay2_DSTATE_lt;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_l5[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_me;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_jv;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_c1;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_ny = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_c1)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Sum1_kv = measure_B.Switch_i0 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_n;
  } else {
    rtb_Sum1_kv = measure_B.Switch_jv -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_ny;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcns4km
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz53ergf;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_e;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupmn;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfbp0na =
      *Out_ptr;
    if (VDD_out ==
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupmn)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcpojk =
        VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcpojk =
        *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupmn)
      *VDD_in = 0;
  }

  rtb_Sum1_kv = (rtb_Sum1_kv -
                 ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfbp0na
                   * rtb_Subtract3_lri) +
                  (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_frq2ejbqmjcpojk
                   * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  rtb_Sum1_kv = (rtb_Sum1_kv * rtb_Sum1_kv) - (rtb_MathFunction1 *
    rtb_MathFunction1);
  if (rtb_Sum1_kv < measure_P.Constant_Value_e1rorg3e1hu) {
    rtb_Sum1_kv = measure_P.Constant_Value_e1;
  }

  if (rtb_MathFunction1 < measure_P.Constant_Value_e1rorg3e1hup) {
    rtb_MathFunction1 = measure_P.Constant_Value_e1r;
  }

  rtb_Sum1_kv = (((rtb_Sum1_kv < 0.0) ? (-std::sqrt(std::abs(rtb_Sum1_kv))) :
                  std::sqrt(rtb_Sum1_kv)) / rtb_MathFunction1) *
    measure_P.Gain_Gain_e1;
  if (rtb_Sum1_kv > measure_P.Constant_Value_e1rorg3e1hupm) {
    rtb_Sum1_kv = measure_P.Constant_Value_e1ro;
  }

  rtb_MathFunction1 = measure_P.ScaleRMSoutputsto1pu_Gain_e1 * rtb_Sum1_dat;
  measure_B.MathFunction_pc = rtb_MathFunction1 * rtb_MathFunction1;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_k = measure_P.double_Value_li;
  } else {
    measure_B.Switch_k = (measure_B.MathFunction_pc +
                          measure_DWork.UnitDelay4_DSTATE_mb) +
      measure_DWork.UnitDelay2_DSTATE_fq;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bz[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lne;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_k;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ai;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_lp = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ai)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_eh = measure_P.double_Value_ly;
  } else {
    measure_B.Switch_eh = (measure_B.MathFunction_pc +
      measure_DWork.UnitDelay4_DSTATE_fp) + measure_DWork.UnitDelay2_DSTATE_d0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ac[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_dw;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_eh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_p;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_cx = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_p)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_MathFunction1 = measure_B.Switch_k -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_lp;
  } else {
    rtb_MathFunction1 = measure_B.Switch_eh -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_cx;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcns4kmg
      [0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_hd;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_pc;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out +=
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupmn0;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfbp0nah =
      *Out_ptr;
    if (VDD_out ==
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupmn0)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_d4 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_d4 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupmn0)
      *VDD_in = 0;
  }

  rtb_MathFunction1 = (rtb_MathFunction1 -
                       ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_br4j50fkfbp0nah
    * rtb_Subtract3_lr) +
                        (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_d4
    * rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  measure_B.MathFunction1_ew = (rtb_MathFunction1 < 0.0) ? (-std::sqrt(std::abs
    (rtb_MathFunction1))) : std::sqrt(rtb_MathFunction1);
  if (rtb_Compare_enj) {
    measure_B.Switch_o = measure_P.double_Value_e1rorg3e1hupm;
  } else {
    measure_B.Switch_o = (measure_B.MathFunction1_ew +
                          measure_DWork.UnitDelay4_DSTATE_pm) +
      measure_DWork.UnitDelay2_DSTATE_mf;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_hz[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_i0;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_o;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_hu;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_ka = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_hu)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_d = measure_P.double_Value_e1rorg3e1hupmn;
  } else {
    measure_B.Switch_d = (measure_B.MathFunction1_ew +
                          measure_DWork.UnitDelay4_DSTATE_gf) +
      measure_DWork.UnitDelay2_DSTATE_pz;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_i1[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_la;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_d;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_bg;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_pi = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_bg)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_MathFunction1 = measure_B.Switch_o -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_ka;
  } else {
    rtb_MathFunction1 = measure_B.Switch_d -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_pi;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_a1[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_d;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_ew;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_c;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_db = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_c)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_i0 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_i0 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_c)
      *VDD_in = 0;
  }

  rtb_MathFunction1 = (rtb_MathFunction1 -
                       ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_db
    * rtb_Subtract3_lri) +
                        (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_i0
    * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  rtb_MathFunction1 = (rtb_MathFunction1 * rtb_MathFunction1) - (rtb_Switch1_ie *
    rtb_Switch1_ie);
  if (rtb_MathFunction1 < measure_P.Constant_Value_e1rorg3e1hupmn) {
    rtb_MathFunction1 = measure_P.Constant_Value_e1ror;
  }

  if (rtb_Switch1_ie < measure_P.Constant_Value_e1rorg3e1hupmn0) {
    rtb_Switch1_ie = measure_P.Constant_Value_e1rorg;
  }

  rtb_Switch1_ie = (((rtb_MathFunction1 < 0.0) ? (-std::sqrt(std::abs
    (rtb_MathFunction1))) : std::sqrt(rtb_MathFunction1)) / rtb_Switch1_ie) *
    measure_P.Gain_Gain_e1r;
  if (rtb_Switch1_ie > measure_P.Constant_Value_ch) {
    rtb_Switch1_ie = measure_P.Constant_Value_e1rorg3;
  }

  rtb_MathFunction1 = measure_P.ScaleRMSoutputsto1pu_Gain_e1r * rtb_Divide_cv;
  measure_B.MathFunction_pcc = rtb_MathFunction1 * rtb_MathFunction1;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_ia = measure_P.double_Value_nx;
  } else {
    measure_B.Switch_ia = (measure_B.MathFunction_pcc +
      measure_DWork.UnitDelay4_DSTATE_hc) + measure_DWork.UnitDelay2_DSTATE_gk;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_o[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_er;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ia;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ob;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_os = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ob)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_cp = measure_P.double_Value_ec;
  } else {
    measure_B.Switch_cp = (measure_B.MathFunction_pcc +
      measure_DWork.UnitDelay4_DSTATE_gv) + measure_DWork.UnitDelay2_DSTATE_hh;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_kw[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_j3;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_cp;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_g;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_g0 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_g)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_MathFunction1 = measure_B.Switch_ia -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_os;
  } else {
    rtb_MathFunction1 = measure_B.Switch_cp -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_g0;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_g[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_p;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction_pcc;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_h;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_oq = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_h)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_b = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_b = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_h)
      *VDD_in = 0;
  }

  rtb_MathFunction1 = (rtb_MathFunction1 -
                       ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_oq
    * rtb_Subtract3_lr) +
                        (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_b
    * rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  measure_B.MathFunction1_ew0 = (rtb_MathFunction1 < 0.0) ? (-std::sqrt(std::abs
    (rtb_MathFunction1))) : std::sqrt(rtb_MathFunction1);
  if (rtb_Compare_enj) {
    measure_B.Switch_cn = measure_P.double_Value_f;
  } else {
    measure_B.Switch_cn = (measure_B.MathFunction1_ew0 +
      measure_DWork.UnitDelay4_DSTATE_g0) + measure_DWork.UnitDelay2_DSTATE_cs5;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_gc[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ky;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_cn;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_n;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_p0 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_n)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_g = measure_P.double_Value_hs;
  } else {
    measure_B.Switch_g = (measure_B.MathFunction1_ew0 +
                          measure_DWork.UnitDelay4_DSTATE_jx) +
      measure_DWork.UnitDelay2_DSTATE_fb;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_pe[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_hb;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_g;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ec;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_bp = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ec)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_MathFunction1 = measure_B.Switch_cn -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_p0;
  } else {
    rtb_MathFunction1 = measure_B.Switch_g -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_bp;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_i[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_ks;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.MathFunction1_ew0;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_om;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_d1 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_om)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_m = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_m = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_om)
      *VDD_in = 0;
  }

  rtb_MathFunction1 = (rtb_MathFunction1 -
                       ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_d1
    * rtb_Subtract3_lri) +
                        (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_m
    * rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  rtb_MathFunction1 = (rtb_MathFunction1 * rtb_MathFunction1) - (rtb_Gain_pj *
    rtb_Gain_pj);
  if (rtb_MathFunction1 < measure_P.Constant_Value_be) {
    rtb_MathFunction1 = measure_P.Constant_Value_e1rorg3e;
  }

  if (rtb_Gain_pj < measure_P.Constant_Value_ab) {
    rtb_Gain_pj = measure_P.Constant_Value_e1rorg3e1;
  }

  rtb_MathFunction1 = (((rtb_MathFunction1 < 0.0) ? (-std::sqrt(std::abs
    (rtb_MathFunction1))) : std::sqrt(rtb_MathFunction1)) / rtb_Gain_pj) *
    measure_P.Gain_Gain_e1ro;
  if (rtb_MathFunction1 > measure_P.Constant_Value_ed) {
    rtb_MathFunction1 = measure_P.Constant_Value_e1rorg3e1h;
  }

  rtb_Gain6_re = ((((measure_P.Gain5_Gain_h1[0].re * rtb_ComplextoRealImag_o2_l)
                    - (measure_P.Gain5_Gain_h1[0].im * rtb_SumofElements1)) +
                   ((measure_P.Gain5_Gain_h1[1].re * rtb_Divide_nfu) -
                    (measure_P.Gain5_Gain_h1[1].im * rtb_UnaryMinus_l))) +
                  ((measure_P.Gain5_Gain_h1[2].re * rtb_Divide_nf) -
                   (measure_P.Gain5_Gain_h1[2].im * rtb_UnaryMinus_o))) *
    measure_P.Gain6_Gain_h;
  rtb_VpuIpktoVrmsIrms_re = ((((measure_P.Gain5_Gain_h1[0].re *
    rtb_SumofElements1) + (measure_P.Gain5_Gain_h1[0].im *
    rtb_ComplextoRealImag_o2_l)) + ((measure_P.Gain5_Gain_h1[1].re *
    rtb_UnaryMinus_l) + (measure_P.Gain5_Gain_h1[1].im * rtb_Divide_nfu))) +
    ((measure_P.Gain5_Gain_h1[2].re * rtb_UnaryMinus_o) +
     (measure_P.Gain5_Gain_h1[2].im * rtb_Divide_nf))) * measure_P.Gain6_Gain_h;
  rtb_Add1_f_idx_0 = (rtb_Gain6_re * rtb_Gain6_re) + (rtb_VpuIpktoVrmsIrms_re *
    rtb_VpuIpktoVrmsIrms_re);
  rtb_VpuIpktoVrmsIrms_re = ((((measure_P.Gain2_Gain_h1r[0].re *
    rtb_ComplextoRealImag_o2_l) - (measure_P.Gain2_Gain_h1r[0].im *
    rtb_SumofElements1)) + ((measure_P.Gain2_Gain_h1r[1].re * rtb_Divide_nfu) -
                               (measure_P.Gain2_Gain_h1r[1].im *
    rtb_UnaryMinus_l))) + ((measure_P.Gain2_Gain_h1r[2].re * rtb_Divide_nf) -
    (measure_P.Gain2_Gain_h1r[2].im * rtb_UnaryMinus_o))) *
    measure_P.Gain4_Gain_h;
  rtb_VpuIpktoVrmsIrms_im = ((((measure_P.Gain2_Gain_h1r[0].re *
    rtb_SumofElements1) + (measure_P.Gain2_Gain_h1r[0].im *
    rtb_ComplextoRealImag_o2_l)) + ((measure_P.Gain2_Gain_h1r[1].re *
    rtb_UnaryMinus_l) + (measure_P.Gain2_Gain_h1r[1].im * rtb_Divide_nfu))) +
    ((measure_P.Gain2_Gain_h1r[2].re * rtb_UnaryMinus_o) +
     (measure_P.Gain2_Gain_h1r[2].im * rtb_Divide_nf))) * measure_P.Gain4_Gain_h;
  rtb_Add1_f_idx = (rtb_VpuIpktoVrmsIrms_re * rtb_VpuIpktoVrmsIrms_re) +
    (rtb_VpuIpktoVrmsIrms_im * rtb_VpuIpktoVrmsIrms_im);
  rtb_Gain_pj = (rtb_Add1_f_idx < 0.0) ? (-std::sqrt(std::abs(rtb_Add1_f_idx))) :
    std::sqrt(rtb_Add1_f_idx);
  if (rtb_Gain_pj < measure_P.Constant_Value_h1rl) {
    rtb_Gain_pj = measure_P.Constant_Value_h1;
  }

  measure_Y.Current[0] = rtb_Switch;
  measure_Y.Current[1] = rtb_Switch1_iew;
  measure_Y.Current[2] = rtb_Add1_f_idx_1;
  measure_Y.Current[3] = rtb_Sum2_i;
  measure_Y.Current[4] = rtb_TrigonometricFunction_hr;
  measure_Y.Current[5] = rtb_TrigonometricFunction_hrx;
  measure_Y.Current[6] = rtb_Sum1_kv;
  measure_Y.Current[7] = rtb_Switch1_ie;
  measure_Y.Current[8] = rtb_MathFunction1;
  measure_Y.Current[9] = (((rtb_Add1_f_idx_0 < 0.0) ? (-std::sqrt(std::abs
    (rtb_Add1_f_idx_0))) : std::sqrt(rtb_Add1_f_idx_0)) / rtb_Gain_pj) *
    measure_P.Gain3_Gain_h1;
  rtb_Divide_la *= rtb_Switch;
  rtb_Divide_i *= rtb_Switch1_iew;
  rtb_Divide_o1 *= rtb_Add1_f_idx_1;
  rtb_Add1_f_idx = (rtb_Divide_la + rtb_Divide_i) + rtb_Divide_o1;
  measure_Y.VA = rtb_Add1_f_idx;
  rtb_SumofElements1 = -rtb_SumofElements1;
  rtb_Add1_f_idx_0 = ((rtb_Divide_h * rtb_ComplextoRealImag_o2_l) -
                      (rtb_Divide_hh * rtb_SumofElements1)) *
    (measure_P.IpktoIrmsconversion_Gain * rtb_Switch_jka);
  rtb_Sum1_kv = ((rtb_Divide_h * rtb_SumofElements1) + (rtb_Divide_hh *
    rtb_ComplextoRealImag_o2_l)) * (measure_P.IpktoIrmsconversion_Gain *
    rtb_Switch_jka);
  rtb_UnaryMinus_l = -rtb_UnaryMinus_l;
  rtb_Add1_f_idx_1 = ((rtb_Divide_b4ha * rtb_Divide_nfu) - (rtb_Divide_b4h *
    rtb_UnaryMinus_l)) * (measure_P.IpktoIrmsconversion_Gain_b * rtb_Switch_jka);
  rtb_Switch1_iew = ((rtb_Divide_b4ha * rtb_UnaryMinus_l) + (rtb_Divide_b4h *
    rtb_Divide_nfu)) * (measure_P.IpktoIrmsconversion_Gain_b * rtb_Switch_jka);
  rtb_UnaryMinus_o = -rtb_UnaryMinus_o;
  rtb_Switch_jka *= measure_P.IpktoIrmsconversion_Gain_b4;
  rtb_VpuIpktoVrmsIrms_re = ((rtb_Divide_nqzy * rtb_Divide_nf) - (rtb_Divide_nqz
    * rtb_UnaryMinus_o)) * rtb_Switch_jka;
  rtb_VpuIpktoVrmsIrms_im = ((rtb_Divide_nqzy * rtb_UnaryMinus_o) +
    (rtb_Divide_nqz * rtb_Divide_nf)) * rtb_Switch_jka;
  rtb_SumofElements1 = (rtb_Add1_f_idx_0 + rtb_Add1_f_idx_1) +
    rtb_VpuIpktoVrmsIrms_re;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_kjg) {
    rtb_Add1_f_idx = measure_P.Constant_Value_k;
  }

  rtb_Gain_pj = rtb_SumofElements1 / rtb_Add1_f_idx;
  if (rtb_Gain_pj < measure_P.Constant_Value_ej) {
    rtb_Add1_f_idx = measure_P.Constant_Value_d;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_i) {
    rtb_Add1_f_idx = measure_P.Constant1_Value;
  } else {
    rtb_Add1_f_idx = rtb_Gain_pj;
  }

  measure_Y.PowerFactor = rtb_Add1_f_idx;
  measure_Y.WattsFundamental = rtb_SumofElements1;
  measure_Y.Vars = (rtb_Sum1_kv + rtb_Switch1_iew) + rtb_VpuIpktoVrmsIrms_im;
  rtb_Add1_f_idx = measure_P.Gain1_Gain_g * measure_P.Constant1_Value_m2;
  measure_B.VI[0] = (rtb_Sum1_lle * rtb_OutputWatts) * rtb_Add1_f_idx;
  measure_B.VI[1] = (rtb_Sum1_p5 * rtb_Sum1_dat) * rtb_Add1_f_idx;
  measure_B.VI[2] = (rtb_Sum1_pz * rtb_Divide_cv) * rtb_Add1_f_idx;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_ez = measure_P.double_Value;
  } else {
    measure_B.Switch_ez = (measure_B.VI[0] + measure_DWork.UnitDelay4_DSTATE_o)
      + measure_DWork.UnitDelay2_DSTATE_n2;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ec[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_kj;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ez;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ae;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_bbj = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ae)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_h5 = measure_P.double_Value_k;
  } else {
    measure_B.Switch_h5 = (measure_B.VI[0] + measure_DWork.UnitDelay4_DSTATE_eq)
      + measure_DWork.UnitDelay2_DSTATE_a5;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ecu[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_kjh;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_h5;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_cu;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_bbje = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_cu)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Add1_f_idx = measure_B.Switch_ez -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_bbj;
  } else {
    rtb_Add1_f_idx = measure_B.Switch_h5 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_bbje;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_pp[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_ah;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.VI[0];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_l;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_h = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_l)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_i0d = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_i0d = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_l)
      *VDD_in = 0;
  }

  measure_B.Divide_d = (rtb_Add1_f_idx -
                        ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_h
    * rtb_Subtract3_lr) +
    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_i0d *
     rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_nh = measure_P.double_Value_c;
  } else {
    measure_B.Switch_nh = (measure_B.Divide_d +
      measure_DWork.UnitDelay4_DSTATE_gy) + measure_DWork.UnitDelay2_DSTATE_dq;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fi[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_op;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_i;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_dt = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_i)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_mm = measure_P.double_Value_o0;
  } else {
    measure_B.Switch_mm = (measure_B.Divide_d +
      measure_DWork.UnitDelay4_DSTATE_je) + measure_DWork.UnitDelay2_DSTATE_ou;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fie[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_opo;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_mm;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_l2;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_dt2 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_l2)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Add1_f_idx = measure_B.Switch_nh -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_dt;
  } else {
    rtb_Add1_f_idx = measure_B.Switch_mm -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_dt2;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_k[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_ju;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_d;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_k;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_og = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_k)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_fu = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_fu = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_k)
      *VDD_in = 0;
  }

  rtb_Add1_f_idx = (rtb_Add1_f_idx -
                    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_og *
                      rtb_Subtract3_lri) +
                     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_fu *
                      rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_gg = measure_P.double_Value_n;
  } else {
    measure_B.Switch_gg = (measure_B.VI[1] + measure_DWork.UnitDelay4_DSTATE_e1)
      + measure_DWork.UnitDelay2_DSTATE_ct;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ep[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obd;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_gg;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_l4;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_dd = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_l4)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_p4 = measure_P.double_Value_d;
  } else {
    measure_B.Switch_p4 = (measure_B.VI[1] + measure_DWork.UnitDelay4_DSTATE_iz)
      + measure_DWork.UnitDelay2_DSTATE_fu;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_epo[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obdq;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_p4;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_nm;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_dd4 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_nm)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_Divide_cv = measure_B.Switch_gg -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_dd;
  } else {
    rtb_Divide_cv = measure_B.Switch_p4 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_dd4;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mfe[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_f;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.VI[1];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mv;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_mc = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mv)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_h = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_h = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mv)
      *VDD_in = 0;
  }

  measure_B.Divide_g = (rtb_Divide_cv -
                        ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_mc
    * rtb_Subtract3_lr) +
    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_h *
     rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_ml = measure_P.double_Value_nw;
  } else {
    measure_B.Switch_ml = (measure_B.Divide_g +
      measure_DWork.UnitDelay4_DSTATE_mu) + measure_DWork.UnitDelay2_DSTATE_gs;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bb[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_of;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ml;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_pt;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_chw = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_pt)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_b1 = measure_P.double_Value_l;
  } else {
    measure_B.Switch_b1 = (measure_B.Divide_g +
      measure_DWork.UnitDelay4_DSTATE_nw) + measure_DWork.UnitDelay2_DSTATE_p2;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bbn[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_of2;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_b1;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dil;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_chwo = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dil)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_Divide_cv = measure_B.Switch_ml -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_chw;
  } else {
    rtb_Divide_cv = measure_B.Switch_b1 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_chwo;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_of[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_g;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_g;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jx;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_c = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jx)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_im = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_im = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jx)
      *VDD_in = 0;
  }

  rtb_Divide_cv = (rtb_Divide_cv -
                   ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_c *
                     rtb_Subtract3_lri) +
                    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_im *
                     rtb_MathFunction_gbn2))) * rtb_Divide_mg;
  if (rtb_LogicalOperator1_fmgwx) {
    measure_B.Switch_ny = measure_P.double_Value_o;
  } else {
    measure_B.Switch_ny = (measure_B.VI[2] + measure_DWork.UnitDelay4_DSTATE_jf)
      + measure_DWork.UnitDelay2_DSTATE_h2;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bm[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_jp;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_ny;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_c3;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_ol = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_c3)
      *VDD_in = 0;
  }

  if (rtb_LogicalOperator_nx) {
    measure_B.Switch_n2 = measure_P.double_Value_a;
  } else {
    measure_B.Switch_n2 = (measure_B.VI[2] + measure_DWork.UnitDelay4_DSTATE_lb)
      + measure_DWork.UnitDelay2_DSTATE_ai5;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bmy[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_jpu;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_n2;
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_hb;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_ol3 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_hb)
      *VDD_in = 0;
  }

  if (rtb_Compare_d) {
    rtb_OutputWatts = measure_B.Switch_ny -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_ol;
  } else {
    rtb_OutputWatts = measure_B.Switch_n2 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_ol3;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mw[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_hl;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.VI[2];
    VDD_out = *VDD_in - measure_B.Switch2_f0yh;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_c2;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_iz = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_c2)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_hy = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_hy = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_c2)
      *VDD_in = 0;
  }

  measure_B.Divide_l = (rtb_OutputWatts -
                        ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_iz
    * rtb_Subtract3_lr) +
    (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_hy *
     rtb_MathFunction_gbn))) * rtb_Tps2dt_dt;
  if (rtb_Compare_enj) {
    measure_B.Switch_bi = measure_P.double_Value_do;
  } else {
    measure_B.Switch_bi = (measure_B.Divide_l +
      measure_DWork.UnitDelay4_DSTATE_co) + measure_DWork.UnitDelay2_DSTATE_lb;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_g5[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_fn;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_bi;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_nc;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_jng = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_nc)
      *VDD_in = 0;
  }

  if (rtb_Compare_ks) {
    measure_B.Switch_oh = measure_P.double_Value_c2;
  } else {
    measure_B.Switch_oh = (measure_B.Divide_l +
      measure_DWork.UnitDelay4_DSTATE_j5o) + measure_DWork.UnitDelay2_DSTATE_cmh;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_g51[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_fny;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_oh;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_o0;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_jngn = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_o0)
      *VDD_in = 0;
  }

  if (rtb_Compare_ddcrdcv) {
    rtb_OutputWatts = measure_B.Switch_bi -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_jng;
  } else {
    rtb_OutputWatts = measure_B.Switch_oh -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_jngn;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_ofy[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_as5;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.Divide_l;
    VDD_out = *VDD_in - measure_B.Switch2_f0yhy;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d5;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_f = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d5)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_m0 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_m0 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d5)
      *VDD_in = 0;
  }

  rtb_Divide_mg *= rtb_OutputWatts -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_f *
      rtb_Subtract3_lri) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_m0 *
      rtb_MathFunction_gbn2));
  measure_Y.WattsWithHarmonics = (rtb_Add1_f_idx + rtb_Divide_cv) +
    rtb_Divide_mg;
  measure_Y.VA3[0] = rtb_Divide_la;
  measure_Y.VA3[1] = rtb_Divide_i;
  measure_Y.VA3[2] = rtb_Divide_o1;
  if (rtb_Divide_la < measure_P.Constant_Value_nm) {
    rtb_Divide_la = measure_P.Constant_Value_b;
  }

  rtb_Divide_la = rtb_Add1_f_idx_0 / rtb_Divide_la;
  if (rtb_Divide_i < measure_P.Constant_Value_gc) {
    rtb_Divide_i = measure_P.Constant_Value_a;
  }

  rtb_Divide_i = rtb_Add1_f_idx_1 / rtb_Divide_i;
  if (rtb_Divide_o1 < measure_P.Constant_Value_c3) {
    rtb_Divide_o1 = measure_P.Constant_Value_ml;
  }

  rtb_Divide_o1 = rtb_VpuIpktoVrmsIrms_re / rtb_Divide_o1;
  measure_Y.PowerFactor3[0] = rtb_Divide_la;
  measure_Y.PowerFactor3[1] = rtb_Divide_i;
  measure_Y.PowerFactor3[2] = rtb_Divide_o1;
  measure_Y.WattsFundamental3[0] = rtb_Add1_f_idx_0;
  measure_Y.WattsFundamental3[1] = rtb_Add1_f_idx_1;
  measure_Y.WattsFundamental3[2] = rtb_VpuIpktoVrmsIrms_re;
  measure_Y.Vars3[0] = rtb_Sum1_kv;
  measure_Y.Vars3[1] = rtb_Switch1_iew;
  measure_Y.Vars3[2] = rtb_VpuIpktoVrmsIrms_im;
  measure_Y.WattsWithHarmonics3[0] = rtb_Add1_f_idx;
  measure_Y.WattsWithHarmonics3[1] = rtb_Divide_cv;
  measure_Y.WattsWithHarmonics3[2] = rtb_Divide_mg;
  rtb_Add1_f_idx = rtb_Sum2_i - rtb_TrigonometricFunction_i;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_egs) {
    rtb_Add1_f_idx += measure_P.Bias1_Bias;
  } else {
    if (rtb_Add1_f_idx > measure_P.Constant_Value_eg) {
      rtb_Add1_f_idx += measure_P.Bias_Bias_h;
    }
  }

  rtb_Add1_f_idx_0 = rtb_TrigonometricFunction_hr - rtb_TrigonometricFunction_ix;
  if (rtb_Add1_f_idx_0 < measure_P.Constant_Value_oc) {
    rtb_Add1_f_idx_0 += measure_P.Bias1_Bias_f;
  } else {
    if (rtb_Add1_f_idx_0 > measure_P.Constant_Value_o) {
      rtb_Add1_f_idx_0 += measure_P.Bias_Bias_f;
    }
  }

  rtb_Sum1_kv = rtb_TrigonometricFunction_hrx - rtb_TrigonometricFunction_ixv;
  if (rtb_Sum1_kv < measure_P.Constant_Value_bbe) {
    rtb_Sum1_kv += measure_P.Bias1_Bias_f1;
  } else {
    if (rtb_Sum1_kv > measure_P.Constant_Value_bb) {
      rtb_Sum1_kv += measure_P.Bias_Bias_f1;
    }
  }

  measure_Y.PowerAngleRad3[0] = rtb_Add1_f_idx;
  measure_Y.PowerAngleRad3[1] = rtb_Add1_f_idx_0;
  measure_Y.PowerAngleRad3[2] = rtb_Sum1_kv;
  measure_Y.PhaseFrequency[0] = rtb_Ts_FFT_k;
  measure_Y.PhaseFrequency[1] = rtb_Ts_FFT;
  measure_Y.PhaseFrequency[2] = rtb_Switch4;
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition = measure_DWork.RateTransition_Buffer0;
    measure_B.RateTransition_o = measure_DWork.RateTransition_Buffer0_l;
    measure_B.RateTransition_g = measure_DWork.RateTransition_Buffer0_b;
  }

  measure_Y.VoltageFundamentalAmplitudePosFreq[0] = measure_B.RateTransition;
  measure_Y.VoltageFundamentalAmplitudePosFreq[1] = measure_B.RateTransition_o;
  measure_Y.VoltageFundamentalAmplitudePosFreq[2] = measure_B.RateTransition_g;
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    for (i = 0; i < 31; i++) {
      measure_B.RateTransition_gf[(i)] = measure_DWork.RateTransition_Buffer0_a
        [(i)];
      measure_B.RateTransition_gw[(i)] = measure_DWork.RateTransition_Buffer0_j
        [(i)];
      measure_B.RateTransition_n[(i)] = measure_DWork.RateTransition_Buffer0_ak
        [(i)];
    }
  }

  memcpy((void *)(&measure_Y.VoltageAmplitudesRelativeToFundamental[0]), (void *)
         (&measure_B.RateTransition_gf[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.VoltageAmplitudesRelativeToFundamental[31]), (void *)
         (&measure_B.RateTransition_gw[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.VoltageAmplitudesRelativeToFundamental[62]), (void *)
         (&measure_B.RateTransition_n[0]), 31U * (sizeof(real_T)));
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    for (i = 0; i < 31; i++) {
      measure_B.RateTransition_h[(i)] = measure_DWork.RateTransition_Buffer0_h
        [(i)];
      measure_B.RateTransition_k[(i)] = measure_DWork.RateTransition_Buffer0_g
        [(i)];
      measure_B.RateTransition_b[(i)] = measure_DWork.RateTransition_Buffer0_hn
        [(i)];
    }
  }

  memcpy((void *)(&measure_Y.VoltagePhasesRelativeToFundamental[0]), (void *)
         (&measure_B.RateTransition_h[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.VoltagePhasesRelativeToFundamental[31]), (void *)
         (&measure_B.RateTransition_k[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.VoltagePhasesRelativeToFundamental[62]), (void *)
         (&measure_B.RateTransition_b[0]), 31U * (sizeof(real_T)));
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    for (i = 0; i < 31; i++) {
      measure_B.RateTransition_a[(i)] = measure_DWork.RateTransition_Buffer0_e
        [(i)];
      measure_B.RateTransition_gy[(i)] =
        measure_DWork.RateTransition_Buffer0_lm[(i)];
      measure_B.RateTransition_m[(i)] = measure_DWork.RateTransition_Buffer0_az
        [(i)];
    }
  }

  memcpy((void *)(&measure_Y.VoltageHarmonicsAnalysed[0]), (void *)
         (&measure_B.RateTransition_a[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.VoltageHarmonicsAnalysed[31]), (void *)
         (&measure_B.RateTransition_gy[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.VoltageHarmonicsAnalysed[62]), (void *)
         (&measure_B.RateTransition_m[0]), 31U * (sizeof(real_T)));
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_l = measure_DWork.RateTransition_Buffer0_m;
    measure_B.RateTransition_gq = measure_DWork.RateTransition_Buffer0_bh;
    measure_B.RateTransition_a0 = measure_DWork.RateTransition_Buffer0_o;
  }

  measure_Y.CurrentFundamentalAmplitudePosFreq[0] = measure_B.RateTransition_l;
  measure_Y.CurrentFundamentalAmplitudePosFreq[1] = measure_B.RateTransition_gq;
  measure_Y.CurrentFundamentalAmplitudePosFreq[2] = measure_B.RateTransition_a0;
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    for (i = 0; i < 31; i++) {
      measure_B.RateTransition_j[(i)] = measure_DWork.RateTransition_Buffer0_aq
        [(i)];
      measure_B.RateTransition_c[(i)] = measure_DWork.RateTransition_Buffer0_oh
        [(i)];
      measure_B.RateTransition_ax[(i)] =
        measure_DWork.RateTransition_Buffer0_lg[(i)];
    }
  }

  memcpy((void *)(&measure_Y.CurrentAmplitudesRelativeToFundamental[0]), (void *)
         (&measure_B.RateTransition_j[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.CurrentAmplitudesRelativeToFundamental[31]), (void *)
         (&measure_B.RateTransition_c[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.CurrentAmplitudesRelativeToFundamental[62]), (void *)
         (&measure_B.RateTransition_ax[0]), 31U * (sizeof(real_T)));
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    for (i = 0; i < 31; i++) {
      measure_B.RateTransition_jz[(i)] = measure_DWork.RateTransition_Buffer0_n
        [(i)];
      measure_B.RateTransition_h2[(i)] = measure_DWork.RateTransition_Buffer0_c
        [(i)];
      measure_B.RateTransition_cc[(i)] =
        measure_DWork.RateTransition_Buffer0_cq[(i)];
    }
  }

  memcpy((void *)(&measure_Y.CurrentPhasesRelativeToFundamental[0]), (void *)
         (&measure_B.RateTransition_jz[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.CurrentPhasesRelativeToFundamental[31]), (void *)
         (&measure_B.RateTransition_h2[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.CurrentPhasesRelativeToFundamental[62]), (void *)
         (&measure_B.RateTransition_cc[0]), 31U * (sizeof(real_T)));
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    for (i = 0; i < 31; i++) {
      measure_B.RateTransition_mz[(i)] =
        measure_DWork.RateTransition_Buffer0_mb[(i)];
      measure_B.RateTransition_jt[(i)] =
        measure_DWork.RateTransition_Buffer0_of[(i)];
      measure_B.RateTransition_f[(i)] = measure_DWork.RateTransition_Buffer0_jc
        [(i)];
    }
  }

  memcpy((void *)(&measure_Y.CurrentHarmonicsAnalysed[0]), (void *)
         (&measure_B.RateTransition_mz[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.CurrentHarmonicsAnalysed[31]), (void *)
         (&measure_B.RateTransition_jt[0]), 31U * (sizeof(real_T)));
  memcpy((void *)(&measure_Y.CurrentHarmonicsAnalysed[62]), (void *)
         (&measure_B.RateTransition_f[0]), 31U * (sizeof(real_T)));
  measure_B.Gain1 = measure_P.Gain1_Gain_j0 * measure_U.IabcAmps[0];
  rtb_Add1_f_idx = measure_P.Gain5_Gain * rtb_Ts_FFT_k;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_hc) {
    rtb_Add1_f_idx = measure_P.Constant_Value;
  }

  rtb_Gain_pj = 1.0 / rtb_Add1_f_idx;
  measure_B.Gain8 = measure_P.Gain8_Gain * rtb_Gain_pj;

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

  rtb_Gain_pj *= (real_T)(measure_B.SFunction_o3 - measure_P.Constant2_Value_os);
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_cq = measure_DWork.RateTransition_Buffer0_k;
  }

  for (i = 0; i < 11; i++) {
    rtb_Gain6_re = (((((measure_P.Gain2_Gain_l * measure_P.Constant9_Value[(i)])
                       * rtb_Gain_pj) +
                      measure_P.udegcompensationsinceusingvefreqoutputfromFFT_Bias)
                     + measure_B.RateTransition_cq) +
                    measure_P.Constant1_Value_m5) / measure_P.Constant2_Value_hp;
    if (measure_P.Constant6_Value_i) {
      measure_B.Switch2_dd[(i)] = rtb_Gain6_re + measure_P.Bias2_Bias;
    } else if (rtb_Gain6_re < measure_P.Constant_Value_is) {
      measure_B.Switch2_dd[(i)] = rtb_Gain6_re + measure_P.Bias_Bias;
    } else {
      measure_B.Switch2_dd[(i)] = rtb_Gain6_re;
    }
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_dd;
    int32_T *y0 = measure_B.SFunction2;
    for (i1=0; i1 < 11; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    memcpy((void *)(&measure_B.RateTransition_hd[0]), (void *)
           (&measure_B.SFunction_o1[0]), (sizeof(real_T)) << 6U);
  }

  measure_B.Gain1_n = measure_P.Gain1_Gain_gd * measure_U.IabcAmps[1];
  rtb_Add1_f_idx = measure_P.Gain5_Gain_l * rtb_Ts_FFT;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_ni) {
    rtb_Add1_f_idx = measure_P.Constant_Value_n;
  }

  rtb_Gain_pj = 1.0 / rtb_Add1_f_idx;
  measure_B.Gain8_l = measure_P.Gain8_Gain_h * rtb_Gain_pj;

  {
    int_T ok = 1;
    real_T t,a,D1,D2,D3;
    real_T* FFT_Data = (real_T*)measure_B.SFunction_o1_i;
    D1 = measure_DWork.SFunction_RWORK_i[0] - measure_B.Gain1_n;
    D2 = measure_DWork.SFunction_RWORK_i[1] - D1;
    D3 = measure_DWork.SFunction_RWORK_i[2] - D2;
    measure_B.SFunction_o2_n = measure_DWork.SFunction_RWORK_i[3] + 1;
    while (ok) {
      t = measure_B.SFunction_o2_n - measure_B.Gain8_l;
      ok = (t>=0);
      if (ok) {
        measure_B.SFunction_o2_n = t;
        a = measure_B.Gain1_n + D1*measure_B.SFunction_o2_n;
        t = measure_B.SFunction_o2_n * (measure_B.SFunction_o2_n-1);
        a += D2*t*0.5;
        t *= (measure_B.SFunction_o2_n-2);
        a += D3*t/6;
        measure_DWork.SFunction_IWORK_m++;
        if (measure_DWork.SFunction_IWORK_m > (64-1) ) {
          measure_DWork.SFunction_IWORK_m= 0;
        }

        FFT_Data[measure_DWork.SFunction_IWORK_m]= a;
      }
    }

    measure_B.SFunction_o3_o = measure_DWork.SFunction_IWORK_m;
    measure_DWork.SFunction_RWORK_i[0] = measure_B.Gain1_n;
    measure_DWork.SFunction_RWORK_i[1] = D1;
    measure_DWork.SFunction_RWORK_i[2] = D2;
    measure_DWork.SFunction_RWORK_i[3] = measure_B.SFunction_o2_n;
  }

  rtb_Gain_pj *= (real_T)(measure_B.SFunction_o3_o - measure_P.Constant2_Value_k);
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_lr = measure_DWork.RateTransition_Buffer0_ki;
  }

  for (i = 0; i < 10; i++) {
    rtb_Gain6_re = (((((measure_P.Constant9_Value[i + 11] *
                        measure_P.Gain2_Gain_e) * rtb_Gain_pj) +
                      measure_P.udegcompensationsinceusingvefreqoutputfromFFT_Bias_h)
                     + measure_B.RateTransition_lr) +
                    measure_P.Constant1_Value_a) / measure_P.Constant2_Value_j;
    if (measure_P.Constant6_Value_e) {
      measure_B.Switch2_h5[(i)] = rtb_Gain6_re + measure_P.Bias2_Bias_eh;
    } else if (rtb_Gain6_re < measure_P.Constant_Value_eh) {
      measure_B.Switch2_h5[(i)] = rtb_Gain6_re + measure_P.Bias_Bias_e;
    } else {
      measure_B.Switch2_h5[(i)] = rtb_Gain6_re;
    }
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_h5;
    int32_T *y0 = measure_B.SFunction2_n;
    for (i1=0; i1 < 10; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    memcpy((void *)(&measure_B.RateTransition_la[0]), (void *)
           (&measure_B.SFunction_o1_i[0]), (sizeof(real_T)) << 6U);
  }

  measure_B.Gain1_p = measure_P.Gain1_Gain_jq * measure_U.IabcAmps[2];
  rtb_Add1_f_idx = measure_P.Gain5_Gain_b * rtb_Switch4;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_nd) {
    rtb_Add1_f_idx = measure_P.Constant_Value_m;
  }

  rtb_Gain_pj = 1.0 / rtb_Add1_f_idx;
  measure_B.Gain8_h = measure_P.Gain8_Gain_n * rtb_Gain_pj;

  {
    int_T ok = 1;
    real_T t,a,D1,D2,D3;
    real_T* FFT_Data = (real_T*)measure_B.SFunction_o1_b;
    D1 = measure_DWork.SFunction_RWORK_c[0] - measure_B.Gain1_p;
    D2 = measure_DWork.SFunction_RWORK_c[1] - D1;
    D3 = measure_DWork.SFunction_RWORK_c[2] - D2;
    measure_B.SFunction_o2_p = measure_DWork.SFunction_RWORK_c[3] + 1;
    while (ok) {
      t = measure_B.SFunction_o2_p - measure_B.Gain8_h;
      ok = (t>=0);
      if (ok) {
        measure_B.SFunction_o2_p = t;
        a = measure_B.Gain1_p + D1*measure_B.SFunction_o2_p;
        t = measure_B.SFunction_o2_p * (measure_B.SFunction_o2_p-1);
        a += D2*t*0.5;
        t *= (measure_B.SFunction_o2_p-2);
        a += D3*t/6;
        measure_DWork.SFunction_IWORK_l++;
        if (measure_DWork.SFunction_IWORK_l > (64-1) ) {
          measure_DWork.SFunction_IWORK_l= 0;
        }

        FFT_Data[measure_DWork.SFunction_IWORK_l]= a;
      }
    }

    measure_B.SFunction_o3_g = measure_DWork.SFunction_IWORK_l;
    measure_DWork.SFunction_RWORK_c[0] = measure_B.Gain1_p;
    measure_DWork.SFunction_RWORK_c[1] = D1;
    measure_DWork.SFunction_RWORK_c[2] = D2;
    measure_DWork.SFunction_RWORK_c[3] = measure_B.SFunction_o2_p;
  }

  rtb_Gain_pj *= (real_T)(measure_B.SFunction_o3_g -
    measure_P.Constant2_Value_nz);
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_aj = measure_DWork.RateTransition_Buffer0_jr;
  }

  for (i = 0; i < 10; i++) {
    rtb_Gain6_re = (((((measure_P.Constant9_Value[i + 21] *
                        measure_P.Gain2_Gain_h) * rtb_Gain_pj) +
                      measure_P.udegcompensationsinceusingvefreqoutputfromFFT_Bias_j)
                     + measure_B.RateTransition_aj) +
                    measure_P.Constant1_Value_mz) / measure_P.Constant2_Value_o;
    if (measure_P.Constant6_Value_iv) {
      measure_B.Switch2_n[(i)] = rtb_Gain6_re + measure_P.Bias2_Bias_i;
    } else if (rtb_Gain6_re < measure_P.Constant_Value_ivc) {
      measure_B.Switch2_n[(i)] = rtb_Gain6_re + measure_P.Bias_Bias_i;
    } else {
      measure_B.Switch2_n[(i)] = rtb_Gain6_re;
    }
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_n;
    int32_T *y0 = measure_B.SFunction2_l;
    for (i1=0; i1 < 10; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    memcpy((void *)(&measure_B.RateTransition_mm[0]), (void *)
           (&measure_B.SFunction_o1_b[0]), (sizeof(real_T)) << 6U);
  }

  if (rtb_Compare_mtg) {
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

  rtb_Switch6_idx = (rtb_Switch1_a == measure_P.Constant_Value_ka);
  rtb_Compare_ks = (rtb_Switch6_idx && ((rtb_Compare_k || rtb_Compare_k3) ||
    rtb_Compare_k3k));
  rtb_LogicalOperator1 = (rtb_Compare_ks && (measure_DWork.delay_DSTATE_i2wj4));
  rtb_LogicalOperator_nx = !rtb_Compare_ks;
  rtb_Gain_pj = measure_P.Gain_Gain_jcfawyw2o0 * measure_P.Constant4_Value_g;
  if (measure_P.Constant6_Value_j) {
    measure_B.Switch2_h1wibj = rtb_Gain_pj + measure_P.Bias1_Bias_j;
  } else {
    measure_B.Switch2_h1wibj = rtb_Gain_pj + measure_P.Bias_Bias_j;
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

  rtb_Compare_ks = (rtb_UnitDelay1_pu5rdhlnellvz > measure_P.Constant_Value_ci0);
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
    measure_B.Switch2_h1wibj2 = rtb_Gain_pj + measure_P.Bias1_Bias_jc;
  } else {
    measure_B.Switch2_h1wibj2 = rtb_Gain_pj + measure_P.Bias_Bias_jc;
  }

  {
    measure_B.SFunction_ilzn5 = (uint32_T)measure_B.Switch2_h1wibj2;
  }

  if (!rtb_LogicalOperator1) {
    rtb_UnitDelay1_pu5rdhlnellvz = measure_B.SFunction_ilzn5 +
      measure_P.FixPtConstant_Value_jc;
  }

  rtb_Compare_ks = (rtb_UnitDelay1_pu5rdhlnellvz == measure_P.Constant_Value_ms);
  if (rtb_UnitDelay4_dmwj4s1jwn3 && ((rtb_RelationalOperator_o &&
        rtb_RelationalOperator_os) && rtb_RelationalOperator_osa)) {
    rtb_Switch1_ia = measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhwrm;
  } else {
    rtb_Switch1_ia = measure_P.const_Value_jcf;
  }

  rtb_Compare_enj = (rtb_Switch1_ia == measure_P.Constant_Value_icp);
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
  if (rtb_LogicalOperator1_fwnazb5b22n) {
    measure_B.Switch_nulzsg5y = measure_P.double_Value_jcfawyw2o;
  } else {
    measure_B.Switch_nulzsg5y = (measure_B.ACripple1stestimate +
      measure_DWork.UnitDelay4_DSTATE_czl44j1i) +
      measure_DWork.UnitDelay2_DSTATE_h5brdqciz0;
  }

  {
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4npphe4[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3seeh3o;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulzsg5y;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawyw2;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_co5gwoze =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawyw2)
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
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4npphe4j[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3seeh3od;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_nulzsg5yk;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawyw2o;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_co5gwoze0 =
      VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in >
        measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawyw2o)
      *VDD_in = 0;
  }

  if (rtb_Compare_hpz455i02) {
    rtb_Add1_f_idx = measure_B.Switch_nulzsg5y -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_co5gwoze;
  } else {
    rtb_Add1_f_idx = measure_B.Switch_nulzsg5yk -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_co5gwoze0;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mf50[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_jngr;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.ACripple1stestimate;
    VDD_out = *VDD_in - measure_B.Switch2_h1wibj25mpus;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jcfa;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_jwh1 = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jcfa)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f1uv = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f1uv = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jcfa)
      *VDD_in = 0;
  }

  rtb_Switch = measure_B.ACripple1stestimate - ((rtb_Add1_f_idx -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_jwh1 *
      rtb_Subtract3_ca) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_f1uv *
      rtb_MathFunction_mti))) * rtb_Tps2dt_cr);
  rtb_Switch_nulzsg5ykq = measure_DWork.UnitDelay_DSTATE_lmdwo3 +
    measure_P.Bias_Bias_jcfawyw2o0os;
  if (rtb_Switch_nulzsg5ykq < measure_DWork.UnitDelay_DSTATE_lmdwo3) {
    rtb_Switch_nulzsg5ykq = MAX_uint32_T;
  }

  rtb_Divide_nqzy = measure_DWork.UnitDelay_DSTATE_lmd;
  rtb_LogicalOperator16 = (measure_DWork.UnitDelay_DSTATE_lmd >
    measure_P.Constant_Value_ot);
  if (measure_P.Constant_Value_ml3) {
    rtb_Compare_ks = (rtb_LogicalOperator16 &&
                      (measure_DWork.delay_DSTATE_i2wj4d));
  } else {
    rtb_Compare_ks = ((rtb_LogicalOperator16 ^ measure_DWork.delay1_DSTATE_ces) &&
                      (measure_DWork.UnitDelay_DSTATE_lmdwo300ig));
  }

  rtb_Compare_ks = ((!measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j45w) &&
                    rtb_Compare_ks);
  if (rtb_Compare_ks) {
    rtb_Switch2_h = rtb_Switch_nulzsg5ykq;
  } else {
    rtb_Switch2_h = measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j4;
  }

  if (rtb_Compare_ks) {
    rtb_Gain_pj = measure_DWork.UnitDelay_DSTATE_lmd -
      measure_DWork.UnitDelay1_DSTATE_cm;
    if (rtb_Gain_pj < measure_P.Constant_Value_ipk) {
      rtb_UnaryMinus_l = -rtb_Gain_pj;
    } else {
      rtb_UnaryMinus_l = rtb_Gain_pj;
    }

    if (rtb_UnaryMinus_l < measure_P.Constant_Value_jn) {
      rtb_Gain_pj = measure_P.Constant1_Value_jcfawyw2o;
    }

    rtb_Divide_o1 = (measure_DWork.UnitDelay1_DSTATE_cm / rtb_Gain_pj) *
      measure_P.T2T1_Gain;
    rtb_Switch_jka = rtb_Divide_o1 - measure_DWork.UnitDelay4_DSTATE_czl44j1ipa;
  } else {
    rtb_Divide_o1 = measure_DWork.UnitDelay1_DSTATE_cmn;
    rtb_Switch_jka = measure_DWork.UnitDelay1_DSTATE_cmnb;
  }

  rtb_Add1_f_idx = (measure_P.Gain_Gain_jcfawyw2o0os * ((real_T)rtb_Switch2_h))
    + rtb_Switch_jka;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_gp) {
    rtb_Add1_f_idx = measure_P.Constant_Value_p4;
  }

  rtb_Divide_nqz = (1.0 / rtb_Add1_f_idx) * measure_P.Gain_Gain_jcfawyw2o0osk;
  if (rtb_Compare_jm) {
    rtb_Divide_i = measure_P.Constant_Value_jcfawyw2o0osk;
  } else {
    rtb_Gain_pj = ((measure_DWork.UnitDelay1_DSTATE_c + rtb_Divide_nqz) *
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
      rtb_Divide_i = measure_P.Constant_Value_jcfawyw2o0;
    } else if (rtb_Gain_pj > measure_P.Constant_Value_jcfawyw2o) {
      rtb_Divide_i = measure_P.Constant1_Value_jcfawy;
    } else {
      rtb_Divide_i = rtb_Gain_pj;
    }
  }

  rtb_Gain_pj = measure_P.Gain2_Gain_j * rtb_Divide_i;
  if (measure_P.Constant6_Value_jcf) {
    if (rtb_Gain_pj > measure_P.Constant_Value_ehx) {
      measure_B.Switch2_h1wibj25 = rtb_Gain_pj + measure_P.Bias1_Bias_jcfa;
    } else {
      measure_B.Switch2_h1wibj25 = rtb_Gain_pj + measure_P.Bias_Bias_jcfa;
    }
  } else {
    measure_B.Switch2_h1wibj25 = rtb_Gain_pj;
  }

  {
    measure_B.SFunction_ilz = (int32_T)measure_B.Switch2_h1wibj25;
  }

  if (((real_T)measure_B.SFunction_ilz) < measure_P.Constant_Value_l) {
    rtb_Gain6_re = measure_P.Constant_Value_jcfawyw2o0osk2;
  } else {
    rtb_Gain6_re = (real_T)measure_B.SFunction_ilz;
  }

  rtb_Gain_pj = ((1.0 / rtb_Divide_i) * rtb_Gain6_re) -
    measure_DWork.UnitDelay1_DSTATE_cmnb3j;
  if (rtb_Gain_pj < measure_P.Constant_Value_hb) {
    rtb_Add1_f_idx_0 = measure_P.Constant_Value_jcfawy;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_jcfaw) {
    rtb_Add1_f_idx_0 = measure_P.Constant1_Value_jcfa;
  } else {
    rtb_Add1_f_idx_0 = rtb_Gain_pj;
  }

  rtb_Divide_la = rtb_Add1_f_idx_0 + measure_DWork.UnitDelay1_DSTATE_cmnb3j;
  if (rtb_Compare_jm) {
    rtb_Switch1_bt = rtb_UnitDelay1_c;
  } else {
    rtb_Switch1_bt = measure_P.int1_Value_jc;
  }

  rtb_Add1_f_idx_0 = std::exp((measure_P.Gain1_Gain_jcfawy * rtb_Divide_i) *
    measure_P.Gain2_Gain_jc);
  rtb_ComplextoRealImag_o2_l = (measure_P.double1_Value - rtb_Add1_f_idx_0) *
    rtb_Switch;
  rtb_OutputWatts = rtb_Divide_nqzy * rtb_Add1_f_idx_0;
  rtb_Add1_f_idx = (measure_P.Gain1_Gain_jcfawyw * rtb_Add1_f_idx) +
    measure_P.Bias_Bias_jcfawyw2o0;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_gw) {
    rtb_Add1_f_idx = measure_P.Constant_Value_pv;
  }

  rtb_Gain_pj = (measure_P.Gain_Gain_jcfawyw2o0osk2 * rtb_Add1_f_idx) +
    measure_P.Bias_Bias_jcfawyw2o0o;
  if (rtb_Gain_pj < measure_P.Constant_Value_ciq) {
    rtb_Gain_pj = measure_P.Constant_Value_dl;
  } else {
    if (rtb_Gain_pj > measure_P.Constant_Value_mp) {
      rtb_Gain_pj = measure_P.Constant1_Value_jcfawyw2;
    }
  }

  if (measure_P.Constant6_Value_jcfa) {
    measure_B.Switch2_h1wibj25m = rtb_Gain_pj + measure_P.Bias1_Bias_jcfawy;
  } else {
    measure_B.Switch2_h1wibj25m = rtb_Gain_pj + measure_P.Bias_Bias_jcfawy;
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

  rtb_LogicalOperator9 = (rtb_UnitDelay1_c > measure_P.Constant_Value_fw);
  if (rtb_LogicalOperator9) {
    rtb_Switch1_fr = rtb_UnitDelay1_c;
  } else {
    rtb_Switch1_fr = measure_P.int1_Value_jcf;
  }

  if (rtb_Compare_ks) {
    rtb_Switch_nulzsg5ykq = measure_P.Constant_Value_ir;
  }

  if (rtb_Switch6_idx) {
    rtb_Switch1_a = measure_P.int2_Value_jcfa;
  }

  rtb_FixPtSum1_cotnt = rtb_Switch1_a - measure_P.FixPtConstant_Value_jcfawyw2o0;
  if (rtb_LogicalOperator12) {
    rtb_Switch1_a = measure_DWork.UnitDelay1_DSTATE_j;
  } else {
    rtb_Switch1_a = measure_P.const_Value_n;
  }

  rtb_Switch6_idx = (rtb_Switch1_a == measure_P.Constant_Value_b4);
  rtb_LogicalOperator12 = (rtb_Switch6_idx && rtb_Disturbance_All_Phases);
  rtb_LogicalOperator1 = (rtb_LogicalOperator12 && (measure_DWork.delay_DSTATE_h));
  rtb_Any_Phases_Not_Disturbed = !rtb_LogicalOperator12;
  rtb_Gain_pj = measure_P.Gain_Gain_he * measure_P.Constant4_Value_g;
  if (measure_P.Constant6_Value_he) {
    measure_B.Switch2_c = rtb_Gain_pj + measure_P.Bias1_Bias_h;
  } else {
    measure_B.Switch2_c = rtb_Gain_pj + measure_P.Bias_Bias_he;
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
  if (measure_P.Constant6_Value_heb) {
    measure_B.Switch2_c1 = rtb_Gain_pj + measure_P.Bias1_Bias_he;
  } else {
    measure_B.Switch2_c1 = rtb_Gain_pj + measure_P.Bias_Bias_heb;
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
  rtb_Add1_f_idx = rtb_TrigonometricFunction_i -
    measure_DWork.UnitDelay3_DSTATE_i5z5;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_apbnf) {
    rtb_Add1_f_idx += measure_P.Bias1_Bias_apb;
  } else {
    if (rtb_Add1_f_idx > measure_P.Constant_Value_apbn) {
      rtb_Add1_f_idx += measure_P.Bias_Bias_apb;
    }
  }

  rtb_Add1_f_idx *= measure_P.Gain_Gain_ap;
  if (rtb_Compare_f) {
    rtb_UnitDelay1_lccp = measure_P.int1_Value_k;
  }

  rtb_FixPtSum1_e = rtb_UnitDelay1_lccp - measure_P.FixPtConstant_Value_k;
  if (rtb_Compare_j1k4d50fkuukjs) {
    rtb_Switch1_pwrmjy = measure_P.int2_Value_k;
  }

  rtb_FixPtSum1_ec = rtb_Switch1_pwrmjy - measure_P.FixPtConstant_Value_ki;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_mv) {
    rtb_Add1_f_idx = -rtb_Add1_f_idx;
  }

  rtb_SumofElements1 = measure_P.Gain_Gain_po * rtb_Add1_f_idx;
  rtb_Divide_nfu = measure_P.Gain1_Gain_p * rtb_UnitDelay_i;
  if (rtb_Compare_j1k4d50fkuukj) {
    rtb_Switch1_pwrm = measure_P.int2_Value_o;
  }

  rtb_FixPtSum1_ecs = rtb_Switch1_pwrm - measure_P.FixPtConstant_Value_o;
  if (rtb_Compare_j1k4d50fkuukjsr) {
    rtb_Switch1_pwrmj = measure_P.int2_Value_od;
  }

  rtb_FixPtSum1_ecsn = rtb_Switch1_pwrmj - measure_P.FixPtConstant_Value_od;
  rtb_Add1_f_idx = rtb_TrigonometricFunction_ix -
    measure_DWork.UnitDelay3_DSTATE_i5z5o;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_i2jfb) {
    rtb_Add1_f_idx += measure_P.Bias1_Bias_i2j;
  } else {
    if (rtb_Add1_f_idx > measure_P.Constant_Value_i2jf) {
      rtb_Add1_f_idx += measure_P.Bias_Bias_i2j;
    }
  }

  rtb_Add1_f_idx *= measure_P.Gain_Gain_i2;
  if (rtb_Compare_gw) {
    rtb_Switch1_dg2as0wb = measure_P.int1_Value_m;
  }

  rtb_FixPtSum1_ecsns = rtb_Switch1_dg2as0wb - measure_P.FixPtConstant_Value_ma;
  if (rtb_Compare_g3iwu32gm4xoql) {
    rtb_Switch1_dg2as0w = measure_P.int2_Value_m;
  }

  rtb_FixPtSum1_ecsnsv = rtb_Switch1_dg2as0w - measure_P.FixPtConstant_Value_maw;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_ij) {
    rtb_Add1_f_idx = -rtb_Add1_f_idx;
  }

  rtb_Sum1_dat = measure_P.Gain_Gain_oe * rtb_Add1_f_idx;
  rtb_TrigonometricFunction_hrx = measure_P.Gain1_Gain_oe * rtb_UnitDelay_it;
  if (rtb_Compare_g3iwu32gm4xoq) {
    rtb_Switch1_dg2as = measure_P.int2_Value_kc;
  }

  rtb_FixPtSum1_ecsnsvo = rtb_Switch1_dg2as - measure_P.FixPtConstant_Value_kc;
  if (rtb_Compare_g3iwu32gm4xoqly) {
    rtb_Switch1_dg2as0 = measure_P.int2_Value_kcq;
  }

  rtb_FixPtSum1_ecsnsvom = rtb_Switch1_dg2as0 -
    measure_P.FixPtConstant_Value_kcq;
  rtb_Add1_f_idx = rtb_TrigonometricFunction_ixv -
    measure_DWork.UnitDelay3_DSTATE_i5z5oq;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_orgz4) {
    rtb_Add1_f_idx += measure_P.Bias1_Bias_or;
  } else {
    if (rtb_Add1_f_idx > measure_P.Constant_Value_orgz) {
      rtb_Add1_f_idx += measure_P.Bias_Bias_or;
    }
  }

  rtb_Add1_f_idx *= measure_P.Gain_Gain_or;
  if (rtb_Compare_il) {
    rtb_Switch1_mf0c25z = measure_P.int1_Value_my;
  }

  rtb_FixPtSum1_ecsnsvomv = rtb_Switch1_mf0c25z -
    measure_P.FixPtConstant_Value_my;
  if (rtb_Compare_dtgasgy1ciwmtjh) {
    rtb_Switch1_mf0c25 = measure_P.int2_Value_my;
  }

  rtb_Switch1_mf0c25z = rtb_Switch1_mf0c25 - measure_P.FixPtConstant_Value_my5;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_in) {
    rtb_Add1_f_idx = -rtb_Add1_f_idx;
  }

  rtb_Sum1_kv = measure_P.Gain_Gain_jn * rtb_Add1_f_idx;
  rtb_TrigonometricFunction_hr = measure_P.Gain1_Gain_jn * rtb_UnitDelay_itx;
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
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_hh[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_dtp;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lli5;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mqco;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_ay = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mqco)
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
    real_T *VDD_buffer = (real_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ii3[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_fy;
    int_T VDD_out;
    VDD_buffer[*VDD_in] = measure_B.Switch_lli5y;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mqco2;
      VDD_out++;
    }

    measure_B.VariableDiscreteDelaywithOneTapSfunction_h4 = VDD_buffer[VDD_out];
    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mqco2)
      *VDD_in = 0;
  }

  if (rtb_Compare_o) {
    rtb_Add1_f_idx = measure_B.Switch_lli5 -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_ay;
  } else {
    rtb_Add1_f_idx = measure_B.Switch_lli5y -
      measure_B.VariableDiscreteDelaywithOneTapSfunction_h4;
  }

  {
    real_T *VDD_buffer =
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mj[0];
    int_T *VDD_in = (int_T*)
      &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_fz;
    int_T VDD_out;
    real_T *Out_ptr;
    VDD_buffer[*VDD_in] = measure_B.ACripple1stestimate_n;
    VDD_out = *VDD_in - measure_B.Switch2_dmf4;
    if (VDD_out < 0) {
      VDD_out += measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mqc;
      VDD_out++;
    }

    Out_ptr= &VDD_buffer[VDD_out];
    measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_ml = *Out_ptr;
    if (VDD_out == measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mqc)
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_b2 = VDD_buffer[0];
    else {
      Out_ptr++;
      measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_b2 = *Out_ptr;
    }

    (*VDD_in)++;
    if (*VDD_in > measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mqc)
      *VDD_in = 0;
  }

  rtb_Switch = measure_B.ACripple1stestimate_n - ((rtb_Add1_f_idx -
    ((measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o1_ml *
      rtb_Switch_jkaja) +
     (measure_B.VariableDiscreteDelaywithTwoTapsSfunction_o2_b2 *
      rtb_MathFunction_pl))) * rtb_Switch_j);
  rtb_UnitDelay1_lccp = measure_DWork.UnitDelay_DSTATE_otr +
    measure_P.Bias_Bias_mqco2g;
  if (rtb_UnitDelay1_lccp < measure_DWork.UnitDelay_DSTATE_otr) {
    rtb_UnitDelay1_lccp = MAX_uint32_T;
  }

  rtb_Sum2_i = measure_DWork.UnitDelay_DSTATE_o;
  rtb_LogicalOperator2_npqx = (measure_DWork.UnitDelay_DSTATE_o >
    measure_P.Constant_Value_c5);
  if (measure_P.Constant_Value_k4) {
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
    if (rtb_Gain_pj < measure_P.Constant_Value_ipg) {
      rtb_UnaryMinus_l = -rtb_Gain_pj;
    } else {
      rtb_UnaryMinus_l = rtb_Gain_pj;
    }

    if (rtb_UnaryMinus_l < measure_P.Constant_Value_hh) {
      rtb_Gain_pj = measure_P.Constant1_Value_mqco2g;
    }

    rtb_Switch1_iew = (measure_DWork.UnitDelay1_DSTATE_dgz / rtb_Gain_pj) *
      measure_P.T2T1_Gain_m;
    rtb_Divide_cv = rtb_Switch1_iew - measure_DWork.UnitDelay4_DSTATE_eduao;
  } else {
    rtb_Switch1_iew = measure_DWork.UnitDelay1_DSTATE_dgzm;
    rtb_Divide_cv = measure_DWork.UnitDelay1_DSTATE_dgzmv;
  }

  rtb_Add1_f_idx = (measure_P.Gain_Gain_mqco * ((real_T)rtb_Switch1_pwrm)) +
    rtb_Divide_cv;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_m2) {
    rtb_Add1_f_idx = measure_P.Constant_Value_cq;
  }

  rtb_Add1_f_idx_1 = (1.0 / rtb_Add1_f_idx) * measure_P.Gain_Gain_mqco2;
  if (rtb_Compare_ky) {
    rtb_Switch1_ie = measure_P.Constant_Value_mqco2gbune;
  } else {
    rtb_Gain_pj = ((measure_DWork.UnitDelay1_DSTATE_dg + rtb_Add1_f_idx_1) *
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
    if (rtb_Gain_pj > measure_P.Constant_Value_lc) {
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

  if (((real_T)measure_B.SFunction_jf) < measure_P.Constant_Value_pu) {
    rtb_Gain6_re = measure_P.Constant_Value_mqco2gbunew;
  } else {
    rtb_Gain6_re = (real_T)measure_B.SFunction_jf;
  }

  rtb_Gain_pj = ((1.0 / rtb_Switch1_ie) * rtb_Gain6_re) -
    measure_DWork.UnitDelay1_DSTATE_dgzmvrp;
  if (rtb_Gain_pj < measure_P.Constant_Value_lg) {
    rtb_Add1_f_idx_0 = measure_P.Constant_Value_mqc;
  } else if (rtb_Gain_pj > measure_P.Constant_Value_mq) {
    rtb_Add1_f_idx_0 = measure_P.Constant1_Value_m;
  } else {
    rtb_Add1_f_idx_0 = rtb_Gain_pj;
  }

  rtb_MathFunction1 = rtb_Add1_f_idx_0 + measure_DWork.UnitDelay1_DSTATE_dgzmvrp;
  if (rtb_Compare_ky) {
    rtb_Switch1_pwrmjy = rtb_Switch_lli5ykm;
  } else {
    rtb_Switch1_pwrmjy = measure_P.int1_Value_mq;
  }

  rtb_Add1_f_idx_0 = std::exp((measure_P.Gain1_Gain_mqc * rtb_Switch1_ie) *
    measure_P.Gain2_Gain_mqc);
  rtb_UnaryMinus_l = (measure_P.double1_Value_m - rtb_Add1_f_idx_0) * rtb_Switch;
  rtb_Add1_f_idx = (measure_P.Gain1_Gain_mqco * rtb_Add1_f_idx) +
    measure_P.Bias_Bias_mqco;
  if (rtb_Add1_f_idx < measure_P.Constant_Value_eu) {
    rtb_Add1_f_idx = measure_P.Constant_Value_h1s;
  }

  rtb_Gain_pj = (measure_P.Gain_Gain_mqco2g * rtb_Add1_f_idx) +
    measure_P.Bias_Bias_mqco2;
  if (rtb_Gain_pj < measure_P.Constant_Value_ndf) {
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

  if (rtb_LogicalOperator1_pvh3 && (measure_P.Constant2_Value_mq)) {
    rtb_UnitDelay1_b = measure_B.SFunction_jft;
  } else {
    rtb_UnitDelay1_b = measure_DWork.UnitDelay_DSTATE_otrx -
      measure_P.FixPtConstant_Value_mq;
  }

  rtb_LogicalOperator1 = (rtb_UnitDelay1_b > measure_P.Constant_Value_i5n);
  if (rtb_LogicalOperator1) {
    rtb_Switch1_ia = rtb_UnitDelay1_b;
  } else {
    rtb_Switch1_ia = measure_P.int1_Value_mqc;
  }

  if (rtb_LogicalOperator1_pvh3) {
    rtb_UnitDelay1_b = measure_P.Constant_Value_ma;
  } else {
    rtb_UnitDelay1_b = rtb_UnitDelay1_lccp;
  }

  if (rtb_Switch6_idx) {
    rtb_Switch1_a = measure_P.int2_Value_a;
  }

  rtb_UnitDelay1_lccp = rtb_Switch1_a - measure_P.FixPtConstant_Value_p;
  measure_B.Gain1_nt = measure_P.Gain1_Gain_b * measure_U.Vabcpu[0];
  rtb_Ts_FFT_k *= measure_P.Gain5_Gain_li;
  if (rtb_Ts_FFT_k < measure_P.Constant_Value_fi) {
    rtb_Ts_FFT_k = measure_P.Constant_Value_bv;
  }

  rtb_Ts_FFT_k = 1.0 / rtb_Ts_FFT_k;
  measure_B.Gain8_o = measure_P.Gain8_Gain_l * rtb_Ts_FFT_k;

  {
    int_T ok = 1;
    real_T t,a,D1,D2,D3;
    real_T* FFT_Data = (real_T*)measure_B.SFunction_o1_m;
    D1 = measure_DWork.SFunction_RWORK_o[0] - measure_B.Gain1_nt;
    D2 = measure_DWork.SFunction_RWORK_o[1] - D1;
    D3 = measure_DWork.SFunction_RWORK_o[2] - D2;
    measure_B.SFunction_o2_d = measure_DWork.SFunction_RWORK_o[3] + 1;
    while (ok) {
      t = measure_B.SFunction_o2_d - measure_B.Gain8_o;
      ok = (t>=0);
      if (ok) {
        measure_B.SFunction_o2_d = t;
        a = measure_B.Gain1_nt + D1*measure_B.SFunction_o2_d;
        t = measure_B.SFunction_o2_d * (measure_B.SFunction_o2_d-1);
        a += D2*t*0.5;
        t *= (measure_B.SFunction_o2_d-2);
        a += D3*t/6;
        measure_DWork.SFunction_IWORK_g++;
        if (measure_DWork.SFunction_IWORK_g > (64-1) ) {
          measure_DWork.SFunction_IWORK_g= 0;
        }

        FFT_Data[measure_DWork.SFunction_IWORK_g]= a;
      }
    }

    measure_B.SFunction_o3_i = measure_DWork.SFunction_IWORK_g;
    measure_DWork.SFunction_RWORK_o[0] = measure_B.Gain1_nt;
    measure_DWork.SFunction_RWORK_o[1] = D1;
    measure_DWork.SFunction_RWORK_o[2] = D2;
    measure_DWork.SFunction_RWORK_o[3] = measure_B.SFunction_o2_d;
  }

  rtb_Gain_pj = ((real_T)(measure_B.SFunction_o3_i -
    measure_P.Constant2_Value_dh)) * rtb_Ts_FFT_k;
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_d = measure_DWork.RateTransition_Buffer0_kg;
  }

  for (i = 0; i < 11; i++) {
    rtb_Gain6_re = (((((measure_P.Gain2_Gain_b * measure_P.Constant9_Value[(i)])
                       * rtb_Gain_pj) +
                      measure_P.udegcompensationsinceusingvefreqoutputfromFFT_Bias_c)
                     + measure_B.RateTransition_d) + measure_P.Constant1_Value_o)
      / measure_P.Constant2_Value_hw;
    if (measure_P.Constant6_Value_iv5) {
      measure_B.Switch2_gu[(i)] = rtb_Gain6_re + measure_P.Bias2_Bias_iv;
    } else if (rtb_Gain6_re < measure_P.Constant_Value_iv5) {
      measure_B.Switch2_gu[(i)] = rtb_Gain6_re + measure_P.Bias_Bias_iv;
    } else {
      measure_B.Switch2_gu[(i)] = rtb_Gain6_re;
    }
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_gu;
    int32_T *y0 = measure_B.SFunction2_lk;
    for (i1=0; i1 < 11; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    memcpy((void *)(&measure_B.RateTransition_hc[0]), (void *)
           (&measure_B.SFunction_o1_m[0]), (sizeof(real_T)) << 6U);
  }

  measure_B.Gain1_m = measure_P.Gain1_Gain_k * measure_U.Vabcpu[1];
  rtb_Ts_FFT *= measure_P.Gain5_Gain_j;
  if (rtb_Ts_FFT < measure_P.Constant_Value_po) {
    rtb_Ts_FFT = measure_P.Constant_Value_n4;
  }

  rtb_Ts_FFT = 1.0 / rtb_Ts_FFT;
  measure_B.Gain8_p = measure_P.Gain8_Gain_d * rtb_Ts_FFT;

  {
    int_T ok = 1;
    real_T t,a,D1,D2,D3;
    real_T* FFT_Data = (real_T*)measure_B.SFunction_o1_j;
    D1 = measure_DWork.SFunction_RWORK_j[0] - measure_B.Gain1_m;
    D2 = measure_DWork.SFunction_RWORK_j[1] - D1;
    D3 = measure_DWork.SFunction_RWORK_j[2] - D2;
    measure_B.SFunction_o2_a = measure_DWork.SFunction_RWORK_j[3] + 1;
    while (ok) {
      t = measure_B.SFunction_o2_a - measure_B.Gain8_p;
      ok = (t>=0);
      if (ok) {
        measure_B.SFunction_o2_a = t;
        a = measure_B.Gain1_m + D1*measure_B.SFunction_o2_a;
        t = measure_B.SFunction_o2_a * (measure_B.SFunction_o2_a-1);
        a += D2*t*0.5;
        t *= (measure_B.SFunction_o2_a-2);
        a += D3*t/6;
        measure_DWork.SFunction_IWORK_p++;
        if (measure_DWork.SFunction_IWORK_p > (64-1) ) {
          measure_DWork.SFunction_IWORK_p= 0;
        }

        FFT_Data[measure_DWork.SFunction_IWORK_p]= a;
      }
    }

    measure_B.SFunction_o3_p = measure_DWork.SFunction_IWORK_p;
    measure_DWork.SFunction_RWORK_j[0] = measure_B.Gain1_m;
    measure_DWork.SFunction_RWORK_j[1] = D1;
    measure_DWork.SFunction_RWORK_j[2] = D2;
    measure_DWork.SFunction_RWORK_j[3] = measure_B.SFunction_o2_a;
  }

  rtb_Gain_pj = ((real_T)(measure_B.SFunction_o3_p -
    measure_P.Constant2_Value_ki)) * rtb_Ts_FFT;
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_l2 = measure_DWork.RateTransition_Buffer0_hw;
  }

  for (i = 0; i < 10; i++) {
    rtb_Gain6_re = (((((measure_P.Constant9_Value[i + 11] *
                        measure_P.Gain2_Gain_n) * rtb_Gain_pj) +
                      measure_P.udegcompensationsinceusingvefreqoutputfromFFT_Bias_f)
                     + measure_B.RateTransition_l2) +
                    measure_P.Constant1_Value_bc) / measure_P.Constant2_Value_m;
    if (measure_P.Constant6_Value_jl) {
      measure_B.Switch2_fz[(i)] = rtb_Gain6_re + measure_P.Bias2_Bias_jl;
    } else if (rtb_Gain6_re < measure_P.Constant_Value_jl) {
      measure_B.Switch2_fz[(i)] = rtb_Gain6_re + measure_P.Bias_Bias_jl;
    } else {
      measure_B.Switch2_fz[(i)] = rtb_Gain6_re;
    }
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_fz;
    int32_T *y0 = measure_B.SFunction2_fx;
    for (i1=0; i1 < 10; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    memcpy((void *)(&measure_B.RateTransition_cy[0]), (void *)
           (&measure_B.SFunction_o1_j[0]), (sizeof(real_T)) << 6U);
  }

  measure_B.Gain1_j = measure_P.Gain1_Gain_d * measure_U.Vabcpu[2];
  rtb_Switch4 *= measure_P.Gain5_Gain_l0;
  if (rtb_Switch4 < measure_P.Constant_Value_n0) {
    rtb_Switch4 = measure_P.Constant_Value_nq;
  }

  rtb_Gain_pj = 1.0 / rtb_Switch4;
  measure_B.Gain8_d = measure_P.Gain8_Gain_g * rtb_Gain_pj;

  {
    int_T ok = 1;
    real_T t,a,D1,D2,D3;
    real_T* FFT_Data = (real_T*)measure_B.SFunction_o1_is;
    D1 = measure_DWork.SFunction_RWORK_g[0] - measure_B.Gain1_j;
    D2 = measure_DWork.SFunction_RWORK_g[1] - D1;
    D3 = measure_DWork.SFunction_RWORK_g[2] - D2;
    measure_B.SFunction_o2_b = measure_DWork.SFunction_RWORK_g[3] + 1;
    while (ok) {
      t = measure_B.SFunction_o2_b - measure_B.Gain8_d;
      ok = (t>=0);
      if (ok) {
        measure_B.SFunction_o2_b = t;
        a = measure_B.Gain1_j + D1*measure_B.SFunction_o2_b;
        t = measure_B.SFunction_o2_b * (measure_B.SFunction_o2_b-1);
        a += D2*t*0.5;
        t *= (measure_B.SFunction_o2_b-2);
        a += D3*t/6;
        measure_DWork.SFunction_IWORK_k++;
        if (measure_DWork.SFunction_IWORK_k > (64-1) ) {
          measure_DWork.SFunction_IWORK_k= 0;
        }

        FFT_Data[measure_DWork.SFunction_IWORK_k]= a;
      }
    }

    measure_B.SFunction_o3_f = measure_DWork.SFunction_IWORK_k;
    measure_DWork.SFunction_RWORK_g[0] = measure_B.Gain1_j;
    measure_DWork.SFunction_RWORK_g[1] = D1;
    measure_DWork.SFunction_RWORK_g[2] = D2;
    measure_DWork.SFunction_RWORK_g[3] = measure_B.SFunction_o2_b;
  }

  rtb_Gain_pj *= (real_T)(measure_B.SFunction_o3_f - measure_P.Constant2_Value_b);
  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    measure_B.RateTransition_p = measure_DWork.RateTransition_Buffer0_kc;
  }

  for (i = 0; i < 10; i++) {
    rtb_Gain6_re = (((((measure_P.Constant9_Value[i + 21] *
                        measure_P.Gain2_Gain_bd) * rtb_Gain_pj) +
                      measure_P.udegcompensationsinceusingvefreqoutputfromFFT_Bias_p)
                     + measure_B.RateTransition_p) +
                    measure_P.Constant1_Value_io) / measure_P.Constant2_Value_p;
    if (measure_P.Constant6_Value_l) {
      measure_B.Switch2_b[(i)] = rtb_Gain6_re + measure_P.Bias2_Bias_l;
    } else if (rtb_Gain6_re < measure_P.Constant_Value_l4) {
      measure_B.Switch2_b[(i)] = rtb_Gain6_re + measure_P.Bias_Bias_l;
    } else {
      measure_B.Switch2_b[(i)] = rtb_Gain6_re;
    }
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_b;
    int32_T *y0 = measure_B.SFunction2_g0;
    for (i1=0; i1 < 10; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if ((measure_M->Timing.RateInteraction.TID0_1 == 1)) {
    memcpy((void *)(&measure_B.RateTransition_fo[0]), (void *)
           (&measure_B.SFunction_o1_is[0]), (sizeof(real_T)) << 6U);
  }

  measure_Y.TotalHarmonicsAnalysedIncludingFundamental =
    measure_P.Constant10_Value;

  {
    measure_DWork.SF_FixedDiscreteDelaySfunction_DSTATE = measure_B.Switch_bn;
  }

  measure_DWork.UnitDelay4_DSTATE_ir = rtb_LogicalOperator2_npqxol;
  measure_DWork.delay_DSTATE = !rtb_UnitDelay4_dq;
  measure_DWork.UnitDelay_DSTATE = rtb_Switch1;

  {
    measure_DWork.SF_FixedDiscreteDelaySfunction_DSTATE_b =
      measure_B.Switch2_h1wib;
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
  measure_DWork.UnitDelay2_DSTATE_h5brdqci = rtb_Divide_la;
  measure_DWork.delay_DSTATE_i2wj = !rtb_Compare_hpz455i02;
  measure_DWork.UnitDelay4_DSTATE_czl44j1 = measure_B.Switch2_h1w;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz = measure_B.Switch_nulzsg5;
  measure_DWork.UnitDelay_DSTATE_lmdw = rtb_Switch1_bt;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqh = rtb_FixPtSum1;
  measure_DWork.UnitDelay1_DSTATE_k = rtb_Switch1_pwrmj;
  measure_DWork.UnitDelay2_DSTATE_kg = rtb_Switch_k;
  measure_DWork.UnitDelay4_DSTATE_hj = rtb_LogicalOperator2_f3l;
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
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s4v = measure_B.Divide_h;
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35bvz = measure_B.Switch_lv2aps;
  measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s4vv = measure_B.Divide;
  measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35bvzo = measure_B.Switch_lv2aps4;
  measure_DWork.UnitDelay4_DSTATE_g = measure_B.Divide;
  measure_DWork.UnitDelay2_DSTATE_i = measure_B.Switch_lv2aps4n;
  measure_DWork.UnitDelay4_DSTATE_n = measure_B.Switch6;
  measure_DWork.UnitDelay2_DSTATE_a = measure_B.Switch_b;
  measure_DWork.delay_DSTATE_izxx = !rtb_Compare_ddcrdc;
  measure_DWork.UnitDelay4_DSTATE_d = measure_B.Switch6;
  measure_DWork.UnitDelay2_DSTATE_ai = measure_B.Switch_bo;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpn = rtb_FixPtSum1_ecsn;
  measure_DWork.UnitDelay_DSTATE_mj2f = rtb_LogicalOperator2_n;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnn = rtb_FixPtSum1_ec;
  measure_DWork.UnitDelay_DSTATE_m = rtb_Divide_nfu + rtb_SumofElements1;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno = rtb_FixPtSum1_e;

  {
    measure_DWork.SF_FixedDiscreteDelaySfunction_DSTATE_n =
      measure_B.DataTypeConversion;
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
  measure_DWork.UnitDelay_DSTATE_mj = rtb_TrigonometricFunction_hrx +
    rtb_Sum1_dat;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml = rtb_FixPtSum1_ecsns;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml3 = rtb_Switch1_dg2as;
  measure_DWork.UnitDelay_DSTATE_mj2fmb = rtb_LogicalOperator2_npqxo;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml3e = rtb_Switch1_mf0c25z;
  measure_DWork.UnitDelay_DSTATE_mj2 = rtb_TrigonometricFunction_hr +
    rtb_Sum1_kv;
  measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml3e2 = rtb_FixPtSum1_ecsnsvomv;
  measure_DWork.UnitDelay3_DSTATE_i5 = rtb_Add_n;
  measure_DWork.UnitDelay4_DSTATE_i = measure_B.Divide_b4;
  measure_DWork.UnitDelay2_DSTATE_m = measure_B.Switch_f0o4o;
  measure_DWork.UnitDelay4_DSTATE_n3 = measure_B.Divide_b4;
  measure_DWork.UnitDelay2_DSTATE_il = measure_B.Switch_f0o4ow;
  measure_DWork.UnitDelay4_DSTATE_a = measure_B.Divide_b;
  measure_DWork.UnitDelay2_DSTATE_b = measure_B.Switch_f0o4owl;
  measure_DWork.UnitDelay4_DSTATE_jk = measure_B.Divide_b;
  measure_DWork.UnitDelay2_DSTATE_hq = measure_B.Switch_f0o4owld;
  measure_DWork.UnitDelay4_DSTATE_p = measure_B.Switch6_j;
  measure_DWork.UnitDelay2_DSTATE_o = measure_B.Switch_f0o4owldo;
  measure_DWork.UnitDelay4_DSTATE_jg = measure_B.Switch6_j;
  measure_DWork.UnitDelay2_DSTATE_f = measure_B.Switch_f0o4owldoy;
  measure_DWork.UnitDelay3_DSTATE_i5z = rtb_Add_gl;
  measure_DWork.UnitDelay4_DSTATE_ih = measure_B.Divide_nq;
  measure_DWork.UnitDelay2_DSTATE_j = measure_B.Switch_ngeqq2;
  measure_DWork.UnitDelay4_DSTATE_m = measure_B.Divide_nq;
  measure_DWork.UnitDelay2_DSTATE_jm = measure_B.Switch_ngeqq2o;
  measure_DWork.UnitDelay4_DSTATE_j5 = measure_B.Divide_n;
  measure_DWork.UnitDelay2_DSTATE_c = measure_B.Switch_ngeqq2os;
  measure_DWork.UnitDelay4_DSTATE_dj = measure_B.Divide_n;
  measure_DWork.UnitDelay2_DSTATE_cm = measure_B.Switch_ngeqq2osh;
  measure_DWork.UnitDelay4_DSTATE_l = measure_B.Switch6_m;
  measure_DWork.UnitDelay2_DSTATE_p = measure_B.Switch_ngeqq2oshh;
  measure_DWork.UnitDelay4_DSTATE_h = measure_B.Switch6_m;
  measure_DWork.UnitDelay2_DSTATE_bf = measure_B.Switch_ngeqq2oshhr;
  measure_DWork.delay1_DSTATE_k = rtb_Compare_o;
  measure_DWork.UnitDelay4_DSTATE_e = measure_B.Switch_j;
  measure_DWork.UnitDelay2_DSTATE_e5 = measure_B.Switch_ll;
  measure_DWork.UnitDelay2_DSTATE_e5y = rtb_MathFunction1;
  measure_DWork.delay_DSTATE_j = !rtb_Compare_o;
  measure_DWork.UnitDelay4_DSTATE_ed = measure_B.Switch_j;
  measure_DWork.UnitDelay2_DSTATE_e5yc = measure_B.Switch_lli;
  measure_DWork.UnitDelay_DSTATE_ot = rtb_Switch1_pwrmjy;
  measure_DWork.UnitDelay_DSTATE_k = rtb_UnitDelay1_c;
  measure_DWork.delay1_DSTATE_b = rtb_Compare_js;
  measure_DWork.UnitDelay1_DSTATE_k2 = rtb_LogicalOperator2_f3;
  measure_DWork.UnitDelay4_DSTATE_mm = measure_B.MathFunction;
  measure_DWork.UnitDelay2_DSTATE_hi = measure_B.Switch_lv2aps4ne;
  measure_DWork.UnitDelay4_DSTATE_pb = measure_B.MathFunction;
  measure_DWork.UnitDelay2_DSTATE_iy = measure_B.Switch_lv2aps4ney;
  measure_DWork.UnitDelay4_DSTATE_md = measure_B.MathFunction1;
  measure_DWork.UnitDelay2_DSTATE_c0 = measure_B.Switch_lv2aps4neyb;
  measure_DWork.UnitDelay4_DSTATE_f = measure_B.MathFunction1;
  measure_DWork.UnitDelay2_DSTATE_cq = measure_B.Switch_lv2aps4neybf;
  measure_DWork.UnitDelay4_DSTATE_ps = measure_B.MathFunction_j;
  measure_DWork.UnitDelay2_DSTATE_d = measure_B.Switch_f0o4owldoyu;
  measure_DWork.UnitDelay4_DSTATE_k = measure_B.MathFunction_j;
  measure_DWork.UnitDelay2_DSTATE_o3 = measure_B.Switch_f0o4owldoyup;
  measure_DWork.UnitDelay4_DSTATE_mw = measure_B.MathFunction1_b;
  measure_DWork.UnitDelay2_DSTATE_d1 = measure_B.Switch_f0o4owldoyupv;
  measure_DWork.UnitDelay4_DSTATE_jz = measure_B.MathFunction1_b;
  measure_DWork.UnitDelay2_DSTATE_l = measure_B.Switch_f0o4owldoyupv1;
  measure_DWork.UnitDelay4_DSTATE_hx = measure_B.MathFunction_jy;
  measure_DWork.UnitDelay2_DSTATE_k0 = measure_B.Switch_ngeqq2oshhr5;
  measure_DWork.UnitDelay4_DSTATE_p4 = measure_B.MathFunction_jy;
  measure_DWork.UnitDelay2_DSTATE_lz = measure_B.Switch_ngeqq2oshhr5r;
  measure_DWork.UnitDelay4_DSTATE_b = measure_B.MathFunction1_bx;
  measure_DWork.UnitDelay2_DSTATE_ls = measure_B.Switch_ngeqq2oshhr5rh;
  measure_DWork.UnitDelay4_DSTATE_ay = measure_B.MathFunction1_bx;
  measure_DWork.UnitDelay2_DSTATE_a3 = measure_B.Switch_ngeqq2oshhr5rhh;
  measure_DWork.UnitDelay1_DSTATE_f = measure_U.IabcAmps[0];
  measure_DWork.UnitDelay2_DSTATE_mk = rtb_UnitDelay1_o;
  measure_DWork.UnitDelay4_DSTATE_do = measure_B.Product_j[0];
  measure_DWork.UnitDelay2_DSTATE_kx = measure_B.Switch_jp;
  measure_DWork.UnitDelay4_DSTATE_dot = measure_B.Product_j[0];
  measure_DWork.UnitDelay2_DSTATE_kxh = measure_B.Switch_jpt;
  measure_DWork.UnitDelay4_DSTATE_dotl = measure_B.Divide_nf;
  measure_DWork.UnitDelay2_DSTATE_kxh1 = measure_B.Switch_jptu;
  measure_DWork.UnitDelay4_DSTATE_dotln = measure_B.Divide_nf;
  measure_DWork.UnitDelay2_DSTATE_kxh1d = measure_B.Switch_jptuz;
  measure_DWork.UnitDelay4_DSTATE_dotlnl = measure_B.Product_j[1];
  measure_DWork.UnitDelay2_DSTATE_kxh1dd = measure_B.Switch_jptuzr;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp = measure_B.Product_j[1];
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb = measure_B.Switch_jptuzrl;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0 = measure_B.Divide_nfu;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb3 = measure_B.Switch_jptuzrlj;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0w = measure_B.Divide_nfu;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33 = measure_B.Switch_jptuzrljf;
  measure_DWork.UnitDelay1_DSTATE_d = measure_U.IabcAmps[1];
  measure_DWork.UnitDelay2_DSTATE_dz = rtb_UnitDelay1_f;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wv = measure_B.Product_jq[0];
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33g = measure_B.Switch_jptuzrljf0;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvp = measure_B.Product_jq[0];
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gq = measure_B.Switch_jptuzrljf05;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpy = measure_B.Divide_nfun;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqp = measure_B.Switch_jptuzrljf055;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpya = measure_B.Divide_nfun;
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpf = measure_B.Switch_jptuzrljf055w;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpyar = measure_B.Product_jq[1];
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpfj =
    measure_B.Switch_jptuzrljf055wg;
  measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpyari = measure_B.Product_jq[1];
  measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpfjt =
    measure_B.Switch_jptuzrljf055wg5;
  measure_DWork.UnitDelay4_DSTATE_ls = measure_B.Divide_nfunb;
  measure_DWork.UnitDelay2_DSTATE_n = measure_B.Switch_c;
  measure_DWork.UnitDelay4_DSTATE_gs = measure_B.Divide_nfunb;
  measure_DWork.UnitDelay2_DSTATE_oz = measure_B.Switch_jc;
  measure_DWork.UnitDelay1_DSTATE_b = measure_U.IabcAmps[2];
  measure_DWork.UnitDelay2_DSTATE_kb = rtb_UnitDelay1_pu;
  measure_DWork.UnitDelay4_DSTATE_hxo = measure_B.Product_jqy[0];
  measure_DWork.UnitDelay2_DSTATE_eo = measure_B.Switch_i;
  measure_DWork.UnitDelay4_DSTATE_gn = measure_B.Product_jqy[0];
  measure_DWork.UnitDelay2_DSTATE_pl = measure_B.Switch_h;
  measure_DWork.UnitDelay4_DSTATE_pz = measure_B.Divide_nfunba;
  measure_DWork.UnitDelay2_DSTATE_ck = measure_B.Switch_e;
  measure_DWork.UnitDelay4_DSTATE_d2 = measure_B.Divide_nfunba;
  measure_DWork.UnitDelay2_DSTATE_cs = measure_B.Switch_jce;
  measure_DWork.UnitDelay4_DSTATE_mz = measure_B.Product_jqy[1];
  measure_DWork.UnitDelay2_DSTATE_fe = measure_B.Switch_el;
  measure_DWork.UnitDelay4_DSTATE_am = measure_B.Product_jqy[1];
  measure_DWork.UnitDelay2_DSTATE_cx = measure_B.Switch_m;
  measure_DWork.UnitDelay4_DSTATE_nh = measure_B.Divide_nfunbaw;
  measure_DWork.UnitDelay2_DSTATE_n1 = measure_B.Switch_jx;
  measure_DWork.UnitDelay4_DSTATE_fu = measure_B.Divide_nfunbaw;
  measure_DWork.UnitDelay2_DSTATE_ko = measure_B.Switch_je;
  measure_DWork.UnitDelay4_DSTATE_m5 = measure_B.MathFunction_p;
  measure_DWork.UnitDelay2_DSTATE_ef = measure_B.Switch_p;
  measure_DWork.UnitDelay4_DSTATE_ee = measure_B.MathFunction_p;
  measure_DWork.UnitDelay2_DSTATE_mh = measure_B.Switch_pi;
  measure_DWork.UnitDelay4_DSTATE_ju = measure_B.MathFunction1_e;
  measure_DWork.UnitDelay2_DSTATE_or = measure_B.Switch_i0;
  measure_DWork.UnitDelay4_DSTATE_hz = measure_B.MathFunction1_e;
  measure_DWork.UnitDelay2_DSTATE_lt = measure_B.Switch_jv;
  measure_DWork.UnitDelay4_DSTATE_mb = measure_B.MathFunction_pc;
  measure_DWork.UnitDelay2_DSTATE_fq = measure_B.Switch_k;
  measure_DWork.UnitDelay4_DSTATE_fp = measure_B.MathFunction_pc;
  measure_DWork.UnitDelay2_DSTATE_d0 = measure_B.Switch_eh;
  measure_DWork.UnitDelay4_DSTATE_pm = measure_B.MathFunction1_ew;
  measure_DWork.UnitDelay2_DSTATE_mf = measure_B.Switch_o;
  measure_DWork.UnitDelay4_DSTATE_gf = measure_B.MathFunction1_ew;
  measure_DWork.UnitDelay2_DSTATE_pz = measure_B.Switch_d;
  measure_DWork.UnitDelay4_DSTATE_hc = measure_B.MathFunction_pcc;
  measure_DWork.UnitDelay2_DSTATE_gk = measure_B.Switch_ia;
  measure_DWork.UnitDelay4_DSTATE_gv = measure_B.MathFunction_pcc;
  measure_DWork.UnitDelay2_DSTATE_hh = measure_B.Switch_cp;
  measure_DWork.UnitDelay4_DSTATE_g0 = measure_B.MathFunction1_ew0;
  measure_DWork.UnitDelay2_DSTATE_cs5 = measure_B.Switch_cn;
  measure_DWork.UnitDelay4_DSTATE_jx = measure_B.MathFunction1_ew0;
  measure_DWork.UnitDelay2_DSTATE_fb = measure_B.Switch_g;
  measure_DWork.UnitDelay4_DSTATE_o = measure_B.VI[0];
  measure_DWork.UnitDelay2_DSTATE_n2 = measure_B.Switch_ez;
  measure_DWork.UnitDelay4_DSTATE_eq = measure_B.VI[0];
  measure_DWork.UnitDelay2_DSTATE_a5 = measure_B.Switch_h5;
  measure_DWork.UnitDelay4_DSTATE_gy = measure_B.Divide_d;
  measure_DWork.UnitDelay2_DSTATE_dq = measure_B.Switch_nh;
  measure_DWork.UnitDelay4_DSTATE_je = measure_B.Divide_d;
  measure_DWork.UnitDelay2_DSTATE_ou = measure_B.Switch_mm;
  measure_DWork.UnitDelay4_DSTATE_e1 = measure_B.VI[1];
  measure_DWork.UnitDelay2_DSTATE_ct = measure_B.Switch_gg;
  measure_DWork.UnitDelay4_DSTATE_iz = measure_B.VI[1];
  measure_DWork.UnitDelay2_DSTATE_fu = measure_B.Switch_p4;
  measure_DWork.UnitDelay4_DSTATE_mu = measure_B.Divide_g;
  measure_DWork.UnitDelay2_DSTATE_gs = measure_B.Switch_ml;
  measure_DWork.UnitDelay4_DSTATE_nw = measure_B.Divide_g;
  measure_DWork.UnitDelay2_DSTATE_p2 = measure_B.Switch_b1;
  measure_DWork.UnitDelay4_DSTATE_jf = measure_B.VI[2];
  measure_DWork.UnitDelay2_DSTATE_h2 = measure_B.Switch_ny;
  measure_DWork.UnitDelay4_DSTATE_lb = measure_B.VI[2];
  measure_DWork.UnitDelay2_DSTATE_ai5 = measure_B.Switch_n2;
  measure_DWork.UnitDelay4_DSTATE_co = measure_B.Divide_l;
  measure_DWork.UnitDelay2_DSTATE_lb = measure_B.Switch_bi;
  measure_DWork.UnitDelay4_DSTATE_j5o = measure_B.Divide_l;
  measure_DWork.UnitDelay2_DSTATE_cmh = measure_B.Switch_oh;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhw = rtb_FixPtSum1_cotnt;
  measure_DWork.delay_DSTATE_i2wj4 = rtb_LogicalOperator_nx;
  measure_DWork.UnitDelay_DSTATE_lmdwo = rtb_Switch1_hb;
  measure_DWork.UnitDelay_DSTATE_lmdwo300 = rtb_LogicalOperator1_fmgwx;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhwr = rtb_FixPtSum1_cotn;
  measure_DWork.UnitDelay_DSTATE_lmdwo300i = measure_P.Constant_Value_aqm;
  measure_DWork.UnitDelay1_DSTATE_cmnb3jxqhwrm = rtb_FixPtSum1_cot;
  measure_DWork.UnitDelay4_DSTATE_czl44j1i = measure_B.ACripple1stestimate;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0 = measure_B.Switch_nulzsg5y;
  measure_DWork.UnitDelay4_DSTATE_czl44j1ip = measure_B.ACripple1stestimate;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j = measure_B.Switch_nulzsg5yk;
  measure_DWork.UnitDelay1_DSTATE_c = rtb_Divide_nqz;
  measure_DWork.UnitDelay_DSTATE_lmdwo3 = rtb_Switch_nulzsg5ykq;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j45w = rtb_LogicalOperator9;
  measure_DWork.UnitDelay_DSTATE_lmd = rtb_ComplextoRealImag_o2_l +
    rtb_OutputWatts;
  measure_DWork.delay_DSTATE_i2wj4d = !rtb_LogicalOperator16;
  measure_DWork.delay1_DSTATE_ces = rtb_LogicalOperator16;
  measure_DWork.UnitDelay_DSTATE_lmdwo300ig = measure_P.Constant_Value_h0;
  measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j4 = rtb_Switch2_h;
  measure_DWork.UnitDelay1_DSTATE_cm = rtb_Divide_nqzy;
  measure_DWork.UnitDelay1_DSTATE_cmn = rtb_Divide_o1;
  measure_DWork.UnitDelay4_DSTATE_czl44j1ipa = rtb_Divide_o1;
  measure_DWork.UnitDelay1_DSTATE_cmnb = rtb_Switch_jka;
  measure_DWork.UnitDelay1_DSTATE_cmnb3 = rtb_Divide_i;
  measure_DWork.UnitDelay1_DSTATE_cmnb3j = rtb_Divide_la;
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
  measure_DWork.UnitDelay1_DSTATE_dg = rtb_Add1_f_idx_1;
  measure_DWork.UnitDelay_DSTATE_otr = rtb_UnitDelay1_b;
  measure_DWork.UnitDelay2_DSTATE_e5yc1iho = rtb_LogicalOperator1;
  measure_DWork.UnitDelay_DSTATE_o = (rtb_Sum2_i * rtb_Add1_f_idx_0) +
    rtb_UnaryMinus_l;
  measure_DWork.delay_DSTATE_j0 = !rtb_LogicalOperator2_npqx;
  measure_DWork.delay1_DSTATE_kz = rtb_LogicalOperator2_npqx;
  measure_DWork.UnitDelay_DSTATE_otrxo = measure_P.Constant_Value_df;
  measure_DWork.UnitDelay2_DSTATE_e5yc1ih = rtb_Switch1_pwrm;
  measure_DWork.UnitDelay1_DSTATE_dgz = rtb_Sum2_i;
  measure_DWork.UnitDelay1_DSTATE_dgzm = rtb_Switch1_iew;
  measure_DWork.UnitDelay4_DSTATE_eduao = rtb_Switch1_iew;
  measure_DWork.UnitDelay1_DSTATE_dgzmv = rtb_Divide_cv;
  measure_DWork.UnitDelay1_DSTATE_dgzmvr = rtb_Switch1_ie;
  measure_DWork.UnitDelay1_DSTATE_dgzmvrp = rtb_MathFunction1;
  measure_DWork.UnitDelay_DSTATE_otrx = rtb_Switch1_ia;
}

void measureModelClass::step1()
{
  real_T rtb_ComplextoMagnitudeAngle2_o2;
  real_T rtb_Sum2_op[31];
  real_T rtb_Divide_g[31];
  real_T rtb_ComplextoMagnitudeAngle2_o1;
  real_T rtb_Switch_gp;
  real_T rtb_Product1_a0[31];
  real_T rtb_ComplextoMagnitudeAngle2_o2_i;
  real_T rtb_ComplextoMagnitudeAngle2_o1_j;
  real_T rtb_Product1_ag[31];
  real_T rtb_ComplextoMagnitudeAngle2_o2_m;
  real_T rtb_ComplextoMagnitudeAngle2_o1_e;
  real_T rtb_Product1_d2[31];
  real_T rtb_ComplextoMagnitudeAngle2_o2_e;
  real_T rtb_ComplextoMagnitudeAngle2_o1_m;
  real_T rtb_Product1_at[31];
  real_T rtb_ComplextoMagnitudeAngle2_o2_g;
  real_T rtb_ComplextoMagnitudeAngle2_o1_k;
  real_T rtb_Product1_ii[31];
  real_T rtb_ComplextoMagnitudeAngle2_o2_a;
  real_T rtb_ComplextoMagnitudeAngle2_o1_c;
  creal_T rtb_FFT[64];
  real_T rtb_Sum3[31];
  real_T rtb_Sum3_n[31];
  real_T rtb_Sum3_a[31];
  real_T rtb_Sum3_o[31];
  real_T rtb_Sum3_i[31];
  int32_T i;
  real_T rtb_Divide_g_0;
  MWDSPCG_FFT_Interleave_R2BR_D(&measure_B.RateTransition_hd[0], &rtb_FFT[0U], 1,
    64);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT[0U], 1, 64, 32, 0, measure_ConstP.pooled1, 2,
                       FALSE);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT[0U], 1, 64, measure_ConstP.pooled1, 1);
  rtb_ComplextoMagnitudeAngle2_o1 = hypot(rtb_FFT[1].re, rtb_FFT[1].im);
  rtb_ComplextoMagnitudeAngle2_o2 = rt_atan2d_snf(rtb_FFT[1].im, rtb_FFT[1].re);
  for (i = 0; i < 31; i++) {
    rtb_Switch_gp = (rt_atan2d_snf(rtb_FFT[i + 2].im, rtb_FFT[i + 2].re) -
                     ((measure_P.Gain3_Gain_l[(i)] *
                       rtb_ComplextoMagnitudeAngle2_o2) +
                      measure_P.Bias1_Bias_d[(i)])) +
      measure_P.Constant1_Value_g;
    rtb_Divide_g_0 = rtb_Switch_gp / measure_P.Constant2_Value_l;
    if (measure_P.Constant6_Value_d) {
      measure_B.Switch2_p[(i)] = rtb_Divide_g_0 + measure_P.Bias2_Bias_e;
    } else if (rtb_Divide_g_0 < measure_P.Constant_Value_db) {
      measure_B.Switch2_p[(i)] = rtb_Divide_g_0 + measure_P.Bias_Bias_a;
    } else {
      measure_B.Switch2_p[(i)] = rtb_Divide_g_0;
    }

    rtb_Sum2_op[i] = rtb_Switch_gp;
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_p;
    int32_T *y0 = measure_B.SFunction2_b;
    for (i1=0; i1 < 31; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if (rtb_ComplextoMagnitudeAngle2_o1 < measure_P.Constant_Value_er) {
    rtb_Switch_gp = measure_P.Constant_Value_p;
  } else {
    rtb_Switch_gp = rtb_ComplextoMagnitudeAngle2_o1;
  }

  for (i = 0; i < 31; i++) {
    rtb_Sum3[i] = (rtb_Sum2_op[i] - (((real_T)measure_B.SFunction2_b[(i)]) *
      measure_P.Constant2_Value_l)) - measure_P.Constant1_Value_g;
    rtb_Product1_a0[i] = (1.0 / rtb_Switch_gp) * hypot(rtb_FFT[i + 2].re,
      rtb_FFT[i + 2].im);
  }

  MWDSPCG_FFT_Interleave_R2BR_D(&measure_B.RateTransition_la[0], &rtb_FFT[0U], 1,
    64);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT[0U], 1, 64, 32, 0, measure_ConstP.pooled1, 2,
                       FALSE);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT[0U], 1, 64, measure_ConstP.pooled1, 1);
  rtb_ComplextoMagnitudeAngle2_o1_j = hypot(rtb_FFT[1].re, rtb_FFT[1].im);
  rtb_ComplextoMagnitudeAngle2_o2_i = rt_atan2d_snf(rtb_FFT[1].im, rtb_FFT[1].re);
  for (i = 0; i < 31; i++) {
    rtb_Switch_gp = (rt_atan2d_snf(rtb_FFT[i + 2].im, rtb_FFT[i + 2].re) -
                     ((measure_P.Gain3_Gain_f[(i)] *
                       rtb_ComplextoMagnitudeAngle2_o2_i) +
                      measure_P.Bias1_Bias_a0[(i)])) +
      measure_P.Constant1_Value_d;
    rtb_Divide_g_0 = rtb_Switch_gp / measure_P.Constant2_Value_d;
    if (measure_P.Constant6_Value_h) {
      measure_B.Switch2_g[(i)] = rtb_Divide_g_0 + measure_P.Bias2_Bias_d;
    } else if (rtb_Divide_g_0 < measure_P.Constant_Value_px) {
      measure_B.Switch2_g[(i)] = rtb_Divide_g_0 + measure_P.Bias_Bias_ek;
    } else {
      measure_B.Switch2_g[(i)] = rtb_Divide_g_0;
    }

    rtb_Sum2_op[i] = rtb_Switch_gp;
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_g;
    int32_T *y0 = measure_B.SFunction2_j;
    for (i1=0; i1 < 31; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if (rtb_ComplextoMagnitudeAngle2_o1_j < measure_P.Constant_Value_kb) {
    rtb_Switch_gp = measure_P.Constant_Value_e;
  } else {
    rtb_Switch_gp = rtb_ComplextoMagnitudeAngle2_o1_j;
  }

  for (i = 0; i < 31; i++) {
    rtb_Sum3_n[i] = (rtb_Sum2_op[i] - (((real_T)measure_B.SFunction2_j[(i)]) *
      measure_P.Constant2_Value_d)) - measure_P.Constant1_Value_d;
    rtb_Product1_ag[i] = (1.0 / rtb_Switch_gp) * hypot(rtb_FFT[i + 2].re,
      rtb_FFT[i + 2].im);
  }

  MWDSPCG_FFT_Interleave_R2BR_D(&measure_B.RateTransition_mm[0], &rtb_FFT[0U], 1,
    64);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT[0U], 1, 64, 32, 0, measure_ConstP.pooled1, 2,
                       FALSE);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT[0U], 1, 64, measure_ConstP.pooled1, 1);
  rtb_ComplextoMagnitudeAngle2_o1_e = hypot(rtb_FFT[1].re, rtb_FFT[1].im);
  rtb_ComplextoMagnitudeAngle2_o2_m = rt_atan2d_snf(rtb_FFT[1].im, rtb_FFT[1].re);
  for (i = 0; i < 31; i++) {
    rtb_Switch_gp = (rt_atan2d_snf(rtb_FFT[i + 2].im, rtb_FFT[i + 2].re) -
                     ((measure_P.Gain3_Gain_o[(i)] *
                       rtb_ComplextoMagnitudeAngle2_o2_m) +
                      measure_P.Bias1_Bias_o3[(i)])) +
      measure_P.Constant1_Value_bk;
    rtb_Divide_g_0 = rtb_Switch_gp / measure_P.Constant2_Value_cs;
    if (measure_P.Constant6_Value_o) {
      measure_B.Switch2_j[(i)] = rtb_Divide_g_0 + measure_P.Bias2_Bias_g;
    } else if (rtb_Divide_g_0 < measure_P.Constant_Value_abn) {
      measure_B.Switch2_j[(i)] = rtb_Divide_g_0 + measure_P.Bias_Bias_d;
    } else {
      measure_B.Switch2_j[(i)] = rtb_Divide_g_0;
    }

    rtb_Sum2_op[i] = rtb_Switch_gp;
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_j;
    int32_T *y0 = measure_B.SFunction2_g;
    for (i1=0; i1 < 31; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if (rtb_ComplextoMagnitudeAngle2_o1_e < measure_P.Constant_Value_pc) {
    rtb_Switch_gp = measure_P.Constant_Value_g;
  } else {
    rtb_Switch_gp = rtb_ComplextoMagnitudeAngle2_o1_e;
  }

  for (i = 0; i < 31; i++) {
    rtb_Sum3_a[i] = (rtb_Sum2_op[i] - (((real_T)measure_B.SFunction2_g[(i)]) *
      measure_P.Constant2_Value_cs)) - measure_P.Constant1_Value_bk;
    rtb_Product1_d2[i] = (1.0 / rtb_Switch_gp) * hypot(rtb_FFT[i + 2].re,
      rtb_FFT[i + 2].im);
  }

  MWDSPCG_FFT_Interleave_R2BR_D(&measure_B.RateTransition_hc[0], &rtb_FFT[0U], 1,
    64);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT[0U], 1, 64, 32, 0, measure_ConstP.pooled1, 2,
                       FALSE);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT[0U], 1, 64, measure_ConstP.pooled1, 1);
  rtb_ComplextoMagnitudeAngle2_o1_m = hypot(rtb_FFT[1].re, rtb_FFT[1].im);
  rtb_ComplextoMagnitudeAngle2_o2_e = rt_atan2d_snf(rtb_FFT[1].im, rtb_FFT[1].re);
  for (i = 0; i < 31; i++) {
    rtb_Switch_gp = (rt_atan2d_snf(rtb_FFT[i + 2].im, rtb_FFT[i + 2].re) -
                     ((measure_P.Gain3_Gain_e[(i)] *
                       rtb_ComplextoMagnitudeAngle2_o2_e) +
                      measure_P.Bias1_Bias_p[(i)])) +
      measure_P.Constant1_Value_el;
    rtb_Divide_g_0 = rtb_Switch_gp / measure_P.Constant2_Value_ly;
    if (measure_P.Constant6_Value_fu) {
      measure_B.Switch2_e[(i)] = rtb_Divide_g_0 + measure_P.Bias2_Bias_j;
    } else if (rtb_Divide_g_0 < measure_P.Constant_Value_n4s) {
      measure_B.Switch2_e[(i)] = rtb_Divide_g_0 + measure_P.Bias_Bias_fy;
    } else {
      measure_B.Switch2_e[(i)] = rtb_Divide_g_0;
    }

    rtb_Sum2_op[i] = rtb_Switch_gp;
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_e;
    int32_T *y0 = measure_B.SFunction2_f;
    for (i1=0; i1 < 31; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if (rtb_ComplextoMagnitudeAngle2_o1_m < measure_P.Constant_Value_mz) {
    rtb_Switch_gp = measure_P.Constant_Value_ao;
  } else {
    rtb_Switch_gp = rtb_ComplextoMagnitudeAngle2_o1_m;
  }

  for (i = 0; i < 31; i++) {
    rtb_Sum3_o[i] = (rtb_Sum2_op[i] - (((real_T)measure_B.SFunction2_f[(i)]) *
      measure_P.Constant2_Value_ly)) - measure_P.Constant1_Value_el;
    rtb_Product1_at[i] = (1.0 / rtb_Switch_gp) * hypot(rtb_FFT[i + 2].re,
      rtb_FFT[i + 2].im);
  }

  MWDSPCG_FFT_Interleave_R2BR_D(&measure_B.RateTransition_cy[0], &rtb_FFT[0U], 1,
    64);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT[0U], 1, 64, 32, 0, measure_ConstP.pooled1, 2,
                       FALSE);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT[0U], 1, 64, measure_ConstP.pooled1, 1);
  rtb_ComplextoMagnitudeAngle2_o1_k = hypot(rtb_FFT[1].re, rtb_FFT[1].im);
  rtb_ComplextoMagnitudeAngle2_o2_g = rt_atan2d_snf(rtb_FFT[1].im, rtb_FFT[1].re);
  for (i = 0; i < 31; i++) {
    rtb_Switch_gp = (rt_atan2d_snf(rtb_FFT[i + 2].im, rtb_FFT[i + 2].re) -
                     ((measure_P.Gain3_Gain_k[(i)] *
                       rtb_ComplextoMagnitudeAngle2_o2_g) +
                      measure_P.Bias1_Bias_mn[(i)])) +
      measure_P.Constant1_Value_jx;
    rtb_Divide_g_0 = rtb_Switch_gp / measure_P.Constant2_Value_mi;
    if (measure_P.Constant6_Value_fd) {
      measure_B.Switch2_cw[(i)] = rtb_Divide_g_0 + measure_P.Bias2_Bias_k;
    } else if (rtb_Divide_g_0 < measure_P.Constant_Value_fj) {
      measure_B.Switch2_cw[(i)] = rtb_Divide_g_0 + measure_P.Bias_Bias_al;
    } else {
      measure_B.Switch2_cw[(i)] = rtb_Divide_g_0;
    }

    rtb_Sum2_op[i] = rtb_Switch_gp;
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_cw;
    int32_T *y0 = measure_B.SFunction2_m;
    for (i1=0; i1 < 31; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if (rtb_ComplextoMagnitudeAngle2_o1_k < measure_P.Constant_Value_c1) {
    rtb_Switch_gp = measure_P.Constant_Value_gb;
  } else {
    rtb_Switch_gp = rtb_ComplextoMagnitudeAngle2_o1_k;
  }

  for (i = 0; i < 31; i++) {
    rtb_Sum3_i[i] = (rtb_Sum2_op[i] - (((real_T)measure_B.SFunction2_m[(i)]) *
      measure_P.Constant2_Value_mi)) - measure_P.Constant1_Value_jx;
    rtb_Product1_ii[i] = (1.0 / rtb_Switch_gp) * hypot(rtb_FFT[i + 2].re,
      rtb_FFT[i + 2].im);
  }

  MWDSPCG_FFT_Interleave_R2BR_D(&measure_B.RateTransition_fo[0], &rtb_FFT[0U], 1,
    64);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT[0U], 1, 64, 32, 0, measure_ConstP.pooled1, 2,
                       FALSE);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT[0U], 1, 64, measure_ConstP.pooled1, 1);
  rtb_ComplextoMagnitudeAngle2_o1_c = hypot(rtb_FFT[1].re, rtb_FFT[1].im);
  rtb_ComplextoMagnitudeAngle2_o2_a = rt_atan2d_snf(rtb_FFT[1].im, rtb_FFT[1].re);
  for (i = 0; i < 31; i++) {
    rtb_Switch_gp = (rt_atan2d_snf(rtb_FFT[i + 2].im, rtb_FFT[i + 2].re) -
                     ((measure_P.Gain3_Gain_p[(i)] *
                       rtb_ComplextoMagnitudeAngle2_o2_a) +
                      measure_P.Bias1_Bias_ob[(i)])) +
      measure_P.Constant1_Value_n;
    rtb_Divide_g_0 = rtb_Switch_gp / measure_P.Constant2_Value_n;
    if (measure_P.Constant6_Value_l5) {
      measure_B.Switch2_g5[(i)] = rtb_Divide_g_0 + measure_P.Bias2_Bias_ix;
    } else if (rtb_Divide_g_0 < measure_P.Constant_Value_f2) {
      measure_B.Switch2_g5[(i)] = rtb_Divide_g_0 + measure_P.Bias_Bias_g;
    } else {
      measure_B.Switch2_g5[(i)] = rtb_Divide_g_0;
    }

    rtb_Sum2_op[i] = rtb_Switch_gp;
  }

  {
    int_T i1;
    const real_T *u0 = measure_B.Switch2_g5;
    int32_T *y0 = measure_B.SFunction2_o;
    for (i1=0; i1 < 31; i1++) {
      y0[i1] = (int32_T)u0[i1];
    }
  }

  if (rtb_ComplextoMagnitudeAngle2_o1_c < measure_P.Constant_Value_bp) {
    rtb_Switch_gp = measure_P.Constant_Value_gy;
  } else {
    rtb_Switch_gp = rtb_ComplextoMagnitudeAngle2_o1_c;
  }

  for (i = 0; i < 31; i++) {
    rtb_Divide_g[i] = (1.0 / rtb_Switch_gp) * hypot(rtb_FFT[i + 2].re, rtb_FFT[i
      + 2].im);
    rtb_Sum2_op[i] = (rtb_Sum2_op[i] - (((real_T)measure_B.SFunction2_o[(i)]) *
      measure_P.Constant2_Value_n)) - measure_P.Constant1_Value_n;
  }

  measure_DWork.RateTransition_Buffer0 = rtb_ComplextoMagnitudeAngle2_o1_m;
  measure_DWork.RateTransition_Buffer0_l = rtb_ComplextoMagnitudeAngle2_o1_k;
  measure_DWork.RateTransition_Buffer0_b = rtb_ComplextoMagnitudeAngle2_o1_c;
  memcpy((void *)measure_DWork.RateTransition_Buffer0_a, (void *)
         (&rtb_Product1_at[0]), 31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_j, (void *)
         (&rtb_Product1_ii[0]), 31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_ak, (void *)
         (&rtb_Divide_g[0]), 31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_h, (void *)(&rtb_Sum3_o[0]),
         31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_g, (void *)(&rtb_Sum3_i[0]),
         31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_hn, (void *)(&rtb_Sum2_op
          [0]), 31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_e, (void *)
         measure_P.Constant4_Value_m, 31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_lm, (void *)
         measure_P.Constant4_Value_p, 31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_az, (void *)
         measure_P.Constant4_Value_ph, 31U * (sizeof(real_T)));
  measure_DWork.RateTransition_Buffer0_m = rtb_ComplextoMagnitudeAngle2_o1;
  measure_DWork.RateTransition_Buffer0_bh = rtb_ComplextoMagnitudeAngle2_o1_j;
  measure_DWork.RateTransition_Buffer0_o = rtb_ComplextoMagnitudeAngle2_o1_e;
  memcpy((void *)measure_DWork.RateTransition_Buffer0_aq, (void *)
         (&rtb_Product1_a0[0]), 31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_oh, (void *)
         (&rtb_Product1_ag[0]), 31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_lg, (void *)
         (&rtb_Product1_d2[0]), 31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_n, (void *)(&rtb_Sum3[0]),
         31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_c, (void *)(&rtb_Sum3_n[0]),
         31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_cq, (void *)(&rtb_Sum3_a[0]),
         31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_mb, (void *)
         measure_P.Constant4_Value_f, 31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_of, (void *)
         measure_P.Constant4_Value_n, 31U * (sizeof(real_T)));
  memcpy((void *)measure_DWork.RateTransition_Buffer0_jc, (void *)
         measure_P.Constant4_Value_j, 31U * (sizeof(real_T)));
  measure_DWork.RateTransition_Buffer0_k = rtb_ComplextoMagnitudeAngle2_o2;
  measure_DWork.RateTransition_Buffer0_ki = rtb_ComplextoMagnitudeAngle2_o2_i;
  measure_DWork.RateTransition_Buffer0_jr = rtb_ComplextoMagnitudeAngle2_o2_m;
  measure_DWork.RateTransition_Buffer0_kg = rtb_ComplextoMagnitudeAngle2_o2_e;
  measure_DWork.RateTransition_Buffer0_hw = rtb_ComplextoMagnitudeAngle2_o2_g;
  measure_DWork.RateTransition_Buffer0_kc = rtb_ComplextoMagnitudeAngle2_o2_a;
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
    int32_T i;

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.SF_FixedDiscreteDelaySfunction_RWORK[0];
      int_T i;
      for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfunction_P1; i++)
        *(VDD_buffer++) = measure_P.SF_FixedDiscreteDelaySfunction_P2;
      measure_DWork.SF_FixedDiscreteDelaySfunction_DSTATE =
        measure_P.SF_FixedDiscreteDelaySfunction_P2;
      measure_DWork.SF_FixedDiscreteDelaySfunction_IWORK = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.SF_FixedDiscreteDelaySfunction_RWORK_b[0];
      int_T i;
      for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfunction_P1_j; i++)
        *(VDD_buffer++) = measure_P.SF_FixedDiscreteDelaySfunction_P2_j;
      measure_DWork.SF_FixedDiscreteDelaySfunction_DSTATE_b =
        measure_P.SF_FixedDiscreteDelaySfunction_P2_j;
      measure_DWork.SF_FixedDiscreteDelaySfunction_IWORK_c = 0;
    }

    measure_DWork.clockTickCounter = 0;
    measure_DWork.clockTickCounter_g = 0;

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_j+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jc+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3 = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4n[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcf
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3s = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_m[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_j+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_j = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4np[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfa+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3se = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4npp[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfaw+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3see = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mf[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jc
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_jn = 0;
    }

    measure_DWork.clockTickCounter_ge = 0;

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4npph[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawy+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3seeh = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4npphe[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawyw+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3seeh3 = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mf5[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jcf+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_jng = 0;
    }

    measure_DWork.clockTickCounter_i = 0;

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_j[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_o = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_je[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ds+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ob = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_a = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jel[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obu = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_ds
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_as = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2 = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5a[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2s = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3o[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asr = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5az[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2sv = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azs[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1h+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svt = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrw = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa
        [0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtg = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0[
        0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgp =
        0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwd = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0t
        [0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m04
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgpu =
        0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0te
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m041+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgpup =
        0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0i[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdn = 0;
    }

    measure_DWork.clockTickCounter_io = 0;
    measure_DWork.clockTickCounter_iom = 0;

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0tej
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5t+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgpupg
        = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0tejd
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5tt+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgpupg2
        = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0il[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jelr5azsa0tejde
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttd+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obui2svtgpupg2k
        = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_p[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdh+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_n = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilk
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf2 = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_l[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mz+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ny = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_e[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mzl
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_nv = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkv[
        0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mz
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25 =
        0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.SF_FixedDiscreteDelaySfunction_RWORK_j[0];
      int_T i;
      for (i = 0; i < measure_P.SF_FixedDiscreteDelaySfunction_P1_f; i++)
        *(VDD_buffer++) = measure_P.SF_FixedDiscreteDelaySfunction_P2_f;
      measure_DWork.SF_FixedDiscreteDelaySfunction_DSTATE_n =
        measure_P.SF_FixedDiscreteDelaySfunction_P2_f;
      measure_DWork.SF_FixedDiscreteDelaySfunction_IWORK_n = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_c[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hi+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_b = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_k[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiq+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_g = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvg
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g =
        0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_i[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqr+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_k = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_p0[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqru+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_e = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvgc
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1h+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g3 =
        0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_a[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_o+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_l = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_m[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_on+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_bh = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvgcl
        [0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_o+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g35
        = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ci[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_hh = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_f[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413r+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_c = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvgclo
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m04+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g35f
        = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_g[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rf+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_d = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_l2[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfk+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_m = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvgclom
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m041+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g35fl
        = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ii[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_a+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_i = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_id[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ao+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ep = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_p3ok0ilkvgclom3
        [0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_a+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_asrwdnf25g35flg
        = 0;
    }

    measure_DWork.clockTickCounter_h = 0;

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_px[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mq+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_gx = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bd[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mqc
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_mn = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_a[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mq
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_i = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_h[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhq+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_bf = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bo[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhqk+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_c0 = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_o[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5t+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_h = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_im[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhqkx+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_gm = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_hs[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dsc5ttdhqkxi+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_p = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_pe[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_dsc5tt+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_m = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_n[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruq+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_dt = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_d[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruqx+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_pt = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_j[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1hi+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_k = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_em[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruqxi+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_pv = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_iz[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_d1m1hiqruqxix+
            1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_eu = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_js[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d1m1hiq+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_ka = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ih[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkr+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_a = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ej[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkrd+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ls = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_l[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0413+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_iy = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_gs[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkrd2+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_bx = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ne[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_m0413rfkrd2o+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_mo = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_pg[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_m0413r+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_e = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fx[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ln = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxf[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_c[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfz[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1r
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1 = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzv[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1ro+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1v = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3 = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvg[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1ror+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vh = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgo[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhz = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1r+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3m = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgoh[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhza = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohd
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3y[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1ro+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3my = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdy[
        0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0 =
        0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdyf
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1h+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0h =
        0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3yn[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1ror+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdyfs
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hu+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0hw =
        0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdyfso
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hup+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0hw1
        = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynu[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1 = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdyfsol
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hupm+
            1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0hw1b
        = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fxfzvgohdyfsolg
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hupmn
            +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lnk1vhzad0hw1bl
        = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynuk[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1u = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ab[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_e1rorg3e1hupmn0
            +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_j = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_jec[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_c+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_go = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukf
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz =
        0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_no[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_h+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_od = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ni[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_om+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_b1 = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfc[
        0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz5 =
        0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b3[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_k+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ir = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_i0[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_b+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_nf = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcn
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1h+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz53 =
        0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_d5[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_cj+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_f = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_nk[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_di+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_cg = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcns
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hu+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz53e
        = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_le[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_l+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_cp = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_pl[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ly+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ox = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcns4
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hup+
            1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz53er
        = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_e5[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_f+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_gs = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_dx[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_hs+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_bt = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcns4k
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupm
            +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz53erg
        = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_kt[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ma+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_nyj = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_l5[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_c1+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_me = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcns4km
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupmn
            +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_mt3myh1uz53ergf
        = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bz[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ai+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_lne = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ac[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_p+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_dw = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_cb3ynukfcns4kmg
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_e1rorg3e1hupmn0
            +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_hd = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_hz[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_hu+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_i0 = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_i1[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_bg+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_la = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_a1[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_c+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_d = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_o[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ob+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_er = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_kw[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_g+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_j3 = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_g[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_h+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_p = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_gc[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_n+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_ky = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_pe[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ec+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_hb = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_i[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_om
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_ks = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ec[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_ae+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_kj = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ecu[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_cu+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_kjh = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_pp[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_l+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_ah = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fi[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_i+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_op = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_fie[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_l2+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_opo = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_k[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_k+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_ju = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ep[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_l4+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obd = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_epo[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_nm+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_obdq = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mfe[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mv
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_f = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bb[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_pt+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_of = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bbn[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_dil
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_of2 = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_of[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jx
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_g = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bm[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_c3+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_jp = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_bmy[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_hb+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_jpu = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mw[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_c2
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_hl = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_g5[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_nc+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_fn = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_g51[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_o0+
                       1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_fny = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_ofy[0];
      int_T i;
      for (i = 0; i < (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_d5
                       +1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_as5 = 0;
    }

    measure_B.RateTransition = measure_P.RateTransition_X0;
    measure_B.RateTransition_o = measure_P.RateTransition_X0_p;
    measure_B.RateTransition_g = measure_P.RateTransition_X0_k;
    measure_B.RateTransition_l = measure_P.RateTransition_X0_fm;
    measure_B.RateTransition_gq = measure_P.RateTransition_X0_n;
    measure_B.RateTransition_a0 = measure_P.RateTransition_X0_pq;
    for (i = 0; i < 31; i++) {
      measure_B.RateTransition_gf[(i)] = measure_P.RateTransition_X0_e;
      measure_B.RateTransition_gw[(i)] = measure_P.RateTransition_X0_l;
      measure_B.RateTransition_n[(i)] = measure_P.RateTransition_X0_j;
      measure_B.RateTransition_h[(i)] = measure_P.RateTransition_X0_c;
      measure_B.RateTransition_k[(i)] = measure_P.RateTransition_X0_f;
      measure_B.RateTransition_b[(i)] = measure_P.RateTransition_X0_pv;
      measure_B.RateTransition_a[(i)] = measure_P.RateTransition_X0_jr;
      measure_B.RateTransition_gy[(i)] = measure_P.RateTransition_X0_lt;
      measure_B.RateTransition_m[(i)] = measure_P.RateTransition_X0_b;
      measure_B.RateTransition_j[(i)] = measure_P.RateTransition_X0_bd;
      measure_B.RateTransition_c[(i)] = measure_P.RateTransition_X0_m;
      measure_B.RateTransition_ax[(i)] = measure_P.RateTransition_X0_jt;
      measure_B.RateTransition_jz[(i)] = measure_P.RateTransition_X0_d;
      measure_B.RateTransition_h2[(i)] = measure_P.RateTransition_X0_fr;
      measure_B.RateTransition_cc[(i)] = measure_P.RateTransition_X0_bf;
      measure_B.RateTransition_mz[(i)] = measure_P.RateTransition_X0_ny;
      measure_B.RateTransition_jt[(i)] = measure_P.RateTransition_X0_jq;
      measure_B.RateTransition_f[(i)] = measure_P.RateTransition_X0_g;
    }

    {
      measure_DWork.SFunction_RWORK[0] = 0.0;
      measure_DWork.SFunction_RWORK[1] = 0.0;
      measure_DWork.SFunction_RWORK[2] = 0.0;
      measure_DWork.SFunction_RWORK[3] = 0.0;
      measure_DWork.SFunction_IWORK = -1;
    }

    measure_B.RateTransition_cq = measure_P.RateTransition_X0_le;

    {
      measure_DWork.SFunction_RWORK_i[0] = 0.0;
      measure_DWork.SFunction_RWORK_i[1] = 0.0;
      measure_DWork.SFunction_RWORK_i[2] = 0.0;
      measure_DWork.SFunction_RWORK_i[3] = 0.0;
      measure_DWork.SFunction_IWORK_m = -1;
    }

    measure_B.RateTransition_lr = measure_P.RateTransition_X0_e5;

    {
      measure_DWork.SFunction_RWORK_c[0] = 0.0;
      measure_DWork.SFunction_RWORK_c[1] = 0.0;
      measure_DWork.SFunction_RWORK_c[2] = 0.0;
      measure_DWork.SFunction_RWORK_c[3] = 0.0;
      measure_DWork.SFunction_IWORK_l = -1;
    }

    measure_B.RateTransition_aj = measure_P.RateTransition_X0_lea;

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4npphe4[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawyw2+1); i
           ++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3seeh3o = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_b4npphe4j
        [0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_jcfawyw2o+1);
           i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_h3seeh3od = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mf50[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_jcfa+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_jngr = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_hh[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mqco+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_dtp = 0;
    }

    {
      real_T *VDD_buffer = (real_T*)
        &measure_DWork.VariableDiscreteDelaywithOneTapSfunction_RWORK_ii3[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithOneTapSfunction_P1_mqco2+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithOneTapSfunction_IWORK_fy = 0;
    }

    {
      real_T *VDD_buffer =
        &measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_RWORK_mj[0];
      int_T i;
      for (i = 0; i <
           (measure_P.VariableDiscreteDelaywithTwoTapsSfunction_P1_mqc+1); i++)
        *(VDD_buffer++) = 0.0;
      measure_DWork.VariableDiscreteDelaywithTwoTapsSfunction_IWORK_fz = 0;
    }

    {
      measure_DWork.SFunction_RWORK_o[0] = 0.0;
      measure_DWork.SFunction_RWORK_o[1] = 0.0;
      measure_DWork.SFunction_RWORK_o[2] = 0.0;
      measure_DWork.SFunction_RWORK_o[3] = 0.0;
      measure_DWork.SFunction_IWORK_g = -1;
    }

    measure_B.RateTransition_d = measure_P.RateTransition_X0_ns;

    {
      measure_DWork.SFunction_RWORK_j[0] = 0.0;
      measure_DWork.SFunction_RWORK_j[1] = 0.0;
      measure_DWork.SFunction_RWORK_j[2] = 0.0;
      measure_DWork.SFunction_RWORK_j[3] = 0.0;
      measure_DWork.SFunction_IWORK_p = -1;
    }

    measure_B.RateTransition_l2 = measure_P.RateTransition_X0_o;

    {
      measure_DWork.SFunction_RWORK_g[0] = 0.0;
      measure_DWork.SFunction_RWORK_g[1] = 0.0;
      measure_DWork.SFunction_RWORK_g[2] = 0.0;
      measure_DWork.SFunction_RWORK_g[3] = 0.0;
      measure_DWork.SFunction_IWORK_k = -1;
    }

    measure_B.RateTransition_p = measure_P.RateTransition_X0_k5;
  }

  {
    int32_T i;
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
    measure_DWork.UnitDelay2_DSTATE_h5brdqciz =
      measure_P.UnitDelay2_X0_jcfawyw2o;
    measure_DWork.UnitDelay_DSTATE_lmdw = measure_P.UnitDelay_X0_jcfa;
    measure_DWork.UnitDelay1_DSTATE_cmnb3jxqh =
      measure_P.UnitDelay1_X0_jcfawyw2o;
    measure_DWork.UnitDelay1_DSTATE_k = measure_P.UnitDelay1_X0_h;
    measure_DWork.UnitDelay2_DSTATE_kg = measure_P.UnitDelay2_X0_m;
    measure_DWork.UnitDelay4_DSTATE_hj = measure_P.UnitDelay4_X0_ll;
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
    measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s4 =
      measure_P.UnitDelay4_X0_dsc5t;
    measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35bv =
      measure_P.UnitDelay2_X0_dsc5t;
    measure_DWork.delay_DSTATE_izx = measure_P.delay_X0_ep;
    measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s4v =
      measure_P.UnitDelay4_X0_dsc5tt;
    measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35bvz =
      measure_P.UnitDelay2_X0_dsc5tt;
    measure_DWork.UnitDelay4_DSTATE_jbkwmsq2kv2s4vv =
      measure_P.UnitDelay4_X0_dsc5ttd;
    measure_DWork.UnitDelay2_DSTATE_gbjgk5qbx35bvzo =
      measure_P.UnitDelay2_X0_dsc5ttd;
    measure_DWork.UnitDelay4_DSTATE_g = measure_P.UnitDelay4_X0_dsc5ttdh;
    measure_DWork.UnitDelay2_DSTATE_i = measure_P.UnitDelay2_X0_dsc5ttdh;
    measure_DWork.UnitDelay4_DSTATE_n = measure_P.UnitDelay4_X0_mz;
    measure_DWork.UnitDelay2_DSTATE_a = measure_P.UnitDelay2_X0_mz;
    measure_DWork.delay_DSTATE_izxx = measure_P.delay_X0_ep3;
    measure_DWork.UnitDelay4_DSTATE_d = measure_P.UnitDelay4_X0_mzl;
    measure_DWork.UnitDelay2_DSTATE_ai = measure_P.UnitDelay2_X0_mzl;
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
    measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml3e = measure_P.UnitDelay1_X0_my;
    measure_DWork.UnitDelay_DSTATE_mj2 = measure_P.UnitDelay_X0_jn;
    measure_DWork.UnitDelay1_DSTATE_aqjzxpnno4ml3e2 =
      measure_P.UnitDelay1_X0_my5;
    measure_DWork.UnitDelay3_DSTATE_i5 = measure_P.UnitDelay3_X0_i;
    measure_DWork.UnitDelay4_DSTATE_i = measure_P.UnitDelay4_X0_d1m1hi;
    measure_DWork.UnitDelay2_DSTATE_m = measure_P.UnitDelay2_X0_d1m1hi;
    measure_DWork.UnitDelay4_DSTATE_n3 = measure_P.UnitDelay4_X0_d1m1hiq;
    measure_DWork.UnitDelay2_DSTATE_il = measure_P.UnitDelay2_X0_d1m1hiq;
    measure_DWork.UnitDelay4_DSTATE_a = measure_P.UnitDelay4_X0_d1m1hiqr;
    measure_DWork.UnitDelay2_DSTATE_b = measure_P.UnitDelay2_X0_d1m1hiqr;
    measure_DWork.UnitDelay4_DSTATE_jk = measure_P.UnitDelay4_X0_d1m1hiqru;
    measure_DWork.UnitDelay2_DSTATE_hq = measure_P.UnitDelay2_X0_d1m1hiqru;
    measure_DWork.UnitDelay4_DSTATE_p = measure_P.UnitDelay4_X0_o;
    measure_DWork.UnitDelay2_DSTATE_o = measure_P.UnitDelay2_X0_o;
    measure_DWork.UnitDelay4_DSTATE_jg = measure_P.UnitDelay4_X0_on;
    measure_DWork.UnitDelay2_DSTATE_f = measure_P.UnitDelay2_X0_on;
    measure_DWork.UnitDelay3_DSTATE_i5z = measure_P.UnitDelay3_X0_o;
    measure_DWork.UnitDelay4_DSTATE_ih = measure_P.UnitDelay4_X0_m0413;
    measure_DWork.UnitDelay2_DSTATE_j = measure_P.UnitDelay2_X0_m0413r;
    measure_DWork.UnitDelay4_DSTATE_m = measure_P.UnitDelay4_X0_m0413r;
    measure_DWork.UnitDelay2_DSTATE_jm = measure_P.UnitDelay2_X0_m0413rf;
    measure_DWork.UnitDelay4_DSTATE_j5 = measure_P.UnitDelay4_X0_m0413rf;
    measure_DWork.UnitDelay2_DSTATE_c = measure_P.UnitDelay2_X0_m0413rfk;
    measure_DWork.UnitDelay4_DSTATE_dj = measure_P.UnitDelay4_X0_m0413rfk;
    measure_DWork.UnitDelay2_DSTATE_cm = measure_P.UnitDelay2_X0_m0413rfkr;
    measure_DWork.UnitDelay4_DSTATE_l = measure_P.UnitDelay4_X0_a;
    measure_DWork.UnitDelay2_DSTATE_p = measure_P.UnitDelay2_X0_a;
    measure_DWork.UnitDelay4_DSTATE_h = measure_P.UnitDelay4_X0_ao;
    measure_DWork.UnitDelay2_DSTATE_bf = measure_P.UnitDelay2_X0_ao;
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
    measure_DWork.UnitDelay4_DSTATE_mm = measure_P.UnitDelay4_X0_dsc5ttdhq;
    measure_DWork.UnitDelay2_DSTATE_hi = measure_P.UnitDelay2_X0_dsc5ttdhq;
    measure_DWork.UnitDelay4_DSTATE_pb = measure_P.UnitDelay4_X0_dsc5ttdhqk;
    measure_DWork.UnitDelay2_DSTATE_iy = measure_P.UnitDelay2_X0_dsc5ttdhqk;
    measure_DWork.UnitDelay4_DSTATE_md = measure_P.UnitDelay4_X0_dsc5ttdhqkx;
    measure_DWork.UnitDelay2_DSTATE_c0 = measure_P.UnitDelay2_X0_dsc5ttdhqkx;
    measure_DWork.UnitDelay4_DSTATE_f = measure_P.UnitDelay4_X0_dsc5ttdhqkxi;
    measure_DWork.UnitDelay2_DSTATE_cq = measure_P.UnitDelay2_X0_dsc5ttdhqkxi;
    measure_DWork.UnitDelay4_DSTATE_ps = measure_P.UnitDelay4_X0_d1m1hiqruq;
    measure_DWork.UnitDelay2_DSTATE_d = measure_P.UnitDelay2_X0_d1m1hiqruq;
    measure_DWork.UnitDelay4_DSTATE_k = measure_P.UnitDelay4_X0_d1m1hiqruqx;
    measure_DWork.UnitDelay2_DSTATE_o3 = measure_P.UnitDelay2_X0_d1m1hiqruqx;
    measure_DWork.UnitDelay4_DSTATE_mw = measure_P.UnitDelay4_X0_d1m1hiqruqxi;
    measure_DWork.UnitDelay2_DSTATE_d1 = measure_P.UnitDelay2_X0_d1m1hiqruqxi;
    measure_DWork.UnitDelay4_DSTATE_jz = measure_P.UnitDelay4_X0_d1m1hiqruqxix;
    measure_DWork.UnitDelay2_DSTATE_l = measure_P.UnitDelay2_X0_d1m1hiqruqxix;
    measure_DWork.UnitDelay4_DSTATE_hx = measure_P.UnitDelay4_X0_m0413rfkr;
    measure_DWork.UnitDelay2_DSTATE_k0 = measure_P.UnitDelay2_X0_m0413rfkrd;
    measure_DWork.UnitDelay4_DSTATE_p4 = measure_P.UnitDelay4_X0_m0413rfkrd;
    measure_DWork.UnitDelay2_DSTATE_lz = measure_P.UnitDelay2_X0_m0413rfkrd2;
    measure_DWork.UnitDelay4_DSTATE_b = measure_P.UnitDelay4_X0_m0413rfkrd2;
    measure_DWork.UnitDelay2_DSTATE_ls = measure_P.UnitDelay2_X0_m0413rfkrd2o;
    measure_DWork.UnitDelay4_DSTATE_ay = measure_P.UnitDelay4_X0_m0413rfkrd2o;
    measure_DWork.UnitDelay2_DSTATE_a3 = measure_P.UnitDelay2_X0_m0413rfkrd2oa;
    measure_DWork.UnitDelay1_DSTATE_f = measure_P.UnitDelay1_X0_f;
    measure_DWork.UnitDelay2_DSTATE_mk = measure_P.UnitDelay2_X0_mu;
    measure_DWork.UnitDelay4_DSTATE_do = measure_P.UnitDelay4_X0_e;
    measure_DWork.UnitDelay2_DSTATE_kx = measure_P.UnitDelay2_X0_e1;
    measure_DWork.UnitDelay4_DSTATE_dot = measure_P.UnitDelay4_X0_e1;
    measure_DWork.UnitDelay2_DSTATE_kxh = measure_P.UnitDelay2_X0_e1r;
    measure_DWork.UnitDelay4_DSTATE_dotl = measure_P.UnitDelay4_X0_e1r;
    measure_DWork.UnitDelay2_DSTATE_kxh1 = measure_P.UnitDelay2_X0_e1ro;
    measure_DWork.UnitDelay4_DSTATE_dotln = measure_P.UnitDelay4_X0_e1ro;
    measure_DWork.UnitDelay2_DSTATE_kxh1d = measure_P.UnitDelay2_X0_e1ror;
    measure_DWork.UnitDelay4_DSTATE_dotlnl = measure_P.UnitDelay4_X0_e1ror;
    measure_DWork.UnitDelay2_DSTATE_kxh1dd = measure_P.UnitDelay2_X0_e1rorg;
    measure_DWork.UnitDelay4_DSTATE_dotlnlp = measure_P.UnitDelay4_X0_e1rorg;
    measure_DWork.UnitDelay2_DSTATE_kxh1ddb = measure_P.UnitDelay2_X0_e1rorg3;
    measure_DWork.UnitDelay4_DSTATE_dotlnlp0 = measure_P.UnitDelay4_X0_e1rorg3;
    measure_DWork.UnitDelay2_DSTATE_kxh1ddb3 = measure_P.UnitDelay2_X0_e1rorg3e;
    measure_DWork.UnitDelay4_DSTATE_dotlnlp0w = measure_P.UnitDelay4_X0_e1rorg3e;
    measure_DWork.UnitDelay2_DSTATE_kxh1ddb33 =
      measure_P.UnitDelay2_X0_e1rorg3e1;
    measure_DWork.UnitDelay1_DSTATE_d = measure_P.UnitDelay1_X0_az;
    measure_DWork.UnitDelay2_DSTATE_dz = measure_P.UnitDelay2_X0_n;
    measure_DWork.UnitDelay4_DSTATE_dotlnlp0wv =
      measure_P.UnitDelay4_X0_e1rorg3e1;
    measure_DWork.UnitDelay2_DSTATE_kxh1ddb33g =
      measure_P.UnitDelay2_X0_e1rorg3e1h;
    measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvp =
      measure_P.UnitDelay4_X0_e1rorg3e1h;
    measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gq =
      measure_P.UnitDelay2_X0_e1rorg3e1hu;
    measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpy =
      measure_P.UnitDelay4_X0_e1rorg3e1hu;
    measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqp =
      measure_P.UnitDelay2_X0_e1rorg3e1hup;
    measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpya =
      measure_P.UnitDelay4_X0_e1rorg3e1hup;
    measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpf =
      measure_P.UnitDelay2_X0_e1rorg3e1hupm;
    measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpyar =
      measure_P.UnitDelay4_X0_e1rorg3e1hupm;
    measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpfj =
      measure_P.UnitDelay2_X0_e1rorg3e1hupmn;
    measure_DWork.UnitDelay4_DSTATE_dotlnlp0wvpyari =
      measure_P.UnitDelay4_X0_e1rorg3e1hupmn;
    measure_DWork.UnitDelay2_DSTATE_kxh1ddb33gqpfjt =
      measure_P.UnitDelay2_X0_e1rorg3e1hupmn0;
    measure_DWork.UnitDelay4_DSTATE_ls = measure_P.UnitDelay4_X0_e1rorg3e1hupmn0;
    measure_DWork.UnitDelay2_DSTATE_n = measure_P.UnitDelay2_X0_cb;
    measure_DWork.UnitDelay4_DSTATE_gs = measure_P.UnitDelay4_X0_c;
    measure_DWork.UnitDelay2_DSTATE_oz = measure_P.UnitDelay2_X0_h;
    measure_DWork.UnitDelay1_DSTATE_b = measure_P.UnitDelay1_X0_mx;
    measure_DWork.UnitDelay2_DSTATE_kb = measure_P.UnitDelay2_X0_ne;
    measure_DWork.UnitDelay4_DSTATE_hxo = measure_P.UnitDelay4_X0_h;
    measure_DWork.UnitDelay2_DSTATE_eo = measure_P.UnitDelay2_X0_om;
    measure_DWork.UnitDelay4_DSTATE_gn = measure_P.UnitDelay4_X0_om;
    measure_DWork.UnitDelay2_DSTATE_pl = measure_P.UnitDelay2_X0_k;
    measure_DWork.UnitDelay4_DSTATE_pz = measure_P.UnitDelay4_X0_k;
    measure_DWork.UnitDelay2_DSTATE_ck = measure_P.UnitDelay2_X0_b;
    measure_DWork.UnitDelay4_DSTATE_d2 = measure_P.UnitDelay4_X0_b;
    measure_DWork.UnitDelay2_DSTATE_cs = measure_P.UnitDelay2_X0_cj;
    measure_DWork.UnitDelay4_DSTATE_mz = measure_P.UnitDelay4_X0_cj;
    measure_DWork.UnitDelay2_DSTATE_fe = measure_P.UnitDelay2_X0_di;
    measure_DWork.UnitDelay4_DSTATE_am = measure_P.UnitDelay4_X0_di;
    measure_DWork.UnitDelay2_DSTATE_cx = measure_P.UnitDelay2_X0_l;
    measure_DWork.UnitDelay4_DSTATE_nh = measure_P.UnitDelay4_X0_l;
    measure_DWork.UnitDelay2_DSTATE_n1 = measure_P.UnitDelay2_X0_ly;
    measure_DWork.UnitDelay4_DSTATE_fu = measure_P.UnitDelay4_X0_ly;
    measure_DWork.UnitDelay2_DSTATE_ko = measure_P.UnitDelay2_X0_f;
    measure_DWork.UnitDelay4_DSTATE_m5 = measure_P.UnitDelay4_X0_f;
    measure_DWork.UnitDelay2_DSTATE_ef = measure_P.UnitDelay2_X0_hs;
    measure_DWork.UnitDelay4_DSTATE_ee = measure_P.UnitDelay4_X0_hs;
    measure_DWork.UnitDelay2_DSTATE_mh = measure_P.UnitDelay2_X0_ma;
    measure_DWork.UnitDelay4_DSTATE_ju = measure_P.UnitDelay4_X0_ma;
    measure_DWork.UnitDelay2_DSTATE_or = measure_P.UnitDelay2_X0_c1;
    measure_DWork.UnitDelay4_DSTATE_hz = measure_P.UnitDelay4_X0_c1;
    measure_DWork.UnitDelay2_DSTATE_lt = measure_P.UnitDelay2_X0_ai;
    measure_DWork.UnitDelay4_DSTATE_mb = measure_P.UnitDelay4_X0_ai;
    measure_DWork.UnitDelay2_DSTATE_fq = measure_P.UnitDelay2_X0_p;
    measure_DWork.UnitDelay4_DSTATE_fp = measure_P.UnitDelay4_X0_p;
    measure_DWork.UnitDelay2_DSTATE_d0 = measure_P.UnitDelay2_X0_hu;
    measure_DWork.UnitDelay4_DSTATE_pm = measure_P.UnitDelay4_X0_hu;
    measure_DWork.UnitDelay2_DSTATE_mf = measure_P.UnitDelay2_X0_bg;
    measure_DWork.UnitDelay4_DSTATE_gf = measure_P.UnitDelay4_X0_bg;
    measure_DWork.UnitDelay2_DSTATE_pz = measure_P.UnitDelay2_X0_ob;
    measure_DWork.UnitDelay4_DSTATE_hc = measure_P.UnitDelay4_X0_ob;
    measure_DWork.UnitDelay2_DSTATE_gk = measure_P.UnitDelay2_X0_g;
    measure_DWork.UnitDelay4_DSTATE_gv = measure_P.UnitDelay4_X0_g;
    measure_DWork.UnitDelay2_DSTATE_hh = measure_P.UnitDelay2_X0_nx;
    measure_DWork.UnitDelay4_DSTATE_g0 = measure_P.UnitDelay4_X0_n;
    measure_DWork.UnitDelay2_DSTATE_cs5 = measure_P.UnitDelay2_X0_ec;
    measure_DWork.UnitDelay4_DSTATE_jx = measure_P.UnitDelay4_X0_ec;
    measure_DWork.UnitDelay2_DSTATE_fb = measure_P.UnitDelay2_X0_ks;
    measure_DWork.UnitDelay4_DSTATE_o = measure_P.UnitDelay4_X0_ph;
    measure_DWork.UnitDelay2_DSTATE_n2 = measure_P.UnitDelay2_X0_db;
    measure_DWork.UnitDelay4_DSTATE_eq = measure_P.UnitDelay4_X0_gm;
    measure_DWork.UnitDelay2_DSTATE_a5 = measure_P.UnitDelay2_X0_lt;
    measure_DWork.UnitDelay4_DSTATE_gy = measure_P.UnitDelay4_X0_lh;
    measure_DWork.UnitDelay2_DSTATE_dq = measure_P.UnitDelay2_X0_gs;
    measure_DWork.UnitDelay4_DSTATE_je = measure_P.UnitDelay4_X0_hh;
    measure_DWork.UnitDelay2_DSTATE_ou = measure_P.UnitDelay2_X0_pu;
    measure_DWork.UnitDelay4_DSTATE_e1 = measure_P.UnitDelay4_X0_hp;
    measure_DWork.UnitDelay2_DSTATE_ct = measure_P.UnitDelay2_X0_d2;
    measure_DWork.UnitDelay4_DSTATE_iz = measure_P.UnitDelay4_X0_jg;
    measure_DWork.UnitDelay2_DSTATE_fu = measure_P.UnitDelay2_X0_oe;
    measure_DWork.UnitDelay4_DSTATE_mu = measure_P.UnitDelay4_X0_n1;
    measure_DWork.UnitDelay2_DSTATE_gs = measure_P.UnitDelay2_X0_i;
    measure_DWork.UnitDelay4_DSTATE_nw = measure_P.UnitDelay4_X0_i;
    measure_DWork.UnitDelay2_DSTATE_p2 = measure_P.UnitDelay2_X0_gr;
    measure_DWork.UnitDelay4_DSTATE_jf = measure_P.UnitDelay4_X0_at;
    measure_DWork.UnitDelay2_DSTATE_h2 = measure_P.UnitDelay2_X0_j3;
    measure_DWork.UnitDelay4_DSTATE_lb = measure_P.UnitDelay4_X0_ce;
    measure_DWork.UnitDelay2_DSTATE_ai5 = measure_P.UnitDelay2_X0_kr;
    measure_DWork.UnitDelay4_DSTATE_co = measure_P.UnitDelay4_X0_ga;
    measure_DWork.UnitDelay2_DSTATE_lb = measure_P.UnitDelay2_X0_il;
    measure_DWork.UnitDelay4_DSTATE_j5o = measure_P.UnitDelay4_X0_b1;
    measure_DWork.UnitDelay2_DSTATE_cmh = measure_P.UnitDelay2_X0_h0;
    measure_DWork.RateTransition_Buffer0 = measure_P.RateTransition_X0;
    measure_DWork.RateTransition_Buffer0_l = measure_P.RateTransition_X0_p;
    measure_DWork.RateTransition_Buffer0_b = measure_P.RateTransition_X0_k;
    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_a[(i)] =
        measure_P.RateTransition_X0_e;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_j[(i)] =
        measure_P.RateTransition_X0_l;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_ak[(i)] =
        measure_P.RateTransition_X0_j;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_h[(i)] =
        measure_P.RateTransition_X0_c;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_g[(i)] =
        measure_P.RateTransition_X0_f;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_hn[(i)] =
        measure_P.RateTransition_X0_pv;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_e[(i)] =
        measure_P.RateTransition_X0_jr;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_lm[(i)] =
        measure_P.RateTransition_X0_lt;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_az[(i)] =
        measure_P.RateTransition_X0_b;
    }

    measure_DWork.RateTransition_Buffer0_m = measure_P.RateTransition_X0_fm;
    measure_DWork.RateTransition_Buffer0_bh = measure_P.RateTransition_X0_n;
    measure_DWork.RateTransition_Buffer0_o = measure_P.RateTransition_X0_pq;
    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_aq[(i)] =
        measure_P.RateTransition_X0_bd;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_oh[(i)] =
        measure_P.RateTransition_X0_m;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_lg[(i)] =
        measure_P.RateTransition_X0_jt;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_n[(i)] =
        measure_P.RateTransition_X0_d;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_c[(i)] =
        measure_P.RateTransition_X0_fr;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_cq[(i)] =
        measure_P.RateTransition_X0_bf;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_mb[(i)] =
        measure_P.RateTransition_X0_ny;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_of[(i)] =
        measure_P.RateTransition_X0_jq;
    }

    for (i = 0; i < 31; i++) {
      measure_DWork.RateTransition_Buffer0_jc[(i)] =
        measure_P.RateTransition_X0_g;
    }

    measure_DWork.RateTransition_Buffer0_k = measure_P.RateTransition_X0_le;
    measure_DWork.RateTransition_Buffer0_ki = measure_P.RateTransition_X0_e5;
    measure_DWork.RateTransition_Buffer0_jr = measure_P.RateTransition_X0_lea;
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
    measure_DWork.UnitDelay4_DSTATE_czl44j1ip =
      measure_P.UnitDelay4_X0_jcfawyw2o;
    measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j =
      measure_P.UnitDelay2_X0_jcfawyw2o0o;
    measure_DWork.UnitDelay1_DSTATE_c = measure_P.UnitDelay1_X0_j;
    measure_DWork.UnitDelay_DSTATE_lmdwo3 = measure_P.UnitDelay_X0_jcfawy;
    measure_DWork.UnitDelay2_DSTATE_h5brdqciz0j45w =
      measure_P.UnitDelay2_X0_jcfawyw2o0osk2;
    measure_DWork.UnitDelay_DSTATE_lmd = measure_P.UnitDelay_X0_jcf;
    measure_DWork.delay_DSTATE_i2wj4d = measure_P.delay_X0_jcfawy;
    measure_DWork.delay1_DSTATE_ces = measure_P.delay1_X0_jcf;
    measure_DWork.UnitDelay_DSTATE_lmdwo300ig =
      measure_P.UnitDelay_X0_jcfawyw2o0;
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
    measure_DWork.RateTransition_Buffer0_kg = measure_P.RateTransition_X0_ns;
    measure_DWork.RateTransition_Buffer0_hw = measure_P.RateTransition_X0_o;
    measure_DWork.RateTransition_Buffer0_kc = measure_P.RateTransition_X0_k5;
  }
}

measureModelClass::measureModelClass()
{
  Parameters_measure measure_P_temp = {
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
    1.0E-9,
    1.0,
    1.0,
    0.0,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    1.0E-9,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    1.0E-9,
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
    1.0E-9,
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
    -6.2831853071795862,
    3.1415926535897931,
    6.2831853071795862,
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
    37.5,
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
    37.5,
    0.026666666666666668,
    0.026666666666666668,
    0.0005,
    0.999999,
    0.499999,
    0.013333333333333334,
    0.013333333333333334,
    0.0005,
    0.999999,
    0.499999,
    0.093333333333333338,
    0.093333333333333338,
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
    234.0,
    117.0,
    0.0,
    0.5,
    0.0015707963267948967,
    0.0,
    3.1415926535897931,
    37.5,
    0.026666666666666668,
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
    767.0,
    384.0,
    0.0,
    0.5,
    0.0,
    1.0,
    127.0,
    64.0,
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
    37.5,
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
    40.5,
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
    1.4142135623730951,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
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
    1.0E-9,
    100.0,
    1000.0,
    0.0,
    1.0E-9,
    100.0,
    1000.0,
    0.33333333333333331,
    0.33333333333333331,
    1.0E-9,
    100.0,
    6.2831853071795862,
    -3.1415926535897931,
    -3.1415926535897931,
    0.33333333333333331,
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
    1.0E-9,
    1.0E-9,
    1.0E-9,
    -3.1415926535897931,
    -3.1415926535897931,
    -3.1415926535897931,
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

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },
    3.1415926535897931,
    6.2831853071795862,
    0.03125,
    64.0,
    1.0E-9,
    4000.0,
    6.2831853071795862,
    -1.5707963267948966,
    0.0,
    0.0,
    3.1415926535897931,
    6.2831853071795862,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },

    { 1.5707963267948966, 3.1415926535897931, 4.71238898038469,
      6.2831853071795862, 7.8539816339744828, 9.42477796076938,
      10.995574287564276, 12.566370614359172, 14.137166941154069,
      15.707963267948966, 17.27875959474386, 18.849555921538759,
      20.420352248333657, 21.991148575128552, 23.561944901923447,
      25.132741228718345, 26.703537555513243, 28.274333882308138,
      29.845130209103033, 31.415926535897931, 32.986722862692829,
      34.557519189487721, 36.128315516282619, 37.699111843077517,
      39.269908169872416, 40.840704496667314, 42.411500823462205,
      43.982297150257104, 45.553093477052, 47.123889803846893,
      48.694686130641792 },
    0.0,
    1.0E-9,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },
    3.1415926535897931,
    6.2831853071795862,
    0.03125,
    64.0,
    1.0E-9,
    4000.0,
    6.2831853071795862,
    -1.5707963267948966,
    0.0,
    0.0,
    3.1415926535897931,
    6.2831853071795862,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },

    { 1.5707963267948966, 3.1415926535897931, 4.71238898038469,
      6.2831853071795862, 7.8539816339744828, 9.42477796076938,
      10.995574287564276, 12.566370614359172, 14.137166941154069,
      15.707963267948966, 17.27875959474386, 18.849555921538759,
      20.420352248333657, 21.991148575128552, 23.561944901923447,
      25.132741228718345, 26.703537555513243, 28.274333882308138,
      29.845130209103033, 31.415926535897931, 32.986722862692829,
      34.557519189487721, 36.128315516282619, 37.699111843077517,
      39.269908169872416, 40.840704496667314, 42.411500823462205,
      43.982297150257104, 45.553093477052, 47.123889803846893,
      48.694686130641792 },
    0.0,
    1.0E-9,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },
    3.1415926535897931,
    6.2831853071795862,
    0.03125,
    64.0,
    1.0E-9,
    4000.0,
    6.2831853071795862,
    -1.5707963267948966,
    0.0,
    0.0,
    3.1415926535897931,
    6.2831853071795862,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },

    { 1.5707963267948966, 3.1415926535897931, 4.71238898038469,
      6.2831853071795862, 7.8539816339744828, 9.42477796076938,
      10.995574287564276, 12.566370614359172, 14.137166941154069,
      15.707963267948966, 17.27875959474386, 18.849555921538759,
      20.420352248333657, 21.991148575128552, 23.561944901923447,
      25.132741228718345, 26.703537555513243, 28.274333882308138,
      29.845130209103033, 31.415926535897931, 32.986722862692829,
      34.557519189487721, 36.128315516282619, 37.699111843077517,
      39.269908169872416, 40.840704496667314, 42.411500823462205,
      43.982297150257104, 45.553093477052, 47.123889803846893,
      48.694686130641792 },
    0.0,
    1.0E-9,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },
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
    3.1415926535897931,
    6.2831853071795862,
    0.03125,
    64.0,
    1.0E-9,
    4000.0,
    6.2831853071795862,
    -1.5707963267948966,
    0.0,
    0.0,
    3.1415926535897931,
    6.2831853071795862,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },

    { 1.5707963267948966, 3.1415926535897931, 4.71238898038469,
      6.2831853071795862, 7.8539816339744828, 9.42477796076938,
      10.995574287564276, 12.566370614359172, 14.137166941154069,
      15.707963267948966, 17.27875959474386, 18.849555921538759,
      20.420352248333657, 21.991148575128552, 23.561944901923447,
      25.132741228718345, 26.703537555513243, 28.274333882308138,
      29.845130209103033, 31.415926535897931, 32.986722862692829,
      34.557519189487721, 36.128315516282619, 37.699111843077517,
      39.269908169872416, 40.840704496667314, 42.411500823462205,
      43.982297150257104, 45.553093477052, 47.123889803846893,
      48.694686130641792 },
    0.0,
    1.0E-9,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },
    3.1415926535897931,
    6.2831853071795862,
    0.03125,
    64.0,
    1.0E-9,
    4000.0,
    6.2831853071795862,
    -1.5707963267948966,
    0.0,
    0.0,
    3.1415926535897931,
    6.2831853071795862,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },

    { 1.5707963267948966, 3.1415926535897931, 4.71238898038469,
      6.2831853071795862, 7.8539816339744828, 9.42477796076938,
      10.995574287564276, 12.566370614359172, 14.137166941154069,
      15.707963267948966, 17.27875959474386, 18.849555921538759,
      20.420352248333657, 21.991148575128552, 23.561944901923447,
      25.132741228718345, 26.703537555513243, 28.274333882308138,
      29.845130209103033, 31.415926535897931, 32.986722862692829,
      34.557519189487721, 36.128315516282619, 37.699111843077517,
      39.269908169872416, 40.840704496667314, 42.411500823462205,
      43.982297150257104, 45.553093477052, 47.123889803846893,
      48.694686130641792 },
    0.0,
    1.0E-9,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },
    3.1415926535897931,
    6.2831853071795862,
    0.03125,
    64.0,
    1.0E-9,
    4000.0,
    6.2831853071795862,
    -1.5707963267948966,
    0.0,
    0.0,
    3.1415926535897931,
    6.2831853071795862,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },

    { 1.5707963267948966, 3.1415926535897931, 4.71238898038469,
      6.2831853071795862, 7.8539816339744828, 9.42477796076938,
      10.995574287564276, 12.566370614359172, 14.137166941154069,
      15.707963267948966, 17.27875959474386, 18.849555921538759,
      20.420352248333657, 21.991148575128552, 23.561944901923447,
      25.132741228718345, 26.703537555513243, 28.274333882308138,
      29.845130209103033, 31.415926535897931, 32.986722862692829,
      34.557519189487721, 36.128315516282619, 37.699111843077517,
      39.269908169872416, 40.840704496667314, 42.411500823462205,
      43.982297150257104, 45.553093477052, 47.123889803846893,
      48.694686130641792 },
    0.0,
    1.0E-9,

    { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
      16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
      28.0, 29.0, 30.0, 31.0, 32.0 },

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
    108,
    108,
    2,
    55,
    55,
    2,
    375,
    375,
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
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    108,
    2,
    55,
    55,
    55,
    55,
    55,
    55,
    2,
    375,
    375,
    375,
    40,
    55,
    55,
    55,
    55,
    55,
    55,
    375,
    375,
    375,
    55,
    55,
    55,
    55,
    55,
    55,
    375,
    375,
    375,
    2,
    321,
    321,
    321,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    108,
    108,
    108,
    55,
    55,
    55,
    32,
    32,
    32,
    321,
    321,
    321,
    321,
    321,
    321,
    32,
    32,
    32,
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
    32U,
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
