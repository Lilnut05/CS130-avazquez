CXX = g++

CXXFLAGS = -std=c++11 -Wall

TARGET = Final

# Source files
SRC = Final.cpp

$(TARGET): Functions.o Final.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) Functions.o Final.o

Final.o: Final.cpp Final.h
	$(CXX) $(CXXFLAGS) -c Final.cpp

Functions.o: Functions.cpp Final.h
	$(CXX) $(CXXFLAGS) -c Functions.cpp

# Clean rule to remove generated files
clean:
	rm -f *.o $(TARGET)


