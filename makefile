# Define the compiler and compilation flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Define the bin directory
BIN_DIR = bin

# Automatically find all cpp files and generate corresponding executables in bin/
SOURCES = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, $(BIN_DIR)/%, $(SOURCES))

# Default target: build all executables
all: $(TARGETS)

# Pattern rule: compile each cpp file into bin/<name>
$(BIN_DIR)/%: %.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# Run a specific game: Usage: make run TARGET_NAME=<executable_name>
# For example, "make run TARGET_NAME=pig" will run bin/pig
run:
	./$(BIN_DIR)/$(TARGET_NAME)

# Clean up generated files
clean:
	rm -rf $(BIN_DIR)
