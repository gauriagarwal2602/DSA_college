#include <stdio.h>
#include <math.h>
//Find the maximum no. of consecutive ones in a binary array
int Max_ones(int nums[], int len){
    int i, currentcount=0, maxcount=0;
    for(i=0; i<len; i++){
        if(nums[i]==1){
            currentcount++;
        }
        else{
            if(maxcount<currentcount){
                maxcount=currentcount;
            }
            currentcount=0;
        }
    }
    if(currentcount>maxcount){
        maxcount=currentcount;
    }
    return maxcount;
}
int main(){
    int bin[]={1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1};
    int len=20;
    printf("%d", Max_ones(bin,len));
    return 0;
}
//Exchange smallest and largest element in the array
/*int exchange_ele(int arr[], int len){
int i, pos1=0, pos2=0;
int small=arr[0];
int large=arr[0];
for(i=0; i<len; i++){
    if(arr[i]<small){
        small= arr[i];
        pos1=i;
    }
    if(arr[i]>large){
        large=arr[i];
        pos2=i;
    }
}
arr[pos2]=small;
arr[pos1]=large;
for(i=0; i<len; i++){
    printf("%d\t", arr[i]);
}
return 0;
}
int main(){
    int arr1[10];
    int len1, i;
    printf("Enter the number of elements you want to enter for arr1: ");
    scanf("%d", &len1);
    for (i = 0; i < len1; i++) {
        printf("Enter the value for arr1[%d]: ", i + 1);
        scanf("%d", &arr1[i]);
    }  
    exchange_ele(arr1, len1);
    return 0;
}
*/
//Merge two sorted arrays
/*int main() {
    int arr1[10];
    int len1, i, j, k, l;
    printf("Enter the number of elements you want to enter for arr1: ");
    scanf("%d", &len1);
    for (i = 0; i < len1; i++) {
        printf("Enter the value for arr1[%d]: ", i + 1);
        scanf("%d", &arr1[i]);
    }
    int arr2[10];
    int len2;
    printf("Enter the number of elements you want to enter for arr2: ");
    scanf("%d", &len2);
    for (i = 0; i < len2; i++) {
        printf("Enter the value for arr2[%d]: ", i + 1);
        scanf("%d", &arr2[i]);
    }
    int len3 = len1 + len2;
    int m_array[len3];
    i = 0;
    j = 0;
    k = 0;
    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) {
            m_array[k] = arr1[i];
            i++;
        } else {
            m_array[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        m_array[k] = arr1[i];
        i++;
        k++;
    }
    while (j < len2) {
        m_array[k] = arr2[j];
        j++;
        k++;
    }
    printf("Merged array: ");
    for (i = 0; i < len3; i++) {
        printf("%d\t", m_array[i]);
    }
    return 0;
}
*/
//Merge two unsorted arrays
/*int main(){
    int arr1[10];
    int len1, i, j;
    printf("Enter the no. of elements you want to enter: ");
    scanf("%d", &len1);
    for(i=0; i<len1; i++){
        printf("Enter the value arr[%d]", i+1);
        scanf("%d", &arr1[i]);
    }
    int arr2[10];
    int len2;
    printf("Enter the no. of elements you want to enter: ");
    scanf("%d", &len2);
    for(i=0; i<len2; i++){
        printf("Enter the value arr[%d]", i+1);
        scanf("%d", &arr2[i]);
    }
    int len3=len1+len2;
    int merged_array[len3];
    for(i=0; i<len1; i++){
        merged_array[i]=arr1[i];
    }
    for(i=len1, j=0; i<len3&&j<len2; i++, j++){
        merged_array[i]=arr2[j];
    }
    for(i=0; i<len3; i++){
        printf("%d\t", merged_array[i]);
    }
    return 0;
}
*/
//Delete an element
/*int main(){
    int arr[10];
    int len, i;
    printf("Enter the no. of elements you want to enter: ");
    scanf("%d", &len);
    for(i=0; i<len; i++){
        printf("Enter the value arr[%d]", i+1);
        scanf("%d", &arr[i]);
    }
    int ele, pos;
    printf("Enter the element: ");
    scanf("%d",&ele);
    for(i=0; i<len; i++){
        if(arr[i]==ele){
            pos=i;
            break;
        }
    }
    for(i=pos; i<len-1;i++){
        arr[i]=arr[i+1];
    }
    len--;
    for(i=0; i<len; i++){
        printf("%d \t",arr[i]);
    }
    return 0;
}*/
//Insert an element in a sorted array
/*int main(){
    int arr[10];
    int len, i;
    printf("Enter the no. of elements you want to enter: ");
    scanf("%d", &len);
    for(i=0; i<len; i++){
        printf("Enter the value arr[%d]", i+1);
        scanf("%d", &arr[i]);
    }
    int ele, pos;
    printf("Enter the element: ");
    scanf("%d",&ele);
    for(i=0; i<len; i++){
        if(arr[i]>ele){
            pos=i+1;
            break;
        }
    }
    for(i=len; i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=ele;
    len++;
    for(i=0; i<len; i++){
        printf("%d \t",arr[i]);
    }
    return 0;
}
*/
//Insert an element
/*int main(){
    int arr[6];
    int len, i;
    printf("Enter the no. of elements you want to enter: ");
    scanf("%d", &len);
    for(i=0; i<len; i++){
        printf("Enter the value arr[%d]", i+1);
        scanf("%d", &arr[i]);
    }
    int ele, pos;
    printf("Enter the position and element: ");
    scanf("%d %d", &pos, &ele);
    for(i=len; i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=ele;
    len++;
    for(i=0; i<len; i++){
        printf("%d \t",arr[i]);
    }
    return 0;
}
*/
//to read n numbers and construct a number from them
/*int main(){
    int arr[5];
    int num=0, i;
    for(i=0; i<5; i++){
        printf("Enter the value arr[%d]", i+1);
        scanf("%d", &arr[i]);
        num= num*10 + arr[i];
        printf("%d\n", num);
    }
    printf("%d", num);
    return 0;
}
*/
// to find the second largest number
/*int main(){
    int arr[5];
    int i, lar, lar2;
    for(i=0; i<5; i++){
        printf("Enter the value arr[%d]", i+1);
        scanf("%d", &arr[i]);
    }
    lar=arr[0];
    for(i=0; i<5; i++){
        if(arr[i]>lar){
            lar=arr[i];
        }
    }
    lar2=arr[0];
    for(i=0; i<5; i++){
        if(arr[i]!=lar){
            if(arr[i]>lar2){
                lar2=arr[i];
            }
        }
    }
    printf("The largest element is %d \n", lar);
    printf("The second largest element is %d", lar2);

    return 0;
}*/