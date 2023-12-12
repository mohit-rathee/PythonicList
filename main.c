#include "main.h"
//#include <stdio.h>
#include <strings.h>

int main(){
    //Initialise list
    list* myList = initList();
    myObj object = {.Class=Int,{.num=5}};
    int index;
    index=2;
    for (int i=0;i<15;i++){
        append(myList,&object);
    }

    list* secondList = initList();
    object =(myObj){.Class=String,{.str="AAAA"}};
    for (int i=0;i<4;i++){
        append(secondList,&object);
    }
    
    add(myList,index,secondList);


    print(myList);
    Free(&secondList);
    Free(&myList);

}
