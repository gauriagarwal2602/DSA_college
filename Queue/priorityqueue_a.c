#include <stdio.h>
int pq[3][4], fr[3][2]={-1};
#define pn 3
#define csize 4
void InsertionPQA(int ele, int prio){
if( fr[prio][0]==(fr[prio][1]+1)%csize){
    printf("Overflow");
}
else if(fr[prio][0]==-1){
    fr[prio][0]=fr[prio][1]=0;
    pq[prio][0]=ele;
}
else{
    fr[prio][1]=(fr[prio][1]+1)%csize;
    pq[prio][fr[prio][1]]=ele;
}
}
void DeletionPQA(){
    int i;
    for(i=0; i<pn; i++){
        if(fr[i][0]!=-1){
        if(fr[1][0]==fr[i][1]){
            printf("%d", pq[i][fr[i][0]]);
            fr[i][0]=fr[i][1]=0;
        }
        else{
            printf("%d", pq[i][fr[i][0]]);
            fr[i][0]=(fr[i][0]+1)%csize;
        }
        break;
        }
    }9
}
void DisplayPQA(){
    int i, j;
    for(i=0; i<pn; i++){
        for(j=0; j<4; j++){
        printf("%d\t",pq[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int choice, ele, prio;
    
    do {
        printf("/n Priority Queue Operations:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert and its priority: ");
                scanf("%d %d", &ele, &prio);
                InsertionPQA(ele, prio);
                break;
            case 2:
                DeletionPQA();
                break;
            case 3:
                DisplayPQA();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

