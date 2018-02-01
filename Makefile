all: main

build:
	mkdir build

clean:
	rm build/*
	rm class_inspector
	rmdir build

main: libclassinspector.1.dylib runtime foundation graphs

runtime:
	clang -framework Foundation src/main.m -o build/class_inspector_with_foundation build/libclassinspector.1.dylib 

foundation:
	clang src/main.m -o build/class_inspector_objc_runtime build/libclassinspector.1.dylib 

libclassinspector.1.dylib: build
	clang -lobjc -dynamiclib src/class_inspector.c -o build/libclassinspector.1.dylib -current_version 1.0 -compatibility_version 1.0

graphs:
	./build/class_inspector_objc_runtime | dot -Tsvg > objc_runtime.svg
	./build/class_inspector_with_foundation | dot -Tsvg > objc_runtime_plus_foundation.svg



