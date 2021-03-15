all: linux win32 win64

linux:
	mkdir -p bin/
	gcc -Wall -c NCX-Core-Lite/store.c -o bin/store.o
	gcc -Wall -c NCX-Core-Lite/functions.c -lcurl -o bin/functions.o
	gcc -Wall -c NCX-Core-Lite/main.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/main.o
	gcc -Wall -c NCX-Core-Lite/cli.c -o bin/cli.o
	gcc bin/store.o bin/functions.o bin/main.o bin/cli.o -lcurl `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/NCX-Core-Lite
	cp NCX-Core-Lite/builder.ui bin/
	rm bin/store.o bin/functions.o bin/main.o bin/cli.o

win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc NCX-Core-Lite/main.c -lcurl -o bin/NCX-Core-Lite32.exe

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc NCX-Core-Lite/main.c -lcurl -o bin/NCX-Core-Lite64.exe 

# Note that the mac executables can only be compiled on mac
macX86:
	mkdir -p bin/
	gcc -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/store.c -o bin/store.o
	gcc -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/functions.c -lcurl -o bin/functions.o
	gcc -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/main.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/main.o
	gcc -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/cli.c -o bin/cli.o
	gcc -target x86_64-apple-macos10.12 bin/store.o bin/functions.o bin/main.o bin/cli.o -lcurl `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o bin/NCX-Core-LiteX86 
	cp NCX-Core-Lite/builder.ui bin/
	rm bin/store.o bin/functions.o bin/main.o bin/cli.o

macARM:
	mkdir -p bin/
	gcc -o bin/NCX-Core-LiteARM -target arm64-apple-macos11 NCX-Core-Lite/main.c

clean:
	rm -rf bin/* rm -d bin/