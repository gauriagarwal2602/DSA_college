#include <stdio.h>

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void insertionQA(int ele) {
    if (rear == SIZE - 1) {
        printf("Overflow\n");
    } else if (rear == -1) {
        rear = front = 0;
        queue[rear] = ele;
    } else {
        rear = rear + 1;
        queue[rear] = ele;
    }
}

int deletionQA() {
    int ele;
    if (front == -1) {
        printf("Underflow\n");
        return -1;
    } else if (front == rear) {
        ele = queue[front];
        front = rear = -1;
        return ele;
    } else {
        ele = queue[front];
        front = front + 1;
        return ele;
    }
}

void printQA() {
    int i;
    if (front == -1) {
        printf("Underflow\n");
    } else {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, ele;
    
    do {
        printf("Queue Operations:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                insertionQA(ele);
                break;
            case 2:
                ele = deletionQA();
                if (ele != -1) {
                    printf("Deleted element: %d\n", ele);
                }
                break;
            case 3:
                printf("Queue elements: ");
                printQA();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
