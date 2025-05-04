typedef struct DLLNode {
  int data;
  struct DLLNode *next;
  struct DLLNode *prev;
} DLLNode;

int ListLength(DLLNode *);
void InsertInLinkedList(DLLNode **, int, int);
DLLNode *NewNode(int);
void PrintList(DLLNode *);
void DeleteNode(DLLNode **, int);
