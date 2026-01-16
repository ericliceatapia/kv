CXX = g++
CXXFLAGS = -Wall -Wextra -O3 -march=native -Iinclude
TARGET = kv

DB_FILE = database.txt
OBJ_DIR = obj
SRC_DIR = src

SRCS = main.cpp $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))

$(TARGET): $(OBJS)
		$(CXX) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

clean:
		rm -rf $(OBJ_DIR) $(DB_FILE) $(TARGET)

.PHONY: clean