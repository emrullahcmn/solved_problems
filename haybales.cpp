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

//Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=666

void setIO(string name = ""){
    if(name == "") return;
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() { 

  setIO("haybales");

  int n,q;
  cin >> n >> q;

  ll a[n];
  for(int i = 0; i< n; i++) cin >> a[i];
  sort(a, a+n);

  set<pair<ll,int>> st;
  st.insert(MP(-1, 0));

  for(int i = 0; i<n; i++){
    st.insert(MP(a[i], i+1));
  }

  ll x, y;
  pair<ll,int> p = {-1, -1};
  for(int i = 0; i<q; i++){
    cin >> x >> y;
    p.first = x;
    auto it = st.lower_bound(p);
    if(it == st.end() || (*it).first > y ){
        cout << 0 << endl;
        continue;
    }
    p.first = y;
    auto it2 = st.lower_bound(p);

    if(it2 == st.end() || (*it2).first > y) it2--;
    it--;
    cout << (*it2).second - (*it).second << endl;
  }

return 0;
}