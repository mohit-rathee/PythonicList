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

}
