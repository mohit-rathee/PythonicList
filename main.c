#include "main.h"

int main(){
    //Initialise list
    list* myList = initList();

    //Append
    //Don't mismatch enumType and valueType
    myObj val = {.Class=Char,.Data={.chr='b'}}; 
    append(myList, val); 
    print(myList);

    //Get
    myObj bbbb = get(myList,10);
    printObj(&bbbb);

    //Pop
    myObj waste= pop(myList);
    printObj(&waste);
    print(myList);
}
