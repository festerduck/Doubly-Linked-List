#include "DList.h"
#include <iostream>

using namespace std;

template <typename T>
DList<T>::DList()
{
    createDummyHead();
}

template <typename T>
DList<T>::~DList()
{
    //Clear The list
    Clear();
    //Delete Dummy Node
    //Write your code between these lines only
    //---------------------------
    delete(head);
    //---------------------------
}

// copy constructor
template <typename T>
DList<T>::DList(const DList& other)
{
    //Initialize current list
    createDummyHead();
    //Check if other list is empty (if empty do nothing)
    if(other.empty())
        return;
    //Iterate through all the nodes of other list
    //and add all data elements to current list
    Node<T>* other_curr = other.head->next;
    Node<T>* other_head = other.head;

    //Write your code between these lines only
    //---------------------------

    while (other_curr != other_head)
    {
        this->addTail(other_curr->data);
        other_curr = other_curr->next;
    }

    //---------------------------
}

// boolean function
template <typename T>
bool DList<T>::empty() const
{
    //Write your code between these lines only
    //---------------------------
    if (head->next == head)
        return 1;
    else
        return 0;
    //---------------------------
}

// access head element
template <typename T>
T DList<T>::headElement() const
{
    if(!empty())
        return head->next->data;
    cerr<<"List is Empty";
}

// access tail element
template <typename T>
T DList<T>::tailElement() const
{
    if(!empty())
        return head->prev->data;
    cerr<<"List is Empty";
}

// access element at specific index
template <typename T>
T DList<T>::getAt(int idx)
{
    Node<T>* pos = goToIndex(idx);
    if(pos != NULL)
    {
    //Write your code between these lines only
    //---------------------------
    return pos->data;
    //---------------------------
    }
}

// add to the head
template <typename T>
void DList<T>::addHead(T newdata)
{
    //Location to insert Head Node,
    //Between DummyHead and Actual First Node
    Node<T>* curr = head->next;

    //Create New Node
    //Write your code between these lines only
    //---------------------------
    Node<T>* node = new Node<T>;
    //---------------------------

    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    node->data = newdata;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
    //---------------------------
}

// delete the head
template <typename T>
void DList<T>::delHead()
{
    //Check if list is empty ? Do nothing
    if(empty())
        return;
    //Location to delete Head Node,
    //Just after DummyHead
    Node<T>* curr = head->next;
    //Update references
    //Write your code between these lines only
    //---------------------------
    head->next = curr->next;
    curr->next->prev = head;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete(curr);
    //---------------------------

}

// add to the head
template <typename T>
void DList<T>::addTail(T newdata)
{
    //Location to insert Head Node,
    //Between DummyHead and Actual Last Node
    Node<T>* curr = head;
    //Create New Node
    Node<T>* newnode = new Node<T>;
    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    newnode->data = newdata;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------
    newnode->prev = curr->prev;
    newnode->next = curr;
    curr->prev->next = newnode;
    curr->prev = newnode;
    //---------------------------

}

// delete the head
template <typename T>
void DList<T>::delTail()
{
    //Check if list is empty ? Do nothing
    if(empty())
        return;
    //Location to delete Tail Node,
    //Just Before DummyHead
    Node<T>* curr = head->prev;
    //Update references
    //Write your code between these lines only
    //---------------------------
    curr->prev->next = head;
    head->prev = curr->prev;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete(curr);
    //---------------------------

}

// add to the head
template <typename T>
void DList<T>::addAt(int idx, T newdata)
{
    //Get node at current position
    Node<T>* curr = goToIndex(idx);
    if(curr == NULL)    //Index exceed size
        return;

    //Create New Node
    //Write your code between these lines only
    //---------------------------
    Node<T>* node = new Node<T>;
    //---------------------------

    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    node->data = newdata;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------

    node->next = curr;
    node->prev = curr->prev;
    curr->prev->next = node;
    curr->prev = node;
    //---------------------------

}

// delete the head
template <typename T>
void DList<T>::delAt(int idx)
{
    //Get node at current position
    Node<T>* curr = goToIndex(idx);
    if(curr == NULL)    //Index exceed size
        return;

    //Update references
    //Write your code between these lines only
    //---------------------------
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete(curr);
    //---------------------------


}

// utility function to get length of list
template <typename T>
int DList<T>::length() const
{
    //Write your code between these lines only
    //---------------------------
    Node<T>* curr = head->next;
    int len;
    for (len = 0; curr != head; len++)
    {
        curr = curr->next;
    }
    return len;
    //---------------------------

}

// display the list
template <typename T>
void DList<T>::print() const
{
    //Set the starting point of list
    Node<T>* curr = head->next;
    cout << "[";
    //Iterate and display list.
    //Make sure to handle comma ',' seperation is correct
    if(!empty()){
        cout << curr->data;
        curr = curr->next;
    }
    while(curr != head){
        cout << ", " << curr->data;
        curr = curr -> next;
    }
    cout << "]" << endl;
}

// Add dummy Head and populate
template <typename T>
void DList<T>::createDummyHead()
{
    head = new Node<T>;
    head->next = head;
    head->prev = head;
}

// Clear The List
template <typename T>
void DList<T>::Clear()
{
    while(!empty())
        delHead();
}

//Go to specific index and return poiter to node at that position
//Indexing is zero based
template <typename T>
Node<T>* DList<T>::goToIndex(int idx)
{
    if(idx > length())
    {
        cerr<<"Error! Given index exceed the size of list";
        return NULL;
    }

    //Iterate uptill given index
    Node<T>* curr = head->next;
    //Write your code between these lines only
    //---------------------------
    for (int i = 0; i != idx && curr != head; i++)
    {
        curr = curr->next;
    }
    //---------------------------

    return curr;
}

