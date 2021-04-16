CC = gcc
TARGET = NCX-Core-Lite
GTK = `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`
CFLAGS = -Wall -O
FILES = NCX-Core-Lite/store.c NCX-Core-Lite/functions.c NCX-Core-Lite/main.c NCX-Core-Lite/cli.c
LIBS = -lcurl
DEBUG =

all: linux

linux:
	mkdir -p bin/
	$(CC) $(CFLAGS) $(FILES) $(LIBS) $(GTK) $(DEBUG) -o bin/$(TARGET)

linuxd:
	mkdir -p bin/
	$(CC) -Wall -c NCX-Core-Lite/store.c -fsanitize=address -g -o bin/store.o
	$(CC) -Wall -c NCX-Core-Lite/functions.c  -lcurl -fsanitize=address -g -o bin/functions.o
	$(CC) -Wall -c NCX-Core-Lite/main.c -fsanitize=address -g `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/main.o
	$(CC) -Wall -c NCX-Core-Lite/cli.c -fsanitize=address -g -o bin/cli.o
	$(CC) bin/store.o bin/functions.o bin/main.o bin/cli.o -fsanitize=address -g -lcurl `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/$(TARGET)
	rm bin/store.o bin/functions.o bin/main.o bin/cli.o

# Note that the mac executables can only be compiled on mac
macX86:
	mkdir -p bin/
	$(CC) -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/store.c -o bin/store.o
	$(CC) -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/functions.c -o bin/functions.o
	$(CC) -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/main.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/main.o
	$(CC) -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/cli.c -o bin/cli.o
	$(CC) -target x86_64-apple-macos10.12 bin/store.o bin/functions.o bin/main.o bin/cli.o -lcurl `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/$(TARGET)X86
	rm bin/store.o bin/functions.o bin/main.o bin/cli.o

macX86app:
	mkdir -p bin/
	$(CC) -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/store.c -o bin/store.o
	$(CC) -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/functions.c -o bin/functions.o
	$(CC) -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/main.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/main.o
	$(CC) -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/cli.c -o bin/cli.o
	$(CC) -target x86_64-apple-macos10.12 bin/store.o bin/functions.o bin/main.o bin/cli.o -lcurl `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/$(TARGET)X86.app
	rm bin/store.o bin/functions.o bin/main.o bin/cli.o

macARM:
	mkdir -p bin/
	$(CC) -target arm64-apple-macos11 -Wall -c NCX-Core-Lite/store.c -o bin/store.o
	$(CC) -target arm64-apple-macos11 -Wall -c NCX-Core-Lite/functions.c -o bin/functions.o
	$(CC) -target arm64-apple-macos11 -Wall -c NCX-Core-Lite/main.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/main.o
	$(CC) -target arm64-apple-macos11 -Wall -c NCX-Core-Lite/cli.c -o bin/cli.o
	$(CC) -target arm64-apple-macos11 bin/store.o bin/functions.o bin/main.o bin/cli.o -lcurl `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/$(TARGET)ARM
	rm bin/store.o bin/functions.o bin/main.o bin/cli.o

clean:
	rm -rf bin/* rm -d bin/
