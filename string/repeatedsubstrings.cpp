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
struct SuffixArray{
    vi sa,lcp;
    string A;
    SuffixArray(string& s, int lim=256){
        A = s;
        int n = sz(s)+1,k=0,a,b;
        vi x(all(s)+1), y(n), ws(max(n,lim)),rank(n);
        sa = lcp = y, iota(all(sa),0);
        for(int j = 0, p = 0; p<n;j=max(1,j*2),lim=p){
            p = j, iota(all(y),n-j);
            rep(i,0,n) if(sa[i]>=j) y[p++] = sa[i]-j;
            fill(all(ws),0);
            rep(i,0,n) ws[x[i]]++;
            rep(i,1,lim) ws[i]+=ws[i-1];
            for(int i=n;i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x,y), p = 1, x[sa[0]] = 0;
            rep(i,1,n) a = sa[i-1], b = sa[i], x[b] = 
            (y[a]==y[b] && y[a+j] == y[b+j]) ? p-1 : p++;
        }
        rep(i,1,n) rank[sa[i]] = i;
        for(int i=0,j;i<n-1;lcp[rank[i++]] = k)
            for( k && k--, j = sa[rank[i]-1];
                s[i+k] == s[j+k]; k++);
            
        
    }
    string solve(){
        int maxi = 0;
        int idx = -1;
        string ans = "";
        FOR(i,sz(lcp)){
            if(maxi<lcp[i]){
               maxi = lcp[i]; 
               idx = i;
            }
        }
        return A.substr(sa[idx],maxi);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string A;
    cin>>A;
    SuffixArray sa(A);
    string ans = sa.solve();
    cout<<ans<<endl;
    return 0;
}
