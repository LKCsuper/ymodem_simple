/*
 * @Description: 
 * @Version: 2.0
 * @Author: lkc
 * @Date: 2022-11-28 19:28:49
 * @LastEditors: lkc
 * @LastEditTime: 2023-04-23 21:58:09
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
/* flash分区 boot app appbak data */
#define     APPLICATION_SIZE            0
#define     APPLICATION_ADDRESS         0
#define     APPLICATION_END_ADDRESS     0
#define     YMODEM_SLEEP_MS(ms)         do{}while(0);

// #define     APPLICATION_SIZE            APP_BAK_SIZE
// #define     APPLICATION_ADDRESS         APP_BAK_START_ADDR
// #define     APPLICATION_END_ADDRESS     APP_BAK_END_ADDR
// #define     YMODEM_SLEEP_MS(ms)           Bsp_Delay_MS(ms)

typedef void (*pFunction)(void);
/* 延时时间,用于不停的发c */
#define     YMODEM_DELAY_MS                 (500)
/* ymodem 发送c的次数 */
#define     YMODEM_C_NUM                    (6)
/* 超时时间，while循环 */
#define     YMODEM_TIMEOUT                  (0x100000)
/* ymodem打印 */
#define     YMODEM_DEBUG                    (0)
/* flash升级标志 */
#define     YMODEM_FLAG                     (1)
/* 文件名字字符串长度 */
#define     FILE_NAME_LENGTH                (32)
/* 文件大小字符串长度 */
#define     FILE_SIZE_LENGTH                (16)

/* 调试打印 */
#if YMODEM_DEBUG
#define YMODEM_PRINTF(format, ...)          printf(format, ##__VA_ARGS__)
#define YMODEM_WARNING(format, ...)         WARNING(format, ##__VA_ARGS__)
#else
#define YMODEM_PRINTF(format, ...)
#define YMODEM_WARNING(format, ...)
#endif

/* 弱定义 */
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
WEAK void Ymodem_Uart_Init(uint32_t ulBound)
WEAK uint32_t Ymodem_GetChar(uint8_t *key);
WEAK void Ymodem_PutChar(uint8_t c);
WEAK void Ymodem_Flash_Set_Flag(bool isSet);
WEAK uint32_t Ymodem_Flash_Get_Flag(void);
WEAK void Ymodem_Flash_Init(void);
WEAK void Ymodem_Flash_Erase_App(void);
WEAK uint32_t Ymodem_Flash_Write(uint32_t *Data, uint32_t DataLength);


#ifdef __cplusplus
};
#endif
#endif  /* __YMODEM_H_ */
/*******************(C)COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
