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
	ll n;
	cin>>n;
	vi bits;
	FOR(i,32-__builtin_clz(n)){
		bits.pb((n&(1<<i))>0);
	}
	reverse(bits.begin(),bits.end());
	ll ans = 0;
	FOR(i,bits.size()){
		ans |= (bits[i]<<i);
	}
	cout<<ans<<endl;

	return 0;
}
