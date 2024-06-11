#ifndef _DEFINE_H_
#define _DEFINE_H_

typedef enum 
{
	// 文件结束
	ENDFILE,
	
	// 错误
	ERROR,
	
    // 关键字
    IF,			// if
    THEN,		// then
    ELSE,		// else
    END,		// end
    REPEAT,		// repeat
    UNTIL,		// until
    READ,		// read
    WRITE,		// write
    
    // 标识符
    ID,
    
    // 无符号整数
    NUM,
    
    // 特殊符号
    ASSIGN,		// :=
    EQ,			// =
    LT,			// <
    PLUS,		// +
    MINUS,		// -
    TIMES,		// *
    OVER,		// /
    LPAREN,		// (
    RPAREN,		// )
    SEMI,		// ;
    
    // 注释
    COMMENT		// {...}
    
}TokenType;

#endif // _DEFINE_H_
