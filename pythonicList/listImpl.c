#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "methods.c"

#define MIN_CAPACITY 4

list* initList(){
    int capacity = MIN_CAPACITY;
    list *my_list = malloc(sizeof(list));
    my_list->capacity = capacity;
    my_list->size = 0;
    my_list->arr = (myObj *) malloc(capacity*sizeof(myObj)) ; 
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
    if (size==capacity){
        //reallocating arr not my_list
        expand(my_list,2);
    }
    my_list->arr[size]= object;
    my_list->size++;
}

void add(list* my_list, int idx, list* sub_list){
    int *index = &idx;
    int size = my_list->size;
    int capacity = my_list->capacity;
    validIndex(&index,size);
    printf("%d\n",size);
    printf("%d\n",capacity);
    if(index==NULL){return;}
    int growthFac = size + sub_list->size - capacity;
    growthFac = (int)(growthFac/MIN_CAPACITY)+2;
    if(growthFac>0){
        expand(my_list,growthFac);
    }
    myObj* arrToIndex = my_list->arr + *index;
    memmove(
        arrToIndex+ sub_list->size,
        arrToIndex,
        (my_list->size-*index) * sizeof(myObj)
    );
    memmove(
        my_list->arr + *index,
        sub_list->arr,
        sub_list->size * sizeof(myObj)
    );
    my_list->size+=sub_list->size;
}

void insert(list* my_list, int idx, myObj object){
    int* index = &idx; // *index will be the index.
    int size = my_list->size;
    int capacity = my_list->capacity;
    validIndex(&index,size);
    if(index && *index==size-1){
        return append(my_list, object);
    }else if(size==capacity){
        expand(my_list,2);//realloc
    }
    //memmove
    myObj* arrToIndex = my_list->arr + *index;
    memmove(
        arrToIndex+1,
        arrToIndex,
        (size - *index) * sizeof(myObj)
    );
    *arrToIndex = object;
    my_list->size++;
}

void expand(list* my_list, int growthFac){
    my_list->arr = realloc(
        my_list->arr,
        (my_list->capacity*sizeof(myObj))*growthFac //double capacity
    );
    my_list->capacity*=growthFac;
    if(my_list->arr == NULL){
        printf("out of memory");
        return;
    }
}

myObj pop(list* my_list, int idx){
    int* index = &idx;
    validIndex(&index, my_list->size);
    if(my_list==NULL || index==NULL){
        return (myObj){.Class=Null};
    }
    int size = my_list->size;
    myObj* arr = my_list->arr;
    if (size==0){return (myObj){.Class=Null};}
    myObj retVal = my_list->arr[*index];
    if(*index != -1){
        memmove(
            &arr[*index],
            &arr[*index+1],
            (size-*index-1) * sizeof(myObj)
        );
    }
    my_list->size--;
    shrink(my_list);

    return retVal;
}

void shrink(list* my_list){
    if(my_list->size*4<my_list->capacity){
        if(my_list->capacity > MIN_CAPACITY){
            //realloc with half size
            my_list->capacity /= 2;
            my_list->arr =
                realloc(my_list->arr, my_list->capacity*sizeof(myObj));
        }
    }
}

void validIndex(int** idx, int size){ // It will actuall return the index
    int index = **idx;
    if(index<0){index+=size;}
    if(index!=0 && (index>=size || index<0)){
        printf("list index out of range.\n");
        *idx = NULL;
    }else{
        **idx = index;
    }
}

myObj get(list* my_list,int idx){
    if(my_list==NULL){return (myObj){.Class=Null};}
    int* index = &idx;
    validIndex(&index, my_list->size);
    if (index){
        myObj object = my_list->arr[*index];
        return object;
    }else{
        return (myObj){.Class=Null};
    }
}

int len(list* my_list){
    return my_list->size;
}

void Free(list** my_list){
    if(*my_list==NULL){return;}
    myObj* arr = (*my_list)->arr;
    for(int i=0;i < (*my_list)->size;i++){
        //free strings and pointers.
        if(arr[i].Class==String){
            free(arr[i].Data.str);
        }
    }
    free((*my_list)->arr);
    free(*my_list);
    *my_list=NULL;
}

void update(list* my_list, int idx, myObj object){
    if(my_list==NULL){return;}
    int* index = &idx;
    validIndex(&index, my_list->size);
    if (index){
        my_list->arr[*index] = object;
    }
}
