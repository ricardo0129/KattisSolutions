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
    int diff = 0;
    cin>>diff;
    int rita, theo;
    cin>>rita>>theo;
    int ans = (rita+theo+7+diff)/2;
    cout<<rita-ans<<endl;
    return 0;
}
