#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long 
#define vll vector<ll>
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back

const int MOD = (int)1e9+7;

int main()
{
	int n;
	cin>>n;
	vll primes;
	int highest = 1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			highest = max(highest,i);
			highest = max(highest,n/i);
		}
	}
	cout<<(n-1)-highest+1<<endl;

	return 0;
}
