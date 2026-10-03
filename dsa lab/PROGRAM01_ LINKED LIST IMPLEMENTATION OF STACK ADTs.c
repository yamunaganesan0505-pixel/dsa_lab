#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
} *top, *top1, *temp;

int count = 0;

int topelement();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();

int main()
{
    int no, ch;

    printf("\n 1- Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Top");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    printf("\n 7 - Stack Count");
    printf("\n 8 - Destroy stack");

    while (1)
    {
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d", &no);
                push(no);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Top element : %d", topelement());
                break;

            case 4:
                empty();
                break;

            case 5:
                exit(0);

            case 6:
                display();
                break;

            case 7:
                stack_count();
                break;

            case 8:
                destroy();
                break;

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}

void push(int data)
{
    if (top == NULL)
    {
        top = (struct node *)malloc(sizeof(struct node));

        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));

        temp->ptr = top;
        temp->info = data;
        top = temp;
    }

    count++;
}

void display()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack is empty");
        return;
    }

    printf("\n");

    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("\nStack is empty");
        return;
    }

    temp = top;
    printf("\nPopped value : %d", temp->info);

    top = top->ptr;
    free(temp);

    count--;
}

int topelement()
{
    if (top == NULL)
    {
        printf("\nStack is empty");
        return -1;
    }

    return top->info;
}

void empty()
{
    if (top == NULL)
        printf("\nStack is empty");
    else
        printf("\nStack is not empty");
}

void destroy()
{
    while (top != NULL)
    {
        temp = top;
        top = top->ptr;
        free(temp);
    }

    count = 0;
    printf("\nAll stack elements destroyed");
}

void stack_count()
{
    printf("\nNo. of elements in stack : %d", count);
}



OUTPUT : 

1- Push
2 - Pop
3 - Top
4 - Empty
5 - Exit
6 - Display
7 - Stack Count
8 - Destroy stack

Enter choice : 1
Enter data : 56

Enter choice : 1
Enter data : 80

Enter choice : 2
Popped value : 80

Enter choice : 3
Top element : 56

Enter choice : 1
Enter data : 78

Enter choice : 1
Enter data : 90

Enter choice : 6
90 78 56

Enter choice : 7
No. of elements in stack : 3

Enter choice : 8
All stack elements destroyed

Enter choice : 4
Stack is empty

Enter choice : 5S
