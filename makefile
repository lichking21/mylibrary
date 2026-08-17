CC = gcc
CFLAGS = -g -Wall -Wextra -I./include
AR = ar
ARFLAGS = rcs

# Directories
SRC = src
OBJ = obj
BIN = bin
LIB = $(BIN)/lib
TEST = tests

LIB_NAME = $(LIB)/libAlib.a
TEST_BIN = $(BIN)/test_runner

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

.PHONY: all clean test

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS) | $(LIB)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIB_NAME)
	$(CC) $(CFLAGS) $(TEST)/test_main.c -L$(LIB) -lAlib -o $(TEST_BIN)
	@echo "--- RUNNING TESTS ---"
	@./$(TEST_BIN)

$(OBJ) $(LIB):
	mkdir -p $@

clean:
	rm -rf $(OBJ) $(BIN)
