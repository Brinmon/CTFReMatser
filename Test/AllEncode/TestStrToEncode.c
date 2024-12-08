#include "../include/StrToEncode.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    const char* input = "Hello, World!";

    // 测试 ConvertStringToHex
    char* hex = ConvertStringToHex(input,1);
    printf("Hex: %s\n", hex);
    free(hex);
    // 测试 ConvertStringToHex
    char* hex1 = ConvertStringToHex(input,0);
    printf("Hex: %s\n", hex1);
    free(hex1);

    // 测试 ConvertStringToDec
    char* dec = ConvertStringToDec(input,1);
    printf("Dec: %s\n", dec);
    free(dec);
    // 测试 ConvertStringToDec
    char* dec1 = ConvertStringToDec(input,0);
    printf("Dec: %s\n", dec1);
    free(dec1);

    // 测试 ConvertStringToBin
    char* bin = ConvertStringToBin(input,1);
    printf("Bin: %s\n", bin);
    free(bin);
    // 测试 ConvertStringToBin
    char* bin1 = ConvertStringToBin(input,0);
    printf("Bin: %s\n", bin1);
    free(bin1);

    char* hexEscape = ConvertStringToHexEscape(input);
    printf("Hex escape format: %s\n", hexEscape);
    free(hexEscape); // 释放分配的内存

    char* urlEncoded = ConvertStringToUrlEncode(input);
    printf("URL Encoded format: %s\n", urlEncoded);
    free(urlEncoded); // 释放分配的内存

    return 0;
}