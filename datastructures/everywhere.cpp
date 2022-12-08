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
    while(t--){
        int n;
        cin>>n;
        set<string> s;
        FOR(i,n){
            string in;
            cin>>in;
            s.insert(in);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}
