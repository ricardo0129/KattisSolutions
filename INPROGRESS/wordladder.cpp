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
vector<string> up(vector<string> gray){
	vector<string> vv;
	int n = gray.size();
	FOR(i,n){
		vv.pb("0"+gray[i]);
	}
	for(int i=n-1;i>=0;i--){
		vv.pb("1"+gray[i]);
	}
	return vv;
}
int main()
{
	vector<string> gray = {"0","1"};
	FOR(i,9){
		gray = up(gray);		
	}
	//(a,b) (c,d) (e,f) 

	return 0;
}
