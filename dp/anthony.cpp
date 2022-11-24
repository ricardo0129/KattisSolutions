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
double A[2000];
double dp[1000][1000];
int n,m;
double solve(int i, int j){
    if(n<=i) return 0;   
    if(m<=j) return 1.0;
    if(dp[i][j]!=-1.0) return dp[i][j];
    return dp[i][j] = solve(i+1,j)*(1-A[i+j])+solve(i,j+1)*(A[i+j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,n+m-1){
        cin>>A[i];
    }
    FOR(i,n) FOR(j,m) dp[i][j] = -1.0;
    double ex = solve(0,0);
    printf("%.8lf\n",ex);
    return 0;
}
