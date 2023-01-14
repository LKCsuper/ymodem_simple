/*
 * @Description: 
 * @Version: 2.0
 * @Author: lkc
 * @Date: 2022-11-28 19:28:49
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-01-14 17:44:57
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __YMODEM_CONFIG_H_
#define __YMODEM_CONFIG_H_
#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
typedef void (*pFunction)(void);
/* 延时时间,用于不停的发c */
#define     YMODEM_DELAY_MS               (500)
#define     YMODEM_SLEEP_MS(ms)           Ymodem_Delay(ms)
/* ymodem 发送c的次数 */
#define     YMODEM_C_NUM                  (6)
/* 超时时间，while循环 */
#define     YMODEM_TIMEOUT                (0x100000)
/* ymodem打印 */
#define     YMODEM_DEBUG                  (1)
#define     YMODEM_FLAG                   (1)

#define     APPLICATION_SIZE            YMODEM_UPDATE_APP_SIZE
#define     APPLICATION_ADDRESS         APP_BAK_START_ADDR
#define     APPLICATION_END_ADDRESS     APP_BAK_END_ADDR

/* flash分区 boot app appbak data */
#if YMODEM_DEBUG
#define DEBUG(format, ...) printf(format, ##__VA_ARGS__)
#define YMODEM_WARNING(format, ...) WARNING(format, ##__VA_ARGS__)
#else
#define DEBUG(format, ...)
#endif

/* Compiler Related Definitions */
#ifdef __CC_ARM /* ARM Compiler */
#define WEAK __weak
#elif defined(__IAR_SYSTEMS_ICC__) /* for IAR Compiler */
#define WEAK __weak
#elif defined(__GNUC__) /* GNU GCC Compiler */
#define WEAK __attribute__((weak))
#elif defined(__ADSPBLACKFIN__) /* for VisualDSP++ Compiler */
#define WEAK __attribute__((weak))
#elif defined(_MSC_VER)
#define WEAK
#elif defined(__TI_COMPILER_VERSION__)
#define WEAK
#else
#error not supported tool chain
#endif

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void Ymodem_Info(void);
void Ymodem_Jump_App(void);

#ifdef __cplusplus
};
#endif
#endif  /* __YMODEM_H_ */
/*******************(C)COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
