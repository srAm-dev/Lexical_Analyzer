#ifndef TOKEN_H
#define TOKEN_H

#include <string>

// 词法单元类型枚举
enum Tokentype {
    // 关键字
    IF,
    THEN,
    ELSE,
    END,
    REPEAT,
    UNTIL,
    READ,
    WRITE,
    ARRAY,

    // 自定义符
    ID,
    NUM,

    // 运算符
    ASSIGN,
    RELOP,
    PLUS,
    MINUS,
    TIMES,
    OVER,
    LPAREN,
    RPAREN,
    LBRACKET,
    RBRACKET,
    SEMI,

    // 注释与空格，词法分析器会识别，但是不会做输出
    COMMENT_SINGLE,
    COMMENT_MULTI,
    DELIMITER,

    // 错误
    ERROR
};

// 词法单元结构体
struct Token {
    Tokentype type;
    std::string lexeme;
};

#endif // TOKEN_H