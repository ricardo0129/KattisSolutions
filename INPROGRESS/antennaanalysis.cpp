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

struct Tree{
	typedef ll T;
	static constexpr T unit = -INF;
	T f(T a, T b) { return max(a,b); }
	vector<T> s; int n;
	Tree(int n =0, T def = unit) : s(2*n,def), n(n) {}
	void update(int pos, T val){
		for(s[pos+=n] = val;pos/=2;)
			s[pos] = f(s[pos*2],s[pos*2+1]);
	}
	T query(int b, int e){
		T ra = unit, rb = unit;
		for(b+=n,e+=n;b<e;b/=2,e/=2){
			if(b%2) ra = f(ra,s[b++]);
			if(e%2) rb = f(s[--e],rb);
		}
		return f(ra,rb);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; ll c;
	cin>>n>>c;
	vll A(n);
	FOR(i,n) cin>>A[i];
	vll ans(n,0);
	Tree less((int)1e6+10);
	Tree more((int)1e6+10);
	FOR(i,n){
		//if A[j]>=A[i]
		ll L = less.query(0,(int)A[i]+1)+A[i]-c*(i+1);
		ll R = more.query(A[i],(int)1e6+1)-A[i]-c*(i+1);
		more.update(A[i],max(more.query(A[i],A[i]+1), A[i]+c*(i+1)));
		less.update(A[i],max(less.query(A[i],A[i]+1),-A[i]+c*(i+1)));
		ans[i] = max(L,R);
		ans[i] = max(ans[i],(ll)0);
	}


	FOR(i,n) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
