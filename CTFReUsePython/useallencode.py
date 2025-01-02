# 在 useallencode.py 中导入 HandlerAllEncode 中的函数
from Data_HandlerByPython.HandlerAllEncode import *

# 测试数据
hex_string_with_spaces_commas = "48 65 6C 6C 6F 2C 20 57 6F 72 6C 64 21"
hex_string_without_spaces_commas = "48656C6C6F2C20576F726C6421"

# 测试数据
hex_string_with_spaces_commas = "48 65 6C 6C 6F 2C 20 57 6F 72 6C 64 21"
hex_string_without_spaces_commas = "48656C6C6F2C20576F726C6421"
hex_string_with_commas_only = "48,65,6C,6C,6F,2C,20,57,6F,72,6C,64,21"

decimal_with_spaces_commas = "072 101 108 108 111 044 032 087 111 114 108 100 033"
decimal_without_spaces_commas = "072101108108111044032087111114108100033"
decimal_with_commas_only = "072,101,108,108,111,044,032,087,111,114,108,100,033"

binary_with_spaces_commas = "01001000 01100101 01101100 01101100 01101111 00101100 00100000 01010111 01101111 01110010 01101100 01100100 00100001"
binary_without_spaces_commas = "01001000011001010110110001101100011011110010110000100000010101110110111101110010011011000110010000100001"
binary_with_commas_only = "01001000,01100101,01101100,01101100,01101111,00101100,00100000,01010111,01101111,01110010,01101100,01100100,00100001"

# 测试调用
print("Hex with spaces and commas:", convert_to_int_list(hex_string_with_spaces_commas, 'hex'))
print("Hex without spaces or commas:", convert_to_int_list(hex_string_without_spaces_commas, 'hex'))
print("Hex with commas only:", convert_to_int_list(hex_string_with_commas_only, 'hex'))

print("Decimal with spaces and commas:", convert_to_int_list(decimal_with_spaces_commas, 'dec'))
print("Decimal without spaces or commas:", convert_to_int_list(decimal_without_spaces_commas, 'dec'))
print("Decimal with commas only:", convert_to_int_list(decimal_with_commas_only, 'dec'))

print("Binary with spaces and commas:", convert_to_int_list(binary_with_spaces_commas, 'bin'))
print("Binary without spaces or commas:", convert_to_int_list(binary_without_spaces_commas, 'bin'))
print("Binary with commas only:", convert_to_int_list(binary_with_commas_only, 'bin'))
