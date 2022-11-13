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

int A[205][2];
int dp[205][205][3];
int n,k;
int solve(int r, int j, int p){
    if(r==n){
        if(j!=k) return MOD;
        else return 0;
    }
    if(dp[r][j][p]!=-1) return dp[r][j][p];
    if(p==2){
        //pick left, right or skip
        int t1 = solve(r+1,j+1,0)+A[r][0];
        int t2 = solve(r+1,j+1,1)+A[r][1];
        int t3 = solve(r+1,j,2);
        return dp[r][j][p] = min({t1,t2,t3});
    }
    if(p==0){
        //pick left or skip    
        int t1 = solve(r+1,j+1,0)+A[r][0];
        int t2 = solve(r+1,j,2);
        return dp[r][j][p] = min(t1,t2);
    }
    int t1 = solve(r+1,j+1,1)+A[r][1]; 
    int t2 = solve(r+1,j,2);
    return dp[r][j][p] = min(t1,t2);
}
int main()
{
    while(cin>>n>>k){
        if(n==k && k==0) break;
        int total = 0;
        FOR(i,n){
            cin>>A[i][0]>>A[i][1];
            total+=A[i][0]+A[i][1];
        }
        memset(dp,-1,sizeof dp);
        int ans = solve(0,0,2);
        cout<<total-ans<<endl;
    }

    return 0;
}
