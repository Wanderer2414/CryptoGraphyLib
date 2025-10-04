SRC_DIR := ./source/Base
BUILD_DIR := bin

SRCS := $(shell find $(SRC_DIR) -type f -name "*.cpp")
SOs := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.so,$(SRCS))

EXES := $(shell find . -type f -name "main.cpp")

all: $(SOs) $(basename $(EXES))

$(BUILD_DIR)/%.so: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	g++ -fPIC -shared -g $< -o $@

%: %.cpp
	g++ -g $< $(SOs) -o $@
	
clean:
	@rm -r bin/