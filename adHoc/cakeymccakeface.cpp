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


map<ll,int> mp;
vector<pll> G[2000*2000];
int main()
{
	int n,m;
	cin>>n>>m;
	vll A(n),B(m);
	FOR(i,n) cin>>A[i];
	FOR(i,m) cin>>B[i];

	FOR(i,n){
		FOR(j,m){
			if(B[j]>=A[i]){
				ll diff = B[j]-A[i];
				if(mp.count(diff)<=0) mp[diff] = mp.size();
				G[mp[diff]].pb({A[i],B[j]});
			}
		}
	}
	int best = 0;
	ll ans = 0;
	for(auto x: mp){
		int curr = G[x.s].size();
		if(best<curr) {
			best = curr;
			ans = x.f;
		}
	}
	cout<<ans<<endl;
	return 0;
}
