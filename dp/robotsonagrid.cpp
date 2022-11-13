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

vector<string> g;
ll M = (1LL<<31)-1;
ll dp[1000][1000];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int n;
bool valid(int i, int j){
    return i>=0 && i<n && j>=0 && j<n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    g.resize(n);
    FOR(i,n) cin>>g[i];
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;
    for(int i=1;i<n;i++){
        if(g[i][0]!='#') dp[i][0] = dp[i-1][0];
        if(g[0][i]!='#') dp[0][i] = dp[0][i-1];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(g[i][j]=='#') continue;
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%M;
        }
    }
    if(dp[n-1][n-1]==0){
        queue<int> x,y;
        x.push(0); y.push(0);
        vector<vi> dist(n,vi(n,-1));
        dist[0][0] = 1;
        while(!x.empty()){
            int i = x.front(); x.pop();
            int j = y.front(); y.pop();
            FOR(k,4){
               int i2 = i+dx[k];
               int j2 = j+dy[k];
               if(valid(i2,j2) && dist[i2][j2]==-1 && g[i2][j2]!='#'){
                    dist[i2][j2] = dist[i][j]+1;
                    x.push(i2);
                    y.push(j2);
               }
            }
        }
        if(dist[n-1][n-1]!=-1) cout<<"THE GAME IS A LIE\n";
        else cout<<"INCONCEIVABLE\n";
    }
    else cout<<dp[n-1][n-1]<<endl;
    


    return 0;
}
