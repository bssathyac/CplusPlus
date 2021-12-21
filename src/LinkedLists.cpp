#include <iostream>
// #include <D:\TrialProjects\VSCode\InitCPP\header\headerConfig.h.in>
#include "D:\TrialProjects\VSCode\InitCPP\header\linkedList.h" // ====HEADER .h file======// 
using namespace std;


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
        vd_printLinkedList(st_t_nodeTmp);
        cout <<" Before the reversing of the given linked list \t" << st_t_nodeTmp <<"\n";
        st_t_nodeTmp = reverseLinkedListPtr(st_t_nodeTmp);
        cout <<" After the reversing of the given linked list \t"<< st_t_nodeTmp <<"\n";
        vd_printLinkedList(st_t_nodeTmp);
        //printf( "\n Mid::> %x", getCurrNodeVal(st_p_getMidNodeOfLinkLst(st_t_nodeTmp)));
        st_t_nodeTmp = st_p_getMidNodeOfLinkLst(st_t_nodeTmp);// mid node
        cout << "\n Mid:>\t" << st_t_nodeTmp; // mid ptr addresss


        
}