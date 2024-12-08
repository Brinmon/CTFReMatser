# MakeFile的编写说明
```d
# 编译器
CC = gcc
# 编译选项
CFLAGS = -Wall -g
# 中间文件目录
OBJ_DIR = build/obj
BIN_DIR = build/bin
UNIT_TEST_DIR = Test
INCLUDE_DIR = include
```
常量的相关定义,编译器,编译选项,中间文件目录,可执行文件目录,单元测试目录,头文件目录


# AllEncode篇的makefile部分
```
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
```
这部分的makefile主要是完成以下命令:
```bash
┌──(kali㉿kali)-[~/GithubProject/CTFReMatser]
└─$ make allencode
gcc -Wall -g -I include/ -c Test/AllEncode/TestEncodeToStr.c -o build/obj/AllEncode/TestEncodeToStr.o
gcc -Wall -g -I include/ -c AllEncode/EncodeToStr.c -o build/obj/AllEncode/EncodeToStr.o
gcc -Wall -g -I include/ -o build/bin/AllEncode/TestEncodeToStr build/obj/AllEncode/TestEncodeToStr.o build/obj/AllEncode/EncodeToStr.o
gcc -Wall -g -I include/ -c Test/AllEncode/TestStrToEncode.c -o build/obj/AllEncode/TestStrToEncode.o
gcc -Wall -g -I include/ -c AllEncode/StrToEncode.c -o build/obj/AllEncode/StrToEncode.o
gcc -Wall -g -I include/ -o build/bin/AllEncode/TestStrToEncode build/obj/AllEncode/TestStrToEncode.o build/obj/AllEncode/StrToEncode.o
```


## 清理所有编译痕迹的部分
```
# 目标：清理编译生成的文件
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
```