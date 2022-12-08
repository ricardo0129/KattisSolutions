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
    vector<string> scales = {"A","A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    int n;
    cin>>n;
    vector<string> A(n);
    FOR(i,n) cin>>A[i]; 
    vector<string> ans;
    int diff[] = {2,2,1,2,2,2,1};
    FOR(i,12){
        set<string> notes;
        int start = i;
        notes.insert(scales[start]);
        FOR(j,7){
            start = (start+diff[j])%12; 
            notes.insert(scales[start]);
        }
        bool valid = true;
        FOR(j,n)
            if(notes.find(A[j])==notes.end()) valid = false;
        if(valid) ans.pb(scales[i]);
    }
    if(ans.size()==0) cout<<"none";
    for(string s: ans) cout<<s<<" ";
    cout<<endl;

    return 0;
}
