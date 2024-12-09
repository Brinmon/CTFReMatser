#ifndef BASE64_H
#define BASE64_H

#include <stddef.h>

// 声明全局 Base64 编码表，允许修改
extern char base64_table[64];

// Base64 编码函数原型
char* base64_encode(const char *data);

// Base64 解码函数原型
char* base64_decode(const char *data);


#endif // BASE64_H
