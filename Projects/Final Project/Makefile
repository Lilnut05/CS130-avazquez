CXX = g++

CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = .exe

# list .cpp files separated by space
CPPFILES = Final.cpp

# make all rule/default rule that'll be run when we run "make"
# first compile each file to object file
# then make a single binary/executable program
build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

# make clean rule
# delete object and binary files
clean:
	rm -f $(PROGRAM) *.o

# FIXED
run:
	./$(PROGRAM)

# add a rule to run the program

# rule to run unittest
unittest:
	./$(PROGRAM) "test"

all: build unittest clean
	@echo "All done!"
	