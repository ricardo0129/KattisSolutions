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
    vector<string> A(8);
    FOR(i,8) cin>>A[i];
    vector<pii> q;
    vi row(8,0), col(8,0);
    bool valid = true;
    FOR(i,8) FOR(j,8){
        if(A[i][j]=='*'){
            q.pb(make_pair(i,j)); 
            if(row[i]) valid = false;
            if(col[j]) valid = false;
            row[i]++;
            col[j]++;
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<i;j++){
            if(abs(q[i].f-q[j].f)==abs(q[i].s-q[j].s)) valid = false;
        }
    }
    cout<<(valid?"valid":"invalid")<<endl;

    return 0;
}
