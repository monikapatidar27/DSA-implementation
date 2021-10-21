#include<iostream>
using namespace std;

int main(){
    int num=12;
    int pos=-1;
    //linear search
    int arr[5]={10,23,4,67,2};
    for(int i=0;i<5;i++){
        if(arr[i]==num){
            pos=i;
            break;
        }
    }
    //binary search
    int a[5]={1,2,3,4,5};
    int low=0;
    int high=4;
    while(low <= high){
        int mid=(low+high)/2;
        if(mid==num){
            pos=mid;
            break;
        }
        else if(num>a[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<a[pos]<<" num is at index "<<pos;
    return 0;
}