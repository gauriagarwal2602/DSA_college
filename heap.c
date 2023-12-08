#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_SIZE 100
int a[MAX_HEAP_SIZE];
int n = 0; 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxHeapifyUp(int ele) {
    int ptr = n;
    while (ptr > 0) {
        int par = (ptr - 1) / 2;
        if (ele <= a[par]) {
            a[ptr] = ele;
            return;
        }
        a[ptr] = a[par];
        ptr = par;
    }
    a[ptr] = ele;
}
void insertElement(int ele) {
    if (n == MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }
    n++;
    maxHeapifyUp(ele);
    printf("Element %d has been inserted into the heap.\n", ele);
}


void maxHeapifyDown(int ele) {
    int ptr = 0;
    int left = 1;
    int right = 2;

    while (right <= n) {
        if (ele >= a[left] && ele >= a[right]) {
            a[ptr] = ele;
            return;
        } else if (a[left] < a[right]) {
            a[ptr] = a[right];
            ptr = right;
        } else {
            a[ptr] = a[left];
            ptr = left;
        }
        left = 2 * ptr + 1;
        right = left + 1;
    }

    if (left == n && ele <= a[left]) {
        a[ptr] = ele;
    } else {
        a[ptr] = a[left];
        a[left] = ele;
    }
}

void deleteMax() {
    if (n == 0) {
        printf("Heap is empty. Cannot delete.\n");
        return;
    }
    int ele = a[n];
    n--;
    maxHeapifyDown(ele);
    printf("Maximum element %d has been deleted from the heap.\n", ele);
}

void printHeap() {
    if (n == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Max Heap Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("\nMax Heap Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Print Heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertElement(element);
                break;
            case 2:
                deleteMax();
                break;
            case 3:
                printHeap();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
