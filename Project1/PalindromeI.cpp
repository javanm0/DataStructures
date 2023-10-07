// PalindromeI implementation file
// Javan Miler

#include "PalindromeI.hpp"

// Header for implementation of stack class
class Stack
{
private:
    class Node
    {
    public:
        char data;
        Node* next;
    };
    Node *top;
public:
    Stack();
    ~Stack();
    void push(char);
    char pop();
    bool isEmpty() const;
};

// Header for implementation of queue class
class Queue
{
private:
    class Node
    {
    public:
        char data;
        Node* next;
    };
    Node *front;
    Node *rear;
public:
    Queue();
    ~Queue();
    void enqueue(char);
    char dequeue();
    bool isEmpty() const;
};


int PalindromeI::test_string(const std::string& s)
{
    Stack stack;
    Queue queue;

    // String with one character or less is a palindrome
    if (s.length() <= 1)
    {
        return -1;
    }

    // Converts string to lowercase
    std::string lowerS = s;
    for (int i = 0; i < lowerS.length(); i++)
    {
        lowerS[i] = tolower(lowerS[i]);
    }

    // Push all letters in string to stack and enqueue to queue
    for (int i = 0; i < s.length(); i++)
    {
        stack.push(s[i]);
        queue.enqueue(s[i]);
    }

    // Pop and dequeue all letters from stack and queue to compare
    while (stack.isEmpty() == false && queue.isEmpty() == false)
    {
        if (stack.pop() != queue.dequeue())
        {
            return 1;
        }
    }

    return -1; // String is a palindrome
}

// Stack implementation functions

// Stack constructor
Stack::Stack()
{
    top = nullptr;
}

// Stack destructor
Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

// Push function
void Stack::push(char c)
{
    Node *newNode = new Node;
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

// Pop function
char Stack::pop()
{
    char c = top->data;
    Node *temp = top->next;
    delete top;
    top = temp;
    return c;
}

// isEmpty function
bool Stack::isEmpty() const
{
    return top == nullptr;
}

// Queue implementation functions

// Queue constructor
Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

// Queue destructor
Queue::~Queue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

// Enqueue function
void Queue::enqueue(char c)
{
    Node *newNode = new Node;
    newNode->data = c;
    newNode->next = nullptr;
    
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue function
char Queue::dequeue()
{
    Node *tempPtr = nullptr;

    if (isEmpty())
    {
        throw "The queue is empty";
    }
    else
    {
        char c = front->data;
        tempPtr = front;
        front = front->next;
        delete tempPtr;
        return c;
    }
}

// isEmpty function
bool Queue::isEmpty() const
{
    if (front == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}