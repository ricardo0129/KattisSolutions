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
#define sz (int)size
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define pb push_back

const int MOD = (int)1e9+7;
const ll INF = (ll)1e17+7;

const int N = 500;
string A[N][N];

struct SuffixArray {
	vi sa, lcp;
	int n;
	string x;
	SuffixArray(string& s, int lim=256) { // or basic_string<int
		x = s;
		n = sz(s) + 1;int k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
	SuffixArray(){}
	vi idx;
	vi val;
	void precompute(){
		idx.resize(n); val.resize(n);
		int mid = -1;
		for(int i=0;i<sz(sa);i++){
			idx[sa[i]] = i;
			if(sa[i]==0)
				mid = i;
		}
		int mini = 1e8;
		for(int j=mid+1;j<n;j++){
			mini = min(mini,lcp[j]);
			val[j] = mini;
		}
		mini = 1e8;
		for(int j=mid-1;j>=0;j--){
			mini = min(mini,lcp[j+1]);
			val[j] = mini;
		}
	}
	bool check(int k){
		int v = idx[n-k-1];
		return val[v]==k;
	}
};
SuffixArray prefix[N][N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin>>n;
	FOR(i,n) FOR(j,n) cin>>A[i][j];
	FOR(i,n) FOR(j,n){
		if(i==j) continue;
		string left = A[j][i];
		string right = A[i][j];
		string v = left+"#"+right;
		//v = si+sj#sj+si
		prefix[i][j] = SuffixArray(v);
		prefix[i][j].precompute();
	}
	//A[i][j] = si + sj
	vi biggest(n,0);
	for(int i=0;i<n;i++){
		int k = 0;
		int big = 1e7;
		for(int j=0;j<n;j++){
			if(i==j) continue;
			big = min(big,(int)A[i][j].size()-1);
		}
		bool valid = true;
		while(k<big){
			set<char> tot;
			for(int j=0;j<n;j++){
				if(i==j) continue;
				tot.insert(A[i][j][k]);
			}
			if(tot.size()!=1) valid = false;
			if(!valid) break;
			k++;
		}
		biggest[i] = k;
	}

	int valid = 0;
	int k = 1;
	int good = -1;
	while(k<=biggest[0]){
		bool ok = true;
		//length of s0 is fixed at k
		vi len(n,-1);
		for(int s = 0;s<n;s++){
			int length = (s==0)?k:(A[0][s].size()-k);
			len[s] = length;
			for(int j=0;j<n;j++){
				if(j==s) continue;
				//A[s][j]
				if(sz(A[s][j])<length || sz(A[j][s])<length){
					ok = false;
				}
				else if(!prefix[j][s].check(length)){
					ok = false;
				}
			}
			if(length>biggest[s]) ok = false;
		}
		for(int s=0;s<n;s++)
			for(int j=0;j<n;j++){
				if(s==j) continue;
				if(len[s]+len[j]!=sz(A[s][j])) ok = false;
			}	
		valid+=ok;
		if(ok){
			good = k;
		}
		k++;
		if(valid>1) break;
	}
	if(valid==0) cout<<"NONE\n";
	else if(valid>1) cout<<"MANY\n";
	else{
		cout<<"UNIQUE\n";
		for(int s=0;s<n;s++){
			int length = (s==0)?good:(A[0][s].size()-good);
			if(s==0) cout<<A[0][1].substr(0,length)<<endl;
			else cout<<A[0][s].substr(sz(A[0][s])-length,length)<<endl;
			
		}
	}


	return 0;
}
