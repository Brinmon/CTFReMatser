## 本体采用的逆向防御技术

### 1. 主动防御
本题的main函数中都不是真正需要逆向的位置,需要锁定目标代码的位置,在无任何提示的情况下

### 2. Linux的init_arry和fini_arry的利用
```c
// 将退出函数添加到 _fini_array
__attribute__((section(".fini_array"))) void (*exit_func3)(void) = exit_function3;


// 获取当前时间戳并将其赋值给 targetTimestamp,将代码添加到init_array
__attribute__((constructor)) time_t getCurrentTimestamp() {
    time_t currentTimestamp;  // 存储当前时间戳

    // 获取当前时间戳
    currentTimestamp = time(NULL);
    
    // 将当前时间戳赋值给全局变量 targetTimestamp
    targetTimestamp = currentTimestamp;

    return currentTimestamp;  // 返回当前时间戳
}
```

### 3.异或加密

### 4.base64编码
