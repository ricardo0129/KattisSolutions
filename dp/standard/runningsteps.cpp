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
ll dp[100][100][100];
ll solve(int i, int l2, int r2){
    int l1 = (i+1)/2 -l2;
    int r1 = (i)/2 - r2;
    int steps = 2*(l2+r2)+(l1+r1);
    if(steps>=n){
        int v = steps==n && (l2+r2)>=(l1+r1) && l1==r1 && l2==r2;
        //if(v) cout<<l2<<" "<<r2<<" "<<l1<<" "<<r1<<endl;
        return v;
    }
    if(dp[i][l2][r2]!=-1) return dp[i][l2][r2];
    ll ans = 0;
    //two setp
    if(i%2==0)
    ans+=solve(i+1,l2+1,r2);
    else
    ans+=solve(i+1,l2,r2+1);

    //one step
    if(i%2==0)
    ans+=solve(i+1,l2,r2);
    else
    ans+=solve(i+1,l2,r2);

    return dp[i][l2][r2] = ans;
}

int main()
{
    int t;
    cin>>t;
    int cc = 1;
    while(t--){
        int k;
        cin>>k>>n;
        memset(dp,-1,sizeof dp);
        ll ans = solve(0,0,0);
        printf("%d %lld\n",cc++,ans);

    }
    return 0;
}
