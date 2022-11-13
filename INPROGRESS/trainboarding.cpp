#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;

int main()
{
    int n,l, p;
    cin>>n>>l>>p;
    vi pos(p);
    FOR(i,p){
        cin>>pos[i];
    }
    int furthest = 0;
    vi curr(n,0);
    FOR(i,p){
        int best = INT_MAX;
        int car = 0;
        int cc = l/2;
        FOR(j,n){
           if(abs(pos[i]-cc)<=best){
                best = abs(pos[i]-cc);
                car = j;
           }
           cc+=l;
        }
        furthest = max(best,furthest);
        curr[car]++;
    }
    int most = 0;
    FOR(i,n) most = max(most,curr[i]);
    cout<<furthest<<endl;
    cout<<most<<endl;
    return 0;
}
