#ifndef TREE_H
#define TREE_H

class Node {
    private:
        char data;
        int weight;
        Node *left;
        Node *right;

    public:
        Node(char d, int w);
        int GetWeight();

};


#endif