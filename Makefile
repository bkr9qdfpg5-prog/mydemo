# Makefile for mydemo project
# Author: Ken Lin (ken.lin@capgemini.com)
# 
# This Makefile provides standard targets for building and testing
# the myArray C++ template class implementation.

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
DEBUG_FLAGS = -g -O0

# Target executable
TARGET = myArray_test

# Source files
SOURCES = myArray_test.cpp
HEADERS = myArray.cpp

# Default target
all: $(TARGET)

# Build the test executable
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Build with debug symbols
# Note: Target-specific variable assignment only affects this target
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

# Run tests
test: $(TARGET)
	@echo "Running tests..."
	@./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET) *.o *.out a.out

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the test executable (default)"
	@echo "  test    - Build and run tests"
	@echo "  debug   - Build with debug symbols"
	@echo "  clean   - Remove build artifacts"
	@echo "  help    - Display this help message"

# Phony targets
.PHONY: all test clean debug help
