// huffman coding on streams

#include "tree.h"
#include "huffman.h"



struct Weight_compare weight_compare;

Forest initialize_forest(std::vector<unsigned int> freq) {
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

