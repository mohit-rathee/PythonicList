#include "structs.c"

list* initList(); // I will give [1,2,3,4,] will create a list in future.

void printObj(myObj*); 

void print(list*);

void append(list*, myObj);

void insert(list*, int, myObj);

void add(list*, int, list*);

myObj pop(list*,int);

void validIndex(int**, int);

void shrink(list*);

void expand(list*, int);

myObj get(list*, int);

int len(list*);

void Free(list**);

void update(list*,int, myObj);

myObj create_myObj(char*);
