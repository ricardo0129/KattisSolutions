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
//left/right
int dx[] = {0,1,1,1,0,-1,-1,-1}; 
//up/down
int dy[] = {-1,-1,0,1,1,1,0,-1};
bool valid(int i, int j){
	return i>=0 && i<n && j>=0 && j<m;
}

char maze[100][100];
int vist[100][100];
int ans = 0;

void dfs(int i, int j){
	vist[i][j] = true;	
	FOR(k,8){
		int i2 = i+dy[k];
		int j2 = j+dx[k];
		if(valid(i2,j2) && !vist[i2][j2] && maze[i2][j2]=='#') dfs(i2,j2);
	}
}

int main()
{
	cin>>n>>m;
	FOR(i,n){
		FOR(j,m){
			cin>>maze[i][j];
		}
	}
	
	FOR(i,n){
		FOR(j,m){
			if(!vist[i][j] && maze[i][j]=='#'){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}
