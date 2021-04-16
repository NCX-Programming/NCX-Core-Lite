CC = gcc
TARGET = NCX-Core-Lite
CFLAGS = -Wall -O
FILES = NCX-Core-Lite/store.c NCX-Core-Lite/functions.c NCX-Core-Lite/main.c NCX-Core-Lite/cli.c
LIBS = -lcurl `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`
DEBUG = -fsanitize=address -g

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
	rm -rf bin/* rm -d bin/
