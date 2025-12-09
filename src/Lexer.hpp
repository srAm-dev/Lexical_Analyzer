#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Token.hpp"
#include "State.hpp"

// 状态转移函数
State transition(State currentState, char inputChar) {
    switch (currentState) {
    case s0:
        if (inputChar == 'i') return s1;
        else if (inputChar == 't') return s2;
        else if (inputChar == 'e') return s3;
        else if (inputChar == 'r') return s4;
        else if (inputChar == 'u') return s5;
        else if (inputChar == 'w') return s6;
        else if (inputChar == 'a') return s53;
        else if (inputChar <= '9' && inputChar >= '0') return s7;
        else if (inputChar == '=') return s8;
        else if (inputChar == '>') return s9;
        else if (inputChar == '<') return s10;
        else if (inputChar == ':') return s11;
        else if (inputChar == '/') return s12;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_')
                 && inputChar != 'i' && inputChar != 't' && inputChar != 'e' && inputChar != 'r' && inputChar != 'u'
                 && inputChar != 'w' && inputChar != 'a')
            return s13;
        else if (inputChar == '+') return s14;
        else if (inputChar == '-') return s15;
        else if (inputChar == '*') return s16;
        else if (inputChar == '(') return s17;
        else if (inputChar == ')') return s18;
        else if (inputChar == '[') return s28;
        else if (inputChar == ']') return s29;
        else if (inputChar == ';') return s19;
        else if (inputChar == '\n' || inputChar == '\t' || inputChar == ' ' || inputChar == '\r') return s20;
        else return s_error;
    case s1:
        if (inputChar == 'f') return s21;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'f')
            return s13;
        else return s_error;
    case s2:
        if (inputChar == 'h') return s22;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'h')
            return s13;
        else return s_error;
    case s3:
        if (inputChar == 'l') return s23;
        else if (inputChar == 'n') return s24;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'l' && inputChar != 'n')
            return s13;
        else return s_error;
    case s4:
        if (inputChar == 'e') return s25;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'e')
            return s13;
        else return s_error;
    case s5:
        if (inputChar == 'n') return s26;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'n')
            return s13;
        else return s_error;
    case s6:
        if (inputChar == 'r') return s27;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'r')
            return s13;
        else return s_error;
    case s7:
        if (inputChar <= '9' && inputChar >= '0') return s7;
        else return s_error;
    case s9:
        if (inputChar == '=') return s8;
        else return s_error;
    case s10:
        if (inputChar == '=' || inputChar == '>') return s8;
        else return s_error;
    case s11:
        if (inputChar == '=') return s31;
        else return s_error;
    case s12:
        if (inputChar == '/') return s32;
        else if (inputChar == '*') return s33;
        else return s_error;
    case s13:
        if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
             || inputChar <= '9' && inputChar >= '0'))
            return s13;
        else return s_error;
    case s21:
        if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
             || inputChar <= '9' && inputChar >= '0'))
            return s13;
        else return s_error;
    case s22:
        if (inputChar == 'e') return s34;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'e')
            return s13;
        else return s_error;
    case s23:
        if (inputChar == 's') return s35;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 's')
            return s13;
        else return s_error;
    case s24:
        if (inputChar == 'd') return s36;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'd')
            return s13;
        else return s_error;
    case s25:
        if (inputChar == 'p') return s37;
        else if (inputChar == 'a') return s38;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'p' && inputChar != 'a')
            return s13;
        else return s_error;
    case s26:
        if (inputChar == 't') return s39;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 't')
            return s13;
        else return s_error;
    case s27:
        if (inputChar == 'i') return s40;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'i')
            return s13;
        else return s_error;
    case s32:
        if (inputChar != '\n') return s32;
        else return s_error;
    case s33:
        if (inputChar == '*') return s41;
        else return s33;
    case s34:
        if (inputChar == 'n') return s42;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'n')
            return s13;
        else return s_error;
    case s35:
        if (inputChar == 'e') return s43;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'e')
            return s13;
        else return s_error;
    case s36:
        if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
             || inputChar <= '9' && inputChar >= '0'))
            return s13;
        else return s_error;
    case s37:
        if (inputChar == 'e') return s44;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'e')
            return s13;
        else return s_error;
    case s38:
        if (inputChar == 'd') return s45;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'd')
            return s13;
        else return s_error;
    case s39:
        if (inputChar == 'i') return s46;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'i')
            return s13;
        else return s_error;
    case s40:
        if (inputChar == 't') return s47;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 't')
            return s13;
        else return s_error;
    case s41:
        if (inputChar == '/') return s48;
        else if (inputChar == '*') return s41;
        else return s33;
    case s42:
        if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
             || inputChar <= '9' && inputChar >= '0'))
            return s13;
        else return s_error;
    case s43:
        if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
             || inputChar <= '9' && inputChar >= '0'))
            return s13;
        else return s_error;
    case s44:
        if (inputChar == 'a') return s49;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'a')
            return s13;
        else return s_error;
    case s45:
        if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
             || inputChar <= '9' && inputChar >= '0'))
            return s13;
        else return s_error;
    case s46:
        if (inputChar == 'l') return s50;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'l')
            return s13;
        else return s_error;
    case s47:
        if (inputChar == 'e') return s51;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'e')
            return s13;
        else return s_error;
    case s49:
        if (inputChar == 't') return s52;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 't')
            return s13;
        else return s_error;
    case s50:
        if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
             || inputChar <= '9' && inputChar >= '0'))
            return s13;
        else return s_error;
    case s51:
        if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
             || inputChar <= '9' && inputChar >= '0'))
            return s13;
        else return s_error;
    case s52:
        if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
             || inputChar <= '9' && inputChar >= '0'))
            return s13;
        else return s_error;
    case s53:
        if (inputChar == 'r') return s54;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'r')
            return s13;
        else return s_error;
    case s54:
        if (inputChar == 'r') return s55;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'r')
            return s13;
        else return s_error;
    case s55:
        if (inputChar == 'a') return s56;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'a')
            return s13;
        else return s_error;
    case s56:
        if (inputChar == 'y') return s57;
        else if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
                  || inputChar <= '9' && inputChar >= '0')
                 && inputChar != 'y')
            return s13;
        else return s_error;
    case s57:
        if ((inputChar <= 'z' && inputChar >= 'a' || inputChar <= 'Z' && inputChar >= 'A' || inputChar == '_'
             || inputChar <= '9' && inputChar >= '0'))
            return s13;
        else return s_error;
    default: return s_error;
    }
}

class Lexer {
private:
    State currentState;
    std::string currentLexeme;
    std::ifstream inputFile;
    std::vector<Token> tokenStream;

    bool getNextToken() {
        char ch;
        currentLexeme = "";
        currentState = s0;

        // 提前确认下一个字符是不是EOF。若是，直接回false
        if (inputFile.peek() == EOF) { return false; }

        while (inputFile.peek() != EOF) {
            char nextChar = inputFile.peek();
            State nextState = transition(currentState, nextChar);

            if (nextState != s_error) {
                // 如果转换有效，吞入字符并转移状态
                inputFile.get(ch);
                currentLexeme += ch;
                currentState = nextState;
            } else {
                // 如果转换无效，停止并返回当前token
                if (currentState == s0) {
                    // 在初始状态下无法转移，说明遇到了非法字符，直接吞入并报错
                    inputFile.get(ch);
                    currentLexeme += ch;
                    currentState = s_error;
                }
                break;
            }
        }

        return true;
    }

public:
    Lexer(std::string filename) : currentState(s0), currentLexeme("") {
        inputFile.open(filename, std::ios::in);
        tokenStream.clear();
    }
    ~Lexer() {
        if (inputFile.is_open()) inputFile.close();
    }
    void tokenOutput(std::string outputFilename) {
        Tokentype currentToken;
        std::ofstream outputFile;
        outputFile.open(outputFilename, std::ios::out);
        while (getNextToken()) {
            if (!isAccepting(currentState) || currentState == s_error) { // 非接受状态或错误状态，报错
                currentToken = ERROR;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "ERROR";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "ERROR" << " " << currentLexeme << std::endl;
            } else if (currentState == s1 || currentState == s2 || currentState == s3 || currentState == s4
                       || currentState == s5 || currentState == s6 || currentState == s13 || currentState == s22
                       || currentState == s23 || currentState == s24 || currentState == s25 || currentState == s26
                       || currentState == s27 || currentState == s33 || currentState == s34 || currentState == s35
                       || currentState == s37 || currentState == s38 || currentState == s39 || currentState == s40
                       || currentState == s41 || currentState == s44 || currentState == s46 || currentState == s47
                       || currentState == s49 || currentState == s53 || currentState == s54 || currentState == s55
                       || currentState == s56) { // ID接受状态
                currentToken = ID;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "ID";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "ID" << " " << currentLexeme << std::endl;
            } else if (currentState == s7) { // NUM接受状态
                currentToken = NUM;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "NUM";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "NUM" << " " << currentLexeme << std::endl;
            } else if (currentState == s8 || currentState == s9 || currentState == s10) { // RELOP接受状态
                currentToken = RELOP;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "RELOP";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "RELOP" << " " << currentLexeme << std::endl;
            } else if (currentState == s12) { // OVER接受状态
                currentToken = OVER;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "OVER";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "OVER" << " " << currentLexeme << std::endl;
            } else if (currentState == s14) { // PLUS接受状态
                currentToken = PLUS;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "PLUS";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "PLUS" << " " << currentLexeme << std::endl;
            } else if (currentState == s15) { // MINUS接受状态
                currentToken = MINUS;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "MINUS";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "MINUS" << " " << currentLexeme << std::endl;
            } else if (currentState == s16) { // TIMES接受状态
                currentToken = TIMES;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "TIMES";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "TIMES" << " " << currentLexeme << std::endl;
            } else if (currentState == s17) { // LPAREN接受状态
                currentToken = LPAREN;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "LPAREN";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "LPAREN" << " " << currentLexeme << std::endl;
            } else if (currentState == s18) { // RPAREN接受状态
                currentToken = RPAREN;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "RPAREN";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "RPAREN" << " " << currentLexeme << std::endl;
            } else if (currentState == s19) { // SEMI接受状态
                currentToken = SEMI;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "SEMI";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "SEMI" << " " << currentLexeme << std::endl;
            } else if (currentState == s20) { // DELIMITER接受状态
                currentToken = DELIMITER;
                tokenStream.push_back({currentToken, currentLexeme});
            } else if (currentState == s21) { // IF接受状态
                currentToken = IF;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "IF";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "IF" << " " << currentLexeme << std::endl;
            } else if (currentState == s28) { // LBRACKET接受状态
                currentToken = LBRACKET;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "LBRACKET";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "LBRACKET" << " " << currentLexeme << std::endl;
            } else if (currentState == s29) { // RBRACKET接受状态
                currentToken = RBRACKET;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "RBRACKET";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "RBRACKET" << " " << currentLexeme << std::endl;
            } else if (currentState == s31) { // ASSIGN接受状态
                currentToken = ASSIGN;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "ASSIGN";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "ASSIGN" << " " << currentLexeme << std::endl;
            } else if (currentState == s32) { // COMMENT_SINGLE接受状态
                currentToken = COMMENT_SINGLE;
                tokenStream.push_back({currentToken, currentLexeme});
            } else if (currentState == s36) { // END接受状态
                currentToken = END;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "END";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "END" << " " << currentLexeme << std::endl;
            } else if (currentState == s42) { // THEN接受状态
                currentToken = THEN;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "THEN";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "THEN" << " " << currentLexeme << std::endl;
            } else if (currentState == s43) { // ELSE接受状态
                currentToken = ELSE;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "ELSE";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "ELSE" << " " << currentLexeme << std::endl;
            } else if (currentState == s45) { // READ接受状态
                currentToken = READ;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "READ";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "READ" << " " << currentLexeme << std::endl;
            } else if (currentState == s48) { // COMMENT_MULTI接受状态
                currentToken = COMMENT_MULTI;
                tokenStream.push_back({currentToken, currentLexeme});
            } else if (currentState == s50) { // UNTIL接受状态
                currentToken = UNTIL;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "UNTIL";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "UNTIL" << " " << currentLexeme << std::endl;
            } else if (currentState == s51) { // WRITE接受状态
                currentToken = WRITE;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "WRITE";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "WRITE" << " " << currentLexeme << std::endl;
            } else if (currentState == s52) { // REPEAT接受状态
                currentToken = REPEAT;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "REPEAT";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "REPEAT" << " " << currentLexeme << std::endl;
            } else if (currentState == s57) { // ARRAY接受状态
                currentToken = ARRAY;
                tokenStream.push_back({currentToken, currentLexeme});
                std::cout << std::setw(15) << std::left << "ARRAY";
                std::cout << std::setw(15) << std::right << currentLexeme << std::endl;
                outputFile << "ARRAY" << " " << currentLexeme << std::endl;
            }
        }
        outputFile.close();
    }
};

#endif // LEXER_H