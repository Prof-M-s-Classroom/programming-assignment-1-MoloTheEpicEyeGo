//
// Created by Manju Muralidharan on 2/17/25.
//

#ifndef CS210PA1_SPACEROUTE_H
#define CS210PA1_SPACEROUTE_H
#include <iostream>
using namespace std;

class SpaceRoute
{

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        while (temp->next!=NULL)
            temp = temp->next;
        delete temp;
        length--;
    }

    void deleteNode(int targetindex) {
        //if list is empty, print error message
        if (head == NULL) {
            cout << "empty list" << endl;
            return;
        }
        //if targetIndex is 0, delete the first node and return
        if (targetindex == 0) {
            delfirst();
            return;
        }

        //make a temporary pointer at the head so we can start at the top of list
        Node<T> *temp = head;
        int indexCounter = 0;

        //traverse the list to find the node before targetindex
        while (temp->next != NULL && indexCounter < targetindex - 1) {
            temp = temp->next;
            indexCounter++;
        }

        //if targetIndex is out of bounds
        if (temp->next == NULL) {
            cout << "index out of bounds" << endl;
            return;
        }

        //store the node to be deleted
        Node<T> *nodeToDelete = temp->next;

        //update next pointer to skip the deleted node
        temp->next = nodeToDelete->next;

        //delete the target node
        delete nodeToDelete;

        //decrement length
        length--;
    }


   void insert(int index, T *value) {
        //TODO:Write a function to insert a new node at a give index. Reuse the pre-written functions for edge cases. Account for missing index
        Node<T> *newNode = new Node<T>(value); //assinging a node to *value
        Node<T> *temp = head;
        int indexCounter = 0;

        //if list is empty, print error message
        if (head == NULL) {
            cout << "empty list" << endl;
            return;
        }
        //if targetIndex is 0, set head to newNode
        if (index == 0) {
            head = newNode;
        }

        //go through the list until we reach a node after our index
        while (temp->next != NULL && indexCounter < index - 1) //will land right before target index
        {
            temp = temp->next;
            indexCounter++;
        }

        if (temp->next == NULL)
        {
            cout << "index out of bounds" << endl;
        }

        newNode->next = temp->next; //the new node will point to what the previous node was pointing to. ex) previous being x->y, now newNode->y
        temp->next = newNode; //since the previous has nothing to point to, we make the previous node point to the new node.
        length++;

    }

   void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.
        Node<T>* prev = nullptr;
        Node<T>* curr = head;
        Node<T>* next = nullptr;

        while (curr != NULL)
        {
            next = curr->next; //saves next node
            curr->next = prev; //reverses the current NEXTS poitner
            prev = curr; //set prev to current node
            curr = next; //set curr to next node

        }

        head = prev; //simiply swapping heads/tail
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

};


#endif //CS210PA1_SPACEROUTE_H
