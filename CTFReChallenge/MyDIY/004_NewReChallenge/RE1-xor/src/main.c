#include <stdio.h>
#include <string.h>

#define FLAG_LENGTH 33
#define MAX_INPUT_SIZE 256

// 假设 global 是一个预定义的标志，长度为 33 字节
unsigned char global[FLAG_LENGTH] = {
  0x66, 0x0A, 0x6B, 0x0C, 0x77, 0x26, 0x4F, 0x2E, 0x40, 0x11, 
  0x78, 0x0D, 0x5A, 0x3B, 0x55, 0x11, 0x70, 0x19, 0x46, 0x1F, 
  0x76, 0x22, 0x4D, 0x23, 0x44, 0x0E, 0x67, 0x06, 0x68, 0x0F, 
  0x47, 0x32, 0x4F
};


// 读取输入行
void get_input_line(char *buffer, size_t buffer_size) {
    fgets(buffer, buffer_size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // 去掉换行符
}

int main(int argc, char **argv, char **envp) {
    int i;
    char input[MAX_INPUT_SIZE];

    // 初始化输入缓冲区
    memset(input, 0, sizeof(input));

    // 提示用户输入
    printf("Please enter your flag:\n");

    // 获取用户输入
    get_input_line(input, sizeof(input));

    // 检查输入长度是否为33字节
    if (strlen(input) != FLAG_LENGTH) { 
        printf("Failed\n");
        return 0;
    }

    // 对输入进行逐字符异或操作
    for (i = 1; i < FLAG_LENGTH; ++i) {
        input[i] ^= input[i - 1];  // input[i] = input[i] ^ input[i-1]
    }

    // //输出input的内容以16进制输出
    // for (i = 1; i < FLAG_LENGTH; ++i) {
    //     printf("%02x", input[i]);
    // }
    // printf("--------------------\n");
    
    // 检查处理后的输入是否与 global 字符串匹配
    if (strncmp(input, global, FLAG_LENGTH - 1) == 0) {
        printf("Success\n");
    } else {
        printf("Failed\n");
    }

    return 0;
}
