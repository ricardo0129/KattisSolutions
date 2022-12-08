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
int all=0;
int cost(string A, string B){
    //going from string A -> B
    vi p(26,0);
    for(char c: A) p[c-'A'] = 1; 
    int cc = 0;
    for(char c: B) if(p[c-'A']) cc++;
    return cc;
}
int n;
vector<string> A;
int dp[1<<10][10];
int solve(int mask,int previous){
    if(mask==all) return 0;
    if(dp[mask][previous]!=-1) return dp[mask][previous];
    int ans = INT_MAX;
    FOR(i,n){
        if(mask&(1<<i)) continue;        
        ans = min(ans,solve(mask|(1<<i),i)+cost(A[previous],A[i]));
    }
    return dp[mask][previous] = ans;
}
int main()
{
    cin>>n;
    A.resize(n);
    FOR(i,n){
        cin>>A[i];
    }
    all = (1<<n)-1;
    int ans = INT_MAX;
    memset(dp,-1,sizeof dp);
    FOR(i,n){
        ans = min(ans,solve(1<<i,i));
    }
    cout<<ans<<endl;

    return 0;
}
