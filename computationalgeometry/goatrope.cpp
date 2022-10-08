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
	int x,y;
	double r;
	circle(int _x, int _y, double _r){
		x = _x; y = _y;
		r = _r;
	}
};
struct rect{
	int x1, x2;
	int y1, y2;
	rect(int a,int b, int c, int d){
		x1 = a; y1 = b; x2 = c; y2 = d;
	}
};
bool intersects(circle A, rect B)
{
	int edgeX = (A.x< B.x1) ? B.x1 : (A.x > B.x2) ? B.x2 : A.x;
	int edgeY = (A.y < B.y1) ? B.y1 : (A.y > B.y2) ? B.y2 : A.y;
	int distX = A.x - edgeX, distY = A.y - edgeY;
	return distX * distX + distY * distY <= A.r * A.r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x,y;
	rect R(0,0,0,0);
	cin>>x>>y;
	cin>>R.x1>>R.y1>>R.x2>>R.y2;
	double l = 0.0001, r = 100000.0;
	double ans = r;
	for(int i=0;i<200;i++){
		double M = (l+r)/2.0;	
		if(intersects(circle(x,y,M),R)){
			ans = M;
			r = M-0.00001;
		}
		else l = M+0.00001;
	}
	printf("%.8lf\n",ans);

	return 0;
}
