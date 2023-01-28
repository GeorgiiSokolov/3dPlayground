CXX = g++
CXXFLAGS = -std=c++11 -g -MMD
LDFLAGS =
LBLIBS := $(CURDIR)/../3dPlayground-Core/lib/3dPlayground-Core/utils/3dPlayground-Core.a
HEADERDIRS := $(CURDIR)/includes/ $(CURDIR)/../3dPlayground-Core/includes
HEADERDIRS := $(patsubst %,-I%,$(HEADERDIRS))

SRC_DIR := $(CURDIR)/src
OBJ_DIR := $(CURDIR)/obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES)) 
EXEC := $(CURDIR)/bin/player.exe
DEPENDS = $(OBJ_FILES:.o=.d)

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LBLIBS)

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