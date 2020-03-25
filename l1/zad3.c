/**
 * @author Tobiasz Wojnar
 * Algorithms and data structures Course 2020
 * list 1 exercise 1
 * Implement circular doubly linked  list
 * Program mesures avreage access time
 **/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//element
struct Element{
    int key;
    struct Element* next;
    struct Element* prev;
};

typedef struct{
    struct Element* head;
} List;
//Function adding element on the beginning
void insert(List* list, int k){
    struct Element* new = (struct Element*)malloc(sizeof(struct Element));
    struct Element* head = list->head;
    new->key = k;
    if(head == NULL){ //if list has no arguments
        list->head = new;
        new->next = new;
        new->prev = new;
        return;
    }   
    new->next = head;
    head->prev->next = new;
    new->prev = head->prev;
    head->prev = new;
}
//Deletes first element with maching key 
void delete(List* list, int k){
    struct Element* temp = list->head;
    struct Element* head = list->head; //to remamder begining of list

    if(head->key == k && head->next == head) //if list has one element 
    {
        list->head = NULL;
        return;
    }    

    while(temp->next != head){
        if(temp->key == k){
            temp->prev->next = temp->next; //one before is linked with next
            temp->next->prev = temp->prev; //on after is linked with one before
            free(temp);
            return;
        }
        temp = temp->next;
    }   
}
//Function returns first element with maching key
struct Element* find(List* list, int k){
    struct Element* result = list->head;
    struct Element* head = list->head;

    if(head->key == k) //if list has one element
        return head;
    while(result->next != head){
        if(result->key ==k)
            return result;
    }
    return NULL;
}
//inserts 1000 rand values beetwen 0 and 999
void listFill(List* list){
    srand((unsigned)time(NULL));
    for(int i= 0; i<1000; i++){
        insert(list, rand()%1000);
    }
}
//Funkcja joins two lists
List* merge(List* l1, List* l2){
    struct Element* head1 = l1->head;
    struct Element* head2 = l2->head;
    struct Element* temp = head1->prev;

    head1->prev->next = head2;
    head2->prev->next = head1;
    head1->prev = head2->prev;
    head2->prev = temp;

    return l1;
}
int main(){
    clock_t start, end;
    double timeUsed;
    struct Element* temp = (struct Element*)malloc(sizeof(struct Element));
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    
    listFill(list);
    //Mesures avrage access time to 100 random elements
    //and to n element, ex.: 680th
    for(int i=0; i<1000; i++){
        start = clock();
        temp = list->head;
        for(int i=1; i<= 680; i++){
            temp = temp->next;
        }
        end = clock();
        timeUsed += (double)(end - start);
    }
    timeUsed /=1000;
    timeUsed /= CLOCKS_PER_SEC;

    printf("Access time to 680th elementu: %f sec \n", timeUsed);
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
    printf("Avreage access time to 500 random elements: %f sec \n", timeUsed);

   /* insert(list, 1);
    insert(list, 2);
    insert(list, 3);
    printf("%d\t", list->head->key);
    temp = list->head->next;
    while(temp != list->head){
        printf("%d\t", temp->key);
        temp = temp->next;
    }*/

     //Sprawdzenie funkcji merge
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
    free(l1);
    free(l2);
    free(list);
}
