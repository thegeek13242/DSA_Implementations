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
