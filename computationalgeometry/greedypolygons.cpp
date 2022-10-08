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
const ll INF = (ll)1e17+7;

double cot(double a){
	return 1.0/tan(a);
}
double solve(int n, int l, int d, int g){
	double polygon_area = 0.25*n*l*l*cot(M_PI/n);
	double blocks = n*l*d*g;
	double circle = (M_PI*g*g*d*d);
	return blocks+circle+polygon_area;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,l,d,g;
		cin>>n>>l>>d>>g;
		printf("%.12lf\n",solve(n,l,d,g));
	}

	return 0;
}
