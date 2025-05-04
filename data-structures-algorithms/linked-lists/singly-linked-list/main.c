#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int ListLength(struct ListNode *head) {
  int length = 0;
  struct ListNode *current = head;
  while (current != NULL) {
    length++;
    current = current->next;
  }
  return length;
};
void InsertInLinkedList(ListNode **head, int data, int position) {
  ListNode *newNode, *p, *q;
  int k = 1;
  newNode = NewNode(data);

  p = *head;

  // Insert to the beginning
  if (position == 1 || p == NULL) {
    newNode->next = p;
    *head = newNode;
  } else {
    while ((p != NULL) && (k < position)) {
      q = p;
      p = p->next;
      k++;
    }
    q->next = newNode;
    newNode->next = p;
  }

  // Insert to middle of the linked list
};

ListNode *NewNode(int data) {
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));
  if (!node) {
    printf("Memory Error.\n");
  }
  node->data = data;
  return node;
};

void PrintList(ListNode *head) {
  ListNode *current = head;
  while (current) {
    printf("Value: %d\n", current->data);
    current = current->next;
  }
};

void DeleteNode(ListNode **head, int position) {
  ListNode *current, *temp;
  int count = 1;

  current = *head;
  if (position == 1) {
    *head = current->next;
    free(current);
    return;
  } else {
    while ((current) && (count < position)) {
      count++;
      temp = current;
      current = current->next;
    }
    if (current) {
      temp->next = current->next;
    } else {
      printf("Invalid position\n");
    }

    free(current);
    return;
  }
}

void DeleteLinkedList(ListNode **head) {
  ListNode *current, *temp;
  current = *head;

  while (current) {
    temp = current->next;
    free(current);
    current = temp;
  }
  *head = NULL;
}

ListNode *MergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode *dump, *l1, *l2, *list;
  dump = (ListNode *)malloc(sizeof(ListNode));
  dump->next = NULL;
  list = dump;
  l1 = list1;
  l2 = list2;

  while ((l1) && (l2)) {
    if (l1->data < l2->data) {
      dump->next = l1;
      l1 = l1->next;
    } else {
      dump->next = l2;
      l2 = l2->next;
    }
    dump = dump->next;
  }

  if (l1 != NULL) {
    dump->next = l1;
  }
  if (l2 != NULL) {
    dump->next = l2;
  }

  return list->next;
}

ListNode *ReverseList(ListNode *head) {
  ListNode *current = head;
  ListNode *reverseList = NULL;
  ListNode *dummy = NULL;
  while (current) {
    dummy = current->next;
    current->next = reverseList;
    reverseList = current;

    current = dummy;
  }
  return reverseList;
}

ListNode *DeleteDuplicate(ListNode *head) {
  struct ListNode *p = head;
  if (p == NULL) {
    return NULL;
  }
  while (p != NULL) {
    if (p->next == NULL) {
      break;
    }
    if (p->data == p->next->data) {
      p->next = p->next->next;
    } else {
      p = p->next;
    }
  }
  return head;
}

int main(int argv, char **argc) {
  ListNode *list1 = NULL;
  ListNode *list2 = NULL;
  InsertInLinkedList(&list1, 5, 1);

  InsertInLinkedList(&list2, 1, 1);
  InsertInLinkedList(&list2, 1, 2);
  InsertInLinkedList(&list2, 1, 3);
  InsertInLinkedList(&list2, 1, 4);
  InsertInLinkedList(&list2, 2, 5);
  InsertInLinkedList(&list2, 3, 6);
  InsertInLinkedList(&list2, 3, 7);

  ListNode *list3 = DeleteDuplicate(list2);
  PrintList(list3);
}
