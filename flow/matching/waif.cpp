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

int f[400][400];
vi G[400];
int n,m,p;

void addEdge(int u, int v,int c){
	//string a = printType(u);
	//string b = printType(v);
	f[u][v]+=c;
}
bool vist[400];
int sink,source;
int getflow(int u,int mini){
	if(u==sink) return mini;
	vist[u] = true;
	int sent = 0;
	for(int v=0;v<400;v++){
		if(f[u][v]>0 && !vist[v]){
			sent = getflow(v,min(mini,f[u][v]));
			if(sent>0){
				f[u][v]-=sent;
				f[v][u]+=sent;
				return sent;
			}
		}
	}
	return 0;
}
int maxflow(){
	int maxflow = 0;
	int flow = -1;
	while(flow!=0){
		memset(vist,false,sizeof vist);
		flow = getflow(source,INT_MAX);
		maxflow+=flow;
	}
	return maxflow;
}
bool used[205];
int main()
{
	FOR(i,400)
		FOR(j,400) f[i][j] = 0;
	cin>>n>>m>>p;
	//children toys cat
	FOR(i,n){
		int k;
		cin>>k;
		FOR(j,k){
			int toy;
			cin>>toy;
			toy--;
			//children to toy
			addEdge(2+p+toy,2+p+m+i,1);
		}	
	}	
	FOR(i,p){
		int k;
		cin>>k;
		FOR(j,k){
			int x;
			cin>>x;
			x--;
			used[x] = true;
			addEdge(1+i,2+p+x,1);
		}	
		int l;
		cin>>l;
		addEdge(0,1+i,l);
	}
	int un = 0;
	int nu = 0;
	FOR(i,m){
		if(!used[i]){
			addEdge(1+p,2+p+i,1);
			un++;
		}
	}
	addEdge(0,1+p,un);
	FOR(i,n){
		addEdge(2+p+m+i,2+p+m+n,1);
	}
	source = 0;
	sink = 2+p+m+n;
	cout<<maxflow()<<endl;

	return 0;
}
