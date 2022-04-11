#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

int main()
{
    int n,k;
    cin>>n>>k;
    vector<pii> A;
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        A.push_back({s,e});
    }
    sort(A.begin(),A.end(),[](pii a, pii b){
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
    });
    
    multiset<int> tree;
    int ans = 0;
    for(int i=0;i<n;i++){
        multiset<int>::iterator it = tree.lower_bound(A[i].first);
        if(it==tree.end()){
            if(tree.size()) tree.erase(tree.begin());
            ans++; tree.insert(A[i].second);
        }
        else if(it!=tree.begin()){
            it--; tree.erase(it);
            ans++; tree.insert(A[i].second);
        }
        else if(tree.size()<k){
            tree.insert(A[i].second);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
