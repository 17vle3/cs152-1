/* Mini Calculator */
/* calc.y */

%{
#include "heading.h"
//#include <stdio.h>
//#define YY_NO_UNPUT
//int yyparse();
int yyerror(char *s);
int yylex(void);
stringstream all_code;
FILE * myin;
%}

%union{
    int       int_val;
    char str_val[256];

    //enum Type {INT, INT_ARR};

    struct {
        stringstream *code;
    }NonTerminal;

    struct {
       stringstream *code;
       //location
       string *place;
       string *offset;
       // branches
       string *op;
       string *begin;
       string *end;
       // type
       //uint val;
       Type type;
       uint length;
       // idents and vars
       vector<string> *ids;
       //vector<> *vars;
    } Terminal;
}

%error-verbose
//%skeleton "lalr1.cc"
//%require "3.0.4"
//%define api.token.constructor
//%define api.value.type variant
//%define parse.assert

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


//%type <Statement> IDENT NUMBER
//%type <NonTerminal> program decl_loop stmt_loop function function_2 statement statement_1

%type <NonTerminal> program
%type <Terminal> decl_loop stmt_loop function function_2 declaration declaration_2 declaration_3 statement  statement_1 statement_2   statement_21 statement_3   statement_4   statement_5   statement_51  statement_6   statement_61  bool_exp      bool_exp2     rel_and_exp   rel_and_exp2  relation_exp   relation_exp_s comp          expression    expression_2  mult_expr     mult_expr_2   term          term_2        term_3        term_31       term_32       var           var_2         


%%

program:    function program {
                printf("program -> function program\n");
                cout << "function:\n-------------------\n" << $1.code->str() << "\n==\nprogram:\n-----------\n" << $2.code << endl;
                //$2 or program should have all functions excecpt newest one
                $$.code = $2.code;
                //*($$.code) << $2.code->str();
              } 
            | {
                printf("program -> EPSILON\n");
                //nothing?
                $$.code = new stringstream();
              }
            ;

function:   FUNCTION IDENT SEMICOLON BEGIN_PARAMS decl_loop END_PARAMS BEGIN_LOCALS decl_loop END_LOCALS BEGIN_BODY statement SEMICOLON function_2 {
                printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS decl_loop END_PARAMS BEGIN_LOCALS decl_loop END_LOCALS BEGIN_BODY statement SEMICOLON function_2\n");
                //$13 or funtion 2, should have entire function code
                $$.code = $13.code;
                //$5 decl_loop should have function params
                //$8 decl_loop should have function local variables
                
            }
            ;

function_2: statement SEMICOLON function_2 {
                printf("function_2 -> statement SEMICOLON function_2\n");
                //$1 or statement should have line statement
                //$3 or func_2, should have previous statements
                $$.code = $3.code;

              } 
            | END_BODY {
                printf("function_2 -> END_BODY\n");
                //nothing?
                $$.code = new stringstream();
              }
            ;

decl_loop:  declaration SEMICOLON decl_loop {
                    printf("decl_loop -> declaration SEMICOLON decl_loop\n");
                    //decl_loop = everything before declaration = newest one
                } 
            | {
                printf("decl_loop -> EPSILON\n");
                //nothing?
                $$.code = new stringstream();
              }
            ;

stmt_loop:  statement SEMICOLON stmt_loop {
                printf("stmt_loop -> statement SEMICOLON stmt_loop\n");
                //stmt_loop everything before and statement = newest
              } 
            | {
                printf("stmt_loop -> EPSILON\n");
                //nothing?
                $$.code = new stringstream();
              }
            ;

declaration:    IDENT declaration_2 {
                    //printf("declaration -> IDENT declaration_2\n");
                    $$.code = $2.code;
                    $$.type = $2.type;
                    $$.length = $2.length;
                    //TODO: add variable to symbol_table

                    if($2.type == INT_ARR){
                        *($$.code) << ".[] " << $1 << ", " << $2.length << "\n";
                    }
                    else if($2.type == INT){
                        *($$.code) << ". " << $1 << "\n";
                    }else{printf("================ ERRRR\n");}
                    cout << "DECL:\n" << $$.code->str() << endl;

                }
                ;

declaration_2:  COMMA IDENT declaration_2 {
                    //printf("declaration_2 -> COMMA IDENT declaration_2\n");
                    $$.code = $3.code;
                    $$.type = $3.type;
                    $$.length = $3.length;
                    //TODO: add variable to symbol_table
                    if($3.type == INT_ARR){
                        *($$.code) << ".[] " << $2 << ", " << $3.length << "\n";
                    }
                    else if($3.type == INT){
                        *($$.code) << ". " << $2 << "\n";
                    }else{printf("================ ERRRR\n");}
                }
                | COLON declaration_3 INTEGER {
                    //printf("declaration_2 -> COLON declaration_3 INTEGER\n");
                    $$.code = $2.code;
                    $$.type = $2.type;
                    $$.length = $2.length;
                }
                ;

declaration_3:  ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF{
                    //printf("declaration_3 -> ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF\n");
                    $$.code = new stringstream();
                    $$.type = INT_ARR;
                    $$.length = $3;
                }
                | {
                    //printf("declaration_3 -> EPSILON\n");
                    $$.code = new stringstream();
                    $$.type = INT;
                    $$.length = 0;
                  }
                ;

statement:      statement_1 {
                    $$.code = $1.code;
                }
                | statement_2 {
                    $$.code = $1.code;
                }
                | statement_3 {
                    $$.code = $1.code;
                }
                | statement_4 {
                    $$.code = $1.code;
                }
                | statement_5 {
                    $$.code = $1.code;
                }
                | statement_6 {
                    $$.code = $1.code;
                }
                | CONTINUE{
                    printf("statement -> CONTINUE\n");
                    //TODO: probably add code to jump to start of loop?
                    $$.code = new stringstream();
                }
                | RETURN expression{
                    printf("statement -> RETURN expression\n");
                    //TODO: probably add code for returning function
                    $$.code = $2.code;
                }

statement_1:    var ASSIGN expression{
                    printf("statement -> var ASSIGN expression\n");
                    //TODO: var = x; check symbol table, assign it expression
                }
                ;

statement_2:    IF bool_exp THEN stmt_loop statement_21 ENDIF{
                    printf("statement -> IF bool_exp THEN stmt_loop statement_21 ENDIF\n");
                    //label, bool exp, loop.code, statemtn (else), label
                }
                ;

statement_21:   {
                    printf("statement_21 -> EPSILON\n");
                    $$.code = new stringstream();
                }
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
                | {
                    printf("statement_51 -> EPSILON\n");
                    $$.code = new stringstream();
                  }
                ;

statement_6:    WRITE var statement_61{
                    printf("statement -> WRITE var statement_61\n");
                  }
                ;

statement_61:   COMMA var statement_61{
                    printf("statement_61 -> COMMA var statement_61\n");
                  }
                |{
                    printf("statement_61 -> EPSILON\n");
                    $$.code = new stringstream();
                 }
                ;

bool_exp:       rel_and_exp bool_exp2{
                    printf("bool_exp -> rel_and_exp bool_exp2\n");
                }
                ;

bool_exp2:      OR rel_and_exp bool_exp2{
                    printf("bool_exp2 -> OR rel_and_exp bool_exp2\n");
                }
                |{
                    printf("bool_exp2 -> EPSILON\n");
                    $$.code = new stringstream();
                 }
                ; 

rel_and_exp:    relation_exp rel_and_exp2{
                    printf("rel_and_exp -> relation_exp rel_and_exp2\n");
                }
                ;

rel_and_exp2:   AND relation_exp rel_and_exp2{
                    printf("rel_and_exp2 -> AND relation_exp rel_and_exp2\n");
                }
                |{
                    printf("rel_and_exp2 -> EPSILON\n");
                    $$.code = new stringstream();
                 }
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
                | TRUE{
                        printf("relation_exp_s -> TRUE\n");
                    }
                | FALSE{
                    printf("relation_exp_s -> FALSE\n");
                  }
                | L_PAREN bool_exp R_PAREN{
                    printf("relation_exp_s -> L_PAREN bool_exp R_PAREN\n");
                }
                ;

comp:           EQ{
                    printf("comp -> EQ\n");
                  }
                | NEQ{
                    printf("comp -> NEQ\n");
                  }
                | LT{
                    printf("comp -> LT\n");
                  }
                | GT{
                    printf("comp -> GT\n");
                  }
                | LTE{
                    printf("comp -> LTE\n");
                  }
                | GTE{
                    printf("comp -> GTE\n");
                  }
                ;

expression:     mult_expr expression_2{
                    printf("expression -> mult_expr expression_2\n");
                  }
                ;

expression_2:   ADD mult_expr expression_2 {
                    printf("expression_2 -> ADD mult_expr expression_2\n");
                  }
                | SUB mult_expr expression_2{
                    printf("expression_2 -> SUB mult_expr expression_2\n");
                  }
                | {
                    printf("expression -> EPSILON\n");
                    $$.code = new stringstream();
                  }
                ;

mult_expr:      term mult_expr_2{
                    $$.code = $2.code;
                    //*$$.code = new stringstream();
                    // *($$.code) << $2.code << " " << term;
                    printf("mult_expr -> term mult_expr_2\n");
                  }
                ;

mult_expr_2:    MULT term mult_expr_2{
                    printf("mult_expr_2 -> MULT mult_expr\n");

                    $$.code = $2.code;
                    //*($$.code) << "*";
                    if($3.op == NULL){
                        $$.place = $2.place;
                        $$.op = new string();
                        *$$.op = "*";
                    }
                    else{
                        //$3.op temp $2.place $3.place
                        //$$.place = temp
                        //$$.op = new string();
                        //*$$.op = "*";

                        //*($$.code) << ". " << temp << "\n"
                        //            << *$$.op << " " << temp << ", " << *$2.place << ", " 
                        //            << *$3.place << "\n";
                    } 
                  }
                | DIV term mult_expr_2{
                    printf("mult_expr_2 -> DIV mult_expr\n");
                    cout << "WARN: TERM CODE IS NULL" << endl;
                     $$.code = $2.code;
                    *($$.code) << "/";                   
                  }
                | MOD term mult_expr_2{
                    printf("mult_expr_2 -> MOD mult_expr\n");
                    $$.code = $2.code;
                    *($$.code) << "%";
                  }
                |{
                    printf("mult_expr_2 -> EPSILON\n");
                    $$.code = new stringstream();
                    $$.op = NULL;
                 }
                ;

term:           SUB term_2{
                    printf("term -> SUB term_2\n");
                    $$.code = $2.code;
                  }
                | term_2{
                    printf("term -> term_2\n");
                    $$.code = $1.code;
                  }
                | term_3{
                    cout << "term_3:" <<  $1.code->str() << endl;
                    printf("term -> term_3\n");
                    $$.code = $1.code;
                  }
                ;

term_2:         var{
                    printf("term_2 -> var\n");
                    $$.code = $1.code;
                  }
                | NUMBER{
                    printf("term_2 -> NUMBER\n");
                    //TODO: probably save number
                    $$.code = new stringstream();
                  }
                | L_PAREN expression R_PAREN{
                    printf("term_2 -> L_PAREN expression R_PAREN\n");
                    $$.code = $2.code;
                  }
                ;

term_3:         IDENT L_PAREN term_31 R_PAREN{
                    cout << "IDENT:" <<  $1 << "\n\n\n\n\n\n";
                    $$.code = new stringstream();
                    //*($$.code) << "my text";
                    //$$.name = "my test" ;
                    //$$.name = $1 ;
                    //strncpy($$.name,$1,256-1);
                    printf("IDENT:%s\n",$1);
                    printf("term_3 -> IDENT L_PAREN term_31 R_PAREN\n");
                }
                ;

term_31:        expression term_32{
                    printf("term_31-> expression term_32\n");
                    //expression followed by comma of term_31
                    $$.code = $2.code;
                } 
                | {
                    printf("term_31 -> EPSILON\n");
                    $$.code = new stringstream(); 
                  }
                ;
term_32:        COMMA term_31{
                    printf("term_32 -> COMMA term_31\n");
                    $$.code = $2.code;
                } 
                | {
                    printf("term_32 -> EPSILON\n");
                    $$.code = new stringstream();
                  }

var:            IDENT var_2{
                    printf("var -> IDENT var_2\n");
                    $$.code = $2.code;
                }
                ;

var_2:          L_SQUARE_BRACKET expression R_SQUARE_BRACKET{
                    //$$.code = new stringstream();
                    $$.code = $2.code;
                    //printf("var_2 -> L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");
                }
                |{
                    $$.code = new stringstream();
                    //printf("var_2 -> EPSILON\n");
                 }
                ;
            
%%

string gen_code(string *res, string op, string *val1, string *val2){
    if(op == "!"){
        return op + " " + *res + "," + *val1;
    }
    else{
        return op + " " + *res + "," + *val1 + ","+ *val2;
    }
}

string * new_temp(){
    string * t = new string();
    *t = "FAKE";
    return t;
}

int main(int argc, char **argv) {

    if ( (argc > 1) && (myin = fopen(argv[1],"r")) == NULL){
        printf("syntax: %s filename\n", argv[0]);
        return 1;
    }

for(int i = 0; i < argc; ++i){
            cout << argv[i] << endl;
        }
    yyparse();

    //all_code << program_code->str();

    ofstream file;
    file.open("mil_code.mil");
    file << all_code.str();
    file.close();


return 0;
}


//int main(int argc, char **argv) {
//    if ( (argc > 1) && (yyin = fopen(argv[1],"r")) == NULL){
//        printf("syntax: %s filename\n", argv[0]);
//        return 1;
//    }
//    yyparse();
//    return 0;
//}
//
int yyerror(char *s)
{
extern int line_cnt;
extern int cursor_pos;
    printf(">>> Line %d, position %d: %s\n",line_cnt,cursor_pos,s);
    return -1;
    //return yyerror(string(s));
}


