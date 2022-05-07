#include "tree.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <functional>
#include <queue>


std::vector<int> compute_freq(std::istream &in) {
    // we only support ascii so there are at most 128 codes.
    std::vector<int> freq(128);
    char current;
    while (in.get(current)) {
        freq[current]++;
    }
    in.clear();
    in.seekg(0, std::ios::beg);
    return freq;
}

void compress(std::istream &in, std::ostream &out) {
    char current[1];
    while (in.read(current, sizeof(current))) {
        out.write(reinterpret_cast<char *>(&current), sizeof(current));
    }
}

void print_freq(std::vector<int> freq) {
    for (int i = 0; i < freq.size(); ++i) {
        std::cout << i << " " << freq[i] << std::endl;
    }
}

void program() {
    std::fstream data("./data.txt", std::ios::in | std::ios::binary);
    std::ofstream output("./out.txt", std::ios::out | std::ios::binary);
    // std::vector<int> freq = compute_freq(data);
    // print_freq(freq);
    compress(data, output);
    data.close();
    output.close();
}

struct weight_compare {
    bool operator()(Node *n1, Node *n2) {
        return n1->GetWeight() < n2->GetWeight();
    }
};


typedef std::priority_queue<Node*, std::vector<Node *>, weight_compare> Forest;

void print_queue(Forest q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        std::cout << q.top()->GetWeight() << ' ';
        q.pop();
    }
    std::cout << '\n';
}

Forest initialize_forest(std::vector<int> freq) {
    Forest q = Forest();
    for (int i = 0; i < freq.size(); ++i) {
        if ( freq[i] > 0 ) {
            // initialize a node where the data is the ascii character associated with the array index 
            // and the weight is the frequency of that character.
            Node *n = new Node(char(i), freq[i]);
            q.push(n);
            print_queue(q);
        }
    }
    return q;
}
 
int main() {
    std::ifstream f("./data.txt");
    std::vector<int> freq = compute_freq(f);
    Forest forest = initialize_forest(freq);
    return 0;
}