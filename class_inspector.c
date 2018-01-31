#include <stdlib.h>
#include <stdio.h>
#include <objc/objc-class.h>

int objc_getClassList(Class *buffer, int bufferCount);
const char *    object_getClassName           (id        obj);

int print_classes() {
  int numClasses;
  Class * classes = NULL;

  classes = NULL;
  numClasses = objc_getClassList(NULL, 0);

  if (numClasses > 0 )
  {
    classes = (Class *)malloc(sizeof(Class) * numClasses);
    numClasses = objc_getClassList(classes, numClasses);
    printf("Num classes: %i", numClasses);
    for(int i=0; i < numClasses; i++){
        printf("%s -> %s\n", class_getName(classes[i]), class_getName(class_getSuperclass(classes[i])));
    }
    free(classes);
  }
  return 0;
}

