#include <iostream>
int main(){
    int num;
    bool prime= true;
    std::cout<<"Enter a number to check if it is a prime number or not : \n";
    std::cin>>num;
    if (num<=0){
        std::cout<<"Number given is negative or zero";
    }
    for(int i=2; i<=num/2; i++){
        if(num%i==0){
            prime=false;
            break;
        }
    }

    if(prime){
        std::cout<<"This is a prime number";
    }
    else {
        std::cout<<"This is not a prime number";
    }
    return 0;
}