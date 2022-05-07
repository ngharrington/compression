#include "tree.h"
#include "huffman.h"
#include <iostream>
#include <fstream>


void compress(std::istream &in, std::ostream &out) {
    char current[1];
    while (in.read(current, sizeof(current))) {
        out.write(reinterpret_cast<char *>(&current), sizeof(current));
    }
}

void print_freq(Freq_v freq) {
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


void print_queue(Forest q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        std::cout << q.top()->GetWeight() << ' ';
        q.pop();
    }
    std::cout << '\n';
}
 
int main() {
    std::ifstream f("./data.txt");
    Freq_v freq = compute_freq(f);
    print_freq(freq);
    Forest forest = initialize_forest(freq);
    // print_freq(freq);
    return 0;
}