#include<bits/stdc++.h>
using namespace std;

class st
{
    struct node
    {
        int l,r;
        int ls,rs;
        int lzy;
        int val;
    };
    vector<node> v;
    int cnt;
    int (*f) (int,int);
    void pointModify(int p,int val);
    int pointSearch(int p);
    void rangeModify(int l,int r,int val);
    int rangeSearch(int l,int r);
    int build(int pt,int l,int r,int * val)
    {
        if(l==r)
        {
            v[pt]={l,r,0,0,0,val[l]};
            return pt;
        }
        int mid=(l+r)>>1;
        int ls=build(++cnt,l,mid,val);
        int rs=build(++cnt,mid+1,r,val);
        v[pt]={l,r,ls,rs,0,f(v[ls].val,v[rs].val)};
        return pt;
    }
    st(int size,int * val,int fun (int,int))
    {
        v=vector<node>(size<<2);
        cnt=0;
        f=fun;
        build(1,1,size,val);
    }
};