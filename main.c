#include "main.h"
#include <stdio.h>
#include <strings.h>

int main(){
    //Initialise list
    list* myList = initList();

    //Append-Update-Get-Pop-Free
    myObj object = {.Class=String,.Data={.str="MOHIT"}};
    append(myList, object); 

    int index =-2;
    object =(myObj){.Class=Int,.Data={.num=5}};
    update(myList, &index, object);
    printf("-----------");
    print(myList);

    myObj result = get(myList,&index);
    printObj(&result);

    myObj waste= pop(myList);
    printObj(&waste);

    Free(&myList);
    printf("%p\n",myList);

}
