CXX = g++
CXXFLAGS = -std="c++17"
TARGET = output
SRC = $(wildcard *.cpp)

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)