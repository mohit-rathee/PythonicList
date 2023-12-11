#include "structs.c"

list* initList(); // I will give [1,2,3,4,] will create a list in future.

void printObj(myObj*); // pass-by-ref to reduce time.

void print(list*);

void append(list*, myObj);

myObj pop(list*,int*);

void validIndex(int* idx, int* size);

myObj get(list*, int*);

void Free(list**);

void update(list*,int*, myObj);

