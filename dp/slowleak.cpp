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

const ll MOD = (ll)1e15+7;

vector<bool> station;
vector<vll> dist;
ll n,m,t,d;
const int N = 505;
ll dp[N][N][2];
ll solve(int i, int k, int stat){
    if(i==n-1) return 0;
    if(k==n) return MOD;
    if(stat==0) return MOD;
    if(dp[i][k][stat]!=-1) return dp[i][k][stat];
    //only take a station that is rechable
    ll ans = MOD;
    for(int j=0;j<n;j++){
        if(dist[i][j]<=d){
            ans = min(ans,solve(j,k+1,station[j])+dist[i][j]);            
        }
    }
    return dp[i][k][stat] = ans;
}
int main()
{
    cin>>n>>m>>t>>d;
    dist.assign(n,vll(n,MOD));
    station.assign(n,false);
    FOR(i,t){
        int x;
        cin>>x; x--;
        station[x] = true;
    }
    station[0] = true;
    FOR(i,m){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    
    memset(dp,-1,sizeof dp);
    ll ans = solve(0,0,1);
    if(ans==MOD) cout<<"stuck\n";
    else cout<<ans<<endl;
            
        
    

    return 0;
}
