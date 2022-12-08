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
ll A[50];
ll dp[55][55][55][20];

ll solve(int i, int p1, int p2, int el){
    if(el==k) return 1;
    if(i==n) return 0;
    if(el<2){
        return dp[i][p1][p2][el] = solve(i+1,p2,i+1,el+1)+solve(i+1,p1,p2,el);
    }
    if(dp[i][p1][p2][el]!=-1) return dp[i][p1][p2][el];

    ll ans = 0;
    ans+=solve(i+1,p1,p2,el);
    if(A[p1-1]+A[p2-1]>=A[i]) ans+=solve(i+1,p2,i+1,el+1);
    return dp[i][p1][p2][el] = ans;
}
int main()
{
    cin>>n>>k;
    FOR(i,n) cin>>A[i];
    sort(A,A+n);
    FOR(i,n) FOR(j,n) FOR(k,n) FOR(l,k+1) dp[i][j][k][l] = -1;
    cout<<solve(0,0,0,0)<<endl;
    
    return 0;
}
