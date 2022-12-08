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

struct dsu{
    vi parent,sz;
    dsu(int n){
        parent.resize(n);
        sz.resize(n);
        FOR(i,n){
            sz[i] = 1;
            parent[i] = i;
        }
    }
    int find_parent(int u){
        if(parent[u]==u) return u;
        return parent[u] = find_parent(parent[u]);
    }
    bool merge(int u, int v){
        u = find_parent(u); v = find_parent(v);
        if(u==v) return false;
        if(sz[u]<sz[v]) swap(u,v);
        sz[u]+=sz[v];
        parent[v] = u;
        return true;
    }
};
double dist(pair<double,double> a, pair<double,double> b){
    return sqrt((a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s));
}

int main()
{
    int n,e,p;
    cin>>n>>e>>p;
    vector<pair<double,double>> loc;
    FOR(i,n){
        double x,y;
        cin>>x>>y;
        loc.pb({x,y});
    }
    vector<pair<double,pii>> E;
    FOR(i,p){
        int u,v;
        cin>>u>>v;
        u--;v--;
        E.pb({0,{u,v}});
    }

    FOR(i,e){
        for(int j=0;j<i;j++){
            E.pb({0,{i,j}});
        }
    }

    FOR(i,n){
        FOR(j,i){
            E.pb({dist(loc[i],loc[j]),{i,j}});
        }
    }
    sort(E.begin(),E.end());
    dsu dj(n);
    double ans = 0;
    for(auto e: E){
       int u = e.s.f; int v = e.s.s;
       double w = e.f;
       if(dj.merge(u,v)){
            ans+=w;
       }
    }

    printf("%.8lf\n",ans);





    
    return 0;
}
