/*
    A straight foward implementation of topological sort. The only caviat is that there may 
    not exist a topological ordering if there is a cycle. We can easily do this by trying to 
    form the topological ordering and there isn't n vertices in the final answer then there 
    contains a cycle.
*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

const int N = (int)1e6;
int n,m;
int indegree[N];
vi G[N];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        indegree[v]++;
        G[u].push_back(v);
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v:G[u]){
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }
    if(topo.size()!=n) cout<<"IMPOSSIBLE\n";
    else{
        for(int v:topo) cout<<v+1<<endl;
    }
    return 0;
}
