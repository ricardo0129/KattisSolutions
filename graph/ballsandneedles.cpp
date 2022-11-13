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

map<vi,int> mp;
map<pii,int> mp2;
const int N = 2e5+1;
int indx(int x, int y, int z){
    if(mp.count({x,y,z})<=0) mp[{x,y,z}] = mp.size();
    return mp[{x,y,z}];
}
int indx(int x, int y){
    if(mp2.count({x,y})<=0) mp2[{x,y}] = mp2.size();
    return mp2[{x,y}];
}
bool vist[N];
bool cycle(int u, int p, vector<vi>& G){
    vist[u] = true;
    bool found = false;
    for(int v : G[u]){
        if(v==p) continue;
        if(!vist[v]) found|= cycle(v,u,G);
        else found = true;
    }
    return found;
}
int main()
{
    int n;
    cin>>n;
    vector<vi> G1(2*n);
    vector<vi> G2(2*n);
    set<pii> edges;
    FOR(i,n){
        int x1,y1,z1;
        cin>>x1>>y1>>z1;
        int x2,y2,z2;
        cin>>x2>>y2>>z2;
        int u = indx(x1,y1,z1);
        int v = indx(x2,y2,z2);
        if(u!=v){
            G1[u].pb(v);
            G1[v].pb(u);
        }
        u = indx(x1,y1);
        v = indx(x2,y2);
        if(u!=v && edges.find({u,v})==edges.end()){
            edges.insert({u,v});
            edges.insert({v,u});
            G2[u].pb(v);
            G2[v].pb(u);
        }
    }
    memset(vist,false,sizeof vist);
    bool has = false;
    FOR(i,mp.size()){
       if(!vist[i]){
         has|= cycle(i,i,G1); 
       }
    }
    if(has) cout<<"True closed chains\n";
    else cout<<"No true closed chains\n";

    memset(vist,false,sizeof vist);
    has = false;
    FOR(i,mp2.size()){
       if(!vist[i]){
         has|= cycle(i,i,G2); 
       }
    }

    if(has) cout<<"Floor closed chains\n";
    else cout<<"No floor closed chains\n";

    return 0;
}
