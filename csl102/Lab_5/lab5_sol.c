#include <stdio.h>
#include <stdlib.h>
#include "csl102_lab5.h"

int queue[MAX_SIZE_QUEUE];
short frontIdx = -1;
short backIdx = -1;

status_t isEmpty(){
    status_t s;
    s = (-1 == frontIdx) ? QUEUE_TRUE : QUEUE_FALSE;
    return s;
}

status_t isFull(){
    status_t s;
    s = ((backIdx + 1 == frontIdx) || (0 == frontIdx && MAX_SIZE_QUEUE - 1 == backIdx)) ? QUEUE_TRUE : QUEUE_FALSE;
    return s;
}

void create(){
	for(short i=0; i<MAX_SIZE_QUEUE; i++)
        queue[i] = -1;
    return;
}

status_t enqueueAtIndex(int value, int index){
	if((index > MAX_SIZE_QUEUE - 1) || 
		(QUEUE_TRUE == isFull()) ||
		(index > backIdx + 1) || // this case will not be tested
		(index < frontIdx)) // this case will not be tested
		return QUEUE_FALSE;

		if(-1 == frontIdx) 
			frontIdx = 0;

		for(short i = backIdx; i >= index; i--){
			queue[i+1] = queue[i];
		}
	
		queue[index] = value;
		backIdx++;

	return QUEUE_TRUE;
}

status_t dequeueFromIndex(int index, int *out_value){
	if((index > MAX_SIZE_QUEUE - 1) || 
		(QUEUE_TRUE == isEmpty()) ||
		(index < frontIdx) || // this case will not be tested
		(index > backIdx)) // this case will not be tested
		return QUEUE_FALSE;

		*out_value = queue[index];
		for(short i = index; i <= backIdx; i++){
			queue[i] = queue[i+1];
		}
	
		if(index == frontIdx)
			frontIdx++;
		else
			--backIdx;

	return QUEUE_TRUE;
}

status_t front(int *out_value){
	if(QUEUE_FALSE == isEmpty()){
        *out_value = queue[frontIdx];
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

status_t back(int *out_value){
	if(QUEUE_FALSE == isEmpty()){
        *out_value = queue[backIdx];
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

int* getQueue(){
	return queue;
}