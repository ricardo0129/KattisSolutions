#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long 
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back

const int MOD = (int)1e9+7;
const ll INF = (ll)1e17+7;
int G[13][13];
int best[13];
int curr[13];
bool used[13];
int n;
bool found;
int solve(int i){
	if(i==n){
		//valid sequence
		if(!found){
			FOR(j,n) best[j] = curr[j];
			found = true;
		}
		return 1;
	}
	int tot = 0;
	FOR(j,n){
		if(!used[j]){
			if(i==0 || G[j][curr[i-1]]==0){
				curr[i] = j;
				used[j] = true; 
				tot+=solve(i+1);
				used[j] = false;
			}
		}
	}
	return tot;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<string> A(n);
		map<string,int> mp;
		FOR(i,n){
			cin>>A[i];
			mp[A[i]] = i;
		}
		memset(G,0,sizeof G);
		int m;
		cin>>m;
		FOR(i,m){
			string a,b;
			cin>>a>>b;
			int u = mp[a], v = mp[b];
			G[u][v] = 1;
			G[v][u] = 1;
		}
		memset(used,0,sizeof used);
		found = false;
		int ans = solve(0);
		cout<<ans<<endl;
		FOR(i,n) cout<<A[best[i]]<<" ";
		cout<<endl;

	}
	return 0;
}
