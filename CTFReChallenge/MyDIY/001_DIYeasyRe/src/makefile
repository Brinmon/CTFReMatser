# 使用 bash 作为 shell
SHELL := /bin/bash

# 编译器
CC = gcc
# 编译选项
CFLAGS = -Wall -g
# 中间文件目录
OBJ_DIR = build/obj
BIN_DIR = build/bin
UNIT_TEST_DIR = Test
INCLUDE_DIR = include


001_DIYeasyRe: 001_DIYeasyRe.o base64.o
	gcc 001_DIYeasyRe.o ../../../../$(OBJ_DIR)/$(BASEENCODEWORK_DIR)/base64.o -o 001_DIYeasyRe

generatexor: XorCrypter.o generatexor.o
	gcc ../../../../$(OBJ_DIR)/$(XorCrypterWORK_DIR)/XorCrypter.o generatexor.o -o generatexor

#BaseEncode 编码篇
BASEENCODEWORK_DIR = BaseEncode

# 目标：生成 base64.o 文件
base64.o:
	@pushd ../../../../ && $(CC) $(CFLAGS) -I $(INCLUDE_DIR)/ -c $(BASEENCODEWORK_DIR)/base64.c -o $(OBJ_DIR)/$(BASEENCODEWORK_DIR)/base64.o && popd


# XorCrypter篇
XorCrypterWORK_DIR = XorCrypter

XorCrypter.o: 
	@pushd ../../../../ && $(CC) $(CFLAGS) -I $(INCLUDE_DIR)/ -c $(XorCrypterWORK_DIR)/XorCrypter.c -o $(OBJ_DIR)/$(XorCrypterWORK_DIR)/XorCrypter.o && popd


001_DIYeasyRe.o : main.c
	gcc -c -o 001_DIYeasyRe.o main.c

generatexor.o : generatexor.c
	gcc -c -o generatexor.o generatexor.c

clean:
	rm ./001_DIYeasyRe ./001_DIYeasyRe.o ./generatexor ./generatexor.o