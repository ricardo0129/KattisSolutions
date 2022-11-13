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
pii expected(int a1, int b1, int a2, int b2){
    int sum = 0;
    int sides = 0;
    for(int i=a1;i<=b1;i++){
        for(int j=a2;j<=b2;j++){
            sum+=i+j;
            sides++;
        }
    }
    return {sum,sides};
}

int main()
{
    int a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    pii g = expected(a1,b1,a2,b2);
    cin>>a1>>b1>>a2>>b2;
    pii e = expected(a1,b1,a2,b2);
    if(g.f*e.s==e.f*g.s) cout<<"Tie\n";
    else if(g.f*e.s<e.f*g.s) cout<<"Emma\n";
    else cout<<"Gunnar\n";
    
    return 0;
}
