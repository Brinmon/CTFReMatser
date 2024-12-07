#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 将字符串转换为十六进制格式，并返回转换后的字符串
// 如果添加Space为1，则十六进制数之间用空格隔开，否则不隔开
char* ConvertStringToHex(const char* input, int addSpace) {
    int len = strlen(input);
    // 每个字符占 2 个字符，考虑是否需要添加空格
    int resultSize = len * 2 + (addSpace ? len - 1 : 0) + 1; 
    char* result = (char*)malloc(resultSize * sizeof(char));
    
    int pos = 0;
    for (int i = 0; i < len; i++) {
        // 将字符转换为十六进制并格式化为 2 位
        pos += sprintf(result + pos, "%02X", (unsigned char)input[i]);

        // 如果需要添加空格且不是最后一个字符，就添加空格
        if (addSpace && i < len - 1) {
            result[pos++] = ' ';
        }
    }

    result[pos] = '\0';  // 结束字符串
    return result;
}

// 将字符串转换为十进制格式，并返回转换后的字符串
// 如果添加Space为1，则十进制数之间用空格隔开，否则不隔开
char* ConvertStringToDec(const char* input, int addSpace) {
    int len = strlen(input);
    // 每个字符占 3 位，考虑是否需要添加空格
    int resultSize = len * 3 + (addSpace ? len - 1 : 0) + 1; 
    char* result = (char*)malloc(resultSize * sizeof(char));
    
    int pos = 0;
    for (int i = 0; i < len; i++) {
        // 将字符转换为十进制并格式化为 3 位
        pos += sprintf(result + pos, "%03d", (unsigned char)input[i]);
        
        // 如果需要添加空格且不是最后一个字符，就添加空格
        if (addSpace && i < len - 1) {
            result[pos++] = ' ';
        }
    }

    result[pos] = '\0';  // 结束字符串
    return result;
}


// 将字符串转换为二进制格式，并返回转换后的字符串
// 如果添加Space为1，则二进制字符之间用空格隔开，否则不隔开
char* ConvertStringToBin(const char* input, int addSpace) {
    int len = strlen(input);
    int resultSize = len * 8 + (addSpace ? len - 1 : 0) + 1;  // 计算需要的内存空间，考虑空格
    char* result = (char*)malloc(resultSize * sizeof(char));

    int pos = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 7; j >= 0; j--) {
            result[pos++] = ((unsigned char)input[i] >> j) & 1 ? '1' : '0';
        }

        // 如果需要添加空格且不是最后一个字符，就添加空格
        if (addSpace && i < len - 1) {
            result[pos++] = ' ';
        }
    }

    result[pos] = '\0';  // 结束字符串
    return result;
}

// 将字符串转换为带转义的十六进制格式，并返回转换后的字符串
char* ConvertStringToHexEscape(const char* input) {
    if (input == NULL) {
        return NULL;
    }

    size_t len = strlen(input);
    // 每个字符转义为两位十六进制数，加上结束符
    char* result = (char*)malloc(len * 3 + 1);
    if (result == NULL) {
        return NULL; // 内存分配失败
    }

    char* ptr = result;
    for (size_t i = 0; i < len; i++) {
        // 将每个字符转换为两位十六进制格式
        ptr += sprintf(ptr, "\\x%02x", (unsigned char)input[i]);
    }
    return result;
}

// 将字符串进行 URL 编码，并返回编码后的字符串
char* ConvertStringToUrlEncode(const char* input) {
    if (input == NULL) {
        return NULL;
    }

    size_t len = strlen(input);
    // 每个字符最多变为3个字符（%xx），加上结束符
    char* result = (char*)malloc(len * 3 + 1);
    if (result == NULL) {
        return NULL; // 内存分配失败
    }

    char* ptr = result;
    for (size_t i = 0; i < len; i++) {
        unsigned char c = (unsigned char)input[i];
        // 判断是否为字母数字或特定符号
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9') || (c == '-' || c == '_' || c == '.' || c == '~')) {
            *ptr++ = c; // 直接添加
        } else {
            // 其它字符使用 %xx 格式编码
            ptr += sprintf(ptr, "%%%02x", c);
        }
    }
    *ptr = '\0'; // 结束字符串
    return result;
}