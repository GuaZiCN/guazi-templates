#include<bits/stdc++.h>
using namespace std;

int add(int a,int b ) { return a+b; }

int main()
{
    int (*f)(int,int)=add;
    int a,b;
    cin>>a>>b;
    cout<<f(a,b)<<endl;
    return 0;
}
