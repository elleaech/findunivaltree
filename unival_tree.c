#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define OK 0
#define NOT_OK -1
#define INITIALIZED 999

typedef struct tree_
{
    int8_t bin;
    struct tree_ *left;
    struct tree_ *right;
} Tree;

Tree *
node(int8_t bin, Tree *left, Tree *right)
{
    Tree *tree = malloc(sizeof(Tree));

    if (NULL != tree)
    {
        tree->bin = bin;

        tree->left = left;
        tree->right = right;
    }

    return tree;
}

void destroyTree(Tree **tree)
{
    if (NULL != tree && NULL != *tree)
    {
        Tree *treeValue = *tree;
        destroyTree(&treeValue->left);
        destroyTree(&treeValue->right);

        free(*tree);
        *tree = NULL;
    }
}

int32_t
countUnivalSubtrees(Tree *startNode)
{
    if (NULL == startNode->right && NULL == startNode->right)
    {
        return 1;
    }
    else if (startNode->right->bin == startNode->bin && startNode->left->bin == startNode->bin)
    {
        return 1 + countUnivalSubtrees(startNode->left) + countUnivalSubtrees(startNode->right);
    }

    return 0 + countUnivalSubtrees(startNode->left) + countUnivalSubtrees(startNode->right);
}

int main()
{
    Tree *root = node(0,
                      node(1, NULL, NULL),
                      node(0,
                           node(1,
                                node(1, NULL, NULL),
                                node(1, NULL, NULL)),
                           node(0, NULL, NULL)));

    /* DO STUFFS */
    int32_t univalSubtrees = countUnivalSubtrees(root);
    printf("Unival subtrees: %d\n", univalSubtrees);

    destroyTree(&root);

    return 0;
}
