# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -g

# Directory for build artifacts
BUILD_DIR = ./build

# Target executable and source files
TARGET = $(BUILD_DIR)/main
SOURCES = main.c 
HEADERS = main.h 

# Default target: build the executable
$(TARGET): $(SOURCES) $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Create the build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean target: remove build artifacts
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Run target: build and run the executable
.PHONY: run
run: $(TARGET)
	@$(TARGET)

