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
const int N = 1000;
int P[N];
int n,m;
vector<pii> G[N];
int djk(int cap, int source, int goal){
    //state (node,fuel) 
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>> >pq;

    vector<vi> dist(n,vi(cap+1,MOD));
    dist[source][0] = 0;
    pq.push({0,{0,source}});
    while(!pq.empty()){
        pair<int,pii> ff = pq.top(); pq.pop();
        int u = ff.s.s;
        int fuel = ff.s.f;
        if(dist[u][fuel]<ff.f) continue;
        if(u==goal) return dist[u][fuel];
        for(pii v:G[u]){
            //we are trying to go from  u -> v
            int needed = max(0,v.s-fuel);
            for(int i=needed;i+fuel<=cap;i++){
                int new_fuel = fuel+i-v.s;
                if(dist[v.f][new_fuel]>dist[u][fuel]+i*P[u]){
                    dist[v.f][new_fuel] = dist[u][fuel]+i*P[u];
                    pq.push({dist[v.f][new_fuel],{new_fuel,v.f}});
                }
            }
        }
    }
    return MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,n) cin>>P[i];
    FOR(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }
    int q;
    cin>>q;
    FOR(i,q){
        int c,s,e;
        cin>>c>>s>>e;
        int dist = djk(c,s,e);
        if(dist==MOD) cout<<"impossible\n";
        else cout<<dist<<endl;
    }




    return 0;
}
