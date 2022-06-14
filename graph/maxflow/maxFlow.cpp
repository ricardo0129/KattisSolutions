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

const int N = 1000;
int cap[N][N];
bool seen[N];
int sink,source;
vi G[N];
int n,m;

void addEdge(int u, int v,int c){
	cap[u][v]+=c;
	G[u].pb(v);
}
int dfs(int u, int flow){
	if(u==sink) return flow;
	seen[u] = true;
	int sent = 0 ;
	for(int v:G[u]){
		if(cap[u][v]>0 && !seen[v]){
			sent = dfs(v,min(flow,cap[u][v]));
			if(sent>0){
				cap[u][v]-=sent;
				cap[v][u]+=sent;
				return sent;
			}
		}
	}
	return 0;
}

int maxFlow(int source){
	int total = 0;
	int curr_flow = -1;
	while(curr_flow!=0){
		memset(seen,false,sizeof seen);
		curr_flow = dfs(source,INT_MAX);
		total+=curr_flow;
	}
	return total;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		addEdge(u,v,c);
		addEdge(v,u,c);
	}
	source = 1; sink = n;
	cout<<maxFlow(1)<<endl;

	
	return 0;
}
