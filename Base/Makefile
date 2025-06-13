# Compilador C++
CXX = g++

# Opções de compilação
CXXFLAGS = -Wall -std=c++17

# Executavelmente gerado
TARGET = grafo

# Arquivos-fonte
SOURCES = main.cpp node.cpp

# Objetos correspondentes
OBJECTS = $(SOURCES:.cpp=.o)

# Regra principal
all: $(TARGET)

# Como linkar o executavelmente
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Como compilar cada .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Limpar os artefatos de compilação
clean:
	rm -f $(OBJECTS) $(TARGET)