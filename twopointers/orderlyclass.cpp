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
    string A, B;
    cin>>A>>B;
    //aaaa bc aaaa   aaaa cb aaaa
    int n = A.size();
    int i = 0, j=n-1;
    while(A[i]==B[i]) i++;
    while(A[j]==B[j]) j--;
    bool valid = true;
    //make sure A[i,j] == B[j,i]
    for(int k=i;k<=j;k++){
        if(A[k]!=B[j-(k-i)]) valid = false;
    }
    if(!valid) cout<<0<<endl;
    else{
        int tot = 1;
        i--; j++;
        while(i>=0 && j<n && A[i]==A[j]) i--, j++,tot++;
        cout<<tot<<endl;
    }
    return 0;
}
