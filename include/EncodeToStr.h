#ifndef ENCODETOSTR_H
#define ENCODETOSTR_H

/**
 * 将16进制的字符串转换为可见字符字符串。
 * 例如: "68656c6c6f" -> "hello"
 *
 * @param hex 16进制字符串（例如 "68656c6c6f"）
 * @return 转换后的可见字符字符串（需要调用者释放内存）
 */
char* ConvertHexToString(const char* hex);

/**
 * 将10进制字符串转换为可见字符字符串。
 * 例如: "72" -> "H"
 *
 * @param dec 10进制字符串（例如 "72"）
 * @return 转换后的可见字符字符串（需要调用者释放内存）
 */
char* ConvertDecToString(const char* dec);

/**
 * 将二进制字符串转换为可见字符字符串。
 * 支持带空格和不带空格的格式。还会进行合法性校验。
 * 例如: "0100100001100101011011000110110001101111" -> "hello"
 *       或 "01001000 01100101 01101100 01101100 01101111" -> "hello"
 *
 * @param bin 二进制字符串（例如 "01001000 01100101 01101100 01101100 01101111"）
 * @return 转换后的可见字符字符串（需要调用者释放内存）
 */
char* ConvertBinToString(const char* bin);

/**
 * 将 \x 编码转换为可见字符字符串。
 * 例如: "\\x48\\x65\\x6c\\x6c\\x6f" -> "Hello"
 *
 * @param escaped 包含 \x 编码的字符串（例如 "\\x48\\x65\\x6c\\x6c\\x6f"）
 * @return 转换后的可见字符字符串（需要调用者释放内存）
 */
char* ConvertHexEscapeToString(const char* escaped);

/**
 * 将 URL 编码转换为可见字符字符串。
 * 例如: "Hello%20World%21" -> "Hello World!"
 *
 * @param url URL 编码字符串（例如 "Hello%20World%21"）
 * @return 转换后的可见字符字符串（需要调用者释放内存）
 */
char* ConvertUrlToString(const char* url);

#endif // ENCODETOSTR_H
