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
int color[100];
int cc;
vi G[100];
vi G2[100];
int comp[100];
bool vist[100];
void dfs(int u){
    vist[u] = true;
    comp[u] = cc;
    for(int v: G[u]){
        if(color[u]==color[v] && !vist[v]){
            dfs(v);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    FOR(i,n) cin>>color[i];
    FOR(i,m){
        int u,v;
        cin>>u>>v; u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    FOR(i,n){
        if(!vist[i]){
            dfs(i);
            cc++;
        }
    }
    FOR(i,n){
        for(int v:G[i]){
            if(comp[i]!=comp[v]){
                G2[comp[i]].pb(comp[v]);
            }
        }
    }
    int radius = INT_MAX;
    FOR(i,cc){
        queue<int> q;
        vi dist(cc,MOD);
        dist[i] = 0;
        q.push(i);
        int max_dist = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();  
            max_dist = max(max_dist,dist[u]);
            for(int v: G2[u]){
                if(dist[v]==MOD){
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }
        radius = min(radius,max_dist);
    }
    cout<<radius<<endl;



    return 0;
}
