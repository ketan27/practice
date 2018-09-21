#include "stack.h"

stack_node *createStackNode(char ch)
{
    stack_node *tmp = (stack_node *)malloc(sizeof(stack_node));
    if (tmp) {
        tmp->data = ch;
        tmp->next = NULL;
    }
    return tmp;
}

void push(stack_node **top, char ch)
{
    stack_node *new_node = createStackNode(ch);

    if (new_node) {
        if (*top == NULL) {
            // no element was there in stack
            *top = new_node;
        } else {
            new_node->next = *top;
            *top = new_node;
        }
    }
}

int isEmpty(stack_node *top)
{
    return (top == NULL);
}

char pop(stack_node **top)
{
    char ret;

    // Non empty stack only
    if (!isEmpty(*top)) {
        stack_node *tmp = *top;
        *top = (*top)->next;

        ret = tmp->data;
        free(tmp);
    }

    return ret;
}

char topNode(stack_node *top)
{
    char ret = 0;

    if (!isEmpty(top)) {
        return top->data;
        ret = 1;
    }

    return ret;
}

void traverse(stack_node *top)
{
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }

    while (top) {
        printf("%c  ", top->data);
        top = top->next;
    }
    printf("\n");
}

void deleteStack(stack_node **top)
{
    if (isEmpty(*top)) {
        printf("Stack is empty, not deleting anything!!\n");
        return;
    }

    stack_node *tmp = NULL;

    while(*top) {
        tmp = *top;
        *top = (*top)->next;

        free(tmp);
    }
}

// 1 on success else 0
int popUntil(stack_node **top, char ch)
{
    stack_node *tmp = NULL;
    // This variable indicates that a matching opening bracket is found. It is required because
    // in case if opening brace is not found, we'll keep on popping until there are elements in
    // stack. In such case, we'll get to know that is is an error.
    int found;

    while ((*top != NULL)) {
        found = 0;
        tmp = *top;
        *top = (*top)->next;

        if ((ch == ')' && tmp->data == '(') ||
            (ch == ']' && tmp->data == '[') ||
            (ch == '}' && tmp->data == '{')) {
            found = 1;
            break;
        }

        free(tmp);
    }

    return found;
}
