#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList()
{
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    dummyHead -> next = dummyTail;
    dummyTail -> prev = dummyHead;
}

void IntList::push_front(int value)
{
    IntNode *tmpNode = new IntNode(value);
    tmpNode -> prev = dummyHead;
    tmpNode -> next = dummyHead -> next;
    dummyHead -> next -> prev = tmpNode;
    dummyHead ->next = tmpNode;
}

void IntList::pop_front()
{
    if(this->empty())
        return;
    IntNode *tmpNode = dummyHead -> next;
    dummyHead -> next = tmpNode -> next;
    tmpNode -> next -> prev = dummyHead;
    delete tmpNode;
}

void IntList::push_back(int value)
{
    IntNode *tmpNode = new IntNode(value);
    tmpNode -> prev = dummyTail -> prev;
    tmpNode -> next = dummyTail;
    dummyTail -> prev -> next = tmpNode;
    dummyTail -> prev = tmpNode;
}

void IntList::pop_back()
{
    if(this->empty())
        return;
    IntNode *tmpNode = dummyTail -> prev;
    dummyTail -> prev = tmpNode -> prev;
    tmpNode -> prev -> next = dummyTail;
    delete tmpNode;
}

bool IntList::empty() const
{
    return dummyHead -> next == dummyTail;
}

std::ostream & operator<<(ostream &out, const IntList &rhs)
{
    IntNode *tmpNode = rhs.dummyHead -> next;
    bool flag = 0;
    while(tmpNode != rhs.dummyTail)
    {
        if(flag)
            out << ' ';
        out << tmpNode -> data;
        flag = 1;
        tmpNode = tmpNode -> next;
    }
    return out;
}

void IntList::printReverse() const
{
    IntNode *tmpNode = dummyTail -> prev;
    bool flag = 0;
    while(tmpNode != dummyHead)
    {
        if(flag)
            cout << ' ';
        cout << tmpNode -> data;
        flag = 1;
        tmpNode = tmpNode -> prev;
    }
}
