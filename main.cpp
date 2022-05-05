#include <fstream>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>

void extract_data(std::string filepath, std::vector<char>* v) {
    std::ifstream input("./data.txt", std::ios::binary);
    v->assign(
        (std::istreambuf_iterator<char>(input)),
         (std::istreambuf_iterator<char>())
    );
    input.close();
}

int main() {

    std::vector<char> bytes;
    extract_data("./data.txt", &bytes);
}