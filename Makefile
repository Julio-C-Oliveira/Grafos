CC = gcc
CFLAGS = -Wall -Wextra -std=c17 # -Wall é pra alguns avisos na compilação, -Wextra é pra detalhes sobre a compilação e alguns avisos e recomendações.
# LDFLAGS =
TARGET = graph

SRC_DIR = .
BASE_DIR = Base
SEARCH_DIR = Algoritmos_de_Busca
EXTRA_DIR = Algoritmos_Extras

# SOURCES = main.c Base/adjacentListGraph.c Base/adjacentMatrizGraph.c Algoritmos_de_Busca/dfs.c Algoritmos_de_Busca/bfs.c Algoritmos_Extras/fleury.c
SOURCES = \
	$(SRC_DIR)/main.c \
	$(BASE_DIR)/adjacentListGraph.c \
	$(BASE_DIR)/adjacentMatrizGraph.c \
	$(SEARCH_DIR)/dfs.c \
	$(SEARCH_DIR)/bfs.c \
	$(EXTRA_DIR)/fleury.c

# OBJECTS = main.o Base/adjacentListGraph.o Base/adjacentMatrizGraph.o Algoritmos_de_Busca/dfs.o Algoritmos_de_Busca/bfs.o Algoritmos_Extras/fleury.o
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
