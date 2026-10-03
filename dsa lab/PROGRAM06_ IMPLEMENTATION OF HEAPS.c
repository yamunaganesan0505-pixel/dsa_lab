#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

/* Insert an element into Max Heap */
void insert(int element)
{
    int current;
    int temp;

    if (size >= MAX)
    {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = element;
    current = size;

    while (current > 0 &&
           heap[current] > heap[(current - 1) / 2])
    {
        temp = heap[current];
        heap[current] = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = temp;

        current = (current - 1) / 2;
    }

    size++;
}

/* Restore Max Heap property */
void heapify_down(int current)
{
    int largest;
    int left;
    int right;
    int temp;

    largest = current;
    left = 2 * current + 1;
    right = 2 * current + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != current)
    {
        temp = heap[current];
        heap[current] = heap[largest];
        heap[largest] = temp;

        heapify_down(largest);
    }
}

/* Delete root element */
void deleteRoot()
{
    if (size <= 0)
    {
        printf("Heap Underflow\n");
        return;
    }

    heap[0] = heap[size - 1];
    size--;

    if (size > 0)
        heapify_down(0);
}

/* Display heap */
void display()
{
    int i;

    if (size == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    for (i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");
}

int main()
{
    int choice;
    int element;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert(element);
                break;

            case 2:
                deleteRoot();
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


OUTPUT : 


1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 50

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 30

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 20

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 15

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
50 30 20 15

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 2

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
30 15 20

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 4
