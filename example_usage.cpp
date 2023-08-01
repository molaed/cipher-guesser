#include <iostream>
#include <string>
#include "caesar.hpp"

int main() {
    std::string src, dest;

    int option = 0, shift = 0;
    std::cout << "Would you like to encode (1) or decode (0)? ";
    std::cin >> option;

    std::cout << "Enter source file name: ";
    std::cin >> src;
    std::cout << "Enter target file name: ";
    std::cin >> dest;
    std::cout << "Enter the shift amount: ";
    std::cin >> shift;

    int lines_read = 0;

    if (option) {
        lines_read = arya::encode_to_file(dest, src, shift);
    } else {
        lines_read = arya::decode_to_file(dest, src, shift);
    }

    std::cout << "Read " << lines_read << " lines" << std::endl;

    return 0;
}
