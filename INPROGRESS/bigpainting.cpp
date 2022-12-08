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
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MOD = (int)1e9+7;
const ll INF = (ll)1e17+7;
vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s),res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) res.pb(i - 2 * sz(pat));
	return res;
}
//	  grid_row, pattern row
int Q[2000][2000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin>>n>>m;
	int r,c;
	cin>>r>>c;
	vector<string> style;
	FOR(i,n){
		string in;
		cin>>in;
		style.pb(in);
	}
	vector<string> g;	
	FOR(i,r){
		string in;
		cin>>in;
		g.pb(in);	
	}
	FOR(i,r){
		 = match(g[i],style[j]);

	}
	int ans = 0;
	FOR(i,r-n+1){
		int mini = INT_MAX;
		FOR(j,n){
			mini = min((int)Q[i+j][j],mini);
		}
		ans+=mini;
	}
	cout<<ans<<endl;

	return 0;
}
