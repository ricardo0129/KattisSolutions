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

ll n,k;
ll A[100];
ll dp[105][105][3];

ll solve(int i, int c,int rest){
	if(i>=n) return 0;
	if(dp[i][c][rest]!=-1) return dp[i][c][rest];
	ll ks = k;
	FOR(j,c){
		ks = ks*2/3;
	}
	ll eat = min(ks,A[i]);
	eat = eat + solve(i+1,c+1,0);
	ll new_c;
	if(rest==0) new_c = max(0,c-1);
	else new_c = 0;
	ll stop = solve(i+1,new_c,1);
	return dp[i][c][rest] = max(eat,stop);
}
int main()
{
	cin>>n>>k;
	FOR(i,n) cin>>A[i];
	FOR(i,n) FOR(j,n) FOR(s,3) dp[i][j][s] = -1;
	cout<<solve(0,0,1)<<endl;
	
	return 0;
}
