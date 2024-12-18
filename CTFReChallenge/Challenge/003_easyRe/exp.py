from Crypto.Cipher import AES, DES

input_31=0xc4
aim = [0xBD, 0xAD, 0xB4, 0x84, 0x10, 0x63, 0xB3, 0xE1, 0xC6, 0x84, 
  0x2D, 0x6F, 0xBA, 0x88, 0x74, 0xC4, 0x90, 0x32, 0xEA, 0x2E, 
  0xC6, 0x28, 0x65, 0x70, 0xC9, 0x75, 0x78, 0xA0, 0x0B, 0x9F, 
  0xA6, 0x00]
print(len(aim))

tmp = [0 for i in range(32)]
tmp[31] = input_31
possible = []
def test_flag(i, tmp):
	if i == -1:   #i==-1说明已经爆破完成！
		possible.append(tmp[:])
		print(tmp)
		return
	_tmp = tmp[:]
	for j in range(256): #从后0xc4往前爆破！
		if ((((2 * (j ^0x13)) + 7) ^ ((j % 9) + _tmp[i+1] + 2))&0xff) == aim[i]:
			_tmp[i] = j
			test_flag(i-1,_tmp)
		if j == 255 and ((((2 * (j ^0x13)) + 7) ^ ((j % 9) + _tmp[i+1] + 2))&0xff) != aim[i]:
			return

test_flag(30, tmp)

key = b"\xAD\x52\xF2\x4C\xE3\x2C\x20\xD6"
text = b"\x0A\xF4\xEE\xC8\x42\x8A\x9B\xDB\xA2\x26\x6F\xEE\xEE\xE0\xD8\xA2"
iv = b"\x00"*8
aes_key = DES.new(key, DES.MODE_CBC, iv).decrypt(text)
print(f'key: {aes_key}')

for x in possible:
	for i in range(31, -1, -1):
		for j in range(int(i/4)):
			x[i] ^= x[j]
	tmp = AES.new(aes_key, AES.MODE_ECB).decrypt(bytes(x))
	print(tmp)