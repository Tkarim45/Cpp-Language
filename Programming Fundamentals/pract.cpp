#include <iostream>
using namespace std;

template<class type>
class Node
{
public:
    Node();
    Node(type val, Node<type>*nptr = nullptr)
    {
        data = val;
        next = nptr;
    }
    template<class type>
    friend class List;

private:
    type data;
    Node<type> * next;
};


template<class type>
class List
{

private:

    Node<type> * head;
    Node<type> * tail;

public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtStart(type val)
    {
        head = new Node<type>(val, head);
        if (tail == nullptr)
            tail = head;
    }
    void insertAtEnd(type val)
    {
        if (tail != nullptr)
        {
            tail->next = new Node<type>(val);
            tail = tail->next;
        }
        else
            head = tail = new Node<type>(val);
    }

    bool search(type val )
    {
        Node<type> * tmp = head;
        while (tmp != nullptr && tmp->data != val)
        {
            if (tmp->data == val)
            {
                return true;
            }
            else
            {
                return false;
            }
            tmp = tmp->next;
        }
    }
    void print()
    {
        Node<type> * tmp;
        for (tmp = head; tmp != nullptr; tmp = tmp->next)
            cout << tmp->data << " ";
        cout << endl;
    }
    bool isEmpty()
    {
        if (head == 0)
        {
            return true;
        }
    }

    void deleteAll(type val)
    {

        Node<type> * temp = head;
        Node<type> * deleter;
        Node<type> * T;

        while (temp->next != nullptr)
        {
            T= temp->next;
            if (T->data== val)
            {
                deleter = temp->next;
                temp->next= deleter->next;
                delete deleter;
                deleter = nullptr;
            }
            temp= temp->next;
        }
    }
    void DeleteAtStart()
    {

        if (head != nullptr)
        {
            Node<type> * tmp = head;
            if (head == tail)
            {
                head = tail = nullptr;
            }
            else
                head = head->next;
            delete tmp;
        }
    }

    ~List()
    {
        Node<type> * temp = head;
        while (head != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        tail = nullptr;
    }

    void insertBefore(type t , type t2)
    {
        type n=t;
        type n2= t2;
        Node<type>* temp = head;
        Node<type>* temp1 = new Node<type>(n, nullptr);
        while(temp->next!=nullptr)
        {
            if(temp->next->data==n2)
            {
                temp1->next = temp->next;
                temp->next = temp1;
                temp = temp->next->next;
            }
            else
                temp = temp->next;
        }

    }
};

int main()
{
    List<int> myList;
    myList.insertAtStart(2);
    myList.insertAtStart(6);
    myList.insertAtStart(7);
    myList.insertAtEnd(9);
    myList.insertAtEnd(7);
    myList.insertAtEnd(8);
    myList.insertAtStart(9);
    myList.print();
    myList.deleteAll(7);
    myList.print();
    myList.insertBefore(10, 6);
    myList.print();
    cout << "searching for 10 :";
    cout << ((myList.search(10)) ? "Found " : "Not Found") << endl;
    cout << "searching for 11 :";
    cout << ((myList.search(11)) ? "Found " : "Not Found") << endl;
    myList.DeleteAtStart();
    myList.print();
    return 0;
}