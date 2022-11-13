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
    int n;
    while(cin>>n){
        if(n==-1) break;
        int previous = 0;
        int total = 0;
        FOR(i,n){
            int mph,t;
            cin>>mph>>t;
            t-=previous;
            total+=mph*(t);
            previous+=t;
        }
        printf("%d miles\n",total);
    }
    return 0;
}
