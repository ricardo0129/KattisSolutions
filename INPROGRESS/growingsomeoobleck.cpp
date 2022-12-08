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

struct circle{
	double x,y,r,s;
	circle(){}
	circle(double _x, double _y, double _r, double _s){
		x = _x; y = _y; r = _r; s = _s;
	}
	void expand(double t){
		r+=s*t;
	}
};
vector<circle> A;
double dist(int i, int j){
	return sqrt((A[i].x-A[j].x)*(A[i].x-A[j].x)+
		    (A[i].y-A[j].y)*(A[i].y-A[j].y));
}
double time(int i, int j){
	double d1 = dist(i,j)-A[i].r-A[j].r;
	double ex1 = A[i].s+A[j].s;
	return d1/ex1;
}
circle combine(vi all, double t){
	set<int> unique;
	for(int v: all) unique.insert(v);
	double x = 0, y = 0, r = 0, s =0;
	for(int v: unique){
		x+=A[v].x;
		y+=A[v].y;
		s = max(s,A[v].s);
		r+=(A[v].r+A[v].s*t)*(A[v].r+A[v].s*t);
	}
	int n = unique.size();
	x/=n; y/=n; r = sqrt(r);
	return circle(x,y,r,s);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	A.resize(n);
	for(circle& c: A){
		cin>>c.x>>c.y>>c.r>>c.s;
	}
	while(A.size()>1){
		vector<pii> B;
		FOR(i,A.size()){
			FOR(j,i){
				B.pb(make_pair(i,j));
			}
		}
		sort(B.begin(),B.end(),[&](pii& lhs, pii& rhs){
			return time(lhs.f,lhs.s)<time(rhs.f,rhs.s);
		});
		vi cc;
		cc.pb(B[0].f); cc.pb(B[0].s);
		double t1 = time(B[0].f,B[0].s);
			for(int j=1;j<B.size();j++){
				double t2 = time(B[j].f,B[j].s);	
				if( t2<0 || abs(t2-t1)<1e-9){
					cc.pb(B[j].f);
					cc.pb(B[j].s);
				}
				else break;
			}	
		t1 = max(t1,0.0);
		circle big = combine(cc,t1);
		set<int> unique;
		for(int x: cc) unique.insert(x);
		vi all;
		for(int x: unique) all.pb(x);
		for(int i=all.size()-1;i>=0;i--){
			A[all[i]] = A.back();
			A.pop_back();
		}
		FOR(i,A.size()) 
			A[i].expand(t1);
		A.pb(big);
	}
	printf("%.8lf %.8lf\n%.8lf\n",A[0].x,A[0].y,A[0].r);
	return 0;
}
