#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 预处理，去除所有空格和逗号
char* remove_spaces_and_commas(const char* input) {
    size_t len = strlen(input);
    char* result = (char*)malloc(len + 1); // 不会比原始字符串长
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed in remove_spaces_and_commas.\n");
        return NULL;
    }

    char* ptr = result;
    for (size_t i = 0; i < len; i++) {
        if (input[i] != ' ' && input[i] != ',') {
            *ptr++ = input[i];
        }
    }
    *ptr = '\0'; // null-terminate the string
    return result;
}
// 校验16进制格式的有效性（带空格或逗号分隔，每对字符必须是有效的16进制字符）
int validate_hex_format(const char* hex) {
    size_t len = strlen(hex);

    // 如果是带空格或逗号的格式，验证每组数字是否是 2 个16进制字符
    if (strchr(hex, ' ') || strchr(hex, ',')) {
        char* token;
        char* input = strdup(hex);  // 复制输入字符串
        if (!input) {
            fprintf(stderr, "Memory allocation failed in validate_hex_format.\n");
            return 0;  // 内存分配失败
        }

        token = strtok(input, " ,");
        while (token) {
            if (strlen(token) != 2) {
                free(input);
                fprintf(stderr, "Each group must be exactly 2 hexadecimal characters in validate_hex_format.\n");
                return 0; // 每组必须是 2 个16进制字符
            }
            for (size_t i = 0; i < 2; i++) {
                if (!isxdigit(token[i])) {
                    free(input);
                    fprintf(stderr, "Invalid hexadecimal character found in validate_hex_format.\n");
                    return 0; // 非16进制字符
                }
            }
            token = strtok(NULL, " ,");
        }
        free(input);  // 释放内存
    }
    // 如果没有空格或逗号，检查长度是否是 2 的倍数
    else {
        if (len % 2 != 0) {
            fprintf(stderr, "Length of hexadecimal string without spaces or commas must be a multiple of 2 in validate_hex_format.\n");
            return 0; // 长度不是 2 的倍数
        }
        for (size_t i = 0; i < len; i++) {
            if (!isxdigit(hex[i])) {
                fprintf(stderr, "Invalid hexadecimal character found in validate_hex_format.\n");
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
        fprintf(stderr, "Invalid hexadecimal format in ConvertHexToString.\n");
        return NULL; // 格式无效
    }

    size_t len = strlen(hex);
    size_t str_len = len / 2 + 1; // 最终的字符串长度
    char* result = (char*)malloc(str_len + 1); // 额外的 1 是给 '\0' 结束符
    if (!result) {
        fprintf(stderr, "Memory allocation failed in ConvertHexToString.\n");
        return NULL;  // 内存分配失败
    }

    size_t j = 0;

    // 如果是带空格或逗号的格式
    if (strchr(hex, ' ') || strchr(hex, ',')) {
        char* token;
        char* input = strdup(hex);  // 复制输入字符串
        if (!input) {
            free(result);
            fprintf(stderr, "Memory allocation failed in ConvertHexToString.\n");
            return NULL;  // 内存分配失败
        }

        token = strtok(input, " ,");
        while (token) {
            if (strlen(token) == 2) {
                unsigned char ch = (unsigned char)strtol(token, NULL, 16); // 将16进制转换为字符
                result[j++] = ch;
            }
            token = strtok(NULL, " ,");
        }
        free(input);  // 释放内存
    }
    // 如果是没有空格或逗号的格式
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



// 校验10进制格式的有效性（带空格或逗号分隔，每个数字占 3 个字符）
int validate_dec_format(const char* dec) {
    size_t len = strlen(dec);

    // 如果是带空格或逗号的格式，验证每个数字是否有 3 个字符，并且只有空格或逗号分隔
    if (strchr(dec, ' ') || strchr(dec, ',')) {
        // 复制输入字符串到一个临时可修改的副本
        char* input = strdup(dec);  // 使用 strdup 复制字符串
        if (!input) {
            fprintf(stderr, "Memory allocation failed in validate_dec_format.\n");
            return 0;  // 内存分配失败
        }

        // 使用 strtok_r 进行分割
        char* token;
        char* save_ptr;
        token = strtok_r(input, " ,", &save_ptr); 
        while (token) {
            if (strlen(token) != 3 || !isdigit(token[0]) || !isdigit(token[1]) || !isdigit(token[2])) {
                free(input);  // 释放临时字符串
                fprintf(stderr, "Each decimal number must be exactly 3 digits in validate_dec_format.\n");
                return 0; // 不符合格式
            }
            token = strtok_r(NULL, " ,", &save_ptr);  
        }
        free(input);  // 释放临时字符串
    }
    // 如果没有空格或逗号，检查总长度是否是 3 的倍数
    else {
        if (len % 3 != 0) {
            fprintf(stderr, "Length of decimal string without spaces or commas must be a multiple of 3 in validate_dec_format.\n");
            return 0; // 总长度必须是 3 的倍数
        }
        for (size_t i = 0; i < len; i++) {
            if (!isdigit(dec[i])) {
                fprintf(stderr, "Non-digit character found in decimal string in validate_dec_format.\n");
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
        fprintf(stderr, "Invalid decimal format in ConvertDecToString.\n");
        return NULL; // 如果格式不正确，返回 NULL
    }

    char* dec_no_spaces_or_commas = remove_spaces_and_commas(dec); // 去除空格和逗号
    size_t len = strlen(dec_no_spaces_or_commas);

    // 每个十进制数字最多是3个字符
    if (len % 3 != 0) {
        free(dec_no_spaces_or_commas);
        fprintf(stderr, "Length of decimal string after removing spaces and commas must be a multiple of 3 in ConvertDecToString.\n");
        return NULL; // 十进制字符串的长度必须是3的倍数
    }

    char* result = (char*)malloc((len / 3) + 1); // 每3个字符表示一个字节
    if (result == NULL) {
        free(dec_no_spaces_or_commas);
        fprintf(stderr, "Memory allocation failed in ConvertDecToString.\n");
        return NULL; // 内存分配失败
    }

    int index = 0;
    for (size_t i = 0; i < len; i += 3) {
        char byte_str[4] = {dec_no_spaces_or_commas[i], dec_no_spaces_or_commas[i+1], dec_no_spaces_or_commas[i+2], '\0'};
        result[index++] = (char)strtol(byte_str, NULL, 10); // 转换为字符
    }
    result[index] = '\0'; // 终止符
    free(dec_no_spaces_or_commas);
    return result;
}

// 检查二进制字符串的格式是否合法（带空格或逗号分隔）
int validate_bin_format(const char* bin) {
    size_t len = strlen(bin);

    // 如果是带空格或逗号的格式，验证每组数字是否是 8 位
    if (strchr(bin, ' ') || strchr(bin, ',')) {
        char* token;
        char* input = strdup(bin);  // 复制输入字符串
        if (!input) {
            fprintf(stderr, "Memory allocation failed in validate_bin_format.\n");
            return 0;  // 内存分配失败
        }

        token = strtok(input, " ,");
        while (token) {
            if (strlen(token) != 8) {
                free(input);  // 释放内存
                fprintf(stderr, "Each group must be exactly 8 binary digits in validate_bin_format.\n");
                return 0; // 每组必须是 8 位
            }
            for (size_t i = 0; i < 8; i++) {
                if (token[i] != '0' && token[i] != '1') {
                    free(input);  // 释放内存
                    fprintf(stderr, "Invalid binary character found in validate_bin_format.\n");
                    return 0; // 非二进制字符
                }
            }
            token = strtok(NULL, " ,");
        }
        free(input);  // 释放内存
    }
    // 如果没有空格或逗号，检查长度是否是 8 的倍数
    else {
        if (len % 8 != 0) {
            fprintf(stderr, "Length of binary string without spaces or commas must be a multiple of 8 in validate_bin_format.\n");
            return 0; // 长度不是 8 的倍数
        }
        for (size_t i = 0; i < len; i++) {
            if (bin[i] != '0' && bin[i] != '1') {
                fprintf(stderr, "Invalid binary character found in validate_bin_format.\n");
                return 0; // 非二进制字符
            }
        }
    }

    return 1; // 格式合法
}

// 将合法的二进制字符串转换为可见字符字符串
char* ConvertBinToString(const char* bin) {
    if (!validate_bin_format(bin)) {
        fprintf(stderr, "Invalid binary format in ConvertBinToString.\n");
        return NULL; // 如果格式不正确，返回 NULL
    }

    size_t len = strlen(bin);
    size_t str_len = (len / 8) + 1; // 最终的字符串长度

    // 结果字符串
    char* result = (char*)malloc(str_len + 1); // 额外的 1 是给 '\0' 结束符
    if (!result) {
        fprintf(stderr, "Memory allocation failed in ConvertBinToString.\n");
        return NULL;  // 内存分配失败
    }

    size_t j = 0;

    // 如果是带空格或逗号的格式
    if (strchr(bin, ' ') || strchr(bin, ',')) {
        char* token;
        char* input = strdup(bin);  // 复制输入字符串
        if (!input) {
            free(result);
            fprintf(stderr, "Memory allocation failed in ConvertBinToString.\n");
            return NULL;  // 内存分配失败
        }

        token = strtok(input, " ,");
        while (token) {
            // 确保每个 token 是 8 位
            if (strlen(token) == 8) {
                unsigned char ch = 0;
                for (size_t i = 0; i < 8; i++) {
                    ch = (ch << 1) | (token[i] - '0'); // 计算二进制值
                }
                result[j++] = ch; // 将字符加入结果
            }
            token = strtok(NULL, " ,");
        }
        free(input);  // 释放内存
    }
    // 如果是没有空格或逗号的格式
    else {
        for (size_t i = 0; i < len; i += 8) {
            unsigned char ch = 0;
            for (size_t k = 0; k < 8; k++) {
                ch = (ch << 1) | (bin[i + k] - '0'); // 计算二进制值
            }
            result[j++] = ch; // 将字符加入结果
        }
    }

    result[j] = '\0';  // 字符串结尾
    return result;
}


// 将\x编码转化为可见字符字符串，并进行合法性校验
char* ConvertHexEscapeToString(const char* escaped) {
    size_t len = strlen(escaped);
    char* result = (char*)malloc(len + 1);
    if (!result) {
        fprintf(stderr, "Memory allocation failed in ConvertHexEscapeToString.\n");
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        if (escaped[i] == '\\' && i + 1 < len) {
            // 处理 \x 格式
            if (escaped[i + 1] == 'x' && i + 3 < len) {
                // 检查后面两个字符是否是合法的十六进制数字
                if (isxdigit(escaped[i + 2]) && isxdigit(escaped[i + 3])) {
                    unsigned int val;
                    if (sscanf(escaped + i + 2, "%2x", &val) == 1) {
                        result[j++] = (char)val;
                        i += 3; // 跳过 \x 和两位十六进制字符
                    } else {
                        free(result);
                        fprintf(stderr, "Failed to convert \\x escape sequence in ConvertHexEscapeToString.\n");
                        return NULL; // 如果转换失败，返回 NULL
                    }
                } else {
                    free(result);
                    fprintf(stderr, "Invalid hexadecimal characters following \\x in ConvertHexEscapeToString.\n");
                    return NULL; // 如果不是有效的十六进制字符，返回 NULL
                }
            } else {
                result[j++] = escaped[i]; // 如果不是 \x 格式，就直接存入
            }
        } else {
            result[j++] = escaped[i]; // 普通字符直接存入
        }
    }
    result[j] = '\0'; // 结束符
    return result;
}

// 将 URL 编码转化为可见字符字符串，并进行合法性校验
char* ConvertUrlToString(const char* url) {
    size_t len = strlen(url);
    char* result = (char*)malloc(len + 1); // 最坏情况下，字符数不会增加
    if (!result) {
        fprintf(stderr, "Memory allocation failed in ConvertUrlToString.\n");
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        if (url[i] == '%' && i + 2 < len) {
            // 检查 % 后面是否是合法的十六进制字符
            if (isxdigit(url[i + 1]) && isxdigit(url[i + 2])) {
                char hex[3] = { url[i + 1], url[i + 2], '\0' };
                result[j++] = (char)strtol(hex, NULL, 16); // 将 %xx 转换为字符
                i += 2; // 跳过百分号和两个十六进制字符
            } else {
                free(result);
                fprintf(stderr, "Invalid hexadecimal characters following %% in ConvertUrlToString.\n");
                return NULL; // 如果 % 后面不是有效的十六进制字符，返回 NULL
            }
        } else {
            result[j++] = url[i]; // 普通字符直接存入
        }
    }
    result[j] = '\0'; // 结束符
    return result;
}



