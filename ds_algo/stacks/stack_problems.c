#include "stack.h"

int isBalanced(char *str)
{
    if (str == NULL) {
        printf("No expression string is given\n");
        return 0;
    }

    printf("Testing the string: %s\n\n", str);
    char ch;
    int ret = 1;

    stack_node *expr = (stack_node *)malloc(sizeof(stack_node));
    expr = NULL;

    while (*str) {
        ch = *str;

        switch(ch) {
            case '{':
            case '(':
            case '[':
                {
                    push(&expr, ch);
                    break;
                }
            case 'a' ... 'z':
            case 'A' ... 'Z':
            case '0' ... '9':
            case '+':
            case '-':
            case '/':
            case '*':
                {
                    if(!isEmpty(expr)) {
                        push(&expr, ch);
                    }
                    break;
                }

            case '}':
            case ')':
            case ']':
            {
                if (isEmpty(expr)) {
                    /*
                     * We have a closing braces, so for balanced equation, there should be an opening
                     * one as well else our string is not balanced.
                     * */
                    return 0;
                }

                /*
                 * Since there are elements in stack, that means we need to pop out until an opening
                 * brace is encountered.
                 */
                ret = popUntil(&expr, ch);
                break;
            }
        }

        str++;
    }// end of string parsing, ideally if it is balanced, stack should be empty.

    if (isEmpty(expr) && ret) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    char *str = "(a+b) + (c+d)";

    if (isBalanced(str)) {
        printf("String is balanced\n");
    } else {
        printf("String is not balanced\n");
    }

    return 0;
}
