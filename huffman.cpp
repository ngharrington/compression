// huffman coding on streams

#include "tree.h"
#include "huffman.h"

#include <queue>


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

