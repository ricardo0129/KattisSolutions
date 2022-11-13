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

const ll MOD = 1e17;
const int N = 1e5;
struct edge{
    int u, v;
    ll w;
    //runs at t = t0+k*p
    ll t0,p;
    edge(int a, int b, ll c, ll d, ll e){
        u = a; v = b;
        t0 = c; p = d; w = e;
    }
};

vector<edge> G[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,s;
    cin>>n>>m>>s;
    FOR(i,m){
        ll a, b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        G[a].pb(edge(a,b,c,d,e));
    }
    //find shortest path from 0 to n-1
    ll l = 0, r = MOD;
    ll ans = MOD;
    while(l<=r){
        ll m = (r-l)/2+l;
        set<pll> q;
        vll dist(n,MOD);
        dist[0] = m;
        q.insert({m,0});
        while(!q.empty()){
            pll ff = *q.begin(); q.erase(q.begin());
            if(dist[ff.s]<ff.f) continue;
            int u = ff.s;
            ll curr_time = dist[u];
            for(edge e: G[u]){
                int v = e.v;
                ll k = ceil((dist[u]-e.t0)/(double)e.p);
                k = max(k,(ll)0);
                ll earliest = e.t0+e.p*k;
                if(dist[v]>earliest+e.w){
                    dist[v] = earliest+e.w;
                    q.insert({dist[v],v});
                }
            }
        }
        if(dist[n-1]<=s){
            //we can make it 
            ans = m;
            l = m+1;
        }
        else r = m-1;
    }
    if(ans==MOD) cout<<"impossible\n";
    else cout<<ans<<endl;




    return 0;
}
