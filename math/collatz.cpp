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

map<int,int> d;
void depth(ll a,int x){
	d[a] = x;
	if(a==1){
		return;
	}
	if(a%2==0) return depth(a/2,x+1);
	else return depth(a*3+1,x+1);
}
int a1,b1,ans;
void solve(ll a,ll x){
	if(d.count(a)>0){
		ans = a;
		a1 = d[a];
		b1 = x;
		ans = a;
		return;
	}
	if(a%2==0){
		solve(a/2,x+1);
	}
	else solve(a*3+1,x+1);
}

int main()
{
	FOR(i,1500){
		ll a,b;
		cin>>a>>b;
		if(a==0 && b==0) break;
		depth(a,0);
		solve(b,0);

		printf("%d needs %d steps, %d needs %d steps, they meet at %d\n",(int)a,a1,(int)b,b1,ans);
		d.clear();
	}

	return 0;
}
