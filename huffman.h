#include <queue>
#include <iostream>
#include <queue>
#include <iostream>
#include <vector>


// compare weights of nodes in the code tree.
struct Weight_compare {
    bool operator()(Node *n1, Node *n2) {
        return n1->GetWeight() < n2->GetWeight();
    }
};

// in constructing the code tree we use a forest (priority queue) of trees
typedef std::priority_queue<Node*, std::vector<Node *>, Weight_compare> Forest;

// Vector for holding character frequencies.
typedef std::vector<unsigned int> Freq_v;


Forest initialize_forest(Freq_v freq);

Freq_v compute_freq(std::istream &in);

void print_freq(Freq_v freq);

Node* compute_huffman_tree(Freq_v freq);

void print_tree(Node* node);
