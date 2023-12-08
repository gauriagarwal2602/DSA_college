#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lc, *rc;
}* root = NULL;

void search(struct node *root1, int ele) {
    if (root1 == NULL) {
        printf("Not Found\n");
    }
    else if (ele == root1->data) {
        printf("Found\n");
    }
    else if (ele > root1->data) {
        search(root1->rc, ele);
    }
    else if (ele < root1->data) {
        search(root1->lc, ele);
    }
}

struct node* insertion(struct node* root1, int ele) {
    if (root1 == NULL) {
        struct node *t = (struct node*)malloc(sizeof(struct node));
        t->data = ele;
        t->lc = t->rc = NULL;
        return t;
    }
    else if (ele > root1->data) {
        root1->rc = insertion(root1->rc, ele);
    }
    else if (ele < root1->data) {
        root1->lc = insertion(root1->lc, ele);
    }

    return root1;
}
struct node* minvalue(struct node* t) {
    while (t->lc != NULL) {
        t = t->lc;
    }
    return t;
}

struct node* deletion(struct node* root1, int ele) {
    if (root1 == NULL)
        return root1;

    if (ele > root1->data)
        root1->rc = deletion(root1->rc, ele);
    else if (ele < root1->data)
        root1->lc = deletion(root1->lc, ele);
    else {
        if (root1->lc == NULL) {
            struct node *temp = root1->rc;
            free(root1);
            return temp;
        }
        else if (root1->rc == NULL) {
            struct node *temp = root1->lc;
            free(root1);
            return temp;
        }

        struct node *temp = minvalue(root1->rc);
        root1->data = temp->data;
        root1->rc = deletion(root1->rc, temp->data);
    }

    return root1;
}



void inorder(struct node* t) {
    if (t != NULL) {
        inorder(t->lc);
        printf("%d ", t->data);
        inorder(t->rc);
    }
}

void preorder(struct node* t) {
    if (t != NULL) {
        printf("%d ", t->data);
        preorder(t->lc);
        preorder(t->rc);
    }
}

void postorder(struct node* t) {
    if (t != NULL) {
        postorder(t->lc);
        postorder(t->rc);
        printf("%d ", t->data);
    }
}

int main() {
    int choice, ele; 
    do {
        printf("Binary Search Tree by linked list operations:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. Inorder\n");
        printf("6. Search\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                root = insertion(root, ele);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &ele);
                root = deletion(root, ele);
                break;
            case 3:
                if (root != NULL) {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 4:
                if (root != NULL) {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 5:
                if (root != NULL) {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 6:
                printf("Enter the element to search: ");
                scanf("%d", &ele);
                search(root, ele);
                break;
            default:
                printf("Enter a valid option. Try again.\n");
        }
    } while (choice == 1 || choice == 2 || choice == 3 || choice == 4|| choice == 5|| choice == 6);


    return 0;
}