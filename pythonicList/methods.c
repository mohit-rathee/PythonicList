#include "structs.c"

list* initList(); // I will give [1,2,3,4,] will create a list in future.

void printObj(myObj* object); // pass-by-ref to reduce time.

void print(list *my_list);

void append(list* my_list, myObj dataobj);

myObj pop(list* my_list);

myObj get(list* my_list,int index);

