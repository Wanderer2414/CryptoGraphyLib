# Compiler and flags
CXX := g++
CXXFLAGS := -fPIC
LDFLAGS := -shared

# Directories
SRC_DIR := source/Base/Binary
BUILD_DIR := bin

# Source files and corresponding .so targets
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
SOs := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.so,$(SRCS))

# Default target: build all .so files
all: $(SOs)

# Rule: build one .so from one .cpp
$(BUILD_DIR)/%.so: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $<

# Clean target
clean:
	rm -rf $(BUILD_DIR)/*

run: 
	g++ -g Set1/Challenge4/main.cpp bin/*.so -o main