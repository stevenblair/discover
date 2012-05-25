/*
 * File: measure.h
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

#ifndef RTW_HEADER_measure_h_
#define RTW_HEADER_measure_h_
#ifndef measure_COMMON_INCLUDES_
# define measure_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* measure_COMMON_INCLUDES_ */

#include "measure_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T SF_FixedDiscreteDelaySfunction;/* '<S1027>/SF_FixedDiscreteDelay S-function' */
  real_T SF_FixedDiscreteDelaySfunctio_k;/* '<S459>/SF_FixedDiscreteDelay S-function' */
  real_T Gain;                         /* '<S348>/Gain' */
  real_T Switch;                       /* '<S361>/Switch' */
  real_T Switch2;                      /* '<S469>/Switch2' */
  real_T VariableDiscreteDelaywithOneTap;/* '<S358>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_j;                     /* '<S362>/Switch' */
  real_T VariableDiscreteDelaywithOneT_n;/* '<S359>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwoTap;/* '<S363>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithTwoT_g;/* '<S363>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch2_p;                    /* '<S313>/Switch2' */
  real_T Switch_jc;                    /* '<S367>/Switch' */
  real_T Switch2_l;                    /* '<S484>/Switch2' */
  real_T VariableDiscreteDelaywithOne_nd;/* '<S364>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_jc4;                   /* '<S368>/Switch' */
  real_T VariableDiscreteDelaywithOn_ndl;/* '<S365>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwoT_h;/* '<S369>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithTwo_gt;/* '<S369>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch4;                      /* '<S313>/Switch4' */
  real_T Switch_jc4w;                  /* '<S373>/Switch' */
  real_T VariableDiscreteDelaywithO_ndlj;/* '<S370>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_jc4wm;                 /* '<S374>/Switch' */
  real_T VariableDiscreteDelaywith_ndljw;/* '<S371>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwo_h0;/* '<S375>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithTw_gtq;/* '<S375>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch2_c;                    /* '<S309>/Switch2' */
  real_T Switch_i;                     /* '<S394>/Switch' */
  real_T Switch2_a;                    /* '<S428>/Switch2' */
  real_T VariableDiscreteDelaywit_ndljwv;/* '<S391>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_iw;                    /* '<S395>/Switch' */
  real_T VariableDiscreteDelaywi_ndljwvw;/* '<S392>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTw_h0q;/* '<S396>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithT_gtqs;/* '<S396>/Variable Discrete Delay with Two Taps S-function' */
  real_T ACripple1stestimate;          /* '<S315>/Add' */
  real_T Switch2_a4;                   /* '<S315>/Switch2' */
  real_T Product[2];                   /* '<S623>/Product' */
  real_T Switch_ix;                    /* '<S642>/Switch' */
  real_T Switch2_h;                    /* '<S563>/Switch2' */
  real_T VariableDiscreteDelaywithOneT_p;/* '<S639>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_ixh;                   /* '<S643>/Switch' */
  real_T VariableDiscreteDelaywithOne_pd;/* '<S640>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwoT_i;/* '<S644>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithTwo_iz;/* '<S644>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide;                       /* '<S641>/Divide' */
  real_T Switch_ixhv;                  /* '<S648>/Switch' */
  real_T VariableDiscreteDelaywithOn_pdh;/* '<S645>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_ixhvn;                 /* '<S649>/Switch' */
  real_T VariableDiscreteDelaywithO_pdh5;/* '<S646>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwo_im;/* '<S650>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithTw_izc;/* '<S650>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide_h;                     /* '<S647>/Divide' */
  real_T Product_j[2];                 /* '<S724>/Product' */
  real_T Switch_d;                     /* '<S743>/Switch' */
  real_T VariableDiscreteDelaywith_pdh55;/* '<S740>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_dh;                    /* '<S744>/Switch' */
  real_T VariableDiscreteDelaywit_pdh55d;/* '<S741>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTw_imq;/* '<S745>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithT_izcm;/* '<S745>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide_n;                     /* '<S742>/Divide' */
  real_T Switch_dh3;                   /* '<S749>/Switch' */
  real_T VariableDiscreteDelaywi_pdh55di;/* '<S746>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_dh3i;                  /* '<S750>/Switch' */
  real_T VariableDiscreteDelayw_pdh55dim;/* '<S747>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithT_imqp;/* '<S751>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywith_izcmu;/* '<S751>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide_ny;                    /* '<S748>/Divide' */
  real_T Product_k[2];                 /* '<S825>/Product' */
  real_T Switch_p;                     /* '<S844>/Switch' */
  real_T VariableDiscreteDelay_pdh55dim3;/* '<S841>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_p0;                    /* '<S845>/Switch' */
  real_T VariableDiscreteDela_pdh55dim3o;/* '<S842>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywith_imqpt;/* '<S846>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywit_izcmu0;/* '<S846>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide_j;                     /* '<S843>/Divide' */
  real_T Switch_p0n;                   /* '<S850>/Switch' */
  real_T VariableDiscreteDel_pdh55dim3ox;/* '<S847>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_p0ny;                  /* '<S851>/Switch' */
  real_T VariableDiscreteDe_pdh55dim3oxm;/* '<S848>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywit_imqptq;/* '<S852>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywi_izcmu0m;/* '<S852>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide_jw;                    /* '<S849>/Divide' */
  real_T Switch_ixhvnq;                /* '<S666>/Switch' */
  real_T Switch2_hh;                   /* '<S578>/Switch2' */
  real_T VariableDiscreteD_pdh55dim3oxmt;/* '<S663>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_ixhvnql;               /* '<S667>/Switch' */
  real_T VariableDiscrete_pdh55dim3oxmtq;/* '<S664>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywi_imqptqt;/* '<S668>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelayw_izcmu0mr;/* '<S668>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch_ixhvnqlu;              /* '<S660>/Switch' */
  real_T VariableDiscret_pdh55dim3oxmtqn;/* '<S657>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_ixhvnqlui;             /* '<S661>/Switch' */
  real_T VariableDiscret_o;            /* '<S658>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelayw_imqptqte;/* '<S662>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelay_izcmu0mrb;/* '<S662>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch6;                      /* '<S496>/Switch6' */
  real_T Switch_dm;                    /* '<S619>/Switch' */
  real_T Switch2_hhs;                  /* '<S593>/Switch2' */
  real_T VariableDiscret_i;            /* '<S616>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_dmo;                   /* '<S620>/Switch' */
  real_T VariableDiscret_id;           /* '<S617>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelay_imqptqte5;/* '<S621>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDela_izcmu0mrbj;/* '<S621>/Variable Discrete Delay with Two Taps S-function' */
  real_T SF_FixedDiscreteDelaySfunctio_i;/* '<S928>/SF_FixedDiscreteDelay S-function' */
  real_T Switch_dh3io;                 /* '<S767>/Switch' */
  real_T VariableDiscret_op;           /* '<S764>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_dh3ioo;                /* '<S768>/Switch' */
  real_T VariableDiscret_g;            /* '<S765>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDela_imqptqte5f;/* '<S769>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDel_izcmu0mrbjz;/* '<S769>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch_dh3ioos;               /* '<S761>/Switch' */
  real_T VariableDiscret_d;            /* '<S758>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_dh3ioosv;              /* '<S762>/Switch' */
  real_T VariableDiscret_k;            /* '<S759>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDel_imqptqte5f3;/* '<S763>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDe_izcmu0mrbjza;/* '<S763>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch6_n;                    /* '<S497>/Switch6' */
  real_T Switch_iu;                    /* '<S720>/Switch' */
  real_T VariableDiscret_j;            /* '<S717>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_iua;                   /* '<S721>/Switch' */
  real_T VariableDiscret_f;            /* '<S718>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDe_imqptqte5f3c;/* '<S722>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteD_izcmu0mrbjzal;/* '<S722>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch_p0ny3;                 /* '<S868>/Switch' */
  real_T VariableDiscret_k3;           /* '<S865>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_p0ny3p;                /* '<S869>/Switch' */
  real_T VariableDiscret_e;            /* '<S866>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteD_imqptqte5f3cu;/* '<S870>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscrete_izcmu0mrbjzali;/* '<S870>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch_p0ny3pk;               /* '<S862>/Switch' */
  real_T VariableDiscret_fz;           /* '<S859>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_p0ny3pkq;              /* '<S863>/Switch' */
  real_T VariableDiscret_fv;           /* '<S860>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscrete_imqptqte5f3cur;/* '<S864>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_izcmu0mrbjzalib;/* '<S864>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch6_a;                    /* '<S498>/Switch6' */
  real_T Switch_ja;                    /* '<S821>/Switch' */
  real_T VariableDiscret_a;            /* '<S818>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_jag;                   /* '<S822>/Switch' */
  real_T VariableDiscret_f1;           /* '<S819>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_imqptqte5f3curu;/* '<S823>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_h;            /* '<S823>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch_l;                     /* '<S508>/Switch' */
  real_T Switch_il;                    /* '<S962>/Switch' */
  real_T Switch2_f;                    /* '<S996>/Switch2' */
  real_T VariableDiscreteDelaywithOneT_d;/* '<S959>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_iln;                   /* '<S963>/Switch' */
  real_T VariableDiscreteDelaywithOne_dr;/* '<S960>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwoT_o;/* '<S964>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithTwo_i4;/* '<S964>/Variable Discrete Delay with Two Taps S-function' */
  real_T ACripple1stestimate_f;        /* '<S503>/Add' */
  real_T Switch_m;                     /* '<S502>/Switch' */
  real_T MathFunction;                 /* '<S677>/Math Function' */
  real_T Switch_ixhvnqluia;            /* '<S682>/Switch' */
  real_T VariableDiscret_el;           /* '<S679>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_ixhvnqluiaa;           /* '<S683>/Switch' */
  real_T VariableDiscret_g3;           /* '<S680>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_jk;           /* '<S684>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_n;            /* '<S684>/Variable Discrete Delay with Two Taps S-function' */
  real_T MathFunction1;                /* '<S677>/Math Function1' */
  real_T Switch_ixhvnqluiaai;          /* '<S630>/Switch' */
  real_T VariableDiscret_j2;           /* '<S627>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_ixhvnqluiaai5;         /* '<S631>/Switch' */
  real_T VariableDiscret_l;            /* '<S628>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_hk;           /* '<S632>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_js;           /* '<S632>/Variable Discrete Delay with Two Taps S-function' */
  real_T MathFunction_c;               /* '<S778>/Math Function' */
  real_T Switch_dh3ioosv2;             /* '<S783>/Switch' */
  real_T VariableDiscret_fo;           /* '<S780>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_dh3ioosv2k;            /* '<S784>/Switch' */
  real_T VariableDiscret_ew;           /* '<S781>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_jg;           /* '<S785>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_p;            /* '<S785>/Variable Discrete Delay with Two Taps S-function' */
  real_T MathFunction1_p;              /* '<S778>/Math Function1' */
  real_T Switch_dh3ioosv2km;           /* '<S731>/Switch' */
  real_T VariableDiscret_m;            /* '<S728>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_dh3ioosv2kma;          /* '<S732>/Switch' */
  real_T VariableDiscret_b;            /* '<S729>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_al;           /* '<S733>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_ki;           /* '<S733>/Variable Discrete Delay with Two Taps S-function' */
  real_T MathFunction_l;               /* '<S879>/Math Function' */
  real_T Switch_p0ny3pkqp;             /* '<S884>/Switch' */
  real_T VariableDiscret_la;           /* '<S881>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_p0ny3pkqpe;            /* '<S885>/Switch' */
  real_T VariableDiscret_hy;           /* '<S882>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_pk;           /* '<S886>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_p5;           /* '<S886>/Variable Discrete Delay with Two Taps S-function' */
  real_T MathFunction1_m;              /* '<S879>/Math Function1' */
  real_T Switch_p0ny3pkqpey;           /* '<S832>/Switch' */
  real_T VariableDiscret_ef;           /* '<S829>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_p0ny3pkqpeyo;          /* '<S833>/Switch' */
  real_T VariableDiscret_ai;           /* '<S830>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_b5;           /* '<S834>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_jn;           /* '<S834>/Variable Discrete Delay with Two Taps S-function' */
  real_T Product_i[2];                 /* '<S109>/Product' */
  real_T Switch_b;                     /* '<S128>/Switch' */
  real_T VariableDiscreteDelaywithOneT_k;/* '<S125>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_b2;                    /* '<S129>/Switch' */
  real_T VariableDiscreteDelaywithOne_kn;/* '<S126>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwoT_a;/* '<S130>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithTwoT_p;/* '<S130>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide_ja;                    /* '<S127>/Divide' */
  real_T Switch_b2j;                   /* '<S146>/Switch' */
  real_T VariableDiscreteDelaywithOn_kne;/* '<S143>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_b2jb;                  /* '<S147>/Switch' */
  real_T VariableDiscreteDelaywithO_knes;/* '<S144>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwo_a3;/* '<S148>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithTwo_p2;/* '<S148>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch_b2jbv;                 /* '<S134>/Switch' */
  real_T VariableDiscreteDelaywith_knesb;/* '<S131>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_b2jbv3;                /* '<S135>/Switch' */
  real_T VariableDiscreteDelaywit_knesbd;/* '<S132>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTw_a3z;/* '<S136>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithTw_p20;/* '<S136>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide_jah;                   /* '<S133>/Divide' */
  real_T Switch_b2jbv30;               /* '<S152>/Switch' */
  real_T VariableDiscreteDelaywi_knesbdm;/* '<S149>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_b2jbv30z;              /* '<S153>/Switch' */
  real_T VariableDiscreteDelayw_knesbdmu;/* '<S150>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithT_a3zz;/* '<S154>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithT_p20b;/* '<S154>/Variable Discrete Delay with Two Taps S-function' */
  real_T Product_io[2];                /* '<S172>/Product' */
  real_T Switch_b2jbv30zm;             /* '<S191>/Switch' */
  real_T VariableDiscreteDelay_knesbdmu1;/* '<S188>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_b2jbv30zmv;            /* '<S192>/Switch' */
  real_T VariableDiscreteDela_knesbdmu1j;/* '<S189>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywith_a3zzb;/* '<S193>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywith_p20bd;/* '<S193>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide_jahf;                  /* '<S190>/Divide' */
  real_T Switch_b2jbv30zmvu;           /* '<S209>/Switch' */
  real_T VariableDiscreteDel_knesbdmu1jd;/* '<S206>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_b2jbv30zmvus;          /* '<S210>/Switch' */
  real_T VariableDiscreteDe_knesbdmu1jdz;/* '<S207>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywit_a3zzbn;/* '<S211>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywit_p20bdb;/* '<S211>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch_b2jbv30zmvusn;         /* '<S197>/Switch' */
  real_T VariableDiscreteD_knesbdmu1jdzx;/* '<S194>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_b2jbv30zmvusna;        /* '<S198>/Switch' */
  real_T VariableDiscrete_knesbdmu1jdzx0;/* '<S195>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywi_a3zzbnn;/* '<S199>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywi_p20bdbu;/* '<S199>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide_jahfx;                 /* '<S196>/Divide' */
  real_T Switch_b2jbv30zmvusnaw;       /* '<S215>/Switch' */
  real_T VariableDiscret_knesbdmu1jdzx0j;/* '<S212>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_n;                     /* '<S216>/Switch' */
  real_T VariableDiscret_mc;           /* '<S213>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelayw_a3zzbnny;/* '<S217>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelayw_p20bdbus;/* '<S217>/Variable Discrete Delay with Two Taps S-function' */
  real_T Product_io0[2];               /* '<S235>/Product' */
  real_T Switch_lf;                    /* '<S254>/Switch' */
  real_T VariableDiscret_pu;           /* '<S251>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_jcx;                   /* '<S255>/Switch' */
  real_T VariableDiscret_mi;           /* '<S252>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelay_a3zzbnnyv;/* '<S256>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelay_p20bdbust;/* '<S256>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide_jahfx5;                /* '<S253>/Divide' */
  real_T Switch_e;                     /* '<S272>/Switch' */
  real_T VariableDiscret_mt;           /* '<S269>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_bd;                    /* '<S273>/Switch' */
  real_T VariableDiscret_fv5;          /* '<S270>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDela_a3zzbnnyvg;/* '<S274>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDela_p20bdbustl;/* '<S274>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch_c;                     /* '<S260>/Switch' */
  real_T VariableDiscret_lw;           /* '<S257>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_d5;                    /* '<S261>/Switch' */
  real_T VariableDiscret_fc;           /* '<S258>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDel_a3zzbnnyvg5;/* '<S262>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDel_p20bdbustlf;/* '<S262>/Variable Discrete Delay with Two Taps S-function' */
  real_T Divide_jahfx50;               /* '<S259>/Divide' */
  real_T Switch_ik;                    /* '<S278>/Switch' */
  real_T VariableDiscret_eg;           /* '<S275>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_nb;                    /* '<S279>/Switch' */
  real_T VariableDiscret_d2;           /* '<S276>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDe_a3zzbnnyvg5z;/* '<S280>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDe_p20bdbustlfs;/* '<S280>/Variable Discrete Delay with Two Taps S-function' */
  real_T MathFunction_k;               /* '<S163>/Math Function' */
  real_T Switch_o;                     /* '<S168>/Switch' */
  real_T VariableDiscret_fq;           /* '<S165>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_oo;                    /* '<S169>/Switch' */
  real_T VariableDiscret_eb;           /* '<S166>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteD_a3zzbnnyvg5zz;/* '<S170>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteD_p20bdbustlfs4;/* '<S170>/Variable Discrete Delay with Two Taps S-function' */
  real_T MathFunction1_g;              /* '<S163>/Math Function1' */
  real_T Switch_g;                     /* '<S116>/Switch' */
  real_T VariableDiscret_je;           /* '<S113>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_pp;                    /* '<S117>/Switch' */
  real_T VariableDiscret_pq;           /* '<S114>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscrete_a3zzbnnyvg5zz5;/* '<S118>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscrete_p20bdbustlfs4u;/* '<S118>/Variable Discrete Delay with Two Taps S-function' */
  real_T MathFunction_k5;              /* '<S226>/Math Function' */
  real_T Switch_cx;                    /* '<S231>/Switch' */
  real_T VariableDiscret_on;           /* '<S228>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_ixo;                   /* '<S232>/Switch' */
  real_T VariableDiscret_mb;           /* '<S229>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_a3zzbnnyvg5zz54;/* '<S233>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_p20bdbustlfs4um;/* '<S233>/Variable Discrete Delay with Two Taps S-function' */
  real_T MathFunction1_ge;             /* '<S226>/Math Function1' */
  real_T Switch_ek;                    /* '<S179>/Switch' */
  real_T VariableDiscret_nz;           /* '<S176>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_j3;                    /* '<S180>/Switch' */
  real_T VariableDiscret_h5;           /* '<S177>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_ho;           /* '<S181>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_is;           /* '<S181>/Variable Discrete Delay with Two Taps S-function' */
  real_T MathFunction_k5t;             /* '<S289>/Math Function' */
  real_T Switch_a;                     /* '<S294>/Switch' */
  real_T VariableDiscret_dl;           /* '<S291>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_d0;                    /* '<S295>/Switch' */
  real_T VariableDiscret_f2;           /* '<S292>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_gz;           /* '<S296>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_jb;           /* '<S296>/Variable Discrete Delay with Two Taps S-function' */
  real_T MathFunction1_ge3;            /* '<S289>/Math Function1' */
  real_T Switch_h;                     /* '<S242>/Switch' */
  real_T VariableDiscret_hx;           /* '<S239>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_it;                    /* '<S243>/Switch' */
  real_T VariableDiscret_my;           /* '<S240>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_ed;           /* '<S244>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_m2;           /* '<S244>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch2_k;                    /* '<S336>/Switch2' */
  real_T Switch2_k0;                   /* '<S345>/Switch2' */
  real_T Switch_iwl;                   /* '<S400>/Switch' */
  real_T VariableDiscreteDelayw_ndljwvwq;/* '<S397>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_iwlt;                  /* '<S401>/Switch' */
  real_T VariableDiscreteDelay_ndljwvwq0;/* '<S398>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithT_h0qt;/* '<S402>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywith_gtqs2;/* '<S402>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch2_a4f;                  /* '<S383>/Switch2' */
  real_T Switch2_a4fq;                 /* '<S446>/Switch2' */
  real_T Switch2_co;                   /* '<S535>/Switch2' */
  real_T Switch2_m;                    /* '<S544>/Switch2' */
  real_T DataTypeConversion;           /* '<S501>/Data Type Conversion' */
  real_T Switch_iln5;                  /* '<S968>/Switch' */
  real_T VariableDiscreteDelaywithOn_dra;/* '<S965>/Variable Discrete Delay with One Tap S-function' */
  real_T Switch_iln5l;                 /* '<S969>/Switch' */
  real_T VariableDiscreteDelaywithO_drao;/* '<S966>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwo_oa;/* '<S970>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithTw_i44;/* '<S970>/Variable Discrete Delay with Two Taps S-function' */
  real_T Switch2_o;                    /* '<S951>/Switch2' */
  real_T Switch2_g;                    /* '<S1014>/Switch2' */
  int32_T SFunction;                   /* '<S469>/S-Function' */
  int32_T Switch2_lr;                  /* '<S470>/Switch2' */
  int32_T SFunction_i;                 /* '<S484>/S-Function' */
  int32_T Switch2_lrp;                 /* '<S485>/Switch2' */
  int32_T SFunction_m;                 /* '<S428>/S-Function' */
  int32_T Switch2_a4fq3;               /* '<S429>/Switch2' */
  int32_T SFunction_m3;                /* '<S563>/S-Function' */
  int32_T Switch2_hhsc;                /* '<S564>/Switch2' */
  int32_T SFunction_m3m;               /* '<S578>/S-Function' */
  int32_T Switch2_hhsca;               /* '<S579>/Switch2' */
  int32_T SFunction_m3ml;              /* '<S593>/S-Function' */
  int32_T Switch2_hhsca5;              /* '<S594>/Switch2' */
  int32_T SFunction_n;                 /* '<S996>/S-Function' */
  int32_T Switch2_f4;                  /* '<S997>/Switch2' */
  int32_T SFunction_mp;                /* '<S383>/S-Function' */
  int32_T SFunction_p;                 /* '<S951>/S-Function' */
  uint32_T SFunction_o;                /* '<S336>/S-Function' */
  uint32_T SFunction_os;               /* '<S345>/S-Function' */
  uint32_T SFunction_mpm;              /* '<S446>/S-Function' */
  uint32_T SFunction_nt;               /* '<S535>/S-Function' */
  uint32_T SFunction_p3;               /* '<S544>/S-Function' */
  uint32_T SFunction_ne;               /* '<S1014>/S-Function' */
} BlockIO_measure;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SF_FixedDiscreteDelaySfunction_;/* '<S1027>/SF_FixedDiscreteDelay S-function' */
  real_T UnitDelay_DSTATE;             /* '<S504>/Unit Delay' */
  real_T SF_FixedDiscreteDelaySfunctio_c;/* '<S459>/SF_FixedDiscreteDelay S-function' */
  real_T UnitDelay_DSTATE_i;           /* '<S316>/Unit Delay' */
  real_T UnitDelay_DSTATE_e;           /* '<S309>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S348>/Unit Delay3' */
  real_T UnitDelay1_DSTATE;            /* '<S85>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S85>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_i;          /* '<S86>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_a;          /* '<S86>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_b;          /* '<S84>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_c;          /* '<S84>/Unit Delay2' */
  real_T UnitDelay4_DSTATE;            /* '<S361>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_l;          /* '<S361>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_k;          /* '<S362>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ls;         /* '<S362>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_kr;         /* '<S367>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_lsc;        /* '<S367>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_krx;        /* '<S368>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_lscn;       /* '<S368>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_krxz;       /* '<S373>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_lscnp;      /* '<S373>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_krxzy;      /* '<S374>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_lscnp0;     /* '<S374>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_krxzyr;     /* '<S394>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_lscnp0r;    /* '<S394>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_lscnp0r3;   /* '<S315>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_krxzyrk;    /* '<S395>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_lscnp0r3j;  /* '<S395>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_h;          /* '<S310>/Unit Delay2' */
  real_T UnitDelay_DSTATE_f;           /* '<S495>/Unit Delay' */
  real_T UnitDelay4_DSTATE_j;          /* '<S642>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_lj;         /* '<S642>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_js;         /* '<S643>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ljf;        /* '<S643>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_js0;        /* '<S648>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ljfw;       /* '<S648>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_js0g;       /* '<S649>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ljfwk;      /* '<S649>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_e;          /* '<S743>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ab;         /* '<S743>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_e1;         /* '<S744>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_abj;        /* '<S744>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_e10;        /* '<S749>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_abju;       /* '<S749>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_e10c;       /* '<S750>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_abju3;      /* '<S750>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_o;          /* '<S844>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_g;          /* '<S844>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_ot;         /* '<S845>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_gl;         /* '<S845>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_otw;        /* '<S850>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_gll;        /* '<S850>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_otws;       /* '<S851>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_gllv;       /* '<S851>/Unit Delay2' */
  real_T UnitDelay3_DSTATE_p;          /* '<S600>/Unit Delay3' */
  real_T UnitDelay4_DSTATE_js0g0;      /* '<S666>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ljfwkl;     /* '<S666>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_js0g0x;     /* '<S667>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ljfwklf;    /* '<S667>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_js0g0xc;    /* '<S660>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ljfwklf5;   /* '<S660>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_js0g0xck;   /* '<S661>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ljfwklf5t;  /* '<S661>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_i;          /* '<S619>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_l1;         /* '<S619>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_iv;         /* '<S620>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_l1a;        /* '<S620>/Unit Delay2' */
  real_T UnitDelay_DSTATE_h;           /* '<S692>/Unit Delay' */
  real_T SF_FixedDiscreteDelaySfunctio_a;/* '<S928>/SF_FixedDiscreteDelay S-function' */
  real_T UnitDelay1_DSTATE_m;          /* '<S633>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_g;          /* '<S734>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_o;          /* '<S835>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S793>/Unit Delay' */
  real_T UnitDelay_DSTATE_d;           /* '<S894>/Unit Delay' */
  real_T UnitDelay3_DSTATE_pz;         /* '<S701>/Unit Delay3' */
  real_T UnitDelay4_DSTATE_e10ck;      /* '<S767>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_abju3r;     /* '<S767>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_e10ck0;     /* '<S768>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_abju3rc;    /* '<S768>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_e10ck0c;    /* '<S761>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_abju3rc3;   /* '<S761>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_e10ck0ct;   /* '<S762>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_abju3rc3x;  /* '<S762>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_b;          /* '<S720>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_k;          /* '<S720>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_bc;         /* '<S721>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_k1;         /* '<S721>/Unit Delay2' */
  real_T UnitDelay3_DSTATE_o;          /* '<S802>/Unit Delay3' */
  real_T UnitDelay4_DSTATE_otwsj;      /* '<S868>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_gllvy;      /* '<S868>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_otwsjg;     /* '<S869>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_gllvyy;     /* '<S869>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_otwsjge;    /* '<S862>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_gllvyya;    /* '<S862>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_otwsjget;   /* '<S863>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_gllvyya5;   /* '<S863>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_kw;         /* '<S821>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_o;          /* '<S821>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_kwr;        /* '<S822>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_o2;         /* '<S822>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_c;          /* '<S962>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_d;          /* '<S962>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_aj;         /* '<S503>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_cv;         /* '<S963>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_dg;         /* '<S963>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_js0g0xcka;  /* '<S682>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ljfwklf5ta; /* '<S682>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_js0g0xckaa; /* '<S683>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ljfwklf5tay;/* '<S683>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_js0g0xckaam;/* '<S630>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ljfwklf5tayt;/* '<S630>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_js0g0xckaamb;/* '<S631>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_ljfwklf5taytr;/* '<S631>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_e10ck0cti;  /* '<S783>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_abju3rc3xa; /* '<S783>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_e10ck0ctir; /* '<S784>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_abju3rc3xak;/* '<S784>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_e10ck0ctirr;/* '<S731>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_abju3rc3xaku;/* '<S731>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_e10ck0ctirrv;/* '<S732>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_abju3rc3xaku5;/* '<S732>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_otwsjgetk;  /* '<S884>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_gllvyya5a;  /* '<S884>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_otwsjgetko; /* '<S885>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_gllvyya5ah; /* '<S885>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_otwsjgetkod;/* '<S832>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_gllvyya5ah0;/* '<S832>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_otwsjgetkod3;/* '<S833>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_gllvyya5ah0l;/* '<S833>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_h;          /* '<S87>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_gp;         /* '<S87>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jn;         /* '<S128>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_n;          /* '<S128>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jnq;        /* '<S129>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_np;         /* '<S129>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jnq1;       /* '<S146>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_npj;        /* '<S146>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jnq1h;      /* '<S147>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_npjj;       /* '<S147>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jnq1hm;     /* '<S134>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_npjj1;      /* '<S134>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jnq1hmy;    /* '<S135>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_npjj1p;     /* '<S135>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jnq1hmyq;   /* '<S152>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_npjj1pt;    /* '<S152>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jnq1hmyqy;  /* '<S153>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_npjj1ptk;   /* '<S153>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_ou;         /* '<S88>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_f;          /* '<S88>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jnq1hmyqya; /* '<S191>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_npjj1ptkd;  /* '<S191>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jnq1hmyqya1;/* '<S192>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_npjj1ptkda; /* '<S192>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jnq1hmyqya1i;/* '<S209>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_npjj1ptkdaf;/* '<S209>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_jnq1hmyqya1it;/* '<S210>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_npjj1ptkdaf2;/* '<S210>/Unit Delay2' */
  real_T UnitDelay4_DSTAT_jnq1hmyqya1it1;/* '<S197>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_npjj1ptkdaf2v;/* '<S197>/Unit Delay2' */
  real_T UnitDelay4_DSTA_jnq1hmyqya1it1v;/* '<S198>/Unit Delay4' */
  real_T UnitDelay2_DSTAT_npjj1ptkdaf2v0;/* '<S198>/Unit Delay2' */
  real_T UnitDelay4_DSTA_p;            /* '<S215>/Unit Delay4' */
  real_T UnitDelay2_DSTA_npjj1ptkdaf2v0r;/* '<S215>/Unit Delay2' */
  real_T UnitDelay4_DSTA_o;            /* '<S216>/Unit Delay4' */
  real_T UnitDelay2_DSTA_i;            /* '<S216>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_bn;         /* '<S89>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_b;          /* '<S89>/Unit Delay2' */
  real_T UnitDelay4_DSTA_k;            /* '<S254>/Unit Delay4' */
  real_T UnitDelay2_DSTA_g;            /* '<S254>/Unit Delay2' */
  real_T UnitDelay4_DSTA_c;            /* '<S255>/Unit Delay4' */
  real_T UnitDelay2_DSTA_n;            /* '<S255>/Unit Delay2' */
  real_T UnitDelay4_DSTA_d;            /* '<S272>/Unit Delay4' */
  real_T UnitDelay2_DSTA_k;            /* '<S272>/Unit Delay2' */
  real_T UnitDelay4_DSTA_h;            /* '<S273>/Unit Delay4' */
  real_T UnitDelay2_DSTA_p;            /* '<S273>/Unit Delay2' */
  real_T UnitDelay4_DSTA_f;            /* '<S260>/Unit Delay4' */
  real_T UnitDelay2_DSTA_ip;           /* '<S260>/Unit Delay2' */
  real_T UnitDelay4_DSTA_o2;           /* '<S261>/Unit Delay4' */
  real_T UnitDelay2_DSTA_h;            /* '<S261>/Unit Delay2' */
  real_T UnitDelay4_DSTA_cq;           /* '<S278>/Unit Delay4' */
  real_T UnitDelay2_DSTA_pl;           /* '<S278>/Unit Delay2' */
  real_T UnitDelay4_DSTA_a;            /* '<S279>/Unit Delay4' */
  real_T UnitDelay2_DSTA_c;            /* '<S279>/Unit Delay2' */
  real_T UnitDelay4_DSTA_n;            /* '<S168>/Unit Delay4' */
  real_T UnitDelay2_DSTA_o;            /* '<S168>/Unit Delay2' */
  real_T UnitDelay4_DSTA_i;            /* '<S169>/Unit Delay4' */
  real_T UnitDelay2_DSTA_f;            /* '<S169>/Unit Delay2' */
  real_T UnitDelay4_DSTA_j;            /* '<S116>/Unit Delay4' */
  real_T UnitDelay2_DSTA_j;            /* '<S116>/Unit Delay2' */
  real_T UnitDelay4_DSTA_jj;           /* '<S117>/Unit Delay4' */
  real_T UnitDelay2_DSTA_ic;           /* '<S117>/Unit Delay2' */
  real_T UnitDelay4_DSTA_dk;           /* '<S231>/Unit Delay4' */
  real_T UnitDelay2_DSTA_hv;           /* '<S231>/Unit Delay2' */
  real_T UnitDelay4_DSTA_dx;           /* '<S232>/Unit Delay4' */
  real_T UnitDelay2_DSTA_l;            /* '<S232>/Unit Delay2' */
  real_T UnitDelay4_DSTA_kd;           /* '<S179>/Unit Delay4' */
  real_T UnitDelay2_DSTA_m;            /* '<S179>/Unit Delay2' */
  real_T UnitDelay4_DSTA_dr;           /* '<S180>/Unit Delay4' */
  real_T UnitDelay2_DSTA_lr;           /* '<S180>/Unit Delay2' */
  real_T UnitDelay4_DSTA_ny;           /* '<S294>/Unit Delay4' */
  real_T UnitDelay2_DSTA_oy;           /* '<S294>/Unit Delay2' */
  real_T UnitDelay4_DSTA_k1;           /* '<S295>/Unit Delay4' */
  real_T UnitDelay2_DSTA_a;            /* '<S295>/Unit Delay2' */
  real_T UnitDelay4_DSTA_ip;           /* '<S242>/Unit Delay4' */
  real_T UnitDelay2_DSTA_ay;           /* '<S242>/Unit Delay2' */
  real_T UnitDelay4_DSTA_hx;           /* '<S243>/Unit Delay4' */
  real_T UnitDelay2_DSTA_la;           /* '<S243>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_krxzyrko;   /* '<S400>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_lscnp0r3jm; /* '<S400>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_krxzyrkob;  /* '<S401>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_lscnp0r3jm2;/* '<S401>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_om;         /* '<S315>/Unit Delay1' */
  real_T UnitDelay_DSTATE_eh;          /* '<S418>/Unit Delay' */
  real_T UnitDelay1_DSTATE_omt;        /* '<S388>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_omtd;       /* '<S441>/Unit Delay1' */
  real_T UnitDelay4_DSTATE_krxzyrkobe; /* '<S388>/Unit Delay4' */
  real_T UnitDelay1_DSTATE_omtd1;      /* '<S442>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_omtd1h;     /* '<S382>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_omtd1hd;    /* '<S381>/Unit Delay1' */
  real_T UnitDelay3_DSTATE_pg;         /* '<S599>/Unit Delay3' */
  real_T UnitDelay3_DSTATE_pzl;        /* '<S700>/Unit Delay3' */
  real_T UnitDelay3_DSTATE_ot;         /* '<S801>/Unit Delay3' */
  real_T UnitDelay4_DSTATE_cvz;        /* '<S968>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_dgh;        /* '<S968>/Unit Delay2' */
  real_T UnitDelay4_DSTATE_cvzr;       /* '<S969>/Unit Delay4' */
  real_T UnitDelay2_DSTATE_dghn;       /* '<S969>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_k;          /* '<S503>/Unit Delay1' */
  real_T UnitDelay_DSTATE_c;           /* '<S986>/Unit Delay' */
  real_T UnitDelay1_DSTATE_gr;         /* '<S956>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_grk;        /* '<S1009>/Unit Delay1' */
  real_T UnitDelay4_DSTATE_a;          /* '<S956>/Unit Delay4' */
  real_T UnitDelay1_DSTATE_grkf;       /* '<S1010>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_j;          /* '<S950>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_d;          /* '<S949>/Unit Delay1' */
  real_T SF_FixedDiscreteDelaySfuncti_c3[80];/* '<S1027>/SF_FixedDiscreteDelay S-function' */
  real_T SF_FixedDiscreteDelaySfunctio_l[80];/* '<S459>/SF_FixedDiscreteDelay S-function' */
  real_T VariableDiscreteDelaywithOneTap[102];/* '<S358>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithOneT_i[102];/* '<S359>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwoTap[102];/* '<S363>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithOne_iq[202];/* '<S364>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithOn_iqv[202];/* '<S365>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwoT_b[202];/* '<S369>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithO_iqvv[202];/* '<S370>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywith_iqvvo[202];/* '<S371>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwo_bq[202];/* '<S375>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywit_iqvvod[322];/* '<S391>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywi_iqvvods[322];/* '<S392>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTw_bqv[322];/* '<S396>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithOneT_f[162];/* '<S639>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithOne_f2[162];/* '<S640>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwoT_a[162];/* '<S644>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithOn_f2j[162];/* '<S645>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithO_f2jg[162];/* '<S646>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwo_ab[162];/* '<S650>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywith_f2jgc[162];/* '<S740>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywit_f2jgc1[162];/* '<S741>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTw_ab4[162];/* '<S745>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywi_f2jgc1y[162];/* '<S746>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelayw_f2jgc1yy[162];/* '<S747>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithT_ab4s[162];/* '<S751>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelay_f2jgc1yyu[162];/* '<S841>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDela_f2jgc1yyuf[162];/* '<S842>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywith_ab4s3[162];/* '<S846>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDel_f2jgc1yyufb[162];/* '<S847>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDe_f2jgc1yyufbl[162];/* '<S848>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywit_ab4s3q[162];/* '<S852>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteD_f2jgc1yyufbl2[82];/* '<S663>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscrete_f2jgc1yyufbl2v[82];/* '<S664>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywi_ab4s3ql[82];/* '<S668>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_f2jgc1yyufbl2vd[82];/* '<S657>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_d[82];        /* '<S658>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelayw_ab4s3qlk[82];/* '<S662>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_g[562];       /* '<S616>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_f[562];       /* '<S617>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelay_ab4s3qlk5[562];/* '<S621>/Variable Discrete Delay with Two Taps S-function' */
  real_T SF_FixedDiscreteDelaySfunctio_j[40];/* '<S928>/SF_FixedDiscreteDelay S-function' */
  real_T VariableDiscret_c[82];        /* '<S764>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_c1[82];       /* '<S765>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDela_ab4s3qlk5c[82];/* '<S769>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_gf[82];       /* '<S758>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_p[82];        /* '<S759>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDel_ab4s3qlk5cc[82];/* '<S763>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_cr[562];      /* '<S717>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_e[562];       /* '<S718>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDe_ab4s3qlk5cc4[562];/* '<S722>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_b[82];        /* '<S865>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_n[82];        /* '<S866>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteD_ab4s3qlk5cc4j[82];/* '<S870>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_gp[82];       /* '<S859>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_i[82];        /* '<S860>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscrete_ab4s3qlk5cc4jf[82];/* '<S864>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_m[562];       /* '<S818>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_mm[562];      /* '<S819>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_ab4s3qlk5cc4jfr[562];/* '<S823>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithOneT_p[322];/* '<S959>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithOne_pb[322];/* '<S960>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwoT_g[322];/* '<S964>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_i3[162];      /* '<S679>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_a[162];       /* '<S680>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_gg[162];      /* '<S684>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_ex[82];       /* '<S627>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_aj[82];       /* '<S628>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_aq[82];       /* '<S632>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_no[162];      /* '<S780>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_f5[162];      /* '<S781>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_ef[162];      /* '<S785>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_ed[82];       /* '<S728>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_a0[82];       /* '<S729>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_pk[82];       /* '<S733>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_dk[162];      /* '<S881>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_o[162];       /* '<S882>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_gs[162];      /* '<S886>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_bt[82];       /* '<S829>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_e0[82];       /* '<S830>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_l[82];        /* '<S834>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithOneT_h[162];/* '<S125>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithOne_hk[162];/* '<S126>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwoT_h[162];/* '<S130>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithOn_hkv[82];/* '<S143>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithO_hkvl[82];/* '<S144>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwo_hj[82];/* '<S148>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywith_hkvl3[162];/* '<S131>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywit_hkvl35[162];/* '<S132>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTw_hjq[162];/* '<S136>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywi_hkvl35c[82];/* '<S149>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelayw_hkvl35cs[82];/* '<S150>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithT_hjqf[82];/* '<S154>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelay_hkvl35css[162];/* '<S188>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDela_hkvl35cssz[162];/* '<S189>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywith_hjqfc[162];/* '<S193>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDel_hkvl35cssz3[82];/* '<S206>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDe_hkvl35cssz3u[82];/* '<S207>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywit_hjqfcq[82];/* '<S211>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteD_hkvl35cssz3uy[162];/* '<S194>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscrete_hkvl35cssz3uyo[162];/* '<S195>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywi_hjqfcqw[162];/* '<S199>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_hkvl35cssz3uyos[82];/* '<S212>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_a02[82];      /* '<S213>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelayw_hjqfcqwr[82];/* '<S217>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_iy[162];      /* '<S251>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_ad[162];      /* '<S252>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelay_hjqfcqwrz[162];/* '<S256>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_m1[82];       /* '<S269>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_g0[82];       /* '<S270>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDela_hjqfcqwrzc[82];/* '<S274>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_j[162];       /* '<S257>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_ox[162];      /* '<S258>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDel_hjqfcqwrzc3[162];/* '<S262>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_m0[82];       /* '<S275>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_fq[82];       /* '<S276>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDe_hjqfcqwrzc31[82];/* '<S280>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_ep[162];      /* '<S165>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_cp[162];      /* '<S166>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteD_hjqfcqwrzc31p[162];/* '<S170>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_h[82];        /* '<S113>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_c4[82];       /* '<S114>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscrete_hjqfcqwrzc31p3[82];/* '<S118>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_jw[162];      /* '<S228>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_bg[162];      /* '<S229>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_hjqfcqwrzc31p34[162];/* '<S233>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_on[82];       /* '<S176>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_nr[82];       /* '<S177>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_om[82];       /* '<S181>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_pe[162];      /* '<S291>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_k[162];       /* '<S292>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_mf[162];      /* '<S296>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscret_p3[82];       /* '<S239>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_me[82];       /* '<S240>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscret_onk[82];      /* '<S244>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelayw_iqvvodsl[322];/* '<S397>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelay_iqvvodsli[322];/* '<S398>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithT_bqvb[322];/* '<S402>/Variable Discrete Delay with Two Taps S-function' */
  real_T VariableDiscreteDelaywithOn_pbu[322];/* '<S965>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithO_pbur[322];/* '<S966>/Variable Discrete Delay with One Tap S-function' */
  real_T VariableDiscreteDelaywithTwo_g0[322];/* '<S970>/Variable Discrete Delay with Two Taps S-function' */
  uint32_T UnitDelay1_DSTATE_omtd1hdp; /* '<S322>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_omtd1hdpu;/* '<S321>/Unit Delay1' */
  uint32_T UnitDelay_DSTATE_ehb;       /* '<S413>/Unit Delay' */
  uint32_T UnitDelay1_DSTATE_omtd1hdput;/* '<S320>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_gf;       /* '<S941>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_m4;       /* '<S607>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_j4;       /* '<S708>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_g0;       /* '<S809>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_c;        /* '<S608>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_n;        /* '<S687>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_nr;       /* '<S685>/Unit Delay1' */
  uint32_T UnitDelay_DSTATE_j;         /* '<S929>/Unit Delay' */
  uint32_T UnitDelay_DSTATE_jq;        /* '<S932>/Unit Delay' */
  uint32_T UnitDelay_DSTATE_jqs;       /* '<S935>/Unit Delay' */
  uint32_T UnitDelay1_DSTATE_cf;       /* '<S709>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_e;        /* '<S788>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_ep;       /* '<S786>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_or;       /* '<S810>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_ir;       /* '<S889>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_irs;      /* '<S887>/Unit Delay1' */
  uint32_T UnitDelay_DSTATE_m;         /* '<S981>/Unit Delay' */
  uint32_T UnitDelay_DSTATE_hs;        /* '<S942>/Unit Delay' */
  uint32_T UnitDelay1_DSTATE_omtd1hdputh;/* '<S319>/Unit Delay1' */
  uint32_T UnitDelay_DSTATE_im;        /* '<S337>/Unit Delay' */
  uint32_T UnitDelay1_DSTATE_omtd1hdputhx;/* '<S335>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_omtd1hdputhxn;/* '<S334>/Unit Delay1' */
  uint32_T UnitDelay_DSTATE_ehbx;      /* '<S443>/Unit Delay' */
  uint32_T UnitDelay2_DSTATE_lscnp0r3jm2b;/* '<S443>/Unit Delay2' */
  uint32_T UnitDelay_DSTATE_ehbxx;     /* '<S448>/Unit Delay' */
  uint32_T UnitDelay1_DSTATE_hf;       /* '<S505>/Unit Delay1' */
  uint32_T UnitDelay_DSTATE_cx;        /* '<S536>/Unit Delay' */
  uint32_T UnitDelay1_DSTATE_cx;       /* '<S534>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_d5;       /* '<S533>/Unit Delay1' */
  uint32_T UnitDelay_DSTATE_jm;        /* '<S1011>/Unit Delay' */
  uint32_T UnitDelay2_DSTATE_oc;       /* '<S1011>/Unit Delay2' */
  uint32_T UnitDelay_DSTATE_jmc;       /* '<S1016>/Unit Delay' */
  int32_T clockTickCounter;            /* '<S475>/Pulse Generator1' */
  int32_T clockTickCounter_f;          /* '<S460>/Pulse Generator1' */
  int32_T clockTickCounter_n;          /* '<S419>/Pulse Generator1' */
  int32_T clockTickCounter_e;          /* '<S554>/Pulse Generator1' */
  int32_T clockTickCounter_ey;         /* '<S584>/Pulse Generator1' */
  int32_T clockTickCounter_ey4;        /* '<S569>/Pulse Generator1' */
  int32_T clockTickCounter_ed;         /* '<S987>/Pulse Generator1' */
  int_T SF_FixedDiscreteDelaySfunctio_i;/* '<S1027>/SF_FixedDiscreteDelay S-function' */
  int_T SF_FixedDiscreteDelaySfunctio_e;/* '<S459>/SF_FixedDiscreteDelay S-function' */
  int_T VariableDiscreteDelaywithOne_pz;/* '<S358>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithOn_pzv;/* '<S359>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithTwoT_m;/* '<S363>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelaywithO_pzv4;/* '<S364>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywith_pzv45;/* '<S365>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithTwo_mw;/* '<S369>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelaywit_pzv45h;/* '<S370>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywi_pzv45hn;/* '<S371>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithTw_mw3;/* '<S375>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelayw_pzv45hn0;/* '<S391>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelay_pzv45hn0c;/* '<S392>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithT_mw3l;/* '<S396>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelaywithOne_hg;/* '<S639>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithOn_hgo;/* '<S640>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithTwoT_o;/* '<S644>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelaywithO_hgow;/* '<S645>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywith_hgowj;/* '<S646>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithTwo_oc;/* '<S650>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelaywit_hgowjf;/* '<S740>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywi_hgowjfv;/* '<S741>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithTw_oci;/* '<S745>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelayw_hgowjfvn;/* '<S746>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelay_hgowjfvnn;/* '<S747>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithT_oci4;/* '<S751>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDela_hgowjfvnnx;/* '<S841>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDel_hgowjfvnnxz;/* '<S842>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywith_oci4c;/* '<S846>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDe_hgowjfvnnxzl;/* '<S847>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteD_hgowjfvnnxzlo;/* '<S848>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywit_oci4cw;/* '<S852>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscrete_hgowjfvnnxzloq;/* '<S663>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_hgowjfvnnxzloqs;/* '<S664>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywi_oci4cw4;/* '<S668>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_pkx;           /* '<S657>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_lw;            /* '<S658>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelayw_oci4cw4v;/* '<S662>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_kq;            /* '<S616>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_ak;            /* '<S617>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelay_oci4cw4vl;/* '<S621>/Variable Discrete Delay with Two Taps S-function' */
  int_T SF_FixedDiscreteDelaySfunctio_h;/* '<S928>/SF_FixedDiscreteDelay S-function' */
  int_T VariableDiscret_bgs;           /* '<S764>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_cv;            /* '<S765>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDela_oci4cw4vlo;/* '<S769>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_j3;            /* '<S758>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_fr;            /* '<S759>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDel_oci4cw4vloz;/* '<S763>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_ny;            /* '<S717>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_gs3;           /* '<S718>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDe_oci4cw4vloz5;/* '<S722>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_lz;            /* '<S865>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_jl;            /* '<S866>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteD_oci4cw4vloz5b;/* '<S870>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_ev;            /* '<S859>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_edt;           /* '<S860>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscrete_oci4cw4vloz5bs;/* '<S864>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_jh;            /* '<S818>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_bm;            /* '<S819>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_oci4cw4vloz5bse;/* '<S823>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelaywithOneT_c;/* '<S959>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithOne_cj;/* '<S960>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithTwo_os;/* '<S964>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_bq;            /* '<S679>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_fqs;           /* '<S680>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_mu;            /* '<S684>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_mr;            /* '<S627>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_eb;            /* '<S628>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_oe;            /* '<S632>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_ib;            /* '<S780>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_pz;            /* '<S781>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_pei;           /* '<S785>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_fy;            /* '<S728>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_ej;            /* '<S729>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_nc;            /* '<S733>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_hf;            /* '<S881>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_a2;            /* '<S882>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_pl;            /* '<S886>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_av;            /* '<S829>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_dg;            /* '<S830>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_lwr;           /* '<S834>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelaywithOneT_e;/* '<S125>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithOne_et;/* '<S126>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithTwoT_p;/* '<S130>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelaywithOn_etx;/* '<S143>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithO_etx1;/* '<S144>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithTwo_pv;/* '<S148>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelaywith_etx1w;/* '<S131>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywit_etx1wx;/* '<S132>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithTw_pv2;/* '<S136>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelaywi_etx1wxm;/* '<S149>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelayw_etx1wxmc;/* '<S150>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithT_pv2z;/* '<S154>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelay_etx1wxmcb;/* '<S188>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDela_etx1wxmcbv;/* '<S189>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywith_pv2zv;/* '<S193>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDel_etx1wxmcbvv;/* '<S206>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDe_etx1wxmcbvvw;/* '<S207>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywit_pv2zv2;/* '<S211>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteD_etx1wxmcbvvwx;/* '<S194>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscrete_etx1wxmcbvvwx0;/* '<S195>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywi_pv2zv24;/* '<S199>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_etx1wxmcbvvwx03;/* '<S212>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_ls;            /* '<S213>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelayw_pv2zv24n;/* '<S217>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_l3;            /* '<S251>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_lb;            /* '<S252>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelay_pv2zv24nx;/* '<S256>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_a2h;           /* '<S269>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_cm;            /* '<S270>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDela_pv2zv24nxp;/* '<S274>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_pc;            /* '<S257>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_am;            /* '<S258>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDel_pv2zv24nxpe;/* '<S262>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_g05;           /* '<S275>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_f4;            /* '<S276>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDe_pv2zv24nxpeb;/* '<S280>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_jx;            /* '<S165>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_kc;            /* '<S166>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteD_pv2zv24nxpebh;/* '<S170>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_ld;            /* '<S113>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_dd;            /* '<S114>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscrete_pv2zv24nxpebhu;/* '<S118>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_hx;            /* '<S228>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_ok;            /* '<S229>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_pv2zv24nxpebhui;/* '<S233>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_iv;            /* '<S176>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_gw;            /* '<S177>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_ou;            /* '<S181>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_c2;            /* '<S291>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_au;            /* '<S292>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_l4;            /* '<S296>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscret_l5;            /* '<S239>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_hd;            /* '<S240>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscret_fe;            /* '<S244>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDela_pzv45hn0c0;/* '<S397>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDel_pzv45hn0c03;/* '<S398>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywith_mw3lz;/* '<S402>/Variable Discrete Delay with Two Taps S-function' */
  int_T VariableDiscreteDelaywithOn_cjw;/* '<S965>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithO_cjwa;/* '<S966>/Variable Discrete Delay with One Tap S-function' */
  int_T VariableDiscreteDelaywithTw_oss;/* '<S970>/Variable Discrete Delay with Two Taps S-function' */
  boolean_T UnitDelay4_DSTATE_ep;      /* '<S494>/Unit Delay4' */
  boolean_T delay_DSTATE;              /* '<S1025>/delay' */
  boolean_T UnitDelay4_DSTATE_krxzyrkobej;/* '<S312>/Unit Delay4' */
  boolean_T delay_DSTATE_b;            /* '<S457>/delay' */
  boolean_T UnitDelay2_DSTATE_lscnp0r3jm2b3;/* '<S309>/Unit Delay2' */
  boolean_T delay1_DSTATE;             /* '<S479>/delay1' */
  boolean_T delay1_DSTATE_l;           /* '<S464>/delay1' */
  boolean_T delay_DSTATE_i;            /* '<S463>/delay' */
  boolean_T delay_DSTATE_i2;           /* '<S478>/delay' */
  boolean_T delay1_DSTATE_f;           /* '<S423>/delay1' */
  boolean_T delay_DSTATE_n;            /* '<S422>/delay' */
  boolean_T UnitDelay4_DSTATE_ii;      /* '<S310>/Unit Delay4' */
  boolean_T delay1_DSTATE_n;           /* '<S558>/delay1' */
  boolean_T delay_DSTATE_c;            /* '<S557>/delay' */
  boolean_T delay1_DSTATE_nm;          /* '<S588>/delay1' */
  boolean_T delay1_DSTATE_nmq;         /* '<S573>/delay1' */
  boolean_T delay_DSTATE_ci;           /* '<S572>/delay' */
  boolean_T delay_DSTATE_cir;          /* '<S587>/delay' */
  boolean_T UnitDelay_DSTATE_b;        /* '<S686>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_md;       /* '<S787>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_cn;       /* '<S888>/Unit Delay' */
  boolean_T delay1_DSTATE_g;           /* '<S991>/delay1' */
  boolean_T delay_DSTATE_h;            /* '<S990>/delay' */
  boolean_T delay1_DSTATE_no;          /* '<S938>/delay1' */
  boolean_T UnitDelay1_DSTATE_p;       /* '<S940>/Unit Delay1' */
  boolean_T delay_DSTATE_e;            /* '<S331>/delay' */
  boolean_T UnitDelay_DSTATE_imt;      /* '<S333>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_imt2;     /* '<S346>/Unit Delay' */
  boolean_T UnitDelay2_DSTAT_lscnp0r3jm2b3r;/* '<S388>/Unit Delay2' */
  boolean_T delay_DSTATE_n0;           /* '<S434>/delay' */
  boolean_T delay1_DSTATE_fk;          /* '<S435>/delay1' */
  boolean_T UnitDelay_DSTATE_ehbxxq;   /* '<S445>/Unit Delay' */
  boolean_T delay_DSTATE_o;            /* '<S530>/delay' */
  boolean_T UnitDelay_DSTATE_jqi;      /* '<S532>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_l;        /* '<S545>/Unit Delay' */
  boolean_T UnitDelay2_DSTATE_ocn;     /* '<S956>/Unit Delay2' */
  boolean_T delay_DSTATE_ep;           /* '<S1002>/delay' */
  boolean_T delay1_DSTATE_l5;          /* '<S1003>/delay1' */
  boolean_T UnitDelay_DSTATE_jmcy;     /* '<S1013>/Unit Delay' */
} D_Work_measure;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T Vabcpu[3];                    /* '<Root>/Vabc (pu)' */
  real_T IabcAmps[3];                  /* '<Root>/Iabc (Amps)' */
} ExternalInputs_measure;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Frequency;                    /* '<Root>/Frequency' */
  real_T Voltage[10];                  /* '<Root>/Voltage' */
  real_T Current[10];                  /* '<Root>/Current' */
  real_T Power[4];                     /* '<Root>/Power' */
} ExternalOutputs_measure;

/* Parameters (auto storage) */
struct Parameters_measure_ {
  real_T Constant_Value;               /* Expression: LowerLimit
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: UpperLimit
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: const
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: LowerLimit
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: LowerLimit
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Constant_Value_bj;            /* Expression: LowerLimit
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T double_Value;                 /* Expression: 0
                                        * Referenced by: '<S116>/double'
                                        */
  real_T double_Value_o;               /* Expression: 0
                                        * Referenced by: '<S117>/double'
                                        */
  real_T double_Value_of;              /* Expression: 0
                                        * Referenced by: '<S128>/double'
                                        */
  real_T double_Value_ofa;             /* Expression: 0
                                        * Referenced by: '<S129>/double'
                                        */
  real_T double_Value_ofaw;            /* Expression: 0
                                        * Referenced by: '<S134>/double'
                                        */
  real_T double_Value_ofawr;           /* Expression: 0
                                        * Referenced by: '<S135>/double'
                                        */
  real_T double_Value_ofawrz;          /* Expression: 0
                                        * Referenced by: '<S146>/double'
                                        */
  real_T double_Value_ofawrzy;         /* Expression: 0
                                        * Referenced by: '<S147>/double'
                                        */
  real_T double_Value_ofawrzyw;        /* Expression: 0
                                        * Referenced by: '<S152>/double'
                                        */
  real_T double_Value_ofawrzywp;       /* Expression: 0
                                        * Referenced by: '<S153>/double'
                                        */
  real_T Constant_Value_o;             /* Expression: LowerLimit
                                        * Referenced by: '<S157>/Constant'
                                        */
  real_T Constant_Value_of;            /* Expression: LowerLimit
                                        * Referenced by: '<S158>/Constant'
                                        */
  real_T Constant_Value_ofa;           /* Expression: UpperLimit
                                        * Referenced by: '<S159>/Constant'
                                        */
  real_T double_Value_ofawrzywpv;      /* Expression: 0
                                        * Referenced by: '<S168>/double'
                                        */
  real_T double_Value_ofawrzywpvf;     /* Expression: 0
                                        * Referenced by: '<S169>/double'
                                        */
  real_T double_Value_ofawrzywpvfx;    /* Expression: 0
                                        * Referenced by: '<S179>/double'
                                        */
  real_T double_Value_ofawrzywpvfxm;   /* Expression: 0
                                        * Referenced by: '<S180>/double'
                                        */
  real_T double_Value_ofawrzywpvfxm1;  /* Expression: 0
                                        * Referenced by: '<S191>/double'
                                        */
  real_T double_Value_ofawrzywpvfxm1r; /* Expression: 0
                                        * Referenced by: '<S192>/double'
                                        */
  real_T double_Value_l;               /* Expression: 0
                                        * Referenced by: '<S197>/double'
                                        */
  real_T double_Value_n;               /* Expression: 0
                                        * Referenced by: '<S198>/double'
                                        */
  real_T double_Value_h;               /* Expression: 0
                                        * Referenced by: '<S209>/double'
                                        */
  real_T double_Value_i;               /* Expression: 0
                                        * Referenced by: '<S210>/double'
                                        */
  real_T double_Value_k;               /* Expression: 0
                                        * Referenced by: '<S215>/double'
                                        */
  real_T double_Value_a;               /* Expression: 0
                                        * Referenced by: '<S216>/double'
                                        */
  real_T Constant_Value_ofaw;          /* Expression: LowerLimit
                                        * Referenced by: '<S220>/Constant'
                                        */
  real_T Constant_Value_ofawr;         /* Expression: LowerLimit
                                        * Referenced by: '<S221>/Constant'
                                        */
  real_T Constant_Value_ofawrz;        /* Expression: UpperLimit
                                        * Referenced by: '<S222>/Constant'
                                        */
  real_T double_Value_k3;              /* Expression: 0
                                        * Referenced by: '<S231>/double'
                                        */
  real_T double_Value_ow;              /* Expression: 0
                                        * Referenced by: '<S232>/double'
                                        */
  real_T double_Value_d;               /* Expression: 0
                                        * Referenced by: '<S242>/double'
                                        */
  real_T double_Value_f;               /* Expression: 0
                                        * Referenced by: '<S243>/double'
                                        */
  real_T double_Value_g;               /* Expression: 0
                                        * Referenced by: '<S254>/double'
                                        */
  real_T double_Value_fo;              /* Expression: 0
                                        * Referenced by: '<S255>/double'
                                        */
  real_T double_Value_hi;              /* Expression: 0
                                        * Referenced by: '<S260>/double'
                                        */
  real_T double_Value_iw;              /* Expression: 0
                                        * Referenced by: '<S261>/double'
                                        */
  real_T double_Value_b;               /* Expression: 0
                                        * Referenced by: '<S272>/double'
                                        */
  real_T double_Value_or;              /* Expression: 0
                                        * Referenced by: '<S273>/double'
                                        */
  real_T double_Value_bv;              /* Expression: 0
                                        * Referenced by: '<S278>/double'
                                        */
  real_T double_Value_j;               /* Expression: 0
                                        * Referenced by: '<S279>/double'
                                        */
  real_T Constant_Value_ofawrzy;       /* Expression: LowerLimit
                                        * Referenced by: '<S283>/Constant'
                                        */
  real_T Constant_Value_ofawrzyw;      /* Expression: LowerLimit
                                        * Referenced by: '<S284>/Constant'
                                        */
  real_T Constant_Value_ofawrzywp;     /* Expression: UpperLimit
                                        * Referenced by: '<S285>/Constant'
                                        */
  real_T double_Value_c;               /* Expression: 0
                                        * Referenced by: '<S294>/double'
                                        */
  real_T double_Value_p;               /* Expression: 0
                                        * Referenced by: '<S295>/double'
                                        */
  real_T Constant1_Value_g;            /* Expression: Fnom
                                        * Referenced by: '<S309>/Constant1'
                                        */
  real_T Constant_Value_f;             /* Expression: UpperLimit
                                        * Referenced by: '<S323>/Constant'
                                        */
  real_T Bias_Bias;                    /* Expression: +0.999999
                                        * Referenced by: '<S336>/Bias'
                                        */
  real_T Bias1_Bias;                   /* Expression: +0.499999
                                        * Referenced by: '<S336>/Bias1'
                                        */
  real_T Bias_Bias_c;                  /* Expression: +0.999999
                                        * Referenced by: '<S345>/Bias'
                                        */
  real_T Bias1_Bias_c;                 /* Expression: +0.499999
                                        * Referenced by: '<S345>/Bias1'
                                        */
  real_T Gain_Gain;                    /* Expression: Tps/2
                                        * Referenced by: '<S317>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S462>/Gain1'
                                        */
  real_T Constant1_Value_n;            /* Expression: Fnom
                                        * Referenced by: '<S313>/Constant1'
                                        */
  real_T Bias_Bias_n;                  /* Expression: -2*pi
                                        * Referenced by: '<S355>/Bias'
                                        */
  real_T Constant_Value_n;             /* Expression: const
                                        * Referenced by: '<S356>/Constant'
                                        */
  real_T Bias1_Bias_n;                 /* Expression: +2*pi
                                        * Referenced by: '<S355>/Bias1'
                                        */
  real_T double_Value_ne;              /* Expression: 0
                                        * Referenced by: '<S361>/double'
                                        */
  real_T double_Value_nes;             /* Expression: 0
                                        * Referenced by: '<S362>/double'
                                        */
  real_T double_Value_nesm;            /* Expression: 0
                                        * Referenced by: '<S367>/double'
                                        */
  real_T double_Value_nesmw;           /* Expression: 0
                                        * Referenced by: '<S368>/double'
                                        */
  real_T double_Value_nesmwp;          /* Expression: 0
                                        * Referenced by: '<S373>/double'
                                        */
  real_T double_Value_nesmwp2;         /* Expression: 0
                                        * Referenced by: '<S374>/double'
                                        */
  real_T Constant1_Value_m;            /* Expression: UpperLimit
                                        * Referenced by: '<S314>/Constant1'
                                        */
  real_T Constant_Value_a;             /* Expression: const
                                        * Referenced by: '<S378>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: LowerLimit
                                        * Referenced by: '<S314>/Constant'
                                        */
  real_T double_Value_e;               /* Expression: 0
                                        * Referenced by: '<S394>/double'
                                        */
  real_T double_Value_ep;              /* Expression: 0
                                        * Referenced by: '<S395>/double'
                                        */
  real_T double_Value_epw;             /* Expression: 0
                                        * Referenced by: '<S400>/double'
                                        */
  real_T double_Value_epwu;            /* Expression: 0
                                        * Referenced by: '<S401>/double'
                                        */
  real_T Constant1_Value_e;            /* Expression: UpperLimit
                                        * Referenced by: '<S403>/Constant1'
                                        */
  real_T Constant_Value_ep;            /* Expression: const
                                        * Referenced by: '<S405>/Constant'
                                        */
  real_T Constant_Value_epw;           /* Expression: LowerLimit
                                        * Referenced by: '<S403>/Constant'
                                        */
  real_T Constant1_Value_ep;           /* Expression: UpperLimit
                                        * Referenced by: '<S406>/Constant1'
                                        */
  real_T Constant_Value_epwu;          /* Expression: const
                                        * Referenced by: '<S409>/Constant'
                                        */
  real_T Constant_Value_epwu2;         /* Expression: LowerLimit
                                        * Referenced by: '<S406>/Constant'
                                        */
  real_T Constant1_Value_epw;          /* Expression: UpperLimit
                                        * Referenced by: '<S407>/Constant1'
                                        */
  real_T Constant_Value_epwu2g;        /* Expression: const
                                        * Referenced by: '<S411>/Constant'
                                        */
  real_T Constant_Value_epwu2gd;       /* Expression: LowerLimit
                                        * Referenced by: '<S407>/Constant'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 1/2
                                        * Referenced by: '<S315>/Gain'
                                        */
  real_T Constant_Value_epwu2gd3;      /* Expression: const
                                        * Referenced by: '<S408>/Constant'
                                        */
  real_T Constant_Value_epwu2gd3x;     /* Expression: const
                                        * Referenced by: '<S410>/Constant'
                                        */
  real_T Constant_Value_epwu2gd3xo;    /* Expression: UpperLimit
                                        * Referenced by: '<S382>/Constant'
                                        */
  real_T Bias_Bias_e;                  /* Expression: +0.499999
                                        * Referenced by: '<S383>/Bias'
                                        */
  real_T Bias1_Bias_e;                 /* Expression: -0.499999
                                        * Referenced by: '<S383>/Bias1'
                                        */
  real_T Constant_Value_epwu2gd3xoy;   /* Expression: LowerLimit
                                        * Referenced by: '<S385>/Constant'
                                        */
  real_T Constant1_Value_epwu;         /* Expression: UpperLimit
                                        * Referenced by: '<S420>/Constant1'
                                        */
  real_T Constant_Value_epwu2gd3xoyd;  /* Expression: const
                                        * Referenced by: '<S427>/Constant'
                                        */
  real_T Constant_Value_epwu2gd3xoydf; /* Expression: LowerLimit
                                        * Referenced by: '<S420>/Constant'
                                        */
  real_T Bias_Bias_ep;                 /* Expression: +0.999999
                                        * Referenced by: '<S428>/Bias'
                                        */
  real_T Bias1_Bias_ep;                /* Expression: +0.499999
                                        * Referenced by: '<S428>/Bias1'
                                        */
  real_T Bias_Bias_epw;                /* Expression: +0.999999
                                        * Referenced by: '<S446>/Bias'
                                        */
  real_T Bias1_Bias_epw;               /* Expression: +0.499999
                                        * Referenced by: '<S446>/Bias1'
                                        */
  real_T Constant1_Value_epwu2;        /* Expression: 4000000000
                                        * Referenced by: '<S447>/Constant1'
                                        */
  real_T Constant_Value_epwu2gd3xoydfl;/* Expression: const
                                        * Referenced by: '<S450>/Constant'
                                        */
  real_T Constant_Value_epwu2gd3xoydfl5;/* Expression: 0
                                         * Referenced by: '<S447>/Constant'
                                         */
  real_T Constant_Value_k;             /* Expression: LowerLimit
                                        * Referenced by: '<S439>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: LowerLimit
                                        * Referenced by: '<S440>/Constant'
                                        */
  real_T Constant1_Value_epwu2g;       /* Expression: 1e-9
                                        * Referenced by: '<S388>/Constant1'
                                        */
  real_T Constant_Value_e1;            /* Expression: const
                                        * Referenced by: '<S436>/Constant'
                                        */
  real_T T2T1_Gain;                    /* Expression: -Tps
                                        * Referenced by: '<S388>/T2-T1'
                                        */
  real_T Constant1_Value_h;            /* Expression: UpperLimit
                                        * Referenced by: '<S461>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: const
                                        * Referenced by: '<S468>/Constant'
                                        */
  real_T Constant_Value_hp;            /* Expression: LowerLimit
                                        * Referenced by: '<S461>/Constant'
                                        */
  real_T Bias_Bias_h;                  /* Expression: +0.999999
                                        * Referenced by: '<S469>/Bias'
                                        */
  real_T Bias1_Bias_h;                 /* Expression: +0.499999
                                        * Referenced by: '<S469>/Bias1'
                                        */
  real_T Constant1_Value_hp;           /* Expression: UpperLimit
                                        * Referenced by: '<S476>/Constant1'
                                        */
  real_T Constant_Value_hpx;           /* Expression: const
                                        * Referenced by: '<S483>/Constant'
                                        */
  real_T Constant_Value_hpxm;          /* Expression: LowerLimit
                                        * Referenced by: '<S476>/Constant'
                                        */
  real_T Bias_Bias_hp;                 /* Expression: +0.999999
                                        * Referenced by: '<S484>/Bias'
                                        */
  real_T Bias1_Bias_hp;                /* Expression: +0.499999
                                        * Referenced by: '<S484>/Bias1'
                                        */
  real_T Constant4_Value;              /* Expression: Fnom
                                        * Referenced by: '<S310>/Constant4'
                                        */
  real_T Constant1_Value_j;            /* Expression: Fnom
                                        * Referenced by: '<S310>/Constant1'
                                        */
  real_T Constant_Value_oo;            /* Expression: LowerLimit
                                        * Referenced by: '<S507>/Constant'
                                        */
  real_T Constant1_Value_o;            /* Expression: UpperLimit
                                        * Referenced by: '<S508>/Constant1'
                                        */
  real_T Constant_Value_ook;           /* Expression: const
                                        * Referenced by: '<S514>/Constant'
                                        */
  real_T Constant_Value_ookg;          /* Expression: LowerLimit
                                        * Referenced by: '<S508>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 1e-9
                                        * Referenced by: '<S509>/Constant2'
                                        */
  real_T Constant_Value_ookgl;         /* Expression: LowerLimit
                                        * Referenced by: '<S516>/Constant'
                                        */
  real_T Constant_Value_ookgly;        /* Expression: const
                                        * Referenced by: '<S518>/Constant'
                                        */
  real_T Constant_Value_ookglyi;       /* Expression: LowerLimit
                                        * Referenced by: '<S517>/Constant'
                                        */
  real_T Constant_Value_ookglyim;      /* Expression: const
                                        * Referenced by: '<S519>/Constant'
                                        */
  real_T Constant_Value_ookglyimv;     /* Expression: const
                                        * Referenced by: '<S515>/Constant'
                                        */
  real_T Constant2_Value_o;            /* Expression: 1e-9
                                        * Referenced by: '<S510>/Constant2'
                                        */
  real_T Constant_Value_ookglyimve;    /* Expression: LowerLimit
                                        * Referenced by: '<S521>/Constant'
                                        */
  real_T Constant_Value_ookglyimven;   /* Expression: const
                                        * Referenced by: '<S523>/Constant'
                                        */
  real_T Constant_Value_ookglyimven1;  /* Expression: LowerLimit
                                        * Referenced by: '<S522>/Constant'
                                        */
  real_T Constant_Value_ookglyimven12; /* Expression: const
                                        * Referenced by: '<S524>/Constant'
                                        */
  real_T Constant_Value_ookglyimven12a;/* Expression: const
                                        * Referenced by: '<S520>/Constant'
                                        */
  real_T Constant2_Value_oo;           /* Expression: 1e-9
                                        * Referenced by: '<S511>/Constant2'
                                        */
  real_T Constant_Value_ookglyimven12av;/* Expression: LowerLimit
                                         * Referenced by: '<S526>/Constant'
                                         */
  real_T Constant_Value_md;            /* Expression: const
                                        * Referenced by: '<S528>/Constant'
                                        */
  real_T Constant_Value_oa;            /* Expression: LowerLimit
                                        * Referenced by: '<S527>/Constant'
                                        */
  real_T Constant_Value_b4;            /* Expression: const
                                        * Referenced by: '<S529>/Constant'
                                        */
  real_T Constant_Value_k1;            /* Expression: const
                                        * Referenced by: '<S525>/Constant'
                                        */
  real_T Bias_Bias_d;                  /* Expression: +0.999999
                                        * Referenced by: '<S535>/Bias'
                                        */
  real_T Bias1_Bias_d;                 /* Expression: +0.499999
                                        * Referenced by: '<S535>/Bias1'
                                        */
  real_T Bias_Bias_b;                  /* Expression: +0.999999
                                        * Referenced by: '<S544>/Bias'
                                        */
  real_T Bias1_Bias_b;                 /* Expression: +0.499999
                                        * Referenced by: '<S544>/Bias1'
                                        */
  real_T Bias_Bias_a;                  /* Expression: -2*pi
                                        * Referenced by: '<S547>/Bias'
                                        */
  real_T Constant_Value_ad;            /* Expression: LowerLimit
                                        * Referenced by: '<S548>/Constant'
                                        */
  real_T Constant1_Value_a;            /* Expression: UpperLimit
                                        * Referenced by: '<S555>/Constant1'
                                        */
  real_T Constant_Value_adh;           /* Expression: const
                                        * Referenced by: '<S562>/Constant'
                                        */
  real_T Constant_Value_adhz;          /* Expression: LowerLimit
                                        * Referenced by: '<S555>/Constant'
                                        */
  real_T Bias_Bias_ad;                 /* Expression: +0.999999
                                        * Referenced by: '<S563>/Bias'
                                        */
  real_T Bias1_Bias_a;                 /* Expression: +0.499999
                                        * Referenced by: '<S563>/Bias1'
                                        */
  real_T Constant1_Value_ad;           /* Expression: UpperLimit
                                        * Referenced by: '<S570>/Constant1'
                                        */
  real_T Constant_Value_adhzk;         /* Expression: const
                                        * Referenced by: '<S577>/Constant'
                                        */
  real_T Constant_Value_adhzk5;        /* Expression: LowerLimit
                                        * Referenced by: '<S570>/Constant'
                                        */
  real_T Bias_Bias_adh;                /* Expression: +0.999999
                                        * Referenced by: '<S578>/Bias'
                                        */
  real_T Bias1_Bias_ad;                /* Expression: +0.499999
                                        * Referenced by: '<S578>/Bias1'
                                        */
  real_T Constant1_Value_adh;          /* Expression: UpperLimit
                                        * Referenced by: '<S585>/Constant1'
                                        */
  real_T Constant_Value_adhzk50;       /* Expression: const
                                        * Referenced by: '<S592>/Constant'
                                        */
  real_T Constant_Value_adhzk50w;      /* Expression: LowerLimit
                                        * Referenced by: '<S585>/Constant'
                                        */
  real_T Bias_Bias_adhz;               /* Expression: +0.999999
                                        * Referenced by: '<S593>/Bias'
                                        */
  real_T Bias1_Bias_adh;               /* Expression: +0.499999
                                        * Referenced by: '<S593>/Bias1'
                                        */
  real_T Bias_Bias_k;                  /* Expression: -2*pi
                                        * Referenced by: '<S613>/Bias'
                                        */
  real_T Constant_Value_kk;            /* Expression: const
                                        * Referenced by: '<S614>/Constant'
                                        */
  real_T Bias1_Bias_k;                 /* Expression: +2*pi
                                        * Referenced by: '<S613>/Bias1'
                                        */
  real_T Constant1_Value_jk;           /* Expression: UpperLimit
                                        * Referenced by: '<S606>/Constant1'
                                        */
  real_T Constant_Value_hi;            /* Expression: const
                                        * Referenced by: '<S694>/Constant'
                                        */
  real_T Constant_Value_mm;            /* Expression: LowerLimit
                                        * Referenced by: '<S606>/Constant'
                                        */
  real_T Constant_Value_kkp;           /* Expression: const
                                        * Referenced by: '<S615>/Constant'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1/(Tps*2*pi)
                                        * Referenced by: '<S600>/Gain'
                                        */
  real_T Constant_Value_bt;            /* Expression: const
                                        * Referenced by: '<S693>/Constant'
                                        */
  real_T Bias_Bias_e5;                 /* Expression: -2*pi
                                        * Referenced by: '<S610>/Bias'
                                        */
  real_T Constant_Value_e5;            /* Expression: const
                                        * Referenced by: '<S611>/Constant'
                                        */
  real_T Bias1_Bias_e5;                /* Expression: +2*pi
                                        * Referenced by: '<S610>/Bias1'
                                        */
  real_T double_Value_d1;              /* Expression: 0
                                        * Referenced by: '<S619>/double'
                                        */
  real_T double_Value_d1r;             /* Expression: 0
                                        * Referenced by: '<S620>/double'
                                        */
  real_T double_Value_bl;              /* Expression: 0
                                        * Referenced by: '<S630>/double'
                                        */
  real_T double_Value_bln;             /* Expression: 0
                                        * Referenced by: '<S631>/double'
                                        */
  real_T double_Value_bln4;            /* Expression: 0
                                        * Referenced by: '<S642>/double'
                                        */
  real_T double_Value_bln4d;           /* Expression: 0
                                        * Referenced by: '<S643>/double'
                                        */
  real_T double_Value_bln4dj;          /* Expression: 0
                                        * Referenced by: '<S648>/double'
                                        */
  real_T double_Value_bln4djb;         /* Expression: 0
                                        * Referenced by: '<S649>/double'
                                        */
  real_T double_Value_bln4djb4;        /* Expression: 0
                                        * Referenced by: '<S660>/double'
                                        */
  real_T double_Value_bln4djb4g;       /* Expression: 0
                                        * Referenced by: '<S661>/double'
                                        */
  real_T double_Value_bln4djb4gs;      /* Expression: 0
                                        * Referenced by: '<S666>/double'
                                        */
  real_T double_Value_bln4djb4gs5;     /* Expression: 0
                                        * Referenced by: '<S667>/double'
                                        */
  real_T Constant_Value_bl;            /* Expression: LowerLimit
                                        * Referenced by: '<S671>/Constant'
                                        */
  real_T Constant_Value_bln;           /* Expression: LowerLimit
                                        * Referenced by: '<S672>/Constant'
                                        */
  real_T Constant_Value_bln4;          /* Expression: UpperLimit
                                        * Referenced by: '<S673>/Constant'
                                        */
  real_T double_Value_bln4djb4gs54;    /* Expression: 0
                                        * Referenced by: '<S682>/double'
                                        */
  real_T double_Value_bln4djb4gs54q;   /* Expression: 0
                                        * Referenced by: '<S683>/double'
                                        */
  real_T Bias_Bias_co;                 /* Expression: -2*pi
                                        * Referenced by: '<S714>/Bias'
                                        */
  real_T Constant_Value_co;            /* Expression: const
                                        * Referenced by: '<S715>/Constant'
                                        */
  real_T Bias1_Bias_co;                /* Expression: +2*pi
                                        * Referenced by: '<S714>/Bias1'
                                        */
  real_T Constant1_Value_mw;           /* Expression: UpperLimit
                                        * Referenced by: '<S707>/Constant1'
                                        */
  real_T Constant_Value_kh;            /* Expression: const
                                        * Referenced by: '<S795>/Constant'
                                        */
  real_T Constant_Value_kg;            /* Expression: LowerLimit
                                        * Referenced by: '<S707>/Constant'
                                        */
  real_T Constant_Value_coy;           /* Expression: const
                                        * Referenced by: '<S716>/Constant'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 1/(Tps*2*pi)
                                        * Referenced by: '<S701>/Gain'
                                        */
  real_T Constant_Value_kp;            /* Expression: const
                                        * Referenced by: '<S794>/Constant'
                                        */
  real_T Bias_Bias_m;                  /* Expression: -2*pi
                                        * Referenced by: '<S711>/Bias'
                                        */
  real_T Constant_Value_m0;            /* Expression: const
                                        * Referenced by: '<S712>/Constant'
                                        */
  real_T Bias1_Bias_m;                 /* Expression: +2*pi
                                        * Referenced by: '<S711>/Bias1'
                                        */
  real_T double_Value_fj;              /* Expression: 0
                                        * Referenced by: '<S720>/double'
                                        */
  real_T double_Value_fjq;             /* Expression: 0
                                        * Referenced by: '<S721>/double'
                                        */
  real_T double_Value_ez;              /* Expression: 0
                                        * Referenced by: '<S731>/double'
                                        */
  real_T double_Value_ezn;             /* Expression: 0
                                        * Referenced by: '<S732>/double'
                                        */
  real_T double_Value_eznc;            /* Expression: 0
                                        * Referenced by: '<S743>/double'
                                        */
  real_T double_Value_ezncl;           /* Expression: 0
                                        * Referenced by: '<S744>/double'
                                        */
  real_T double_Value_eznclc;          /* Expression: 0
                                        * Referenced by: '<S749>/double'
                                        */
  real_T double_Value_eznclc5;         /* Expression: 0
                                        * Referenced by: '<S750>/double'
                                        */
  real_T double_Value_eznclc5x;        /* Expression: 0
                                        * Referenced by: '<S761>/double'
                                        */
  real_T double_Value_eznclc5xg;       /* Expression: 0
                                        * Referenced by: '<S762>/double'
                                        */
  real_T double_Value_eznclc5xg5;      /* Expression: 0
                                        * Referenced by: '<S767>/double'
                                        */
  real_T double_Value_eznclc5xg5q;     /* Expression: 0
                                        * Referenced by: '<S768>/double'
                                        */
  real_T Constant_Value_ez;            /* Expression: LowerLimit
                                        * Referenced by: '<S772>/Constant'
                                        */
  real_T Constant_Value_ezn;           /* Expression: LowerLimit
                                        * Referenced by: '<S773>/Constant'
                                        */
  real_T Constant_Value_eznc;          /* Expression: UpperLimit
                                        * Referenced by: '<S774>/Constant'
                                        */
  real_T double_Value_eznclc5xg5q1;    /* Expression: 0
                                        * Referenced by: '<S783>/double'
                                        */
  real_T double_Value_eznclc5xg5q1u;   /* Expression: 0
                                        * Referenced by: '<S784>/double'
                                        */
  real_T Bias_Bias_f;                  /* Expression: -2*pi
                                        * Referenced by: '<S815>/Bias'
                                        */
  real_T Constant_Value_fg;            /* Expression: const
                                        * Referenced by: '<S816>/Constant'
                                        */
  real_T Bias1_Bias_f;                 /* Expression: +2*pi
                                        * Referenced by: '<S815>/Bias1'
                                        */
  real_T Constant1_Value_ob;           /* Expression: UpperLimit
                                        * Referenced by: '<S808>/Constant1'
                                        */
  real_T Constant_Value_j;             /* Expression: const
                                        * Referenced by: '<S896>/Constant'
                                        */
  real_T Constant_Value_a4;            /* Expression: LowerLimit
                                        * Referenced by: '<S808>/Constant'
                                        */
  real_T Constant_Value_fgl;           /* Expression: const
                                        * Referenced by: '<S817>/Constant'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 1/(Tps*2*pi)
                                        * Referenced by: '<S802>/Gain'
                                        */
  real_T Constant_Value_nv;            /* Expression: const
                                        * Referenced by: '<S895>/Constant'
                                        */
  real_T Bias_Bias_ki;                 /* Expression: -2*pi
                                        * Referenced by: '<S812>/Bias'
                                        */
  real_T Constant_Value_ki;            /* Expression: const
                                        * Referenced by: '<S813>/Constant'
                                        */
  real_T Bias1_Bias_ki;                /* Expression: +2*pi
                                        * Referenced by: '<S812>/Bias1'
                                        */
  real_T double_Value_g0;              /* Expression: 0
                                        * Referenced by: '<S821>/double'
                                        */
  real_T double_Value_g0w;             /* Expression: 0
                                        * Referenced by: '<S822>/double'
                                        */
  real_T double_Value_e0;              /* Expression: 0
                                        * Referenced by: '<S832>/double'
                                        */
  real_T double_Value_e0r;             /* Expression: 0
                                        * Referenced by: '<S833>/double'
                                        */
  real_T double_Value_e0r1;            /* Expression: 0
                                        * Referenced by: '<S844>/double'
                                        */
  real_T double_Value_e0r1h;           /* Expression: 0
                                        * Referenced by: '<S845>/double'
                                        */
  real_T double_Value_e0r1hm;          /* Expression: 0
                                        * Referenced by: '<S850>/double'
                                        */
  real_T double_Value_e0r1hmw;         /* Expression: 0
                                        * Referenced by: '<S851>/double'
                                        */
  real_T double_Value_e0r1hmwt;        /* Expression: 0
                                        * Referenced by: '<S862>/double'
                                        */
  real_T double_Value_e0r1hmwtw;       /* Expression: 0
                                        * Referenced by: '<S863>/double'
                                        */
  real_T double_Value_e0r1hmwtwq;      /* Expression: 0
                                        * Referenced by: '<S868>/double'
                                        */
  real_T double_Value_e0r1hmwtwqc;     /* Expression: 0
                                        * Referenced by: '<S869>/double'
                                        */
  real_T Constant_Value_e0;            /* Expression: LowerLimit
                                        * Referenced by: '<S873>/Constant'
                                        */
  real_T Constant_Value_e0r;           /* Expression: LowerLimit
                                        * Referenced by: '<S874>/Constant'
                                        */
  real_T Constant_Value_e0r1;          /* Expression: UpperLimit
                                        * Referenced by: '<S875>/Constant'
                                        */
  real_T double_Value_e0r1hmwtwqc2;    /* Expression: 0
                                        * Referenced by: '<S884>/double'
                                        */
  real_T double_Value_e0r1hmwtwqc2e;   /* Expression: 0
                                        * Referenced by: '<S885>/double'
                                        */
  real_T double_Value_ii;              /* Expression: 0
                                        * Referenced by: '<S962>/double'
                                        */
  real_T double_Value_ii1;             /* Expression: 0
                                        * Referenced by: '<S963>/double'
                                        */
  real_T double_Value_ii12;            /* Expression: 0
                                        * Referenced by: '<S968>/double'
                                        */
  real_T double_Value_ii12h;           /* Expression: 0
                                        * Referenced by: '<S969>/double'
                                        */
  real_T Constant1_Value_f;            /* Expression: UpperLimit
                                        * Referenced by: '<S971>/Constant1'
                                        */
  real_T Constant_Value_fg1;           /* Expression: const
                                        * Referenced by: '<S973>/Constant'
                                        */
  real_T Constant_Value_fg15;          /* Expression: LowerLimit
                                        * Referenced by: '<S971>/Constant'
                                        */
  real_T Constant1_Value_hpe;          /* Expression: UpperLimit
                                        * Referenced by: '<S974>/Constant1'
                                        */
  real_T Constant_Value_hpe;           /* Expression: const
                                        * Referenced by: '<S977>/Constant'
                                        */
  real_T Constant_Value_hper;          /* Expression: LowerLimit
                                        * Referenced by: '<S974>/Constant'
                                        */
  real_T Constant1_Value_hper;         /* Expression: UpperLimit
                                        * Referenced by: '<S975>/Constant1'
                                        */
  real_T Constant_Value_hper2;         /* Expression: const
                                        * Referenced by: '<S979>/Constant'
                                        */
  real_T Constant_Value_hper21;        /* Expression: LowerLimit
                                        * Referenced by: '<S975>/Constant'
                                        */
  real_T Gain_Gain_ce;                 /* Expression: 1/2
                                        * Referenced by: '<S503>/Gain'
                                        */
  real_T Constant_Value_hper21c;       /* Expression: const
                                        * Referenced by: '<S976>/Constant'
                                        */
  real_T Constant_Value_hper21c0;      /* Expression: const
                                        * Referenced by: '<S978>/Constant'
                                        */
  real_T Constant_Value_hper21c0u;     /* Expression: UpperLimit
                                        * Referenced by: '<S950>/Constant'
                                        */
  real_T Bias_Bias_i;                  /* Expression: +0.499999
                                        * Referenced by: '<S951>/Bias'
                                        */
  real_T Bias1_Bias_i;                 /* Expression: -0.499999
                                        * Referenced by: '<S951>/Bias1'
                                        */
  real_T Constant_Value_l;             /* Expression: LowerLimit
                                        * Referenced by: '<S953>/Constant'
                                        */
  real_T Constant1_Value_c;            /* Expression: UpperLimit
                                        * Referenced by: '<S988>/Constant1'
                                        */
  real_T Constant_Value_cj;            /* Expression: const
                                        * Referenced by: '<S995>/Constant'
                                        */
  real_T Constant_Value_cjw;           /* Expression: LowerLimit
                                        * Referenced by: '<S988>/Constant'
                                        */
  real_T Bias_Bias_p;                  /* Expression: +0.999999
                                        * Referenced by: '<S996>/Bias'
                                        */
  real_T Bias1_Bias_p;                 /* Expression: +0.499999
                                        * Referenced by: '<S996>/Bias1'
                                        */
  real_T Bias_Bias_g;                  /* Expression: +0.999999
                                        * Referenced by: '<S1014>/Bias'
                                        */
  real_T Bias1_Bias_g;                 /* Expression: +0.499999
                                        * Referenced by: '<S1014>/Bias1'
                                        */
  real_T Constant1_Value_gb;           /* Expression: 4000000000
                                        * Referenced by: '<S1015>/Constant1'
                                        */
  real_T Constant_Value_g;             /* Expression: const
                                        * Referenced by: '<S1018>/Constant'
                                        */
  real_T Constant_Value_gb;            /* Expression: 0
                                        * Referenced by: '<S1015>/Constant'
                                        */
  real_T Constant_Value_gbv;           /* Expression: LowerLimit
                                        * Referenced by: '<S1007>/Constant'
                                        */
  real_T Constant_Value_gbvu;          /* Expression: LowerLimit
                                        * Referenced by: '<S1008>/Constant'
                                        */
  real_T Constant1_Value_gbv;          /* Expression: 1e-9
                                        * Referenced by: '<S956>/Constant1'
                                        */
  real_T Constant_Value_gbvuw;         /* Expression: const
                                        * Referenced by: '<S1004>/Constant'
                                        */
  real_T T2T1_Gain_g;                  /* Expression: -Tps
                                        * Referenced by: '<S956>/T2-T1'
                                        */
  real_T SF_FixedDiscreteDelaySfunction_;/* Expression: double(x0(1))
                                          * Referenced by: '<S1027>/SF_FixedDiscreteDelay S-function'
                                          */
  real_T UnitDelay_X0;                 /* Expression: x0
                                        * Referenced by: '<S504>/Unit Delay'
                                        */
  real_T SF_FixedDiscreteDelaySfunctio_o;/* Expression: double(x0(1))
                                          * Referenced by: '<S459>/SF_FixedDiscreteDelay S-function'
                                          */
  real_T UnitDelay_X0_o;               /* Expression: x0
                                        * Referenced by: '<S316>/Unit Delay'
                                        */
  real_T UnitDelay_X0_j;               /* Expression: Fnom
                                        * Referenced by: '<S309>/Unit Delay'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S475>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Expression: (ceil((dtMax*2)/Tps)+20)
                                        * Referenced by: '<S475>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Expression: ceil((ceil((dtMax*2)/Tps)+20)/2)
                                        * Referenced by: '<S475>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S475>/Pulse Generator1'
                                        */
  real_T Constant_Value_hpxmk;         /* Expression: const
                                        * Referenced by: '<S481>/Constant'
                                        */
  real_T PulseGenerator1_Amp_h;        /* Expression: 1
                                        * Referenced by: '<S460>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period_h;     /* Expression: (ceil((dtMax*2)/Tps)+20)
                                        * Referenced by: '<S460>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty_h;       /* Expression: ceil((ceil((dtMax*2)/Tps)+20)/2)
                                        * Referenced by: '<S460>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay_h; /* Expression: 0
                                        * Referenced by: '<S460>/Pulse Generator1'
                                        */
  real_T Constant_Value_hpxmkf;        /* Expression: const
                                        * Referenced by: '<S466>/Constant'
                                        */
  real_T UnitDelay3_X0;                /* Expression: 0
                                        * Referenced by: '<S348>/Unit Delay3'
                                        */
  real_T UnitDelay1_X0;                /* Expression: 0
                                        * Referenced by: '<S85>/Unit Delay1'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S85>/Unit Delay2'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 1/2
                                        * Referenced by: '<S93>/Gain'
                                        */
  real_T Constant7_Value[3];           /* Expression: [0 0 0] * 10e-6
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant8_Value[3];           /* Expression: [0 0 0] * 10e-6
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1/Tps
                                        * Referenced by: '<S85>/Gain'
                                        */
  real_T Bias_Bias_j;                  /* Expression: 1
                                        * Referenced by: '<S85>/Bias'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 1/2
                                        * Referenced by: '<S93>/Gain1'
                                        */
  real_T UnitDelay1_X0_i;              /* Expression: 0
                                        * Referenced by: '<S86>/Unit Delay1'
                                        */
  real_T UnitDelay2_X0_l;              /* Expression: 0
                                        * Referenced by: '<S86>/Unit Delay2'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 1/2
                                        * Referenced by: '<S95>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -1/Tps
                                        * Referenced by: '<S86>/Gain'
                                        */
  real_T Bias_Bias_it;                 /* Expression: 1
                                        * Referenced by: '<S86>/Bias'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 1/2
                                        * Referenced by: '<S95>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S352>/Gain2'
                                        */
  real_T UnitDelay1_X0_e;              /* Expression: 0
                                        * Referenced by: '<S84>/Unit Delay1'
                                        */
  real_T UnitDelay2_X0_g;              /* Expression: 0
                                        * Referenced by: '<S84>/Unit Delay2'
                                        */
  real_T Gain_Gain_ew;                 /* Expression: 1/2
                                        * Referenced by: '<S91>/Gain'
                                        */
  real_T Gain_Gain_b;                  /* Expression: -1/Tps
                                        * Referenced by: '<S84>/Gain'
                                        */
  real_T Bias_Bias_pv;                 /* Expression: 1
                                        * Referenced by: '<S84>/Bias'
                                        */
  real_T Gain1_Gain_dy;                /* Expression: 1/2
                                        * Referenced by: '<S91>/Gain1'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 2
                                        * Referenced by: '<S352>/Gain'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 1/3
                                        * Referenced by: '<S352>/Gain1'
                                        */
  real_T Constant_Value_ne;            /* Expression: const
                                        * Referenced by: '<S357>/Constant'
                                        */
  real_T Gain_Gain_ne;                 /* Expression: 1/(Tps*2*pi)
                                        * Referenced by: '<S348>/Gain'
                                        */
  real_T UnitDelay4_X0;                /* Expression: 0
                                        * Referenced by: '<S361>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_n;              /* Expression: 0
                                        * Referenced by: '<S361>/Unit Delay2'
                                        */
  real_T Constant_Value_hpxmkfi;       /* Expression: const
                                        * Referenced by: '<S467>/Constant'
                                        */
  real_T Gain_Gain_hp;                 /* Expression: 1/Tps
                                        * Referenced by: '<S462>/Gain'
                                        */
  real_T Constant_Value_hpxmkfin;      /* Expression: 0
                                        * Referenced by: '<S472>/Constant'
                                        */
  real_T UnitDelay4_X0_n;              /* Expression: 0
                                        * Referenced by: '<S362>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ne;             /* Expression: 0
                                        * Referenced by: '<S362>/Unit Delay2'
                                        */
  real_T Constant_Value_nes;           /* Expression: 0
                                        * Referenced by: '<S376>/Constant'
                                        */
  real_T UnitDelay4_X0_ne;             /* Expression: 0
                                        * Referenced by: '<S367>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_nes;            /* Expression: 0
                                        * Referenced by: '<S367>/Unit Delay2'
                                        */
  real_T Gain_Gain_ni;                 /* Expression: 2
                                        * Referenced by: '<S309>/Gain'
                                        */
  real_T Constant_Value_hpxmkfino;     /* Expression: const
                                        * Referenced by: '<S482>/Constant'
                                        */
  real_T Gain_Gain_hpx;                /* Expression: 1/Tps
                                        * Referenced by: '<S477>/Gain'
                                        */
  real_T Constant_Value_hpxmkfinoy;    /* Expression: 0
                                        * Referenced by: '<S487>/Constant'
                                        */
  real_T UnitDelay4_X0_nes;            /* Expression: 0
                                        * Referenced by: '<S368>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_nesm;           /* Expression: 0
                                        * Referenced by: '<S368>/Unit Delay2'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 2
                                        * Referenced by: '<S477>/Gain1'
                                        */
  real_T Gain_Gain_hpxm;               /* Expression: Tps/2
                                        * Referenced by: '<S318>/Gain'
                                        */
  real_T UnitDelay4_X0_nesm;           /* Expression: 0
                                        * Referenced by: '<S373>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_nesmw;          /* Expression: 0
                                        * Referenced by: '<S373>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_nesmw;          /* Expression: 0
                                        * Referenced by: '<S374>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_nesmwp;         /* Expression: 0
                                        * Referenced by: '<S374>/Unit Delay2'
                                        */
  real_T Constant5_Value;              /* Expression: 0.02
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 1/0.05/(2*pi*Tps)
                                        * Referenced by: '<S311>/Gain1'
                                        */
  real_T Bias_Bias_fk;                 /* Expression: Fnom*1.2*3
                                        * Referenced by: '<S311>/Bias'
                                        */
  real_T Constant_Value_fk;            /* Expression: const
                                        * Referenced by: '<S330>/Constant'
                                        */
  real_T PulseGenerator1_Amp_e;        /* Expression: 1
                                        * Referenced by: '<S419>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period_e;     /* Expression: (ceil((dtMax*2)/Tps)+20)
                                        * Referenced by: '<S419>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty_e;       /* Expression: ceil((ceil((dtMax*2)/Tps)+20)/2)
                                        * Referenced by: '<S419>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay_e; /* Expression: 0
                                        * Referenced by: '<S419>/Pulse Generator1'
                                        */
  real_T Constant_Value_li;            /* Expression: const
                                        * Referenced by: '<S425>/Constant'
                                        */
  real_T UnitDelay4_X0_e;              /* Expression: 0
                                        * Referenced by: '<S394>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e;              /* Expression: 0
                                        * Referenced by: '<S394>/Unit Delay2'
                                        */
  real_T UnitDelay2_X0_ep;             /* Expression: 0
                                        * Referenced by: '<S315>/Unit Delay2'
                                        */
  real_T Constant_Value_a2;            /* Expression: const
                                        * Referenced by: '<S426>/Constant'
                                        */
  real_T Gain_Gain_ep;                 /* Expression: 1/Tps
                                        * Referenced by: '<S421>/Gain'
                                        */
  real_T Constant_Value_pz;            /* Expression: 0
                                        * Referenced by: '<S431>/Constant'
                                        */
  real_T UnitDelay4_X0_ep;             /* Expression: 0
                                        * Referenced by: '<S395>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_epw;            /* Expression: 0
                                        * Referenced by: '<S395>/Unit Delay2'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S421>/Gain1'
                                        */
  real_T Gain_Gain_epw;                /* Expression: Tps/2
                                        * Referenced by: '<S387>/Gain'
                                        */
  real_T Constant_Value_ed;            /* Expression: 0
                                        * Referenced by: '<S456>/Constant'
                                        */
  real_T Constant2_Value_h;            /* Expression: 5
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain1_Gain_n5;                /* Expression: 4/2/Fnom
                                        * Referenced by: '<S309>/Gain1'
                                        */
  real_T Constant_Value_aw;            /* Expression: const
                                        * Referenced by: '<S377>/Constant'
                                        */
  real_T UnitDelay2_X0_nc;             /* Expression: Fnom
                                        * Referenced by: '<S310>/Unit Delay2'
                                        */
  real_T PulseGenerator1_Amp_a;        /* Expression: 1
                                        * Referenced by: '<S554>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period_a;     /* Expression: (ceil((dtMax*2)/Tps)+20)
                                        * Referenced by: '<S554>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty_a;       /* Expression: ceil((ceil((dtMax*2)/Tps)+20)/2)
                                        * Referenced by: '<S554>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay_a; /* Expression: 0
                                        * Referenced by: '<S554>/Pulse Generator1'
                                        */
  real_T Constant_Value_adhzk50wx;     /* Expression: const
                                        * Referenced by: '<S560>/Constant'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 2*pi*Tps
                                        * Referenced by: '<S495>/Gain'
                                        */
  real_T UnitDelay_X0_a;               /* Expression: 0
                                        * Referenced by: '<S495>/Unit Delay'
                                        */
  real_T Constant_Value_adhzk50wx0;    /* Expression: const
                                        * Referenced by: '<S552>/Constant'
                                        */
  real_T Constant_Value_adhzk50wx0e;   /* Expression: const
                                        * Referenced by: '<S553>/Constant'
                                        */
  real_T FCn3_Gain;                    /* Expression: 1/MinFreq
                                        * Referenced by: '<S495>/F//Cn3'
                                        */
  real_T Bias_Bias_adhzk;              /* Expression: 2
                                        * Referenced by: '<S495>/Bias'
                                        */
  real_T UnitDelay4_X0_b;              /* Expression: 0
                                        * Referenced by: '<S642>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_b;              /* Expression: 0
                                        * Referenced by: '<S642>/Unit Delay2'
                                        */
  real_T Constant_Value_adhzk50wx0e4;  /* Expression: const
                                        * Referenced by: '<S561>/Constant'
                                        */
  real_T Gain_Gain_ad;                 /* Expression: 1/Tps
                                        * Referenced by: '<S556>/Gain'
                                        */
  real_T Constant_Value_adhzk50wx0e4y; /* Expression: 0
                                        * Referenced by: '<S566>/Constant'
                                        */
  real_T UnitDelay4_X0_bl;             /* Expression: 0
                                        * Referenced by: '<S643>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bl;             /* Expression: 0
                                        * Referenced by: '<S643>/Unit Delay2'
                                        */
  real_T Gain1_Gain_ad;                /* Expression: 2
                                        * Referenced by: '<S556>/Gain1'
                                        */
  real_T Gain_Gain_adh;                /* Expression: Tps/2
                                        * Referenced by: '<S549>/Gain'
                                        */
  real_T UnitDelay4_X0_bln;            /* Expression: 0
                                        * Referenced by: '<S648>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bln;            /* Expression: 0
                                        * Referenced by: '<S648>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_bln4;           /* Expression: 0
                                        * Referenced by: '<S649>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bln4;           /* Expression: 0
                                        * Referenced by: '<S649>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ez;             /* Expression: 0
                                        * Referenced by: '<S743>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ez;             /* Expression: 0
                                        * Referenced by: '<S743>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ezn;            /* Expression: 0
                                        * Referenced by: '<S744>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ezn;            /* Expression: 0
                                        * Referenced by: '<S744>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_eznc;           /* Expression: 0
                                        * Referenced by: '<S749>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_eznc;           /* Expression: 0
                                        * Referenced by: '<S749>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ezncl;          /* Expression: 0
                                        * Referenced by: '<S750>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ezncl;          /* Expression: 0
                                        * Referenced by: '<S750>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_e0;             /* Expression: 0
                                        * Referenced by: '<S844>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0;             /* Expression: 0
                                        * Referenced by: '<S844>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_e0r;            /* Expression: 0
                                        * Referenced by: '<S845>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0r;            /* Expression: 0
                                        * Referenced by: '<S845>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_e0r1;           /* Expression: 0
                                        * Referenced by: '<S850>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0r1;           /* Expression: 0
                                        * Referenced by: '<S850>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_e0r1h;          /* Expression: 0
                                        * Referenced by: '<S851>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0r1h;          /* Expression: 0
                                        * Referenced by: '<S851>/Unit Delay2'
                                        */
  real_T PulseGenerator1_Amp_ad;       /* Expression: 1
                                        * Referenced by: '<S584>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period_ad;    /* Expression: (ceil((dtMax*2)/Tps)+20)
                                        * Referenced by: '<S584>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty_ad;      /* Expression: ceil((ceil((dtMax*2)/Tps)+20)/2)
                                        * Referenced by: '<S584>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay_ad;/* Expression: 0
                                        * Referenced by: '<S584>/Pulse Generator1'
                                        */
  real_T Constant_Value_adhzk50wx0e4yn;/* Expression: const
                                        * Referenced by: '<S590>/Constant'
                                        */
  real_T UnitDelay3_X0_k;              /* Expression: 0
                                        * Referenced by: '<S600>/Unit Delay3'
                                        */
  real_T PulseGenerator1_Amp_adh;      /* Expression: 1
                                        * Referenced by: '<S569>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period_adh;   /* Expression: (ceil((dtMax*2)/Tps)+20)
                                        * Referenced by: '<S569>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty_adh;     /* Expression: ceil((ceil((dtMax*2)/Tps)+20)/2)
                                        * Referenced by: '<S569>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay_adh;/* Expression: 0
                                         * Referenced by: '<S569>/Pulse Generator1'
                                         */
  real_T Constant_Value_adhzk50wx0e4yn1;/* Expression: const
                                         * Referenced by: '<S575>/Constant'
                                         */
  real_T UnitDelay4_X0_bln4d;          /* Expression: 0
                                        * Referenced by: '<S666>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bln4d;          /* Expression: 0
                                        * Referenced by: '<S666>/Unit Delay2'
                                        */
  real_T FCn1_Gain;                    /* Expression: 1/2
                                        * Referenced by: '<S495>/F//Cn1'
                                        */
  real_T Constant_Value_d;             /* Expression: const
                                        * Referenced by: '<S576>/Constant'
                                        */
  real_T Gain_Gain_adhz;               /* Expression: 1/Tps
                                        * Referenced by: '<S571>/Gain'
                                        */
  real_T Constant_Value_gv;            /* Expression: 0
                                        * Referenced by: '<S581>/Constant'
                                        */
  real_T UnitDelay4_X0_bln4dj;         /* Expression: 0
                                        * Referenced by: '<S667>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bln4dj;         /* Expression: 0
                                        * Referenced by: '<S667>/Unit Delay2'
                                        */
  real_T Gain1_Gain_adh;               /* Expression: 2
                                        * Referenced by: '<S571>/Gain1'
                                        */
  real_T Gain_Gain_adhzk;              /* Expression: Tps/2
                                        * Referenced by: '<S550>/Gain'
                                        */
  real_T UnitDelay4_X0_bln4djb;        /* Expression: 0
                                        * Referenced by: '<S660>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bln4djb;        /* Expression: 0
                                        * Referenced by: '<S660>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_bln4djb4;       /* Expression: 0
                                        * Referenced by: '<S661>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bln4djb4;       /* Expression: 0
                                        * Referenced by: '<S661>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_d;              /* Expression: 0
                                        * Referenced by: '<S619>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_d;              /* Expression: 0
                                        * Referenced by: '<S619>/Unit Delay2'
                                        */
  real_T FCn2_Gain;                    /* Expression: 3.5
                                        * Referenced by: '<S495>/F//Cn2'
                                        */
  real_T Constant_Value_h2;            /* Expression: const
                                        * Referenced by: '<S591>/Constant'
                                        */
  real_T Gain_Gain_adhzk5;             /* Expression: 1/Tps
                                        * Referenced by: '<S586>/Gain'
                                        */
  real_T Constant_Value_ec;            /* Expression: 0
                                        * Referenced by: '<S596>/Constant'
                                        */
  real_T UnitDelay4_X0_d1;             /* Expression: 0
                                        * Referenced by: '<S620>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_d1;             /* Expression: 0
                                        * Referenced by: '<S620>/Unit Delay2'
                                        */
  real_T Gain1_Gain_adhz;              /* Expression: 2
                                        * Referenced by: '<S586>/Gain1'
                                        */
  real_T Gain_Gain_adhzk50;            /* Expression: Tps/2
                                        * Referenced by: '<S551>/Gain'
                                        */
  real_T Bias_Bias_bc;                 /* Expression: 0.0
                                        * Referenced by: '<S500>/Bias'
                                        */
  real_T UnitDelay_X0_h;               /* Expression: InitialState
                                        * Referenced by: '<S692>/Unit Delay'
                                        */
  real_T Constant_Value_i;             /* Expression: const
                                        * Referenced by: '<S602>/Constant'
                                        */
  real_T SF_FixedDiscreteDelaySfunctio_i;/* Expression: double(x0(1))
                                          * Referenced by: '<S928>/SF_FixedDiscreteDelay S-function'
                                          */
  real_T Constant_Value_fc;            /* Expression: const
                                        * Referenced by: '<S927>/Constant'
                                        */
  real_T UnitDelay1_X0_b;              /* Expression: x0
                                        * Referenced by: '<S633>/Unit Delay1'
                                        */
  real_T Gain_Gain_bl;                 /* Expression: 1/Tps
                                        * Referenced by: '<S633>/Gain'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: 1/Fnom
                                        * Referenced by: '<S623>/Gain2'
                                        */
  real_T Constant_Value_bln4d;         /* Expression: 0
                                        * Referenced by: '<S653>/Constant'
                                        */
  real_T Constant_Value_bln4dj;        /* Expression: const
                                        * Referenced by: '<S637>/Constant'
                                        */
  real_T UnitDelay1_X0_ez;             /* Expression: x0
                                        * Referenced by: '<S734>/Unit Delay1'
                                        */
  real_T Gain_Gain_ez;                 /* Expression: 1/Tps
                                        * Referenced by: '<S734>/Gain'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 1/Fnom
                                        * Referenced by: '<S724>/Gain2'
                                        */
  real_T Constant_Value_ezncl;         /* Expression: 0
                                        * Referenced by: '<S754>/Constant'
                                        */
  real_T Constant_Value_eznclc;        /* Expression: const
                                        * Referenced by: '<S738>/Constant'
                                        */
  real_T UnitDelay1_X0_e0;             /* Expression: x0
                                        * Referenced by: '<S835>/Unit Delay1'
                                        */
  real_T Gain_Gain_e0;                 /* Expression: 1/Tps
                                        * Referenced by: '<S835>/Gain'
                                        */
  real_T Gain2_Gain_e0;                /* Expression: 1/Fnom
                                        * Referenced by: '<S825>/Gain2'
                                        */
  real_T Constant_Value_e0r1h;         /* Expression: 0
                                        * Referenced by: '<S855>/Constant'
                                        */
  real_T Constant_Value_e0r1hm;        /* Expression: const
                                        * Referenced by: '<S839>/Constant'
                                        */
  real_T UnitDelay_X0_g;               /* Expression: InitialState
                                        * Referenced by: '<S793>/Unit Delay'
                                        */
  real_T Constant_Value_g1;            /* Expression: const
                                        * Referenced by: '<S703>/Constant'
                                        */
  real_T UnitDelay_X0_m;               /* Expression: InitialState
                                        * Referenced by: '<S894>/Unit Delay'
                                        */
  real_T Constant_Value_eza;           /* Expression: const
                                        * Referenced by: '<S804>/Constant'
                                        */
  real_T UnitDelay3_X0_c;              /* Expression: 0
                                        * Referenced by: '<S701>/Unit Delay3'
                                        */
  real_T UnitDelay4_X0_eznclc;         /* Expression: 0
                                        * Referenced by: '<S767>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_eznclc;         /* Expression: 0
                                        * Referenced by: '<S767>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_eznclc5;        /* Expression: 0
                                        * Referenced by: '<S768>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_eznclc5;        /* Expression: 0
                                        * Referenced by: '<S768>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_eznclc5x;       /* Expression: 0
                                        * Referenced by: '<S761>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_eznclc5x;       /* Expression: 0
                                        * Referenced by: '<S761>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_eznclc5xg;      /* Expression: 0
                                        * Referenced by: '<S762>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_eznclc5xg;      /* Expression: 0
                                        * Referenced by: '<S762>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_f;              /* Expression: 0
                                        * Referenced by: '<S720>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_f;              /* Expression: 0
                                        * Referenced by: '<S720>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_fj;             /* Expression: 0
                                        * Referenced by: '<S721>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_fj;             /* Expression: 0
                                        * Referenced by: '<S721>/Unit Delay2'
                                        */
  real_T Bias1_Bias_dv;                /* Expression: 0.0
                                        * Referenced by: '<S500>/Bias1'
                                        */
  real_T UnitDelay3_X0_f;              /* Expression: 0
                                        * Referenced by: '<S802>/Unit Delay3'
                                        */
  real_T UnitDelay4_X0_e0r1hm;         /* Expression: 0
                                        * Referenced by: '<S868>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0r1hm;         /* Expression: 0
                                        * Referenced by: '<S868>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_e0r1hmw;        /* Expression: 0
                                        * Referenced by: '<S869>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0r1hmw;        /* Expression: 0
                                        * Referenced by: '<S869>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_e0r1hmwt;       /* Expression: 0
                                        * Referenced by: '<S862>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0r1hmwt;       /* Expression: 0
                                        * Referenced by: '<S862>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_e0r1hmwtw;      /* Expression: 0
                                        * Referenced by: '<S863>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0r1hmwtw;      /* Expression: 0
                                        * Referenced by: '<S863>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_g;              /* Expression: 0
                                        * Referenced by: '<S821>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_g0;             /* Expression: 0
                                        * Referenced by: '<S821>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_g0;             /* Expression: 0
                                        * Referenced by: '<S822>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_g0w;            /* Expression: 0
                                        * Referenced by: '<S822>/Unit Delay2'
                                        */
  real_T Bias2_Bias;                   /* Expression: 0.0
                                        * Referenced by: '<S500>/Bias2'
                                        */
  real_T Constant_Value_dz;            /* Expression: const
                                        * Referenced by: '<S512>/Constant'
                                        */
  real_T Constant_Value_oj;            /* Expression: const
                                        * Referenced by: '<S513>/Constant'
                                        */
  real_T PulseGenerator1_Amp_d;        /* Expression: 1
                                        * Referenced by: '<S987>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period_d;     /* Expression: (ceil((dtMax*2)/Tps)+20)
                                        * Referenced by: '<S987>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty_d;       /* Expression: ceil((ceil((dtMax*2)/Tps)+20)/2)
                                        * Referenced by: '<S987>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay_d; /* Expression: 0
                                        * Referenced by: '<S987>/Pulse Generator1'
                                        */
  real_T Constant_Value_da;            /* Expression: const
                                        * Referenced by: '<S993>/Constant'
                                        */
  real_T UnitDelay4_X0_i;              /* Expression: 0
                                        * Referenced by: '<S962>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_i;              /* Expression: 0
                                        * Referenced by: '<S962>/Unit Delay2'
                                        */
  real_T UnitDelay2_X0_gy;             /* Expression: 0
                                        * Referenced by: '<S503>/Unit Delay2'
                                        */
  real_T Constant_Value_cjwa;          /* Expression: const
                                        * Referenced by: '<S994>/Constant'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 1/Tps
                                        * Referenced by: '<S989>/Gain'
                                        */
  real_T Constant_Value_pf;            /* Expression: 0
                                        * Referenced by: '<S999>/Constant'
                                        */
  real_T UnitDelay4_X0_ii;             /* Expression: 0
                                        * Referenced by: '<S963>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ii;             /* Expression: 0
                                        * Referenced by: '<S963>/Unit Delay2'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S989>/Gain1'
                                        */
  real_T Gain_Gain_am;                 /* Expression: Tps/2
                                        * Referenced by: '<S955>/Gain'
                                        */
  real_T Constant_Value_kz;            /* Expression: 0
                                        * Referenced by: '<S1024>/Constant'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 4/2/Fnom
                                        * Referenced by: '<S310>/Gain'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant_Value_i5;            /* Expression: const
                                        * Referenced by: '<S493>/Constant'
                                        */
  real_T Constant1_Value_m2;           /* Expression: 1.0*sqrt(3)/sqrt(2)
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1/3
                                        * Referenced by: '<S33>/Gain6'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/3
                                        * Referenced by: '<S33>/Gain4'
                                        */
  real_T Constant_Value_jw;            /* Expression: const
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: 100
                                        * Referenced by: '<S33>/Gain3'
                                        */
  real_T ScaleRMSoutputsto1pu_Gain;    /* Expression: sqrt(2)
                                        * Referenced by: '<S626>/Scale RMS outputs to 1pu'
                                        */
  real_T UnitDelay4_X0_bln4djb4g;      /* Expression: 0
                                        * Referenced by: '<S682>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bln4djb4g;      /* Expression: 0
                                        * Referenced by: '<S682>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_bln4djb4gs;     /* Expression: 0
                                        * Referenced by: '<S683>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bln4djb4gs;     /* Expression: 0
                                        * Referenced by: '<S683>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_bln4djb4gs5;    /* Expression: 0
                                        * Referenced by: '<S630>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bln4djb4gs5;    /* Expression: 0
                                        * Referenced by: '<S630>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_bln4djb4gs54;   /* Expression: 0
                                        * Referenced by: '<S631>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bln4djb4gs54;   /* Expression: 0
                                        * Referenced by: '<S631>/Unit Delay2'
                                        */
  real_T Constant_Value_bln4djb;       /* Expression: const
                                        * Referenced by: '<S674>/Constant'
                                        */
  real_T Constant_Value_bln4djb4;      /* Expression: const
                                        * Referenced by: '<S675>/Constant'
                                        */
  real_T Gain_Gain_bln;                /* Expression: 100
                                        * Referenced by: '<S625>/Gain'
                                        */
  real_T Constant_Value_bln4djb4g;     /* Expression: const
                                        * Referenced by: '<S676>/Constant'
                                        */
  real_T ScaleRMSoutputsto1pu_Gain_e;  /* Expression: sqrt(2)
                                        * Referenced by: '<S727>/Scale RMS outputs to 1pu'
                                        */
  real_T UnitDelay4_X0_eznclc5xg5;     /* Expression: 0
                                        * Referenced by: '<S783>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_eznclc5xg5;     /* Expression: 0
                                        * Referenced by: '<S783>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_eznclc5xg5q;    /* Expression: 0
                                        * Referenced by: '<S784>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_eznclc5xg5q;    /* Expression: 0
                                        * Referenced by: '<S784>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_eznclc5xg5q1;   /* Expression: 0
                                        * Referenced by: '<S731>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_eznclc5xg5q1;   /* Expression: 0
                                        * Referenced by: '<S731>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_eznclc5xg5q1u;  /* Expression: 0
                                        * Referenced by: '<S732>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_eznclc5xg5q1u;  /* Expression: 0
                                        * Referenced by: '<S732>/Unit Delay2'
                                        */
  real_T Constant_Value_eznclc5;       /* Expression: const
                                        * Referenced by: '<S775>/Constant'
                                        */
  real_T Constant_Value_eznclc5x;      /* Expression: const
                                        * Referenced by: '<S776>/Constant'
                                        */
  real_T Gain_Gain_ezn;                /* Expression: 100
                                        * Referenced by: '<S726>/Gain'
                                        */
  real_T Constant_Value_eznclc5xg;     /* Expression: const
                                        * Referenced by: '<S777>/Constant'
                                        */
  real_T ScaleRMSoutputsto1pu_Gain_e0; /* Expression: sqrt(2)
                                        * Referenced by: '<S828>/Scale RMS outputs to 1pu'
                                        */
  real_T UnitDelay4_X0_e0r1hmwtwq;     /* Expression: 0
                                        * Referenced by: '<S884>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0r1hmwtwq;     /* Expression: 0
                                        * Referenced by: '<S884>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_e0r1hmwtwqc;    /* Expression: 0
                                        * Referenced by: '<S885>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0r1hmwtwqc;    /* Expression: 0
                                        * Referenced by: '<S885>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_e0r1hmwtwqc2;   /* Expression: 0
                                        * Referenced by: '<S832>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0r1hmwtwqc2;   /* Expression: 0
                                        * Referenced by: '<S832>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_e0r1hmwtwqc2e;  /* Expression: 0
                                        * Referenced by: '<S833>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_e0r1hmwtwqc2e;  /* Expression: 0
                                        * Referenced by: '<S833>/Unit Delay2'
                                        */
  real_T Constant_Value_e0r1hmw;       /* Expression: const
                                        * Referenced by: '<S876>/Constant'
                                        */
  real_T Constant_Value_e0r1hmwt;      /* Expression: const
                                        * Referenced by: '<S877>/Constant'
                                        */
  real_T Gain_Gain_e0r;                /* Expression: 100
                                        * Referenced by: '<S827>/Gain'
                                        */
  real_T Constant_Value_e0r1hmwtw;     /* Expression: const
                                        * Referenced by: '<S878>/Constant'
                                        */
  real_T UnitDelay1_X0_h;              /* Expression: 0
                                        * Referenced by: '<S87>/Unit Delay1'
                                        */
  real_T UnitDelay2_X0_c;              /* Expression: 0
                                        * Referenced by: '<S87>/Unit Delay2'
                                        */
  real_T Gain_Gain_d2;                 /* Expression: 1/2
                                        * Referenced by: '<S97>/Gain'
                                        */
  real_T Gain_Gain_cep;                /* Expression: -1/Tps
                                        * Referenced by: '<S87>/Gain'
                                        */
  real_T Bias_Bias_o;                  /* Expression: 1
                                        * Referenced by: '<S87>/Bias'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 1/2
                                        * Referenced by: '<S97>/Gain1'
                                        */
  real_T UnitDelay4_X0_o;              /* Expression: 0
                                        * Referenced by: '<S128>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_o;              /* Expression: 0
                                        * Referenced by: '<S128>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_of;             /* Expression: 0
                                        * Referenced by: '<S129>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_of;             /* Expression: 0
                                        * Referenced by: '<S129>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofa;            /* Expression: 0
                                        * Referenced by: '<S146>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofa;            /* Expression: 0
                                        * Referenced by: '<S146>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofaw;           /* Expression: 0
                                        * Referenced by: '<S147>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofaw;           /* Expression: 0
                                        * Referenced by: '<S147>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofawr;          /* Expression: 0
                                        * Referenced by: '<S134>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofawr;          /* Expression: 0
                                        * Referenced by: '<S134>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofawrz;         /* Expression: 0
                                        * Referenced by: '<S135>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofawrz;         /* Expression: 0
                                        * Referenced by: '<S135>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofawrzy;        /* Expression: 0
                                        * Referenced by: '<S152>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofawrzy;        /* Expression: 0
                                        * Referenced by: '<S152>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofawrzyw;       /* Expression: 0
                                        * Referenced by: '<S153>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofawrzyw;       /* Expression: 0
                                        * Referenced by: '<S153>/Unit Delay2'
                                        */
  real_T IpktoIrms_Gain;               /* Expression: 1/sqrt(2)
                                        * Referenced by: '<S12>/Ipk to Irms'
                                        */
  real_T UnitDelay1_X0_l;              /* Expression: 0
                                        * Referenced by: '<S88>/Unit Delay1'
                                        */
  real_T UnitDelay2_X0_i3;             /* Expression: 0
                                        * Referenced by: '<S88>/Unit Delay2'
                                        */
  real_T Gain_Gain_jf;                 /* Expression: 1/2
                                        * Referenced by: '<S99>/Gain'
                                        */
  real_T Gain_Gain_b4;                 /* Expression: -1/Tps
                                        * Referenced by: '<S88>/Gain'
                                        */
  real_T Bias_Bias_m1;                 /* Expression: 1
                                        * Referenced by: '<S88>/Bias'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 1/2
                                        * Referenced by: '<S99>/Gain1'
                                        */
  real_T UnitDelay4_X0_ofawrzywp;      /* Expression: 0
                                        * Referenced by: '<S191>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofawrzywp;      /* Expression: 0
                                        * Referenced by: '<S191>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofawrzywpv;     /* Expression: 0
                                        * Referenced by: '<S192>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofawrzywpv;     /* Expression: 0
                                        * Referenced by: '<S192>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofawrzywpvf;    /* Expression: 0
                                        * Referenced by: '<S209>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofawrzywpvf;    /* Expression: 0
                                        * Referenced by: '<S209>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofawrzywpvfx;   /* Expression: 0
                                        * Referenced by: '<S210>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofawrzywpvfx;   /* Expression: 0
                                        * Referenced by: '<S210>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofawrzywpvfxm;  /* Expression: 0
                                        * Referenced by: '<S197>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofawrzywpvfxm;  /* Expression: 0
                                        * Referenced by: '<S197>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofawrzywpvfxm1; /* Expression: 0
                                        * Referenced by: '<S198>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofawrzywpvfxm1; /* Expression: 0
                                        * Referenced by: '<S198>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ofawrzywpvfxm1r;/* Expression: 0
                                        * Referenced by: '<S215>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ofawrzywpvfxm1r;/* Expression: 0
                                        * Referenced by: '<S215>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_l;              /* Expression: 0
                                        * Referenced by: '<S216>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_lt;             /* Expression: 0
                                        * Referenced by: '<S216>/Unit Delay2'
                                        */
  real_T IpktoIrms_Gain_h;             /* Expression: 1/sqrt(2)
                                        * Referenced by: '<S13>/Ipk to Irms'
                                        */
  real_T UnitDelay1_X0_d;              /* Expression: 0
                                        * Referenced by: '<S89>/Unit Delay1'
                                        */
  real_T UnitDelay2_X0_na;             /* Expression: 0
                                        * Referenced by: '<S89>/Unit Delay2'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1/2
                                        * Referenced by: '<S101>/Gain'
                                        */
  real_T Gain_Gain_jx;                 /* Expression: -1/Tps
                                        * Referenced by: '<S89>/Gain'
                                        */
  real_T Bias_Bias_oi;                 /* Expression: 1
                                        * Referenced by: '<S89>/Bias'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 1/2
                                        * Referenced by: '<S101>/Gain1'
                                        */
  real_T UnitDelay4_X0_ng;             /* Expression: 0
                                        * Referenced by: '<S254>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ng;             /* Expression: 0
                                        * Referenced by: '<S254>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_h;              /* Expression: 0
                                        * Referenced by: '<S255>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_h;              /* Expression: 0
                                        * Referenced by: '<S255>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_iy;             /* Expression: 0
                                        * Referenced by: '<S272>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_iy;             /* Expression: 0
                                        * Referenced by: '<S272>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_k;              /* Expression: 0
                                        * Referenced by: '<S273>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_k;              /* Expression: 0
                                        * Referenced by: '<S273>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_a;              /* Expression: 0
                                        * Referenced by: '<S260>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_a;              /* Expression: 0
                                        * Referenced by: '<S260>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_k3;             /* Expression: 0
                                        * Referenced by: '<S261>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_k3;             /* Expression: 0
                                        * Referenced by: '<S261>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ow;             /* Expression: 0
                                        * Referenced by: '<S278>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ow;             /* Expression: 0
                                        * Referenced by: '<S278>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_db;             /* Expression: 0
                                        * Referenced by: '<S279>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_db;             /* Expression: 0
                                        * Referenced by: '<S279>/Unit Delay2'
                                        */
  real_T IpktoIrms_Gain_j;             /* Expression: 1/sqrt(2)
                                        * Referenced by: '<S14>/Ipk to Irms'
                                        */
  real_T Gain6_Gain_h;                 /* Expression: 1/3
                                        * Referenced by: '<S34>/Gain6'
                                        */
  real_T Gain4_Gain_o;                 /* Expression: 1/3
                                        * Referenced by: '<S34>/Gain4'
                                        */
  real_T Constant_Value_or;            /* Expression: const
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T Gain3_Gain_l;                 /* Expression: 100
                                        * Referenced by: '<S34>/Gain3'
                                        */
  real_T ScaleRMSoutputsto1pu_Gain_o;  /* Expression: sqrt(2)
                                        * Referenced by: '<S112>/Scale RMS outputs to 1pu'
                                        */
  real_T UnitDelay4_X0_ff;             /* Expression: 0
                                        * Referenced by: '<S168>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ff;             /* Expression: 0
                                        * Referenced by: '<S168>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ga;             /* Expression: 0
                                        * Referenced by: '<S169>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ga;             /* Expression: 0
                                        * Referenced by: '<S169>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_fo;             /* Expression: 0
                                        * Referenced by: '<S116>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_fo;             /* Expression: 0
                                        * Referenced by: '<S116>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_hi;             /* Expression: 0
                                        * Referenced by: '<S117>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_hi;             /* Expression: 0
                                        * Referenced by: '<S117>/Unit Delay2'
                                        */
  real_T Constant_Value_ofawrzywpv;    /* Expression: const
                                        * Referenced by: '<S160>/Constant'
                                        */
  real_T Constant_Value_ofawrzywpvf;   /* Expression: const
                                        * Referenced by: '<S161>/Constant'
                                        */
  real_T Gain_Gain_of;                 /* Expression: 100
                                        * Referenced by: '<S111>/Gain'
                                        */
  real_T Constant_Value_ofawrzywpvfx;  /* Expression: const
                                        * Referenced by: '<S162>/Constant'
                                        */
  real_T ScaleRMSoutputsto1pu_Gain_of; /* Expression: sqrt(2)
                                        * Referenced by: '<S175>/Scale RMS outputs to 1pu'
                                        */
  real_T UnitDelay4_X0_iw;             /* Expression: 0
                                        * Referenced by: '<S231>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_iw;             /* Expression: 0
                                        * Referenced by: '<S231>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_by;             /* Expression: 0
                                        * Referenced by: '<S232>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_by;             /* Expression: 0
                                        * Referenced by: '<S232>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_or;             /* Expression: 0
                                        * Referenced by: '<S179>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_or;             /* Expression: 0
                                        * Referenced by: '<S179>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_bv;             /* Expression: 0
                                        * Referenced by: '<S180>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_bv;             /* Expression: 0
                                        * Referenced by: '<S180>/Unit Delay2'
                                        */
  real_T Constant_Value_ofawrzywpvfxm; /* Expression: const
                                        * Referenced by: '<S223>/Constant'
                                        */
  real_T Constant_Value_ofawrzywpvfxm1;/* Expression: const
                                        * Referenced by: '<S224>/Constant'
                                        */
  real_T Gain_Gain_ofa;                /* Expression: 100
                                        * Referenced by: '<S174>/Gain'
                                        */
  real_T Constant_Value_ofawrzywpvfxm1r;/* Expression: const
                                         * Referenced by: '<S225>/Constant'
                                         */
  real_T ScaleRMSoutputsto1pu_Gain_ofa;/* Expression: sqrt(2)
                                        * Referenced by: '<S238>/Scale RMS outputs to 1pu'
                                        */
  real_T UnitDelay4_X0_j;              /* Expression: 0
                                        * Referenced by: '<S294>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_j;              /* Expression: 0
                                        * Referenced by: '<S294>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_c;              /* Expression: 0
                                        * Referenced by: '<S295>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_c5;             /* Expression: 0
                                        * Referenced by: '<S295>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_p;              /* Expression: 0
                                        * Referenced by: '<S242>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_p;              /* Expression: 0
                                        * Referenced by: '<S242>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_cu;             /* Expression: 0
                                        * Referenced by: '<S243>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_cu;             /* Expression: 0
                                        * Referenced by: '<S243>/Unit Delay2'
                                        */
  real_T Constant_Value_jo;            /* Expression: const
                                        * Referenced by: '<S286>/Constant'
                                        */
  real_T Constant_Value_c5;            /* Expression: const
                                        * Referenced by: '<S287>/Constant'
                                        */
  real_T Gain_Gain_ofaw;               /* Expression: 100
                                        * Referenced by: '<S237>/Gain'
                                        */
  real_T Constant_Value_ps;            /* Expression: const
                                        * Referenced by: '<S288>/Constant'
                                        */
  real_T IpktoIrmsconversion_Gain;     /* Expression: 1/sqrt(2)
                                        * Referenced by: '<S12>/Ipk to Irms conversion'
                                        */
  real_T IpktoIrmsconversion_Gain_m;   /* Expression: 1/sqrt(2)
                                        * Referenced by: '<S13>/Ipk to Irms conversion'
                                        */
  real_T IpktoIrmsconversion_Gain_f;   /* Expression: 1/sqrt(2)
                                        * Referenced by: '<S14>/Ipk to Irms conversion'
                                        */
  real_T Constant_Value_e4;            /* Expression: const
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant_Value_ck;            /* Expression: const
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: (5+2)/50
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value_g;            /* Expression: 10/50
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Gain_Gain_ci;                 /* Expression: 1/Tps
                                        * Referenced by: '<S332>/Gain'
                                        */
  real_T Gain_Gain_civ;                /* Expression: 1/Tps
                                        * Referenced by: '<S335>/Gain'
                                        */
  real_T UnitDelay4_X0_epw;            /* Expression: 0
                                        * Referenced by: '<S400>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_epwu;           /* Expression: 0
                                        * Referenced by: '<S400>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_epwu;           /* Expression: 0
                                        * Referenced by: '<S401>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_epwu2;          /* Expression: 0
                                        * Referenced by: '<S401>/Unit Delay2'
                                        */
  real_T UnitDelay1_X0_ep;             /* Expression: 0
                                        * Referenced by: '<S315>/Unit Delay1'
                                        */
  real_T UnitDelay_X0_e;               /* Expression: InitialState
                                        * Referenced by: '<S418>/Unit Delay'
                                        */
  real_T Constant_Value_b5;            /* Expression: 0
                                        * Referenced by: '<S437>/Constant'
                                        */
  real_T Gain_Gain_epwu;               /* Expression: Tps
                                        * Referenced by: '<S443>/Gain'
                                        */
  real_T UnitDelay1_X0_epw;            /* Expression: 0
                                        * Referenced by: '<S388>/Unit Delay1'
                                        */
  real_T Constant_Value_mk;            /* Expression: 0
                                        * Referenced by: '<S455>/Constant'
                                        */
  real_T UnitDelay1_X0_epwu;           /* Expression: x0
                                        * Referenced by: '<S441>/Unit Delay1'
                                        */
  real_T UnitDelay4_X0_epwu2;          /* Expression: 0
                                        * Referenced by: '<S388>/Unit Delay4'
                                        */
  real_T UnitDelay1_X0_epwu2;          /* Expression: x0
                                        * Referenced by: '<S442>/Unit Delay1'
                                        */
  real_T Constant_Value_o5;            /* Expression: const
                                        * Referenced by: '<S454>/Constant'
                                        */
  real_T Gain_Gain_epwu2;              /* Expression: 1/(2-FullCycles)
                                        * Referenced by: '<S388>/Gain'
                                        */
  real_T UnitDelay1_X0_epwu2g;         /* Expression: Vinit
                                        * Referenced by: '<S382>/Unit Delay1'
                                        */
  real_T Gain2_Gain_ep;                /* Expression: 1/RippleFreqMin
                                        * Referenced by: '<S315>/Gain2'
                                        */
  real_T Constant_Value_dh;            /* Expression: 0
                                        * Referenced by: '<S412>/Constant'
                                        */
  real_T Constant_Value_ef;            /* Expression: const
                                        * Referenced by: '<S416>/Constant'
                                        */
  real_T UnitDelay1_X0_epwu2gd;        /* Expression: Vinit
                                        * Referenced by: '<S381>/Unit Delay1'
                                        */
  real_T Constant_Value_hn;            /* Expression: const
                                        * Referenced by: '<S404>/Constant'
                                        */
  real_T Gain1_Gain_ep;                /* Expression: 1/2
                                        * Referenced by: '<S315>/Gain1'
                                        */
  real_T Gain2_Gain_epw;               /* Expression: -2*pi*Tps
                                        * Referenced by: '<S417>/Gain2'
                                        */
  real_T double1_Value;                /* Expression: 1
                                        * Referenced by: '<S417>/double1'
                                        */
  real_T Gain1_Gain_epw;               /* Expression: 0.4
                                        * Referenced by: '<S388>/Gain1'
                                        */
  real_T Bias_Bias_epwu;               /* Expression: -2*Tps
                                        * Referenced by: '<S388>/Bias'
                                        */
  real_T Constant_Value_oi;            /* Expression: const
                                        * Referenced by: '<S453>/Constant'
                                        */
  real_T Gain_Gain_epwu2g;             /* Expression: 1/Tps
                                        * Referenced by: '<S438>/Gain'
                                        */
  real_T Bias_Bias_epwu2;              /* Expression: 1
                                        * Referenced by: '<S438>/Bias'
                                        */
  real_T Constant_Value_pc;            /* Expression: const
                                        * Referenced by: '<S449>/Constant'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 1/Tps
                                        * Referenced by: '<S531>/Gain'
                                        */
  real_T Gain_Gain_ds;                 /* Expression: 1/Tps
                                        * Referenced by: '<S534>/Gain'
                                        */
  real_T UnitDelay3_X0_ka;             /* Expression: 0
                                        * Referenced by: '<S599>/Unit Delay3'
                                        */
  real_T Constant_Value_e52;           /* Expression: const
                                        * Referenced by: '<S612>/Constant'
                                        */
  real_T Gain_Gain_ju;                 /* Expression: 1/Tps
                                        * Referenced by: '<S599>/Gain'
                                        */
  real_T Constant_Value_as;            /* Expression: 0
                                        * Referenced by: '<S699>/Constant'
                                        */
  real_T Gain_Gain_h1;                 /* Expression: A
                                        * Referenced by: '<S692>/Gain'
                                        */
  real_T Gain1_Gain_h1;                /* Expression: B
                                        * Referenced by: '<S692>/Gain1'
                                        */
  real_T UnitDelay3_X0_p;              /* Expression: 0
                                        * Referenced by: '<S700>/Unit Delay3'
                                        */
  real_T Constant_Value_m0j;           /* Expression: const
                                        * Referenced by: '<S713>/Constant'
                                        */
  real_T Gain_Gain_fx;                 /* Expression: 1/Tps
                                        * Referenced by: '<S700>/Gain'
                                        */
  real_T Constant_Value_nb;            /* Expression: 0
                                        * Referenced by: '<S800>/Constant'
                                        */
  real_T Gain_Gain_g3;                 /* Expression: A
                                        * Referenced by: '<S793>/Gain'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: B
                                        * Referenced by: '<S793>/Gain1'
                                        */
  real_T UnitDelay3_X0_fw;             /* Expression: 0
                                        * Referenced by: '<S801>/Unit Delay3'
                                        */
  real_T Constant_Value_ki2;           /* Expression: const
                                        * Referenced by: '<S814>/Constant'
                                        */
  real_T Gain_Gain_kv;                 /* Expression: 1/Tps
                                        * Referenced by: '<S801>/Gain'
                                        */
  real_T Constant_Value_lz;            /* Expression: 0
                                        * Referenced by: '<S901>/Constant'
                                        */
  real_T Gain_Gain_mh;                 /* Expression: A
                                        * Referenced by: '<S894>/Gain'
                                        */
  real_T Gain1_Gain_mh;                /* Expression: B
                                        * Referenced by: '<S894>/Gain1'
                                        */
  real_T Constant_Value_bx;            /* Expression: const
                                        * Referenced by: '<S914>/Constant'
                                        */
  real_T Constant_Value_gby;           /* Expression: const
                                        * Referenced by: '<S915>/Constant'
                                        */
  real_T Constant_Value_p0;            /* Expression: const
                                        * Referenced by: '<S916>/Constant'
                                        */
  real_T Constant_Value_d4;            /* Expression: const
                                        * Referenced by: '<S917>/Constant'
                                        */
  real_T Constant_Value_oy;            /* Expression: const
                                        * Referenced by: '<S918>/Constant'
                                        */
  real_T Constant_Value_fv;            /* Expression: const
                                        * Referenced by: '<S919>/Constant'
                                        */
  real_T Constant_Value_h3;            /* Expression: const
                                        * Referenced by: '<S920>/Constant'
                                        */
  real_T Constant_Value_no;            /* Expression: const
                                        * Referenced by: '<S921>/Constant'
                                        */
  real_T UnitDelay4_X0_ii1;            /* Expression: 0
                                        * Referenced by: '<S968>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ii1;            /* Expression: 0
                                        * Referenced by: '<S968>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0_ii12;           /* Expression: 0
                                        * Referenced by: '<S969>/Unit Delay4'
                                        */
  real_T UnitDelay2_X0_ii12;           /* Expression: 0
                                        * Referenced by: '<S969>/Unit Delay2'
                                        */
  real_T UnitDelay1_X0_hr;             /* Expression: 0
                                        * Referenced by: '<S503>/Unit Delay1'
                                        */
  real_T UnitDelay_X0_en;              /* Expression: InitialState
                                        * Referenced by: '<S986>/Unit Delay'
                                        */
  real_T Constant_Value_gbvuwp;        /* Expression: 0
                                        * Referenced by: '<S1005>/Constant'
                                        */
  real_T Gain_Gain_gb;                 /* Expression: Tps
                                        * Referenced by: '<S1011>/Gain'
                                        */
  real_T UnitDelay1_X0_g;              /* Expression: 0
                                        * Referenced by: '<S956>/Unit Delay1'
                                        */
  real_T Constant_Value_gbvuwpg;       /* Expression: 0
                                        * Referenced by: '<S1023>/Constant'
                                        */
  real_T UnitDelay1_X0_gb;             /* Expression: x0
                                        * Referenced by: '<S1009>/Unit Delay1'
                                        */
  real_T UnitDelay4_X0_gb;             /* Expression: 0
                                        * Referenced by: '<S956>/Unit Delay4'
                                        */
  real_T UnitDelay1_X0_gbv;            /* Expression: x0
                                        * Referenced by: '<S1010>/Unit Delay1'
                                        */
  real_T Constant_Value_gbvuwpgu;      /* Expression: const
                                        * Referenced by: '<S1022>/Constant'
                                        */
  real_T Gain_Gain_gbv;                /* Expression: 1/(2-FullCycles)
                                        * Referenced by: '<S956>/Gain'
                                        */
  real_T UnitDelay1_X0_hp;             /* Expression: Vinit
                                        * Referenced by: '<S950>/Unit Delay1'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 1/RippleFreqMin
                                        * Referenced by: '<S503>/Gain2'
                                        */
  real_T Constant_Value_ii;            /* Expression: 0
                                        * Referenced by: '<S980>/Constant'
                                        */
  real_T Constant_Value_gs;            /* Expression: const
                                        * Referenced by: '<S984>/Constant'
                                        */
  real_T UnitDelay1_X0_ea;             /* Expression: Vinit
                                        * Referenced by: '<S949>/Unit Delay1'
                                        */
  real_T Constant_Value_fg15t;         /* Expression: const
                                        * Referenced by: '<S972>/Constant'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 1/2
                                        * Referenced by: '<S503>/Gain1'
                                        */
  real_T Gain2_Gain_en;                /* Expression: -2*pi*Tps
                                        * Referenced by: '<S985>/Gain2'
                                        */
  real_T double1_Value_e;              /* Expression: 1
                                        * Referenced by: '<S985>/double1'
                                        */
  real_T Gain1_Gain_gb;                /* Expression: 0.4
                                        * Referenced by: '<S956>/Gain1'
                                        */
  real_T Bias_Bias_gb;                 /* Expression: -2*Tps
                                        * Referenced by: '<S956>/Bias'
                                        */
  real_T Constant_Value_gbvuwpgu2;     /* Expression: const
                                        * Referenced by: '<S1021>/Constant'
                                        */
  real_T Gain_Gain_gbvu;               /* Expression: 1/Tps
                                        * Referenced by: '<S1006>/Gain'
                                        */
  real_T Bias_Bias_gbv;                /* Expression: 1
                                        * Referenced by: '<S1006>/Bias'
                                        */
  real_T Constant_Value_gbvuwpgu2k;    /* Expression: const
                                        * Referenced by: '<S1017>/Constant'
                                        */
  creal_T Gain5_Gain[3];               /* Expression: [1  exp(-j*2*pi/3)  exp(j*2*pi/3)]
                                        * Referenced by: '<S33>/Gain5'
                                        */
  creal_T Gain2_Gain_o[3];             /* Expression: [1  exp(j*2*pi/3)  exp(-j*2*pi/3)]
                                        * Referenced by: '<S33>/Gain2'
                                        */
  creal_T Gain5_Gain_d[3];             /* Expression: [1  exp(-j*2*pi/3)  exp(j*2*pi/3)]
                                        * Referenced by: '<S34>/Gain5'
                                        */
  creal_T Gain2_Gain_bc[3];            /* Expression: [1  exp(j*2*pi/3)  exp(-j*2*pi/3)]
                                        * Referenced by: '<S34>/Gain2'
                                        */
  int32_T Constant3_Value_e;           /* Computed Parameter: Constant3_Value_e
                                        * Referenced by: '<S429>/Constant3'
                                        */
  int32_T Constant_Value_ng;           /* Computed Parameter: Constant_Value_ng
                                        * Referenced by: '<S433>/Constant'
                                        */
  int32_T Constant_Value_h1;           /* Computed Parameter: Constant_Value_h1
                                        * Referenced by: '<S429>/Constant'
                                        */
  int32_T Constant3_Value_h;           /* Computed Parameter: Constant3_Value_h
                                        * Referenced by: '<S470>/Constant3'
                                        */
  int32_T Constant_Value_hpxmkfinoys;  /* Computed Parameter: Constant_Value_hpxmkfinoys
                                        * Referenced by: '<S474>/Constant'
                                        */
  int32_T Constant_Value_hpxmkfinoysh; /* Computed Parameter: Constant_Value_hpxmkfinoysh
                                        * Referenced by: '<S470>/Constant'
                                        */
  int32_T Constant3_Value_hp;          /* Computed Parameter: Constant3_Value_hp
                                        * Referenced by: '<S485>/Constant3'
                                        */
  int32_T Constant_Value_hpxmkfinoyshi;/* Computed Parameter: Constant_Value_hpxmkfinoyshi
                                        * Referenced by: '<S489>/Constant'
                                        */
  int32_T Constant_Value_hpxmkfinoyshik;/* Computed Parameter: Constant_Value_hpxmkfinoyshik
                                         * Referenced by: '<S485>/Constant'
                                         */
  int32_T Constant3_Value_a;           /* Computed Parameter: Constant3_Value_a
                                        * Referenced by: '<S564>/Constant3'
                                        */
  int32_T Constant_Value_jv;           /* Computed Parameter: Constant_Value_jv
                                        * Referenced by: '<S568>/Constant'
                                        */
  int32_T Constant_Value_aj;           /* Computed Parameter: Constant_Value_aj
                                        * Referenced by: '<S564>/Constant'
                                        */
  int32_T Constant3_Value_ad;          /* Computed Parameter: Constant3_Value_ad
                                        * Referenced by: '<S579>/Constant3'
                                        */
  int32_T Constant_Value_cp;           /* Computed Parameter: Constant_Value_cp
                                        * Referenced by: '<S583>/Constant'
                                        */
  int32_T Constant_Value_aa;           /* Computed Parameter: Constant_Value_aa
                                        * Referenced by: '<S579>/Constant'
                                        */
  int32_T Constant3_Value_adh;         /* Computed Parameter: Constant3_Value_adh
                                        * Referenced by: '<S594>/Constant3'
                                        */
  int32_T Constant_Value_kf;           /* Computed Parameter: Constant_Value_kf
                                        * Referenced by: '<S598>/Constant'
                                        */
  int32_T Constant_Value_po;           /* Computed Parameter: Constant_Value_po
                                        * Referenced by: '<S594>/Constant'
                                        */
  int32_T Constant3_Value_p;           /* Computed Parameter: Constant3_Value_p
                                        * Referenced by: '<S997>/Constant3'
                                        */
  int32_T Constant_Value_pfg;          /* Computed Parameter: Constant_Value_pfg
                                        * Referenced by: '<S1001>/Constant'
                                        */
  int32_T Constant_Value_pfgw;         /* Computed Parameter: Constant_Value_pfgw
                                        * Referenced by: '<S997>/Constant'
                                        */
  int32_T SF_FixedDiscreteDelaySfunctio_g;/* Expression: int32(DelaySamples(1))
                                           * Referenced by: '<S1027>/SF_FixedDiscreteDelay S-function'
                                           */
  int32_T SF_FixedDiscreteDelaySfuncti_o0;/* Expression: int32(DelaySamples(1))
                                           * Referenced by: '<S459>/SF_FixedDiscreteDelay S-function'
                                           */
  int32_T Constant_Value_hpxmkfinoyshikv;/* Computed Parameter: Constant_Value_hpxmkfinoyshikv
                                          * Referenced by: '<S473>/Constant'
                                          */
  int32_T VariableDiscreteDelaywithOneTap;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S358>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithOneT_n;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S359>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwoTap;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S363>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T Constant_Value_n5;           /* Computed Parameter: Constant_Value_n5
                                        * Referenced by: '<S488>/Constant'
                                        */
  int32_T VariableDiscreteDelaywithOne_ne;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S364>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithOn_nes;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S365>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwoT_n;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S369>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywithO_nesm;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S370>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywith_nesmw;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S371>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwo_ne;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S375>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T Constant_Value_ds;           /* Computed Parameter: Constant_Value_ds
                                        * Referenced by: '<S432>/Constant'
                                        */
  int32_T VariableDiscreteDelaywithOneT_e;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S391>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithOne_ep;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S392>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwoT_e;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S396>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T Constant_Value_a1;           /* Computed Parameter: Constant_Value_a1
                                        * Referenced by: '<S567>/Constant'
                                        */
  int32_T VariableDiscreteDelaywithOneT_b;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S639>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithOne_bl;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S640>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwoT_b;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S644>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywithOn_bln;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S645>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithO_bln4;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S646>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwo_bl;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S650>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywithOne_ez;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S740>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithOn_ezn;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S741>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwo_ez;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S745>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywithO_eznc;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S746>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywith_ezncl;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S747>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTw_ezn;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S751>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywithOne_e0;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S841>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithOn_e0r;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S842>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwo_e0;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S846>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywithO_e0r1;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S847>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywith_e0r1h;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S848>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTw_e0r;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S852>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T Constant_Value_ny;           /* Computed Parameter: Constant_Value_ny
                                        * Referenced by: '<S582>/Constant'
                                        */
  int32_T VariableDiscreteDelaywith_bln4d;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S663>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywit_bln4dj;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S664>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTw_bln;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S668>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywi_bln4djb;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S657>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelayw_bln4djb4;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S658>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithT_bln4;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S662>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T Constant_Value_bq;           /* Computed Parameter: Constant_Value_bq
                                        * Referenced by: '<S597>/Constant'
                                        */
  int32_T VariableDiscreteDelaywithOneT_h;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S616>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithOne_hk;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S617>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwoT_h;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S621>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T SF_FixedDiscreteDelaySfuncti_ic;/* Expression: int32(DelaySamples(1))
                                           * Referenced by: '<S928>/SF_FixedDiscreteDelay S-function'
                                           */
  int32_T VariableDiscreteDelaywit_eznclc;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S764>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywi_eznclc5;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S765>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithT_eznc;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S769>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelayw_eznclc5x;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S758>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelay_eznclc5xg;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S759>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDela_eznclc5xg5;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S763>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywithOne_h0;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S717>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithOn_h0u;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S718>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwoT_p;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S722>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywit_e0r1hm;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S865>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywi_e0r1hmw;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S866>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithT_e0r1;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S870>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelayw_e0r1hmwt;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S859>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelay_e0r1hmwtw;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S860>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDela_e0r1hmwtwq;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S864>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywithOneT_m;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S818>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithOne_mo;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S819>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwo_en;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S823>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T Constant_Value_pfgws;        /* Computed Parameter: Constant_Value_pfgws
                                        * Referenced by: '<S1000>/Constant'
                                        */
  int32_T VariableDiscreteDelaywithOneT_i;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S959>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithOne_ii;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S960>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwoT_i;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S964>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelay_bln4djb4g;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S679>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDela_bln4djb4gs;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S680>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDel_bln4djb4gs5;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S684>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDe_bln4djb4gs54;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S627>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteD_bln4djb4gs54q;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S628>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscrete_bln4djb4gs54qg;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S632>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDel_eznclc5xg5q;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S780>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDe_eznclc5xg5q1;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S781>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteD_eznclc5xg5q1u;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S785>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscrete_eznclc5xg5q1ug;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S728>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscret_eznclc5xg5q1ugj;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S729>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscret_k;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S733>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscreteDel_e0r1hmwtwqc;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S881>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDe_e0r1hmwtwqc2;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S882>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteD_e0r1hmwtwqc2e;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S886>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscrete_e0r1hmwtwqc2ev;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S829>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscret_e0r1hmwtwqc2evm;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S830>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscret_kl;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S834>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscreteDelaywithOneT_o;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S125>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithOne_of;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S126>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwoT_o;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S130>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywithOn_ofa;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S143>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithO_ofaw;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S144>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwo_of;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S148>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywith_ofawr;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S131>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywit_ofawrz;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S132>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTw_ofa;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S136>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywi_ofawrzy;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S149>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelayw_ofawrzyw;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S150>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithT_ofaw;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S154>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelay_ofawrzywp;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S188>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDela_ofawrzywpv;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S189>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDel_ofawrzywpvf;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S193>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDe_ofawrzywpvfx;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S206>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteD_ofawrzywpvfxm;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S207>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscrete_ofawrzywpvfxm1;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S211>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscret_ofawrzywpvfxm1r;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S194>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscret_l;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S195>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_h;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S199>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscret_n;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S212>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_hy;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S213>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_i;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S217>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscret_iy;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S251>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_ku;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S252>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_kuf;         /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S256>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscret_a;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S269>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_k3;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S270>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_aa;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S274>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscret_o;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S257>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_d;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S258>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_k35;         /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S262>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscret_f;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S275>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_g;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S276>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_ow;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S280>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscret_fo;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S165>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_hi;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S166>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_db;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S170>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscret_iw;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S113>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_b;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S114>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_ff;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S118>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscret_or;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S228>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_bv;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S229>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_ga;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S233>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscret_j;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S176>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_c;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S177>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_foe;         /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S181>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscret_p;           /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S291>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_cu;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S292>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_hin;         /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S296>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscret_bq;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S239>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_f4;          /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S240>/Variable Discrete Delay with One Tap S-function'
                                        */
  int32_T VariableDiscret_iwf;         /* Expression: int32(MaxDelaySamples(1))
                                        * Referenced by: '<S244>/Variable Discrete Delay with Two Taps S-function'
                                        */
  int32_T VariableDiscreteDelaywithOn_epw;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S397>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithO_epwu;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S398>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwo_ep;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S402>/Variable Discrete Delay with Two Taps S-function'
                                           */
  int32_T VariableDiscreteDelaywithOn_ii1;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S965>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithO_ii12;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S966>/Variable Discrete Delay with One Tap S-function'
                                           */
  int32_T VariableDiscreteDelaywithTwo_ii;/* Expression: int32(MaxDelaySamples(1))
                                           * Referenced by: '<S970>/Variable Discrete Delay with Two Taps S-function'
                                           */
  uint32_T int2_Value;                 /* Computed Parameter: int2_Value
                                        * Referenced by: '<S320>/int2'
                                        */
  uint32_T const_Value;                /* Computed Parameter: const_Value
                                        * Referenced by: '<S320>/const'
                                        */
  uint32_T int2_Value_f;               /* Computed Parameter: int2_Value_f
                                        * Referenced by: '<S321>/int2'
                                        */
  uint32_T const_Value_f;              /* Computed Parameter: const_Value_f
                                        * Referenced by: '<S321>/const'
                                        */
  uint32_T int2_Value_fk;              /* Computed Parameter: int2_Value_fk
                                        * Referenced by: '<S322>/int2'
                                        */
  uint32_T const_Value_fk;             /* Computed Parameter: const_Value_fk
                                        * Referenced by: '<S322>/const'
                                        */
  uint32_T int1_Value;                 /* Computed Parameter: int1_Value
                                        * Referenced by: '<S337>/int1'
                                        */
  uint32_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S340>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_c;      /* Computed Parameter: FixPtConstant_Value_c
                                        * Referenced by: '<S338>/FixPt Constant'
                                        */
  uint32_T int2_Value_c;               /* Computed Parameter: int2_Value_c
                                        * Referenced by: '<S334>/int2'
                                        */
  uint32_T const_Value_c;              /* Computed Parameter: const_Value_c
                                        * Referenced by: '<S334>/const'
                                        */
  uint32_T int1_Value_c;               /* Computed Parameter: int1_Value_c
                                        * Referenced by: '<S335>/int1'
                                        */
  uint32_T FixPtConstant_Value_ci;     /* Computed Parameter: FixPtConstant_Value_ci
                                        * Referenced by: '<S347>/FixPt Constant'
                                        */
  uint32_T int1_Value_e;               /* Computed Parameter: int1_Value_e
                                        * Referenced by: '<S413>/int1'
                                        */
  uint32_T FixPtConstant_Value_e;      /* Computed Parameter: FixPtConstant_Value_e
                                        * Referenced by: '<S415>/FixPt Constant'
                                        */
  uint32_T int32_Value;                /* Computed Parameter: int32_Value
                                        * Referenced by: '<S413>/int32'
                                        */
  uint32_T int1_Value_ep;              /* Computed Parameter: int1_Value_ep
                                        * Referenced by: '<S448>/int1'
                                        */
  uint32_T FixPtConstant_Value_ep;     /* Computed Parameter: FixPtConstant_Value_ep
                                        * Referenced by: '<S452>/FixPt Constant'
                                        */
  uint32_T Constant_Value_hw;          /* Computed Parameter: Constant_Value_hw
                                        * Referenced by: '<S443>/Constant'
                                        */
  uint32_T int2_Value_h;               /* Computed Parameter: int2_Value_h
                                        * Referenced by: '<S319>/int2'
                                        */
  uint32_T const_Value_h;              /* Computed Parameter: const_Value_h
                                        * Referenced by: '<S319>/const'
                                        */
  uint32_T int1_Value_m;               /* Computed Parameter: int1_Value_m
                                        * Referenced by: '<S536>/int1'
                                        */
  uint32_T FixPtConstant_Value_m;      /* Computed Parameter: FixPtConstant_Value_m
                                        * Referenced by: '<S539>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_p;      /* Computed Parameter: FixPtConstant_Value_p
                                        * Referenced by: '<S537>/FixPt Constant'
                                        */
  uint32_T int2_Value_c2;              /* Computed Parameter: int2_Value_c2
                                        * Referenced by: '<S533>/int2'
                                        */
  uint32_T const_Value_e;              /* Computed Parameter: const_Value_e
                                        * Referenced by: '<S533>/const'
                                        */
  uint32_T int1_Value_m2;              /* Computed Parameter: int1_Value_m2
                                        * Referenced by: '<S534>/int1'
                                        */
  uint32_T FixPtConstant_Value_j;      /* Computed Parameter: FixPtConstant_Value_j
                                        * Referenced by: '<S546>/FixPt Constant'
                                        */
  uint32_T int1_Value_ci;              /* Computed Parameter: int1_Value_ci
                                        * Referenced by: '<S685>/int1'
                                        */
  uint32_T const_Value_ci;             /* Computed Parameter: const_Value_ci
                                        * Referenced by: '<S685>/const'
                                        */
  uint32_T int2_Value_ci;              /* Computed Parameter: int2_Value_ci
                                        * Referenced by: '<S687>/int2'
                                        */
  uint32_T const_Value_ci1;            /* Computed Parameter: const_Value_ci1
                                        * Referenced by: '<S687>/const'
                                        */
  uint32_T int2_Value_k;               /* Computed Parameter: int2_Value_k
                                        * Referenced by: '<S607>/int2'
                                        */
  uint32_T const_Value_o;              /* Computed Parameter: const_Value_o
                                        * Referenced by: '<S607>/const'
                                        */
  uint32_T int2_Value_a;               /* Computed Parameter: int2_Value_a
                                        * Referenced by: '<S608>/int2'
                                        */
  uint32_T const_Value_n;              /* Computed Parameter: const_Value_n
                                        * Referenced by: '<S608>/const'
                                        */
  uint32_T int1_Value_h;               /* Computed Parameter: int1_Value_h
                                        * Referenced by: '<S786>/int1'
                                        */
  uint32_T const_Value_hg;             /* Computed Parameter: const_Value_hg
                                        * Referenced by: '<S786>/const'
                                        */
  uint32_T int2_Value_hg;              /* Computed Parameter: int2_Value_hg
                                        * Referenced by: '<S788>/int2'
                                        */
  uint32_T const_Value_hg0;            /* Computed Parameter: const_Value_hg0
                                        * Referenced by: '<S788>/const'
                                        */
  uint32_T int2_Value_n;               /* Computed Parameter: int2_Value_n
                                        * Referenced by: '<S708>/int2'
                                        */
  uint32_T const_Value_ec;             /* Computed Parameter: const_Value_ec
                                        * Referenced by: '<S708>/const'
                                        */
  uint32_T int2_Value_c5;              /* Computed Parameter: int2_Value_c5
                                        * Referenced by: '<S709>/int2'
                                        */
  uint32_T const_Value_o5;             /* Computed Parameter: const_Value_o5
                                        * Referenced by: '<S709>/const'
                                        */
  uint32_T int1_Value_g;               /* Computed Parameter: int1_Value_g
                                        * Referenced by: '<S887>/int1'
                                        */
  uint32_T const_Value_g;              /* Computed Parameter: const_Value_g
                                        * Referenced by: '<S887>/const'
                                        */
  uint32_T int2_Value_g;               /* Computed Parameter: int2_Value_g
                                        * Referenced by: '<S889>/int2'
                                        */
  uint32_T const_Value_gu;             /* Computed Parameter: const_Value_gu
                                        * Referenced by: '<S889>/const'
                                        */
  uint32_T int2_Value_c1;              /* Computed Parameter: int2_Value_c1
                                        * Referenced by: '<S809>/int2'
                                        */
  uint32_T const_Value_l;              /* Computed Parameter: const_Value_l
                                        * Referenced by: '<S809>/const'
                                        */
  uint32_T int2_Value_d;               /* Computed Parameter: int2_Value_d
                                        * Referenced by: '<S810>/int2'
                                        */
  uint32_T const_Value_d;              /* Computed Parameter: const_Value_d
                                        * Referenced by: '<S810>/const'
                                        */
  uint32_T int1_Value_gq;              /* Computed Parameter: int1_Value_gq
                                        * Referenced by: '<S929>/int1'
                                        */
  uint32_T FixPtConstant_Value_g;      /* Computed Parameter: FixPtConstant_Value_g
                                        * Referenced by: '<S931>/FixPt Constant'
                                        */
  uint32_T int32_Value_g;              /* Computed Parameter: int32_Value_g
                                        * Referenced by: '<S929>/int32'
                                        */
  uint32_T int1_Value_gqo;             /* Computed Parameter: int1_Value_gqo
                                        * Referenced by: '<S932>/int1'
                                        */
  uint32_T FixPtConstant_Value_gq;     /* Computed Parameter: FixPtConstant_Value_gq
                                        * Referenced by: '<S934>/FixPt Constant'
                                        */
  uint32_T int32_Value_gq;             /* Computed Parameter: int32_Value_gq
                                        * Referenced by: '<S932>/int32'
                                        */
  uint32_T int1_Value_gqop;            /* Computed Parameter: int1_Value_gqop
                                        * Referenced by: '<S935>/int1'
                                        */
  uint32_T FixPtConstant_Value_gqo;    /* Computed Parameter: FixPtConstant_Value_gqo
                                        * Referenced by: '<S937>/FixPt Constant'
                                        */
  uint32_T int32_Value_gqo;            /* Computed Parameter: int32_Value_gqo
                                        * Referenced by: '<S935>/int32'
                                        */
  uint32_T int1_Value_cm;              /* Computed Parameter: int1_Value_cm
                                        * Referenced by: '<S942>/int1'
                                        */
  uint32_T FixPtConstant_Value_cm;     /* Computed Parameter: FixPtConstant_Value_cm
                                        * Referenced by: '<S944>/FixPt Constant'
                                        */
  uint32_T int32_Value_c;              /* Computed Parameter: int32_Value_c
                                        * Referenced by: '<S942>/int32'
                                        */
  uint32_T int2_Value_o;               /* Computed Parameter: int2_Value_o
                                        * Referenced by: '<S941>/int2'
                                        */
  uint32_T const_Value_oz;             /* Computed Parameter: const_Value_oz
                                        * Referenced by: '<S941>/const'
                                        */
  uint32_T int1_Value_n;               /* Computed Parameter: int1_Value_n
                                        * Referenced by: '<S981>/int1'
                                        */
  uint32_T FixPtConstant_Value_n;      /* Computed Parameter: FixPtConstant_Value_n
                                        * Referenced by: '<S983>/FixPt Constant'
                                        */
  uint32_T int32_Value_n;              /* Computed Parameter: int32_Value_n
                                        * Referenced by: '<S981>/int32'
                                        */
  uint32_T int1_Value_gb;              /* Computed Parameter: int1_Value_gb
                                        * Referenced by: '<S1016>/int1'
                                        */
  uint32_T FixPtConstant_Value_gb;     /* Computed Parameter: FixPtConstant_Value_gb
                                        * Referenced by: '<S1020>/FixPt Constant'
                                        */
  uint32_T Constant_Value_gbvuwpgu2km; /* Computed Parameter: Constant_Value_gbvuwpgu2km
                                        * Referenced by: '<S1011>/Constant'
                                        */
  uint32_T int2_Value_gx;              /* Computed Parameter: int2_Value_gx
                                        * Referenced by: '<S505>/int2'
                                        */
  uint32_T const_Value_p;              /* Computed Parameter: const_Value_p
                                        * Referenced by: '<S505>/const'
                                        */
  uint32_T UnitDelay1_X0_f;            /* Computed Parameter: UnitDelay1_X0_f
                                        * Referenced by: '<S322>/Unit Delay1'
                                        */
  uint32_T Constant_Value_fkx;         /* Computed Parameter: Constant_Value_fkx
                                        * Referenced by: '<S328>/Constant'
                                        */
  uint32_T UnitDelay1_X0_fk;           /* Computed Parameter: UnitDelay1_X0_fk
                                        * Referenced by: '<S321>/Unit Delay1'
                                        */
  uint32_T Constant_Value_fkxn;        /* Computed Parameter: Constant_Value_fkxn
                                        * Referenced by: '<S326>/Constant'
                                        */
  uint32_T UnitDelay_X0_ep;            /* Computed Parameter: UnitDelay_X0_ep
                                        * Referenced by: '<S413>/Unit Delay'
                                        */
  uint32_T Constant_Value_e3;          /* Computed Parameter: Constant_Value_e3
                                        * Referenced by: '<S414>/Constant'
                                        */
  uint32_T UnitDelay1_X0_fkx;          /* Computed Parameter: UnitDelay1_X0_fkx
                                        * Referenced by: '<S320>/Unit Delay1'
                                        */
  uint32_T Constant_Value_fkxna;       /* Computed Parameter: Constant_Value_fkxna
                                        * Referenced by: '<S324>/Constant'
                                        */
  uint32_T UnitDelay1_X0_fo;           /* Computed Parameter: UnitDelay1_X0_fo
                                        * Referenced by: '<S941>/Unit Delay1'
                                        */
  uint32_T UnitDelay1_X0_l3;           /* Computed Parameter: UnitDelay1_X0_l3
                                        * Referenced by: '<S607>/Unit Delay1'
                                        */
  uint32_T Constant_Value_lo;          /* Computed Parameter: Constant_Value_lo
                                        * Referenced by: '<S695>/Constant'
                                        */
  uint32_T UnitDelay1_X0_j;            /* Computed Parameter: UnitDelay1_X0_j
                                        * Referenced by: '<S708>/Unit Delay1'
                                        */
  uint32_T Constant_Value_cm;          /* Computed Parameter: Constant_Value_cm
                                        * Referenced by: '<S796>/Constant'
                                        */
  uint32_T UnitDelay1_X0_ex;           /* Computed Parameter: UnitDelay1_X0_ex
                                        * Referenced by: '<S809>/Unit Delay1'
                                        */
  uint32_T Constant_Value_him;         /* Computed Parameter: Constant_Value_him
                                        * Referenced by: '<S897>/Constant'
                                        */
  uint32_T UnitDelay1_X0_l5;           /* Computed Parameter: UnitDelay1_X0_l5
                                        * Referenced by: '<S608>/Unit Delay1'
                                        */
  uint32_T Constant_Value_e1g;         /* Computed Parameter: Constant_Value_e1g
                                        * Referenced by: '<S697>/Constant'
                                        */
  uint32_T UnitDelay1_X0_c;            /* Computed Parameter: UnitDelay1_X0_c
                                        * Referenced by: '<S687>/Unit Delay1'
                                        */
  uint32_T Constant_Value_ci;          /* Computed Parameter: Constant_Value_ci
                                        * Referenced by: '<S690>/Constant'
                                        */
  uint32_T UnitDelay1_X0_ci;           /* Computed Parameter: UnitDelay1_X0_ci
                                        * Referenced by: '<S685>/Unit Delay1'
                                        */
  uint32_T Constant_Value_ci1;         /* Computed Parameter: Constant_Value_ci1
                                        * Referenced by: '<S688>/Constant'
                                        */
  uint32_T UnitDelay_X0_gq;            /* Computed Parameter: UnitDelay_X0_gq
                                        * Referenced by: '<S929>/Unit Delay'
                                        */
  uint32_T Constant_Value_gq;          /* Computed Parameter: Constant_Value_gq
                                        * Referenced by: '<S930>/Constant'
                                        */
  uint32_T UnitDelay_X0_gqo;           /* Computed Parameter: UnitDelay_X0_gqo
                                        * Referenced by: '<S932>/Unit Delay'
                                        */
  uint32_T Constant_Value_gqo;         /* Computed Parameter: Constant_Value_gqo
                                        * Referenced by: '<S933>/Constant'
                                        */
  uint32_T UnitDelay_X0_gqop;          /* Computed Parameter: UnitDelay_X0_gqop
                                        * Referenced by: '<S935>/Unit Delay'
                                        */
  uint32_T Constant_Value_gqop;        /* Computed Parameter: Constant_Value_gqop
                                        * Referenced by: '<S936>/Constant'
                                        */
  uint32_T UnitDelay1_X0_f0;           /* Computed Parameter: UnitDelay1_X0_f0
                                        * Referenced by: '<S709>/Unit Delay1'
                                        */
  uint32_T Constant_Value_oh;          /* Computed Parameter: Constant_Value_oh
                                        * Referenced by: '<S798>/Constant'
                                        */
  uint32_T UnitDelay1_X0_hg;           /* Computed Parameter: UnitDelay1_X0_hg
                                        * Referenced by: '<S788>/Unit Delay1'
                                        */
  uint32_T Constant_Value_hg;          /* Computed Parameter: Constant_Value_hg
                                        * Referenced by: '<S791>/Constant'
                                        */
  uint32_T UnitDelay1_X0_hg0;          /* Computed Parameter: UnitDelay1_X0_hg0
                                        * Referenced by: '<S786>/Unit Delay1'
                                        */
  uint32_T Constant_Value_hg0;         /* Computed Parameter: Constant_Value_hg0
                                        * Referenced by: '<S789>/Constant'
                                        */
  uint32_T UnitDelay1_X0_k;            /* Computed Parameter: UnitDelay1_X0_k
                                        * Referenced by: '<S810>/Unit Delay1'
                                        */
  uint32_T Constant_Value_oyw;         /* Computed Parameter: Constant_Value_oyw
                                        * Referenced by: '<S899>/Constant'
                                        */
  uint32_T UnitDelay1_X0_gu;           /* Computed Parameter: UnitDelay1_X0_gu
                                        * Referenced by: '<S889>/Unit Delay1'
                                        */
  uint32_T Constant_Value_gu;          /* Computed Parameter: Constant_Value_gu
                                        * Referenced by: '<S892>/Constant'
                                        */
  uint32_T UnitDelay1_X0_gun;          /* Computed Parameter: UnitDelay1_X0_gun
                                        * Referenced by: '<S887>/Unit Delay1'
                                        */
  uint32_T Constant_Value_gun;         /* Computed Parameter: Constant_Value_gun
                                        * Referenced by: '<S890>/Constant'
                                        */
  uint32_T UnitDelay_X0_n;             /* Computed Parameter: UnitDelay_X0_n
                                        * Referenced by: '<S981>/Unit Delay'
                                        */
  uint32_T Constant_Value_nl;          /* Computed Parameter: Constant_Value_nl
                                        * Referenced by: '<S982>/Constant'
                                        */
  uint32_T Constant_Value_na;          /* Computed Parameter: Constant_Value_na
                                        * Referenced by: '<S945>/Constant'
                                        */
  uint32_T UnitDelay_X0_c;             /* Computed Parameter: UnitDelay_X0_c
                                        * Referenced by: '<S942>/Unit Delay'
                                        */
  uint32_T Constant_Value_cmk;         /* Computed Parameter: Constant_Value_cmk
                                        * Referenced by: '<S943>/Constant'
                                        */
  uint32_T FixPtConstant_Value_f;      /* Computed Parameter: FixPtConstant_Value_f
                                        * Referenced by: '<S325>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_fk;     /* Computed Parameter: FixPtConstant_Value_fk
                                        * Referenced by: '<S327>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_fkx;    /* Computed Parameter: FixPtConstant_Value_fkx
                                        * Referenced by: '<S329>/FixPt Constant'
                                        */
  uint32_T UnitDelay1_X0_hn;           /* Computed Parameter: UnitDelay1_X0_hn
                                        * Referenced by: '<S319>/Unit Delay1'
                                        */
  uint32_T Constant_Value_hnl;         /* Computed Parameter: Constant_Value_hnl
                                        * Referenced by: '<S490>/Constant'
                                        */
  uint32_T UnitDelay_X0_ci;            /* Computed Parameter: UnitDelay_X0_ci
                                        * Referenced by: '<S337>/Unit Delay'
                                        */
  uint32_T Constant_Value_civ;         /* Computed Parameter: Constant_Value_civ
                                        * Referenced by: '<S339>/Constant'
                                        */
  uint32_T UnitDelay1_X0_civ;          /* Computed Parameter: UnitDelay1_X0_civ
                                        * Referenced by: '<S335>/Unit Delay1'
                                        */
  uint32_T Constant_Value_civ2;        /* Computed Parameter: Constant_Value_civ2
                                        * Referenced by: '<S343>/Constant'
                                        */
  uint32_T UnitDelay1_X0_civ2;         /* Computed Parameter: UnitDelay1_X0_civ2
                                        * Referenced by: '<S334>/Unit Delay1'
                                        */
  uint32_T Constant_Value_civ2q;       /* Computed Parameter: Constant_Value_civ2q
                                        * Referenced by: '<S341>/Constant'
                                        */
  uint32_T FixPtConstant_Value_civ;    /* Computed Parameter: FixPtConstant_Value_civ
                                        * Referenced by: '<S342>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_civ2;   /* Computed Parameter: FixPtConstant_Value_civ2
                                        * Referenced by: '<S344>/FixPt Constant'
                                        */
  uint32_T UnitDelay_X0_epw;           /* Computed Parameter: UnitDelay_X0_epw
                                        * Referenced by: '<S443>/Unit Delay'
                                        */
  uint32_T Bias_Bias_epwu2g;           /* Computed Parameter: Bias_Bias_epwu2g
                                        * Referenced by: '<S443>/Bias'
                                        */
  uint32_T UnitDelay2_X0_epwu2g;       /* Computed Parameter: UnitDelay2_X0_epwu2g
                                        * Referenced by: '<S443>/Unit Delay2'
                                        */
  uint32_T UnitDelay_X0_epwu;          /* Computed Parameter: UnitDelay_X0_epwu
                                        * Referenced by: '<S448>/Unit Delay'
                                        */
  uint32_T Constant_Value_a3;          /* Computed Parameter: Constant_Value_a3
                                        * Referenced by: '<S451>/Constant'
                                        */
  uint32_T FixPtConstant_Value_h;      /* Computed Parameter: FixPtConstant_Value_h
                                        * Referenced by: '<S491>/FixPt Constant'
                                        */
  uint32_T UnitDelay1_X0_hi;           /* Computed Parameter: UnitDelay1_X0_hi
                                        * Referenced by: '<S505>/Unit Delay1'
                                        */
  uint32_T Constant_Value_a0;          /* Computed Parameter: Constant_Value_a0
                                        * Referenced by: '<S1028>/Constant'
                                        */
  uint32_T UnitDelay_X0_m4;            /* Computed Parameter: UnitDelay_X0_m4
                                        * Referenced by: '<S536>/Unit Delay'
                                        */
  uint32_T Constant_Value_m4;          /* Computed Parameter: Constant_Value_m4
                                        * Referenced by: '<S538>/Constant'
                                        */
  uint32_T UnitDelay1_X0_m;            /* Computed Parameter: UnitDelay1_X0_m
                                        * Referenced by: '<S534>/Unit Delay1'
                                        */
  uint32_T Constant_Value_cjo;         /* Computed Parameter: Constant_Value_cjo
                                        * Referenced by: '<S542>/Constant'
                                        */
  uint32_T UnitDelay1_X0_n;            /* Computed Parameter: UnitDelay1_X0_n
                                        * Referenced by: '<S533>/Unit Delay1'
                                        */
  uint32_T Constant_Value_f0;          /* Computed Parameter: Constant_Value_f0
                                        * Referenced by: '<S540>/Constant'
                                        */
  uint32_T FixPtConstant_Value_jh;     /* Computed Parameter: FixPtConstant_Value_jh
                                        * Referenced by: '<S541>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_jl;     /* Computed Parameter: FixPtConstant_Value_jl
                                        * Referenced by: '<S543>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_ci1;    /* Computed Parameter: FixPtConstant_Value_ci1
                                        * Referenced by: '<S689>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_ci1z;   /* Computed Parameter: FixPtConstant_Value_ci1z
                                        * Referenced by: '<S691>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_eb;     /* Computed Parameter: FixPtConstant_Value_eb
                                        * Referenced by: '<S696>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_b;      /* Computed Parameter: FixPtConstant_Value_b
                                        * Referenced by: '<S698>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_hg;     /* Computed Parameter: FixPtConstant_Value_hg
                                        * Referenced by: '<S790>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_hg0;    /* Computed Parameter: FixPtConstant_Value_hg0
                                        * Referenced by: '<S792>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_gy;     /* Computed Parameter: FixPtConstant_Value_gy
                                        * Referenced by: '<S797>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_bi;     /* Computed Parameter: FixPtConstant_Value_bi
                                        * Referenced by: '<S799>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_gu;     /* Computed Parameter: FixPtConstant_Value_gu
                                        * Referenced by: '<S891>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_gun;    /* Computed Parameter: FixPtConstant_Value_gun
                                        * Referenced by: '<S893>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_cp;     /* Computed Parameter: FixPtConstant_Value_cp
                                        * Referenced by: '<S898>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_fkp;    /* Computed Parameter: FixPtConstant_Value_fkp
                                        * Referenced by: '<S900>/FixPt Constant'
                                        */
  uint32_T FixPtConstant_Value_k;      /* Computed Parameter: FixPtConstant_Value_k
                                        * Referenced by: '<S946>/FixPt Constant'
                                        */
  uint32_T UnitDelay_X0_gb;            /* Computed Parameter: UnitDelay_X0_gb
                                        * Referenced by: '<S1011>/Unit Delay'
                                        */
  uint32_T Bias_Bias_gbvu;             /* Computed Parameter: Bias_Bias_gbvu
                                        * Referenced by: '<S1011>/Bias'
                                        */
  uint32_T UnitDelay2_X0_gb;           /* Computed Parameter: UnitDelay2_X0_gb
                                        * Referenced by: '<S1011>/Unit Delay2'
                                        */
  uint32_T UnitDelay_X0_gbv;           /* Computed Parameter: UnitDelay_X0_gbv
                                        * Referenced by: '<S1016>/Unit Delay'
                                        */
  uint32_T Constant_Value_gbvuwpgu2kml;/* Computed Parameter: Constant_Value_gbvuwpgu2kml
                                        * Referenced by: '<S1019>/Constant'
                                        */
  uint32_T FixPtConstant_Value_mp;     /* Computed Parameter: FixPtConstant_Value_mp
                                        * Referenced by: '<S1029>/FixPt Constant'
                                        */
  boolean_T Constant5_Value_d;         /* Computed Parameter: Constant5_Value_d
                                        * Referenced by: '<S310>/Constant5'
                                        */
  boolean_T UnitDelay4_X0_oc;          /* Computed Parameter: UnitDelay4_X0_oc
                                        * Referenced by: '<S494>/Unit Delay4'
                                        */
  boolean_T delay_X0;                  /* Computed Parameter: delay_X0
                                        * Referenced by: '<S1025>/delay'
                                        */
  boolean_T UnitDelay4_X0_ci;          /* Computed Parameter: UnitDelay4_X0_ci
                                        * Referenced by: '<S312>/Unit Delay4'
                                        */
  boolean_T delay_X0_o;                /* Computed Parameter: delay_X0_o
                                        * Referenced by: '<S457>/delay'
                                        */
  boolean_T UnitDelay2_X0_ek;          /* Computed Parameter: UnitDelay2_X0_ek
                                        * Referenced by: '<S309>/Unit Delay2'
                                        */
  boolean_T delay1_X0;                 /* Computed Parameter: delay1_X0
                                        * Referenced by: '<S479>/delay1'
                                        */
  boolean_T delay1_X0_h;               /* Computed Parameter: delay1_X0_h
                                        * Referenced by: '<S464>/delay1'
                                        */
  boolean_T delay_X0_h;                /* Computed Parameter: delay_X0_h
                                        * Referenced by: '<S463>/delay'
                                        */
  boolean_T delay_X0_hp;               /* Computed Parameter: delay_X0_hp
                                        * Referenced by: '<S478>/delay'
                                        */
  boolean_T delay1_X0_e;               /* Computed Parameter: delay1_X0_e
                                        * Referenced by: '<S423>/delay1'
                                        */
  boolean_T delay_X0_e;                /* Computed Parameter: delay_X0_e
                                        * Referenced by: '<S422>/delay'
                                        */
  boolean_T Constant1_Value_p;         /* Computed Parameter: Constant1_Value_p
                                        * Referenced by: '<S502>/Constant1'
                                        */
  boolean_T UnitDelay4_X0_ol;          /* Computed Parameter: UnitDelay4_X0_ol
                                        * Referenced by: '<S310>/Unit Delay4'
                                        */
  boolean_T delay1_X0_a;               /* Computed Parameter: delay1_X0_a
                                        * Referenced by: '<S558>/delay1'
                                        */
  boolean_T delay_X0_a;                /* Computed Parameter: delay_X0_a
                                        * Referenced by: '<S557>/delay'
                                        */
  boolean_T delay1_X0_ad;              /* Computed Parameter: delay1_X0_ad
                                        * Referenced by: '<S588>/delay1'
                                        */
  boolean_T delay1_X0_adh;             /* Computed Parameter: delay1_X0_adh
                                        * Referenced by: '<S573>/delay1'
                                        */
  boolean_T delay_X0_ad;               /* Computed Parameter: delay_X0_ad
                                        * Referenced by: '<S572>/delay'
                                        */
  boolean_T delay_X0_adh;              /* Computed Parameter: delay_X0_adh
                                        * Referenced by: '<S587>/delay'
                                        */
  boolean_T UnitDelay_X0_ci1;          /* Computed Parameter: UnitDelay_X0_ci1
                                        * Referenced by: '<S686>/Unit Delay'
                                        */
  boolean_T UnitDelay_X0_hg;           /* Computed Parameter: UnitDelay_X0_hg
                                        * Referenced by: '<S787>/Unit Delay'
                                        */
  boolean_T UnitDelay_X0_gu;           /* Computed Parameter: UnitDelay_X0_gu
                                        * Referenced by: '<S888>/Unit Delay'
                                        */
  boolean_T delay1_X0_d;               /* Computed Parameter: delay1_X0_d
                                        * Referenced by: '<S991>/delay1'
                                        */
  boolean_T delay_X0_d;                /* Computed Parameter: delay_X0_d
                                        * Referenced by: '<S990>/delay'
                                        */
  boolean_T delay1_X0_k;               /* Computed Parameter: delay1_X0_k
                                        * Referenced by: '<S938>/delay1'
                                        */
  boolean_T UnitDelay1_X0_gd;          /* Computed Parameter: UnitDelay1_X0_gd
                                        * Referenced by: '<S940>/Unit Delay1'
                                        */
  boolean_T Constant_Value_py;         /* Computed Parameter: Constant_Value_py
                                        * Referenced by: '<S103>/Constant'
                                        */
  boolean_T Constant6_Value_n;         /* Computed Parameter: Constant6_Value_n
                                        * Referenced by: '<S310>/Constant6'
                                        */
  boolean_T delay_X0_c;                /* Computed Parameter: delay_X0_c
                                        * Referenced by: '<S331>/delay'
                                        */
  boolean_T UnitDelay_X0_civ;          /* Computed Parameter: UnitDelay_X0_civ
                                        * Referenced by: '<S333>/Unit Delay'
                                        */
  boolean_T UnitDelay_X0_civ2;         /* Computed Parameter: UnitDelay_X0_civ2
                                        * Referenced by: '<S346>/Unit Delay'
                                        */
  boolean_T Constant_Value_civ2qn;     /* Computed Parameter: Constant_Value_civ2qn
                                        * Referenced by: '<S346>/Constant'
                                        */
  boolean_T UnitDelay2_X0_epwu2gd;     /* Computed Parameter: UnitDelay2_X0_epwu2gd
                                        * Referenced by: '<S388>/Unit Delay2'
                                        */
  boolean_T delay_X0_ep;               /* Computed Parameter: delay_X0_ep
                                        * Referenced by: '<S434>/delay'
                                        */
  boolean_T Constant_Value_adu;        /* Computed Parameter: Constant_Value_adu
                                        * Referenced by: '<S388>/Constant'
                                        */
  boolean_T delay1_X0_ep;              /* Computed Parameter: delay1_X0_ep
                                        * Referenced by: '<S435>/delay1'
                                        */
  boolean_T UnitDelay_X0_epwu2;        /* Computed Parameter: UnitDelay_X0_epwu2
                                        * Referenced by: '<S445>/Unit Delay'
                                        */
  boolean_T Constant_Value_dso;        /* Computed Parameter: Constant_Value_dso
                                        * Referenced by: '<S445>/Constant'
                                        */
  boolean_T Constant2_Value_e;         /* Computed Parameter: Constant2_Value_e
                                        * Referenced by: '<S388>/Constant2'
                                        */
  boolean_T delay_X0_o0;               /* Computed Parameter: delay_X0_o0
                                        * Referenced by: '<S530>/delay'
                                        */
  boolean_T UnitDelay_X0_i;            /* Computed Parameter: UnitDelay_X0_i
                                        * Referenced by: '<S532>/Unit Delay'
                                        */
  boolean_T UnitDelay_X0_mr;           /* Computed Parameter: UnitDelay_X0_mr
                                        * Referenced by: '<S545>/Unit Delay'
                                        */
  boolean_T Constant_Value_mr;         /* Computed Parameter: Constant_Value_mr
                                        * Referenced by: '<S545>/Constant'
                                        */
  boolean_T UnitDelay2_X0_gbv;         /* Computed Parameter: UnitDelay2_X0_gbv
                                        * Referenced by: '<S956>/Unit Delay2'
                                        */
  boolean_T delay_X0_g;                /* Computed Parameter: delay_X0_g
                                        * Referenced by: '<S1002>/delay'
                                        */
  boolean_T Constant_Value_gbvuwpgu2kml1;/* Computed Parameter: Constant_Value_gbvuwpgu2kml1
                                          * Referenced by: '<S956>/Constant'
                                          */
  boolean_T delay1_X0_g;               /* Computed Parameter: delay1_X0_g
                                        * Referenced by: '<S1003>/delay1'
                                        */
  boolean_T UnitDelay_X0_gbvu;         /* Computed Parameter: UnitDelay_X0_gbvu
                                        * Referenced by: '<S1013>/Unit Delay'
                                        */
  boolean_T Constant_Value_gbvuwpgu2kml14;/* Computed Parameter: Constant_Value_gbvuwpgu2kml14
                                           * Referenced by: '<S1013>/Constant'
                                           */
  boolean_T Constant2_Value_g;         /* Computed Parameter: Constant2_Value_g
                                        * Referenced by: '<S956>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_measure {
  const char_T * volatile errorStatus;
};

/* Class declaration for model measure */
class measureModelClass {
  /* public data and function members */
 public:
  /* External inputs */
  ExternalInputs_measure measure_U;

  /* External outputs */
  ExternalOutputs_measure measure_Y;

  /* Model entry point functions */

  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  measureModelClass();

  /* Destructor */
  ~measureModelClass();

  /* Block parameters get method */
  const Parameters_measure & getBlockParameters() const;

  /* Block parameters set method */
  void setBlockParameters(const Parameters_measure *pmeasure_P);

  /* Real-Time Model get method */
  RT_MODEL_measure * getRTM() const;

  /* private data and function members */
 private:
  /* Tunable parameters */
  Parameters_measure measure_P;

  /* Block signals */
  BlockIO_measure measure_B;

  /* Block states */
  D_Work_measure measure_DWork;

  /* Real-Time Model */
  RT_MODEL_measure measure_M_;

  /* Real-Time Model pointer */
  RT_MODEL_measure *measure_M;
};

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
 * '<Root>' : 'measure'
 * '<S1>'   : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews'
 * '<S2>'   : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values'
 * '<S3>'   : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values'
 * '<S4>'   : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi'
 * '<S5>'   : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase'
 * '<S6>'   : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase1'
 * '<S7>'   : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi1'
 * '<S8>'   : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews'
 * '<S9>'   : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement'
 * '<S10>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Lower limit'
 * '<S11>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Range limit'
 * '<S12>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method'
 * '<S13>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method1'
 * '<S14>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method2'
 * '<S15>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Lower limit/Compare To Constant'
 * '<S16>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Range limit/Compare To Constant'
 * '<S17>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Range limit/Compare To Constant1'
 * '<S18>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method/Check for <-pi or >pi'
 * '<S19>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method/Lower limit'
 * '<S20>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method/Check for <-pi or >pi/Compare To Constant'
 * '<S21>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method/Check for <-pi or >pi/Compare To Constant1'
 * '<S22>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method/Lower limit/Compare To Constant'
 * '<S23>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method1/Check for <-pi or >pi'
 * '<S24>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method1/Lower limit'
 * '<S25>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method1/Check for <-pi or >pi/Compare To Constant'
 * '<S26>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method1/Check for <-pi or >pi/Compare To Constant1'
 * '<S27>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method1/Lower limit/Compare To Constant'
 * '<S28>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method2/Check for <-pi or >pi'
 * '<S29>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method2/Lower limit'
 * '<S30>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method2/Check for <-pi or >pi/Compare To Constant'
 * '<S31>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method2/Check for <-pi or >pi/Compare To Constant1'
 * '<S32>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase power analyser Using Fourier path average values/Resolve voltage and current angles Vector method2/Lower limit/Compare To Constant'
 * '<S33>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method'
 * '<S34>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1'
 * '<S35>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/Check for <-pi or >pi'
 * '<S36>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/Mean or max of size 3 array'
 * '<S37>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/Mean or max of size 3 array1'
 * '<S38>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method/Cart to Polar'
 * '<S39>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method/Cart to Polar1'
 * '<S40>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method/Cart to Polar2'
 * '<S41>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method/Lower limit'
 * '<S42>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method/Cart to Polar/atan2'
 * '<S43>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method/Cart to Polar/hypot'
 * '<S44>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method/Cart to Polar1/atan2'
 * '<S45>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method/Cart to Polar1/hypot'
 * '<S46>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method/Cart to Polar2/atan2'
 * '<S47>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method/Cart to Polar2/hypot'
 * '<S48>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method/Lower limit/Compare To Constant'
 * '<S49>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1/Cart to Polar'
 * '<S50>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1/Cart to Polar1'
 * '<S51>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1/Cart to Polar2'
 * '<S52>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1/Lower limit'
 * '<S53>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1/Cart to Polar/atan2'
 * '<S54>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1/Cart to Polar/hypot'
 * '<S55>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1/Cart to Polar1/atan2'
 * '<S56>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1/Cart to Polar1/hypot'
 * '<S57>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1/Cart to Polar2/atan2'
 * '<S58>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1/Cart to Polar2/hypot'
 * '<S59>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/+ve, -ve & zero sequences and unbalance Vector method1/Lower limit/Compare To Constant'
 * '<S60>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/Check for <-pi or >pi/Compare To Constant'
 * '<S61>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/3-phase voltage and current balance analyser Using Fourier path average values/Check for <-pi or >pi/Compare To Constant1'
 * '<S62>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi/Compare To Constant'
 * '<S63>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi/Compare To Constant1'
 * '<S64>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase/Check for <-pi or >pi'
 * '<S65>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase/Check for <-pi or >pi1'
 * '<S66>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase/Check for <-pi or >pi2'
 * '<S67>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase/Check for <-pi or >pi/Compare To Constant'
 * '<S68>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase/Check for <-pi or >pi/Compare To Constant1'
 * '<S69>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase/Check for <-pi or >pi1/Compare To Constant'
 * '<S70>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase/Check for <-pi or >pi1/Compare To Constant1'
 * '<S71>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase/Check for <-pi or >pi2/Compare To Constant'
 * '<S72>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase/Check for <-pi or >pi2/Compare To Constant1'
 * '<S73>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase1/Check for <-pi or >pi'
 * '<S74>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase1/Check for <-pi or >pi1'
 * '<S75>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase1/Check for <-pi or >pi2'
 * '<S76>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase1/Check for <-pi or >pi/Compare To Constant'
 * '<S77>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase1/Check for <-pi or >pi/Compare To Constant1'
 * '<S78>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase1/Check for <-pi or >pi1/Compare To Constant'
 * '<S79>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase1/Check for <-pi or >pi1/Compare To Constant1'
 * '<S80>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase1/Check for <-pi or >pi2/Compare To Constant'
 * '<S81>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi Three phase1/Check for <-pi or >pi2/Compare To Constant1'
 * '<S82>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi1/Compare To Constant'
 * '<S83>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Check for <-pi or >pi1/Compare To Constant1'
 * '<S84>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay'
 * '<S85>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay1'
 * '<S86>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay2'
 * '<S87>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay3'
 * '<S88>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay4'
 * '<S89>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay5'
 * '<S90>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay/2nd order polynomial'
 * '<S91>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay/2nd order polynomial fitter'
 * '<S92>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay1/2nd order polynomial'
 * '<S93>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay1/2nd order polynomial fitter'
 * '<S94>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay2/2nd order polynomial'
 * '<S95>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay2/2nd order polynomial fitter'
 * '<S96>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay3/2nd order polynomial'
 * '<S97>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay3/2nd order polynomial fitter'
 * '<S98>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay4/2nd order polynomial'
 * '<S99>'  : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay4/2nd order polynomial fitter'
 * '<S100>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay5/2nd order polynomial'
 * '<S101>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Correct for ADC time skews 6 signals 2nd order Dynamic skews/Apply lag to ADC input 2nd order Dynamic delay5/2nd order polynomial fitter'
 * '<S102>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase'
 * '<S103>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid'
 * '<S104>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging'
 * '<S105>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1'
 * '<S106>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2'
 * '<S107>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results'
 * '<S108>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt'
 * '<S109>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle'
 * '<S110>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B'
 * '<S111>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms'
 * '<S112>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle'
 * '<S113>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S114>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S115>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S116>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S117>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S118>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S119>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/2-point differentiator'
 * '<S120>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2'
 * '<S121>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3'
 * '<S122>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar'
 * '<S123>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Compare To Constant'
 * '<S124>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/abs'
 * '<S125>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S126>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S127>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order'
 * '<S128>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S129>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S130>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S131>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S132>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S133>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order'
 * '<S134>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S135>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S136>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S137>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/atan2'
 * '<S138>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/hypot'
 * '<S139>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/abs/Compare To Zero'
 * '<S140>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt'
 * '<S141>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1'
 * '<S142>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar'
 * '<S143>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S144>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S145>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S146>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S147>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S148>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S149>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S150>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S151>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order'
 * '<S152>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S153>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S154>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S155>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar/atan2'
 * '<S156>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar/hypot'
 * '<S157>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit'
 * '<S158>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit2'
 * '<S159>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Upper limit'
 * '<S160>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit/Compare To Constant'
 * '<S161>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit2/Compare To Constant'
 * '<S162>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Upper limit/Compare To Constant'
 * '<S163>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle'
 * '<S164>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt'
 * '<S165>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S166>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S167>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S168>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S169>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S170>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S171>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Avg//int, variable Tint, 1st order, opt'
 * '<S172>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle'
 * '<S173>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B'
 * '<S174>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/THD from Urms and U1rms'
 * '<S175>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Urms No cancellation One or half cycle'
 * '<S176>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S177>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S178>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S179>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S180>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S181>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S182>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/2-point differentiator'
 * '<S183>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2'
 * '<S184>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3'
 * '<S185>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Cart to Polar'
 * '<S186>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Compare To Constant'
 * '<S187>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/abs'
 * '<S188>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S189>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S190>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order'
 * '<S191>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S192>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S193>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S194>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S195>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S196>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order'
 * '<S197>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S198>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S199>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S200>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/atan2'
 * '<S201>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/hypot'
 * '<S202>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Discrete fourier (dynamic F) part B One cycle/abs/Compare To Zero'
 * '<S203>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt'
 * '<S204>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1'
 * '<S205>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Cart to Polar'
 * '<S206>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S207>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S208>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S209>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S210>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S211>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S212>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S213>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S214>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order'
 * '<S215>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S216>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S217>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S218>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Cart to Polar/atan2'
 * '<S219>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Further averaging of Path_A and Path_B/Cart to Polar/hypot'
 * '<S220>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/THD from Urms and U1rms/Lower limit'
 * '<S221>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/THD from Urms and U1rms/Lower limit2'
 * '<S222>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/THD from Urms and U1rms/Upper limit'
 * '<S223>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/THD from Urms and U1rms/Lower limit/Compare To Constant'
 * '<S224>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/THD from Urms and U1rms/Lower limit2/Compare To Constant'
 * '<S225>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/THD from Urms and U1rms/Upper limit/Compare To Constant'
 * '<S226>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Urms No cancellation One or half cycle/RMS One or half cycle'
 * '<S227>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt'
 * '<S228>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S229>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S230>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S231>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S232>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S233>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging1/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S234>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Avg//int, variable Tint, 1st order, opt'
 * '<S235>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle'
 * '<S236>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B'
 * '<S237>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/THD from Urms and U1rms'
 * '<S238>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Urms No cancellation One or half cycle'
 * '<S239>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S240>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S241>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S242>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S243>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S244>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S245>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/2-point differentiator'
 * '<S246>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2'
 * '<S247>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3'
 * '<S248>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Cart to Polar'
 * '<S249>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Compare To Constant'
 * '<S250>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/abs'
 * '<S251>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S252>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S253>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order'
 * '<S254>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S255>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S256>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S257>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S258>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S259>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order'
 * '<S260>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S261>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S262>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S263>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/atan2'
 * '<S264>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/hypot'
 * '<S265>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Discrete fourier (dynamic F) part B One cycle/abs/Compare To Zero'
 * '<S266>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt'
 * '<S267>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1'
 * '<S268>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Cart to Polar'
 * '<S269>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S270>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S271>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S272>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S273>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S274>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S275>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S276>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S277>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order'
 * '<S278>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S279>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S280>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S281>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Cart to Polar/atan2'
 * '<S282>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Further averaging of Path_A and Path_B/Cart to Polar/hypot'
 * '<S283>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/THD from Urms and U1rms/Lower limit'
 * '<S284>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/THD from Urms and U1rms/Lower limit2'
 * '<S285>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/THD from Urms and U1rms/Upper limit'
 * '<S286>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/THD from Urms and U1rms/Lower limit/Compare To Constant'
 * '<S287>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/THD from Urms and U1rms/Lower limit2/Compare To Constant'
 * '<S288>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/THD from Urms and U1rms/Upper limit/Compare To Constant'
 * '<S289>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Urms No cancellation One or half cycle/RMS One or half cycle'
 * '<S290>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt'
 * '<S291>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S292>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S293>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S294>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S295>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S296>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging2/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S297>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs'
 * '<S298>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs1'
 * '<S299>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs2'
 * '<S300>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs/Check for <-pi or >pi'
 * '<S301>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs/Check for <-pi or >pi/Compare To Constant'
 * '<S302>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs/Check for <-pi or >pi/Compare To Constant1'
 * '<S303>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs1/Check for <-pi or >pi'
 * '<S304>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs1/Check for <-pi or >pi/Compare To Constant'
 * '<S305>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs1/Check for <-pi or >pi/Compare To Constant1'
 * '<S306>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs2/Check for <-pi or >pi'
 * '<S307>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs2/Check for <-pi or >pi/Compare To Constant'
 * '<S308>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging Three Phase/Process 3-phase Fourier results/Process Fourier outputs2/Check for <-pi or >pi/Compare To Constant1'
 * '<S309>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through'
 * '<S310>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid'
 * '<S311>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity'
 * '<S312>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough'
 * '<S313>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core'
 * '<S314>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Range limit'
 * '<S315>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold'
 * '<S316>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Signal hold with lookback'
 * '<S317>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1'
 * '<S318>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2'
 * '<S319>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/True for N secs ?'
 * '<S320>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity/True for N secs ?'
 * '<S321>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity/True for N secs ?1'
 * '<S322>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity/True for N secs ?2'
 * '<S323>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity/Upper limit'
 * '<S324>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity/True for N secs ?/Compare To Zero'
 * '<S325>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity/True for N secs ?/Decrement Real World'
 * '<S326>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity/True for N secs ?1/Compare To Zero'
 * '<S327>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity/True for N secs ?1/Decrement Real World'
 * '<S328>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity/True for N secs ?2/Compare To Zero'
 * '<S329>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity/True for N secs ?2/Decrement Real World'
 * '<S330>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Check for validity/Upper limit/Compare To Constant'
 * '<S331>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/0-1 detect'
 * '<S332>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/Hold pulse high X secs'
 * '<S333>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/Latched boolean (priority off)'
 * '<S334>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/True for N secs ?2'
 * '<S335>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/True for X secs ?'
 * '<S336>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/Hold pulse high X secs/Double to UInt32 (Ceil) direct C cast no saturation checking'
 * '<S337>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/Hold pulse high X secs/Hold pulse high X samples'
 * '<S338>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/Hold pulse high X secs/Increment Real World'
 * '<S339>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/Hold pulse high X secs/Hold pulse high X samples/Compare To Zero'
 * '<S340>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/Hold pulse high X secs/Hold pulse high X samples/Decrement Real World'
 * '<S341>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/True for N secs ?2/Compare To Zero'
 * '<S342>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/True for N secs ?2/Decrement Real World'
 * '<S343>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/True for X secs ?/Compare To Zero'
 * '<S344>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/True for X secs ?/Decrement Real World'
 * '<S345>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/True for X secs ?/Double to UInt32 (Ceil) direct C cast no saturation checking'
 * '<S346>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/True for X secs ?/FALSE for initial sample'
 * '<S347>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Decide whether to activate RideThrough/True for X secs ?/Increment Real World'
 * '<S348>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/2-point differentiator of phase change to frequency'
 * '<S349>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt1'
 * '<S350>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt2'
 * '<S351>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt3'
 * '<S352>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Clark transform'
 * '<S353>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/abs'
 * '<S354>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/atan2'
 * '<S355>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/2-point differentiator of phase change to frequency/Check for <-pi or >pi'
 * '<S356>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/2-point differentiator of phase change to frequency/Check for <-pi or >pi/Compare To Constant'
 * '<S357>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/2-point differentiator of phase change to frequency/Check for <-pi or >pi/Compare To Constant1'
 * '<S358>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S359>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S360>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order'
 * '<S361>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S362>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S363>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S364>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S365>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S366>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order'
 * '<S367>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S368>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S369>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S370>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S371>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S372>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order'
 * '<S373>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S374>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S375>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S376>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Frequency of a 3-phase signal, via Clarkes rotating vector, Using a single-cycle phase change, plus 2+2 cycles averaging  core/abs/Compare To Zero'
 * '<S377>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Range limit/Compare To Constant'
 * '<S378>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Range limit/Compare To Constant1'
 * '<S379>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt'
 * '<S380>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1'
 * '<S381>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter'
 * '<S382>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value'
 * '<S383>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Double to Int32 (Zero) direct C cast no saturation checking'
 * '<S384>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Hold pulse high N secs'
 * '<S385>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Lower limit'
 * '<S386>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Lowpass filter Manual implementation Dynamic cutoff frequency'
 * '<S387>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order'
 * '<S388>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core'
 * '<S389>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/abs'
 * '<S390>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/int32 to double'
 * '<S391>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S392>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S393>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S394>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S395>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S396>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S397>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S398>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S399>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order'
 * '<S400>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S401>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S402>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S403>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter/Range limit'
 * '<S404>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter/Range limit/Compare To Constant'
 * '<S405>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter/Range limit/Compare To Constant1'
 * '<S406>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit'
 * '<S407>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit1'
 * '<S408>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit/Compare To Constant'
 * '<S409>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit/Compare To Constant1'
 * '<S410>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit1/Compare To Constant'
 * '<S411>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit1/Compare To Constant1'
 * '<S412>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Double to Int32 (Zero) direct C cast no saturation checking/Compare To Zero2'
 * '<S413>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Hold pulse high N secs/Hold pulse high N samples'
 * '<S414>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Hold pulse high N secs/Hold pulse high N samples/Compare To Zero'
 * '<S415>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Hold pulse high N secs/Hold pulse high N samples/Decrement Real World'
 * '<S416>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Lower limit/Compare To Constant'
 * '<S417>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Lowpass filter Manual implementation Dynamic cutoff frequency/Lowpass filter Manual implementation Dynamic cutoff frequency Part A'
 * '<S418>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Lowpass filter Manual implementation Dynamic cutoff frequency/Lowpass filter Manual implementation Dynamic cutoff frequency Part B'
 * '<S419>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Integral tick-tock system clock'
 * '<S420>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Range limit'
 * '<S421>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation'
 * '<S422>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Integral tick-tock system clock/0-1 detect'
 * '<S423>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Integral tick-tock system clock/1-0 detect'
 * '<S424>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Integral tick-tock system clock/Double to Boolean1'
 * '<S425>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Integral tick-tock system clock/Double to Boolean1/Compare To Constant'
 * '<S426>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Range limit/Compare To Constant'
 * '<S427>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Range limit/Compare To Constant1'
 * '<S428>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking'
 * '<S429>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/Range check Int32'
 * '<S430>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/int32 to double'
 * '<S431>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking/Compare To Zero2'
 * '<S432>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/Range check Int32/Compare To Constant'
 * '<S433>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/Range check Int32/Compare To Constant1'
 * '<S434>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/0-1 detect'
 * '<S435>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/1-0 or 0-1 detect'
 * '<S436>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Compare To Constant'
 * '<S437>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Compare To Zero'
 * '<S438>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking'
 * '<S439>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Lower limit'
 * '<S440>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Lower limit1'
 * '<S441>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Sample and hold'
 * '<S442>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Sample and hold3'
 * '<S443>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Time between pulses'
 * '<S444>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/abs'
 * '<S445>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/1-0 or 0-1 detect/FALSE for initial sample'
 * '<S446>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Double to UInt32 (Ceil) direct C cast no saturation checking'
 * '<S447>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Double to Uint32 saturation check'
 * '<S448>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Hold pulse high X samples'
 * '<S449>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Double to Uint32 saturation check/Compare To Constant'
 * '<S450>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Double to Uint32 saturation check/Compare To Constant1'
 * '<S451>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Hold pulse high X samples/Compare To Zero'
 * '<S452>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Hold pulse high X samples/Decrement Real World'
 * '<S453>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Lower limit/Compare To Constant'
 * '<S454>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Lower limit1/Compare To Constant'
 * '<S455>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/abs/Compare To Zero'
 * '<S456>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Ripple remover Dynamic ripple threshold/abs/Compare To Zero'
 * '<S457>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Signal hold with lookback/0-1 detect'
 * '<S458>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Signal hold with lookback/Fixed signal delay'
 * '<S459>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Signal hold with lookback/Fixed signal delay/Fixed signal delay S-function'
 * '<S460>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Integral tick-tock system clock'
 * '<S461>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Range limit'
 * '<S462>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Set up delay and interpolation'
 * '<S463>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Integral tick-tock system clock/0-1 detect'
 * '<S464>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Integral tick-tock system clock/1-0 detect'
 * '<S465>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Integral tick-tock system clock/Double to Boolean1'
 * '<S466>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Integral tick-tock system clock/Double to Boolean1/Compare To Constant'
 * '<S467>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Range limit/Compare To Constant'
 * '<S468>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Range limit/Compare To Constant1'
 * '<S469>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking'
 * '<S470>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Set up delay and interpolation/Range check Int32'
 * '<S471>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Set up delay and interpolation/int32 to double'
 * '<S472>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking/Compare To Zero2'
 * '<S473>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Set up delay and interpolation/Range check Int32/Compare To Constant'
 * '<S474>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order1/Set up delay and interpolation/Range check Int32/Compare To Constant1'
 * '<S475>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Integral tick-tock system clock'
 * '<S476>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Range limit'
 * '<S477>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Set up delay and interpolation'
 * '<S478>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Integral tick-tock system clock/0-1 detect'
 * '<S479>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Integral tick-tock system clock/1-0 detect'
 * '<S480>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Integral tick-tock system clock/Double to Boolean1'
 * '<S481>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Integral tick-tock system clock/Double to Boolean1/Compare To Constant'
 * '<S482>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Range limit/Compare To Constant'
 * '<S483>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Range limit/Compare To Constant1'
 * '<S484>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking'
 * '<S485>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Set up delay and interpolation/Range check Int32'
 * '<S486>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Set up delay and interpolation/int32 to double'
 * '<S487>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking/Compare To Zero2'
 * '<S488>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Set up delay and interpolation/Range check Int32/Compare To Constant'
 * '<S489>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/Time period info, 1st order2/Set up delay and interpolation/Range check Int32/Compare To Constant1'
 * '<S490>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/True for N secs ?/Compare To Zero'
 * '<S491>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Frequency of a 3-phase signal, via Clarkes rotating vector With ride through/True for N secs ?/Decrement Real World'
 * '<S492>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions'
 * '<S493>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Compare To Constant1'
 * '<S494>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough'
 * '<S495>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle'
 * '<S496>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core'
 * '<S497>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1'
 * '<S498>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2'
 * '<S499>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results'
 * '<S500>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results, Mags only'
 * '<S501>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances'
 * '<S502>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Replacement of input with seed if outside window'
 * '<S503>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold'
 * '<S504>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Signal hold with lookback'
 * '<S505>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/True for N secs ?'
 * '<S506>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Valid but modify with single or two-phase disturbances'
 * '<S507>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Lower limit'
 * '<S508>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Range limit'
 * '<S509>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements'
 * '<S510>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements1'
 * '<S511>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements2'
 * '<S512>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Lower limit/Compare To Constant'
 * '<S513>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Range limit/Compare To Constant'
 * '<S514>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Range limit/Compare To Constant1'
 * '<S515>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements/Compare To Constant'
 * '<S516>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements/Lower limit'
 * '<S517>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements/Lower limit1'
 * '<S518>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements/Lower limit/Compare To Constant'
 * '<S519>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements/Lower limit1/Compare To Constant'
 * '<S520>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements1/Compare To Constant'
 * '<S521>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements1/Lower limit'
 * '<S522>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements1/Lower limit1'
 * '<S523>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements1/Lower limit/Compare To Constant'
 * '<S524>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements1/Lower limit1/Compare To Constant'
 * '<S525>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements2/Compare To Constant'
 * '<S526>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements2/Lower limit'
 * '<S527>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements2/Lower limit1'
 * '<S528>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements2/Lower limit/Compare To Constant'
 * '<S529>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Calculate frequency from three single-phase measurements Precalculated Use decisions/Weighting factor for single-phase frequency measurements2/Lower limit1/Compare To Constant'
 * '<S530>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/0-1 detect'
 * '<S531>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/Hold pulse high X secs'
 * '<S532>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/Latched boolean (priority off)'
 * '<S533>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/True for N secs ?2'
 * '<S534>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/True for X secs ?'
 * '<S535>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/Hold pulse high X secs/Double to UInt32 (Ceil) direct C cast no saturation checking'
 * '<S536>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/Hold pulse high X secs/Hold pulse high X samples'
 * '<S537>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/Hold pulse high X secs/Increment Real World'
 * '<S538>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/Hold pulse high X secs/Hold pulse high X samples/Compare To Zero'
 * '<S539>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/Hold pulse high X secs/Hold pulse high X samples/Decrement Real World'
 * '<S540>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/True for N secs ?2/Compare To Zero'
 * '<S541>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/True for N secs ?2/Decrement Real World'
 * '<S542>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/True for X secs ?/Compare To Zero'
 * '<S543>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/True for X secs ?/Decrement Real World'
 * '<S544>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/True for X secs ?/Double to UInt32 (Ceil) direct C cast no saturation checking'
 * '<S545>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/True for X secs ?/FALSE for initial sample'
 * '<S546>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Decide whether to activate RideThrough/True for X secs ?/Increment Real World'
 * '<S547>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Check for >pi'
 * '<S548>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Lower limit'
 * '<S549>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1'
 * '<S550>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2'
 * '<S551>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3'
 * '<S552>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Check for >pi/Compare To Constant'
 * '<S553>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Lower limit/Compare To Constant'
 * '<S554>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Integral tick-tock system clock'
 * '<S555>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Range limit'
 * '<S556>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Set up delay and interpolation'
 * '<S557>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Integral tick-tock system clock/0-1 detect'
 * '<S558>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Integral tick-tock system clock/1-0 detect'
 * '<S559>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Integral tick-tock system clock/Double to Boolean1'
 * '<S560>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Integral tick-tock system clock/Double to Boolean1/Compare To Constant'
 * '<S561>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Range limit/Compare To Constant'
 * '<S562>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Range limit/Compare To Constant1'
 * '<S563>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking'
 * '<S564>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Set up delay and interpolation/Range check Int32'
 * '<S565>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Set up delay and interpolation/int32 to double'
 * '<S566>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking/Compare To Zero2'
 * '<S567>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Set up delay and interpolation/Range check Int32/Compare To Constant'
 * '<S568>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order1/Set up delay and interpolation/Range check Int32/Compare To Constant1'
 * '<S569>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Integral tick-tock system clock'
 * '<S570>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Range limit'
 * '<S571>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Set up delay and interpolation'
 * '<S572>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Integral tick-tock system clock/0-1 detect'
 * '<S573>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Integral tick-tock system clock/1-0 detect'
 * '<S574>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Integral tick-tock system clock/Double to Boolean1'
 * '<S575>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Integral tick-tock system clock/Double to Boolean1/Compare To Constant'
 * '<S576>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Range limit/Compare To Constant'
 * '<S577>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Range limit/Compare To Constant1'
 * '<S578>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking'
 * '<S579>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Set up delay and interpolation/Range check Int32'
 * '<S580>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Set up delay and interpolation/int32 to double'
 * '<S581>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking/Compare To Zero2'
 * '<S582>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Set up delay and interpolation/Range check Int32/Compare To Constant'
 * '<S583>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order2/Set up delay and interpolation/Range check Int32/Compare To Constant1'
 * '<S584>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Integral tick-tock system clock'
 * '<S585>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Range limit'
 * '<S586>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Set up delay and interpolation'
 * '<S587>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Integral tick-tock system clock/0-1 detect'
 * '<S588>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Integral tick-tock system clock/1-0 detect'
 * '<S589>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Integral tick-tock system clock/Double to Boolean1'
 * '<S590>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Integral tick-tock system clock/Double to Boolean1/Compare To Constant'
 * '<S591>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Range limit/Compare To Constant'
 * '<S592>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Range limit/Compare To Constant1'
 * '<S593>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking'
 * '<S594>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Set up delay and interpolation/Range check Int32'
 * '<S595>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Set up delay and interpolation/int32 to double'
 * '<S596>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking/Compare To Zero2'
 * '<S597>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Set up delay and interpolation/Range check Int32/Compare To Constant'
 * '<S598>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Discrete fourier (dynamic F) part A, 1st order Outputs for 1 cycle base blocks Plus 3p5-cycle/Time period info, 1st order3/Set up delay and interpolation/Range check Int32/Compare To Constant1'
 * '<S599>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/2-point differentiator of phase change'
 * '<S600>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/2-point differentiator of phase change to frequency'
 * '<S601>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Avg//int, variable Tint, 1st order, opt3'
 * '<S602>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Compare To Constant1'
 * '<S603>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging'
 * '<S604>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Latched boolean with timed hysteresis for TRUE//FALSE'
 * '<S605>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Lowpass filter Manual implementation Specified by 5RC time'
 * '<S606>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Range limit'
 * '<S607>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/True for N secs ?1'
 * '<S608>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/True for N secs ?2'
 * '<S609>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/abs'
 * '<S610>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/2-point differentiator of phase change/Check for <-pi or >pi'
 * '<S611>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/2-point differentiator of phase change/Check for <-pi or >pi/Compare To Constant'
 * '<S612>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/2-point differentiator of phase change/Check for <-pi or >pi/Compare To Constant1'
 * '<S613>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/2-point differentiator of phase change to frequency/Check for <-pi or >pi'
 * '<S614>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/2-point differentiator of phase change to frequency/Check for <-pi or >pi/Compare To Constant'
 * '<S615>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/2-point differentiator of phase change to frequency/Check for <-pi or >pi/Compare To Constant1'
 * '<S616>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S617>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S618>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order'
 * '<S619>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S620>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S621>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S622>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt'
 * '<S623>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle'
 * '<S624>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B'
 * '<S625>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms'
 * '<S626>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle'
 * '<S627>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S628>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S629>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S630>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S631>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S632>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S633>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/2-point differentiator'
 * '<S634>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2'
 * '<S635>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3'
 * '<S636>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar'
 * '<S637>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Compare To Constant'
 * '<S638>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/abs'
 * '<S639>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S640>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S641>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order'
 * '<S642>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S643>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S644>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S645>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S646>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S647>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order'
 * '<S648>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S649>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S650>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S651>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/atan2'
 * '<S652>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/hypot'
 * '<S653>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/abs/Compare To Zero'
 * '<S654>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt'
 * '<S655>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1'
 * '<S656>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar'
 * '<S657>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S658>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S659>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S660>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S661>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S662>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S663>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S664>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S665>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order'
 * '<S666>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S667>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S668>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S669>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar/atan2'
 * '<S670>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar/hypot'
 * '<S671>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit'
 * '<S672>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit2'
 * '<S673>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Upper limit'
 * '<S674>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit/Compare To Constant'
 * '<S675>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit2/Compare To Constant'
 * '<S676>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Upper limit/Compare To Constant'
 * '<S677>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle'
 * '<S678>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt'
 * '<S679>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S680>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S681>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S682>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S683>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S684>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S685>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Latched boolean with timed hysteresis for TRUE//FALSE/False for N secs ?'
 * '<S686>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Latched boolean with timed hysteresis for TRUE//FALSE/Latched boolean (priority off)'
 * '<S687>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Latched boolean with timed hysteresis for TRUE//FALSE/True for N secs ?'
 * '<S688>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Latched boolean with timed hysteresis for TRUE//FALSE/False for N secs ?/Compare To Zero'
 * '<S689>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Latched boolean with timed hysteresis for TRUE//FALSE/False for N secs ?/Decrement Real World'
 * '<S690>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Latched boolean with timed hysteresis for TRUE//FALSE/True for N secs ?/Compare To Zero'
 * '<S691>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Latched boolean with timed hysteresis for TRUE//FALSE/True for N secs ?/Decrement Real World'
 * '<S692>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Lowpass filter Manual implementation Specified by 5RC time/Amplitude corrected lowpass filter Manual implementation'
 * '<S693>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Range limit/Compare To Constant'
 * '<S694>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/Range limit/Compare To Constant1'
 * '<S695>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/True for N secs ?1/Compare To Zero'
 * '<S696>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/True for N secs ?1/Decrement Real World'
 * '<S697>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/True for N secs ?2/Compare To Zero'
 * '<S698>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/True for N secs ?2/Decrement Real World'
 * '<S699>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core/abs/Compare To Zero'
 * '<S700>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/2-point differentiator of phase change'
 * '<S701>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/2-point differentiator of phase change to frequency'
 * '<S702>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Avg//int, variable Tint, 1st order, opt3'
 * '<S703>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Compare To Constant1'
 * '<S704>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging'
 * '<S705>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Latched boolean with timed hysteresis for TRUE//FALSE'
 * '<S706>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Lowpass filter Manual implementation Specified by 5RC time'
 * '<S707>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Range limit'
 * '<S708>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/True for N secs ?1'
 * '<S709>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/True for N secs ?2'
 * '<S710>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/abs'
 * '<S711>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/2-point differentiator of phase change/Check for <-pi or >pi'
 * '<S712>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/2-point differentiator of phase change/Check for <-pi or >pi/Compare To Constant'
 * '<S713>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/2-point differentiator of phase change/Check for <-pi or >pi/Compare To Constant1'
 * '<S714>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/2-point differentiator of phase change to frequency/Check for <-pi or >pi'
 * '<S715>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/2-point differentiator of phase change to frequency/Check for <-pi or >pi/Compare To Constant'
 * '<S716>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/2-point differentiator of phase change to frequency/Check for <-pi or >pi/Compare To Constant1'
 * '<S717>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S718>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S719>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order'
 * '<S720>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S721>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S722>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S723>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt'
 * '<S724>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle'
 * '<S725>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B'
 * '<S726>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms'
 * '<S727>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle'
 * '<S728>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S729>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S730>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S731>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S732>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S733>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S734>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/2-point differentiator'
 * '<S735>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2'
 * '<S736>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3'
 * '<S737>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar'
 * '<S738>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Compare To Constant'
 * '<S739>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/abs'
 * '<S740>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S741>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S742>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order'
 * '<S743>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S744>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S745>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S746>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S747>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S748>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order'
 * '<S749>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S750>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S751>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S752>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/atan2'
 * '<S753>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/hypot'
 * '<S754>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/abs/Compare To Zero'
 * '<S755>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt'
 * '<S756>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1'
 * '<S757>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar'
 * '<S758>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S759>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S760>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S761>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S762>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S763>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S764>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S765>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S766>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order'
 * '<S767>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S768>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S769>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S770>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar/atan2'
 * '<S771>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar/hypot'
 * '<S772>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit'
 * '<S773>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit2'
 * '<S774>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Upper limit'
 * '<S775>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit/Compare To Constant'
 * '<S776>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit2/Compare To Constant'
 * '<S777>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Upper limit/Compare To Constant'
 * '<S778>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle'
 * '<S779>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt'
 * '<S780>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S781>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S782>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S783>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S784>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S785>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S786>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Latched boolean with timed hysteresis for TRUE//FALSE/False for N secs ?'
 * '<S787>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Latched boolean with timed hysteresis for TRUE//FALSE/Latched boolean (priority off)'
 * '<S788>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Latched boolean with timed hysteresis for TRUE//FALSE/True for N secs ?'
 * '<S789>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Latched boolean with timed hysteresis for TRUE//FALSE/False for N secs ?/Compare To Zero'
 * '<S790>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Latched boolean with timed hysteresis for TRUE//FALSE/False for N secs ?/Decrement Real World'
 * '<S791>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Latched boolean with timed hysteresis for TRUE//FALSE/True for N secs ?/Compare To Zero'
 * '<S792>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Latched boolean with timed hysteresis for TRUE//FALSE/True for N secs ?/Decrement Real World'
 * '<S793>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Lowpass filter Manual implementation Specified by 5RC time/Amplitude corrected lowpass filter Manual implementation'
 * '<S794>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Range limit/Compare To Constant'
 * '<S795>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/Range limit/Compare To Constant1'
 * '<S796>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/True for N secs ?1/Compare To Zero'
 * '<S797>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/True for N secs ?1/Decrement Real World'
 * '<S798>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/True for N secs ?2/Compare To Zero'
 * '<S799>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/True for N secs ?2/Decrement Real World'
 * '<S800>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core1/abs/Compare To Zero'
 * '<S801>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/2-point differentiator of phase change'
 * '<S802>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/2-point differentiator of phase change to frequency'
 * '<S803>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Avg//int, variable Tint, 1st order, opt3'
 * '<S804>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Compare To Constant1'
 * '<S805>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging'
 * '<S806>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Latched boolean with timed hysteresis for TRUE//FALSE'
 * '<S807>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Lowpass filter Manual implementation Specified by 5RC time'
 * '<S808>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Range limit'
 * '<S809>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/True for N secs ?1'
 * '<S810>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/True for N secs ?2'
 * '<S811>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/abs'
 * '<S812>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/2-point differentiator of phase change/Check for <-pi or >pi'
 * '<S813>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/2-point differentiator of phase change/Check for <-pi or >pi/Compare To Constant'
 * '<S814>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/2-point differentiator of phase change/Check for <-pi or >pi/Compare To Constant1'
 * '<S815>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/2-point differentiator of phase change to frequency/Check for <-pi or >pi'
 * '<S816>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/2-point differentiator of phase change to frequency/Check for <-pi or >pi/Compare To Constant'
 * '<S817>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/2-point differentiator of phase change to frequency/Check for <-pi or >pi/Compare To Constant1'
 * '<S818>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S819>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S820>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order'
 * '<S821>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S822>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S823>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S824>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt'
 * '<S825>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle'
 * '<S826>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B'
 * '<S827>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms'
 * '<S828>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle'
 * '<S829>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S830>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S831>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S832>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S833>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S834>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S835>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/2-point differentiator'
 * '<S836>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2'
 * '<S837>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3'
 * '<S838>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar'
 * '<S839>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Compare To Constant'
 * '<S840>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/abs'
 * '<S841>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S842>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S843>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order'
 * '<S844>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S845>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S846>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt2/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S847>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S848>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S849>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order'
 * '<S850>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S851>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S852>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Avg//int, variable Tint, 1st order, opt3/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S853>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/atan2'
 * '<S854>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/Cart to Polar/hypot'
 * '<S855>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Discrete fourier (dynamic F) part B One cycle/abs/Compare To Zero'
 * '<S856>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt'
 * '<S857>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1'
 * '<S858>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar'
 * '<S859>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S860>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S861>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S862>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S863>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S864>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S865>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S866>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S867>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order'
 * '<S868>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S869>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S870>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S871>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar/atan2'
 * '<S872>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Further averaging of Path_A and Path_B/Cart to Polar/hypot'
 * '<S873>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit'
 * '<S874>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit2'
 * '<S875>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Upper limit'
 * '<S876>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit/Compare To Constant'
 * '<S877>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Lower limit2/Compare To Constant'
 * '<S878>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/THD from Urms and U1rms/Upper limit/Compare To Constant'
 * '<S879>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle'
 * '<S880>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt'
 * '<S881>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S882>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S883>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S884>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S885>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S886>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Discrete fourier (dynamic F) part B [1(NC)+0.5] system Path averaging/Urms No cancellation One or half cycle/RMS One or half cycle/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S887>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Latched boolean with timed hysteresis for TRUE//FALSE/False for N secs ?'
 * '<S888>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Latched boolean with timed hysteresis for TRUE//FALSE/Latched boolean (priority off)'
 * '<S889>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Latched boolean with timed hysteresis for TRUE//FALSE/True for N secs ?'
 * '<S890>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Latched boolean with timed hysteresis for TRUE//FALSE/False for N secs ?/Compare To Zero'
 * '<S891>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Latched boolean with timed hysteresis for TRUE//FALSE/False for N secs ?/Decrement Real World'
 * '<S892>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Latched boolean with timed hysteresis for TRUE//FALSE/True for N secs ?/Compare To Zero'
 * '<S893>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Latched boolean with timed hysteresis for TRUE//FALSE/True for N secs ?/Decrement Real World'
 * '<S894>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Lowpass filter Manual implementation Specified by 5RC time/Amplitude corrected lowpass filter Manual implementation'
 * '<S895>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Range limit/Compare To Constant'
 * '<S896>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/Range limit/Compare To Constant1'
 * '<S897>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/True for N secs ?1/Compare To Zero'
 * '<S898>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/True for N secs ?1/Decrement Real World'
 * '<S899>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/True for N secs ?2/Compare To Zero'
 * '<S900>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/True for N secs ?2/Decrement Real World'
 * '<S901>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/FLL hybrid single-phase core2/abs/Compare To Zero'
 * '<S902>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs'
 * '<S903>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs1'
 * '<S904>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs2'
 * '<S905>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs/Check for <-pi or >pi'
 * '<S906>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs/Check for <-pi or >pi/Compare To Constant'
 * '<S907>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs/Check for <-pi or >pi/Compare To Constant1'
 * '<S908>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs1/Check for <-pi or >pi'
 * '<S909>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs1/Check for <-pi or >pi/Compare To Constant'
 * '<S910>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs1/Check for <-pi or >pi/Compare To Constant1'
 * '<S911>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs2/Check for <-pi or >pi'
 * '<S912>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs2/Check for <-pi or >pi/Compare To Constant'
 * '<S913>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Process 3-phase Fourier results/Process Fourier outputs2/Check for <-pi or >pi/Compare To Constant1'
 * '<S914>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Compare To Constant1'
 * '<S915>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Compare To Constant10'
 * '<S916>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Compare To Constant11'
 * '<S917>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Compare To Constant2'
 * '<S918>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Compare To Constant3'
 * '<S919>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Compare To Constant4'
 * '<S920>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Compare To Constant8'
 * '<S921>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Compare To Constant9'
 * '<S922>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Double to Boolean'
 * '<S923>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Fixed signal delay'
 * '<S924>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs'
 * '<S925>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs1'
 * '<S926>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs2'
 * '<S927>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Double to Boolean/Compare To Constant'
 * '<S928>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Fixed signal delay/Fixed signal delay S-function'
 * '<S929>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs/Hold pulse high N samples'
 * '<S930>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs/Hold pulse high N samples/Compare To Zero'
 * '<S931>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs/Hold pulse high N samples/Decrement Real World'
 * '<S932>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs1/Hold pulse high N samples'
 * '<S933>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs1/Hold pulse high N samples/Compare To Zero'
 * '<S934>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs1/Hold pulse high N samples/Decrement Real World'
 * '<S935>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs2/Hold pulse high N samples'
 * '<S936>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs2/Hold pulse high N samples/Compare To Zero'
 * '<S937>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Qualify transients to detect genuine disturbances/Hold pulse high N secs2/Hold pulse high N samples/Decrement Real World'
 * '<S938>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Replacement of input with seed if outside window/1-0 detect'
 * '<S939>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Replacement of input with seed if outside window/Hold pulse high N secs'
 * '<S940>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Replacement of input with seed if outside window/Latched boolean (priority on)'
 * '<S941>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Replacement of input with seed if outside window/True for N secs ?'
 * '<S942>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Replacement of input with seed if outside window/Hold pulse high N secs/Hold pulse high N samples'
 * '<S943>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Replacement of input with seed if outside window/Hold pulse high N secs/Hold pulse high N samples/Compare To Zero'
 * '<S944>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Replacement of input with seed if outside window/Hold pulse high N secs/Hold pulse high N samples/Decrement Real World'
 * '<S945>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Replacement of input with seed if outside window/True for N secs ?/Compare To Zero'
 * '<S946>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Replacement of input with seed if outside window/True for N secs ?/Decrement Real World'
 * '<S947>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt'
 * '<S948>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1'
 * '<S949>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter'
 * '<S950>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value'
 * '<S951>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Double to Int32 (Zero) direct C cast no saturation checking'
 * '<S952>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Hold pulse high N secs'
 * '<S953>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Lower limit'
 * '<S954>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Lowpass filter Manual implementation Dynamic cutoff frequency'
 * '<S955>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order'
 * '<S956>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core'
 * '<S957>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/abs'
 * '<S958>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/int32 to double'
 * '<S959>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S960>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S961>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order'
 * '<S962>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S963>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S964>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S965>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function'
 * '<S966>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Discrete variable delay No range checks and direct feedthrough S-function1'
 * '<S967>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order'
 * '<S968>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps'
 * '<S969>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Trapezial integrator with reset to zero Multiplied by 2//Tps1'
 * '<S970>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Avg//int, variable Tint, 1st order, opt1/Integral correction, variable Tint, 1st order/Discrete variable delay, oldest two No range checks and direct feedthrough S-function'
 * '<S971>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter/Range limit'
 * '<S972>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter/Range limit/Compare To Constant'
 * '<S973>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter/Range limit/Compare To Constant1'
 * '<S974>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit'
 * '<S975>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit1'
 * '<S976>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit/Compare To Constant'
 * '<S977>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit/Compare To Constant1'
 * '<S978>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit1/Compare To Constant'
 * '<S979>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Discrete Rate Limiter with limits and reset to max value/Range limit1/Compare To Constant1'
 * '<S980>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Double to Int32 (Zero) direct C cast no saturation checking/Compare To Zero2'
 * '<S981>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Hold pulse high N secs/Hold pulse high N samples'
 * '<S982>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Hold pulse high N secs/Hold pulse high N samples/Compare To Zero'
 * '<S983>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Hold pulse high N secs/Hold pulse high N samples/Decrement Real World'
 * '<S984>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Lower limit/Compare To Constant'
 * '<S985>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Lowpass filter Manual implementation Dynamic cutoff frequency/Lowpass filter Manual implementation Dynamic cutoff frequency Part A'
 * '<S986>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Lowpass filter Manual implementation Dynamic cutoff frequency/Lowpass filter Manual implementation Dynamic cutoff frequency Part B'
 * '<S987>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Integral tick-tock system clock'
 * '<S988>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Range limit'
 * '<S989>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation'
 * '<S990>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Integral tick-tock system clock/0-1 detect'
 * '<S991>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Integral tick-tock system clock/1-0 detect'
 * '<S992>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Integral tick-tock system clock/Double to Boolean1'
 * '<S993>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Integral tick-tock system clock/Double to Boolean1/Compare To Constant'
 * '<S994>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Range limit/Compare To Constant'
 * '<S995>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Range limit/Compare To Constant1'
 * '<S996>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking'
 * '<S997>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/Range check Int32'
 * '<S998>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/int32 to double'
 * '<S999>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/Double to Int32 (Ceil) direct C cast no saturation checking/Compare To Zero2'
 * '<S1000>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/Range check Int32/Compare To Constant'
 * '<S1001>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Time period info, 1st order/Set up delay and interpolation/Range check Int32/Compare To Constant1'
 * '<S1002>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/0-1 detect'
 * '<S1003>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/1-0 or 0-1 detect'
 * '<S1004>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Compare To Constant'
 * '<S1005>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Compare To Zero'
 * '<S1006>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking'
 * '<S1007>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Lower limit'
 * '<S1008>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Lower limit1'
 * '<S1009>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Sample and hold'
 * '<S1010>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Sample and hold3'
 * '<S1011>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Time between pulses'
 * '<S1012>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/abs'
 * '<S1013>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/1-0 or 0-1 detect/FALSE for initial sample'
 * '<S1014>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Double to UInt32 (Ceil) direct C cast no saturation checking'
 * '<S1015>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Double to Uint32 saturation check'
 * '<S1016>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Hold pulse high X samples'
 * '<S1017>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Double to Uint32 saturation check/Compare To Constant'
 * '<S1018>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Double to Uint32 saturation check/Compare To Constant1'
 * '<S1019>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Hold pulse high X samples/Compare To Zero'
 * '<S1020>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Hold pulse high X secs with saturation checking/Hold pulse high X samples/Decrement Real World'
 * '<S1021>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Lower limit/Compare To Constant'
 * '<S1022>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/Lower limit1/Compare To Constant'
 * '<S1023>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/Zero crossing frequency calc, using half or full cycles, core/abs/Compare To Zero'
 * '<S1024>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Ripple remover Dynamic ripple threshold/abs/Compare To Zero'
 * '<S1025>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Signal hold with lookback/0-1 detect'
 * '<S1026>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Signal hold with lookback/Fixed signal delay'
 * '<S1027>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/Signal hold with lookback/Fixed signal delay/Fixed signal delay S-function'
 * '<S1028>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/True for N secs ?/Compare To Zero'
 * '<S1029>' : 'measure/Full nodal power flow analysis including corrections for CT,VT,ADC timing skews/Three-phase FLL hybrid Plus current measurement/Three-phase FLL hybrid/Three-phase FLL hybrid/True for N secs ?/Decrement Real World'
 */
#endif                                 /* RTW_HEADER_measure_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
