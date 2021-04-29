# Basic settings
CC=gcc
TARGET=NCX-Core-Lite
# MAKE arguments
CFLAGS=-Wall -O2
LIBS=-lcurl `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`
DEBUG=-fsanitize=address -g
# Files to compile
FILES=src/store.c src/functions.c src/main.c src/cli.c

all: linux

linux:
	mkdir -p bin/
	$(CC) $(CFLAGS) $(FILES) $(LIBS) -o bin/$(TARGET)

linuxd:
	mkdir -p bin/
	$(CC) $(CFLAGS) $(FILES) $(LIBS) $(DEBUG) -o bin/$(TARGET)

# Note that the mac executables can only be compiled on mac
mac:
	mkdir -p bin/
	$(CC) -target x86_64-apple-macos10.12 $(CFLAGS) $(FILES) $(LIBS) -o bin/$(TARGET)X86

macd:
	mkdir -p bin/
	$(CC) -target x86_64-apple-macos10.12 $(CFLAGS) $(FILES) $(LIBS) $(DEBUG) -o bin/$(TARGET)X86

macapp:
	mkdir -p bin/
	$(CC) -target x86_64-apple-macos10.12 $(CFLAGS) $(FILES) $(LIBS) -o bin/$(TARGET)X86.app

macARM:
	mkdir -p bin/
	$(CC) -target arm64-apple-macos11 $(CFLAGS) $(FILES) $(LIBS) $(DEBUG) -o bin/$(TARGET)X86

clean:
	rm -rf bin/
