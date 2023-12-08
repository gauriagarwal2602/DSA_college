#include <stdio.h>
int factail(int n, int a){
    printf("%d %d \n", n, a);
    if(n==0||n==1){
        return a;
    }
    else{
        return(factail(n-1, n*a));
    }
}

int main(){
    int result= factail(5,1);
    printf("%d", result);
    return 0;
}