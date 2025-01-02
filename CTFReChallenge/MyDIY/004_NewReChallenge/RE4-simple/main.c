#include <stdio.h>
#include <string.h>

int main() {
    char input[100];  // 存储用户输入的字符串
    const char target[] = "flag{123456789}";  // 目标字符串

    // 提示用户输入字符串
    printf("please input flag: ");
    scanf("%99s", input);  // 读取用户输入，限制最大输入长度为99

    // 比较输入的字符串与目标字符串
    if (strcmp(input, target) == 0) {
        printf("you get flag\n");
    } else {
        printf("Faild\n");
    }

    return 0;
}
