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

void write_node(Node* n, std::ostream &s) {
    s << n->GetChar() << "." << n->GetWeight() << " "; // NB: Hey this is a legit char, we probably shouldn't encode data with it
}


// write traversals to the stream as {character}.{weight} {character}.{weight}
void write_preorder(Node* n, std::ostream &s) {
    write_node(n, s);
    if (n->GetLeft()) {
        write_preorder(n->GetLeft(), s);
    }
    if (n->GetRight()) {
        write_preorder(n->GetRight(), s);
    }
}

void write_inorder(Node* n, std::ostream &s) {
    if (n->GetLeft()) {
        write_inorder(n->GetLeft(), s);
    }
    write_node(n, s);
    if (n->GetRight()) {
        write_inorder(n->GetRight(), s);
    }
}

void write_traversals(Node* n, std::ostream &s) {
    write_preorder(n, s);
    s << '\0';
    write_inorder(n, s);
    s << '\0';
    s << '\0';
}


Node read_node(std::istream &s) {
    char c;
    int w;
    // read in the character that the node represents
    // if it's not a . character (e.g. the node has a non null character associated with it) read the character
    if (s.peek() == '.') {
        s >> c;
    }

    // skip the . character as it delimits where the frequency data in the stream starts
    s.ignore();
    
    // now read data into a new stream until you hit the whitespace character, indicating the end
    // of this nodes data.
    s >> w;

    Node n = Node(c, w);
    return n;
}

std::vector<Node> read_traversal(std::istream &s) {
    std::vector<Node> v;
    // the '\0' character indicates the end of traversal data
    while (s.peek() != '\0') {
        Node n = read_node(s);
        v.push_back(n);
    }
    return v;
}

Node* read_tree(std::istream &s) {
    Node* n;
    
    std::vector<Node> trav_pre, trav_in;
    trav_pre = read_traversal(s);
    trav_in = read_traversal(s);
    s.get();
    return n;
}
