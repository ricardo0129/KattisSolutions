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

void solve(int n, vector<vector<bool>>& dp, vector<vi>& G, vi& indeg){
    dp[0][0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: G[u]){
            for(int i=1;i<=1000;i++){
                dp[v][i] = dp[v][i] || dp[u][i-1];
            }
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }
    FOR(i,n) assert(indeg[i]==0);
}
int main()
{
    int n1,n2,m1,m2;
    cin>>n1>>n2;
    cin>>m1>>m2;
    vector<vi> G1(n1);
    vector<vi> G2(n2);
    vi indeg1(n1),indeg2(n2);
    FOR(i,m1){
        int u,v;
        cin>>u>>v;
        u--;v--;
        G1[u].pb(v);
        indeg1[v]++;
    }
    FOR(i,m2){
        int u,v;
        cin>>u>>v;
        u--;v--;
        G2[u].pb(v);
        indeg2[v]++;
    }
    vector<vector<bool>> dp1(n1,vector<bool>(1005,false));
    vector<vector<bool>> dp2(n2,vector<bool>(1005,false));
    solve(n1,dp1,G1,indeg1);
    solve(n2,dp2,G2,indeg2);
    int q;
    cin>>q;
    FOR(i,q){
        int x;
        cin>>x;
        bool valid = false;
        FOR(j,x+1){
            if(j<n1 && x-j<n2)
            if(dp1[n1-1][j] && dp2[n2-1][x-j]) valid = true;
            if(x-j<n1 && j<n2)
            if(dp1[n1-1][x-j] && dp2[n2-1][j]) valid = true;
        }
        if(valid) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
