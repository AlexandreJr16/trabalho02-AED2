CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
Q_DIR   = $(SRC_DIR)/questions

TADS = $(OBJ_DIR)/vetor.o $(OBJ_DIR)/bst.o $(OBJ_DIR)/avl.o $(OBJ_DIR)/utils.o
QUESTIONS = $(BIN_DIR)/question1 $(BIN_DIR)/question2 $(BIN_DIR)/question3 $(BIN_DIR)/question4

.PHONY: all clean q1 q2 q3 q4

all: $(QUESTIONS)

q1: $(BIN_DIR)/question1
q2: $(BIN_DIR)/question2
q3: $(BIN_DIR)/question3
q4: $(BIN_DIR)/question4

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJ_DIR)/%.o: $(Q_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(BIN_DIR)/%: $(OBJ_DIR)/%.o $(TADS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lm
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
