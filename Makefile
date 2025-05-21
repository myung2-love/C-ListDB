CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iuser
TARGET = program
SRC_DIR = user
OBJS = main.o user_data.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c $(SRC_DIR)/user_data.h
	$(CC) $(CFLAGS) -c main.c

user_data.o: $(SRC_DIR)/user_data.c $(SRC_DIR)/user_data.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/user_data.c

clean:
	rm -f $(OBJS) $(TARGET)
