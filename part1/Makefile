# Makefile


all:
			flex mini_l.lex
			gcc lex.yy.c -lfl -o lexer

test:		all
			./mytest.sh
			

clean:		
			rm -f lex.yy.c lexer

