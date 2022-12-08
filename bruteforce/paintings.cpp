#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
#define pii pair<int,int>
#define ll long long 
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back

const int MOD = (int)1e9+7;
const ll INF = (ll)1e17+7;
int G[13][13];
int best[13];
int curr[13];
bool used[13];
int n;
bool found;
int solve(int i){
	if(i==n){
		//valid sequence
		if(!found){
			FOR(j,n) best[j] = curr[j];
			found = true;
		}
		return 1;
	}
	int tot = 0;
	FOR(j,n){
		if(!used[j]){
			if(i==0 || G[j][curr[i-1]]==0){
				curr[i] = j;
				used[j] = true; 
				tot+=solve(i+1);
				used[j] = false;
			}
		}
	}
	return tot;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<string> A(n);
		map<string,int> mp;
		FOR(i,n){
			cin>>A[i];
			mp[A[i]] = i;
		}
		memset(G,0,sizeof G);
		int m;
		cin>>m;
		FOR(i,m){
			string a,b;
			cin>>a>>b;
			int u = mp[a], v = mp[b];
			G[u][v] = 1;
			G[v][u] = 1;
		}
		memset(used,0,sizeof used);
		found = false;
		int ans = solve(0);
		cout<<ans<<endl;
		FOR(i,n) cout<<A[best[i]]<<" ";
		cout<<endl;

	}
	return 0;
=======
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
vector<string> colors;
const int N = 20;
bool bad[N][N];
int total;
bool used[N];
int arrangment[N];
int ans[N];
int n;
void solve(int i){
    if(i==n){
        if(total++==0){
            FOR(j,n) ans[j] = arrangment[j];
        }
        return;
    }
    FOR(k,n){
        if(used[k]) continue;
        if(i==0 || !bad[arrangment[i-1]][k]){
            arrangment[i] = k;
            used[k] = true;
            solve(i+1);
            used[k] = false;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        map<string,int> mp;
        colors.clear();
        memset(bad,false,sizeof bad);
        FOR(i,n){
            string in;
            cin>>in;
            colors.pb(in);
            mp[in] = mp.size();
        }
        int edges;
        cin>>edges;
        FOR(i,edges){
            string a,b;
            cin>>a>>b;
            int u = mp[a];
            int v = mp[b];
            bad[u][v] = true;
            bad[v][u] = true;
        }
        total=0;
        memset(used,false,sizeof false);
        solve(0);
        cout<<total<<endl;
        FOR(i,n) cout<<colors[ans[i]]<<" ";
        cout<<endl;

    }
    return 0;
>>>>>>> 005b24874fba2338c7f7dc70853c6b3d04d1217b
}
