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

int MOD = 100;
ll mult(ll a, ll b){
	return ((a%MOD)*(b%MOD))%MOD;
}
ll add(ll a, ll b){
	return ((a%MOD)+(b%MOD))%MOD;
}
ll epow(ll a, ll b){
	if(b==0) return 1;
	if(b==1) return a%MOD;
	ll x = epow(a,b/2);
	x = mult(x,x);
	if(b%2==1) x = mult(x,a);
	return x;
}
ll divi(ll a, ll b){
	return ((a%MOD)*(epow(b,MOD-2)))%MOD;
}
template<class T> 
struct RMQ{
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1,V){
        for(int pw = 1, k = 1; pw*2<=sz(V); pw*=2, ++k){
            jmp.emplace_back(sz(V)-pw*2+1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k-1][j],jmp[k-1][j+pw]);
        }
    }
    T query(int a, int b){
        assert(a<b);
        int dep = 31 - __builtin_clz(b-a);
        return min(jmp[dep][a],jmp[dep][b-(1<<dep)]);
    }
};
struct LCA{
    int T = 0;
    vi time,path,ret;
    RMQ<int> rmq;
    LCA(vector<vi>& C): time(sz(C)), rmq((dfs(C,0,-1),ret)) {}
    void dfs(vector<vi>& C, int v, int par){
        time[v] = T++;
        for(int y: C[v]) if(y!=par){
            path.pb(v), ret.pb(time[v]);
            dfs(C,y,v);
        }
    }
    int lca(int a, int b){
        if(a==b) return a;
        tie(a,b) = minmax(time[a],time[b]);
        return path[rmq.query(a,b)];
    }
};
const int N = 2e5+1;
vi parent;
vi depth;
vector<vi> G;
int max_depth = 0;
ll val[N];
int n,q;
ll V[N];
LCA* lc;
vector<vi> vv;
vector<vi> uu;
vector<vi> jump;
int max_d=0;
vector<vi> treeJump(vi& P){
    int on = 1, d = 1;
    while(on<sz(P)) on*=2,d++;
    max_d = d;
    vector<vi> jmp(d,P);
    vv = jmp;
    uu = jmp;

    FOR(i,sz(P)){
        vv[0][i] = V[i]%MOD;
        uu[0][i] = V[i]%MOD;
    }
    ll offset = 1;
    rep(i,1,d){
        rep(j,0,sz(P)){
            jmp[i][j] = jmp[i-1][jmp[i-1][j]];
            vv[i][j] = add(mult(vv[i-1][j],epow(10,offset)),vv[i-1][jmp[i-1][j]]);
            uu[i][j] = add(mult(uu[i-1][jmp[i-1][j]],epow(10,offset)),uu[i-1][j]);
        }
        offset*=2;
    }
    return jmp;
}

void dfs(int u){
    max_depth = max(max_depth,depth[u]);
    for(int v:G[u]){
        if(v!=parent[u]){
            parent[v] = u;
            depth[v] = depth[u]+1;
            dfs(v);
        }
    }
}
int jjn = 0;
ll query(int u, int v){
    int p = lc->lca(u,v);
    ll res = 0;
    if(u==p){
        int cc = 0;
        for(int i=max_d-1;i>=0;i--){
            if(depth[jump[i][v]]>depth[u]){
                res=add(res,mult(uu[i][v],epow(10,cc)));
                v = jump[i][v];
                cc+=(1<<i);
            }
        }
        res = add(res,mult(epow(10,cc++),V[v]));
        if(v!=p){
            v = parent[v];
            res = add(res,mult(epow(10,cc++),V[v]));
        }

    }
    else{
        for(int i=max_d-1;i>=0;i--){
            if(depth[jump[i][u]]>depth[p]){
                res = mult(res,epow(10,1LL<<i));
                res = add(res,vv[i][u]);
                u = jump[i][u];
            }
        }
        res = mult(res,10);
        res = add(res,V[u]);
        u = parent[u];

        res = mult(res,10);
        res = add(res,V[u]);

        res = mult(res,epow(10,depth[v]-depth[u]));
        int start = v;
        for(int i=max_d-1;i>=0;i--){
            if(depth[jump[i][v]]>depth[p]){
                res = add(res,mult(uu[i][v],epow(10,depth[start]-depth[v])));
                v = jump[i][v];
            }
        }
        if(v!=p)
        res = add(res,mult(vv[0][v],epow(10,depth[start]-depth[v])));
        
    }
    return res%MOD;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>MOD>>q;
    //MOD = 10000000;
    G.resize(n);
    parent.resize(n);
    depth.resize(n);
    FOR(i,n-1){
        int u,v;
        cin>>u>>v;
        u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    FOR(i,n) cin>>V[i];
    lc = new LCA(G);
    depth[0] = 0;
    parent[0] = 0;
    dfs(0);
    jump = treeJump(parent);
    double avg = 0;
    FOR(i,q){
      int u,v;
      cin>>u>>v;
      u--;v--;
      printf("%lld\n",query(u,v));
      /*
      if(i%10000==0){
        cout<<(jjn/(double)10000)<<endl;
        jjn = 0;
      }
      */
    }

    return 0;
}
