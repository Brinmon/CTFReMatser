enc = b'sxrujtv`labiVzbp`vpg|'
enc = bytearray(enc)
i = 0
j = 21

for _ in range(21):
    enc[i] ^= j
    i += 1
    j -= 1

print(enc)