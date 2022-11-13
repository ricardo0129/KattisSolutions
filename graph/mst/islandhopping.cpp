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

struct point{
    double x,y;
    point(){
        x = y = 0;
    }
    point(int _x, int _y){
        x = _x;
        y = _y;
    }
};
double dist(point a, point b){
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
struct dsu{
    vi parent,sz;
    dsu(int n){
        parent.resize(n);
        sz.resize(n);
        FOR(i,n){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find_parent(int u){
        if(parent[u]==u) return u;
        return parent[u] = find_parent(parent[u]);
    }
    void merge(int u,int v){
        u = find_parent(u);
        v = find_parent(v);
        if(u==v) return;
        if(sz[u]<sz[v]) swap(u,v);
        sz[u]+=sz[v];
        parent[v] = u;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){        
        int n;
        cin>>n;
        vector<point> A(n);
        FOR(i,n){
            cin>>A[i].x>>A[i].y;
        }
        vector<pair<double,pii>> all;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                double dd = dist(A[i],A[j]);
                all.pb({dd,make_pair(i,j)});
            }
        }
        dsu dj(n);
        sort(all.begin(),all.end());
        double ans = 0;
        for(auto x: all){
            double w = x.f;
            pii e = x.s;
            int u = dj.find_parent(e.f);
            int v = dj.find_parent(e.s);
            if(u!=v){
                ans+=w;
                dj.merge(e.f,e.s);
            }
        }
        printf("%.8lf\n",ans);
        //cout<<ans<<endl;
    }
    return 0;
}
