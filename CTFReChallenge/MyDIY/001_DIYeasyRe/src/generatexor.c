#include "../../../../include/XorCrypter.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    char  key1[36] = { 0 };
    for (int i = 0; i < 36; i++) {
        key1[i] = i;
    }

    char* data1 = "Info:The first four chars are `flag`";
    // 加密数据
    xor_encrypt_decrypt(data1, 36, key1, 36);
    printf("EncryptedData: %s\n", data1);

    // 加密数据
    xor_encrypt_decrypt(data1, 36, key1, 36);
    printf("DecryptData: %s\n", data1);

}