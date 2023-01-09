#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class PhoneNode
{
private:
    string model;
    float price;

public:
    PhoneNode *next;
    PhoneNode(string m, float p)
    {
        model = m;
        price = p;
    }
    void getPhoneInfo()
    {
        cout << model << ": RM" << price;
    }
};

class List
{
private:
    PhoneNode *firstNode;

public:
    List()
    {
        firstNode = NULL;
    }
    void task1();
    void task2(PhoneNode *);
    void task3(int);
    void task4();
};

void List::task1()
{
}

void List::task2(PhoneNode *node)
{
    if (firstNode == NULL)
    {
        node->next = node;
        firstNode = node;
    }
    else
    {
        PhoneNode *tempNode = firstNode;
        while (tempNode->next != firstNode)
        {
            tempNode = tempNode->next;
        }
        
    }
}

int main()
{
    List phoneList;
    PhoneNode *p1 = new PhoneNode("iPhone 13", 3899);
    PhoneNode *p1 = new PhoneNode("Xiaomi", 1699);
    PhoneNode *p1 = new PhoneNode("Vivo X70", 2499);
    PhoneNode *p1 = new PhoneNode("Galazy Z Flip3", 3999);
}