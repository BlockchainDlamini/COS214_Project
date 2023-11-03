# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++2a -Wall

# Source directory
SRC_DIR := .

# Get a list of all .cpp files in the source directory
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Object files will be generated in the same directory as source files
OBJS := $(SRCS:.cpp=.o)

# Executable name
TARGET := myprogram

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Generate object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean