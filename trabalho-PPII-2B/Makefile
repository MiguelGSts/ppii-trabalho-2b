CC = gcc
CFLAGS = -Wall -Wextra -finput-charset=UTF-8 -fexec-charset=UTF-8
SRC = $(wildcard *.c)
OUT = main.exe

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: $(OUT)
	./$(OUT)

clean:
	del /f $(OUT) 2>nul