#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // 包含 read 函数的头文件
#include "../../../../include/base64.h"

const char* expectedEncodedData = "Vm0wd2VHUXhTWGhpUm1SWVYwZDRWVll3Wkc5WFJsbDNXa1pPVlUxV2NIcFhhMk0xVmpKS1NHVkdXbFpOYmtKVVZtcEtTMUl5VGtsaVJtUk9ZV3hhZVZadGVHdFRNVTVYVW01T2FGSnRVbGhhVjNoaFZWWmtWMXBFVWxSTmJFcElWbTAxVDJGV1NuTlhia0pXWWxob1dGUnJXbXRXTVZaeVdrWm9hVlpyV1hwV1IzaGhXVmRHVjFOdVVsWmlhMHBZV1ZSR1lWZEdVbFZTYlhSWFRWWndNRlZ0TVc5VWJGcFZWbXR3VjJKSFVYZFdha1pXWlZaT2NtRkhhRk5pVjJoWVYxZDBhMVV3TlhOalJscFlZbGhTY1ZsclduZGxiR1J5VmxSR1ZXSlZjRWhaTUZKaFZqSktWVkZZYUZkV1JWcFlWV3BHYTFkWFRrZFRiV3hvVFVoQ1dsWXhaRFJpTWtsM1RVaG9hbEpYYUhOVmJUVkRZekZhY1ZKcmRGTk5Wa3A2VjJ0U1ExWlhTbFpqUldoYVRVWndkbFpxUmtwbGJVWklZVVprYUdFeGNHOVhXSEJIWkRGS2RGSnJhR2hTYXpWdlZGVm9RMlJzV25STldHUlZUVlpXTlZadE5VOVdiVXBJVld4c1dtSllUWGhXTUZwell6RmFkRkpzVWxOaVNFSktWa1phVTFFeFduUlRhMlJxVWxad1YxWnRlRXRXTVZaSFVsUnNVVlZVTURrPQ==";

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

// 验证处理后的数据是否与目标数据匹配
int compare_data(const char *processed_data, const char *target_data) {
    printf("\nProcessed data:\n %s", processed_data);
    printf("\nTarget data:\n %s", target_data);
    return strcmp(processed_data, target_data) == 0;
}

int main(int argc, char **argv) {
    char keystring[36];
    char userInputKey3[37];

    memcpy(keystring, "Iodl>Qnb(ocy\x7Fy.i", 16);
    keystring[16] = 127;
    memcpy(&keystring[17], "d`3w}wek9{iy=~yL@EC", 19);

    memset(userInputKey3, 0, sizeof(userInputKey3));
    read(0, &userInputKey3, 0x24); // 读取用户输入，并确保不会溢出
    // 丢弃标准输入流中的多余数据
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // 只丢弃直到换行符或文件结束
    }
    // 计算userInputKey3的长度
    int userInputKey3Len = strlen(userInputKey3);
    printf("Test string contains carriage return: %s\n", contains_newline(userInputKey3) ? "True" : "False");
    printf("userInputKey3Len: %d\n", userInputKey3Len);

    if (userInputKey3Len == 36) {
        printf("inputlen is right!\n");
        for (int i = 0; i < 36; i++) {
            if ((userInputKey3[i] ^ i) != keystring[i]) {  //遇到的问题:(userInputKey3[i] ^ i) != keystring[i] 和 userInputKey3[i] ^ i != keystring[i] 不同
                                                           //由于 ^ 运算符的优先级低于 != 运算符，因此 if 语句实际执行的逻辑是:userInputKey3[i] ^ (i != keystring[i])
                // printf("i is %d\n",i);
                // printf("arr1 is %d\n",userInputKey3[i] ^ i);
                // printf("arr2 is %d\n",keystring[i]);
                printf("input is wrong!\n");
                return 0;
            }
        }
    } else {
        printf("inputlen is wrong!\n");
        return 0;
    }

    char userInputKey4[39];
    char *encodedData = NULL;
    char *currentData = NULL;

    memset(userInputKey4, 0, sizeof(userInputKey4));
    puts("continue!Please input your flag:");
    read(0, userInputKey4, 39);
    printf("Test string contains carriage return: %s\n", contains_newline(userInputKey4) ? "True" : "False");
    printf("userInputKey4: %s\n", userInputKey4);
    int userInputKey4Len = strlen(userInputKey4);
    printf("userInputKey4Len: %d\n", userInputKey4Len);
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // 只丢弃直到换行符或文件结束
    }
    if (userInputKey4Len == 39) {
        // 对数据进行 10 次 base64 编码
        currentData = userInputKey4;
        for (int i = 0; i < 10; i++) {
            encodedData = base64_encode(currentData, strlen(currentData));  // 编码数据
            currentData = encodedData;  // 更新当前数据为最新的编码结果
        }
        // 检查结果是否匹配任何目标数据
        if (compare_data(currentData,expectedEncodedData)) {
            printf("Congratulations! The flag is correct.\n");
        } else {
            printf("Sorry, the flag is incorrect.\n");
        }
    }

    return 0;
}
