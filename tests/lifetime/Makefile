CC = gcc
CFLAGS = -I../.. -Wall -Wextra -g -DLOGGER_IMPLEMENTATION

BUILD = build

RACE_TARGET = $(BUILD)/race
MAIN_TARGET = $(BUILD)/main
LOGGER_H = ../../logger.h

MAIN_SRC = main.c
RACE_SRC = race.c

all: $(MAIN_TARGET) $(RACE_TARGET) $(BUILD)

$(BUILD):
	mkdir -p $(BUILD)

$(MAIN_TARGET): $(MAIN_SRC) $(LOGGER_H) | $(BUILD)
	$(CC) $(CFLAGS) -o $(MAIN_TARGET) $(MAIN_SRC)

$(RACE_TARGET): $(RACE_SRC) $(LOGGER_H) | $(BUILD)
	$(CC) $(CFLAGS) -o $(RACE_TARGET) $(RACE_SRC)

clean:
	rm -rf $(BUILD)
