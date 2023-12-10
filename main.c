#include "main.h"
#include <strings.h>

int main(){
    //Initialise list
    list* myList = initList();
    print(myList);

    //Append
    //Don't mismatch enumType and valueType
    myObj val = {.Class=Char,.Data={.chr='b'}}; 
    for(int i=0; i<200000000; i++){
        append(myList, val); 
    }

    //Update
    int index = 5;
    myObj object = {.Class=String,.Data={.str="MOHIT"}};


    //Get
    //myObj result = get(myList,&index);
    //printObj(&result);

    //Pop
    myObj waste= pop(myList);
    for(int i=0; i<200000000; i++){
        waste=pop(myList); 
    }
}
