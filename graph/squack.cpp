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
const int N = 100;
vi G[N];
int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    FOR(i,m){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    vll curr(n,0);
    curr[s] = 1;
    FOR(i,t){
        vll next(n,0);
        FOR(u,n){
            for(int v: G[u]){
                next[v]+=curr[u];
            }
        }
        curr = next;
    }
    ll ans = 0;
    FOR(i,n) ans+=curr[i];
    cout<<ans<<endl;
    return 0;
}
