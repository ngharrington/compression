#include "tree.h"
#include <vector>
#include <queue>
#include <iostream>

Node::Node(char d, int w) {
    data = d;
    weight = w;
}

int Node::GetWeight() {
    return weight;
}
