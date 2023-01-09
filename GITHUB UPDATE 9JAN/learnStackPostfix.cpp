#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class nodeStack
{
public:
    char data;
    nodeStack *next;
};

class stack
{
    nodeStack *top;

public:
    // To initialize top
    void createStack()
    {
        top = NULL;
    }

    // To check either a stack is empty or not
    bool isEmpty()
    {
        return top == NULL;
    }

    // To get the item at the top of stack
    char stackTop()
    {
        if (top != NULL)
            return top->data;
    }

    void push(char);
    void pop();
};

// To insert a new item into a stack
void stack::push(char newItem)
{
    nodeStack *node = new nodeStack;

    node->data = newItem;
    node->next = top;
    top = node;
}

// To delete the item from a stack
void stack::pop()
{
    if (top != NULL)
        top = top->next;
}

// Check if a character is an operator
bool isOperator(char ch)
{
    if (ch == '/' || ch == '*' || ch == '-' || ch == '+')
        return true;
    else
        return false;
}

// Determine the precedence of the operator
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    default:
        return -1;
    }
}

int main()
{
    char ch;
    stack s;      // Stack
    string infix; // Infix expression
    cout << "\nEnter your infix: ";
    getline(cin, infix);
    string postfix = ""; // Postfix expression

    cout << "Convert infix to postfix" << endl;
    cout << "Infix: " << infix << endl;

    s.createStack();
    s.push('#');

    // Convert infix expression to postfix
    for (int i = 0; i < infix.length(); i++)
    {
        ch = infix[i];

        // If an operand is encountered, add it to postfix expression.
        if (isdigit(ch))
            postfix += ch;

        //-------------------------------------------------
        // Task 1: If a left parentheses is encountered, push
        // it into a stack. (2 marks)

        if (ch == '(')
            s.push(ch);

        //-------------------------------------------------
        // Task 2: If an operator is encountered, then
        //(1) Repeatedly pop from stack and add to postfix expression
        //    each operator on the top of stack which has the same
        //    precedence as or higher precedence than encountered operator.
        //(2) Add operator to stack. (8 marks)
        if (isOperator(ch))
        {
            while (!s.isEmpty() && (ch) <= precedence(s.stackTop()))
            {
                postfix += s.stackTop();
                s.pop();
            }
            s.push(ch);
        }

        //-------------------------------------------------
        // Task 3: If a right parentheses is encountered, then:
        //(1) Repeatedly pop from stack and add to postfix expression
        //    each operator on the top of stack until a left
        //    parentheses is encountered.
        //(2) Remove the left parentheses. (5 marks)
        if (ch == ')')
        {
            while (s.stackTop() != '(')
            {
                postfix += s.stackTop();
                s.pop();
            }
            s.pop();
        }
    }

    while (s.stackTop() != '#')
    {
        postfix += s.stackTop();
        s.pop();
    }

    cout << "\nPostfix: " << postfix << endl;

    int operand1, operand2, result;

    s.createStack();

    // Evaluate postfix expression
    for (int i = 0; i < postfix.length(); i++)
    {
        ch = postfix[i];

        // If operand is encountered, push it onto stack
        if (isdigit(ch))
            s.push(ch - '0');

        else
        {
            //-------------------------------------------------
            // Task 4: If an operator is encountered, then
            //(1) Pop the first two operands in stack
            //(2) Evaluate the encountered operator using both operands
            //(3) Push the result of the evaluation to stack. (10 marks)
            char op1, op2;
            op1 = s.stackTop();
            s.pop();
            op2 = s.stackTop();
            s.pop();
            switch(ch){
                case '+':
                s.push(op2 + op1);
                break;
                case '-':
                s.push(op2 - op1);
                break;
                case '/':
                s.push(op2 / op1);
                break;
                case '*':
                s.push(op2 * op1);
                break;
                default:
                cout<<"ERROR";
                break;
            }
            
        }
    }

    cout << "\nEvaluating postfix expression" << endl;
    cout << "Postfix expression: " << postfix << endl;
    cout << "Result = " << (int)s.stackTop() << endl;

    system("PAUSE");

    return 0;
}
