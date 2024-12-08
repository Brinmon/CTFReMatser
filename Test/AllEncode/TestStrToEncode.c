#include "../include/StrToEncode.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    const char* inputString = "Hello, World!";
    // 计算输入字符串的长度
    int maxLen = strlen(inputString);
    // 测试 ConvertStringToHex 函数
    char* hexWithSpacesAndCommas = ConvertStringToHex(inputString, 1,maxLen);
    printf("Hex with spaces and commas: %s\n", hexWithSpacesAndCommas);
    free(hexWithSpacesAndCommas);

    char* hexWithoutSpacesOrCommas = ConvertStringToHex(inputString, 0,maxLen);
    printf("Hex without spaces or commas: %s\n", hexWithoutSpacesOrCommas);
    free(hexWithoutSpacesOrCommas);

    char* hexWithCommasOnly = ConvertStringToHex(inputString, 2,maxLen);
    printf("Hex with commas only: %s\n", hexWithCommasOnly);
    free(hexWithCommasOnly);

    // 测试 ConvertStringToDec 函数
    char* decWithSpacesAndCommas = ConvertStringToDec(inputString, 1,maxLen);
    printf("Decimal with spaces and commas: %s\n", decWithSpacesAndCommas);
    free(decWithSpacesAndCommas);

    char* decWithoutSpacesOrCommas = ConvertStringToDec(inputString, 0,maxLen);
    printf("Decimal without spaces or commas: %s\n", decWithoutSpacesOrCommas);
    free(decWithoutSpacesOrCommas);

    char* decWithCommasOnly = ConvertStringToDec(inputString, 2,maxLen);
    printf("Decimal with commas only: %s\n", decWithCommasOnly);
    free(decWithCommasOnly);

    // 测试 ConvertStringToBin 函数
    char* binWithSpacesAndCommas = ConvertStringToBin(inputString, 1,maxLen);
    printf("Binary with spaces and commas: %s\n", binWithSpacesAndCommas);
    free(binWithSpacesAndCommas);

    char* binWithoutSpacesOrCommas = ConvertStringToBin(inputString, 0,maxLen);
    printf("Binary without spaces or commas: %s\n", binWithoutSpacesOrCommas);
    free(binWithoutSpacesOrCommas);

    char* binWithCommasOnly = ConvertStringToBin(inputString, 2,maxLen);
    printf("Binary with commas only: %s\n", binWithCommasOnly);
    free(binWithCommasOnly);

    // 测试 ConvertStringToHexEscape 函数
    char* hexEscapeFormat = ConvertStringToHexEscape(inputString);
    printf("Hex escape format: %s\n", hexEscapeFormat);
    free(hexEscapeFormat); // 释放分配的内存

    // 测试 ConvertStringToUrlEncode 函数
    char* urlEncodedFormat = ConvertStringToUrlEncode(inputString);
    printf("URL Encoded format: %s\n", urlEncodedFormat);
    free(urlEncodedFormat); // 释放分配的内存

    return 0;
}



