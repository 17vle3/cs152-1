/* 
 * Description: Recognize the 32-bit hexadecimal integer from stdin
 * Pattern: 0[xX]([0-9a-fA-F]{1,8})
yyleng
IDENT_VAR_ERR	()({LETTER}|{DIGIT}|[_])*[_]+

 */

	int line_cnt = 1;
	int cursor_pos = 1;

DIGIT		    [0-9]
LETTER  	    [a-zA-Z]
COMMENT		    ##.*
IDENT_VAR	    {LETTER}({LETTER}|{DIGIT}|[_])*(({LETTER}|{DIGIT})+)*
IDENT_DIG	    {DIGIT}*
IDENT_ERR_START ({DIGIT}|[_])({LETTER}|{DIGIT}|[_])*(({LETTER}|{DIGIT})+)*
IDENT_ERR_END	{LETTER}({LETTER}|{DIGIT}|[_])*([_])+

%%
[ \t]+ 		        cursor_pos += yyleng;
\n 		            ++line_cnt;cursor_pos=1;
{COMMENT}	        
function 	        printf("FUNCTION\n");cursor_pos += yyleng;
beginparams	        printf("BEGIN_PARAMS\n");cursor_pos += yyleng;
endparams	        printf("END_PARAMS\n");cursor_pos += yyleng;
beginlocals	        printf("BEGIN_LOCALS\n");cursor_pos += yyleng;
endlocals	        printf("END_LOCALS\n");cursor_pos += yyleng;
beginbody	        printf("BEGIN_BODY\n");cursor_pos += yyleng;
endbody		        printf("END_BODY\n");cursor_pos += yyleng;
integer		        printf("INTEGER\n");cursor_pos += yyleng;
array		        printf("ARRAY\n");cursor_pos += yyleng;
of		            printf("OF\n");cursor_pos += yyleng;
if		            printf("IF\n");cursor_pos += yyleng;
then		        printf("THEN\n");cursor_pos += yyleng;
endif		        printf("ENDIF\n");cursor_pos += yyleng;
else		        printf("ELSE\n");cursor_pos += yyleng;
while		        printf("WHILE\n");cursor_pos += yyleng;
do		            printf("DO\n");cursor_pos += yyleng;
beginloop	        printf("BEGINLOOP\n");cursor_pos += yyleng;
endloop		        printf("ENDLOOP\n");cursor_pos += yyleng;
continue	        printf("CONTINUE\n");cursor_pos += yyleng;
read		        printf("READ\n");cursor_pos += yyleng;
write		        printf("WRITE\n");cursor_pos += yyleng;
and		            printf("AND\n");cursor_pos += yyleng;
or		            printf("OR\n");cursor_pos += yyleng;
not		            printf("NOT\n");cursor_pos += yyleng;
true		        printf("TRUE\n");cursor_pos += yyleng;
false		        printf("FALSE\n");cursor_pos += yyleng;
\-		            printf("SUB\n");cursor_pos += yyleng;
\+		            printf("ADD\n");cursor_pos += yyleng;
\*		            printf("MULT\n");cursor_pos += yyleng;
\/		            printf("DIV\n");cursor_pos += yyleng;
\%		            printf("MOD\n");cursor_pos += yyleng;
\=\=		        printf("EQ\n");cursor_pos += yyleng;
\<\>		        printf("NEQ\n");cursor_pos += yyleng;
\<		            printf("LT\n");cursor_pos += yyleng;
\>		            printf("GT\n");cursor_pos += yyleng;
\<\=		        printf("LTE\n");cursor_pos += yyleng;
\>\=		        printf("GTE\n");cursor_pos += yyleng;
\;		            printf("SEMICOLON\n");cursor_pos += yyleng;
\:		            printf("COLON\n");cursor_pos += yyleng;
\,		            printf("COMMA\n");cursor_pos += yyleng;
\(		            printf("L_PAREN\n");cursor_pos += yyleng;
\)		            printf("R_PAREN\n");cursor_pos += yyleng;
\[		            printf("L_SQUARE_BRACKET\n");cursor_pos += yyleng;
\]		            printf("R_SQUARE_BRACKET\n");cursor_pos += yyleng;
\:\=		        printf("ASSIGN\n");cursor_pos += yyleng;
return              printf("RETURN\n");cursor_pos += yyleng;
{IDENT_DIG}	        printf("NUMBER %s\n",yytext);cursor_pos += yyleng; 
{IDENT_ERR_START}   fprintf(stderr,"Error at line %d, column %d: identifier \"%s\" must begin with a letter\n",line_cnt,cursor_pos,yytext);exit(0);
{IDENT_ERR_END}	    fprintf(stderr,"Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n",line_cnt,cursor_pos,yytext);exit(0);
{IDENT_VAR}	        printf("IDENT %s\n",yytext);cursor_pos += yyleng;  
.		            fprintf(stderr,"Error at line %d, column %d: unrecognized symbol \"%s\"\n",line_cnt,cursor_pos,yytext);exit(0);
%%

/*
*/
int main(int argc, char **argv)
{
  yylex();
}
