//start of required boilerplate
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
#define malloc(size) debug_malloc(size,__FILE__,__LINE__)
#define calloc(amount, size) debug_calloc(amount, size,__FILE__,__LINE__)
#define realloc(location, size) debug_realloc(location, size,__FILE__,__LINE__)
#define free(variable) debug_free(variable,__FILE__,__LINE__)
//end of required boilerplate
int main() {
    int* ptr = (int*)malloc(10 * sizeof(int));
    ptr = (int*)realloc(ptr, 20 * sizeof(int));
    free(ptr);
    int* array = (int*)calloc(10, sizeof(int));
    printf("Values after calloc: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}