/*
 * File: inv1_genC_data.c
 *
 * Code generated for Simulink model 'inv1_genC'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Apr 23 08:05:12 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "inv1_genC.h"
#include "inv1_genC_private.h"

/* Constant parameters (auto storage) */
const ConstP_inv1_genC_T inv1_genC_ConstP = {
  /* Expression: zeros(9,1)
   * Referenced by: '<S50>/SwitchCurrents'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: S.A
   * Referenced by: '<S48>/State-Space'
   */
  { 0.99999995977474287, -1.7699113121978865E-6, 0.044247782804947171,
    -0.044247782804947171, 0.044247782804947171, -0.044247782804947171,
    0.0032180205676325237, -0.85840709502416879, -3539.8226243957765,
    3539.822624395777, -3539.822624395777, 3539.8226243957797,
    2.0112628547703246E-8, 8.8495565609893839E-7, 0.93025706120523644,
    0.022123891629230868, -0.022123891175716108, -0.025495155989816672,
    -2.011262854770326E-8, -8.8495565609894348E-7, 0.022123891629230952,
    0.93025706120523621, -0.025495155989816668, -0.022123891175716219,
    2.0112628547703256E-8, 8.8495565609894326E-7, -0.022123891175716219,
    -0.025495155989816675, 0.93025706120523621, 0.022123891629230952,
    -2.0112628547703045E-8, -8.8495565609893839E-7, -0.025495155989816779,
    -0.022123891175716111, 0.022123891629230757, 0.93025706120523644 },

  /* Expression: S.B
   * Referenced by: '<S48>/State-Space'
   */
  { -21118.259975088411, -929203.43890389, -2.676991426549799E+10,
    -2.3230086210692497E+10, 2.3230085734502014E+10, 2.676991378930751E+10,
    21118.259975088422, 929203.43890389043, -2.3230086210692505E+10,
    -2.6769914265497974E+10, 2.6769913789307495E+10, 2.3230085734502026E+10,
    -21118.259975088422, -929203.43890389043, 2.3230085734502026E+10,
    2.6769913789307503E+10, -2.6769914265497967E+10, -2.3230086210692505E+10,
    21118.259975088411, 929203.43890389, 2.6769913789307507E+10,
    2.3230085734502018E+10, -2.323008621069249E+10, -2.676991426549799E+10, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, -21118.259975088411, -929203.43890389,
    -2.676991426549799E+10, -2.3230086210692497E+10, 2.3230085734502014E+10,
    2.676991378930751E+10, 21118.259975088422, 929203.43890389043,
    -2.3230086210692505E+10, -2.6769914265497974E+10, 2.6769913789307495E+10,
    2.3230085734502026E+10, -21118.259975088422, -929203.43890389043,
    2.3230085734502026E+10, 2.6769913789307503E+10, -2.6769914265497967E+10,
    -2.3230086210692505E+10, 21118.259975088411, 929203.43890389,
    2.6769913789307507E+10, 2.3230085734502018E+10, -2.323008621069249E+10,
    -2.676991426549799E+10, -1.0625181290357943E-17, 6.9388939039072284E-18,
    -47619.047165532887, -47619.047165532887, -47619.047165532887,
    -47619.0471655329, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: S.C
   * Referenced by: '<S48>/State-Space'
   */
  { 4.6460171945194513E-7, -4.6460171945194513E-7, 4.6460171945194513E-7,
    -4.6460171945194513E-7, 0.0, 4.6460171945194513E-7, -4.6460171945194513E-7,
    4.6460171945194513E-7, -4.6460171945194513E-7, 9.9999997988737139E-7, 0.0,
    -0.037168137556155618, 0.037168137556155618, -0.037168137556155618,
    0.037168137556155618, 0.0, -0.037168137556155618, 0.037168137556155618,
    -0.037168137556155618, 0.037168137556155618, 1.6090102838162606E-9, 0.0,
    2.6769914265498226E-7, 2.3230086210692244E-7, -2.3230085734501772E-7,
    -2.6769913789307754E-7, 0.0, 2.6769914265498226E-7, 2.3230086210692244E-7,
    -2.3230085734501772E-7, -2.6769913789307754E-7, 1.0056314273851622E-14, 0.0,
    2.32300862106925E-7, 2.6769914265497972E-7, -2.67699137893075E-7,
    -2.3230085734502028E-7, 0.0, 2.32300862106925E-7, 2.6769914265497972E-7,
    -2.67699137893075E-7, -2.3230085734502028E-7, -1.005631427385163E-14, 0.0,
    -2.3230085734502023E-7, -2.6769913789307495E-7, 2.6769914265497977E-7,
    2.3230086210692493E-7, 0.0, -2.3230085734502023E-7, -2.6769913789307495E-7,
    2.6769914265497977E-7, 2.3230086210692493E-7, 1.0056314273851629E-14, 0.0,
    -2.6769913789307765E-7, -2.3230085734501766E-7, 2.3230086210692238E-7,
    2.6769914265498237E-7, 0.0, -2.6769913789307765E-7, -2.3230085734501766E-7,
    2.3230086210692238E-7, 2.6769914265498237E-7, -1.0056314273851411E-14, 0.0 },

  /* Expression: S.D
   * Referenced by: '<S48>/State-Space'
   */
  { -281084.09978772886, -243915.90521227109, 243915.90021227114,
    281084.094787729, 0.0, -281084.09978772886, -243915.90521227109,
    243915.90021227114, 281084.094787729, -0.010559129987544205, 0.0,
    -243915.9052122712, -281084.09978772874, 281084.09478772886,
    243915.90021227128, 0.0, -243915.9052122712, -281084.09978772874,
    281084.09478772886, 243915.90021227128, 0.01055912998754421, 0.0,
    243915.90021227128, 281084.09478772886, -281084.09978772874,
    -243915.9052122712, 0.0, 243915.90021227128, 281084.09478772886,
    -281084.09978772874, -243915.9052122712, -0.01055912998754421, 0.0,
    281084.094787729, 243915.90021227117, -243915.90521227109,
    -281084.09978772886, 0.0, 281084.094787729, 243915.90021227117,
    -243915.90521227109, -281084.09978772886, 0.010559129987544205, 0.0, 0.0,
    0.0, 0.0, 0.0, -1.0E+6, 0.0, 0.0, 0.0, 0.0, 1.0E+6, 0.0, -281084.09978772886,
    -243915.90521227109, 243915.90021227114, 281084.094787729, 0.0,
    -281084.09978772886, -243915.90521227109, 243915.90021227114,
    281084.094787729, -0.010559129987544205, 0.0, -243915.9052122712,
    -281084.09978772874, 281084.09478772886, 243915.90021227128, 0.0,
    -243915.9052122712, -281084.09978772874, 281084.09478772886,
    243915.90021227128, 0.01055912998754421, 0.0, 243915.90021227128,
    281084.09478772886, -281084.09978772874, -243915.9052122712, 0.0,
    243915.90021227128, 281084.09478772886, -281084.09978772874,
    -243915.9052122712, -0.01055912998754421, 0.0, 281084.094787729,
    243915.90021227117, -243915.90521227109, -281084.09978772886, 0.0,
    281084.094787729, 243915.90021227117, -243915.90521227109,
    -281084.09978772886, 0.010559129987544205, 0.0, -0.49999999523809524,
    -0.49999999523809524, -0.49999999523809524, -0.49999999523809524, 0.0,
    -0.49999999523809524, -0.49999999523809524, -0.49999999523809524,
    -0.49999999523809524, -5.3125906451789716E-24, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0 },

  /* Expression: S.x0
   * Referenced by: '<S48>/State-Space'
   */
  { -4.9811767466514273E-8, -3.4106051316484809E-12, -1.7849999991499937E+8,
    -1.7849999991499904E+8, -1.7849999991499966E+8, -1.7849999991500029E+8 },

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