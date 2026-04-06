CC = gcc
CFLAGS = -g -Wall -Wextra -Iinclude
SRC = src
OBJ = obj
BIN = bin
TARGET = $(BIN)/app

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%c, $(OBJ)/%o, $(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	mkdir -p $@

clean:
	rm -rf $(TARGET) $(OBJ)