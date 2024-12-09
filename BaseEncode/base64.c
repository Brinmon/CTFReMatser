#include "../include/base64.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Base64转换表，使用字符串表示
static const char *base64_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Base64编码函数
char* base64_encode(const char *data) {
    int len = strlen(data);
    int encoded_len = 4 * ((len + 2) / 3);  // Base64 编码后长度
    char *encoded_data = (char *)malloc(encoded_len + 1);  // 分配内存

    int i = 0, j = 0;
    unsigned char a, b, c;
    while (i < len) {
        // 获取每个 3 字节的数据
        a = i < len ? data[i++] : 0;
        b = i < len ? data[i++] : 0;
        c = i < len ? data[i++] : 0;

        // 编码为 4 个字符
        encoded_data[j++] = base64_alphabet[a >> 2];
        encoded_data[j++] = base64_alphabet[((a & 0x03) << 4) | (b >> 4)];
        encoded_data[j++] = base64_alphabet[((b & 0x0f) << 2) | (c >> 6)];
        encoded_data[j++] = base64_alphabet[c & 0x3f];
    }

    // 处理填充字符
    if (len % 3 == 1) {
        encoded_data[j - 2] = '=';
        encoded_data[j - 1] = '=';
    } else if (len % 3 == 2) {
        encoded_data[j - 1] = '=';
    }

    encoded_data[encoded_len] = '\0';  // 终止字符串
    return encoded_data;
}

// Base64解码函数
char* base64_decode(const char* encoded_data) {
    int len = strlen(encoded_data);
    if (len % 4 != 0) return NULL;  // Base64 编码长度必须是 4 的倍数

    int decoded_len = (len / 4) * 3;  // 解码后长度
    if (encoded_data[len - 1] == '=') decoded_len--;  // 处理填充
    if (encoded_data[len - 2] == '=') decoded_len--;

    char *decoded_data = (char *)malloc(decoded_len + 1);  // 分配内存

    int i = 0, j = 0;
    unsigned char a, b, c, d;
    while (i < len) {
        // 取出 Base64 编码的 4 个字符
        a = strchr(base64_alphabet, encoded_data[i++]) - base64_alphabet;
        b = strchr(base64_alphabet, encoded_data[i++]) - base64_alphabet;
        c = strchr(base64_alphabet, encoded_data[i++]) - base64_alphabet;
        d = strchr(base64_alphabet, encoded_data[i++]) - base64_alphabet;

        // 还原回原始的 3 字节数据
        decoded_data[j++] = (a << 2) | (b >> 4);
        if (c != 64) decoded_data[j++] = (b << 4) | (c >> 2);
        if (d != 64) decoded_data[j++] = (c << 6) | d;
    }

    decoded_data[decoded_len] = '\0';  // 终止字符串
    return decoded_data;
}

