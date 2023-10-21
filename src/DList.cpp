#include "DList.h"
#include <iostream>

using namespace std;

DList::DList()
{
    createDummyHead();
}

DList::~DList()
{
    //Clear The list
    Clear();
    //Delete Dummy Node
    //Write your code between these lines only
    //---------------------------
    delete head;
    //---------------------------
}

// copy constructor
DList::DList(const DList& other)
{
    //Initialize current list
    createDummyHead();
    //Check if other list is empty (if empty do nothing)
    if(other.empty())
        return;
    //Iterate through all the nodes of other list
    //and add all data elements to current list
    Nodeptr other_curr = other.head->next;
    Nodeptr other_head = other.head;

    //Write your code between these lines only
    //---------------------------
    int counter = 0;
    while(other_curr != other_head)
    {
        addAt(counter, other_curr->data);
        counter++;
        other_curr = other_curr->next;
    }
    //---------------------------
}

// boolean function
bool DList::empty() const
{
    //Write your code between these lines only
    //---------------------------
    //TODO
    return (head->next == head);

    //---------------------------
}

// access head element
int DList::headElement() const
{
    if(!empty())
        return head->next->data;
    cerr<<"List is Empty";
}

// access tail element
int DList::tailElement() const
{
    if(!empty())
        return head->prev->data;
    cerr<<"List is Empty";
}

// access element at specific index
int DList::getAt(int idx)
{
    Nodeptr pos = goToIndex(idx);
    if(pos != NULL)
    {
    //Write your code between these lines only
    //---------------------------
    return pos->data;
    //---------------------------
    }
    return -1;
}

// add to the head
void DList::addHead(int newdata)
{
    //Location to insert Head Node,
    //Between DummyHead and Actual First Node
    Nodeptr curr = head->next;

    //Create New Node
    //Write your code between these lines only
    //---------------------------
    Nodeptr New = new Node;
    //---------------------------

    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    New->data = newdata;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------


        New->next = head->next;
        New->prev = head;
        (New->next)->prev = New;
        (New->prev)->next = New;


    //---------------------------
}

// delete the head
void DList::delHead()
{
    //Check if list is empty ? Do nothing
    if(empty())
        return;
    //Location to delete Head Node,
    //Just after DummyHead
    Nodeptr curr = head->next;
    //Update references
    //Write your code between these lines only
    //---------------------------
    (curr->prev)->next = curr->next;
    (curr->next)->prev = curr->prev;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete curr;
    //---------------------------
}

// add to the head
void DList::addTail(int newdata)
{
    //Location to insert Head Node,
    //Between DummyHead and Actual Last Node
    Nodeptr curr = head;
    //Create New Node
    Nodeptr newnode = new Node;
    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    //TODO
    newnode->data = newdata;


    //Link the new created node
    //Write your code between these lines only
    //---------------------------
    newnode->prev = curr->prev;
    newnode->next = (newnode->prev)->next;
    curr->prev = newnode;
    (newnode->prev)->next = newnode;
    //---------------------------

}

// delete the head
void DList::delTail()
{
    //Check if list is empty ? Do nothing
    if(empty())
        return;
    //Location to delete Tail Node,
    //Just Before DummyHead
    Nodeptr curr = head->prev;
    //Update references
    //Write your code between these lines only
    //---------------------------
    (curr->next)->prev = curr->prev;
    (curr->prev)->next = curr->next;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete curr;
    //---------------------------

}

// add to the head
void DList::addAt(int idx, int newdata)
{
    //Get node at current position
    Nodeptr curr = goToIndex(idx);
    if(curr == NULL)    //Index exceed size
        return;

    //Create New Node
    //Write your code between these lines only
    //---------------------------
    Nodeptr New = new Node;
    //---------------------------

    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
        New->data = newdata;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------
        New->next = curr;
        New->prev = curr->prev;
        (New->prev)->next = New;
        (New->next)->prev = New;
    //---------------------------

}

// delete the head
void DList::delAt(int idx)
{
    //Get node at current position
    Nodeptr curr = goToIndex(idx);
    if(curr == NULL)    //Index exceed size
        return;

    //Update references
    //Write your code between these lines only
    //---------------------------
    (curr->prev)->next = curr->next;
    (curr->next)->prev = curr->prev;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete curr;
    //---------------------------

}

// utility function to get length of list
int DList::length() const
{
    //Write your code between these lines only
    //---------------------------
    int counter = 0;
    Nodeptr curr = head->next;
    while(curr != head)
    {
        counter++;
        curr = curr->next;
    }
    return counter;
    //---------------------------

}

// display the list
void DList::print() const
{
    //Set the starting point of list
    Nodeptr curr = head->next;
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
void DList::createDummyHead()
{
    head = new Node;
    head->next = head;
    head->prev = head;
}

// Clear The List
void DList::Clear()
{
    while(!empty())
        delHead();
}

//Go to specific index and return pointer to node at that position
//Indexing is zero based
Nodeptr DList::goToIndex(int idx)
{
    if(idx > length())
    {
        cerr<<"Error! Given index exceed the size of list";
        return NULL;
    }

    //Iterate uptill given index
    Nodeptr curr = head->next;
    //Write your code between these lines only
    //---------------------------
    int counter = 0;
    while(curr != head)
    {
        if(counter == idx)
            break;
        counter++;
        curr = curr->next;
    }

    //---------------------------

    return curr;
}

