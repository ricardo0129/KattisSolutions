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
int p[300];
double tot = 0;
int sum[300];
//double dp[300][100][100][100][2];
double dp[301][301][301];
double solve(int i, int c1, int c2){
    //assert(cn==c3);
    int c3 = (i-c1-2*c2)/3;
    int c0 = n-c1-c2-c3;
    if(i==n*3){
        //return sum[i-1]*p;
        return sum[i-1];
    }
    if(dp[i][c1][c2]!=-1) return dp[i][c1][c2];
    //coninue
    double a1 = 0;
    if(c0){
        double x = solve(i+1,c1+1,c2)*(c0/(double)n);
        if(x>0) a1+=x;
    }
    if(c1){
        double x = solve(i+1,c1-1,c2+1)*(c1/(double)n);
        if(x>0) a1+=x;
    }
    if(c2){
        double x = solve(i+1,c1,c2-1)*(c2/(double)n);
        if(x>0) a1+=x;
    }
    double a2 = 0;
    if(i!=0) a2 = sum[i-1];
    //cout<<i<<" "<<a1<<" "<<a2<<endl;
    return dp[i][c1][c2] = max(a1,a2);
}

int main()
{
    cin>>n;
    int curr=0;
    FOR(i,3*n){
        cin>>p[i];
        curr+=p[i];
        sum[i] = curr;
    }
    FOR(i,3*n+1) FOR(j,3*n+1) FOR(k,3*n+1) dp[i][j][k] = -1;
    double ans = solve(0,0,0);
    printf("%.10lf\n",ans);
    return 0;
}
