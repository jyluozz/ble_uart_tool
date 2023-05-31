#ifndef REG_COMP_TYPE_H_
#define REG_COMP_TYPE_H_
#include <stdint.h>

typedef struct
{
    volatile uint32_t COMP_CTRL;
} reg_comp_t;

enum COMP_REG_STAT_FIELD
{
    COMP_STAT_COMP1_RINTR_MASK = 0x1,
    COMP_STAT_COMP1_RINTR_POS = 0,
    COMP_STAT_COMP1_FINTR_MASK = 0x2,
    COMP_STAT_COMP1_FINTR_POS = 1,
    COMP_STAT_COMP2_RINTR_MASK = 0x4,
    COMP_STAT_COMP2_RINTR_POS = 2,
    COMP_STAT_COMP2_FINTR_MASK = 0x8,
    COMP_STAT_COMP2_FINTR_POS = 3,
    COMP_STAT_COMP3_RINTR_MASK = 0x10,
    COMP_STAT_COMP3_RINTR_POS = 4,
    COMP_STAT_COMP3_FINTR_MASK = 0x20,
    COMP_STAT_COMP3_FINTR_POS = 5,
    COMP_STAT_COMP1_OUT_MASK = 0x100,
    COMP_STAT_COMP1_OUT_POS = 8,
    COMP_STAT_COMP2_OUT_MASK = 0x200,
    COMP_STAT_COMP2_OUT_POS = 9,
    COMP_STAT_COMP3_OUT_MASK = 0x400,
    COMP_STAT_COMP3_OUT_POS = 10,
};

enum COMP_REG_CTRL_FIELD
{
    COMP_CTRL_EN_MASK = 0x1,
    COMP_CTRL_EN_POS = 0,
    COMP_CTRL_MODE_MASK = 0xe,
    COMP_CTRL_MODE_POS = 1,
    COMP_CTRL_HYS_MASK = 0x30,
    COMP_CTRL_HYS_POS = 4,
    COMP_CTRL_VREFCTL_MASK = 0xc0,
    COMP_CTRL_VREFCTL_POS = 6,
    COMP_CTRL_VREFSEL_MASK = 0x700,
    COMP_CTRL_VREFSEL_POS = 8,
    COMP_CTRL_IOVIPSEL_MASK = 0x1800,
    COMP_CTRL_IOVIPSEL_POS = 11,
    COMP_FLT_PRD_MASK = (int)0x30000,
    COMP_FLT_PRD_POS = 16,
    COMP_FLT_BYP_MASK = (int)0x40000,
    COMP_FLT_BYP_POS = 18,
    COMP_INTR_REN_MASK = (int)0x80000,
    COMP_INTR_REN_POS = 19,
    COMP_INTR_FEN_MASK = (int)0x100000,
    COMP_INTR_FEN_POS = 20,
    COMP_INTR_CLR_MASK = (int)0x600000,
    COMP_INTR_CLR_POS = 21,
};

#endif