#include <stdio.h>

// 第一个初始化函数
__attribute__((constructor)) void init_function1(void) {
    printf("Initializing system resources: function 1.\n");
}

// 第二个初始化函数
__attribute__((constructor)) void init_function2(void) {
    printf("Initializing system resources: function 2.\n");
}

// 第三个初始化函数
__attribute__((constructor)) void init_function3(void) {
    printf("Initializing system resources: function 3.\n");
}

int main() {
    printf("Main function starts.\n");

    // 其他程序逻辑
    // ...

    printf("Main function ends.\n");
    return 0;
}
