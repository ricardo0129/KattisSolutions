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


struct Tree{
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b){return max(a,b);}
	vector<T> s; int n;
	Tree(int n=0,T def = unit): s(2*n,def), n(n){}
	void update(int pos, T val){
		for (s[pos+=n] = val; pos/=2;)
			s[pos] = f(s[pos*2],s[pos*2+1]);
	}
	T query(int b, int e){//[b,e)
		T ra = unit, rb = unit;
		for(b+=n,e+=n;b<e;b/=2,e/=2){
			if(b%2) ra = f(ra,s[b++]);
			if(e%2) rb = f(s[--e],rb);
		}
		return f(ra,rb);
	}
};

stack<int> ss;
vector<pii> i1,i2;
pii interval(){
	int l = ss.top();
	int r = ss.top();
	while(!ss.empty()){
		l = ss.top();
		ss.pop();
	}
	return {l,r};
}
int find(vector<pii> A,int v){
	int n = A.size();
	int L = 0, R = n-1;
	while(L<=R){
		int M = (L+R)/2;
		if(A[M].f<=v && v<=A[M].s) return M;
		else if(A[M].s<v){
			L = M+1;
		}
		else R = M-1;
	}
	return -1;
}
int getAns(int l, int r,vector<pii> it, Tree tt){
	int L = find(it,l);
	int R = find(it,r);
	if(L==R){
		return r-l+1;
	}
	int ans = max(it[L].s-l+1,r-it[R].f+1);
	int x1 = L+1,x2 = R-1;
	if(x1<=x2){
		ans = max(ans,tt.query(x1,x2+1));
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	vi A(n);
	FOR(i,n) cin>>A[i];
	FOR(i,n){
		if(ss.empty() || A[ss.top()]<=A[i]) ss.push(i);
		else{
			i1.pb(interval());
			ss.push(i);
		}
	}
	i1.pb(interval());
	FOR(i,n){
		if(ss.empty() || A[ss.top()]>=A[i]) ss.push(i);
		else{
			i2.pb(interval());
			ss.push(i);
		}
	}
	i2.pb(interval());
	cout<<"INCREASING\n";
	for(auto x: i1) cout<<x.f<<" "<<x.s<<endl;
	cout<<"DECREASEING\n";
	for(auto x: i2) cout<<x.f<<" "<<x.s<<endl;
	Tree t1(i1.size());
	FOR(i,i1.size()) t1.update(i,i1[i].s-i1[i].f+1);
	Tree t2(i2.size());
	FOR(i,i2.size()) t2.update(i,i2[i].s-i2[i].f+1);



	int q;
	cin>>q;
	FOR(tt,q){
		int l,r;
		cin>>l>>r;
		l--; r--;
		int ans = max(getAns(l,r,i1,t1),getAns(l,r,i2,t2));
		cout<<ans<<endl;

	}
	return 0;
}
