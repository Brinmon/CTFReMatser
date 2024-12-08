#ifndef BASE64_H
#define BASE64_H

#include <stddef.h>

// 声明全局 Base64 编码表，允许修改
extern char base64_table[64];

// Base64 编码函数原型
char* base64_encode(const unsigned char *data, size_t length);

// Base64 解码函数原型
unsigned char* base64_decode(const char *data, size_t *out_length);

// 函数：初始化 Base64 编码表
void initialize_base64_table(const char *custom_table);

// 函数：打印当前 Base64 编码表
void print_base64_table(void);

#endif // BASE64_H
