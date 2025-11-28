#include "list.hpp"

ListNode_t* NewListNode(){
    ListNode_t* NewNode = new ListNode_t;
    NewNode -> data = 0;
    NewNode -> pNext = nullptr;
    return NewNode;
}

void FreeListNode(ListNode_t* elem){
    if (elem != nullptr)
    {
        delete elem;
    }
}

List_t* NewList(){
    List_t* NewCreatedList = new List_t;
    NewCreatedList -> pHead = nullptr;
    NewCreatedList -> pTail = nullptr;
    NewCreatedList -> size = 0;
    return NewCreatedList;
}

void FreeList(List_t* list) {
    if (list != nullptr)                                    //Sicherheitscheck: Existiert die Liste überhaupt?
    {
        ListNode_t* CurrentNode = list -> pHead;            //Ersten Knoten speichern
        while (CurrentNode != nullptr)                      //Solange bis ein nullptr in CurrentNode gespeichert wird
        {
            ListNode_t* NextNode = CurrentNode -> pNext;    //Der Pointer zum nächsten Knoten wird gespeichert
            FreeListNode(CurrentNode);                      //Der aktuelle Knoten wird gelöscht
            CurrentNode = NextNode;                         //While Schleife geht weiter mit nächstem Knoten
        }
        delete list;
    }
}

int InsertIntoLinkedList(List_t* list, ListNode_t* elem) {
    if (list == nullptr || elem == nullptr)
    {
        return 1;
    }
    else
    {
        elem -> pNext = nullptr;
        if (list -> size == 0)
        {
            list -> pHead = elem;
            list -> pTail = elem;
        }
        else
        {
            list -> pTail -> pNext = elem;
            list -> pTail = elem;
        }
        list -> size++; 
        return 0;
    }
}

int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node, ListNode_t* elem){
    if (node == list -> pTail)
    {
        return InsertIntoLinkedList(list, elem);
    }
    else
    {
        elem -> pNext = node -> pNext;
        node -> pNext = elem;
        list -> size++;
    }
    return 0;
}