CXX = g++
CXXFLAGS = -std=c++17 -g -MMD -Wall
LDFLAGS = -static
LBLIBS := $(CURDIR)/../3dPlayground-Core/lib/3dPlayground-Core/3dPlayground-Core.a \
			$(CURDIR)/../Extern/glad/lib/glad.a
HEADERDIRS := $(CURDIR)/includes $(CURDIR)/../3dPlayground-Core/includes \
			$(CURDIR)/../Extern/glad/include \
			$(CURDIR)/../Extern/glm
HEADERDIRS := $(patsubst %,-I%,$(HEADERDIRS))

SRC_DIR := $(CURDIR)/src
OBJ_DIR := $(CURDIR)/obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES)) 
EXEC := $(CURDIR)/bin/player.exe
DEPENDS = $(OBJ_FILES:.o=.d)

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LBLIBS) -lgdi32 -lglu32 -lopengl32

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