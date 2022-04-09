#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool ans = true;
        vector<string> A(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        sort(A.begin(),A.end());
        reverse(A.begin(),A.end());
        for(int i=1;i<n;i++){
            int k = A[i].size();
            int l = A[i-1].size();
            bool matched = true;
            if(k>l) matched = false;
            else{
                for(int j=0;j<k;j++){
                    if(A[i][j]!=A[i-1][j]) matched = false;
                }
            }
            if(matched) ans = false;

        }

        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
