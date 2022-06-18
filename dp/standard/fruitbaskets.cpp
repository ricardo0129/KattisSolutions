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

int A[40];
ll dp[40][1000*40+100];
int main()
{
	int n;
	cin>>n;
	int max_w = 0;
	FOR(i,n){
		cin>>A[i];
		max_w+=A[i];
	}
	dp[0][0] = 1;
	dp[0][A[0]] = 1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=max_w;j++){
			dp[i][j] = dp[i-1][j];
			if(j-A[i]>=0) dp[i][j]+=dp[i-1][j-A[i]];
		}
	}
	
	ll ans = 0;
	for(int j=200;j<=max_w;j++) ans+=j*dp[n-1][j];
	cout<<ans<<endl;

	return 0;
}
