#include <iostream>
#include <string>

#include "include/krslex.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Please pass the filename as the arg\n";
        return 1;
    }
    krslex_compile_filename(argv[1]);
}
