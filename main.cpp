#include "tree.h"
#include "huffman.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <functional>
#include <queue>


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

void compress(std::istream &in, std::ostream &out) {
    char current[1];
    while (in.read(current, sizeof(current))) {
        out.write(reinterpret_cast<char *>(&current), sizeof(current));
    }
}

void print_freq(std::vector<unsigned int> freq) {
    for (unsigned int i = 0; i < freq.size(); ++i) {
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


// typedef std::priority_queue<Node*, std::vector<Node *>, weight_compare> Forest;

void print_queue(Forest q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        std::cout << q.top()->GetWeight() << ' ';
        q.pop();
    }
    std::cout << '\n';
}
 
int main() {
    std::ifstream f("./data.txt");
    std::vector<unsigned int> freq = compute_freq(f);
    Forest forest = initialize_forest(freq);
    print_freq(freq);
    return 0;
}