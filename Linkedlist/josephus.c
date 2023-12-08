#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int josephus(int n, int k) {
    struct Node* head = createNode(1);
    struct Node* prev = head;
    
    // Create the circular linked list of n nodes.
    for (int i = 2; i <= n; i++) {
        prev->next = createNode(i);
        prev = prev->next;
    }
    prev->next = head; // Make the linked list circular.
    
    struct Node* current = head;
    struct Node* previous = prev;
    
    while (current->next != current) {
        int count = 1;
        while (count != k) {
            previous = current;
            current = current->next;
            count++;
        }
        
        previous->next = current->next;
        free(current);
        current = previous->next;
    }
    
    int survivor = current->data;
    free(current);
    
    return survivor;
}

int main() {
    int n, k;
    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the counting interval (k): ");
    scanf("%d", &k);
    
    int survivor = josephus(n, k);
    printf("The survivor's position is: %d\n", survivor);
    
    return 0;
}
