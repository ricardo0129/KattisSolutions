#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;

int main()
{
    string in;
    cin>>in;
    int n = sz(in);
    if(in=="1") cout<<1<<endl;
    else if(n<10){
        //solve seperately 
        int fact = 1;
        int numb = stoi(in);
        int i = 1;
        while(fact<numb){
            fact*=i;
            i++;
        }
        cout<<i-1<<endl;
    }
    else{
        int i = 1;
        double v = 0;
        while((int)ceil(v)<n){
           v+=log10(i++); 
        }
        cout<<i-1<<endl;
    }
    return 0;
}
