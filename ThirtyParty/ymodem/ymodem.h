/*
 * @Description: 
 * @Date: 2022-11-28 19:28:49
 * @LastEditTime: 2023-01-08 23:11:13
 * @FilePath: \YMODEM\ThirtyParty\ymodem\ymodem.h
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __YMODEM_H_
#define __YMODEM_H_

#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
typedef enum tagYmodemFlag
{
	YMODEM_RESET = 0,
	YMODEM_SET = !YMODEM_RESET
}
YMODEM_FLAG_E;

typedef enum tagYmodemState
{
	YMODEM_DISABLE = 0,
	YMODEM_ENABLE = !YMODEM_DISABLE
}
YMODEM_STATE_E;
typedef enum
{
	YMODEM_ERROR = 0,
	YMODEM_SUCCESS = !YMODEM_ERROR
}
YMODEM_ERROR_STATUS_E;

/* Private define ------------------------------------------------------------*/
#define PACKET_SEQNO_INDEX      (1)
#define PACKET_SEQNO_COMP_INDEX (2)

#define PACKET_HEADER           (3)
#define PACKET_TRAILER          (2)
#define PACKET_OVERHEAD         (PACKET_HEADER + PACKET_TRAILER)
#define PACKET_SIZE             (128)
#define PACKET_1K_SIZE          (1024)

#define FILE_NAME_LENGTH        (256)
#define FILE_SIZE_LENGTH        (16)

#define SOH                     (0x01)  /* start of 128-byte data packet */
#define STX                     (0x02)  /* start of 1024-byte data packet */
#define EOT                     (0x04)  /* end of transmission */
#define ACK                     (0x06)  /* acknowledge */
#define NAK                     (0x15)  /* negative acknowledge */
#define CA                      (0x18)  /* two of these in succession aborts transfer */
#define CRC16                   (0x43)  /* 'C' == 0x43, request 16-bit CRC */
#define end1                    (0x62) 
#define end2                    (0x72) 

#define ABORT1                  (0x41)  /* 'A' == 0x41, abort by user */
#define ABORT2                  (0x61)  /* 'a' == 0x61, abort by user */

#define MAX_ERRORS              (5)

/* 规定次数ymodem没有回应 */
#define ERROR_NO_ACK                (-5)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
STATIC UCHAR FLAGg = 0;
STATIC UCHAR datatest[3] = { 0 };

/* Private functions ---------------------------------------------------------*/

LONG Ymodem_Receive(UCHAR*);
UCHAR Ymodem_Transmit(UCHAR*, const  UCHAR*, ULONG);
LONG Receive_Byte(UCHAR* c, ULONG timeout);
ULONG Send_Byte(UCHAR c);
LONG Receive_Packet(UCHAR* data, LONG* length, ULONG timeout);
void Ymodem_ShowFileInfo(void);

#ifdef __cplusplus
};
#endif
#endif  /* __YMODEM_H_ */
