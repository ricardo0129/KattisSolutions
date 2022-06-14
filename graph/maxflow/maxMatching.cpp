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

const int N = 400;
int cap[N][N];
vi G[N];
int seen[N];
int parent[N];
int n,m,k;
int source, sink;

int bfs(int s, int t){
	memset(parent,-1,sizeof parent);	
	parent[s] = -2;
	queue<pii> q;
	q.push({s,INT_MAX});
	while(!q.empty()){
		int u = q.front().first;
		int flow = q.front().second;
		q.pop();
		for(int v:G[u]){
			if(parent[v]==-1 && cap[u][v]>0){
				parent[v] = u;
				int new_flow = min(flow,cap[u][v]);
				if(v==t) return new_flow;
				
				q.push({v,new_flow});
			}
		}
	}
	return 0;
}

int maxFlow(){
	int flow = 0;
	int cur_flow = 0;
	while(cur_flow=bfs(source,sink)){
		flow+=cur_flow;
		int cur = sink;	
		while(cur!=source){
			int pre = parent[cur];
			cap[pre][cur]-=cur_flow;
			cap[cur][pre]+=cur_flow;
			cur = pre;
		}
	}

	return flow;
}
int cap2[N][N];
set<pii> edges;
void makeEdge(int u, int v, int c){
	if(edges.find({u,v})!=edges.end()) return;
	cap[u][v]=c;
	cap[v][u]=c;
	cap2[u][v]=c;
	cap2[v][u]=c;
	G[u].pb(v);
	G[v].pb(u);
	edges.insert({u,v});
}
int main()
{
	cin>>n>>m>>k;
	FOR(i,k){
		int u,v;
		cin>>u>>v;
		u--;v--;
		makeEdge(u+1,v+1+n,1);
	}
	FOR(i,n){
		makeEdge(0,1+i,1);
	}
	FOR(i,m){
		makeEdge(1+n+i,1+n+m,1);
	}
	source = 0, sink = n+m+1;

	int flow = maxFlow();
	cout<<flow<<endl;
	int k = 0;
	FOR(i,n){
		FOR(j,m){
			if( cap[1+i][1+n+j]<cap[1+n+j][1+i] ){
				k++;
				cout<<1+i<<" "<<1+j<<endl;
			}
		}
	}
	if(k<flow) return 1;

	
	return 0;
}
