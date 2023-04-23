/*
 * @Description: 
 * @Version: 2.0
 * @Author: lkc
 * @Date: 2022-11-28 19:28:50
 * @LastEditors: lkc
 * @LastEditTime: 2023-04-23 21:01:59
 */
#ifndef _BSP_USART_H
#define _BSP_USART_H

/* Includes ------------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* 使用的基本外设串口 */
#define EVAL_COM1                        USART1
#define EVAL_COM1_CLK                    RCC_APB2Periph_USART1 
#define EVAL_COM1_TX_PIN                 GPIO_Pin_9
#define EVAL_COM1_TX_GPIO_PORT           GPIOA
#define EVAL_COM1_TX_GPIO_CLK            RCC_AHB1Periph_GPIOA
#define EVAL_COM1_TX_SOURCE              GPIO_PinSource9
#define EVAL_COM1_TX_AF                  GPIO_AF_USART1

#define EVAL_COM1_RX_PIN                 GPIO_Pin_10
#define EVAL_COM1_RX_GPIO_PORT           GPIOA
#define EVAL_COM1_RX_GPIO_CLK            RCC_AHB1Periph_GPIOA
#define EVAL_COM1_RX_SOURCE              GPIO_PinSource10
#define EVAL_COM1_RX_AF                  GPIO_AF_USART1
#define EVAL_COM1_IRQn                   USART1_IRQn
    
/* 可以使用systick 时钟来计算时间 看门狗防止程序跑飞 */
VOID    Bsp_Uart_Init(ULONG ulBound);
VOID    Bsp_PutChar(UCHAR c);
ULONG   Bsp_GetChar(UCHAR* key);
VOID    Bsp_HardWareInit(void);

#endif
