CXX = g++
CXXFLAGS = -Wall -Wextra -O3 -march=native -Iinclude
TARGET = kv

SRC = main.cpp $(wildcard src/*.cpp)
OBJ = $(patsubst %.cpp, obj/%.o, $(notdir $(SRC)))

all: $(TARGET)

$(TARGET): $(OBJ)
		$(CXX) $(OBJ) -o $(TARGET)

obj/%.o: src/%.cpp | obj
		$(CXX) $(CXXFLAGS) -c $< -o $@

obj/main.o: main.cpp | obj
		$(CXX) $(CXXFLAGS) -c $< -o $@

obj:
		mkdir -p obj

clean:
		rm -rf obj database.txt $(TARGET)