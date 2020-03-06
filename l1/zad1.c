/** 
* Implement queue FIFO
 **/
#include<stdlib.h>
#include<stdio.h>

//emelent in queue
typedef struct {
    int data;
    struct Node* next;
}Node ;
//queue
typedef struct {
    Node* tail;
    Node* head;
    int size;
} Queue;

//Function that adds elements at the end of list
void enqueue(Queue* queue, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = queue->tail;
    queue->tail = node;
    if(queue->head == NULL)
        queue->head = node;
    ++queue->size; //updates que size
}
//initialize queue
void initialize(Queue* queue){
    queue->tail = NULL;
    queue->head = NULL;
    queue->size = 0;
}
//Returns element that was the longest in the queue
Node* dequeue(Queue* queue){
    Node* result;
    Node* node;
    node = queue->tail;
    if(node->next != NULL){
        while(node->next != queue->head){
            node = node->next;
        }
        result = node->next;       
    }else{
        result = node;
    }
    node->next= NULL;
    queue->head = node;
    --queue->size; //updates queue size
    return result;
}
int main(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    initialize(queue);
    
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("%d \n", queue->tail->data );
    printf("%d \n", queue->head->data );
    printf("Queue size: %d \n", queue->size);
    Node* node = dequeue(queue);

    printf("%d \n", queue->tail->data );
    printf("%d \n", queue->head->data );
    printf("%d \n", node->data);
    printf("Queue size: %d \n", queue->size);

    free(queue);
    return 0;
}