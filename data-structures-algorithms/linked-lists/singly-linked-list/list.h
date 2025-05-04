typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

int ListLength(ListNode *);
void InsertInLinkedList(ListNode **, int , int);
ListNode* NewNode(int);
void PrintList(ListNode *);
void DeleteNode(ListNode **, int);
void DeleteLinkedList(ListNode **);