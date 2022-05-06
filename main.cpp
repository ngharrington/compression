#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

std::vector<int> getFrequencies(std::istream &in) {
    // we only support ascii so there are at most 128 codes.
    std::vector<int> freq(128);
    char current;
    while (in.get(current)) {
        freq[current]++;
    }
    
    return freq;
}

int main() {
    std::istringstream data("hello there");
    std::istream x(data.rdbuf());
    std::vector<int> freq = getFrequencies(x);
    for (int i = 0; i < freq.size(); ++i) {
        std::cout << i << " " << freq[i] << std::endl;
    }
}