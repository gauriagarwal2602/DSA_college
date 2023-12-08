#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
int main(){
    int value, choice;
    struct node* start, *new_node, *ptr;
    start= NULL;
    int num, i, count, len;
    len=0;
    int pos, ele, temp;
    struct node *t, *t1;
    printf("Enter corresponding number for the following operations:- \n");
    printf("Enter 10 to exit\n");
    printf("1-> Creation \n");
    printf("2-> Display \n");
    printf("3-> Insertion\n");
    printf("4-> Deletion\n");
    scanf("%d", &choice);
    do{
        switch(choice){
            case 1:
            printf("Enter -1 to end\n");
            printf("Enter the value:- ");
            scanf("%d", &value);
            while(value!=-1){
                new_node=(struct node*)malloc(sizeof(struct node));
                new_node->data=value;
                new_node->next=NULL;
                if(start==NULL){
                    start=new_node;
                    new_node->prev=NULL;
                    new_node->next=NULL;
                }
                else {
                    for(ptr=start; ptr->next!=NULL; ptr=ptr->next);
                    ptr->next=new_node;
                    new_node->prev=ptr;
                    new_node->next=NULL;
                }
                printf("Enter -1 to end\n");
            printf("Enter the value:- ");
            scanf("%d", &value);
            

            }
            break;
            case 2:
            for(ptr=start; ptr!=NULL; ptr=ptr->next){
                printf("%d \t", ptr->data);
            }
            break;
            case 3:
            break;
            case 4:
            break;
            default: 
            printf("Try again. If you want to exit enter 8\n");
        }
    }while(choice!=10);
    return 0;
}