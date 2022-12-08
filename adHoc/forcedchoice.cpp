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
    int n,c,t;
    cin>>n>>c>>t;
    FOR(i,t){
        int k;
        cin>>k;
        bool inside = false;
        FOR(j,k){
            int x;
            cin>>x;
            if(x==c) inside = true;
        }
        if(inside) cout<<"KEEP\n";
        else cout<<"REMOVE\n";
    }
    return 0;
}
