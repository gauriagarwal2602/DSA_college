#include <stdio.h>

int BTree[50], size = 50;

void BTCreation(int i) {
    int data;
    printf("Enter the following data, otherwise -1\n");
    scanf("%d", &data);
    if (data != -1 && i < size) {
        BTree[i] = data;
        printf("Enter the left child of %d\n", BTree[i]);
        BTCreation(2 * i + 1);
        printf("Enter the right child of %d\n", BTree[i]);
        BTCreation(2 * i + 2);
    }
}

void traversal_inorder(int i) {
    if (i < size && BTree[i] != -1) {
        traversal_inorder(2 * i + 1);
        printf("%d-", BTree[i]);
        traversal_inorder(2 * i + 2);
    }
}

void traversal_preorder(int i) {
    if (i < size && BTree[i] != -1) {
        printf("%d-", BTree[i]);
        traversal_preorder(2 * i + 1);
        traversal_preorder(2 * i + 2);
    }
}

void traversal_postorder(int i) {
    if (i < size && BTree[i] != -1) {
        traversal_postorder(2 * i + 1);
        traversal_postorder(2 * i + 2);
        printf("%d-", BTree[i]);
    }
}

int main() {
    int choice, index;
    for (int i = 0; i < size; i++) {
        BTree[i] = -1;
    }
    do {
        printf("Binary Tree by array operations:\n");
        printf("1. Creation\n");
        printf("2. Traversal(inorder)\n");
        printf("3. Traversal(preorder)\n");
        printf("4. Traversal(postorder)\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the index of the data:");
                scanf("%d", &index);
                BTCreation(index);
                break;
            case 2:
                printf("Inorder Traversal: ");
                traversal_inorder(0);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                traversal_preorder(0);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                traversal_postorder(0);
                printf("\n");
                break;
            default:
                printf("Enter a valid option. Exiting the program.\n");
                return 0;
        }
    } while (choice == 1 || choice == 2 || choice == 3 || choice == 4);

    return 0;
}
