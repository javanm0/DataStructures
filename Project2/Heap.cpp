// Javan Miller - jlm451

#include "Heap.hpp"

void Heap::enqueue(HNode* element)
{
    // Checks to see if the tree has enough space to insert another node
    if (++position >= tree.size())
    {
        tree.resize(position * 2); // Doubles the size of the tree
    }

    tree[position] = element; // Adds element to end of tree

    fix_up(position); // Recursively heapify

    count++;
}

void Heap::fix_up(const int& treeIndex)
{
    int parentIndex = treeIndex / 2; // Parent
    
    // Swap if child is smaller than parent    
    if (parentIndex > 0 && *tree[treeIndex] < *tree[parentIndex])
    {
        HNode* temp = tree[treeIndex]; // Temporarily stores child
        tree[treeIndex] = tree[parentIndex]; // Sets child to parent
        tree[parentIndex] = temp; // Sets parent to child

        fix_up(parentIndex); // Recursively heapify
    }
}

HNode* Heap::dequeue()
{
    HNode* root = tree[1]; // Stores root

    tree[1] = tree[position--]; // Moves the last node to the root

    fix_down(1); // Recursively heapify

    count--;

    return root; // Returns root node
}

void Heap::fix_down(const int& treeIndex)
{
    int leftChild = treeIndex * 2; // Left child
    int rightChild = leftChild + 1; // Right child
    int parentIndex = treeIndex; // Parent

    // Returns if children are out of bounds
    if (leftChild >= tree.size() || rightChild >= tree.size() || parentIndex >= tree.size())
    {
        return;
    }

    // Checks to see if left child is smaller than parent
    if (leftChild <= position && *tree[leftChild] < *tree[parentIndex])
    {
        parentIndex = leftChild;
    }

    // Checks to see if right child is smaller than parent
    if (rightChild <= position && *tree[rightChild] < *tree[parentIndex])
    {
        parentIndex = rightChild;
    }

    // Swaps parent with child if child is smaller
    if (parentIndex != treeIndex)
    {
        HNode* temp = tree[treeIndex];
        tree[treeIndex] = tree[parentIndex];
        tree[parentIndex] = temp;

        fix_down(parentIndex); // Recursively heapify
    }
}

void Heap::clear()
{
    // Steps through the tree and deletes all nodes
    for (int index = 1; index <= position; index++)
    {
        delete tree[index]; // Deletes node
        tree[index] = nullptr; // Sets pointer to null
    }

    // Resets position and count
    position = 0;
    count = 0;

    tree.resize(2); // Sets tree back to original size
}