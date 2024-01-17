#include <stdbool.h>

typedef enum {
    Int,   
    String,
    Char,  
    Bool,  
    Null,  
} myclass;

typedef struct {
    int refs;
    char* value;
} refrences;

typedef union {
    int num;
    refrences* ref; // max size
    char chr;
    _Bool boool;
} value;

typedef struct{
    myclass Class;
    value Data;
} myObj;

typedef struct {
    int capacity;
    int size;
    myObj* arr;
} list ;

