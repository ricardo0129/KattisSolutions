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

int n,m;
int solve(vector<pii>& A){
    priority_queue<int,vi,greater<int>> pq;
    int ans = 0;
    FOR(i,n){
        int b=A[i].f,e=A[i].s;
        //cout<<b<<" "<<e<<endl;
        //remove the idle computers after m minutes
        while(pq.size()>0 && pq.top()<b-m)
            pq.pop();
        if(pq.size()==0 || (pq.top()>b))
            ans++;
        else
            pq.pop();
        
        pq.push(e);

    }
    return n-ans;
}
int main()
{
    scanf("%d %d", &n, &m);
    //insert endpoints
    vector<pii> A(n);
    FOR(i,n) scanf("%d %d", &A[i].f, &A[i].s);
    FOR(i,n) A[i].s+=A[i].f;
    sort(A.begin(),A.end());
    int ans = solve(A);
    printf("%d\n",ans);
        
    return 0;
}
