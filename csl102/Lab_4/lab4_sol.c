#include <stdio.h>
#include "csl102lab4.h"

unsigned long size(stackRow_t row);
status_t isEmpty(stackRow_t row);
status_t isFull(stackRow_t row);

int elementsStack[NUM_STACK_ROWS][MAX_SIZE_EACH_STACK];
short topArr[NUM_STACK_ROWS];


void reset_unity(){
    for(short i=0; i<NUM_STACK_ROWS; i++)
        topArr[i] = -1;
    return;
}

void init_unity(){
   reset_unity();
}

status_t push_unity(int val, stackRow_t row){

    if(row >= NUM_STACK_ROWS)
		return STACK_FALSE;

    if(STACK_FALSE == isFull(row)){
        topArr[row] = topArr[row] + 1;
        elementsStack[row][topArr[row]] = val;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status_t pop_unity(int* ptrVal, stackRow_t row){

    if(row >= NUM_STACK_ROWS)
		return STACK_FALSE;

    if(STACK_FALSE == isEmpty(row)){
        *ptrVal = elementsStack[row][topArr[row]];
        topArr[row] = topArr[row] - 1;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status_t peek_unity(int* ptrVal, stackRow_t row){

    if(row >= NUM_STACK_ROWS)
		return STACK_FALSE;

     if(STACK_FALSE == isEmpty(row)){
        *ptrVal = elementsStack[row][topArr[row]];
        //topOfStack--;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

unsigned long size(stackRow_t row){
    return topArr[row] + 1;
}

status_t isEmpty(stackRow_t row){
    if(-1 == topArr[row])
        return STACK_TRUE;

    return STACK_FALSE;
}

status_t isFull(stackRow_t row){
    if(MAX_SIZE_EACH_STACK == topArr[row] + 1)
        return STACK_TRUE;

    return STACK_FALSE;
}
