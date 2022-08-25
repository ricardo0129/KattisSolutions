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
	ll w;
	cin>>w;
	int n;
	cin>>n;
	ll area = 0;
	FOR(i,n){
		ll x,y;
		cin>>x>>y;
		area+=x*y;
	}
	cout<<area/w<<endl;
	return 0;
}
