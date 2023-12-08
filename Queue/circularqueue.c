#include <stdio.h>

#define SIZE 10

int cq[SIZE];
int front = -1, rear = -1;

void insertionCQA(int ele) {
    if ((front == 0 && rear == SIZE - 1) || (front == (rear + 1) % SIZE)) {
        printf("Overflow\n");
    } else if (rear == -1) {
        front = rear = 0;
        cq[rear] = ele;
    } else {
        rear = (rear + 1) % SIZE;
        cq[rear] = ele;
    }
}

void deletionQA() {
    if (front == -1) {
        printf("Underflow\n");
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void print() {
    int i;
    if (front == -1) {
        printf("Underflow\n");
    } else {
        printf("Circular Queue elements: ");
        for (i = front; ; i = (i + 1) % SIZE) {
            printf("%d ", cq[i]);
            if (i == rear) {
                break;
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, ele;
    
    do {
        printf("Circular Queue Operations:\n");
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
                insertionCQA(ele);
                break;
            case 2:
                deletionQA();
                break;
            case 3:
                print();
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
