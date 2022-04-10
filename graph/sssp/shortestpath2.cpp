/*
Not really a hard problem, but more like a simple implementation of single source shortest path. 
If you have a good implementation of dijkstras then this should be solved fairly quickly. 
Only caviat how we relax edges. 
We have two main cases 
Case 1. P  = 0: This means we can only take the edge at time t0. 
Case 2. P != 0: This means we can take the edge at any time 
We just have to find the minimum time we can take it and we use this value to relax the edge. 
*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>
const int INF = (int)1e9;

const int N = (int)1e4;
vector<vector<int>> G[N];
int n,m,q,s;

vi solve(){
    vi dist(n,INF);
    dist[s] = 0;
    set<pii> q;
    q.insert({0,s});
    while(!q.empty()){
        int u = q.begin()->second;
        q.erase(q.begin());
        for(vi v:G[u]){
            if(v[3] == 0){
                if(dist[u]<=v[2] && v[2]+v[1]<dist[v[0]]){
                    q.erase({dist[v[0]],v[0]}); 
                    dist[v[0]] = v[2]+v[1];
                    q.insert({dist[v[0]],v[0]});
                }
            }
            else{
                int d = 0;
                if(dist[u]<=v[2]) d = v[2];
                else d = v[2]+((int)ceil((dist[u]-v[2])/(double)v[3]))*v[3];
                if(d+v[1]<dist[v[0]]){
                    q.erase({dist[v[0]],v[0]}); 
                    dist[v[0]] = d+v[1];
                    q.insert({dist[v[0]],v[0]});
                }
            }
        }
    }
    return dist;
}

int main()
{
    int t = 0;
    while(true){
        cin>>n>>m>>q>>s;
        if(n+m+q+s==0) break;
        if(t++!=0) cout<<endl;
        for(int i=0;i<m;i++){
            int u,v,t,p,d;
            cin>>u>>v>>t>>p>>d;
            G[u].push_back({v,d,t,p});
        }

        vi dist = solve();
        for(int i=0;i<q;i++){
            int v;
            cin>>v;
            if(dist[v]==INF) cout<<"Impossible\n";
            else cout<<dist[v]<<endl;
        }
        for(int i=0;i<n;i++) G[i].clear();

        
    }
    return 0;
}
