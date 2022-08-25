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
	vi A(3);
	while(true){
		FOR(i,3) cin>>A[i];
		sort(A.begin(),A.end());
		if(A[2]==0) break;
		if((A[0]*A[0]+A[1]*A[1])==(A[2]*A[2])) cout<<"right\n";
		else cout<<"wrong\n";



	}
	return 0;
}
