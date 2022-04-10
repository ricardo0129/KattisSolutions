/*
I found this problem to actually be nice. We start with implementing a sliding window algorithm. 
Then are asked to find some property of how many times a certain element is in the sliding window. 
The size of the array is 100'000. 
First approach is just to implement the sliding window algorithm which is O(n) and lets just save 
the sliding windows as tuples of (s,e) 
We can just find the first occurence of element 1. Then we iterate from left to right until we find
the last occurence of that element. This algorithm is O(n^2). Pretty bad considering 100'000^2 will 
time limit exceed. So how do we optimize. 
Well lets just add binary search to reduce the time complexity to O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

const int N = (int)1e5;
int ans[N];
ll A[N];
vector<pii> sub;

int main()
{
    int n; ll c;
    cin>>n>>c;
    for(int i=0;i<n;i++) cin>>A[i];
    int s = 0, e = 0;
    ll sum = A[0];
    while(s<n){
        if(s<=e) sub.push_back({s,e});
        if(e+1>=n){
            sum-=A[s];
            s++;
        }
        else if(sum+A[e+1]>c){
            sum-=A[s];
            s++; 
        }
        else{
            sum+=A[e+1];
            e++;
        }
    }
    int j = 0;
    for(int i=0;i<sub.size();i++){
        if(sub[i].first<=j && j<=sub[i].second){
            int maximum = 0;
            int L = i, R = sub.size()-1;
            while(L<=R){
                int M = (L+R)/2;
                if(sub[M].first<=j && j<=sub[M].second){
                    maximum = M-i+1; 
                    L = M+1;
                }
                else R = M-1;
            }

            ans[j] = maximum;
            j++;
        }
     
    }


    for(int i=0;i<n;i++) cout<<ans[i]<<endl;


    return 0;
}
