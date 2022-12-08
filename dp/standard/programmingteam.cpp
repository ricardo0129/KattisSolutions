#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<long double,long double>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;

struct emp{
    double sal,prod;
    int rec;
    emp(double a, double b, int c){
        sal = a; prod = b;
        rec = c;
    }
};
const int N = 2505;
vi G[N];
vector<emp> A;
int n,k;
int tt[N];
int t_out[N];
int t_numb[N];
int subt[N];
int numb=0;

void dfs(int u, int p){
    t_numb[u] = numb;
    subt[u] = numb;
    tt[numb] = u;
    numb++;
    for(int v:G[u]){
        dfs(v,u);
        subt[u] = max(subt[u],subt[v]);
    }
    t_out[t_numb[u]] = subt[u]+1;
}

//prod/sal
double dp[N][N];
bool solve(double bound){
/*
    if(k==ks) return 0;
    if(u==numb) return -1e17;
    if(dp[u][ks]!=-1e20) return dp[u][ks];

    double x1 = solve(u+1,ks+1)+A[tt[u]].prod-bound*A[tt[u]].sal;
    double x2 = solve(t_out[u],ks);
    return dp[u][ks] = max(x1,x2);
*/
    for(int i=0;i<=n+1;i++) for(int j=0;j<=k;j++) dp[i][j] = -1e11;
    dp[n][1] = A[tt[n]].prod-bound*A[tt[n]].sal;
    //base case
    for(int i=0;i<=n+1;i++) dp[i][0] = 0;

    for(int i=n-1;i>0;i--){
        //go backwards in dfs order    
        //we don't take
        for(int j=1;j<=k;j++){
           //dp[i][j] = max(dp[i+1][j-1]+A[tt[i]].prod-bound*A[tt[i]].sal,dp[t_out[i]][j]);
           double x1 = dp[i+1][j-1]+A[tt[i]].prod-bound*A[tt[i]].sal;
           double x2 = dp[t_out[i]][j];
           dp[i][j] = max(x1,x2);
        }
    }
    return dp[1][k]>=0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>n;
    //model the hierchy as a tree and do dp
    //on the euler tour of the tree
    A.pb(emp(-1,-1,-1));
    FOR(i,n){
        long double a,b;
        int c;
        cin>>a>>b>>c;
        A.pb(emp(a,b,c));
        G[c].pb(i+1);
    }
    dfs(0,0);
    double L = 4e-8, R = 4e8;
    double best = -1;
    while(R-L>=1e-5){
        double M = (L+R)/2;
        bool ans = solve(M);
        if(ans){
            best = M;
            L = M;
        }
        else
            R = M;
    }
    printf("%.3lf\n",best);
    return 0;
}

