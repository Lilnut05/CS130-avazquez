CXX = g++

CXXFLAGS = -std=c++11 -Wall
# the build target executable file; .exe is not required
PROGRAM = Final

# list .cpp files separated by space
SRC = Functions.cpp Final.cpp

# Rule to create the final executable
$(PROGRAM): Final.o Functions.o
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) Final.o Functions.o

Final.o: Final.cpp Final.h
	$(CXX) $(CXXFLAGS) -c Final.cpp

run:
	./$(PROGRAM)

# make clean rule
# delete object and binary files
clean:
	rm -f $(PROGRAM) *.o


