CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = lab3

SOURCES = main.cpp Tests.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Tests.o: Tests.cpp
	$(CXX) $(CXXFLAGS) -c Tests.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean all

.PHONY: all run clean rebuild
