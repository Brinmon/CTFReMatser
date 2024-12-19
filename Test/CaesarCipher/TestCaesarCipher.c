#include "../../include/CaesarCipher.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    // 定义一个明文字符串和偏移量
    char text[] = "Hello World";  // 测试字符串
    int shift = 3;  // 设置偏移量

    // 打印原始文本
    printf("原始文本: %s\n", text);

    // 调用加密函数
    caesar_encrypt(text, shift);
    printf("加密后的文本: %s\n", text);

    // 调用解密函数
    caesar_decrypt(text, shift);
    printf("解密后的文本: %s\n", text);

    return 0;
}
