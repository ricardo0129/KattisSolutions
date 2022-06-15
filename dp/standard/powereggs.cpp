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

ll dp[40][40];
void precompute(){
	memset(dp,0,sizeof dp);
	for(int i=1;i<=32;i++) dp[1][i] = i;
	for(int i=2;i<=32;i++){
		dp[i][0] = 0;
		for(int j=1;j<=32;j++){
			dp[i][j] = dp[i-1][j-1]+dp[i][j-1]+1;
		}
	}
}
int main()
{
	precompute();
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int i;
		for(i=0;i<=32;i++){
			if(dp[k][i]>=n) break;
		}
		if(dp[k][i]<n) cout<<"Impossible\n";
		else cout<<i<<endl;

	}
	return 0;
}
