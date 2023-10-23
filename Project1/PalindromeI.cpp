// PalindromeI implementation file
// Javan Miler
// jlm451@uakron.edu

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
template <class T>
class Queue
{
private:
    T *queueArray; // Points to the queue array
    int queueSize; // Size of array
    int front; // Points to front
    int rear; // Points to rear
    int numItems; // Number of elements in the queue
public:
    Queue(int);
    ~Queue();
    void enqueue(char);
    char dequeue();
    bool isEmpty() const;
};

int PalindromeI::test_string(const std::string& s)
{
    int lengthString = s.length();
    Stack stack;
    Queue<char> queue(lengthString);
    int matches = 0;

    // String with one character or less is a palindrome so return now
    if (s.length() <= 1)
    {
        return -1;
    }

    // Checks if character is alphabetical and converts to lowercase
    // Push all letters in string to stack and enqueue to queue
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            stack.push(tolower(s[i]));
            queue.enqueue(tolower(s[i]));
        }
    }

    // Pop and dequeue all letters from stack and queue to compare
    while (stack.isEmpty() == false && queue.isEmpty() == false)
    {
        if (stack.pop() != queue.dequeue())
        {
            stack.~Stack(); // Call destructor for stack object since the memory is dynamically allocated
            return matches;
        }
        matches++; // Counts the number of matches
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
    if (isEmpty())
    {
        throw "The stack is empty";
    }
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
template <class T>
Queue<T>::Queue(int size)
{
    queueArray = new T[size]; // Allocates memory for array
    queueSize = size;
    front = 0;
    rear = 0;
    numItems = 0;
}

// Queue destructor
template <class T>
Queue<T>::~Queue()
{
    if (numItems > 0)
    {
        delete [] queueArray;
    }
}

// Enqueue function
template <class T>
void Queue<T>::enqueue(char c)
{
    if (numItems < queueSize)
    {
        queueArray[rear] = c; // Adds item to rear
        rear = (rear + 1) % queueSize;
        numItems++;
    }
    else
    {
        throw "The queue is full";
    }
}

// Dequeue function
template <class T>
char Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw "The queue is empty";
    }
    else
    {
        T item = queueArray [front];
        front = (front + 1) % queueSize;
        numItems--;
        return item;
    }
}

// isEmpty function
template <class T>
bool Queue<T>::isEmpty() const
{
    return numItems == 0;
}