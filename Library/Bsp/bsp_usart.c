#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "includes.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
 * @description: 重定向怕【rintf
 * @detail description: 
 * @param {int} ch
 * @param {FILE} *p
 * @return {*}
 */
int fputc(int ch, FILE *p)
{
	USART_SendData(USART1, (u8)ch);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);

	return ch;
}

 /**
 * @brief		ymodem串口初始化
 * @details	    This is the detail description.
 * @param[in]	ulBound 波特率
 * @param[out]	None
 * @retval		None
 * @par  time 2022/8/5
 * @par  name Ymodem_UartInit
 */
VOID Ymodem_Uart_Init(ULONG ulBound)
{
	RCC_AHB1PeriphClockCmd(EVAL_COM1_TX_GPIO_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd(EVAL_COM1_RX_GPIO_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(EVAL_COM1_CLK, ENABLE);

	GPIO_PinAFConfig(EVAL_COM1_TX_GPIO_PORT, EVAL_COM1_TX_SOURCE, EVAL_COM1_TX_AF);
	GPIO_PinAFConfig(EVAL_COM1_RX_GPIO_PORT, EVAL_COM1_RX_SOURCE, EVAL_COM1_RX_AF);

	USART_InitTypeDef USART_InitStructure;

	USART_InitStructure.USART_BaudRate = ulBound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; 
	USART_Init(EVAL_COM1, &USART_InitStructure); 
	
	USART_Cmd(EVAL_COM1, ENABLE);

	USART_ClearFlag(EVAL_COM1, USART_FLAG_TC);

	/* 清空发送缓冲区 */
	while (USART_GetFlagStatus(EVAL_COM1, USART_FLAG_TC) == RESET)
	{
		USART_ReceiveData(EVAL_COM1);
	}

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = EVAL_COM1_TX_PIN | EVAL_COM1_RX_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(EVAL_COM1_TX_GPIO_PORT, &GPIO_InitStructure);

	return;
}

/**
  * @brief  输出到终端一个字符
  * @param  c: 输出字符
  * @retval None
  */
VOID Ymodem_PutChar(UCHAR c)
{
	USART_SendData(EVAL_COM1, c);
	while (USART_GetFlagStatus(EVAL_COM1, USART_FLAG_TXE) == RESET)
	{

	}

	return;
}

/**
  * @brief  Test to see if a key has been pressed on the HyperTerminal
  * @param  key: The key pressed
  * @retval 1: Correct
  *         0: Error
  */
ULONG Ymodem_GetChar(UCHAR* key)
{
	/* 当存在数据的时候 */
	if (USART_GetFlagStatus(EVAL_COM1, USART_FLAG_RXNE) != RESET)
	{
		/* 取出数据 */
		*key = (UCHAR)EVAL_COM1->DR;
		return 1;
	}
	else
	{
		return 0;
	}
}

#ifdef __cplusplus
};
#endif
