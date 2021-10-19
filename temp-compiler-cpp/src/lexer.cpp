#include <string>
#include <iostream>

#include "lexer.h"
#include "token.h"

LEXER_T* lexer_init(std::string src) {
    // Initalization of the struct object
    LEXER_T* lexer = {};
    lexer->src = src;
    lexer->current_char = src[0];
    lexer->src_size = src.length();

    return lexer;
}

TOKEN_T* lexer_current(LEXER_T* lexer, int id) {
    TOKEN_T* tok = init_token(lexer->current_char + "\0", id);
    return tok;
}

TOKEN_T* lexer_next(LEXER_T* lexer) {
    std::cout << lexer->current_char << std::endl;
    while (lexer->current_char != '\0') {
        // lexer_skip_whitespaces(lexer);
        switch(lexer->current_char) {
            case '(': return lexer_current(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_LPAREN));
            default:
                break;
        }
    }

    return init_token("\0", static_cast<int>(TOKEN_T::TYPE::TOKEN_EOF));
}
