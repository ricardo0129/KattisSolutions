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
    int n = A.size();
    int same = 0, diff = 0;
    FOR(i,n){
       if(A[i]==B[i]) same++;
       else diff++;
    }
    int notcorrect = n-correct;
    if(correct<same) cout<<correct+diff<<endl;
    else cout<<notcorrect+same<<endl;
    return 0;
}
