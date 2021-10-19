#include <string>
#include <iostream>

#include "lexer.h"
#include "token.h"

LEXER_T* lexer_init(std::string src) {
    LEXER_T* lexer = new LEXER_T();
    lexer->src = src;
    lexer->i = 0;
    lexer->current_char = src[lexer->i];
    lexer->src_size = src.length();

    return lexer;
}

TOKEN_T* lexer_current(LEXER_T* lexer, int id) {
    TOKEN_T* tok = init_token(std::string(1, lexer->current_char), id);
    lexer_advance(lexer);
    return tok;
}

char lexer_peek(LEXER_T* lexer, int offset) {
    int index = lexer->i;
    if (index < lexer->src_size) {
        lexer_advance_by(lexer, offset);
        return lexer->src[index + offset];
    }
    lexer_advance_by(lexer, lexer->src_size - index);
    return lexer->src[lexer->src_size];
}

void lexer_advance_by(LEXER_T* lexer, int offset) {
    while (--offset >= 0) {
        lexer_advance(lexer);
    }
}

void lexer_advance(LEXER_T* lexer) {
    if (lexer->i < lexer->src_size && lexer->current_char != '\0') {
        lexer->i += 1;
        lexer->current_char = lexer->src[lexer->i];
    }
}

TOKEN_T* lexer_advance_with(LEXER_T* lexer, TOKEN_T* token) {
    lexer_advance(lexer);
    return token;
}

void lexer_skip_whitespaces(LEXER_T* lexer) {
    while (isspace(lexer->current_char)) {
        lexer_advance(lexer);
    }
}

TOKEN_T* lexer_advance_parse_id(LEXER_T* lexer, int type) {
    std::string value = "";
    while (isalpha(lexer->current_char)) {
        value.push_back(lexer->current_char);
        lexer_advance(lexer);
    }
    return init_token(value, type);
}

TOKEN_T* lexer_advance_parse_number(LEXER_T* lexer, int type) {
    std::string value = "";
    while (isdigit(lexer->current_char)) {
        value.push_back(lexer->current_char);
        lexer_advance(lexer);
    }
    return init_token(value, type);
}

TOKEN_T* lexer_next(LEXER_T* lexer) {
    while (lexer->current_char != '\0') {
        lexer_skip_whitespaces(lexer);

        if (isalpha(lexer->current_char)) {
            return lexer_advance_parse_id(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_ID));
        }

        if (isdigit(lexer->current_char)) {
            return lexer_advance_parse_number(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_INT));
        }

        /* std::cout << "current char: " << std::string(1, lexer->current_char) << ", " << lexer->i << std::endl; */
        switch(lexer->current_char) {
            case '(': return lexer_current(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_LPAREN));
            case ')': return lexer_current(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_RPAREN));
            case '=': {
                    if (lexer_peek(lexer, 1) == '>') return lexer_advance_with(lexer, init_token("=>", static_cast<int>(TOKEN_T::TYPE::TOKEN_RIGHT_ARROW)));
                    else if (lexer_peek(lexer, 1) == '=') return lexer_advance_with(lexer, init_token("=", static_cast<int>(TOKEN_T::TYPE::TOKEN_EQUALS)));
            } break;
            case '{': return lexer_current(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_LBRACE));
            case '}': return lexer_current(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_RBRACE));
            case ':': return lexer_current(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_COLON));
            case ',': return lexer_current(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_COMMA));
            case '<': return lexer_current(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_LT));
            case '>': return lexer_current(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_GT));
            case ';': return lexer_current(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_SEMI));
            case '+': return lexer_current(lexer, static_cast<int>(TOKEN_T::TYPE::TOKEN_ADD));
            default:
                std::cout << "Unexpected character found: " << std::string(1, lexer->current_char) << "\n";
                break;
        }
        break;
    }

    return init_token("\0", static_cast<int>(TOKEN_T::TYPE::TOKEN_EOF));
}
