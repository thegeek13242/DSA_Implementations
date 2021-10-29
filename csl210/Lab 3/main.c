#include "csl210_lab3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SPACE_GAP_LEVEL 5;

void printTree(btNode_t *root, short space)
{
     if (root == NULL)
          return;

     space += SPACE_GAP_LEVEL;

     printTree(root->right, space);

     printf("\n");
     // for (int i = SPACE_GAP_LEVEL; i < space; i++)
     //     printf(" ");
     int i = SPACE_GAP_LEVEL;
     while (i < space)
     {
          printf(" ");
          i++;
     }
     printf("%c, %d\n", root->value, root->frequency);

     printTree(root->left, space);
}

void printInorder(btNode_t *node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d->", node->frequency);
     printInorder(node->right);
}

int main()
{
     // char input[] = {'a', 'b', 'c', 'd', 'g', 'h', 'i', 'd', 'c', 'b', 'a', 'k', 'g', 'i', 'd', 'a', 'c', 'c', 'r', 's', 'a', 'b', 'i', 'h', 'r', 'r', 'r', 'd', 'c', 's'};
     // char input[]="qwertyqqwfrtggggbryyyyyyyeeeeqqqqqqq";
     // char input[] = "abc";
     unsigned short sz = 30;
     btNode_t *root = createHuffmanTree(input, sz);
     printTree(root, 5);
     printInorder(root);
}

//Aviral Verma, BT20CSE214, IIITN

/* My Output 1:

                    c, 5

               , 9      

                    r, 4

          , 17

                    d, 4

               , 8      

                    a, 4

     , 30

                         s, 2

                    , 4

                         h, 2

               , 7

                    i, 3

          , 13

                    b, 3

               , 6

                         g, 2

                    , 3

                         k, 1
1->3->2->6->3->13->3->7->2->4->2->30->4->8->4->17->4->9->5->

My Output 2:

               q, 10

          , 20

                    e, 5

               , 10

                         r, 3

                    , 5

                         t, 2

     , 36

               y, 8

          , 16

                    g, 4

               , 8

                         w, 2

                    , 4

                              b, 1

                         , 2

                              f, 1
1->2->1->4->2->8->4->16->8->36->2->5->3->10->5->20->10->

My Output 3:

               b, 1

          , 2

               a, 1

     , 3

          c, 1
1->3->1->2->1->
*/