#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;

int main()
{
    int t;
    cin>>t;
    while(t--){
		int k, b, n;
		cin>>k>>b>>n;
		ll numb = 0;
		for(int i=0;n;i++, n=n/10){
			 numb+=pow(b,i)*(n%10);
		}
		ll ans = 0;
		while(numb){
			ans+=(numb%10)*(numb%10);
			numb/=10;
		}
		cout<<k<<" "<<ans<<endl;
    }
    return 0;
}
