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
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MOD = (int)1e9+7;
const int N = 2e5+1;
template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
            jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
    assert(a < b); // or return in f i f a == b
    int dep = 31 - __builtin_clz(b - a);
    return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
}
};
int depth[N];
struct LCA {
    int T = 0;
    vi time, path, ret;
    RMQ<int> rmq;
    LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vi>& C, int v, int par) {
        time[v] = T++;
        for (int y : C[v]) if (y != par) {
            path.push_back(v), ret.push_back(time[v]);
            dfs(C, y, v);
        }
    }
    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
    //dist(a , b){return depth [a ] + depth [ b ] − 2∗depth [ lca (a , b) ] ;}
};
void dfs(int u, int p, int d,vector<vi>& G){
    depth[u] = d; 
    for(int v:G[u]){
        if(v==p) continue;
        dfs(v,u,d+1,G);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vi> G(n);
    FOR(i,n-1){
        int u,v;
        cin>>u>>v;
        u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(0,0,0,G);
    LCA qq(G);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i*2;j<=n;j+=i){
            int lc = qq.lca(i-1,j-1);
            ans+=depth[i-1]+depth[j-1]-2*depth[lc]+1;
        }
    }
    cout<<ans<<endl;


    return 0;
}
