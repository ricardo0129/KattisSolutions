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
    int curr = 1;
    bool valid = true;
    FOR(i,n){
        string in;
        cin>>in;
        if(in=="mumble"){
            curr++;
        }
        else if(in==to_string(curr)){
            curr++;
        }
        else valid = false;
    }
    if(valid) cout<<"makes sense\n";
    else cout<<"something is fishy\n";
    return 0;
}
