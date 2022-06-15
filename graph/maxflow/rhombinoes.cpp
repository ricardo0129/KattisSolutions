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

bool used[100][100];
int cap[10000][10000];
bool vist[10000];
int sink,source;
vi G[10000];

void addEdge(int u, int v, int c){
	G[u].pb(v);
	G[v].pb(u);
	cap[u][v]+=c;
}

int dfs(int u, int flow){
	vist[u] = true;
	if(u==sink) return flow;
	int sent = 0;
	for(auto v:G[u]){
		if(cap[u][v]>0 && !vist[v]){
			sent = dfs(v,min(flow,cap[u][v]));	
			if(sent>0){
				cap[u][v]-=sent;
				cap[v][u]+=sent;
				return sent;
			}
		}
	}
	return sent;
}
int maxFlow(){
	int max_flow = 0;
	int flow = -1;
	while(flow!=0){
		memset(vist,false,sizeof vist);
		flow = dfs(source,INT_MAX);
		max_flow+=flow;
	}
	return max_flow;
}
int r,c,k;
bool valid(int i, int j){
	return i>=0 && i<r && j>=0 && j<c && !used[i][j];
}

int main()
{
	memset(cap,0,sizeof cap);
	cin>>c>>r>>k;
	FOR(i,k){
		int x,y;
		cin>>x>>y;
		used[y][x] = true;	
	}
	FOR(i,r){
		FOR(j,c){
			if(valid(i,j) && valid(i+1,j)  && !(i%2==j%2)){
				int u = i*c+j;
				int v = (i+1)*c+j;
				int polarity = u%2;
				if(c%2==0 && i%2==1) polarity = (polarity+1)%2;
				if(polarity!=0) swap(u,v);
				//printf("%d -> %d\n",i*c+j,(i+1)*c+j);
				addEdge(1+u,1+(r*c)+v,1);
				//cout<<endl;
				
			}
			if(valid(i,j) && valid(i,j+1) ){
				int u = i*c+j;
				int v = i*c+j+1;
				int polarity = u%2;
				if(c%2==0 && i%2==1) polarity = (polarity+1)%2;
				if(polarity!=0) swap(u,v);
				//printf("%d -> %d\n",i*c+j,(i)*c+j+1);
				addEdge(1+u,1+(r*c)+v,1);
				//cout<<endl;
				
			}
		}
	}
	FOR(i,r*c){
		addEdge(0,1+i,1);
		addEdge(1+r*c+i,1+2*r*c,1);
	}
	source = 0;
	sink = 1+2*r*c;
	cout<<maxFlow()<<endl;
	return 0;
}
