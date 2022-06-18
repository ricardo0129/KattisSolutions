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

bool used[(int)5e5];
int remain[1000];
int A[1000];
map<string,int> mp;
vi G[(int)5e5];
int main()
{
	int n;
	cin>>n;
	queue<int> q;

	FOR(i,n){
		string in;
		cin>>in;
		
		if(in=="if"){
			int type = 0;
			int j=0;
			int all = 0;
			while(true){
				cin>>in;		
				if(in=="then") break;
				if(j%2==1){
					if(in=="and") type = 1;
				}
				else{
					if(!mp.count(in)){
						mp[in] = mp.size();
					}
					G[mp[in]].pb(i);
					all++;
				}
				j++;
			}
			cin>>in;
			if(!mp.count(in)) mp[in] = mp.size();
			A[i] = mp[in];
			remain[i] = (type==0)?1:all;
		}
		else{
			if(!mp.count(in)){
				mp[in] = mp.size();
			}
			if(!used[mp[in]]){
				q.push(mp[in]);
				used[mp[in]] = true;
			}
		}
	}
	int ans = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		ans++;
		for(int v:G[u]){
			remain[v]--;
			if(remain[v]==0 && !used[A[v]]){
				used[A[v]] = true;
				q.push(A[v]);
			}
		}
	}

	cout<<ans<<endl;

	
	return 0;
}
