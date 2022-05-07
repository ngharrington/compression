#ifndef TREE_H
#define TREE_H

class Node {
    private:
        char data;
        unsigned int weight;
        Node *left;
        Node *right;

    public:
        Node(char d, unsigned int w);
        unsigned int GetWeight();

};


#endif