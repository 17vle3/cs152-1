/* Mini Calculator */
/* calc.y */

%{
#include "heading.h"
    int yyerror(char *s);
    int yylex(void);
    %}

%union{
      int       int_val;
        string* op_val;
}

%error-verbose
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token INTEGER ARRAY OF 
%token IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE 
%token READ WRITE 
%token AND OR NOT TRUE FALSE 
%token SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE 
%token SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN NUMBER

%type <int_val> NUMBER
%type <str_val> IDENT

%%

program:    function program {printf("PROGRAM -> function program");} | error
            ;
function:   FUNCTION IDENT SEMICOLON BEGIN_PARAMS{printf("---------- %s\n", $2);printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS")}

            
%%

//int yyerror(string s)
//{
//      extern int yylineno;  // defined and maintained in lex.c
//        extern char *yytext;    // defined and maintained in lex.c
//          
//            cerr << "ERROR: " << s << " at symbol \"" << yytext;
//              cerr << "\" on line " << yylineno << endl;
//                exit(1);
//}

int yyerror(char *s)
{
      return yyerror(string(s));
}


