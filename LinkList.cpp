/***************************************************************************************************
File: LinkList.cpp
Author : <Jeni Robbie>
Description: function definitions for IntList class
Date Created: 16/02/20
Last Modified: 20/02/20

/***************************************************************************************************/
#include "LinkList.h"

// Constructor
Intlist::Intlist()
{
    Head = nullptr;
    Tail = nullptr;
}

// Destructor

Intlist :: ~Intlist()
{
    Node* temp;
    while (Head != nullptr)     //Loop until list is exhausted i.e. head is pointing to nothing
    {
        temp = Head;
        Head = Head->right;     //Move through list from left to right and reassign head
        delete temp;        //delete old head
    }
}

// Tests
//Check if list is empty
bool Intlist::isEmpty() const
{
    return (Head == nullptr && Tail==nullptr) ? true : false; //list is empty if head and tail are null (both just to make sure noth has happened)
}

// Insert to list at position where integer fits in in ascending order
bool Intlist::Insert(const int& new_element)
{

    Node* oldNode=nullptr;  //holds location of previous node in list
    Node* temp= nullptr;    //hold   location of temporary node in list
    Node* new_node= nullptr;    //Holds location of new node in list
    new_node = new Node;        //create new node and assign location to new_node pointer
    new_node->Element = new_element;        //Set new node element to be user input integer





if (Head==nullptr)  //Insert into empty list
    {
        Head = new_node;
        Tail = new_node;
        return true;
    }
    else if (Head->Element >= new_element)  //Insert new head if less than value or same
    {
       
        new_node->right = Head;     //Point new node on right to head 
        Head -> left = new_node;         //Point current head to new node on left (as its element is less or same)
        Head = new_node;            //Assign head pointer to new node
        return true;
    }
    else if (Tail->Element <= new_element) //if element  more than value or same as current tail
    {

        new_node->left = Tail;      //Point new node to tail as left
        Tail->right = new_node;        //Point cureent tail node to new node on right (as its element is greter or same)
        Tail = new_node;        //Assign tail pointer to new node
        return true;
    }
    //If element is added between Tail and head
    else
    {

        //If the insert item might be in the middle of the list

        int differenceH = 0;        //difference between head and serach element
        int differenceT = 0;         //difference between head and serach element

        differenceH = abs(new_element - Head->Element);
        differenceT = abs(Tail->Element - new_element);

        if (differenceH <= differenceT)
        {
            oldNode = Head;
            temp = Head->right;
            while ((temp->Element < new_element) && (temp->right != Tail))     //Loop until less temporary pointer element is more than new element. Note: second condiition not needed just precautionary loop stop
            {
                oldNode = temp;
                temp = temp->right; //List moves through right to left

            }
            new_node->right = temp;     //Set new node pointers
            new_node->left = oldNode;

            oldNode->right = new_node;  //Set surrounding pointers to point to new node
            temp->left = new_node;
            return true;

        }
        else
        {
            oldNode = Tail;     //If insert item is closer to tail element value
            temp = Tail->left;
            while ((temp->Element > new_element) && (temp->left != Tail))     //Loop until less temporary pointer element is more than new element. Note: second condiition not needed just precautionary loop stop
            {
                oldNode = temp;
                temp = temp->left; //List moves through right to left

            }
            new_node->left = temp;     //Set new node pointers
            new_node->right = oldNode;

            oldNode->left = new_node;  //Set surrounding pointers to point to new node
            temp->right = new_node;
            return true;
        }
    }
}




// Delete item in list

bool Intlist::Delete(const int& del_element)
{
    Node* temp = nullptr;         //Temporary pointer for deletion and moving through list
    Node* old = nullptr;          //Pointer for node before temporary pointer node
    Node* afterTemp = nullptr;  //Pointer for node to left of temporary pointer node


    if (isEmpty())
        return false;
    else if ((Head->Element == del_element) && (Tail->Element == del_element))    //If the list only has one item that is the delete item the tail and head need to be set to null
    {
        temp = Head;
        Head = nullptr;
        Tail = nullptr;
        delete temp;
        return true;
    }
    else if (Head->Element == del_element)  //if the head element is the item we want to delete
    {
        temp = Head;                //Set temp pointer to point to head element
        Head = Head->right;             //Move head one node towards tail
        Head->left = nullptr;           //Set left pointer to null so it isn't point at garbage
        delete temp;
        return true;
    }

    else if (Head->right == nullptr)        //if there is no other element in the list and previous checks have failed
        return false;       //there is no item in the list

    else if (Tail->Element == del_element)      //If the tail is the delete item
    {
        temp = Tail;
        Tail = Tail->left;      //move tail 1 node towards head
        Tail->right = nullptr;      //Set right pointer to null so it isnt pointing at garbage
        delete temp;
        return true;

    }
    else
    {
        //If the delete item might be in the middle of the list

        int differenceH = 0;        //difference between head and serach element
        int differenceT = 0;         //difference between head and serach element

        differenceH = abs(del_element - Head->Element);
        differenceT = abs(Tail->Element - del_element);

        if (differenceH <= differenceT) //Traverse from head to tail if delete item is closer to head
        {
            old = Head;
            temp = Head->right;

            afterTemp = temp->right;
            while ((temp->Element != del_element) && (temp->right != nullptr))                   //Until the end of list
            {
                old = temp;                              //Assign all the pointer to correct place moving from head to tail through loop  
                temp = temp->right;
                afterTemp = temp->right;
            }
            if (temp->Element == del_element)           //if delete item found
            {
                afterTemp->left = temp->left;           //Set the afterTemp to point to temps left
                old->right = temp->right;               //Set the node before temp to point to afterTemp

                delete temp;
                return true;
            }
            else  // list exhausted
                return false;       //if not found 
        }
        else
        {
            old = Tail;                                 //Traverse from Tail to Head if delete item is closer to Tail
            temp = Tail->left;
            afterTemp = temp->left;

            while ((temp->Element != del_element) && (temp->left != nullptr))                   //Until the end of list or item found
            {
                old = temp;                              //Assign all the pointer to correct place moving from head to tail through loop  
                temp = temp->left;
                afterTemp = temp->left;
            }
            if (temp->Element == del_element)           //if delete item found
            {
                afterTemp->right = temp->right;           //Set the afterTemp to point to temps left
                old->left = temp->left;               //Set the node before temp to point to afterTemp

                delete temp;
                return true;
            }
            else  // list exhausted
                return false;       //if not found 
        }

    }
}


// Print list
void Intlist::Print(bool isAsc) const
{
  Node* temp;
  if (isEmpty())
  {
      cout << "List: Empty!" << endl;
  }
  else
  {
      if (isAsc == true) {      //To print in ascending order
          temp = Head;
          while (temp != nullptr)   //Until list has been exhausted
          {
              cout << temp->Element << " ";
              temp = temp->right;       //Loop though list by setting pinter to the right node
          }
      }
      else
      {                     //To print in descending order
          temp = Tail;
          while (temp != nullptr)       //Until list is exhausted
          {
              cout << temp->Element << " ";
              temp = temp->left;        //Assign temp to node to left
          }
      }
  }
    
    


}






