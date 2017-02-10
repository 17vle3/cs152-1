/* Mini Calculator */
/* calc.y */

%{
#include <stdio.h>
#include <stdlib.h>
int yyparse();
int yyerror(char *s);
int yylex(void);
extern int line_cnt;
extern int cursor_pos;
FILE * yyin;
%}

%union{
    int       int_val;
    char str_val[256];
}

%error-verbose
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token INTEGER ARRAY OF 
%token IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE 
%token READ WRITE RETURN
%token AND OR NOT TRUE FALSE 
%token SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE 
%token SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN
%token NUMBER IDENT

%type <int_val> NUMBER
%type <str_val> IDENT

%%

program:    function program {printf("program -> function program\n");} 
            | {printf("program -> EPSILON\n");}
            ;

function:   FUNCTION IDENT SEMICOLON BEGIN_PARAMS decl_loop END_PARAMS BEGIN_LOCALS decl_loop END_LOCALS BEGIN_BODY statement SEMICOLON function_2 {
        printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS decl_loop END_PARAMS BEGIN_LOCALS decl_loop END_LOCALS BEGIN_BODY statement SEMICOLON function_2\n");
        //printf("---------- IDENT -> %s\n", $2);
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
                //printf("---------- IDENT -> %s\n", $1);
                }
                ;

declaration_2:  COMMA IDENT declaration_2 {
                printf("declaration_2 -> COMMA IDENT declaration_2\n");
                //printf("---------- IDENT -> %s\n", $2);
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
                | CONTINUE{
                    printf("statement -> CONTINUE\n");
                }
                | RETURN expression{
                    printf("statement -> RETURN expression\n");
                }

statement_1:    var ASSIGN expression{
                printf("statement -> var ASSIGN expression\n");
                }
                ;

statement_2:    IF bool_exp THEN stmt_loop statement_21 ENDIF{
                printf("statement -> IF bool_exp THEN stmt_loop statement_21 ENDIF\n");
                }
                ;

statement_21:   {printf("statement_21 -> EPSILON\n");}
                | ELSE stmt_loop{
                printf("statement_21 -> ELSE stmt_loop\n");
                }
                ;

statement_3:    WHILE bool_exp BEGINLOOP stmt_loop ENDLOOP{
                printf("statement -> WHILE bool_exp BEGINLOOP stmt_loop ENDLOOP\n");
                }
                ;

statement_4:    DO BEGINLOOP stmt_loop ENDLOOP WHILE bool_exp{
                printf("statement -> DO BEGINLOOP stmt_loop ENDLOOP WHILE bool_exp\n");
                }
                ;

statement_5:    READ var statement_51{
                printf("statement -> READ var statement_51\n");
                }
                ;

statement_51:   COMMA var statement_51 {
                printf("statement_51 -> COMMA var statement_51\n");
                }
                | {printf("statement_51 -> EPSILON\n");}
                ;

statement_6:    WRITE var statement_61{printf("statement -> WRITE var statement_61\n");}
                ;

statement_61:   COMMA var statement_61{printf("statement_61 -> COMMA var statement_61\n");}
                |{printf("statement_61 -> EPSILON\n");}
                ;

bool_exp:       rel_and_exp bool_exp2{
                printf("bool_exp -> rel_and_exp bool_exp2\n");
                }
                ;

bool_exp2:      OR rel_and_exp bool_exp2{
                printf("bool_exp2 -> OR rel_and_exp bool_exp2\n");
                }
                |{printf("bool_exp2 -> EPSILON\n");}
                ; 

rel_and_exp:    relation_exp rel_and_exp2{
                printf("rel_and_exp -> relation_exp rel_and_exp2\n");
                }
                ;

rel_and_exp2:   AND relation_exp rel_and_exp2{
                printf("rel_and_exp2 -> AND relation_exp rel_and_exp2\n");
                }
                |{printf("rel_and_exp2 -> EPSILON\n");}
                ;

relation_exp:   relation_exp_s{
                printf("relation_exp -> relation_exp_s\n");
                }
                | NOT relation_exp_s{
                printf("relation_exp -> NOT relation_exp_s\n");
                }
                ;

relation_exp_s: expression comp expression{
                printf("relation_exp_s -> expression comp expression\n");
                }
                | TRUE{printf("relation_exp_s -> TRUE\n");}
                | FALSE{printf("relation_exp_s -> FALSE\n");}
                | L_PAREN bool_exp R_PAREN{
                printf("relation_exp_s -> L_PAREN bool_exp R_PAREN\n");
                }
                ;

comp:           EQ{printf("comp -> EQ\n");}
                | NEQ{printf("comp -> NEQ\n");}
                | LT{printf("comp -> LT\n");}
                | GT{printf("comp -> GT\n");}
                | LTE{printf("comp -> LTE\n");}
                | GTE{printf("comp -> GTE\n");}
                ;

expression:     mult_expr expression_2{printf("expression -> mult_expr expression_2\n");}
                ;

expression_2:   ADD mult_expr expression_2 {printf("expression_2 -> ADD mult_expr expression_2\n");}
                | SUB mult_expr expression_2{printf("expression_2 -> SUB mult_expr expression_2\n");}
                | {printf("expression -> EPSILON\n");}
                ;

mult_expr:      term mult_expr_2{printf("mult_expr -> term mult_expr_2\n");}
                ;

mult_expr_2:    MULT mult_expr{printf("mult_expr_2 -> MULT mult_expr\n");}
                | DIV mult_expr{printf("mult_expr_2 -> DIV mult_expr\n");}
                | MOD mult_expr{printf("mult_expr_2 -> MOD mult_expr\n");}
                |{printf("mult_expr_2 -> EPSILON\n");}
                ;

term:           SUB term_2{printf("term -> SUB term_2\n");}
                | term_2{printf("term -> term_2\n");}
                | term_3{printf("term -> term_3\n");}
                ;

term_2:         var{printf("term_2 -> var\n");}
                | NUMBER{printf("term_2 -> NUMBER\n");}
                | L_PAREN expression R_PAREN{printf("term_2 -> L_PAREN expression R_PAREN\n");}
                ;

term_3:         IDENT L_PAREN term_31 R_PAREN{
                printf("term_3 -> IDENT L_PAREN term_31 R_PAREN\n");
                //printf("---------- IDENT -> %s\n", $1);
                }
                ;

term_31:        expression term_32{printf("term_31-> expression term_32\n");} | {printf("term_31 -> EPSILON\n");}
                ;
term_32:        COMMA term_31{printf("term_32 -> COMMA term_31\n");} | {printf("term_32 -> EPSILON\n");}

//term_31:        expression COMMA term_31{printf("term_31 -> expression COMMA term_31\n");}
//                | {printf("term_31 -> EPSILON\n");}
//                ;

var:            IDENT var_2{
                printf("var -> IDENT var_2\n");
                //printf("---------- IDENT -> %s\n", $1);
                }
                ;

var_2:          L_SQUARE_BRACKET expression R_SQUARE_BRACKET{
                printf("var_2 -> L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");
                }
                |{printf("var_2 -> EPSILON\n");}
                ;
            
%%

int main(int argc, char **argv) {
    if ( (argc > 1) && (yyin = fopen(argv[1],"r")) == NULL){
        printf("syntax: %s filename\n", argv[0]);
        return 1;
    }
    yyparse();
    return 0;
}

//
//int main(int argc, char **argv)
//{
//    if ((argc > 1) && (freopen(argv[1], "r", stdin) == NULL))
//    {
//        cerr << argv[0] << ": File " << argv[1] << " cannot be opened.\n";
//        exit( 1 );
//    }
//yyparse();
//return 0;
//}

int yyerror(char *s)
{
    printf("***** Line %d, position %d: %s\n",line_cnt,cursor_pos,s);
    //return yyerror(string(s));
}


