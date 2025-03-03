#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node* prev;

    Node(T d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }

    void print()
    {
        cout << data << " ";
    }
};

template <typename T>
class SpaceRoute
{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    //modified so when its called, it creates an empty double linked list.
    SpaceRoute()
    {
        head = nullptr; //both head and tail are null
        tail = nullptr;
    }


    //used to delete any existing linkedLists to avoid memory leaks
    ~SpaceRoute()
    {
        //loops through the doubleLinked list and deletes every element
        while (head)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addWaypointAtBeginning(T& data)
    {
        //create a new node specifically for parameter "data"
        Node<T>* newNode = new Node<T>(data);

        //if head is nullptr/empty
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        //
        else
        {
            newNode->next = head; //puts "newNode" to the left of the current head, making "newNode" the NEW head.
            head->prev = newNode; //since heads "prev" was nullptr, we make heads "prev" point to newNode.
            head = newNode; //finalize the newNode being head
        }
    }

    void addWaypointAtEnd(T& data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail; //puts "newNode" to the right of the curren tail, making "newNode" the NEW tail.
            tail->next = newNode; //since tails "next" was nullptr, we make tails "next" point to newNode
            tail = newNode; //finalize the newNode being tail
        }
    }

    void addWaypointAtIndex(int index, T& data)
    {
        //edge cases
        if (index < 0)
        {
            cout << "invalid bound" << endl;
            return;
        }
        if (index == 0)
        {
            //call already defined method
            addWaypointAtBeginning(data);
            return;
        }

        Node<T>* temp = head;
        int count = 0;
        //iterate til it hits index
        while (temp && count < index)
        {
            temp = temp->next;
            count++;
        }

        //if temp reaches the end of the list
        if (!temp)
        {
            addWaypointAtEnd(data);
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void removeWaypointAtBeginning()
    {
        if (!head)
        {
            cout << "empty" << endl;
            return;
        }

        Node<T>* temp = head; //we set the CURRENT head of the list, to temp because we will delete it later
        head = head->next;  //we set the NEW head to the element that is to the right of the old head.
        if (head) //if head still exists,
        {
            head->prev = nullptr; //we nullify the prev of the new head which was previously the old head.
        }
        else //if the list becomes empty,
        {
            tail = nullptr; //set tail as null aswell so the list is fully empty
        }
        delete temp; //remove temp
    }

    void removeWaypointAtEnd()
    {
        //edge case
        //if tail does not exists
        if (!tail)
        {
            return;
        }

        Node<T>* temp = tail; //set current tail to temp because it will be deleted at the end
        tail = tail->prev; //set the NEW tail to the element that is to the left of the old tail
        if (tail) //if tail still exists,
        {
            tail->next = nullptr; //nullify the "next" of the new tail which was previously the old tail.
        }
        else
        {
            head = nullptr; //sets head to null so the whole list is empty.
        }
        delete temp;
    }

    void removeWaypointAtIndex(int index)
    {
        //edge case if list is empty or negative index (impossible)
        if (!head || index < 0)
        {
            cout << "invalid index" << endl;
            return;
        }


        if (index == 0)
        {
            removeWaypointAtBeginning();
            return;
        }

        Node<T>* current = head;
        int count = 0;
        while (current && count < index)
        {
            current = current->next;
            count++;
        }

        //if "current" is null (meaning its in a invalid bound), it will automatically return
        if (!current)
        {
            return;
        }

        if (current == tail)
        {
            removeWaypointAtEnd();
            return;
        }

        //making sure we delete the node and maintain the list
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    void traverseForward()
    {
        Node<T>* current = head;
        //simply traverse through the list and print
        while (current)
        {
            current->print();
            current = current->next;
        }
        cout << endl;
    }

    void traverseBackward()
    {
        Node<T>* current = tail;
        //traverse from the tail and back
        while (current)
        {
            current->print();
            current = current->prev;
        }
        cout << endl;
    }

    Node<T>* getWaypoint(int index)
    {
        if (index < 0)
        {
            cout << "invalid index" << endl;
            return nullptr;
        }

        Node<T>* current = head;
        int count = 0;
        while (current && count < index)
        {
            current = current->next;
            count++;
        }
        return current;
    }

    void setWaypoint(int index, T& data)
    {
        Node<T>* node = getWaypoint(index);
        if (node)
        {
            node->data = data;
        }
    }

    void print()
    {
        Node<T>* current = head;
        while (current)
        {
            current->print();
            current = current->next;
        }
        cout << endl;
    }
};
