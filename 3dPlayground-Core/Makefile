CXX = g++
CXXFLAGS = -std=c++11 -g -MMD
LDFLAGS =
LBLIBS =
HEADERDIRS := $(CURDIR)/includes/
HEADERDIRS := $(patsubst %,-I%,$(HEADERDIRS))

SRC_DIR := $(CURDIR)/src/3dPlayground-Core/utils
OBJ_DIR := $(CURDIR)/obj/3dPlayground-Core/utils
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES)) 
EXEC := $(CURDIR)/lib/3dPlayground-Core/utils/3dPlayground-Core.a
DEPENDS = $(OBJ_FILES:.o=.d)

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	ar rcs $@ $^ $(LBLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(HEADERDIRS) -c -o $@ $<

-include $(DEPENDS)

clean:
	del $(subst /,\,$(OBJ_FILES) $(EXEC))

print:
	@echo Object files and executable
	@echo $(OBJ_FILES) $(EXEC)
	@echo DEPENDS
	@echo $(DEPENDS)