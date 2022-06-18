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

bool is_prime[32000];
vi primes;
void precompute(){
	memset(is_prime,true,sizeof is_prime);
	is_prime[0] = is_prime[1] = false;
	for(int i=2;i<32000;i++){
		if(is_prime[i]){
			primes.pb(i);
			for(int j=i*2;j<32000;j+=i){
				is_prime[j] = false;	
			}
		}
	}
}

int main()
{
	precompute();

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<pii> ans;
		for(auto x: primes){
			if(x>=n) break;	
			if(is_prime[n-x]){
				ans.insert({min(x,n-x),max(x,n-x)});
			}
		}
		printf("%d has %d representation(s)\n",n,(int)ans.size());
		for(auto x: ans){
			cout<<x.f<<"+"<<x.s<<endl;
		}
	}
	return 0;
}
