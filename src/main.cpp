#include <iostream>
#include <fstream>
#include "Lexer.hpp"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 1;
    }
    Lexer lexer(argv[1]);
    lexer.tokenOutput(argv[2]);
    return 0;
}