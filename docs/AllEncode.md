# AllEncode CTFReMaster 编码篇

## 简单使用
```bash
#在项目根目录直接使用
make allencode
```

文件代码结构:
```bash
├── AllEncode
│   ├── EncodeToStr.c
│   └── StrToEncode.c
├── build
│   └── bin
│       └── AllEncode
│           ├── TestEncodeToStr
│           └── TestStrToEncode
├── include
│   ├── EncodeToStr.h
│   └── StrToEncode.h
├── Test
    ├── AllEncode
        ├── TestEncodeToStr.c
        └── TestStrToEncode.c
```

## 简单函数api介绍
### 数字转可见字符
1. **`ConvertHexToString`, 参数: `const char* hex`, 作用: 将16进制字符串转换为可见字符字符串。**
2. **`ConvertDecToString`, 参数: `const char* dec`, 作用: 将10进制字符串转换为可见字符字符串。**
3. **`ConvertBinToString`, 参数: `const char* bin`, 作用: 将二进制字符串转换为可见字符字符串，支持带空格和不带空格的格式，并进行合法性校验。**
4. **`ConvertHexEscapeToString`, 参数: `const char* escaped`, 作用: 将包含 `\x` 编码的字符串转换为可见字符字符串。**
5. **`ConvertUrlToString`, 参数: `const char* url`, 作用: 将URL编码的字符串转换为可见字符字符串。**


### 可见字符转数字
1. **`ConvertStringToHex`, 参数: `const char* input, int addSpace`, 作用: 将字符串转换为十六进制格式字符串。**
2. **`ConvertStringToDec`, 参数: `const char* input, int addSpace`, 作用: 将字符串转换为十进制格式字符串。**
3. **`ConvertStringToBin`, 参数: `const char* input, int addSpace`, 作用: 将字符串转换为二进制格式字符串。**
4. **`ConvertStringToHexEscape`, 参数: `const char* input`, 作用: 将字符串转换为带转义的十六进制格式字符串。**
5. **`ConvertStringToUrlEncode`, 参数: `const char* input`, 作用: 将字符串进行 URL 编码。**