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

bool used[360][60][60];
int c1,c2,c3;
void cut(int a, int b, int c){
	int k = 0;
	c3+=c;
	k = c3/60;
	c3 = c3%60;
	c2 += b+k;
	k = c2/60;
	c2 = c2%60;
	c1 += a+k;
	c1 = c1%360;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		ll r,n;
		cin>>r>>n;
		int a1,a2,a3;
		cin>>a1>>a2>>a3;
		c1=c2=c3=0;
		FOR(i,360) FOR(j,60) FOR(k,60) used[i][j][k] = false;
		FOR(i,n){
			if(used[c1][c2][c3]) break;
			used[c1][c2][c3] = true;
			cut(a1,a2,a3);
		}
		c1 = c2 = c3 = 0;
		long double big = 0.0;
		long double prev = 0.0;
		for(int i=0;i<360*60*60;i++){
			cut(0,0,1);
			long double d = c1+(c2/(long double)60.0)+(c3/(long double)3600.0);
			if(!used[c1][c2][c3]) continue;
			if(d==0) big = max(big,360-prev);
			else big = max(big,d-prev);
			prev = d;
		}
		if(n==1) big = 360.0;
		long double ans = acos(-1)*r*r*(big/360.0);

		printf("%.6Lf\n",ans);
	}
	return 0;
}
