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

int main()
{
	map<int,int> x,y;
	FOR(i,3){
		int xx,yy;
		cin>>xx>>yy;
		x[xx]++;
		y[yy]++;
	}
	for(auto s: x){
		if(s.second==1) cout<<s.first<<" ";
	}
	for(auto s: y){
		if(s.second==1) cout<<s.first<<" ";
	}
	cout<<endl;
	return 0;
}
