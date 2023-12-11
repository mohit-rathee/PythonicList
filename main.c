#include "main.h"
//#include <stdio.h>
#include <strings.h>

int main(){
    //Initialise list
    list* myList = initList();
    
    int index;

    print(myList);

    index=2;
    myObj object= pop(myList,index);
    print(myList);

    index= 1;
    insert(myList, index, &object);

    print(myList);
    Free(&myList);

}
