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
const int N = 505;
bool adj[N][N];
int dp[N][N];
/*
int solve(int i, int j){
    times++;
    if(i>=j) return 0;
    assert(i>=0 && i<n && j>=0 && j<n);
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 0;
    for(int k=i;k!=j;k=(k+1)%n){
        for(int l=(k+1)%n;;l=(l+1)%n){
            int s1=0,s2=0,s3=0;
            if(adj[k][l]){
                s1 = solve((k+1)%n,((l-1)%n+n)%n);
                if(k!=i)
                s2 = solve(i,((k-1)%n+n)%n);
                if(l!=j)
                s3 = solve((l+1)%n,j);
                ans = max(s1+s2+s3+1,ans);
                //if(times==10) break;
                //break;
            }
            if(l==j) break;
        }
    }

    return dp[i][j] = ans;
}
*/
int mod(int i){
    return ((i)%n+n)%n;
}
int main()
{
    cin>>n;
    FOR(i,n)
        FOR(j,n) 
            cin>>adj[i][j];
    memset(dp,0,sizeof dp);
    int best = 0;
    for(int i=0;i<n;i++)
        dp[i][2] = adj[i][mod(i+1)];
    for(int i=0;i<n;i++){
        dp[i][3] = dp[i][2] || dp[mod(i+1)][2] || adj[i][mod(i+2)];
    }

    for(int i=4;i<=n;i++){
        //start in j using i elemets
        for(int j=0;j<n;j++){
            //dp[j][i]=?
            for(int k=1;k<i;k++){
                int l=0,r=0;
                l = dp[j][k-1];
                assert(i-k-1>=0);
                r = dp[mod(j+k)][i-k-1];
                int ans = l+r;
                if(adj[mod(j+k-1)][mod(j+i-1)])
                    ans++;
                dp[j][i] = max(ans,dp[j][i]);
            }
            //dp[j][i] = max(dp[j][i],dp[mod(j+1)][i-2]+adj[j][mod(j+i-1)]);
            dp[j][i] = max(dp[j][i],dp[j][i-1]);
        }
    }
    for(int i = 0;i<n;i++) for(int j=2;j<=n;j++) best = max(best,dp[i][j]);
    cout<<best<<endl;
    return 0;
}
