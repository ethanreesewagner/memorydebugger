/*This debuggger prints every allocation in c and is a simplified version of Eskil Steenberg's forge 
memory debugger. Compiling this may bring up some warnings about redifining basic c functions.*/
void* debug_malloc(size_t size, char* file, int line) {
    #undef malloc
    void* ptr = malloc(size);
    #define malloc(size) debug_malloc(size)
    printf("MALLOC at %s:%d of size %zu.\n", file, line, size);
    return ptr;
}
void* debug_calloc(size_t amount, size_t size, char* file, int line) {
    #undef calloc
    void* ptr = calloc(amount, size);
    #define calloc(amount, size) debug_calloc(amount, size)
    printf("CALLOC at %s:%d of amount %zu and size %zu.\n", file, line, amount, size);
    return ptr;
}
void* debug_realloc(void* location, size_t size, char* file, int line) {
    #undef realloc
    void* ptr = realloc(location, size);
    #define realloc(location, size) debug_realloc(location, size)
    printf("REALLOC at %s:%d of location %p and size %zu.\n", file, line, location, size);
    return ptr;
}
void debug_free(void* variable, char* file, int line) {
    #undef free
    free(variable); 
    #define free(variable) debug_free(variable)
    printf("FREE at %s:%d of variable %p.\n", file, line, variable);
}
