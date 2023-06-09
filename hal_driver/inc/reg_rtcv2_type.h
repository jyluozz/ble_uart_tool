#ifndef REG_RTCV2_TYPE_H_
#define REG_RTCV2_TYPE_H_
#include <stdint.h>

typedef struct
{
    volatile uint32_t CTRL;
    volatile uint32_t CALIB;
    volatile uint32_t TIME;
    volatile uint32_t CAL;
    volatile uint32_t CURTIME;
    volatile uint32_t CURCAL;
    volatile uint32_t INTR;
} reg_rtc_t;

enum RTC_REG_CTRL_FIELD
{
    RTC_CTRL_RTCEN_MASK = 0x00000001,
    RTC_CTRL_RTCEN_POS = 0,
    RTC_CTRL_CALIB_MASK = 0x00000002,
    RTC_CTRL_CALIB_POS = 1,
    RTC_CTRL_ALARMEN_MASK = 0x00000004,
    RTC_CTRL_ALARMEN_POS = 2,
    RTC_CTRL_TGGL_MASK = 0x00000008,
    RTC_CTRL_TGGL_POS = 3,
    RTC_CTRL_INTRCLR_MASK = 0x00000010,
    RTC_CTRL_INTRCLR_POS = 4,
};

enum RTC_REG_CALIB_FIELD
{
    RTC_CALIB_CYC1HZ_MASK = 0x000fffff,
    RTC_CALIB_CYC1HZ_POS = 0,
    RTC_CALIB_CYC_MASK = (int)0xff000000,
    RTC_CALIB_CYC_POS = 24,
};

enum RTC_REG_TIME_FIELD
{
    RTC_TIME_SEC_MASK = 0x0000003f,
    RTC_TIME_SEC_POS = 0,
    RTC_TIME_MIN_MASK = 0x00003f00,
    RTC_TIME_MIN_POS = 8,
    RTC_TIME_HOUR_MASK = 0x001f0000,
    RTC_TIME_HOUR_POS = 16,
    RTC_TIME_DATE_MASK = 0x1f000000,
    RTC_TIME_DATE_POS = 24,
};

enum RTC_REG_CAL_FIELD
{
    RTC_CAL_WEEK_MASK = 0x00000007,
    RTC_CAL_WEEK_POS = 0,
    RTC_CAL_MON_MASK = 0x000000f0,
    RTC_CAL_MON_POS = 4,
    RTC_CAL_YEAR_MASK = 0x0000ff00,
    RTC_CAL_YEAR_POS = 8,
};

enum RTC_REG_CURTIME_FIELD
{
    RTC_CURTIME_SEC_MASK = 0x0000003f,
    RTC_CURTIME_SEC_POS = 0,
    RTC_CURTIME_MIN_MASK = 0x00003f00,
    RTC_CURTIME_MIN_POS = 8,
    RTC_CURTIME_HOUR_MASK = 0x001f0000,
    RTC_CURTIME_HOUR_POS = 16,
    RTC_CURTIME_DATE_MASK = 0x1f000000,
    RTC_CURTIME_DATE_POS = 24,
};

enum RTC_REG_CURCAL_FIELD
{
    RTC_CURCAL_WEEK_MASK = 0x00000007,
    RTC_CURCAL_WEEK_POS = 0,
    RTC_CURCAL_MON_MASK = 0x000000f0,
    RTC_CURCAL_MON_POS = 4,
    RTC_CURCAL_YEAR_MASK = 0x0000ff00,
    RTC_CURCAL_YEAR_POS = 8,
};

enum RTC_REG_INTR_FIELD
{
    RTC_INTR_MASK = 0x00000001,
    RTC_INTR_POS = 0,
};

#endif
