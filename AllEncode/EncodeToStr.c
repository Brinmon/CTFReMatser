#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 预处理，去除所有空格
char* remove_spaces(const char* input) {
    size_t len = strlen(input);
    char* result = (char*)malloc(len + 1); // 不会比原始字符串长
    if (result == NULL) return NULL;

    char* ptr = result;
    for (size_t i = 0; i < len; i++) {
        if (input[i] != ' ') {
            *ptr++ = input[i];
        }
    }
    *ptr = '\0'; // null-terminate the string
    return result;
}

// 校验16进制格式的有效性（带空格或不带空格，每对字符必须是有效的16进制字符）
int validate_hex_format(const char* hex) {
    size_t len = strlen(hex);

    // 如果是带空格的格式，验证每组数字是否是 2 个16进制字符
    if (strchr(hex, ' ')) {
        char* token;
        char* input = strdup(hex);  // 复制输入字符串
        if (!input) {
            return 0;  // 内存分配失败
        }

        token = strtok(input, " ");
        while (token) {
            if (strlen(token) != 2) {
                free(input);
                return 0; // 每组必须是 2 个16进制字符
            }
            for (size_t i = 0; i < 2; i++) {
                if (!isxdigit(token[i])) {
                    free(input);
                    return 0; // 非16进制字符
                }
            }
            token = strtok(NULL, " ");
        }
        free(input);  // 释放内存
    }
    // 如果没有空格，检查长度是否是 2 的倍数
    else {
        if (len % 2 != 0) {
            return 0; // 长度不是 2 的倍数
        }
        for (size_t i = 0; i < len; i++) {
            if (!isxdigit(hex[i])) {
                return 0; // 非16进制字符
            }
        }
    }
    return 1; // 格式有效
}

// 将16进制字符串转换为可见字符字符串
char* ConvertHexToString(const char* hex) {
    // 验证16进制字符串格式
    if (!validate_hex_format(hex)) {
        return NULL; // 格式无效
    }

    size_t len = strlen(hex);
    size_t str_len = len / 2 + 1; // 最终的字符串长度
    char* result = (char*)malloc(str_len + 1); // 额外的 1 是给 '\0' 结束符
    if (!result) {
        return NULL;  // 内存分配失败
    }

    size_t j = 0;

    // 如果是带空格的格式
    if (strchr(hex, ' ')) {
        char* token;
        char* input = strdup(hex);  // 复制输入字符串
        if (!input) {
            free(result);
            return NULL;  // 内存分配失败
        }

        token = strtok(input, " ");
        while (token) {
            if (strlen(token) == 2) {
                unsigned char ch = (unsigned char)strtol(token, NULL, 16); // 将16进制转换为字符
                result[j++] = ch;
            }
            token = strtok(NULL, " ");
        }
        free(input);  // 释放内存
    }
    // 如果是没有空格的格式
    else {
        for (size_t i = 0; i < len; i += 2) {
            char hex_pair[3] = { hex[i], hex[i+1], '\0' }; // 取每一对16进制字符
            unsigned char ch = (unsigned char)strtol(hex_pair, NULL, 16); // 将16进制转换为字符
            result[j++] = ch;
        }
    }

    result[j] = '\0';  // 字符串结尾
    return result;
}

// 检查十进制格式的有效性（带空格或不带空格，每个数字占 3 个字符）
int validate_dec_format(const char* dec) {
    size_t len = strlen(dec);

    // 如果是带空格的格式，验证每个数字是否有 3 个字符，并且只有空格分隔
    if (strchr(dec, ' ')) {
        // 复制输入字符串到一个临时可修改的副本
        char* input = strdup(dec);  // 使用 strdup 复制字符串
        if (!input) {
            return 0;  // 内存分配失败
        }

        // 使用 strtok_r 进行分割
        char* token;
        char* save_ptr;
        token = strtok_r(input, " ", &save_ptr); //strtok 会修改传入的字符串。如果你传递的是一个常量字符串，它不允许被修改，因此使用时会引发段错误。所以使用strtok_r
        while (token) {
            if (strlen(token) != 3 || !isdigit(token[0]) || !isdigit(token[1]) || !isdigit(token[2])) {
                free(input);  // 释放临时字符串
                return 0; // 不符合格式
            }
            token = strtok_r(NULL, " ", &save_ptr);  // 获取下一个 token
        }
        free(input);  // 释放临时字符串
    }
    // 如果没有空格，检查总长度是否是 3 的倍数
    else {
        if (len % 3 != 0) {
            return 0; // 总长度必须是 3 的倍数
        }
        for (size_t i = 0; i < len; i++) {
            if (!isdigit(dec[i])) {
                return 0; // 确保每个字符都是数字
            }
        }
    }

    return 1; // 格式有效
}

// 将十进制字符串转换回普通字符串
char* ConvertDecToString(const char* dec) {
    // 先检查输入的十进制格式是否合法
    if (!validate_dec_format(dec)) {
        return NULL; // 如果格式不正确，返回 NULL
    }

    char* dec_no_spaces = remove_spaces(dec); // 去除空格
    size_t len = strlen(dec_no_spaces);

    // 每个十进制数字最多是3个字符
    if (len % 3 != 0) {
        free(dec_no_spaces);
        return NULL; // 十进制字符串的长度必须是3的倍数
    }

    char* result = (char*)malloc((len / 3) + 1); // 每3个字符表示一个字节
    if (result == NULL) {
        free(dec_no_spaces);
        return NULL; // 内存分配失败
    }

    int index = 0;
    for (size_t i = 0; i < len; i += 3) {
        char byte_str[4] = {dec_no_spaces[i], dec_no_spaces[i+1], dec_no_spaces[i+2], '\0'};
        result[index++] = (char)strtol(byte_str, NULL, 10); // 转换为字符
    }
    result[index] = '\0'; // 终止符
    free(dec_no_spaces);
    return result;
}

// 检查二进制字符串的格式是否合法（带空格或不带空格）
int validate_bin_format(const char* bin) {
    size_t len = strlen(bin);

    // 如果是带空格的格式，验证每组数字是否是 8 位
    if (strchr(bin, ' ')) {
        char* token;
        char* input = strdup(bin);  // 复制输入字符串
        if (!input) {
            return 0;  // 内存分配失败
        }

        token = strtok(input, " ");
        while (token) {
            if (strlen(token) != 8) {
                free(input);  // 释放内存
                return 0; // 每组必须是 8 位
            }
            for (size_t i = 0; i < 8; i++) {
                if (token[i] != '0' && token[i] != '1') {
                    free(input);  // 释放内存
                    return 0; // 非二进制字符
                }
            }
            token = strtok(NULL, " ");
        }
        free(input);  // 释放内存
    }
    // 如果没有空格，检查长度是否是 8 的倍数
    else {
        if (len % 8 != 0) {
            return 0; // 长度不是 8 的倍数
        }
        for (size_t i = 0; i < len; i++) {
            if (bin[i] != '0' && bin[i] != '1') {
                return 0; // 非二进制字符
            }
        }
    }

    return 1; // 格式合法
}

// 将合法的二进制字符串转换为可见字符字符串
char* ConvertBinToString(const char* bin) {
    if (!validate_bin_format(bin)) {
        return NULL; // 如果格式不正确，返回 NULL
    }


    size_t len = strlen(bin);
    size_t str_len = (len / 8) + 1; // 最终的字符串长度

    // 结果字符串
    char* result = (char*)malloc(str_len + 1); // 额外的 1 是给 '\0' 结束符
    if (!result) {
        return NULL;  // 内存分配失败
    }

    size_t j = 0;

    // 如果是带空格的格式
    if (strchr(bin, ' ')) {
        char* token;
        char* input = strdup(bin);  // 复制输入字符串
        if (!input) {
            free(result);
            return NULL;  // 内存分配失败
        }

        token = strtok(input, " ");
        while (token) {
            // 确保每个 token 是 8 位
            if (strlen(token) == 8) {
                unsigned char ch = 0;
                for (size_t i = 0; i < 8; i++) {
                    ch = (ch << 1) | (token[i] - '0'); // 计算二进制值
                }
                result[j++] = ch; // 将字符加入结果
            }
            token = strtok(NULL, " ");
        }
        free(input);  // 释放内存
    }
    // 如果是没有空格的格式
    else {
        for (size_t i = 0; i < len; i += 8) {
            unsigned char ch = 0;
            for (size_t j = 0; j < 8; j++) {
                ch = (ch << 1) | (bin[i + j] - '0'); // 计算二进制值
            }
            result[j++] = ch; // 将字符加入结果
        }
    }

    result[j] = '\0';  // 字符串结尾
    return result;
}



