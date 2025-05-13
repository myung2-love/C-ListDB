CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = program
OBJS = main.o user_data.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c user_data.h
	$(CC) $(CFLAGS) -c main.c

user_data.o: user_data.c user_data.h
	$(CC) $(CFLAGS) -c user_data.c

clean:
	rm -f $(OBJS) $(TARGET)
