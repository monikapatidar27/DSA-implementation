#include <iostream>
using namespace std;
  
template <typename T>
class Myvector{
    int size;
    int mxsize;
    int *arr;
    
    public:
    Myvector(){
        this->mxsize=5;
        this->arr=new int[this->mxsize];
        this->size=0;
        for(int i=0;i<this->mxsize;i++){
            arr[i]=char(0);
        }
    }

    Myvector(int n){
        this->mxsize=n;
        this->arr=new int[this->mxsize];
        this->size=0;
        for(int i=0;i<this->mxsize;i++){
            this->arr[i]=char(0);
        }
    }
    Myvector(int n,T val){
        this->mxsize=n;
        this->arr=new int[this->mxsize];
        this->size=n;
        for(int i=0;i<this->mxsize;i++){
            this->arr[i]=val;
        }
    }
    //print element
    void display(){
        for(int i=0;i<this->size;i++){
            cout<<this->arr[i]<<" ";
        }
        cout<<endl;
    }
    //maxsize
    int maxsize(){
        return this->mxsize;
    }
    //size
    int Size(){
        return this->size;
    }
    //back
    T back(){
        return this->arr[this->size-1];
    }
    //clean
    void clean(){
        for(int i=0;i<this->size;i++){
            this->arr[i]=char(0);
        }
        cout<<endl;
    }
    //erase
    void erase(int ind){
        for(int i=ind;i<this->size-1;i++){
            this->arr[i]=this->arr[i+1];
        }
        this->arr[size-1]=char(0);
        this->size--;
    }
    //delete all
    int deleteAll(){
        this->mxsize=0;
        return this->mxsize;
    }
    //check vector is empty or not
    bool empty(){
        if(this->size==0){
            return true;
        }
        return false;
    }
    //pop_back remove from last
    void pop_back(){
        if(size==0){
            return;
        }
        this->arr[size-1]=char(0);
        this->size--;
    }

    //reverse
    void reverse()
    {

        int start=0,end=this->mxsize-1;
        while (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
   
    }
    // insert()
    void insert(T val,int ind){
        if(this->size >= this->mxsize){
            int oldsize=this->mxsize;
            this->mxsize*=2;
            int oldArr[oldsize];
            for(int i=0;i<oldsize;i++){
                oldArr[i]=this->arr[i];
            }
            this->arr=new T[mxsize];
            for(int i=0;i<oldsize;i++){
                this->arr[i]=oldArr[i];
            }
        }
        for(int i=size;i>ind;i--){
            this->arr[i]=this->arr[i-1];
        }
        this->arr[ind]=val;
        this->size++;
    }
    // pushBack() add at last
    void pushBack(T val){
        if(this->size >= this->mxsize ){
            int oldsize=this->mxsize;
            this->mxsize*=2;
            int oldArr[oldsize];
            for(int i=0;i<oldsize;i++){
                oldArr[i]=this->arr[i];
            }
            this->arr=new T[mxsize];
            for(int i=0;i<oldsize;i++){
                this->arr[i]=oldArr[i];
            }
        }
        this->arr[this->size]=val;
        size++;
    }
};

int main(){

   // Myvector<int>mv(7,4);
    Myvector<int>mv;
    mv.pushBack(5);
    mv.pushBack(3);
    mv.pushBack(8);
    mv.pushBack(4);
    mv.pushBack(1);
    mv.display();
    // cout<<"Size is "<<mv.Size();
    // cout<<endl;
    // mv.pop_back();
    // mv.reverse();
    // mv.display();
    cout<<"MaxSize is " <<mv.maxsize();
    // mv.erase(3);
    // mv.clean();
    // mv.display();
    // cout<<"Size is "<<mv.Size();
    // cout<<endl;
    // cout<<mv.deleteAll();
    cout<<endl;
    mv.insert(27,2);
    mv.display( );
    cout<<"MaxSize is " <<mv.maxsize();

    return 0;
}