#include "main.h"
#include <string.h>
#include <strings.h>

int main(){
    char* Str="AAASDFSDFASDFASFDASdf";
    //Initialise list
    list* my_list = initList();
    //put strings
    for (int i=0; i<2000000;i++) {
        myObj object = create_myObj(Str);
        append(my_list, object);
    }
    //put integers
    for (int i=0; i<90000000;i++) {
        myObj object = (myObj){.Class=Int,.Data={.num=444}};
        append(my_list, object);
    }
    list* new_list = initList();
    add(new_list,0,my_list);
    Free(&my_list);
    Free(&new_list);
    char r;
    scanf("%c",&r);

    
    //the sublist should not be freed. If you are freeing the major one.
    // I could make a count on each myObj telling number of connections
    // but that's just waste of time. 
    // A good was could be to create a Garbage collector. (forgive me)

}
