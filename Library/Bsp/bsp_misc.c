/*
 * @Description:
 * @Version: 2.0
 * @Author: lkc
 * @Date: 2022-11-28 19:28:49
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-01-14 18:16:22
 */
#ifdef __cplusplus
extern "C"
{
#endif
/* Includes ------------------------------------------------------------------*/
#include "includes.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define  SYS_CLOCK           SystemCoreClock

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
volatile uint32_t time_delay; // 延时时间，注意定义为全局变量

/**
 * @description: 延时毫秒
 * @event: 
 * @param {volatile unsigned long} nms
 * @return {*}
 */
void Bsp_Delay_MS(volatile uint32_t nms)
{
    // SYSTICK分频--1ms的系统时钟中断
    if (SysTick_Config(SYS_CLOCK / 1000))
    {
        while (1);
    }
    time_delay = nms; // 读取定时时间
    while (time_delay);
    SysTick->CTRL = 0x00; // 关闭计数器
    SysTick->VAL = 0X00;  // 清空计数器
}

/**
 * @description: 延时us
 * @detail description: 
 * @param {volatile uint32_t} nus
 * @return {*}
 */
void Bsp_Delay_US(volatile uint32_t nus)
{
    // SYSTICK分频--1us的系统时钟中断
    if (SysTick_Config(SYS_CLOCK / 1000000))
    {
        while (1);
    }
    time_delay = nus; // 读取定时时间
    while (time_delay) ;
    SysTick->CTRL = 0x00; // 关闭计数器
    SysTick->VAL = 0X00;  // 清空计数器
}

/**
 * @description: sys中断
 * @detail description: 实现变量递减
 * @return {*}
 */
void SysTick_Handler(void)
{
    if (time_delay)
        time_delay--;
}

/**
 * @description: ymodem 延时
 * @detail description: 
 * @param {unsigned int} ms
 * @return {*}
 */
void Ymodem_Delay(unsigned int ms)
{
    Bsp_Delay_MS(ms);
}

/**
 * @description: 看门狗初始化
 * @detail description: 
 * @return {*}
 */
void Bsp_Misc_Iwdg(UCHAR prv ,USHORT rlv)
{
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
    IWDG_SetPrescaler(prv);
    IWDG_SetReload(rlv);
    IWDG_ReloadCounter();
    IWDG_Enable(); 

    return;
}

#ifdef __cplusplus
};
#endif
