#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define OPCODE_SIZE 96
#define MMAP_ADDRESS 0x23000
#define MMAP_SIZE 0x1000

unsigned char opcodes[] =
{
  0x00, 0x81, 0x42, 0x26, 0x3C, 0x08, 0x02, 0x01, 0x35, 0x28, 
  0x3A, 0x03, 0x24, 0x0B, 0x02, 0x16, 0x24, 0x0A, 0x02, 0x03, 
  0x11, 0x61, 0x02, 0x05, 0x00, 0x01, 0x02, 0x03, 0x21, 0x28, 
  0x02, 0x02, 0x21, 0x09, 0x02, 0x02, 0x21, 0x4B, 0xFD, 0xFC, 
  0x11, 0x41, 0x02, 0x09, 0x00, 0x01, 0x02, 0x03, 0x01, 0x8D, 
  0x62, 0x25, 0x01, 0xAC, 0x6A, 0x25, 0x81, 0x2D, 0x02, 0x03, 
  0x81, 0x0C, 0x02, 0x03, 0x01, 0x8B, 0x62, 0x25, 0x01, 0xAD, 
  0x6A, 0x25, 0x11, 0xA1, 0xFD, 0xF7, 0x00, 0x01, 0x02, 0x03, 
  0x24, 0x0A, 0x02, 0x02, 0x01, 0x61, 0x12, 0x26, 0x03, 0xE1, 
  0x02, 0x0B, 0x00, 0x01, 0x02, 0x03
};

char input[32];

int main(int argc, const char **argv, const char **envp) {
    // Constant string initialization
    const char constantString[] = "sxrujtv`labiVzbp`vpg|";
    memset(input, 0, sizeof(input));

    // Allocate a page of executable memory
    void* mappedMemory = mmap((void*)MMAP_ADDRESS, MMAP_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mappedMemory == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    // Modify opcodes
    unsigned char* opcodePointer = opcodes;
    for (int i = 0; i < OPCODE_SIZE; ++i) {
        unsigned char value = i & 3 ^ *opcodePointer;
        *opcodePointer++ = value;  //这里在修改opcodePointer的指向后想要输出数据必须把指向修改回来
        // printf("%d", value);
    }

    // Output the modified opcodes in array format
    printf("Modified opcodes in array format:\n");
    printf("unsigned char opcodes[96] = {\n");
    for (int i = 0; i < 96; ++i) {
        printf("0x%02X", opcodes[i]);
        if (i < 95) {
            printf(", ");
        }
        if ((i + 1) % 16 == 0 && i < 95) {
            printf("\n");
        }
    }
    printf("\n};\n");

    // Fork process
    pid_t childPid = fork();
    if (childPid > 0) { // Parent process waits for child process to finish
        int status;
        while (waitpid(childPid, &status, WNOHANG) == 0) {
            sleep(1);
        }
    } else if (childPid == 0) { // Child process
        opcodePointer = opcodes;
        unsigned char* destination = (unsigned char*)mappedMemory;

        // Copy opcodes to mapped memory
        while (opcodePointer != &opcodes[OPCODE_SIZE]) {
            memcpy(destination, opcodePointer, 4);
            opcodePointer += 4;
            destination += 4;
        }

        // Set specific values in mapped memory
        destination[512] = constantString[0];
        destination[513] = constantString[1];
        destination[514] = constantString[2];
        destination[515] = constantString[3];
        destination[516] = constantString[4];
        *(destination + 2068) = (constantString[5] >> 8) & 0xFF; // Store high byte of constantString[5]

        // Prompt user for input
        puts("input your flag, be fast:");
        ssize_t bytesRead = read(0, input, sizeof(input) - 1);
        if (bytesRead <= 0 || bytesRead != 22) {
            write(1, "\xF0\x9F\x98\xA0\n", 5); // Output emoji
        } else {
            input[bytesRead] = '\0'; // Null-terminate the input
            // if (((int (*)(const char*))mappedMemory)(input)) {
            //     write(1, "wrong\n", 7);
            // } else {
            //     write(1, "right\n", 7);
            // }
        }
    } else {
        perror("fork failed");
        return 1;
    }

    return 0;
}





// #include <stdio.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/mman.h>

// unsigned char opcodes[] =
// {
//   0x00, 0x81, 0x42, 0x26, 0x3C, 0x08, 0x02, 0x01, 0x35, 0x28, 
//   0x3A, 0x03, 0x24, 0x0B, 0x02, 0x16, 0x24, 0x0A, 0x02, 0x03, 
//   0x11, 0x61, 0x02, 0x05, 0x00, 0x01, 0x02, 0x03, 0x21, 0x28, 
//   0x02, 0x02, 0x21, 0x09, 0x02, 0x02, 0x21, 0x4B, 0xFD, 0xFC, 
//   0x11, 0x41, 0x02, 0x09, 0x00, 0x01, 0x02, 0x03, 0x01, 0x8D, 
//   0x62, 0x25, 0x01, 0xAC, 0x6A, 0x25, 0x81, 0x2D, 0x02, 0x03, 
//   0x81, 0x0C, 0x02, 0x03, 0x01, 0x8B, 0x62, 0x25, 0x01, 0xAD, 
//   0x6A, 0x25, 0x11, 0xA1, 0xFD, 0xF7, 0x00, 0x01, 0x02, 0x03, 
//   0x24, 0x0A, 0x02, 0x02, 0x01, 0x61, 0x12, 0x26, 0x03, 0xE1, 
//   0x02, 0x0B, 0x00, 0x01, 0x02, 0x03
// };

// void processMemoryAndData() {
//     char destinationBuffer[21];
//     char sourceString[] = "sxrujtvlabiVzbpvpg|";
//     memset(destinationBuffer, 0, sizeof(destinationBuffer));

//     // Allocate a page of executable memory
//     void* executableMemory = mmap((void*)0x23000, 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
//     if (executableMemory == MAP_FAILED) {
//         // Handle error
//         return;
//     }

//     unsigned char* opcodePointer = (unsigned char*)&opcodes;
//     for (int i = 0; i < 96; ++i) {
//         unsigned char value = i & 3 ^ *opcodePointer;
//         *opcodePointer++ = value;
//     }

//     // Output the modified opcodes in array format
//     printf("Modified opcodes in array format:\n");
//     printf("unsigned char opcodes[96] = {\n");
//     opcodePointer = (unsigned char*)&opcodes; // Reset pointer to start of opcodes array
//     for (int i = 0; i < 96; ++i) {
//         printf("0x%02X", *opcodePointer++);
//         if (i < 95) {
//             printf(", ");
//         }
//         if ((i + 1) % 16 == 0 && i < 95) {
//             printf("\n");
//         }
//     }
//     printf("\n};\n");
// }

// int main() {
//     processMemoryAndData();
//     printf("父进程: 创建子进程\n");
//     pid_t pid = fork();  // 创建子进程,子进程和父进程从这里开始产生差异

//     if (pid) {
//         // 父进程代码
//         pid_t v9;
//         do {
//             v9 = waitpid(pid, NULL, WNOHANG);  // 等待子进程结束
//             sleep(1);  // 暂停 1 秒钟
//         } while (v9 == 0);  // 子进程未结束时继续等待

//         printf("父进程: 子进程已结束\n");
//     } else {
//         // 子进程代码
//         printf("子进程: 执行任务\n");
//         exit(0);  // 子进程退出
//     }

//     return 0;
// }
