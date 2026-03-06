CXX      = g++
CXXFLAGS = -g -std=c++23 -Wall -Iinclude -Itest_txt $(shell pkg-config --cflags gtkmm-4.0)
LDLIBS   = $(shell pkg-config --libs gtkmm-4.0)

SRC_DIR  = src
OBJ_DIR  = executable
BIN_DIR  = executable

SRC      = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJ      = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter $(SRC_DIR)/%.cpp,$(SRC))) \
           $(OBJ_DIR)/main.o

TARGET   = $(BIN_DIR)/main.exe

all: $(TARGET) run

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CXX) $(OBJ) -o $@ $(LDLIBS)

$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)