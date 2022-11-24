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

const int N = 2e5+1;
vi G[N];
ll sz[N];
int main()
{
    int n,m; cin>>n>>m;
    FOR(i,m){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    FOR(i,n) cin>>sz[i+1];
    ll curr = 0;
    vector<bool> vist(n+1,false);
    vist[1] = true;
    set<pll> q;
    q.insert({0,1});
    while(!q.empty()){
        pll ff = *q.begin(); q.erase(q.begin());
        int u = ff.s;
        if(u!=1 && ff.f>=curr) break;
        curr+=sz[u];
        for(int v:G[u]){
            if(!vist[v]){
                q.insert({sz[v],v});
                vist[v] = true;
            }
        }
    }
    cout<<curr<<endl;
    return 0;
}
