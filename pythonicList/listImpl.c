#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "methods.c"

#define MIN_CAPACITY 50

list* initList(){
    int capacity = MIN_CAPACITY;
    list *my_list = malloc(sizeof(list));
    my_list->capacity = capacity;
    my_list->size = 0;
    my_list->arr = (myObj *) malloc(capacity*sizeof(myObj)) ; 
    //filing data
    my_list->arr[0]=(myObj){.Class=Int,.Data={.num=5}};
    my_list->arr[1]=(myObj){.Class=Char,.Data={.chr='f'}};
    my_list->arr[2]=(myObj){.Class=String,.Data={.str="AAAA"}};
    my_list->arr[3]=(myObj){.Class=Bool,.Data={.boool=false}};
    my_list->size=4; 
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
    if(my_list==NULL){return;}
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
    if(my_list==NULL){return;}
    int capacity = my_list->capacity;
    int size = my_list->size;
    if (size>=capacity){
        //reallocating arr not my_list
        printf("expanding ");
        capacity*=2;
        my_list->arr = realloc(my_list->arr, capacity*sizeof(myObj));
        my_list->capacity = capacity;
        printf("%d\n",my_list->capacity);
        if(my_list->arr == NULL){
            printf("out of memory");
            return;
        }
    }
    my_list->arr[size]= object;
    my_list->size++;
}

myObj pop(list* my_list, int* index){
    validIndex(&index, &my_list->size);
    if(my_list==NULL || index==NULL){
        printf("list index out of range.\n");
        return (myObj){.Class=Null};
    }
    int size = my_list->size;
    myObj* arr = my_list->arr;
    if (size==0){return (myObj){.Class=Null};}
    myObj retVal = my_list->arr[*index];
    if(*index != -1){
        // I have to just copy el's after index to their predecesor. 
        for (int i=*index+1;i<size;i++){
            arr[i-1]=arr[i];
        }
    }
    my_list->size--;

    if(my_list->size*4<my_list->capacity){
        if(my_list->capacity > MIN_CAPACITY){
            //realloc with half size
            printf("shrinking ");
            my_list->capacity /= 2;
            printf("%d\n",my_list->capacity);
            my_list->arr =
                realloc(arr, my_list->capacity*sizeof(myObj));
        }
    }
    return retVal;
}

void validIndex(int** idx, int* size){ // It will actuall return the index
    printf("%d\n",**idx);
    int index = **idx;
    if(index<0){index+=*size;}
    if(index>=*size || index<0){
        *idx = NULL;
    }else{
        **idx = index;
    }
}

myObj get(list* my_list,int* index){
    if(my_list==NULL){return (myObj){.Class=Null};}
    validIndex(&index, &my_list->size);
    if (index){
        myObj object = my_list->arr[*index];
        return object;
    }else{
        printf("list index out of range.\n");
        return (myObj){.Class=Null};
    }
}

void Free(list** my_list){
    if(*my_list==NULL){return;}
    free((*my_list)->arr);
    free(*my_list);
    *my_list=NULL;
}

void update(list* my_list, int* index, myObj object){
    if(my_list==NULL){return;}
    validIndex(&index, &my_list->size);
    if (index){
        my_list->arr[*index] = object;
    }else{
        printf("list index out of range.\n");
    }
}
