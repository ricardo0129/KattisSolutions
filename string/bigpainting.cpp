#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;

struct AhoCorasick {
	enum {alpha = 3, first = '0'}; // change this!
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vi backp;
	void insert(string& s, int j) {
		assert(!s.empty());
		int n = 0;
		for (char c : s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches++;
	}
	AhoCorasick(vector<string>& pat) : N(1, -1) {
		rep(i,0,sz(pat)) insert(pat[i], i);
		N[0].back = sz(N);
		N.emplace_back(0);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			rep(i,0,alpha) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	vi find(string word) {
		int n = 0;
		vi res; // ll count = 0;
		for (char c : word) {
			n = N[n].next[c - first];
			res.push_back(N[n].end);
			// count += N[n].nmatches;
		}
		return res;
	}
	vector<vi> findAll(vector<string>& pat, string word) {
		vi r = find(word);
		vector<vi> res(sz(word));
		rep(i,0,sz(word)) {
			int ind = r[i];
			while (ind != -1) {
				res[i - sz(pat[ind]) + 1].push_back(ind);
				ind = backp[ind];
			}
		}
		return res;
	}
};
vi pi(const vi& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const vi& s, const vi& pat) {
        vi B = pat;
        B.pb(-1);
        for(int x: s) B.pb(x);
	vi p = pi(B), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int pc, pr;
    cin>>pr>>pc;
    int r,c;
    cin>>r>>c;
    unordered_map<string,int> mp;
    vi pattern;
    vector<string> pat;
    FOR(i,pr){
        string row = "";
        cin>>row;
        FOR(j,sz(row)){
            if(row[j]=='x') row[j] = '0';
            else row[j] = '1';
        }
        if(mp.count(row)<=0){
            mp[row] = mp.size();
            pat.pb(row);
        }
        pattern.pb(mp[row]);
    }
    vector<string> A(r);
    FOR(i,r){
        cin>>A[i];
        FOR(j,sz(A[i])){
            if(A[i][j]=='x') A[i][j] = '0';
            else A[i][j] = '1';
        }
    }
    vector<vi> cols(c);
    string big = "";
    FOR(i,r){
        big+=A[i];
    }
    AhoCorasick ac(pat);
    vector<vi> all_pat = ac.findAll(pat,big);
    for(int i=0;i<sz(all_pat);i++){
        if(i%c<c-pc+1){
            if(all_pat[i].size()==0)
                cols[i%c].pb(-1);
            else
                cols[i%c].pb(all_pat[i][0]);
        }
        else cols[i%c].pb(-1);
    }
    ll ans = 0;
    FOR(i,c){
        vi res = match(cols[i],pattern); 
        ans+=res.size();
    }

    cout<<ans<<endl;




    


    return 0;
}
