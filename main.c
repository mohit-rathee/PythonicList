#include "main.h"
#include <strings.h>

int main(){
    //Initialise list
    list* myList = initList();
    print(myList);

    //Append
    //Don't mismatch enumType and valueType
    myObj val = {.Class=Char,.Data={.chr='b'}}; 
    append(myList, val); 

    //Append when capacity == size
    append(myList, val);
    append(myList, val);
    append(myList, val);
    append(myList, val);
    print(myList);

    //Update
    int index = 5;
    myObj object = {.Class=String,.Data={.str="MOHIT"}};


    //Get
//    myObj result = get(myList,&index);
  //  printObj(&result);

    //Pop
    //myObj waste= pop(myList);
}
