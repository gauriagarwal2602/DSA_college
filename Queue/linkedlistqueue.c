#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *ptr;
};

struct node *front = NULL;
struct node *rear = NULL;

void insertionQLL(int ele) {
    struct node *t = malloc(sizeof(struct node));
    if (t != NULL) {
        t->data = ele;
        t->ptr = NULL;
        if (rear == NULL) {
            front = rear = t;
        } else {
            rear->ptr = t;
            rear = t;
        }
    } else {
        printf("Memory allocation failed. Queue is full.\n");
    }
}

void deletionQLL() {
    struct node *t;
    if (front == NULL) {
        printf("Underflow\n");
    } else if (front == rear) {
        t = front;
        front = rear = NULL;
        free(t);
    } else {
        t = front;
        front = front->ptr;
        free(t);
    }
}

void printQLL() {
    struct node *t;
    printf("Linked List Queue elements: ");
    for (t = front; t != NULL; t = t->ptr) {
        printf("%d ", t->data);
    }
    printf("\n");
}

int main() {
    int choice, ele;
    
    do {
        printf("Linked List Queue Operations:\n");
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
                insertionQLL(ele);
                break;
            case 2:
                deletionQLL();
                break;
            case 3:
                printQLL();
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
