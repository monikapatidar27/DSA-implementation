#include<bits/stdc++.h>
using namespace std;
class Node{

public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        data=-1;
        prev=NULL;
        next=NULL;
    }
    Node(int val)
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
    Node(int val,Node *pr,Node *nx)
    {
        data=val;
        next=nx;
        prev=pr;
    }
};

class doubly_linklist{
public:
    Node *head;
    doubly_linklist()
    {
        this->head=NULL;
    }
    doubly_linklist(int val)
    {
        this->head->data=val;
        this->head->prev=NULL;
        this->head->next=NULL;
    }
    int size()
    {
        Node *ptr=head;
        int count=0;
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            count++;
        }
        return count;
    }
    void display()
    {
        Node *ptr=head;
        if(head==NULL)
        {
            return;
        }
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            cout<<ptr->data<<"->";
        }
        cout<<endl;
    }
    //insert at first position
    void prepend(int val){
        Node *toadd=new Node(val);
        Node *ptr=this->head;
        toadd->prev=NULL;
        if(this->head==NULL)
        {
            this->head=toadd;
            this->head->next=NULL;
        }
        else{
        toadd->next=this->head;
        this->head->prev=toadd;
        this->head=toadd;
        }
    }
    //insert at last position
    void append(int val)
    {
        Node *toadd=new Node(val);
        Node *ptr=head;
        if(head==NULL)
        {
            head=toadd;
            return;
        }
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=toadd;
        toadd->prev=ptr;
    }
    //insert at any position
    void insert(int val,int pos)
    {
        Node *ptr=head;
        Node *toadd=new Node(val);
        if(this->head==NULL)
        {
            toadd->next=ptr;
            ptr->prev=toadd;
            toadd->prev=NULL;
            head=toadd;
            return;
        }
        if(pos==1)
        {
            prepend(val);
            return;
        }
        if(pos>size())
        {
            return;
        }
        for(int i=0;i<pos-2;i++)
        {
            ptr=ptr->next;
        }
        toadd->next=ptr->next;
        ptr->next->prev=toadd;
        toadd->prev=ptr;
        ptr->next=toadd;
    }
    //delete at first position
    void delete_at_first()
    {
        if(head==NULL)
        {
            return;
        }
        head=head->next;
    }
    //delete at last
    void delete_at_last()
    {
        Node *ptr=head;
        if(head==NULL)
        {
            return;
        }
        if(head->next==NULL){
            head=NULL;
            return;
        }
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next->prev=NULL;
        ptr->next=NULL;
    }
    //delete at any position
    void delete_at_pos(int pos)
    {
        Node *ptr=head;
        if(head==NULL)
        {
            return;
        }
         if(pos==1)
        {
            delete_at_first();
            return;
        }
        for(int i=0;i<pos-2;i++){
            ptr=ptr->next;
        }
        ptr->next->prev=NULL;
        ptr->next->next->prev=ptr;
        ptr->next=ptr->next->next;
    }
    

};



int main(){
    doubly_linklist l1;
    l1.append(56);
    l1.append(89);
    l1.insert(45,2);
    l1.insert(4,1);
    l1.display();
    // l1.delete_at_first();
    // l1.delete_at_last();
    l1.delete_at_pos(1);
    l1.display();
    return 0;
}