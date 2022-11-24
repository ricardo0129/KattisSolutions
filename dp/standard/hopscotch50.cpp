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
int g[50][50];
int main()
{
    int n,k;
    cin>>n>>k;
    vector<vi> dp(n,vi(n,MOD));
    vector<vector<pii>> groups(k);
    FOR(i,n) FOR(j,n){
        cin>>g[i][j];
        g[i][j]--;
        if(g[i][j]==0){
            dp[i][j] = 0;
        }
        groups[g[i][j]].pb({i,j});
    }
    for(int i=1;i<k;i++){
       for(auto y: groups[i]){
           for(auto x: groups[i-1]){
                int dist = abs(x.f-y.f)+abs(x.s-y.s);
                dp[y.f][y.s] = min(dp[y.f][y.s],dp[x.f][x.s]+dist);
           }
        }
    }
    int ans = MOD;
    for(auto y: groups[k-1]){
        ans = min(ans,dp[y.f][y.s]);
    }
    if(ans==MOD) cout<<-1<<endl;
    else cout<<ans<<endl;


    
    return 0;
}
