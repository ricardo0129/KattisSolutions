#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;
struct Tree{
    vll A; vll vt,vn,vx;
    int n;
    int left(int p) { return p<<1; }
    int right(int p) { return ((p<<1)|1); }
    void init(int l, int r, int p){
        if(l==r){
            vt[p] = 0;
            vn[p] = A[l];
            vx[p] = A[l];
            return;
        }
        int m = (l+r)/2;
        init(l,m,left(p));
        init(m+1,r,right(p));
        vn[p] = min(vn[left(p)],vn[right(p)]);
        vx[p] = max(vx[left(p)],vx[right(p)]);
        int c1 = vt[left(p)], c2 = vt[right(p)];
        vt[p] = max(c1,c2);
        vt[p] = max(vt[p],vx[right(p)]-vn[left(p)]);
    }
    vll query(int l, int r, int i, int j, int p){
        //          (query_ans, max, min)
        vll q = {0,INT_MIN,INT_MAX};
        if(i<=l && r<=j){
            q[0] = vt[p];
            q[1] = vx[p];
            q[2] = vn[p];
            return q;
        }
        if(r<i || l>j) return q;
        int m = (l+r)/2;
        vll lq = query(l,m,i,j,left(p));
        vll rq = query(m+1,r,i,j,right(p));
        q[1] = max(rq[1],lq[1]);
        q[2] = min(rq[2],lq[2]);
        q[0] = max(rq[0],lq[0]);
        q[0] = max(q[0],rq[1]-lq[2]);
        return q;
    }
    ll query(int i, int j){
        vll ans = query(0,n-1,i,j,1);
        return ans[0];
    }
    Tree(vll& B){
       A = B; 
       n = A.size();
       vt.resize(4*n);
       vn.resize(4*n);
       vx.resize(4*n);
       init(0,n-1,1);
    }
};
int main()
{
    int n;
    cin>>n;
    vll v(n), d(n);
    FOR(i,n){
        cin>>v[i]>>d[i];
    }
    Tree* ST[7][2];
    int off[7] = {0,1,2,3,2,1,0};
    FOR(i,7){
        vll A(n);
        int day = i;
        FOR(j,n){
            A[j] = v[j]+d[j]*off[day];
            day = (day+1)%7;
        }
        ST[i][0] = new Tree(A);
        reverse(A.begin(),A.end());
        ST[i][1] = new Tree(A);
    }
    int q;
    cin>>q;
    FOR(i,q){
        int x,y;
        cin>>x>>y;
        x--;y--;
        if(x<=y){
            int idx = ((-(x%7))%7+7)%7;
            cout<<ST[idx][0]->query(x,y)<<endl;
        }
        else{
            int idx = (6-(x%7))%7;
            x = n-1-x;
            y = n-1-y;
            cout<<ST[idx][1]->query(x,y)<<endl;

        }
    } 

    
    return 0;
}
