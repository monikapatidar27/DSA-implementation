#include<iostream>
using namespace std;

void merge(int a[],int low,int mid,int high){
    int n1=mid-low+1,n2=high-mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=a[low+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=a[mid+i+1];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            a[k]=left[i];
            i++;
            k++;
        }
        else{
            a[k]=right[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        a[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=right[j];
        j++;
        k++;
    }
}

void merge_sort(int a[],int l,int r){
    if(r>l){
        int m=l+(r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);

    }
}
void insertion_sort(int arr[],int n){
    
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min_ind=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min_ind])
            min_ind=j;
        swap(a[min_ind],a[i]);
    }
}

void merge_and_sort(int a[],int b[],int m,int n){
    int i=0,j=0;
    while(i<m &&j<n){
        if(a[i]<=b[j]){
            cout<<a[i]<<" ";
            i++;
        }
        else{
            cout<<b[j]<<" ";
            j++;
        }    
    }
    while(i<m){
        cout<<a[i]<<" ";
        i++;
    }
    while(j<n){
        cout<<b[j]<<" ";
        j++;
    }
}

int main(){
    // int arr[5]={10,20,40,20,30};
    // merge(arr,0,2,4);
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }
    // int arr[5]={3,5,1,6,2};
    // merge_sort(arr,0,5);
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }
    // int arr[5]={3,5,1,6,2};
    // insertion_sort(arr,5);
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }
    // int arr[5]={3,5,1,6,2};
    // selection_sort(arr,5);
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }
    int a[5]={1,2,3,4,4};
    int b[4]={2,2,3,4};
    merge_and_sort(a,b,5,4);
    
    return 0;
}