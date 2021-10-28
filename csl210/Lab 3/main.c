#include "csl210_lab3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SPACE_GAP_LEVEL 5;

void printTree(btNode_t* root, short space)
{
    if (root == NULL)
        return;
  
    space += SPACE_GAP_LEVEL;
  
    printTree(root->right, space);
  
    printf("\n");
    // for (int i = SPACE_GAP_LEVEL; i < space; i++)
    //     printf(" ");
    int i = SPACE_GAP_LEVEL;
    while(i<space)
    {
        printf(" ");
        i++;
    }
    printf("%c, %d\n", root->value, root->frequency);
  
    printTree(root->left, space);
}

void printInorder(btNode_t* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d->",node->frequency);
    printInorder(node->right);
}

int main()
{
    char input[]="qwertyqqwfrtggggbryyyyyyyeeeeqqqqqqq";
    // char input[] = "abc";
    unsigned short sz = strlen(input);
    btNode_t *root = createHuffmanTree(input, sz);
    printTree(root, 5);
    printInorder(root);
}