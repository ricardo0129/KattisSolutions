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

vector<string> words;
//map to new alphabet a=0,b=1,...
char mp[26];
int times[26];
int solutions = 0;
string dic[12];
string ans;
int n;
bool match(string A,string B){
    for(int i = 0;i<sz(A);i++)
        for(int j=0;j<sz(A);j++){
            if(A[i]==A[j] && B[i]!=B[j]) return false;
            if(B[i]==B[j] && A[i]!=A[j]) return false;
        }
    return true;
}
bool check(int i, int j){
    //check if we can map word[i] from dic[j] 
    if(words[i].size()!=dic[j].size()) return false;
    if(!match(words[i],dic[j])) return false;
    for(int k=0;k<sz(words[i]);k++){
        char c = words[i][k];
        char v = mp[c-'a'];
        if(v!='0' && v!=dic[j][k]) return false;
    }
    return true;
}
int alp[26];
set<string> allans;
void solve(int i){
    if(solutions>1) return;
    if(i==n){
        FOR(k,26){
            if(alp[k] && mp[k]=='0') return;
        }
        FOR(k,26){
            FOR(l,k){
                if(mp[k]=='0' || mp[l]=='0') continue;
                if(mp[k]==mp[l]) return;
            }
        }
        ans = "";
        FOR(k,sz(words)){
            string w = words[k];
            for(char c: w){
                ans+=string(1,mp[c-'a']);
            }
            if(k!=sz(words)-1) ans+=" ";
        }
        allans.insert(ans);
        solutions = allans.size();
        return;
    }
    string curr = words[i];
    FOR(j,12){
        if(check(i,j)){
            FOR(k,sz(dic[j])){
                mp[words[i][k]-'a'] = dic[j][k];
                times[words[i][k]-'a']++;
            }
            solve(i+1);
            FOR(k,sz(dic[j])){
                times[words[i][k]-'a']--;
                if(times[words[i][k]-'a']==0) 
                    mp[words[i][k]-'a'] = '0';
            }
        }
    }
    //skip
    solve(i+1);
}

int main()
{
    dic[0] = "be";    dic[1] = "our";   dic[2] = "rum";     dic[3] = "will"; 
    dic[4] = "dead";  dic[5] = "hook";  dic[6] = "ship";    dic[7] = "blood";
    dic[8] = "sable"; dic[9] = "avenge"; dic[10] = "parrot"; dic[11] = "captain";
    string enc;
    getline(cin,enc);
    stringstream ss(enc);
    string in;
    memset(alp,0,sizeof alp);
    while(ss>>in){
        words.pb(in);
        for(char c: in) alp[c-'a'] = 1;
    }
    n = words.size(); 
    FOR(i,26) mp[i] = '0';
    memset(times,0,sizeof times);
    solve(0);
    if(solutions==1) cout<<ans<<endl;
    else cout<<"Impossible\n";
    
    return 0;
}
