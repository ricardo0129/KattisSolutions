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
const ll INF = (ll)1e17+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> all;
		FOR(i,n){
			int k;
			cin>>k;
			int total =0;
			FOR(j,k){
				int x;
				cin>>x;
				total+=x;
			}
			all.pb(total);
		}
		sort(all.begin(),all.end());
		double ans = 0;
		ll sum = 0;
		FOR(i,n){
			sum+=all[i];
			ans+=sum;
		}
		ans/=n;
		printf("%.8lf\n",ans);
	}
	return 0;
}
