#ifndef KRS_LEX_TOKEN_H
#define KRS_LEX_TOKEN_H

#include <string>

struct TOKEN_T {
    std::string value;
    enum struct TYPE {
        TOKEN_ID=0,
        TOKEN_EQUALS=1,
        TOKEN_LPAREN=2,
        TOKEN_RPAREN=3,
        TOKEN_LBRACE=4,
        TOKEN_RBRACE=5,
        TOKEN_COLON=6,
        TOKEN_COMMA=7,
        TOKEN_LT=8,
        TOKEN_GT=9,
        TOKEN_RIGHT_ARROW=10,
        TOKEN_INT=11,
        TOKEN_SEMI=12,
        TOKEN_EOF=13,
        TOKEN_ADD=14
    };

    TYPE type;
};

TOKEN_T* init_token(const std::string value, int type);

std::string token_type_to_string(TOKEN_T::TYPE type);

#endif
