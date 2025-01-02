from Crypto.Cipher import DES

# 将 \x 数据转换为列表
key_list = [0xAD, 0x52, 0xF2, 0x4C, 0xE3, 0x2C, 0x20, 0xD6]
text_list = [
    0x0A, 0xF4, 0xEE, 0xC8, 0x42, 0x8A, 0x9B, 0xDB,
    0xA2, 0x26, 0x6F, 0xEE, 0xEE, 0xE0, 0xD8, 0xA2
]

# 将列表转换回字节串
key = bytes(key_list)
text = bytes(text_list)
iv = b"\x00" * 8

# 使用 DES 进行解密
aes_key = DES.new(key, DES.MODE_CBC, iv).decrypt(text)
print(f'key: {aes_key}')
