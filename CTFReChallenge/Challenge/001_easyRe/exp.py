key1=[0x40,0x35,0x20,0x56,0x5D,0x18,0x22,0x45,0x17,0x2F,0x24,0x6E,0x62,0x3C,0x27,0x54,0x48,0x6C,0x24,0x6E,0x72,0x3C,0x32,0x45,0x5B]
key2='flag'
v2=[]
flag=''
for x in range(4):
    v2.append(key1[x] ^ ord(key2[x]))
print(v2)
# 定义字节列表
byte_list = v2

# 转换为字节对象
byte_data = bytes(byte_list)

# 将字节对象转换为整数，假设是大端字节序
integer_value = int.from_bytes(byte_data, byteorder='big')

# 输出结果
print(integer_value)

for i in range(len(key1)):
    print(chr(v2[i%4]^key1[i]),end='')