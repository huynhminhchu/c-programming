#include "list.h"
#include <stdio.h>
#include <stdlib.h>

DLLNode *NewNode(int data) {
  DLLNode *newNode = (DLLNode *)malloc(sizeof(DLLNode));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void DLLInsert(DLLNode **head, int data, int pos) {
  DLLNode *newNode, *p;
  p = *head;
  int k = 1;
  newNode = NewNode(data);
  if (pos == 1) {
    newNode->next = p;
    newNode->prev = NULL;

    if (p != NULL) {
      p->prev = newNode;
    }
    *head = newNode;
    return;
  }
  while ((p->next != NULL) && (k < pos - 1)) {
    p = p->next;
    k++;
  }
  if (k != pos) {
    printf("Position does not exist.\n");
  }
  newNode->next = p->next;
  newNode->prev = p;
  if (p->next) {
    p->next->prev = newNode;
  }
  p->next = newNode;
}

void PrintForward(DLLNode *head) {
  DLLNode *p = head;
  while (p) {
    printf("Value: %d\n", p->data);
    p = p->next;
  }
}

void PrintBackward(DLLNode *head) {
  DLLNode *p = head;
  while (p->next != NULL) {
    p = p->next;
  }
  while (p) {
    printf("Value: %d\n", p->data);
    p = p->prev;
  }
}

void DLLDelete(DLLNode **head, int pos) {

  DLLNode *temp, *temp2;
  temp = *head;
  int k = 1;
  if (head == NULL) {
    printf("list is empty.\n");
    return;
  }
  if (pos == 1) {
    (*head) = (*head)->next;
    if (*head != NULL) {
      (*head)->prev = NULL;
      free(temp);
      return;
    }
  }
  while ((k < pos) && (temp->next != NULL)) {
    temp = temp->next;
    k++;
  }
  if (k != pos - 1) {
    printf("Desired position doesn't exist.\n");
  }
  temp2 = temp->prev;
  temp2->next = temp->next;

  if (temp2->next) {
    temp2->next->prev = temp2;
  }
  free(temp);
  return;
}
int main() {
  DLLNode *dllist = NULL;
  DLLInsert(&dllist, 5, 1);
  DLLInsert(&dllist, 5, 1);
  DLLInsert(&dllist, 10, 2);
  DLLInsert(&dllist, 6, 4);
  PrintForward(dllist);
  printf("After delete: \n");
  DLLDelete(&dllist, 1);
  DLLDelete(&dllist, 2);
  PrintForward(dllist);
  /*
   DLLDelete(&dllist, 1);
  DLLDelete(&dllist, 1);
  printf("Afte delete.\n");
  PrintForward(dllist);
  */
}
