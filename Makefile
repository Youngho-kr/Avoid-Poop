CC = g++
CFLAGS = -std=c++11
SRC_DIR = src
BUILD_DIR = build
TARGET = poop.exe

# SRC_DIR에 존재하는 모든 .cpp 파일 
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

$(TARGET):$(OBJ)
	$(CC) $^ -o $@ -lncurses

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: clean