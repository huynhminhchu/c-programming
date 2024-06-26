#include <stdio.h>
#include "readline.h"
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};


struct part *inventory = NULL;


struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);

int main(void)
{
    char code;
    for (;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;
        switch (code)
        {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'q':
            return 0;
        case 'e':
            erase();
            break;
        default:
            printf("Illegal code\n");
            break;
        }
        printf("\n");   
    }
}

struct part *find_part(int number)
{
    struct part *current;
    for (current = inventory; current != NULL; current = current -> next){
        if (current->number == number)
            return current;
    }
    return NULL;
}

void insert(void)
{
    struct part *cur, *prev, *new_node;

    new_node = (struct part *) malloc(sizeof(struct part));
    if (new_node == NULL){
        printf("Database is full; can't add more parts\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next);
    if (cur != NULL && new_node->number == cur->number){
        printf("Part already exists.\n");
        free(new_node);
        return;
    }
    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter entity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;

    //if insert to the beginning of the list
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

void erase(void)
{
    int part_number;
    struct part *cur, *prev;
    printf("Enter part number: ");
    scanf("%d", &part_number);

    for (cur = inventory, prev = NULL; cur != NULL && part_number > cur->number; prev = cur, cur = cur->next);
    if (cur == NULL){
        /* Not found */
        printf("Position does not exist\n");
    }
    if (prev == NULL){
        inventory = cur->next;
        free(cur);
    }
    if (cur != NULL && part_number == cur->number){
        prev->next = cur->next;
        free(cur);
        return;
    }

}

void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf(" %d", &number);
    p = find_part(number);
    if (p == NULL){
        printf("Part not found.\n");
    } else {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }
}
void update(void)
{
    int number, change;
    struct part *p;
    printf("Enter part number: ");
    scanf(" %d", &number);
    p = find_part(number);
    if (p == NULL){
        printf("Part not found.\n");
    } else {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    }
}

void print(void)
{
    printf("Part Number     Part Name                                       "
            "Quantity on Hand\n");
    for (struct part *p = inventory; p != NULL; p = p->next){
        printf("%7d         %-25s%11d\n", p->number, p->name, p->on_hand);
    }
}