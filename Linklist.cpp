#include<iostream>
using namespace std;
class Node{

public:
    int data;
    Node *next;
    Node()
    {
        data=-1;
        next=NULL;
    }
    Node(int val)
    {
        data=val;
        next=NULL;
    }
    Node(int val,Node *n)
    {
        data=val;
        next=n;
    }

};
class Linklist{

public:
    Node *head;
    Linklist()
    {
        head=NULL;
    }
    Linklist(int val)
    {
        head->data=val;
    }
    //size of linklist
    int size()
    {
        Node *ptr=head;
        int count=0;
        if(this->head==NULL)
        {
            return count;
        }
        for(ptr=this->head;ptr!=NULL;ptr=ptr->next)
        {
            count++;
        }
        return count;
    }
    //print the linklist
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
        if(this->head==NULL)
        {
            this->head=toadd;
            this->head->next=NULL;
        }
        else{
        toadd->next=head;
        head=toadd;
        }
    }
    //insert at last position
    void append(int val)
    {
        Node *toadd=new Node(val);
        Node *ptr=head;
        // toadd->data=val;
        // toadd->next=NULL;
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
        
    }
    //insert at any position
    void insert(int val,int pos)
    {
        Node *ptr=head;
        Node *toadd=new Node(val);
        // toadd->data=val;
        // toadd->next=NULL;
        if(head==NULL)
        {
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
        ptr->next=ptr->next->next;
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
        ptr->next=NULL;
    }
    
};
int main()
{
    Linklist l1;
    l1.prepend(23);
    l1.append(49);
    l1.display();
    l1.insert(22,1);
    // l1.insert(2,4);
    // l1.append(55);
    // l1.append(12);
    // l1.delete_at_first();
   l1.delete_at_pos(1);
    // l1.delete_at_last();
    l1.display();
    cout<<l1.size();
    return 0;
}