CXX = g++
CXXFLAGS = -Wall -Iinclude -std=c++17
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Archivos fuente y objetos intermedios
SRCS = $(filter-out $(SRC_DIR)/main_encoded.cpp $(SRC_DIR)/main_decoded.cpp, $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Archivos main y sus ejecutables correspondientes
MAIN_ENCODED = $(SRC_DIR)/main_encoded.cpp
MAIN_DECODED = $(SRC_DIR)/main_decoded.cpp
TARGET_ENCODED = $(BIN_DIR)/huffman_encoded
TARGET_DECODED = $(BIN_DIR)/huffman_decoded

# Regla principal que compila ambos objetivos
all: $(TARGET_ENCODED) $(TARGET_DECODED)

# Regla para compilar el objetivo huffman_encoded
$(TARGET_ENCODED): $(OBJS) $(OBJ_DIR)/main_encoded.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar el objetivo huffman_decoded
$(TARGET_DECODED): $(OBJS) $(OBJ_DIR)/main_decoded.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Reglas para compilar los archivos .cpp a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear los directorios si no existen
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Limpiar archivos generados
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(TARGET_ENCODED) $(TARGET_DECODED)

