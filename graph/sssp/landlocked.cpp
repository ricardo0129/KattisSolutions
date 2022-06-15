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

const int INF = (int)1e8;
int p[(int)1e6];
int sz[(int)1e6];
void make_set(int u){
	p[u] = u;
	sz[u] = 1;
}
int find_set(int u){
	if(p[u]==u) return u;
	return p[u] = find_set(p[u]);
}
void merge_set(int u, int v){
	u = find_set(u);
	v = find_set(v);
	if(u!=v){
		if(sz[u]<sz[v]) swap(u,v);
		sz[u]+=sz[v];
		p[v] = u;
	}
}


int r,c;
char g[1000][1000];
bool valid(int i, int j){
	return i>=0 && i<r && j>=0 && j<c;
}
int f(int i, int j){
	return i*c+j;
}
char inv(int i){
	return g[(int)i/c][i%c];	
}

vector<pii> dirs = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
set<int> G[(int)1e6];
int ans[26];
int dist[(int)1e6];
int main()
{
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	FOR(i,26) ans[i] = INF;
	cin>>r>>c;
	FOR(i,r*c) dist[i] = INF;
	FOR(i,r) FOR(j,c) make_set(f(i,j));
	FOR(i,r)
		FOR(j,c){
			cin>>g[i][j];
			FOR(k,8){
				if(valid(i+dirs[k].f,j+dirs[k].s) && g[i+dirs[k].f][j+dirs[k].s]==g[i][j]){
					merge_set(f(i+dirs[k].f,j+dirs[k].s),f(i,j));
				}	
			}
		}
	queue<int> q;
	FOR(i,r){
		FOR(j,c){
			FOR(k,8){
				if(valid(i+dirs[k].f,j+dirs[k].s) && g[i+dirs[k].f][j+dirs[k].s]!=g[i][j]){
					int u = find_set(f(i,j));
					int v = find_set(f(i+dirs[k].f,j+dirs[k].s));
					G[u].insert(v);
					G[v].insert(u);
				}	
			}
			if(g[i][j]=='W' && dist[find_set(f(i,j))]==INF){
				dist[find_set(f(i,j))] = 0;
				q.push(find_set(f(i,j)));
			}
		}
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		char x = inv(u);
		ans[x-'A'] = min(ans[x-'A'],dist[u]);
		for(int v: G[u]){
			if(dist[v]==INF){
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
	FOR(i,26){
		if(i!=22 && ans[i]!=INF){
			cout<<(char)('A'+i)<<" "<<ans[i]-1<<endl;
		}
	}


	

	return 0;
}
