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

const int MOD = (int)1e6;

int main()
{
    int n;
    cin>>n;
    vi dp(n+1); dp[0] = 1; dp[1] = 1;
    for(int i=2;i<=n;i++) dp[i] = ((dp[i-1]%MOD)+(dp[i-2]%MOD))%MOD;
    cout<<dp[n]<<endl;
    return 0;
}
