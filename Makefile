CC = gcc
CFLAGS = -std=c11 -Wall -Wextra
OBJS = main.o dynarr.o
HDRS = dynarrlib.h
TARGET = maim.exe


.PHONY: setup run clean

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

main.o: main.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

dynarr.o: dynarr.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@


run:
	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)