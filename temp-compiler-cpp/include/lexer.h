#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "token.h"

struct LEXER_T {
    std::string src;
    char current_char;
    size_t src_size;
};

LEXER_T* lexer_init(std::string data);
TOKEN_T* lexer_next(LEXER_T* lexer);

#endif
