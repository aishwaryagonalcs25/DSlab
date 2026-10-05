#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push an element into the stack
void push(char ch)
{
    stack[++top] = ch;
}

// Pop an element from the stack
char pop()
{
    return stack[top--];
}

// Check whether brackets match
int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    if (open == '{' && close == '}')
        return 1;

    return 0;
}

int main()
{
    char str[MAX];
    int i;
    int valid = 1;

    printf("Enter the brackets: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        // If opening bracket, push it
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
        }

        // If closing bracket
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            // If stack is empty, no opening bracket exists
            if (top == -1)
            {
                valid = 0;
                break;
            }

            // Check whether brackets match
            if (!isMatching(pop(), str[i]))
            {
                valid = 0;
                break;
            }
        }
    }

    // If anything is left in stack, brackets are unmatched
    if (top != -1)
    {
        valid = 0;
    }

    if (valid)
        printf("True - Valid Parentheses\n");
    else
        printf("False - Invalid Parentheses\n");

    return 0;
}