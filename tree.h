#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <string>

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

// https://stackoverflow.com/questions/2675756/efficient-array-storage-for-binary-tree could be interesting.
// for now store traversals in the file.
// void write_tree(std::istream &s) {
    
// }


// write traversals to the stream as {character}.{weight}|{character}.{weight}
void write_preorder(Node* n, std::ostream &s);

void write_inorder(Node* n, std::ostream &s);

void write_node(Node* n, std::ostream &s);

void write_traversals(Node* n, std::ostream &s);

std::vector<Node> read_traversal(std::istream &s);

std::vector<Node> read_traversal_data(std::istream &s);

Node* read_tree(std::istream &s);

#endif