
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
    string encoding;
    getline(cin,encoding);
    string ids;
    cin>>ids;
    int n = ids.size();
    FOR(i,n/3){
        string v = string(1,ids[i*3])+string(1,ids[i*3+1])+string(1,ids[i*3+2]);
        int value = stoi(v);
        cout<<encoding[value-1];
    }
    cout<<endl;
    return 0;
}
