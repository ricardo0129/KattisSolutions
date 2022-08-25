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
	int n;
	cin>>n;
	vll A(n),B(n);
	FOR(i,n) cin>>A[i];
	FOR(i,n) cin>>B[i];
	ll Z[3];
	FOR(i,3) Z[i] = 0;
	FOR(i,n){
		Z[i%3]+=A[i];	
	}
	ll ans[3];
	FOR(i,3) ans[i] = 0;
	//0 white 1 yello 2 pink
	int idx[3]; idx[0] = 0; idx[1] = 1; idx[2] = 2;

	FOR(i,n){
		FOR(j,3){
			ans[j] += B[i]*Z[idx[j]];
		}
		FOR(j,3){
			idx[j] = ((idx[j]-1)%3+3)%3;
		}
	}
	cout<<ans[1]<<" "<<ans[2]<<" "<<ans[0]<<endl;

	return 0;
}
