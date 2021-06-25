CC = gcc
BIN_DIR ?= ./bin
TARGET ?= $(BIN_DIR)/emulate.out
SRC_DIRS ?= ./src
INC_DIR ?= ./include

SRCS := $(shell find $(SRC_DIRS) -name  *.c)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(INC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

DEBUG_FLAG := -g

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP  -Wall $(DEBUG_FLAG)
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBES) $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)