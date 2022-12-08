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

int main()
{
    //s=0, h=1, d=2, c=3
    map<char,int> suit; suit['s'] = 0; suit['h'] = 1; suit['d'] = 2; suit['c'] = 3;
    map<char,int> vv; vv['T'] = 10; vv['J'] = 11; vv['Q'] = 12; vv['K'] = 13; vv['A'] = 14;
    for(char i = '2';i<='9';i++) vv[i] = i-'0';
    int n;
    cin>>n;
    vector<string> cards;
    cards.resize(n);
    vector<pii> vals;
    FOR(i,n) cin>>cards[i];
    FOR(i,n)
        vals.pb({vv[cards[i][0]],suit[cards[i][1]]});
    
    vi s(4); FOR(i,4) s[i] = i;
    int ans = INT_MAX;
    for(int tt=0;tt<(1<<4);tt++){
        vi v = s;
        do{
            vector<pii> B = vals;
            auto comp = [&](const pii& l, const pii& r){
                int l1 = v[l.s];
                int r1 = (tt&(1<<l.s))?-l.f:l.f;
                int l2 = v[r.s];
                int r2 = (tt&(1<<r.s))?-r.f:r.f;
                if(l1==l2) return r1<r2;
                return l1<l2;
            };
            vector<pii> C = vals;
            int dp[n];
            int moves = 1;
            dp[0] = 1;
            for(int i=1;i<n;i++){
                dp[i] = 0;
                for(int j=0;j<i;j++){
                    if(comp(C[j],C[i])) dp[i] = max(dp[i],dp[j]);
                }
                dp[i]++;
                moves = max(dp[i],moves);
            }
            ans = min(ans,n-moves);
        }while(next_permutation(v.begin(),v.end()));
    }


    cout<<ans<<endl;
    return 0;
}
