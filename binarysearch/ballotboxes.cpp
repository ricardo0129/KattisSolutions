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
	while(true){
		int n,b;
		cin>>n>>b;
		if(n==-1 && b==-1) break;
		vi A(n);
		FOR(i,n) cin>>A[i];

		int L = 1, R = (int)5e6;
		int ans = R;
		while(L<=R){
			int M = (R-L)/2+L;
			int boxes=0;
			FOR(i,n){
				boxes+=ceil(A[i]/(double)M);
			}
			if(boxes<=b){
				R =  M-1;	
				ans = M;
			}
			else{
				L = M+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
