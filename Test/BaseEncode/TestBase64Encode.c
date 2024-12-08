#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/base64.h"

int main() {
    // 打印默认的 Base64 编码表
    print_base64_table();

    // 设置自定义的 Base64 编码表
    const char *custom_table = "ABCDEFGH@#IJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    initialize_base64_table(custom_table);

    // 打印自定义的 Base64 编码表
    print_base64_table();

    // 测试编码和解码
    const char *test_data = "Hello, World!";
    size_t length = strlen(test_data);

    // Base64 编码
    char *encoded = base64_encode((unsigned char*)test_data, length);
    printf("Encoded: %s\n", encoded);

    // Base64 解码
    size_t decoded_length;
    unsigned char *decoded = base64_decode(encoded, &decoded_length);
    if (decoded) {
        printf("Decoded: %.*s\n", (int)decoded_length, decoded);
        free(decoded);
    } else {
        printf("Base64 decoding failed.\n");
    }

    free(encoded);
    return 0;
}
