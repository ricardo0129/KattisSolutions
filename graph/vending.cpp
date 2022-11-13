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

const int N = 1e5+100;
ll market[N];
ll pay[N];
ll to[N];
ll amount[N];
struct edge{
    int u, v;
    ll w, c;
    edge(int a, int b, ll e, ll d){
        u  = a; v = b;
        w = e; c = d;
    }
};
vector<edge> G[N];
int color[N];
bool vist[N];
vi cycle_nodes;
ll ans = 0;
void findcycle(int u){
    color[u] = 1;
    for(edge e: G[u]){
        if(color[e.v]==0) findcycle(e.v);
        else if(color[e.v]==1){
           cycle_nodes.pb(u); 
        }
    }
    color[u] = 2;
}
int sz;
int indeg[N];
ll highest[N];
int cycle[N];
ll delta[N];
bool inside;
int curr;
ll process(int u){
    cycle[u] = curr;
    sz++;
    color[u] = 1;
    if(indeg[u]>1) inside = true;
    ll min_weight = highest[u]/amount[u];
    ans+=highest[u];
    for(edge e: G[u]){
        if(!color[e.v]){
            ll mm = process(e.v);
            min_weight = min(mm,min_weight);
        }
    }
    return min_weight;
}
void fixcycle(int u){
    vist[u] = true;
    for(edge e: G[u]){
        if(!vist[e.v] && cycle[e.v]==0) 
            fixcycle(e.v);
        if(cycle[e.v]!=0){
            int cn = cycle[e.v];
            ll v = highest[e.v]/amount[e.v];
            delta[cn] = max(delta[cn],-v+e.w);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    FOR(i,n){
        int v,p,m,s;
        cin>>v>>p>>m>>s;
        to[i] = v-1;
        pay[i] = p;
        amount[i] = s;
        market[i] = m;
    }
    memset(color,0,sizeof color);
    memset(cycle,0,sizeof cycle);
    memset(highest,0,sizeof highest);
    memset(indeg,0,sizeof indeg);
    FOR(i,n){
        int u = i;
        int v = to[i];
        if(market[v]>pay[u]){
            G[u].pb(edge(u,v,market[v]-pay[u],amount[v]));
            highest[v] = max(highest[v],(market[v]-pay[u])*amount[v]);
            indeg[v]++;
        }
    }
    curr = 1;
    FOR(i,n){
        if(!color[i])
            findcycle(i); 
    }
    memset(color,0,sizeof color);
    for(int x: cycle_nodes){
        if(color[x]==0){
            sz = 0;
            inside = false;
            ll low = process(x);
            if(sz!=1){
                //ans-=low;
                delta[curr] = -low;
            }
            else delta[curr] = 0;
            //cycle number 
            curr++;
        }
    }
    memset(vist,false,sizeof vist);
    FOR(i,n){
       if(!vist[i] && cycle[i]==0){
        fixcycle(i); 
       }
    }
    for(int i=1;i<curr;i++){
        assert(delta[i]<=0);
        ans+=delta[i];
    }
    queue<int> q;
    FOR(i,n){
        if(indeg[i]==0){
            color[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        ans+=highest[u];
        for(edge e: G[u]){
           indeg[e.v]--;
           if(indeg[e.v]==0 && color[e.v]==0){
                q.push(e.v); 
           }
        }
    }

    cout<<ans<<endl;
    




    return 0;
}
