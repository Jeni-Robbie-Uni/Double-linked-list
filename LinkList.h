/***************************************************************************************************
File: LinkList.h
Author : <Jeni Robbie>
Description: header file for IntList class declaration for a linked listand internal Node declaration
Date Created: 16/03/20
Last Modified: 20/03/20

/***************************************************************************************************/


#pragma once
#include <iostream>
using namespace std;

class Intlist
{
private:
    class Node
    {
    public:
        int Element;        //Integer stored in node
        Node* right;     //Pointer to node on right
        Node* left; //Pointer to node on left of current node
       //Constructors 
        Node() {
            right = nullptr, left = nullptr;
        }
        Node(int data, Node* pnode = nullptr, Node* onode = nullptr) {
            Element = data, right = pnode, left=onode;
        }
    };

    Node* Head;     //Pointer to start of list
    Node* Tail; //Pointer to end of list
public:
    Intlist();      //constructor
    ~Intlist();     //destructor
    bool isEmpty() const;   //check if list is empty
    bool Insert(const int& new_element);    //Insert new element to list
    bool Delete(const int& del_element);        //Delete an element from the list
    void Print(bool) const;         //Print the list in ascending or descending order

};
