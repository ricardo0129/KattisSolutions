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

char A[100][100];
int main()
{
	int r,c,z;
	cin>>r>>c>>z;
	FOR(i,r) FOR(j,c) cin>>A[i][j];
	int ans = 0;
	pii start = {0,0};
	FOR(i,r-z+1){
		FOR(j,c-z+1){
			int curr = 0;
			FOR(k,z){
				FOR(l,z){
					if(k!=0 && k!=z-1 && l!=0 && l!=z-1) curr+=A[i+k][j+l]=='*';

				}
			}
			if(curr>ans){
				ans = curr;
				start = {i,j};
			}

		}
	}
	cout<<ans<<endl;
	int i = start.f;
	int j = start.s;
	FOR(k,z){
		FOR(l,z){
			if(k!=0 && k!=z-1 && l!=0 && l!=z-1) continue;
			if(k==0 && l==0) A[i+k][j+l] = '+';
			else if(k==0 && l==z-1) A[i+k][j+l] = '+';
			else if(k==z-1 && l==z-1) A[i+k][j+l] = '+';
			else if(k==z-1 && l==0) A[i+k][j+l] = '+';
			else if(k==0 || k==z-1) A[i+k][j+l] = '-';
			else A[i+k][j+l] = '|';
		}
	}
	FOR(i,r){
		FOR(j,c){
			cout<<A[i][j];
		}
		cout<<endl;
	}


	return 0;
}
