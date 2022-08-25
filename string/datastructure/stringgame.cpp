#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define FOR(i,n) for(int i=0;i<n;i++)

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}
struct SegTree{
        vi A,vt;
        int n;
        int left(int p){return p<<1;}
        int right(int p ){return (p<<1)|1;}
        void init(int p, int l, int r){
                if(l==r){
                        vt[p] = A[l];
                        return;
                }
                int m = (l+r)/2;
                init(left(p),l,m);
                init(right(p),m+1,r);
                vt[p] = vt[left(p)]+vt[right(p)];
        }
        int query(int p, int l, int r, int i, int j){
                if(i<=l && r<=j) return vt[p];
                if(r<i || l>j) return 0;
                int m = (r+l)/2;
                int L = query(left(p),l,m,i,j);
                int R = query(right(p),m+1,r,i,j);
                return L+R;
        }
        void update(int p, int l, int r, int i, ll v){
                if(l==r){
                        vt[p] = v;
                        return;
                }
                int m = (l+r)/2;
                if(i<=m) update(left(p),l,m,i,v);
                else update(right(p),m+1,r,i,v);
                vt[p] = vt[left(p)]+vt[right(p)];
        }
        int query(int i, int j){
                return query(1,0,n-1,i,j);
        }
        void update(int i, ll v){
                update(1,0,n-1,i,v);
        }
        SegTree(vi& B){
                n = B.size();
                A = B;
                vt.resize(4*n);
                init(1,0,n-1);
        }
};

string in,last;
int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>in>>last;
		vi pi = rabin_karp(last,in);
		vi valid(in.size(),false);
		FOR(i,in.size()) valid[i] = false;
		FOR(i,pi.size()) valid[pi[i]] = true;
		int k = (int)in.size()-(int)last.size();
		int alice = (k/2);
		int bob = (k/2)+(k%2==1);
		bool possible = true;

		SegTree st(valid);

		FOR(i,bob+1){
			int ss = i, rr = i+alice;
			bool curr = false;
			int js = st.query(ss,rr);
			if(js>0) curr  = true;
			possible &= curr;
		}
		if(!bob){
			possible = valid[0];
		}
		if(possible) cout<<"Alice\n";
		else cout<<"Bob\n";



	}
	return 0;
}
