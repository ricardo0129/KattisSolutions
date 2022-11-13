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
    cin>>n;
    FOR(i,n){
        string A, B;
        cin>>A>>B;
        cout<<A<<endl;
        cout<<B<<endl;
        FOR(i,A.size()){
            if(A[i]==B[i]) cout<<".";
            else cout<<"*";
        }
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
