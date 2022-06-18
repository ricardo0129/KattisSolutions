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

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int n;
	cin>>n;
	vi A(n);
	FOR(i,n)cin>>A[i];
	
	int ans = 0;
	for(int i=1;i<=100;i++){
		int g = -1;
		bool possible = false;
		FOR(j,n){
			if(A[j]%i==0){
				if(g==-1) g = A[j];
				else g = gcd(g,A[j]);
			}
			else{
				g = -1;
			}
			if(g==i) possible = true;
		}
		if(possible) ans++;
	}
	
	cout<<ans<<endl;
	return 0;
}
