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
bool valid(int i, int j){
	return i>=0 && i<n && j>=0 && j<m;
}
int main()
{
	map<char,pii> dirs;
	dirs['E'] = {0,1}; dirs['W'] = {0,-1}; dirs['S'] = {1,0}; dirs['N'] = {-1,0};
	cin>>n>>m;
	char g[n][m];
	int dist[n][m];
	FOR(i,n){
		FOR(j,m){
			cin>>g[i][j];
			dist[i][j] = -1;
		}

	}

	queue<int> x,y;
	x.push(0); y.push(0);
	dist[0][0] = 0;
	bool poss = true;
	int ans = -1;
	while(!x.empty()){
		int i = x.front(); x.pop();
		int j = y.front(); y.pop();
		if(g[i][j]=='T'){
			ans = dist[i][j];
			break;
		}
		pii d = dirs[g[i][j]];
		if(!valid(i+d.f,j+d.s)){
			poss = false;
			break;
		}
		else if(dist[i+d.f][j+d.s]==-1){
			dist[i+d.f][j+d.s] = dist[i][j]+1;
			x.push(i+d.f); y.push(j+d.s);
		}
	}
	if(!poss) cout<<"Out"<<endl;
	else if(ans==-1) cout<<"Lost"<<endl;
	else cout<<ans<<endl;

	return 0;
}
