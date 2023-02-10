CXX = gcc
CXXFLAGS = -g -MMD -Wall
LDFLAGS =
LBLIBS =
HEADERDIRS := $(CURDIR)/include
HEADERDIRS := $(patsubst %,-I%,$(HEADERDIRS))

SRC_DIR := $(CURDIR)/src
OBJ_DIR := $(CURDIR)/obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES)) 
EXEC := $(CURDIR)/lib/glad.a
DEPENDS = $(OBJ_FILES:.o=.d)

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	ar $(LDFLAGS) rcs $@ $^ $(LBLIBS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CXX) $(CXXFLAGS) $(HEADERDIRS) -c -o $@ $<

-include $(DEPENDS)

clean:
	rm $(OBJ_FILES) $(EXEC) $(DEPENDS)

print:
	@echo Object files and executable
	@echo $(OBJ_FILES) $(EXEC)
	@echo DEPENDS
	@echo $(DEPENDS)