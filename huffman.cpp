// huffman coding on streams

#include "tree.h"
#include "huffman.h"



struct Weight_compare weight_compare;

Forest initialize_forest(Freq_v freq) {
    Forest q = Forest();
    for (unsigned int i = 0; i < freq.size(); ++i) {
        if ( freq[i] > 0 ) {
            // initialize a node where the data is the ascii character associated with the array index 
            // and the weight is the frequency of that character.
            Node *n = new Node(char(i), freq[i]);
            q.push(n);
        }
    }
    return q;
}


std::vector<unsigned int> compute_freq(std::istream &in) {
    // we only support ascii so there are at most 128 codes.
    std::vector<unsigned int> freq(128);
    char current;
    while (in.get(current)) {
        freq[current]++;
    }
    in.clear();
    in.seekg(0, std::ios::beg);
    return freq;
}

void print_freq(Freq_v freq) {
    for (unsigned int i = 0; i < freq.size(); ++i) {
        std::cout << i << " " << freq[i] << std::endl;
    }
}

void _combine_tree_step(Forest *f) {
    Node* n1;
    Node* n2;
    n1 = f->top();
    f->pop();
    n2 = f->top();
    f->pop();
    int new_weight = n1->GetWeight() + n2->GetWeight();
    Node *nnode = new Node(new_weight, n1, n2);
    f->push(nnode);
}

void print_tree(const std::string& prefix, Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->GetChar() << "-" << node->GetWeight() << std::endl;

        // enter the next tree level - left and right branch
        print_tree( prefix + (isLeft ? "│   " : "    "), node->GetLeft(), true);
        print_tree( prefix + (isLeft ? "│   " : "    "), node->GetRight(), false);
    }
}

void print_tree(Node* node)
{
    print_tree("", node, false);    
}



Node* compute_huffman_tree(Freq_v freq) {
    Forest f = initialize_forest(freq);

    while (f.size() > 1) {
        _combine_tree_step(&f);
    }
    return f.top();
}
