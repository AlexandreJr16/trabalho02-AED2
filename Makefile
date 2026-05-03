CC      = gcc
CFLAGS  = -Wall -Wextra -g
INCLUDES = -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
Q_DIR   = $(SRC_DIR)/questions

TADS = $(OBJ_DIR)/vetor.o $(OBJ_DIR)/bst.o $(OBJ_DIR)/avl.o $(OBJ_DIR)/utils.o $(OBJ_DIR)/bst_pacote.o

QUESTIONS_OBJ = $(OBJ_DIR)/question1.o $(OBJ_DIR)/question2.o \
                $(OBJ_DIR)/question3.o $(OBJ_DIR)/question4.o

TARGET = $(BIN_DIR)/main

.PHONY: all clean run

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJ_DIR)/main.o $(QUESTIONS_OBJ) $(TADS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lm

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(Q_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
