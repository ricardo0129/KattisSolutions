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

template<class T> T edmonds(vector<unordered_map<int,T>>& graph, int source, int sink){
    T flow = 0;
    vi par(sz(graph)), q = par;
    for(;;){
        fill(all(par),-1);
        par[source] = 0;
        int ptr = 1;
        q[0] = source;
        rep(i,0,ptr){
            int x = q[i];
            for(auto e: graph[x]){
                if(par[e.f]==-1 && e.s>0){
                    par[e.f] = x;
                    q[ptr++] = e.f;
                    if(e.f==sink) goto out;
                }
            }
        }
        return flow;
    out:
        T inc = numeric_limits<T>::max();
        for(int y = sink; y!=source; y = par[y])
            inc = min(inc,graph[par[y]][y]);

        flow+=inc;
        for(int y = sink;y!=source;y = par[y]){
            int p = par[y];
            if((graph[p][y]-=inc)<=0) graph[p].erase(y);
            graph[y][p] += inc;
        }
    }
}
int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<unordered_map<int,int>> graph(n);
    FOR(i,m){
        int u,v,c;
        cin>>u>>v>>c;
        graph[u][v]+=c;
    }
    vector<unordered_map<int,int>> before = graph;
    int mincut = edmonds(graph,s,t);
    int leftcut = 0;
    vector<bool> vist(n,false);
    queue<int> q; q.push(s);
    int left = 0;
    vist[s] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        left++;
        for(int v=0;v<n;v++){
            int residual = graph[u][v];
            if(residual>0 && !vist[v]){
                vist[v] = true;
                q.push(v);
            }
        }
    }
    cout<<left<<endl;
    FOR(i,n){
        if(vist[i]) cout<<i<<endl;
    }
    cout<<endl;



    return 0;
}
