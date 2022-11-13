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
    int t;
    cin>>t;
    FOR(i,t){
        int b; double t;
        cin>>b>>t;
        printf("%.4lf %.4lf %.4lf\n",60.0/(t/(b-1)),(60.0*b)/t,60.0/(t/(b+1)));
    }
    return 0;
}
