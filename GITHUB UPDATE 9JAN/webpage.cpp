
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class nodeStack
{
public:
    string url;
    string title;
    nodeStack *next;
    nodeStack()
    {
        url = "";
        title = "";
        next = NULL;
    }
    nodeStack(string url, string title)
    {
        this->url = url;
        this->title = title;
    }
};

class stack
{
    nodeStack *top;

public:
    void createStack()
    {
        top == NULL;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    void push();
    void pop();
    void display();
    void search();
};

void stack::push()
{
    string newUrl, newTitle;
    nodeStack *node = new nodeStack;
    if (node == NULL)
    {
        cout << "Cannot allocate memory" << endl;
    }
    else
    {
        system("CLS");
        cout << "<<<<<< Insert Web Pages >>>>>>" << endl
             << endl;

        // Task 1 - write the code to insert new browsing history to the stack
        //  first, ask the user to enter the information of the url
        // and title of the browsing history
        // then insert the new browing item by using the information
        // entered
        cout << "Page URL: ";
        getline(cin, newUrl);
        cout << "Page Title: ";
        getline(cin, newTitle);

        node->url = newUrl;
        node->title = newTitle;

        node->next = top;
        top = node;
    }
}

void stack::pop()
{
    nodeStack *delNode;
    system("CLS");

    cout << "<<<<< Remove Web Browsing History >>>>>" << endl
         << endl;
    cout << "URL: " << top->url << endl;
    cout << "TItle: " << top->title << endl;
    cout << "<< Press any key to continue >>";

    cin.get();

    // task2 - write the code to remove the history from the stack
    // answer task 2 start here
    delNode = top;
    top = top->next;

    delete delNode;
    // task2 end
}

void stack::display()
{
    int num = 0;
    nodeStack *currNode = top;
    system("CLS");
    cout << "<<<<< Display Web Browsing History >>>>>" << endl << endl;
    // task 3
    cout << "[" << num + 1 << "]"
         << "Page URL: " << currNode->url << endl;
    cout << "Page Title: " << currNode->title << endl;
    num++;
    currNode = currNode->next;
    while (currNode->next != NULL)
    {
        cout << "[" << num + 1 << "]";
        cout << "Page URL: " << currNode->url << endl;
        cout << "Page Title: " << currNode->title << endl;
        num++;
        currNode = currNode->next;
    }
    
    system("PAUSE");
}

void stack::search()
{
    int choice;
    string input;
    string abc;
    nodeStack *currNode = top;
    system("CLS");
    cout << "<<< Searching browsing history >>> " << endl;
}

void dispMenu()
{
    system("CLS");
    cout << "WEAB PAGE BROWSING HISTORY" << endl
         << "\n\t1. Insert New Page"
         << "\n\t2. REmove page"
         << "\n\t3. Search Page"
         << "\n\t4. Display Page History"
         << "\n\t5. Exit" << endl;
}

int main()
{
    stack webBrowse;
    webBrowse.createStack();
    int choice;
    do
    {
        dispMenu();
        cout << "\nEnter your choice 1-5: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            webBrowse.push();
            break;
        case 2:
            webBrowse.pop();
            break;
        case 3:
            webBrowse.search();
            break;
        case 4:
            webBrowse.display();
    
            break;
        default:
            cout << "Thank you see you again" << endl;
            system("PAUSE");
            return 0;
        }
    } while ((choice > 0) && (choice < 5));
    return 0;
}
