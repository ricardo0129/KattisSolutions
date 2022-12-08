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

const ll INF = (ll)1e17;
const int MOD = (int)1e9+7;
const int N = 100000;
vector<pii> G[N];
int main()
{
    int n,m,T;
    cin>>n>>m>>T;
    FOR(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }
    int s,t;
    cin>>s>>t;
    int k;
    cin>>k;
    vi spiders(k);
    vll spiderdist(n,INF);
    set<pll> q;
    FOR(i,k){
        cin>>spiders[i];
        spiderdist[spiders[i]] = 0;
        q.insert({0,spiders[i]});
    }
    //djistras for closest distance from spiders
    while(!q.empty()){
        pll ff = *q.begin(); q.erase(q.begin());
        if(spiderdist[ff.s]<ff.f) continue;
        int u = ff.s;
        for(pii v: G[u]){
            if(spiderdist[v.f]>spiderdist[u]+v.s){
                spiderdist[v.f] = spiderdist[u]+v.s;
                q.insert({spiderdist[v.f],v.f});
            }
        }
    }
    vector<pll> dist(n,{0,INF});
    dist[s] = {spiderdist[s],0};
    set<pair<pll,ll>> q2;
    q2.insert({{-spiderdist[s],0},s});
    ll ans = INF;
    while(!q2.empty()){
        pair<pll,ll> ff = *q2.begin(); q2.erase(q2.begin());
        int u = ff.s;
        if(dist[u].s<ff.f.s) continue;
        if(u==t && dist[u].s<=T){
            ans = min(ans,ff.f.f);
        }
        for(pii v: G[u]){
            if(dist[v.f].s>dist[u].s+v.s){
                //dist[v.f] = dist[u]+v.s;
                int maxi = max(ff.f.f,-spiderdist[v.f]);
                dist[v.f] = {maxi,dist[u].s+v.s};
                q2.insert( { {maxi,dist[v.f].s} , v.f });
            }
        }
    }
    cout<<-ans<<endl;



    return 0;
}
