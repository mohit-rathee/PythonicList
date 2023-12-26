#include <malloc.h>
#include "main.h"
#include <string.h>
#include <strings.h>

int main(){
    char* Str="AAASDFSDFASDFASFDASdf";
    //Initialise list
    list* my_list = initList();
    //put strings
    for (int i=0; i<50000000;i++) {
        myObj object = create_myObj(Str);
        append(my_list, object);
    }
    printf("%s","Added 10000000strings.\n");

    //put integers
    for (int i=0; i<10000000;i++) {
        myObj object = (myObj){.Class=Int,.Data={.num=444}};
        append(my_list, object);
    }
    printf("%s","Added 10000000 integers.\n");

    for (int i=0; i<10000000;i++) {
        myObj object = (myObj){.Class=Bool,.Data={.boool=1}};
        append(my_list, object);
    }
    printf("%s","Added 10000000booleans.\n");
    for (int i=0; i<10000000;i++) {
        myObj object = (myObj){.Class=Char,.Data={.chr='m'}};
        append(my_list, object);
    }
    printf("%s","Added 10000000characters.\n");
    Free(&my_list);
    printf("%s","Freed the list.\n");

    printf("%s","check the ram usage graph.\n");

    printf("%s","👍\n");
    malloc_trim(0);  // Release free memory to the system
    // This motivates me to write my own heap.
    char s;
    scanf(" %c",&s);


    
    //the sublist should not be freed. If you are freeing the major one.
    // I could make a count on each myObj telling number of connections
    // but that's just waste of time. 
    // A good was could be to create a Garbage collector. (forgive me)

}
