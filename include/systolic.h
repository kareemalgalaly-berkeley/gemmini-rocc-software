// See LICENSE for license details.

#ifndef SRC_MAIN_C_SYSTOLIC_H
#define SRC_MAIN_C_SYSTOLIC_H

#include "rocc-software/src/xcustom.h"

#define k_MVIN 2
#define k_MVOUT 3
#define k_COMPUTE_PRELOADED 4
#define k_COMPUTE_ACCUMULATE 5
#define k_PRELOAD 8
#define k_SETMODE 9

#define XCUSTOM_ACC 3

#define ROCC_INSTRUCTION_RS1_RS2(x, rs1, rs2, funct) \
  ROCC_INSTRUCTION_0_R_R(x, rs1, rs2, funct, 10, 11)

#define matmul_mvin(dram_addr, spad_addr)                        \
  ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_ACC, dram_addr, spad_addr, k_MVIN);
#define matmul_mvout(dram_addr, spad_addr)                              \
  ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_ACC, dram_addr, spad_addr, k_MVOUT);

#define matmul_compute_preloaded(A, B)                              \
  ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_ACC, A, B, k_COMPUTE_PRELOADED);

#define matmul_preload(rd, C, D)                              \
  ROCC_INSTRUCTION(XCUSTOM_ACC, rd, C, D, k_PRELOAD);
#define matmul_preload_no_rd(C, D)                              \
  ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_ACC, C, D, k_PRELOAD);
#define matmul_setmode(mode)                              \
  ROCC_INSTRUCTION_RS1_RS2(XCUSTOM_ACC, mode, 0, k_SETMODE);

#endif  // SRC_MAIN_C_SYSTOLIC_H
