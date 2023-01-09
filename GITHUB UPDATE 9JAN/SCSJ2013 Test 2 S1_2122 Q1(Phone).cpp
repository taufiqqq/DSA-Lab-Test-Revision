#include <iostream>
#include <iomanip>
using namespace std;

class PhoneNode{
	private:
		string model;
		float price;
	public:
		PhoneNode *next;
		PhoneNode(string m, float p){
			model=m;
			price=p;
		}
		void getPhoneInfo(){
			cout << model << ": RM" << price;
		}
};

class List{
	private:
		PhoneNode *firstNode;
	public:
		List(){
			firstNode=NULL;
		}
		void task1();
		void task2(PhoneNode *);
		void task3(int);
		void task4();
};

void List::task1(){
	PhoneNode *currNode=firstNode;
	if(firstNode==NULL){
		cout << "List is empty." << endl;
	}
	else{
		cout << "PhoneList\n";
		cout << fixed << setprecision(2);
		currNode->getPhoneInfo();
		currNode=currNode->next;
		while(currNode!=firstNode){
			cout << " -> ";
			currNode->getPhoneInfo();
			currNode=currNode->next;
		}
		cout << endl << endl;
	}
}

void List::task2(PhoneNode *p){
	PhoneNode *newNode=p;
	PhoneNode *currNode=firstNode;
	if(firstNode==NULL){
		firstNode=newNode;
		firstNode->next=newNode;
	}
	else{
		while(currNode->next!=firstNode){
			currNode=currNode->next;
		}
		currNode->next=newNode;
		newNode->next=firstNode;
	}
}

void List::task3(int n){
	PhoneNode *currNode=firstNode;
	int num=1;
	if(firstNode==NULL){
		cout << "List is empty." << endl;
	}
	else
	{
		while(currNode->next!=firstNode){
			PhoneNode *delNode=currNode->next;
			if(num==n-1){
				currNode->next=delNode->next;
				delete delNode;
				break;
			}
			currNode=currNode->next;
			num++;
		}
	}
}

void List::task4(){
	PhoneNode *currNode=firstNode;
	PhoneNode *delNode=firstNode;
	if(firstNode==NULL){
		cout << "List is empty." << endl;
	}
	else
	{
		while(currNode->next!=firstNode){
			currNode=currNode->next;
		}
		firstNode=delNode->next;
		currNode->next=firstNode;
		delete delNode;
	}
}


int main(){
	List phoneList;
	PhoneNode *p1=new PhoneNode("iPhone 13",3899);
	PhoneNode *p2=new PhoneNode("Xiaomi",1699);
	PhoneNode *p3=new PhoneNode("vivo X70",2499);
	PhoneNode *p4=new PhoneNode("Galaxy Z Flip3",3999);
	
	// Imcomplete main function definition
	phoneList.task2(p4);
	phoneList.task1();
	phoneList.task2(p2);
	phoneList.task1();
	phoneList.task2(p3);
	phoneList.task1();
	phoneList.task2(p1);
	phoneList.task1();
	phoneList.task3(3);
	phoneList.task1();
	phoneList.task4();
	phoneList.task1();
	phoneList.task4();
	phoneList.task1();
	
	return 0;
}
