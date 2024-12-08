#include "../include/StrToEncode.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    const char* inputString = "Hello, World!";

    // 测试 ConvertStringToHex 函数
    char* hexWithSpacesAndCommas = ConvertStringToHex(inputString, 1);
    printf("Hex with spaces and commas: %s\n", hexWithSpacesAndCommas);
    free(hexWithSpacesAndCommas);

    char* hexWithoutSpacesOrCommas = ConvertStringToHex(inputString, 0);
    printf("Hex without spaces or commas: %s\n", hexWithoutSpacesOrCommas);
    free(hexWithoutSpacesOrCommas);

    char* hexWithCommasOnly = ConvertStringToHex(inputString, 2);
    printf("Hex with commas only: %s\n", hexWithCommasOnly);
    free(hexWithCommasOnly);

    // 测试 ConvertStringToDec 函数
    char* decWithSpacesAndCommas = ConvertStringToDec(inputString, 1);
    printf("Decimal with spaces and commas: %s\n", decWithSpacesAndCommas);
    free(decWithSpacesAndCommas);

    char* decWithoutSpacesOrCommas = ConvertStringToDec(inputString, 0);
    printf("Decimal without spaces or commas: %s\n", decWithoutSpacesOrCommas);
    free(decWithoutSpacesOrCommas);

    char* decWithCommasOnly = ConvertStringToDec(inputString, 2);
    printf("Decimal with commas only: %s\n", decWithCommasOnly);
    free(decWithCommasOnly);

    // 测试 ConvertStringToBin 函数
    char* binWithSpacesAndCommas = ConvertStringToBin(inputString, 1);
    printf("Binary with spaces and commas: %s\n", binWithSpacesAndCommas);
    free(binWithSpacesAndCommas);

    char* binWithoutSpacesOrCommas = ConvertStringToBin(inputString, 0);
    printf("Binary without spaces or commas: %s\n", binWithoutSpacesOrCommas);
    free(binWithoutSpacesOrCommas);

    char* binWithCommasOnly = ConvertStringToBin(inputString, 2);
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



