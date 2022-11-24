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
const int N = 5000;
int A[N];
ll dp[N][N][2];
int n,k;
ll solve(int i, int j, bool taking){
    if(j==k) return 0;
    if(i==n) return -1e18;
    if(dp[i][j][taking]!=-1)  return dp[i][j][taking];
    ll ans = -1e18;
    //take the element
    //case 1 end current subarray
    ans = max(ans,solve(i+1,j+1,0)+A[i]);
    //case 2 continue current subarray
    ans = max(ans,solve(i+1,j,1)+A[i]);

    //dont take the element
    ans = max(ans,solve(i+1,taking?(j+1):j,0)); 

    return dp[i][j][taking] = ans;
}
int main()
{
    cin>>n>>k;
    FOR(i,n) cin>>A[i];
    memset(dp,-1,sizeof dp);
    cout<<solve(0,0,0)<<endl;
    return 0;
}
