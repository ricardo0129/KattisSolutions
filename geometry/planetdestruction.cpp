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

int locx[10000];
int locy[10000];
int speed[10000];
int spread[10000];
int main()
{
	int t;
	cin>>t;
	while(t--){
		int r,n;
		cin>>r>>n;
		FOR(i,n){
			cin>>locx[i];
			cin>>locy[i];
			cin>>speed[i];
			cin>>spread[i];
		}

	}
	return 0;
}
