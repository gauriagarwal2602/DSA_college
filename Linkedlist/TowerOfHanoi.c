#include <stdio.h>
void TOH(int n, char S, char M, char D){
    if(n==0){
        printf("Move disk %d from %c to %c \n", n, S, D);
    }
    else{
        TOH((n-1), S,D,M);
        printf("Move disk %d from %c to %c \n", n,S,D);
        TOH((n-1),M,S,D);
    }
}
int main(){
    int num;
    printf("Enter the number of disk present: ");
    scanf("%d",&num);
    char S='S', M='M', D='D';
    TOH(num,S,M,D);
    return 0;
}