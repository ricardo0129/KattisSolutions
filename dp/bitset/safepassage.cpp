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
int n;
int emptystate;
int A[20];
int dp[1<<16];
int solve(int s){
    if(s==emptystate) return 0;
    if(dp[s]!=-1) return dp[s];
    int tot=0;
    int minimum = 0;
    FOR(i,n){
        if(s&(1<<i)) continue;
        tot++;
        minimum = max(minimum,A[i]); 
    }
    //base case less than or equal to two people
    if(tot<=2){
        return dp[s] = minimum;
    }
    int ans = MOD;
    FOR(i,n){
        if(s&(1<<i)) continue;
        for(int j=i+1;j<n;j++){
            if(s&(1<<j)) continue; 
            int time = max(A[i],A[j]);
            ans = min(ans,solve(s|(1<<i))+time+A[j]);
            ans = min(ans,solve(s|(1<<j))+time+A[i]);
            FOR(k,n){
                if(s&(1<<k)){
                    int v = s|(1<<i)|(1<<j);
                    v &= ~(1UL << k);
                    ans = min(ans,solve(v)+time+A[k]);
                }
            }
        }
    }
    return dp[s] = ans;
}

int main()
{
    cin>>n;
    FOR(i,n) cin>>A[i];
    emptystate = (1<<n)-1;
    memset(dp,-1,sizeof dp);
    int ans = solve(0);
    cout<<ans<<endl;


    return 0;
}
