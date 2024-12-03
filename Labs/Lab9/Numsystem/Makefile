# compiler name
CXX = g++
# g++ compiler flags
# -g: adds debugging information to the executable file
# -Wall: turns on most, but not  all, compiler warnings
# -std=c++17: uses c++17 standard
# put all the required flags separated by space
CXXFLAGS = -c -g -Wall -std=gnu++17

# the build target executable file; .exe is not required
PROGRAM = main.exe #FIXED

# list .cpp files separated by space
CPPFILES = numberSystem.cpp #FIXED

# make all rule/default rule that'll be run when we run "make"
# first compile each file to object file
# then make a single binary/executable program
build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

# make clean rule
# delete object and binary files
clean:
	@rm -f $(PROGRAM) *.o

# FIXED - add rule to run unittest functions
unittest:
	@./$(PROGRAM) test

all: build test clean
	@echo "All done!"