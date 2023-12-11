#include "main.h"
//#include <stdio.h>
#include <strings.h>

int main(){
    //Initialise list
    list* myList = initList();
    
    int index =-4;

    print(myList);

    index=0;
    myObj waste= pop(myList,index);
    printObj(&waste);

    print(myList);
    Free(&myList);

}
