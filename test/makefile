CXX      = g++
CXXFLAGS = -g -std=c++23 -Wall -Iinclude

SRC_DIR  = src
OBJ_DIR  = executable
BIN_DIR  = executable

# sources: tout dans src/ + tes fichiers de test à la racine
SRC      = $(wildcard $(SRC_DIR)/*.cpp) test_main.cpp test.cpp

# objets correspondants dans executable/
OBJ      = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.cpp)) \
           $(OBJ_DIR)/test_main.o $(OBJ_DIR)/test.o

TARGET   = $(BIN_DIR)/test_main.exe

all: clean $(TARGET) run

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# compilation des .cpp à la racine
$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# compilation des .cpp dans src/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)