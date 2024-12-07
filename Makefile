CC = gcc  # 编译器
CFLAGS = -Wall -g  # 编译选项，开启所有警告并带有调试信息

# 目标文件和可执行文件的存放目录
OBJ_DIR = build/obj  # 目标文件存放目录
EXEC_DIR = build/bin  # 可执行文件存放目录

# 确保目录存在
$(shell mkdir -p $(OBJ_DIR) $(EXEC_DIR))

# StrToEncode 可执行文件
EXEC1 = $(EXEC_DIR)/TestStrToEncode  
SRC1 = AllEncode/StrToEncode.c AllEncode/TestStrToEncode.c
OBJ_FILES1 = $(patsubst AllEncode/%.c,$(OBJ_DIR)/%.o,$(SRC1))

# EncodeToStr 可执行文件
EXEC2 = $(EXEC_DIR)/TestEncodeToStr  
SRC2 = AllEncode/EncodeToStr.c AllEncode/TestEncodeToStr.c
OBJ_FILES2 = $(patsubst AllEncode/%.c,$(OBJ_DIR)/%.o,$(SRC2))

# 默认目标
all: $(EXEC1) $(EXEC2)

# 生成可执行文件
$(EXEC1): $(OBJ_FILES1)
	@echo "Linking $@"
	$(CC) $(CFLAGS) -o $@ $^

$(EXEC2): $(OBJ_FILES2)
	@echo "Linking $@"
	$(CC) $(CFLAGS) -o $@ $^

# 生成目标文件，将 .o 文件存放在 OBJ_DIR 目录中
$(OBJ_DIR)/%.o: AllEncode/%.c | $(OBJ_DIR)
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

# 确保目录存在
$(OBJ_DIR):
	@mkdir -p $@

# 清理目标文件和可执行文件
clean:
	@echo "Cleaning up..."
	rm -rf $(EXEC_DIR) $(OBJ_DIR)

# 伪目标
.PHONY: all clean debug

# 检查源文件是否存在
ifeq ($(wildcard $(SRC1) $(SRC2)),)
$(error Source files not found in AllEncode directory)
endif

# 显示详细的构建信息（调试用）
print-%: ; @echo $* = $($*)

# 调试信息
debug: print-OBJ_DIR print-EXEC_DIR print-SRC1 print-SRC2 print-OBJ_FILES1 print-OBJ_FILES2