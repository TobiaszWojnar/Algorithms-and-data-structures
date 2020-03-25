/**
 * @author Tobiasz Wojnar
 * Algorithms and data structures Course 2020
 * list 1 exercise 1
 * Implement singly linked list and mesure average time
 **/

#include<stdlib.h>
#include<stdio.h>
#include <time.h>

struct Element{
    int key;
    struct Element* next;
};

typedef struct{
    struct Element* head;
} List;
//Adds element o the begining of the list
void insert(List* list, int k){
    struct Element* new = (struct Element*)malloc(sizeof(struct Element));
    new->key = k;
    new->next = list->head;
    list->head = new;
}
//Returns first element that matches the key
struct Element* find(List* list, int k){
    struct Element* result = list->head;
    do{
        if(result->key == k)
            break;
        result = result->next;
    }while(result != NULL);
    return result;
}
//Deletes first element that matches the key
void delete(List* list, int k){
    struct Element* temp = list->head;

    if(temp->key == k){
        list->head = temp->next;
        return;
    } 
    while(temp->next != NULL && temp->next->key != k ){
        temp = temp->next;
    }
    if(temp->next == NULL)
        return;
    temp->next = (temp->next)->next;
}
//Insterts list with 1000 rand numbers
void listFill(List* list){
    srand((unsigned)time(NULL));
    for(int i= 0; i<1000; i++){
        insert(list, rand()%1000);
    }
}
//Funkcja joins two lists
List* merge(List* l1, List* l2){
    struct Element* temp = l1->head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = l2->head; //links beeginig of l2 at the end of l1
    return l1;
}
int main(){
    clock_t start, end;
    double timeUsed;
    struct Element* temp = (struct Element*)malloc(sizeof(struct Element));

    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;

    listFill(list); //inserts 1000 rand values
    //Mesures avrage access time to random elements
    //and to n element, ex.: 780th
    for(int i=0; i<1000; i++){
        start = clock();
        temp = list->head;
        for(int i=1; i<= 780; i++){
            temp = temp->next;
        }
        end = clock();
        timeUsed += (double)(end - start);
    }
    timeUsed /=1000;
    timeUsed /= CLOCKS_PER_SEC;

    printf("Access time to 780th element: %f sec \n", timeUsed);
    //restarting time countes
    timeUsed = 0;
    srand((unsigned)time(NULL));
    for(int i =0; i<500; i++){       
        int n= rand()%1000;

        start = clock();
        temp = list->head;
        for(int i=0; i< n; i++){
            temp = temp->next;
        }
        end = clock();
        timeUsed += (double)(end - start);
    }
    timeUsed /= 500;
    timeUsed /= CLOCKS_PER_SEC;
    printf("Avreage access time to  500 random elements: %f sec \n", timeUsed);

    //testing merge function
    List* l1 = (List*)malloc(sizeof(List));
    l1->head = NULL;
    List* l2 = (List*)malloc(sizeof(List));
    l2->head = NULL;

    insert(l1, 1);
    insert(l1, 2);
    insert(l1, 3);
    insert(l2, 4);
    insert(l2, 5);
    insert(l2, 6);
    l1 = merge(l1, l2);
    temp = l1->head;
    for(int i=0; i<6; i++){
        printf("%d\t",temp->key );
        temp = temp->next;
    }
    free(list);
    return 0;
}
