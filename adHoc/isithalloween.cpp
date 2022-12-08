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
    string month,day;
    cin>>month>>day;
    if(month=="DEC" && day=="25") cout<<"yup\n";
    else if(month=="OCT" && day=="31") cout<<"yup\n";
    else cout<<"nope\n";
    return 0;
}
