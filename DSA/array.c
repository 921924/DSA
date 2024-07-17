#include<stdio.h>
int main(){
    int K=3, i=0;
    int n=10;
    int arr[7]={ 1,2,3,4,5,6,7 };
    int temp[7];
    for(K=1;K<4;K++)
    {
    for(i=0; i<7; i++)
    {
        temp[(i+K)%n]=arr[i];
    }
    for(i=1; i<=7; i++)
    {
        printf("%d ",temp[i]);
    }
    }
}