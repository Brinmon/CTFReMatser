# 编译器
CC = gcc
# 编译选项
CFLAGS = -Wall -g
# 中间文件目录
OBJ_DIR = build/obj
BIN_DIR = build/bin
UNIT_TEST_DIR = Test
INCLUDE_DIR = include


# AllEncode篇
ALLENCODEWORK_DIR = AllEncode
EncodeToStr.o:
	@mkdir -p $(OBJ_DIR)/$(ALLENCODEWORK_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR)/ -c $(ALLENCODEWORK_DIR)/EncodeToStr.c -o $(OBJ_DIR)/$(ALLENCODEWORK_DIR)/EncodeToStr.o

TestEncodeToStr.o :
	@mkdir -p $(OBJ_DIR)/$(ALLENCODEWORK_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR)/ -c $(UNIT_TEST_DIR)/$(ALLENCODEWORK_DIR)/TestEncodeToStr.c -o $(OBJ_DIR)/$(ALLENCODEWORK_DIR)/TestEncodeToStr.o

TestEncodeToStr: TestEncodeToStr.o EncodeToStr.o
	@mkdir -p $(BIN_DIR)/$(ALLENCODEWORK_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR)/ -o $(BIN_DIR)/$(ALLENCODEWORK_DIR)/TestEncodeToStr $(OBJ_DIR)/$(ALLENCODEWORK_DIR)/TestEncodeToStr.o $(OBJ_DIR)/$(ALLENCODEWORK_DIR)/EncodeToStr.o


# 编译 StrToEncode.o (包含实现)
StrToEncode.o:
	@mkdir -p $(OBJ_DIR)/$(ALLENCODEWORK_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR)/ -c $(ALLENCODEWORK_DIR)/StrToEncode.c -o $(OBJ_DIR)/$(ALLENCODEWORK_DIR)/StrToEncode.o

# 编译 TestStrToEncode.o
TestStrToEncode.o :
	@mkdir -p $(OBJ_DIR)/$(ALLENCODEWORK_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR)/ -c $(UNIT_TEST_DIR)/$(ALLENCODEWORK_DIR)/TestStrToEncode.c -o $(OBJ_DIR)/$(ALLENCODEWORK_DIR)/TestStrToEncode.o

# 链接阶段，确保包括 StrToEncode.o
TestStrToEncode: TestStrToEncode.o StrToEncode.o
	@mkdir -p $(BIN_DIR)/$(ALLENCODEWORK_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR)/ -o $(BIN_DIR)/$(ALLENCODEWORK_DIR)/TestStrToEncode $(OBJ_DIR)/$(ALLENCODEWORK_DIR)/TestStrToEncode.o $(OBJ_DIR)/$(ALLENCODEWORK_DIR)/StrToEncode.o

allencode: TestEncodeToStr TestStrToEncode


# XorCrypter篇
XorCrypterWORK_DIR = XorCrypter

XorCrypter.o: 
	@mkdir -p $(OBJ_DIR)/$(XorCrypterWORK_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR)/ -c $(XorCrypterWORK_DIR)/XorCrypter.c -o $(OBJ_DIR)/$(XorCrypterWORK_DIR)/XorCrypter.o

TestXorCrypter.o:
	@mkdir -p $(OBJ_DIR)/$(XorCrypterWORK_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR)/ -c $(UNIT_TEST_DIR)/$(XorCrypterWORK_DIR)/TestXorCrypter.c -o $(OBJ_DIR)/$(XorCrypterWORK_DIR)/TestXorCrypter.o

TestXorCrypter: TestXorCrypter.o XorCrypter.o StrToEncode.o
	@mkdir -p $(BIN_DIR)/$(XorCrypterWORK_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR)/ -o $(BIN_DIR)/$(XorCrypterWORK_DIR)/TestXorCrypter $(OBJ_DIR)/$(XorCrypterWORK_DIR)/TestXorCrypter.o $(OBJ_DIR)/$(XorCrypterWORK_DIR)/XorCrypter.o $(OBJ_DIR)/$(ALLENCODEWORK_DIR)/StrToEncode.o


xorcrypter : TestXorCrypter





# 目标：清理编译生成的文件
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)