import base64

# base64解码
encoded_str = "SGVsbG8sIFdvcmxkI"

# 添加填充符，使其长度符合 Base64 编码的要求
encoded_str = encoded_str + "=" * ((4 - len(encoded_str) % 4) % 4)

# 解码
decoded_str = base64.b64decode(encoded_str).decode('utf-8')

# 输出解码后的结果
print(decoded_str)
