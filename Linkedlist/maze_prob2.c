#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 6
int a, b;
struct node {
    int r;
    int c;
    struct node *next;
} *start = NULL, *t;
void push(int a, int b) {
    t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Stack Overflow");
    } else {
        t->r = a;
        t->c = b;
        t->next = start;
        start = t;
    }
}
void pop() {
    if (start == NULL) {
        printf("Stack Underflow");
    } else {
        t = start->next;
        start = start->next;
        a = t->r;
        b = t->c;
        free(t);
       // printf("%d %d\n", a, b);
    }
}
void peep() {
    t = start;
    while (t != NULL) {
        printf("(%d, %d) -> ", t->r, t->c);
        t = t->next;
    }
    printf("NULL\n");
}
int solveMaze(int maze[N][N], int x, int y) {
    if (x == N - 1 && y == N - 1) {
        push(x, y);
        return 1;
    }
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        push(x, y);
        if (solveMaze(maze, x + 1, y)) return 1;
        if (solveMaze(maze, x, y + 1)) return 1;
        if (solveMaze(maze, x - 1, y)) return 1;
        if (solveMaze(maze, x, y - 1)) return 1;
        pop();
        maze[x][y] = 0;
    }
}
int maze[6][6]={{1,1,0,0,0,0},{0,1,1,1,0,0},{0,1,0,1,0,0},{0,1,1,1,1,1},{0,0,0,0,0,1},{0,0,0,0,0,1}};
int main(){
    solveMaze(maze, 0, 0);
    struct node *prev, *current, *next;
    prev=NULL;
    current=start;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    start=prev;
    peep();
    return 0;
}
