#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

typedef struct node {
    int data;
    struct node* leftChild, *rightChild;
} ST_TREE_NODE;


ST_TREE_NODE * newTreeNode(int a_data_mem)
{
    ST_TREE_NODE *node = (ST_TREE_NODE *)calloc(1, sizeof(ST_TREE_NODE));
    node->data = a_data_mem;
    node->leftChild = NULL;
    node->rightChild = NULL;

    return node;
}

int checkTree(void)
{
    ST_TREE_NODE *rootNode = newTreeNode(1);

    rootNode->leftChild = newTreeNode(2);
    rootNode->rightChild = newTreeNode(3);

    return 0;
}