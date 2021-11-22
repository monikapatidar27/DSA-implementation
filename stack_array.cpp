#include <iostream>
using namespace std;
  
template <typename T>
class Stack{
    int capacity;
    T *arr;
    int top;
     
public:
    Stack(){
        this->capacity=5;
        arr=new T[this->capacity];
        this->top=-1;
    }
   
    //number of item in the stack
    int Size(){
        return (this->top+1);
    }
    //access the item at the i position
    T peek(){
        if(isEmpty())
        {
            T(NULL);
        }
        else
        {
            return this->arr[this->top];
        }    
    }
    //stack is full or not.
    bool isFull(){
        if(this->top == (this->capacity-1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // stack is empty or not
    bool isEmpty(){
        if(this->top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //Display all items in the stack
    void display(){
        for(int i=0;i<=this->top;i++){
            cout<<this->arr[i]<<endl;
        }
    }
    // Return the item at the top of the stack and then remove it. 
    //If pop is called when stack is empty, it is in an underflow state.
    T pop(){
        if(isEmpty())
        {
            return T(NULL);
        }
        else
        {
            int num=this->arr[this->top];
            this->arr[top]=0;
            this->top--;
            return num;
        }
    }
    //Place an item onto the stack. If there is no place for new item, stack is in overflow state.
    void push(T x){
		this->top++;
		if(this->top == this->capacity){
			int oldsize=this->capacity;
			T * oldarr=new T[oldsize];
			for(int i=0;i<oldsize;i++){
				oldarr[i]=arr[i];
			}
			this->capacity*=2;
			this->arr=new T[this->capacity];
			for(int i=0;i<oldsize;i++){
				arr[i]=oldarr[i];
			}
		}
		this->arr[this->top]=x;
	}
    
};

int main(){
    Stack <int>st;
    st.push(2);
    st.push(5);
    st.push(6);
    st.push(1);
    st.push(2);
    st.push(5);
    st.push(6);
    st.push(1);
    st.push(2);
    st.push(5);
    st.push(6);
    st.push(1);
    st.display();
    cout<<st.Size()<<endl;
    cout<<st.isEmpty()<<endl;
    cout<<st.isFull()<<endl;
    st.pop();
    
    st.display();
    return 0;
}