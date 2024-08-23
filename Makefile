# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++17 -Wall

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
DATA_DIR = data

# Source Files
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/HuffmanTree.cpp $(SRC_DIR)/Compression.cpp $(SRC_DIR)/Decompression.cpp

# Output Binary
TARGET = $(BUILD_DIR)/huffman_coding

# Build Target
$(TARGET): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $(SRC_FILES) -o $(TARGET)

# Clean up the build
clean:
	rm -rf $(BUILD_DIR)/*

# Phony Targets
.PHONY: clean
