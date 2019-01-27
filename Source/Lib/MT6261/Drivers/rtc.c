// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "rtc.h"

static const uint8_t DayInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static void UpdateRTCContext(void)
{
    RTC_WRTGR = WRTGR;
    while(RTC_BBPU & CBUSY);
}

static void RTC_Unprotect(void)
{
    RTC_PROT = PROT1;
    UpdateRTCContext();
    RTC_PROT = PROT2;
    UpdateRTCContext();
}

static void RTC_SetPowerkey(void)
{
    RTC_POWERKEY1 = POWERKEY1;
    RTC_POWERKEY2 = POWERKEY2;
    UpdateRTCContext();
}

static void RTC_SetOSC32CON(uint16_t Data)
{
    RTC_OSC32CON = OSC32KEY1;
    while(RTC_BBPU & CBUSY);
    RTC_OSC32CON = OSC32KEY2;
    while(RTC_BBPU & CBUSY);
    RTC_OSC32CON = Data;
    while(RTC_BBPU & CBUSY);
    UpdateRTCContext();
}

static uint8_t RTC_DayOfWeek(pDATE Date)
{
    uint32_t a, y, m, dow;

    a = (14 - Date->Month) / 12;
    y = Date->Year - a;
    m = Date->Month + 12 * a - 2;
    dow = (7000 + (Date->Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;

    return (!dow) ? 7 : dow;
}

boolean RTC_Initialize(void)
{
    TDATETIME DateTime;

    if (RTC_OSC32CON != 0x042F) RTC_SetOSC32CON(0x042F);                                            //Set OSC32CON default value
    RTC_Unprotect();
    RTC_SetPowerkey();

    if (!RTC_IsValidState())
    {
//Initial configure RTC
        DebugPrint("settings invalid - ");
        RTC_CON = LPEN(1) | LPSTA_RAW;
        UpdateRTCContext();                                                                         //Enable Low Power Detection
        RTC_CON = LPEN(1) | LPRST; //-V525
        UpdateRTCContext();
        RTC_CON = LPEN(1);
        UpdateRTCContext();

        RTC_IRQ_EN  = 0;                                                                            //Disable IRQ
        UpdateRTCContext();
        RTC_IRQ_STA = RTC_IRQ_STA;                                                                  //Clear interrupts

        memset(&DateTime, 0x00, sizeof(DateTime));                                                  //Set default Date/Time values
        DateTime.Date.Day = 1;
        DateTime.Date.Month = 1;
        DateTime.Date.Year = RTC_INITIAL_YEAR;
        DateTime.Date.DoW = RTC_DayOfWeek(&DateTime.Date);
        RTC_SetTime(&DateTime.Time);
        RTC_SetDate(&DateTime.Date);
        RTC_SetAlarmDateTime(&DateTime, false);

        RTC_AL_MASK = YEA_MSK | MTH_MSK | DOM_MSK | DOW_MSK | HOU_MSK | MIN_MSK | SEC_MSK;          //Disable Alarm
        UpdateRTCContext();
        DebugPrint("reconfigured!\r\n");
        return true;
    }
    DebugPrint("Complete.\r\n");
    return true;
}

boolean RTC_LockBBPower(void)
{
    RTC_BBPU = KEY_BBPU | AUTO | ((RTC_BBPU | BBPU) & 0xFF);
    UpdateRTCContext();
    return (RTC_BBPU & BBPU) ? true : false;
}

boolean RTC_UnlockBBPower(void)
{
    RTC_BBPU = KEY_BBPU | ((RTC_BBPU & ~BBPU) & 0xFF);
    UpdateRTCContext();
    return (RTC_BBPU & BBPU) ? false : true;
}

boolean RTC_EnablePowerUp(void)
{
    RTC_BBPU = KEY_BBPU | ((RTC_BBPU | PWREN) & 0xFF);
    UpdateRTCContext();
    return (RTC_BBPU & PWREN) ? true : false;
}

boolean RTC_DisablePowerUp(void)
{
    RTC_BBPU = KEY_BBPU | ((RTC_BBPU & ~PWREN) & 0xFF);
    UpdateRTCContext();
    return (RTC_BBPU & PWREN) ? false : true;
}

boolean RTC_IsValidState(void)
{
    return (RTC_CON & VBAT_LPSTA_RAW) ? false : true;
}

boolean RTC_IsAlarmActive(void)
{
    uint16_t AlmSTA;

    if (!RTC_IsValidState()) return false;

    AlmSTA = RTC_IRQ_EN & RTC_IRQ_STA;

    return ((RTC_BBPU & PWREN) && (AlmSTA & ALSTA)) ? true : false;
}

TDATETIME RTC_GetDateTime(void)
{
    TDATETIME DateTime;

    DateTime.Time.Sec   = RTC_TC_SEC;
    DateTime.Time.Min   = RTC_TC_MIN;
    DateTime.Time.Hour  = RTC_TC_HOU;

    DateTime.Date.Day   = RTC_TC_DOM;
    DateTime.Date.DoW   = RTC_TC_DOW;
    DateTime.Date.Month = RTC_TC_MTH;
    DateTime.Date.Year  = RTC_TC_YEA + RTC_INITIAL_YEAR;

    return DateTime;
}

boolean RTC_SetTime(pTIME Time)
{
    if (Time == NULL) return false;

    if ((Time->Hour < 24) &&
            (Time->Min  < 60) &&
            (Time->Sec  < 60))
    {
        RTC_TC_HOU = Time->Hour;
        RTC_TC_MIN = Time->Min;
        RTC_TC_SEC = Time->Sec;

        UpdateRTCContext();
        return true;
    }
    return false;
}

boolean RTC_SetDate(pDATE Date)
{
    uint8_t leap;

    if (Date == NULL) return false;
    if (Date->Year > (RTC_INITIAL_YEAR + 127)) return false;
    if (!Date->Month || (Date->Month > 12)) return false;

    leap = (!(Date->Year % 4) &&
            ((Date->Year % 100) || !(Date->Year % 400)) &&
            (Date->Month == 2)) ? 1 : 0;

    if (Date->Day && (Date->Day <= DayInMonth[Date->Month] + leap))
    {
        RTC_TC_YEA = Date->Year - RTC_INITIAL_YEAR;
        RTC_TC_MTH = Date->Month;
        RTC_TC_DOW = RTC_DayOfWeek(Date);
        RTC_TC_DOM = Date->Day;

        UpdateRTCContext();
        return true;
    }

    return false;
}

TDATETIME RTC_GetAlarmDateTime(void)
{
    TDATETIME DateTime;

    DateTime.Time.Sec   = RTC_AL_SEC;
    DateTime.Time.Min   = RTC_AL_MIN;
    DateTime.Time.Hour  = RTC_AL_HOU;

    DateTime.Date.Day   = RTC_AL_DOM;
    DateTime.Date.DoW   = RTC_AL_DOW;
    DateTime.Date.Month = RTC_AL_MTH;
    DateTime.Date.Year  = RTC_AL_YEA + RTC_INITIAL_YEAR;

    return DateTime;
}

boolean RTC_SetAlarmDateTime(pDATETIME DateTime, boolean UseInterrupt)
{
    uint8_t leap;

    if (DateTime == NULL) return false;

    if ((DateTime->Time.Hour < 24) &&
            (DateTime->Time.Min  < 60) &&
            (DateTime->Time.Sec  < 60))
    {

        if (DateTime->Date.Year > (RTC_INITIAL_YEAR + 127)) return false;
        if (!DateTime->Date.Month || (DateTime->Date.Month > 12)) return false;

        leap = (!(DateTime->Date.Year % 4) &&
                ((DateTime->Date.Year % 100) || !(DateTime->Date.Year % 400)) &&
                (DateTime->Date.Month == 2)) ? 1 : 0;

        if (DateTime->Date.Day && (DateTime->Date.Day <= DayInMonth[DateTime->Date.Month] + leap))
        {
            RTC_AL_HOU = DateTime->Time.Hour;
            RTC_AL_MIN = DateTime->Time.Min;
            RTC_AL_SEC = DateTime->Time.Sec;

            RTC_AL_YEA = DateTime->Date.Year - RTC_INITIAL_YEAR;
            RTC_AL_MTH = DateTime->Date.Month;
            RTC_AL_DOW = RTC_DayOfWeek(&DateTime->Date);
            RTC_AL_DOM = DateTime->Date.Day;

            RTC_IRQ_EN = (UseInterrupt) ? RTC_IRQ_EN | AL_EN : RTC_IRQ_EN & ~AL_EN;
            RTC_AL_MASK = ~(YEA_MSK | MTH_MSK | DOM_MSK | HOU_MSK | MIN_MSK | SEC_MSK) & 0xFF;

            UpdateRTCContext();
            return true;
        }
    }
    return false;
}

void RTC_Sleep(void)
{
}

void RTC_Resume(void)
{
}
