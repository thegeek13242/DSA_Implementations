#include "csl210_lab1.h"

void printTable(){
	for(int i=0;i<SIZE_HASH_TABLE;i++){
		priorityNodeQ_t* temp = g_priorityHashTable[i];
		printf("[%d] -> ",i);
		while(temp){
			printf("(v:%d,p:%d) -> ",temp->value,temp->priority);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

void printlist(nodeQ_t *head)
{
  nodeQ_t *temp = head;
  while (temp != EMPTYNODE)
  {
    printf("v:%d\tr:%d\tc:%d\t\n", temp->value, temp->row, temp->column);
    temp = temp->next;
  }
}

int main(){
	unsigned short row=0,column=0;
	
	// arr1 m1 3x3
	
	row=3; column=3;
	unsigned short ** arr1 = (unsigned short **)malloc(row * sizeof(unsigned short));

	for (int r = 0; r < row; r++){
		arr1[r] = (unsigned short *)malloc(column * sizeof(unsigned short));
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			arr1[i][j]=0;
		}
	}

	arr1[0][1]=1;
	arr1[1][0]=2;
	arr1[1][2]=2;
	arr1[2][1]=1;
	arr1[2][2]=3;

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			printf("%d ",arr1[i][j]);
		}
		printf("\n");
	}

	nodeQ_t* m1=convertSparseMatrixToLinkedList(arr1,row,column);
	printlist(m1);
	printf("\n");

	//------------
	
	// arr2 m2 3x3

	row=3; column=3;
	unsigned short ** arr2 = (unsigned short **)malloc(row * sizeof(unsigned short));

	for (int r = 0; r < row; r++){
		arr2[r] = (unsigned short *)malloc(column * sizeof(unsigned short));
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			arr2[i][j]=0;
		}
	}

	arr2[0][0]=2;
	arr2[1][1]=2;
	arr2[2][0]=2;
	arr2[2][2]=2;

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			printf("%d ",arr2[i][j]);
		}
		printf("\n");
	}

	nodeQ_t* m2=convertSparseMatrixToLinkedList(arr2,row,column);
	printlist(m2);	
	printf("\n");
	
	//------------
	
	// arr3 m3 3x1

	row=3; column=1;
	unsigned short ** arr3 = (unsigned short **)malloc(row * sizeof(unsigned short));

	for (int r = 0; r < row; r++){
		arr3[r] = (unsigned short *)malloc(column * sizeof(unsigned short));
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			arr3[i][j]=0;
		}
	}

	arr3[0][0]=1;
	arr3[2][0]=3;

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			printf("%d ",arr3[i][j]);
		}
		printf("\n");
	}

	nodeQ_t* m3=convertSparseMatrixToLinkedList(arr3,row,column);
	printlist(m3);
	printf("\n");

	//------------
	
	// arr4 m4 1x3

	row=1; column=3;
	unsigned short ** arr4 = (unsigned short **)malloc(row * sizeof(unsigned short));

	for (int r = 0; r < row; r++){
		arr4[r] = (unsigned short *)malloc(column * sizeof(unsigned short));
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			arr4[i][j]=0;
		}
	}

	arr4[0][1]=2;
	arr4[0][2]=1;

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			printf("%d ",arr4[i][j]);
		}
		printf("\n");
	}

	nodeQ_t* m4=convertSparseMatrixToLinkedList(arr4,row,column);
	printlist(m4);
	printf("\n");

	//------------
	
	// arr5 m5 3x4

	row=3; column=4;
	unsigned short ** arr5 = (unsigned short **)malloc(row * sizeof(unsigned short));

	for (int r = 0; r < row; r++){
		arr5[r] = (unsigned short *)malloc(column * sizeof(unsigned short));
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			arr5[i][j]=0;
		}
	}

	arr5[0][3]=1;
	arr5[1][0]=2;
	arr5[1][2]=4;
	arr5[2][3]=3;

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			printf("%d ",arr5[i][j]);
		}
		printf("\n");
	}

	nodeQ_t* m5=convertSparseMatrixToLinkedList(arr5,row,column);
	printlist(m5);
	printf("\n");

	//------------
	
	// arr6 m6 4x3

	row=4; column=3;
	unsigned short ** arr6 = (unsigned short **)malloc(row * sizeof(unsigned short));

	for (int r = 0; r < row; r++){
		arr6[r] = (unsigned short *)malloc(column * sizeof(unsigned short));
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			arr6[i][j]=0;
		}
	}

	arr6[0][1]=4;
	arr6[1][0]=1;
	arr6[1][2]=5;
	arr6[2][2]=6;
	arr6[3][0]=1;

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			printf("%d ",arr6[i][j]);
		}
		printf("\n");
	}

	nodeQ_t* m6=convertSparseMatrixToLinkedList(arr6,row,column);
	printlist(m6);
	printf("\n");
	//------------
	
	// mul1=m1 x m2 [3x3:3x3]==3x3
	nodeQ_t* mul1 = multiplySparseMatricesLinkedLists(m1,m2);
	printlist(mul1);
	printf("\n");
	// mul2=m2 x m3 [3x3:3x1]==3x1
	nodeQ_t* mul2 = multiplySparseMatricesLinkedLists(m2,m3);
	printlist(mul2);
	printf("\n");
	// mul3=m3 x m4 [3x1:1x3]==3x3
	nodeQ_t* mul3 = multiplySparseMatricesLinkedLists(m3,m4);
	printlist(mul3);
	printf("\n");
	// mul4=m4 x m3 [1x3:3x1]==1x1
	nodeQ_t* mul4 = multiplySparseMatricesLinkedLists(m4,m3);
	printlist(mul4);
	printf("\n");
	// mul5=m1 x m5 [3x3:3x4]==3x4
	nodeQ_t* mul5 = multiplySparseMatricesLinkedLists(m1,m5);
	printlist(mul5);
	printf("\n");
	// mul6=m5 x m6 [3x4:4x3]==3x3
	nodeQ_t* mul6 = multiplySparseMatricesLinkedLists(m5,m6);
	printlist(mul6);
	printf("\n");
	// mul7=m6 x m5 [4x3:3x4]==4x4
	nodeQ_t* mul7 = multiplySparseMatricesLinkedLists(m6,m5);
	printlist(mul7);
	printf("\n");

	// [0] v=0 p=2
	priorityNodeQ_t* temp=NULL;
    temp = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp->next=EMPTYNODE;
    temp->value=0;
    temp->priority=2;
	insertPriorityHashTable(temp);
	printTable();
	printf("\n");
	// [0] v=10 p=5
	priorityNodeQ_t* temp1=NULL;
    temp1 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp1->next=EMPTYNODE;
    temp1->value=10;
    temp1->priority=5;
	insertPriorityHashTable(temp1);
	printTable();
	printf("\n");
	// [0] v=5 p=1
	priorityNodeQ_t* temp2=NULL;
    temp2 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp2->next=EMPTYNODE;
    temp2->value=5;
    temp2->priority=1;
	insertPriorityHashTable(temp2);
	printTable();
	printf("\n");
	// [0] v=15 p=5
	priorityNodeQ_t* temp3=NULL;
    temp3 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp3->next=EMPTYNODE;
    temp3->value=15;
    temp3->priority=5;
	insertPriorityHashTable(temp3);
	printTable();
	printf("\n");
	// [0] v=105 p=5
	priorityNodeQ_t* temp4=NULL;
    temp4 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp4->next=EMPTYNODE;
    temp4->value=105;
    temp4->priority=5;
	insertPriorityHashTable(temp4);
	printTable();
	printf("\n");


	// [1] v=1 p=1
	priorityNodeQ_t* temp5=NULL;
    temp5 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp5->next=EMPTYNODE;
    temp5->value=1;
    temp5->priority=1;
	insertPriorityHashTable(temp5);
	printTable();
	printf("\n");	
	// [1] v=11 p=2
	priorityNodeQ_t* temp6=NULL;
    temp6 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp6->next=EMPTYNODE;
    temp6->value=11;
    temp6->priority=2;
	insertPriorityHashTable(temp6);
	printTable();
	printf("\n");	
	// [1] v=21 p=1
	priorityNodeQ_t* temp7=NULL;
    temp7 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp7->next=EMPTYNODE;
    temp7->value=21;
    temp7->priority=1;
	insertPriorityHashTable(temp7);
	printTable();
	printf("\n");	
	// [1] v=31 p=4
	priorityNodeQ_t* temp8=NULL;
    temp8 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp8->next=EMPTYNODE;
    temp8->value=31;
    temp8->priority=4;
	insertPriorityHashTable(temp8);
	printTable();
	printf("\n");	
	// [1] v=6 p=3
	priorityNodeQ_t* temp9=NULL;
    temp9 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp9->next=EMPTYNODE;
    temp9->value=6;
    temp9->priority=3;
	insertPriorityHashTable(temp9);
	printTable();
	printf("\n");	
	// [1] v=16 p=1
	priorityNodeQ_t* temp0=NULL;
    temp0 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp0->next=EMPTYNODE;
    temp0->value=16;
    temp0->priority=1;
	insertPriorityHashTable(temp0);
	printTable();
	printf("\n");


	// [3] v=3 p=3
	priorityNodeQ_t* temp10=NULL;
    temp10 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp10->next=EMPTYNODE;
    temp10->value=3;
    temp10->priority=3;
	insertPriorityHashTable(temp10);
	printTable();
	printf("\n");	
	// [3] v=8 p=5
	priorityNodeQ_t* temp20=NULL;
    temp20 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp20->next=EMPTYNODE;
    temp20->value=8;
    temp20->priority=5;
	insertPriorityHashTable(temp20);
	printTable();
	printf("\n");
	// [3] v=13 p=3
	priorityNodeQ_t* temp30=NULL;
    temp30 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp30->next=EMPTYNODE;
    temp30->value=13;
    temp30->priority=3;
	insertPriorityHashTable(temp30);
	printTable();
	printf("\n");	
	// [3] v=18 p=3
	priorityNodeQ_t* temp40=NULL;
    temp40 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp40->next=EMPTYNODE;
    temp40->value=18;
    temp40->priority=3;
	insertPriorityHashTable(temp40);
	printTable();
	printf("\n");	
	// [3] v=23 p=2
	priorityNodeQ_t* temp50=NULL;
    temp50 = (priorityNodeQ_t*)malloc(sizeof(priorityNodeQ_t));
    temp50->next=EMPTYNODE;
    temp50->value=23;
    temp50->priority=2;
	insertPriorityHashTable(temp50);
	printTable();
	printf("\n");

	priorityNodeQ_t* test;
	// deques [0]
	test = dequeueFromPriorityHashTable(0);
	if(test){
		printf("%d\n",test->value);
	}else{
		printf("%d\n",test);
	}
	printTable();
	printf("\n");
	
	// deques [0]
	test = dequeueFromPriorityHashTable(0);
	if(test){
		printf("%d\n",test->value);
	}else{
		printf("%d\n",test);
	}
	printTable();
	printf("\n");

	// deques [0]
	test = dequeueFromPriorityHashTable(0);
	if(test){
		printf("%d\n",test->value);
	}else{
		printf("%d\n",test);
	}
	printTable();
	printf("\n");
	
	// deques [0]
	test = dequeueFromPriorityHashTable(0);
	if(test){
		printf("%d\n",test->value);
	}else{
		printf("%d\n",test);
	}
	printTable();
	printf("\n");
	
	// deques [0]
	test = dequeueFromPriorityHashTable(0);
	if(test){
		printf("%d\n",test->value);
	}else{
		printf("%d\n",test);
	}
	printTable();
	printf("\n");

	
	// deques [0]
	test = dequeueFromPriorityHashTable(0);
	if(test){
		printf("%d\n",test->value);
	}else{
		printf("%d\n",test);
	}
	printTable();
	printf("\n");

	// deques [1]
	test = dequeueFromPriorityHashTable(1);
	if(test){
		printf("%d\n",test->value);
	}else{
		printf("%d\n",test);
	}
	printTable();
	printf("\n");	

	
	// deques [3]
	test = dequeueFromPriorityHashTable(3);
	if(test){
		printf("%d\n",test->value);
	}else{
		printf("%d\n",test);
	}
	printTable();
	printf("\n");

	
	// deques [1]
	test = dequeueFromPriorityHashTable(1);
	if(test){
		printf("%d\n",test->value);
	}else{
		printf("%d\n",test);
	}
	printTable();
	printf("\n");
}