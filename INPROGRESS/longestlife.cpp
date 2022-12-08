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

int main()
{
    ll n;
    int p,c;
    cin>>n>>p>>c;
    vector<vi> pills(p);
    FOR(i,p){
        vi A(3);
        FOR(j,3) cin>>A[j];
        pills[i] = A;
    }
    sort(pills.begin(),pills.end());
    vector<double> dp(p);
    double ans = n;
    dp[0] = pills[0][0]+(n-pills[0][0]-c)*(double)(pills[0][1])/(double)(pills[0][2]);
    ans = max(ans,dp[0]);
    cout<<dp[0]<<endl;
    for(int i=1;i<p;i++){
        dp[i] = pills[i][0]+(n-pills[i][0]-c)*(double)(pills[i][1])/(double)(pills[i][2]);
        for(int j = 0;j<i;j++){
            dp[i] = max(dp[i],
            dp[j]-(double)pills[j][1]/(double)pills[j][2]*(n-pills[i][0])
            //+(pills[i][0]-pills[j][0])*(double)(pills[j][1])/(double)(pills[j][2])
            +(n-pills[i][0]-c)*(double)(pills[i][1])/(double)(pills[i][2]));
        }
        cout<<dp[i]<<endl;
        ans = max(ans,dp[i]);
    }
    printf("%.8lf\n",ans);

    return 0;
}
