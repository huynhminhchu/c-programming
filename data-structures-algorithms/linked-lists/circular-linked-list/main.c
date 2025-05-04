#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int CircularListLength(CLLNode *head) {
  struct CLLNode *current = head;
  int count = 0;

  if (head == NULL) {
    return 0;
  }
}
void InsertAtEndInCLL(CLLNode **head, int data) {
  CLLNode *p, *newNode;
  newNode = NewNode(data);
  p = *head;
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  while (p->next != (*head)) {
    p = p->next;
  }
  if (p) {
    p->next = newNode;
    newNode->next = *head;
  }
}

CLLNode *NewNode(int data) {
  CLLNode *newNode = (CLLNode *)malloc(sizeof(CLLNode));
  if (!newNode) {
    printf("Memory error!!!\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = newNode;
  return newNode;
}
void PrintCLL(CLLNode *head) {
  CLLNode *p = head;
  if (head == NULL) {
    printf("Empty list.\n");
    return;
  }
  do {
    printf("Value: %d\n", p->data);
    p = p->next;
  } while (p != head);
}
int main() {
  CLLNode *head = NULL;
  InsertAtEndInCLL(&head, 2);
  InsertAtEndInCLL(&head, 4);
  InsertAtEndInCLL(&head, 8);
  PrintCLL(head);
  return 0;
}
