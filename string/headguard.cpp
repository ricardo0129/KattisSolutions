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
    string in;
    while(cin>>in){
        char previous = in[0];
        int cc = 0;
        FOR(i,in.size()){
            if(in[i]==previous)cc++;
            else{
                cout<<cc<<previous;
                previous=in[i];
                cc=1;
            }
        }
        cout<<cc<<previous<<endl;
    }
    return 0;
}
