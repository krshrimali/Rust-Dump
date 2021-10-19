#include "token.h"

TOKEN_T* init_token(const std::string value, int num) {
    TOKEN_T* token = {};
    token->value = value;
    token->type = static_cast<TOKEN_T::TYPE>(num);

    return token;
}
