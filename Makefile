CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = graph

SOURCES = main.cpp Base/adjacentListGraph.cpp Base/adjacentMatrizGraph.cpp
OBJECTS = main.o Base/adjacentListGraph.o Base/adjacentMatrizGraph.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
