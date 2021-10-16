#include <iostream>
using namespace std;
  
template <typename T>
class Array{
    T *arr;
    int size;
    int capacity;
public:
    Array(int cap){
        this->capacity=cap;
        this->size=0;
        arr=new T[this->capacity];
    }

    Array(int cap,T val){
        this->capacity=cap;
        this->size=cap;
        arr=new T[this-capacity];
        for(int i=0;i<this->capacity;i++){
            this->arr[i]=val;
        }
    }

    Array(int cap,T value[]){
        this->capacity=cap;
        this->size=cap;
        arr=new T[this->size];
        for(int i=0;i<this->capacity;i++){
            this->arr[i]=value[i];

        }
    }

    //capacity
    int Capacity(){
        return this->capacity;
    }
    //size
    int Size(){
        return this->size;
    }
    //print array
    void display(){
        for(int i=0;i<this->size;i++){
            cout<<this->arr[i]<<" ";                                                                                                    
        }
    }
    //append
    void append(T x){
        if(this->size == this->capacity){
            return ;
        }
       arr[this->size]=x;
       this->size++;

    }
    //sort the array
    void bubbleSort()
    {
        for (int i = 0; i < this->size; i++){
            for (int j = 0; j<this->size-i-1; j++){
                if (this->arr[j] > this->arr[j + 1]){
                    swap(this->arr[j], this->arr[j + 1]);
                }    
            }  
        }  
    }
    // n maximum elements
    void bubbleSort(int n)
    {
        if(n>this->size){
            return;
        }    
        for (int i = 0; i < n; i++){
            for (int j = 0; j<this->size-i-1; j++){
                if (this->arr[j] > this->arr[j + 1]){
                    swap(this->arr[j], this->arr[j + 1]);
                }    
            }  
        }  
    }
    // selection sort
    void selectionSort(){
        int i ,j,min,temp;
        for(i=0;i<this->size-1;i++){
            min=i;
            for(j=i+1;j<this->size;j++){
                if(this->arr[j]<this->arr[min]){
                    min=j;
                }
            }
                temp=this->arr[min];
                this->arr[min]=this->arr[i];
                this->arr[i]=temp;       
        }
    }

    //n minimum 
    void selectionSort(int n){
        int i ,j,min,temp;
        if(n>this->size){
            return;
        } 
        for(i=0;i<n;i++){
            min=i;
            for(j=i+1;j<this->size;j++){
                if(this->arr[j]<this->arr[min]){
                    min=j;
                }
            }
                temp=this->arr[min];
                this->arr[min]=this->arr[i];
                this->arr[i]=temp;       
        }
    }

    //insert
    void insert(T x,int pos){
        if(this->size==this->capacity){
            return ;
        }
        if(pos>=this->capacity){
            return;
        }
        for(int i=this->size;i>pos-1;i--){
            this->arr[i]=this->arr[i-1];
        }
            this->arr[pos-1]=x;
          
        this->size++;       
    }

    //reverse
    void revereseArray()
    {

        int start=0,end=this->size-1;
        while (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
   
    }
    //delete
    int deletElement(T x){
       int i=search(x);
	    // for(i;i<this->size;i++){
		//     if(this->arr[i]==x)
        //         break;
	    // }

	    if(i==-1){
		    return this->size;
	    }
	    for(i;i<this->size-1;i++){
		    this->arr[i]=this->arr[i+1];
	    }
        this->size--;
	        return this->size;
    
    }
    //deleteall element
    int deleteAll(){
        this->size=0;
        return this->size;
    }

    //search
    int search(T x){
        for(int i=0;i<this->size;i++){
            if(this->arr[i]==x){
                return i;
            }
        }
        return -1;
    }

};
int main()
{
    int arr[5] = { 3, 8, 12, 5, 6 };
    Array<int> num(5,arr);

    num.display();
    cout<<endl;
    cout<<num.Size()<<endl;
    // num.bubbleSort(2);
    // num.revereseArray();
    // num.deletElement(3);
    // num.bubbleSort();
    // cout<<num.search(2)<<endl;
    // cout<<num.deleteAll();
    // num.selectionSort();
    num.selectionSort(4);
    // num.insert(9,1);
    // num.append(1);
    num.display(); 
    cout<<endl;    
    cout<<num.Capacity()<<endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

}