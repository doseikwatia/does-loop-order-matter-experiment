CC = gcc
CFLAGS = -O0
SRC_DIR = src
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/matrix.c
OBJS = $(SRCS:.c=.o)

all: $(BUILD_DIR)/experiment

$(BUILD_DIR)/experiment: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(BUILD_DIR)/experiment

.PHONY: all clean