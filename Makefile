all: linux win32 win64

linux:
	mkdir -p bin/
	gcc NCX-Core-Lite/main.c -o bin/NCX-Core-Lite

win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc -o bin/NCX-Core-Lite32.exe NCX-Core-Lite/main.c

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc -o bin/NCX-Core-Lite64.exe NCX-Core-Lite/main.c

# Note that the mac executables can only be compiled on mac
macX86:
	mkdir -p bin/
	gcc -o bin/NCX-Core-LiteX86 -target x86_64-apple-macos10.12 NCX-Core-Lite/main.c

macARM:
	mkdir -p bin/
	gcc -o bin/NCX-Core-LiteARM -target arm64-apple-macos11 NCX-Core-Lite/main.c

clean:
	rm -f bin/* rm -d bin/