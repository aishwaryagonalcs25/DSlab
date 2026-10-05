#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Push operation
void push()
{
    int item;

    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &item);

        top++;
        stack[top] = item;

        printf("Element pushed successfully\n");
    }
}

// Pop operation
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

// Display operation
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}