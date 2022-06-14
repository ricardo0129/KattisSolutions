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

const int N = (int)1e4+1;
vi G[N];
int parent[N];
int sz[N];

int getsz(int u, int p){
	int s = 1;
	for(int v:G[u]){
		if(v!=p){
			parent[v] = u;
			s+=getsz(v,u);
		}
	}
	return sz[u] = s;
}

ll ans = 0;
int node = 0;
void dfs(int u,int p){
	ll t = 0;
	for(int v:G[u]){
		ll s;
		s=sz[v];
		t+=s;
	}
	ll total = 0;
	for(int v:G[u]){
		ll s;
		s=sz[v];
		total+=(t-s)*s;
	}
	total/=2;
	if(ans<total){
		ans = total;
		node = u;
	}


	for(int v:G[u]){
		if(v!=p){
			ll x1 = sz[v];
			ll x2 = sz[u];
			sz[v]+=sz[u]-sz[v];
			sz[u]=sz[u]-x1;
			dfs(v,u);
			sz[v] = x1;
			sz[u] = x2;
		}
	}

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	FOR(i,n){
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	getsz(0,0);
	dfs(0,0);
	cout<<ans<<" ";
	vector<ll> all;
	ll t=0;
	for(int v:G[node]){
		all.pb(getsz(v,node));
		t+=all[all.size()-1];
	}
	ll mini = ans;
	int l = all.size();
	for(int i=0;i<l;i++){
		for(int j=i+1;j<l;j++){
			ll new_sum = ans-all[i]*(t-all[i])-all[j]*(t-all[j])+all[i]*all[j]+(all[i]+all[j])*(t-all[i]-all[j]);
			mini = min(mini,new_sum);
		}
	}
	cout<<mini<<endl;
	return 0;
}
