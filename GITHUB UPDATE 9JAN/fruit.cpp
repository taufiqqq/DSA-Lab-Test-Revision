#include <iostream>
#include <iomanip>

using namespace std;

class FruitNode
{
private:
    string name;
    float price;

public:
    FruitNode *next;
    FruitNode(string n, float p)
    {
        name = n;
        price = p;
    }
    void getFruitInfo()
    {
        cout << name << " = RM" << price;
    }
};

class List
{
private:
    FruitNode *headNode;

public:
    List()
    {
        headNode = NULL;
    }
    void task1(string, float);
    void task2();
    void task3(int, string, float);
    void task4();
};

void List::task1(string s, float f)
{
    FruitNode *node = new FruitNode(s, f);
    if (headNode == NULL)
    {
        headNode = node;
        node->next = node;
    }
    else
    {
        node->next = headNode;
        FruitNode *tempNode = node;
        do
        {
            tempNode = tempNode->next;
        } while (tempNode->next != headNode);
        //node->next = headNode;
        headNode = node;
        tempNode->next = node;
    }
}

void List::task2()
{
    cout << "Fruit List" << endl;
    FruitNode *tempNode = headNode;
    do
    {
        tempNode->getFruitInfo();
        if (tempNode->next != headNode)
            cout << " >> ";
        tempNode = tempNode->next;     
    } while (tempNode != headNode);
    cout << endl;
    cout << endl;
}

void List::task3(int i, string s, float f)
{
    FruitNode *node = new FruitNode(s, f);
    FruitNode *prevNode = headNode;
    for (int j = 2; j < i; j++)
    {
        prevNode = prevNode->next;
    }
    FruitNode *nextNode = prevNode->next;
    prevNode->next = node;
    node->next = nextNode;
}

void List::task4()
{
    int position;
    FruitNode *node = headNode;
    while (node->next->next != headNode)
    {
        node = node->next;
    }
    node->next = headNode;
}

int main()
{
    List fruitList;

    fruitList.task1("Kiwi", 21.89);
    fruitList.task2();

    fruitList.task1("Apple", 11.95);
    fruitList.task2();

    fruitList.task1("Orange", 16.5);
    fruitList.task2();

    fruitList.task3(2, "Grape", 19.95);
    fruitList.task2();

    fruitList.task4();
    fruitList.task2();

    fruitList.task4();
    fruitList.task2();

    system("PAUSE");
}