#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // 包含 read 函数的头文件

// 扩展函数用于检测字符串中是否包含任何类型的换行符（\r, \n, 或 \r\n）
int contains_newline(const char *str) {
    if (str == NULL) {
        return 0; // 如果传入的指针是NULL，返回0表示不包含换行符
    }

    while (*str) {
        if (*str == '\r' || *str == '\n') {
            return 1; // 如果找到任意一种换行符，返回1表示包含
        }
        str++;
    }
    return 0; // 遍历结束后如果没有找到换行符，返回0表示不包含
}

int main(int argc, char **argv) {
    char keystring[36];
    char userInputKey3[36];

    memcpy(keystring, "Iodl>Qnb(ocy\x7Fy.i", 16);
    keystring[16] = 127;
    memcpy(&keystring[17], "d`3w}wek9{iy=~yL@EC", 19);

    memset(userInputKey3, 0, sizeof(userInputKey3));
    read(0, &userInputKey3, 0x24); // 读取用户输入，并确保不会溢出

    // 计算userInputKey3的长度
    int userInputKey3Len = strlen(userInputKey3);
    printf("Test string contains carriage return: %s\n", contains_newline(userInputKey3) ? "True" : "False");
    printf("userInputKey3Len: %d\n", userInputKey3Len);

    if (userInputKey3Len == 36) {
        printf("inputlen is right!\n");
    } else {
        printf("inputlen is wrong!\n");
    }

    return 0;
}
