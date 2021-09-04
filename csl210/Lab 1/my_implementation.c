#include "csl210_lab1.h"
#include <stdlib.h>
#include <stdio.h>

nodeQ_t* convertSparseMatrixToLinkedList(unsigned short** matrix, unsigned short rows, unsigned short columns)
{
    nodeQ_t *head = (nodeQ_t *)malloc(sizeof(nodeQ_t));
    head->row = rows;
    head->column = columns;
    head->next = EMPTYNODE;
    nodeQ_t *curr = head;
    int t_val = 0;
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            if (matrix[i][j] != 0)
            {
                    t_val++;
                    curr->next = (nodeQ_t *)malloc(sizeof(nodeQ_t));
                    curr = curr->next;
                    curr->row = i;
                    curr->column = j;
                    curr->value = matrix[i][j];
                    curr->next = EMPTYNODE;
            }
        }
    }
    
    head->value = t_val;
    return head;
}

void findAndAdd(unsigned short row, unsigned short column, short value, nodeQ_t *head)
{
    nodeQ_t *curr = head;
    nodeQ_t *prev = head;
    while (curr)
    {
        if (curr->row == row && curr->column == column)
        {
            curr->value = curr->value + value;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    curr = prev;
    curr->next = (nodeQ_t *)malloc(sizeof(nodeQ_t));
    curr = curr->next;
    curr->row = row;
    curr->column = column;
    curr->value = value;
    curr->next = EMPTYNODE;
}

nodeQ_t* removeZeroVal(nodeQ_t* head){
    nodeQ_t* temp = EMPTYNODE;
    while(head!=EMPTYNODE && head->value == 0 ){
        temp = head;
        head = head->next;
        free(temp);
    }
    if(head == EMPTYNODE)
        return head;
    nodeQ_t* curr = head->next;
    nodeQ_t* prev = head;
    while(curr){
        if(curr->value == 0){
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}


nodeQ_t *multiplySparseMatricesLinkedLists(nodeQ_t *matrix_llist_1, nodeQ_t *matrix_llist_2)
{
    if(matrix_llist_1->column != matrix_llist_2->row || matrix_llist_1 == EMPTYNODE || matrix_llist_2 == EMPTYNODE)
    return EMPTYNODE;

    nodeQ_t *head = (nodeQ_t *)malloc(sizeof(nodeQ_t));
    head->row = matrix_llist_1->row;
    head->column = matrix_llist_2->column;
    head->value = -1;
    head->next = EMPTYNODE;
    nodeQ_t *curr = head;
    nodeQ_t *curr_1 = matrix_llist_1->next;
    nodeQ_t *curr_2 = matrix_llist_2->next;
    
    while (curr_1 != EMPTYNODE)
    {
        while (curr_2 != EMPTYNODE)
        {
            if (curr_1->column == curr_2->row)
            {
                findAndAdd(curr_1->row,curr_2->column,curr_1->value * curr_2->value,head);
            }
            curr_2 = curr_2->next;
        }
        curr_1 = curr_1->next;
        curr_2 = matrix_llist_2->next;
    }
    head = removeZeroVal(head);
    return head;
}

void collisionPriorityQueue(priorityNodeQ_t *item, int idx)
{
    priorityNodeQ_t *curr = g_priorityHashTable[idx];
    if(item->priority < g_priorityHashTable[idx]->priority){
        item->next = g_priorityHashTable[idx];
        g_priorityHashTable[idx] = item;
        return;
    }
    while (curr->next != EMPTYNODE && curr->next->priority < item->priority)
    {
        curr = curr->next;
    }
    if(curr->next != EMPTYNODE && curr->next->priority == item->priority){
        curr = curr->next;
    }
        item->next = curr->next;
        curr->next = item;
}

void insertPriorityHashTable(priorityNodeQ_t *item)
{
    if (EMPTYNODE == item)
    {
        return;
    }
    unsigned short key = hashFuncLab1(item->value);
    if (EMPTYNODE == g_priorityHashTable[key])
    {
        g_priorityHashTable[key] = item;
    }
    else
    {
        collisionPriorityQueue(item, key);
    }
}

priorityNodeQ_t *dequeueFromPriorityHashTable(unsigned short key)
{
    key = hashFuncLab1(key);
    if(EMPTYNODE == g_priorityHashTable[key]){
        return EMPTYNODE;
    }
    priorityNodeQ_t *rem = EMPTYNODE;
    rem = g_priorityHashTable[key];
    g_priorityHashTable[key] = g_priorityHashTable[key]->next;
    return rem;
}

void display(nodeQ_t *head)
{
    if (!head)
    {
        printf("EMPTYNODE");
    }
    while (head)
    {
        printf("%d, %d, %d -> ", head->row, head->column, head->value);
        head = head->next;
    }
    printf("\n");
    printf("\n");
    return;
}

void displayPriorityHashTable(){
    for(int i = 0; i < SIZE_HASH_TABLE; i++){
        if(g_priorityHashTable[i] != EMPTYNODE){
            printf("%d -> ", i);
            for(priorityNodeQ_t* j = g_priorityHashTable[i]; j != EMPTYNODE; j = j->next){
                printf("val: %d, priority: %d,-> ", j->value, j->priority);
            }
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    int r1 = 4, c1 = 4;
    unsigned short **arr1 = (unsigned short **)malloc(r1 * sizeof(unsigned short *));
    for (int i = 0; i < r1; i++)
        arr1[i] = (unsigned short *)malloc(c1 * sizeof(unsigned short));
    int c=1;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            arr1[i][j] = c++;
        }
    }
    nodeQ_t* head1 = convertSparseMatrixToLinkedList(arr1, r1, c1);
    display(head1);

    int r2 = 4, c2 = 3;
    unsigned short **arr2 = (unsigned short **)malloc(r2 * sizeof(unsigned short *));
    for (int i = 0; i < r2; i++)
        arr2[i] = (unsigned short *)malloc(c2 * sizeof(unsigned short));
    c=1;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            arr2[i][j] = c++;
        }
    }
    nodeQ_t* head2 = convertSparseMatrixToLinkedList(arr2, r2, c2);
    display(head2);

    nodeQ_t* head3 = multiplySparseMatricesLinkedLists(head1,head2);
    display(head3);
    
    priorityNodeQ_t* item = (priorityNodeQ_t *)malloc(sizeof(priorityNodeQ_t));
    item->value = 10;
    item->priority = 2;
    item->next = EMPTYNODE;
    insertPriorityHashTable(item);
    item = (priorityNodeQ_t *)malloc(sizeof(priorityNodeQ_t));
    item->value = 20;
    item->priority = 1;
    item->next = EMPTYNODE;
    insertPriorityHashTable(item);
    item = (priorityNodeQ_t *)malloc(sizeof(priorityNodeQ_t));
    item->value = 30;
    item->priority = 3;
    item->next = EMPTYNODE;

    insertPriorityHashTable(item);
    item = (priorityNodeQ_t *)malloc(sizeof(priorityNodeQ_t));
    item->value = 40;
    item->priority = 5;
    item->next = EMPTYNODE;

    insertPriorityHashTable(item);
    item = (priorityNodeQ_t *)malloc(sizeof(priorityNodeQ_t));
    item->value = 50;
    item->priority = 4;
    item->next = EMPTYNODE;

    insertPriorityHashTable(item);
    item = (priorityNodeQ_t *)malloc(sizeof(priorityNodeQ_t));
    item->value = 60;
    item->priority = 1;
    item->next = EMPTYNODE;

    insertPriorityHashTable(item);
    item = (priorityNodeQ_t *)malloc(sizeof(priorityNodeQ_t));
    item->value = 70;
    item->priority = 2;
    item->next = EMPTYNODE;
    insertPriorityHashTable(item);

    displayPriorityHashTable();
    priorityNodeQ_t* rem;

    rem = dequeueFromPriorityHashTable(0);
    printf("Rem val:%d\n", rem->value);
    printf("Rem priority:%d\n", rem->priority);
    dequeueFromPriorityHashTable(10);
    dequeueFromPriorityHashTable(20);
    dequeueFromPriorityHashTable(30);
    dequeueFromPriorityHashTable(40);
    dequeueFromPriorityHashTable(50);
    dequeueFromPriorityHashTable(60);
    dequeueFromPriorityHashTable(70);
    dequeueFromPriorityHashTable(80);

    displayPriorityHashTable();

    return 0;
}
// Aviral Verma, IIITN, BT20CSE214
