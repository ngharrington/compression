#include "tree.h"
#include <vector>
#include <queue>
#include <iostream>

Node::Node(char d, unsigned int w) {
    data = d;
    weight = w;
}

unsigned int Node::GetWeight() {
    return weight;
}
