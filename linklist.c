 #include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};
//tranverse the linklist
void display(struct Node *head)
{
    struct Node *ptr=head;
    if(head==NULL){
        return;
    }
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d ->",ptr->data);
    }
    printf("\n");
}
//count the size of linklist
int size(struct Node *head)
{
    struct Node *ptr=head;
    int count=0;
    if(head==NULL){
        return count;
    }
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        count++;
    }
    return count;
}
//insert at first position
struct Node *prepend(struct Node *head,int val)
{
    struct Node  *toadd = malloc(sizeof(struct Node));
    toadd->data=val;
    toadd->next =NULL;
    if(head==NULL){
        head=toadd;
        head->next=NULL;
    }
    else{
        toadd->next=head;
        head=toadd;
    }
    return head;
}
//insert at last position
struct Node *append(struct Node *head,int val)
{
    struct Node  *toadd = malloc(sizeof(struct Node));
    struct Node *ptr=head;
    toadd->data=val;
    toadd->next =NULL;
    if(head==NULL){
        head=toadd;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=toadd;
    
}
//insert at anywhere
struct Node *insert(struct Node *head,int val,int pos)
{
    struct Node  *toadd = malloc(sizeof(struct Node));
    struct Node *ptr=head;
    toadd->data=val;
    toadd->next =NULL;
    if(head==NULL){
        head=toadd;
    }
    for(int i=0;i<pos-2;i++){
        ptr=ptr->next;
    }
    ptr->next=toadd->next;
    ptr->next=toadd;
}
//delete the first node
struct Node *delete_at_first(struct Node *head)
{
    if(head==NULL){
        return;
    }
    head=head->next;
    return head;
}
//delete the last node
struct Node *delete(struct Node *head,int pos)
{
    struct Node *ptr=head;
    if(head==NULL){
        return;
    }
    for(int i=0;i<pos-2;i++){
        ptr=ptr->next;
    }
    ptr->next=ptr->next->next;
}
//delete from anywhere
struct Node *delete_at_last(struct Node*head)
{
    struct Node *ptr=head;
    if(head==NULL){
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
int main(){
    
    struct Node *head=malloc(sizeof(struct Node));
    head->data=45;
    head= prepend(head,33);
    printf("size is : %d \n",size(head));
    insert(head,32,2);
    append(head,43);
    append(head,53);
    append(head,95);
    append(head,55);
    append(head,4);
    //delete(head,3);
    head=delete_at_first(head);
    delete_at_last(head);
    display(head);
    return 0;
}


