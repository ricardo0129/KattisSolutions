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

const ll MOD = (ll)1e17+7;

const int N = 25000;
ll dp[N];
int n,q;
vll A;
ll solve(int u){
   if(dp[u]!=-1) return dp[u];
   if(u<=n){
        if(u==0) return 0;
        return A[u-1];
   }
   ll ans = MOD;
   for(int i=1;i<u;i++){
        ans = min(ans,solve(i)+solve(u-i));
   }
   return dp[u] = ans;
}
int main()
{
    cin>>n>>q;
    A.resize(n);
    vector<pair<double,int>> B;
    FOR(i,n){
        cin>>A[i];
        B.pb(make_pair(A[i]/(double)(i+1),i+1));
    }
    sort(B.begin(),B.end());
    ll s1 = (n)*(n+1)/2;
    memset(dp,-1,sizeof dp);
    FOR(i,q){
        ll x;
        cin>>x;
        ll v = min(4*s1,x);
        x-=v;
        ll over = x/(B[0].s)*(A[B[0].s-1]);
        x = x%(B[0].s);
        ll ans = solve(v+x)+over;
        cout<<ans<<endl;
    }
    return 0;
}
