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

program:    function program {printf("program -> function program");} 
            | {printf("program -> EPSILON");}
            ;

function:   FUNCTION IDENT SEMICOLON BEGIN_PARAMS decl_loop END_PARAMS BEGIN_LOCALS decl_loop END_LOCALS BEGIN_BODY statement SEMICOLON function_2 {
        printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS decl_loop END_PARAMS BEGIN_LOCALS decl_loop END_LOCALS BEGIN_BODY statement SEMICOLON function_2\n");
        printf("---------- %s\n", $2);
}
            ;

function_2: statement SEMICOLON function_2 {printf("function_2 -> statement SEMICOLON function_2\n");} 
            | END_BODY {printf("function_2 -> END_BODY\n");}
            ;

decl_loop:  declaration SEMICOLON decl_loop {printf("decl_loop -> declaration SEMICOLON decl_loop\n");} 
            | {printf("decl_loop -> EPSILON\n");}
            ;

stmt_loop:  statement SEMICOLON stmt_loop {printf("stmt_loop -> statement SEMICOLON stmt_loop\n");} 
            | {printf("stmt_loop -> EPSILON\n");}
            ;

declaration:    IDENT declaration_2 {
                printf("declaration -> IDENT declaration_2\n");
                printf("---------- %s\n", $1);
                }
                ;

declaration_2:  COMMA IDENT declaration_2 {
                printf("declaration_2 -> COMMA IDENT declaration_2\n");
                printf("---------- %s\n", $2);
                }
                | COLON declaration_3 INTEGER {
                    printf("declaration_2 -> COLON declaration_3 INTEGER\n");
                }
                ;

declaration_3:  {printf("declaration_3 -> EPSILON\n");}
                | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF{
                    printf("declaration_3 -> ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF\n");
                }
                ;

statement:      statement_1 
                | statement_2 
                | statement_3 
                | statement_4 
                | statement_5 
                | statement_6 
                | CONTINUE 
                | 

            
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


