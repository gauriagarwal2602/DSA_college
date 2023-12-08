#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int deque[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insertFront(int ele) {
    if (isFull()) {
        printf("Overflow: Deque is full.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        deque[front] = ele;
        printf("Inserted element %d at the front.\n", ele);
    }
}

void insertRear(int ele) {
    if (isFull()) {
        printf("Overflow: Deque is full.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = ele;
        printf("Inserted element %d at the rear.\n", ele);
    }
}

void deleteFront() {
    if (isEmpty()) {
        printf("Underflow: Deque is empty.\n");
    } else {
        printf("Deleted element %d from the front.\n", deque[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            if (front == MAX_SIZE - 1) {
                front = 0;
            } else {
                front++;
            }
        }
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Underflow: Deque is empty.\n");
    } else {
        printf("Deleted element %d from the rear.\n", deque[rear]);
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        do {
            printf("%d ", deque[i]);
            if (i == rear) {
                break;
            }
            if (i == MAX_SIZE - 1) {
                i = 0;
            } else {
                i++;
            }
        } while (i != front);
        printf("\n");
    }
}

int main() {
    int choice, ele;

    do {
        printf("Input-Restricted Deque Operations:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at the front: ");
                scanf("%d", &ele);
                insertFront(ele);
                break;
            case 2:
                printf("Enter element to insert at the rear: ");
                scanf("%d", &ele);
                insertRear(ele);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
