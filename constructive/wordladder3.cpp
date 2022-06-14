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

string tohex(ll x){
	string n="";
	for(int i=9;i>=0;i--){
		ll k = pow(26,i);
		ll d = x/k;
		n+=d+'a';
		x-=k*d;
	}
	return n;
}

int main()
{
	int n;
	cin>>n;
	ll off1=1,off2=26;
	int i1 = 0;
	ll aoff1 = pow(26,2), aoff2 = pow(26,3);	
	int j1 = 2;
	ll x = 0;	
	FOR(i,n){
		string s = tohex(x);
		cout<<s<<endl;
		if(s[9-i1]=='z' && s[9-i1-1]=='z'){
			x+=aoff1;
			cout<<tohex(x)<<endl;
			x+=aoff2;
			cout<<tohex(x)<<endl;
			off1*=-1;
			off2*=-1;
			x+=off1;
			cout<<tohex(x)<<endl;
		}
		else if(i%2==0){
				x+=off1;
		}
		else{
			x+=off2;
		}
	}
	return 0;
}
