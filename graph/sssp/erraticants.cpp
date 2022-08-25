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

pii dirs[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		pii loc = {0,0};
		set<pii> all;
		set<pair<pii,pii>> edges;
		all.insert({0,0});
		FOR(i,n){
			char d;
			cin>>d;
			pii y = loc;
			if(d=='E') loc.f+=1;
			else if(d=='W') loc.f-=1;
			else if(d=='N') loc.s+=1;
			else loc.s-=1;
			all.insert(loc);
			edges.insert({y,loc});
			edges.insert({loc,y});
		}
		pii start = {0,0};
		map<pii,int> dist;
		dist[start] = 0;
		queue<pii> q;
		q.push(start);
		while(!q.empty()){
			pii u = q.front(); q.pop();
			for(int i=0;i<4;i++){
				pii v = {u.f+dirs[i].f,u.s+dirs[i].s};
				if(all.find(v)!=all.end() && dist.count(v)==0 && edges.find({u,v})!=edges.end()){
					dist[v] = dist[u]+1;	
					q.push(v);
				}

			}
		}
		//cout<<loc.f<<" "<<loc.s<<endl;
		cout<<dist[loc]<<endl;
	}
	return 0;
}
