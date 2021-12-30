#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_random(int maxy){
    int num = (rand() % maxy);
    return num;
}

struct listNode {
    int data;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;


void printList( ListNodePtr currentPtr);
void insert( ListNodePtr *sPtr, int value);

//1
typedef struct node
{
    int value;
    struct node *next;
} node;

int main()
{
    int length = 5;
    int random_numb;
    srand(time(0));
    struct node *headNode, *currentNode, *temp;

    printf("\n\n First list is:   ");
    for (int i = 0; i < length; i++)
    {
        currentNode = (node *)malloc(sizeof(node));
        random_numb = generate_random(50);
        printf("%d  ", random_numb);

        currentNode->value = random_numb;

        if (i == 0)
        {
            headNode = temp = currentNode;
        }
        else
        {
            temp->next = currentNode;
            temp = currentNode;
        }
    }
    temp->next = NULL;
    temp = headNode;

    // second one 
    struct node *headNode2, *currentNode2, *temp2;

    
    printf("\n\n Second list is:  ");
    for (int i = 0; i < length; i++)
    {
        currentNode2 = (node *)malloc(sizeof(node));
        random_numb = generate_random(100);
        printf("%d  ", random_numb);

        currentNode2->value = random_numb;
        
        if (i == 0)
        {
            headNode2 = temp2 = currentNode2;
        }
        else
        {
            temp2->next = currentNode2;
            temp2 = currentNode2;
        }
    }
    temp2->next = NULL;
    temp2 = headNode2;

    ListNodePtr startPtr = NULL;
    unsigned int choice;
    int item1, item2;


    while (temp != NULL)
    {
        item1 = temp->value;
        item2 = temp2->value;

        insert( &startPtr, item1);
        insert( &startPtr, item2);

        temp2 = temp2->next;
        temp = temp->next;
    }
    
    printList( startPtr);
}



void insert( ListNodePtr *sPtr, int value){
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    newPtr = malloc( sizeof( ListNode) );

    if (newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = *sPtr;

        while ( currentPtr != NULL && value > currentPtr->data ){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if ( previousPtr == NULL){
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else{
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else{
        printf( "%d not inserted. No memory available. \n", value );
    }
}

void printList( ListNodePtr currentPtr){

        printf("\n\nThe list is:       ");

        while ( currentPtr != NULL){
            printf( "%d   ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
    
}