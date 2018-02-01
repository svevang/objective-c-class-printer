#include <stdlib.h>
#include <stdio.h>
#include <objc/objc-class.h>

int objc_getClassList(Class *buffer, int bufferCount);
const char * object_getClassName(id obj);

int print_classes() {
  int numClasses;
  Class * classes = NULL;

  classes = NULL;
  numClasses = objc_getClassList(NULL, 0);

  if (numClasses > 0 )
  {
    classes = (Class *)malloc(sizeof(Class) * numClasses);
    numClasses = objc_getClassList(classes, numClasses);
    printf("digraph foundation {\n");
    for(int i=0; i < numClasses; i++){
        const char * class_name = class_getName(classes[i]);
        const char * parent_class_name = class_getName(class_getSuperclass(classes[i]));
        printf("%s [label=\"{<f0> %s|<f1> \\n}\" shape=Mrecord];\n", class_name, class_name);
        printf("%s [label=\"{<f0> %s|<f1> \\n}\" shape=Mrecord];\n", parent_class_name, parent_class_name);
        printf("%s -> %s;\n", class_name, parent_class_name);
    }
    printf("}\n");
    free(classes);
  }
  return 0;
}

