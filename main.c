#include "main.h"
#include <stdio.h>
#include <strings.h>

int main(){
    //Initialise list
    list* myList = initList();

    //Append-Update-Get-Pop-Free
    myObj object = {.Class=String,.Data={.str="MOHIT"}};
    for(int i=0;i<102;i++){
        append(myList, object); 
    }


    myObj waste;
    int s = -1;
    for(int i=0;i<102;i++){
        pop(myList,s);
    }

    print(myList);
    
    int index =-4;
    object =(myObj){.Class=Int,.Data={.num=5}};
    update(myList, index, object);
    printf("-----------");
    //print(myList);

    index=0;
    waste= pop(myList,index);
    printObj(&waste);

    print(myList);
    Free(&myList);

}
