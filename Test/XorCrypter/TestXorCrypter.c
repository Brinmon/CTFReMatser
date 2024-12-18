#include "../../include/StrToEncode.h"
#include "../../include/XorCrypter.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    char  data[] = { 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x00, 0x20, 0x58, 0x4f, 0x52, 0x00, 0x45, 0x6e, 0x63, 0x72, 0x79 };
    size_t arr_length = sizeof(data) / sizeof(data[0]);
    // printf("arr_length: %ld\n",arr_length);

    // 测试 ConvertStringToHex 函数
    char* DataArr = ConvertStringToDec(data, 2,arr_length);
    printf("DataArr: %s\n", DataArr);
    free(DataArr);

    // 生成密钥
    size_t key_len = 8;  // 密钥长度
    unsigned char key[key_len];
    generate_key(key, key_len);

    // 加密数据
    xor_encrypt_decrypt(data, arr_length, key, key_len);
    char* EncryptedData = ConvertStringToDec(data, 1,arr_length);
    printf("EncryptedData: %s\n", EncryptedData);
    free(EncryptedData);

    // 加密数据
    xor_encrypt_decrypt(data, arr_length, key, key_len);
    char* DecryptData = ConvertStringToDec(data, 2,arr_length);
    printf("DecryptData: %s\n", DecryptData);
    free(DecryptData);

    // 测试 ConvertStringToHex 函数
    char* DataArr1 = ConvertStringToDec(data, 2,arr_length);
    printf("DataArr1: %s\n", DataArr1);
    free(DataArr1);
}