CC = gcc
CFLAGS = -Wall -Wextra -Isrc

# List all source files
SRCS = example.c $(wildcard src/*.c)

# Name of the executable
TARGET = example

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)