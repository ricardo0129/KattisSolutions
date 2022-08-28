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

int main()
{
	int n,m;
	cin>>n>>m;
	vi rows(n);
	ll a1=0,a2=0;
	FOR(i,n){
		cin>>rows[i];
		a1+=rows[i];
	}
	multiset<int> q;
	FOR(i,m){
		int x;
		cin>>x;
		a2+=x;
		if(x>0) q.insert(x);
	}
	bool ans = a1==a2;
	FOR(i,n){
		bool valid = true;
		stack<int> s;
		FOR(j,rows[i]){
			if(q.size()<=0){
				valid = false;
				break;	
			}
			int x = *q.rbegin();
			x--;
			q.erase(--q.end());
			if(x>0) s.push(x);
		}
		while(!s.empty()){
			q.insert(s.top());
			s.pop();
		}
		ans &= valid;
	}
	if(ans) cout<<"Yes\n";
	else cout<<"No\n";

	return 0;
}
