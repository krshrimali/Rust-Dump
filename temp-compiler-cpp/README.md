**Execution**:

```bash
$ make
$ ./a.out main.krs

func, TOKEN_ID
(, TOKEN_LPAREN
3, TOKEN_INT
,, TOKEN_COMMA
4, TOKEN_INT
), TOKEN_RPAREN
=>, TOKEN_RIGHT_ARROW
{, TOKEN_LBRACE
return, TOKEN_ID
3, TOKEN_INT
+, TOKEN_ADD
4, TOKEN_INT
;, TOKEN_SEMI
}, TOKEN_RBRACE
EOF, TOKEN_EOF
```

**Note:**

- I'm currently attempting to write a compiler (will add references soon) in C++ and while I'm learning Rust - I'll attempt to port this to Rust.
- This is in WIP stage.

**Why C++ and not Rust now?**

- I'm more comfortable with C++ right now.
- I'm still learning Rust, and it will take me some time to get comfortable.
- I don't want to delay learning compiler development.

This is highly inspired from these resources:

1. Crafting Interpreters: https://craftinginterpreters.com/contents.html
2. Series on compiler development: https://www.youtube.com/watch?v=PRcMPwaWj1Y
