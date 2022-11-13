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

const int MOD = (int)1e9+7;
struct edge{
    int u,v,w,t;
    edge(int _u, int _v, int _w, int _t){
        u = _u;
        v = _v;
        w = _w;
        t = _t;
    }
};
const int N = 1000;
vector<edge> G[N];
int water[N];
bool dfs(int u, double flow){
    if(water[u]!=-1){
        return flow>=water[u];
    }
    bool valid = true;
    for(edge e: G[u]){
        double going  = (e.w/100.0)*(flow);
        if(e.t) going = going*going;
        valid &= dfs(e.v,going);
    }
    return valid;
}

int main()
{
    int n;
    cin>>n;
    FOR(i,n-1){
        int u,v,w,t;
        cin>>u>>v>>w>>t;
        u--;v--;
        G[u].pb(edge(u,v,w,t));
    }
    FOR(i,n) cin>>water[i];
    double l = 0.00001, r = 1e16;
    double ans = r;
    FOR(i,120){
        double m = (l+r)/2.0;
        if(dfs(0,m)){
            ans = m;
            r = m-0.00001;
        }
        else l = m+0.00001;
    }
    printf("%.10lf\n",ans);

    return 0;
}
