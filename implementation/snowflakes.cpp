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
	int t;
	cin>>t;
	while(t--){
		int n;
		map<int,int> tree;
		cin>>n;
		vi A(n);
		FOR(i,n) cin>>A[i];
		int ans = 1;
		int prev = 0;
		FOR(i,n){
			if(tree.count(A[i])==0){
				tree[A[i]] = i;
			}
			else{
				prev = max(tree[A[i]]+1,prev);
				tree[A[i]] = i;
			}
			ans = max(ans,i-prev+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
