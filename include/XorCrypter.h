#ifndef XORCRYPTER_H
#define XORCRYPTER_H

#include <stddef.h>  // size_t 是一个无符号类型，专门用于表示内存大小、数组长度等，确保平台独立性、避免负值错误，并与系统架构的字长匹配，适用于处理大范围的对象或内存位置。

// 异或加密/解密函数
// data：需要加密或解密的数据
// data_len：数据长度
// key：加密密钥
// key_len：密钥长度
void xor_encrypt_decrypt(unsigned char *data, size_t data_len, unsigned char *key, size_t key_len);

// 生成随机密钥函数
// key：密钥数组
// key_len：密钥长度
void generate_key(unsigned char *key, size_t key_len);

#endif // XORCRYPTER_H
