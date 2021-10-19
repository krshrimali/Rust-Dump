#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "token.h"

struct LEXER_T {
    std::string src;
    char current_char;
    int i;
    size_t src_size;
};

LEXER_T* lexer_init(std::string data);

TOKEN_T* lexer_next(LEXER_T* lexer);

void lexer_skip_whitespaces(LEXER_T* lexer);

void lexer_advance(LEXER_T* lexer);

TOKEN_T* lexer_advance_with(LEXER_T* lexer, TOKEN_T* token);

TOKEN_T* lexer_advance_parse_id(LEXER_T* lexer, int type);

TOKEN_T* lexer_advance_parse_number(LEXER_T* lexer, int type);

void lexer_advance_by(LEXER_T* lexer, int offset);

char lexer_peek(LEXER_T* lexer, int offset);

#endif
