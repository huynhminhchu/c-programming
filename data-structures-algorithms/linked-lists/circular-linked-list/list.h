typedef struct CLLNode {
  int data;
  struct CLLNode *next;
} CLLNode;

int CircularListLength(CLLNode *);
void InsertAtEndInCLL(CLLNode **, int);
void PrintCLL(CLLNode *);
CLLNode *NewNode(int);
