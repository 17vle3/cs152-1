
#include "heading.h"
#include <stdio.h>
#define YY_NO_UNPUT
int yyparse();
FILE * myin;

int main(int argc, char **argv) {
        if ( (argc > 1) && (myin = fopen(argv[1],"r")) == NULL){
                    printf("syntax: %s filename\n", argv[0]);
                            return 1;
                                }
            yyparse();
                return 0;
}

