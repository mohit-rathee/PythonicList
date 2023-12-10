#include "main.h"
#include <strings.h>

int main(){
    //Initialise list
    list* myList = initList();

    //Append
    //Don't mismatch enumType and valueType
    myObj val = {.Class=Char,.Data={.chr='b'}}; 
    append(myList, val); 
    print(myList);

    //Update
    int index = 3;
    myObj object = {.Class=String,.Data={.str="MOHIT"}};
    update(myList, &index, object);


    //Get
    myObj result = get(myList,&index);
    printObj(&result);

    //Pop
    myObj waste= pop(myList);
    printObj(&waste);
    print(myList);
}
