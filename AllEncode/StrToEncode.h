// StrToEncode.h
#ifndef STRTOENCODE_H
#define STRTOENCODE_H

// 将字符串转换为十六进制格式，并返回转换后的字符串
char* ConvertStringToHex(const char* input, int addSpace);

// 将字符串转换为十进制格式，并返回转换后的字符串
char* ConvertStringToDec(const char* input, int addSpace);

// 将字符串转换为二进制格式，并返回转换后的字符串
char* ConvertStringToBin(const char* input, int addSpace);

// 将字符串转换为带转义的十六进制格式，并返回转换后的字符串
char* ConvertStringToHexEscape(const char* input);

// 将字符串进行 URL 编码，并返回编码后的字符串
char* ConvertStringToUrlEncode(const char* input);
#endif
