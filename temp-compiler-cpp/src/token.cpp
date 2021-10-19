#include "token.h"
#include <iostream>

TOKEN_T* init_token(const std::string value, int num) {
    TOKEN_T* token = new TOKEN_T();
    token->value = value;
    token->type = static_cast<TOKEN_T::TYPE>(num);

    return token;
}

std::string token_type_to_string(TOKEN_T::TYPE type) {
    switch (type) {
        case TOKEN_T::TYPE::TOKEN_ID: return "TOKEN_ID";
        case TOKEN_T::TYPE::TOKEN_EQUALS: return "TOKEN_EQUALS";
        case TOKEN_T::TYPE::TOKEN_LPAREN: return "TOKEN_LPAREN";
        case TOKEN_T::TYPE::TOKEN_RPAREN: return "TOKEN_RPAREN";
        case TOKEN_T::TYPE::TOKEN_LBRACE: return "TOKEN_LBRACE";
        case TOKEN_T::TYPE::TOKEN_RBRACE: return "TOKEN_RBRACE";
        case TOKEN_T::TYPE::TOKEN_COLON: return "TOKEN_COLON";
        case TOKEN_T::TYPE::TOKEN_COMMA: return "TOKEN_COMMA";
        case TOKEN_T::TYPE::TOKEN_LT: return "TOKEN_LT";
        case TOKEN_T::TYPE::TOKEN_GT: return "TOKEN_GT";
        case TOKEN_T::TYPE::TOKEN_RIGHT_ARROW: return "TOKEN_RIGHT_ARROW";
        case TOKEN_T::TYPE::TOKEN_INT: return "TOKEN_INT";
        case TOKEN_T::TYPE::TOKEN_SEMI: return "TOKEN_SEMI";
        case TOKEN_T::TYPE::TOKEN_EOF: return "TOKEN_EOF";
        default:
            std::cout << "Unexpected token given: " << static_cast<int>(type)  << '\n';
            break;
    };

    return NULL;
}
