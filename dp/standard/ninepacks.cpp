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

const int MOD = (int)1e6+7;
const int N = 105;
const int UPPER=N*1000;
int dp1[N][UPPER];
int dp2[N][UPPER];
int n,m;
int A[N];
int B[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    FOR(i,n) cin>>A[i];
    cin>>m;
    FOR(i,m) cin>>B[i];
    if(n==0 || m==0){
        cout<<"impossible\n";
        return 0;
    }
    FOR(i,N) FOR(j,UPPER) dp1[i][j] = dp2[i][j] = MOD;
    FOR(i,N) dp1[i][0] = dp2[i][0] = 0;
    if(n>0)
    dp1[0][A[0]] = 1;
    if(m>0)
    dp2[0][B[0]] = 1;
    for(int i=1;i<n;i++){
        dp1[i][A[i]] = 1;
        for(int j=0;j<UPPER;j++){
            dp1[i][j] = min(dp1[i][j],dp1[i-1][j]);
            if(j-A[i]>=0) dp1[i][j] = min(dp1[i][j],dp1[i-1][j-A[i]]+1);
        }
    }
    
    for(int i=1;i<m;i++){
        dp2[i][B[i]] = 1;
        for(int j=0;j<UPPER;j++){
            dp2[i][j] = min(dp2[i][j],dp2[i-1][j]);
            if(j-B[i]>=0) dp2[i][j] = min(dp2[i][j],dp2[i-1][j-B[i]]+1);
        }
    }

    int ans = MOD;
    for(int i=1;i<UPPER;i++){
       if(dp1[n-1][i]!=MOD && dp2[m-1][i]!=MOD){
        ans = min(ans,dp1[n-1][i]+dp2[m-1][i]);
       }
    }
    if(ans==MOD) cout<<"impossible\n";
    else cout<<ans<<endl;

    return 0;
}
