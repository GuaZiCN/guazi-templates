#include<bits/stdc++.h>
using namespace std;

const int MAXN=114514;

static vector<int> lg({-1});
static int mxm=0;

class sparseTable
{
    private:

    vector<vector<int>> val;

    public:

    sparseTable(int size,vector<int> & v)
    {
        if(size > mxm)
        {
            for(int i=mxm+1;i<=size;++i) 
                lg.push_back(lg[i>>1]+1);
            mxm=size;
        }
        val=vector<vector<int>>(lg[size]+1,vector<int>(size+1,0));
        int l=lg[size];
        for(int i=1;i<=size;++i) val[0][i]=v[i];
        for(int i=1;i<=l;++i)
        {
            int off=1<<(i-1);
            for(int j=size-off;j;--j)
            {
                val[i][j]=max(val[i-1][j],val[i-1][j+off]);
            }
        }
        return;
    }

    int search(int l,int r)
    {
        int sz=r-l+1;
        int lz=lg[sz];
        return max(val[lz][l],val[lz][r+1-(1<<lz)]);
    }

};

int main()
{
    vector<int> a(MAXN+1,0);
    sparseTable st(MAXN,a);
    return 0;
}