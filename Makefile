# Nom de l'exécutable
TARGET = build/main

# Liste des fichiers sources
SRC = main.cpp $(wildcard engine/*.cpp) $(wildcard entities/*.cpp)

# Flags de compilation
CXX = g++
CXXFLAGS = -std=c++11 $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf

# Règle par défaut
all: build_dir $(TARGET) exec

# Règle pour créer le dossier build
build_dir:
	mkdir -p build

exec:
	./build/main

# Règle de compilation
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Règle de nettoyage
clean:
	rm -f $(TARGET)

