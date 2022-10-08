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
	int n;
	cin>>n;
	vi A(n);
	FOR(i,n) cin>>A[i];
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());
	double ans = 0;

	FOR(i,n){
		ans+=A[i]*pow(0.8,i);
	}
	printf("%.8lf\n",0.2*ans);
	ans = 0;
	FOR(i,n){
		double curr = 0;
		int k = 0;
		FOR(j,n){
			if(i==j) continue;
			curr+=A[j]*pow(0.8,k++);
		}
		curr*=0.2;
		ans+=curr;
	}
	printf("%.8lf\n",ans/n);
	return 0;
}
