////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ2013- item Structures and Algorithms
// Semester 1, 2018/2019
// Lab Test  - Question 1 Linked List (30 marks)
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Node
{
public:
    int item;
    Node *next;

    Node(int d = 0)
    {
        item = d;
        next = NULL;
    }
};

// To print the list of nodes from head to tail
void print(Node *head)
{
    Node *node = head;

    while (node)
    {
        cout << node->item << "\t";
        node = node->next;
    }
    cout << endl
         << endl;
}

int main()
{
    Node *head, *tail;

    head = tail = new Node(45);

    for (int n = 50; n <= 85; n += 5)
    {
        tail->next = new Node(n);
        tail = tail->next;
    }

    print(head);

    Node *node = new Node;

    //-------------------------------------------------
    // Task 1: Insert a new node (with the item = 111) at
    // the end of the list (3 marks)
    node->item = 111;
    tail->next = node;
    tail = node;

    print(head);

    //-------------------------------------------------
    // Task 2: Insert a new node (with the item = 222) between
    // node 65 and node 70 (7 marks)
    node = new Node;
    node->item = 222;
    Node *prevNode = head;
    for (int i = 0; i < 4; i++)
    {
        prevNode = prevNode->next;
    }
    Node *nextNode = prevNode->next;
    node->next = nextNode;
    prevNode->next = node;

    print(head);

    //-------------------------------------------------
    // Task 3: Delete the first node from the list (3 marks)
    Node *tempNode = head;
    head = head->next;
    delete tempNode;

    print(head);

    //-------------------------------------------------
    // Task 4: Swap the positions of the first and last nodes (9 marks)
    Node *tempHead = head;
    Node *prevTail = head;
    Node *tempTail = tail;

    while (prevTail->next != tail)
    {
        prevTail = prevTail->next;
    }
    prevTail->next = tempHead;
    tail->next = tempHead->next;
    tempHead->next = NULL;
    tail = tempHead;
    head = tempTail;

    print(head);

    //-------------------------------------------------
    // Task 5: Find a node in the list with the number that
    // you have entered (8 marks)

    int num;
    bool found = false;

    cout << "Enter a number that you want to find in the list: ";
    cin >> num;
    cout << endl;
    // Complete your Task 5 here
    node = head;
    if (node->item == num)
        found = true;
    while (node != tail)
    {
        node = node->next;
        if (node->item == num)
            found = true;
    }

    cout << num;
    if (found)
        cout << " is in the list" << endl;
    else
        cout << " is NOT in the list" << endl;

    system("PAUSE");
    return 0;
}
