#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push an element into stack
void push(char x)
{
    stack[++top] = x;
}

// Pop an element from stack
char pop()
{
    return stack[top--];
}

// Return precedence of operator
int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;

    return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char symbol;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];

        // If operand, add it directly to postfix
        if (isalnum(symbol))
        {
            postfix[j++] = symbol;
        }

        // If opening parenthesis, push it
        else if (symbol == '(')
        {
            push(symbol);
        }

        // If closing parenthesis, pop until '('
        else if (symbol == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            pop();   // Remove '('
        }

        // If operator
        else if (symbol == '+' || symbol == '-' ||
                 symbol == '*' || symbol == '/')
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j++] = pop();
            }

            push(symbol);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}