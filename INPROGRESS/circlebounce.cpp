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
struct Matrix{
	int r,c;
	vector<vll> m;
	Matrix(int _r, int _c){
		r = _r; c = _c;
		m.assign(_r,vector<ll>(_c,0));
	}
	Matrix operator*(const Matrix& B){
		//this * b = c()
		Matrix cd = Matrix(r,B.c);
		FOR(i,r){
			FOR(j,B.c){
				FOR(k,c){
					cd.m[i][j]+=m[i][k]*B.m[k][j];
				}
			}
		}
		return cd;
	}
	Matrix pow(Matrix a, ll p){
		if(p==0){
			//idenity matrix;
			Matrix idenity(a.r,a.c);
			FOR(i,a.r) idenity.m[i][i] = 1;
			return idenity;
		}
		if(p==1) return a;
		Matrix x = pow(a,p/2);
		x = x*x;
		if(p%2==1) x = x*a;
		return x;
	}
	void print(){
		FOR(i,r){
			FOR(j,c)
			cout<<m[i][j]<<" ";
			cout<<endl;
		}
	}
};
ll bipow(ll a, ll b){
	if(b==0) return 1;
	if(b==1) return a%MOD;
	ll x = bipow(a,b/2)%MOD;
	x = (x*x)%MOD;
	if(b%2==1) x = ((x%MOD)*(a%MOD))%MOD;
	return x;
}
ll divi(ll a, ll b){
	//a/b
	return (a%MOD)*(bipow(b,MOD-2))%MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Matrix m(2,2);
	m.m[0][0] = 0; m.m[0][1] = -1;
	m.m[1][0] = 1; m.m[1][1] = 0;
	


	return 0;
}
