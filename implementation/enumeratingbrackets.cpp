#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long 
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)
ll INF = 1000000000000000005ll;
ll n,k;
ll dp[2001][2001];

ll add(ll a, ll b){
	if(a+b>=INF) return INF;
	return a+b;
}
ll solve(int i, int open){
	if(i==n){
		if(open!=n/2) return dp[i][open] = 0;
		return dp[i][open] = 1;
	}
	if(dp[i][open]!=-1) return dp[i][open];
	ll a1=0,a2=0;
	int closed = i-open;
	a1=solve(i+1,open+1);
	if(closed+1<=open){
		a2=solve(i+1,open);
	}
	return dp[i][open] = add(a1,a2);
}
char state[2000];
void gen(int i, int open){
	if(i==n){
		return;
	}

	ll c1 = dp[i+1][open+1];
	ll c2 = dp[i+1][open];
	if(k<=c1){
		state[i] = '(';
		gen(i+1,open+1);
	}
	else{
		k-=c1;
		state[i] = ')';
		gen(i+1,open);
	}
}

int main()
{
	cin>>n>>k;
	memset(dp,-1,sizeof dp);
	ll x=solve(0,0);
	gen(0,0);
	FOR(i,n) cout<<state[i];
	cout<<endl;

	return 0;
}
