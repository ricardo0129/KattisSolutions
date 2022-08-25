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

const ll INF = (int)1e8;
int r,c,k;
int A[500][500];
ll dp[500][501][20];
int pass[500][500];
bool valid(int i, int j){
	return i>=0 && i<r && j>=0 && j<c && A[i][j]!=-1;
}
ll solve(int i, int j, int kc){
	if(kc>k) return INF;
	if(j==c){
		if(kc==k) return 0;
		else return INF;
	}
	if(j==c-1) return solve(i,j+1,kc+pass[i][j])+A[i][j];
	if(dp[i][j][kc]!=-1) return dp[i][j][kc];
	ll ans = INF;
	if(valid(i+1,j+1)) ans = min(ans,solve(i+1,j+1,kc+pass[i][j])+A[i][j]);
	if(valid(i-1,j+1)) ans = min(ans,solve(i-1,j+1,kc+pass[i][j])+A[i][j]);
	if(valid(i  ,j+1)) ans = min(ans,solve(i  ,j+1,kc+pass[i][j])+A[i][j]);
	return dp[i][j][kc] = ans;
}


int main()
{
	cin>>r>>c>>k;
	FOR(i,r)
		FOR(j,c)
			cin>>A[i][j];

	FOR(i,r){
		FOR(j,c){
			if( valid(i-1,j) && valid(i+1,j) && valid(i,j+1) && valid(i,j-1)){
				if(A[i][j]>A[i][j-1] && A[i][j]>A[i][j+1] && A[i][j]<A[i+1][j] && A[i][j]<A[i-1][j]) pass[i][j] = 1;
			}
		}	
	}
	FOR(i,r) FOR(j,c+1) FOR(s,k+1) dp[i][j][s] = -1;
	ll ans = INF;
	FOR(i,r){
		if(valid(i,0))
		ans = min(ans,solve(i,0,0));
	}
	if(ans>=INF) cout<<"impossible\n";
	else cout<<ans<<endl;


	return 0;
}
