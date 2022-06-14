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

ll times[10][2];
ll k[10][3];
int main()
{
	FOR(i,10)
		FOR(j,2)
			cin>>times[i][j];
	FOR(i,10){
		FOR(j,3) cin>>k[i][j];
	}

	ll curr = 0;
	FOR(i,3){
		FOR(j,10){
			if(k[j][2]>curr){
				k[j][2] = max(k[j][2],curr+times[j][0]);
				curr+=times[j][0]+times[j][1];
			}
			else{
				ll cyc = (curr-k[j][2])/(k[j][0]+k[j][1]);
				curr = max(cyc*(k[j][0]+k[j][1])+k[j][2]+k[j][0],curr);
				k[j][2] = curr+times[j][0];
				curr+=times[j][0]+times[j][1];
			}
		}
	}
	cout<<curr-times[9][0]<<endl;
	
	return 0;
}
