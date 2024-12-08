#include "../include/XorCrypter.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 异或加密/解密函数
void xor_encrypt_decrypt(unsigned char *data, size_t data_len, unsigned char *key, size_t key_len) {
    for (size_t i = 0; i < data_len; i++) {
        data[i] ^= key[i % key_len];  // 异或操作
    }
}

// 生成随机密钥
void generate_key(unsigned char *key, size_t key_len) {
    srand(time(NULL));  // 使用当前时间作为种子
    for (size_t i = 0; i < key_len; i++) {
        key[i] = rand() % 256;  // 生成0-255范围内的随机字节
    }
}

