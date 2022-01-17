#ifndef LINKED_LIST_CPP_HEADER_FILES
#define LINKED_LIST_CPP_HEADER_FILES

// Global vars
#include <iostream>
#include <stdlib.h>

using namespace std;
typedef struct st_ll_node
{
    struct st_ll_node *st_p_nxt_node;
    int value;
} st_nodeEle;

void setHeadNodeVal(st_nodeEle &st_a_node, int i_a_val);
void setNextNodeVal(st_nodeEle &st_a_currNode, int i_a_val);
int getNextNodeVal(st_nodeEle *st_a_node);
int getCurrNodeVal(st_nodeEle *st_a_node);
int getListNodeCount(st_nodeEle *st_a_Head);
int getListNodeAtN(st_nodeEle *st_a_Head, int i_a_nth);
st_nodeEle* getListNodePtrAtN(st_nodeEle *st_a_Head, int i_a_nth);
int insertListNodeAtN(st_nodeEle *st_a_Head, int i_a_nth);
void swapXthAndYthNodeVals(st_nodeEle *st_a_Head, int i_a_xth, int i_a_yth);
void swapXthAndYthNodePtr(st_nodeEle *st_a_Head, int i_a_xth, int i_a_yth);
st_nodeEle * reverseLinkedListPtr(st_nodeEle *st_a_Head);
void create5ElementLinkedList(st_nodeEle &n1, st_nodeEle &n2, st_nodeEle &n3, st_nodeEle &n4, st_nodeEle &n5);
st_nodeEle * st_p_createNewfLnkedLstNode();
void reverseLinkedList(st_nodeEle *st_a_Head);
st_nodeEle * st_p_createNnodesLnkdList(int i_a_elemCnt);
void vd_printLinkedList(st_nodeEle *st_a_Head);
st_nodeEle * st_p_getMidNodeOfLinkLst(st_nodeEle *st_ap_Head);

#endif // LINKED_LIST_CPP_HEADER_FILES