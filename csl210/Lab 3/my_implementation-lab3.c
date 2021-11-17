#include "csl210_lab3.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

btNode_t **freq_array;
int length_freq_array;

btNode_t *createNode(char value, int freq)
{
    btNode_t *node = (btNode_t *)malloc(sizeof(btNode_t));
    node->value = value;
    node->frequency = freq;
    node->left = EMPTYNODE;
    node->right = EMPTYNODE;
    return node;
}

void sort()
{
    int i, j;
    btNode_t *temp;
    for (i = 0; i < length_freq_array; i++)
    {
        for (j = 0; j < length_freq_array - 1; j++)
        {
            if (freq_array[j]->frequency > freq_array[j + 1]->frequency)
            {
                temp = freq_array[j];
                freq_array[j] = freq_array[j + 1];
                freq_array[j + 1] = temp;
            }
        }
    }
}

int isPresent(char c, int *location) //linear search to find location of character
{
    for (int idx = 0; idx < length_freq_array; idx++)
    {
        if (freq_array[idx] == EMPTYNODE)
        {
            return FALSE;
        }
        else if (freq_array[idx]->value == c)
        {
            *location = idx;
            return TRUE;
        }
    }
    return FALSE;
}

void gen_freq_array(char *array) //array is original string
{
    freq_array = (btNode_t **)malloc(sizeof(btNode_t *) * (length_freq_array));
    for (int init = 0; init < length_freq_array; init++)
    {
        freq_array[init] = EMPTYNODE;
    }
    int location = 0;
    int idx;
    int counter_for_char_array = 0;
    for (idx = 0; idx < length_freq_array; idx++)
    {
        if (isPresent(array[idx], &location) == TRUE)
        {
            (freq_array[location]->frequency)++;
        }
        else
        {
            freq_array[counter_for_char_array++] = createNode(array[idx], 1);
        }
    }
    length_freq_array = counter_for_char_array;
    return;
}

btNode_t *createHuffmanTree(char input[], unsigned short sz)
{
    // freq_array = EMPTYNODE;
    length_freq_array = sz;
    gen_freq_array(input);
    sort();
    for(int i = 0; i < length_freq_array; i++)
    {
        printf("%c %d\n", freq_array[i]->value, freq_array[i]->frequency);
    }
    while (length_freq_array > 1)
    {
        btNode_t *left = freq_array[0];
        btNode_t *right = freq_array[1];
        btNode_t *parent = createNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        freq_array[0] = parent;
        freq_array[1] = createNode('\0', 65535);
        sort();
        length_freq_array--;
    }
    return freq_array[0];
}

// Aviral Verma, BT20CSE214 - Lab 3 (IIIT Nagpur)