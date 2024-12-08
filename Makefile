

# # 程序名
# PROGRAM = TestEncodeToStr          # 默认目标程序名

# # 源代码文件和目标文件映射
# SRC = main.c $(wildcard AllEncode/*.c) $(wildcard Test/AllEncode/*.c) $(wildcard XorCrypter/*.c)
# OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# # 默认目标
# all: $(BIN_DIR)/$(PROGRAM)

# # 目标：编译源代码文件
# $(OBJ_DIR)/%.o: %.c
# 	@mkdir -p $(OBJ_DIR)               # 确保目标文件目录存在
# 	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@  # 编译源文件为目标文件

# # 目标：链接目标文件生成可执行文件
# $(BIN_DIR)/$(PROGRAM): $(OBJ)
# 	@mkdir -p $(BIN_DIR)               # 确保可执行文件目录存在
# 	$(CC) $(OBJ) -o $@                 # 链接所有目标文件生成可执行文件

# # 目标：清理编译生成的文件
# clean:
# 	rm -rf $(OBJ_DIR) $(BIN_DIR)

# # 目标：根据不同程序名进行编译
# program:
# 	$(MAKE) PROGRAM=TestEncodeToStr
# 	$(MAKE) PROGRAM=TestStrToEncode


# 定义变量
# 编译器
CC = gcc
# 编译选项
CFLAGS = -Wall -g
# 中间文件目录
OBJ_DIR = build/obj
BIN_DIR = build/bin
UNIT_TEST_DIR = Test
INCLUDE_DIR = include

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

all: TestEncodeToStr TestStrToEncode

# 目标：清理编译生成的文件
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)