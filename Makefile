all: linux win32 win64

linux:
	mkdir -p bin/
	gcc -Wall -c NCX-Core-Lite/store.c -o bin/store.o
	gcc -Wall -c NCX-Core-Lite/functions.c -lcurl -o bin/functions.o
	gcc -Wall -c NCX-Core-Lite/main.c -lcurl -o bin/main.o
	gcc bin/store.o bin/functions.o bin/main.o -lcurl -o bin/NCX-Core-Lite
	rm bin/store.o bin/functions.o bin/main.o

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
	gcc -target x86_64-apple-macos10.12 -Wall -c NCX-Core-Lite/main.c -o bin/main.o
	gcc -target x86_64-apple-macos10.12 bin/store.o bin/functions.o bin/main.o -lcurl -o bin/NCX-Core-LiteX86 
	rm bin/store.o bin/functions.o bin/main.o

macARM:
	mkdir -p bin/
	gcc -o bin/NCX-Core-LiteARM -target arm64-apple-macos11 NCX-Core-Lite/main.c

clean:
	rm -f bin/* rm -d bin/