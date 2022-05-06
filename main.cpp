#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>


std::vector<int> computeFrequencies(std::istream &in) {
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

void compressFile(std::istream &in, std::ostream &out) {
    char current[1];
    while (in.read(current, sizeof(current))) {
        out.write(reinterpret_cast<char *>(&current), sizeof(current));
    }
}

void printFrequencies(std::vector<int> freq) {
    for (int i = 0; i < freq.size(); ++i) {
        std::cout << i << " " << freq[i] << std::endl;
    }
}

int main() {
    std::fstream data("./data.txt", std::ios::in | std::ios::binary);
    std::ofstream output("./out.txt", std::ios::out | std::ios::binary);
    // std::vector<int> freq = computeFrequencies(data);
    // printFrequencies(freq);
    compressFile(data, output);
    data.close();
    output.close();
}

