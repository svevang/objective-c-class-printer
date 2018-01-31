all: class_inspector

class_inspector:
	clang -lobjc -dynamiclib -std=gnu99 class_inspector.c -current_version 1.0 -compatibility_version 1.0 -fvisibility=hidden -o libClassInspector.A.dylib





