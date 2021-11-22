#include<bits/stdc++.h>
using namespace std;

const int gs=5;
template <typename T>
class Node{
public:
    T data;
    Node<T>* leftside;
    Node<T>* rightside;
    Node(T val){
        this->data=val;
        this->leftside=NULL;
        this->rightside=NULL;

    }
    void print_tree(Node<T>*r,int space){
        if(r==NULL)
        return;
        space+=gs;
        print_tree(r->right,space);
        cout<<endl;
        for(int i=gs;i<=space;i++)
            cout<<" ";
            cout<<r->data<<endl;
        print_tree(r->left,space);
    }
};
int main()
{
//  

    
}
