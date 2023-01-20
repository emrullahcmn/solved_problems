// Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=763
#include <bits/stdc++.h> 
#include <set> 
#include <map> 
#include <unordered_map> 
#include <vector> 
#include <utility> //pair
#include <string>
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair 
typedef long long ll; 
using namespace std; 

int main() { 

   freopen("measurement.in","r",stdin);
   freopen("measurement.out","w",stdout);

   int n,g;
   cin >> n >> g;

   vector<pair<int, pair<int,int>>> vp;

   int a,b,c;
   map<int,int> occurence;
   map<int,int> key_value;
   set<int> indexes;
   set<pair<int,int>> st;
   occurence[g]++;
   for(int i = 0; i<n; i++){
    cin >> a >> b >> c;
    vp.push_back(MP(a, MP(b,c)));
    if(indexes.find(b) == indexes.end()){
      occurence[g]++; 
      key_value[b] = g;
      st.insert(MP(g, b));
    }
   }

   sort(vp.begin(), vp.end());

   int howmany = occurence[g];
   int mx = g;
   int lastind = -1;
   int cnt = 0;
   for(auto &p : vp){

    auto pr = p.second;
    auto val = key_value[pr.first];

    st.erase(st.find(MP(val, pr.first)));

    occurence[key_value[pr.first]]--;
    key_value[pr.first] += pr.second;
    occurence[key_value[pr.first]]++;
    st.insert(MP(key_value[pr.first], pr.first));
    auto greatest = (*st.rbegin()).first;

    if(occurence[greatest] > 1){
      lastind = -1;
    }
    if(occurence[greatest] > 1 && howmany != occurence[greatest]){
      cnt++;
      howmany = occurence[greatest];
      continue;
    }

    if(occurence[greatest] == 1 && lastind != (*st.rbegin()).second){
      cnt++;
      lastind = (*st.rbegin()).second;
      howmany = occurence[greatest];
    }

   }

   cout << cnt << endl;


return 0;
}