/*
Not much to explain on this one. The implementatino is a bit long 
but we just have to keep a maping of students -> ids. 
a set for each student of the projects they are signed up for. 
and a set for each project of the students that have signed for it. It's
a good problem to test your basic data structure knowledge.
*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

map<string,int> students;
set<int> sign[100];
set<int> sign2[10000];
vector<string> names;
string pk;
int pk_int;

int main()
{
	while(true){
		while(true){
			string p;
			getline(cin,p);
			if(p[0]=='0') return 0;
			else if(p[0]=='1') break;
			
			if(isupper(p[0])){
				pk_int = names.size();
				names.push_back(p);
			}
			else{
				map<string,int>::iterator it = students.find(p);
				if(it==students.end()) students[p] = students.size();
				sign[pk_int].insert(students[p]);
				sign2[students[p]].insert(pk_int);
			}
		}
		for(int i=0;i<students.size();i++){
			if(sign2[i].size()>1){
				for(auto x: sign2[i]){
					sign[x].erase(i);
				}
			}
		}
		vector<pair<int,string>> sorted;
		for(int i=0;i<=pk_int;i++){
			sorted.push_back({(int)sign[i].size(),names[i]});
		}
		sort(sorted.begin(),sorted.end(),[](auto lhs, auto rhs){
			if(lhs.first==rhs.first) return lhs.second<rhs.second;
			return lhs.first>rhs.first;
		});
		for(auto x: sorted){
				cout<<x.second<<" "<<x.first<<endl;
		}
		for(int i=0;i<=pk_int;i++)
			sign[i].clear();
		for(int i=0;i<students.size();i++) sign2[i].clear();
		students.clear();
		names.clear();
		


	}	

	return 0;
}
