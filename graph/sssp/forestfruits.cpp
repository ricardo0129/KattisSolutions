#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long 
#define vll vector<ll>
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back

const int MOD = (int)1e9+7;
const ll INF = (ll)1e16+7;
int v,e,c;
ll k,m;
const int N = (int)2e4+1;
vector<pii> G[N];
bool fruit[N];

void make_edge(int u, int v,int w){
	G[u].pb({v,w});
	G[v].pb({u,w});
}

int main()
{
	cin>>v>>e>>c>>k>>m;		
	FOR(i,e){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		make_edge(u,v,w);
	}
	FOR(i,c){
		int a;
		cin>>a;
		a--;
		fruit[a] = true;
	}
	set<pll> q;
	vll dist(v,INF);
	dist[0] = 0 ;
	q.insert({0,0});
	
	while(!q.empty()){
		pll fr = *q.begin();
		q.erase(q.begin());
		if(dist[fr.s]<fr.f) continue;
		for(pii v:G[fr.s]){
			if(dist[v.f]>dist[fr.s]+v.s){
				dist[v.f] = dist[fr.s]+v.s;
				q.insert({dist[v.f],v.f});
			}
		}
	}
	vll paths;
	FOR(i,v){
		if(fruit[i] && dist[i]!=INF) paths.push_back(dist[i]);
	}
	sort(paths.begin(),paths.end());
	c = paths.size();
	if(paths.size()==0 || (c<k && m>c)) cout<<-1<<endl;
	else{
		ll ans = 0;
		FOR(i,min({(ll)m,(ll)k,(ll)c})){
			ans = max(ans,paths[i]*2);
		}
		cout<<ans<<endl;


	}

	return 0;
}
