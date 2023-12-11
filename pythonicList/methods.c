#include "structs.c"

list* initList(); // I will give [1,2,3,4,] will create a list in future.

void printObj(myObj*); 

void print(list*);

void append(list*, myObj*);

void insert(list*, int, myObj*);

myObj pop(list*,int);

void validIndex(int**, int);

void shrink(list*);

void expand(list*);

myObj get(list*, int);

void Free(list**);

void update(list*,int, myObj);

