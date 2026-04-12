CC = gcc
CFLAGS = -Wall -Wextra -O2 -fPIC

BUILD_DIR = build

SRC = glitch.c glitch-clock.c glitch-complex.c glitch-rand.c
OBJ = $(SRC:.c=.o)

# Detect OS
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    SHARED_EXT = so
    LDFLAGS = -shared
endif
ifeq ($(UNAME_S),Darwin)
    SHARED_EXT = dylib
    LDFLAGS = -dynamiclib
endif

# Fallback (just in case)
SHARED_EXT ?= so
LDFLAGS ?= -shared

LIBS = $(SRC:.c=.$(SHARED_EXT))

OBJ_BUILD = $(addprefix $(BUILD_DIR)/, $(OBJ))
LIB_BUILD = $(addprefix $(BUILD_DIR)/, $(LIBS))

all: $(BUILD_DIR) $(LIB_BUILD)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.$(SHARED_EXT): $(BUILD_DIR)/%.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
