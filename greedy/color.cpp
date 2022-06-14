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
	int s,c,k;
	cin>>s>>c>>k;
	vi A(s);
	FOR(i,s) cin>>A[i];
	sort(A.begin(),A.end());
	int i = 0;
	int ans = 0;
	for(int j=0;j<s;j++){
		if( (A[j]-A[i])>k || (j-i+1)>c){
			ans++;
			i = j;
		}
	}
	ans++;
	cout<<ans<<endl;

	return 0;
}
