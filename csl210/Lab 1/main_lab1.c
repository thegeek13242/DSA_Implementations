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
    dequeueFromPriorityHashTable(0);
    dequeueFromPriorityHashTable(0);
    dequeueFromPriorityHashTable(0);
    dequeueFromPriorityHashTable(0);
    dequeueFromPriorityHashTable(0);
    dequeueFromPriorityHashTable(0);
    dequeueFromPriorityHashTable(4);
    dequeueFromPriorityHashTable(0);

    displayPriorityHashTable();

    return 0;
}
// Aviral Verma, IIITN, BT20CSE214