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

// Problem : https://cses.fi/problemset/task/1632

int main() { 
  
  int n,k;
  cin >> n >> k;

  vector<pair<int,int>> v(n);
  for(int i = 0; i<n; i++){
    cin >> v[i].second >> v[i].first;
  }

  sort(v.begin(), v.end());

  multiset<int> ms;
  int ans = 1;
  ms.insert(v[0].first);

  for(int i = 1; i<n; i++){
    auto it = ms.lower_bound(v[i].second);
    if(it == ms.end() || (*it > v[i].second && it != ms.begin())) it--;
 
    if(*it <= v[i].second){

        ans++;
        ms.erase(ms.find(*it));
        ms.insert(v[i].first);
    }else{
        if(ms.size() < k){
            ms.insert(v[i].first);
            ans++;
        }
    }
  }

  cout << ans << endl;

return 0;
}