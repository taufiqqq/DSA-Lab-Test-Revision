#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class StudentNode //content & aliran
{
public:
    string name;
    float CPA;
    StudentNode *next, *prev;
    StudentNode(string n = NULL, float c = 0)
    {
        name = n;
        CPA = c;
        next = NULL;
        prev = NULL;
    }
};

class List //petunjuk start n habis . head dan tail
{
private:
    StudentNode *head;
    StudentNode *tail;

public:
    void task1(StudentNode *);
    void task2(StudentNode *);
    void task3();
    void task4();
    void task5(StudentNode *, int);
    void task5();
    void task6();
};

void List::task1(StudentNode *node) //LISA
{
    head = node;
    tail = node;
    node->prev = node;
    node->next = node;
}

void List::task2(StudentNode *node ) //SHAH
{
    node->next = head;
    node->prev = tail;
    tail->next = node;
    head->prev = node;
    tail = node;
}

void List::task3()
{
    StudentNode *currNode = head;
    cout << "Print forward:" << endl;

    do
    {
        cout << "[" << currNode->name << " " << currNode->CPA << "] ";
        currNode = currNode->next;
        if (currNode != head)
            cout << "-> ";
    } while (currNode != head);
    cout << endl;
    cout << endl;
}

void List::task4()
{
    StudentNode *newHead = head->next;
    newHead->prev = tail;
    tail->next = newHead;
    head->next = NULL;
    head->prev = NULL;
    head = newHead;
}

void List::task5(StudentNode *node, int position)
{
    StudentNode *prevNode = head;
    for (int i = 1; i < (position - 1); i++)
    {
        prevNode = prevNode->next;
    }
    StudentNode *nextNode = prevNode->next;
    node->prev = prevNode;
    prevNode->next = node;
    node->next = nextNode;
    nextNode->prev = node;
}

void List::task6()
{
    StudentNode *newTail = tail->prev;
    newTail->next = head;
    head->prev = newTail;
    tail->prev = NULL;
    tail->next = NULL;
    tail = newTail;
}

int main()
{
    List StudList;
    StudentNode *s1 = new StudentNode("Lisa", 3.56);
    StudentNode *s2 = new StudentNode("Shah", 3.75);
    StudentNode *s3 = new StudentNode("Amin", 3.67);
    StudentNode *s4 = new StudentNode("Iman", 3.85);
    StudentNode *s5 = new StudentNode("Afiq", 3.61);
    cout << fixed << setprecision(2) << left;
    StudList.task1(s1);
    StudList.task2(s2);
    StudList.task2(s3);
    StudList.task3();
    StudList.task4();
    StudList.task3();

    StudList.task5(s4, 2);
    StudList.task5(s5, 3);
    StudList.task3();

    StudList.task6();
    StudList.task3();

    system("PAUSE");
    return 0;
}

/*
CREATE A SORTED LINKED LIST
    int currIndex = 0;
    StudentNode *currNode = head;
    StudentNode *prevNode = NULL;
    while (currNode && node.CPA > currNode->CPA)
    {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    StudentNode *newNode = new StudentNode;
    newNode->CPA = node->CPA;
    if (currIndex == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        newNode->next = prevNode->next;
        preNode->next = newNode;
    }
    return newNode;
*/