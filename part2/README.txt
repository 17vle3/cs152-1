//will create y.tab.c .h and y.tab.h and y.output
bison -v -d --file-prefix=y mini_l.y

// creates lex.yy.c
flex mini_l.lex

// creates parser
gcc -o parser y.tab.c lex.yy.c -lfl
