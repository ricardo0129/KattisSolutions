#include <iostream>
#include <vector> 
#include <queue>

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

const ll INF = (ll)1e19;
const int MOD = (int)1e9+7;
struct edge{
    //white = 0 red = 1 blue = 2
    int color,u,v;
    ll w;
    edge(){}
    edge(int a,int b, ll c, int d){
        u = a; v = b;
        w = c; color = d;
    }

};
struct state{
    ll d;
    int u, k1,k2;
    state(){}
    state(int _u, ll w, int a, int b){
        u = _u; d = w;
        k1 = a; k2 = b;
    }
    bool operator> (const state& lhs) const {
        return d>lhs.d;
    }
};
const int N = 500;
vector<edge> G[N];
int n,m,k1,k2;
ll djk(int s, int t){
    //do state djkstras (node,k1,k2)
    vector<vector<vll>> dist(n,vector<vll>(k1+1,vll(k2+1,INF)));
    priority_queue<state,vector<state>,greater<state> >pq;
    pq.push(state(s,0,0,0));
    dist[s][0][0] = 0;
    while(!pq.empty()){
        state ff = pq.top(); pq.pop();
        ll w = ff.d;
        if(w>dist[ff.u][ff.k1][ff.k2]) continue;
        for(edge e: G[ff.u]){
            if(e.color==1 && ff.k1==k1) continue;
            if(e.color==2 && ff.k2==k2) continue;
            int k1_n = ff.k1+(e.color==1);
            int k2_n = ff.k2+(e.color==2);
            if(dist[e.v][k1_n][k2_n]>dist[ff.u][ff.k1][ff.k2]+e.w){
                dist[e.v][k1_n][k2_n] = dist[ff.u][ff.k1][ff.k2]+e.w;
                pq.push(state(e.v,dist[e.v][k1_n][k2_n],k1_n,k2_n));
            }

        }
    }

    return dist[t][k1][k2];
}
int main()
{
    scanf("%d %d %d %d", &n, &m, &k1, &k2);
    FOR(i,m){
       int u, v, c; 
       ll x;
       scanf("%d %d %lld %d",&u, &v, &x, &c);
       u--; v--;
       G[u].pb(edge(u,v,x,c));
       G[v].pb(edge(v,u,x,c));
    }
    int s, t;
    scanf("%d %d", &s, &t);
    ll ans = djk(s-1,t-1);
    if(ans==INF) printf("%d\n",-1);
    else printf("%lld\n",ans);

    return 0;
}
