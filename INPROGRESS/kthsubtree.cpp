#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)

ll A[5001][5001];
ll B[5001][5001];
vi G[5001];
int n;
void dfs(int u, int p){
        A[u][1] = 1;
        B[u][1] = 0;
        vll tmp(n+1);
        for(int v:G[u]){
                if(v!=p){
                        dfs(v,u);
                        for(int i=1;i<=n;i++){
                                B[u][i]+=B[v][i];
                                tmp[i]+=A[v][i];
                        }
                }
        }
        
        //
        
}

int main()
{
        int k;
        cin>>n>>k;
        FOR(i,n-1){
                int u,v;
                cin>>u>>v;
                u--;v--;
                G[u].pb(v);
                G[v].pb(u);
        }

	return 0;
}
