CXX      = g++
CXXFLAGS = -g -std=c++23 -Wall -Iinclude -Itest_txt $(shell pkg-config --cflags gtkmm-4.0)
LDLIBS   = $(shell pkg-config --libs gtkmm-4.0)

SRC_DIR  = src
OBJ_DIR  = bin
TEST_DIR = test

SRC      = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)

OBJ      = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter $(SRC_DIR)/%.cpp,$(SRC))) \
           $(OBJ_DIR)/main.o
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter $(TEST_DIR)/%.cpp,$(TEST_SRC)))

TARGET   = $(OBJ_DIR)/main.exe
TEST_TARGET = $(OBJ_DIR)/test.exe



all: clean $(TARGET)

$(TARGET): $(OBJ) | $(OBJ_DIR)
	$(CXX) $(OBJ) -o $@ $(LDLIBS)

$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)



$(TEST_TARGET): $(TEST_OBJ) | $(OBJ_DIR)
	$(CXX) $(TEST_OBJ) -o $@ $(LDLIBS)

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: clean $(TEST_TARGET)

run_test: $(TEST_TARGET)
	./$(TEST_TARGET)


clean:
	rm -rf $(OBJ_DIR)