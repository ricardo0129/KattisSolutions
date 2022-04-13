/*
This problem is similair to class scheduling problem. We can have a greedy solution
we sort the intervals by ending time and we keep a set of current intervals end times. Then lets 
say we are looking at a new interval (s,e) we haven't seen. We then binary search for 
the start time s of the new interval. then we have some cases

Case 1: All elements are in our current intervals < s. In this case we can schedule a 
class in any of the rooms we have in the set, so lets just delete the one with the lowest
ending time and add our new interval.
Case 2: We found the s time in our current intervals. Then we can just delete the 
element previous to it, because we know this element is e<s. And add our interval to the set
Case 3: We failed both case 1 and case 2. But our set has less then k intervals so we can just add it.

We can then just iterate through all intervals and check all three of these test cases. 
Then the number of elements added to the set is our answer. 
*/

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
