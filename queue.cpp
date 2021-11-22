#include <iostream>
using namespace std;
  

class  queue{
    int capacity;
    int front;
    int rear;
    int *arr;
    public:
        queue(int size){
            this->front=this->rear=-1;
            this->capacity=size;
            arr=new int[size];
        }
        bool empty(){
            if(rear==-1){
                return true;
            }
            else{
                return false;
            }
        }
        int size(){
            if(empty()){
                return 0;
            }
            else{
                return (this->rear-this->front)+1;
            }
        }
        bool full(){
            if(size() == this->capacity){
                return true;
            }
            else{
                return false;
            }
        }
        void queue_Enqueue(int data){
            if(empty()){
                rear=0;
                front=0;
            }
            else if(this->rear == this->capacity){
                cout<<"Overflow condition";
                return;
            }
            else{
                rear++;
            }
            arr[rear]=data;
            
        }
        void display(){
            if(this->rear==this->front){
                cout<<"Queue is empty"<<endl;
                return;
            }
            else{
                for(int i=front;i<=rear;i++){
                    cout<<arr[i]<<"<--";
                }
            }
            return;
        }
        void pop(){
            if(size()==0){
                cout<<"underflow condition";
                return ;
            }
            else{
                arr[this->front]=-1;
                this->front++;
            }
        }

};
int main(){
    queue q(5);
    q.display();
    q.queue_Enqueue(20);
    q.queue_Enqueue(30);
    q.queue_Enqueue(40);
    q.queue_Enqueue(50);
    q.display();
    cout<<endl;
    cout<<"size is "<<q.size()<<endl;;
    q.pop();
    cout<<endl;
    q.display();

    
    
    
}