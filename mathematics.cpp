#include<bits/stdc++.h>
using namespace std;

//1. count digit
int count(int n)
{
    int res=0;
    while(n>0)
    {
        n=n/10;
        res++;
    }
    return res;
    
}
//2.Palindrome number
bool pal(int n)
{
    int rev=0;
    int temp=n;
    while(temp!=0)
    {
        int last=temp%10;
        rev=rev*10+last;
        temp=temp/10;
    }
    return (rev==n);
}
//3.Trailing zeros in factorial
int countZero(int n)
{
    int res=0;
    for(int i=5;i<=n;i=i*5)
    {
        res=res+n/i;
    }
    return res;
}
//4.greatest common divisor
int gcd(int a,int b)
{
    int res=min(a,b);
    while(res>0)
    {
        if(a%res ==0 && b%res ==0)
        {
            break;
        }
        res--;
    }
    return res;

}
//5. LCM of two number
int lcm(int a,int b)
{
    int res=max(a,b);
    while(true)
    {
        if(res%a ==0 && res%b==0){
            res++; 
        }
    }
    return res;
}
//6.check the number is prime or not
bool isprime(int n)
{
    if(n==1)
    {
        return false;
    }
    for(int i=0;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
//7.Prime factor
void isPrimeFact(int n)
{
    for(int i=2;i<n;i++)
    {
        if(isprime(i))
        {
            int x=i;
            while(n%x==0)
            {
                cout<<i;
                x=x*i;
            }
        }
    }       
}
int main(){
    
    cout<<countZero(251);
    return 0;
}