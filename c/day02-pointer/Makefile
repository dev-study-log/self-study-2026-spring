CC      = gcc
CFLAGS  = -Wall -g
OUT_DIR = build
TARGET  = $(OUT_DIR)/thickness_aggregator

all: $(OUT_DIR) $(TARGET)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(TARGET): $(OUT_DIR)/main.o $(OUT_DIR)/calc.o
	$(CC) $(CFLAGS) -o $(TARGET) $(OUT_DIR)/main.o $(OUT_DIR)/calc.o

$(OUT_DIR)/main.o: main.c calc.h
	$(CC) $(CFLAGS) -c main.c -o $(OUT_DIR)/main.o

$(OUT_DIR)/calc.o: calc.c calc.h
	$(CC) $(CFLAGS) -c calc.c -o $(OUT_DIR)/calc.o

clean:
	rm -rf $(OUT_DIR)
