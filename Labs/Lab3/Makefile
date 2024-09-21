# Compiler name
CXX = g++

# C++ compiler flags
# -g : adds debugging information to the executable file
# -Wall : turns on most, but not all, compiler warnings
# -std=c++17 : uses C++17 standard
CXXFLAGS = -c -g -Wall -std=c++17

# The build target executable file
PROGRAM = distance_calculator

# List of .cpp files separated by space
CPPFILES = main.cpp

# Make build rule/default rule that will be run when we run "make"
# First compile each file to object file
# Then make a single binary program
all: $(PROGRAM)

# Rule to build the program
$(PROGRAM): $(CPPFILES:.cpp=.o)
	$(CXX) -o $(PROGRAM) $^

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $<

# Run the program
run: $(PROGRAM)
	./$(PROGRAM)

# Clean rule
# Delete object and binary files
clean:
	rm -f $(PROGRAM) *.o
