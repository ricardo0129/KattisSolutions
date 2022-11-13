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
int n,k;
struct env{
    ll w,h,q;
    env(ll a, ll b, int c){
        w = a;
        h = b;
        q = c;
    }
};
vector<env> A;
int big=0;
ll dp[1<<15][15];
ll cost[1<<15];
vi G[1<<15];
ll iters = 0;
ll solve(int mask,int k){
    if(mask==big) return 0;
    if(dp[mask][k]!=-1) return dp[mask][k];
    if(k==1){
        ll maxh=0,maxw=0;
        FOR(i,n){
            if(mask&(1<<i)) continue;
            maxh = max(maxh,A[i].h);
            maxw = max(maxw,A[i].w);
        }
        ll cost = 0;
        FOR(i,n){
            if(mask&(1<<i)) continue;
            cost += (maxh*maxw-A[i].h*A[i].w)*A[i].q;
        }
        return dp[mask][k] = cost;
    }
    ll ans = 1e17;

    for(int v:G[mask^big]){
        ans = min(ans,solve(mask|v,k-1)+cost[v]);
    }

    return dp[mask][k] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    FOR(i,n){
        int a,b,c;
        cin>>a>>b>>c;
        A.pb(env(a,b,c));
    }

    int used[n];
    ll tot = 0;
    FOR(i,1<<n){
        if(i==0) continue;
        int l=0;
        FOR(j,n){
            if(i&(1<<j)){
               used[l++] = j; 
            }
        }
        FOR(j,1<<l){
            if(j==0) continue;
            int newmask = 0;
            FOR(k,l){
                if(j&(1<<k)){
                    newmask|=1<<used[k];
                }
            }
            G[i].pb(newmask);
        }
    }
    FOR(i,1<<n){
        ll maxh=0,maxw=0;
        FOR(j,n){
            if(i&(1<<j)){
               maxw = max(maxw,A[j].w); 
               maxh = max(maxh,A[j].h); 
            }
        }
        ll cc = 0;
        FOR(j,n){
            if(i&(1<<j)){
                cc+=(maxw*maxh-A[j].w*A[j].h)*A[j].q;
            }
        }
        cost[i] = cc;
    }
    big = (1<<n)-1;
    memset(dp,-1,sizeof dp);
    ll ans = solve(0,k);
    cout<<ans<<endl;



    return 0;
}
