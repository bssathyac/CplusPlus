
// #include <D:\TrialProjects\VSCode\InitCPP\header\headerConfig.h.in>
#include "D:\TrialProjects\VSCode\InitCPP\header\linkedList.h" // ====HEADER .h file======// 
#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>


void setHeadNodeVal(st_nodeEle &st_a_node, int i_a_val)
{
    st_a_node.value = i_a_val;
}

void setNextNodeVal(st_nodeEle &st_a_currNode, int i_a_val)
{
    if(st_a_currNode.st_p_nxt_node != nullptr)
    {
        st_a_currNode.st_p_nxt_node->value = i_a_val;
    }
}

int getNextNodeVal(st_nodeEle *st_a_node)
{
    return ((st_a_node? (st_a_node->st_p_nxt_node? st_a_node->st_p_nxt_node->value:0):0));
}

int getCurrNodeVal(st_nodeEle *st_a_node)
{
    return ((st_a_node? st_a_node->value:0));
}

int getListNodeCount(st_nodeEle *st_a_Head)
{
    st_nodeEle *temp;
    int count = 1; // head has to be counted at init
    // if ( st_a_Head->st_p_nxt_node !=nullptr )
    // { 
    //     count++;
        temp = st_a_Head->st_p_nxt_node; // ->st_p_nxt_node;
        while ( temp  !=nullptr )
        {
            count++;
            temp = temp->st_p_nxt_node;
        }
    // }
    return (count);
}

int getListNodeAtN(st_nodeEle *st_a_Head, int i_a_nth)
{
    st_nodeEle *temp;
    int count = 1; // head has to be counted at init

    temp = st_a_Head;
    while (( temp  !=nullptr ) && (count<i_a_nth))
    {
        count++;
        temp = temp->st_p_nxt_node;
    }
    return (temp->value);
}

int insertListNodeAtN(st_nodeEle *st_a_Head, int i_a_nth)
{
    st_nodeEle *temp;
    int count = 1; // head has to be counted at init
    
    temp = st_a_Head;
    while (( temp  !=nullptr ) && (count<i_a_nth))
    {
        count++;
        temp = temp->st_p_nxt_node;
    }
    return (temp->value);
}

void swapXthAndYthNodeVals(st_nodeEle *st_a_Head, int i_a_xth, int i_a_yth)
{
    int k, max, min, listCount, i_t_tmp;
    st_nodeEle *st_t_temp1, *st_t_temp2;

    st_t_temp1 = st_t_temp2 = st_a_Head;
    max = (i_a_xth > i_a_yth? i_a_xth: i_a_yth);
    min = (i_a_xth + i_a_yth) % max;

    listCount = getListNodeCount(st_a_Head);

    if (max <= listCount )
    {
        for(k=1; k < max; k++)
        {
            st_t_temp1 = st_t_temp1->st_p_nxt_node;
            if(k < min)
            {
                st_t_temp2 = st_t_temp2->st_p_nxt_node;
            }
        }
        i_t_tmp = st_t_temp1->value;
        st_t_temp1->value = st_t_temp2->value;
        st_t_temp2->value = i_t_tmp;
    }
}

st_nodeEle* getListNodePtrAtN(st_nodeEle *st_a_Head, int i_a_nth)
{
    int cnt = i_a_nth-1; /* since head is the 1st element */
    st_nodeEle *st_t_temp;
    st_t_temp = st_a_Head;

    while( 
        (st_t_temp != 0) && 
        (cnt > 0)
         )
        {
            st_t_temp = st_t_temp->st_p_nxt_node;
            cnt--;
        }

        // cout << "::" << st_t_temp << "\n";

    return st_t_temp;
}

void swapXthAndYthNodePtr(st_nodeEle *st_a_Head, int i_a_xth, int i_a_yth)
{
    int i_t_yth, i_t_xth;
    st_nodeEle *st_t_tempX, *st_t_tempY, *st_t_tempN, *st_t_tempP;

    st_nodeEle *st_t_tempC = st_a_Head;

    if (i_a_yth > i_a_xth)
    {
        i_t_yth = i_a_xth;
        i_t_xth = i_a_yth;
    }
    else /* y needs to be lesser than x */
    {
        i_t_yth = i_a_yth;
        i_t_xth = i_a_xth;
    }
    
    if ( 
        (st_t_tempC != 0) &&
        (i_a_yth != i_a_xth)
    )
    {
        if ( 
            (i_a_xth > 1) &&
             (i_a_yth > 1) 
           )
        {
            st_t_tempY = getListNodePtrAtN(st_a_Head, i_t_yth);
            st_t_tempX = getListNodePtrAtN(st_a_Head, i_t_xth);

            st_t_tempP = getListNodePtrAtN(st_a_Head, (i_t_xth - 1));
            st_t_tempN = getListNodePtrAtN(st_a_Head, (i_t_xth + 1));

            if ( st_t_tempP != 0 )
                {   
                    st_t_tempP->st_p_nxt_node = st_t_tempY;
                    st_t_tempC = st_t_tempY->st_p_nxt_node;
                    st_t_tempY->st_p_nxt_node = st_t_tempN; 
                }

            st_t_tempP = getListNodePtrAtN(st_a_Head, (i_t_yth - 1));
            if ( st_t_tempP != 0 )
                {   
                    st_t_tempP->st_p_nxt_node = st_t_tempX; 
                    st_t_tempX->st_p_nxt_node = st_t_tempC; 
                }
        }
        else /* i_t_yth will be 1 as per logic above */
        {
            st_t_tempY = getListNodePtrAtN(st_a_Head, i_t_yth);
            st_t_tempX = getListNodePtrAtN(st_a_Head, i_t_xth);
            st_t_tempN = getListNodePtrAtN(st_a_Head, (i_t_xth + 1));
            st_t_tempP = getListNodePtrAtN(st_a_Head, (i_t_xth - 1));
            st_t_tempC = getListNodePtrAtN(st_a_Head, (i_t_yth + 1));
            st_t_tempX->st_p_nxt_node = st_t_tempC;
            st_t_tempP->st_p_nxt_node = st_t_tempY;
            st_t_tempY->st_p_nxt_node = st_t_tempN;
        }
    }
}

st_nodeEle * reverseLinkedListPtr(st_nodeEle *st_a_Head)
{
    st_nodeEle *st_tp_p = 0, *st_tp_c = 0, *st_tp_n = 0;
    st_tp_c = st_a_Head;

        // std::cout << "\n" << st_a_Head; // <<"\t"<< st_tp_p <<"\t"<<st_tp_n <<"\t \n";
    while(st_tp_c !=0)
    {
        st_tp_n = st_tp_c->st_p_nxt_node;
        // std::cout << "1. \n" << st_tp_c <<"\t"<< st_tp_p <<"\t"<<st_tp_n <<"\t \n";
        st_tp_c->st_p_nxt_node = st_tp_p;
        // std::cout << "2. \n" << st_tp_c <<"\t"<< st_tp_p <<"\t"<<st_tp_n <<"\t \n";
        st_tp_p = st_tp_c;
        // std::cout << "3. \n" << st_tp_c <<"\t"<< st_tp_p <<"\t"<<st_tp_n <<"\t \n";
        st_tp_c = st_tp_n;
        // st_tp_c = st_tp_n;
        // std::cout << "4. \n" << st_tp_c <<"\t"<< st_tp_p <<"\t"<<st_tp_n <<"\t \n";
    }
     st_a_Head = st_tp_p;
        // std::cout << "\n" << st_a_Head; // <<"\t"<< st_tp_p <<"\t"<<st_tp_n <<"\t \n";
        if (st_a_Head == 0)
        {
            printf("Error: null pointer");
        }
        return st_a_Head;
}

void create5ElementLinkedList(st_nodeEle &n1, st_nodeEle &n2, st_nodeEle &n3, st_nodeEle &n4, st_nodeEle &n5)
{
    n1.value = 1; // head
    n1.st_p_nxt_node = &n2;
    n2.value = 2;
    n2.st_p_nxt_node = &n3;
    n3.value = 3;
    n3.st_p_nxt_node = &n4;
    n4.value = 4;
    n4.st_p_nxt_node = &n5;
    n5.value = 5; // null tail
    n5.st_p_nxt_node = nullptr;

}

st_nodeEle * st_p_createNewfLnkedLstNode()
{
    st_nodeEle * st_tp_newNodeLL = (st_nodeEle *) calloc(1, sizeof(st_nodeEle));
    if(st_tp_newNodeLL != nullptr)
    {
        printf("Node created with address: %x :",st_tp_newNodeLL);
    }
    else
    {
        printf("Error: Memory could not be allocated");
    }

    return st_tp_newNodeLL;
}

void reverseLinkedList(st_nodeEle *st_a_Head)
{
    int i_t_nodCount, j;

    i_t_nodCount = getListNodeCount(st_a_Head);

    for(j = 0;j < i_t_nodCount/2; j++)
    {
        swapXthAndYthNodeVals(st_a_Head, j+1, i_t_nodCount-j);
    }
}

st_nodeEle * st_p_createNnodesLnkdList(int i_a_elemCnt)
{
    int i,j;
    st_nodeEle *st_tp_headNode, *st_tp_tempNode, *st_tp_PREVtempNode;
   
    for(i = i_a_elemCnt; i > 0 ; i--)
    {
        st_tp_tempNode = st_p_createNewfLnkedLstNode();

        if (st_tp_tempNode != nullptr)
        {
            if(i == i_a_elemCnt)
            {
                if (st_tp_tempNode != nullptr)
                {
                    st_tp_headNode = st_tp_tempNode;
                    if (i_a_elemCnt <= 1)
                    {
                        st_tp_headNode->st_p_nxt_node = nullptr;
                    }
                    else
                    {
                        st_tp_PREVtempNode = st_tp_tempNode; // save for the next node
                    }
                    // st_tp_headNode->st_p_nxt_node = st_tp_tempNode;
                    cout << "\n Enter the value to store in head \t";
                    cin >> j;
                    st_tp_headNode->value = j;
                }         
            }
            else
            {
                st_tp_PREVtempNode->st_p_nxt_node = st_tp_tempNode;
                cout << "\n Enter the value to store in Node \t";
                cin >> j;
                st_tp_tempNode->value = j;
                st_tp_PREVtempNode = st_tp_tempNode; // move the node to next element
            }
        }
        else
        {
            printf("Error, memory allocation failed");
        }
    }

    return st_tp_headNode;
}

void vd_printLinkedList(st_nodeEle *st_a_Head)
{
    st_nodeEle *st_tp_temp = st_a_Head;
    while(st_tp_temp != nullptr)
    {
        cout << st_tp_temp << " : " << st_tp_temp->value << "\n";
        st_tp_temp = st_tp_temp->st_p_nxt_node;

    }
}

st_nodeEle * st_p_getMidNodeOfLinkLst(st_nodeEle *st_ap_Head)
{
    st_nodeEle *st_tp_Mid, *st_tp_temp;

    st_tp_temp = st_ap_Head;
    st_tp_Mid = st_ap_Head;

    while( 
        (st_tp_temp != nullptr) &&
        (st_tp_temp->st_p_nxt_node != nullptr)
    )
    {
            st_tp_Mid = st_tp_Mid->st_p_nxt_node;
            st_tp_temp = st_tp_temp->st_p_nxt_node->st_p_nxt_node;
            // cout << "check" << "\t" << st_tp_temp <<"\n" << st_tp_Mid;

    }

    return st_tp_Mid;
}

void linkedListsFunction()
{
    cout << "print this \n Hello World! \n" ;//<< (int)HEADER_VERSION_MAJOR_VERSION_MINOR;
    int num;
    st_nodeEle node1, node2, node3, node4, node5, *st_t_nodeTmp;
    create5ElementLinkedList(node1, node2, node3, node4, node5);
    cout << getCurrNodeVal(&node1) << "\t"
         << getNextNodeVal(&node1) << "\t"
         << getNextNodeVal(&node2) << "\t"
         << getNextNodeVal(&node3) << "\t"
         << getNextNodeVal(&node4) << "\t"
         << getNextNodeVal(&node5) << "\t";

    setHeadNodeVal(node1, 10);   
    setNextNodeVal(node1, 20);   
    setNextNodeVal(node2, 30);   
    setNextNodeVal(node3, 40);   
    setNextNodeVal(node4, 50);  
    setNextNodeVal(node5, 60);  

    cout << getCurrNodeVal(&node1) << "\t" // head
        << getNextNodeVal(&node1) << "\t"
        << getNextNodeVal(&node2) << "\t"
        << getNextNodeVal(&node3) << "\t"
        << getNextNodeVal(&node4) << "\t"
        << getNextNodeVal(&node5) << "\t" //tail next is null
        << "\n"//  
        
        << getListNodeCount(&node1) << "\t" // count
        << getListNodeAtN(&node1, 3) << "\t"; // n th element

    // swapXthAndYthNodeVals(&node1, 1, 2);
    cout << getCurrNodeVal(&node2) << "\t"
         << getCurrNodeVal(&node1) << "\t";

    // reverseLinkedList(&node1);
    cout << "\n >>"    << (node1.st_p_nxt_node) << "\t"
        << (node2.st_p_nxt_node) << "\t"
        << (node3.st_p_nxt_node) << "\t"
        << (node4.st_p_nxt_node) << "\t"
        << (node5.st_p_nxt_node) << "\t" ;//tail next is null
    reverseLinkedListPtr(&node1);

    //swapXthAndYthNodePtr(&node1, 1, 2);
    cout << "\n R>>: "<< getCurrNodeVal(&node5) << "\t" // head
        << getNextNodeVal(&node5) << "\t"
        << getNextNodeVal(&node4) << "\t"
        << getNextNodeVal(&node3) << "\t"
        << getNextNodeVal(&node2) << "\t"
        << getNextNodeVal(&node1) << "\t" //tail next is null
        << "\n"// 

        << (node5.st_p_nxt_node) << "\t"
        << (node4.st_p_nxt_node) << "\t"
        << (node3.st_p_nxt_node) << "\t"
        << (node2.st_p_nxt_node) << "\t"
        << (node1.st_p_nxt_node) << "\t" ;//tail next is null

        cout <<"\n Enter the number of list elements to add to linked list \t";
        cin >> num;
        
        st_t_nodeTmp = st_p_createNnodesLnkdList(num);
        cout <<" Before the reversing of the given linked list \t" << st_t_nodeTmp <<"\n";
        vd_printLinkedList(st_t_nodeTmp);
        st_t_nodeTmp = reverseLinkedListPtr(st_t_nodeTmp);
        cout <<" After the reversing of the given linked list \t"<< st_t_nodeTmp <<"\n";
        vd_printLinkedList(st_t_nodeTmp);
        //printf( "\n Mid::> %x", getCurrNodeVal(st_p_getMidNodeOfLinkLst(st_t_nodeTmp)));
        st_t_nodeTmp = st_p_getMidNodeOfLinkLst(st_t_nodeTmp);// mid node
        cout << "\n Mid:>\t" << st_t_nodeTmp<<"\n"; // mid ptr addresss
        cout <<" Before the swap of the given linked list elements\t" << &node5 <<"\n";
        vd_printLinkedList(&node5);
        cout <<" After the swap of the given linked list elements\t" << &node1 <<"\n";
        swapXthAndYthNodePtr(&node5, 1, 5);
        vd_printLinkedList(&node1);
   
}