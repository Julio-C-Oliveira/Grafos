CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = graph

SOURCES = main.cpp Base/base.cpp Algoritmos/fleury.cpp Algoritmos/dfs.cpp
OBJECTS = main.o Base/base.o Algoritmos/fleury.o Algoritmos/dfs.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
