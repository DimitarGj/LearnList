#include <stdio.h>
#include <stdlib.h>>

typedef struct Node Node;

struct Node{
  int x;
  Node* next;
};

void Prepend(Node **pHead, int value){
  Node *new = malloc(sizeof(Node));
  new->next = *pHead;
  new->x = value;
  
  *pHead = new;
}

void Append(Node **pHead, int value){
  Node *new = malloc(sizeof(Node));
  new->next = NULL;
  new->x = value;

  if(*pHead==NULL){
    *pHead = new;
  }else{
  
  Node *curr = *pHead;
  for(curr=curr; curr->next!=NULL; curr=curr->next){} 
  curr->next = new;
  }
}

void InsertBetween(Node **pHead, int value, int index){
 Node *new = malloc(sizeof(Node));
  new->next = NULL;
  new->x = value;
  int count = 1;  
  Node *curr = *pHead;
  for(curr=curr; curr->next!=NULL; curr=curr->next){
      if(count==index){
        new->next = curr->next;
        curr->next = new;
        break;
      }
    count++;
  } 
}

void Deallocate(Node** pHead){
  Node *curr = *pHead; 
  while(curr!=NULL){
   Node *aux = curr;
    curr=curr->next;
    free(aux);
  }
  *pHead=NULL;
}

int main(void) {
  Node *pHead = malloc(sizeof(Node));
  pHead = NULL; 
  int value;
  
  while(scanf("%d", &value)){
    if(value==-1){
      break;
    }else{
      Append(&pHead, value);
    }
  }

  Prepend(&pHead, 69);
  Prepend(&pHead, 68);
  Prepend(&pHead, 67);

InsertBetween(&pHead, 70, 3);
  
  Node *curr = pHead; 

  for(curr=curr; curr!=NULL; curr=curr->next){
    printf("%d\n", curr->x);
  }

  Deallocate(&pHead);
  return 0;
}