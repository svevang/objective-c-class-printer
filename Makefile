all: main

build:
	mkdir build

clean:
	rm build/*
	rmdir build

main: libclassinspector.1.dylib
	clang src/main.m -o class_inspector build/libclassinspector.1.dylib 

libclassinspector.1.dylib: build
	clang -lobjc -dynamiclib src/class_inspector.c -o build/libclassinspector.1.dylib -current_version 1.0 -compatibility_version 1.0





