#ifndef STATE_H
#define STATE_H

// 定义DFA的各个状态
// 未进行标注的接受状态为ID接受状态
enum State {
    s0 = 0,
    s1,
    s2,
    s3,
    s4,
    s5,
    s6,
    s7,  // NUM接受状态
    s8,  // RELOP接受状态
    s9,  // RELOP接受状态
    s10, // RELOP接受状态
    s11,
    s12, // OVER接受状态
    s13,
    s14, // PLUS接受状态
    s15, // MINUS接受状态
    s16, // TIMES接受状态
    s17, // LPAREN接受状态
    s18, // RPAREN接受状态
    s19, // SEMI接受状态
    s20, // DELIMITER接受状态
    s21, // IF接受状态
    s22,
    s23,
    s24,
    s25,
    s26,
    s27,
    s28,      // LBRACKET接受状态
    s29,      // RBRACKET接受状态
    s31 = 31, // ASSIGN接受状态
    s32,      // COMMENT_SINGLE接受状态
    s33,
    s34,
    s35,
    s36, // END接受状态
    s37,
    s38,
    s39,
    s40,
    s41,
    s42, // THEN接受状态
    s43, // ELSE接受状态
    s44,
    s45, // READ接受状态
    s46,
    s47,
    s48, // COMMENT_MULTI接受状态
    s49,
    s50, // UNTIL接受状态
    s51, // WRITE接受状态
    s52, // REPEAT接受状态
    s53,
    s54,
    s55,
    s56,
    s57, // ARRAY接受状态
    s_error = -1
};

// 判断是否为接受状态
// 0, 11, 33, 41 不是接受状态，其余均为接受状态
inline bool isAccepting(State s) { return s != s0 && s != s11 && s != s33 && s != s41; }

#endif