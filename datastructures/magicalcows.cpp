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
	int c,n,m;
	cin>>c>>n>>m;
	vll days(c+1);
	FOR(i,n){
		int x;
		cin>>x;
		days[x]++;
	}
	vll ans_arr(51);
	FOR(i,51){
		ll ans = 0;
		FOR(i,c+1) ans+=days[i];
		ans_arr[i] = ans;
		vll next(c+1);
		FOR(i,c+1){
			int cc = 2*i;
			if(cc>c){
				next[(int)(cc/2)] += days[i];
				next[(int)ceil(cc/2.0)] += days[i];
			}
			else{
				next[cc] += days[i];
			}
		}
		days = next;
	}
	FOR(i,m){
		int d;
		cin>>d;
		cout<<ans_arr[d]<<" ";
	}
	cout<<endl;
	return 0;
}
