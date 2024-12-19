#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 将字符串转换为十六进制格式，并返回转换后的字符串
// 如果添加Space为1，则十六进制数之间用空格隔开；如果为2，则使用逗号隔开；否则不隔开
// 将字符串转换为十六进制表示，可以自定义长度和是否添加分隔符
char* ConvertStringToHex(const char* input, int addSpace, int maxLen) {
    if (input == NULL || maxLen <= 0) {
        fprintf(stderr, "Invalid input or maxLen in ConvertStringToHex.\n");
        return NULL;
    }

    int len = strlen(input);
    if (len == 0) {
        fprintf(stderr, "Input string is empty in ConvertStringToHex.\n");
        return NULL;
    }

    // 如果 maxLen 小于输入字符串长度，取 max(len, maxLen)
    len = (maxLen < len) ? len : maxLen;
    // printf("len: %d\n",len);

    // 每个字符占 2 个字符，考虑是否需要添加分隔符
    int resultSize = len * 2 + (addSpace > 0 ? len - 1 : 0) + 1;
    char* result = (char*)malloc(resultSize * sizeof(char));
    if (!result) {
        fprintf(stderr, "Memory allocation failed in ConvertStringToHex.\n");
        return NULL;
    }

    int pos = 0;
    for (int i = 0; i < len; i++) {
        // 将字符转换为十六进制并格式化为 2 位
        pos += sprintf(result + pos, "%02X", (unsigned char)input[i]);

        // 如果需要添加分隔符且不是最后一个字符，就添加分隔符
        if (addSpace > 0 && i < len - 1) {
            result[pos++] = (addSpace == 1) ? ' ' : ',';
        }
    }

    result[pos] = '\0';  // 结束字符串
    return result;
}

// 将字符串转换为十进制格式，并返回转换后的字符串
// 如果添加Space为1，则十进制数之间用空格隔开；如果为2，则使用逗号隔开；否则不隔开
// 参数 `length` 用于指定输入字符数组的长度，`addSpace` 用于决定是否添加分隔符
char* ConvertStringToDec(const char* input, int addSpace, int length) {
    // 如果输入的长度小于或等于0，说明无效
    if (length <= 0) {
        fprintf(stderr, "Invalid length in ConvertStringToDec.\n");
        return NULL;
    }

    // 每个字符转换成 3 位的十进制数，考虑是否需要添加分隔符
    int resultSize = length * 3 + (addSpace > 0 ? length - 1 : 0) + 1; 
    char* result = (char*)malloc(resultSize * sizeof(char));
    if (!result) {
        fprintf(stderr, "Memory allocation failed in ConvertStringToDec.\n");
        return NULL;
    }

    int pos = 0;
    for (int i = 0; i < length; i++) {
        // 将字符转换为十进制并格式化为 3 位
        pos += sprintf(result + pos, "%03d", (unsigned char)input[i]);
        
        // 如果需要添加分隔符且不是最后一个字符，就添加分隔符
        if (addSpace > 0 && i < length - 1) {
            result[pos++] = (addSpace == 1) ? ' ' : ',';  // 根据 addSpace 的值来选择分隔符
        }
    }

    result[pos] = '\0';  // 结束字符串
    return result;
}

// 将字符串转换为二进制格式，并返回转换后的字符串
// 如果添加Space为1，则二进制字符之间用空格隔开；如果为2，则使用逗号隔开；否则不隔开
// 参数 `length` 用于指定输入字符数组的长度，`addSpace` 用于决定是否添加分隔符
char* ConvertStringToBin(const char* input, int addSpace, int length) {
    // 如果输入的长度小于或等于0，说明无效
    if (length <= 0) {
        fprintf(stderr, "Invalid length in ConvertStringToBin.\n");
        return NULL;
    }

    // 每个字符转换为 8 位二进制数，考虑是否需要添加分隔符
    int resultSize = length * 8 + (addSpace > 0 ? length - 1 : 0) + 1;
    char* result = (char*)malloc(resultSize * sizeof(char));
    if (!result) {
        fprintf(stderr, "Memory allocation failed in ConvertStringToBin.\n");
        return NULL;
    }

    int pos = 0;
    for (int i = 0; i < length; i++) {
        // 将字符转换为二进制格式，按位从高到低
        for (int j = 7; j >= 0; j--) {
            result[pos++] = ((unsigned char)input[i] >> j) & 1 ? '1' : '0';
        }

        // 如果需要添加分隔符且不是最后一个字符，就添加分隔符
        if (addSpace > 0 && i < length - 1) {
            result[pos++] = (addSpace == 1) ? ' ' : ',';  // 根据 addSpace 的值来选择分隔符
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