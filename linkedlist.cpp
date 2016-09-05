//============================================================================
// Name        : linkedlist.cpp
// Author      : Scott Chandler
// Version     :9/4/2016
// Copyright   :
// Description : Assignmnet 1
//============================================================================
#include <iostream>
#include <cstdlib>
#include <malloc.h>
#include <ctime>// for Time
using namespace std;
struct Node {
    int number;
    struct Node* nextNode;
};
//append Method Implementation
void append(struct Node** head, int num)
{
    if (*head == NULL) { // checking if first node is NULL or not
        (*head) = (struct Node*)malloc(sizeof(struct Node));
        (*head)->number = num;
        (*head)->nextNode = NULL;
    }
    else {

        struct Node* temp = *head;
        while (temp->nextNode != NULL) {
            temp = temp->nextNode;
        }
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //dynamically allocation of memory
        newNode->number = num;
        newNode->nextNode = NULL;
        temp->nextNode = newNode;
    }
}
/* Getting Node with value from List*/
Node* search(struct Node** head, int value)
{
clock_t begin = clock();
std::cout<<begin<<std::endl;
    struct Node* temp = *head;
    while (temp != NULL) {
        if (temp->number == value) {
           clock_t end = clock();
           std::cout<<end<<std::endl;
           std::cout<<"Time taken in search is: "<<(end - begin)<<"ms "<<std::endl;
            return temp;
        }
        temp = temp->nextNode;
    }

    return NULL;
}
/*Display List Method Implementation*/
void printList(struct Node* head)
{
    while (head != NULL) {
        std::cout << head->number << " ";
        head = head->nextNode;
    }
    std::cout << endl;
}
int main(int argc, char *argv[])
{
    struct Node* head = NULL,*temp;
    srand(time(0));
     if ( argc != 3 ) // argc should be 2 for correct execution
    // We print error message
    std::cout<<"Please Enter 3 argument"<<std::endl;
else {
    //Total number of integers
    int N=atoi(argv[1]);
    //Numbers to be search in linked list
     int searchElement=atoi(argv[2]);
    //inserting element into linked list
    // we are generating element between 1 to 100
    for(int i=0;i<N;i++){
       append(&head,rand()%100+1);
   }
   //printing linked list
   printList(head);
    // calling searh function for searching element
temp= search(&head,searchElement);
if(temp!=NULL){
      std::cout<<"Element is present in List"<<std::endl;
}else{
   std::cout<<"Element is not present in List"<<std::endl;
}

}
return 0;
}

