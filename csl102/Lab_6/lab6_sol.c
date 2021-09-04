#include <stdio.h>
#include <stdlib.h>
#include "csl102_lab6.h"
#include <time.h>

#define MAX_SIZE_STACK 1024
#define TRUE 1
#define FALSE 0

nodeQ_t* stack[MAX_SIZE_STACK] = {0};
short top = -1;
struct node* root = EMPTYNODE;

nodeQ_t* createNode(short data){
	nodeQ_t* node = (nodeQ_t*)malloc(sizeof(nodeQ_t));
	node->data = data;

	node->left = EMPTYNODE;
	node->right = EMPTYNODE;
	return node;
}

/*
void printTree(nodeQ_t* root, short space){
    if (root == NULL)
        return;
  
    space += 15;
  
    printTree(root->right, space);
  
    printf("\n\n\n");
    for (int i = 15; i < space; i++)
        printf(" ");
    printf("%d\n\n\n", root->data);
  
    printTree(root->left, space);
}

void printInorder(nodeQ_t* node){
    if(!node) 
        return;

    printInorder(node->left); // left
    printf("%d\t", node->data); // root
    printInorder(node->right); // right

}

void printPreorder(nodeQ_t* node){
    if(!node) 
        return;

    printf("%d\t", node->data); // root
    printPreorder(node->left); // left
    printPreorder(node->right); // right

}

void printPostorder(nodeQ_t* node){
    if(!node) 
        return;

    printPostorder(node->left); // left
    printPostorder(node->right); // right
    printf("%d\t", node->data); // root

}
*/

void push(nodeQ_t* p_nd){
    if(MAX_SIZE_STACK == top + 1) return;
    stack[++top] = p_nd;
    //printf("%d\n", p_nd->data);
}

unsigned short isEmpty(){
    if(-1 == top)
        return TRUE;

    return FALSE;
}

nodeQ_t* pop(){
    if(FALSE == isEmpty()) return stack[top--];
    return EMPTYNODE;
}

nodeQ_t* peek(){
    if(FALSE == isEmpty()) return stack[top];
    return EMPTYNODE;
}


void getInorder(nodeQ_t* node, short **out_array, short *out_size){
 
    if(EMPTYNODE == node) return;
    if(EMPTYNODE == *out_array) return;
    top = -1;

    nodeQ_t* curr = node;
    short counter = 0;
 
    while(TRUE){
        if(EMPTYNODE != curr){
            push(curr);                                              
            curr = curr->left; 
        }    
        else{
            curr = pop();
            if(EMPTYNODE != curr){
                (*out_array)[counter++] = curr->data;
                // this will work too: *(*out_array + counter) = curr->data;
                // this will not work: *out_array[counter]
                curr = curr->right;
            }
            else{
                *out_size = counter;
                top = -1;
                return;
            }
        }
    } 
}

void getPreorder(nodeQ_t* node, short **out_array, short *out_size){

    if(EMPTYNODE == node) return;
    if(EMPTYNODE == *out_array) return;

    top = -1;
    short counter = 0;

    nodeQ_t* curr = node;
    push(curr);

    while(TRUE){

        if(TRUE == isEmpty()){
            *out_size = counter;
            top = -1;
            return;
        }

        curr = pop();
        if(EMPTYNODE != curr){
            (*out_array)[counter++] = curr->data;
            // this will work too: *(*out_array + counter) = curr->data;
            // this will not work: *out_array[counter]
        }        

        if(EMPTYNODE != curr->right) push(curr->right);
        if(EMPTYNODE != curr->left) push(curr->left);
    }

    return;
}

void getPostorder(nodeQ_t* node, short **out_array, short *out_size){
    
    if(EMPTYNODE == node) return;
    if(EMPTYNODE == *out_array) return;

    top = -1;
    short counter = 0;
    nodeQ_t* curr = node;

    while(TRUE){ 

        while (EMPTYNODE != curr){
            if (EMPTYNODE != curr->right) push(curr->right);
            push(curr);
            curr = curr->left;
         }

         curr = pop();

        if(EMPTYNODE == curr){ 
            // this case should not happen ideally
            *out_size = counter;
            top = -1;
            return;
        } 

        if(EMPTYNODE != curr->right && peek() == curr->right){
            pop();
            push(curr);
            curr = curr->right;
        }
        else{
            (*out_array)[counter++] = curr->data;
            // this will work too: *(*out_array + counter) = curr->data;
            // this will not work: *out_array[counter]
            curr = EMPTYNODE;
        }

        if(TRUE == isEmpty()){
            *out_size = counter;
            top = -1;
            return;
        }
      } 
}
