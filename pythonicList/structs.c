#include <stdbool.h>

typedef enum {
    Int,
    String,
    Char,
    Bool,
    Null,
} myclass;

typedef union {
    int num;
    char* str;
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
