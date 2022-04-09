/*
    Very straight foward string/ad hoc problem. The string input size is only 100. 
    We can start with the complete string and we can greedily try to take the largest 
    substring starting from the beginning and check if its the lexiographically smallest 
    rotation. Once we find the longest substring that matches the criteria we recurse 
    taking away that substring. 
*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

string in;
void solve(int l, int r){
    if(l>=in.size() || l>r) return;
    set<string> all;
    string A = in.substr(l,(r-l)+1);
    for(int i=0;i<(r-l)+1;i++){
        all.insert(A);
        A = A[A.size()-1]+A.substr(0,A.size()-1);
    }
    if(*all.begin()==A){
        cout<<"("<<A<<")";
        solve(r+1,in.size()-1);
    }
    else{
        solve(l,r-1);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>in;
        solve(0,in.size()-1);
        cout<<endl;
    }

    return 0;
}
