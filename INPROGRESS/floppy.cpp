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

const int N = 105;
int B[N];
int E[N];
bool dp[N][10005];
int main()
{
    int f;
    cin>>f;
    bool valid = true;
    FOR(tt,f){
        int t,n;
        cin>>t>>n;
        for(int i=0;i<n;i++) cin>>B[i]>>E[i];
        memset(dp,false,sizeof dp);
        FOR(i,t+1) dp[0][i] = true;
        for(int i=1;i<=n;i++){
            int dist = E[i-1]-B[i-1];
            for(int j=0;j<=t;j++){
                if(j-dist>=0){
                    dp[i][j] |= dp[i-1][j-dist];
                }
                if(j+dist<=t){
                    dp[i][j] |= dp[i-1][j+dist];
                }
            }
        }
        bool check = false;
        for(int j=0;j<=t;j++) check = check || dp[n][j];
        valid &=check;
    }
    if(valid) cout<<"possible\n";
    else cout<<"impossible\n";
    return 0;
}
