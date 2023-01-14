/*
 * This file is part of the EasyFlash Library.
 *
 * Copyright (c) 2014-2019, Armink, <armink.ztl@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * 'Software'), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Function: It is an head file for this library. You can see all be called functions.
 * Created on: 2014-09-10
 */


#ifndef EASYFLASH_H_
#define EASYFLASH_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <ef_cfg.h>
#include <ef_def.h>

#ifdef __cplusplus
extern "C" {
#endif


/* easyflash.c */
// 初始化各个组件
EfErrCode easyflash_init(void);
#ifdef EF_USING_ENV
/* only supported on ef_env.c */
size_t ef_get_env_blob(const char *key, void *value_buf, size_t buf_len, size_t *saved_value_len);
bool ef_get_env_obj(const char *key, env_node_obj_t env);
size_t ef_read_env_value(env_node_obj_t env, uint8_t *value_buf, size_t buf_len);
EfErrCode ef_set_env_blob(const char *key, const void *value_buf, size_t buf_len);
/* ef_env.c, ef_env_legacy_wl.c and ef_env_legacy.c */
// 加载Flash中的所有的环境变量到系统内存中
EfErrCode ef_load_env(void);
// 打印所有的环境变量
void ef_print_env(void);
// 通过环境变量的名字来获取其对应的值
char *ef_get_env(const char *key);
// 设置环境变量
EfErrCode ef_set_env(const char *key, const char *value);
// 删除环境变量
EfErrCode ef_del_env(const char *key);
// 保存环境变量
EfErrCode ef_save_env(void);
// 设置默认  这里可以进行更改 设置该有的环境变量
EfErrCode ef_env_set_default(void);
// 获取当前环境变量写入到Flash的字节大小
size_t ef_get_env_write_bytes(void);
// 设置并且保存环境变量
EfErrCode ef_set_and_save_env(const char *key, const char *value);
// 删除并且保存环境变量
EfErrCode ef_del_and_save_env(const char *key);
#endif

#ifdef EF_USING_IAP
/* ef_iap.c */
// 擦除备份区中的应用程序
EfErrCode ef_erase_bak_app(size_t app_size);
// 擦除用户应用程序
EfErrCode ef_erase_user_app(uint32_t user_app_addr, size_t user_app_size);
// 大部分用户的应用程序与被分去不在同一个flash中时 需要用户擦除额外指定擦除应用程序方法
EfErrCode ef_erase_spec_user_app(uint32_t user_app_addr, size_t app_size,
                                 EfErrCode (*app_erase)(uint32_t addr, size_t size));
// 擦除bootloader
EfErrCode ef_erase_bl(uint32_t bl_addr, size_t bl_size);
// 写数据到备份区
EfErrCode ef_write_data_to_bak(uint8_t *data, size_t size, size_t *cur_size,
                               size_t total_size);
// 从备份拷贝应用程序
EfErrCode ef_copy_app_from_bak(uint32_t user_app_addr, size_t app_size);
// 当用户程序与被分去不在同一个flash中 通过用户指定的写操作方法来拷贝应用程序
EfErrCode ef_copy_spec_app_from_bak(uint32_t user_app_addr, size_t app_size,
                                    EfErrCode (*app_write)(uint32_t addr, const uint32_t *buf, size_t size));
// 从备份区拷贝BootLoader 先擦除原有的bootloader
EfErrCode ef_copy_bl_from_bak(uint32_t bl_addr, size_t bl_size);
uint32_t ef_get_bak_app_start_addr(void);
#endif

#ifdef EF_USING_LOG
/* ef_log.c */
// 从flash中读取日志
EfErrCode ef_log_read(size_t index, uint32_t *log, size_t size);
// 往flash 写日志
EfErrCode ef_log_write(const uint32_t *log, size_t size);
// 清空存储在Flash中的全部日志
EfErrCode ef_log_clean(void);
// 获取已存储在Flash中的日志大小
size_t ef_log_get_used_size(void);
#endif

/* ef_utils.c */
uint32_t ef_calc_crc32(uint32_t crc, const void *buf, size_t size);

/* ef_port.c */
EfErrCode ef_port_read(uint32_t addr, uint32_t *buf, size_t size);
EfErrCode ef_port_erase(uint32_t addr, size_t size);
EfErrCode ef_port_write(uint32_t addr, const uint32_t *buf, size_t size);
void ef_port_env_lock(void);
void ef_port_env_unlock(void);
void ef_log_debug(const char *file, const long line, const char *format, ...);
void ef_log_info(const char *format, ...);
void ef_print(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* EASYFLASH_H_ */
