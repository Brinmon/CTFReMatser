#include <stdio.h>
#include <stdlib.h>

// 第一个退出函数
void exit_function1(void) {
    printf("This is exit function 1.\n");
}

// 第二个退出函数
void exit_function2(void) {
    printf("This is exit function 2.\n");
}

// 第三个退出函数
void exit_function3(void) {
    printf("This is exit function 3.\n");
}

// 将退出函数添加到 _fini_array
__attribute__((section(".fini_array"))) void (*exit_func1)(void) = exit_function1;
__attribute__((section(".fini_array"))) void (*exit_func2)(void) = exit_function2;
__attribute__((section(".fini_array"))) void (*exit_func3)(void) = exit_function3;

int main() {
    printf("Main function starts.\n");

    // 其他程序逻辑
    // ...

    printf("Main function ends.\n");
    return 0;
}
