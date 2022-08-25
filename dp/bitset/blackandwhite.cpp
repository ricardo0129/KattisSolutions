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

int n;
double A[20];

int main()
{
	cin>>n;
	FOR(i,n) cin>>A[i];
	vector<double> dp(1<<n);
	FOR(i,1<<n){
		if(__builtin_popcount(i)<=2) continue;
		double allup=1.0, alldown=1.0;
		FOR(j,n){
			if(i&(1<<j)) allup*=A[j];
			if(i&(1<<j)) alldown*=(1-A[j]);
		}
		double tot=0;
		FOR(j,n){
			if(i&(1<<j)){
				double p = (allup/A[j])*(1-A[j]) + (alldown/(1-A[j]))*A[j];
				dp[i]+=p*dp[i-(1<<j)];
				tot+=p;
			}
		}
		dp[i] = (dp[i]+1)/tot;
	}
	printf("%.8lf\n",dp.back());

	return 0;
}
