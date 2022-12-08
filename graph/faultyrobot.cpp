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
const int N = (int)2e3+2;
bool vist[N];
struct edge{
    int u, v;
    bool forced=false;
    edge(int a, int b, int c){
        u = a; v = b;
        forced=c;
    }
};
int ans = 0;
int n,m;
vector<edge> G[N];
bool valid[N];
void dfs(int u, int bug){
    if(vist[u]) return;
    vist[u] = true;
    bool forced = false;
    bool notforced = false;
    for(edge e: G[u]){
        if(e.forced){
            forced = true;
        }
        else notforced = true;
    }
    //cout<<u<<" "<<forced<<endl;
    if(!forced){
        valid[u-bug*n] = true;
    }
    else{
        for(edge e: G[u]){
            if(e.forced) dfs(e.v,bug);
        }
    }
    if(!bug){
        for(edge e: G[u]){
           dfs(e.v+n,1); 
        }
    }
}

int main()
{
    cin>>n>>m;
    FOR(i,m){
        int u, v;
        cin>>u>>v;
        G[abs(u)].pb(edge(abs(u),v,(u<0)));
        G[abs(u)+n].pb(edge(abs(u)+n,v+n,(u<0)));
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) if(valid[i]) ans++;
    cout<<ans<<endl;
    return 0;
}
