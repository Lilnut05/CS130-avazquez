# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Executable name
TARGET = fizzbuzz

# Source files
SRCS = main.cpp

# Default target: compile the program
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Run unit tests
unit_test:
	./$(TARGET) test

# run kattis test
kattis_test:
	./$(TARGET) < kattis_test.txt

# Run program with default input
run:
	./$(TARGET)

# Clean up
clean:
	rm -f $(TARGET)
