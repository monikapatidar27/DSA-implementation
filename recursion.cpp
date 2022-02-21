#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.print n to 1
void printn(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    printn(n-1);
}
//2.print 1 to n
void print1(int n){
    if(n==0){
        return;
    }
    print1(n-1);
    cout<<n<<" ";
}
//3.calculate factorial
int fact(int n){
    if(n<=1){
        return 1;
    }
    return n*fact(n-1);
    
}
//4.fibonacci
int fibo(int n){
    if(n<=1){
        return n;
    }
    int ans1=fibo(n-1);
    int ans2=fibo(n-2);
    return ans1+ans2;
}
//5.sum of natural numbers
int sum(int n){
    if(n==0){
        return 0;
    }
    return n+sum(n-1);
}
//6.sum of digit
int getsum(int n){
    if(n<=9){
        return n;
    }
    return getsum(n/10)+n%10;
}
//7. check palindrome or not
bool isPal(string str,int s,int e){
    if(s>=e){
        return true;
    }
    return (str[s]==str[e]) && isPal(str,s+1,e-1);
}
//8.rope cutting problem
int maxr(int n,int a,int b, int c){
    
    if(n==0){
        return 0;
    }
    if(n<0){
        return -1;
    }
    int res=max(maxr(n-a,a,b,c),maxr(n-b,a,b,c));
    res=max(res,maxr(n-c,a,b,c));
    if(res==-1){
        return -1;
    }
    return res+1;
}
//9.Generate subset
void subset(string str,string curr="",int i=0){
    if(i==str.length()){
        cout<<curr<<"  ";
        return;
    }
    subset(str,curr,i+1);
    subset(str,curr+str[i],i+1);
}
//10.subset sum problem
int subsum(int arr[],int n,int sum)
{
    if(n==0)
    {
        return (sum==0)? 1:0;
    }
    return subsum(arr,n-1,sum)+subsum(arr,n-1,sum-arr[n-1]);
}
//11.Josephus problem
int jos(int n,int k)
{
    if(n==1)
    {
        return 0;
    }
    else
    return (jos(n-1,k)+k)%n;
}
//12.Tower of hanoi
void TOH(int n,char a,char b,char c)
{
    if(n==1)
    {
        cout<<"move 1 from "<<a<<" to "<<c<<endl;
        return;
    }
    TOH(n-1,a,c,b);
    cout<<"move "<<n<<" from "<<a<<" to "<<c<<endl;
    TOH(n-1,b,a,c);
}
//13.count digit
int count(int n)
{
    if(n==0)
    {
        return 0;
    }
    return 1+ count(n/10);
}
//14.greatest common divisor
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
//15. LCM 
int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}
int main(){
    
    // print1(5);
    // cout<<endl;
    // printn(5);
    // cout<<endl;
    // cout<<getsum(234)<<endl;
    cout<<maxr(23,11,9,12)<<endl;
    if(isPal("abb",0,2)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    cout<<fact(5)<<endl;
    cout<<fibo(5)<<endl;
    cout<<sum(4)<<endl;
    subset("abc");
    cout<<endl;
    int arr[]={20,20,15};
    cout<< subsum(arr,3,25)<<endl;
    cout<<jos(5,3)<<endl;
    TOH(2,'a','b','c');
    return 0;

}
