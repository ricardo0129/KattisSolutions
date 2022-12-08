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
int dp[40][40];
int nck(int n, int k){
    if(n==k) return 1;
    if(k==0) return 1;
    if(k>n) return 0;
    if(dp[n][k]!=-1) return dp[n][k];
    return dp[n][k] = nck(n-1,k-1)+nck(n-1,k);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        memset(dp,-1,sizeof dp);
        cout<<nck(n,m-1)<<endl;
    }
    return 0;
}
