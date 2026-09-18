#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P=998244353;
//const int P=1e9+7;

int pow(int a,int x)
{
    int ans=1;
    while(x)
    {
        if(x&1) ans=ll(ans)*a%P;
        a=ll(a)*a%P;
        x>>=1;
    }
    return ans;
}