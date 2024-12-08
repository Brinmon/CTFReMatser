#include "../include/base64.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 默认的 Base64 编码表
char base64_table[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


// 设置 Base64 编码表
void initialize_base64_table(const char *table) {
    for (int i = 0; i < 64; i++) {
        base64_table[i] = table[i];
    }
}

// 将 6 位二进制转为对应的 Base64 字符
static char base64_encode_char(int value) {
    return base64_table[value];
}

// Base64 编码函数
char* base64_encode(const unsigned char *data, size_t length) {
    size_t encoded_length = 4 * ((length + 2) / 3);  // 计算编码后的长度
    char *encoded_data = malloc(encoded_length + 1);  // 分配内存

    size_t i, j;
    for (i = 0, j = 0; i < length;) {
        unsigned int byte1 = data[i++];
        unsigned int byte2 = (i < length) ? data[i++] : 0;
        unsigned int byte3 = (i < length) ? data[i++] : 0;

        encoded_data[j++] = base64_encode_char(byte1 >> 2);
        encoded_data[j++] = base64_encode_char(((byte1 & 0x03) << 4) | (byte2 >> 4));
        encoded_data[j++] = base64_encode_char(((byte2 & 0x0F) << 2) | (byte3 >> 6));
        encoded_data[j++] = base64_encode_char(byte3 & 0x3F);
    }

    // 处理填充字符（=）
    for (size_t i = 0; i < length % 3; i++) {
        encoded_data[encoded_length - 1 - i] = '=';
    }

    encoded_data[encoded_length] = '\0';  // 添加字符串结束符
    return encoded_data;
}

// 获取 Base64 字符的解码值
int base64_decode_char(char c) {
    if (c == '=') {
        return -2;  // 用 -2 表示填充字符 '='，不当做非法字符
    }

    for (int i = 0; i < 64; i++) {
        if (base64_table[i] == c) {
            return i;
        }
    }

    return -1;  // 如果是非法字符，返回 -1
}

// Base64 解码函数
unsigned char* base64_decode(const char *data, size_t *out_length) {
    size_t length = strlen(data);
    
    // 检查长度是否是4的倍数
    if (length % 4 != 0) {
        fprintf(stderr, "Error: Base64 string length is not a multiple of 4.\n");
        return NULL;
    }

    size_t decoded_length = (length / 4) * 3;
    if (data[length - 1] == '=') decoded_length--;
    if (data[length - 2] == '=') decoded_length--;

    unsigned char *decoded_data = malloc(decoded_length);
    if (!decoded_data) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    size_t i, j;
    for (i = 0, j = 0; i < length;) {
        // 获取 Base64 字符的值
        int val1 = base64_decode_char(data[i++]);
        int val2 = base64_decode_char(data[i++]);
        int val3 = base64_decode_char(data[i++]);
        int val4 = base64_decode_char(data[i++]);

        // 检查是否为非法字符
        if (val1 == -1 || val2 == -1 || val3 == -1 || val4 == -1) {
            fprintf(stderr, "Error: Invalid character found in Base64 string.\n");
            free(decoded_data);
            return NULL;
        }

        // 跳过 '=' 填充字符
        if (val1 == -2) continue;
        if (val2 == -2) continue;
        if (val3 == -2) continue;
        if (val4 == -2) continue;

        // 进行解码
        decoded_data[j++] = (val1 << 2) | (val2 >> 4);
        if (data[i-1] != '=') decoded_data[j++] = ((val2 & 0x0F) << 4) | (val3 >> 2);
        if (data[i-2] != '=') decoded_data[j++] = ((val3 & 0x03) << 6) | val4;
    }

    *out_length = decoded_length;
    return decoded_data;
}



// 打印 Base64 编码表
void print_base64_table(void) {
    printf("Base64 Table: ");
    for (int i = 0; i < 64; i++) {
        putchar(base64_table[i]);
    }
    putchar('\n');
}


