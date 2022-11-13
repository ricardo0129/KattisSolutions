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

int r,c,b,x,y;
int xpos[20];
int ypos[20];
int took;
int dist(int i, int j, int k){
    return abs(i-xpos[k])+abs(j-ypos[k]);
}
int dp[20][20][1<<10];
int solve(int i, int j, int mask){
    if(mask==took) return abs(i-x)+abs(j-y);
    if(dp[i][j][mask]!=-1) return dp[i][j][mask];
    int ans = MOD;
    FOR(k,b){
        if(mask&(1<<k)) continue;
        ans = min(ans,solve(xpos[k],ypos[k],mask|(1<<k))+dist(i,j,k)); 
    }
    return dp[i][j][mask] = ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>r>>c;
        cin>>x>>y;
        x--; y--;
        cin>>b;
        FOR(i,b){
           cin>>xpos[i]>>ypos[i]; 
           xpos[i]--; 
           ypos[i]--;
        }
        took = (1<<b)-1;
        memset(dp,-1,sizeof dp);
        int ans = solve(x,y,0);
        cout<<ans<<endl;

    }
    return 0;
}
