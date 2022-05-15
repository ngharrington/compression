#include "tree.h"
#include <vector>
#include <queue>
#include <iostream>

Node::Node(char d, unsigned int w) {
    data = d;
    weight = w;
}

Node::Node(unsigned int w, Node *l, Node *r) {
    weight = w;
    left = l;
    right = r;
}

Node* Node::GetLeft() {
    return left;
}

Node* Node::GetRight() {
    return right;
}

char Node::GetChar() {
    return data;
}

unsigned int Node::GetWeight() {
    return weight;
}
