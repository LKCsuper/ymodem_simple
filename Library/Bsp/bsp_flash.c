/*
 * @Description: 
 * @Version: 2.0
 * @Author: lkc
 * @Date: 2022-11-28 19:28:49
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-01-14 17:44:48
 */
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
 * @brief  擦除所有的app 备份部分
 * @param  StartSector: start of user flash area
 * @retval 0: user flash area successfully erased
 *         1: error occurred
 */
void FLASH_Erase_App_Bak(void)
{
    /* 这里注意，stm擦除只能按照扇区擦除，部分单片机可以擦除字节 */
    FLASH_EraseSector(FLASH_Sector_6, VoltageRange_4);
    FLASH_EraseSector(FLASH_Sector_7, VoltageRange_4);

    return;
}

/**
 * @description: 将app从备份区拷贝到app
 * @detail description: 
 * @return {*}
 */
void FLASH_CopyApp(void)
{

    return;
}

/**
 * @brief  擦除所有的app 部分
 * @param  StartSector: start of user flash area
 * @retval 0: user flash area successfully erased
 *         1: error occurred
 */
void FLASH_Erase_App(void)
{
    /* 这里注意，stm擦除只能按照扇区擦除，部分单片机可以擦除字节 */
    FLASH_EraseSector(FLASH_Sector_4, VoltageRange_4);
    FLASH_EraseSector(FLASH_Sector_5, VoltageRange_4);

    return;
}

/**
 * @brief  关闭flash写保护.
 * @param  None
 * @retval 1: Write Protection successfully disabled
 *         2: Error: Flash write unprotection failed
 */
uint32_t FLASH_DisableWriteProtection(void)
{
    /* Unlock the Option Bytes */
    FLASH_OB_Unlock();

    /* 这里把所有区域都取消保护 */
    FLASH_OB_WRPConfig(OB_WRP_Sector_All, DISABLE);

    /* Start the Option Bytes programming process. */
    if (FLASH_OB_Launch() != FLASH_COMPLETE)
    {
        FLASH_OB_Lock();
        /* Error: Flash write unprotection failed */
        return ERROR;
    }

    FLASH_OB_Lock();
    /* Write Protection successfully disabled */
    return SUCCESS;
}

/**
 * @brief  关闭flash写保护.
 * @param  None
 * @retval 1: Write Protection successfully disabled
 *         2: Error: Flash write unprotection failed
 */
uint32_t FLASH_EnableWriteProtection(void)
{
    /* Unlock the Option Bytes */
    FLASH_OB_Unlock();

    /* 所有区域实行保护 */
    FLASH_OB_WRPConfig(OB_WRP_Sector_All, ENABLE);

    /* 这里还是对config区进行解锁，以便未来写配置参数 */
    FLASH_OB_WRPConfig(FLASH_Sector_3, ENABLE);
    FLASH_OB_WRPConfig(FLASH_Sector_4, ENABLE);

    /* Start the Option Bytes programming process. */
    if (FLASH_OB_Launch() != FLASH_COMPLETE)
    {
        FLASH_OB_Lock();
        /* Error: Flash write unprotection failed */
        return ERROR;
    }

    FLASH_OB_Lock();
    /* Write Protection successfully disabled */
    return SUCCESS;
}

/**
 * @description: 升级标志
 * @detail: 主要是ymodem升级到备份区之后然后置位
 * @param {bool} isSet 是否置位
 * @return {*}
 * @author: lkc
 */
uint32_t Ymodem_Flash_Get_Flag(void) 
{
    return GET_DATA(UPDATE_FLAG_ADR);
}

/**
 * @description: 升级标志
 * @detail: 主要是ymodem升级到备份区之后然后置位
 * @param {bool} isSet 是否置位
 * @return {*}
 * @author: lkc
 */
void Ymodem_Flash_Set_Flag(bool isSet)
{
    if (isSet)
    {
        FLASH_ProgramWord(UPDATE_FLAG_ADR, UPDATE_FLAG);
    }
    else
    {
        FLASH_ProgramWord(UPDATE_FLAG_ADR, 0xffffffff);
    }

    return;
}

/**
 * @brief  flash初始化
 * @param  None
 * @retval None
 */
void Ymodem_FLASH_Init(void)
{
    /* 需要解除写保护 */
    FLASH_Unlock();

    /* 清除所有的flash标志 */
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                    FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);

    return;
}

/**
 * @brief  擦除所有的app部分
 * @param  StartSector: start of user flash area
 * @retval 0: user flash area successfully erased
 *         1: error occurred
 */
void YMODEM_FLASH_Erase_App(void)
{
    /* 这里可以选择你想要擦除的区域，这里是规定的升级区域*/
    FLASH_Erase_App();

    return;
}

/**
 * @description: 这里我们不需要起始地址，只需要数据就可以完成接口
 * @detail description: 
 * @param {uint32_t} *Data          数据
 * @param {uint32_t} DataLength     数据长度
 * @return {*}
 */
uint32_t Ymodem_Flash_Write(uint32_t FlashAddress ,uint32_t Data)
{
    
    return 0;
}

#ifdef __cplusplus
};
#endif
