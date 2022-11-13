#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;

struct emp{
    int tech,time;
    emp(int b, int c){
        tech = b;
        time = c;
    }
    emp(){
        tech = time = 0;
    }
};
const int N = 1e5+1;
struct FT{
    vll s;
    FT(int n): s(n) {}
    void update(int pos, ll diff){
        for(;pos<sz(s);pos|=pos+1) s[pos]+=diff;
    }
    ll query(int pos){
        //sum from [0,pos)
        ll res = 0;
        for(;pos>0;pos&=pos-1) res+=s[pos-1];
        return res;
    }
};
FT* ds;
vi G[N];
emp A[N];
ll ans[N];
void dfs(int u){
    ll prev = ds->query(A[u].tech); 
    for(int v:G[u]){
        dfs(v);
    }
    ans[u] = ds->query(A[u].tech)-prev;
    ds->update(A[u].tech,A[u].time);
}

int main()
{
    int n;
    cin>>n;
    ds = new FT(100001);
    int start = -1;
    FOR(i,n){
        int u,r,t;
        cin>>u>>r>>t;
        if(u!=-1)
            G[u-1].pb(i);
        else 
            start = i;
        A[i] = emp(r,t);
    }
    dfs(start);
    FOR(i,n){
        cout<<ans[i]<<endl;
    }


    
    return 0;
}
