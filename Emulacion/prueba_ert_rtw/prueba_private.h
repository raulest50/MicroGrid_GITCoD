/*
 * File: prueba_private.h
 *
 * Code generated for Simulink model 'prueba'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Thu Jul 05 11:00:52 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_prueba_private_h_
#define RTW_HEADER_prueba_private_h_
#include "rtwtypes.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern void qp_linprog(SimStruct *rts);
extern void qpOASES_SQProblem(SimStruct *rts);

#endif                                 /* RTW_HEADER_prueba_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
