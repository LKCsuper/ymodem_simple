/*
 * @Description: 
 * @Version: 2.0
 * @Author: lkc
 * @Date: 2022-11-28 19:28:50
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-01-14 18:11:22
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_FLASH_H
#define __BSP_FLASH_H

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Base address of the Flash sectors */
#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbyte */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base @ of Sector 1, 16 Kbyte */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base @ of Sector 2, 16 Kbyte */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base @ of Sector 3, 16 Kbyte */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbyte */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbyte */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base @ of Sector 6, 128 Kbyte */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base @ of Sector 7, 128 Kbyte */
#define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000) /* Base @ of Sector 8, 128 Kbyte */
#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base @ of Sector 9, 128 Kbyte */
#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbyte */
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbyte */

/*
    stmzet6 flash 512kb
    boot 16 16
    config 16 16
    app 64 128
    app_bak 128 128 末尾存在升级标志
*/

#define UPDATE_FLAG_ADR                 (0x0806FFFFU)
#define UPDATE_FLAG                     (0x12345678U)

#define BOOT_SIZE                       (32 * 1024)
#define BOOT_START_ADDR                 (0x08000000U)
#define BOOT_END_ADDR                   (BOOT_START_ADDR + BOOT_SIZE)

#define APP_SIZE                        (192 * 1024)
#define APP_START_ADDR                  (0x08010000U)
#define APP_START_END_ADDR              (APP_START_ADDR + APP_SIZE)

#define APP_BAK_SIZE                    (256 * 1024)
#define APP_BAK_START_ADDR              (0x08040000U)
#define APP_BAK_END_ADDR                (APP_BAK_START_ADDR + APP_BAK_SIZE)

#define CONFIG_ADDR                     (32 * 1024)
#define CONFIG_START_ADDR               (0x08008000U)
#define CONFIG_END_ADDR                 (CONFIG_BAK_START_ADDR + APP_BAK_SIZE)

#define YMODEM_UPDATE_APP_SIZE                          APP_BAK_SIZE
#define YMODEM_UPDATE_APP_START_ADDR                    APP_BAK_START_ADDR
#define YMODEM_UPDATE_APP_END_ADDR                      APP_BAK_END_ADDR

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void FLASH_Erase_App_Bak(void);
void FLASH_CopyApp(void);
void FLASH_Erase_App(void);
uint32_t FLASH_DisableWriteProtection(void);
uint32_t FLASH_EnableWriteProtection(void);

uint32_t Ymodem_Flash_Get_Flag(void);
void Ymodem_Flash_Set_Flag(bool isSet);
void Ymodem_Flash_Init(void);
void Ymodem_Flash_Erase_App(void);
uint32_t Ymodem_Flash_Write(uint32_t *Data, uint32_t DataLength);

#endif  /* __FLASH_IF_H */
