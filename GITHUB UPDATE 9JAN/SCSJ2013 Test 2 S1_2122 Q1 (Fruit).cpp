// Program 1

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

void List::task1(string n, float p)
{
	FruitNode *node = new FruitNode(n, p);
	if (headNode == NULL)
	{
		headNode = node;
		headNode->next = node;
	}
	else
	{
		FruitNode *temp = headNode;
		while (temp->next != headNode)
		{
			temp = temp->next;
		}
		node->next = headNode;
		temp->next = node;
		headNode = node;
	}
}

void List::task2()
{
	FruitNode *temp = headNode;
	cout << "Fruit List\n";
	temp->getFruitInfo();
	temp = temp->next;
	while (temp != headNode)
	{
		cout << " >> ";
		temp->getFruitInfo();
		temp = temp->next;
	};
	cout << endl
		 << endl;
}

void List::task3(int num, string n, float p)
{
	FruitNode *node = new FruitNode(n, p);
	FruitNode *temp = headNode;
	int number = 1;
	if (headNode == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		while (temp->next != headNode)
		{
			number++;
			if (number == num)
			{
				node->next = temp->next;
				temp->next = node;
			}
			temp = temp->next;
		}
	}
}

void List::task4()
{
	FruitNode *temp = headNode;
	while (temp->next->next != headNode)
	{
		temp = temp->next;
	}
	FruitNode *lastNode = temp->next;
	temp->next = headNode;
	delete lastNode;
}

int main()
{
	List fruitList;
	// Incomplete main function definition
	fruitList.task1("Kiwi", 21.89);
	fruitList.task2();
	fruitList.task1("Apple", 11.95);
	fruitList.task2();
	fruitList.task1("Orange", 16.50);
	fruitList.task2();
	fruitList.task3(2, "Grape", 19.95);
	fruitList.task2();
	fruitList.task4();
	fruitList.task2();
	fruitList.task4();
	fruitList.task2();
	return 0;
}
