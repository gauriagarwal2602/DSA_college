#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
int main(){
    int value, choice;
    struct node* start, *new_node, *ptr;
    start= NULL;
    int num, i, count, len, frequency;
    len=0;
    int pos, ele, temp;
    struct node *t, *t1, *min, *max;
    printf("Enter corresponding number for the following operations:- \n");
    printf("Enter 11 to exit\n");
    printf("1-> Creation \n");
    printf("2-> Display \n");
    printf("3-> Insertion\n");
    printf("4-> Deletion\n");
    printf("5-> Search an element\n");
    printf("6-> Reverse the list\n");
    printf("7-> Print the mid element of the linked list\n");
    printf("8-> Find the length of the given linked list\n");
    printf("9-> Sort the given linked list\n");
    printf("10-> Remove duplicates from the given linked list \n");
    scanf("%d", &choice);
    do{
        struct node*prev, *current, *next;
        switch(choice){
            int flag;
            flag=0;
            count=0;
            case 1:
            printf("Enter -1 to end\n");
            printf("Enter the value:- ");
            scanf("%d", &value);
            while(value!=-1){
                new_node= (struct node *)malloc(sizeof(struct node));
                new_node->data= value;
                new_node->next= NULL;
                if(start==NULL){
                    start= new_node;
                }
                else{
                    ptr=start;
                    while(ptr->next!=NULL){
                        ptr= ptr->next;
                    }
                    ptr->next=new_node;
                }
                printf("Enter -1 to end\n");
            printf("Enter the value:- ");
            scanf("%d", &value);
            }
            break;
            case 2:
            max=min=ptr=start;
            for(;ptr!=NULL;ptr=ptr->next){
                printf("%d \t", ptr->data);
                if (min->data > ptr->data){
                    min=ptr;
                }    
                if(max->data< ptr->data){
                    max=ptr;
                }
            }
            printf("The maximum element is %d \n",max->data);
            printf("The minimum element is %d \n", min->data);
            break;
            case 3:
            t= (struct node*)malloc(sizeof(struct node));
            printf("Enter the value and the pos:- ");
            scanf("%d %d", &num, &pos);
            t->data=num;
            t->next= NULL;
            if(pos==1){
                t->next=start;
                start=t;
            }
            else{
                t1=start;
                for(i=1; i<pos-1 && t1->next!=NULL; i++){
                    t1=t1->next;

                }
                t->next=t1->next;
                t1->next=t;
            }
            break;
            case 4:
            printf("Enter the position of the element:- ");
            scanf("%d", &pos);
            if(pos<=0){
                printf("Invalid entry of position, try again \n");
            }
            else if(pos==1){
                t1=start;
                start=start->next;
                free(t1);
            }
            else if(start==NULL){
                printf("The list is empty, first create a linked list\n");
            }
            else{
                t1=t=start;
                for(i=1; i<pos; i++){
                    t=t1;
                    t1=t1->next;
                }
                if(t1==NULL){
                    flag=1;
                }
                if(flag!=1){
                    t->next=t1->next;
                    free(t1);
                }
                else if(flag==1){
                    printf("The position is not valid. Try again\n");
                }

            }
            break;
            case 5:
            printf("Enter the element to be found:- ");
            scanf("%d", &ele);
            t=start;
            count=0;
            for(i=1; t !=NULL; i++){
                if(t->data==ele){
                    printf("%d element is found on %d position.\n", ele, i);
                    count++;
                }
                t=t->next;
            }
            printf("%d element occurs %d times in the given linked list", ele, count);
            break;
            case 6: 
            prev=NULL;
            current=start;
            while(current!=NULL){
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
            }
            start=prev;
            break;
            case 7:
            t1= start;
            t= start;
            while(t1!=NULL && t1->next!=NULL){
                t1=t1->next->next;
                current=t;
                t=t->next;
            }
            if(t1==NULL){
                printf("The middle elements are:- %d and %d.",current->data, current->next->data );
            }
            else{
                printf("The middle element is:- %d.",t->data);
            }
            break;
            case 8: 
            ptr= start;
            while(ptr!=NULL){
                ++len;
                ptr=ptr->next;
            }
            printf("The length of this linked list is %d", len);
            break;
            case 9:
            t=start;
            while(t->next!=NULL){
                t1= t->next;
                while(t1!=NULL){
                    if(t->data > t1->data){
                        temp= t->data;
                        t->data= t1->data;
                        t1->data= temp;
                    }
                    t1= t1->next;
                }
                t=t->next;
            }
            break;
            case 10:
            t=start;
            while(t!=NULL){
                ptr=t;
                t1= t->next;
                while(t1!=NULL){
                    if(t->data==t1->data){
                        current=t1;
                        ptr->next=t1->next;
                        free(current);}
                    ptr=t1;
                    t1=t1->next;
                }
            t=t->next;
            }
            break;
            default: 
            printf("Try again. If you want to exit enter 11\n");
        }
        printf("\nEnter corresponding number for the following operations:- \n");
        printf("Enter 11 to exit\n");
        printf("1-> Creation \n");
        printf("2-> Display \n");
        printf("3-> insertion\n");
        printf("4-> Deletion\n");
        printf("5-> Search an element\n");
        printf("6-> Reverse the list\n");
        printf("7-> Print the mid element of the linked list\n");
        printf("8-> Find the length of the given linked list\n");
        printf("9-> Sort the given linked list\n");
        printf("10-> Remove duplicates from the given linked list ");
        scanf("%d", &choice);
        
    }while(choice!=11);
    return 0;
}