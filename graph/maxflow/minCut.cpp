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
int cap2[N][N];
vi G[N];
bool seen[N];
int source,sink;
int parent[N];

int bfs(int s, int t){
	memset(parent,-1,sizeof parent);
	parent[s] = -2;
	queue<pii> q;
	q.push({s,INT_MAX});
	while(!q.empty()){
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();
		for(int v:G[cur]){
			if(parent[v]==-1 && cap[cur][v]>0){
				parent[v] = cur;
				int new_flow = min(flow,cap[cur][v]);
				if(v==t)
					return new_flow;
				q.push({v,new_flow});

				
			}
		}
	}
	return 0;
}

int maxflow(int s, int t){
	int flow = 0;
	int new_flow;
	while(new_flow=bfs(s,t)){
		flow+=new_flow;
		int cur = t;
		while(cur!=s){
			int prev = parent[cur];
			cap[prev][cur]-=new_flow;
			cap[cur][prev]+=new_flow;
			cur = prev;
		}
	}
	return flow;
}
int n;
void copy(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) 
			cap[i][j] = cap2[i][j];

}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	while(cin>>n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				char x;
				cin>>x;
				cap2[i][j]=(int)(x-'0');
				if(cap2[i][j]) G[i].pb(j);
			}
		}
		int ans = INT_MAX;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				copy();
				ans = min(ans,maxflow(i,j));
			}
		}
		cout<<ans<<endl;
		for(int i=0;i<n;i++) G[i].clear();
	}
	return 0;
}
