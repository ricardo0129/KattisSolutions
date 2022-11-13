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
    int correct;
    cin>>correct;
    string A,B;
    cin>>A>>B;
    int match = 0;
    int n = A.size();
    FOR(i,n){
        if(A[i]==B[i]) match++;
    }
    int notcorrect = A.size()-correct;
    int notmatch = A.size()-match;
    if(match<=correct) cout<<match+notcorrect<<endl;
    else cout<<correct+notmatch<<endl;
    

    return 0;
}
