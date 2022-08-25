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

map<string,int> mp;
const int N = (int)2e6;
vector<pair<ll,pll>> G[N];
int indeg[N];
ll cost[10000];
ll pres[10000];
int b;

pll dfs(int u){
	if(cost[u]!=-1) return {cost[u],pres[u]};
	pll ans = {0,0};
	for(auto v:G[u]){
		pii x = dfs(v.f);
		x.f+=v.s.f; x.s+=v.s.s;
		if(ans.f>x.f) ans = x;
		else if(ans.f==x.f && x.s>ans.s) ans = x;
		if(ans.f==0) ans = x;
	}
	cost[u] = ans.f;
	pres[u] = ans.s;
	return ans;
}
ll dp[10005][10005];
const ll INF = (ll)1e14;
int main()
{
	int n;
	cin>>b>>n;
	FOR(i,n){
		string derived,base,ing;
		ll cost,pres;
		cin>>derived>>base>>ing;
		cin>>cost>>pres;
		if(mp.count(derived)<=0){
			mp[derived] = mp.size();
		}
		if(mp.count(base)<=0){
			mp[base] = mp.size();
		}
		int u = mp[derived];
		int v = mp[base];
		G[u].pb({v,{cost,pres}});
		indeg[v]++;
	}
	n = mp.size();
	FOR(i,n) cost[i] = -1;
	FOR(i,min(n,1)) FOR(j,b+1) dp[i][j] = 0;

	FOR(i,mp.size()){
		if(indeg[i]==0){
			dfs(i);
		}
	}
	dp[0][0] = 0;
	dp[0][cost[0]] = pres[0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=b;j++){
			dp[i][j] = dp[i-1][j];
			if((j-cost[i])>=0) dp[i][j] = max(dp[i][j],dp[i-1][j-cost[i]]+pres[i]);
		}
	}
		
	if(n==0) cout<<0<<endl<<0<<endl;
	else{
	pll ans = {INF,-INF};
	for(int j=0;j<=b;j++){
		if(ans.s<dp[n-1][j]){
			ans = {(ll)j,dp[n-1][j]};
		}	
	}
	cout<<ans.s<<endl<<ans.f<<endl;
	}

	return 0;
}
