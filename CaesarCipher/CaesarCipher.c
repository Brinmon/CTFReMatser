#include "../include/CaesarCipher.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 加密函数
void caesar_encrypt(char* text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // 处理大写字母
        if (isupper(ch)) {
            text[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // 处理小写字母
        else if (islower(ch)) {
            text[i] = (ch - 'a' + shift) % 26 + 'a';
        }
    }
}

// 解密函数
void caesar_decrypt(char* text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // 处理大写字母
        if (isupper(ch)) {
            text[i] = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // 处理小写字母
        else if (islower(ch)) {
            text[i] = (ch - 'a' - shift + 26) % 26 + 'a';
        }
    }
}
