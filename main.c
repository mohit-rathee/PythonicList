#include "main.h"
#include <string.h>
#include <strings.h>

int main(){
    char* Str="AAASDFSDFASDFASFDASdf";
    myObj object = {.Class=String};
    list* my_list = initList();
    for(int i=0;i<100000000;i++){
        object.Data.str=strdup(Str);
        append(my_list, object);
    }

    Free(&my_list);

}
