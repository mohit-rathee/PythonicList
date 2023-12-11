#include "main.h"
#include <stdio.h>
#include <strings.h>

int main(){
    //Initialise list
    list* myList = initList();

    //Append-Update-Get-Pop-Free
    myObj object = {.Class=String,.Data={.str="MOHIT"}};
    append(myList, object); 

    int index =-4;
    object =(myObj){.Class=Int,.Data={.num=5}};
    update(myList, &index, object);
    printf("-----------");
    print(myList);

    index=20;
    myObj waste= pop(myList,&index);
    printObj(&waste);

    print(myList);
    Free(&myList);

}
