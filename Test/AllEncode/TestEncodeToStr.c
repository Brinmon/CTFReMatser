#include "../include/EncodeToStr.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    // 测试十进制字符串转换
    const char* decSpaceStr = "072 101 108 108 111 044 032 087 111 114 108 100 033";
    const char* decStr = "072101108108111044032087111114108100033";
    const char* decStrCommas = "072,101,108,108,111,044,032,087,111,114,108,100,033";

    char* decToString = ConvertDecToString(decSpaceStr);
    printf("Converted decimal string with spaces: %s\n", decToString);
    free(decToString);

    char* decToString1 = ConvertDecToString(decStr);
    printf("Converted decimal string without spaces or commas: %s\n", decToString1);
    free(decToString1);

    char* decToString2 = ConvertDecToString(decStrCommas);
    printf("Converted decimal string with commas: %s\n", decToString2);
    free(decToString2);

    // 测试二进制字符串转换
    const char* binWithSpace = "01001000 01100101 01101100 01101100 01101111 00101100 00100000 01010111 01101111 01110010 01101100 01100100 00100001"; 
    const char* binWithoutSpace = "01001000011001010110110001101100011011110010110000100000010101110110111101110010011011000110010000100001";  
    const char* binWithoutCommas = "01001000,01100101,01101100,01101100 ,01101111,00101100, 00100000,01010111 ,01101111,01110010,01101100,01100100,00100001";

    char* binToString = ConvertBinToString(binWithSpace);
    printf("Converted binary string with spaces: %s\n", binToString);
    free(binToString);

    char* binToString1 = ConvertBinToString(binWithoutSpace);
    printf("Converted binary string without spaces or commas: %s\n", binToString1);
    free(binToString1);

    char* binToString2 = ConvertBinToString(binWithoutCommas);
    printf("Converted binary string with commas: %s\n", binToString2);
    free(binToString2);

    // 测试十六进制字符串转换
    const char* hexWithSpace = "48 65 6C 6C 6F 2C 20 57 6F 72 6C 64 21";  // "Hello"
    const char* hexWithoutSpace = "48656C6C6F2C20576F726C6421";  // "Hello"
    const char* hexWithoutCommas = "48, 65,6C ,6C, 6F,2C, 20,57 ,6F, 72,6C,64,21";

    char* hexToString = ConvertHexToString(hexWithSpace);
    printf("Converted hexadecimal string with spaces: %s\n", hexToString);
    free(hexToString);

    char* hexToString1 = ConvertHexToString(hexWithoutSpace);
    printf("Converted hexadecimal string without spaces or commas: %s\n", hexToString1);
    free(hexToString1);

    char* hexToString2 = ConvertHexToString(hexWithoutCommas);
    printf("Converted hexadecimal string with commas: %s\n", hexToString2);
    free(hexToString2);

    // 测试 \x 编码字符串转换
    const char* escapedStr = "\x48\x65\x6c\x6c\x6f\x2c\x20\x57\x6f\x72\x6c\x64\x21"; // "Hello" 的 \x 编码
    char* result = ConvertHexEscapeToString(escapedStr);
    printf("Converted \\x encoded string: %s\n", result); // 期望输出 "Hello"
    free(result); // 释放动态分配的内存    

    const char* escapedStr1 = "\\x48\\x65\\x6c\\x6c\\x6f\\x2c\\x20\\x57\\x6f\\x72\\x6c\\x64\\x21"; // "Hello" 的 \x 编码
    char* result2 = ConvertHexEscapeToString(escapedStr1);
    printf("Converted \\\\x encoded string: %s\n", result2); // 期望输出 "Hello"
    free(result2); // 释放动态分配的内存   

    // 测试 URL 编码字符串转换
    const char* urlStr = "Hello%20World%21"; // "Hello World!"
    char* result1 = ConvertUrlToString(urlStr);
    printf("Converted URL encoded string: %s\n", result1); // 期望输出 "Hello World!"
    free(result1); // 释放动态分配的内存

    return 0;
}



