#include <stdio.h>
#include <stdlib.h>
#include "methods.c"

list* initList(){
    int capacity = 50;
    list *my_list = malloc(sizeof(list));
    my_list->capacity = capacity;
    my_list->size = 0;
    my_list->arr = (myObj *) malloc(capacity*sizeof(myObj)) ; 
    //filing data
    my_list->arr[0]=(myObj){.Class=Int,.Data={.num=5}};
    my_list->arr[1]=(myObj){.Class=Char,.Data={.chr='f'}};
    my_list->arr[2]=(myObj){.Class=String,.Data={.str="AAAA"}};
    my_list->arr[3]=(myObj){.Class=Bool,.Data={.boool=true}};
    my_list->size=3; 
    return my_list;
}

void printObj(myObj* object){ 
    switch (object->Class) {
        case Int:
            printf("<class: int> <data: %d>\n",object->Data.num);
            break;
        case String:
            printf("<class: String> <data: \"%s\">\n",object->Data.str);
            break;
        case Char:
            printf("<class: Char> <data: '%c'>\n",object->Data.chr);
            break;
        case Bool:
            printf("<class: Bool> <data: %b>\n",object->Data.boool);
            break;
        case Null:
            printf("<class: Null>\n");
            break;
    }
}

void print(list *my_list){
    int capacity = my_list->capacity;
    int size = my_list->size;
    printf("capacity: %d \n",capacity);
    printf("size: %d \n",size);
    printf("[\n");
    myObj* arr = my_list->arr;
    for (int i=0;i<size;i++){
        printObj(&arr[i]);
    }
    printf("]\n");
    

}

void append(list* my_list, myObj object){
    int capacity = my_list->capacity;
    int size = my_list->size;
    if (size>capacity){
        //realloc
    }
    my_list->arr[size]= object;
    my_list->size++;
}

myObj pop(list* my_list){
    int size = my_list->size;
    if (size<0){return (myObj){.Class=Null};}
    myObj retVal = my_list->arr[size-1];
    my_list->size--;
    return retVal;
}

void validIndex(int* idx, int* size){ // It will actuall return the index
    int index = * idx;
    if(index<0){index=*size-index;}
    if(index>=*size && index<0){
        idx = NULL;
    }
}

myObj get(list* my_list,int* index){
    validIndex(index, &my_list->size);
    if (index){
        myObj object = my_list->arr[*index];
        return object;
    }else{
        return (myObj){.Class=Null};
    }
}

void update(list* my_list, int* index, myObj object){
    validIndex(index, &my_list->size);
    printf("%p",index);
    if (index){
        my_list->arr[*index] = object;
    }else{
    printf("list index out of range.\n");
    }
}
