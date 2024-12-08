#include "../include/EncodeToStr.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    const char* DecSpaceStr = "072 101 108 108 111 044 032 087 111 114 108 100 033";
    const char* DecStr = "072101108108111044032087111114108100033";
    char* dectostring = ConvertDecToString(DecSpaceStr);
    char* dectostring1 = ConvertDecToString(DecStr);
    printf("dectostring: %s\n", dectostring);
    printf("dectostring1: %s\n", dectostring1);
    free(dectostring);
    free(dectostring1);

    const char* binWithSpace = "01001000 01100101 01101100 01101100 01101111 00101100 00100000 01010111 01101111 01110010 01101100 01100100 00100001"; 
    const char* binWithoutSpace = "01001000011001010110110001101100011011110010110000100000010101110110111101110010011011000110010000100001";  
    char* debintostring = ConvertBinToString(binWithSpace);
    char* debintostring1 = ConvertBinToString(binWithoutSpace);
    printf("binWithSpace: %s\n", debintostring);
    printf("binWithoutSpace : %s\n", debintostring1);
    free(debintostring);
    free(debintostring1);

    const char* hexWithSpace = "48 65 6C 6C 6F 2C 20 57 6F 72 6C 64 21";  // "Hello"
    const char* hexWithoutSpace = "48656C6C6F2C20576F726C6421";  // "Hello"

    // 检查带空格的16进制字符串是否合法并转换
    char* str = ConvertHexToString(hexWithSpace);
    // 检查不带空格的16进制字符串是否合法并转换
    char* str2 = ConvertHexToString(hexWithoutSpace);
    printf("hexWithSpace : %s\n", str);
    free(str);
    printf("hexWithoutSpace : %s\n", str2);
    free(str2);

    // 合法的 \x 编码字符串
    const char* escapedStr = "\\x48\\x65\\x6c\\x6c\\x6f"; // "Hello" 的 \x 编码
    char* result = ConvertHexEscapeToString(escapedStr);
    printf("转换结果: %s\n", result); // 期望输出 "Hello"
    free(result); // 释放动态分配的内存    

    const char* urlStr = "Hello%20World%21"; // "Hello World!"
    char* result1 = ConvertUrlToString(urlStr);
    printf("转换结果: %s\n", result1); // 期望输出 "Hello World!"
    free(result1); // 释放动态分配的内存

    return 0;
}