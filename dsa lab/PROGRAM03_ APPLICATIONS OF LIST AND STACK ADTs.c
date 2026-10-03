#include <stdio.h>
#include <ctype.h>

#define MAX 20

int stack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = x;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

int main()
{
    char exp[MAX];
    char *e;
    int n1, n2, n3, num;

    printf("Enter the expression :: ");
    scanf("%19s", exp);

    e = exp;

    while (*e != '\0')
    {
        if (isdigit((unsigned char)*e))
        {
            num = *e - '0';
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();

            if (n1 == -1 || n2 == -1)
                return 1;

            switch (*e)
            {
                case '+':
                    n3 = n2 + n1;
                    break;

                case '-':
                    n3 = n2 - n1;
                    break;

                case '*':
                    n3 = n2 * n1;
                    break;

                case '/':
                    if (n1 == 0)
                    {
                        printf("Division by zero is not allowed\n");
                        return 1;
                    }
                    n3 = n2 / n1;
                    break;

                default:
                    printf("Invalid operator: %c\n", *e);
                    return 1;
            }

            push(n3);
        }

        e++;
    }

    if (top != 0)
    {
        printf("Invalid expression\n");
        return 1;
    }

    printf("\nThe result of expression %s = %d\n", exp, pop());

    return 0;
}


OUTPUT :

Enter the expression :: 245+*

The result of expression 245+* = 18
