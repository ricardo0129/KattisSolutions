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

map<string,int> mp;
int idx(string in){
    if(mp.count(in)<=0) mp[in] = mp.size();
    return mp[in];
}
template<class T> T edmonds(vector<unordered_map<int,T>>& graph, int source, int sink){
    assert(source!=sink);
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
                if(par[e.f]==-1 && e.second>0){
                    par[e.f] = x;
                    q[ptr++] = e.f;
                    if(e.f==sink) goto out;
                }
            }
                

        }
        
    
    return flow;
out: 
    T inc = numeric_limits<T>::max();
    for(int y = sink;y!=source;y=par[y])
        inc = min(inc,graph[par[y]][y]);
    flow+=inc;
    for(int y = sink;y!=source;y=par[y]){
        int p = par[y];
        if((graph[p][y]-=inc)<=0) graph[p].erase(y);
        graph[y][p]+=inc;
    }
    }
}
    

int main()
{
    int s,r,f,t;
    cin>>s>>r>>f>>t;
    set<int> factory,raw; 
    FOR(i,r){
        string in; cin>>in;
        raw.insert(idx(in));
    }
    FOR(i,f){
        string in; cin>>in;
        factory.insert(idx(in));
    }
    vector<unordered_map<int,int>> graph(2+s+t*3);
    FOR(i,t){
        int k; cin>>k;
        int u = 2+s+i*3;
        graph[u][u+2] = 1;
        graph[u+2][u] = 1;

        graph[u][u+1] = 1;
        graph[u+1][u] = 1;
        FOR(j,k){
            string in; cin>>in;
            int id = idx(in);
            if(raw.find(id)!=raw.end()){
                  graph[id+2][u+1] = 1; 
                  graph[u+1][id+2] = 1; 
            }
            else if(factory.find(id)!=factory.end()){
                graph[u+2][id+2] = 1;
                graph[id+2][u+2] = 1;
            }
            else{
               graph[id+2][u+1] = 1; 

               graph[u+2][id+2] = 1; 
            }
        }
    }
    for(auto x: raw){
        graph[0][x+2] = 1;
        graph[x+2][0] = 1;
    }
    for(auto x: factory){
        graph[x+2][1] = 1;
        graph[1][x+2] = 1;
    }
    int ans = edmonds(graph,0,1);
    cout<<ans<<endl;

    return 0;
}
