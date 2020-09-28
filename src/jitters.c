#include <stdio.h>
#include <stdlib.h>

#include "ast/ast.h"
#include "print/printer.h"
#include "parse/parse-jitters.h"

int main(void)
{
    struct ast_node *ast = NULL;
    int ret = 0;
    yydebug = getenv("PARSE") != NULL;
    if ((ret = yyparse(&ast)) == 0) {
        printer_ast(ast);
        putchar('\n');
    }

    destroy_ast(ast);

    return ret;
}
