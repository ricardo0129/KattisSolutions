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

ll INF = (int)1e9;

ll dp[310][60];
ll n,w;

ll s[60];
ll price[60][101];
ll seats[60][101];
ll dp2;


ll solve(int i, int j){
	if(j==w+1) return 0;
	if(i<0){
		return -INF;
	}
	if(i==0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	ll ans = -INF;
	if(j==0){
		FOR(k,s[j]){
			ll s = solve(max(i-seats[j][k],(ll)0),j+1)+price[j][k]*(min((ll)i,seats[j][k]));	
			if(s>ans){
				ans = s;
				dp2 = price[j][k];
			}
			else if(s==ans && dp2>price[j][k]){
				ans = s;
				dp2 = price[j][k];
			}
		}
		return ans;
	}
	FOR(k,s[j]){
		ans = max(ans,solve(max(i-seats[j][k],(ll)0),j+1)+price[j][k]*(min((ll)i,seats[j][k])));	
	}
	return dp[i][j] = ans;
}

int main()
{
	cin>>n>>w;
	FOR(i,w+1){
		ll k;
		cin>>k;
		s[i] = k;
		FOR(j,k){
			cin>>price[i][j];
		}
		FOR(j,k){
			cin>>seats[i][j];
		}
	}
	FOR(i,n+1)
		FOR(j,w+2)
			dp[i][j] = -1;

	cout<<solve(n,0)<<endl;
	cout<<dp2<<endl;



	return 0;
}
