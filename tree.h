#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>

class Node {
    private:
        char data;
        unsigned int weight;
        Node *left;
        Node *right;

    public:
        Node(char d, unsigned int w);
        Node(unsigned int w, Node *l, Node *r);
        unsigned int GetWeight();
        Node* GetLeft();
        Node* GetRight();
        char GetChar();
};

// https://stackoverflow.com/questions/2675756/efficient-array-storage-for-binary-tree
char* serialize_node(Node* n) {
    // we have the character of the node, the weight, a 
}

#endif