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

const int N = 1e5+1;
set<string> students[N];
map<string,int> mp;
int main()
{
	int n;
	cin>>n;
	map<string,int> sign;
	set<string> nn;
	FOR(i,n){
		string fi,la,course;
		cin>>fi>>la>>course;
		string name = fi+"_"+la;
		nn.insert(course);
		if(mp.count(course)<=0){
			mp[course] = mp.size();
		}
		students[mp[course]].insert(name);
	}
	for(auto x: nn){
		cout<<x<<" "<<students[mp[x]].size()<<endl;
	}

	return 0;
}
