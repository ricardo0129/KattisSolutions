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
const ll INF = (ll)1e19;
const int N = 2e5+1;
vector<vector<pll>> GO;
vector<vector<pll>> GR;
set<ll> S;
int n,m,d;
vll djk(int source, vector<vector<pll>>& G){
    vll dist(n+1,INF);
    dist[source] = 0;
    set<pll> q;
    q.insert({dist[source],source});
    while(!q.empty()){
        pll ff = *q.begin();
        q.erase(q.begin());
        int u = ff.s;
        if(dist[u]<ff.f) continue;
        for(pll v: G[u]){
            if(dist[v.f]>dist[u]+v.s){
                dist[v.f] = dist[u]+v.s;
                q.insert({dist[v.f],v.f});
            }
        }
    }
    return dist;
}
vector<pll> G2[N];
int found = 0;
int parent[N];
void dfs(int u, vll& dist){
    if(found>=2) return;

    if(u==n){
        found++;
    }

    auto it = S.upper_bound(dist[u]);
    for(pll v:G2[u]){
        if(it==S.end() || dist[u]+v.s<=*it){
            parent[v.f] = u;
            dfs(v.f,dist);
        }
    }
}
int main()
{
    cin>>n>>m>>d;
    GO.resize(n+1);
    GR.resize(n+1);
    FOR(i,m){
        int u, v;
        ll w;
        cin>>u>>v>>w;
        GO[u].pb({v,w});
        GR[v].pb({u,w});
    }
    FOR(i,d){
        ll x;
        cin>>x;
        S.insert(x);
    }
    vll d1 = djk(1,GO);
    ll minimum_path = d1[n];
    vll d2 = djk(n,GR);
    for(int i=1;i<=n;i++){
        for(pll v: GO[i]){
           if(d1[i]+v.s+d2[v.f]==minimum_path){
                G2[i].pb({v.f,v.s});
           }
        }
    }
    dfs(1,d1);
    if(*S.rbegin()>minimum_path) found = 0;
    if(found>=2) cout<<1<<endl;
    else if(found==0) cout<<0<<endl;
    else{
       vi path; 
       int start = n;
       while(start!=1){
            path.pb(start);
            start = parent[start];
       }
       path.pb(start);
       cout<<path.size()<<endl;
       for(int i=path.size()-1;i>=0;i--){
            cout<<path[i]<<endl;
       }
    }






    return 0;
}
