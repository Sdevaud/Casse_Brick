CXX      = g++
CXXFLAGS = -g -std=c++23 -Wall -Iinclude

SRC_DIR  = src
OBJ_DIR  = executable
BIN_DIR  = executable

SRC      = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJ      = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter $(SRC_DIR)/%.cpp,$(SRC))) \
           $(OBJ_DIR)/main.o

TARGET   = $(BIN_DIR)/main.exe

all: clean $(TARGET) run

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/main.o: main.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)