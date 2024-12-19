#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp) {
    int index; // 用来遍历数组
    FILE *fileStream; // 文件流
    char data[24]; // 用来存储从文件读取的字节数据

    // 打开文件 "flag" 以读取数据
    fileStream = fopen("flag", "r");
    
    // 检查文件是否成功打开
    if (fileStream == NULL) {
        perror("Failed to open file");
        return -1;
    }

    // 从文件中读取 20 字节数据
    fread(data, 1, 20, fileStream);
    fclose(fileStream); // 读取完成后关闭文件

    // 对数据进行处理并打印
    for (index = 1; index <= 19; ++index) {
        if (index % 2 != 0) {
            // 如果下标为奇数，则左移
            printf("%ld\n", (data[index] << index));
        } else {
            // 如果下标为偶数，则进行乘法
            printf("%ld\n", (index * data[index]));
        }
    }
    return 0;
}
