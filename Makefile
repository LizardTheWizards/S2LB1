CC = gcc
CFLAGS = -std=c11 -Wall -Wextra
OBJS = main.o dynarr.o type_info.o
HDRS = dynarrlib.h type_info.h
TARGET = maim.exe


.PHONY: setup run clean

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

main.o: main.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

dynarr.o: dynarr.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

type_info.o: type_info.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@


run:
	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)