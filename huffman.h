#include <queue>


// compare weights of nodes in the code tree.
struct weight_compare {
    bool operator()(Node *n1, Node *n2) {
        return n1->GetWeight() < n2->GetWeight();
    }
};

// in constructing the code tree we use a forest (priority queue) of trees
typedef std::priority_queue<Node*, std::vector<Node *>, weight_compare> Forest;


Forest initialize_forest(std::vector<unsigned int> freq);