CXX = gcc
CXXFLAGS = -std=c++17 -g -MMD -Wall
LDFLAGS =
LBLIBS =
HEADERDIRS := $(CURDIR)/includes $(CURDIR)/../Extern/glad/include
HEADERDIRS := $(patsubst %,-I%,$(HEADERDIRS))

SRC_DIR := $(CURDIR)/src/3dPlayground-Core
OBJ_DIR := $(CURDIR)/obj/3dPlayground-Core
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES)) 
EXEC := $(CURDIR)/lib/3dPlayground-Core/3dPlayground-Core.a
DEPENDS = $(OBJ_FILES:.o=.d)

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	ar $(LDFLAGS) rcs $@ $^ $(LBLIBS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(HEADERDIRS) -c -o $@ $<

-include $(DEPENDS)

clean:
	rm $(OBJ_FILES) $(EXEC) $(DEPENDS)

print:
	@echo Object files and executable
	@echo $(OBJ_FILES) $(EXEC)
	@echo DEPENDS
	@echo $(DEPENDS)