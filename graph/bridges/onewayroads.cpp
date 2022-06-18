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

int n,m;
int num;
int dfs_num[100],dfs_low[100];
int p[100];
vi G[100];
int dfsRoot,rootChildren;
bool possible;

void dfs(int u){
	dfs_num[u] = dfs_low[u] = num++;

	for(int v:G[u]){
		if(dfs_num[v]==-1){
			p[v] = u;
			if(u==dfsRoot) rootChildren++;
			dfs(v);		
			if(dfs_low[v]>dfs_num[u]) possible = false;
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}
		else if(v!=p[u]){
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
		}
	}
}
int color[100];
void construct(int u){
	color[u] = 1;
	for(int v:G[u]){
		if(color[v]==0){
			cout<<u+1<<" "<<v+1<<endl;
			p[v] = u;
			construct(v);
		}
		else if(color[v]!=2 && p[u]!=v){
			cout<<u+1<<" "<<v+1<<endl;
		}
	}
	color[u] = 2;
}
int main()
{
	cin>>n>>m;
	FOR(i,m){
		int u,v;
		cin>>u>>v;
		u--;v--;
		G[u].pb(v);
		G[v].pb(u);
	}

	possible = true; dfsRoot = 0; rootChildren = 0;
	FOR(i,n) dfs_num[i] = -1;
	num = 0;
	dfs(0);
	if(!possible) cout<<"NO\n";
	else{
		cout<<"YES\n";
		num = 0;
		FOR(i,n) dfs_num[i] = -1;
		construct(0);
	}




	return 0;
}
