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

vi A;
vi B;
int b,p;
int dp[1010][1000*100][2];
int main()
{
    cin>>b>>p;
    A.resize(p+1);
    FOR(i,p) cin>>A[i];
    reverse(A.begin(),A.end());
    int f=0;
    for(;f<p;f++){
        if(A[f]!=0) break;
    }
    B.assign(p+1,0);
    B[f] = b-A[f];
    f++;
    for(;f<p;f++){
        B[f] = b-1-A[f];
    }
	dp[0][0][0] = 
    
    return 0;
}
