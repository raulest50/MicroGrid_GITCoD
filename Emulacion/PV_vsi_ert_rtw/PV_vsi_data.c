/*
 * File: PV_vsi_data.c
 *
 * Code generated for Simulink model 'PV_vsi'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Jul 31 14:14:34 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PV_vsi.h"
#include "PV_vsi_private.h"

/* Constant parameters (auto storage) */
const ConstP_PV_vsi_T PV_vsi_ConstP = {
  /* Expression: zeros(9,1)
   * Referenced by: '<S72>/SwitchCurrents'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: S.A
   * Referenced by: '<S70>/State-Space'
   */
  { 0.99999999845344889, -1.8867924495911859E-6, -5.029658049710714E-27,
    0.04716981123977964, -0.04716981123977964, 0.047169811239779647,
    -0.047169811239779626, 1.5465511881895017E-5, -0.9811320755040881,
    4.1731261903300246E-22, -471.69811239780188, 471.69811239780239,
    -471.698112397802, 471.69811239779642, -9.1975081335401476E-25,
    -4.8405539667794866E-22, 0.98019801886836466, -0.047147571877818206,
    -0.047147571877818227, -0.047147571877818206, -0.047147571877818227,
    7.7327559409476059E-10, 9.4339622479559063E-7, -4.7147571877818224E-10,
    0.92879604677228833, 0.023584905631115458, -0.023584905608664157,
    -0.024034141987932068, -7.7327559409474787E-10, -9.4339622479559306E-7,
    -4.7147571877818214E-10, 0.023584905631115434, 0.92879604677228811,
    -0.024034141987932189, -0.023584905608664202, 7.7327559409474787E-10,
    9.4339622479559306E-7, -4.7147571877818224E-10, -0.023584905608664209,
    -0.024034141987932189, 0.92879604677228844, 0.023584905631115427,
    -7.7327559409474012E-10, -9.4339622479557919E-7, -4.7147571877818214E-10,
    -0.024034141987932408, -0.023584905608663834, 0.023584905631115129,
    0.92879604677228844 },

  /* Expression: S.B
   * Referenced by: '<S70>/State-Space'
   */
  { -811.93937379948557, -990566.036035372, 495.04950471709122,
    -2.52358491109026E+10, -2.4764150912671188E+10, 2.4764150889097408E+10,
    2.5235849087328808E+10, 811.93937379948534, 990566.03603537276,
    495.04950471709122, -2.4764150912671204E+10, -2.523584911090258E+10,
    2.52358490873288E+10, 2.4764150889097416E+10, -811.93937379948534,
    -990566.03603537276, 495.04950471709122, 2.476415088909742E+10,
    2.5235849087328796E+10, -2.5235849110902584E+10, -2.47641509126712E+10,
    811.93937379948557, 990566.036035372, 495.04950471709122,
    2.5235849087328815E+10, 2.4764150889097404E+10, -2.4764150912671192E+10,
    -2.5235849110902592E+10, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -811.93937379948557, -990566.036035372, 495.04950471709122,
    -2.52358491109026E+10, -2.4764150912671188E+10, 2.4764150889097408E+10,
    2.5235849087328808E+10, 811.93937379948534, 990566.03603537276,
    495.04950471709122, -2.4764150912671204E+10, -2.523584911090258E+10,
    2.52358490873288E+10, 2.4764150889097416E+10, -811.93937379948534,
    -990566.03603537276, 495.04950471709122, 2.476415088909742E+10,
    2.5235849087328796E+10, -2.5235849110902584E+10, -2.47641509126712E+10,
    811.93937379948557, 990566.036035372, 495.04950471709122,
    2.5235849087328815E+10, 2.4764150889097404E+10, -2.4764150912671192E+10,
    -2.5235849110902592E+10, -7.6927302340056582E-21, -3.5980694269229244E-18,
    19801.98018868365, -471.47571877818206, -471.47571877818228,
    -471.47571877818206, -471.47571877818228, -3.8463651170028289E-22,
    -1.7990347134614624E-19, 990.09900943418245, -23.573785938909104,
    -23.573785938909115, -23.573785938909104, -23.573785938909115, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: S.C
   * Referenced by: '<S70>/State-Space'
   */
  { 4.9528301801768622E-7, -4.9528301801768622E-7, 4.9528301801768622E-7,
    -4.9528301801768622E-7, 0.0, 4.9528301801768622E-7, -4.9528301801768622E-7,
    4.9528301801768622E-7, -4.9528301801768622E-7, 9.9999999922672431E-7,
    5.0296580497107132E-32, 0.0, -9.43396224795593E-13, -0.004952830180176864,
    0.004952830180176864, -0.004952830180176864, 0.004952830180176864, 0.0,
    -0.004952830180176864, 0.004952830180176864, -0.004952830180176864,
    0.004952830180176864, 7.7327559409474791E-12, -5.0296580497107147E-28, 0.0,
    9.43396224795593E-9, -4.95049504717091E-7, -4.9504950471709124E-7,
    -4.9504950471709113E-7, -4.9504950471709135E-7, 0.0, -4.95049504717091E-7,
    -4.9504950471709124E-7, -4.9504950471709113E-7, -4.9504950471709135E-7,
    -3.8463651170028288E-31, -1.980198018868365E-5, 0.0, -1.7990347134614623E-28,
    2.5235849110902674E-7, 2.4764150912671108E-7, -2.4764150889097323E-7,
    -2.5235849087328884E-7, 0.0, 2.5235849110902674E-7, 2.4764150912671108E-7,
    -2.4764150889097323E-7, -2.5235849087328884E-7, 3.8663779704738722E-16,
    4.7147571877818232E-15, 0.0, 4.7169811239779455E-13, 2.4764150912671209E-7,
    2.5235849110902574E-7, -2.5235849087328789E-7, -2.4764150889097424E-7, 0.0,
    2.4764150912671209E-7, 2.5235849110902574E-7, -2.5235849087328789E-7,
    -2.4764150889097424E-7, -3.8663779704737396E-16, 4.7147571877818224E-15, 0.0,
    -4.7169811239779646E-13, -2.4764150889097424E-7, -2.52358490873288E-7,
    2.5235849110902584E-7, 2.4764150912671214E-7, 0.0, -2.4764150889097424E-7,
    -2.52358490873288E-7, 2.5235849110902584E-7, 2.4764150912671214E-7,
    3.8663779704737396E-16, 4.7147571877818232E-15, 0.0, 4.7169811239779656E-13,
    -2.523584908732952E-7, -2.4764150889096683E-7, 2.4764150912670467E-7,
    2.5235849110903304E-7, 0.0, -2.523584908732952E-7, -2.4764150889096683E-7,
    2.4764150912670467E-7, 2.5235849110903304E-7, -3.8663779704736562E-16,
    4.7147571877818224E-15, 0.0, -4.7169811239778233E-13 },

  /* Expression: S.D
   * Referenced by: '<S70>/State-Space'
   */
  { -264976.41566447727, -260023.58458304754, 260023.58433552276,
    264976.41541695246, 0.0, -264976.41566447727, -260023.58458304754,
    260023.58433552276, 264976.41541695246, -0.00040596968689974276,
    -0.0049504950471709122, 0.0, -0.49528301801768593, -260023.58458304775,
    -264976.41566447704, 264976.41541695222, 260023.58433552296, 0.0,
    -260023.58458304775, -264976.41566447704, 264976.41541695222,
    260023.58433552296, 0.00040596968689974265, -0.0049504950471709122, 0.0,
    0.49528301801768637, 260023.58433552296, 264976.41541695228,
    -264976.41566447704, -260023.58458304775, 0.0, 260023.58433552296,
    264976.41541695228, -264976.41566447704, -260023.58458304775,
    -0.00040596968689974265, -0.0049504950471709122, 0.0, -0.49528301801768637,
    264976.41541695246, 260023.58433552276, -260023.58458304754,
    -264976.41566447727, 0.0, 264976.41541695246, 260023.58433552276,
    -260023.58458304754, -264976.41566447727, 0.00040596968689974276,
    -0.0049504950471709122, 0.0, 0.49528301801768593, 0.0, 0.0, 0.0, 0.0,
    -1.0E+6, 0.0, 0.0, 0.0, 0.0, 1.0E+6, 0.0, 0.0, 0.0, -264976.41566447727,
    -260023.58458304754, 260023.58433552276, 264976.41541695246, 0.0,
    -264976.41566447727, -260023.58458304754, 260023.58433552276,
    264976.41541695246, -0.00040596968689974276, -0.0049504950471709122, 0.0,
    -0.49528301801768593, -260023.58458304775, -264976.41566447704,
    264976.41541695222, 260023.58433552296, 0.0, -260023.58458304775,
    -264976.41566447704, 264976.41541695222, 260023.58433552296,
    0.00040596968689974265, -0.0049504950471709122, 0.0, 0.49528301801768637,
    260023.58433552296, 264976.41541695228, -264976.41566447704,
    -260023.58458304775, 0.0, 260023.58433552296, 264976.41541695228,
    -264976.41566447704, -260023.58458304775, -0.00040596968689974265,
    -0.0049504950471709122, 0.0, -0.49528301801768637, 264976.41541695246,
    260023.58433552276, -260023.58458304754, -264976.41566447727, 0.0,
    264976.41541695246, 260023.58433552276, -260023.58458304754,
    -264976.41566447727, 0.00040596968689974276, -0.0049504950471709122, 0.0,
    0.49528301801768593, -0.0049504950471709105, -0.0049504950471709131,
    -0.0049504950471709113, -0.0049504950471709131, 0.0, -0.0049504950471709105,
    -0.0049504950471709131, -0.0049504950471709113, -0.0049504950471709131,
    -3.8463651170028288E-27, 19.801980198113164, 0.0, -1.7990347134614621E-24,
    -0.00024752475235854552, -0.00024752475235854563, -0.00024752475235854552,
    -0.00024752475235854563, 0.0, -0.00024752475235854552,
    -0.00024752475235854563, -0.00024752475235854552, -0.00024752475235854563,
    -1.9231825585014143E-28, -0.0099009900943418244, 0.0,
    -8.9951735673073121E-26, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: S.x0
   * Referenced by: '<S70>/State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: tv
   * Referenced by: '<S16>/Look-Up Table'
   */
  { -1.0, 0.0, 1.0E+6, 1.0E+6, 1.000001E+6 },

  /* Expression: opv
   * Referenced by: '<S16>/Look-Up Table'
   */
  { 1.0, 1.0, 1.0, 0.0, 0.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */