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
    char color;
    int u,v;
    edge(int a, int b, char c){
        u = a; v = b;
        color = c;
    }
};
const int N = 1000;
vector<edge> G[N];
bool vist[N];
bool adj[1000][1000];
int cc;
vi gg[N];
int compedges[N];
void dfs(int u){
    vist[u] = true; 
    gg[cc].pb(u);
    for(edge e: G[u]){
        if(e.color=='B' && !vist[e.v]) dfs(e.v);
        if(e.color=='B') compedges[cc]++;
    }
}
int n,m,k;
int main()
{
    int curr = 0;
    while(cin>>n>>m>>k){
    memset(adj,false,sizeof adj);
    memset(compedges,0,sizeof compedges);
    FOR(i,n) G[i].clear();
    FOR(i,n) gg[i].clear();
    //we just care about connected compenets blue makes 
    //this tells us how many red edges we can add 
    //ipso facto how many blue edges we can use
    //if(curr==37) cout<<n<<" "<<m<<" "<<k<<endl;
    int bu = 0;
    int re = 0;
    FOR(i,m){
        char t; int u,v;
        cin>>t>>u>>v;
        //if(curr==37) cout<<t<<" "<<u<<" "<<v<<endl;
        u--;v--;
        G[u].pb(edge(u,v,t));
        G[v].pb(edge(v,u,t));
        if(t=='R'){
            re++;
            adj[u][v] = true;
            adj[v][u] = true;
        }
        else bu++;
    }
    cc = 0;
    memset(vist,false,sizeof vist);
    FOR(i,n){
        if(!vist[i]){
            dfs(i);
            cc++;
        }
    }
    bool valid = true;
    if(bu<k)  valid = false;
    if(cc-1>n-1-k){
        valid = false;
    }
    else{
        int tot = 0;
        //connect components
        int one = 0, two = 0;;
        for(int i=0;i<cc;i++){
           for(int j=0;j<i;j++){
                bool valid = false;
                for(auto x: gg[i]){
                    for(auto y: gg[j]){
                        if(adj[x][y]) valid = true;
                    }
                }
                if(valid){
                    if((int)gg[i].size()>1 && (int)gg[j].size()>1) two++;
                    else one++;
                }
           }
        }
        if(one+two<cc-1){
            valid = false;
        }
        //remove extra
        int left = n-1-k-(cc-1);
        int avail = 0;
        for(int i=0;i<cc;i++){
            int c_sz = (int)gg[i].size();
            int tt = 0;
            for(auto x: gg[i]){
                for(auto y: gg[i]){
                    if(adj[x][y]) tt++;
                }
            }
            tt/=2;
            ll v = min(compedges[i]-(c_sz-1),tt);
            avail+=v;
        }
        int v = cc-1;
        v-=one;
        two-=v;
        if(avail+two<left) valid = false;
    }
    if(valid) cout<<1<<endl;
    else cout<<0<<endl;
    curr++;
    }
    
    return 0;
}
