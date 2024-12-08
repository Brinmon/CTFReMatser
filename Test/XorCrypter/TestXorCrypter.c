#include "../../include/StrToEncode.h"
#include "../../include/XorCrypter.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    const char  data[] = { 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x00, 0x20, 0x58, 0x4f, 0x52, 0x00, 0x45, 0x6e, 0x63, 0x72, 0x79 };
    size_t arr_length = sizeof(data) / sizeof(data[0]);
    // printf("arr_length: %ld\n",arr_length);
    // 测试 ConvertStringToHex 函数
    char* hexWithSpacesAndCommas = ConvertStringToHex(data, 1,arr_length);
    printf("Hex with spaces and commas: %s\n", hexWithSpacesAndCommas);
    free(hexWithSpacesAndCommas);
}