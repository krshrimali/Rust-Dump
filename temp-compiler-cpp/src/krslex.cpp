#include "include/krslex.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void krslex_compile(std::string data) {
    std::cout << data << std::endl;
    while(lexer_read(data)) {
        continue;
    }
}

void krslex_compile_filename(std::string filename) {
    std::ifstream file(filename);
    // TODO: is this slow?
    std::stringstream data;
    data << file.rdbuf();
    krslex_compile(data.str());
}
