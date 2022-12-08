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
template<class T> T edmond(vector<unordered_map<int,T>>& graph, int source, int sink){
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
    vector<pii> edges;
    FOR(i,m){
        int u, v, c;
        cin>>u>>v>>c;
        graph[u][v] += c;
        edges.pb({u,v});
    }
    vector<unordered_map<int,int>> before = graph;
    int flow = edmond(graph,s,t);
    map<pii,int> cap;
    set<int> nodes;
    for(pii e: edges){
        int u = e.f, v = e.s;
        int taken = before[u][v]-graph[u][v];
        if(taken>0){
           cap[{u,v}]+=taken; 
           nodes.insert(u);
           nodes.insert(v);
        }
    }
    cout<<n<<" "<<flow<<" "<<sz(cap)<<endl;
    for(auto e: cap){
       cout<<e.f.f<<" "<<e.f.s<<" "<<e.s<<endl;
    }
    return 0;
}
