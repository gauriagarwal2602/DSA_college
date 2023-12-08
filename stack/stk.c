/*#include <stdio.h>
#include <stdlib.h>
int stack[5];
int tos=-1;
void push(int ele){
    if(tos==4){
        printf("StackOverflow\n");
    }
    else{
        stack[++tos]=ele;
    }
}

int pop(){
    if(tos==-1){
        printf("Stack Underflow");
        exit(-1);
    }
    else{
        return stack[tos--];
    }
}

void display(){
    for(int i=0; i<10; i++){
        printf("%d\t", stack[i]);
    }
}

int main(){
    int choice;
    int element;
    do{
        printf("Enter the choice: \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter the element\n");
            scanf("%d", &element);
            push(element);
            break;
            case 2:
            element=pop();
            printf("%d", element);
            break;
            case 3:
            printf("The elements are: ");
            display();
            printf("\n");
            break;
            default:
            printf("Exiting the stack");
        }}while((choice==1)||(choice==2)||(choice==3));

    
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
struct stack{
    int data;
    struct stack* next;
} *top=NULL, *r;
typedef struct stack stack;
int element;
void push(int ele){
    stack* t;
    t= (stack*)malloc(sizeof(stack));
    if(t==NULL){
        printf("Stack Overflow");
    }
    else{
        t->data=ele;
        t->next=top;
        top=t;
    }
}
int pop(){
    stack* temp;
    temp= (stack*)malloc(sizeof(stack));
    if(top==NULL){
        printf("Stack Underflow");
    }
    else{
        temp=top;
        element=top->data;
        top= top->next;
        free(temp);
        return element;
    }
}
void peep(){
    stack *t1;
    t1= (stack*)malloc(sizeof(stack*));
    for(t1=top; t1!=NULL; t1=t1->next){
        printf("%d\t", t1->data);
    }
}
r=top;
void reverse(stack* r){
    if(r->next==NULL){
        printf("%d\t", r->data);
    }
    else{
        reverse(r->next);
    }

}
int main(){
    int choice;
    int element;
    do{
        printf("Enter the choice: \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Reverse\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter the element\n");
            scanf("%d", &element);
            push(element);
            break;
            case 2:
            element=pop();
            printf("%d", element);
            break;
            case 3:
            printf("The elements are: ");
            peep();
            printf("\n");
            break;
            case 4:
            reverse(stack *r);
            default:
            printf("Exiting the stack");
        }}while((choice==1)||(choice==2)||(choice==3)||(choice==4));

    
    return 0;
}
