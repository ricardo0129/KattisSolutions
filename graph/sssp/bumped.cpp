#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)

const ll INF = (ll)1e17+7;
vector<pii> G[(int)1e5];
ll dist[(int)1e5];
int main()
{
        int n,m,f,s,t;
        cin>>n>>m>>f>>s>>t;
        FOR(i,m){
                int u,v,w;
                cin>>u>>v>>w;
                G[u].pb({v,w});
                G[v].pb({u,w});
                G[u+n].pb({v+n,w});
                G[v+n].pb({u+n,w});
        }
        FOR(i,f){
                int u,v;
                cin>>u>>v;
                G[u].pb({v+n,0});
        }
        FOR(i,n) G[i].pb({i+n,0});

        FOR(i,2*n) dist[i] = INF;
        dist[s] = 0;
        set<pll> q;
        q.insert({0,s});
        while(!q.empty()){
                pll u = *q.begin(); q.erase(q.begin());
                if(dist[u.s]<u.f) continue;
                for(pii v:G[u.s]){
                        if(dist[v.f]>dist[u.s]+v.s){
                                dist[v.f] = dist[u.s]+v.s;
                                q.insert({dist[v.f],v.f});
                        }
                }
        }
        cout<<dist[n+t]<<endl;


	return 0;
}
