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
    vector<string> A(n);
    FOR(i,n) cin>>A[i];
    vector<string> B = A;
    sort(B.begin(),B.end());
    vector<string> C = B;
    reverse(C.begin(),C.end());


    if(A==B) cout<<"INCREASING\n";
    else if(A==C) cout<<"DECREASING\n";
    else cout<<"NEITHER\n";
        
    

    
    return 0;
}
