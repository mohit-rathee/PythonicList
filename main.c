#include "main.h"
#include <string.h>
#include <strings.h>

int main(){
    char* Str="AAASDFSDFASDFASFDASdf";
    myObj object = {.Class=String};
    list* my_list = initList();
    for (int i=0; i<10;i++) {
        object.Data.str=strdup(Str);
        append(my_list, object);
    }
    list* new_list = initList();
    add(new_list,0,my_list);
    print(my_list);
    print(new_list);
    Free(&my_list);
    
    //the sublist should not be freed. If you are freeing the major one.
    // I could make a count on each myObj telling number of connections
    // but that's just waste of time. 
    // A good was could be to create a Garbage collector. (forgive me)

}
