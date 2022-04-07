#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

int n,k,t;
int t0;
vector<pair<int,double>> A;

double solve(int i, int t1, int s){ 
    if(i==n){
        if(s==k-1 && t1<=t0) return 1.0;
        else return 0.0;
    }
    return solve(i+1,t1,s)*0.5+ (solve(i+1,t1+A[i].first,s+1)*(A[i].second)+solve(i+1,t1,s+1)*(1.0-A[i].second))*0.5;
}

int main()
{
    cin>>n>>k>>t;
    A.resize(n);
    for(int i=0;i<n;i++){
        cin>>A[i].second>>A[i].first;
    }
    t0 = t-A[0].first;
    double t1 = solve(1,0,0);
    cout<<t1*A[0].second<<endl;
    cout<<(k)/(double)(n*n)<<endl;

    return 0;
}


/*
3 2 100
0.3432 99
0.1231 100
0.5878 2




0.5*((1-0.1231))+0.5











*/
