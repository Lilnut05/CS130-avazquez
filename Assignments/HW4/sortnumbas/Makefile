CXX = g++
CXXFLAGS = -Wall

TARGET = main
SRCS = main.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
run:
	./$(PROGRAM)
	
test: $(TARGET)
	./$(TARGET) test