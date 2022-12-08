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
const int N = 1e5;
vi G[N];

int n,l;
int center(vi vert){
    //edge case only one node
    if(sz(vert)==1) return vert[0];
    queue<int> q;
    vi indeg(sz(vert),0);
    int k = 0;
    map<int,int> mp;
    for(int x: vert){
        mp[x] = k;
        indeg[k++] = G[x].size();
        if(G[x].size()==1) q.push(x);
    }
    int center = -1;
    while(!q.empty()){
        int u = q.front(); q.pop(); 
        center = u;
        for(int v:G[u]){
            indeg[mp[v]]--;
            if(indeg[mp[v]]==1)
                q.push(v);
        }
    }
    return center;
}
bool vist[N];
vector<vi> comp;
int cc;
void dfs(int u){
    comp[cc].pb(u);
    vist[u] = true; 
    for(int v:G[u])
        if(!vist[v]) dfs(v);
}
void components(){
    cc = 0;
    for(int i=0;i<n;i++){
        if(!vist[i]){
            vi A;
            comp.pb(A);
            dfs(i);
            cc++;
        }
    }
}
int radius;
void rad(int u,int p, int depth){
    radius = max(radius,depth);
    for(int v:G[u]){
        if(v!=p) 
            rad(v,u,depth+1);
    }
}
int diameter(){
    if(n==1) return 0;
    queue<int> q;
    vi dist(n,-1);
    dist[0] = 0;
    q.push(0);
    int left = -1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        left = u;
        for(int v:G[u]){
            if(dist[v]==-1){
                q.push(v);
                dist[v] = dist[u]+1;
            }
        }
    }
    dist.assign(n,-1);
    q.push(left);
    dist[left] = 0;
    int d = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        d = dist[u];
        for(int v:G[u]){
            if(dist[v]==-1){
                q.push(v);
                dist[v] = dist[u]+1;
            }
        } 

    }
    return d;
}


int main()
{
    cin>>n>>l;
    FOR(i,l){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    memset(vist,false,sizeof vist);
    components();
    vector<pii> heads;
    for(vi c: comp){
        int cent = center(c);
        radius = 0;
        rad(cent,cent,0);
        heads.pb(make_pair(radius,cent));
    }
    sort(heads.begin(),heads.end());
    for(int i=sz(heads)-2;i>=0;i--){
        int u = heads[sz(heads)-1].s;
        int v = heads[i].s;
        G[u].pb(v);
        G[v].pb(u);
    }
    int ans = diameter();
    cout<<ans<<endl;
    

    return 0;
}
