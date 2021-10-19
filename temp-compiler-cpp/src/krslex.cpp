#include "krslex.h"
#include "lexer.h"
#include "token.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void krslex_compile(std::string data) {
    LEXER_T* lexer = lexer_init(data);
    TOKEN_T* tok = lexer_next(lexer);

    while(tok->type != TOKEN_T::TYPE::TOKEN_EOF) {
        // std::cout << tok->type;
        std::cout << "Hi\n";
    } 

    // std::cout << TOKEN_T::TYPE::TOKEN_EOF;
}

void krslex_compile_filename(std::string filename) {
    std::ifstream file(filename);
    // TODO: is this slow?
    std::stringstream data;
    data << file.rdbuf();
    krslex_compile(data.str());
}
