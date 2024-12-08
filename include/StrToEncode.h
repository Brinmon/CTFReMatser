// StrToEncode.h
#ifndef STRTOENCODE_H
#define STRTOENCODE_H

// 将字符串转换为十六进制格式，并返回转换后的字符串
// 参数:
//   const char* input: 输入的原始字符串
//   int addSpace: 控制输出格式：
//     0 - 不添加空格或逗号分隔
//     1 - 使用空格分隔每两个十六进制字符
//     2 - 使用逗号分隔每两个十六进制字符
// 返回值: 转换后的十六进制字符串
char* ConvertStringToHex(const char* input, int addSpace);

// 将字符串转换为十进制格式，并返回转换后的字符串
// 参数:
//   const char* input: 输入的原始字符串
//   int addSpace: 控制输出格式：
//     0 - 不添加空格或逗号分隔
//     1 - 使用空格分隔每三个十进制数字
//     2 - 使用逗号分隔每三个十进制数字
// 返回值: 转换后的十进制字符串
char* ConvertStringToDec(const char* input, int addSpace);

// 将字符串转换为二进制格式，并返回转换后的字符串
// 参数:
//   const char* input: 输入的原始字符串
//   int addSpace: 控制输出格式：
//     0 - 不添加空格或逗号分隔
//     1 - 使用空格分隔每八个二进制位
//     2 - 使用逗号分隔每八个二进制位
// 返回值: 转换后的二进制字符串
char* ConvertStringToBin(const char* input, int addSpace);

// 将字符串转换为带转义的十六进制格式，并返回转换后的字符串
// 参数:
//   const char* input: 输入的原始字符串
// 返回值: 转换后的带转义的十六进制字符串（例如 \x48\x65\x6c\x6c\x6f）
char* ConvertStringToHexEscape(const char* input);

// 将字符串进行 URL 编码，并返回编码后的字符串
// 参数:
//   const char* input: 输入的原始字符串
// 返回值: URL 编码后的字符串
char* ConvertStringToUrlEncode(const char* input);

#endif // STRTOENCODE_H