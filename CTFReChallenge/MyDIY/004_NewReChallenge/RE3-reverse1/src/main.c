#include <stdio.h>
#include <string.h>

// 提示用户输入信息
void prompt_input(const char *message) {
    printf("%s", message);
}

// 初始化标志字符串，将每4个字节设为-858993460
void initialize_flag_string(char *flag_str) {
    for (int i = 0; i < 82; i++) {
        *(int *)(flag_str + i * 4) = -858993460;  // 初始化值为-858993460，可能是为了后续的安全检查
    }
}

// 替换预定义标志字符串中的指定字符（例如将字符'o'替换为'0'）
void replace_character_in_flag(char *flag_str, char target, char replacement) {
    size_t j = 0;
    // 遍历字符串直到遇到结束符
    while (flag_str[j] != '\0') {
        if (flag_str[j] == target) {
            flag_str[j] = replacement;  // 替换字符
        }
        j++;
    }
}

int main(int argc, const char **argv, const char **envp) {
    char flag_str[224];  // 用于存储用户输入的标志字符串
    char predefined_flag[224] = "{hello_world}"; // 预定义的目标标志
    size_t flag_length;  // 预定义标志的长度

    // 初始化标志字符串
    initialize_flag_string(flag_str);

    // 对预定义标志进行字符替换（例如将'o'替换为'0'）
    replace_character_in_flag(predefined_flag, 111, 48);  // 将字符'o'（ASCII值为111）替换为字符'0'（ASCII值为48）

    // 提示用户输入标志
    prompt_input("Input the flag: ");
    scanf("%20s", flag_str);  // 读取用户输入的标志字符串（最大长度为20）

    // 获取预定义标志的长度
    flag_length = strlen(predefined_flag);

    // 比较用户输入的标志与预定义标志
    if (strncmp(flag_str, predefined_flag, flag_length) == 0) {
        // 如果匹配，输出正确的标志信息
        prompt_input("This is the right flag!\n");
    } else {
        // 如果不匹配，输出错误的标志信息
        prompt_input("Wrong flag\n");
    }

    return 0;
}
