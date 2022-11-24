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
    int x;
    cin>>x;
    int y = 100-x;
    printf("%.8lf\n%.8lf\n",(x+y)/(double)x,(x+y)/(double)y);
    return 0;
}
