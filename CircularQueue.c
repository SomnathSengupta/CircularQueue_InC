#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct queue_array{
    int front, rear, arr[max];
}queue;
void insert(queue* qu, int val) {
    if ((qu -> rear + 1) % max == qu -> front)
        printf("Queue is Full.\n");
    else if (qu -> rear == -1 && qu -> front == -1) {
        qu -> rear = qu -> front = 0;
        qu -> arr[qu -> rear] = val;
    }
    else {
        qu -> rear = (qu -> rear + 1) % max;
        qu -> arr[qu -> rear] = val;
        printf("%d successfully inserted.\n", val);
    }
}
void delete(queue* qu) {
    if (qu -> rear == -1 && qu -> front == -1) 
        printf("Queue is empty.\n");
    else if (qu -> rear == qu -> front) 
        qu -> rear = qu -> front = -1;
    else {
        int x = qu -> arr[qu -> front];
        qu -> front = (qu -> front + 1) % max;
        printf("%d successfully deleted.\n", x);
    }
}
void display(queue qu) {
    if (qu.rear == -1 && qu.front == -1) 
        printf("Queue is empty.\n");
    else {
        printf("Displaying...\n");
        if (qu.front < qu.rear) {
            for (int i = qu.front; i <= qu.rear; i++) {
                printf("%d ", qu.arr[i]);
            }
        }
        else {
            for (int i = qu.rear; i <= max - 1; i++)
                printf("%d ", qu.arr[i]);
            for (int i = 0; i <= qu.front; i++)
                printf("%d ", qu.arr[i]);
        }
    }
}
int main()
{
    queue qu;
    qu.front = qu.rear = -1;
    int ch, val;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choise: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter the no you want to insert:");
                scanf("%d", &val);
                insert(&qu, val);
                break;
            case 2:
                delete(&qu);
                break;
            case 3:
                display(qu);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("You have entered wrong value.\n");
                break;
        }
    }
    return 0;
}
    
