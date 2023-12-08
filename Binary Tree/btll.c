#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *lc, *rc;
};

struct node *root = NULL;

struct node *BinaryTreeCreation() {
  int data;
  printf("Enter data (or -1 to stop): ");
  scanf("%d", &data);

  if (data == -1) {
    return NULL;
  }

  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->lc = BinaryTreeCreation();
  newNode->rc = BinaryTreeCreation();

  return newNode;
}

void inorder(struct node *t) {
  if (t != NULL) {
    inorder(t->lc);
    printf("%d ", t->data);
    inorder(t->rc);
  }
}

void preorder(struct node *t) {
  if (t != NULL) {
    printf("%d ", t->data);
    preorder(t->lc);
    preorder(t->rc);
  }
}

void postorder(struct node *t) {
  if (t != NULL) {
    postorder(t->lc);
    postorder(t->rc);
    printf("%d ", t->data);
  }
}

int main() {
  int choice;
  do {
    printf("Binary Tree Operations:\n");
    printf("1. Creation\n");
    printf("2. Display(InOrder)\n");
    printf("3. Display(PreOrder)\n");
    printf("4. Display(PostOrder)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        root = BinaryTreeCreation();
        break;
      case 2:
        if (root != NULL) {
          printf("InOrder Traversal: ");
          inorder(root);
          printf("\n");
        } else {
          printf("Tree is empty.\n");
        }
        break;
      case 3:
        if (root != NULL) {
          printf("PreOrder Traversal: ");
          preorder(root);
          printf("\n");
        } else {
          printf("Tree is empty.\n");
        }
        break;
      case 4:
        if (root != NULL) {
          printf("PostOrder Traversal: ");
          postorder(root);
          printf("\n");
        } else {
          printf("Tree is empty.\n");
        }
        break;
      default:
        printf("Invalid entry of choice, try again\n");
        break;
    }
  } while (choice == 1 || (choice >= 2 && choice <= 4));

  return 0;
}
