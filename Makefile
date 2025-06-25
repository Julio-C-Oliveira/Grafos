CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = graph

SOURCES = main.c Base/adjacentListGraph.c Base/adjacentMatrizGraph.c Algoritmos/dfs.c Algoritmos/bfs.c
OBJECTS = main.o Base/adjacentListGraph.o Base/adjacentMatrizGraph.o Algoritmos/dfs.o Algoritmos/bfs.c

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
