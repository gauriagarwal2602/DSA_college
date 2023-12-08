#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lc, *rc;
    int ht;
};
int height(struct node *t)
{
    if (t == NULL)
        return 0;
    else
    {
        int lh, rh;
        lh = height(t->lc);
        rh = height(t->rc);
        if (lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
    }
}

int balfact(struct node *t)
{
    int lh, rh;
    if (t == NULL)
        return 0;
    if (t->lc == NULL)
        lh = 0;
    else
        lh = t->lc->ht;
    if (t->rc == NULL)
        rh = 0;
    else
        rh = t->rc->ht;
    return (lh - rh);
}

struct node *LeftRotate(struct node *a)
{
    struct node *b = a->rc;
    a->rc = b->lc;
    b->lc = a;
    a->ht = height(a);
    b->ht = height(b);
    return b;
}
struct node *RightRotate(struct node *a)
{
    struct node *b = a->lc;
    a->lc = b->rc;
    b->rc = a;
    a->ht = height(a);
    b->ht = height(b);
    return b;
}
struct node *LRrotation(struct node *t)
{
    t->lc = LeftRotate(t->lc);
    t = RightRotate(t);
    return t;
}

struct node *RLrotation(struct node *t)
{
    t->rc = RightRotate(t->rc);
    t = LeftRotate(t);
    return t;
}

struct node *LLrotation(struct node *t)
{
    t = RightRotate(t);
    return t;
}

struct node *RRrotation(struct node *t)
{
    t = LeftRotate(t);
    return t;
}

struct node *insertion(struct node *t, int ele)
{
    if (t == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = ele;
        t->lc = t->rc = NULL;
    }
    else if (ele > t->data)
    {
        t->rc = insertion(t->rc, ele);
        if (balfact(t) == -2)
        {
            if (ele > t->rc->data)
                t = RRrotation(t);
            else
                t = RLrotation(t);
        }
    }
    else if (ele < t->data)
    {
        t->lc = insertion(t->lc, ele);
        if (balfact(t) == 2)
        {
            if (ele < t->lc->data)
                t = LLrotation(t);
            else
                t = LRrotation(t);
        }
    }
    t->ht = height(t);
    return t;
}

struct node *findMin(struct node *t)
{
    if (t == NULL)
        return NULL;
    while (t->lc != NULL)
        t = t->lc;
    return t;
}
struct node *deletion(struct node *t, int ele)
{
    if (t == NULL)
    {
        printf("Not Found!\n");
        return NULL;
    }

    if (ele > t->data)
    {
        t->rc = deletion(t->rc, ele);
        if (balfact(t) == 2)
        {
            if (balfact(t->lc) >= 0)
                t = LLrotation(t);
            else
                t = LRrotation(t);
        }
    }
    else if (ele < t->data)
    {
        t->lc = deletion(t->lc, ele);
        if (balfact(t) == -2)
        {
            if (balfact(t->rc) <= 0)
                t = RRrotation(t);
            else
                t = RLrotation(t);
        }
    }
    else
    {
        if (t->rc != NULL)
        {
            struct node *temp = findMin(t->rc);
            t->data = temp->data;
            t->rc = deletion(t->rc, temp->data);
            if (balfact(t) == 2)
            {
                if (balfact(t->lc) >= 0)
                    t = LLrotation(t);
                else
                    t = LRrotation(t);
            }
        }
        else
        {
            t = t->lc;
        }
    }
    t->ht = height(t);
    return t;
}

void inorder(struct node *t)
{
    if (t == NULL)
        return;
    inorder(t->lc);
    printf("%d ", t->data);
    inorder(t->rc);
}

int main()
{
    struct node *root = NULL;
    int choice, element;

    while (1)
    {
        printf("\nAVL Tree Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Print In-Order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            root = insertion(root, element);
            break;
        case 2:
            printf("Enter element to delete: ");
            scanf("%d", &element);
            root = deletion(root, element);
            break;
        case 3:
            printf("In-Order Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
