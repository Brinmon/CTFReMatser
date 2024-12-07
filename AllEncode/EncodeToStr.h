// foo.h
#ifndef ENCODETOSTR_H
#define ENCODETOSTR_H

//将16进制的字符串转换为可见字符字符串
char* ConvertHexToString(const char* hex);
// 将10进制字符串转化为可见字符字符串
char* ConvertDecToString(const char* dec);
// 将二进制字符串转化为可见字符字符串,可以判断字符串的合法性判断是否可以转换，可以接受两种格式的字符串有空个的和没空格的
char* ConvertBinToString(const char* bin);
// 将\x编码转化为可见字符字符串

// 将 URL 编码转化为可见字符字符串


#endif
